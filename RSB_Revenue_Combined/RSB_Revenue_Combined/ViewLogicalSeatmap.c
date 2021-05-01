ViewLogicalSeatmap()
{

	lr_replace("seatURL_LSM_1", "seatsURLParameters", "flightList");
	lr_replace("seatURL_LSM_1", "fltIndex", "flightIndex");
	web_reg_save_param_custom(lr_eval_string("{seatURL_LSM_1}"), "LSM_flightNum", "flightNumber\":\"", "\"");
	web_reg_save_param_custom(lr_eval_string("{seatURL_LSM_1}"), "LSM_fleetName", "fleetName\":\"", "\"");
	web_reg_save_param_custom(lr_eval_string("{seatURL_LSM_1}"), "LSM_fleetTypeCode", "fleetTypeCode\":\"", "\"");
	web_reg_save_param_custom(lr_eval_string("{seatURL_LSM_1}"), "LSM_subFleetTypeCode", "subFleetTypeCode\":\"", "\"");
	web_reg_save_param_custom(lr_eval_string("{seatURL_LSM_1}"), "LSM_airlineCode", "airlineCode\":\"", "\"");
	
	lr_save_string(lr_eval_string("XXXX{seatURL_LSM_1}XXXX"), "seatURL_LSM_1");
	web_reg_save_param_custom(lr_eval_string("{seatURL_LSM_1}"), "seatURL_LSM_1", "XXXX{", "}XXXX");

	lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_03a_ViewLogicalSeatmap"));
	lr_start_transaction("%RSB_LogicalSeatMap%");

	web_reg_find("Text=302 Found", "SaveCount=redirect_count",
		LAST);
	
	web_submit_data("LSM", 
		"Action=https://{URL}/seat-map/LSM", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://{URL}/flight-search/search-results?cacheKeySuffix={cacheKey}", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=flightListData", "Value={\"appId\":\"SEATS\",\"channelId\":\"ecomm\",\"pageId\":\"LSM-SHO\",\"redirectURL\":\"flight-search/search-results?cacheKeySuffix={cacheKey}&rindex=1\",\"customerReferenceId\":\"{customerReferenceId}\",\"fltNumber\":\"{LSM_flightNum}\",\"originCityCode\":\"{Origin}\",{seatURL_LSM_1},\"isModal\":true}", ENDITEM, 
		EXTRARES, 
		LAST);

	if(atoi(lr_eval_string("{redirect_count}"))>0){
		lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_302_REDIRECT"));
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_302_REDIRECT"), LR_AUTO);

		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_03a_ViewLogicalSeatmap"), LR_FAIL);
		lr_end_transaction("%RSB_LogicalSeatMap%", LR_FAIL);	
		lr_error_message("Seatmap 302 REDIRECT %s-%s", lr_eval_string("{Origin}"),lr_eval_string("{Destination}"));
		//lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_FAIL);
	} else {
	
		lr_end_transaction("%RSB_LogicalSeatMap%", LR_AUTO);
	}
	
	web_url("bcdata.action", 
		"URL=https://{URL}/databroker/bcdata.action", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/seat-map/LSM", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	web_url("seats-errors-messages.model.json", 
		"URL=https://{URL}/content/www/seats/seats-errors-messages.model.json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/seat-map/LSM", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	web_url("seats-labels.model.json", 
		"URL=https://{URL}/content/www/seats/seats-labels.model.json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/seat-map/LSM", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		LAST);

	web_url("seats-urls.model.json", 
		"URL=https://{URL}/content/www/seats/seats-urls.model.json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/seat-map/LSM", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	web_url("featureflagconfig.model.json", 
		"URL=https://{URL}/content/www/seats/featureflagconfig.model.json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/seat-map/LSM", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Cache-Control", "no-cache");
	web_add_header("Accept", "application/json, text/plain, */*");	
	
	web_reg_find("Text=302 Found", "SaveCount=redirect_count",
		LAST);
	
	lr_start_transaction("%RSB_SeatmapLSM%");

	web_custom_request("lsm", 
		"URL=https://{URL}/seatmap/lsm", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/seat-map/LSM", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"appId\":\"SEATS\",\"channelId\":\"ecomm\",\"pageId\":\"LSM-SHO\",\"redirectURL\":\"flight-search/search-results?cacheKeySuffix={cacheKey}&rindex=1\",\"customerReferenceId\":\"{customerReferenceId}\",\"fltNumber\":\"{LSM_flightNum}\",\"originCityCode\":\"{Origin}\",{seatURL_LSM_1},\"isModal\":true,\"customerRefId\":\"{customerReferenceId}\"}", 
		LAST);

	if(atoi(lr_eval_string("{redirect_count}"))>0){
			lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_302_REDIRECT"));
			lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_302_REDIRECT"), LR_AUTO);
	
			lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_03a_ViewLogicalSeatmap"), LR_FAIL);
			lr_end_transaction("%RSB_SeatmapISM%", LR_FAIL);	
			lr_error_message("Seatmap 302 REDIRECT %s-%s", lr_eval_string("{Origin}"),lr_eval_string("{Destination}"));
			
			return 0;
	} else{
	
		lr_end_transaction("%RSB_SeatmapLSM%", LR_AUTO);
	}
	
	lr_start_transaction("%getpersonalizedContent%");

	web_custom_request("getpersonalizedContent", 
		"URL=https://{URL}/personalization-api/getpersonalizedContent", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/seat-map/LSM", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body={\"userdata\":{\"flightName\":\"{LSM_fleetName}\",\"flightCode\":\"{LSM_fleetTypeCode}\",\"subFlightCode\":\"{LSM_subFleetTypeCode}\",\"operatingAirlineCode\":\"{LSM_airlineCode}\"},\"requestparam\":{\"campaignId\":\"seats:seats-interstitial\"}}", 
		EXTRARES, 
		LAST);

	lr_end_transaction("%getpersonalizedContent%", LR_AUTO);

	web_url("notificationconfig.model.json", 
		"URL=https://{URL}/content/www/seats/notificationconfig.model.json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://{URL}/seat-map/LSM", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		EXTRARES, 
		LAST);

	lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_03a_ViewLogicalSeatmap"), LR_AUTO);
	
			
	return 0;
}
