SaveSeatsReviewPay()
{

	lr_think_time(5);
	
	createWholeRequest();
	lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_09_SaveSeats"));

	lr_start_transaction("%RSB_bookSeats%");
 
	web_reg_find("Text=SUCCESS", "SaveCount=success_count",
		LAST);

	web_reg_find("Text=302 Found", "SaveCount=redirect_count",
		LAST);

	web_reg_save_param("wholeRequest", "LB=", "RB=", "Notfound=warning",
        "Search=Body",LAST);	
	
	if(atoi(lr_eval_string("{randomSeatSelection}")) <= 5){
	web_custom_request("book", 
		"URL=https://{URL}/seatmap/seats/book", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/seat-map/ISM/book", 
		"Snapshot=t74.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"passengerSeatRqList\":[{finalSeatRequest}],\"appId\":\"SEATS\",\"cartId\":\"{cartId}\",\""
		"channelId\":\"ecomm\"}", 
		LAST);
	} else {
		web_custom_request("book", 
		"URL=https://{URL}/seatmap/seats/book", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
//		"Referer=https://{URL}/seat-map/ISM/tripSum?seatmapReferenceKey={seatmapReferenceKey}",
		"Referer={saveSeatReferrer}", 
		"Snapshot=t74.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"passengerSeatRqList\":[{finalSeatRequest}],\"appId\":\"SEATS\",\"cartId\":\"{cartId}\",\""
		"channelId\":\"ecomm\",\"seatmapReferenceKey\":\"{seatmapReferenceKey}\",\"selectedFareIndex\":\"{selectedFareIndex}\"}", 
		LAST);
	}

	if(atoi(lr_eval_string("{redirect_count}"))>0){
		lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_302_REDIRECT"));
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_302_REDIRECT"), LR_AUTO);

		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_09_SaveSeats"), LR_FAIL);
		lr_end_transaction("%RSB_bookSeats%", LR_FAIL);	
		lr_error_message("Seatmap 302 REDIRECT %s-%s", lr_eval_string("{Origin}"),lr_eval_string("{Destination}"));
		//lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_FAIL);
	} else if(atoi(lr_eval_string("{success_count}"))<=0)
		{
			lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_09_SaveSeats"), LR_AUTO);
			lr_end_transaction("%RSB_bookSeats%", LR_AUTO);	
			lr_output_message("RSB Seat Selection in Review and Pay Page Failed: \tCartID:%s\tCacheKey:%s\tResponse:%s",lr_eval_string("{cartId}"), lr_eval_string("{cacheKey}"), lr_eval_string("{wholeRequest}"));
			lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);
			
	} else {
	
		lr_end_transaction("%RSB_bookSeats%", LR_AUTO);		
	}
	
	lr_save_string("true", "loyaltyMileageInfoIndicator");
	
	ContinueAndReview();
		
	if(atoi(lr_eval_string("{insurancePurchase}"))==1) {
		if(strcmp(lr_eval_string("{ccType}"), "TP")!=0){
				InsuranceSearch();
				if(strlen(lr_eval_string("{quotePackId}"))<=0){
					lr_output_message("Insurance unavailable for %s-%s", lr_eval_string("{Origin}"),lr_eval_string("{Destination}"));
					lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_09_SaveSeats"), LR_AUTO);
					lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);
				}
		}
	}
	
	lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_09_SaveSeats"), LR_AUTO);
	
	return 0;
}
