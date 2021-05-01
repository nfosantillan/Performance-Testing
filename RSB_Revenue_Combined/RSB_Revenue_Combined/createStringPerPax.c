createStringPerPax()
{
	int i;
	
	for(i=1; i<=atoi(lr_eval_string("{numPax}")); i++){
		lr_save_int(i, "passengerIndex");
		createJSONSeatRequestString();
	}
	
	return 0;
}
