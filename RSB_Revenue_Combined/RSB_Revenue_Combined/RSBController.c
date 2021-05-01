RSBController()
{
	randomizeFlexAndNonFlex();
	
	/************************** INLINE ENROLLMENT CONTROL (START) *********************************/
	lr_save_int(5, "randEnrollPercent"); //indicate how many percent to indicate probability that it will go to inlineEnrollment and perform SM enrollment
	lr_save_string(lr_eval_string("{RandEnroll}"), "randomEnrollNumSelected");
	
	if(atoi(lr_eval_string("{randomEnrollNumSelected}"))<=atoi(lr_eval_string("{randEnrollPercent}"))){
		lr_save_int(1, "inlineEnrollmentFlag");
	} else {
		lr_save_int(0, "inlineEnrollmentFlag");
	}
	/************************** INLINE ENROLLMENT CONTROL (END) *********************************/
	
	lr_save_string(lr_eval_string("{RandPSD2}"), "PSD2");
	lr_save_string("0", "PSD2");
	lr_save_string("0", "METERING");
	lr_save_int(0, "checkoutBannerFlag");
	lr_save_int(0, "tripInsuranceSuccessFlag");
	
	if(strcmp(lr_eval_string("{RandTripType}"), "RT")==0){
		lr_save_string("roundtrip", "randTripTypeString");
	}
	if(strcmp(lr_eval_string("{RandTripType}"), "OW")==0){
		lr_save_string("oneway", "randTripTypeString");
	}
	if(strcmp(lr_eval_string("{RandTripType}"), "MC")==0){
		lr_save_string("multicity", "randTripTypeString");
	}	
	
	
	if(strcmp(lr_eval_string("{ccType}"), "VI")==0){
		lr_save_string("visa", "ccTypeString");
	}
	if(strcmp(lr_eval_string("{ccType}"), "DC")==0){
		lr_save_string("dc", "ccTypeString");
	}
	if(strcmp(lr_eval_string("{ccType}"), "DS")==0){
		lr_save_string("discover", "ccTypeString");
	}
	if(strcmp(lr_eval_string("{ccType}"), "JC")==0){
		lr_save_string("jcb", "ccTypeString");
	}	
	if(strcmp(lr_eval_string("{ccType}"), "CA")==0){
		lr_save_string("mastercard", "ccTypeString");
	}
	if(strcmp(lr_eval_string("{ccType}"), "AX")==0){
		lr_save_string("amex", "ccTypeString");
	}
	if(strcmp(lr_eval_string("{ccType}"), "TP")==0){
		lr_save_string("uatp", "ccTypeString");
	}
	
	if(strcmp(lr_eval_string("{formOfPayment}"), "Paypal")==0){
		lr_save_int(0, "insurancePurchase"); 
		lr_save_int(0, "tripExtrasPurchase");
	}
	
	Homepage();
	
	//RSBShoplite();
	
	//BAUShoplite();
	return 0;
}
