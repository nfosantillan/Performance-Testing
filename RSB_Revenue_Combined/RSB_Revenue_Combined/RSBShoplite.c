RSBShoplite()
{
	web_cache_cleanup();

	web_cleanup_cookies();

	web_set_max_html_param_len("999999");
	
	web_set_sockets_option("SSL_VERSION", "TLS1.2");
	//web_set_sockets_option("ALLOW_ONLY_HOSTS","{URL};{contentURL};stg-content.delta.com;si.delta.com;0eafstag.cardinalcommerce.com;merchantacsstag.cardinalcommerce.com");
	web_set_sockets_option("ALLOW_ONLY_HOSTS","{URL};{contentURL};0eafstag.cardinalcommerce.com;merchantacsstag.cardinalcommerce.com");
	web_add_header("Upgrade-Insecure-Requests", 
		"1");
	
//	web_add_header("X-APP-CHANNEL", "sl-sho");
//	web_add_header("X-APP-ROUTE", "SL-RSB");
	web_add_header("Accept-Encoding", "gzip, deflate, br");
	
	web_add_cookie("ignorePersistenceCookie=true; DOMAIN={contentURL}");
	web_add_cookie("pref=en-us; DOMAIN={URL}");
	web_add_cookie("mobile=N;DOMAIN={URL}");
	web_add_header("devicetype", "desktop");
	
	web_reg_find("Text/IC=Book a Flight", "SaveCount=Homepage_Check",
		LAST);

	//web_reg_save_param("cacheKey", "LB=cacheKey\":\"", "RB=\"", LAST);
	
	
	lr_start_transaction(lr_eval_string("RSB_Revenue_00_RSBSearchFlightPage"));

	web_url("book-a-flight", 
		"URL=https://{URL}/flight-search/book-a-flight", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		EXTRARES,
		"Url=../admin/ruxitagentjs_ICA2SVfghjqrx_10171190801163814.js", ENDITEM, 
		"Url=../content/dam/delta-applications/fresh-air-core/20.3.0/css/fresh-air.css", ENDITEM, 
		"Url=../content/dam/delta-applications/fresh-air-core/20.3.0/fonts/fresh-air-fonts.css", ENDITEM, 
		"Url=../content/dam/delta-applications/flight-search/static/styles/11.0.124/fonts/fonts.css", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/flight-search/static/styles/11.0.124/css/styles.css", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/flight-search/static/v20.3.116/vendor/jquery-3.2.1.js", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/flight-search/static/v20.3.116/vendor/tracker.js", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/flight-search/static/v20.3.116/vendor/delta.utils.logger.js", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/flight-search/static/v20.3.116/vendor/idp.datalayer.js", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/flight-search/static/v20.3.116/runtime.js", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/flight-search/static/v20.3.116/polyfills.js", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/flight-search/static/v20.3.116/main.js", ENDITEM, 
		"Url=https://{contentURL}/content/www/us/en.damAssetRender.20180508T1619553790400.html/content/dam/delta_homepage_redesign/Logo/Delta%20Logo.svg", ENDITEM, 
		"Url=https://{contentURL}/content/www/us/en.damAssetRender.20180508T1619555470400.html/content/dam/delta_homepage_redesign/Logo/Sky%20Team.svg", ENDITEM, 		
		LAST);

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("getClosestDeltaAirportCode", 
		"URL=https://{URL}/pref/geoLocationService/getClosestDeltaAirportCode", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/flight-search/book-a-flight", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);


	web_url("bcdata.action", 
		"URL=https://{URL}/databroker/bcdata.action", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/flight-search/book-a-flight", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		EXTRARES, 
		LAST);

	web_revert_auto_header("X-Requested-With");


	web_custom_request("en.headerfooter.json", 
		"URL=https://{URL}/content/www/us/en.headerfooter.json", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/flight-search/book-a-flight", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	web_url("errormessage.errormessage.json", 
		"URL=https://{URL}/content/www/delta-homepage-redesign-whitelabel/errormessage.errormessage.json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/flight-search/book-a-flight", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	web_url("getdevicetype", 
		"URL=https://{URL}/flight-search/getdevicetype", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/flight-search/book-a-flight", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("retrieveSearch", 
		"URL=https://{URL}/prefill/retrieveSearch?searchType=RecentSearchesJSON", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/flight-search/book-a-flight", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		EXTRARES, 
		"Url=https://{contentURL}/content/dam/delta-applications/flight-search/assets/images/supergraphic-delta-mark_1200.svg", "Referer=https://stg-content.delta.com/content/dam/delta-applications/flight-search/static/styles/11.0.124/css/styles.css", ENDITEM, 
		LAST);

	web_url("getDashBrdData.action_2", 
		"URL=https://{URL}/custlogin/getDashBrdData.action", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/flight-search/book-a-flight", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);

	web_url("getdevicetype_2", 
		"URL=https://{URL}/flight-search/getdevicetype", 
		"Resource=0", 
		"Referer=https://{URL}/flight-search/book-a-flight", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	web_url("bcdata.action_2", 
		"URL=https://{URL}/databroker/bcdata.action", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/flight-search/book-a-flight", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);

	web_url("advancesearch.data.json", 
		"URL=https://{URL}/content/www/en_US/air-shopping/advancesearch.data.json", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{URL}/flight-search/book-a-flight", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		LAST);

	web_url("retrieveKeyPrefillData", 
		"URL=https://{URL}/prefillapp/json/retrieveKeyPrefillData?prefillAttribute=RecentSearchesJSON", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/flight-search/book-a-flight", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		LAST);

	web_url("getClosestDeltaAirportCode_2", 
		"URL=https://{URL}/pref/geoLocationService/getClosestDeltaAirportCode", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/flight-search/book-a-flight", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("CacheKey", 
		"");

	web_add_header("X-APP-CHANNEL", 
		"sl-sho");

	web_add_header("X-APP-REFRESH", 
		"");

	web_add_header("X-APP-ROUTE", 
		"SL-RSB");

		web_reg_save_param_json(
			"ParamName=c_cacheKey",
			"QueryString=$..request.cacheKey",
			"Notfound=warning",
			SEARCH_FILTERS,
			"Scope=Body",
			LAST);
		web_reg_save_param("errorNumber", "LB=\"code\":\"", "RB=\"", "Notfound=warning", LAST);
		web_reg_save_param("errorMessage", "LB=\"message\":\"", "RB=\"", "Notfound=warning", LAST);
		
	web_custom_request("defaultsandlookups", 
		"URL=https://{URL}/shop/defaultsandlookups", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/flight-search/book-a-flight", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		LAST);

	web_url("ErrorMessage.json", 
		"URL=https://{URL}/content/dam/delta-applications/flight-search/assets/json/ErrorMessage.json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/flight-search/book-a-flight", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("Origin", 
		"https://{URL}");

	web_custom_request("getDashBrdData", 
		"URL=https://{URL}/login/login/getDashBrdData", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/flight-search/book-a-flight", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={}", 
		LAST);

	if(strlen(lr_eval_string("{c_cacheKey}"))<=0){	
			lr_output_message("RSB_Revenue_00_RSBSearchFlightPage: Flights page not available.\tErrorNumber:%s.\tErrorMessage:%s",lr_eval_string("{errorNumber}"),lr_eval_string("{errorMessage}"));
			lr_end_transaction(lr_eval_string("RSB_Revenue_00_RSBSearchFlightPage"), LR_AUTO);
			lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);
		}
		
	if(atoi(lr_eval_string("{Homepage_Check}")) == 0){
		
		lr_end_transaction("RSB_Revenue_00_RSBSearchFlightPage", LR_FAIL);
		lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);
	}

	
	lr_end_transaction(lr_eval_string("RSB_Revenue_00_RSBSearchFlightPage"), LR_AUTO);

	if(atoi(lr_eval_string("{PSD2}"))==1){
		lr_save_string(lr_eval_string("{Origin_psd2}"), "Origin");
		lr_save_string(lr_eval_string("{Destination_psd2}"), "Destination");
		lr_save_string(lr_eval_string("{ccNum_psd2}"), "ccNum");
		lr_save_string(lr_eval_string("{ccType_psd2}"), "ccType");
		lr_save_string(lr_eval_string("{cvv_psd2}"), "cvv");
		lr_save_string(lr_eval_string("{lastFourDigits_psd2}"), "lastFourDigits");
		
		lr_save_int(0, "tripExtrasPurchase");
		lr_save_int(0, "insurancePurchase");
	}
	
	if(strcmp(lr_eval_string("{Origin}"), lr_eval_string("{Destination}"))==0){
		lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);
	}

	if(strlen(lr_eval_string("{cacheKey}"))<=0){	
		lr_output_message("Flights page not available");
		lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);
	} 
	
	lr_think_time(5);
	
	lr_save_datetime("%Y-%m-%d", DATE_NOW , "date_today");
	x = atoi(lr_eval_string("{RandDep}"));
    lr_save_datetime("%Y-%m-%d", DATE_NOW + (x*ONE_DAY), "P_DepartureDate");
    lr_save_datetime("%m/%d/%Y", DATE_NOW + (x*ONE_DAY), "P_departureDate");
	    
    y = x + atoi(lr_eval_string("{RandRet}"));
    lr_save_datetime("%Y-%m-%d", DATE_NOW + (y*ONE_DAY), "P_ReturnDate");
    lr_save_datetime("%m/%d/%Y", DATE_NOW + (y*ONE_DAY), "P_returnDate");
    
    web_convert_param("DepDate_URL","SourceString={P_DepartureDate}","SourceEncoding=HTML","TargetEncoding=URL",LAST);	    
    web_convert_param("RetDate_URL","SourceString={P_ReturnDate}","SourceEncoding=HTML","TargetEncoding=URL",LAST);	    
    
    sprintf(depdtdiff,"%d",x-1);
	sprintf(retdtdiff,"%d",y-1);
	lr_save_string(retdtdiff,"returnadvancepurchase");
	lr_save_string(depdtdiff,"departureadvancepurchase");
	
	web_add_auto_header("Origin", 
		"https://{URL}");

	web_custom_request("updateSearch", 
		"URL=https://{URL}/prefill/updateSearch?searchType=RecentSearchesJSON", 
		"Method=POST", 
		"Resource=0", 
		"Referer=https://{URL}/", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={\"airports\":{\"fromCity\":\"Minneapolis/St Paul, MN\",\"toCity\":\"\",\"fromAirportcode\":\"{Origin}\",\"toAirportcode\":\"{Destination}\"},\"selectTripType\":\"ROUND_TRIP\",\"dates\":{\"departureDate\":\"{P_departureDate}\",\"returnDate\":\"{P_returnDate}\"},\"passenger\":\"{numPax}\",\"swapedFromCity\":null,\"swapedToCity\":null,\"schedulePrice\":\"price\",\"flightHotelDeals\":false,\"faresFor\":\"BE\",\"meetingEventCode\":\"\",\"refundableFlightsOnly\":false,\"nearbyAirports\":false,\"deltaOnly\":\"off\",\"awardTravel\""
		":false,\"departureTime\":\"AT\",\"returnTime\":\"AT\",\"adtGbeCount\":null,\"infantCount\":null,\"maxPaxCount\":null,\"adtCount\":null,\"cnnCount\":null,\"gbeCount\":null}", 
		LAST);
	
	web_revert_auto_header("Origin");

	web_reg_save_param("cityNameOrigin", "LB=\"cityName\":\"", "RB=\"", "Notfound=warning", LAST);
	web_reg_save_param("regionOrigin", "LB=\"region\":\"", "RB=\"", "Notfound=warning", LAST);
	
	web_url("getPredictiveCities", 
		"URL=https://{URL}/predictivetext/getPredictiveCities?code={Origin}", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/", 
		"Snapshot=t2764.inf", 
		"Mode=HTML", 
		LAST);

	web_reg_save_param("cityNameDestination", "LB=\"cityName\":\"", "RB=\"", "Notfound=warning", LAST);
	web_reg_save_param("regionDestination", "LB=\"region\":\"", "RB=\"", "Notfound=warning", LAST);
	
	web_url("getPredictiveCities", 
		"URL=https://{URL}/predictivetext/getPredictiveCities?code={Destination}", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/", 
		"Snapshot=t2765.inf", 
		"Mode=HTML", 
		LAST);
	
	
	web_add_header("Upgrade-Insecure-Requests", "1");

	lr_start_transaction(lr_eval_string("Revenue_{RandTripType}_01_SearchFlight{actionTypeTransaction}"));
	
	web_submit_data("search-shop", 
		"Action=https://{URL}/flight-search/search-shop?cacheKeySuffix={c_cacheKey}", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{URL}/flight-search/book-a-flight", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=fromAirportCode", "Value={Origin}", ENDITEM, 
		"Name=fromCity", "Value={cityNameOrigin}, {regionOrigin}", ENDITEM, 
		"Name=arrivalCity", "Value={Destination}", ENDITEM, 
		"Name=toCity", "Value={cityNameDestination}, {regionDestination}", ENDITEM, 
		"Name=invalidAirportCodes", "Value=", ENDITEM, 
		"Name=selectTripType", "Value=ROUND_TRIP", ENDITEM, 
		"Name=schedulePrice", "Value=price", ENDITEM, 
		"Name=faresFor", "Value=BE", ENDITEM, 
		"Name=meetingEventCode", "Value=", ENDITEM, 
		"Name=searchType", "Value=simple", ENDITEM, 
		"Name=bookingPostVerify", "Value=RTR_YES", ENDITEM, 
		"Name=bundled", "Value=off", ENDITEM, 
		"Name=deltaOnly", "Value={deltaOnly}", ENDITEM, 
		"Name=dl", "Value=y", ENDITEM, 
		"Name=departureTime", "Value=AT", ENDITEM, 
		"Name=returnTime", "Value=AT", ENDITEM, 
		"Name=directServiceOnly", "Value=off", ENDITEM, 
		"Name=dispatchMethod", "Value=findFlights", ENDITEM, 
		"Name=fareBundle", "Value=B5-Coach", ENDITEM, 
		"Name=flexMainRTRTravelDate", "Value=off", ENDITEM, 
		"Name=preferItinId", "Value=", ENDITEM, 
		"Name=medallionTraveler", "Value=0", ENDITEM, 
		"Name=displayPreferredOnly", "Value=0", ENDITEM, 
		"Name=calendarSearch", "Value=false", ENDITEM, 
		"Name=pricingSearch", "Value=true", ENDITEM, 
		"Name=directServiceOnly", "Value=off", ENDITEM, 
		"Name=hiddenFieldsId", "Value=", ENDITEM, 
		"Name=awardTravel", "Value=false", ENDITEM, 
		"Name=action", "Value=findFlights", ENDITEM, 
		"Name=pageName", "Value=advanceSearchPage", ENDITEM, 
		"Name=branchingOptions", "Value=", ENDITEM, 
		"Name=removeEdoc", "Value=", ENDITEM, 
		"Name=tripType", "Value=ROUND_TRIP", ENDITEM, 
		"Name=cacheKey", "Value=", ENDITEM, 
		"Name=shopType", "Value=REVENUE", ENDITEM, 
		"Name=flexAirport", "Value={flexAirportFlag}", ENDITEM, 
		"Name=originAirportRadius", "Value=0", ENDITEM, 
		"Name=destinationAirportRadius", "Value=0", ENDITEM, 
		"Name=originCity", "Value={Origin}", ENDITEM, 
		"Name=destinationCity", "Value={Destination}", ENDITEM, 
		"Name=departureDate", "Value={P_ReturnDate}", ENDITEM, 
		"Name=returnDate", "Value={P_DepartureDate}", ENDITEM, 
		"Name=is_Flex_Search", "Value=true", ENDITEM, 
		"Name=datesFlexible", "Value=", ENDITEM, 
		"Name=flexDays", "Value=3", ENDITEM, 
		"Name=bestFare", "Value=BE", ENDITEM, 
		"Name=fareFamily", "Value=BE", ENDITEM, 
		"Name=is_award_travel", "Value=false", ENDITEM, 
		"Name=paxCount", "Value={numPax}", ENDITEM, 
		"Name=flexDate", "Value=", ENDITEM, 
		"Name=searchByCabin", "Value=true", ENDITEM, 
		"Name=cabinFareClass", "Value=BE", ENDITEM,
		"Name=adtCount", "Value=", ENDITEM, 
		"Name=gbeCount", "Value=", ENDITEM, 
		"Name=cnnCount", "Value=", ENDITEM, 
		"Name=infCount", "Value=", ENDITEM, 		
		LAST);
	
		lr_save_string("flight-search", "flightSearchLink");
		lr_save_string("true", "ftw_reroute");	

	lr_save_string(lr_eval_string("{c_cacheKey}"), "cacheKey");
	if(strcmp(lr_eval_string("{flexAirportFlag}"), "false")==0){
		NonFlexSearch();
	} else {
			web_custom_request("getDashBrdData.action_2", 
				"URL=https://{URL}/custlogin/getDashBrdData.action", 
				"Method=POST", 
				"Resource=0", 
				"RecContentType=application/json", 
				"Referer=https://{URL}/{flightSearchLink}/search?se=squares&action=findFlights&tripType=ROUND_TRIP&priceSchedule=PRICE&originCity={Origin}&destinationCity={Destination}&departureDate={DepDate_URL}&departureTime=AT&returnDate={RetDate_URL}&returnTime=AT&paxCount={numPax}&searchByCabin=true&cabinFareClass=BE&deltaOnlySearch=false&deltaOnly=off&Go=Find%20Flights&meetingEventCode=&refundableFlightsOnly=false&compareAirport=false&awardTravel=false&datesFlexible=undefined&flexAirport={flexAirportFlag}&paxCounts%5B0%5D={numPax}&ftw_reroute=true", 
				"Snapshot=t12.inf", 
				"Mode=HTML", 
				"EncType=application/json; charset=utf-8", 
				"Body={}", 
				EXTRARES, 
				"Url=../{flightSearchLink}/favicon.ico", "Referer=", ENDITEM, 
				"Url=https://{contentURL}/content/dam/delta-applications/{c_cacheKey}/static/v4.3.1/vendor/tracker.js", "Referer=https://{URL}/{flightSearchLink}/search?se=squares&action=findFlights&tripType=ROUND_TRIP&priceSchedule=PRICE&originCity={Origin}&destinationCity={Destination}&departureDate={DepDate_URL}&departureTime=AT&returnDate={RetDate_URL}&returnTime=AT&paxCount={numPax}&searchByCabin=true&cabinFareClass=BE&deltaOnlySearch=false&deltaOnly=off&Go=Find%20Flights&meetingEventCode=&refundableFlightsOnly=false&compareAirport=false&awardTravel=false&datesFlexible=undefined&flexAirport={flexAirportFlag}&paxCounts%5B0%5D={numPax}&ftw_reroute=true", ENDITEM, 
				LAST);
		
				web_url("flexairport.data.json", 
					"URL=https://{URL}/content/www/en_US/air-shopping/flexairport.data.json", 
					"Resource=0", 
					"RecContentType=text/html", 
					"Referer=https://{URL}/{flightSearchLink}/flexible-airports?cacheKeySuffix={c_cacheKey}", 
					"Snapshot=t13.inf", 
					"Mode=HTML", 
					LAST);
			
				web_add_header("CacheKey", 
					"{c_cacheKey}");
			
				web_add_header("X-APP-CHANNEL", 
					"sl-sho");
			
				web_add_header("X-APP-ROUTE", 
					"SL-RSB");
			
//		   		if(strcmp(lr_eval_string("{offerAPIFlag}"), "true")==0){
//						lr_save_string("OFFERAPI", "SearchAPI_Route");
//						lr_start_transaction("%getpersonalizedContent%");
//							lr_start_transaction("%getpersonalizedContent_Offer%");
//						web_custom_request("getpersonalizedContent_3", 
//							"URL=https://{URL}/personalization-api/getpersonalizedContent", 
//							"Method=POST", 
//							"Resource=0", 
//							"RecContentType=application/json", 
//							"Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", 
//							"Snapshot=t12.inf", 
//							"Mode=HTML", 
//							"EncType=application/json; charset=UTF-8", 
//							"Body={\"userdata\":{\"isEdocAdded\":false},\"requestparam\":{\"campaignId\":\"shopping-lite:shop-offer-api\"}}", 
//							LAST);
//						lr_end_transaction("%getpersonalizedContent_Offer%", LR_AUTO);
//		
//						lr_end_transaction("%getpersonalizedContent%", LR_AUTO);
//					
//						web_add_header("X-OFFER-ROUTE", "SL-OFFER");
//					}
				
				web_custom_request("flexairportsearch", 
					"URL=https://{URL}/shop/rt/flexairportsearch", 
					"Method=POST", 
					"Resource=0", 
					"RecContentType=application/json", 
					"Referer=https://{URL}/{flightSearchLink}/flexible-airports?cacheKeySuffix={c_cacheKey}", 
					"Snapshot=t14.inf", 
					"Mode=HTML", 
					"EncType=application/json; charset=utf-8", 
					"Body={\"bestFare\":\"BE\",\"action\":\"findFlights\",\"destinationAirportRadius\":{\"unit\":\"MI\",\"measure\":100},\"deltaOnlySearch\":{deltaOnlySearch},\"meetingEventCode\":\"\",\"originAirportRadius\":{\"unit\":\"MI\",\"measure\":100},\"passengers\":[{\"type\":\"ADT\",\"count\":{numPax}}],\"searchType\":\"radiusSearch\",\"segments\":[{\"returnDate\":\"{P_ReturnDate}\",\"departureDate\":\"{P_DepartureDate}\",\"destination\":\"{Destination}\",\"origin\":\"{Origin}\"}],\"shopType\":\"MONEY\",\"tripType\":\"ROUND_TRIP\",\"priceType\":\""
					"Revenue\",\"priceSchedule\":\"PRICE\",\"awardTravel\":false,\"refundableFlightsOnly\":false,\"nonstopFlightsOnly\":false,\"datesFlexible\":false,\"flexCalendar\":false,\"flexAirport\":\"{flexAirportFlag}\",\"upgradeRequest\":false,\"cacheKey\":\"{c_cacheKey}\",\"selectedSolutions\":[{\"sliceIndex\":1}],\"actionType\":\"flexAirportSearch\",\"vendorDetails\":{},\"initialSearchBy\":{\"fareFamily\":\"BE\",\"cabinFareClass\":null,\"meetingEventCode\":\"\",\"refundable\":false,\"flexAirport\""
					":true,\"flexDate\":false,\"flexDaysWeeks\":null},\"pageName\":\"FLEX_AIRPORT\"}", 
					LAST);
			
				web_url("bcdata.action_2", 
					"URL=https://{URL}/databroker/bcdata.action", 
					"Resource=0", 
					"RecContentType=application/json", 
					"Referer=https://{URL}/{flightSearchLink}/flexible-airports?cacheKeySuffix={c_cacheKey}", 
					"Snapshot=t16.inf", 
					"Mode=HTML", 
					LAST);
			
				web_add_header("CacheKey", 
					"{c_cacheKey}");
			
				web_add_header("X-APP-CHANNEL", 
					"sl-sho");
			
				web_add_header("X-APP-ROUTE", 
					"SL-RSB");
			
				lr_start_transaction("%getpersonalizedContent%");

				web_custom_request("getpersonalizedContent", 
					"URL=https://{URL}/personalization-api/getpersonalizedContent", 
					"Method=POST", 
					"Resource=0", 
					"RecContentType=application/json", 
					"Referer=https://{URL}/{flightSearchLink}/flexible-airports?cacheKeySuffix={c_cacheKey}", 
					"Snapshot=t17.inf", 
					"Mode=HTML", 
					"EncType=application/json; charset=utf-8", 
					"Body={\"userdata\":{\"origin\":\"{Origin}\",\"destination\":\"{Destination}\",\"triptype\":\"ROUND_TRIP\",\"departuredate\":\"{P_DepartureDate}\",\"returndate\":\"{P_ReturnDate}\",\"noofpassengers\":{numPax}},\"requestparam\":{\"campaignId\":\"shopping-lite:interstitial-banner\"}}", 
					EXTRARES, 
					"Url=../content/dam/delta-applications/{flightSearchLink}/static/v4.3.1/fonts/Whitney-Bold.eot", "Referer=https://{URL}/{flightSearchLink}/flexible-airports?cacheKeySuffix={c_cacheKey}", ENDITEM, 
					"Url=../content/dam/delta-applications/{flightSearchLink}static/v4.3.1/fonts/Whitney-Bold.otf", "Referer=https://{URL}/{flightSearchLink}/flexible-airports?cacheKeySuffix={c_cacheKey}", ENDITEM, 
					LAST);
				
				lr_end_transaction("%getpersonalizedContent%", LR_AUTO);			

	}
	
	lr_end_transaction(lr_eval_string("Revenue_{RandTripType}_01_SearchFlight{actionTypeTransaction}"), LR_AUTO);
	
	lr_save_string(lr_eval_string("{c_cacheKey}"), "cacheKey");

	
	RSBFlow();
	
	return 0;
}
