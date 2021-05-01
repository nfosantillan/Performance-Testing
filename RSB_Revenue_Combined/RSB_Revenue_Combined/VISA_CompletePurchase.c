VISA_CompletePurchase()
{

	lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_13a_VISA_CompletePurchase"));

	web_add_auto_header("X-Adapter", 
		"mobile");

	web_add_auto_header("cartId", 
		"{cartId}");

	web_custom_request("paymentDetails", 
		"URL=https://{URL}/payment/paymentDetails", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"cardDetails\":{\"billingAdr\":{\"addressLine1Text\":\"3614 MAIN STREET\",\"addressLine2Text\":\"\",\"cityLocalityName\":\"MC LEAN\",\"countryCode\":\"US\",\"countrySubdivisionCode\":\"VA\",\"postalCode\":\"22102\",\"id\":\"\",\"alias\":\"\"},\"cardHolderName\":{\"firstName\":\"Test\",\"lastName\":\"Tester\",\"middleInitialName\":null,\"prefix\":null,\"suffix\":null},\"cardType\":\"VI\",\"expirationMonthNum\":\"12\",\"expirationYearNum\":\"2020\",\"lastFourDigits\":\"1111\",\""
		"paymentCardNum\":\"4111111111111111\",\"paymentCardSecurityCode\":\"305\",\"paymentType\":\"Credit Card\",\"purchaseVrfyFlag\":false,\"alias\":null,\"alipayPaymentReferenceId\":null,\"formatInd\":null,\"paymentCardNetworkCode\":null,\"paymentVendorTransactionId\":null,\"savedFopId\":\"\",\"secureIdOnFOP\":null,\"uid\":null,\"taxFormId\":\"\",\"taxFormNumber\":\"\"},\"paymentType\":\"Credit Card\",\"afopFields\":[],\"rtbt\":{}}", 
		LAST);

	web_custom_request("paymentDetails_2", 
		"URL=https://{URL}/payment/paymentDetails", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"cardDetails\":{\"billingAdr\":{\"addressLine1Text\":\"3614 MAIN STREET\",\"addressLine2Text\":\"\",\"cityLocalityName\":\"MC LEAN\",\"countryCode\":\"US\",\"countrySubdivisionCode\":\"VA\",\"postalCode\":\"22102\",\"id\":\"\",\"alias\":\"\"},\"cardHolderName\":{\"firstName\":\"Test\",\"lastName\":\"Tester\",\"middleInitialName\":null,\"prefix\":null,\"suffix\":null},\"cardType\":\"VI\",\"expirationMonthNum\":\"12\",\"expirationYearNum\":\"2020\",\"lastFourDigits\":\"1111\",\""
		"paymentCardNum\":\"4111111111111111\",\"paymentCardSecurityCode\":\"305\",\"paymentType\":\"Credit Card\",\"purchaseVrfyFlag\":false,\"alias\":null,\"alipayPaymentReferenceId\":null,\"formatInd\":null,\"paymentCardNetworkCode\":null,\"paymentVendorTransactionId\":null,\"savedFopId\":\"\",\"secureIdOnFOP\":null,\"uid\":null,\"taxFormId\":\"\",\"taxFormNumber\":\"\"},\"paymentType\":\"Credit Card\",\"afopFields\":[],\"rtbt\":{}}", 
		LAST);

	web_revert_auto_header("X-Adapter");

	web_revert_auto_header("cartId");

	web_add_auto_header("CacheKey", 
		"{cacheKey}");

	web_add_auto_header("X-APP-CHANNEL", 
		"RSB-Booking");

	web_add_auto_header("appId", 
		"CKO");

	web_add_auto_header("channelId", 
		"ECOM");

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

	web_add_header("pageName", 
		"REVIEW_PAY");

	web_reg_save_param_json(
        "ParamName=paReq",
        "QueryString=$.paReq",
        "Notfound=warning",
        "SEARCH_FILTERS",
        "Scope=Body",
        "LAST");

	web_reg_save_param_json(
        "ParamName=termUrl",
        "QueryString=$.termUrl",
        "Notfound=warning",
        "SEARCH_FILTERS",
        "Scope=Body",
        "LAST");
	
	web_reg_save_param_json(
        "ParamName=redirectUrl",
        "QueryString=$.redirectUrl",
        "Notfound=warning",
        "SEARCH_FILTERS",
        "Scope=Body",
        "LAST");
	
	
	web_custom_request("confirmation", 
		"URL=https://{URL}/checkout/confirmation", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={\"cartId\":\"{cartId}\",\"channel\":\"ECOM\",\"purchaseInsurance\":true}", 
		LAST);

	web_revert_auto_header("CacheKey");

	web_revert_auto_header("X-APP-CHANNEL");

	web_revert_auto_header("appId");

	web_revert_auto_header("channelId");

	web_revert_auto_header("Origin");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");
	
	web_add_header("Content-Type", 
		"application/x-www-form-urlencoded");
	
	web_add_header("Accept", 
		"text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8");

	web_add_header("Origin", 
		"https://{URL}");
	
	web_reg_save_param("MD", "LB=input type='hidden' name='MD' value='", "RB='", "Notfound=warning", LAST);
	//paReq: eNpVUV1zgjAQfM+vcJw+E0gRxTkzg7WOTr+sIvWVxpuCw5cBWu2vb4JQ27fbvbtkdw/8SCLONihqiRyesCzDD+zF+0n/vk52R386KOJH/yH6dq06MPscVt4ajxw+UZZxnnHLMA0GtINEPSFFFGYVh1Acp8tnbjsusxygLSSQolzOuOOMLHOo+AskkIUp8hkmVdjzYpnEGZZAG5KAyOuskmc+sk2gHSBQy4RHVVWMKRXndyUhr6VAQ+QpUN0jQK9yVrWuSuXyFO/5eheUb4v59vUQfIXb03bDIufFn1vBwZsA1RME9mGFnJmWa9om61mj8WA4tpXihicQploIv7lljuEoXS0mUOifvAtSTd37Syk7tZSYic5PhwjgqcgzVDMq0t9aubhqv1voYEWlImMmGw4cVyfb4GY9VsEoyZf9uEmJ6h3a3o22J1bVv9P/ANfMqL8=
	web_submit_data("redirect", 
		"Action=https://0eafstag.cardinalcommerce.com/EAFService/jsp/v1/redirect", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{URL}/complete-purchase/review-pay?cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=paReq", "Value={paReq}", ENDITEM, 
		"Name=TermUrl", "Value={termUrl}", ENDITEM, 
		"Name=MD", "Value={cacheKey}", ENDITEM, 
		"Name=url", "Value={redirectUrl}", ENDITEM, 
		"Name=cacheKeySuffix", "Value={cacheKey}", ENDITEM, 
		LAST);

	web_add_auto_header("Origin", 
		"https://0eafstag.cardinalcommerce.com");

	web_reg_save_param("PaRes", "LB=input type=\"hidden\" name=\"PaRes\" value=\"", "RB=\"", "Notfound=warning", LAST);
	
	//MD: P.8ad123a4626bc2282ace9b83d33e3f34983193bd4d13785e6841a6ddc0c053047b0acee8f54f18a991c56a71fec5aca8f98d35acb6283c12b819f17c2813f8307964222d48d4bfe60f659be54ec2ed13
	web_submit_data("pareq.jsp", 
		"Action=https://merchantacsstag.cardinalcommerce.com/MerchantACSWeb/pareq.jsp?gold="
		"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
		"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
		"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://0eafstag.cardinalcommerce.com/EAFService/jsp/v1/redirect", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=PaReq", "Value={paReq}", ENDITEM, 
		"Name=TermUrl", "Value=https://0eafstag.cardinalcommerce.com/EAFService/jsp/v1/term", ENDITEM, 
		"Name=MD", "Value={MD}", ENDITEM, 
		LAST);

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_custom_request("saveProfilingData", 
		"URL=https://0eafstag.cardinalcommerce.com/EAFService/v1/saveProfilingData", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://0eafstag.cardinalcommerce.com/EAFService/jsp/v1/profile?payload={MD}", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"Request\":{\"Headers\":\"referer:https://0eafstag.cardinalcommerce.com/EAFService/jsp/v1/redirect, accept-language:en-US,en;q=0.9, cookie:BIGipServerCentinel-Web-Stag-EnhancedAltFlow.app~Centinel-Web-Stag-EnhancedAltFlow_pool=627615936.6695.0000, host:0eafstag.cardinalcommerce.com, upgrade-insecure-requests:1, connection:keep-alive, x-forwarded-for:205.174.22.25, user-agent:Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36, "
		"accept:text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8\",\"Ip\":\"205.174.22.25\",\"Referer\":\"https://0eafstag.cardinalcommerce.com/EAFService/jsp/v1/redirect\"},\"Browser\":{\"Language\":\"en-US\",\"Useragent\":\"Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36\",\"Cookies\":{\"Legacy\":true,\"SessionStorage\":true,\"LocalStorage\":true},\"Fingerprint\":\"0d5a9d59c534ba4b7eb8835f32368a0e\",\""
		"FingerprintJson\":\"[{\\\"key\\\":\\\"user_agent\\\",\\\"value\\\":\\\"Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36\\\"},{\\\"key\\\":\\\"language\\\",\\\"value\\\":\\\"en-US\\\"},{\\\"key\\\":\\\"color_depth\\\",\\\"value\\\":24},{\\\"key\\\":\\\"resolution\\\",\\\"value\\\":[1600,900]},{\\\"key\\\":\\\"available_resolution\\\",\\\"value\\\":[1600,860]},{\\\"key\\\":\\\"timezone_offset\\\",\\\"value\\\":300},{\\\"key\\\":\\\""
		"session_storage\\\",\\\"value\\\":1},{\\\"key\\\":\\\"local_storage\\\",\\\"value\\\":1},{\\\"key\\\":\\\"indexed_db\\\",\\\"value\\\":1},{\\\"key\\\":\\\"open_database\\\",\\\"value\\\":1},{\\\"key\\\":\\\"cpu_class\\\",\\\"value\\\":\\\"unknown\\\"},{\\\"key\\\":\\\"navigator_platform\\\",\\\"value\\\":\\\"Win32\\\"},{\\\"key\\\":\\\"do_not_track\\\",\\\"value\\\":\\\"unknown\\\"},{\\\"key\\\":\\\"regular_plugins\\\",\\\"value\\\":[\\\"Chrome PDF Plugin::Portable Document Format::application/"
		"x-google-chrome-pdf~pdf\\\",\\\"Chrome PDF Viewer::::application/pdf~pdf\\\",\\\"Native Client::::application/x-nacl~,application/x-pnacl~\\\"]},{\\\"key\\\":\\\"adblock\\\",\\\"value\\\":false},{\\\"key\\\":\\\"has_lied_languages\\\",\\\"value\\\":false},{\\\"key\\\":\\\"has_lied_resolution\\\",\\\"value\\\":false},{\\\"key\\\":\\\"has_lied_os\\\",\\\"value\\\":true},{\\\"key\\\":\\\"has_lied_browser\\\",\\\"value\\\":false},{\\\"key\\\":\\\"touch_support\\\",\\\"value\\\":[255,false,false]},{\\"
		"\"key\\\":\\\"js_fonts\\\",\\\"value\\\":[\\\"Arial\\\",\\\"Arial Black\\\",\\\"Arial Narrow\\\",\\\"Arial Unicode MS\\\",\\\"Book Antiqua\\\",\\\"Bookman Old Style\\\",\\\"Calibri\\\",\\\"Cambria\\\",\\\"Cambria Math\\\",\\\"Century\\\",\\\"Century Gothic\\\",\\\"Century Schoolbook\\\",\\\"Comic Sans MS\\\",\\\"Consolas\\\",\\\"Courier\\\",\\\"Courier New\\\",\\\"Garamond\\\",\\\"Georgia\\\",\\\"Helvetica\\\",\\\"Impact\\\",\\\"Lucida Bright\\\",\\\"Lucida Calligraphy\\\",\\\"Lucida Console\\\","
		"\\\"Lucida Fax\\\",\\\"Lucida Handwriting\\\",\\\"Lucida Sans\\\",\\\"Lucida Sans Typewriter\\\",\\\"Lucida Sans Unicode\\\",\\\"Microsoft Sans Serif\\\",\\\"Monotype Corsiva\\\",\\\"MS Gothic\\\",\\\"MS Outlook\\\",\\\"MS PGothic\\\",\\\"MS Reference Sans Serif\\\",\\\"MS Sans Serif\\\",\\\"MS Serif\\\",\\\"Palatino Linotype\\\",\\\"Segoe Print\\\",\\\"Segoe Script\\\",\\\"Segoe UI\\\",\\\"Segoe UI Light\\\",\\\"Segoe UI Semibold\\\",\\\"Segoe UI Symbol\\\",\\\"Tahoma\\\",\\\"Times\\\",\\\"Times "
		"New Roman\\\",\\\"Trebuchet MS\\\",\\\"Verdana\\\",\\\"Wingdings\\\",\\\"Wingdings 2\\\",\\\"Wingdings 3\\\"]}]\",\"Screen\":{\"Resolution\":\"900x1600\",\"Ratio\":1.7777777777777777},\"TimeoffSet\":5,\"Plugins\":\"{\\\"key\\\":\\\"regular_plugins\\\",\\\"value\\\":[\\\"Chrome PDF Plugin::Portable Document Format::application/x-google-chrome-pdf~pdf\\\",\\\"Chrome PDF Viewer::::application/pdf~pdf\\\",\\\"Native Client::::application/x-nacl~,application/x-pnacl~\\\"]}\"},\"CardinalPayload\":\""
		"{MD}\"}", 
		LAST);

	web_add_auto_header("Origin", 
		"https://merchantacsstag.cardinalcommerce.com");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_submit_data("term", 
		"Action=https://0eafstag.cardinalcommerce.com/EAFService/jsp/v1/term", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://merchantacsstag.cardinalcommerce.com/MerchantACSWeb/pareq.jsp?gold="
		"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
		"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
		"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=PaRes", "Value={PaRes}", ENDITEM, 
		"Name=MD", "Value={MD}", ENDITEM, 
		LAST);

	web_add_auto_header("Origin", 
		"https://0eafstag.cardinalcommerce.com");

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_custom_request("saveMouseData", 
		"URL=https://0eafstag.cardinalcommerce.com/EAFService/v1/saveMouseData", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://0eafstag.cardinalcommerce.com/EAFService/jsp/v1/redirect", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"CardinalPayload\":\"{MD}\",\"Data\":\"[]\"}", 
		LAST);

	web_custom_request("savePageData", 
		"URL=https://0eafstag.cardinalcommerce.com/EAFService/v1/savePageData", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://0eafstag.cardinalcommerce.com/EAFService/jsp/v1/redirect", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"CardinalPayload\":\"{MD}\",\"Data\":\"{\\\"WindowLoadTimestamp\\\":1554231469101,\\\"WindowUnloadTimestamp\\\":1554231470047,\\\"Events\\\":[{\\\"FrameChange\\\":{\\\"Sequence\\\":1,\\\"Timestamp\\\":1554231469979}},{\\\"FrameChange\\\":{\\\"Sequence\\\":2,\\\"Timestamp\\\":1554231470046}}]}\",\"Data2\":\"[{\\\"name\\\":\\\"https://"
		"0eafstag.cardinalcommerce.com/EAFService/jsp/v1/redirect\\\",\\\"entryType\\\":\\\"navigation\\\",\\\"startTime\\\":0,\\\"duration\\\":4065.999999991618,\\\"initiatorType\\\":\\\"navigation\\\",\\\"nextHopProtocol\\\":\\\"http/1.1\\\",\\\"workerStart\\\":0,\\\"redirectStart\\\":0,\\\"redirectEnd\\\":0,\\\"fetchStart\\\":16.100000008009374,\\\"domainLookupStart\\\":16.100000008009374,\\\"domainLookupEnd\\\":16.100000008009374,\\\"connectStart\\\":24.099999980535358,\\\"connectEnd\\\""
		":2819.900000002235,\\\"secureConnectionStart\\\":60.89999998221174,\\\"requestStart\\\":2820.1000000117347,\\\"responseStart\\\":2884.4999999855645,\\\"responseEnd\\\":2886.3000000128523,\\\"transferSize\\\":2951,\\\"encodedBodySize\\\":2531,\\\"decodedBodySize\\\":9327,\\\"serverTiming\\\":[],\\\"unloadEventStart\\\":0,\\\"unloadEventEnd\\\":0,\\\"domInteractive\\\":3166.2999999825843,\\\"domContentLoadedEventStart\\\":3166.2999999825843,\\\"domContentLoadedEventEnd\\\":3190.200000011828,\\\""
		"domComplete\\\":4065.999999991618,\\\"loadEventStart\\\":4065.999999991618,\\\"loadEventEnd\\\":4065.999999991618,\\\"type\\\":\\\"navigate\\\",\\\"redirectCount\\\":0},{\\\"name\\\":\\\"https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js\\\",\\\"entryType\\\":\\\"resource\\\",\\\"startTime\\\":2901.1000000173226,\\\"duration\\\":226.09999997075647,\\\"initiatorType\\\":\\\"script\\\",\\\"nextHopProtocol\\\":\\\"http/1.1\\\",\\\"workerStart\\\":0,\\\"redirectStart\\\":0,\\\""
		"redirectEnd\\\":0,\\\"fetchStart\\\":2901.1000000173226,\\\"domainLookupStart\\\":2901.1000000173226,\\\"domainLookupEnd\\\":2901.1000000173226,\\\"connectStart\\\":2907.69999998156,\\\"connectEnd\\\":3107.799999997951,\\\"secureConnectionStart\\\":2977.3999999742955,\\\"requestStart\\\":3107.900000002701,\\\"responseStart\\\":3122.0999999786727,\\\"responseEnd\\\":3127.199999988079,\\\"transferSize\\\":34505,\\\"encodedBodySize\\\":33951,\\\"decodedBodySize\\\":97163,\\\"serverTiming\\\":[]},{\\"
		"\"name\\\":\\\"https://0eafstag.cardinalcommerce.com/EAFService/includes/js/framedata.js\\\",\\\"entryType\\\":\\\"resource\\\",\\\"startTime\\\":2901.300000026822,\\\"duration\\\":45.69999995874241,\\\"initiatorType\\\":\\\"script\\\",\\\"nextHopProtocol\\\":\\\"http/1.1\\\",\\\"workerStart\\\":0,\\\"redirectStart\\\":0,\\\"redirectEnd\\\":0,\\\"fetchStart\\\":2901.300000026822,\\\"domainLookupStart\\\":2901.300000026822,\\\"domainLookupEnd\\\":2901.300000026822,\\\"connectStart\\\""
		":2901.300000026822,\\\"connectEnd\\\":2901.300000026822,\\\"secureConnectionStart\\\":0,\\\"requestStart\\\":2913.5000000242144,\\\"responseStart\\\":2946.300000010524,\\\"responseEnd\\\":2946.9999999855645,\\\"transferSize\\\":1471,\\\"encodedBodySize\\\":1202,\\\"decodedBodySize\\\":3492,\\\"serverTiming\\\":[]},{\\\"name\\\":\\\"https://0eafstag.cardinalcommerce.com/EAFService/jsp/v1/profile?payload="
		"{MD}\\\",\\\"entryType\\\":\\\"resource\\\",\\\"startTime\\\":2948.199999984354,\\\"duration\\\":39.0999999945052,\\\"initiatorType\\\":\\\"iframe\\\",\\\"nextHopProtocol\\\":\\\"http/1.1\\\",\\\"workerStart\\\":0,\\\"redirectStart\\\":0,\\\"redirectEnd\\\":0,\\\"fetchStart\\\":2948.199999984354,\\\"domainLookupStart\\\":2948.199999984354,\\"
		"\"domainLookupEnd\\\":2948.199999984354,\\\"connectStart\\\":2948.199999984354,\\\"connectEnd\\\":2948.199999984354,\\\"secureConnectionStart\\\":0,\\\"requestStart\\\":2949.900000006892,\\\"responseStart\\\":2986.1999999848194,\\\"responseEnd\\\":2987.299999978859,\\\"transferSize\\\":1031,\\\"encodedBodySize\\\":817,\\\"decodedBodySize\\\":1469,\\\"serverTiming\\\":[]},{\\\"name\\\":\\\"https://merchantacsstag.cardinalcommerce.com/MerchantACSWeb/pareq.jsp?gold="
		"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
		"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
		"AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\\\","
		"\\\"entryType\\\":\\\"resource\\\",\\\"startTime\\\":2956.9999999948777,\\\"duration\\\":503.9000000106171,\\\"initiatorType\\\":\\\"iframe\\\",\\\"nextHopProtocol\\\":\\\"http/1.1\\\",\\\"workerStart\\\":0,\\\"redirectStart\\\":0,\\\"redirectEnd\\\":0,\\\"fetchStart\\\":2956.9999999948777,\\\"domainLookupStart\\\":0,\\\"domainLookupEnd\\\":0,\\\"connectStart\\\":0,\\\"connectEnd\\\":0,\\\"secureConnectionStart\\\":0,\\\"requestStart\\\":0,\\\"responseStart\\\":0,\\\"responseEnd\\\""
		":3460.900000005495,\\\"transferSize\\\":0,\\\"encodedBodySize\\\":0,\\\"decodedBodySize\\\":0,\\\"serverTiming\\\":[]},{\\\"name\\\":\\\"https://0eafstag.cardinalcommerce.com/EAFService/v1/saveMouseData\\\",\\\"entryType\\\":\\\"resource\\\",\\\"startTime\\\":4134.299999976065,\\\"duration\\\":265.4000000329688,\\\"initiatorType\\\":\\\"xmlhttprequest\\\",\\\"nextHopProtocol\\\":\\\"http/1.1\\\",\\\"workerStart\\\":0,\\\"redirectStart\\\":0,\\\"redirectEnd\\\":0,\\\"fetchStart\\\""
		":4134.299999976065,\\\"domainLookupStart\\\":4134.299999976065,\\\"domainLookupEnd\\\":4134.299999976065,\\\"connectStart\\\":4134.299999976065,\\\"connectEnd\\\":4134.299999976065,\\\"secureConnectionStart\\\":0,\\\"requestStart\\\":4151.200000022072,\\\"responseStart\\\":4398.400000005495,\\\"responseEnd\\\":4399.700000009034,\\\"transferSize\\\":162,\\\"encodedBodySize\\\":2,\\\"decodedBodySize\\\":2,\\\"serverTiming\\\":[]}]\"}", 
		LAST);

	web_revert_auto_header("X-Requested-With");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_reg_find("Text=<title>Booking : Delta Air Lines</title>", LAST);
	
	web_submit_data("vbvAuthConfirmation",
	     "Action={termUrl}",            
		//"Action=https://{URL}/checkout/vbvAuthConfirmation?afopType=VBV&CacheKey={cacheKey}&cartId={cartId}&offerId=null", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://0eafstag.cardinalcommerce.com/EAFService/jsp/v1/term", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=PaRes", "Value={PaRes}", ENDITEM, 
		"Name=MD", "Value={cacheKey}", ENDITEM, 
		EXTRARES, 
		"Url=../content/dam/delta-applications/complete-purchase/0.4.140/fonts.css", "Referer=https://{URL}/complete-purchase/review-pay?redirect=onlinePay&cacheKeySuffix={cacheKey}&cartId={cartId}", ENDITEM, 
		LAST);

	web_revert_auto_header("Origin");

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("getClosestDeltaAirportCode", 
		"URL=https://{URL}/pref/geoLocationService/getClosestDeltaAirportCode", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/review-pay?redirect=onlinePay&cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	web_url("bcdata.action", 
		"URL=https://{URL}/databroker/bcdata.action", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/review-pay?redirect=onlinePay&cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		EXTRARES, 
		LAST);

	web_revert_auto_header("X-Requested-With");


	web_url("getdevicetype", 
		"URL=https://{URL}/complete-purchase/getdevicetype", 
		"Resource=0", 
		"Referer=https://{URL}/complete-purchase/review-pay?redirect=onlinePay&cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=../content/dam/delta-applications/complete-purchase/common/json/checkoutErrorMessage.json", "Referer=https://{URL}/complete-purchase/review-pay?redirect=onlinePay&cacheKeySuffix={cacheKey}&cartId={cartId}", ENDITEM, 
		LAST);

	web_add_header("CacheKey", 
		"{cacheKey}");

	web_custom_request("checkCustLoginInfo", 
		"URL=https://{URL}/checkout/checkCustLoginInfo?cartId={cartId}", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/review-pay?redirect=onlinePay&cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		LAST);

	web_custom_request("retrieveSearch", 
		"URL=https://{URL}/prefill/retrieveSearch?searchType=RecentSearchesJSON", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/review-pay?redirect=onlinePay&cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		LAST);

	web_url("getdevicetype_2", 
		"URL=https://{URL}/complete-purchase/getdevicetype", 
		"Resource=0", 
		"Referer=https://{URL}/complete-purchase/review-pay?redirect=onlinePay&cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		LAST);

	web_add_auto_header("Origin", 
		"https://{URL}");

	web_custom_request("getDashBrdData.action", 
		"URL=https://{URL}/custlogin/getDashBrdData.action", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/review-pay?redirect=onlinePay&cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={}", 
		EXTRARES, 
		LAST);

	web_add_header("CacheKey", 
		"{cacheKey}");

	web_add_header("X-APP-CHANNEL", 
		"RSB-Booking");

	web_add_header("appId", 
		"CKO");

	web_add_header("channelId", 
		"ECOM");

	web_custom_request("retrievecart", 
		"URL=https://{URL}/checkout/retrievecart", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/review-pay?redirect=onlinePay&cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={\"cartId\":\"{cartId}\",\"channel\":\"MOB\",\"offerId\":\"11111\"}", 
		EXTRARES, 
		LAST);

	web_add_auto_header("CacheKey", 
		"{cacheKey}");

	web_add_header("X-APP-CHANNEL", 
		"RSB-Booking");

	web_add_header("appId", 
		"CKO");

	web_add_header("channelId", 
		"ECOM");

	web_custom_request("tripTotalForAllPax", 
		"URL=https://{URL}/checkout/tripTotalForAllPax", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/review-pay?redirect=onlinePay&cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t30.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={\"cartId\":\"{cartId}\",\"currencyCode\":\"{C_currencyCode}\",\"offerId\":\"\"}", 
		LAST);

	web_revert_auto_header("Origin");

	web_custom_request("populatePassengers", 
		"URL=https://{URL}/checkout/populatePassengers?cartId={cartId}", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/review-pay?redirect=onlinePay&cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t31.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=utf-8", 
		LAST);

	web_revert_auto_header("CacheKey");

	web_add_header("CacheKey", 
		"{cacheKey}");

	web_add_header("X-APP-CHANNEL", 
		"RSB-Booking");

	web_add_header("appId", 
		"CKO");

	web_add_header("channelId", 
		"ECOM");

	web_custom_request("baggage", 
		"URL=https://{URL}/checkout/baggage", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/review-pay?redirect=onlinePay&cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t33.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={\"cartId\":\"{cartId}\",\"channel\":\"MOB\",\"offerId\":\"11111\"}", 
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
		"Referer=https://{URL}/complete-purchase/review-pay?redirect=onlinePay&cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t34.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"cartId\":\"{cartId}\",\"mockResponse\":false}", 
		EXTRARES, 
		"Url=../content/dam/delta-applications/complete-purchase/0.4.140/assets/fonts/Whitney-Medium.otf", "Referer=https://{URL}/content/dam/delta-applications/complete-purchase/0.4.140/fonts.css", ENDITEM, 
		"Url=../content/dam/delta-applications/complete-purchase/0.4.140/assets/fonts/icomoon.woff", "Referer=https://{URL}/content/dam/delta-applications/complete-purchase/0.4.140/fonts.css", ENDITEM, 
		"Url=../content/dam/delta-applications/complete-purchase/0.4.140/assets/fonts/Whitney-Bold.otf", "Referer=https://{URL}/content/dam/delta-applications/complete-purchase/0.4.140/fonts.css", ENDITEM, 
		"Url=../content/dam/delta-applications/complete-purchase/0.4.140/assets/fonts/Whitney-Light.woff", "Referer=https://{URL}/content/dam/delta-applications/complete-purchase/0.4.140/fonts.css", ENDITEM, 
		LAST);

//	web_add_header("CacheKey", 
//		"{cacheKey}");
//
//	web_add_header("X-APP-CHANNEL", 
//		"RSB-Booking");
//
//	web_add_header("airlineCode", 
//		"DL");
//
//	web_add_header("appId", 
//		"CKO");
//
//	web_add_header("channelId", 
//		"ECOM");
//
//	web_add_header("isMobile", 
//		"false");
//
//	web_add_header("pageName", 
//		"ABC");
//
//	web_custom_request("search", 
//		"URL=https://{URL}/merchandize/insurance/search", 
//		"Method=POST", 
//		"Resource=0", 
//		"RecContentType=application/json", 
//		"Referer=https://{URL}/complete-purchase/review-pay?redirect=onlinePay&cacheKeySuffix={cacheKey}&cartId={cartId}", 
//		"Snapshot=t35.inf", 
//		"Mode=HTML", 
//		"EncType=application/json; charset=UTF-8", 
//		"Body={\"requester\":{\"cartId\":\"{cartId}\",\"offerId\":\"\",\"offerItemId\":\"\",\"pnrNumber\":\"\",\"requesterType\":\"CKO\",\"bookingPath\":\"CKO\"}}", 
//		EXTRARES, 
//		"Url=https://{contentURL}/content/dam/delta-content-api/sprites/mobile/amenity_wifi_new@3x.png", "Referer=https://{URL}/complete-purchase/review-pay?redirect=onlinePay&cacheKeySuffix={cacheKey}&cartId={cartId}", ENDITEM, 
//		"Url=https://{contentURL}/content/dam/delta-content-api/sprites/mobile/flight_amenity_usb_power_icon@3x.png", "Referer=https://{URL}/complete-purchase/review-pay?redirect=onlinePay&cacheKeySuffix={cacheKey}&cartId={cartId}", ENDITEM, 
//		LAST);

	web_revert_auto_header("Origin");

	web_add_auto_header("CacheKey", 
		"{cacheKey}");

	web_add_auto_header("X-APP-CHANNEL", 
		"RSB-Booking");

	web_add_header("airlineCode", 
		"DL");

	web_add_auto_header("appId", 
		"CKO");

	web_add_auto_header("channelId", 
		"ECOM");

	web_add_header("isMobile", 
		"false");

	web_add_header("pageName", 
		"ABC");

	web_custom_request("passengerAgeInfo", 
		"URL=https://{URL}/checkout/passengerAgeInfo", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/review-pay?redirect=onlinePay&cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t39.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={\"birthDate\":\"1971-01-03\",\"travelDate\":\"{P_DepartureDate}\"}", 
		LAST);
	
	lr_start_transaction("%LoyaltyMileageInfo%");

	web_custom_request("loyaltyMileageInfo", 
		"URL=https://{URL}/checkout/loyaltyMileageInfo", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/complete-purchase/review-pay?redirect=onlinePay&cacheKeySuffix={cacheKey}&cartId={cartId}", 
		"Snapshot=t40.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={\"cartId\":\"{cartId}\",\"loyaltyMileageInfoIndicator\":true}", 
		LAST);

	lr_end_transaction("%LoyaltyMileageInfo%", LR_AUTO);

	web_revert_auto_header("CacheKey");

	web_revert_auto_header("X-APP-CHANNEL");

	web_revert_auto_header("appId");

	web_revert_auto_header("channelId");

	web_revert_auto_header("Origin");
	
	lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_13a_VISA_CompletePurchase"), LR_AUTO);

	return 0;
}
