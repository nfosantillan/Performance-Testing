Homepage()
{
	web_cache_cleanup();

	web_cleanup_cookies();

	web_set_max_html_param_len("999999");

	lr_think_time(5);

	web_set_sockets_option("SSL_VERSION", "TLS1.2");
//;{contentURL}
	//web_set_sockets_option("ALLOW_ONLY_HOSTS","{URL};{contentURL};stg-content.delta.com;si.delta.com;0eafstag.cardinalcommerce.com;merchantacsstag.cardinalcommerce.com");
	if(atoi(lr_eval_string("{analyticsFlow}"))==0){
		web_set_sockets_option("ALLOW_ONLY_HOSTS","{URL};{contentURL};0eafstag.cardinalcommerce.com;merchantacsstag.cardinalcommerce.com");
	}
	
	web_reg_find("SaveCount=HPcheck","Text=Flights: Book Direct with",LAST);
	
	lr_start_transaction("%HomePage%");	

	web_add_cookie("ignorePersistenceCookie=true; DOMAIN={contentURL}");
	web_add_cookie("pref=en-us; DOMAIN={URL}");
	web_add_cookie("mobile=N;DOMAIN={URL}");
	web_add_header("devicetype", "desktop");
	
	web_url("{URL}", 
		"URL=https://{URL}/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		EXTRARES, 	
		LAST);

	web_url("getClosestDeltaAirportCode", 
		"URL=https://{URL}/pref/geoLocationService/getClosestDeltaAirportCode", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	web_url("bcdata.action", 
		"URL=https://{URL}/databroker/bcdata.action", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		EXTRARES,
		"Url=../content/dam/delta-applications/fresh-air-core/20.3.0/fonts/CB8837CA379681FED.woff2", "Referer=https://{URL}/content/dam/delta-applications/fresh-air-core/20.3.0/fonts/fresh-air-fonts.css", ENDITEM, 
		LAST);

	web_url("errormessage.errormessage.json", 
		"URL=https://{URL}/content/www/delta-homepage-redesign-whitelabel/errormessage.errormessage.json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin", 
		"https://{URL}");

	web_custom_request("getDashBrdData", 
		"URL=https://{URL}/login/login/getDashBrdData", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={}", 
		LAST);

	web_custom_request("en.headerfooter.json",
		"URL=https://{URL}/content/www/us/en.headerfooter.json", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);
	
	web_url("home.content.html", 
		"URL=https://{URL}/content/www/us/en/home.content.html", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{URL}/", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("country-language.json", 
		"URL=https://{URL}/content/dam/fresh-air/datasource/country-language.json", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);
	
	web_url("getClosestDeltaAirportCode_2", 
		"URL=https://{URL}/pref/geoLocationService/getClosestDeltaAirportCode", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin", 
		"https://{URL}");

	web_custom_request("getDashBrdData_2", 
		"URL=https://{URL}/login/login/getDashBrdData", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={}", 
		LAST);
	
	web_custom_request("retrieveSearch", 
		"URL=https://{URL}/prefill/retrieveSearch?searchType=RecentSearchesJSON", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		LAST);
	
	web_url("devicetype", 
		"URL=https://{URL}/home/devicetype", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin", 
		"https://{URL}");

	web_custom_request("getDashBrdData_3", 
		"URL=https://{URL}/login/login/getDashBrdData", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={}", 
		LAST);
	
	web_url("bcdata.action_2", 
		"URL=https://{URL}/databroker/bcdata.action", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=https://{contentURL}/content/dam/delta-applications/fresh-air-core/20.3.0/images/flyout-close.svg", "Referer=https://{contentURL}/content/dam/delta-applications/fresh-air-core/20.3.0/css/fresh-air.css", ENDITEM, 
		"Url=../content/dam/delta-applications/fresh-air-core/20.3.0/fonts/A32A3E152E391B379.woff2", "Referer=https://{URL}/content/dam/delta-applications/fresh-air-core/20.3.0/fonts/fresh-air-fonts.css", ENDITEM, 
		"Url=../content/dam/delta-applications/fresh-air-core/20.3.0/fonts/icomoon.woff", "Referer=https://{URL}/content/dam/delta-applications/fresh-air-core/20.3.0/fonts/fresh-air-fonts.css", ENDITEM, 
		"Url=../content/dam/delta-applications/fresh-air-core/20.3.0/fonts/3955045D2CF71A4B6.woff2", "Referer=https://{URL}/content/dam/delta-applications/fresh-air-core/20.3.0/fonts/fresh-air-fonts.css", ENDITEM, 
		"Url=../content/dam/delta-applications/fresh-air-core/20.3.0/fonts/AABA9C13AF9C5C638.woff2", "Referer=https://{URL}/content/dam/delta-applications/fresh-air-core/20.3.0/fonts/fresh-air-fonts.css", ENDITEM, 
		"Url=../content/dam/delta-applications/fresh-air-core/20.3.0/fonts/5F3C862F467F43533.woff2", "Referer=https://{URL}/content/dam/delta-applications/fresh-air-core/20.3.0/fonts/fresh-air-fonts.css", ENDITEM, 
		"Url=../content/dam/delta-applications/fresh-air-core/20.3.0/fonts/C2031C89118431E67.woff2", "Referer=https://{URL}/content/dam/delta-applications/fresh-air-core/20.3.0/fonts/fresh-air-fonts.css", ENDITEM, 
		LAST);

	lr_continue_on_error(1);
	
	web_add_header("Origin", "https://{URL}");
	
	lr_start_transaction("%getMultiplePersonalizedContent%");

	web_custom_request("getMultiplePersonalizedContent", 
		"URL=https://{URL}/personalization-api/getMultiplePersonalizedContent", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{URL}/", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
//		"Body={\"userdata\":{\"closestAirportStateCode\":\"GA\",\"closestAirport\":\"ATL\",\"mbActionIndicator\":\"Y\",\"mbIsLoggedIn\":\"N\",\"ckLangCode\":\"en\",\"ckCountry\":\"us\",\"pageName\":\"home\",\"channelId\":\"ecomm\"},\"requestparam\":{\"campaignId\":[\"homepage:banner-promoquilt\",\"homepage:homepagesection\"],\"format\":\"html\"}}", 
		"Body={\"userdata\":{\"closestAirportStateCode\":\"GA\",\"closestAirport\":\"ATL\",\"userData\":{},\"v01\":\"\",\"v02\":\"\",\"v03\":\"Y\",\"v04\":\"\",\"v05\":\"\",\"v06\":\"\",\"v07\":\"\",\"v08\":\"\",\"v09\":\"\",\"v10\":\"\",\"v11\":\"\",\"v12\":\"\",\"v13\":\"\",\"v14\":\"\",\"v15\":\"\",\"v16\":\"\",\"v17\":\"\",\"v18\":\"\",\"v19\":\"\",\"v20\":\"\",\"v21\":\"\",\"v22\":\"\",\"v23\":\"\",\"v24\":\"\",\"v27\":\"\",\"v29\":\"N\",\"v38\":\"\",\"v39\":\"\",\"v40\":\"\",\"ckLangCode\":\"en\",\""
		"ckCountry\":\"us\",\"pageName\":\"home\",\"channelId\":\"ecomm\"},\"requestparam\":{\"campaignId\":[\"homepage:banner-promoquilt\",\"homepage:homepagesection\"],\"format\":\"html\"}}", 
		EXTRARES,
		"Url=https://{contentURL}/content/dam/delta-applications/fresh-air-core/20.3.0/images/carot-redpromo-quilt.svg", "Referer=https://{contentURL}/content/dam/delta-applications/fresh-air-core/20.3.0/css/fresh-air.css", ENDITEM, 
		LAST);

	lr_end_transaction("%getMultiplePersonalizedContent%", LR_AUTO);
	
	lr_continue_on_error(0);
	
//	web_add_auto_header("Origin", 
//		"{URL}");
//	
//	lr_start_transaction("%getpersonalizedContent%");
//	
//	web_custom_request("getpersonalizedContent", 
//		"URL=https://{URL}/personalization-api/getpersonalizedContent", 
//		"Method=POST", 
//		"Resource=0", 
//		"RecContentType=text/html", 
//		"Referer=https://{URL}/",  
//		"Snapshot=t15.inf", 
//		"Mode=HTML", 
//		"EncType=application/json; charset=UTF-8", 
//		"Body={\"userdata\":{\"closestAirportStateCode\":\"GA\",\"closestAirport\":\"ATL\",\"mbActionIndicator\":\"Y\",\"mbIsLoggedIn\":\"N\",\"ckLangCode\":\"en\",\"ckCountry\":\"us\",\"pageName\":\"home\",\"channelId\":\"ecomm\"},\"requestparam\":{\"campaignId\":\"homepage:homepagehero\",\"format\":\"html\"}}", 
//		LAST);
//
//	lr_end_transaction("%getpersonalizedContent%", LR_AUTO);
//
//	lr_start_transaction("%getpersonalizedContent%");
//
//	web_custom_request("getpersonalizedContent_2", 
//		"URL=https://{URL}/personalization-api/getpersonalizedContent", 
//		"Method=POST", 
//		"Resource=0", 
//		"RecContentType=text/html", 
//		"Referer=https://{URL}/", 
//		"Snapshot=t16.inf", 
//		"Mode=HTML", 
//		"EncType=application/json; charset=UTF-8", 
//		"Body={\"userdata\":{\"closestAirportStateCode\":\"GA\",\"closestAirport\":\"ATL\",\"mbActionIndicator\":\"Y\",\"mbIsLoggedIn\":\"N\",\"ckLangCode\":\"en\",\"ckCountry\":\"us\",\"pageName\":\"home\",\"channelId\":\"ecomm\"},\"requestparam\":{\"campaignId\":\"homepage:banner\",\"format\":\"html\"}}", 
//		LAST);
//
//	lr_end_transaction("%getpersonalizedContent%", LR_AUTO);
//
//	lr_start_transaction("%getpersonalizedContent%");
//
//	web_custom_request("getpersonalizedContent_3", 
//		"URL=https://{URL}/personalization-api/getpersonalizedContent", 
//		"Method=POST", 
//		"Resource=0", 
//		"RecContentType=text/html", 
//		"Referer=https://{URL}/", 
//		"Snapshot=t17.inf", 
//		"Mode=HTML", 
//		"EncType=application/json; charset=UTF-8", 
//		"Body={\"userdata\":{\"closestAirportStateCode\":\"GA\",\"closestAirport\":\"ATL\",\"mbActionIndicator\":\"Y\",\"mbIsLoggedIn\":\"N\",\"ckLangCode\":\"en\",\"ckCountry\":\"us\",\"pageName\":\"home\",\"channelId\":\"ecomm\"},\"requestparam\":{\"campaignId\":\"homepage:homepagepromoquilt\",\"format\":\"html\"}}", 
//		LAST);
//
//	lr_end_transaction("%getpersonalizedContent%", LR_AUTO);
//
//	web_revert_auto_header("Origin");
//
//	lr_start_transaction("%getpersonalizedContent%");
//
//	web_custom_request("getpersonalizedContent_4", 
//		"URL=https://{URL}/personalization-api/getpersonalizedContent", 
//		"Method=POST", 
//		"Resource=0", 
//		"RecContentType=text/html", 
//		"Referer=https://{URL}/", 
//		"Snapshot=t18.inf", 
//		"Mode=HTML", 
//		"EncType=application/json; charset=UTF-8", 
//		"Body={\"userdata\":{\"closestAirportStateCode\":\"GA\",\"closestAirport\":\"ATL\",\"mbActionIndicator\":\"Y\",\"mbIsLoggedIn\":\"N\",\"ckLangCode\":\"en\",\"ckCountry\":\"us\",\"pageName\":\"home\",\"channelId\":\"ecomm\"},\"requestparam\":{\"campaignId\":\"homepage:homepagesection\",\"format\":\"html\"}}", 
//		LAST);
//
//	lr_end_transaction("%getpersonalizedContent%", LR_AUTO);
	
	if(atoi(lr_eval_string("{HPcheck}"))>0)
	{
		//lr_end_transaction("FlightBooking_Award_Oneway_00_Homepage", LR_PASS);
		lr_end_transaction("%HomePage%", LR_PASS);
		
	}
	else
	{
		//lr_end_transaction("FlightBooking_Award_Oneway_00_Homepage", LR_FAIL);
		lr_end_transaction("%HomePage%", LR_FAIL);
		lr_exit(LR_EXIT_ITERATION_AND_CONTINUE,LR_AUTO);
	}
	
	if(atoi(lr_eval_string("{PSD2}"))==1){
		lr_save_string(lr_eval_string("{Origin_psd2}"), "Origin");
		lr_save_string(lr_eval_string("{Destination_psd2}"), "Destination");
		lr_save_string(lr_eval_string("{Origin_psd2}"), "FinalDestination");
		lr_save_string(lr_eval_string("{ccNum_psd2}"), "ccNum");
		lr_save_string(lr_eval_string("{ccType_psd2}"), "ccType");
		lr_save_string(lr_eval_string("{cvv_psd2}"), "cvv");
		lr_save_string(lr_eval_string("{lastFourDigits_psd2}"), "lastFourDigits");
		
		lr_save_int(0, "tripExtrasPurchase");
		lr_save_int(0, "insurancePurchase");
	}
	
	if(atoi(lr_eval_string("{METERING}"))==1){
		lr_save_string(lr_eval_string("{OriginMetering}"), "Origin");
		lr_save_string(lr_eval_string("{DestinationMetering}"), "Destination");
		lr_save_string(lr_eval_string("{OriginMetering}"), "FinalDestination");
		
		lr_save_int(0, "tripExtrasPurchase");
		lr_save_int(0, "insurancePurchase");		
	}

	if(strcmp(lr_eval_string("{Origin}"), lr_eval_string("{Destination}"))==0){
		lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);
	}
	
	lr_save_string(lr_eval_string("{Origin}"), "FinalDestination");
	
	SearchFlight();
	
	return 0;
}