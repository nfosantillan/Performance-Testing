createTripExtraProductsString()
{

	int i=0, TripExtraIndex,tripExtraSuccessFlag=0;
	
	lr_save_string("\"statusCode\":\"AVL\"", "needle");
	lr_save_string("\"productId\":\"PBZPB\"", "productNeedle");
	for(TripExtraIndex=1;TripExtraIndex<=atoi(lr_eval_string("{tripExtraProducts_count}"));TripExtraIndex++){
		if(strstr(lr_eval_string(lr_paramarr_idx("tripExtraProducts", TripExtraIndex)), lr_eval_string("{needle}"))!=NULL){
			if(strstr(lr_eval_string(lr_paramarr_idx("tripExtraProducts", TripExtraIndex)), lr_eval_string("{productNeedle}"))!=NULL){
				lr_save_string(lr_eval_string(lr_paramarr_idx("tripExtraProducts", TripExtraIndex)), "selectedTripExtra");
				TripExtraIndex=10000;
				tripExtraSuccessFlag=1;
			}
		}				
	}

	if(tripExtraSuccessFlag==0){
		lr_save_int(0, "tripExtrasSuccessFlag");
		return 0;
		//lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);
	}
	
	lr_save_int(1, "tripExtrasSuccessFlag");
	
	web_reg_save_param_custom(lr_eval_string("{selectedTripExtra}"),"productId","productId\":\"","\"");
	web_reg_save_param_custom(lr_eval_string("{selectedTripExtra}"),"productAccountingCode","productAccountingCode\":\"","\"");
	lr_save_string(lr_eval_string("{\"passengers\":[{\"passengerId\":\"1\",\"flightInfoDisplay\":[{\"deptArptCode\":\"{deptArptCode}\",\"arrArptCode\":\"{arrArptCode}\",\"tripDepartureDate\":\"{tripDepartureDate}\",\"flightNum\":\"{flightNum}\",\"segmentNumber\":\"{segmentNumber}\",\"airlineCode\":\"{airlineCode}\",\"status\":\"AVL\"}]}],\"productAccountingCode\":\"{productAccountingCode}\",\"productId\":\"{productId}\"}"), "tripExtraProductString");
	lr_save_string(lr_eval_string("{\"emailAdr\":\"\",\"loyaltyMemberId\":\"\",\"passengerId\":\"1\",\"personName\":{\"firstName\":\"Test\",\"lastName\":\"Tester\"}}"), "passengersString");
	
	for(i=2;i<=atoi(lr_eval_string("{numPax}"));i++){
		
		lr_save_int(i, "passengerId");
		
		lr_save_string(lr_eval_string("{tripExtraProductString},{\"passengers\":[{\"passengerId\":\"{passengerId}\",\"flightInfoDisplay\":[{\"deptArptCode\":\"{deptArptCode}\",\"arrArptCode\":\"{arrArptCode}\",\"tripDepartureDate\":\"{tripDepartureDate}\",\"flightNum\":\"{flightNum}\",\"segmentNumber\":\"{segmentNumber}\",\"airlineCode\":\"{airlineCode}\",\"status\":\"AVL\"}]}],\"productAccountingCode\":\"{productAccountingCode}\",\"productId\":\"{productId}\"}"), "tripExtraProductString");
		lr_save_string(lr_eval_string("{passengersString},{\"emailAdr\":\"\",\"loyaltyMemberId\":\"\",\"passengerId\":\"{passengerId}\",\"personName\":{\"firstName\":\"Test{passengerId}\",\"lastName\":\"Tester{passengerId}\"}}"), "passengersString");
		
		
	}
	return 0;
}
