CancelSeatReviewPay()
{

	ContinueAndReview();
		
	if(atoi(lr_eval_string("{insurancePurchase}"))==1) {
		if(strcmp(lr_eval_string("{ccType}"), "TP")!=0){
				InsuranceSearch();
				if(strlen(lr_eval_string("{quotePackId}"))<=0){
					lr_output_message("Insurance unavailable for %s-%s", lr_eval_string("{Origin}"),lr_eval_string("{Destination}"));
					lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);
				}
		}
	}
	
	return 0;
}
