VTS_InsertRows(char *PNRDetails){
	
	char  *VtsServer = "10.6.173.129";  //Server name or IP
	int    nPort=7500;   				//Port used when enabling the instance.
	int    rc = 0;

	rc = lrvtc_connect(VtsServer, nPort, VTOPT_KEEP_ALIVE);
	
    if(rc != 0)
    {
    	lr_log_message("rc=%d\n", rc);
        lr_error_message ("VTS connection failed");
        lr_exit(LR_EXIT_VUSER, LR_FAIL);
    }

	rc = lrvtc_send_if_unique("PNRDetails", PNRDetails);
	
	if(rc != 0)
    {
    	lr_log_message("rc=%d\n", rc);
        lr_error_message ("Unable to retrieve rows");
        lrvtc_disconnect();
        lr_exit(LR_EXIT_MAIN_ITERATION_AND_CONTINUE, LR_FAIL);
    }
    else{
    	lrvtc_disconnect();
    }
	 
    return 0;
}