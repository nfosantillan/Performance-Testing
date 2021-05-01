SelectSeats()
{
	int flightIndex;

	if(strcmp(lr_eval_string("{upgradeFlag}"),"true") == 0){
		
		web_reg_save_param_json(
	        "ParamName=selectedFareOfferPlusPrice",
	        "QueryString=$.passengerList[*].selectedFareOfferPlusPrice",
	        "Notfound=warning",
	        "SEARCH_FILTERS",
	        "Scope=Body",
        	"LAST");
		
		lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_08b_UpgradeSeat"));
			
		web_custom_request("calculatePassengerPlusPrice", 
			"URL=https://{URL}/seatmap/ism/calculatePassengerPlusPrice", 
			"Method=POST", 
			"Resource=0", 
			"RecContentType=application/json", 
			"Referer=https://{URL}/seat-map/ISM/{ismSeatLoc}?seatmapReferenceKey={seatmapReferenceKey}", 
			"Snapshot=t4.inf", 
			"Mode=HTML", 
			"EncType=application/json", 
			"Body={\"pendingFareIndex\":\"{pendingFareIndex}\",\"baseFareIndex\":0,\"selectedOfferIndex\":0,\"itineraryOfferList\":{itineraryOfferList},\"passengers\":{passengerList},\"priceType\":\"REV\"}", 
		LAST);
		
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_08b_UpgradeSeat"), LR_AUTO);
		
	}
	
	for(flightIndex=2;flightIndex<=atoi(lr_eval_string("{flightList_count}"));flightIndex++){
	
	lr_think_time(5);
		
	lr_save_int(flightIndex, "flightIndex");
	
	lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_08_SelectSeat"));
	lr_start_transaction("%RSB_SeatmapISM%");
	
	web_reg_save_param_json(
        "ParamName=seatCabin",
        "QueryString=$.seatMapDetails.mainDeck.seatCabins[*]",
        "SelectAll=Yes",
         "Notfound=warning",
        "SEARCH_FILTERS",
        "Scope=Body",
        "LAST");

	/**** ADDED FOR UPSELL PROJECT (START) ****/
	
//	web_reg_save_param_json(
//        "ParamName=itineraryOfferList",
//        "QueryString=$.fareOffer.itineraryOfferList[]",
//        "Notfound=warning",
//        "SEARCH_FILTERS",
//        "Scope=Body",
//        "LAST");
//	
//	web_reg_save_param_json(
//        "ParamName=passengerList",
//        "QueryString=$.passengerList[]",
//        "Notfound=warning",
//        "SEARCH_FILTERS",
//        "Scope=Body",
//        "LAST");

	web_reg_save_param_json(
        "ParamName=seatmapReferenceKey",
        "QueryString=$.bookingInformation.seatmapReferenceKey",
        "Notfound=warning",
        "SEARCH_FILTERS",
        "Scope=Body",
        "LAST");
	
	/**** ADDED FOR UPSELL PROJECT (END) ****/
	
	web_reg_find("Text=302 Found", "SaveCount=redirect_count",
		LAST);
	
	web_custom_request("tripSum_2", 
		"URL=https://{URL}/seatmap/ism/{ismSeatLoc}", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/seat-map/ISM/{ismSeatLoc}", 
		"Snapshot=t64.inf", 
		"Mode=HTML", 
		"EncType=application/json;charset=UTF-8", 
		"Body={\"appId\":\"SEATS\",\"cartId\":\"{cartId}\",\"channelId\":\"ecomm\",\"pageId\":\"ISM-BOK\",\"currencyCode\":\"{C_currencyCode}\",\"flightIndex\":{flightIndex},\"numberOfPassengers\":\"{numPax}\",\"redirectURL\":\"/complete-purchase/{CompletePurchaseLoc}?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho\"}", 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);		

	lr_start_transaction("%getpersonalizedContent%");
	
	web_custom_request("getpersonalizedContent", 
		"URL=https://{URL}/personalization-api/getpersonalizedContent", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/seat-map/ISM/{ismSeatLoc}", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"userdata\":{},\"requestparam\":{\"campaignId\":\"seats:seats-interstitial\"}}", 
		LAST);
	
	lr_end_transaction("%getpersonalizedContent%", LR_AUTO);
	
	if(atoi(lr_eval_string("{redirect_count}"))>0){
		lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_302_REDIRECT"));
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_302_REDIRECT"), LR_AUTO);

		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_08_SelectSeat"), LR_FAIL);
		lr_end_transaction("%RSB_SeatmapISM%", LR_FAIL);	
		lr_error_message("Seatmap 302 REDIRECT %s-%s", lr_eval_string("{Origin}"),lr_eval_string("{Destination}"));
		//lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_FAIL);
	} else if(atoi(lr_eval_string("{seatCabin_count}"))<=0)
		{
			lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_08_SelectSeat"), LR_AUTO);	
			lr_end_transaction("%RSB_SeatmapISM%", LR_AUTO);		
			lr_output_message("Seatmap unavailable %s-%s", lr_eval_string("{Origin}"),lr_eval_string("{Destination}"));
			lr_save_int(0, "seatsSelection");
			return 0;
			//lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);
			
	}
		else {
	
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_08_SelectSeat"), LR_AUTO);	
		lr_end_transaction("%RSB_SeatmapISM%", LR_AUTO);
	}

		lr_save_string("","previousSelectedSeatIdList");

		lr_save_string(lr_eval_string(lr_paramarr_idx("flightList", flightIndex)), "flightListSelectionTEMP");
					
		lr_eval_json("Buffer={flightListSelectionTEMP}", "JsonObject=flightListSelectionTEMP_obj", LAST);
		lr_json_get_values("JsonObject=flightListSelectionTEMP_obj", "ValueParam=fareBrandIDTEMP", "QueryString=$.fareBrandID", LAST);
		
		createStringPerPax();
		//createJSONSeatRequestString();
		
		if(atoi(lr_eval_string("{seatsSelection}"))<=0){
			return 0;
		}
	
	}

	return 0;
}
