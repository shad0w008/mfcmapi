#pragma once

namespace smartview
{
	// After 'No Parsing', these are in alphabetical order
	static NAME_ARRAY_ENTRY g_SmartViewParserTypeArray[] = {
		{IDS_STNOPARSING, L"Choose Smart View Parser"}, // STRING_OK
		{IDS_STADDITIONALRENENTRYIDSEX, L"Additional Ren Entry IDs Ex"}, // STRING_OK
		{IDS_STAPPOINTMENTRECURRENCEPATTERN, L"Appointment Recurrence Pattern"}, // STRING_OK
		{IDS_STCONVERSATIONINDEX, L"Conversation Index"}, // STRING_OK
		{IDS_STENTRYID, L"Entry Id"}, // STRING_OK
		{IDS_STENTRYLIST, L"Entry List"}, // STRING_OK
		{IDS_STEXTENDEDFOLDERFLAGS, L"Extended Folder Flags"}, // STRING_OK
		{IDS_STEXTENDEDRULECONDITION, L"Extended Rule Condition"}, // STRING_OK
		{IDS_STFLATENTRYLIST, L"Flat Entry List"}, // STRING_OK
		{IDS_STFOLDERUSERFIELDS, L"Folder User Fields Stream"}, // STRING_OK
		{IDS_STGLOBALOBJECTID, L"Global Object Id"}, // STRING_OK
		{IDS_STPROPERTIES, L"Property"}, // STRING_OK
		{IDS_STPROPERTYDEFINITIONSTREAM, L"Property Definition Stream"}, // STRING_OK
		{IDS_STRECIPIENTROWSTREAM, L"Recipient Row Stream"}, // STRING_OK
		{IDS_STRECURRENCEPATTERN, L"Recurrence Pattern"}, // STRING_OK
		{IDS_STREPORTTAG, L"Report Tag"}, // STRING_OK
		{IDS_STRESTRICTION, L"Restriction"}, // STRING_OK
		{IDS_STRULECONDITION, L"Rule Condition"}, // STRING_OK
		{IDS_STSEARCHFOLDERDEFINITION, L"Search Folder Definition"}, // STRING_OK
		{IDS_STSECURITYDESCRIPTOR, L"Security Descriptor"}, // STRING_OK
		{IDS_STSID, L"SID"}, // STRING_OK
		{IDS_STTASKASSIGNERS, L"Task Assigners"}, // STRING_OK
		{IDS_STTIMEZONE, L"Time Zone"}, // STRING_OK
		{IDS_STTIMEZONEDEFINITION, L"Time Zone Definition"}, // STRING_OK
		{IDS_STWEBVIEWPERSISTSTREAM, L"Web View Persistence Object Stream"}, // STRING_OK
		{IDS_STNICKNAMECACHE, L"Nickname Cache"}, // STRING_OK
		{IDS_STENCODEENTRYID, L"Encode Entry ID"}, // STRING_OK
		{IDS_STDECODEENTRYID, L"Decode Entry ID"}, // STRING_OK
		{IDS_STVERBSTREAM, L"Verb Stream"}, // STRING_OK
		{IDS_STTOMBSTONE, L"Tombstone"}, // STRING_OK
		{IDS_STPCL, L"Predecessor Change List"}, // STRING_OK
		{IDS_STFBSECURITYDESCRIPTOR, L"Free Busy Security Descriptor"}, // STRING_OK
		{IDS_STXID, L"XID"}, // STRING_OK
	};

	static SMARTVIEW_PARSER_ARRAY_ENTRY g_SmartViewParserArray[] = {
		// clang-format off
		BINARY_STRUCTURE_ENTRY(PR_REPORT_TAG, IDS_STREPORTTAG)
		BINARY_STRUCTURE_ENTRY(PR_RECEIVED_BY_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_SENT_REPRESENTING_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_RCVD_REPRESENTING_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_REPORT_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_READ_RECEIPT_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_ORIGINAL_AUTHOR_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_REPLY_RECIPIENT_ENTRIES, IDS_STFLATENTRYLIST)
		BINARY_STRUCTURE_ENTRY(PR_ORIGINAL_SENDER_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_ORIGINAL_SENT_REPRESENTING_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_CONVERSATION_INDEX, IDS_STCONVERSATIONINDEX)
		BINARY_STRUCTURE_ENTRY(PR_SENDER_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_PARENT_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_SENTMAIL_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_NT_SECURITY_DESCRIPTOR, IDS_STSECURITYDESCRIPTOR)
		BINARY_STRUCTURE_ENTRY(PR_CREATOR_SID, IDS_STSID)
		BINARY_STRUCTURE_ENTRY(PR_LAST_MODIFIER_SID, IDS_STSID)
		BINARY_STRUCTURE_ENTRY(PR_EXTENDED_RULE_MSG_CONDITION, IDS_STEXTENDEDRULECONDITION)
		BINARY_STRUCTURE_ENTRY(PR_FREEBUSY_NT_SECURITY_DESCRIPTOR, IDS_STFBSECURITYDESCRIPTOR)
		BINARY_STRUCTURE_ENTRY(PR_STORE_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_ORIGINALLY_INTENDED_RECIP_ENTRYID, IDS_STENTRYID)
		MV_BINARY_STRUCTURE_ENTRY(PR_CONFLICT_ITEMS, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_TARGET_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_IPM_SUBTREE_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_IPM_OUTBOX_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_IPM_WASTEBASKET_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_IPM_SENTMAIL_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_VIEWS_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_COMMON_VIEWS_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_FINDER_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_DEFAULT_VIEW_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_IPM_APPOINTMENT_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_IPM_CONTACT_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_IPM_JOURNAL_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_IPM_NOTE_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_IPM_TASK_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_REM_ONLINE_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_REM_OFFLINE_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_IPM_DRAFTS_ENTRYID, IDS_STENTRYID)
		MV_BINARY_STRUCTURE_ENTRY(PR_ADDITIONAL_REN_ENTRYIDS, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_ADDITIONAL_REN_ENTRYIDS_EX, IDS_STADDITIONALRENENTRYIDSEX)
		BINARY_STRUCTURE_ENTRY(PR_EXTENDED_FOLDER_FLAGS, IDS_STEXTENDEDFOLDERFLAGS)
		BINARY_STRUCTURE_ENTRY(PR_FOLDER_WEBVIEWINFO, IDS_STWEBVIEWPERSISTSTREAM)
		BINARY_STRUCTURE_ENTRY(PR_USERFIELDS, IDS_STFOLDERUSERFIELDS)
		MV_BINARY_STRUCTURE_ENTRY(PR_FREEBUSY_ENTRYIDS, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_ALTERNATE_RECIPIENT, IDS_STFLATENTRYLIST)
		BINARY_STRUCTURE_ENTRY(PR_ORIGINAL_ENTRYID, IDS_STENTRYID)
		MV_BINARY_STRUCTURE_ENTRY(PR_AB_SEARCH_PATH, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_IDENTITY_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_OWN_STORE_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_HEADER_FOLDER_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_CONFLICT_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_MOVE_TO_STORE_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_MOVE_TO_FOLDER_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_CREATOR_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_LAST_MODIFIER_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_RECIPIENT_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_USER_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_MAILBOX_OWNER_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_SCHEDULE_FOLDER_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_IPM_DAF_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_NON_IPM_SUBTREE_ENTRYID, IDS_STENTRYID)
		MV_BINARY_STRUCTURE_ENTRY(PR_CONTAB_FOLDER_ENTRYIDS, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_EFORMS_REGISTRY_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_SPLUS_FREE_BUSY_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_OFFLINE_ADDRBOOK_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_EFORMS_FOR_LOCALE_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_FREE_BUSY_FOR_LOCAL_SITE_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_ADDRBOOK_FOR_LOCAL_SITE_ENTRYID, IDS_STENTRYID)
		MV_BINARY_STRUCTURE_ENTRY(PR_CONTAB_STORE_ENTRYIDS, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_OFFLINE_MESSAGE_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_GW_MTSIN_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_GW_MTSOUT_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_IPM_FAVORITES_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_IPM_PUBLIC_FOLDERS_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_SYS_CONFIG_FOLDER_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_ADDRESS_BOOK_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_PUBLIC_FOLDER_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_DAM_ORIGINAL_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_RULE_FOLDER_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_ACTIVE_USER_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_ORIGINATOR_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_REPORT_DESTINATION_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_LONGTERM_ENTRYID_FROM_TABLE, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_EVENTS_ROOT_FOLDER_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_NNTP_ARTICLE_FOLDER_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_NEWSGROUP_ROOT_FOLDER_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_WLINK_AB_EXSTOREEID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_WLINK_ABEID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_WLINK_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_WLINK_STORE_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_WB_SF_DEFINITION, IDS_STSEARCHFOLDERDEFINITION)
		MV_BINARY_STRUCTURE_ENTRY(PR_SCHDINFO_DELEGATE_ENTRYIDS, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_EMS_AB_PARENT_ENTRYID, IDS_STENTRYID)
		BINARY_STRUCTURE_ENTRY(PR_SCHDINFO_APPT_TOMBSTONE, IDS_STTOMBSTONE)
		BINARY_STRUCTURE_ENTRY(PR_PREDECESSOR_CHANGE_LIST, IDS_STPCL)
		BINARY_STRUCTURE_ENTRY(PR_CHANGE_KEY, IDS_STXID)

		NAMEDPROP_BINARY_STRUCTURE_ENTRY(LID_GLOBAL_OBJID, PSETID_Meeting, IDS_STGLOBALOBJECTID)
		NAMEDPROP_BINARY_STRUCTURE_ENTRY(LID_CLEAN_GLOBAL_OBJID, PSETID_Meeting, IDS_STGLOBALOBJECTID)
		NAMEDPROP_BINARY_STRUCTURE_ENTRY(dispidSelectedOriginalEntryID, PSETID_Address, IDS_STENTRYID)
		NAMEDPROP_BINARY_STRUCTURE_ENTRY(dispidAnniversaryEventEID, PSETID_Address, IDS_STENTRYID)
		NAMEDPROP_MV_BINARY_STRUCTURE_ENTRY(dispidDLOneOffMembers, PSETID_Address, IDS_STENTRYID)
		NAMEDPROP_MV_BINARY_STRUCTURE_ENTRY(dispidDLMembers, PSETID_Address, IDS_STENTRYID)
		NAMEDPROP_BINARY_STRUCTURE_ENTRY(dispidEmail1OriginalEntryID, PSETID_Address, IDS_STENTRYID)
		NAMEDPROP_BINARY_STRUCTURE_ENTRY(dispidEmail2OriginalEntryID, PSETID_Address, IDS_STENTRYID)
		NAMEDPROP_BINARY_STRUCTURE_ENTRY(dispidEmail3OriginalEntryID, PSETID_Address, IDS_STENTRYID)
		NAMEDPROP_BINARY_STRUCTURE_ENTRY(dispidFax1EntryID, PSETID_Address, IDS_STENTRYID)
		NAMEDPROP_BINARY_STRUCTURE_ENTRY(dispidFax2EntryID, PSETID_Address, IDS_STENTRYID)
		NAMEDPROP_BINARY_STRUCTURE_ENTRY(dispidFax3EntryID, PSETID_Address, IDS_STENTRYID)
		NAMEDPROP_BINARY_STRUCTURE_ENTRY(dispidTaskRecur, PSETID_Task, IDS_STRECURRENCEPATTERN)
		NAMEDPROP_BINARY_STRUCTURE_ENTRY(dispidTaskMyDelegators, PSETID_Task, IDS_STTASKASSIGNERS)
		NAMEDPROP_BINARY_STRUCTURE_ENTRY(dispidApptRecur, PSETID_Appointment, IDS_STAPPOINTMENTRECURRENCEPATTERN)
		NAMEDPROP_BINARY_STRUCTURE_ENTRY(dispidTimeZoneStruct, PSETID_Appointment, IDS_STTIMEZONE)
		NAMEDPROP_BINARY_STRUCTURE_ENTRY(dispidOrigStoreEid, PSETID_Appointment, IDS_STENTRYID)
		NAMEDPROP_BINARY_STRUCTURE_ENTRY(dispidApptUnsendableRecips, PSETID_Appointment, IDS_STRECIPIENTROWSTREAM)
		NAMEDPROP_BINARY_STRUCTURE_ENTRY(dispidApptTZDefStartDisplay, PSETID_Appointment, IDS_STTIMEZONEDEFINITION)
		NAMEDPROP_BINARY_STRUCTURE_ENTRY(dispidApptTZDefEndDisplay, PSETID_Appointment, IDS_STTIMEZONEDEFINITION)
		NAMEDPROP_BINARY_STRUCTURE_ENTRY(dispidApptTZDefRecur, PSETID_Appointment, IDS_STTIMEZONEDEFINITION)
		NAMEDPROP_BINARY_STRUCTURE_ENTRY(dispidForwardNotificationRecipients, PSETID_Appointment, IDS_STRECIPIENTROWSTREAM)
		NAMEDPROP_BINARY_STRUCTURE_ENTRY(dispidPropDefStream, PSETID_Common, IDS_STPROPERTYDEFINITIONSTREAM)
		NAMEDPROP_BINARY_STRUCTURE_ENTRY(dispidContactLinkEntry, PSETID_Common, IDS_STFLATENTRYLIST)
		NAMEDPROP_BINARY_STRUCTURE_ENTRY(dispidReferenceEID, PSETID_Common, IDS_STENTRYID)
		NAMEDPROP_BINARY_STRUCTURE_ENTRY(dispidSharingInitiatorEid, PSETID_Sharing, IDS_STENTRYID)
		NAMEDPROP_BINARY_STRUCTURE_ENTRY(dispidSharingFolderEid, PSETID_Sharing, IDS_STENTRYID)
		NAMEDPROP_BINARY_STRUCTURE_ENTRY(dispidSharingOriginalMessageEid, PSETID_Sharing, IDS_STENTRYID)
		NAMEDPROP_BINARY_STRUCTURE_ENTRY(dispidSharingBindingEid, PSETID_Sharing, IDS_STENTRYID)
		NAMEDPROP_BINARY_STRUCTURE_ENTRY(dispidSharingIndexEid, PSETID_Sharing, IDS_STENTRYID)
		NAMEDPROP_BINARY_STRUCTURE_ENTRY(dispidSharingParentBindingEid, PSETID_Sharing, IDS_STENTRYID)
		NAMEDPROP_BINARY_STRUCTURE_ENTRY(dispidConvActionMoveFolderEid, PSETID_Sharing, IDS_STENTRYID)
		NAMEDPROP_BINARY_STRUCTURE_ENTRY(dispidConvActionMoveStoreEid, PSETID_Sharing, IDS_STENTRYID)
		NAMEDPROP_BINARY_STRUCTURE_ENTRY(dispidVerbStream, PSETID_Common, IDS_STVERBSTREAM)

		BINARY_STRUCTURE_ENTRY(PR_RULE_ID, IDS_STPTI8)
		BINARY_STRUCTURE_ENTRY(PidTagFolderId, IDS_STSFIDMID)
		BINARY_STRUCTURE_ENTRY(PidTagMid, IDS_STSFIDMID)
		BINARY_STRUCTURE_ENTRY(PR_WB_SF_LAST_USED, IDS_STLONGRTIME)
		BINARY_STRUCTURE_ENTRY(PR_WB_SF_EXPIRATION, IDS_STLONGRTIME)
		BINARY_STRUCTURE_ENTRY(PR_FREEBUSY_PUBLISH_START, IDS_STLONGRTIME)
		BINARY_STRUCTURE_ENTRY(PR_FREEBUSY_PUBLISH_END, IDS_STLONGRTIME)
		// clang-format on
	};
}