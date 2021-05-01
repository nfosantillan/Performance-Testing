randomizeFlexAndNonFlex()
{
	
	lr_save_int(5, "flexAirportPercent"); //indicate how many percent to indicate probability that it will go to Flex, the rest will go to NonFlex
	lr_save_string(lr_eval_string("{RandFlex}"), "randomFlexNumSelected");
	
	//flex search 
	if(atoi(lr_eval_string("{randomFlexNumSelected}"))<=atoi(lr_eval_string("{flexAirportPercent}"))){
		lr_save_string("true", "flexAirportFlag");
		lr_save_string("flexAirportSearch", "actionType");
		lr_save_string("_FLEX", "actionTypeTransaction");
	} else { //non flex search
		lr_save_string("false", "flexAirportFlag");
		lr_save_string("search", "actionType");	
		lr_save_string("", "actionTypeTransaction");		
	}
	
	return 0;
}
