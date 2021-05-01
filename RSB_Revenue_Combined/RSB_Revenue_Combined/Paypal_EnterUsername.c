Paypal_EnterUsername()
{

	
	lr_save_string(lr_eval_string("{csrfTokenString}"), "csrfTokenString_URLFORM");
	web_reg_save_param("otpMayflyKey", "LB=otpMayflyKey\":\"", "RB=\"", "NotFound=Warning", LAST);
	web_reg_save_param("otpMayflyKey2", "LB=otpMayflyKey\" value=\"", "RB=\"", "NotFound=Warning", LAST);
	lr_replace("csrfTokenString_URLFORM","/", "%2F");
	lr_replace("csrfTokenString_URLFORM","+", "%2B");
	lr_replace("csrfTokenString_URLFORM","=", "%3D");
	
	web_add_auto_header("Content-Type", "application/x-www-form-urlencoded");
	web_add_auto_header("Accept", "application/json");
	
	lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_12d_Paypal_02_EnterUsername"));

	web_custom_request("signin", 
		"URL=https://www.sandbox.paypal.com/signin?intent=checkout&ctxId=xo_ctx_{paypalPayload}&returnUri=%2Fwebapps%2Fhermes&state=%3Fflow%3D1-P%26ulReturn%3Dtrue%26useraction%3Dcommit%26token%3D{paypalPayload}&locale.x=en_US&country.x=US&flowId={paypalPayload}", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.sandbox.paypal.com/cgi-bin/webscr?cmd=_express-checkout&useraction=commit&token={paypalPayload}", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		"Body=_csrf={csrfTokenString_URLFORM}&_sessionID={paypalSessionID}&locale.x=en_US&processSignin=main&fn_sync_data="
		"%257B%2522SC_VERSION%2522%253A%25222.0.1%2522%252C%2522syncStatus%2522%253A%2522data%2522%252C%2522f%2522%253A%2522{paypalPayload}%2522%252C%2522s%2522%253A%2522UL_CHECKOUT_INPUT_EMAIL%2522%252C%2522chk%2522%253A%257B%2522ts%2522%253A1596563638151%252C%2522eteid%2522%253A%255B4062143986%252C-8445949230%252C10166125267%252C1149123879%252C6355610174%252C2828186731%252Cnull%252Cnull%255D%252C%2522tts%2522%253A125%257D%252C%2522dc%2522%253A%2522%257B%255C%2522screen%255C%2522%253A%257B%255C%2522c"
		"olorDepth%255C%2522%253A24%252C%255C%2522pixelDepth%255C%2522%253A24%252C%255C%2522height%255C%2522%253A768%252C%255C%2522width%255C%2522%253A1366%252C%255C%2522availHeight%255C%2522%253A728%252C%255C%2522availWidth%255C%2522%253A1366%257D%252C%255C%2522ua%255C%2522%253A%255C%2522Mozilla%252F5.0%2520(Windows%2520NT%25206.1%253B%2520Win64%253B%2520x64)%2520AppleWebKit%252F537.36%2520(KHTML%252C%2520like%2520Gecko)"
		"%2520Chrome%252F83.0.4103.97%2520Safari%252F537.36%255C%2522%257D%2522%252C%2522d%2522%253A%257B%2522ts1%2522%253A%2522Dk17%253A44748Di0%253A171Uk17%253A105Ui0%253A28Uh%253A1942%2522%252C%2522rDT%2522%253A%252231365%252C31373%252C30770%253A10972%252C10886%252C10279%253A21257%252C21136%252C20526%253A36653%252C36509%252C35895%253A11044%252C10898%252C10278%253A11046%252C10898%252C10310%253A52033%252C51882%252C51238%253A11059%252C10900%252C10274%253A5941%252C5778%252C5142%253A41851%252C41614%252C42844"
		"%253A42161%252C41006%252C44982%253A36942%252C35967%252C35884%253A6069%252C5347%252C5157%253A46944%252C46398%252C46141%253A52004%252C51540%252C51263%253A21237%252C20803%252C20525%253A46836%252C46413%252C46141%253A10932%252C10535%252C10279%253A5793%252C5406%252C5156%253A46758%252C46388%252C46141%253A18020%252C21%2522%257D%257D&intent=checkout&ads-client-context=checkout&flowId={paypalPayload}&ads-client-context-data="
		"%7B%22context_id%22%3A%7B%22context_id%22%3A%22{paypalPayload}%22%2C%22channel%22%3A0%2C%22flow_type%22%3A%22checkout%22%7D%7D&ctxId=xo_ctx_{paypalPayload}&requestUrl=%2Fsignin%3Fintent%3Dcheckout%26ctxId%3Dxo_ctx_{paypalPayload}%26returnUri%3D%252Fwebapps%252Fhermes%26state%3D%253Fflow%253D1-P%2526ulReturn%253Dtrue%2526useraction%253Dcommit%2526token%253D{paypalPayload}%26locale.x%3Den_US%26country.x%3DUS%26flowId%3D{paypalPayload}&forcePhonePasswordOptIn=&returnUri="
		"%2Fwebapps%2Fhermes&state=%3Fflow%3D1-P%26ulReturn%3Dtrue%26useraction%3Dcommit%26token%3D{paypalPayload}&login_email=paypal_1362585737_per%40yahoo.com&captchaCode=&initialSplitLoginContext=inputEmail&isTpdOnboarded=&captcha=&rememberMe=true&splitLoginContext=inputEmail", 
		LAST);

	if(strlen(lr_eval_string("{otpMayflyKey}"))<=0){
		if(strlen(lr_eval_string("{otpMayflyKey2}"))>0){
			lr_save_string(lr_eval_string("{otpMayflyKey2}"), "otpMayflyKey");
		} else{
			lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_12d_Paypal_02_EnterUsername"), LR_FAIL);
			lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);
		}
	}
	web_custom_request("sms", 
		"URL=https://www.sandbox.paypal.com/signin/challenge/sms", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.sandbox.paypal.com/cgi-bin/webscr?cmd=_express-checkout&useraction=commit&token={paypalPayload}", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		"Body=_csrf={csrfTokenString_URLFORM}&_sessionID={paypalSessionID}&locale.x=en_US&processSignin=main&fn_sync_data="
		"%257B%2522SC_VERSION%2522%253A%25222.0.1%2522%252C%2522syncStatus%2522%253A%2522data%2522%252C%2522f%2522%253A%2522{paypalPayload}%2522%252C%2522s%2522%253A%2522UL_CHECKOUT_INPUT_EMAIL%2522%252C%2522chk%2522%253A%257B%2522ts%2522%253A1596563638151%252C%2522eteid%2522%253A%255B4062143986%252C-8445949230%252C10166125267%252C1149123879%252C6355610174%252C2828186731%252Cnull%252Cnull%255D%252C%2522tts%2522%253A125%257D%252C%2522dc%2522%253A%2522%257B%255C%2522screen%255C%2522%253A%257B%255C%2522c"
		"olorDepth%255C%2522%253A24%252C%255C%2522pixelDepth%255C%2522%253A24%252C%255C%2522height%255C%2522%253A768%252C%255C%2522width%255C%2522%253A1366%252C%255C%2522availHeight%255C%2522%253A728%252C%255C%2522availWidth%255C%2522%253A1366%257D%252C%255C%2522ua%255C%2522%253A%255C%2522Mozilla%252F5.0%2520(Windows%2520NT%25206.1%253B%2520Win64%253B%2520x64)%2520AppleWebKit%252F537.36%2520(KHTML%252C%2520like%2520Gecko)"
		"%2520Chrome%252F83.0.4103.97%2520Safari%252F537.36%255C%2522%257D%2522%252C%2522d%2522%253A%257B%2522ts1%2522%253A%2522Dk17%253A44748Di0%253A171Uk17%253A105Ui0%253A28Uh%253A1942%2522%252C%2522rDT%2522%253A%252231365%252C31373%252C30770%253A10972%252C10886%252C10279%253A21257%252C21136%252C20526%253A36653%252C36509%252C35895%253A11044%252C10898%252C10278%253A11046%252C10898%252C10310%253A52033%252C51882%252C51238%253A11059%252C10900%252C10274%253A5941%252C5778%252C5142%253A41851%252C41614%252C42844"
		"%253A42161%252C41006%252C44982%253A36942%252C35967%252C35884%253A6069%252C5347%252C5157%253A46944%252C46398%252C46141%253A52004%252C51540%252C51263%253A21237%252C20803%252C20525%253A46836%252C46413%252C46141%253A10932%252C10535%252C10279%253A5793%252C5406%252C5156%253A46758%252C46388%252C46141%253A18020%252C21%2522%257D%257D&intent=checkout&ads-client-context=checkout&flowId={paypalPayload}&ads-client-context-data="
		"%7B%22context_id%22%3A%7B%22context_id%22%3A%22{paypalPayload}%22%2C%22channel%22%3A0%2C%22flow_type%22%3A%22checkout%22%7D%7D&ctxId=xo_ctx_{paypalPayload}&requestUrl=%2Fsignin%3Fintent%3Dcheckout%26ctxId%3Dxo_ctx_{paypalPayload}%26returnUri%3D%252Fwebapps%252Fhermes%26state%3D%253Fflow%253D1-P%2526ulReturn%253Dtrue%2526useraction%253Dcommit%2526token%253D{paypalPayload}%26locale.x%3Den_US%26country.x%3DUS%26flowId%3D{paypalPayload}&forcePhonePasswordOptIn=&returnUri="
		"%2Fwebapps%2Fhermes&state=%3Fflow%3D1-P%26ulReturn%3Dtrue%26useraction%3Dcommit%26token%3D{paypalPayload}&login_email=paypal_1362585737_per%40yahoo.com&captchaCode=&login_phone=&initialSplitLoginContext=inputEmail&isTpdOnboarded=&login_password=&captcha=&rememberMe=true&splitLoginContext=inputPassword&otpMayflyKey={otpMayflyKey}&otpVariant=viaLink", 
		LAST);
	
	lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_12d_Paypal_02_EnterUsername"), LR_AUTO);

	return 0;
}
