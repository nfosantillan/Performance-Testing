inlineSM_clickJoinSkyMiles()
{
	web_add_header("Origin", "https://{URL}");
	web_add_header("appId", "cus");
	web_add_header("channelId", "ecom");

	web_reg_find("Text=\"status\":\"SUCCESS\"", "SaveCount=getInlineEnrollmentData_success", LAST);
	
	lr_think_time(3);
	lr_start_transaction("%InlineSkymilesEnrollment_clickJoinSkyMiles%");
	lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_15_InlineSM_1a_getInlineEnrollmentData"));
	
	web_custom_request("getInlineEnrollmentData", 
		"URL=https://{URL}/customer/getInlineEnrollmentData", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t1002.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"customerRefId\":\"{customerRefId}\",\"earnedMiles\":\"{earnedMiles}\",\"emailAddress\":\"{c_customerEmailAddress}\",\"originalApp\":\"checkout\",\"paymentRefId\":\"{paymentRefId}\",\"phoneCtyCode\":\"1\",\"phoneNumber\":\"{c_phoneNumber}\",\"recordLocator\":\"{PNR}\"}", 
		LAST);
	
	if(atoi(lr_eval_string("{getInlineEnrollmentData_success}")) > 0){
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_15_InlineSM_1a_getInlineEnrollmentData"), LR_PASS);
	} else {
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_15_InlineSM_1a_getInlineEnrollmentData"), LR_FAIL);
		lr_end_transaction("%InlineSkymilesEnrollment_clickJoinSkyMiles%", LR_FAIL);
		lr_exit(LR_EXIT_ITERATION_AND_CONTINUE,LR_AUTO);
	}
	
	web_custom_request("inline-error-messages.json", 
		"URL=https://{URL}/content/dam/delta-applications/inline-enrollment/1.1.2/assets/json/inline-error-messages.json", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t1004.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin", "https://{URL}");
	web_add_header("appId", "cus");
	web_add_header("channelId", "ecom");

	web_reg_find("Text=\"status\":\"SUCCESS\"", "SaveCount=getOptionListCountryCode_success", LAST);
	
	lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_15_InlineSM_1b_getOptionList_PhoneCountryCode"));
	
	web_custom_request("getOptionList", 
		"URL=https://{URL}/customer/getOptionList", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t1005.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"optionType\":\"PHONECOUNTRYCODE\"}", 
		LAST);

	if(atoi(lr_eval_string("{getOptionListCountryCode_success}")) > 0){
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_15_InlineSM_1b_getOptionList_PhoneCountryCode"), LR_PASS);
	} else {
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_15_InlineSM_1b_getOptionList_PhoneCountryCode"), LR_FAIL);
		lr_end_transaction("%InlineSkymilesEnrollment_clickJoinSkyMiles%", LR_FAIL);
		lr_exit(LR_EXIT_ITERATION_AND_CONTINUE,LR_AUTO);
	}
	
	web_add_header("Origin", "https://{URL}");
	web_add_auto_header("appId", "cus");
	web_add_auto_header("channelId", "ecom");

	web_reg_find("Text=\"status\":\"SUCCESS\"", "SaveCount=getOptionListType_success", LAST);
	
	lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_15_InlineSM_1c_getOptionList_PhoneType"));
	
	web_custom_request("getOptionList_2", 
		"URL=https://{URL}/customer/getOptionList", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t1007.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"optionType\":\"PHONETYPE\"}", 
		LAST);

	if(atoi(lr_eval_string("{getOptionListType_success}")) > 0){
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_15_InlineSM_1c_getOptionList_PhoneType"), LR_PASS);
	} else {
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_15_InlineSM_1c_getOptionList_PhoneType"), LR_FAIL);
		lr_end_transaction("%InlineSkymilesEnrollment_clickJoinSkyMiles%", LR_FAIL);
		lr_exit(LR_EXIT_ITERATION_AND_CONTINUE,LR_AUTO);
	}
	
	web_reg_find("Text=\"status\":\"SUCCESS\"", "SaveCount=getSecurityQuestionList_success", LAST);
	
	lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_15_InlineSM_1d_getSecurityQuestionList"));
	
	web_custom_request("getSecurityQuestionList", 
		"URL=https://{URL}/customer/getSecurityQuestionList", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t1008.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=../content/dam/delta-applications/complete-purchase/styles/6.0.0-226/assets/fonts/Whitney-Book.otf", "Referer=https://{URL}/content/dam/delta-applications/complete-purchase/styles/6.0.0-226/fonts.css", ENDITEM, 
		LAST);

	if(atoi(lr_eval_string("{getOptionListType_success}")) > 0){
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_15_InlineSM_1d_getSecurityQuestionList"), LR_PASS);
		lr_end_transaction("%InlineSkymilesEnrollment_clickJoinSkyMiles%", LR_PASS);
	} else {
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_15_InlineSM_1d_getSecurityQuestionList"), LR_FAIL);
		lr_end_transaction("%InlineSkymilesEnrollment_clickJoinSkyMiles%", LR_FAIL);
		lr_exit(LR_EXIT_ITERATION_AND_CONTINUE,LR_AUTO);
	}
	
	web_revert_auto_header("appId");
	web_revert_auto_header("channelId");
	
	return 0;
}
