TripExtrasSearch()
{

	lr_think_time(5);
	
	web_add_header("CacheKey", "{cacheKey}");
	web_add_header("Accept", "application/json");
	web_add_header("Content-Type", "application/json; charset=utf-8");	
	web_add_header("appId", "CKO");
	web_add_header("X-APP-CHANNEL", "RSB-Booking");	
	web_add_header("channelId", "ECOM");
	web_add_header("timeout", "25000");
	web_add_header("airlineCode", "DL");
	web_add_header("isMobile", "false");
	web_add_header("pageName", "ABC");
	
	web_reg_save_param("deptArptCode", "LB=deptArptCode\":\"", "RB=\"", "Notfound=warning",LAST);
	web_reg_save_param("arrArptCode", "LB=arrArptCode\":\"", "RB=\"", "Notfound=warning",LAST);
	web_reg_save_param("tripDepartureDate", "LB=tripDepartureDate\":\"", "RB=\"", "Notfound=warning",LAST);
	web_reg_save_param("flightNum", "LB=flightNum\":\"", "RB=\"", "Notfound=warning",LAST);
	web_reg_save_param("segmentNumber", "LB=segmentNumber\":\"", "RB=\"", "Notfound=warning",LAST);
	web_reg_save_param("airlineCode", "LB=airlineCode\":\"", "RB=\"", "Notfound=warning",LAST);

	web_reg_save_param("errorNumber", "LB=\"code\":\"", "RB=\"", "Notfound=warning", LAST);
	web_reg_save_param("errorMessage", "LB=\"message\":\"", "RB=\"", "Notfound=warning", LAST);
		
	web_reg_save_param_json(
        "ParamName=tripExtraProducts",
        "QueryString=$.tripExtraDisplayOffers.tripExtraProduct[*]",
        "SelectAll=Yes",
        "Notfound=warning",
        "SEARCH_FILTERS",
        "Scope=Body",
        "LAST");
	
	lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_05_TripExtraSearch"));

	lr_continue_on_error(1);
	
	web_custom_request("search", 
		"URL=https://{URL}/merchandize/tripextra/search", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", 
		"Snapshot=t81.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		"Body={\"requester\":{\"cartId\":\"{cartId}\",\"offerId\":\"\",\"offerItemId\":\"\",\"pnrNumber\":\"\",\"requesterType\":\"CKO\"}}", 
		EXTRARES, 
		"Url=/content/www/en_US/rsb/modal.compdata.json", "Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", ENDITEM, 
		"Url=/content/experience-fragments/delta/rsb/terms-and-conditions-modal/trip-extras.data.json", "Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", ENDITEM, 
		LAST);
	
	web_url("modal.compdata.json", 
		"URL=https://{URL}/content/www/en_US/rsb/modal.compdata.json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", 
		"Snapshot=t2213.inf", 
		"Mode=HTML", 
		LAST);

	web_url("trip-extras.data.json", 
		"URL=https://{URL}/content/experience-fragments/delta/rsb/terms-and-conditions-modal/trip-extras.data.json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", 
		"Snapshot=t3543.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_continue_on_error(0);
	
	lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_05_TripExtraSearch"), LR_AUTO);
	
	if(strlen(lr_eval_string("{errorNumber}"))>0){
		lr_error_message("RSB_Revenue_%s_05_TripExtraSearch: Trip Extra not Available for \tORIGIN\t%s\tDESTINATION\t%s\tFLIGHT DATES\t%s-%s\tCacheKey:%s",lr_eval_string("{RandTripType}"),lr_eval_string("{Origin}"),lr_eval_string("{Destination}"),lr_eval_string("{P_DepartureDate}"),lr_eval_string("{P_ReturnDate}"),lr_eval_string("{cacheKey}"));
		lr_save_int(0, "tripExtrasSuccessFlag");
		
	} else if(atoi(lr_eval_string("{tripExtraProducts_count}"))<=0){
		lr_error_message("RSB_Revenue_%s_05_TripExtraSearch: Trip Extra not Available for \tORIGIN\t%s\tDESTINATION\t%s\tFLIGHT DATES\t%s-%s\tCacheKey:%s",lr_eval_string("{RandTripType}"),lr_eval_string("{Origin}"),lr_eval_string("{Destination}"),lr_eval_string("{P_DepartureDate}"),lr_eval_string("{P_ReturnDate}"),lr_eval_string("{cacheKey}"));
		lr_save_int(0, "tripExtrasSuccessFlag");
	}
	
	return 0;
}
