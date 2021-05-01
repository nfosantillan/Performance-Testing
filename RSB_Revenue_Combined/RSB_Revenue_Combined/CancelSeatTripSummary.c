CancelSeatTripSummary()
{
	
	lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_04b_TripSummaryPage"));
	lr_start_transaction("%RSB_TripSummary%");

//	web_reg_find("Text=Booking : Delta Air Lines", "SaveCount=tripSummary2_count",
//		LAST);

	web_reg_find("Text=Booking", "SaveCount=tripSummary2_count",
		LAST);	
	
	web_url("trip-summary", 
		"URL=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{URL}/seat-map/ISM/tripSum", 
		"Snapshot=t77.inf", 
		"Mode=HTML", 
		EXTRARES, 
		LAST);

	lr_end_transaction("%RSB_TripSummary%", LR_AUTO);	
	
	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("getClosestDeltaAirportCode", 
		"URL=https://{URL}/pref/geoLocationService/getClosestDeltaAirportCode", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);


	web_url("bcdata.action", 
		"URL=https://{URL}/databroker/bcdata.action", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		EXTRARES, 
		LAST);

	web_revert_auto_header("X-Requested-With");

	web_add_header("CacheKey", 
		"{cacheKey}");

	web_add_header("X-APP-CHANNEL", 
		"RSB-Booking");

	web_add_header("appId", 
		"CKO");

	web_add_header("channelId", 
		"ECOM");

	web_custom_request("getDashBrdData.action", 
		"URL=https://{URL}/custlogin/getDashBrdData.action", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("CacheKey", 
		"{cacheKey}");

	web_add_header("Accept", "application/json");
	web_add_header("Content-Type", "application/json; charset=utf-8");
	
	web_custom_request("checkCustLoginInfo", 
		"URL=https://{URL}/checkout/checkCustLoginInfo?cartId={cartId}", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho",
		"Snapshot=t2225.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		LAST);

	web_reg_find("Text=\"dynamicbannerFlag\":true", "SaveCount=dynamicbannerFlag_count", LAST);
	
	web_url("trip_summary.data.json", 
		"URL=https://{URL}/content/www/en_US/rsb/trip_summary.data.json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", 
		"Snapshot=t1425.inf", 
		"Mode=HTML", 
		LAST);
	
	web_custom_request("retrieveSearch", 
		"URL=https://{URL}/prefill/retrieveSearch?searchType=RecentSearchesJSON", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		EXTRARES, 
		LAST);

//	web_custom_request("getDashBrdData.action_2", 
//		"URL=https://{URL}/custlogin/getDashBrdData.action", 
//		"Method=POST", 
//		"Resource=0", 
//		"RecContentType=application/json", 
//		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", 
//		"Snapshot=t12.inf", 
//		"Mode=HTML", 
//		"EncType=application/json; charset=utf-8", 
//		"Body={}", 
//		LAST);
	
	web_add_auto_header("CacheKey", "{cacheKey}");
	web_add_auto_header("Accept", "application/json");
	web_add_auto_header("Content-Type", "application/json; charset=utf-8");
	
	web_add_header("appId", "CKO");

	web_add_header("X-APP-CHANNEL", "RSB-Booking");	
	web_add_header("channelId", "ECOM");
	web_add_header("timeout", "40000");
	
	web_custom_request("retrievecart", 
		"URL=https://{URL}/checkout/retrievecart", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", 
		"Snapshot=t78.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		"Body={\"cartId\":\"{cartId}\",\"channel\":\"MOB\",\"offerId\":\"11111\"}", 
		EXTRARES, 
		LAST);

	web_revert_auto_header("CacheKey");
	web_revert_auto_header("Content-Type");
	web_revert_auto_header("Accept");

	web_add_header("CacheKey", "{cacheKey}");
	web_add_header("Accept", "application/json");
	web_add_header("Content-Type", "application/json; charset=utf-8");

	web_custom_request("populatePassengers", 
		"URL=https://{URL}/checkout/populatePassengers?cartId={cartId}", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho",
		"Snapshot=t1552.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		EXTRARES, 
		LAST);
	
	web_add_auto_header("CacheKey", 
		"{cacheKey}");

	web_add_auto_header("X-APP-CHANNEL", 
		"RSB-Booking");

	web_add_auto_header("appId", 
		"CKO");

	web_add_auto_header("channelId", 
		"ECOM");

	web_add_auto_header("Origin", 
		"https://{URL}");

	web_add_header("Accept", "application/json");
	web_add_header("Content-Type", "application/json; charset=utf-8");

	web_reg_save_param_json(
        "ParamName=saveSeatsTripCost",
        "QueryString=$.totalAmountDue.currency.amount",
        "Notfound=warning",
        "SEARCH_FILTERS",
        "Scope=Body",
        "LAST");
	
	web_custom_request("tripTotalForAllPax", 
		"URL=https://{URL}/checkout/tripTotalForAllPax", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho",
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={\"cartId\":\"{cartId}\",\"currencyCode\":\"{C_currencyCode}\",\"offerId\":\"\"}", 
		LAST);

	web_revert_auto_header("Origin");

	lr_replace("saveSeatsTripCost", ",", "");
	
	lr_save_string("true", "loyaltyMileageInfoIndicator");
	
	lr_start_transaction("%LoyaltyMileageInfo%");

	web_custom_request("loyaltyMileageInfo", 
		"URL=https://{URL}/checkout/loyaltyMileageInfo", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", 
		"Snapshot=t2215.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={\"cartId\":\"{cartId}\",\"loyaltyMileageInfoIndicator\":{loyaltyMileageInfoIndicator}}",
		LAST);

	lr_end_transaction("%LoyaltyMileageInfo%", LR_AUTO);

//	lr_start_transaction("%LoyaltyMileageInfo%");
//
//	web_custom_request("loyaltyMileageInfo", 
//		"URL=https://{URL}/checkout/loyaltyMileageInfo", 
//		"Method=POST", 
//		"Resource=0", 
//		"RecContentType=application/json", 
//		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", 
//		"Snapshot=t2215.inf", 
//		"Mode=HTML", 
//		"EncType=application/json; charset=UTF-8", 
//		"Body={\"cartId\":\"{cartId}\",\"loyaltyMileageInfoIndicator\":{loyaltyMileageInfoIndicator}}",
//		LAST);
//
//	lr_end_transaction("%LoyaltyMileageInfo%", LR_AUTO);
	
	web_revert_auto_header("CacheKey");

	web_revert_auto_header("X-APP-CHANNEL");

	web_revert_auto_header("appId");

	web_revert_auto_header("channelId");

//	web_url("credit-offer-config.json", 
//		"URL=https://{URL}/content/dam/delta-applications/fab/1.0.19/assets/json/credit-offer-config.json", 
//		"Resource=0", 
//		"RecContentType=application/json", 
//		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", 
//		"Snapshot=t2236.inf", 
//		"Mode=HTML", 
//		LAST);

	web_custom_request("contentfragment.fabdata.json", 
		"URL=https://{URL}/content/www/en_US/rsb/fabzeus/gold/jcr:content/par/contentfragment.fabdata.json", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho",
		"Snapshot=t1559.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		EXTRARES, 
		LAST);
	
	web_add_header("appId", 
		"enrl");

	web_add_header("channelId", 
		"ecom");

	//customerRefId is constant: acc51227-63cb-4dcb-bfd1-354bb85056e1
//	web_custom_request("getOffer", 
//		"URL=https://{URL}/customer/cardOffer/getOffer", 
//		"Method=POST", 
//		"Resource=0", 
//		"RecContentType=application/json", 
//		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", 
//		"Snapshot=t37.inf", 
//		"Mode=HTML", 
//		"EncType=application/json", 
//		"Body={\"businessIndicator\":\"CONSUMER\",\"currencyCode\":\"{C_currencyCode}\",\"currencySymbol\":\"{C_currencySymbol}\",\"customerRefId\":\"acc51227-63cb-4dcb-bfd1-354bb85056e1\",\"pageId\":\"TPS\",\"tripCost\":\"{oldTripCost}\"}", 
//		LAST);
	
	lr_start_transaction("%z_FAB_getOffer%");
	lr_start_transaction("%z_FAB_getOffer_TripSummary%");

		lr_start_transaction("%z_FAB_getOffer_REV%");
		lr_start_transaction("%z_FAB_getOffer_TripSummary_REV%");
		
	web_reg_find("Text=\"status\":\"SUCCESS\"", "SaveCount=getOffer_count",
		LAST);
	web_reg_save_param("errorMessage", "LB=\"message\":\"", "RB=\"", "Notfound=warning", LAST);
	
	web_custom_request("getOffer", 
		"URL=https://{URL}/enrollment/cardOffer/getOffer", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho",
		"Snapshot=t44.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"applicationType\":\"revenue\",\"bannerTemplateId\":\"G\",\"browserAreaText\":\"1280x913\",\"customerRefId\":\"{customerReferenceId}\",\"fromMobile\":false,\"ipDerivedPostalCode\":\"\",\"pageId\":\"trip-summary-rev\",\"privateBrowsing\":false,\"referringUrlText\":\"\",\"screenResolutionText\":\"1280x1024\",\"taxesAndFeesCost\":\"\",\"tripCost\":\"{oldTripCost}\",\"tripMilesCost\":\"0\"}", //163.10 
		EXTRARES, 
		LAST);

	if(atoi(lr_eval_string("{getOffer_count}"))<=0){
		lr_end_transaction("%z_FAB_getOffer%", LR_FAIL);
		lr_end_transaction("%z_FAB_getOffer_TripSummary%", LR_FAIL);

			lr_end_transaction("%z_FAB_getOffer_REV%", LR_FAIL);
			lr_end_transaction("%z_FAB_getOffer_TripSummary_REV%", LR_FAIL);
			
		lr_error_message("[REV] Get Offer not Loaded in Trip Summary. Message: %s.", lr_eval_string("{errorMessage}"));
	} else {
		lr_end_transaction("%z_FAB_getOffer%", LR_AUTO);
		lr_end_transaction("%z_FAB_getOffer_TripSummary%", LR_AUTO);
		
		lr_end_transaction("%z_FAB_getOffer_REV%", LR_AUTO);
		lr_end_transaction("%z_FAB_getOffer_TripSummary_REV%", LR_AUTO);		
	}

	if(atoi(lr_eval_string("{dynamicbannerFlag_count}"))>0){
		PE_CKO_Banner();
	}
	
	if(atoi(lr_eval_string("{tripSummary2_count}"))>0)
	{
		
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_04b_TripSummaryPage"), LR_AUTO);	
		
	}
	else
	{
		lr_output_message("RSB Cancel Seats in Revenue Trip Summary Page: \tCartID:%s\tCacheKey:%s",lr_eval_string("{cartId}"), lr_eval_string("{cacheKey}"));
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_04b_TripSummaryPage"), LR_AUTO);
		lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);
	}
	
	return 0;
}
