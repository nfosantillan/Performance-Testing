CarPurchase()
{
	lr_think_time(5);
	
	web_reg_find("Text=Car Search Result : Delta AirLines", "Savecount=carSearchPage",
		LAST);

	web_add_header("Upgrade-Insecure-Requests", "1");

	
	lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_14_ViewAllCars"));

	web_submit_data("shopMerchandiseCarAction.action", 
		"Action=https://{URL}/merch/shopMerchandiseCarAction.action", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t3098.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=currencyCode", "Value=", ENDITEM, 
		"Name=vendorId", "Value=", ENDITEM, 
		"Name=confirmationNo", "Value={PNR}", ENDITEM, 
		"Name=firstName", "Value={firstPassengerFirstName}", ENDITEM, 
		"Name=lastName", "Value={firstPassengerLastName}", ENDITEM, 
		EXTRARES, 
		"Url=../pref/geoLocationService/getClosestDeltaAirportCode", ENDITEM, 
		"Url=../databroker/bcdata.action", ENDITEM, 
		"Url=https://{contentURL}/etc/designs/delta/images/site_sprite.png", "Referer=https://{contentURL}/content/dam/delta-applications/css/sitewide/v5.12.0/swr.css", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/merch/photography/wifi_interstitial.jpg", "Referer=https://{contentURL}/content/dam/delta-applications/css/merch/v5.12.0/carResults.css", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/merch/forms/bg_form_texture.jpg", "Referer=https://{contentURL}/content/dam/delta-applications/css/merch/v5.12.0/carResults.css", ENDITEM, 
		"Url=https://{contentURL}/etc/designs/delta/images/texture-light.png", "Referer=https://{contentURL}/content/dam/delta-applications/css/sitewide/v5.12.0/swr.css", ENDITEM, 
		"Url=https://{contentURL}/dlhome/current/delta/sitewide/json/errorMessages/jQuery.validator.messages.js", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/fresh-air-core/20.3.0/images/supergraphic-delta-mark_1600.svg", "Referer=https://{contentURL}/content/dam/delta-applications/fresh-air-core/20.3.0/css/fresh-air-legacy.css", ENDITEM, 
		"Url=../prefill/retrieveSearch?searchType=RecentSearchesJSON", ENDITEM, 
		"Url=../content/dam/delta-applications/fresh-air-core/20.3.0/fonts/icomoon.woff", "Referer=https://{URL}/content/dam/delta-applications/fresh-air-core/20.3.0/fonts/fresh-air-fonts.css", ENDITEM, 
		"Url=../content/dam/delta-applications/fresh-air-core/20.3.0/fonts/A32A3E152E391B379.woff2", "Referer=https://{URL}/content/dam/delta-applications/fresh-air-core/20.3.0/fonts/fresh-air-fonts.css", ENDITEM, 
		"Url=../content/dam/delta-applications/fresh-air-core/20.3.0/fonts/3955045D2CF71A4B6.woff2", "Referer=https://{URL}/content/dam/delta-applications/fresh-air-core/20.3.0/fonts/fresh-air-fonts.css", ENDITEM, 
		"Url=../content/dam/delta-applications/fresh-air-core/20.3.0/fonts/AABA9C13AF9C5C638.woff2", "Referer=https://{URL}/content/dam/delta-applications/fresh-air-core/20.3.0/fonts/fresh-air-fonts.css", ENDITEM, 
		"Url=../content/dam/delta-applications/fresh-air-core/20.3.0/fonts/CB8837CA379681FED.woff2", "Referer=https://{URL}/content/dam/delta-applications/fresh-air-core/20.3.0/fonts/fresh-air-fonts.css", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/merch/icons/tick-mark-01.png", "Referer=https://{contentURL}/content/dam/delta-applications/css/merch/v5.12.0/carResults.css", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/merch/car/rentalCarType.jpg", "Referer=https://{contentURL}/content/dam/delta-applications/css/merch/v5.12.0/carResults.css", ENDITEM, 
		"Url=https://{contentURL}/etc/designs/delta/images/ui-icons_222222_256x240.png", "Referer=https://{contentURL}/content/dam/delta-applications/css/sitewide/v5.12.0/swr.css", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/merch/car/EHI/vendor/ZE_120x40.jpg", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/merch/car/EHI/vendor/AL_120x40.jpg", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/merch/car/EHI/vendor/ET_120x40.jpg", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/merch/car/EHI/vendor/ZL_120x40.jpg", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/merch/car/EHI/vendor/ZR_120x40.jpg", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/merch/car/EHI/vendor/ZT_120x40.jpg", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/merch/car/EHI/carType/IC170x80.jpg", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/merch/car/EHI/carType/FC170x80.jpg", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/merch/car/EHI/carType/EC170x80.jpg", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/merch/car/EHI/carType/LC170x80.jpg", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta_homepage_redesign/hpr_optimized_images/social_icons/Twitter-icon-LG.svg", "Referer=https://{contentURL}/content/dam/delta-applications/fresh-air-core/20.3.0/css/fresh-air-legacy.css", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta_homepage_redesign/hpr_optimized_images/social_icons/Facebook-icon-LG.svg", "Referer=https://{contentURL}/content/dam/delta-applications/fresh-air-core/20.3.0/css/fresh-air-legacy.css", ENDITEM, 
		"Url=../content/dam/delta-applications/fresh-air-core/20.3.0/fonts/5F3C862F467F43533.woff2", "Referer=https://{URL}/content/dam/delta-applications/fresh-air-core/20.3.0/fonts/fresh-air-fonts.css", ENDITEM, 
		"Url=https://{contentURL}/etc/designs/delta/images/favicon.ico", ENDITEM, 
		LAST);

	if(atoi(lr_eval_string("{carSearchPage}"))<=0)
	{
		lr_output_message("Cars Not Available");
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_14_ViewAllCars"), LR_AUTO);
		lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);		
	}
	

	web_reg_save_param("carId", "LB=carCode\":\"", "RB=\"", "Notfound=warning", LAST);
	web_reg_save_param("carVendorCode", "LB=carVendorCode\":\"", "RB=\"", "Notfound=warning", LAST);
	web_reg_save_param("totalPrice", "LB=carTotalAfterTax\":\"", "RB=\"", "Notfound=warning", LAST);
	web_reg_save_param("carImageURL", "LB=carImageUrl\":\"", "RB=\"", "Notfound=warning", LAST);
	
	web_custom_request("retreiveCarResultsJsonAction.action", 
		"URL=https://{URL}/merch/retreiveCarResultsJsonAction.action", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/merch/shopMerchandiseCarAction.action", 
		"Snapshot=t6789.inf", 
		"Mode=HTML", 
		"EncType=", 
		LAST);

	if(strlen(lr_eval_string("{carId}"))<=0)
	{
		lr_output_message("Cars Not Available");
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_14_ViewAllCars"), LR_AUTO);
		lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);		
	}
	
	web_custom_request("getDashBrdData.action", 
		"URL=https://{URL}/custlogin/getDashBrdData.action", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/merch/shopMerchandiseCarAction.action", 
		"Snapshot=t734.inf", 
		"Mode=HTML", 
		"EncType=", 
		LAST);

	web_url("devicetype", 
		"URL=https://{URL}/home/devicetype", 
		"Resource=0", 
		"Referer=https://{URL}/merch/shopMerchandiseCarAction.action", 
		"Snapshot=t866.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("getDashBrdData.action_2", 
		"URL=https://{URL}/custlogin/getDashBrdData.action", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/merch/shopMerchandiseCarAction.action", 
		"Snapshot=t954.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={}", 
		LAST);

	lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_14_ViewAllCars"), LR_AUTO);


	lr_think_time(5);
	
	lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_15_AddToCart"));

	
	web_submit_data("addCarToCart.action", 
		"Action=https://{URL}/merch/addCarToCart.action", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/merch/shopMerchandiseCarAction.action", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=addTocartRequest.carVendorCode", "Value={carVendorCode}", ENDITEM, 
		"Name=addTocartRequest.carId", "Value={carId}", ENDITEM, 
		"Name=addTocartRequest.firstName", "Value={firstPassengerFirstName}", ENDITEM, 
		"Name=addTocartRequest.lastName", "Value={firstPassengerLastName}", ENDITEM, 
		"Name=addTocartRequest.skyMilesAccNo", "Value=", ENDITEM, 
		"Name=addTocartRequest.hertz1Club", "Value=", ENDITEM, 
		"Name=addTocartRequest.totalPrice", "Value={totalPrice}", ENDITEM, 
		"Name=addTocartRequest.carImageURL", "Value={carImageURL}", ENDITEM, 
		EXTRARES, 
		LAST);
	
	lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_15_AddToCart"), LR_AUTO);

	lr_think_time(5);
	
	lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_16_CarCheckOut"));

	web_url("reviewcart", 
		"URL=https://{URL}/cart/activity/reviewcart", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{URL}/merch/shopMerchandiseCarAction.action", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/pref/geoLocationService/getClosestDeltaAirportCode", ENDITEM, 
		"Url=/databroker/bcdata.action", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/cart/background/grey-texure.png", "Referer=https://{contentURL}/content/dam/delta-applications/css/cart/v5.12.1/cart.css", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/cart/icon/blue-arrow.gif", "Referer=https://{contentURL}/content/dam/delta-applications/css/cart/v5.12.1/cart.css", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/cart/background/price-blue-dark-back.png", "Referer=https://{contentURL}/content/dam/delta-applications/css/cart/v5.12.1/cart.css", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/cart/background/nav-diagonals.png", "Referer=https://{contentURL}/content/dam/delta-applications/css/cart/v5.12.1/cart.css", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/cart/background/my_cart_background.png", "Referer=https://{contentURL}/content/dam/delta-applications/css/cart/v5.12.1/cart.css", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/cart/background/checkout-top-shading.png", "Referer=https://{contentURL}/content/dam/delta-applications/css/cart/v5.12.1/cart.css", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/cart/icon/red_ribbon.jpg", "Referer=https://{contentURL}/content/dam/delta-applications/css/cart/v5.12.1/cart.css", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/cart/background/cal_background.gif", "Referer=https://{contentURL}/content/dam/delta-applications/css/cart/v5.12.1/cart.css", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/cart/background/confirmation_background.jpg", "Referer=https://{contentURL}/content/dam/delta-applications/css/cart/v5.12.1/cart.css", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/cart/background/transparent-px.gif", "Referer=https://{contentURL}/content/dam/delta-applications/css/cart/v5.12.1/cart.css", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/cart/icon/icon-calc01.png", "Referer=https://{contentURL}/content/dam/delta-applications/css/cart/v5.12.1/cart.css", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/cart/icon/estimated_total_help-icon.png", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/cart/icon/flyout-close.png", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/cart/icon/tooltip_image.gif", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/cart/icon/tooltip_image_left.gif", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/cart/icon/confirmation_tick.gif", ENDITEM, 
		LAST);

	web_custom_request("ManageCartJSONAction", 
		"URL=https://{URL}/cart/activity/ManageCartJSONAction", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/cart/activity/reviewcart", 
		"Snapshot=t6765.inf", 
		"Mode=HTML", 
		"EncType=", 
		LAST);

	web_custom_request("getDashBrdData.action", 
		"URL=https://{URL}/custlogin/getDashBrdData.action", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/cart/activity/reviewcart", 
		"Snapshot=t7421.inf", 
		"Mode=HTML", 
		"EncType=", 
		LAST);

	web_url("devicetype", 
		"URL=https://{URL}/home/devicetype", 
		"Resource=0", 
		"Referer=https://{URL}/cart/activity/reviewcart", 
		"Snapshot=t8432.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("getDashBrdData.action_2", 
		"URL=https://{URL}/custlogin/getDashBrdData.action", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/cart/activity/reviewcart", 
		"Snapshot=t1041.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={}", 
		LAST);
	
	lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_16_CarCheckOut"), LR_AUTO);

	lr_think_time(5);
	
	lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_17_ClickBOOKNOW"));

	web_submit_data("FOPPopulateAction", 
		"Action=https://{URL}/cart/activity/FOPPopulateAction", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/cart/activity/reviewcart", 
		"Snapshot=t209.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=errorData", "Value={}", ENDITEM, 
		LAST);

	web_url("paymentSecurityModalContainer.html", 
		"URL=https://{URL}/utils/Cart/popup/paymentSecurityModalContainer.html", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://{URL}/cart/activity/reviewcart", 
		"Snapshot=t300.inf", 
		"Mode=HTML", 
		EXTRARES, 
		LAST);

	web_url("paymentSecurityModalContainer.html_2", 
		"URL=https://{URL}/utils/Cart/popup/paymentSecurityModalContainer.html", 
		"Resource=0", 
		"Referer=https://{URL}/cart/activity/reviewcart", 
		"Snapshot=t478.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=https://{contentURL}/content/dam/delta-applications/cart/background/vertical-dot.png", "Referer=https://{contentURL}/content/dam/delta-applications/css/cart/v5.12.1/cart.css", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/cart/background/txtbx-bg.jpg", "Referer=https://{contentURL}/content/dam/delta-applications/css/cart/v5.12.1/cart.css", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/cart/background/horizontal-dot.png", "Referer=https://{contentURL}/content/dam/delta-applications/css/cart/v5.12.1/cart.css", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/cart/icon/contact-icon.jpg", "Referer=https://{URL}/cart/activity/reviewcart", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/cart/icon/lock.png", "Referer=https://{URL}/cart/activity/reviewcart", ENDITEM, 
		LAST);
	
	lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_17_ClickBOOKNOW"), LR_AUTO);

	lr_think_time(5);
	
	web_reg_find("Text=Confirmation Page : Delta Air Lines", "Savecount=confirmCount",
		LAST);
	
	lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_18_CompleteCarBooking"));

	web_submit_data("purchase.action", 
		"Action=https://{URL}/cart/activity/purchase.action", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{URL}/cart/activity/reviewcart", 
		"Snapshot=t498.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=tempCreditCard", "Value=", ENDITEM, 
		"Name=tempCardType", "Value=", ENDITEM, 
		"Name=contactCountryName", "Value=", ENDITEM, 
		"Name=txtFName", "Value=Test", ENDITEM, 
		"Name=txtLName", "Value=Tester", ENDITEM, 
		"Name=nameOnCard", "Value=Test Tester", ENDITEM, 
		"Name=email", "Value=test@delta.com", ENDITEM, 
		"Name=confirmEmail", "Value=test@delta.com", ENDITEM, 
		"Name=emailType", "Value=H", ENDITEM, 
		"Name=emailFormat", "Value=H", ENDITEM, 
		"Name=emailType", "Value=H", ENDITEM, 
		"Name=emailFormat", "Value=H", ENDITEM, 
		"Name=txtContactCountryCd", "Value=1", ENDITEM, 
		"Name=txtAreaCode", "Value=800", ENDITEM, 
		"Name=txtPhoneNo", "Value=8544587", ENDITEM, 
		"Name=txtLocation", "Value=H", ENDITEM, 
		"Name=txtExtCode", "Value=", ENDITEM, 
		"Name=contactType", "Value=C", ENDITEM, 
		"Name=txtLocation", "Value=H", ENDITEM, 
		"Name=contactType", "Value=C", ENDITEM, 
		EXTRARES, 
		"Url=/pref/geoLocationService/getClosestDeltaAirportCode", ENDITEM, 
		"Url=/databroker/bcdata.action", ENDITEM, 
		"Url=https://{contentURL}/etc/designs/delta/images/background-light.png", "Referer=https://{contentURL}/content/dam/delta-applications/css/sitewide/v5.12.0/swr-legacy.css", ENDITEM, 
		LAST);

	web_submit_data("ConfirmationJSONAction", 
		"Action=https://{URL}/cart/activity/ConfirmationJSONAction", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/cart/activity/purchase.action", 
		"Snapshot=t687.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=errorData", "Value={}", ENDITEM, 
		"Name=selectedEmailId", "Value=", ENDITEM, 
		LAST);


	web_custom_request("getDashBrdData.action", 
		"URL=https://{URL}/custlogin/getDashBrdData.action", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/cart/activity/purchase.action", 
		"Snapshot=t723.inf", 
		"Mode=HTML", 
		"EncType=", 
		LAST);


	web_url("devicetype", 
		"URL=https://{URL}/home/devicetype", 
		"Resource=0", 
		"Referer=https://{URL}/cart/activity/purchase.action", 
		"Snapshot=t853.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=https://{contentURL}/content/dam/delta-applications/cart/background/confirmation_small_block.jpg", "Referer=https://{contentURL}/content/dam/delta-applications/css/cart/v5.12.1/cart.css", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/cart/icon/tick_image.jpg", "Referer=https://{contentURL}/content/dam/delta-applications/css/cart/v5.12.1/cart.css", ENDITEM, 
		LAST);

	web_custom_request("ConfirmationMailJSONAction", 
		"URL=https://{URL}/cart/activity/ConfirmationMailJSONAction", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/cart/activity/purchase.action", 
		"Snapshot=t975.inf", 
		"Mode=HTML", 
		"EncType=", 
		LAST);

	web_custom_request("getDashBrdData.action_2", 
		"URL=https://{URL}/custlogin/getDashBrdData.action", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/cart/activity/purchase.action", 
		"Snapshot=t1062.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={}", 
		LAST);
	
	
	if(atoi(lr_eval_string("{confirmCount}"))>0)
	{
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_18_CompleteCarBooking"), LR_AUTO);			
	}
	else
	{
		lr_output_message("Car purchase unsuccessful");
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_18_CompleteCarBooking"), LR_AUTO);
			
		lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);
	}

	return 0;
}
