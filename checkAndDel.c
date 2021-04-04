checkAndDel()
{
	int i, minPrice, minPriceNumber, count;
	char paramName[100];
	
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
	    "ParamName=prices", 
	    "LB/IC=Total Charge: $ ",
	    "RB/IC= ",
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
	minPrice = atoi(lr_eval_string("{prices_1}"));
	minPriceNumber = 1;
	count = atoi(lr_eval_string("{prices_count}"));
	for(i = 2;i <= count; i++) {
		sprintf(paramName, "{prices_%d}", i);
		
		if (minPrice > atoi(lr_eval_string(paramName))) {
			minPrice = atoi(lr_eval_string(paramName));
			minPriceNumber = i;
		}
	}
	
	lr_output_message("Минимальная цена %d у билена под номером %d", minPrice, minPriceNumber);
	
//	собираем набор параметров для удаления
	lr_save_string("","param");
	lr_param_sprintf("param","%d=on&", minPriceNumber);
	
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
