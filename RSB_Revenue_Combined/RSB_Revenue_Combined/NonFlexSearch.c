NonFlexSearch()
{

  	lr_think_time(5);
 
	web_reg_save_param("C_currencyCode", "LB=\"currencyCode\":\"", "RB=\"", "Notfound=warning", LAST);
	web_reg_save_param("C_currencySymbol", "LB=\"currencySymbol\":\"", "RB=\"", "Notfound=warning", LAST);
	
  	if(strcmp(lr_eval_string("{RandTripType}"), "RT")==0){

			web_reg_save_param("offerAPIFlag", "LB=\"callPEOfferAPI\":\"", "RB=\"", "Notfound=warning", LAST);
			
			web_url("flightresult.data.json", 
				"URL=https://{URL}/content/www/en_US/air-shopping/flightresult.data.json", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", 
				"Snapshot=t7532.inf", 
				"Mode=HTML", 
				LAST);

			web_url("flightresult.data.json", 
				"URL=https://{URL}/content/www/en_US/air-shopping/flightresult.data.json", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", 
				"Snapshot=t7532.inf", 
				"Mode=HTML", 
				LAST);
			
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
						lr_save_string("OFFERAPI", "SearchAPI_Route");
						web_reg_save_param_json(
					        "ParamName=dominantSegmentBrandIdO",
					        //"QueryString=$.itinerary[*].fare[*].solutionId",
					        //"QueryString=$['itinerary','itineraries'][*]['fare','fares'][*]['dominantSegmentBrandId']",
					        "QueryString=$['itinerary','itineraries'][*]['fare','fares'][?(@.soldOut==false)]['dominantSegmentBrandId']",
					        "SelectAll=Yes",
					        "Notfound=warning",
					        "SEARCH_FILTERS",
					        "Scope=Body",
					        "LAST");
						
						web_add_header("X-OFFER-ROUTE", "SL-OFFER");
					} else {
							lr_save_string("SHOPAPI", "SearchAPI_Route");
						}
				}
			web_add_header("X-APP-CHANNEL", "sl-sho");
			web_add_header("X-APP-ROUTE", "SL-RSB");
			web_add_header("CacheKey", "{cacheKey}");
			web_add_header("Origin", "https://{URL}");
			
			web_reg_save_param("customerReferenceId", "LB=customerReferenceId\":\"", "RB=\"", "Notfound=warning", LAST);
	
			web_reg_save_param_json(
		        "ParamName=solutionIdO",
		        //"QueryString=$.itinerary[*].fare[*].solutionId",
		        //"QueryString=$['itinerary','itineraries'][*]['fare','fares'][*]['solutionId']",
		        "QueryString=$['itinerary','itineraries'][*]['fare','fares'][?(@.soldOut==false)]['solutionId']",
		        "SelectAll=Yes",
		        "Notfound=warning",
		        "SEARCH_FILTERS",
		        "Scope=Body",
		        "LAST");

			web_reg_save_param_json(
		        "ParamName=seatURL_LSM",
		        //"QueryString=$.itinerary[*].fare[*].solutionId",
		        //"QueryString=$['itinerary','itineraries'][*]['fare','fares'][*]['solutionId']",
		        "QueryString=$['itinerary','itineraries'][*]['trip','trips'][*]['viewSeatUrls'][*]",
		        "SelectAll=Yes",
		        "Notfound=warning",
		        "SEARCH_FILTERS",
		        "Scope=Body",
		        "LAST");
			
			web_reg_save_param_json(
		        "ParamName=p_dynamicBannerRequest",
		        "QueryString=$.dynamicBannerRequest",
		        "Notfound=warning",
		        "SEARCH_FILTERS",
		        "Scope=Body",
		        "LAST");
		
			web_reg_save_param_json(
			        "ParamName=callDuration",
			        //"QueryString=$.itinerary[*].fare[*].solutionId",
			        "QueryString=$..callDuration",
			        "Notfound=warning",
			        "SEARCH_FILTERS",
			        "Scope=Body",
			        "LAST");
			
			//web_reg_save_param("solutionIdO", "LB=solutionId\":\"", "RB=\"", "Ord=All", "Notfound=warning", LAST);
		
			web_reg_save_param("errorNumber", "LB=\"code\":\"", "RB=\"", "Notfound=warning", LAST);
						
			lr_start_transaction(lr_eval_string("%FlightShop_{SearchAPI_Route}%"));
			
			web_reg_find("Text=\"segments\":[{\"returnDate\":\"{P_ReturnDate}\",\"departureDate\":\"{P_DepartureDate}\",\"destination\":\"{Destination}\",\"origin\":\"{Origin}\"}]", "SaveCount=searchCriteria", LAST);
			
			web_custom_request("search", 
				"URL=https://{URL}/shop/rt/search", 
				"Method=POST", 
				"Resource=0", 
				"RecContentType=application/json", 
				"Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", 
				"Snapshot=t21.inf", 
				"Mode=HTML", 
				"EncType=application/json; charset=utf-8", 
				"Body={\"bestFare\":\"BE\",\"action\":\"findFlights\",\"destinationAirportRadius\":{\"unit\":\"MI\",\"measure\":100},\"deltaOnlySearch\":{deltaOnlySearch},\"meetingEventCode\":\"\",\"originAirportRadius\":{\"unit\":\"MI\",\"measure\":100},\"passengers\":[{\"type\":\"ADT\",\"count\":{numPax}}],\"searchType\":\"search\",\"segments\":[{\"returnDate\":\"{P_ReturnDate}\",\"departureDate\":\"{P_DepartureDate}\",\"destination\":\"{Destination}\",\"origin\":\"{Origin}\"}],\"shopType\":\"MONEY\",\"tripType\":\"ROUND_TRIP\",\"priceType\":\"Revenue\",\""
				"priceSchedule\":\"PRICE\",\"awardTravel\":false,\"refundableFlightsOnly\":false,\"nonstopFlightsOnly\":false,\"datesFlexible\":false,\"flexCalendar\":false,\"flexAirport\":{flexAirportFlag},\"upgradeRequest\":false,\"cacheKey\":\"{cacheKey}\",\"actionType\":\"{actionType}\",\"vendorDetails\":{},\"initialSearchBy\":{\"fareFamily\":\"BE\",\"cabinFareClass\":null,\"meetingEventCode\":\"\",\"refundable\":false,\"flexAirport\":{flexAirportFlag},\"flexDate\":false,\"flexDaysWeeks\":null},\"pageName\":\""
				"FLIGHT_SEARCH\",\"requestPageNum\":\"1\"}",
				EXTRARES, 
				"Url=https://{contentURL}/content/dam/delta-applications/flight-search/assets/images/desktopspinner-white-100x100-animation.gif", "Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", ENDITEM, 
				LAST);
		
			lr_end_transaction(lr_eval_string("%FlightShop_{SearchAPI_Route}%"), LR_AUTO);
			
			if(atoi(lr_eval_string("{callDurationFlag}"))==1){
				lr_output_message("[REVENUE FLIGHTSHOP\t%s]TripType:\t%s\tCallDuration:\t%s",lr_eval_string("{SearchAPI_Route}"),lr_eval_string("{RandTripType}"),lr_eval_string("{callDuration}"));
			}
			web_url("bcdata.action", 
				"URL=https://{URL}/databroker/bcdata.action", 
				"Resource=0", 
				"RecContentType=application/json", 
				"Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", 
				"Snapshot=t4.inf", 
				"Mode=HTML", 
				LAST);
		
			web_url("getdevicetype_2", 
				"URL=https://{URL}/flight-search/getdevicetype", 
				"Resource=0", 
				"Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", 
				"Snapshot=t18.inf", 
				"Mode=HTML", 
				LAST);
			
			web_url("ErrorMessage.json", 
				"URL=https://{URL}/content/dam/delta-applications/flight-search/assets/json/ErrorMessage.json", 
				"Resource=0", 
				"RecContentType=application/json", 
				"Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", 
				"Snapshot=t20.inf", 
				"Mode=HTML", 
				LAST);
			
			web_add_auto_header("CacheKey", 
				"{cacheKey}");
		
			web_add_auto_header("Origin", 
				"https://{URL}");
		
			web_add_auto_header("X-APP-CHANNEL", 
				"sl-sho");
		
			web_add_auto_header("X-APP-ROUTE", 
				"SL-RSB");
		
			lr_start_transaction("%getpersonalizedContent%");
			
			web_custom_request("getpersonalizedContent", 
				"URL=https://{URL}/personalization-api/getpersonalizedContent", 
				"Method=POST", 
				"Resource=0", 
				"RecContentType=application/json", 
				"Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", 
				"Snapshot=t5.inf", 
				"Mode=HTML", 
				"EncType=application/json; charset=UTF-8", 
				"Body={\"userdata\":{\"origin\":\"{Origin}\",\"destination\":\"{Destination}\",\"triptype\":\"ROUND_TRIP\",\"departuredate\":\"{P_DepartureDate}\",\"returndate\":\"{P_ReturnDate}\",\"noofpassengers\":{numPax}},\"requestparam\":{\"campaignId\":\"shopping-lite:interstitial-banner\"}}", 
				EXTRARES, 
				"Url=../content/dam/delta-applications/flight-search/assets/images/supergraphic-delta-mark_1200.svg", "Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", ENDITEM, 
				"Url=../content/dam/delta-www/responsive/apps/login/favicon.ico", "Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", ENDITEM, 
				LAST);
		
			
			lr_end_transaction("%getpersonalizedContent%", LR_AUTO);
			
			if(atoi(lr_eval_string("{covidBannerFlag}"))==0){
				lr_start_transaction("%getpersonalizedContent%");
				
				web_custom_request("getpersonalizedContent_2", 
					"URL=https://{URL}/personalization-api/getpersonalizedContent", 
					"Method=POST", 
					"Resource=0", 
					"RecContentType=application/json", 
					"Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", 
					"Snapshot=t6.inf", 
					"Mode=HTML", 
					"EncType=application/json; charset=UTF-8", 
					"Body={\"userdata\":{\"loggedinrestriction\":\"yes\",\"triptype\":\"ROUND_TRIP\",\"includesaturdaynightstay\":false,\"returndate\":\"{P_ReturnDate}\",\"origin\":\"{Origin}\",\"shoppingDate\":\"{date_today}\",\"destination\":\"{Destination}\",\"departuredate\":\"{P_DepartureDate}\",\"returnadvancepurchase\":174,\"noofpassengers\":{numPax},\"skymilesTier\":\"\",\"markettype\":\"Domestic48\",\"originDestinationPair\":\"{Origin}{Destination}\",\"corporate\":false,\"departureadvancepurchase\":172,\"shopType\":\"Revenue\",\"availableFareBrands\":[\"DCP\","
					"\"MAIN\",\"FIRST\"]},\"requestparam\":{\"campaignId\":\"shopping-lite:dynamic-banner\"}}", 
					LAST);
			
				lr_end_transaction("%getpersonalizedContent%", LR_AUTO);
			}
			web_revert_auto_header("CacheKey");
		
			web_revert_auto_header("X-APP-CHANNEL");
		
			web_revert_auto_header("X-APP-ROUTE");
		
			web_revert_auto_header("Origin");

			if(atoi(lr_eval_string("{covidBannerFlag}"))>0){
				PE_SHO_Banner();
			}
			
			if(atoi(lr_eval_string("{solutionIdO_count}"))>0)
			{	
				return 0;	
				
			} else if (strlen(lr_eval_string("{customerReferenceId}"))<=0){
				//lr_output_message("Customer Reference Id not found for \tORIGIN\t%s\tDESTINATION\t%s\tCACHEKEY:%s",lr_eval_string("{Origin}"),lr_eval_string("{Destination}"),lr_eval_string("{cacheKey}"));
				lr_end_transaction(lr_eval_string("Revenue_{RandTripType}_01_SearchFlight{actionTypeTransaction}"), LR_AUTO);
				getErrorMessage();
				lr_output_message("Customer Reference Id not found for \tORIGIN\t%s\tDESTINATION\t%s\tCACHEKEY:%s\tError Number:\t%s\tError Message:\t%s",lr_eval_string("{Origin}"),lr_eval_string("{Destination}"),lr_eval_string("{cacheKey}"),lr_eval_string("{errorNumber}"),lr_eval_string("{errorMessage}"));		
				lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);		
			} else if (strlen(lr_eval_string("{searchCriteria}"))<=0){
				lr_error_message("Revenue_%s_01_SearchFlight-RSB_%s: Search Criteria Different for \tORIGIN\t%s\tDESTINATION\t%s\tFLIGHT DATES\t%s-%s\tCacheKey:%s",lr_eval_string("{RandTripType}"),lr_eval_string("{SearchAPI_Route}"),lr_eval_string("{Origin}"),lr_eval_string("{Destination}"),lr_eval_string("{P_DepartureDate}"),lr_eval_string("{P_ReturnDate}"),lr_eval_string("{cacheKey}"));
				lr_end_transaction(lr_eval_string("Revenue_{RandTripType}_01_SearchFlight{actionTypeTransaction}"), LR_AUTO);	
				lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);		
			}
			else
			{	
				lr_end_transaction(lr_eval_string("Revenue_{RandTripType}_01_SearchFlight{actionTypeTransaction}"), LR_AUTO);
				
				getErrorMessage();
				lr_output_message("Revenue_%s_01_SearchFlight-RSB_%s: No Flights Found for \tORIGIN\t%s\tDESTINATION\t%s\tFLIGHT DATES\t%s-%s\tError Number:\t%s\tError Message:\t%s\tCacheKey:%s",lr_eval_string("{RandTripType}"),lr_eval_string("{SearchAPI_Route}"),lr_eval_string("{Origin}"),lr_eval_string("{Destination}"),lr_eval_string("{P_DepartureDate}"),lr_eval_string("{P_ReturnDate}"),lr_eval_string("{errorNumber}"),lr_eval_string("{errorMessage}"),lr_eval_string("{cacheKey}"));
				lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);
			}
  	} else if(strcmp(lr_eval_string("{RandTripType}"), "OW")==0){

			web_reg_save_param("offerAPIFlag", "LB=\"callPEOfferAPI\":\"", "RB=\"", "Notfound=warning", LAST);
			
			web_url("flightresult.data.json", 
				"URL=https://{URL}/content/www/en_US/air-shopping/flightresult.data.json", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", 
				"Snapshot=t7532.inf", 
				"Mode=HTML", 
				LAST);

			web_url("flightresult.data.json", 
				"URL=https://{URL}/content/www/en_US/air-shopping/flightresult.data.json", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", 
				"Snapshot=t7532.inf", 
				"Mode=HTML", 
				LAST);
			
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
						lr_save_string("OFFERAPI", "SearchAPI_Route");
					web_reg_save_param_json(
				        "ParamName=dominantSegmentBrandIdO",
				        //"QueryString=$.itinerary[*].fare[*].solutionId",
				        //"QueryString=$['itinerary','itineraries'][*]['fare','fares'][*]['dominantSegmentBrandId']",
				        "QueryString=$['itinerary','itineraries'][*]['fare','fares'][?(@.soldOut==false)]['dominantSegmentBrandId']",
				        "SelectAll=Yes",
				        "Notfound=warning",
				        "SEARCH_FILTERS",
				        "Scope=Body",
				        "LAST");
					
					web_add_header("X-OFFER-ROUTE", "SL-OFFER");
					}else {
							lr_save_string("SHOPAPI", "SearchAPI_Route");
						}
				}
			web_add_header("X-APP-CHANNEL", "sl-sho");
			web_add_header("X-APP-ROUTE", "SL-RSB");
			web_add_header("CacheKey", "{cacheKey}");
			web_add_header("Origin", "https://{URL}");
			
			web_reg_save_param("customerReferenceId", "LB=customerReferenceId\":\"", "RB=\"", "Notfound=warning", LAST);
			
			//web_reg_save_param("solutionIdO", "LB=solutionId\":\"", "RB=\"", "Ord=All", "Notfound=warning", LAST);
			
			web_reg_save_param_json(
		        "ParamName=solutionIdO",
		        //"QueryString=$.itinerary[*].fare[*].solutionId",
		        //"QueryString=$['itinerary','itineraries'][*]['fare','fares'][*]['solutionId']",
		        "QueryString=$['itinerary','itineraries'][*]['fare','fares'][?(@.soldOut==false)]['solutionId']",
		        "SelectAll=Yes",
		        "Notfound=warning",
		        "SEARCH_FILTERS",
		        "Scope=Body",
		        "LAST");

			web_reg_save_param_json(
		        "ParamName=seatURL_LSM",
		        //"QueryString=$.itinerary[*].fare[*].solutionId",
		        //"QueryString=$['itinerary','itineraries'][*]['fare','fares'][*]['solutionId']",
		        "QueryString=$['itinerary','itineraries'][*]['trip','trips'][*]['viewSeatUrls'][*]",
		        "SelectAll=Yes",
		        "Notfound=warning",
		        "SEARCH_FILTERS",
		        "Scope=Body",
		        "LAST");
			
			web_reg_save_param_json(
		        "ParamName=p_dynamicBannerRequest",
		        "QueryString=$.dynamicBannerRequest",
		        "Notfound=warning",
		        "SEARCH_FILTERS",
		        "Scope=Body",
		        "LAST");
			
			web_reg_save_param_json(
		        "ParamName=callDuration",
		        //"QueryString=$.itinerary[*].fare[*].solutionId",
		        "QueryString=$..callDuration",
		        "Notfound=warning",
		        "SEARCH_FILTERS",
		        "Scope=Body",
		        "LAST");
			
			web_reg_save_param("errorNumber", "LB=\"code\":\"", "RB=\"", "Notfound=warning", LAST);
						
			lr_start_transaction(lr_eval_string("%FlightShop_{SearchAPI_Route}%"));
			
			web_reg_find("Text=\"segments\":[{\"departureDate\":\"{P_DepartureDate}\",\"destination\":\"{Destination}\",\"origin\":\"{Origin}\"}]", "SaveCount=searchCriteria", LAST);
			
			web_custom_request("search", 
				"URL=https://{URL}/shop/ow/search", 
				"Method=POST", 
				"Resource=0", 
				"RecContentType=application/json", 
				"Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", 
				"Snapshot=t21.inf", 
				"Mode=HTML", 
				"EncType=application/json; charset=utf-8", 
				"Body={\"bestFare\":\"BE\",\"action\":\"findFlights\",\"destinationAirportRadius\":{\"unit\":\"MI\",\"measure\":100},\"deltaOnlySearch\":{deltaOnlySearch},\"meetingEventCode\":\"\",\"originAirportRadius\":{\"unit\":\"MI\",\"measure\":100},\"passengers\":[{\"type\":\"ADT\",\"count\":{numPax}}],\"searchType\":\"search\",\"segments\":[{\"departureDate\":\"{P_DepartureDate}\",\"destination\":\"{Destination}\",\"origin\":\"{Origin}\"}],\"shopType\":\"MONEY\",\"tripType\":\"ONE_WAY\",\"priceType\":\"Revenue\",\""
				"priceSchedule\":\"PRICE\",\"awardTravel\":false,\"refundableFlightsOnly\":false,\"nonstopFlightsOnly\":false,\"datesFlexible\":false,\"flexCalendar\":false,\"flexAirport\":{flexAirportFlag},\"upgradeRequest\":false,\"cacheKey\":\"{cacheKey}\",\"actionType\":\"{actionType}\",\"vendorDetails\":{},\"initialSearchBy\":{\"fareFamily\":\"BE\",\"cabinFareClass\":null,\"meetingEventCode\":\"\",\"refundable\":false,\"flexAirport\":{flexAirportFlag},\"flexDate\":false,\"flexDaysWeeks\":null},\"pageName\":\""
				"FLIGHT_SEARCH\",\"requestPageNum\":\"1\"}",
				EXTRARES, 
				"Url=https://{contentURL}/content/dam/delta-applications/flight-search/assets/images/desktopspinner-white-100x100-animation.gif", "Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", ENDITEM, 
				LAST);
		
			lr_end_transaction(lr_eval_string("%FlightShop_{SearchAPI_Route}%"), LR_AUTO);
			
			if(atoi(lr_eval_string("{callDurationFlag}"))==1){
				lr_output_message("[REVENUE FLIGHTSHOP\t%s]TripType:\t%s\tCallDuration:\t%s",lr_eval_string("{SearchAPI_Route}"),lr_eval_string("{RandTripType}"),lr_eval_string("{callDuration}"));
			}
			web_url("bcdata.action", 
				"URL=https://{URL}/databroker/bcdata.action", 
				"Resource=0", 
				"RecContentType=application/json", 
				"Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", 
				"Snapshot=t4.inf", 
				"Mode=HTML", 
				LAST);
		
			web_url("getdevicetype_2", 
				"URL=https://{URL}/flight-search/getdevicetype", 
				"Resource=0", 
				"Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", 
				"Snapshot=t18.inf", 
				"Mode=HTML", 
				LAST);
			
			web_url("ErrorMessage.json", 
				"URL=https://{URL}/content/dam/delta-applications/flight-search/assets/json/ErrorMessage.json", 
				"Resource=0", 
				"RecContentType=application/json", 
				"Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", 
				"Snapshot=t20.inf", 
				"Mode=HTML", 
				LAST);
			
			web_add_auto_header("CacheKey", 
				"{cacheKey}");
		
			web_add_auto_header("Origin", 
				"https://{URL}");
		
			web_add_auto_header("X-APP-CHANNEL", 
				"sl-sho");
		
			web_add_auto_header("X-APP-ROUTE", 
				"SL-RSB");
		
			lr_start_transaction("%getpersonalizedContent%");
			
			web_custom_request("getpersonalizedContent", 
				"URL=https://{URL}/personalization-api/getpersonalizedContent", 
				"Method=POST", 
				"Resource=0", 
				"RecContentType=application/json", 
				"Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", 
				"Snapshot=t5.inf", 
				"Mode=HTML", 
				"EncType=application/json; charset=UTF-8", 
				"Body={\"userdata\":{\"origin\":\"{Origin}\",\"destination\":\"{Destination}\",\"triptype\":\"ONE_WAY\",\"departuredate\":\"{P_DepartureDate}\",\"noofpassengers\":{numPax}},\"requestparam\":{\"campaignId\":\"shopping-lite:interstitial-banner\"}}", 
				EXTRARES, 
				"Url=../content/dam/delta-applications/flight-search/assets/images/supergraphic-delta-mark_1200.svg", "Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", ENDITEM, 
				"Url=../content/dam/delta-www/responsive/apps/login/favicon.ico", "Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", ENDITEM, 
				LAST);
		
			
			lr_end_transaction("%getpersonalizedContent%", LR_AUTO);
			if(atoi(lr_eval_string("{covidBannerFlag}"))==0){
				lr_start_transaction("%getpersonalizedContent%");
				
				web_custom_request("getpersonalizedContent_2", 
					"URL=https://{URL}/personalization-api/getpersonalizedContent", 
					"Method=POST", 
					"Resource=0", 
					"RecContentType=application/json", 
					"Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", 
					"Snapshot=t6.inf", 
					"Mode=HTML", 
					"EncType=application/json; charset=UTF-8", 
					"Body={\"userdata\":{\"loggedinrestriction\":\"yes\",\"triptype\":\"ONE_WAY\",\"includesaturdaynightstay\":false,\"origin\":\"{Origin}\",\"shoppingDate\":\"{date_today}\",\"destination\":\"{Destination}\",\"departuredate\":\"{P_DepartureDate}\",\"returnadvancepurchase\":174,\"noofpassengers\":{numPax},\"skymilesTier\":\"\",\"markettype\":\"Domestic48\",\"originDestinationPair\":\"{Origin}{Destination}\",\"corporate\":false,\"departureadvancepurchase\":172,\"shopType\":\"Revenue\",\"availableFareBrands\":[\"DCP\","
					"\"MAIN\",\"FIRST\"]},\"requestparam\":{\"campaignId\":\"shopping-lite:dynamic-banner\"}}", 
					LAST);
			
				lr_end_transaction("%getpersonalizedContent%", LR_AUTO);
			}
			web_revert_auto_header("CacheKey");
		
			web_revert_auto_header("X-APP-CHANNEL");
		
			web_revert_auto_header("X-APP-ROUTE");
		
			web_revert_auto_header("Origin");

			if(atoi(lr_eval_string("{covidBannerFlag}"))>0){
				PE_SHO_Banner();
			}
			
			if(atoi(lr_eval_string("{solutionIdO_count}"))>0)
			{	
				return 0;	
				
			} else if (strlen(lr_eval_string("{customerReferenceId}"))<=0){
				//lr_output_message("Customer Reference Id not found for \tORIGIN\t%s\tDESTINATION\t%s\tCACHEKEY:%s",lr_eval_string("{Origin}"),lr_eval_string("{Destination}"),lr_eval_string("{cacheKey}"));
				lr_end_transaction(lr_eval_string("Revenue_{RandTripType}_01_SearchFlight{actionTypeTransaction}"), LR_AUTO);
				getErrorMessage();
				lr_output_message("Customer Reference Id not found for \tORIGIN\t%s\tDESTINATION\t%s\tCACHEKEY:%s\tError Number:\t%s\tError Message:\t%s",lr_eval_string("{Origin}"),lr_eval_string("{Destination}"),lr_eval_string("{cacheKey}"),lr_eval_string("{errorNumber}"),lr_eval_string("{errorMessage}"));		
				lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);		
			} else if (strlen(lr_eval_string("{searchCriteria}"))<=0){
				lr_error_message("Revenue_%s_01_SearchFlight-RSB_%s: Search Criteria Different for \tORIGIN\t%s\tDESTINATION\t%s\tFLIGHT DATES\t%s-%s\tCacheKey:%s",lr_eval_string("{RandTripType}"),lr_eval_string("{SearchAPI_Route}"),lr_eval_string("{Origin}"),lr_eval_string("{Destination}"),lr_eval_string("{P_DepartureDate}"),lr_eval_string("{P_ReturnDate}"),lr_eval_string("{cacheKey}"));
				lr_end_transaction(lr_eval_string("Revenue_{RandTripType}_01_SearchFlight{actionTypeTransaction}"), LR_AUTO);	
				lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);		
			}
			else
			{	
				lr_end_transaction(lr_eval_string("Revenue_{RandTripType}_01_SearchFlight{actionTypeTransaction}"), LR_AUTO);
				
				getErrorMessage();
				lr_output_message("Revenue_%s_01_SearchFlight-RSB_%s: No Flights Found for \tORIGIN\t%s\tDESTINATION\t%s\tFLIGHT DATES\t%s-%s\tError Number:\t%s\tError Message:\t%s\tCacheKey:%s",lr_eval_string("{RandTripType}"),lr_eval_string("{SearchAPI_Route}"),lr_eval_string("{Origin}"),lr_eval_string("{Destination}"),lr_eval_string("{P_DepartureDate}"),lr_eval_string("{P_ReturnDate}"),lr_eval_string("{errorNumber}"),lr_eval_string("{errorMessage}"),lr_eval_string("{cacheKey}"));
				lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);
			}
  	} else if(strcmp(lr_eval_string("{RandTripType}"), "MC")==0){
		
			web_reg_save_param("offerAPIFlag", "LB=\"callPEOfferAPI\":\"", "RB=\"", "Notfound=warning", LAST);
			
			web_url("flightresult.data.json", 
				"URL=https://{URL}/content/www/en_US/air-shopping/flightresult.data.json", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", 
				"Snapshot=t7532.inf", 
				"Mode=HTML", 
				LAST);

			web_url("flightresult.data.json", 
				"URL=https://{URL}/content/www/en_US/air-shopping/flightresult.data.json", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", 
				"Snapshot=t7532.inf", 
				"Mode=HTML", 
				LAST);
			
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
						lr_save_string("OFFERAPI", "SearchAPI_Route");
						web_reg_save_param_json(
					        "ParamName=dominantSegmentBrandIdO",
					        //"QueryString=$.itinerary[*].fare[*].solutionId",
					        //"QueryString=$['itinerary','itineraries'][*]['fare','fares'][*]['dominantSegmentBrandId']",
					        "QueryString=$['itinerary','itineraries'][*]['fare','fares'][?(@.soldOut==false)]['dominantSegmentBrandId']",
					        "SelectAll=Yes",
					        "Notfound=warning",
					        "SEARCH_FILTERS",
					        "Scope=Body",
					        "LAST");
						
						web_add_header("X-OFFER-ROUTE", "SL-OFFER");
					} else {
							lr_save_string("SHOPAPI", "SearchAPI_Route");
						}
				}
			
		 	web_add_header("CacheKey",
				"{cacheKey}");
		
			web_add_header("X-APP-CHANNEL", 
				"sl-sho");
			
			web_add_header("X-APP-ROUTE", 
				"SL-RSB");
		
			//web_reg_save_param("solutionId_DUMMY", "LB=solutionId\":\"", "RB=\"", "Ord=All", "Notfound=warning", LAST);
		
			web_reg_save_param_json(
		        "ParamName=solutionIdO",
		        //"QueryString=$.itinerary[*].fare[*].solutionId",
		        //"QueryString=$['itinerary','itineraries'][*]['fare','fares'][*]['solutionId']",
		        "QueryString=$['itinerary','itineraries'][*]['fare','fares'][?(@.soldOut==false)]['solutionId']",
		        "SelectAll=Yes",
		        "Notfound=warning",
		        "SEARCH_FILTERS",
		        "Scope=Body",
		        "LAST");

			web_reg_save_param_json(
		        "ParamName=seatURL_LSM",
		        //"QueryString=$.itinerary[*].fare[*].solutionId",
		        //"QueryString=$['itinerary','itineraries'][*]['fare','fares'][*]['solutionId']",
		        "QueryString=$['itinerary','itineraries'][*]['trip','trips'][*]['viewSeatUrls'][*]",
		        "SelectAll=Yes",
		        "Notfound=warning",
		        "SEARCH_FILTERS",
		        "Scope=Body",
		        "LAST");
			
			web_reg_save_param_json(
		        "ParamName=p_dynamicBannerRequest",
		        "QueryString=$.dynamicBannerRequest",
		        "Notfound=warning",
		        "SEARCH_FILTERS",
		        "Scope=Body",
		        "LAST");
			
			web_reg_save_param_json(
		        "ParamName=callDuration",
		        //"QueryString=$.itinerary[*].fare[*].solutionId",
		        "QueryString=$..callDuration",
		        "Notfound=warning",
		        "SEARCH_FILTERS",
		        "Scope=Body",
		        "LAST");
			
			web_reg_save_param("errorNumber", "LB=\"code\":\"", "RB=\"", "Notfound=warning", LAST);
			//web_reg_save_param("errorMessage", "LB=\"message\":\"", "RB=\"", "Notfound=warning", LAST);
					
			lr_start_transaction(lr_eval_string("%FlightShop_{SearchAPI_Route}%"));
		
			web_custom_request("search_2", 
				"URL=https://{URL}/shop/mc/search", 
				"Method=POST", 
				"Resource=0", 
				"RecContentType=application/json", 
				"Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", 
				"Snapshot=t1152.inf", 
				"Mode=HTML", 
				"EncType=application/json; charset=UTF-8", 
				"Body={\"bestFare\":\"BE\",\"action\":\"findFlights\",\"destinationAirportRadius\":{\"unit\":\"MI\",\"measure\":100},\"deltaOnlySearch\":{deltaOnlySearch},\"meetingEventCode\":\"\",\"originAirportRadius\":{\"unit\":\"MI\",\"measure\":100},\"passengers\":[{\"type\":\"ADT\",\"count\":{numPax}}],\"searchType\":\"search\",\"segments\":[{\"departureDate\":\"{P_DepartureDate}\",\"destination\":\"{Destination}\",\"origin\":\"{Origin}\"},{\"departureDate\":\"{P_ReturnDate}\",\"destination\":\"{FinalDestination}\",\"origin\":\"{Destination}\"},{\"departureDate\":\"{P_ReturnDate1}"
				"\",\"destination\":\"{Destination}\",\"origin\":\"{Origin}\"}],\"shopType\":\"MONEY\",\"tripType\":\"MULTICITY\",\"priceType\":\"Revenue\",\"priceSchedule\":\"PRICE\",\"awardTravel\":false,\"refundableFlightsOnly\":false,\"nonstopFlightsOnly\":false,\"datesFlexible\":false,\"flexCalendar\":false,\"flexAirport\":false,\"upgradeRequest\":false,\"cacheKey\":\"{cacheKey}\",\"actionType\":\"search\",\"vendorDetails\":{},\"initialSearchBy\":{\"fareFamily\":\"BE\",\"cabinFareClass\":null,\""
				"meetingEventCode\":\"\",\"refundable\":false,\"flexAirport\":false,\"flexDate\":false,\"flexDaysWeeks\":null},\"pageName\":\"FLIGHT_SEARCH\",\"requestPageNum\":\"1\"}", 
				EXTRARES, 
		//		"Url=/content/www/en_US/air-shopping/flightresult.data.json", "Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", ENDITEM, 
				LAST);
		
			lr_end_transaction(lr_eval_string("%FlightShop_{SearchAPI_Route}%"), LR_AUTO);
			
			if(atoi(lr_eval_string("{callDurationFlag}"))==1){
				lr_output_message("[REVENUE FLIGHTSHOP\t%s]TripType:\t%s\tCallDuration:\t%s",lr_eval_string("{SearchAPI_Route}"),lr_eval_string("{RandTripType}"),lr_eval_string("{callDuration}"));
			}
			web_revert_auto_header("Origin");
		
			web_url("getdevicetype_2", 
				"URL=https://{URL}/flight-search/getdevicetype", 
				"Resource=0", 
				"Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", 
				"Snapshot=t1212.inf", 
				"Mode=HTML", 
				LAST);
		
			web_url("bcdata.action_2", 
				"URL=https://{URL}/databroker/bcdata.action", 
				"Resource=0", 
				"RecContentType=application/json", 
				"Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", 
				"Snapshot=t1376.inf", 
				"Mode=HTML", 
				LAST);
		
			web_add_header("CacheKey", 
				"{cacheKey}");
		
			web_add_auto_header("Origin", 
				"https://{URL}");
		
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
				"Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", 
				"Snapshot=t1443.inf", 
				"Mode=HTML", 
				"EncType=application/json; charset=UTF-8", 
				"Body={\"userdata\":{\"origin\":\"{Origin}\",\"destination\":\"{Destination}\",\"triptype\":\"MULTICITY\",\"departuredate\":\"{P_DepartureDate}\",\"noofpassengers\":1},\"requestparam\":{\"campaignId\":\"shopping-lite:interstitial-banner\"}}", 
				EXTRARES, 
				"Url=../content/dam/delta-applications/flight-search/assets/images/supergraphic-delta-mark_1200.svg", "Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", ENDITEM,
				"Url=../content/dam/delta-applications/air-shopping/flightResults/interstitials/dps-A330-900NEO-seats-717.jpg", "Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", ENDITEM, 
				"Url=../content/dam/delta-applications/air-shopping/flightResults/interstitials/dps-A330-900NEO-seats-945.jpg", "Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", ENDITEM, 		
				LAST);
		
			lr_end_transaction("%getpersonalizedContent%", LR_AUTO);
			
			if(atoi(lr_eval_string("{covidBannerFlag}"))==0){
				web_add_header("CacheKey", 
					"{cacheKey}");
			
				web_add_header("X-APP-CHANNEL", 
					"sl-sho");
			
				web_add_header("X-APP-ROUTE", 
					"SL-RSB");
			
				lr_start_transaction("%getpersonalizedContent%");
				
				web_custom_request("getpersonalizedContent_2", 
					"URL=https://{URL}/personalization-api/getpersonalizedContent", 
					"Method=POST", 
					"Resource=0", 
					"RecContentType=application/json", 
					"Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", 
					"Snapshot=t2042.inf", 
					"Mode=HTML", 
					"EncType=application/json; charset=UTF-8", 
					"Body={\"userdata\":{\"loggedinrestriction\":\"yes\",\"triptype\":\"MULTICITY\",\"includesaturdaynightstay\":false,\"origin\":\"{Origin}\",\"shoppingDate\":\"{date_today}\",\"destination\":\"{Destination}\",\"departuredate\":\"{P_DepartureDate}\",\"noofpassengers\":{numPax},\"skymilesTier\":\"\",\"markettype\":\"Domestic48\",\"originDestinationPair\":\"{Origin}{Destination}\",\"corporate\":false,\"departureadvancepurchase\":141,\"shopType\":\"Award\",\"availableFareBrands\":[\"DCP\",\"MAIN\",\"FIRST\"]},\"requestparam\":{\"campaignId\":\""
					"shopping-lite:dynamic-banner\"}}", 
					EXTRARES, 
			//		"Url=../content/dam/delta-applications/fresh-air-core/5.1.0/fonts/AABA9C13AF9C5C638.woff2", "Referer=https://{URL}/content/dam/delta-applications/fresh-air-core/5.1.0/fonts/fresh-air-fonts.css", ENDITEM, 
			//		"Url=../content/dam/delta-applications/fresh-air-core/5.1.0/fonts/3955045D2CF71A4B6.woff2", "Referer=https://{URL}/content/dam/delta-applications/fresh-air-core/5.1.0/fonts/fresh-air-fonts.css", ENDITEM, 
			//		"Url=https://{contentURL}/content/dam/delta-applications/flight-search/assets/sprites/sprites-shopping.png", "Referer=https://{contentURL}/content/dam/delta-applications/flight-search/static/v4.2.13/styles.css", ENDITEM, 
			//		"Url=https://{contentURL}/content/dam/delta-applications/flight-search/assets/sprites/flight-results-sprite-1.png", "Referer=https://{contentURL}/content/dam/delta-applications/flight-search/static/v4.2.13/styles.css", ENDITEM, 
					LAST);
			
				lr_end_transaction("%getpersonalizedContent%", LR_AUTO);
			}
			if(atoi(lr_eval_string("{covidBannerFlag}"))>0){
				PE_SHO_Banner();
			}
			
			if(atoi(lr_eval_string("{solutionIdO_count}"))<=0)
			{
				
				//lr_output_message("No Flights Found for \tORIGIN\t%s\tDESTINATION\t%s\tFINALDESTINATION\t%s",lr_eval_string("{Origin}"),lr_eval_string("{Destination}"),lr_eval_string("{FinalDestination}"));
				lr_end_transaction(lr_eval_string("Revenue_{RandTripType}_01_SearchFlight{actionTypeTransaction}"), LR_AUTO);
				getErrorMessage();
				lr_output_message("Revenue_%s_01_SearchFlight-RSB_%s: No Flights Found for \tORIGIN\t%s\tDESTINATION\t%s\tFINALDESTINATION\t%s\tFLIGHT DATES\t%s-%s-%s\tError Number:\t%s\tError Message:\t%s\tCacheKey:%s",lr_eval_string("{RandTripType}"),lr_eval_string("{SearchAPI_Route}"),lr_eval_string("{Origin}"),lr_eval_string("{Destination}"),lr_eval_string("{FinalDestination}"),lr_eval_string("{P_DepartureDate}"),lr_eval_string("{P_ReturnDate}"),lr_eval_string("{P_ReturnDate1}"),lr_eval_string("{errorNumber}"),lr_eval_string("{errorMessage}"),lr_eval_string("{cacheKey}"));
				lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);
			} 		
  	}
  
	return 0;
}
