ContinueAndReview()
{

	web_add_header("CacheKey", 
		"{cacheKey}");

	web_add_header("Accept", "application/json");
	web_add_header("Content-Type", "application/json; charset=utf-8");
	
	web_custom_request("checkCustLoginInfo", 
		"URL=https://{URL}/checkout/checkCustLoginInfo?cartId={cartId}", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		LAST);

		web_add_header("X-APP-CHANNEL", 
			"sl-sho");
	
		web_add_header("X-APP-ROUTE", 
			"SL-RSB");
			
		web_add_header("X-APP-REFRESH", 
			"");
	
	
		web_custom_request("defaultsandlookups", 
			"URL=https://{URL}/shop/defaultsandlookups", 
			"Method=GET", 
			"Resource=0", 
			"RecContentType=application/json", 
			"Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}", 
			"Snapshot=t11.inf", 
			"Mode=HTML", 
			EXTRARES, 
			LAST);

		web_add_header("X-APP-CHANNEL", 
			"sl-sho");
	
		web_add_header("X-APP-ROUTE", 
			"SL-RSB");
			
		web_add_header("X-APP-REFRESH", 
			"");
	
	
		web_custom_request("defaultsandlookups", 
			"URL=https://{URL}/shop/defaultsandlookups", 
			"Method=GET", 
			"Resource=0", 
			"RecContentType=application/json", 
			"Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}", 
			"Snapshot=t11.inf", 
			"Mode=HTML", 
			EXTRARES, 
			LAST);
	
//	web_add_header("CacheKey", 
//		"{cacheKey}");
//
//	web_add_header("X-APP-CHANNEL", 
//		"RSB-Booking");
//
//	web_add_header("appId", 
//		"CKO");
//
//	web_add_header("channelId", 
//		"ECOM");
//
//	web_custom_request("getDashBrdData.action", 
//		"URL=https://{URL}/custlogin/getDashBrdData.action", 
//		"Method=GET", 
//		"Resource=0", 
//		"RecContentType=application/json", 
//		"Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}", 
//		"Snapshot=t3.inf", 
//		"Mode=HTML", 
//		LAST);
//
//	web_custom_request("getDashBrdData.action_2", 
//		"URL=https://{URL}/custlogin/getDashBrdData.action", 
//		"Method=POST", 
//		"Resource=0", 
//		"RecContentType=application/json", 
//		"Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}", 
//		"Snapshot=t4.inf", 
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
		"Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t104.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		"Body={\"cartId\":\"{cartId}\",\"channel\":\"MOB\",\"offerId\":\"11111\"}", 
		EXTRARES, 
		//"Url=../content/www/en_US/rsb/review-pay.data.json", "Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/paymentEngine/styles.css", "Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}", ENDITEM, 
		LAST);

	web_revert_auto_header("CacheKey");
	web_revert_auto_header("Content-Type");
	web_revert_auto_header("Accept");
	
	web_reg_find("Text=\"dynamicbannerFlag\":true", "SaveCount=dynamicbannerFlag_count", LAST);
	web_reg_find("Text=\"displayCalculateButtonExCKO\":\"true\"", "SaveCount=displayCalculateButtonExCKO", LAST);
	web_reg_find("Text=\"displayCalculateButtonRnP\":\"true\",", "SaveCount=displayCalculateButtonRnP", LAST);

	web_reg_find("Text=\"displayNewBaggageAllowanceExCKO\":\"true\"", "SaveCount=displayNewBaggageAllowanceExCKO", LAST);
	web_reg_find("Text=\"displayNewBaggageAllowanceRnP\":\"true\",", "SaveCount=displayNewBaggageAllowanceRnP", LAST);
	
	web_url("review-pay.data.json", 
		"URL=https://{URL}/content/www/en_US/rsb/review-pay.data.json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);
	
	web_add_header("CacheKey", "{cacheKey}");
	
	web_add_header("appId", "CKO");

	web_add_header("X-APP-CHANNEL", "RSB-Booking");	
	web_add_header("channelId", "ECOM");
	web_add_header("timeout", "40000");
	
	web_add_header("Accept", "application/json");
	web_add_header("Content-Type", "application/json; charset=utf-8");

	web_reg_save_param_json(
        "ParamName=newTripCost",
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
	
	web_add_header("CacheKey", "{cacheKey}");

	lr_replace("newTripCost", ",", "");
	
	if(strcmp(lr_eval_string("{newTripCost}"),lr_eval_string("{oldTripCost}"))!=0){
		lr_save_string("true", "loyaltyMileageInfoIndicator");
	}
	
	web_add_header("appId", "CKO");

	web_add_header("X-APP-CHANNEL", "RSB-Booking");	
	web_add_header("channelId", "ECOM");
	web_add_header("timeout", "40000");
	
	web_custom_request("baggage", 
		"URL=https://{URL}/checkout/baggage", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t105.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		"Body={\"cartId\":\"{cartId}\",\"channel\":\"MOB\",\"offerId\":\"11111\"}", 
		LAST);

	web_custom_request("allowances", 
		"URL=https://{URL}/baggage/allowances", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t293.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"cartId\":\"{cartId}\"}", 
		LAST);
	
	web_add_header("X-Adapter", "web");	
	web_add_header("cartId", "{cartId}");
	web_add_header("mockResponse", "false");

	web_add_auto_header("Accept", "application/json");
	web_add_auto_header("Content-Type", "application/json");
	
	web_custom_request("retrieveEligibleFop", 
		"URL=https://{URL}/payment/retrieveEligibleFop", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t106.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"cartId\":\"{cartId}\",\"skymilesNbr\":\"\",\"mockResponse\":false}", 
		LAST);

	web_add_header("appId", 
		"cus");

	web_add_header("channelId", 
		"ecom");

	//customerRefId is constant: acc51227-63cb-4dcb-bfd1-354bb85056e1
	web_custom_request("getOffer", 
		"URL=https://{URL}/customer/cardOffer/getOffer", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t37.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"businessIndicator\":\"CONSUMER\",\"currencyCode\":\"{C_currencyCode}\",\"currencySymbol\":\"{C_currencySymbol}\",\"customerRefId\":\"acc51227-63cb-4dcb-bfd1-354bb85056e1\",\"pageId\":\"TPS\",\"tripCost\":\"{newTripCost}\"}", 
		LAST);
	
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
		LAST);

	lr_end_transaction("%LoyaltyMileageInfo%", LR_AUTO);
//Added Aug 8 - there are two calls in browser
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
	
	web_revert_auto_header("CacheKey");

	web_revert_auto_header("X-APP-CHANNEL");

	web_revert_auto_header("appId");

	web_revert_auto_header("channelId");	
	
	web_add_header("CacheKey", "{cacheKey}");
	web_add_header("Accept", "application/json");
	web_add_header("Content-Type", "application/json; charset=utf-8");
	
	web_custom_request("populatePassengers", 
		"URL=https://{URL}/checkout/populatePassengers?cartId={cartId}", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t1244.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		LAST);

	web_url("payment.omniui.json", 
		"URL=https://{URL}/content/www/omniui-payment/payment.omniui.json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}",
		"Snapshot=t1515.inf", 
		"Mode=HTML", 
		LAST);

	web_url("baggage-calculator.cfdata.json", 
		"URL=https://{URL}/content/www/en_US/rsb/baggage-calculator-fragments/baggage-calculator.cfdata.json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}",
		"Snapshot=t61.inf", 
		"Mode=HTML", 
		LAST);
	
//	if(atoi(lr_eval_string("{checkoutBannerFlag}"))==0){
		if(atoi(lr_eval_string("{dynamicbannerFlag_count}"))>0){
			PE_CKO_Banner();
		}
//	}
	
	if(atoi(lr_eval_string("{displayNewBaggageAllowanceRnP}"))>0){
		PE_BaggageCalculator();
	}	
	return 0;
}
