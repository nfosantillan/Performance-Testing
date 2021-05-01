createJSONSeatRequestString()
{
	
	char withBraces[13], withoutBraces[13];
	int i;
	
	i = atoi(lr_eval_string("{passengerIndex}"));
	sprintf(withBraces, "{seatRqList_%d}", i);
	sprintf(withoutBraces, "seatRqList_%d", i);
	
	lr_save_string("{\"freeOfCharge\":true,\"productSeat\":false,", "temporarySeatString");
	
	if(atoi(lr_eval_string("{flightIndex}"))>1){
		lr_save_string(lr_eval_string(withBraces), "seatReqListTemp");
		lr_save_string(lr_eval_string("{seatReqListTemp}"), "TempSeatReqList");
		lr_save_string(lr_eval_string("{TempSeatReqList},{\"freeOfCharge\":true,\"productSeat\":false,"), "temporarySeatString");
	}
	
	lr_save_string(lr_eval_string(lr_paramarr_idx("flightList", atoi(lr_eval_string("{flightIndex}")))), "tempFlightString");
	
	//FlightInformation	
	web_reg_save_param_custom(lr_eval_string("{tempFlightString}"),"arrivalCity","arrivalCity\":\"","\"");
	web_reg_save_param_custom(lr_eval_string("{tempFlightString}"),"arrivalDate","localArrivalDate\":\"","\"");
	web_reg_save_param_custom(lr_eval_string("{tempFlightString}"),"arrivalTime","localArrivalTime\":\"","\"");
	web_reg_save_param_custom(lr_eval_string("{tempFlightString}"),"departureCity","departureCity\":\"","\"");
	web_reg_save_param_custom(lr_eval_string("{tempFlightString}"),"departureDate","localDepartureDate\":\"","\"");
	web_reg_save_param_custom(lr_eval_string("{tempFlightString}"),"departureTime","localDepartureTime\":\"","\"");
	web_reg_save_param_custom(lr_eval_string("{tempFlightString}"),"flightInfoIndex","flightInfoIndex\":\"","\"");
	web_reg_save_param_custom(lr_eval_string("{tempFlightString}"),"legId","legId\":\"","\"");
	web_reg_save_param_custom(lr_eval_string("{tempFlightString}"),"marketingAirlineCode","marketingAirlineCode\":\"","\"");
	web_reg_save_param_custom(lr_eval_string("{tempFlightString}"),"marketingClassOfService","marketingClassOfServiceCode\":\"","\"");
	web_reg_save_param_custom(lr_eval_string("{tempFlightString}"),"marketingFlightNumber","marketingFlightNumber\":\"","\"");
	web_reg_save_param_custom(lr_eval_string("{tempFlightString}"),"operatingAirline","operatingAirlineCode\":\"","\"");
	//web_reg_save_param_custom(lr_eval_string("{tempFlightString}"),"pendingSeatBrandId","fareBrandID\":\"","\"");
	web_reg_save_param_custom(lr_eval_string("{tempFlightString}"),"segmentId","segmentNumber\":\"","\"");
	web_reg_save_param_custom(lr_eval_string("{tempFlightString}"),"tripId","tripId\":\"","\"");

	
	getSeatColumn();
	
	web_reg_save_param_custom(lr_eval_string("{selectedSeatColumn}"),"pendingSeatNumber","seatNumber\":\"","\"");
	web_reg_save_param_custom(lr_eval_string("{selectedSeatColumn}"),"pendingSeatOfferId","offerId\":\"","\"");
	web_reg_save_param_custom(lr_eval_string("{selectedSeatColumn}"),"pendingSeatOfferItemNumber","offerItemNumber\":",",");
	web_reg_save_param_custom(lr_eval_string("{selectedSeatColumn}"),"pendingSeatPriceAmount","amount\":",",");
	web_reg_save_param_custom(lr_eval_string("{selectedSeatColumn}"),"pendingSeatProductCode","productCode\":\"","\"");

	if(strcmp(lr_eval_string("{pendingSeatBrandId}"), "FIRST")==0){
		lr_save_string("First Class", "pendingSeatBrandDescription");
	}

	if(strcmp(lr_eval_string("{pendingSeatBrandId}"), "MAIN")==0){
		lr_save_string("Main Cabin", "pendingSeatBrandDescription");
	}

	if(strcmp(lr_eval_string("{pendingSeatBrandId}"), "PRF")==0){
		lr_save_string("PREFERRED", "pendingSeatBrandDescription");
	}	
	
	if(strcmp(lr_eval_string("{pendingSeatBrandId}"), "DCP")==0){
		lr_save_string("Delta Comfort+&#174;", "pendingSeatBrandDescription");
	}

	if(strcmp(lr_eval_string("{pendingSeatBrandId}"), "EXT")==0){
		lr_save_string("Preferred Exit", "pendingSeatBrandDescription");
	}	
	//create Seat Request String
	lr_save_string(lr_eval_string("{temporarySeatString}\"arrivalCity\":\"{arrivalCity}\","), "temporarySeatString");
	lr_save_string(lr_eval_string("{temporarySeatString}\"arrivalDate\":\"{arrivalDate}\","), "temporarySeatString");
	lr_save_string(lr_eval_string("{temporarySeatString}\"arrivalTime\":\"{arrivalTime}\","), "temporarySeatString");
	lr_save_string(lr_eval_string("{temporarySeatString}\"departureCity\":\"{departureCity}\","), "temporarySeatString");
	lr_save_string(lr_eval_string("{temporarySeatString}\"departureDate\":\"{departureDate}\","), "temporarySeatString");
	lr_save_string(lr_eval_string("{temporarySeatString}\"departureTime\":\"{departureTime}\","), "temporarySeatString");
	lr_save_string(lr_eval_string("{temporarySeatString}\"firstNIN\":\"01\","), "temporarySeatString");
	lr_save_string(lr_eval_string("{temporarySeatString}\"flightInfoIndex\":\"{flightInfoIndex}\","), "temporarySeatString");
	lr_save_string(lr_eval_string("{temporarySeatString}\"lastNIN\":\"0{passengerIndex}\","), "temporarySeatString");
	lr_save_string(lr_eval_string("{temporarySeatString}\"legId\":\"{legId}\","), "temporarySeatString");
	lr_save_string(lr_eval_string("{temporarySeatString}\"marketingAirlineCode\":\"{marketingAirlineCode}\","), "temporarySeatString");
	lr_save_string(lr_eval_string("{temporarySeatString}\"marketingClassOfService\":\"{marketingClassOfService}\","), "temporarySeatString");
	lr_save_string(lr_eval_string("{temporarySeatString}\"marketingFlightNumber\":\"{marketingFlightNumber}\","), "temporarySeatString");
	lr_save_string(lr_eval_string("{temporarySeatString}\"operatingAirline\":\"{operatingAirline}\","), "temporarySeatString");
	lr_save_string(lr_eval_string("{temporarySeatString}\"passengerRefId\":\"{passengerIndex}\","), "temporarySeatString");
	lr_save_string(lr_eval_string("{temporarySeatString}\"pendingSeatBrandDescription\":\"{pendingSeatBrandDescription}\","), "temporarySeatString");
	lr_save_string(lr_eval_string("{temporarySeatString}\"pendingSeatBrandId\":\"{pendingSeatBrandId}\","), "temporarySeatString");
	lr_save_string(lr_eval_string("{temporarySeatString}\"pendingSeatCurrencyCode\":\"{pendingSeatCurrencyCode}\","), "temporarySeatString");
	lr_save_string(lr_eval_string("{temporarySeatString}\"pendingSeatCurrencySymbol\":\"{pendingSeatCurrencySymbol}\","), "temporarySeatString");
	lr_save_string(lr_eval_string("{temporarySeatString}\"pendingSeatNumber\":\"{pendingSeatNumber}\","), "temporarySeatString");
	lr_save_string(lr_eval_string("{temporarySeatString}\"pendingSeatOfferId\":\"{pendingSeatOfferId}\","), "temporarySeatString");
	lr_save_string(lr_eval_string("{temporarySeatString}\"pendingSeatOfferItemNumber\":{pendingSeatOfferItemNumber},"), "temporarySeatString");
	lr_save_string(lr_eval_string("{temporarySeatString}\"pendingSeatPriceAmount\":{pendingSeatPriceAmount},"), "temporarySeatString");
	lr_save_string(lr_eval_string("{temporarySeatString}\"pendingSeatProductCode\":\"{pendingSeatProductCode}\","), "temporarySeatString");
	lr_save_string(lr_eval_string("{temporarySeatString}\"pendingSeatProductDescription\":\"\","), "temporarySeatString");
	lr_save_string(lr_eval_string("{temporarySeatString}\"segmentId\":\"{segmentId}\","), "temporarySeatString");
	lr_save_string(lr_eval_string("{temporarySeatString}\"tripId\":\"{tripId}\"}"), "temporarySeatString");
	
	lr_save_string(lr_eval_string("{temporarySeatString}"), lr_eval_string(withoutBraces));
	
	return 0;
}
