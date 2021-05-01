Paypal_CompletePurchase()
{
	int i;
	lr_think_time(5);
	
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
		"Body={\"cardDetails\":{\"billingAdr\":{\"addressLine1Text\":\"1500 towerview rd\",\"addressLine2Text\":\"\",\"cityLocalityName\":\"eagan\",\"countryCode\":\"US\",\"countrySubdivisionCode\":\"MN\",\"postalCode\":\"55122\",\"districtTownName\":\"\",\"id\":\"\",\"alias\":\"\",\"primary\":\"\",\"isPrimary\":\"\",\"areaTerritoryPrefecture\":null},\"cardHolderName\":{\"firstName\":\"Test\",\"lastName\":\"Tester\",\"middleInitialName\":null,\"prefix\":null,\"suffix\":null},\"cardType\":null,\""
		"expirationMonthNum\":null,\"expirationYearNum\":null,\"lastFourDigits\":null,\"paymentCardNum\":null,\"paymentCardSecurityCode\":null,\"paymentType\":\"payPal\",\"purchaseVrfyFlag\":false,\"alias\":null,\"alipayPaymentReferenceId\":null,\"formatInd\":null,\"paymentCardNetworkCode\":null,\"paymentVendorTransactionId\":null,\"savedFopId\":null,\"secureIdOnFOP\":null,\"uid\":null,\"taxFormId\":\"\",\"taxFormNumber\":\"\"},\"paymentType\":\"payPal\",\"afopFields\":[],\"rtbt\":{}}", 
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
	
	Paypal_LoginPage();
	Paypal_EnterUsername();
	Paypal_EnterPassword();
	/**************************************START OF COMPLETE PURCHASE **********************************************************************************/
	lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_13_CompletePurchase_{formOfPayment}"));

	web_add_header("paypal-client-metadata-id", 
		"{paypalPayload}");
	
	web_add_header("x-paypal-internal-euat", 
		"{paypal_internal_eaut}");

	web_add_header("x-app-name", "checkoutuinodeweb");

	web_add_header("content-type", "application/json");

	web_custom_request("graphql", 
		"URL=https://www.sandbox.paypal.com/graphql/", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.sandbox.paypal.com/webapps/hermes?flow=1-P&ulReturn=true&useraction=commit&token={paypalPayload}&country.x=US&locale.x=en_US", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body=[{\"operationName\":\"approveMemberPayment\",\"variables\":{\"token\":\"{paypalPayload}\",\"selectedAddressId\":\"\",\"preferredShippingAddressId\":\"\",\"selectedFundingOptionId\":\"BALANCEUSD\",\"secondaryFundingOptionIds\":[],\"preAuthorizationRequired\":false,\"fundingMethodType\":\"INSTANT\"},\"query\":\"mutation approveMemberPayment($token: String!, $selectedAddressId: String, $preferredShippingAddressId: String, $selectedFundingOptionId: String!, $preferredFundingOptionId: String,"
		" $secondaryFundingOptionIds: [String!], $selectedInstallmentOption: InstallmentsInput, $rewards: RewardsInput, $preAuthorizationRequired: Boolean, $fundingMethodType: FundingInstrumentMethodType, $shareAddressWithDonatee: Boolean) {\\n  approveMemberPayment(token: $token, selectedAddressId: $selectedAddressId, preferredShippingAddressId: $preferredShippingAddressId, primaryFundingOptionId: $selectedFundingOptionId, preferredFundingOptionId: $preferredFundingOptionId, secondaryFundingOptionIds: "
		"$secondaryFundingOptionIds, selectedInstallmentOption: $selectedInstallmentOption, rewards: $rewards, preAuthorizationRequired: $preAuthorizationRequired, fundingMethodType: $fundingMethodType, shareAddressWithDonatee: $shareAddressWithDonatee) {\\n    state\\n    buyer {\\n      userId\\n      __typename\\n    }\\n    cart {\\n      intent\\n      paymentId\\n      billingToken\\n      returnUrl {\\n        href\\n        __typename\\n      }\\n      state\\n      __typename\\n    }\\n    "
		"paymentContingencies {\\n      ...PaymentContingenciesFragment\\n      __typename\\n    }\\n    __typename\\n  }\\n}\\n\\nfragment PaymentContingenciesFragment on PaymentContingencies {\\n  confirmCreditCardCvvData {\\n    ...ConfirmCreditCardCvvFields\\n    __typename\\n  }\\n  sepaMandateAcceptanceNeeded {\\n    ...SepaMandateAcceptanceNeededFragment\\n    __typename\\n  }\\n  threeDomainSecure {\\n    ...ThreeDomainSecureFields\\n    __typename\\n  }\\n  needConsentForBankAccountInfoRetrieval "
		"{\\n    encryptedId\\n    __typename\\n  }\\n  needRealTimeBalanceForBankAccount {\\n    encryptedId\\n    __typename\\n  }\\n  __typename\\n}\\n\\nfragment ConfirmCreditCardCvvFields on ConfirmCreditCardCvvContingency {\\n  encryptedId\\n  lastFourDigits\\n  type\\n  __typename\\n}\\n\\nfragment ThreeDomainSecureFields on ThreeDomainSecureContingency {\\n  redirectUrl {\\n    href\\n    __typename\\n  }\\n  status\\n  method\\n  parameter\\n  encryptedId\\n  experience\\n  requestParams {\\n    "
		"key\\n    value\\n    __typename\\n  }\\n  __typename\\n}\\n\\nfragment SepaMandateAcceptanceNeededFragment on BankAccount {\\n  id\\n  type\\n  accountNumber\\n  accountNumberShort\\n  bankIdentifierCode\\n  currencyCode\\n  beneficiaries {\\n    fullName\\n    __typename\\n  }\\n  billingAddress {\\n    city\\n    country\\n    state\\n    fullAddress\\n    __typename\\n  }\\n  issuer {\\n    name\\n    __typename\\n  }\\n  creditor {\\n    id\\n    name\\n    address {\\n      fullAddress\\n   "
		"   __typename\\n    }\\n    __typename\\n  }\\n  __typename\\n}\\n\"}]", 
		EXTRARES, 
		//"Url=https://www.paypalobjects.com/images/checkout/hermes/icon_ot_spin_lock_skinny.png", "Referer=https://www.paypalobjects.com/checkoutweb/release/hermione/css/Spinner~21833f8f.462dd1f6.css", ENDITEM, 
		LAST);
	
	web_add_header("Sec-Fetch-Site", 
		"cross-site");

	web_add_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Sec-Fetch-Dest", 
		"document");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");
	
	web_add_auto_header("Accept", "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9");
	
	web_url("onlinePaymentReturn", 
		"URL=https://{URL}/checkout/onlinePaymentReturn?afopType=payPal&CacheKey={cacheKey}&cartId={cartId}&offerId=null&token={paypalPayload}&PayerID={custID_Paypal}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://www.sandbox.paypal.com/webapps/hermes?flow=1-P&ulReturn=true&useraction=commit&token={paypalPayload}&country.x=US&locale.x=en_US", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);	
	
	web_revert_auto_header("Accept");

	web_url("bcdata.action", 
		"URL=https://{URL}/databroker/bcdata.action", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://stga.delta.com/complete-purchase/confirmation?redirect=onlinePay&cacheKeySuffix=5615bcea-2946-4615-b1d1-9f45bb29ac40&cartId=f2c828f3-4497-42d1-86f4-0723bbabc768", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		EXTRARES, 
		LAST);

	web_url("getdevicetype", 
		"URL=https://{URL}/complete-purchase/getdevicetype", 
		"Resource=0", 
		"Referer=https://stga.delta.com/complete-purchase/confirmation?redirect=onlinePay&cacheKeySuffix=5615bcea-2946-4615-b1d1-9f45bb29ac40&cartId=f2c828f3-4497-42d1-86f4-0723bbabc768", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);


	web_url("getdevicetype_2", 
		"URL=https://{URL}/complete-purchase/getdevicetype", 
		"Resource=0", 
		"Referer=https://stga.delta.com/complete-purchase/confirmation?redirect=onlinePay&cacheKeySuffix=5615bcea-2946-4615-b1d1-9f45bb29ac40&cartId=f2c828f3-4497-42d1-86f4-0723bbabc768", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_start_transaction("%RSB_Booking_Paypal%");
	

	web_add_auto_header("CacheKey", "{cacheKey}");

	web_add_header("pageName", 
		"CONFIRMATION");
	
	web_add_auto_header("Accept", "application/json");
//	web_add_auto_header("Content-Type", "application/json; charset=UTF-8");
	
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
	
	web_custom_request("confirmation", 
		"URL=https://{URL}/checkout/confirmation", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t1254.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={\"cartId\":\"{cartId}\",\"channel\":\"ECOM\"}", 
		EXTRARES, 
		//"Url=../content/www/omniui-payment/payment.omniui.json", "Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}", ENDITEM,  
		LAST);

	web_revert_auto_header("CacheKey");
	web_revert_auto_header("Content-Type");
	web_revert_auto_header("Accept");
	
	if(strstr(lr_eval_string("{redirectUrl}"), "merchantacsstag.cardinalcommerce.com")!=NULL){
		lr_output_message("RSB Checkout 3DS Card: \tCartID:%s\tCacheKey:%s\tCCNum:%s\tCCType:%s",lr_eval_string("{cartId}"), lr_eval_string("{cacheKey}"),lr_eval_string("{ccNum}"), lr_eval_string("{ccType}"));
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_13_CompletePurchase_{formOfPayment}"), LR_FAIL);
		lr_end_transaction("%RSB_Booking_Paypal%", LR_FAIL);
		
		lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);
		
	}
		
	if(atoi(lr_eval_string("{fareChanged_count}"))>0){
		lr_output_message("Fare Changed for \tORIGIN\t%s\tDESTINATION\t%s",lr_eval_string("{Origin}"),lr_eval_string("{Destination}"));
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_13_CompletePurchase_{formOfPayment}"), LR_AUTO);	
		lr_end_transaction("%RSB_Booking_Paypal%", LR_AUTO);

		lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);		
	}
		
	
	if(strlen(lr_eval_string("{PNR}"))<=0)
	{
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_13_CompletePurchase_{formOfPayment}"), LR_FAIL);
		
		if(strlen(lr_eval_string("{checkOutError}"))>0){
			lr_error_message("RSB Save Passenger Error: \t%s",lr_eval_string("{checkOutError}"));
			lr_error_message("RSB Checkout Error Key [Save Passenger was also Failed]: \t%s\tCartID:%s\tCacheKey:%s",lr_eval_string("{errorKey}"),lr_eval_string("{cartId}"),lr_eval_string("{cacheKey}"));
		} else if (strlen(lr_eval_string("{errorKey}"))>0){
			lr_error_message("RSB Checkout Error Key for Paypal: \t%s\tCartID:%s\tCacheKey:%s",lr_eval_string("{errorKey}"),lr_eval_string("{cartId}"), lr_eval_string("{cacheKey}"));
		}
		
		lr_end_transaction("%RSB_Booking_Paypal%", LR_FAIL);		
		lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);	
		
	}
	
	lr_end_transaction("%RSB_Booking_Paypal%", LR_AUTO);
	lr_save_datetime("%c %Z",DATE_NOW,"PNRCreationDate");
	//lr_error_message("PNR:\t%s,%s,%s,%s,REVENUE",lr_eval_string("{PNR}"),lr_eval_string("{firstPassengerFirstName}"),lr_eval_string("{firstPassengerLastName}"),lr_eval_string("{formOfPayment}"));
	
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


	web_reg_find("Text=\"status\":\"SUCCESS\"", "SaveCount=smetricsSuccess_count", LAST);
	
	lr_start_transaction("%SMETRICS_tripTotalForAllPax%");

	web_custom_request("{currentPageFileURL}",
				"URL=https://smetrics.delta.com/b/ss/deltadev2/10/JS-2.3.0/s9579494271090?AQB=1&ndh=1&pf=1&callback=s_c_il[1].doPostbacks&et=1&t=4%2F7%2F2020%2013%3A58%3A34%202%20240&d.&nsid=0&jsonv=1&.d&sdid=7C3CEF5EBC73BBAB-7BBC1938C04C5776&mid=65999830347700170910129085401349202063&aid=2F878B688515BA89-40000B2B24264CA9&aamlh=7&ce=UTF-8&pageName=Booking%20Confirmation%20Page&g=https%3A%2F%2Fstga.delta.com%2Fcomplete-purchase%2Fconfirmation%3Fredirect%3DonlinePay%26cacheKeySuffix%3D{cacheKey}%26cartId%3D{cartId}&r=https%3A%2F%2Fwww.sandbox.paypal.com%2Fwebapps%2Fhermes%3Fflow%3D1-P%26ulReturn%3Dtrue%26useraction%3Dcommit%26token%3D{paypalPayload}%26country.x%3DUS%26locale.x%3Den_US&cc=USD&purchaseID={PNR}{date_today_smetrics}&ch=Flight%20Checkout&server=stga&v0=REF%7Cwww.sandbox.paypal.com&state=MN&zip=55122&events=purchase%2Cevent8%2Cevent218%2Cevent219%2Cevent106%2Cevent255&products=%3BRevenue-{randTripTypeString}-{Origin}-{Destination}%3B1%3B203.10%3Bevent8%3D10.10%7Cevent218%3D1%7Cevent219%3D1&aamb=j8Odv6LonN4r3an7LhD3WZrU1bUpAkFkkiY1ncBR96t2PTI&v2=Referrers&l2=0062428641921&v4=ATL&v5=MSP&v6={Origin}-{Destination}&v7=revenue&v9=T&c16=us%3Aen&v16=delta.com&v17=payPal&v18=eagan&v20=us%3Aen&v23=Repeat&v24=USD&v26=2F878B688515BA89-40000B2B24264CA9&v37=MAIN&c42=%7Cweek%3A1%7Cmonth%3A1&c47=VisitorAPI%20Present&c48=codeversion%3A2.3.0%3A08072017&v56=www.sandbox.paypal.com&v57=United%20States&c61=https%3A%2F%2Fstga.delta.com%2Fcomplete-purchase%2Fconfirmation&v74=Desktop%3A1200-1399px&v129=RSB&v130=n%7Cn&c.&a.&activitymap.&page=Booking%20Verify%20and%20Purchase&link=COMPLETE%20PURCHASE&region=BODY&pageIDType=1&.activitymap&.a&.c&s=1366x768&c=24&j=1.6&v=N&k=Y&bw=1366&bh=657&mcorgid=F0E65E09512D2CC50A490D4D%40AdobeOrg&AQE=1", 
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
	
	lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_13_CompletePurchase_{formOfPayment}"), LR_PASS);

	lr_save_string(lr_eval_string("{formOfPayment}"), "paymentType");
	WriteFilePNR();
	return 0;
}
