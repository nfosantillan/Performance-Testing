Logout()
{

	lr_think_time(5);
	
	lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_99_Logout"));
	
	lr_start_transaction("%RSB_Logout%");

	web_url("logout.action", 
		"URL=https://{URL}/custlogin/logout.action", 
		"Resource=0", 
		"RecContentType=text/html", 
		//"Referer=https://{URL}/complete-purchase/confirmation?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		EXTRARES, 
		LAST);

	lr_end_transaction("%RSB_Logout%", LR_AUTO);

	web_url("getClosestDeltaAirportCode", 
		"URL=https://{URL}/pref/geoLocationService/getClosestDeltaAirportCode", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	web_url("bcdata.action", 
		"URL=https://{URL}/databroker/bcdata.action", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	web_custom_request("getDashBrdData", 
		"URL=https://{URL}/login/login/getDashBrdData", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		"Body={}", 
		LAST);


	web_custom_request("retrieveSearch", 
		"URL=https://{URL}/prefill/retrieveSearch?searchType=RecentSearchesJSON", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		LAST);

	web_url("getClosestDeltaAirportCode_2", 
		"URL=https://{URL}/pref/geoLocationService/getClosestDeltaAirportCode", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_99_Logout"), LR_AUTO);

	
	return 0;
}
