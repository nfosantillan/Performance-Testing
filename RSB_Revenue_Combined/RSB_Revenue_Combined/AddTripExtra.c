AddTripExtra()
{

	lr_think_time(5);
	
	//lr_save_string(lr_eval_string(lr_paramarr_idx("flightList", atoi(lr_eval_string("{flightIndex}")))), "tempFlightString");

	createTripExtraProductsString();
	web_add_header("CacheKey", "{cacheKey}");
	
	web_add_header("appId", "CKO");

	web_add_header("X-APP-CHANNEL", "RSB-Booking");	
	web_add_header("channelId", "ECOM");
	web_add_header("timeout", "40000");
	web_add_header("appId", "CKO");
	web_add_header("airlineCode", "DL");
	web_add_header("isMobile", "false");
	web_add_header("pageName", "ABC");
	
	lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_06_AddTripExtra"));

	web_custom_request("add", 
		"URL=https://{URL}/merchandize/tripextra/add", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", 
		"Snapshot=t92.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		"Body={\"requester\":{\"cartId\":\"{cartId}\",\"requesterType\":\"CKO\"},\"tripExtraProducts\":[{tripExtraProductString}],\"passengers\":[{passengersString}]}", 
		LAST);

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
		"Snapshot=t93.inf", 
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
		"Snapshot=t1559.inf", 
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
        "ParamName=tripExtraTripCost",
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

	lr_replace("tripExtraTripCost", ",", "");
	
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


	lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_06_AddTripExtra"), LR_AUTO);
	
	return 0;
}
