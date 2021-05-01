getSeatColumnBackup()
{

	int seatCabinIndex, seatCabinIndexFinal, seatRowIndex=0, seatRowIndexFinal=0, seatColumnIndex=0, seatColumnIndexFinal=0;
	
	//select the correct CABIN
	lr_save_string("\"brandId\":\"MAIN\"", "needle");
	for(seatCabinIndex=1;seatCabinIndex<=atoi(lr_eval_string("{seatCabin_count}"));seatCabinIndex++){
		
		if(strstr(lr_eval_string(lr_paramarr_idx("seatCabin", seatCabinIndex)), lr_eval_string("{needle}"))!=NULL){
			seatCabinIndexFinal = seatCabinIndex;
			//lr_save_int(seatCabinIndex, "selectedSeatCabinIndex");
		 }	
	}
	
	lr_save_int(seatCabinIndexFinal, "seatCabinIndexFinal");
	lr_save_string(lr_eval_string(lr_paramarr_idx("seatCabin", seatCabinIndexFinal)), "selectedSeatCabin");
	
	if(atoi(lr_eval_string("{passengerIndex}"))>1){
		lr_replace("selectedSeatCabin", lr_eval_string("{selectedSeatColumn}"), lr_eval_string("{previousSelectedSeatColumn}"));
	}
	
	lr_eval_json("Buffer={selectedSeatCabin}", "JsonObject=seatCabin_obj", LAST);
	lr_json_get_values("JsonObject=seatCabin_obj", "ValueParam=seatRows", "QueryString=$.seatRows[*]", "SelectAll=Yes", LAST);

	
	/********************************   Select Row Index ****************************************************************************************/
	lr_save_string("\"available\":true", "SeatRowNeedle");
	lr_save_string("\"exit\":false", "SeatRowNeedleEXIT");
	for(seatRowIndex=1;seatRowIndex<=atoi(lr_eval_string("{seatRows_Count}"));seatRowIndex++){
		
		if(strstr(lr_eval_string(lr_paramarr_idx("seatRows", seatRowIndex)), lr_eval_string("{SeatRowNeedle}"))!=NULL){
			if(strstr(lr_eval_string(lr_paramarr_idx("seatRows", seatRowIndex)), lr_eval_string("{SeatRowNeedleEXIT}"))!=NULL){
				seatRowIndexFinal = seatRowIndex;
				seatRowIndex = 1000000000;
			}
		 }	
	}

	if(seatRowIndexFinal<=0){
		lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);
	}
	
	lr_save_int(seatRowIndexFinal, "seatRowIndexFinal");
	lr_save_string(lr_eval_string(lr_paramarr_idx("seatRows", seatRowIndexFinal)), "selectedSeatRow");
	
	lr_eval_json("Buffer={selectedSeatRow}", "JsonObject=seatRow_obj", LAST);
	lr_json_get_values("JsonObject=seatRow_obj", "ValueParam=seatColumns", "QueryString=$.seatColumns[*]", "SelectAll=Yes", LAST);
	
	/********************************   Select Column Index ************************************************************************************/
	
	lr_save_string("\"available\":true", "SeatColumnNeedle");
	lr_save_string("\"exit\":false", "SeatColumnNeedleEXIT");
	for(seatColumnIndex=1;seatColumnIndex<=atoi(lr_eval_string("{seatColumns_Count}"));seatColumnIndex++){
		
		if(strstr(lr_eval_string(lr_paramarr_idx("seatColumns", seatColumnIndex)), lr_eval_string("{SeatColumnNeedle}"))!=NULL){
			if(strstr(lr_eval_string(lr_paramarr_idx("seatColumns", seatColumnIndex)), lr_eval_string("{SeatColumnNeedleEXIT}"))!=NULL){
				seatColumnIndexFinal = seatColumnIndex;
				seatColumnIndex = 1000000000;
			}
		 }	
	}
	if(seatColumnIndexFinal<=0){
		lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);
	}
	
	lr_save_int(seatColumnIndexFinal, "seatColumnIndexFinal");
	lr_save_string(lr_eval_string(lr_paramarr_idx("seatColumns", seatColumnIndexFinal)), "selectedSeatColumn");
	
	lr_save_string(lr_eval_string("{selectedSeatColumn}"), "previousSelectedSeatColumn");
	
	lr_replace("previousSelectedSeatColumn", "\"available\":true", "\"available\":false");

	
	/********************************   Select Column Index ************************************************************************************/

	return 0;
}
