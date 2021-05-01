TripSummaryPage()
{

	lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_04b_TripSummaryPage"));

	lr_start_transaction("%RSB_TripSummary%");

//	web_reg_find("Text=Booking : Delta Air Lines", "SaveCount=tripSummary_count",
//		LAST);

	web_reg_find("Text=Booking", "SaveCount=tripSummary_count",
		LAST);

	web_url("trip-summary", 
		"URL=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{URL}/flight-search/search-results/return?cacheKeySuffix={cacheKey}", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		EXTRARES,
		"Url=https://{contentURL}/content/dam/delta-applications/complete-purchase/jquery-3.2.1.js", "Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/complete-purchase/styles/20.2.47/fonts.css", "Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/complete-purchase/styles/20.2.47/styles.css", "Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/fresh-air-core/20.3.0/css/fresh-air.css", "Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/complete-purchase/20.2.47/runtime.js", "Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/complete-purchase/20.2.47/polyfills.js", "Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/complete-purchase/20.2.47/main.js?", "Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/complete-purchase/20.2.47/idp.datalayer.js", "Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/complete-purchase/20.2.47/MerchantScriptRedirect.js", "Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", ENDITEM, 
		LAST);

	lr_end_transaction("%RSB_TripSummary%", LR_AUTO);

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("getClosestDeltaAirportCode", 
		"URL=https://{URL}/pref/geoLocationService/getClosestDeltaAirportCode", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", 
		"Snapshot=t698.inf", 
		"Mode=HTML", 
		LAST);


	web_url("bcdata.action", 
		"URL=https://{URL}/databroker/bcdata.action", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", 
		"Snapshot=t700.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=../content/dam/delta-applications/fresh-air-core/20.3.0/fonts/CB8837CA379681FED.woff2", "Referer=https://{URL}/content/dam/delta-applications/fresh-air-core/20.3.0/fonts/fresh-air-fonts.css", ENDITEM, 
		LAST);

	web_revert_auto_header("X-Requested-With");

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
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		LAST);
	
	web_url("getdevicetype", 
		"URL=https://{URL}/complete-purchase/getdevicetype", 
		"Resource=0", 
		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", 
		"Snapshot=t812.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("retrieveSearch", 
		"URL=https://{URL}/prefill/retrieveSearch?searchType=RecentSearchesJSON", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		EXTRARES, 
		"Url=../content/dam/delta-applications/complete-purchase/styles/20.3.0/assets/fonts/Whitney-Semibold.otf", "Referer=https://{URL}/content/dam/delta-applications/complete-purchase/styles/20.3.0/fonts.css", ENDITEM, 
		"Url=../content/dam/delta-applications/complete-purchase/styles/20.2.47/assets/fonts/Whitney-Medium.otf", "Referer=https://{URL}/content/dam/delta-applications/complete-purchase/styles/20.2.47/fonts.css", ENDITEM, 
		"Url=../content/dam/delta-applications/complete-purchase/styles/20.2.47/assets/fonts/Whitney-Light.woff", "Referer=https://{URL}/content/dam/delta-applications/complete-purchase/styles/20.2.47/fonts.css", ENDITEM, 
		LAST);
	
	web_url("checkoutErrorMessage.json", 
		"URL=https://{URL}/content/dam/delta-applications/complete-purchase/common/json/checkoutErrorMessage.json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", 
		"Snapshot=t932.inf", 
		"Mode=HTML", 
		LAST);

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
		"Snapshot=t1087.inf", 
		"Mode=HTML", 
		LAST);

	web_url("errormessage.errormessage.json", 
		"URL=https://{URL}/content/www/delta-homepage-redesign-whitelabel/errormessage.errormessage.json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);
	
	web_custom_request("country-language.json", 
		"URL=https://{URL}/content/dam/fresh-air/datasource/country-language.json", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", 
		"Snapshot=t1120.inf", 
		"Mode=HTML", 
		LAST);
	
	web_url("getdevicetype_2", 
		"URL=https://{URL}/complete-purchase/getdevicetype", 
		"Resource=0", 
		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", 
		"Snapshot=t1143.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("en.headerfooter.json", 
		"URL=https://{URL}/content/www/us/en.headerfooter.json", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", 
		"Snapshot=t1266.inf", 
		"Mode=HTML", 
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
		"Snapshot=t1276.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		EXTRARES, 
		"Url=../content/dam/delta-applications/fresh-air-core/20.3.0/fonts/icomoon.woff", "Referer=https://{URL}/content/dam/delta-applications/fresh-air-core/20.3.0/fonts/fresh-air-fonts.css", ENDITEM, 
		"Url=../content/dam/delta-applications/complete-purchase/styles/20.2.47/assets/fonts/Whitney-Semibold.otf", "Referer=https://{URL}/content/dam/delta-applications/complete-purchase/styles/20.2.47/fonts.css", ENDITEM, 
		"Url=../content/dam/delta-applications/complete-purchase/styles/20.2.47/assets/fonts/Whitney-Medium.otf", "Referer=https://{URL}/content/dam/delta-applications/complete-purchase/styles/20.2.47/fonts.css", ENDITEM, 
		"Url=../content/dam/delta-applications/complete-purchase/styles/20.2.47/assets/fonts/Whitney-Light.woff", "Referer=https://{URL}/content/dam/delta-applications/complete-purchase/styles/20.2.47/fonts.css", ENDITEM, 
		LAST);

	web_add_header("Origin", 
		"https://{URL}");

	web_custom_request("getDashBrdData.action_2", 
		"URL=https://{URL}/custlogin/getDashBrdData.action", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={}", 
		LAST);
	
	web_add_auto_header("CacheKey", "{cacheKey}");
	web_add_auto_header("Accept", "application/json");
	web_add_auto_header("Content-Type", "application/json; charset=utf-8");
	
	web_add_header("appId", "CKO");

	web_add_header("X-APP-CHANNEL", "RSB-Booking");	
	web_add_header("channelId", "ECOM");
	web_add_header("timeout", "40000");
	
	web_reg_save_param_json(
        "ParamName=nameParam",
        "QueryString=$.flightProductCart.selectedItinerary[0].trip[*]",
        "SelectAll=Yes",
        "Notfound=warning",
        "SEARCH_FILTERS",
        "Scope=Body",
        "LAST");
 
	web_reg_save_param("C_currencyCode", "LB=\"currencyCode\":\"", "RB=\"", "Notfound=warning", LAST);
	web_reg_save_param("C_currencySymbol", "LB=\"currencySymbol\":\"", "RB=\"", "Notfound=warning", LAST);
	
	web_custom_request("retrievecart", 
		"URL=https://{URL}/checkout/retrievecart", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", 
		"Snapshot=t43.inf", 
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

	web_add_header("CacheKey", 
		"{cacheKey}");

	web_add_header("Accept", "application/json");
	web_add_header("Content-Type", "application/json; charset=utf-8");
	
	web_add_header("X-APP-CHANNEL", 
		"RSB-Booking");

	web_add_header("appId", 
		"CKO");

	web_add_header("channelId", 
		"ECOM");

	web_reg_save_param_json(
        "ParamName=oldTripCost",
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
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={\"cartId\":\"{cartId}\",\"currencyCode\":\"{C_currencyCode}\",\"offerId\":\"\"}", 
		EXTRARES, 
		"Url=../content/dam/delta-applications/fresh-air-core/20.3.0/fonts/3955045D2CF71A4B6.woff2", "Referer=https://{URL}/content/dam/delta-applications/fresh-air-core/20.3.0/fonts/fresh-air-fonts.css", ENDITEM, 
		"Url=../content/dam/delta-applications/fresh-air-core/20.3.0/fonts/AABA9C13AF9C5C638.woff2", "Referer=https://{URL}/content/dam/delta-applications/fresh-air-core/20.3.0/fonts/fresh-air-fonts.css", ENDITEM, 
		"Url=../content/dam/delta-applications/complete-purchase/styles/20.2.47/assets/fonts/icomoon.woff", "Referer=https://{URL}/content/dam/delta-applications/complete-purchase/styles/20.2.47/fonts.css", ENDITEM, 
		"Url=../content/dam/delta-applications/complete-purchase/styles/20.2.47/assets/fonts/Whitney-Bold.otf", "Referer=https://{URL}/content/dam/delta-applications/complete-purchase/styles/20.2.47/fonts.css", ENDITEM, 
		LAST);

	lr_replace("oldTripCost", ",", "");
	
	lr_save_string("false", "loyaltyMileageInfoIndicator");
	
	web_revert_auto_header("Origin");
	
	web_add_auto_header("CacheKey", 
		"{cacheKey}");
	
	web_add_auto_header("X-APP-CHANNEL", 
		"RSB-Booking");

	web_add_auto_header("appId", 
		"CKO");

	web_add_auto_header("channelId", 
		"ECOM");
	
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
		EXTRARES, 
		"Url=../content/dam/delta-applications/fresh-air-core/20.3.0/fonts/5F3C862F467F43533.woff2", "Referer=https://{URL}/content/dam/delta-applications/fresh-air-core/20.3.0/fonts/fresh-air-fonts.css", ENDITEM, 
		"Url=../content/dam/delta-applications/fresh-air-core/20.3.0/fonts/2AEF2F564D90434B1.woff2", "Referer=https://{URL}/content/dam/delta-applications/fresh-air-core/20.3.0/fonts/fresh-air-fonts.css", ENDITEM, 
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
	
	if(atoi(lr_eval_string("{tripSummary_count}"))>0)
	{
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_04b_TripSummaryPage"), LR_AUTO);
			
		
	} else if(atoi(lr_eval_string("{nameParam_count}"))<=0){
		lr_output_message("RSB_Revenue_%s_04b_TripSummaryPage: Trip Summary unavailable.\t%s\t%s\t%s-%s\tCacheKey:%s",lr_eval_string("{RandTripType}"),lr_eval_string("{Origin}"),lr_eval_string("{Destination}"),lr_eval_string("{P_DepartureDate}"),lr_eval_string("{P_ReturnDate}"),lr_eval_string("{cacheKey}"));
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_04b_TripSummaryPage"), LR_AUTO);
			
		lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);		
	}
	else
	{
		lr_output_message("RSB_Revenue_%s_04b_TripSummaryPage: Trip Summary unavailable.\t%s\t%s\t%s-%s\tCacheKey:%s",lr_eval_string("{RandTripType}"),lr_eval_string("{Origin}"),lr_eval_string("{Destination}"),lr_eval_string("{P_DepartureDate}"),lr_eval_string("{P_ReturnDate}"),lr_eval_string("{cacheKey}"));
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_04b_TripSummaryPage"), LR_AUTO);
			
		lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);
	}

//	if (strstr(lr_eval_string("{solutionIdReturn}"), lr_eval_string("{BASICECONOMY}"))!=NULL) {
//		lr_save_int(0, "seatsPurchase");
//	}
	
	return 0;
}
