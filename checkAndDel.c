checkAndDel()
{
	int i, count;
	char paramName[100];
	char *p;
	
//	Заходим в Itinerary
	web_reg_save_param_ex(
	    "ParamName=flightIDs", 
	    "LB/IC=name=\"flightID\" value=\"",
	    "RB/IC=\"",
	    "Ordinal=all");
	
    web_reg_save_param("ccgifields",
	    "lb=<input type=\"hidden\" name=\".cgifields\" value=\"",
	    "rb=\"  />",
	    "ord=all",
	    LAST);
		
	web_reg_save_param_ex(
	    "ParamName=departCity", 
	    "LB/IC=leaves ",
	    "RB/IC=.<br>  ",
	    "Ordinal=all");
	
	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

//	Ищем что удалать
	
	count = atoi(lr_eval_string("{flightIDs_count}"));
	lr_save_string("","param");

	for(i = 1;i <= count; i++) {
		strncpy(paramName, lr_paramarr_idx("departCity",i), 6);

		if (strcmp(paramName,"London",6) != 0) {
			lr_param_sprintf("param","%s%d=on&",lr_eval_string("{param}"), i);
			lr_output_message("Удалить билет №%d в нем город отправки %s", i, paramName);
		}
		
	}
	
//	собираем набор параметров для удаления
	for(i = 1;i <= count; i++) {
        lr_param_sprintf("param",
	        "%sflightID=%s&",
	        lr_eval_string("{param}"),
	        lr_paramarr_idx("flightIDs",
	        i));

        lr_param_sprintf("param",
	        "%s.cgifields=%s&",
	        lr_eval_string("{param}"),
	        lr_paramarr_idx("ccgifields",
	        i));

	}

	lr_save_string(lr_eval_string("{param}removeFlights.x=36&removeFlights.y=4"), "c_wcr");
		
    web_custom_request("itinerary.pl_2",
	    "URL=http://localhost:1080/cgi-bin/itinerary.pl",
	    "Method=POST",
	    "Resource=0",
	    "RecContentType=text/html",
	    "Referer==http://localhost:1080/cgi-bin/itinerary.pl",
	    "Snapshot=t4.inf",
	    "Mode=HTTP",
	    "Body={c_wcr}",
	    LAST);

	return 0;
}
