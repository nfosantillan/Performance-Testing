vuser_init()
{
	char URLVal[10],reviePageVal[10],analyticsFlowVal[10],covidBannerVal[10],insuranceVal[10], tripSummaryWithPurchaseVal[10], tripExtrasPurchaseVal[10], seatsPurchaseVal[10], carsSearchVal[10], callDurationVal[10];
	
	//already has control in Additional Attributes in Runtime Settings
	//lr_save_int(1, "tripSummaryWithPurchase");
	//lr_save_int(0, "tripExtrasPurchase");
	//lr_save_int(0, "seatsPurchase");
	//lr_save_int(0, "insurancePurchase"); 
	//lr_save_int(0, "carsSearch");
	
	//lr_save_int(0, "PSD2");
	
	lr_save_int(1, "deltaOnlyFlag");
	
	lr_save_string("101645:INVALID_SM_ACCOUNT_FOR_MC", "lastErrorValue");

	if(atoi(lr_eval_string("{deltaOnlyFlag}"))>0){
		lr_save_string("true", "deltaOnlySearch");
		lr_save_string("on", "deltaOnly");	            	
	} else {
		lr_save_string("false", "deltaOnlySearch");
		lr_save_string("off", "deltaOnly");	            	
	}

	//Runtime Settings get attributes
	//CALL DURATION LOGS
    sprintf(callDurationVal,"%s",lr_get_attrib_string("C_callDuration"));

    if(strcmp(callDurationVal,"(null)")==0) {
        
        lr_save_int(0,"callDurationFlag");
    }
    else {
        lr_save_string(callDurationVal,"callDurationFlag");
    } 	

	//REVIEW PAGE
    sprintf(reviePageVal,"%s",lr_get_attrib_string("C_reviewPageOnly"));

    if(strcmp(reviePageVal,"(null)")==0) {
        
        lr_save_int(0,"reviewPageOnly");
    }
    else {
        lr_save_string(reviePageVal,"reviewPageOnly");
    } 
    
	//TRIP SUMMARY WITH PURCHASE
    sprintf(tripSummaryWithPurchaseVal,"%s",lr_get_attrib_string("C_tripSummaryWithPurchase"));

    if(strcmp(tripSummaryWithPurchaseVal,"(null)")==0) {
        
        lr_save_int(0,"tripSummaryWithPurchase");
    }
    else {
        lr_save_string(tripSummaryWithPurchaseVal,"tripSummaryWithPurchase");
    } 

   	//TRIP EXTRA PURCHASE
    sprintf(tripExtrasPurchaseVal,"%s",lr_get_attrib_string("C_tripExtrasPurchase"));

    if(strcmp(tripExtrasPurchaseVal,"(null)")==0) {
        
        lr_save_int(0,"tripExtrasPurchase");
    }
    else {
        lr_save_string(tripExtrasPurchaseVal,"tripExtrasPurchase");
    } 
 
   	//SEATS PURCHASE
    sprintf(seatsPurchaseVal,"%s",lr_get_attrib_string("C_seatsPurchase"));

    if(strcmp(seatsPurchaseVal,"(null)")==0) {
        
        lr_save_int(0,"seatsPurchase");
    }
    else {
        lr_save_string(seatsPurchaseVal,"seatsPurchase");
    } 
 
   	//CARS PURCHASE
    sprintf(carsSearchVal,"%s",lr_get_attrib_string("C_carsSearch"));

    if(strcmp(carsSearchVal,"(null)")==0) {
        
        lr_save_int(0,"carsSearch");
    }
    else {
        lr_save_string(carsSearchVal,"carsSearch");
    } 
 
 	//COVID BANNER FLAG
    sprintf(covidBannerVal,"%s",lr_get_attrib_string("C_covidBannerFlag"));

    if(strcmp(covidBannerVal,"(null)")==0) {
        
        lr_save_int(0,"covidBannerFlag");
    }
    else {
        lr_save_string(covidBannerVal,"covidBannerFlag");
    } 
    
	//INSURANCE PURCHASE	
    sprintf(insuranceVal,"%s",lr_get_attrib_string("C_insurancePurchase"));

    if(strcmp(insuranceVal,"(null)")==0) {
        
        lr_save_int(0,"insurancePurchase");
    }
    else {
        lr_save_string(insuranceVal,"insurancePurchase");
    }  
    
	if(atoi(lr_eval_string("{insurancePurchase}"))>0){
		lr_save_string("true", "purchaseInsurance");
		lr_save_string("Y", "BAU_purchaseInsurance");
	} else {
		lr_save_string("false", "purchaseInsurance");
		lr_save_string("N", "BAU_purchaseInsurance");
	}
    
   	//ANALYTICS FLOW
    sprintf(analyticsFlowVal,"%s",lr_get_attrib_string("C_analyticsFlow"));

    if(strcmp(analyticsFlowVal,"(null)")==0) {
        
        lr_save_int(0,"analyticsFlow");
    }
    else {
        lr_save_string(analyticsFlowVal,"analyticsFlow");
    } 

	//URL Value
	lr_save_string(lr_eval_string("{URL}"), "URL");
	lr_save_string(lr_eval_string("{contentURL}"), "contentURL");
    sprintf(URLVal,"%s",lr_get_attrib_string("C_URL"));

    if(strcmp(URLVal,"(null)")==0) {
        
        lr_save_int(0,"URL");
    }
    else {
        lr_save_string(URLVal,"URL");
    } 
    
    if(strcmp(lr_eval_string("{URL}"), "stgp.delta.com")==0){
    	lr_save_string("stgp-content.delta.com", "contentURL");
    }
    
	/******************* HOW TO CREATE DYNAMIC PARAMETER ***************************
	char withBraces[10], withoutBraces[10];
	int i = 1;
	
	sprintf(withBraces, "{Param_%d}", 1);
	//sprintf(withDoubleBraces, "{{Param_%d}}", 1);
	sprintf(withoutBraces, "Param_%d", 1);
	lr_save_string("test", lr_eval_string(withoutBraces));
	lr_save_string(lr_eval_string(withBraces), "tempFinal");
	lr_save_string(lr_eval_string("{tempFinal}76"), "FINALTALAGA");
	******************* HOW TO CREATE DYNAMIC PARAMETER ***************************/
	
	return 0;
}

void web_reg_save_param_custom(char *sourceStr, char* outpuStr, char *leftBdry, char *rightBdry) {    
	char *st1, *st2;    
	int result, i = 0;              
	i=strlen(leftBdry);    
	st1 = (char*) strstr(sourceStr, leftBdry);     
	
	if (st1 != NULL){        
		st1 += i;        
		st2 = (char*) strstr(st1, rightBdry);         
		
		if (st2 != NULL){            
			result = st2 - st1;            
			*(st1 + result) = '\0';        
		}    
	}     
	
	if ((st1 == NULL) || (st2 == NULL))   {
//		lr_error_message("Error: No substring found for the specified boundary");
		lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);	
	}else{
		lr_save_string(lr_eval_string(st1), outpuStr);
	}
} 

char *strReplace(const char *src, const char *from, const char *to)                                                           
                                                                                                                              
{                                                                                                                             
                                                                                                                              
  char *value;                                                                                                                
  char *dst;                                                                                                                                                                                                                                                
  char *match;                                                                                                                
  int size;                                                                                                                   
  int fromlen;                                                                                                                
  int tolen;                                                                                                                  
  size = strlen(src) + 1;                                                                                                     
  fromlen = strlen(from);                                                                                                     
  tolen = strlen(to);                                                                                                         
  value = (char *)malloc(size);                                                                                               
  dst = value;                                                                                                                
  if ( value != NULL )                                                                                                        
  {                                                                                                                           
    for ( ;; )                                                                                                                
    {                                                                                                                         
      match = (char *) strstr(src, from);                                                                                     
      if ( match != NULL )                                                                                                    
      {                                                                                                                       
        size_t count = match - src;                                                                                           
        char *temp;                                                                                                           
        size += tolen - fromlen;                                                                                              
        temp = (char *)realloc(value, size);                                                                                  
        if ( temp == NULL )                                                                                                   
        {                                                                                                                     
          free(value);                                                                                                        
          return NULL;                                                                                                                              
        }                                                                                                                     
        dst = temp + (dst - value);                                                                                           
        value = temp;                                                                                                         
        memmove(dst, src, count);                                                                                             
        src += count;                                                                                                         
        dst += count;                                                                                                         
        memmove(dst, to, tolen);                                                                                              
        src += fromlen;                                                                                                       
        dst += tolen;                                                                                                         
      }                                                                                                                       
                                                                                                                              
      else // No match found.                                                                                                 
                                                                                                                              
      {                                                                                                                       
        strcpy(dst, src);                                                                                                     
        break;                                                                                                                
      }                                                                                                                       
    } // For Loop()                                                                                                           
  }                                                                                                                           
                                                                                                                              
  return value;                                                                                                               
                                                                                                                              
}                                                                                                                             
                                                                                                                              
int lr_replace( const char *lrparam, char *findstr, char *replacestr )                                                        
{                                                                                                                             
  int res = 0;                                                                                                                
  char *result_str;                                                                                                           
  char lrp[1024];                                                                                                             
  sprintf( lrp, "{%s}", lrparam);                                                                                             
  result_str = strReplace( lr_eval_string(lrp), findstr, replacestr );                                                        
  if (result_str != NULL )                                                                                                    
  {                                                                                                                           
    lr_save_string( result_str, lrparam );                                                                                    
    free( result_str );                                                                                                       
    res = 1;                                                                                                                  
  }                                                                                                                           
  return res; 
}

char *strReplace_2(const char *src, const char *from, const char *to)                                                           
                                                                                                                              
{                                                                                                                             
                                                                                                                              
  char *value;                                                                                                                
  char *dst;                                                                                                                                                                                                                                                
  char *match;                                                                                                                
  int size;                                                                                                                   
  int fromlen;                                                                                                                
  int tolen;                                                                                                                  
  size = strlen(src) + 1;                                                                                                     
  fromlen = strlen(from);                                                                                                     
  tolen = strlen(to);                                                                                                         
  value = (char *)malloc(size);                                                                                               
  dst = value;                                                                                                                
  if ( value != NULL )                                                                                                        
  {                                                                                                                           
    for ( ;; )                                                                                                                
    {                                                                                                                         
      match = (char *) strstr(src, from);                                                                                     
      if ( match != NULL )                                                                                                    
      {                                                                                                                       
        size_t count = match - src;                                                                                           
        char *temp;                                                                                                           
        size += tolen - fromlen;                                                                                              
        temp = (char *)realloc(value, size);                                                                                  
        if ( temp == NULL )                                                                                                   
        {                                                                                                                     
          free(value);                                                                                                        
          return NULL;                                                                                                                              
        }                                                                                                                     
        dst = temp + (dst - value);                                                                                           
        value = temp;                                                                                                         
        memmove(dst, src, count);                                                                                             
        src += count;                                                                                                         
        dst += count;                                                                                                         
        memmove(dst, to, tolen);                                                                                              
        src += fromlen;                                                                                                       
        dst += tolen;                                                                                                         
      }                                                                                                                       
                                                                                                                              
      else // No match found.                                                                                                 
                                                                                                                              
      {                                                                                                                       
        strcpy(dst, src);                                                                                                     
        break;                                                                                                                
      }                                                                                                                       
    } // For Loop()                                                                                                           
  }                                                                                                                           
                                                                                                                               
  return value;                                                                                                               
                                                                                                                              
}                                                                                                                             
                                                                                                                              
 extern int lr_replace_2( const char *lrparam,const char *name, char *findstr, char *replacestr )                                                        
{                                                                                                                             
  int res = 0;                                                                                                                
  char *result_str;                                                                                                           
  char lrp[20000];                                                                                                             
  sprintf( lrp, "%s", lrparam);                                                                                             
  result_str = strReplace_2( lr_eval_string(lrp), findstr, replacestr );                                                        
  if (result_str != NULL )                                                                                                    
  {                                                                                                                           
    lr_save_string( result_str, name);                                                                                    
    free( result_str );                                                                                                       
    res = 1;                                                                                                                  
  }                                                                                                                           
  return res;  
}
 
 char *Replacer_2(char *capValue, char *replace, char *replacewith)
	 {
	  char *pos;
	  int offset;
	  char output[10000];
	  
	 pos = (char *)strstr(capValue, replace);
	  strcpy(output, "");
	  while(pos!=0)
	  {
	   offset = (int) (pos - capValue);
	   strncat(output, capValue, offset);
	   strcat(output, replacewith);
	   capValue = (char *) (pos + strlen(replace));
	   pos = (char *)strstr(capValue, replace);
	  }
	  strcat(output, capValue);
	  //lr_output_message("%s", output);
	  return output;
}