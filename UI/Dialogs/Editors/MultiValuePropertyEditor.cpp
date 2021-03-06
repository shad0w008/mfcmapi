#include <StdAfx.h>
#include <UI/Dialogs/Editors/MultiValuePropertyEditor.h>
#include <MAPI/MAPIFunctions.h>
#include <Interpret/SmartView/SmartView.h>
#include <UI/Controls/SortList/MVPropData.h>
#include <UI/Dialogs/Editors/PropertyEditor.h>
#include <Interpret/InterpretProp.h>
#include <MAPI/MapiMemory.h>

namespace dialog
{
	namespace editor
	{
		static std::wstring MVCLASS = L"CMultiValuePropertyEditor"; // STRING_OK

		// Create an editor for a MAPI property
		CMultiValuePropertyEditor::CMultiValuePropertyEditor(
			_In_ CWnd* pParentWnd,
			UINT uidTitle,
			UINT uidPrompt,
			bool bIsAB,
			_In_opt_ LPVOID lpAllocParent,
			_In_opt_ LPMAPIPROP lpMAPIProp,
			ULONG ulPropTag,
			_In_opt_ const _SPropValue* lpsPropValue)
			: CEditor(pParentWnd, uidTitle, uidPrompt, CEDITOR_BUTTON_OK | CEDITOR_BUTTON_CANCEL)
		{
			TRACE_CONSTRUCTOR(MVCLASS);

			m_bIsAB = bIsAB;
			m_lpAllocParent = lpAllocParent;
			m_lpsOutputValue = nullptr;

			m_lpMAPIProp = lpMAPIProp;
			if (m_lpMAPIProp) m_lpMAPIProp->AddRef();
			m_ulPropTag = ulPropTag;
			m_lpsInputValue = lpsPropValue;

			const auto szPromptPostFix = strings::format(
				L"\r\n%ws", interpretprop::TagToString(m_ulPropTag, m_lpMAPIProp, m_bIsAB, false).c_str()); // STRING_OK
			SetPromptPostFix(szPromptPostFix);

			InitPropertyControls();
		}

		CMultiValuePropertyEditor::~CMultiValuePropertyEditor()
		{
			TRACE_DESTRUCTOR(MVCLASS);
			if (m_lpMAPIProp) m_lpMAPIProp->Release();
		}

		BOOL CMultiValuePropertyEditor::OnInitDialog()
		{
			const auto bRet = CEditor::OnInitDialog();

			ReadMultiValueStringsFromProperty();
			ResizeList(0, false);

			const auto smartView =
				smartview::InterpretPropSmartView2(m_lpsInputValue, m_lpMAPIProp, nullptr, nullptr, m_bIsAB, true);

			const auto iStructType = smartView.first;
			auto szSmartView = smartView.second;
			if (!szSmartView.empty())
			{
				auto lpPane = dynamic_cast<viewpane::SmartViewPane*>(GetPane(1));
				if (lpPane)
				{
					lpPane->SetParser(iStructType);
					lpPane->SetStringW(szSmartView);
				}
			}

			UpdateButtons();

			return bRet;
		}

		void CMultiValuePropertyEditor::OnOK()
		{
			// This is where we write our changes back
			WriteMultiValueStringsToSPropValue();
			WriteSPropValueToObject();
			CMyDialog::OnOK(); // don't need to call CEditor::OnOK
		}

		void CMultiValuePropertyEditor::InitPropertyControls()
		{
			InitPane(0, viewpane::ListPane::Create(IDS_PROPVALUES, false, false, ListEditCallBack(this)));
			if (PT_MV_BINARY == PROP_TYPE(m_ulPropTag) || PT_MV_LONG == PROP_TYPE(m_ulPropTag))
			{
				auto lpPane = viewpane::SmartViewPane::Create(IDS_SMARTVIEW);
				InitPane(1, lpPane);

				if (lpPane && PT_MV_LONG == PROP_TYPE(m_ulPropTag))
				{
					lpPane->DisableDropDown();
				}
			}
		}

		// Function must be called AFTER dialog controls have been created, not before
		void CMultiValuePropertyEditor::ReadMultiValueStringsFromProperty() const
		{
			InsertColumn(0, 0, IDS_ENTRY);
			InsertColumn(0, 1, IDS_VALUE);
			InsertColumn(0, 2, IDS_ALTERNATEVIEW);
			if (PT_MV_LONG == PROP_TYPE(m_ulPropTag) || PT_MV_BINARY == PROP_TYPE(m_ulPropTag))
			{
				InsertColumn(0, 3, IDS_SMARTVIEW);
			}

			if (!m_lpsInputValue) return;
			if (!(PROP_TYPE(m_lpsInputValue->ulPropTag) & MV_FLAG)) return;

			// All the MV structures are basically the same, so we can cheat when we pull the count
			const auto cValues = m_lpsInputValue->Value.MVi.cValues;
			for (ULONG iMVCount = 0; iMVCount < cValues; iMVCount++)
			{
				auto lpData = InsertListRow(0, iMVCount, std::to_wstring(iMVCount));

				if (lpData)
				{
					lpData->InitializeMV(m_lpsInputValue, iMVCount);

					SPropValue sProp = {0};
					sProp.ulPropTag =
						CHANGE_PROP_TYPE(m_lpsInputValue->ulPropTag, PROP_TYPE(m_lpsInputValue->ulPropTag) & ~MV_FLAG);
					sProp.Value = lpData->MV()->m_val;
					UpdateListRow(&sProp, iMVCount);

					lpData->bItemFullyLoaded = true;
				}
			}
		}

		// Perisist the data in the controls to m_lpsOutputValue
		void CMultiValuePropertyEditor::WriteMultiValueStringsToSPropValue()
		{
			// If we're not dirty, don't write
			// Unless we had no input value. Then we're creating a new property.
			// So we're implicitly dirty.
			if (!IsDirty(0) && m_lpsInputValue) return;

			// Take care of allocations first
			if (!m_lpsOutputValue)
			{
				m_lpsOutputValue = mapi::allocate<LPSPropValue>(sizeof(SPropValue), m_lpAllocParent);
				if (!m_lpAllocParent)
				{
					m_lpAllocParent = m_lpsOutputValue;
				}
			}

			if (m_lpsOutputValue)
			{
				WriteMultiValueStringsToSPropValue(static_cast<LPVOID>(m_lpAllocParent), m_lpsOutputValue);
			}
		}

		// Given a pointer to an SPropValue structure which has already been allocated, fill out the values
		void CMultiValuePropertyEditor::WriteMultiValueStringsToSPropValue(
			_In_ LPVOID lpParent,
			_In_ LPSPropValue lpsProp) const
		{
			if (!lpParent || !lpsProp) return;

			const auto ulNumVals = GetListCount(0);

			lpsProp->ulPropTag = m_ulPropTag;
			lpsProp->dwAlignPad = NULL;

			switch (PROP_TYPE(lpsProp->ulPropTag))
			{
			case PT_MV_I2:
				lpsProp->Value.MVi.lpi = mapi::allocate<short int*>(sizeof(short int) * ulNumVals, lpParent);
				lpsProp->Value.MVi.cValues = ulNumVals;
				break;
			case PT_MV_LONG:
				lpsProp->Value.MVl.lpl = mapi::allocate<LONG*>(sizeof(LONG) * ulNumVals, lpParent);
				lpsProp->Value.MVl.cValues = ulNumVals;
				break;
			case PT_MV_DOUBLE:
				lpsProp->Value.MVdbl.lpdbl = mapi::allocate<double*>(sizeof(double) * ulNumVals, lpParent);
				lpsProp->Value.MVdbl.cValues = ulNumVals;
				break;
			case PT_MV_CURRENCY:
				lpsProp->Value.MVcur.lpcur = mapi::allocate<CURRENCY*>(sizeof(CURRENCY) * ulNumVals, lpParent);
				lpsProp->Value.MVcur.cValues = ulNumVals;
				break;
			case PT_MV_APPTIME:
				lpsProp->Value.MVat.lpat = mapi::allocate<double*>(sizeof(double) * ulNumVals, lpParent);
				lpsProp->Value.MVat.cValues = ulNumVals;
				break;
			case PT_MV_SYSTIME:
				lpsProp->Value.MVft.lpft = mapi::allocate<FILETIME*>(sizeof(FILETIME) * ulNumVals, lpParent);
				lpsProp->Value.MVft.cValues = ulNumVals;
				break;
			case PT_MV_I8:
				lpsProp->Value.MVli.lpli = mapi::allocate<LARGE_INTEGER*>(sizeof(LARGE_INTEGER) * ulNumVals, lpParent);
				lpsProp->Value.MVli.cValues = ulNumVals;
				break;
			case PT_MV_R4:
				lpsProp->Value.MVflt.lpflt = mapi::allocate<float*>(sizeof(float) * ulNumVals, lpParent);
				lpsProp->Value.MVflt.cValues = ulNumVals;
				break;
			case PT_MV_STRING8:
				lpsProp->Value.MVszA.lppszA = mapi::allocate<LPSTR*>(sizeof(LPSTR) * ulNumVals, lpParent);
				lpsProp->Value.MVszA.cValues = ulNumVals;
				break;
			case PT_MV_UNICODE:
				lpsProp->Value.MVszW.lppszW = mapi::allocate<LPWSTR*>(sizeof(LPWSTR) * ulNumVals, lpParent);
				lpsProp->Value.MVszW.cValues = ulNumVals;
				break;
			case PT_MV_BINARY:
				lpsProp->Value.MVbin.lpbin = mapi::allocate<SBinary*>(sizeof(SBinary) * ulNumVals, lpParent);
				lpsProp->Value.MVbin.cValues = ulNumVals;
				break;
			case PT_MV_CLSID:
				lpsProp->Value.MVguid.lpguid = mapi::allocate<GUID*>(sizeof(GUID) * ulNumVals, lpParent);
				lpsProp->Value.MVguid.cValues = ulNumVals;
				break;
			default:
				break;
			}
			// Allocation is now done

			// Now write our data into the space we allocated
			for (ULONG iMVCount = 0; iMVCount < ulNumVals; iMVCount++)
			{
				const auto lpData = GetListRowData(0, iMVCount);

				if (lpData && lpData->MV())
				{
					switch (PROP_TYPE(lpsProp->ulPropTag))
					{
					case PT_MV_I2:
						lpsProp->Value.MVi.lpi[iMVCount] = lpData->MV()->m_val.i;
						break;
					case PT_MV_LONG:
						lpsProp->Value.MVl.lpl[iMVCount] = lpData->MV()->m_val.l;
						break;
					case PT_MV_DOUBLE:
						lpsProp->Value.MVdbl.lpdbl[iMVCount] = lpData->MV()->m_val.dbl;
						break;
					case PT_MV_CURRENCY:
						lpsProp->Value.MVcur.lpcur[iMVCount] = lpData->MV()->m_val.cur;
						break;
					case PT_MV_APPTIME:
						lpsProp->Value.MVat.lpat[iMVCount] = lpData->MV()->m_val.at;
						break;
					case PT_MV_SYSTIME:
						lpsProp->Value.MVft.lpft[iMVCount] = lpData->MV()->m_val.ft;
						break;
					case PT_MV_I8:
						lpsProp->Value.MVli.lpli[iMVCount] = lpData->MV()->m_val.li;
						break;
					case PT_MV_R4:
						lpsProp->Value.MVflt.lpflt[iMVCount] = lpData->MV()->m_val.flt;
						break;
					case PT_MV_STRING8:
						lpsProp->Value.MVszA.lppszA[iMVCount] = mapi::CopyStringA(lpData->MV()->m_val.lpszA, lpParent);
						break;
					case PT_MV_UNICODE:
						lpsProp->Value.MVszW.lppszW[iMVCount] = mapi::CopyStringW(lpData->MV()->m_val.lpszW, lpParent);
						break;
					case PT_MV_BINARY:
						lpsProp->Value.MVbin.lpbin[iMVCount] = mapi::CopySBinary(lpData->MV()->m_val.bin, lpParent);
						break;
					case PT_MV_CLSID:
						if (lpData->MV()->m_val.lpguid)
						{
							lpsProp->Value.MVguid.lpguid[iMVCount] = *lpData->MV()->m_val.lpguid;
						}

						break;
					default:
						break;
					}
				}
			}
		}

		void CMultiValuePropertyEditor::WriteSPropValueToObject() const
		{
			if (!m_lpsOutputValue || !m_lpMAPIProp) return;

			LPSPropProblemArray lpProblemArray = nullptr;

			auto hRes = EC_MAPI(m_lpMAPIProp->SetProps(1, m_lpsOutputValue, &lpProblemArray));

			EC_PROBLEMARRAY(lpProblemArray);
			MAPIFreeBuffer(lpProblemArray);

			if (SUCCEEDED(hRes))
			{
				hRes = EC_MAPI(m_lpMAPIProp->SaveChanges(KEEP_OPEN_READWRITE));
			}
		}

		// Callers beware: Detatches and returns the modified prop value - this must be MAPIFreeBuffered!
		_Check_return_ LPSPropValue CMultiValuePropertyEditor::DetachModifiedSPropValue()
		{
			const auto m_lpRet = m_lpsOutputValue;
			m_lpsOutputValue = nullptr;
			return m_lpRet;
		}

		_Check_return_ bool CMultiValuePropertyEditor::DoListEdit(
			ULONG /*ulListNum*/,
			int iItem,
			_In_ controls::sortlistdata::SortListData* lpData)
		{
			if (!lpData) return false;
			if (!lpData->MV())
			{
				lpData->InitializeMV(nullptr);
			}

			SPropValue tmpPropVal = {0};
			// Strip off MV_FLAG since we're displaying only a row
			tmpPropVal.ulPropTag = m_ulPropTag & ~MV_FLAG;
			tmpPropVal.Value = lpData->MV()->m_val;

			LPSPropValue lpNewValue = nullptr;
			auto hRes = WC_H(DisplayPropertyEditor(
				this,
				IDS_EDITROW,
				NULL,
				m_bIsAB,
				NULL, // not passing an allocation parent because we know we're gonna free the result
				m_lpMAPIProp,
				NULL,
				true, // This is a row from a multivalued property. Only case we pass true here.
				&tmpPropVal,
				&lpNewValue));

			if (hRes == S_OK && lpNewValue)
			{
				lpData->InitializeMV(lpNewValue);

				// update the UI
				UpdateListRow(lpNewValue, iItem);
				UpdateSmartView();
				return true;
			}

			// Remember we didn't have an allocation parent - this is safe
			MAPIFreeBuffer(lpNewValue);
			return false;
		}

		void CMultiValuePropertyEditor::UpdateListRow(_In_ LPSPropValue lpProp, ULONG iMVCount) const
		{
			std::wstring szTmp;
			std::wstring szAltTmp;

			interpretprop::InterpretProp(lpProp, &szTmp, &szAltTmp);
			SetListString(0, iMVCount, 1, szTmp);
			SetListString(0, iMVCount, 2, szAltTmp);

			if (PT_MV_LONG == PROP_TYPE(m_ulPropTag) || PT_MV_BINARY == PROP_TYPE(m_ulPropTag))
			{
				auto szSmartView =
					smartview::InterpretPropSmartView(lpProp, m_lpMAPIProp, nullptr, nullptr, m_bIsAB, true);

				if (!szSmartView.empty()) SetListString(0, iMVCount, 3, szSmartView);
			}
		}

		void CMultiValuePropertyEditor::UpdateSmartView() const
		{
			auto lpPane = dynamic_cast<viewpane::SmartViewPane*>(GetPane(1));
			if (lpPane)
			{
				auto lpsProp = mapi::allocate<LPSPropValue>(sizeof(SPropValue));
				if (lpsProp)
				{
					WriteMultiValueStringsToSPropValue(static_cast<LPVOID>(lpsProp), lpsProp);

					std::wstring szSmartView;
					switch (PROP_TYPE(m_ulPropTag))
					{
					case PT_MV_LONG:
						szSmartView =
							smartview::InterpretPropSmartView(lpsProp, m_lpMAPIProp, nullptr, nullptr, m_bIsAB, true);
						break;
					case PT_MV_BINARY:
						const auto iStructType = static_cast<__ParsingTypeEnum>(lpPane->GetDropDownSelectionValue());
						if (iStructType)
						{
							szSmartView =
								smartview::InterpretMVBinaryAsString(lpsProp->Value.MVbin, iStructType, m_lpMAPIProp);
						}
						break;
					}

					if (!szSmartView.empty())
					{
						lpPane->SetStringW(szSmartView);
					}
				}

				MAPIFreeBuffer(lpsProp);
			}
		}

		_Check_return_ ULONG CMultiValuePropertyEditor::HandleChange(UINT nID)
		{
			auto i = static_cast<ULONG>(-1);

			// We check against the list pane first so we can track if it handled the change,
			// because if it did, we're going to recalculate smart view.
			auto lpPane = dynamic_cast<viewpane::ListPane*>(GetPane(0));
			if (lpPane)
			{
				i = lpPane->HandleChange(nID);
			}

			if (i == static_cast<ULONG>(-1))
			{
				i = CEditor::HandleChange(nID);
			}

			if (i == static_cast<ULONG>(-1)) return static_cast<ULONG>(-1);

			UpdateSmartView();
			OnRecalcLayout();

			return i;
		}
	}
}