CompletePurchase()
{
	int i;
	lr_think_time(5);
	
	//lr_save_string("NonPSD2", "cardPDS2Flag");
	
	/****************************************** START OF ADD PASSENGER DETAILS, PAYMENT, INFORMATION ******************************************************/
	
	createPassengerList();
	web_add_header("cartid", "{cartId}");
	web_add_header("X-Adapter", "mobile");
	web_add_header("mockResponse", "false");
	
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
		"Body={\"cardDetails\":{\"billingAdr\":{\"addressLine1Text\":\"1500 Towerview Rd\",\"cityLocalityName\":\"Eagan\",\"countryCode\":\"US\",\"countrySubdivisionCode\":\"MN\",\"postalCode\":\"55122\"},\"cardHolderName\":{\"firstName\":\"{firstName}\",\"lastName\":\"{lastName}\",\"middleInitialName\":null,\"prefix\":null,\"suffix\":null},\"cardType\":\"{ccType}\",\"expirationMonthNum\":\"02\",\"expirationYearNum\":\"2020\",\"lastFourDigits\":\"{lastFourDigits}\",\"paymentCardNum\":\"{ccNum}\",\""
		"paymentCardSecurityCode\":\"{cvv}\",\"paymentType\":\"Credit Card\",\"purchaseVrfyFlag\":false,\"alias\":null,\"alipayPaymentReferenceId\":null,\"formatInd\":null,\"paymentCardNetworkCode\":null,\"paymentVendorTransactionId\":null,\"savedFopId\":null,\"secureIdOnFOP\":null,\"uid\":null},\"paymentType\":\"Credit Card\",\"afopFields\":[],\"rtbt\":{}}", 
		EXTRARES, 
		LAST);
	
	lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_12_SavePaymentDetails"), LR_AUTO);

	for(i=1;i<=atoi(lr_eval_string("{numPax}"));i++){
			web_add_header("CacheKey", 
				"{cacheKey}");
		
			web_add_header("X-APP-CHANNEL", 
				"RSB-Booking");
		
			web_add_header("airlineCode", 
				"DL");
		
			web_add_header("appId", 
				"CKO");
		
			web_add_header("channelId", 
				"ECOM");
		
			web_add_header("isMobile", 
				"false");
		
			web_add_header("pageName", 
				"ABC");
		
			lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_12c_SaveAgeDetails"));
		
			web_custom_request("passengerAgeInfo", 
				"URL=https://{URL}/checkout/passengerAgeInfo", 
				"Method=POST", 
				"Resource=0", 
				"RecContentType=application/json", 
				"Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}",
				"Snapshot=t5.inf", 
				"Mode=HTML", 
				"EncType=application/json; charset=utf-8", 
				"Body={\"birthDate\":\"1971-01-03\",\"travelDate\":\"{P_DepartureDate}\"}", 
				LAST);
			
			lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_12c_SaveAgeDetails"), LR_AUTO);
	}
	
	lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_12b_SavePassengerDetails"));

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
		"Snapshot=t122.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		"Body={\"bookingContactInfo\":{\"emailAddress\":{\"emailAddress\":\"test@delta.com\"},\"confirmEmailAddress\":{\"emailAddress\":\"test@delta.com\"},\"phone\":{\"phoneNumber\":\"6155255589\",\"countryCode\":\"1\"}},\"cartId\":\"{cartId}\",\"passengerList\":[{passengerListString}],\"ofacAccepted\":false}",
		LAST);
	
	lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_12b_SavePassengerDetails"), LR_AUTO);

	lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_12a_SaveContactDetails"));

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
	
	lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_12a_SaveContactDetails"), LR_AUTO);
	/****************************************** END OF ADD PASSENGER DETAILS, PAYMENT, INFORMATION ******************************************************/
	/**************************************START OF COMPLETE PURCHASE **********************************************************************************/
	lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_13_CompletePurchase_{ccType}_{psd2Flag}"));

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
		"Body={\"cardDetails\":{\"billingAdr\":{\"addressLine1Text\":\"1500 Towerview Rd\",\"cityLocalityName\":\"Eagan\",\"countryCode\":\"US\",\"countrySubdivisionCode\":\"MN\",\"postalCode\":\"55122\"},\"cardHolderName\":{\"firstName\":\"{firstName}\",\"lastName\":\"{lastName}\",\"middleInitialName\":null,\"prefix\":null,\"suffix\":null},\"cardType\":\"{ccType}\",\"expirationMonthNum\":\"02\",\"expirationYearNum\":\"2030\",\"lastFourDigits\":\"{lastFourDigits}\",\"paymentCardNum\":\"{ccNum}\",\""
		"paymentCardSecurityCode\":\"{cvv}\",\"paymentType\":\"Credit Card\",\"purchaseVrfyFlag\":false,\"alias\":null,\"alipayPaymentReferenceId\":null,\"formatInd\":null,\"paymentCardNetworkCode\":null,\"paymentVendorTransactionId\":null,\"savedFopId\":null,\"secureIdOnFOP\":null,\"uid\":null},\"paymentType\":\"Credit Card\",\"afopFields\":[],\"rtbt\":{}}", 
		EXTRARES, 
		LAST);
	
	lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_12_SavePaymentDetails"), LR_AUTO);	

	web_add_header("X-Adapter", 
		"web");

	web_add_header("cartId", 
		"{cartId}");

	web_custom_request("retrieveEligibleFop", 
		"URL=https://{URL}/payment/retrieveEligibleFop", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}",
		"Snapshot=t3253.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"cartId\":\"{cartId}\",\"skymilesNbr\":\"\"}", 
		LAST);
	
	web_reg_save_param_json("ParamName=PSD2Chk","QueryString=$.usePSD2","notfound=warning",LAST);
		
	lr_start_transaction("%IDP-PSD2%");

	web_url("component-config.psd2compdata.json", 
		"URL=https://{URL}/content/www/en_US/idp-psd2/component-config.psd2compdata.json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}",
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);
	
	web_reg_save_param_json("ParamName=PSD2Chk2","QueryString=$..APP_PSD2","notfound=warning",LAST);

	web_url("feature-flag.psd2data.json", 
		"URL=https://{URL}/content/www/en_US/idp-psd2/feature-flag.psd2data.json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("%IDP-PSD2%", LR_AUTO);
	
	if((strcmp(lr_eval_string("{PSD2Chk}"),"true")==0)&&(strcmp(lr_eval_string("{PSD2Chk2}"),"ON")==0)){
	
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

		web_add_auto_header("purchasePath", 
			"BOOKING");

		web_add_auto_header("appId", 
			"DCOM");
		
		web_reg_save_param("C_jwt","LB={\"jwt\":\"","RB=\"","notfound=warning",LAST);
		web_reg_find("SaveCount=bypassAuth_count","Text=\"bypassAuthentication\":true",LAST);
		
		lr_start_transaction("%3DS_Intialize%");
	
		web_custom_request("3dsInitialize", 
			"URL=https://{URL}/payment/v2/formsOfPayments/3ds/initialize", 
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
	
		if(atoi(lr_eval_string("{bypassAuth_count}"))==0){
			if(strlen(lr_eval_string("{C_jwt}"))>0){
			
				//lr_save_string("PSD2", "cardPDS2Flag");
				
			lr_start_transaction("%3DS_Authenticate%");
			
			web_custom_request("authenticate", 
				"URL=https://{URL}/payment/v2/formsOfPayments/3ds/authenticate", 
				"Method=POST", 
				"Resource=0", 
				"RecContentType=application/json", 
				"Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}",
				"Snapshot=t96.inf", 
				"Mode=HTML", 
				"EncType=application/json", 
				"Body={\"DFReferenceId\":\"\",\"browserSpecification\":{\"acceptHeaderText\":\"\",\"colorDepthCnt\":\"24\",\"ipAdr\":\"\",\"javaEnabled\":false,\"languageCode\":\"en-US\",\"screenHeightCnt\":\"2990\",\"screenWidthCnt\":\"1520\",\"timeZoneMinuteCnt\":\"300\",\"userAgentHeaderText\":\"Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/78.0.3895.5 Safari/537.36\"},\"emailAdr\":\"\",\"formOfPayment\":{\"paymentMethod\":{\"paymentMethodTypeName\":\"\",\""
				"customerReferenceId\":\"\",\"billingAddress\":{\"addressAliasName\":\"\",\"addressLine1Text\":\"\",\"addressLine2Text\":\"\",\"businessName\":\"\",\"cityLocalityName\":\"\",\"contactPointCode\":\"\",\"countryCode\":\"\",\"countrySubdivisionCode\":\"\",\"districtTownName\":\"\",\"isoCountryCode\":\"\",\"mailingRecipientName\":\"\",\"postalCode\":\"\",\"prefectureLocationName\":\"\"},\"miles\":{\"loyaltyMemberId\":\"\",\"passengerCnt\":0,\"passengerTypeCode\":\"ADT\",\"payWithMilesCode\":\""
				"PAY_WITH_MILES_FULL,PAY_WITH_MILES_PARTIAL,UPGRADE_WITH_MILES\",\"perPassengerDiscountAmt\":{\"currencyEquivalentPriceAmt\":{\"countryCode\":\"\",\"currencyAmt\":0,\"currencyCode\":\"\",\"decimalPrecisionCnt\":0,\"iataDecimalPrecisionCnt\":0},\"milesEquivalentPriceAmt\":{\"cashPlusMiles\":false,\"discountMileCnt\":0,\"mileCnt\":0}},\"pssPassengerTypeCode\":\"K\"},\"financialInstitution\":{\"financialInstitutionId\":\"\",\"financialInstitutionName\":\"\"},\"paymentCard\":{\"authenticationCode\":\""
				"\",\"billingAdr\":{\"addressAliasName\":\"\",\"addressLine1Text\":\"\",\"addressLine2Text\":\"\",\"businessName\":\"\",\"cityLocalityName\":\"\",\"contactPointCode\":\"\",\"countryCode\":\"\",\"countrySubdivisionCode\":\"\",\"districtTownName\":\"\",\"isoCountryCode\":\"\",\"mailingRecipientName\":\"\",\"postalCode\":\"\",\"prefectureLocationName\":\"\"},\"cardHolderName\":{\"firstName\":\"\",\"lastName\":\"\",\"middleInitialName\":\"\",\"middleName\":\"\",\"namePrefixCode\":\"\",\"nameSuffixCode"
				"\":\"\"},\"cardVerificationValueNum\":\"\",\"expirationMonthNum\":\"\",\"expirationYearNum\":\"\",\"paymentCardLast4Num\":\"\",\"paymentCardNetworkCode\":\"\",\"paymentCardNetworkName\":\"\",\"paymentCardNum\":\"\",\"paymentCardTypeCode\":\"\",\"storedPaymentMethodId\":\"\"},\"eDocument\":{\"couponIsOpenStatus\":false,\"destinationAirportCode\":\"\",\"digitsAfterDecimalForRequestedCurrencyValidated\":false,\"documentAssociatedToBooking\":false,\"documentAssociatedToPrimaryCarrierBooking\":false,\""
				"documentDesc\":\"\",\"documentNum\":\"\",\"documentSubTypeCode\":\"\",\"documentSuspended\":false,\"documentTotalAmt\":{\"currencyEquivalentPriceAmt\":{\"countryCode\":\"\",\"currencyAmt\":0,\"currencyCode\":\"\",\"decimalPrecisionCnt\":0,\"iataDecimalPrecisionCnt\":0},\"milesEquivalentPriceAmt\":{\"cashPlusMiles\":false,\"discountMileCnt\":0,\"mileCnt\":0}},\"documentTypeCode\":\"\",\"documentVoided\":false,\"enteredDocumentNum\":\"\",\"expirationDate\":\"\",\"flightDepartureDate\":\"\",\""
				"highLevelDocumentTypeCode\":\"\",\"isPrimary\":false,\"issueLocalDate\":\"\",\"loyaltyMemberId\":\"\",\"loyaltyMemberPinCode\":\"\",\"originAirportCode\":\"\",\"personName\":{\"firstName\":\"\",\"lastName\":\"\",\"middleInitialName\":\"\",\"middleName\":\"\",\"namePrefixCode\":\"\",\"nameSuffixCode\":\"\"},\"phoneNum\":\"\",\"redemptionCode\":\"\",\"redemptionCodeRequiredToDisplay\":false,\"requestedCurrencyValidated\":false,\"valueInRequestedCurrencyValidated\":false},\"edocument\":{\""
				"couponIsOpenStatus\":false,\"destinationAirportCode\":\"\",\"digitsAfterDecimalForRequestedCurrencyValidated\":false,\"documentAssociatedToBooking\":false,\"documentAssociatedToPrimaryCarrierBooking\":false,\"documentDesc\":\"\",\"documentNum\":\"\",\"documentSubTypeCode\":\"\",\"documentSuspended\":false,\"documentTotalAmt\":{\"currencyEquivalentPriceAmt\":{\"countryCode\":\"\",\"currencyAmt\":0,\"currencyCode\":\"\",\"decimalPrecisionCnt\":0,\"iataDecimalPrecisionCnt\":0},\""
				"milesEquivalentPriceAmt\":{\"cashPlusMiles\":false,\"discountMileCnt\":0,\"mileCnt\":0}},\"documentTypeCode\":\"\",\"documentVoided\":false,\"enteredDocumentNum\":\"\",\"expirationDate\":\"\",\"flightDepartureDate\":\"\",\"highLevelDocumentTypeCode\":\"\",\"isPrimary\":false,\"issueLocalDate\":\"\",\"loyaltyMemberId\":\"\",\"loyaltyMemberPinCode\":\"\",\"originAirportCode\":\"\",\"personName\":{\"firstName\":\"\",\"lastName\":\"\",\"middleInitialName\":\"\",\"middleName\":\"\",\"namePrefixCode\":"
				"\"\",\"nameSuffixCode\":\"\"},\"phoneNum\":\"\",\"redemptionCode\":\"\",\"redemptionCodeRequiredToDisplay\":false,\"requestedCurrencyValidated\":false,\"valueInRequestedCurrencyValidated\":false}},\"price\":{\"currencyEquivalentPriceAmt\":{\"countryCode\":\"\",\"currencyAmt\":0,\"currencyCode\":\"\",\"decimalPrecisionCnt\":0,\"iataDecimalPrecisionCnt\":0},\"milesEquivalentPriceAmt\":{\"cashPlusMiles\":false,\"discountMileCnt\":0,\"mileCnt\":0}},\"authenticationData\":{\"ucafIndicator\":\"\",\"eci"
				"\":\"\",\"cavv\":\"\",\"cavvAlgorithm\":\"\",\"xid\":\"\",\"serverTransactionId\":\"\",\"dsTransactionId\":\"\"},\"authorization\":{\"approvalCode\":\"\",\"authorizationCharactersInd\":\"\",\"validationCode\":\"\",\"responseCode\":\"\",\"sourceName\":\"\",\"posEntryModeCode\":\"\",\"avsResponseCode\":\"\",\"banknetDate\":\"\",\"banknetReferenceNum\":\"\",\"cardLevelResultsText\":\"\",\"acquirerReferenceDataText\":\"\",\"posDataCode\":\"\",\"cardholderIdMethodCode\":\"\",\"accountStatusCode\":\"\","
				"\"tokenAssuranceLevelCode\":\"\",\"tokenRequestorId\":\"\",\"spendQualifiedCode\":\"\",\"securityProtocolText\":\"\",\"transactionIntegrityClassCode\":\"\",\"paymentAccountReferenceNum\":\"\",\"marketSpecificDataCode\":\"\",\"systemTraceAuditNum\":\"\",\"tranasctionDataConditionCode\":\"\",\"processingCode\":\"\"},\"paymentReferenceId\":\"\",\"marketedProductType\":\"\"},\"loyaltyMemberId\":\"\",\"phoneNum\":\"\"}", 
				LAST);	
			
			lr_end_transaction("%3DS_Authenticate%", LR_AUTO);
			}
		}
	}
	
	web_revert_auto_header("Origin");

	web_revert_auto_header("X-Adapter");

	web_revert_auto_header("airlineCode");

	web_revert_auto_header("cacheKey");

	web_revert_auto_header("channelId");

	web_revert_auto_header("mockResponse");

	web_revert_auto_header("paymentReferenceId");		

	web_revert_auto_header("appId");

	web_revert_auto_header("purchasePath");	
	
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

	web_add_header("X-Adapter", 
		"web");

	web_add_header("cartId", 
		"{cartId}");

	web_custom_request("retrieveEligibleFop", 
		"URL=https://{URL}/payment/retrieveEligibleFop", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}",
		"Snapshot=t3253.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"cartId\":\"{cartId}\",\"skymilesNbr\":\"\"}", 
		LAST);
	
//	web_add_header("X-Adapter", 
//		"mobile");
//
//	web_add_header("cartId", 
//		"{cartId}");
//
//	web_custom_request("revalCart", 
//		"URL=https://{URL}/seatmap/ism/revalCart", 
//		"Method=POST", 
//		"Resource=0", 
//		"RecContentType=application/json", 
//		"Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}",
//		"Snapshot=t545.inf", 
//		"Mode=HTML", 
//		"EncType=application/json", 
//		"Body={\"cartId\":\"{cartId}\"}", 
//		LAST);
	
	if(atoi(lr_eval_string("{domesticFlag}"))>0){
		lr_save_string("%Booking_Rev_Domestic%", "OrderTransaction");
	} else{
		lr_save_string("%Booking_Rev_NotDomestic%", "OrderTransaction");
	}
	
	lr_start_transaction("%RSB_Booking%");
	lr_start_transaction("%Booking%");
	lr_start_transaction(lr_eval_string("{OrderTransaction}"));

	web_add_auto_header("CacheKey", "{cacheKey}");

	web_add_header("pageName", 
		"REVIEW_PAY");
	
	web_add_auto_header("Accept", "application/json");
	web_add_auto_header("Content-Type", "application/json; charset=utf-8");
	
	web_add_header("appId", "CKO");

	web_add_header("X-APP-CHANNEL", "RSB-Booking");	
	web_add_header("channelId", "ECOM");
	web_add_header("timeout", "40000");
	
	web_reg_save_param("PNR", "LB=recordLocator\":\"", "RB=\"", "Notfound=warning", LAST);
	web_reg_save_param("customerRefId", "LB=\"customerRefId\":\"", "RB=\"", "Notfound=warning", LAST);
	web_reg_find("Text=key\":\"3005R", "Savecount=fareChanged_count", LAST);

	web_reg_save_param_json(
        "ParamName=errorKey",
        "QueryString=$.checkoutErrorInfo",
        "Notfound=warning",
        "SEARCH_FILTERS",
        "Scope=Body",
        "LAST");

	web_reg_save_param_json(
        "ParamName=insurancePurchaseInformation",
        "QueryString=$.insurancePurchase",
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

	web_reg_save_param("c_customerEmailAddress", "LB=\"customerEmailAddress\":\"", "RB=\"", "NotFound=Warning", "Search=Body", LAST);
	web_reg_save_param("c_phoneNumber", "LB=\"phoneNum\":\"", "RB=\"", "NotFound=Warning", "Search=Body", LAST);
	web_reg_save_param("paymentRefId", "LB=paymentRefId\":\"", "RB=\"", "NotFound=Warning", LAST);
	web_reg_find("Text=\"retailRoute\":true", "Savecount=retailRouteTrueFlag", LAST);
	
	web_custom_request("confirmation", 
		"URL=https://{URL}/checkout/confirmation", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t1254.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		"Body={\"cartId\":\"{cartId}\",\"channel\":\"ECOM\",\"purchaseInsurance\":{purchaseInsurance}}", 
		EXTRARES, 
		"Url=../content/www/omniui-payment/payment.omniui.json", "Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}", ENDITEM,  
		LAST);

	web_revert_auto_header("CacheKey");
	web_revert_auto_header("Content-Type");
	web_revert_auto_header("Accept");
	
	if(strstr(lr_eval_string("{redirectUrl}"), "merchantacsstag.cardinalcommerce.com")!=NULL){
		lr_output_message("RSB Checkout 3DS Card: \tCartID:%s\tCacheKey:%s\tCCNum:%s\tCCType:%s",lr_eval_string("{cartId}"), lr_eval_string("{cacheKey}"),lr_eval_string("{ccNum}"), lr_eval_string("{ccType}"));
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_13_CompletePurchase_{ccType}_{psd2Flag}"), LR_FAIL);
		lr_end_transaction("%RSB_Booking%", LR_FAIL);
		lr_end_transaction("%Booking%", LR_FAIL);
		lr_end_transaction(lr_eval_string("{OrderTransaction}"), LR_FAIL);
		
		lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);
		
	}
		
	if(atoi(lr_eval_string("{fareChanged_count}"))>0){
		lr_output_message("Fare Changed for \tORIGIN\t%s\tDESTINATION\t%s",lr_eval_string("{Origin}"),lr_eval_string("{Destination}"));
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_13_CompletePurchase_{ccType}_{psd2Flag}"), LR_AUTO);	
		lr_end_transaction("%RSB_Booking%", LR_AUTO);
		lr_end_transaction("%Booking%", LR_AUTO);
		lr_end_transaction(lr_eval_string("{OrderTransaction}"), LR_AUTO);
		lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);		
	}
		
	
	if(strlen(lr_eval_string("{PNR}"))<=0)
	{
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_13_CompletePurchase_{ccType}_{psd2Flag}"), LR_FAIL);
		
		if(strlen(lr_eval_string("{checkOutError}"))>0){
			lr_error_message("RSB Save Passenger Error: \t%s",lr_eval_string("{checkOutError}"));
			lr_error_message("RSB Checkout Error Key [Save Passenger was also Failed]: \t%s\tCartID:%s\tCacheKey:%s",lr_eval_string("{errorKey}"),lr_eval_string("{cartId}"),lr_eval_string("{cacheKey}"));
		} else if (strlen(lr_eval_string("{errorKey}"))>0){
			lr_error_message("RSB Checkout Error Key: \t%s\tCartID:%s\tCacheKey:%s\tCCType:%s\tCCNum:%s",lr_eval_string("{errorKey}"),lr_eval_string("{cartId}"), lr_eval_string("{cacheKey}"), lr_eval_string("{ccType}"), lr_eval_string("{ccNum}"));
		} else{
			lr_error_message("RSB Checkout NO Error Key: \t%s\tCartID:%s\tCacheKey:%s\tCCType:%s\tCCNum:%s",lr_eval_string("{wholeRequest}"),lr_eval_string("{cartId}"), lr_eval_string("{cacheKey}"), lr_eval_string("{ccType}"), lr_eval_string("{ccNum}"));
		}
		
		lr_end_transaction("%RSB_Booking%", LR_FAIL);
		lr_end_transaction("%Booking%", LR_FAIL);
		lr_end_transaction(lr_eval_string("{OrderTransaction}"), LR_FAIL);		
		lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);	
		
	}
	
	
	lr_end_transaction("%RSB_Booking%", LR_AUTO);
	lr_end_transaction("%Booking%", LR_AUTO);
	lr_end_transaction(lr_eval_string("{OrderTransaction}"), LR_AUTO);
	
	lr_save_datetime("%c %Z",DATE_NOW,"PNRCreationDate");
	
//	if(atoi(lr_eval_string("{retailRouteTrueFlag}"))>0){
//		lr_error_message("ORDER TRUE for\t%s\tCartID:%s\tCacheKey:%s\tCCType:%s\tCCNum:%s",lr_eval_string("{PNR}"),lr_eval_string("{cartId}"), lr_eval_string("{cacheKey}"), lr_eval_string("{ccType}"), lr_eval_string("{ccNum}"));
//	}
		
	lr_save_string("false", "loyaltyMileageInfoIndicator");
	
	web_add_auto_header("CacheKey", 
		"{cacheKey}");

	web_add_auto_header("X-APP-CHANNEL", 
		"RSB-Booking");

	web_add_auto_header("appId", 
		"CKO");

	web_add_auto_header("channelId", 
		"ECOM");

	web_reg_save_param("earnedMiles", "LB=earnedMQMs\":\"", "RB=\"", "Notfound=warning", LAST);
		
	lr_start_transaction("%LoyaltyMileageInfo%");

	web_custom_request("loyaltyMileageInfo", 
		"URL=https://{URL}/checkout/loyaltyMileageInfo", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", 
		"Snapshot=t2215.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={\"cartId\":\"{cartId}\",\"loyaltyMileageInfoIndicator\":false}", 
		LAST);

	lr_end_transaction("%LoyaltyMileageInfo%", LR_AUTO);

//	lr_start_transaction("%LoyaltyMileageInfo%");
//
//	web_custom_request("loyaltyMileageInfo", 
//		"URL=https://{URL}/checkout/loyaltyMileageInfo", 
//		"Method=POST", 
//		"Resource=0", 
//		"RecContentType=application/json", 
//		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", 
//		"Snapshot=t2215.inf", 
//		"Mode=HTML", 
//		"EncType=application/json; charset=UTF-8", 
//		"Body={\"cartId\":\"{cartId}\",\"loyaltyMileageInfoIndicator\":{loyaltyMileageInfoIndicator}}", 
//		LAST);
//
//	lr_end_transaction("%LoyaltyMileageInfo%", LR_AUTO);
	
	web_revert_auto_header("CacheKey");

	web_revert_auto_header("X-APP-CHANNEL");

	web_revert_auto_header("appId");

	web_revert_auto_header("channelId");
	
	
	web_add_header("CacheKey", "{cacheKey}");

	web_add_header("X-APP-CHANNEL", 
		"RSB-Booking");

	web_add_header("appId", 
		"CKO");

	web_add_header("channelId", 
		"ECOM");

	web_add_header("Accept", "application/json");
	web_add_header("Content-Type", "application/json; charset=utf-8");
	
	web_custom_request("sendEmailAfterConfirmation", 
		"URL=https://{URL}/checkout/sendEmailAfterConfirmation?RecordLocator={PNR}", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t888.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		"Body={}", 
		LAST);

	if(atoi(lr_eval_string("{insurancePurchase}"))==1) {
		if(strcmp(lr_eval_string("{ccType}"), "TP")!=0){
			if(atoi(lr_eval_string("{tripInsuranceSuccessFlag}"))==1) {
				
				if(strlen(lr_eval_string("{insurancePurchaseInformation}"))>0){
					lr_save_string(lr_eval_string("XXX{insurancePurchaseInformation}XXX"), "insurancePurchaseInformation");
					web_reg_save_param_custom(lr_eval_string("{insurancePurchaseInformation}"), "insurancePurchaseInformation_TEMP", "XXX{", "}XXX");
					lr_save_string(lr_eval_string("{{insurancePurchaseInformation_TEMP},\"cardPayment\":{\"emailAdr\":\"test@delta.com\",\"paymentReferenceId\":\"{paymentReferenceId}\",\"billingAdr\":{\"phoneNum\":\"6152352345\"}}}"),"insurancePurchaseInformation");
				}
				
				web_add_auto_header("CacheKey", 
					"{cacheKey}");
			
				web_add_auto_header("X-APP-CHANNEL", 
					"RSB-Booking");
			
				web_add_auto_header("appId", 
					"CKO");
			
				web_add_auto_header("channelId", 
					"ECOM");
				
				web_add_header("airlineCode", 
					"DL");
			
				web_add_header("isMobile", 
					"false");
			
				web_add_header("pageName", 
					"ABC");
			
				lr_continue_on_error(1);
				
				web_custom_request("purchase", 
					"URL=https://{URL}/merchandize/products/purchase", 
					"Method=POST", 
					"Resource=0", 
					"RecContentType=application/json", 
					"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", 
					"Snapshot=t20.inf", 
					"Mode=HTML", 
					"EncType=application/json; charset=utf-8", 
					"Body={insurancePurchaseInformation}", 
					LAST);
			
				lr_continue_on_error(0);
				
				web_revert_auto_header("CacheKey");
			
				web_revert_auto_header("X-APP-CHANNEL");
			
				web_revert_auto_header("appId");
			
				web_revert_auto_header("channelId");
			}
		}
	}
	
//	web_add_header("CacheKey", "{cacheKey}");
//	
//	web_add_header("appId", "CKO");
//
//	web_add_header("X-APP-CHANNEL", "RSB-Booking");	
//	web_add_header("channelId", "ECOM");
//	web_add_header("timeout", "40000");
//	
//	web_custom_request("baggage", 
//		"URL=https://{URL}/checkout/baggage", 
//		"Method=POST", 
//		"Resource=0", 
//		"RecContentType=application/json", 
//		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", 
//		"Snapshot=t1266.inf", 
//		"Mode=HTML", 
//		"EncType=application/json; charset=utf-8", 
//		"Body={\"cartId\":\"{cartId}\",\"channel\":\"MOB\",\"offerId\":\"11111\"}", 
//		EXTRARES, 
//		"Url=https://{contentURL}/content/dam/delta-applications/complete-purchase/common/images/Visa_small_icon.png", "Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", ENDITEM, 
//		"Url=https://{contentURL}/content/dam/delta-applications/complete-purchase/common/images/American_express_small_icon.png", "Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", ENDITEM, 
//		"Url=https://{contentURL}/content/dam/delta-applications/complete-purchase/common/images/NatureCons_Logo.png", "Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", ENDITEM, 
//		LAST);


	web_custom_request("getDashBrdData.action", 
		"URL=https://{URL}/custlogin/getDashBrdData.action", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t2489.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={}", 
		EXTRARES, 
		"Url=../content/dam/delta-applications/fresh-air-core/5.0.29/images/supergraphic-delta-mark_1600.svg", "Referer=https://{URL}/content/dam/delta-applications/fresh-air-core/5.0.29/css/fresh-air.css", ENDITEM, 
		LAST);

	web_reg_find("Text=\"dynamicbannerFlag\":true", "SaveCount=dynamicbannerFlag_count", LAST);
	
	web_url("confirmation.data.json", 
		"URL=https://{URL}/content/www/en_US/rsb/confirmation.data.json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}",
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	if(atoi(lr_eval_string("{dynamicbannerFlag_count}"))>0){
		PE_CKO_Banner();
	}
	
//	web_add_header("Origin", 
//		"https://{URL}");
//	
//	lr_start_transaction("%getpersonalizedContent%");
//	
//	web_custom_request("getpersonalizedContent", 
//		"URL=https://{URL}/personalization-api/getpersonalizedContent", 
//		"Method=POST", 
//		"Resource=0", 
//		"RecContentType=application/json", 
//		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", 
//		"Snapshot=t2976.inf", 
//		"Mode=HTML", 
//		"EncType=application/json", 
//		"Body={\"userdata\":{\"destination\":\"{Destination}\"},\"requestparam\":{\"campaignId\":\"rsb:confirmation\"}}", 
//		EXTRARES, 
//		LAST);
//
//	lr_end_transaction("%getpersonalizedContent%", LR_AUTO);
	
//	web_add_auto_header("CacheKey", 
//		"{cacheKey}");
//
//	web_add_auto_header("X-APP-CHANNEL", 
//		"RSB-Booking");
//
//	web_add_auto_header("appId", 
//		"CKO");
//
//	web_add_auto_header("channelId", 
//		"ECOM");
//
//	web_custom_request("loyaltyMileageInfo_2", 
//		"URL=https://{URL}/checkout/loyaltyMileageInfo", 
//		"Method=POST", 
//		"Resource=0", 
//		"RecContentType=application/json", 
//		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", 
//		"Snapshot=t2215.inf", 
//		"Mode=HTML", 
//		"EncType=application/json; charset=UTF-8", 
//		"Body={\"cartId\":\"{cartId}\"}", 
//		LAST);
//
//	web_revert_auto_header("CacheKey");
//
//	web_revert_auto_header("X-APP-CHANNEL");
//
//	web_revert_auto_header("appId");
//
//	web_revert_auto_header("channelId");
	
//	web_add_header("CacheKey", "{cacheKey}");
//	
//	web_add_header("appId", "CKO");
//
//	web_add_header("X-APP-CHANNEL", "RSB-Booking");	
//	web_add_header("channelId", "ECOM");
//	web_add_header("timeout", "40000");
//
//	web_add_header("Accept", "application/json");
//	web_add_header("Content-Type", "application/json; charset=utf-8");
//	
//	web_custom_request("tripTotal", 
//		"URL=https://{URL}/checkout/tripTotal", 
//		"Method=POST", 
//		"Resource=0", 
//		"RecContentType=application/json", 
//		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", 
//		"Snapshot=t965.inf", 
//		"Mode=HTML", 
//		"EncType=application/json; charset=UTF-8", 
//		"Body={\"amountOffPerPassenger\":\"\",\"cartId\":\"{cartId}\",\"milesOffPerPassenger\":\"\",\"offerId\":\"\"}", 
//		LAST);

//	web_add_header("CacheKey", "{cacheKey}");
	web_add_auto_header("Accept", "application/json");
	web_add_auto_header("Content-Type", "application/json; charset=utf-8");

	if(atoi(lr_eval_string("{carsSearch}"))==1) {	
		web_add_header("X-APP-CHANNEL", "RSB-Booking");	
		web_add_header("channelId", "ECOM");
		web_add_header("timeout", "40000");
		web_add_header("appId", "CKO");
		web_add_header("airlineCode", "DL");
		web_add_header("isMobile", "false");
		web_add_header("pageName", "ABC");
		web_add_header("Origin", "https://{URL}");
		
		lr_continue_on_error(1);
		
		web_custom_request("search", 
			"URL=https://{URL}/merchandize/cars/search", 
			"Method=POST", 
			"Resource=0", 
			"RecContentType=application/json", 
			"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", 
			"Snapshot=t3123.inf", 
			"Mode=HTML", 
			"EncType=application/json; charset=UTF-8", 
			"Body={\"requester\":{\"cartId\":\"{cartId}\",\"offerId\":\"\",\"offerItemId\":\"\",\"pnrNumber\":\"{PNR}\",\"requesterType\":\"CKO\",\"ticketNumber\":\"\"}}", 
			EXTRARES, 
			//"Url=/content/www/en_US/rsb/confirmation.data.json", "Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", ENDITEM, 
			LAST);
	
		lr_continue_on_error(0);
	}
	

	
//	web_add_header("CacheKey", "{cacheKey}");
//	
//	web_add_header("appId", "CKO");
//
//	web_add_header("X-APP-CHANNEL", "RSB-Booking");	
//	web_add_header("channelId", "ECOM");
//	web_add_header("timeout", "40000");
//	
//	web_custom_request("baggage", 
//		"URL=https://{URL}/checkout/baggage", 
//		"Method=POST", 
//		"Resource=0", 
//		"RecContentType=application/json", 
//		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", 
//		"Snapshot=t3221.inf", 
//		"Mode=HTML", 
//		"EncType=application/json; charset=UTF-8", 
//		"Body={\"cartId\":\"{cartId}\",\"channel\":\"MOB\",\"offerId\":\"11111\"}", 
//		EXTRARES, 
//		"Url=../content/dam/delta-applications/fresh-air-core/5.0.29/fonts/3955045D2CF71A4B6.woff2", "Referer=https://{URL}/content/dam/delta-applications/fresh-air-core/5.0.29/fonts/fresh-air-fonts.css", ENDITEM, 
//		LAST);

//	web_url("qat3-content.delta.com", 
//		"URL=https://{contentURL}/", 
//		"Resource=0", 
//		"RecContentType=text/html", 
//		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", 
//		"Snapshot=t3343.inf", 
//		"Mode=HTML", 
//		EXTRARES, 
//		"Url=/content/dam/delta-applications/complete-purchase/common/images/American_express_small_icon.png", "Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", ENDITEM, 
//		"Url=/content/dam/delta-tnt/homepage/hero/4/amex-beach-hero.jpg", "Referer=https://{URL}/complete-purchase", ENDITEM, 
//		"Url=/content/dam/delta-applications/complete-purchase/common/images/NatureCons_Logo.png", "Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", ENDITEM, 
//		LAST);

	web_add_header("Origin", 
		"https://{URL}");
	
	web_add_header("appId", 
		"CKO");

	web_add_header("CacheKey", 
		"{cacheKey}");

	web_add_header("X-APP-CHANNEL", 
		"RSB-Booking");

	web_add_header("channelId", 
		"ECOM");

	web_reg_save_param_json(
        "ParamName=getOfferTripCost",
        "QueryString=$.totalAmountDue.currency.amount",
        "Notfound=warning",
        "SEARCH_FILTERS",
        "Scope=Body",
        "LAST");
	
	web_custom_request("tripTotalForAllPax", 
		"URL=https://{URL}/checkout/tripTotalForAllPax", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={\"amountOffPerPassenger\":\"\",\"cartId\":\"{cartId}\",\"milesOffPerPassenger\":\"\",\"offerId\":\"\"}", 
		LAST);

	if(atoi(lr_eval_string("{analyticsFlow}"))>0){
		web_reg_find("Text=\"status\":\"SUCCESS\"", "SaveCount=smetricsSuccess_count", LAST);
		
		lr_start_transaction("%SMETRICS_tripTotalForAllPax%");
	
		web_custom_request("{currentPageFileURL}",
					"URL=https://smetrics.delta.com/b/ss/deltadev2/10/JS-2.3.0/s15227936139960?AQB=1&ndh=1&pf=1&callback=s_c_il[1].doPostbacks&et=1&t=29%2F6%2F2020%2011%3A28%3A51%203%20240&d.&nsid=0&jsonv=1&.d&mid=65999830347700170910129085401349202063&aid=2F878B688515BA89-40000B2B24264CA9&aamlh=7&ce=UTF-8&pageName=Booking%20Confirmation%20Page&g=https%3A%2F%2Fstga.delta.com%2Fcomplete-purchase%2Ftrip-summary%3FcacheKeySuffix%3D{cacheKey}%26cartId%3D{cartId}%26app%3Dsl-sho&cc=USD&purchaseID={PNR}{date_today_smetrics}&ch=Flight%20Checkout&server=stga&state=MN&zip=55122&events=purchase%2Cevent8%2Cevent218%2Cevent219%2Cevent33%2Cevent34%2Cevent35%2Cevent106&products=%3BRevenue-{randTripTypeString}-{Origin}-{Destination}%3B1%3B206.73%3Bevent8%3D10.10%7Cevent218%3D1%7Cevent219%3D1%2C%3Btri%3Aallianz%3Abasic%3B%3B%3Bevent33%3D1%7Cevent35%3D23.63&aamb=j8Odv6LonN4r3an7LhD3WZrU1bUpAkFkkiY1ncBR96t2PTI&l2=0062428668647&v4={Origin}&v5={Destination}&v6={Origin}-{Destination}&v7=revenue&v9=T&c16=us%3Aen&v16=delta.com&v17=cc%3A{ccTypeString}&v18=eagan&v20=us%3Aen&v23=Repeat&v24=USD&v26=2F878B688515BA89-40000B2B24264CA9&v37=MAIN&c42=%7Cweek%3A1%7Cmonth%3A1&c47=VisitorAPI%20Present&c48=codeversion%3A2.3.0%3A08072017&v57=United%20States&v60=A694C6B0D1AD10D11B1AAAA49270BA70&c61=https%3A%2F%2Fstga.delta.com%2Fcomplete-purchase%2Fconfirmation&v74=Phone%3A0-365px&v129=RSB&v130=n%7Cn&s=1366x768&c=24&j=1.6&v=N&k=Y&bw=1366&bh=657&mcorgid=F0E65E09512D2CC50A490D4D%40AdobeOrg&AQE=1", 
					"Method=GET", 
					"Resource=0", 
					"RecContentType=application/javascript; charset=utf-8", 
					"Referer=https://{URL}/", 
					"Snapshot=t10.inf", 
					"Mode=HTML", 
					LAST);
		
		if(atoi(lr_eval_string("{smetricsSuccess_count}"))<=0){
				lr_end_transaction("%SMETRICS_tripTotalForAllPax%", LR_FAIL);
				lr_error_message("SMETRICS FAILED FOR:\t%s,%s,%s,%s",lr_eval_string("{PNR}"),lr_eval_string("{firstPassengerFirstName}"),lr_eval_string("{firstPassengerLastName}"),lr_eval_string("{ccType}"));
		} else {
			lr_end_transaction("%SMETRICS_tripTotalForAllPax%", LR_AUTO);
		}		
	}
	
	web_add_header("CacheKey", "{cacheKey}");
	web_add_header("Accept", "application/json");
	web_add_header("Content-Type", "application/json; charset=utf-8");
	
	web_add_header("X-APP-CHANNEL", "RSB-Booking");	
	web_add_header("channelId", "ECOM");
	web_add_header("timeout", "40000");
	web_add_header("appId", "CKO");
	web_add_header("Origin", "https://{URL}");
	
	lr_continue_on_error(1);
	
	web_custom_request("saveConsentDetails", 
		"URL=https://{URL}/checkout/saveConsentDetails?policyConfirmationInd=Y", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t1943.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={}", 
		EXTRARES, 
		LAST);
	
	lr_continue_on_error(0);
	
//	web_add_header("CacheKey", "{cacheKey}");
//	
//	web_add_header("appId", "CKO");
//
//	web_add_header("X-APP-CHANNEL", "RSB-Booking");	
//	web_add_header("channelId", "ECOM");
//	web_add_header("timeout", "40000");
//
//	web_add_header("Accept", "application/json");
//	web_add_header("Content-Type", "application/json; charset=utf-8");
//	
//	web_custom_request("tripTotal_2", 
//		"URL=https://{URL}/checkout/tripTotal", 
//		"Method=POST", 
//		"Resource=0", 
//		"RecContentType=application/json", 
//		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", 
//		"Snapshot=t965.inf", 
//		"Mode=HTML", 
//		"EncType=application/json; charset=UTF-8", 
//		"Body={\"amountOffPerPassenger\":\"\",\"cartId\":\"{cartId}\",\"milesOffPerPassenger\":\"\",\"offerId\":\"\"}", 
//		LAST);

	web_add_header("appId", 
		"cus");

	web_add_header("channelId", 
		"ecom");

	web_custom_request("inline-enrollment-config.json", 
		"URL=https://{URL}/content/dam/delta-applications/inline-enrollment/1.3.7/assets/json/inline-enrollment-config.json", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t1954.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=https://{contentURL}/content/dam/delta-tnt/homepage/hero/default/hero-image-1440x460.png", "Referer=https://{URL}/complete-purchase", ENDITEM, 
		LAST);

	web_custom_request("rewards-program.data.json", 
		"URL=https://{URL}/content/experience-fragments/delta/rsb/inline-enrollment-modal/rewards-program.data.json", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t2043.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("Origin", 
		"https://{URL}");

//	web_add_header("appId", 
//		"cus");
//
//	web_add_header("channelId", 
//		"ecom");
//
//	web_reg_save_param("applicantRequestTrackingId", "LB=applicantRequestTrackingId\":\"", "RB=\"", "Notfound=warning", LAST);
//
//	web_custom_request("getOffer", 
//		"URL=https://{URL}/customer/cardOffer/getOffer", 
//		"Method=POST", 
//		"Resource=0", 
//		"RecContentType=application/json", 
//		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", 
//		"Snapshot=t2275.inf", 
//		"Mode=HTML", 
//		"Body={\"businessIndicator\":\"CONSUMER\",\"currencyCode\":\"{C_currencyCode}\",\"currencySymbol\":\"{C_currencySymbol}\",\"customerRefId\":\"{customerRefId}\",\"pageId\":\"CNF\",\"tripCost\":\"{getOfferTripCost}\",\"customerData\":{\"firstName\":\"{firstPassengerFirstName}\",\"lastName\":\"{firstPassengerLastName}\",\"email\":\"test@delta.com\",\"phoneNumber\":\"6155675896\",\"address\":{\"addressLine1\":\"1500 Towerview Rd\",\"addressLine6\":\"\",\"addressLine4\":\"Eagan\",\"addressLine7\":\"MN\",\"addressLine8\":\"US\",\"addressLine9\":\""
//		"55122\",\"type\":\"H\"}}}", 
//		LAST);

//	web_add_header("appId", 
//		"cus");
//
//	web_add_header("channelId", 
//		"ecom");
//
//	web_reg_save_param("applicantRequestTrackingId", "LB=applicantRequestTrackingId\":\"", "RB=\"", "Notfound=warning", LAST);
//
//	web_custom_request("getOffer", 
//		"URL=https://{URL}/customer/cardOffer/getOffer", 
//		"Method=POST", 
//		"Resource=0", 
//		"RecContentType=application/json", 
//		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", 
//		"Snapshot=t2275.inf", 
//		"Mode=HTML", 
//		"Body={\"businessIndicator\":\"CONSUMER\",\"currencyCode\":\"{C_currencyCode}\",\"currencySymbol\":\"{C_currencySymbol}\",\"customerRefId\":\"{customerRefId}\",\"pageId\":\"CNF\",\"tripCost\":\"{getOfferTripCost}\",\"customerData\":{\"firstName\":\"{firstPassengerFirstName}\",\"lastName\":\"{firstPassengerLastName}\",\"email\":\"test@delta.com\",\"phoneNumber\":\"6155675896\",\"address\":{\"addressLine1\":\"1500 Towerview Rd\",\"addressLine6\":\"\",\"addressLine4\":\"Eagan\",\"addressLine7\":\"MN\",\"addressLine8\":\"US\",\"addressLine9\":\""
//		"55122\",\"type\":\"H\"}}}", 
//		LAST);
//	
//	web_revert_auto_header("Origin");

//	web_url("credit-offer-config.json", 
//		"URL=https://{URL}/content/dam/delta-applications/fab/1.0.19/assets/json/credit-offer-config.json", 
//		"Resource=0", 
//		"RecContentType=application/json", 
//		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", 
//		"Snapshot=t2236.inf", 
//		"Mode=HTML", 
//		LAST);
//
//	web_url("credit-offer-config.json", 
//		"URL=https://{URL}/content/dam/delta-applications/fab/1.2.1/assets/json/credit-offer-config.json", 
//		"Resource=0", 
//		"RecContentType=application/json", 
//		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", 
//		"Snapshot=t2236.inf", 
//		"Mode=HTML", 
//		LAST);
	web_custom_request("contentfragment.fabdata.json", 
		"URL=https://{URL}/content/www/en_US/rsb/fabzeus/gold/jcr:content/par/contentfragment.fabdata.json", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho",
		"Snapshot=t1559.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		EXTRARES, 
		LAST);

	web_add_header("appId", 
		"cus");

	web_add_header("channelId", 
		"ecom");

	//customerRefId is constant: acc51227-63cb-4dcb-bfd1-354bb85056e1
	web_custom_request("getOffer", 
		"URL=https://{URL}/customer/cardOffer/getOffer", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t37.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"businessIndicator\":\"CONSUMER\",\"currencyCode\":\"{C_currencyCode}\",\"currencySymbol\":\"{C_currencySymbol}\",\"customerRefId\":\"acc51227-63cb-4dcb-bfd1-354bb85056e1\",\"pageId\":\"TPS\",\"tripCost\":\"{getOfferTripCost}\"}", 
		LAST);
	
	web_add_header("appId", 
		"enrl");

	web_add_header("channelId", 
		"ecom");
	lr_start_transaction("%z_FAB_getOffer%");
	lr_start_transaction("%z_FAB_getOffer_Confirmation%");

	lr_start_transaction("%z_FAB_getOffer_REV%");
	lr_start_transaction("%z_FAB_getOffer_Confirmation_REV%");
		
	web_reg_find("Text=\"status\":\"SUCCESS\"", "SaveCount=getOffer_count",
		LAST);
	web_reg_save_param("errorMessage", "LB=\"message\":\"", "RB=\"", "Notfound=warning", LAST);
	
	web_custom_request("getOffer", 
		"URL=https://{URL}/enrollment/cardOffer/getOffer", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho",
		"Snapshot=t44.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"applicationType\":\"revenue\",\"bannerTemplateId\":\"G\",\"browserAreaText\":\"1280x913\",\"customerRefId\":\"{customerReferenceId}\",\"fromMobile\":false,\"ipDerivedPostalCode\":\"\",\"pageId\":\"trip-confirmation-rev\",\"privateBrowsing\":false,\"referringUrlText\":\"\",\"screenResolutionText\":\"1280x1024\",\"taxesAndFeesCost\":\"\",\"tripCost\":\"{getOfferTripCost}\",\"tripMilesCost\":\"0\"}", 
		EXTRARES, 
		LAST);

	if(atoi(lr_eval_string("{getOffer_count}"))<=0){
		lr_end_transaction("%z_FAB_getOffer%", LR_FAIL);
		lr_end_transaction("%z_FAB_getOffer_Confirmation%", LR_FAIL);

		lr_end_transaction("%z_FAB_getOffer_REV%", LR_FAIL);
		lr_end_transaction("%z_FAB_getOffer_Confirmation_REV%", LR_FAIL);
			
		lr_error_message("[REV] Get Offer not Loaded in Confirmation. Message: %s.", lr_eval_string("{errorMessage}"));
	} else {
		lr_end_transaction("%z_FAB_getOffer%", LR_AUTO);
		lr_end_transaction("%z_FAB_getOffer_Confirmation%", LR_AUTO);

		lr_end_transaction("%z_FAB_getOffer_REV%", LR_AUTO);
		lr_end_transaction("%z_FAB_getOffer_Confirmation_REV%", LR_AUTO);		
	}	
//	web_add_header("appId", 
//		"cus");
//
//	web_add_header("channelId", 
//		"ecom");
//
//	web_custom_request("acknowledgeOffer", 
//		"URL=https://{URL}/customer/cardOffer/acknowledgeOffer", 
//		"Method=POST", 
//		"Resource=0", 
//		"RecContentType=application/json", 
//		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", 
//		"Snapshot=t2687.inf", 
//		"Mode=HTML", 
//		"EncType=application/json", 
//		"Body={\"applicantRequestTrackingId\":\"{applicantRequestTrackingId}\"}", 
//		LAST);

	web_revert_auto_header("Origin");

//	if(atoi(lr_eval_string("{offerAPI_ON}"))>0){
//		web_add_header("X-OFFER-ROUTE", 
//			"SL-OFFER");
//	}
//	
//	web_custom_request("clearAccountableDocuments", 
//		"URL=https://{URL}/shop/clearAccountableDocuments", 
//		"Method=POST", 
//		"Resource=0", 
//		"RecContentType=application/json", 
//		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}",
//		"Snapshot=t51.inf", 
//		"Mode=HTML", 
//		"EncType=application/json; charset=utf-8", 
//		LAST);

//	web_add_header("X-APP-CHANNEL", 
//		"RSB-Booking");
//
//	web_add_header("appId", 
//		"CKO");
//
//	web_add_header("channelId", 
//		"ECOM");
//
//	web_add_header("paymentReferenceID", 
//		"{paymentReferenceId}");
//
//	web_custom_request("removeCVV", 
//		"URL=https://{URL}/checkout/removeCVV", 
//		"Method=DELETE", 
//		"Resource=0", 
//		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}",
//		"Snapshot=t52.inf", 
//		"Mode=HTML", 
//		EXTRARES, 
//		LAST);
	
	lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_13_CompletePurchase_{ccType}_{psd2Flag}"), LR_PASS);

	if(atoi(lr_eval_string("{analyticsFlow}"))>0){
		lr_save_string(lr_eval_string("{ccType}"), "paymentType");
		
		WriteFilePNR();
	}
	
	return 0;
}
