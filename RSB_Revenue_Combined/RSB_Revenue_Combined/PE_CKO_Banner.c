PE_CKO_Banner()
{
	if(strcmp(lr_eval_string("{RandTripType}"), "OW")==0){
		lr_save_string("ONE_WAY", "CKO_TripType");
	} else if(strcmp(lr_eval_string("{RandTripType}"), "RT")==0){
		lr_save_string("ROUND_TRIP", "CKO_TripType");
	} else {
		lr_save_string("MULTICITY", "CKO_TripType");
	}

	lr_save_string("", "covidBannerModal");
	
	if(atoi(lr_eval_string("{covidBannerFlag}"))>0){
		lr_save_string(",\"rsb:tripsummary-alert-modal\",\"rsb:review-pay-alert-modal\",\"rsb:express-checkout-alert-modal\",\"rsb:confirmation-alert-modal\"", "covidBannerModal");
	}
	
	web_reg_find("SaveCount=reviewPayBanner","Text=rsb:review-pay-dynamic-banner",LAST);
	web_reg_find("SaveCount=expCKOBanner","Text=rsb:express-checkout-dynamic-banner",LAST);
	web_reg_find("SaveCount=tripSummaryBanner","Text=rsb:tripsummary-dynamic-banner",LAST);
	web_reg_find("SaveCount=confirmationBanner","Text=rsb:confirmation-dynamic-banner",LAST);
	
	lr_start_transaction("%CKO_getMultiplePersonalizedContent%");

	web_custom_request("getMultiplePersonalizedContent", 
		"URL=https://{URL}/personalization-api/getMultiplePersonalizedContent", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={\"userdata\":{\"destination\":\"{Destination}\",\"triptype\":\"{CKO_TripType}\"},\"requestparam\":{\"campaignId\":[\"rsb:review-pay-dynamic-banner\",\"rsb:express-checkout-dynamic-banner\",\"rsb:tripsummary-dynamic-banner\",\"rsb:confirmation-dynamic-banner\"{covidBannerModal}],\"format\":\"json\"}}", 
		LAST);
	
	lr_save_int(1, "checkoutBannerFlag");
	
	if(atoi(lr_eval_string("{reviewPayBanner}"))<=0){
		lr_end_transaction("%CKO_getMultiplePersonalizedContent%", LR_PASS);
		
		lr_error_message("PE_CheckoutBanner: Review Pay Banner not Present.\tOrigin:\t%s\tDestination:\t%s\tTripType:\t%s", lr_eval_string("{Origin}"),lr_eval_string("{Destination}"),lr_eval_string("{CKO_TripType}"));
		lr_start_transaction("%CKO_getMultiplePersonalizedContent_BLANK%");
		lr_end_transaction("%CKO_getMultiplePersonalizedContent_BLANK%", LR_PASS);
		return 0;
	} else 	if(atoi(lr_eval_string("{expCKOBanner}"))<=0){
		lr_end_transaction("%CKO_getMultiplePersonalizedContent%", LR_PASS);
		
		lr_error_message("PE_CheckoutBanner: Express Checkout Banner not Present.\tOrigin:\t%s\tDestination:\t%s\tTripType:\t%s", lr_eval_string("{Origin}"),lr_eval_string("{Destination}"),lr_eval_string("{CKO_TripType}"));
		lr_start_transaction("%CKO_getMultiplePersonalizedContent_BLANK%");
		lr_end_transaction("%CKO_getMultiplePersonalizedContent_BLANK%", LR_PASS);		
		return 0;
	} else 	if(atoi(lr_eval_string("{tripSummaryBanner}"))<=0){
		lr_end_transaction("%CKO_getMultiplePersonalizedContent%", LR_PASS);
		
		lr_error_message("PE_CheckoutBanner: Trip Summary Banner not Present.\tOrigin:\t%s\tDestination:\t%s\tTripType:\t%s", lr_eval_string("{Origin}"),lr_eval_string("{Destination}"),lr_eval_string("{CKO_TripType}"));
		lr_start_transaction("%CKO_getMultiplePersonalizedContent_BLANK%");
		lr_end_transaction("%CKO_getMultiplePersonalizedContent_BLANK%", LR_PASS);		
		return 0;
	} else 	if(atoi(lr_eval_string("{confirmationBanner}"))<=0){
		lr_end_transaction("%CKO_getMultiplePersonalizedContent%", LR_PASS);
		
		lr_error_message("PE_CheckoutBanner: Confirmation Banner not Present.\tOrigin:\t%s\tDestination:\t%s\tTripType:\t%s", lr_eval_string("{Origin}"),lr_eval_string("{Destination}"),lr_eval_string("{CKO_TripType}"));
		lr_start_transaction("%CKO_getMultiplePersonalizedContent_BLANK%");
		lr_end_transaction("%CKO_getMultiplePersonalizedContent_BLANK%", LR_PASS);		
		return 0;
	} 
	
	lr_end_transaction("%CKO_getMultiplePersonalizedContent%", LR_AUTO);
	
	lr_start_transaction("%CKO_getMultiplePersonalizedContent_NOTBLANK%");
	lr_end_transaction("%CKO_getMultiplePersonalizedContent_NOTBLANK%", LR_PASS);
	return 0;
}
