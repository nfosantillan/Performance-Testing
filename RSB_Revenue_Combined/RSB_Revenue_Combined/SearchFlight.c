SearchFlight()
{

	lr_think_time(5);

	lr_save_string("SHOPAPI", "SearchAPI_Route");
	
	if((strcmp(lr_eval_string("{Origin}"), "LHR")==0)||(strcmp(lr_eval_string("{Origin}"), "MAN")==0)){
		lr_save_string("GBP", "C_currencyCode");
		lr_save_string("&#163;", "C_currencySymbol");
	} else{
		lr_save_string("USD", "C_currencyCode");
		lr_save_string("&#36;", "C_currencySymbol");		
	}
	
	lr_save_datetime("%Y-%m-%d", DATE_NOW , "date_today");
	x = atoi(lr_eval_string("{RandDep}"));
    lr_save_datetime("%Y-%m-%d", DATE_NOW + (x*ONE_DAY), "P_DepartureDate");
    lr_save_datetime("%m/%d/%Y", DATE_NOW + (x*ONE_DAY), "P_departureDate");
	    
    y = x + atoi(lr_eval_string("{RandRet}"));
    lr_save_datetime("%Y-%m-%d", DATE_NOW + (y*ONE_DAY), "P_ReturnDate");
    lr_save_datetime("%m/%d/%Y", DATE_NOW + (y*ONE_DAY), "P_returnDate");
 
	z = y + atoi(lr_eval_string("{RandRet}"));
	lr_save_datetime("%Y-%m-%d", DATE_NOW + (z*ONE_DAY), "P_ReturnDate1");
	lr_save_datetime("%m/%d/%Y", DATE_NOW + (z*ONE_DAY), "P_returnDate1");
	
    web_convert_param("DepDate_URL","SourceString={P_DepartureDate}","SourceEncoding=HTML","TargetEncoding=URL",LAST);	    
    web_convert_param("RetDate_URL","SourceString={P_ReturnDate}","SourceEncoding=HTML","TargetEncoding=URL",LAST);	    
    
    sprintf(depdtdiff,"%d",x-1);
	sprintf(retdtdiff,"%d",y-1);
	sprintf(retdtdiff1,"%d",z-1);
	lr_save_string(retdtdiff,"returnadvancepurchase");
	lr_save_string(retdtdiff1,"returnadvancepurchase1");
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

	web_reg_save_param("cityNameFinalDestination", "LB=\"cityName\":\"", "RB=\"", "Notfound=warning", LAST);
	web_reg_save_param("regionFinalDestination", "LB=\"region\":\"", "RB=\"", "Notfound=warning", LAST);
	
	web_url("getPredictiveCities",
	        "URL=https://{URL}/predictivetext/getPredictiveCities?code={FinalDestination}",
	        "Resource=0",
	        "RecContentType=application/json",
	        "Referer=https://{URL}/",
	        "Snapshot=t2765.inf",
	        "Mode=HTML",
	        LAST);
	
	if(strcmp(lr_eval_string("{RandTripType}"), "RT")==0){
	 	web_add_header("Upgrade-Insecure-Requests", 
			"1");
		
		lr_start_transaction(lr_eval_string("Revenue_{RandTripType}_01_SearchFlight{actionTypeTransaction}"));
	
		web_add_header("Upgrade-Insecure-Requests", 
			"1");
	
		web_submit_data("search-shop", 
			"Action=https://{URL}/flight-search/search-shop", 
			"Method=POST", 
			"RecContentType=text/html", 
			"Referer=https://{URL}/", 
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
			"Name=departureDate", "Value={P_DepartureDate}", ENDITEM,
			"Name=returnDate", "Value={P_ReturnDate}", ENDITEM, 
			"Name=is_Flex_Search", "Value=true", ENDITEM, 
			"Name=datesFlexible", "Value=", ENDITEM, 
			"Name=flexDays", "Value=3", ENDITEM, 
			"Name=bestFare", "Value=BE", ENDITEM, 
			"Name=fareFamily", "Value=BE", ENDITEM, 
			"Name=is_award_travel", "Value=false", ENDITEM, 
			"Name=paxCount", "Value={numPax}", ENDITEM, 
			"Name=flexDate", "Value=", ENDITEM, 
			"Name=searchByCabin", "Value=true", ENDITEM, 
			"Name=cabinFareClass", "Value=", ENDITEM, 
			EXTRARES, 
			"Url=../content/dam/delta-applications/fresh-air-core/20.3.0/css/fresh-air.css", "Referer=https://{URL}/flight-search/search-shop?se=grid&&ftw_reroute=true", ENDITEM, 
			"Url=../content/dam/delta-applications/flight-search/static/styles/20.3.116/fonts/fonts.css", "Referer=https://{URL}/flight-search/search-shop?se=grid&&ftw_reroute=true", ENDITEM, 
			LAST);
		
		// lr_save_int(1, "redirectFlag"); //<--- this is for debugging purposes only, this will force the flow into the desired route
		//======================== determine if the flow will be RSB or BAU =================================
		lr_save_string("flight-search", "flightSearchLink");
		lr_save_string("true", "ftw_reroute");
			
			    web_add_header("X-APP-CHANNEL", "sl-sho");
				web_add_header("X-APP-ROUTE", "SL-RSB");
				
				
		web_reg_save_param_json(
				"ParamName=c_cacheKey",
				"QueryString=$..request.cacheKey",
				"Notfound=warning",
				SEARCH_FILTERS,
				"Scope=Body",
				LAST);
		web_reg_save_param("errorNumber", "LB=\"code\":\"", "RB=\"", "Notfound=warning", LAST);
		//web_reg_save_param("errorMessage", "LB=\"message\":\"", "RB=\"", "Notfound=warning", LAST);
		
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
			"Referer=https://{URL}/{flightSearchLink}/search-shop", 
			"Snapshot=t11.inf", 
			"Mode=HTML", 
			EXTRARES, 
			"Url=../content/dam/delta-applications/flight-search/static/styles/20.3.116/fonts/Whitney-Book.otf", "Referer=https://{URL}/content/dam/delta-applications/flight-search/static/styles/20.3.116/fonts/fonts.css", ENDITEM, 
			"Url=../content/dam/delta-applications/flight-search/static/styles/20.3.116/fonts/icomoon.woff", "Referer=https://{URL}/content/dam/delta-applications/flight-search/static/styles/20.3.116/fonts/fonts.css", ENDITEM, 
			"Url=../content/dam/delta-applications/flight-search/static/styles/20.3.116/fonts/Whitney-Semibold.otf", "Referer=https://{URL}/content/dam/delta-applications/flight-search/static/styles/20.3.116/fonts/fonts.css", ENDITEM, 
			"Url=../content/dam/delta-applications/flight-search/static/styles/20.3.116/fonts/Whitney-Light.otf", "Referer=https://{URL}/content/dam/delta-applications/flight-search/static/styles/20.3.116/fonts/fonts.css", ENDITEM, 
			"Url=../content/dam/delta-applications/flight-search/static/styles/20.3.116/fonts/Whitney-Medium.otf", "Referer=https://{URL}/content/dam/delta-applications/flight-search/static/styles/20.3.116/fonts/fonts.css", ENDITEM, 
			LAST);
			
			web_url("getdevicetype", 
			"URL=https://{URL}/flight-search/getdevicetype", 
			"Resource=0", 
			"RecContentType=application/json", 
			"Referer=https://{URL}/flight-search/search-shop?se=grid&&ftw_reroute=true", 
			"Snapshot=t17.inf", 
			"Mode=HTML", 
			LAST);
			
		web_custom_request("retrieveSearch", 
			"URL=https://{URL}/prefill/retrieveSearch?searchType=RecentSearchesJSON", 
			"Method=GET", 
			"Resource=0", 
			"RecContentType=application/json", 
			"Referer=https://{URL}/flight-search/search-shop?se=grid&&ftw_reroute=true", 
			"Snapshot=t18.inf", 
			"Mode=HTML", 
			"EncType=application/json; charset=utf-8", 
			EXTRARES,
			"Url=../content/dam/delta-applications/fresh-air-core/20.3.0/css/fresh-air.css", "Referer=https://{URL}/content/dam/delta-applications/fresh-air-core/20.3.0/css/fresh-air.css", ENDITEM, 
			LAST);		
			
		web_custom_request("getDashBrdData_2", 
			"URL=https://{URL}/login/login/getDashBrdData", 
			"Method=POST", 
			"Resource=0", 
			"RecContentType=application/json", 
			"Referer=https://{URL}/flight-search/search-shop?se=grid&ftw_reroute=true", 
			"Snapshot=t20.inf", 
			"Mode=HTML", 
			"EncType=application/json; charset=UTF-8", 
			"Body={}", 
			LAST);
	
			if(strlen(lr_eval_string("{c_cacheKey}"))<=0){			
				lr_end_transaction(lr_eval_string("Revenue_{RandTripType}_01_SearchFlight{actionTypeTransaction}"), LR_AUTO);
				
				getErrorMessage();
				lr_output_message("Revenue_%s_01_SearchFlight%s: Flights page not available \tORIGIN\t%s\tDESTINATION\t%s\tFLIGHT DATES\t%s-%s\tError Number:\t%s\tError Message:\t%s",lr_eval_string("{RandTripType}"),lr_eval_string("{actionTypeTransaction}"),lr_eval_string("{Origin}"),lr_eval_string("{Destination}"),lr_eval_string("{P_DepartureDate}"),lr_eval_string("{P_ReturnDate}"),lr_eval_string("{errorNumber}"),lr_eval_string("{errorMessage}"));
				lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);
			} 
		
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
			
					web_reg_save_param("offerAPIFlag", "LB=\"callPEOfferAPI\":\"", "RB=\"", "Notfound=warning", LAST);
					
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
				
		   		if(strcmp(lr_eval_string("{offerAPIFlag}"), "true")==0){
						
						
						web_reg_find("Text=\"flagenabledisable\":{\"enable\":true", "Savecount=offerAPI_ON", LAST);
						lr_start_transaction("%getpersonalizedContent%");
							lr_start_transaction("%getpersonalizedContent_Offer%");
						web_custom_request("getpersonalizedContent_3", 
							"URL=https://{URL}/personalization-api/getpersonalizedContent", 
							"Method=POST", 
							"Resource=0", 
							"RecContentType=application/json", 
							"Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", 
							"Snapshot=t12.inf", 
							"Mode=HTML", 
							"EncType=application/json; charset=UTF-8", 
							"Body={\"userdata\":{\"isEdocAdded\":false},\"requestparam\":{\"campaignId\":\"shopping-lite:shop-offer-api\"}}", 
							LAST);
						lr_end_transaction("%getpersonalizedContent_Offer%", LR_AUTO);
		
						lr_end_transaction("%getpersonalizedContent%", LR_AUTO);
					
						if(atoi(lr_eval_string("{offerAPI_ON}"))>0){
							web_add_header("X-OFFER-ROUTE", "SL-OFFER");
							lr_save_string("OFFERAPI", "SearchAPI_Route");
						} else {
							lr_save_string("SHOPAPI", "SearchAPI_Route");
						}
					}

			web_reg_save_param_json(
			        "ParamName=callDuration",
			        //"QueryString=$.itinerary[*].fare[*].solutionId",
			        "QueryString=$..callDuration",
			        "Notfound=warning",
			        "SEARCH_FILTERS",
			        "Scope=Body",
			        "LAST");
					
					web_reg_find("Text=\"segments\":[{\"returnDate\":\"{P_ReturnDate}\",\"departureDate\":\"{P_DepartureDate}\",\"destination\":\"{Destination}\",\"origin\":\"{Origin}\"}]", "SaveCount=searchCriteria", LAST);
					
					lr_start_transaction(lr_eval_string("%FLEXAIRPORTSEARCH_{SearchAPI_Route}%"));

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
				
					lr_end_transaction(lr_eval_string("%FLEXAIRPORTSEARCH_{SearchAPI_Route}%"), LR_AUTO);
					
					if(atoi(lr_eval_string("{callDurationFlag}"))==1){
						lr_output_message("[REVENUE FLEXAIRPORTSEARCH\t%s]TripType:\t%s\tCallDuration:\t%s",lr_eval_string("{SearchAPI_Route}"),lr_eval_string("{RandTripType}"),lr_eval_string("{callDuration}"));
					}
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
					if (atoi(lr_eval_string("{searchCriteria}"))<=0){
						lr_error_message("Revenue_%s_01_SearchFlight%s: Search Criteria Different for \tORIGIN\t%s\tDESTINATION\t%s\tFLIGHT DATES\t%s-%s\tCacheKey:%s",lr_eval_string("{RandTripType}"),lr_eval_string("{actionTypeTransaction}"),lr_eval_string("{Origin}"),lr_eval_string("{Destination}"),lr_eval_string("{P_DepartureDate}"),lr_eval_string("{P_ReturnDate}"),lr_eval_string("{cacheKey}"));
						lr_end_transaction(lr_eval_string("Revenue_{RandTripType}_01_SearchFlight{actionTypeTransaction}"), LR_AUTO);
							
						lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_FAIL);		
					}				
	
			}
				
				lr_end_transaction(lr_eval_string("Revenue_{RandTripType}_01_SearchFlight{actionTypeTransaction}"), LR_AUTO);
		
		if(strlen(lr_eval_string("{c_cacheKey}"))<=0){
			getErrorMessage();
			lr_output_message("Revenue_%s_01_SearchFlight%s: Flights page not available \tORIGIN\t%s\tDESTINATION\t%s\tFLIGHT DATES\t%s-%s\tError Number:\t%s\tError Message:\t%s",lr_eval_string("{RandTripType}"),lr_eval_string("{actionTypeTransaction}"),lr_eval_string("{Origin}"),lr_eval_string("{Destination}"),lr_eval_string("{P_DepartureDate}"),lr_eval_string("{P_ReturnDate}"),lr_eval_string("{errorNumber}"),lr_eval_string("{errorMessage}"));
			lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);
		} 
	} else 	if(strcmp(lr_eval_string("{RandTripType}"), "OW")==0){
	 	web_add_header("Upgrade-Insecure-Requests", 
			"1");
		
		lr_start_transaction(lr_eval_string("Revenue_{RandTripType}_01_SearchFlight{actionTypeTransaction}"));
	
		web_add_header("Upgrade-Insecure-Requests", 
			"1");
	
		web_submit_data("search-shop", 
			"Action=https://{URL}/flight-search/search-shop", 
			"Method=POST", 
			"RecContentType=text/html", 
			"Referer=https://{URL}/", 
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
			"Name=tripType", "Value=ONE_WAY", ENDITEM, 
			"Name=cacheKey", "Value=", ENDITEM, 
			"Name=shopType", "Value=REVENUE", ENDITEM, 
			"Name=flexAirport", "Value={flexAirportFlag}", ENDITEM, 
			"Name=originAirportRadius", "Value=0", ENDITEM, 
			"Name=destinationAirportRadius", "Value=0", ENDITEM, 
			"Name=originCity", "Value={Origin}", ENDITEM, 
			"Name=destinationCity", "Value={Destination}", ENDITEM, 
			"Name=departureDate", "Value={P_DepartureDate}", ENDITEM, 
			"Name=returnDate", "Value=undefined--undefined", ENDITEM, 
			"Name=is_Flex_Search", "Value=true", ENDITEM, 
			"Name=datesFlexible", "Value=", ENDITEM, 
			"Name=flexDays", "Value=3", ENDITEM, 
			"Name=bestFare", "Value=BE", ENDITEM, 
			"Name=fareFamily", "Value=BE", ENDITEM, 
			"Name=is_award_travel", "Value=false", ENDITEM, 
			"Name=paxCount", "Value={numPax}", ENDITEM, 
			"Name=flexDate", "Value=", ENDITEM, 
			"Name=searchByCabin", "Value=true", ENDITEM, 
			"Name=cabinFareClass", "Value=", ENDITEM, 
			EXTRARES, 
			"Url=../content/dam/delta-applications/fresh-air-core/20.3.0/css/fresh-air.css", "Referer=https://{URL}/flight-search/search-shop?se=grid&&ftw_reroute=true", ENDITEM, 
			"Url=../content/dam/delta-applications/flight-search/static/styles/20.3.116/fonts/fonts.css", "Referer=https://{URL}/flight-search/search-shop?se=grid&&ftw_reroute=true", ENDITEM, 
			LAST);
		
		// lr_save_int(1, "redirectFlag"); //<--- this is for debugging purposes only, this will force the flow into the desired route
		//======================== determine if the flow will be RSB or BAU =================================
		lr_save_string("flight-search", "flightSearchLink");
		lr_save_string("true", "ftw_reroute");
			
			    web_add_header("X-APP-CHANNEL", "sl-sho");
				web_add_header("X-APP-ROUTE", "SL-RSB");
				
				
		web_reg_save_param_json(
				"ParamName=c_cacheKey",
				"QueryString=$..request.cacheKey",
				"Notfound=warning",
				SEARCH_FILTERS,
				"Scope=Body",
				LAST);
		web_reg_save_param("errorNumber", "LB=\"code\":\"", "RB=\"", "Notfound=warning", LAST);
		//web_reg_save_param("errorMessage", "LB=\"message\":\"", "RB=\"", "Notfound=warning", LAST);
		
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
			"Referer=https://{URL}/{flightSearchLink}/search-shop", 
			"Snapshot=t11.inf", 
			"Mode=HTML", 
			EXTRARES, 
			"Url=../content/dam/delta-applications/flight-search/static/styles/20.3.116/fonts/Whitney-Book.otf", "Referer=https://{URL}/content/dam/delta-applications/flight-search/static/styles/20.3.116/fonts/fonts.css", ENDITEM, 
			"Url=../content/dam/delta-applications/flight-search/static/styles/20.3.116/fonts/icomoon.woff", "Referer=https://{URL}/content/dam/delta-applications/flight-search/static/styles/20.3.116/fonts/fonts.css", ENDITEM, 
			"Url=../content/dam/delta-applications/flight-search/static/styles/20.3.116/fonts/Whitney-Semibold.otf", "Referer=https://{URL}/content/dam/delta-applications/flight-search/static/styles/20.3.116/fonts/fonts.css", ENDITEM, 
			"Url=../content/dam/delta-applications/flight-search/static/styles/20.3.116/fonts/Whitney-Light.otf", "Referer=https://{URL}/content/dam/delta-applications/flight-search/static/styles/20.3.116/fonts/fonts.css", ENDITEM, 
			"Url=../content/dam/delta-applications/flight-search/static/styles/20.3.116/fonts/Whitney-Medium.otf", "Referer=https://{URL}/content/dam/delta-applications/flight-search/static/styles/20.3.116/fonts/fonts.css", ENDITEM, 
			LAST);
			
			web_url("getdevicetype", 
			"URL=https://{URL}/flight-search/getdevicetype", 
			"Resource=0", 
			"RecContentType=application/json", 
			"Referer=https://{URL}/flight-search/search-shop?se=grid&&ftw_reroute=true", 
			"Snapshot=t17.inf", 
			"Mode=HTML", 
			LAST);
			
		web_custom_request("retrieveSearch", 
			"URL=https://{URL}/prefill/retrieveSearch?searchType=RecentSearchesJSON", 
			"Method=GET", 
			"Resource=0", 
			"RecContentType=application/json", 
			"Referer=https://{URL}/flight-search/search-shop?se=grid&&ftw_reroute=true", 
			"Snapshot=t18.inf", 
			"Mode=HTML", 
			"EncType=application/json; charset=utf-8", 
			EXTRARES,
			"Url=../content/dam/delta-applications/fresh-air-core/20.3.0/css/fresh-air.css", "Referer=https://{URL}/content/dam/delta-applications/fresh-air-core/20.3.0/css/fresh-air.css", ENDITEM, 
			LAST);		
			
		web_custom_request("getDashBrdData_2", 
			"URL=https://{URL}/login/login/getDashBrdData", 
			"Method=POST", 
			"Resource=0", 
			"RecContentType=application/json", 
			"Referer=https://{URL}/flight-search/search-shop?se=grid&ftw_reroute=true", 
			"Snapshot=t20.inf", 
			"Mode=HTML", 
			"EncType=application/json; charset=UTF-8", 
			"Body={}", 
			LAST);
	
			if(strlen(lr_eval_string("{c_cacheKey}"))<=0){			
				lr_end_transaction(lr_eval_string("Revenue_{RandTripType}_01_SearchFlight{actionTypeTransaction}"), LR_AUTO);
				
				getErrorMessage();
				lr_output_message("Revenue_%s_01_SearchFlight%s: Flights page not available \tORIGIN\t%s\tDESTINATION\t%s\tFLIGHT DATES\t%s-%s\tError Number:\t%s\tError Message:\t%s",lr_eval_string("{RandTripType}"),lr_eval_string("{actionTypeTransaction}"),lr_eval_string("{Origin}"),lr_eval_string("{Destination}"),lr_eval_string("{P_DepartureDate}"),lr_eval_string("{P_ReturnDate}"),lr_eval_string("{errorNumber}"),lr_eval_string("{errorMessage}"));
				lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);
			} 
		
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
			
					web_reg_save_param("offerAPIFlag", "LB=\"callPEOfferAPI\":\"", "RB=\"", "Notfound=warning", LAST);
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
				
		   		if(strcmp(lr_eval_string("{offerAPIFlag}"), "true")==0){
						
						
						web_reg_find("Text=\"flagenabledisable\":{\"enable\":true", "Savecount=offerAPI_ON", LAST);
						lr_start_transaction("%getpersonalizedContent%");
							lr_start_transaction("%getpersonalizedContent_Offer%");
						web_custom_request("getpersonalizedContent_3", 
							"URL=https://{URL}/personalization-api/getpersonalizedContent", 
							"Method=POST", 
							"Resource=0", 
							"RecContentType=application/json", 
							"Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", 
							"Snapshot=t12.inf", 
							"Mode=HTML", 
							"EncType=application/json; charset=UTF-8", 
							"Body={\"userdata\":{\"isEdocAdded\":false},\"requestparam\":{\"campaignId\":\"shopping-lite:shop-offer-api\"}}", 
							LAST);
						lr_end_transaction("%getpersonalizedContent_Offer%", LR_AUTO);
		
						lr_end_transaction("%getpersonalizedContent%", LR_AUTO);
					
						if(atoi(lr_eval_string("{offerAPI_ON}"))>0){
							web_add_header("X-OFFER-ROUTE", "SL-OFFER");
							lr_save_string("OFFERAPI", "SearchAPI_Route");
						} else {
							lr_save_string("SHOPAPI", "SearchAPI_Route");
						}
					}

			web_reg_save_param_json(
			        "ParamName=callDuration",
			        //"QueryString=$.itinerary[*].fare[*].solutionId",
			        "QueryString=$..callDuration",
			        "Notfound=warning",
			        "SEARCH_FILTERS",
			        "Scope=Body",
			        "LAST");
					
					web_reg_find("Text=\"segments\":[{\"departureDate\":\"{P_DepartureDate}\",\"destination\":\"{Destination}\",\"origin\":\"{Origin}\"}]", "SaveCount=searchCriteria", LAST);
					
					lr_start_transaction(lr_eval_string("%FLEXAIRPORTSEARCH_{SearchAPI_Route}%"));

					web_custom_request("flexairportsearch", 
						"URL=https://{URL}/shop/ow/flexairportsearch", 
						"Method=POST", 
						"Resource=0", 
						"RecContentType=application/json", 
						"Referer=https://{URL}/{flightSearchLink}/flexible-airports?cacheKeySuffix={c_cacheKey}", 
						"Snapshot=t14.inf", 
						"Mode=HTML", 
						"EncType=application/json; charset=utf-8", 
						"Body={\"bestFare\":\"BE\",\"action\":\"findFlights\",\"destinationAirportRadius\":{\"unit\":\"MI\",\"measure\":100},\"deltaOnlySearch\":{deltaOnlySearch},\"meetingEventCode\":\"\",\"originAirportRadius\":{\"unit\":\"MI\",\"measure\":100},\"passengers\":[{\"type\":\"ADT\",\"count\":{numPax}}],\"searchType\":\"radiusSearch\",\"segments\":[{\"departureDate\":\"{P_DepartureDate}\",\"destination\":\"{Destination}\",\"origin\":\"{Origin}\"}],\"shopType\":\"MONEY\",\"tripType\":\"ONE_WAY\",\"priceType\":\""
						"Revenue\",\"priceSchedule\":\"PRICE\",\"awardTravel\":false,\"refundableFlightsOnly\":false,\"nonstopFlightsOnly\":false,\"datesFlexible\":false,\"flexCalendar\":false,\"flexAirport\":\"{flexAirportFlag}\",\"upgradeRequest\":false,\"cacheKey\":\"{c_cacheKey}\",\"selectedSolutions\":[{\"sliceIndex\":1}],\"actionType\":\"flexAirportSearch\",\"vendorDetails\":{},\"initialSearchBy\":{\"fareFamily\":\"BE\",\"cabinFareClass\":null,\"meetingEventCode\":\"\",\"refundable\":false,\"flexAirport\""
						":true,\"flexDate\":false,\"flexDaysWeeks\":null},\"pageName\":\"FLEX_AIRPORT\"}", 
						LAST);
				
					lr_end_transaction(lr_eval_string("%FLEXAIRPORTSEARCH_{SearchAPI_Route}%"), LR_AUTO);
					
					if(atoi(lr_eval_string("{callDurationFlag}"))==1){
						lr_output_message("[REVENUE FLEXAIRPORTSEARCH\t%s]TripType:\t%s\tCallDuration:\t%s",lr_eval_string("{SearchAPI_Route}"),lr_eval_string("{RandTripType}"),lr_eval_string("{callDuration}"));
					}
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
						"Body={\"userdata\":{\"origin\":\"{Origin}\",\"destination\":\"{Destination}\",\"triptype\":\"ONE_WAY\",\"departuredate\":\"{P_DepartureDate}\",\"noofpassengers\":{numPax}},\"requestparam\":{\"campaignId\":\"shopping-lite:interstitial-banner\"}}", 
						EXTRARES, 
						"Url=../content/dam/delta-applications/{flightSearchLink}/static/v4.3.1/fonts/Whitney-Bold.eot", "Referer=https://{URL}/{flightSearchLink}/flexible-airports?cacheKeySuffix={c_cacheKey}", ENDITEM, 
						"Url=../content/dam/delta-applications/{flightSearchLink}static/v4.3.1/fonts/Whitney-Bold.otf", "Referer=https://{URL}/{flightSearchLink}/flexible-airports?cacheKeySuffix={c_cacheKey}", ENDITEM, 
						LAST);
					
					lr_end_transaction("%getpersonalizedContent%", LR_AUTO);
					if (atoi(lr_eval_string("{searchCriteria}"))<=0){
						lr_error_message("Revenue_%s_01_SearchFlight%s: Search Criteria Different for \tORIGIN\t%s\tDESTINATION\t%s\tFLIGHT DATES\t%s-%s\tCacheKey:%s",lr_eval_string("{RandTripType}"),lr_eval_string("{actionTypeTransaction}"),lr_eval_string("{Origin}"),lr_eval_string("{Destination}"),lr_eval_string("{P_DepartureDate}"),lr_eval_string("{P_ReturnDate}"),lr_eval_string("{cacheKey}"));
						lr_end_transaction(lr_eval_string("Revenue_{RandTripType}_01_SearchFlight{actionTypeTransaction}"), LR_AUTO);
							
						lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_FAIL);		
					}				
	
			}
				
				lr_end_transaction(lr_eval_string("Revenue_{RandTripType}_01_SearchFlight{actionTypeTransaction}"), LR_AUTO);
		
		if(strlen(lr_eval_string("{c_cacheKey}"))<=0){
			getErrorMessage();
			lr_output_message("Revenue_%s_01_SearchFlight%s: Flights page not available \tORIGIN\t%s\tDESTINATION\t%s\tFLIGHT DATES\t%s-%s\tError Number:\t%s\tError Message:\t%s",lr_eval_string("{RandTripType}"),lr_eval_string("{actionTypeTransaction}"),lr_eval_string("{Origin}"),lr_eval_string("{Destination}"),lr_eval_string("{P_DepartureDate}"),lr_eval_string("{P_ReturnDate}"),lr_eval_string("{errorNumber}"),lr_eval_string("{errorMessage}"));
			lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);
		} 
	} else 	if(strcmp(lr_eval_string("{RandTripType}"), "MC")==0){
		lr_save_string("false", "flexAirportFlag");
		lr_save_string("search", "actionType");	
		lr_save_string("", "actionTypeTransaction");	
		
	 	web_add_header("Upgrade-Insecure-Requests", 
			"1");
		
		lr_start_transaction(lr_eval_string("Revenue_{RandTripType}_01_SearchFlight{actionTypeTransaction}"));
	
		web_add_header("Upgrade-Insecure-Requests", 
			"1");
	
	web_submit_data("search-shop",
	                "Action=https://{URL}/flight-search/search-shop",
	                "Method=POST",
	                "RecContentType=text/html",
	                "Referer=https://{URL}/",
	                "Snapshot=t3.inf",
	                "Mode=HTML",
	                ITEMDATA,
	                "Name=selectTripType", "Value=MULTICITY", ENDITEM,
	                "Name=fromAirportCode", "Value={Origin}", ENDITEM,
	                "Name=fromCity", "Value={cityNameOrigin}, {regionOrigin}", ENDITEM,
	                "Name=toAirportcode", "Value={Destination}", ENDITEM,
	                "Name=toCity", "Value={cityNameDestination}, {regionDestination}", ENDITEM,
	                "Name=mpmRestriction", "Value=", ENDITEM,
	                "Name=milesRestriction", "Value=", ENDITEM,
	                "Name=connectionAirport", "Value=", ENDITEM,
	                "Name=originCity[1]", "Value={Origin}", ENDITEM,
	                "Name=destinationCity[1]", "Value={Destination}", ENDITEM,
	                "Name=departureDate[1]", "Value={P_departureDate}", ENDITEM,
	                "Name=connectionCity[1]", "Value=", ENDITEM,
	                "Name=departureTime[1]", "Value=AT", ENDITEM,
	                "Name=mpmRestriction[1]", "Value=", ENDITEM,
	                "Name=milesRestriction[1]", "Value=", ENDITEM,
	                "Name=fromAirportCode", "Value={Destination}", ENDITEM,
	                "Name=fromCity", "Value={cityNameDestination}", ENDITEM,
	                "Name=toAirportcode", "Value={FinalDestination}", ENDITEM,
	                "Name=toCity", "Value={cityNameFinalDestination}, {regionFinalDestination}", ENDITEM,
	                "Name=mpmRestriction", "Value=", ENDITEM,
	                "Name=milesRestriction", "Value=", ENDITEM,
	                "Name=connectionAirport", "Value=", ENDITEM,
	                "Name=originCity[2]", "Value={Destination}", ENDITEM,
	                "Name=destinationCity[2]", "Value={FinalDestination}", ENDITEM,
	                "Name=departureDate[2]", "Value={P_returnDate}", ENDITEM,
	                "Name=connectionCity[2]", "Value=", ENDITEM,
	                "Name=departureTime[2]", "Value=AT", ENDITEM,
	                "Name=mpmRestriction[2]", "Value=", ENDITEM,
	                "Name=milesRestriction[2]", "Value=", ENDITEM,
	                "Name=fromAirportCode", "Value={Origin}", ENDITEM,
	                "Name=fromCity", "Value={cityNameOrigin}", ENDITEM,
	                "Name=toAirportcode", "Value={Destination}", ENDITEM,
	                "Name=toCity", "Value={cityNameFinalDestination}, {regionFinalDestination}", ENDITEM,
	                "Name=mpmRestriction", "Value=", ENDITEM,
	                "Name=milesRestriction", "Value=", ENDITEM,
	                "Name=connectionAirport", "Value=", ENDITEM,
	                "Name=originCity[3]", "Value={Origin}", ENDITEM,
	                "Name=destinationCity[3]", "Value={Destination}", ENDITEM,
	                "Name=departureDate[3]", "Value={P_returnDate1}", ENDITEM,
	                "Name=connectionCity[3]", "Value=", ENDITEM,
	                "Name=departureTime[3]", "Value=AT", ENDITEM,
	                "Name=mpmRestriction[3]", "Value=", ENDITEM,
	                "Name=milesRestriction[3]", "Value=", ENDITEM,
	                "Name=schedulePrice", "Value=money", ENDITEM,
	                "Name=faresFor", "Value=BE", ENDITEM,
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
	                "Name=tripType", "Value=MULTICITY", ENDITEM,
	                "Name=cacheKey", "Value=", ENDITEM,
	                "Name=shopType", "Value=REVENUE", ENDITEM,
	                "Name=flexAirport", "Value=false", ENDITEM,
	                "Name=originAirportRadius", "Value=0", ENDITEM,
	                "Name=destinationAirportRadius", "Value=0", ENDITEM,
	                "Name=departureDate", "Value={P_DepartureDate}", ENDITEM,
	                "Name=returnDate", "Value={P_ReturnDate}", ENDITEM,
	                "Name=is_Flex_Search", "Value=true", ENDITEM,
	                "Name=datesFlexible", "Value=false", ENDITEM,
	                "Name=flexDays", "Value=3", ENDITEM,
	                "Name=bestFare", "Value=BE", ENDITEM,
	                "Name=fareFamily", "Value=BE", ENDITEM,
	                "Name=is_award_travel", "Value=false", ENDITEM,
	                "Name=paxCount", "Value={numPax}", ENDITEM,
	                "Name=flexDate", "Value=false", ENDITEM,
	                "Name=searchByCabin", "Value=true", ENDITEM,
	                "Name=cabinFareClass", "Value=", ENDITEM,
	                EXTRARES,
	                "Url=https://{contentURL}/content/dam/delta-applications/flight-search/static/v20.3.116/vendor/jquery-3.2.1.js", "Referer=https://{URL}/flight-search/search-shop?se=grid&&ftw_reroute=true", ENDITEM,
	                "Url=../content/dam/delta-applications/fresh-air-core/20.3.0/css/fresh-air.css", "Referer=https://{URL}/flight-search/search-shop?se=grid&&ftw_reroute=true", ENDITEM,
	                "Url=../content/dam/delta-applications/flight-search/static/styles/20.3.116/fonts/fonts.css", "Referer=https://{URL}/flight-search/search-shop?se=grid&&ftw_reroute=true", ENDITEM,
	                "Url=https://{contentURL}/content/dam/delta-applications/flight-search/static/styles/20.3.116/css/styles.css", "Referer=https://{URL}/flight-search/search-shop?se=grid&&ftw_reroute=true", ENDITEM,
	                "Url=https://{contentURL}/content/dam/delta-applications/flight-search/static/v20.3.116/vendor/tracker.js", "Referer=https://{URL}/flight-search/search-shop?se=grid&&ftw_reroute=true", ENDITEM,
	                "Url=https://{contentURL}/content/dam/delta-applications/flight-search/static/v20.3.116/vendor/delta.utils.logger.js", "Referer=https://{URL}/flight-search/search-shop?se=grid&&ftw_reroute=true", ENDITEM,
	                "Url=https://{contentURL}/content/dam/delta-applications/flight-search/static/v20.3.116/vendor/idp.datalayer.js", "Referer=https://{URL}/flight-search/search-shop?se=grid&&ftw_reroute=true", ENDITEM,
	                "Url=https://{contentURL}/content/dam/delta-applications/flight-search/static/v20.3.116/runtime.js", "Referer=https://{URL}/flight-search/search-shop?se=grid&&ftw_reroute=true", ENDITEM,
	                "Url=https://{contentURL}/content/dam/delta-applications/flight-search/static/v20.3.116/polyfills.js", "Referer=https://{URL}/flight-search/search-shop?se=grid&&ftw_reroute=true", ENDITEM,
	                "Url=https://{contentURL}/content/dam/delta-applications/flight-search/static/v20.3.116/main.js", "Referer=https://{URL}/flight-search/search-shop?se=grid&&ftw_reroute=true", ENDITEM,
	                LAST);
		
		// lr_save_int(1, "redirectFlag"); //<--- this is for debugging purposes only, this will force the flow into the desired route
		//======================== determine if the flow will be RSB or BAU =================================
		lr_save_string("flight-search", "flightSearchLink");
		lr_save_string("true", "ftw_reroute");
			
			    web_add_header("X-APP-CHANNEL", "sl-sho");
				web_add_header("X-APP-ROUTE", "SL-RSB");
				
				
		web_reg_save_param_json(
				"ParamName=c_cacheKey",
				"QueryString=$..request.cacheKey",
				"Notfound=warning",
				SEARCH_FILTERS,
				"Scope=Body",
				LAST);
		web_reg_save_param("errorNumber", "LB=\"code\":\"", "RB=\"", "Notfound=warning", LAST);
		//web_reg_save_param("errorMessage", "LB=\"message\":\"", "RB=\"", "Notfound=warning", LAST);
		
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
			"Referer=https://{URL}/{flightSearchLink}/search-shop", 
			"Snapshot=t11.inf", 
			"Mode=HTML", 
			EXTRARES, 
			"Url=../content/dam/delta-applications/flight-search/static/styles/20.3.116/fonts/Whitney-Book.otf", "Referer=https://{URL}/content/dam/delta-applications/flight-search/static/styles/20.3.116/fonts/fonts.css", ENDITEM, 
			"Url=../content/dam/delta-applications/flight-search/static/styles/20.3.116/fonts/icomoon.woff", "Referer=https://{URL}/content/dam/delta-applications/flight-search/static/styles/20.3.116/fonts/fonts.css", ENDITEM, 
			"Url=../content/dam/delta-applications/flight-search/static/styles/20.3.116/fonts/Whitney-Semibold.otf", "Referer=https://{URL}/content/dam/delta-applications/flight-search/static/styles/20.3.116/fonts/fonts.css", ENDITEM, 
			"Url=../content/dam/delta-applications/flight-search/static/styles/20.3.116/fonts/Whitney-Light.otf", "Referer=https://{URL}/content/dam/delta-applications/flight-search/static/styles/20.3.116/fonts/fonts.css", ENDITEM, 
			"Url=../content/dam/delta-applications/flight-search/static/styles/20.3.116/fonts/Whitney-Medium.otf", "Referer=https://{URL}/content/dam/delta-applications/flight-search/static/styles/20.3.116/fonts/fonts.css", ENDITEM, 
			LAST);
			
			web_url("getdevicetype", 
			"URL=https://{URL}/flight-search/getdevicetype", 
			"Resource=0", 
			"RecContentType=application/json", 
			"Referer=https://{URL}/flight-search/search-shop?se=grid&&ftw_reroute=true", 
			"Snapshot=t17.inf", 
			"Mode=HTML", 
			LAST);
			
		web_custom_request("retrieveSearch", 
			"URL=https://{URL}/prefill/retrieveSearch?searchType=RecentSearchesJSON", 
			"Method=GET", 
			"Resource=0", 
			"RecContentType=application/json", 
			"Referer=https://{URL}/flight-search/search-shop?se=grid&&ftw_reroute=true", 
			"Snapshot=t18.inf", 
			"Mode=HTML", 
			"EncType=application/json; charset=utf-8", 
			EXTRARES,
			"Url=../content/dam/delta-applications/fresh-air-core/20.3.0/css/fresh-air.css", "Referer=https://{URL}/content/dam/delta-applications/fresh-air-core/20.3.0/css/fresh-air.css", ENDITEM, 
			LAST);		
			
		web_custom_request("getDashBrdData_2", 
			"URL=https://{URL}/login/login/getDashBrdData", 
			"Method=POST", 
			"Resource=0", 
			"RecContentType=application/json", 
			"Referer=https://{URL}/flight-search/search-shop?se=grid&ftw_reroute=true", 
			"Snapshot=t20.inf", 
			"Mode=HTML", 
			"EncType=application/json; charset=UTF-8", 
			"Body={}", 
			LAST);
	
			if(strlen(lr_eval_string("{c_cacheKey}"))<=0){			
				lr_end_transaction(lr_eval_string("Revenue_{RandTripType}_01_SearchFlight{actionTypeTransaction}"), LR_AUTO);
				
				getErrorMessage();
				lr_output_message("Revenue_%s_01_SearchFlight%s: Flights page not available \tORIGIN\t%s\tDESTINATION\t%s\tFLIGHT DATES\t%s-%s\tError Number:\t%s\tError Message:\t%s",lr_eval_string("{RandTripType}"),lr_eval_string("{actionTypeTransaction}"),lr_eval_string("{Origin}"),lr_eval_string("{Destination}"),lr_eval_string("{P_DepartureDate}"),lr_eval_string("{P_ReturnDate}"),lr_eval_string("{errorNumber}"),lr_eval_string("{errorMessage}"));
				lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);
			} 
		
			lr_save_string(lr_eval_string("{c_cacheKey}"), "cacheKey");
			
			NonFlexSearch();
				
			lr_end_transaction(lr_eval_string("Revenue_{RandTripType}_01_SearchFlight{actionTypeTransaction}"), LR_AUTO);
	}
	
	
	lr_save_string(lr_eval_string("{c_cacheKey}"), "cacheKey");
	RSBFlow();
	
	return 0;
}
