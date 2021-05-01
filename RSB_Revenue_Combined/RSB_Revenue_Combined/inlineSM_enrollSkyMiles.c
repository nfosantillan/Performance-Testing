inlineSM_enrollSkyMiles()
{
	web_add_header("appId", "cus");
	web_add_header("channelId", "ecom");

	web_reg_save_param("c_smNumber", "LB=\"smNumber\":\"", "RB=\"", "NotFound=Warning", "Search=Body", LAST);
	web_reg_save_param("c_loginTokenId", "LB=\"loginTokenId\":\"", "RB=\"", "NotFound=Warning", "Search=Body", LAST);
	web_reg_save_param("ErrorMsgEnroll","LB=errors\":[{","RB=]","Notfound=warning",LAST);
	web_reg_find("Text=\"status\":\"SUCCESS\"", "SaveCount=enrollInline_success", LAST);
	
	lr_think_time(3);
	lr_start_transaction("%InlineSkymilesEnrollment_CompleteEnrollment%");
	lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_15_InlineSM_3a_enrollInline"));
	
	web_custom_request("enrollInline", 
		"URL=https://{URL}/customer/enrollInline", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"customerRefId\":\"{customerRefId}\",\"earnedMiles\":{earnedMiles},\"inputEnrollmentData\":{\"emailAddress\":{\"emailAddress\":\"{c_customerEmailAddress}\"},\"emailPreferences\":{\"isFareSaleSelected\":true,\"isPartnerOfferSelected\":true,\"isSMPromotionSelected\":true,\"isSMStatementSelected\":true,\"isTravelNewsSelected\":true},\"enrollmentType\":\"enrollInline\",\"isGDPRConsent\":true,\"originalApp\":\"checkout\",\"tlMaskInfo_password\":\"Delta999\",\"phoneInfo\":{\""
		"countryCode\":\"1_US\",\"deviceType\":\"C\",\"phoneNumber\":\"{c_phoneNumber}\"},\"saveFOPFlag\":\"false\",\"securityQuestion1\":{\"sqNumber\":4,\"tlMaskInfo_sqText\":\"Berto\"},\"securityQuestion2\":{\"sqNumber\":2,\"tlMaskInfo_sqText\":\"Awaw\"},\"username\":\"{firstPassengerFirstName}{firstPassengerLastName}\"},\"paymentRefId\":\"{paymentRefId}\",\"recordLocator\":\"{PNR}\"}", 
		LAST);

//	if((atoi(lr_eval_string("{enrollInline_success}")) > 0) && (strlen(lr_eval_string("{c_smNumber}")) != 0)){
	if(strlen(lr_eval_string("{c_smNumber}")) != 0){
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_15_InlineSM_3a_enrollInline"), LR_PASS);
	} else {
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_15_InlineSM_3a_enrollInline"), LR_FAIL);
		lr_end_transaction("%InlineSkymilesEnrollment_CompleteEnrollment%", LR_FAIL);
		lr_error_message("RSB_Revenue_%s_15_InlineSM_3a_enrollInline: Enroll Failed: %s",lr_eval_string("{RandTripType}"),lr_eval_string("{ErrorMsgEnroll}"));
		lr_exit(LR_EXIT_ITERATION_AND_CONTINUE,LR_AUTO);
	}
	
	web_add_header("Origin", "https://{URL}");

	web_reg_find("Text=\"isLoggedIn\":true", "SaveCount=loginCustomer_success", LAST);
	web_reg_save_param("ErrorMsg","LB=errors\":[{","RB=]","Notfound=warning",LAST);
	
	lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_15_InlineSM_3b_loginCustomerAfterEnrollment"));
	
	web_custom_request("loginCustomer", 
		"URL=https://{URL}/login/login/loginCustomer", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={\"tokenId\":\"{c_loginTokenId}\",\"fromApp\":\"Enrl\",\"refreshURL\":\"\"}", 
		LAST);

	if(atoi(lr_eval_string("{loginCustomer_success}")) > 0){
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_15_InlineSM_3b_loginCustomerAfterEnrollment"), LR_PASS);
	} else {
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_15_InlineSM_3b_loginCustomerAfterEnrollment"), LR_FAIL);
		lr_end_transaction("%InlineSkymilesEnrollment_CompleteEnrollment%", LR_FAIL);
		lr_error_message("RSB_Revenue_%s_15_InlineSM_3b_loginCustomerAfterEnrollment: LogIn Failed for %s,%s",lr_eval_string("{RandTripType}"),lr_eval_string("{c_smNumber}"),lr_eval_string("{ErrorMsg}"));
		lr_exit(LR_EXIT_ITERATION_AND_CONTINUE,LR_AUTO);
	}
	
	//web_reg_find("Text=Booking : Delta Air Lines", "SaveCount=returnToConfirmation", LAST);
	web_reg_find("Text=Booking", "SaveCount=returnToConfirmation", LAST);
	web_add_header("Upgrade-Insecure-Requests", "1");

	lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_15_InlineSM_3c_returnToConfirmationPage"));
	
	web_url("confirmation", 
		"URL=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}&inlineEnroll=SUCCESS&inlineMiles={earnedMiles}", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		EXTRARES, 
		LAST);

	if(atoi(lr_eval_string("{returnToConfirmation}")) > 0){
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_15_InlineSM_3c_returnToConfirmationPage"), LR_PASS);
	} else {
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_15_InlineSM_3c_returnToConfirmationPage"), LR_FAIL);
		lr_end_transaction("%InlineSkymilesEnrollment_CompleteEnrollment%", LR_FAIL);
		lr_exit(LR_EXIT_ITERATION_AND_CONTINUE,LR_AUTO);
	}
	
	web_add_auto_header("X-Requested-With", "XMLHttpRequest");

	web_url("getClosestDeltaAirportCode", 
		"URL=https://{URL}/pref/geoLocationService/getClosestDeltaAirportCode", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}&inlineEnroll=SUCCESS&inlineMiles={earnedMiles}", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	web_url("bcdata.action", 
		"URL=https://{URL}/databroker/bcdata.action", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}&inlineEnroll=SUCCESS&inlineMiles={earnedMiles}", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	web_revert_auto_header("X-Requested-With");

	web_url("getdevicetype", 
		"URL=https://{URL}/complete-purchase/getdevicetype", 
		"Resource=0", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}&inlineEnroll=SUCCESS&inlineMiles={earnedMiles}", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	web_url("getdevicetype_2", 
		"URL=https://{URL}/complete-purchase/getdevicetype", 
		"Resource=0", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}&inlineEnroll=SUCCESS&inlineMiles={earnedMiles}", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("CacheKey", "{cacheKey}");
	web_add_header("Origin", "https://{URL}");
	web_add_header("X-APP-CHANNEL", "RSB-Booking");
	web_add_header("appId", "CKO");
	web_add_header("channelId", "ECOM");
	web_add_header("pageName", "CONFIRMATION");

	web_custom_request("confirmation_2", 
		"URL=https://{URL}/checkout/confirmation", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}&inlineEnroll=SUCCESS&inlineMiles={earnedMiles}", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={\"cartId\":\"{cartId}\",\"channel\":\"ECOM\"}", 
		LAST);

	web_url("getdevicetype_3", 
		"URL=https://{URL}/complete-purchase/getdevicetype", 
		"Resource=0", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}&inlineEnroll=SUCCESS&inlineMiles={earnedMiles}", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("retrieveSearch", 
		"URL=https://{URL}/prefill/retrieveSearch?searchType=RecentSearchesJSON", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}&inlineEnroll=SUCCESS&inlineMiles={earnedMiles}", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		LAST);

	web_custom_request("getDashBrdData", 
		"URL=https://{URL}/login/login/getDashBrdData", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}&inlineEnroll=SUCCESS&inlineMiles={earnedMiles}", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={}", 
		EXTRARES, 
		LAST);

	web_revert_auto_header("Origin");
	
	web_add_header("CacheKey", "{cacheKey}");
	web_add_auto_header("Origin", "https://{URL}");
	web_add_header("X-APP-CHANNEL", "RSB-Booking");
	web_add_header("appId", "CKO");
	web_add_header("channelId", "ECOM");

	web_custom_request("tripTotalForAllPax", 
		"URL=https://{URL}/checkout/tripTotalForAllPax", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}&inlineEnroll=SUCCESS&inlineMiles={earnedMiles}", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={\"amountOffPerPassenger\":\"\",\"cartId\":\"{cartId}\",\"milesOffPerPassenger\":\"\",\"offerId\":\"\"}", 
		EXTRARES, 
		LAST);

	web_custom_request("getpersonalizedContent", 
		"URL=https://{URL}/personalization-api/getpersonalizedContent", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}&inlineEnroll=SUCCESS&inlineMiles={earnedMiles}", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"userdata\":{\"destination\":\"MSP\"},\"requestparam\":{\"campaignId\":\"rsb:confirmation\"}}", 
		LAST);

	web_add_auto_header("CacheKey", "{cacheKey}");
	web_add_auto_header("X-APP-CHANNEL", "RSB-Booking");
	web_add_auto_header("appId", "CKO");
	web_add_auto_header("channelId", "ECOM");

	web_custom_request("tripTotalForAllPax_2", 
		"URL=https://{URL}/checkout/tripTotalForAllPax", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}&inlineEnroll=SUCCESS&inlineMiles={earnedMiles}", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={\"amountOffPerPassenger\":\"\",\"cartId\":\"{cartId}\",\"milesOffPerPassenger\":\"\",\"offerId\":\"\"}", 
		LAST);

	web_custom_request("loyaltyMileageInfo", 
		"URL=https://{URL}/checkout/loyaltyMileageInfo", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}&inlineEnroll=SUCCESS&inlineMiles={earnedMiles}", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={\"cartId\":\"{cartId}\",\"loyaltyMileageInfoIndicator\":false}", 
		LAST);

	web_custom_request("sendEmailAfterConfirmation", 
		"URL=https://{URL}/checkout/sendEmailAfterConfirmation?RecordLocator={PNR}", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}&inlineEnroll=SUCCESS&inlineMiles={earnedMiles}", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={}", 
		LAST);
///*
	if(atoi(lr_eval_string("{carsSearch}"))==1) {	
		web_add_header("airlineCode", "DL");
		web_add_header("isMobile", "false");
		web_add_header("pageName", "ABC");
	
		lr_continue_on_error(1);
		web_custom_request("search", 
			"URL=https://{URL}/merchandize/cars/search", 
			"Method=POST", 
			"Resource=0", 
			"RecContentType=application/json", 
			"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}&inlineEnroll=SUCCESS&inlineMiles={earnedMiles}", 
			"Snapshot=t26.inf", 
			"Mode=HTML", 
			"EncType=application/json; charset=UTF-8", 
			"Body={\"requester\":{\"cartId\":\"{cartId}\",\"offerId\":\"\",\"offerItemId\":\"\",\"pnrNumber\":\"{PNR}\",\"requesterType\":\"CKO\",\"ticketNumber\":\"\"}}", 
			LAST);
	
		lr_continue_on_error(0);
	}
	web_revert_auto_header("CacheKey");
	web_revert_auto_header("X-APP-CHANNEL");
	web_revert_auto_header("appId");
	web_revert_auto_header("channelId");

	web_add_header("Content-Type", "application/x-www-form-urlencoded");
	web_add_header("Accept-Encoding", "gzip, deflate, br");
	web_add_header("Accept-Language", "en-US,en;q=0.9");
	
	web_submit_data("trackerData",
		"Action=https://{URL}/myaccount/tracker/trackerData", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}&inlineEnroll=SUCCESS&inlineMiles={earnedMiles}", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=skymilesNbr", "Value={c_smNumber}", ENDITEM, 
		LAST);

	web_add_header("Content-Type", "application/x-www-form-urlencoded");
	web_add_header("Accept-Encoding", "gzip, deflate, br");
	web_add_header("Accept-Language", "en-US,en;q=0.9");
	web_add_header("Connection", "keep-alive");
	
	web_submit_data("todaysTrip", 
		"Action=https://{URL}/myaccount/trip/todaysTrip", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}&inlineEnroll=SUCCESS&inlineMiles={earnedMiles}", 
		"Snapshot=t28.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=skymilesNbr", "Value={c_smNumber}", ENDITEM, 
		"Name=nmbrOfTrips", "Value=1", ENDITEM, 
		LAST);
//*/
	web_custom_request("getSavedSearchList.action", 
		"URL=https://{URL}/air-shopping/getSavedSearchList.action", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}&inlineEnroll=SUCCESS&inlineMiles={earnedMiles}", 
		"Snapshot=t29.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={\"customerId\":\"000{c_smNumber}\"}", 
		EXTRARES, 
		LAST);

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

	//customerRefId is constant: acc51227-63cb-4dcb-bfd1-354bb85056e1
//	web_custom_request("getOffer", 
//		"URL=https://{URL}/customer/cardOffer/getOffer", 
//		"Method=POST", 
//		"Resource=0", 
//		"RecContentType=application/json", 
//		"Referer=https://{URL}/complete-purchase/trip-summary?cacheKeySuffix={cacheKey}&cartId={cartId}&app=sl-sho", 
//		"Snapshot=t37.inf", 
//		"Mode=HTML", 
//		"EncType=application/json", 
//		"Body={\"businessIndicator\":\"CONSUMER\",\"currencyCode\":\"{C_currencyCode}\",\"currencySymbol\":\"{C_currencySymbol}\",\"customerRefId\":\"acc51227-63cb-4dcb-bfd1-354bb85056e1\",\"pageId\":\"TPS\",\"tripCost\":\"{oldTripCost}\"}", 
//		LAST);
	
	lr_start_transaction("%z_FAB_getOffer%");
	lr_start_transaction("%z_FAB_getOffer_Enrollment%");

	lr_start_transaction("%z_FAB_getOffer_REV%");
	lr_start_transaction("%z_FAB_getOffer_Enrollment_REV%");
	
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
		"Body={\"applicationType\":\"revenue\",\"bannerTemplateId\":\"G\",\"browserAreaText\":\"1280x913\",\"customerRefId\":\"{customerReferenceId}\",\"fromMobile\":false,\"ipDerivedPostalCode\":\"\",\"loyaltyMemberId\":\"{c_smNumber}\",\"pageId\":\"trip-confirmation-rev\",\"privateBrowsing\":false,\"referringUrlText\":\"\",\"screenResolutionText\":\"1280x1024\",\"taxesAndFeesCost\":\"\",\"tripCost\":\"{getOfferTripCost}\",\"tripMilesCost\":\"0\"}",
		EXTRARES, 
		LAST);

	if(atoi(lr_eval_string("{getOffer_count}"))<=0){
		lr_end_transaction("%z_FAB_getOffer%", LR_FAIL);
		lr_end_transaction("%z_FAB_getOffer_Enrollment%", LR_FAIL);

		lr_end_transaction("%z_FAB_getOffer_REV%", LR_FAIL);
		lr_end_transaction("%z_FAB_getOffer_Enrollment_REV%", LR_FAIL);
		
		lr_error_message("[REV] Get Offer not Loaded in Enrollment for %s. Message: %s.", lr_eval_string("{c_smNumber}"),lr_eval_string("{errorMessage}"));
	} else {
		lr_end_transaction("%z_FAB_getOffer%", LR_AUTO);
		lr_end_transaction("%z_FAB_getOffer_Enrollment%", LR_AUTO);

		lr_end_transaction("%z_FAB_getOffer_REV%", LR_AUTO);
		lr_end_transaction("%z_FAB_getOffer_Enrollment_REV%", LR_AUTO);		
	}	
	
//	web_add_auto_header("appId", "cus");
//	web_add_auto_header("channelId", "ecom");
//
////	web_reg_save_param("c_applicantRequestTrackingId1", "LB=applicantRequestTrackingId\":\"", "RB=\"", "NotFound=Warning", LAST);
//	
//	web_custom_request("getOffer", 
//		"URL=https://{URL}/customer/cardOffer/getOffer", 
//		"Method=POST", 
//		"Resource=0", 
//		"RecContentType=application/json", 
//		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}&inlineEnroll=SUCCESS&inlineMiles={earnedMiles}", 
//		"Snapshot=t31.inf", 
//		"Mode=HTML", 
//		"EncType=application/json", 
//		"Body={\"businessIndicator\":\"CONSUMER\",\"currencyCode\":\"{C_currencyCode}\",\"currencySymbol\":\"{C_currencySymbol}\",\"customerRefId\":\"{customerRefId}\",\"pageId\":\"CNF\",\"tripCost\":\"476.60\",\"customerData\":{\"firstName\":\"Jhun\",\"lastName\":\"Doe\",\"email\":\"test@delta.com\",\"phoneNumber\":\"{c_phoneNumber}\",\"address\":{\"addressLine1\":\"123 Address\",\"addressLine6\":\"\",\"addressLine4\":\"SCHENECTADY\",\"addressLine7\":\"NY\",\"addressLine8\":\"US\",\"addressLine9\":\""
//		"12345\",\"type\":\"H\"}}}", 
//		LAST);
//
////	web_reg_save_param("c_applicantRequestTrackingId2", "LB=applicantRequestTrackingId\":\"", "RB=\"", "NotFound=Warning", LAST);
//	
//	web_custom_request("getOffer_2", 
//		"URL=https://{URL}/customer/cardOffer/getOffer", 
//		"Method=POST", 
//		"Resource=0", 
//		"RecContentType=application/json", 
//		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}&inlineEnroll=SUCCESS&inlineMiles={earnedMiles}", 
//		"Snapshot=t32.inf", 
//		"Mode=HTML", 
//		"EncType=application/json", 
//		"Body={\"businessIndicator\":\"CONSUMER\",\"currencyCode\":\"{C_currencyCode}\",\"currencySymbol\":\"{C_currencySymbol}\",\"customerRefId\":\"{customerRefId}\",\"pageId\":\"CNF\",\"tripCost\":\"476.60\",\"customerData\":{\"firstName\":\"Jhun\",\"lastName\":\"Doe\",\"email\":\"test@delta.com\",\"phoneNumber\":\"{c_phoneNumber}\",\"address\":{\"addressLine1\":\"123 Address\",\"addressLine6\":\"\",\"addressLine4\":\"SCHENECTADY\",\"addressLine7\":\"NY\",\"addressLine8\":\"US\",\"addressLine9\":\""
//		"12345\",\"type\":\"H\"}}}", 
//		LAST);

	web_revert_auto_header("appId");
	web_revert_auto_header("channelId");

	web_custom_request("getDashBrdData_2", 
		"URL=https://{URL}/login/login/getDashBrdData", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}&inlineEnroll=SUCCESS&inlineMiles={earnedMiles}", 
		"Snapshot=t33.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={}", 
		LAST);

//	web_add_header("appId", "cus");
//	web_add_header("channelId", "ecom");
//
//	web_custom_request("acknowledgeOffer", 
//		"URL=https://{URL}/customer/cardOffer/acknowledgeOffer", 
//		"Method=POST", 
//		"Resource=0", 
//		"RecContentType=application/json", 
//		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}&inlineEnroll=SUCCESS&inlineMiles={earnedMiles}", 
//		"Snapshot=t39.inf", 
//		"Mode=HTML", 
//		"EncType=application/json", 
//		"Body={\"applicantRequestTrackingId\":\"{c_applicantRequestTrackingId}\"}", 
//		LAST);

	lr_end_transaction("%InlineSkymilesEnrollment_CompleteEnrollment%", LR_PASS);

	Logout();
	
	return 0;
}
