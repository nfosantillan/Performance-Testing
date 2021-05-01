getSeatColumn()
{

	int seatCabinIndex, seatCabinIndexFinal, seatRowIndex=0, seatRowIndexFinal=0, seatColumnIndex=0, seatColumnIndexFinal=0;
	
	//select the correct CABIN
	lr_save_string("\"available\":true", "needle");
	//lr_save_string("10","randomSeatSelection");
			/**** ADDED FOR UPSELL PROJECT (END) ****/
			
			if((atoi(lr_eval_string("{upgradeAvailableFIRST}"))>=1) && (atoi(lr_eval_string("{randomSeatSelection}"))==10)) {
				lr_save_string("10","randomSeatSelection");
			} else if((atoi(lr_eval_string("{upgradeAvailableDCP}"))>=1) && ((atoi(lr_eval_string("{randomSeatSelection}"))>=6)) ) {
				lr_save_string("9","randomSeatSelection");
			} else {
				lr_save_string("4","randomSeatSelection");
			}
			
			if(atoi(lr_eval_string("{randomSeatSelection}")) <= 5)  {
				lr_save_string(lr_eval_string("\"brandId\":\"MAIN\""), "fareNeedle");
				lr_save_string("MAIN", "pendingSeatBrandId");
				lr_save_string("false","upgradeFlag");
				lr_save_string(lr_eval_string("https://{URL}/seat-map/ISM/{ismSeatLoc}"),"saveSeatReferrer");
			} else if (atoi(lr_eval_string("{randomSeatSelection}")) == 10) {
				lr_save_string(lr_eval_string("\"brandId\":\"FIRST\""), "fareNeedle");
				lr_save_string("FIRST", "pendingSeatBrandId");
				lr_save_string("2","pendingFareIndex");
				lr_save_string("2","selectedFareIndex");
				lr_save_string("true","upgradeFlag");
				lr_save_string(lr_eval_string("https://{URL}/seat-map/ISM/{ismSeatLoc}?seatmapReferenceKey={seatmapReferenceKey}"),"saveSeatReferrer");
			} else {
				lr_save_string(lr_eval_string("\"brandId\":\"DCP\""), "fareNeedle");
				lr_save_string("DCP", "pendingSeatBrandId");
				lr_save_string("1","pendingFareIndex");
				lr_save_string("1","selectedFareIndex");
				lr_save_string("true","upgradeFlag");
				lr_save_string(lr_eval_string("https://{URL}/seat-map/ISM/{ismSeatLoc}?seatmapReferenceKey={seatmapReferenceKey}"),"saveSeatReferrer");
			}	
			
			/**** ADDED FOR UPSELL PROJECT (END) ****/
	
	//lr_save_string(lr_eval_string("\"brandId\":\"{fareBrandIDTEMP}\""), "fareNeedle");
	lr_save_string("", "selectedSeatCabin");
	for(seatCabinIndex=1;seatCabinIndex<=atoi(lr_eval_string("{seatCabin_count}"));seatCabinIndex++){
		
		if(strstr(lr_eval_string(lr_paramarr_idx("seatCabin", seatCabinIndex)), lr_eval_string("{needle}"))!=NULL){
			if(strstr(lr_eval_string(lr_paramarr_idx("seatCabin", seatCabinIndex)), lr_eval_string("{fareNeedle}"))!=NULL){
				seatCabinIndexFinal = seatCabinIndex;
				lr_save_int(seatCabinIndexFinal, "seatCabinIndexFinal");
				lr_save_string(lr_eval_string(lr_paramarr_idx("seatCabin", seatCabinIndexFinal)), "selectedSeatCabin");
				seatCabinIndexFinal = 1000000000;
				seatCabinIndex = 1000000000;
			}
		 }	
	}
	
	if(strlen(lr_eval_string("{selectedSeatCabin}"))<=0){
		lr_save_int(0, "seatsSelection");
		return 0;
		//lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);
	}
	
//	lr_save_int(seatCabinIndexFinal, "seatCabinIndexFinal");
//	lr_save_string(lr_eval_string(lr_paramarr_idx("seatCabin", seatCabinIndexFinal)), "selectedSeatCabin");
	
	
	lr_eval_json("Buffer={selectedSeatCabin}", "JsonObject=seatCabin_obj", LAST);
	lr_json_get_values("JsonObject=seatCabin_obj", "ValueParam=seatRows", "QueryString=$.seatRows[*]", "SelectAll=Yes", LAST);

	
	/********************************   Select Row Index ****************************************************************************************/
	lr_save_string("\"available\":true", "SeatRowNeedle");
	lr_save_string("\"exit\":false", "SeatRowNeedleEXIT");
	for(seatRowIndex=1;seatRowIndex<=atoi(lr_eval_string("{seatRows_count}"));seatRowIndex++){
		
		if(strstr(lr_eval_string(lr_paramarr_idx("seatRows", seatRowIndex)), lr_eval_string("{SeatRowNeedle}"))!=NULL){
			if(strstr(lr_eval_string(lr_paramarr_idx("seatRows", seatRowIndex)), lr_eval_string("{SeatRowNeedleEXIT}"))!=NULL){
				
					seatRowIndexFinal = seatRowIndex;
				
				
					lr_save_int(seatRowIndexFinal, "seatRowIndexFinal");
					lr_save_string(lr_eval_string(lr_paramarr_idx("seatRows", seatRowIndexFinal)), "selectedSeatRow");
					
					lr_eval_json("Buffer={selectedSeatRow}", "JsonObject=seatRow_obj", LAST);
					lr_json_get_values("JsonObject=seatRow_obj", "ValueParam=seatColumns", "QueryString=$.seatColumns[*]", "SelectAll=Yes", LAST);
	
							/********************************   Select Column Index ************************************************************************************/
							lr_save_string("\"available\":true", "SeatColumnNeedle");
							lr_save_string("\"exit\":false", "SeatColumnNeedleEXIT");
							for(seatColumnIndex=1;seatColumnIndex<=atoi(lr_eval_string("{seatColumns_count}"));seatColumnIndex++){
								
								if(strstr(lr_eval_string(lr_paramarr_idx("seatColumns", seatColumnIndex)), lr_eval_string("{SeatColumnNeedle}"))!=NULL){
									if(strstr(lr_eval_string(lr_paramarr_idx("seatColumns", seatColumnIndex)), lr_eval_string("{SeatColumnNeedleEXIT}"))!=NULL){
										lr_save_string(lr_eval_string(lr_paramarr_idx("seatColumns", seatColumnIndex)), "selectedSeatColumnTEMP");
										lr_eval_json("Buffer={selectedSeatColumnTEMP}", "JsonObject=selectedSeatColumnTEMP_obj", LAST);
										lr_json_get_values("JsonObject=selectedSeatColumnTEMP_obj", "ValueParam=seatIdTemp", "QueryString=$.id", LAST);							
										if(strstr(lr_eval_string("{previousSelectedSeatIdList}"), lr_eval_string("{seatIdTemp}"))==NULL){
											seatColumnIndexFinal = seatColumnIndex;
											seatColumnIndex = 1000000000;
											seatRowIndex = 1000000000;
											seatRowIndexFinal = 1000000000;
											
											//lr_error_message("ERROR HERE TOO LATE");
											
											lr_save_int(seatColumnIndexFinal, "seatColumnIndexFinal");
											lr_save_string(lr_eval_string(lr_paramarr_idx("seatColumns", seatColumnIndexFinal)), "selectedSeatColumn");
							
											lr_save_string(lr_eval_string("{previousSelectedSeatIdList}{seatIdTemp}"), "previousSelectedSeatIdList");
											seatColumnIndexFinal = 1000000000;
											lr_save_int(1, "seatsSelection");
											return 0;
										}
									}
								 }	
							}
					
							/********************************   Select Column Index ************************************************************************************/
				
			}
		 }	
	}

	if(seatRowIndexFinal == atoi(lr_eval_string("{seatRows_count}"))){
		lr_save_int(0, "seatsSelection");
		return 0;
		//lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);
	}

	if(seatColumnIndexFinal != 1000000000){
		lr_save_int(0, "seatsSelection");
		return 0;
		//lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);
	}
	
	return 0;
}
