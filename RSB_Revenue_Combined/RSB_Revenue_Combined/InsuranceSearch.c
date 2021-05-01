InsuranceSearch()
{

	lr_save_string("1","tripInsuranceSuccessFlag");
	
	web_add_header("CacheKey", "{cacheKey}");

	web_add_header("X-APP-CHANNEL", "RSB-Booking");	
	web_add_header("channelId", "ECOM");
	web_add_header("timeout", "40000");
	web_add_header("appId", "CKO");
	web_add_header("airlineCode", "DL");
	web_add_header("isMobile", "false");
	web_add_header("pageName", "ABC");
	web_add_header("Origin", "https://{URL}");

	web_add_header("Accept", "application/json");
	web_add_header("Content-Type", "application/json; charset=utf-8");
	
	web_reg_save_param("quotePackId", "LB=quotePackId\":\"", "RB=\"", "Notfound=warning", LAST);
	
	lr_continue_on_error(1);
	
	web_custom_request("search", 
		"URL=https://{URL}/merchandize/insurance/search", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t107.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		"Body={\"requester\":{\"cartId\":\"{cartId}\",\"offerId\":\"\",\"offerItemId\":\"\",\"pnrNumber\":\"\",\"requesterType\":\"CKO\",\"bookingPath\":\"CKO\"}}", 
		EXTRARES, 
		"Url=/content/dam/delta-applications/complete-purchase/0.4.117/assets/fonts/Whitney-BookItalic.ttf", "Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}", ENDITEM, 
		"Url=https://{contentURL}/content/dam/delta-applications/complete-purchase/common/images/amex_demo.png", "Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}", ENDITEM, 
		"Url=/content/www/omniui-payment/payment.omniui.json", "Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}", ENDITEM, 
		LAST);
	
	lr_continue_on_error(0);
	
	if(strlen(lr_eval_string("{quotePackId}"))<=0){
		lr_save_string("0","tripInsuranceSuccessFlag");
	}
	
	return 0;
}
