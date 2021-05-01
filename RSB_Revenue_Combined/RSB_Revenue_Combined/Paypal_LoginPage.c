Paypal_LoginPage()
{

	lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_12d_Paypal_01_LoginPage"));

	web_add_header("cartid", "{cartId}");
	web_add_header("X-Adapter", "mobile");
	web_add_header("mockResponse", "false");
	
	web_reg_save_param("paymentReferenceId", "LB=paymentReferenceId\":\"", "RB=\"", "Notfound=warning", LAST);
	
	lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_12_SavePaymentDetails"));

	web_custom_request("paymentDetails", 
		"URL=https://{URL}/payment/paymentDetails", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"afopFields\":[],\"cardDetails\":{\"billingAdr\":{\"id\":\"\",\"alias\":\"\",\"addressLine1Text\":\"1500 towerview rd\",\"addressLine2Text\":\"\",\"cityLocalityName\":\"eagan\",\"countryCode\":\"US\",\"countrySubdivisionCode\":\"MN\",\"postalCode\":\"55122\",\"districtTownName\":\"\"},\"cardHolderName\":{\"firstName\":\"Test\",\"lastName\":\"Tester\"},\"paymentType\":\"payPal\",\"purchaseVrfyFlag\":false,\"taxFormId\":\"\",\"taxFormNumber\":\"\"},\"rtbt\":{}}", 
		EXTRARES, 
		LAST);
	
	lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_12_SavePaymentDetails"), LR_AUTO);	

//	web_add_header("X-Adapter", 
//		"web");
//
//	web_add_header("cartId", 
//		"{cartId}");
//
//	web_custom_request("retrieveEligibleFop", 
//		"URL=https://{URL}/payment/retrieveEligibleFop", 
//		"Method=POST", 
//		"Resource=0", 
//		"RecContentType=application/json", 
//		"Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}",
//		"Snapshot=t3253.inf", 
//		"Mode=HTML", 
//		"EncType=application/json", 
//		"Body={\"cartId\":\"{cartId}\",\"skymilesNbr\":\"\"}", 
//		LAST);
	
		web_add_auto_header("Origin", 
			"https://{URL}");
	
		web_add_auto_header("X-Adapter", 
			"mobile");
	
		web_add_auto_header("airlineCode", 
			"dl");
	
		web_add_auto_header("cacheKey", 
			"{cacheKey}");
	
		web_add_auto_header("channelId", 
			"web");
	
		web_add_auto_header("mockResponse", 
			"false");
	
		web_add_auto_header("paymentReferenceId", 
			"{paymentReferenceId}");	
			
		web_reg_save_param("C_jwt","LB={\"jwt\":\"","RB=\"","notfound=warning",LAST);
		web_reg_find("SaveCount=bypassAuth_count","Text=\"bypassAuthentication\":true",LAST);
		
		lr_start_transaction("%3DS_Intialize%");
	
		web_custom_request("3dsInitialize", 
			"URL=https://{URL}/payment/formsOfPayments/3ds/initialize", 
			"Method=POST", 
			"Resource=0", 
			"RecContentType=application/json", 
			"Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}", 
			"Snapshot=t16.inf", 
			"Mode=HTML", 
			"EncType=application/json", 
			"Body={}", 
			EXTRARES, 
			LAST);
		
		lr_end_transaction("%3DS_Intialize%", LR_AUTO);
	
	web_revert_auto_header("Origin");

	web_revert_auto_header("X-Adapter");

	web_revert_auto_header("airlineCode");

	web_revert_auto_header("cacheKey");

	web_revert_auto_header("channelId");

	web_revert_auto_header("mockResponse");

	web_revert_auto_header("paymentReferenceId");		
	
	web_add_header("CacheKey", "{cacheKey}");
	
	web_add_header("appId", "CKO");

	web_add_header("X-APP-CHANNEL", "RSB-Booking");	
	web_add_header("channelId", "ECOM");
	web_add_header("timeout", "40000");

	web_reg_save_param_json(
        "ParamName=checkOutError",
        "QueryString=$.checkoutError",
        "Notfound=warning",
        "SEARCH_FILTERS",
        "Scope=Body",
        "LAST");
	
	web_custom_request("savePassengers", 
		"URL=https://{URL}/checkout/savePassengers", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t123.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		"Body={\"bookingContactInfo\":{\"emailAddress\":{\"emailAddress\":\"test@delta.com\"},\"confirmEmailAddress\":{\"emailAddress\":\"test@delta.com\"},\"phone\":{\"phoneNumber\":\"6155255589\",\"countryCode\":\"1\"}},\"cartId\":\"{cartId}\",\"passengerList\":[{passengerListString}],\"ofacAccepted\":false}",
		LAST);

	web_add_header("CacheKey", "{cacheKey}");
	
	web_add_header("appId", "CKO");

	web_add_header("X-APP-CHANNEL", "RSB-Booking");	
	web_add_header("channelId", "ECOM");
	web_add_header("timeout", "40000");
	
	web_custom_request("saveContactInfo", 
		"URL=https://{URL}/checkout/saveContactInfo", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t254.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={\"bookingContactInfo\":{\"emailAddress\":{\"emailAddress\":\"test@delta.com\"},\"confirmEmailAddress\":{\"emailAddress\":\"test@delta.com\"},\"phone\":{\"phoneNumber\":\"6155675896\",\"countryCode\":\"1\"}}}", 
		LAST);
	
	lr_start_transaction("%RSB_Booking_PaypalLogin%");
	

	web_add_auto_header("CacheKey", "{cacheKey}");

	web_add_header("pageName", 
		"REVIEW_PAY");
	
	web_add_auto_header("Accept", "application/json");
	web_add_auto_header("Content-Type", "application/json; charset=utf-8");
	
	web_add_header("appId", "CKO");

	web_add_header("X-APP-CHANNEL", "RSB-Booking");	
	web_add_header("channelId", "ECOM");
	web_add_header("timeout", "40000");

	web_reg_save_param_json(
        "ParamName=errorKey",
        "QueryString=$.checkoutErrorInfo",
        "Notfound=warning",
        "SEARCH_FILTERS",
        "Scope=Body",
        "LAST");

	
	web_reg_save_param("wholeRequest", "LB=", "RB=", "Notfound=warning",
        "Search=Body",LAST);
	
	web_reg_save_param_json(
        "ParamName=redirectUrl",
        "QueryString=$.redirectUrl",
        "Notfound=warning",
        "SEARCH_FILTERS",
        "Scope=Body",
        "LAST");

	web_reg_save_param("paypalPayload", "LB=payload\":{\"token\":\"", "RB=\"", "NotFound=Warning", LAST);
	
	web_custom_request("confirmation", 
		"URL=https://{URL}/checkout/confirmation", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t1254.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		"Body={\"cartId\":\"{cartId}\",\"channel\":\"ECOM\"}", 
		EXTRARES, 
		LAST);

	web_revert_auto_header("CacheKey");
	web_revert_auto_header("Content-Type");
	web_revert_auto_header("Accept");

	
	if(strlen(lr_eval_string("{paypalPayload}"))<=0)
	{
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_12d_Paypal_01_LoginPage"), LR_FAIL);
		
		if(strlen(lr_eval_string("{checkOutError}"))>0){
			lr_error_message("RSB Save Passenger Error: \t%s",lr_eval_string("{checkOutError}"));
			lr_error_message("RSB Checkout Error Key [Save Passenger was also Failed]: \t%s\tCartID:%s\tCacheKey:%s",lr_eval_string("{errorKey}"),lr_eval_string("{cartId}"),lr_eval_string("{cacheKey}"));
		} else if (strlen(lr_eval_string("{errorKey}"))>0){
			lr_error_message("RSB Checkout Error Key for Paypal: \t%s\tCartID:%s\tCacheKey:%s",lr_eval_string("{errorKey}"),lr_eval_string("{cartId}"), lr_eval_string("{cacheKey}"));
		}
		
		lr_end_transaction("%RSB_Booking_PaypalLogin%", LR_FAIL);		
		lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);	
		
	}
	
	lr_end_transaction("%RSB_Booking_PaypalLogin%", LR_AUTO);
	
	web_reg_save_param("csrfTokenString", "LB=\"data-csrf-token=\"", "RB=\"", "NotFound=Warning", LAST);
	web_reg_save_param("paypalSessionID", "LB=name=\"_sessionID\" value=\"", "RB=\"", "NotFound=Warning", LAST);
	web_reg_save_param("createChallengeURL", "LB=data-ads-challenge-url=\"", "RB=\"", "NotFound=Warning", LAST);
		
	web_url("webscr", 
		"URL=https://www.sandbox.paypal.com/cgi-bin/webscr?cmd=_express-checkout&useraction=commit&token={paypalPayload}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	web_reg_save_param("csrfVerifyChallenge", "LB=&_csrf=','", "RB=','", "NotFound=Warning", LAST);
	web_reg_save_param("verfyChallengeStringRAW", "LB='/auth/verifychallenge'", "RB=)", "NotFound=Warning", LAST);
	
	web_custom_request("challenge.js",
		"URL=https://www.sandbox.paypal.com{createChallengeURL}", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);
	
	web_submit_data("client-log", 
		"Action=https://www.sandbox.paypal.com/signin/client-log", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://www.sandbox.paypal.com/cgi-bin/webscr?cmd=_express-checkout&useraction=commit&token={paypalPayload}", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=_csrf", "Value={csrfTokenString}", ENDITEM, 
		"Name=currentUrl", "Value=https://www.sandbox.paypal.com/cgi-bin/webscr?cmd=_express-checkout&useraction=commit&token={paypalPayload}", ENDITEM, 
		"Name=logRecords", "Value=[{\"evt\":\"HYBRID_LOGIN\",\"data\":\"RENDERED_XO_DESKTOP\",\"calEvent\":true,\"timestamp\":1596563638292},{\"evt\":\"state_name\",\"data\":\"begin_hybrid_login\",\"instrument\":true,\"timestamp\":1596563638292},{\"evt\":\"transition_name\",\"data\":\"prepare_hybrid\",\"instrument\":true,\"timestamp\":1596563638292},{\"evt\":\"autofill\",\"data\":\"N\",\"instrument\":true,\"timestamp\":1596563638292},{\"evt\":\"landing_page\",\"data\":\"login\",\"instrument\":true,\""
		"timestamp\":1596563638292},{\"evt\":\"design\",\"data\":\"full-context\",\"instrument\":true,\"timestamp\":1596563638292},{\"evt\":\"page_lang\",\"data\":\"en_US\",\"instrument\":true,\"timestamp\":1596563638292},{\"evt\":\"context_correlation_id\",\"data\":\"a454e54013427\",\"instrument\":true},{\"evt\":\"serverside_data_source\",\"data\":\"checkout\",\"instrument\":true},{\"evt\":\"intent\",\"data\":\"checkout\",\"instrument\":true},{\"evt\":\"context_id\",\"data\":\"{paypalPayload}\",\""
		"instrument\":true}]", ENDITEM, 
		"Name=intent", "Value=checkout", ENDITEM, 
		"Name=_sessionID", "Value={paypalSessionID}", ENDITEM, 
		LAST);

	web_url("cookie-banner", 
		"URL=https://www.sandbox.paypal.com/signin/cookie-banner?flowId={paypalPayload}", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.sandbox.paypal.com/cgi-bin/webscr?cmd=_express-checkout&useraction=commit&token={paypalPayload}", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin", 
		"https://www.sandbox.paypal.com");

	web_submit_data("client-log_2", 
		"Action=https://www.sandbox.paypal.com/signin/client-log", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://www.sandbox.paypal.com/cgi-bin/webscr?cmd=_express-checkout&useraction=commit&token={paypalPayload}", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=_csrf", "Value={csrfTokenString}", ENDITEM, 
		"Name=currentUrl", "Value=https://www.sandbox.paypal.com/cgi-bin/webscr?cmd=_express-checkout&useraction=commit&token={paypalPayload}", ENDITEM, 
		"Name=logRecords", "Value=[{\"evt\":\"CHECKOUT_INCONTEXT\",\"data\":\"ONLOAD_WINDOW_NAME\",\"calEvent\":true,\"calPayload\":\"\",\"timestamp\":1596563638327},{\"evt\":\"context_correlation_id\",\"data\":\"a454e54013427\",\"instrument\":true},{\"evt\":\"serverside_data_source\",\"data\":\"checkout\",\"instrument\":true},{\"evt\":\"intent\",\"data\":\"checkout\",\"instrument\":true},{\"evt\":\"context_id\",\"data\":\"{paypalPayload}\",\"instrument\":true}]", ENDITEM, 
		"Name=intent", "Value=checkout", ENDITEM, 
		"Name=_sessionID", "Value={paypalSessionID}", ENDITEM, 
		LAST);	
	
	
//	web_reg_save_param_custom(lr_eval_string("{verfyChallengeStringRAW}"), "firstString", ",", ",");
//	web_reg_save_param_custom(lr_eval_string("{verfyChallengeStringRAW}"), "secondString", lr_eval_string("{firstString},'"), "',");
//	web_reg_save_param_custom(lr_eval_string("{verfyChallengeStringRAW}"), "thirdString", lr_eval_string("{secondString}','"), "'");
	
//	web_add_header("Sec-Fetch-Site", 
//		"same-origin");
//
//	web_add_header("Sec-Fetch-Mode", 
//		"cors");
//
//	web_add_header("Sec-Fetch-Dest", 
//		"empty");
//
//	web_add_header("Origin", 
//		"https://www.sandbox.paypal.com");
//
//	web_add_header("X-Requested-With", 
//		"XMLHttpRequest");
//
//	web_submit_data("verifychallenge", 
//		"Action=https://www.sandbox.paypal.com/auth/verifychallenge", 
//		"Method=POST", 
//		"RecContentType=text/plain", 
//		"Referer=https://www.sandbox.paypal.com/cgi-bin/webscr?cmd=_express-checkout&useraction=commit&token={paypalPayload}", 
//		"Snapshot=t21.inf", 
//		"Mode=HTML", 
//		ITEMDATA, 
//		"Name=ads_token_js", "Value=y1k8r50lo7355ok2rk25110inl18294bzy477095c8f215914f7d9fj6038001901q31v5sw473833zs6335zv905b0fs90623c56d7b593ed163", ENDITEM, 
//		"Name=_csrf", "Value={csrfVerifyChallenge}", ENDITEM, 
//		"Name=_sessionID", "Value={paypalSessionID}", ENDITEM, 
//		"Name={secondString}", "Value={thirdString}", ENDITEM, 
//		EXTRARES, 
//		LAST);

	lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_12d_Paypal_01_LoginPage"), LR_AUTO);
	
	
	return 0;
}
