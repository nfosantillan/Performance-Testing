SelectSecondFlight()
{
	
	int i, seatsSecondSuccess=0;
	lr_think_time(5);

	
		
   		if(atoi(lr_eval_string("{offerAPI_ON}"))>0){

				lr_save_string("DCP", "COMFORTPLUS");
				lr_save_string("BE", "BASICECONOMY");
				lr_save_string("MAIN", "ECONOMY");
				//lr_save_string("BUSINESS-FIRST", "BUSINESSFIRST");
				lr_save_string("FIRST", "FIRST");
				
				for(i=1;i<=atoi(lr_eval_string("{solutionId2_count}"));i++){
							
					if((strstr(lr_eval_string(lr_paramarr_idx("dominantSegmentBrandId2", i)), lr_eval_string("{COMFORTPLUS}"))!=NULL)||(strstr(lr_eval_string(lr_paramarr_idx("dominantSegmentBrandId2", i)), lr_eval_string("{ECONOMY}"))!=NULL)||(strstr(lr_eval_string(lr_paramarr_idx("dominantSegmentBrandId2", i)), lr_eval_string("{FIRST}"))!=NULL)) {
							lr_save_string(lr_paramarr_idx("solutionId2", i),"solutionIdSecond");
							seatsSecondSuccess = 1;
							i=10000000;			
					}		
				}
				
				if(seatsSecondSuccess<=0){
					lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);
				}
				lr_save_string("OFFERAPI", "SearchAPI_Route");
			
				lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_03b_SelectSecondFlight_{SearchAPI_Route}"));
				
				
				
//				web_reg_find("Text=\"flagenabledisable\":{\"enable\":true", "Savecount=offerAPI_ON_NEW", LAST);
//				
//				lr_start_transaction("%getpersonalizedContent%");
//					lr_start_transaction("%getpersonalizedContent_Offer%");
//				web_custom_request("getpersonalizedContent_3", 
//					"URL=https://{URL}/personalization-api/getpersonalizedContent", 
//					"Method=POST", 
//					"Resource=0", 
//					"RecContentType=application/json", 
//					"Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", 
//					"Snapshot=t12.inf", 
//					"Mode=HTML", 
//					"EncType=application/json; charset=UTF-8", 
//					"Body={\"userdata\":{\"isEdocAdded\":false},\"requestparam\":{\"campaignId\":\"shopping-lite:shop-offer-api\"}}", 
//					LAST);
//				lr_end_transaction("%getpersonalizedContent_Offer%", LR_AUTO);
//
//				lr_end_transaction("%getpersonalizedContent%", LR_AUTO);
//
//				if(strcmp(lr_eval_string("{offerAPI_ON_NEW}"), lr_eval_string("{offerAPI_ON}"))!=0){
//					lr_error_message("OFFERAPI FLAG MISMATCH - %s.", lr_eval_string("{cacheKey}"));
//				}

					web_reg_save_param_json(
				        "ParamName=dominantSegmentBrandIdR",
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
					
					lr_save_string("COMFORT-PLUS", "COMFORTPLUS");
					lr_save_string("BASIC-ECONOMY", "BASICECONOMY");
					lr_save_string("/ECONOMY", "ECONOMY");
					lr_save_string("BUSINESS-FIRST", "BUSINESSFIRST");
					lr_save_string("/FIRST", "FIRST");
			
			for(i=1;i<=atoi(lr_eval_string("{solutionId2_count}"));i++){
				
				if((strstr(lr_eval_string(lr_paramarr_idx("solutionId2", i)), lr_eval_string("{COMFORTPLUS}"))!=NULL)||(strstr(lr_eval_string(lr_paramarr_idx("solutionId2", i)), lr_eval_string("{ECONOMY}"))!=NULL)||(strstr(lr_eval_string(lr_paramarr_idx("solutionId2", i)), lr_eval_string("{FIRST}"))!=NULL)) {
						lr_save_string(lr_paramarr_idx("solutionId2", i),"solutionIdSecond");
						seatsSecondSuccess = 1;
						i=10000000;			
				}
							
		//		if(strstr(lr_eval_string(lr_paramarr_idx("solutionIdO", i)), lr_eval_string("{COS_Needle}"))==NULL){
		//			if(strstr(lr_eval_string(lr_paramarr_idx("solutionIdO", i)), lr_eval_string("{COS_Needle2}"))==NULL){
		//				lr_save_string(lr_paramarr_idx("solutionIdO", i),"solutionIdOutbound");
		//				seatsOutboundSuccess = 1;
		//				i=10000000;
		//			}
		//		}
			}
			
			if(seatsSecondSuccess<=0){
				lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);
			}
					
			lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_03b_SelectSecondFlight_{SearchAPI_Route}"));
		}
	
	web_add_header("X-APP-ROUTE", "SL-RSB");

	web_add_header("X-APP-CHANNEL", "sl-sho");
	
	web_add_header("CacheKey", "{cacheKey}");
	
	//web_reg_save_param_custom(lr_eval_string("{solutionIdSecond}"), "solutionIdSecond", "solutionId\":\"", "\"");
		
	//UNCOMMENT FOR QAT2.DELTA.COM
	//web_reg_save_param("solutionIdR", "LB=longestHaulCos\":null,\"solutionId\":\"", "RB=\"","Ord=All", "Notfound=warning", LAST);
	
	//UNCOMMENT FOR STGA.DELTA.COM
	//web_reg_save_param("solutionIdR", "LB=\"dominantSegmentBrand", "RB=\"brandByFlightLeg","Ord=All", "Notfound=warning", LAST);

	web_reg_save_param_json(
        "ParamName=solutionIdR",
        //"QueryString=$['itinerary','itineraries'][*]['fare','fares'][*]['solutionId']",
        "QueryString=$['itinerary','itineraries'][*]['fare','fares'][?(@.soldOut==false)]['solutionId']",
        //"QueryString=$.itinerary[*].fare[*].solutionId",
        "SelectAll=Yes",
        "Notfound=warning",
        "SEARCH_FILTERS",
        "Scope=Body",
        "LAST");
	
	web_reg_save_param("errorNumber", "LB=\"code\":\"", "RB=\"", "Notfound=warning", LAST);
	//web_reg_save_param("errorMessage", "LB=\"message\":\"", "RB=\"", "Notfound=warning", LAST);

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
	
	lr_start_transaction(lr_eval_string("%FlightShop_{SearchAPI_Route}%"));
	
	web_custom_request("search", 
		"URL=https://{URL}/shop/mc/search", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/flight-search/search-results/multicity/2?cacheKeySuffix={cacheKey}", 
		"Snapshot=t527.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		"Body={\"bestFare\":\"BE\",\"action\":\"findFlights\",\"destinationAirportRadius\":{\"unit\":\"MI\",\"measure\":100},\"deltaOnlySearch\":{deltaOnlySearch},\"meetingEventCode\":\"\",\"originAirportRadius\":{\"unit\":\"MI\",\"measure\":100},\"passengers\":[{\"type\":\"ADT\",\"count\":{numPax}}],\"searchType\":\"selectFlightSearch\",\"segments\":[{\"departureDate\":\"{P_DepartureDate}\",\"destination\":\"{Destination}\",\"origin\":\"{Origin}\"},{\"departureDate\":\"{P_ReturnDate}\",\"destination\":\"{FinalDestination}\",\"origin\":\"{Destination}\"},{\"departureDate\":"
		"\"{P_ReturnDate1}\",\"destination\":\"{Destination}\",\"origin\":\"{Origin}\"}],\"shopType\":\"MONEY\",\"tripType\":\"MULTICITY\",\"priceType\":\"Revenue\",\"priceSchedule\":\"PRICE\",\"awardTravel\":false,\"refundableFlightsOnly\":false,\"nonstopFlightsOnly\":false,\"datesFlexible\":false,\"flexCalendar\":false,\"flexAirport\":false,\"upgradeRequest\":false,\"pageName\":\"FLIGHT_SEARCH\",\"cacheKey\":\"{cacheKey}\",\"requestPageNum\":\"1\",\"currentSolution\":{\"solutionId\""
		":\"{solutionIdSecond}\",\"solutionIndex\":0,\"sliceIndex\":\"2\"},\"selectedSolutions\":[{\"solutionId\":\"{solutionIdOutbound}\",\"solutionIndex\":0,\"sliceIndex\":1},{\"sliceIndex\":2}],\"actionType\":\"search\",\"initialSearchBy\":{\"fareFamily\":\"BE\",\"meetingEventCode\":\"\",\"refundable\":false,\""
		"flexAirport\":false,\"flexDate\":false},\"vendorDetails\":{}}", 
		LAST);	

	lr_end_transaction(lr_eval_string("%FlightShop_{SearchAPI_Route}%"), LR_AUTO);	

	if(atoi(lr_eval_string("{callDurationFlag}"))==1){
		lr_output_message("[REVENUE FLIGHTSHOP\t%s]TripType:\t%s\tCallDuration:\t%s",lr_eval_string("{SearchAPI_Route}"),lr_eval_string("{RandTripType}"),lr_eval_string("{callDuration}"));
	}
	
	if(atoi(lr_eval_string("{covidBannerFlag}"))==0){
		lr_start_transaction("%getpersonalizedContent%");
		
		web_custom_request("getpersonalizedContent", 
			"URL=https://{URL}/personalization-api/getpersonalizedContent", 
			"Method=POST", 
			"Resource=0", 
			"RecContentType=application/json", 
			"Referer=https://{URL}/flight-search/search-results/multicity/2?cacheKeySuffix={cacheKey}", 
			"Snapshot=t7.inf", 
			"Mode=HTML", 
			"EncType=application/json; charset=UTF-8", 
			"Body={\"userdata\":{\"loggedinrestriction\":\"yes\",\"triptype\":\"MULTICITY\",\"includesaturdaynightstay\":false,\"origin\":\"{FinalDestination}\",\"shoppingDate\":\"{date_today}\",\"destination\":\"{Origin}\",\"departuredate\":\"{P_ReturnDate1}\",\"noofpassengers\":{numPax},\"skymilesTier\":\"\",\"markettype\":\"Domestic48\",\"originDestinationPair\":\"{FinalDestination}{Origin}\",\"corporate\":false,\"departureadvancepurchase\":145,\"shopType\":\"CashPlusMiles\",\"availableFareBrands\":[\"DCP\",\"MAIN\",\"FIRST\"]},\"requestparam\":{\"campaignId\""
			":\"shopping-lite:dynamic-banner\"}}", 
			LAST);
		
		lr_end_transaction("%getpersonalizedContent%", LR_AUTO);
	}

	if(atoi(lr_eval_string("{covidBannerFlag}"))>0){
				PE_SHO_Banner();
	}
	
	if(atoi(lr_eval_string("{solutionIdR_count}"))>0)
	{
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_03b_SelectSecondFlight_{SearchAPI_Route}"), LR_AUTO);	
		
		
	}
	else
	{
		
		//lr_output_message("No Flights Found for \tORIGIN\t%s\tDESTINATION\t%s\tFINALDESTINATION\t%s",lr_eval_string("{Origin}"),lr_eval_string("{Destination}"),lr_eval_string("{FinalDestination}"));
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_03b_SelectSecondFlight_{SearchAPI_Route}"), LR_AUTO);
			getErrorMessage();
			lr_output_message("RSB_Revenue_%s_03b_SelectSecondFlight_%s: No Flights Found for \tORIGIN\t%s\tDESTINATION\t%s\tFINALDESTINATION\t%s\tFLIGHT DATES\t%s-%s-%s\tError Number:\t%s\tError Message:\t%s\tCacheKey:%s",lr_eval_string("{RandTripType}"),lr_eval_string("{SearchAPI_Route}"),lr_eval_string("{Origin}"),lr_eval_string("{Destination}"),lr_eval_string("{FinalDestination}"),lr_eval_string("{P_DepartureDate}"),lr_eval_string("{P_ReturnDate}"),lr_eval_string("{P_ReturnDate1}"),lr_eval_string("{errorNumber}"),lr_eval_string("{errorMessage}"),lr_eval_string("{cacheKey}"));
		lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);
	}
	
	
	return 0;
}
