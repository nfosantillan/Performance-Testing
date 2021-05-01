RSBFlow()
{
	
	if(strcmp(lr_eval_string("{flexAirportFlag}"), "true")==0){
		SelectFromGrid();
	}
	
	if(atoi(lr_eval_string("{seatsPurchase}"))==1) {
		if(atoi(lr_eval_string("{RandSeatSelectLoc}"))<=10) {
			ViewLogicalSeatmap();
		}
	}
	
	SelectOutbound();
	if(strcmp(lr_eval_string("{RandTripType}"), "RT")==0){
		SelectReturn();
	}

	if(strcmp(lr_eval_string("{RandTripType}"), "MC")==0){
		SelectSecondFlight();
		SelectReturn();
	}
	
	TripSummaryPage();
	
	if(atoi(lr_eval_string("{tripSummaryWithPurchase}"))==1) {
		if(atoi(lr_eval_string("{tripExtrasPurchase}"))==1) {
			if(strcmp(lr_eval_string("{ccType}"), "TP")!=0){
				TripExtrasSearch();
				if(atoi(lr_eval_string("{tripExtrasSuccessFlag}"))==1) {
					
						AddTripExtra();			
				}
			}
		}
		
		if(atoi(lr_eval_string("{seatsPurchase}"))==1) {
			if(atoi(lr_eval_string("{RandSeatSelectLoc}"))>=5) { //if RandSeatSelectLoc>=5, select seats in TripSummary page else select seats in ReviewPage
				lr_save_string("tripSum", "ismSeatLoc");
				lr_save_string("trip-summary", "CompletePurchaseLoc");
				ViewSeatmap();
				SelectSeats();
				if(atoi(lr_eval_string("{seatsSelection}"))<=0){
					CancelSeatTripSummary();
				} else {
					SaveSeatsTripSummary();
				}
			}
		}
		
		lr_think_time(5);
		lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_10_ContinueAndReview"));
		ContinueAndReview();
		
			if(atoi(lr_eval_string("{insurancePurchase}"))==1) {
				if(strcmp(lr_eval_string("{ccType}"), "TP")!=0){
					InsuranceSearch();
						if(strlen(lr_eval_string("{quotePackId}"))<=0){
							lr_output_message("Insurance unavailable for %s-%s", lr_eval_string("{Origin}"),lr_eval_string("{Destination}"));
							//lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_10_ContinueAndReview"), LR_AUTO);
//							lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);
						}
				}
			}
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_10_ContinueAndReview"), LR_AUTO);

		if(atoi(lr_eval_string("{seatsPurchase}"))==1) {
			if(atoi(lr_eval_string("{RandSeatSelectLoc}"))<=4) { //if RandSeatSelectLoc<=4, select seats in TripSummary page else select seats in ReviewPage
				lr_save_string("book", "ismSeatLoc");
				lr_save_string("review-pay", "CompletePurchaseLoc");
				ViewSeatmap();
				SelectSeats();
				if(atoi(lr_eval_string("{seatsSelection}"))<=0){
					CancelSeatReviewPay();
				} else {
					SaveSeatsReviewPay();
				}				
				
			}
		}		

		if(atoi(lr_eval_string("{reviewPageOnly}"))==0) {
			if(atoi(lr_eval_string("{insurancePurchase}"))==1) {
				if(strcmp(lr_eval_string("{ccType}"), "TP")!=0){
					if(atoi(lr_eval_string("{tripInsuranceSuccessFlag}"))==1) {
						AddInsurance();
					}
				}
			}
			
			if(atoi(lr_eval_string("{analyticsFlow}"))>0){
				if(strcmp(lr_eval_string("{formOfPayment}"), "CC")==0){
					CompletePurchase();
				
				} else if(strcmp(lr_eval_string("{formOfPayment}"), "Paypal")==0){
					Paypal_CompletePurchase();
				}			
			} else{
				//if(atoi(lr_eval_string("{randomSeatSelection}"))>=7) { //REMOVE AFTER FAB VIRTUALIZED TEST
					CompletePurchase();
					//CarPurchase();
				
					if(atoi(lr_eval_string("{inlineEnrollmentFlag}"))==1) {
						inlineSM_clickJoinSkyMiles();
						inlineSM_enterUserAndPW();
						inlineSM_enrollSkyMiles();
					}
				//}
			}
		}
	}
	
	return 0;
}
