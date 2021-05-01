inlineSM_enterUserAndPW()
{
	web_add_header("Origin", "https://{URL}");
	web_add_header("appId", "cus");
	web_add_header("channelId", "ecom");

	web_reg_find("Text=\"status\":\"SUCCESS\",\"isUnique\":true", "SaveCount=checkUserUnique_success", LAST);

	lr_think_time(3);
	lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_15_InlineSM_2_checkUsernameUnique"));
	
	web_custom_request("checkUsernameUnique", 
		"URL=https://{URL}/customer/checkUsernameUnique", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t2004.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"inputData\":\"{firstPassengerFirstName}{firstPassengerLastName}\"}", 
		LAST);

	if(atoi(lr_eval_string("{checkUserUnique_success}")) > 0){
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_15_InlineSM_2_checkUsernameUnique"), LR_PASS);
	} else {
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_15_InlineSM_2_checkUsernameUnique"), LR_FAIL);
		lr_exit(LR_EXIT_ITERATION_AND_CONTINUE,LR_AUTO);
	}
	
	
//	web_add_header("Origin", "https://{URL}");
//	web_add_header("appId", "cus");
//	web_add_header("channelId","ecom");
//
//	web_custom_request("checkUsernameUnique_2", 
//		"URL=https://{URL}/customer/checkUsernameUnique", 
//		"Method=POST", 
//		"Resource=0", 
//		"RecContentType=application/json", 
//		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", 
//		"Snapshot=t13.inf", 
//		"Mode=HTML", 
//		"EncType=application/json", 
//		"Body={\"inputData\":\"deltabot1234\"}", 
//		LAST);

	return 0;
}
