PE_BaggageCalculator()
{

	lr_start_transaction("%BaggageCalculator_getMultiplePersonalizedContent%");
	
	web_custom_request("getMultiplePersonalizedContent", 
		"URL=https://{URL}/personalization-api/getMultiplePersonalizedContent", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t34.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"userdata\":{},\"requestparam\":{\"campaignId\":[\"baggage-calculator:checkout-pages\"],\"format\":\"json\"}}", 
		LAST);
	
	lr_end_transaction("%BaggageCalculator_getMultiplePersonalizedContent%", LR_PASS);
	
	return 0;
}
