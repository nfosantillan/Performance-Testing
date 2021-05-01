createPassengerList()
{

	int i=0;
	lr_save_string(lr_eval_string("{firstName}"), "pnrFirstName");
	lr_save_string(lr_eval_string("{lastName}"), "pnrLastName");
	lr_save_string(lr_eval_string("{pnrFirstName}"), "firstPassengerFirstName");
	lr_save_string(lr_eval_string("{pnrLastName}"), "firstPassengerLastName");	
	lr_save_string(lr_eval_string("{\"basicInfo\":{\"birthDate\":{\"year\":\"1991\",\"month\":\"1\",\"day\":\"3\"},\"gender\":\"M\",\"name\":{\"firstName\":\"{pnrFirstName}\",\"lastName\":\"{pnrLastName}\",\"middleName\":\"\",\"suffix\":\"\"},\"pnrFirstName\":\"{pnrFirstName}\",\"pnrLastName\":\"{pnrLastName}\"},\"loyaltyAccount\":{},\"saveCompanion\":false,\"travelInfo\":{\"passengerType\":\"ADT\",\"passengerReferenceId\":1}}"), "passengerListString");
	
	
	for(i=2;i<=atoi(lr_eval_string("{numPax}"));i++){
		
		lr_save_int(i, "passengerId");
		lr_save_string(lr_eval_string("{firstName}"), "pnrFirstName");
		lr_save_string(lr_eval_string("{lastName}"), "pnrLastName");		
		lr_save_string(lr_eval_string("{passengerListString},{\"basicInfo\":{\"birthDate\":{\"year\":\"1991\",\"month\":\"1\",\"day\":\"3\"},\"gender\":\"M\",\"name\":{\"firstName\":\"{pnrFirstName}\",\"lastName\":\"{pnrLastName}\",\"middleName\":\"\",\"suffix\":\"\"},\"pnrFirstName\":\"{pnrFirstName}\",\"pnrLastName\":\"{pnrLastName}\"},\"loyaltyAccount\":{},\"saveCompanion\":false,\"travelInfo\":{\"passengerType\":\"ADT\",\"passengerReferenceId\":{passengerId}}}"), "passengerListString");		
		
	}

	return 0;
}
