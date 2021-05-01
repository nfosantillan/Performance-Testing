createWholeRequest()
{

	int i;
	
	if(atoi(lr_eval_string("{randomSeatSelection}")) <= 5){
			lr_save_string(lr_eval_string("{\"seatRqList\":[{seatRqList_1}],\"associatedPassengerName\":\"Passenger\",\"customerId\":\"1\",\"firstNIN\":\"01\",\"firstName\":\"Passenger\",\"isDefaultName\":true,\"isLoggedInCustomer\":false,\"age\":0,\"passengerRefId\":\"1\",\"lastNIN\":\"01\",\"lastName\":\"1\",\"loyaltyNumber\":\"\",\"passengerType\":\"ADT\"}"), "finalSeatRequest");
	
			for(i=2; i<=atoi(lr_eval_string("{numPax}"));i++){
			
				lr_save_int(i, "passengerIndexFinal");
		
				if(i == 2){
					lr_save_string(lr_eval_string("{finalSeatRequest},{\"seatRqList\":[{seatRqList_2}],\"associatedPassengerName\":\"Passenger\",\"customerId\":\"{passengerIndexFinal}\",\"firstNIN\":\"01\",\"firstName\":\"Passenger\",\"isDefaultName\":true,\"isLoggedInCustomer\":false,\"age\":0,\"passengerRefId\":\"{passengerIndexFinal}\",\"lastNIN\":\"0{passengerIndexFinal}\",\"lastName\":\"{passengerIndexFinal}\",\"loyaltyNumber\":\"\",\"passengerType\":\"ADT\"}"), "finalSeatRequest");	
				}
				if(i == 3){
					lr_save_string(lr_eval_string("{finalSeatRequest},{\"seatRqList\":[{seatRqList_3}],\"associatedPassengerName\":\"Passenger\",\"customerId\":\"{passengerIndexFinal}\",\"firstNIN\":\"01\",\"firstName\":\"Passenger\",\"isDefaultName\":true,\"isLoggedInCustomer\":false,\"age\":0,\"passengerRefId\":\"{passengerIndexFinal}\",\"lastNIN\":\"0{passengerIndexFinal}\",\"lastName\":\"{passengerIndexFinal}\",\"loyaltyNumber\":\"\",\"passengerType\":\"ADT\"}"), "finalSeatRequest");	
				}
				if(i == 4){
					lr_save_string(lr_eval_string("{finalSeatRequest},{\"seatRqList\":[{seatRqList_4}],\"associatedPassengerName\":\"Passenger\",\"customerId\":\"{passengerIndexFinal}\",\"firstNIN\":\"01\",\"firstName\":\"Passenger\",\"isDefaultName\":true,\"isLoggedInCustomer\":false,\"age\":0,\"passengerRefId\":\"{passengerIndexFinal}\",\"lastNIN\":\"0{passengerIndexFinal}\",\"lastName\":\"{passengerIndexFinal}\",\"loyaltyNumber\":\"\",\"passengerType\":\"ADT\"}"), "finalSeatRequest");	
				}
				if(i == 5){
					lr_save_string(lr_eval_string("{finalSeatRequest},{\"seatRqList\":[{seatRqList_5}],\"associatedPassengerName\":\"Passenger\",\"customerId\":\"{passengerIndexFinal}\",\"firstNIN\":\"01\",\"firstName\":\"Passenger\",\"isDefaultName\":true,\"isLoggedInCustomer\":false,\"age\":0,\"passengerRefId\":\"{passengerIndexFinal}\",\"lastNIN\":\"0{passengerIndexFinal}\",\"lastName\":\"{passengerIndexFinal}\",\"loyaltyNumber\":\"\",\"passengerType\":\"ADT\"}"), "finalSeatRequest");	
				}
				if(i == 6){
					lr_save_string(lr_eval_string("{finalSeatRequest},{\"seatRqList\":[{seatRqList_6}],\"associatedPassengerName\":\"Passenger\",\"customerId\":\"{passengerIndexFinal}\",\"firstNIN\":\"01\",\"firstName\":\"Passenger\",\"isDefaultName\":true,\"isLoggedInCustomer\":false,\"age\":0,\"passengerRefId\":\"{passengerIndexFinal}\",\"lastNIN\":\"0{passengerIndexFinal}\",\"lastName\":\"{passengerIndexFinal}\",\"loyaltyNumber\":\"\",\"passengerType\":\"ADT\"}"), "finalSeatRequest");	
				}
				if(i == 7){
					lr_save_string(lr_eval_string("{finalSeatRequest},{\"seatRqList\":[{seatRqList_7}],\"associatedPassengerName\":\"Passenger\",\"customerId\":\"{passengerIndexFinal}\",\"firstNIN\":\"01\",\"firstName\":\"Passenger\",\"isDefaultName\":true,\"isLoggedInCustomer\":false,\"age\":0,\"passengerRefId\":\"{passengerIndexFinal}\",\"lastNIN\":\"0{passengerIndexFinal}\",\"lastName\":\"{passengerIndexFinal}\",\"loyaltyNumber\":\"\",\"passengerType\":\"ADT\"}"), "finalSeatRequest");	
				}
				if(i == 8){
					lr_save_string(lr_eval_string("{finalSeatRequest},{\"seatRqList\":[{seatRqList_8}],\"associatedPassengerName\":\"Passenger\",\"customerId\":\"{passengerIndexFinal}\",\"firstNIN\":\"01\",\"firstName\":\"Passenger\",\"isDefaultName\":true,\"isLoggedInCustomer\":false,\"age\":0,\"passengerRefId\":\"{passengerIndexFinal}\",\"lastNIN\":\"0{passengerIndexFinal}\",\"lastName\":\"{passengerIndexFinal}\",\"loyaltyNumber\":\"\",\"passengerType\":\"ADT\"}"), "finalSeatRequest");	
				}
				if(i == 9){
					lr_save_string(lr_eval_string("{finalSeatRequest},{\"seatRqList\":[{seatRqList_9}],\"associatedPassengerName\":\"Passenger\",\"customerId\":\"{passengerIndexFinal}\",\"firstNIN\":\"01\",\"firstName\":\"Passenger\",\"isDefaultName\":true,\"isLoggedInCustomer\":false,\"age\":0,\"passengerRefId\":\"{passengerIndexFinal}\",\"lastNIN\":\"0{passengerIndexFinal}\",\"lastName\":\"{passengerIndexFinal}\",\"loyaltyNumber\":\"\",\"passengerType\":\"ADT\"}"), "finalSeatRequest");	
				}
				
			}
			
	} else {
		
			lr_save_string(lr_eval_string("{\"seatRqList\":[{seatRqList_1}],\"associatedPassengerName\":\"Passenger\",\"customerId\":\"1\",\"firstNIN\":\"01\",\"firstName\":\"Passenger\",\"isDefaultName\":true,\"isLoggedInCustomer\":false,\"age\":0,\"passengerRefId\":\"1\",\"lastNIN\":\"01\",\"lastName\":\"1\",\"loyaltyNumber\":\"\",\"passengerType\":\"ADT\",\"selectedFareOfferPlusPrice\": {selectedFareOfferPlusPrice},\"passengerTypeLabelTxt\": \"\"}"), "finalSeatRequest");
			
			for(i=2; i<=atoi(lr_eval_string("{numPax}"));i++){
			
				lr_save_int(i, "passengerIndexFinal");
		
				if(i == 2){
					lr_save_string(lr_eval_string("{finalSeatRequest},{\"seatRqList\":[{seatRqList_2}],\"associatedPassengerName\":\"Passenger\",\"customerId\":\"{passengerIndexFinal}\",\"firstNIN\":\"01\",\"firstName\":\"Passenger\",\"isDefaultName\":true,\"isLoggedInCustomer\":false,\"age\":0,\"passengerRefId\":\"{passengerIndexFinal}\",\"lastNIN\":\"0{passengerIndexFinal}\",\"lastName\":\"{passengerIndexFinal}\",\"loyaltyNumber\":\"\",\"passengerType\":\"ADT\",\"selectedFareOfferPlusPrice\": {selectedFareOfferPlusPrice},\"passengerTypeLabelTxt\": \"\"}"), "finalSeatRequest");	
				}
				if(i == 3){
					lr_save_string(lr_eval_string("{finalSeatRequest},{\"seatRqList\":[{seatRqList_3}],\"associatedPassengerName\":\"Passenger\",\"customerId\":\"{passengerIndexFinal}\",\"firstNIN\":\"01\",\"firstName\":\"Passenger\",\"isDefaultName\":true,\"isLoggedInCustomer\":false,\"age\":0,\"passengerRefId\":\"{passengerIndexFinal}\",\"lastNIN\":\"0{passengerIndexFinal}\",\"lastName\":\"{passengerIndexFinal}\",\"loyaltyNumber\":\"\",\"passengerType\":\"ADT\",\"selectedFareOfferPlusPrice\": {selectedFareOfferPlusPrice},\"passengerTypeLabelTxt\": \"\"}"), "finalSeatRequest");	
				}
				if(i == 4){
					lr_save_string(lr_eval_string("{finalSeatRequest},{\"seatRqList\":[{seatRqList_4}],\"associatedPassengerName\":\"Passenger\",\"customerId\":\"{passengerIndexFinal}\",\"firstNIN\":\"01\",\"firstName\":\"Passenger\",\"isDefaultName\":true,\"isLoggedInCustomer\":false,\"age\":0,\"passengerRefId\":\"{passengerIndexFinal}\",\"lastNIN\":\"0{passengerIndexFinal}\",\"lastName\":\"{passengerIndexFinal}\",\"loyaltyNumber\":\"\",\"passengerType\":\"ADT\",\"selectedFareOfferPlusPrice\": {selectedFareOfferPlusPrice},\"passengerTypeLabelTxt\": \"\"}"), "finalSeatRequest");	
				}
				if(i == 5){
					lr_save_string(lr_eval_string("{finalSeatRequest},{\"seatRqList\":[{seatRqList_5}],\"associatedPassengerName\":\"Passenger\",\"customerId\":\"{passengerIndexFinal}\",\"firstNIN\":\"01\",\"firstName\":\"Passenger\",\"isDefaultName\":true,\"isLoggedInCustomer\":false,\"age\":0,\"passengerRefId\":\"{passengerIndexFinal}\",\"lastNIN\":\"0{passengerIndexFinal}\",\"lastName\":\"{passengerIndexFinal}\",\"loyaltyNumber\":\"\",\"passengerType\":\"ADT\",\"selectedFareOfferPlusPrice\": {selectedFareOfferPlusPrice},\"passengerTypeLabelTxt\": \"\"}"), "finalSeatRequest");	
				}
				if(i == 6){
					lr_save_string(lr_eval_string("{finalSeatRequest},{\"seatRqList\":[{seatRqList_6}],\"associatedPassengerName\":\"Passenger\",\"customerId\":\"{passengerIndexFinal}\",\"firstNIN\":\"01\",\"firstName\":\"Passenger\",\"isDefaultName\":true,\"isLoggedInCustomer\":false,\"age\":0,\"passengerRefId\":\"{passengerIndexFinal}\",\"lastNIN\":\"0{passengerIndexFinal}\",\"lastName\":\"{passengerIndexFinal}\",\"loyaltyNumber\":\"\",\"passengerType\":\"ADT\",\"selectedFareOfferPlusPrice\": {selectedFareOfferPlusPrice},\"passengerTypeLabelTxt\": \"\"}"), "finalSeatRequest");	
				}
				if(i == 7){
					lr_save_string(lr_eval_string("{finalSeatRequest},{\"seatRqList\":[{seatRqList_7}],\"associatedPassengerName\":\"Passenger\",\"customerId\":\"{passengerIndexFinal}\",\"firstNIN\":\"01\",\"firstName\":\"Passenger\",\"isDefaultName\":true,\"isLoggedInCustomer\":false,\"age\":0,\"passengerRefId\":\"{passengerIndexFinal}\",\"lastNIN\":\"0{passengerIndexFinal}\",\"lastName\":\"{passengerIndexFinal}\",\"loyaltyNumber\":\"\",\"passengerType\":\"ADT\",\"selectedFareOfferPlusPrice\": {selectedFareOfferPlusPrice},\"passengerTypeLabelTxt\": \"\"}"), "finalSeatRequest");	
				}
				if(i == 8){
					lr_save_string(lr_eval_string("{finalSeatRequest},{\"seatRqList\":[{seatRqList_8}],\"associatedPassengerName\":\"Passenger\",\"customerId\":\"{passengerIndexFinal}\",\"firstNIN\":\"01\",\"firstName\":\"Passenger\",\"isDefaultName\":true,\"isLoggedInCustomer\":false,\"age\":0,\"passengerRefId\":\"{passengerIndexFinal}\",\"lastNIN\":\"0{passengerIndexFinal}\",\"lastName\":\"{passengerIndexFinal}\",\"loyaltyNumber\":\"\",\"passengerType\":\"ADT\",\"selectedFareOfferPlusPrice\": {selectedFareOfferPlusPrice},\"passengerTypeLabelTxt\": \"\"}"), "finalSeatRequest");	
				}
				if(i == 9){
					lr_save_string(lr_eval_string("{finalSeatRequest},{\"seatRqList\":[{seatRqList_9}],\"associatedPassengerName\":\"Passenger\",\"customerId\":\"{passengerIndexFinal}\",\"firstNIN\":\"01\",\"firstName\":\"Passenger\",\"isDefaultName\":true,\"isLoggedInCustomer\":false,\"age\":0,\"passengerRefId\":\"{passengerIndexFinal}\",\"lastNIN\":\"0{passengerIndexFinal}\",\"lastName\":\"{passengerIndexFinal}\",\"loyaltyNumber\":\"\",\"passengerType\":\"ADT\",\"selectedFareOfferPlusPrice\": {selectedFareOfferPlusPrice},\"passengerTypeLabelTxt\": \"\"}"), "finalSeatRequest");	
				}
			}
			
	}
	
	return 0;
}
