getErrorMessage()
{
	int loopCount=0;
	
	if(strlen(lr_eval_string("{errorNumber}"))<=0){
		lr_save_string("", "errorMessage");
		return 0;
	}
	
	lr_save_int(0, "errorFound");
	do {
		lr_save_string(lr_eval_string("{errorCodes}"), "savedErrorCode");
		if(strstr(lr_eval_string("{savedErrorCode}"),lr_eval_string("{errorNumber}"))!=NULL){ //get the error message equivalent of the error code then print
			lr_save_string(lr_eval_string("{savedErrorCode}"), "lastErrorValue");
			lr_save_string(lr_eval_string("{savedErrorCode}"), "errorMessage");
			lr_save_int(1, "errorFound");
			return 0;
		}
		loopCount++;
	}while((strstr(lr_eval_string("{savedErrorCode}"),lr_eval_string("{lastErrorValue}"))==NULL)||(loopCount<101)); //loop throughout the table up to the lastErrorValue on the previous iteration
	
	if(atoi(lr_eval_string("{errorFound}"))<=0){
		lr_save_string(lr_eval_string("{savedErrorCode}"), "lastErrorValue");
		lr_save_string("", "errorMessage");
	}
	
	return 0;
}
