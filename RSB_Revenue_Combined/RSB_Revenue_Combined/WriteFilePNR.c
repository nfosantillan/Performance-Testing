WriteFilePNR()
{

	lr_save_string(lr_eval_string("{PNR}\t{firstPassengerFirstName}\t{firstPassengerLastName}\t{paymentType}\tREVENUE\t{PNRCreationDate}"),"PNRDetails");
	
	VTS_InsertRows(lr_eval_string("{PNRDetails}"));
	
	return 0;
}
