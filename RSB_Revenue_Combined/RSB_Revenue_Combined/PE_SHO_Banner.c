PE_SHO_Banner()
{

	web_reg_save_param_custom(lr_eval_string("{p_dynamicBannerRequest}"), "campaignIdString", "\"campaignId\":", "}");
	
	if(strstr("[", lr_eval_string("{campaignIdString}"))==NULL){
		lr_save_string(lr_eval_string("[{campaignIdString},\"shopping-lite:flightresult-alert-modal\"],\"format\":\"json\""), "campaignIdStringFinal");
	}
	
	lr_replace("p_dynamicBannerRequest", lr_eval_string("{campaignIdString}"), lr_eval_string("{campaignIdStringFinal}"));
	
	web_add_header("X-APP-CHANNEL", 
						"RSB-Booking");
	
	lr_start_transaction("%SHO_getMultiplePersonalizedContent%");

	web_custom_request("getMultiplePersonalizedContent", 
		"URL=https://{URL}/personalization-api/getMultiplePersonalizedContent", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={p_dynamicBannerRequest}", 
		LAST);
	
	lr_end_transaction("%SHO_getMultiplePersonalizedContent%", LR_PASS);
	
	return 0;
}
