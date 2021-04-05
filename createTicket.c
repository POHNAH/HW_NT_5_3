createTicket()
{	
//	int randomNumber;
//	randomNumber = rand()%2;
	

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
	
	if (j == randomTicket) {
		lr_save_string(lr_eval_string("{city}"),"city1");
		while(strcmp(lr_eval_string("{city1}"),"London") == 0) {
			lr_save_string(lr_eval_string("{city}"),"city1");
		};
	}
	else {
		lr_save_string("London","city1");
	}
	lr_output_message(lr_eval_string("{city1}"));
	lr_save_string(lr_eval_string("{city}"),"city2");
	lr_output_message(lr_eval_string("{city2}"));
	lr_save_string(lr_eval_string("{seatPref}"),"sPref");
	lr_output_message(lr_eval_string("{sPref}"));
	lr_save_string(lr_eval_string("{seatType}"),"sType");
	lr_output_message(lr_eval_string("{sType}"));
	
//	if (randomNumber == 0) {
		web_reg_save_param_ex(
		    "ParamName=outFlight", 
		    "LB/IC=name=\"outboundFlight\" value=\"",
		    "RB/IC=\"",
		    "Ordinal=all");
		
		web_submit_form("reservations.pl", 
			"Snapshot=t4.inf", 
			ITEMDATA, 
			"Name=depart", "Value={city1}", ENDITEM, 
			"Name=departDate", "Value={date1}", ENDITEM, 
			"Name=arrive", "Value={city2}", ENDITEM, 
			"Name=returnDate", "Value={date2}", ENDITEM, 
			"Name=numPassengers", "Value=1", ENDITEM, 
			"Name=roundtrip", "Value=<OFF>", ENDITEM, 
			"Name=seatPref", "Value={sPref}", ENDITEM, 
			"Name=seatType", "Value={sType}", ENDITEM, 
			"Name=findFlights.x", "Value=64", ENDITEM, 
			"Name=findFlights.y", "Value=11", ENDITEM, 
			LAST);
		
		lr_save_string(lr_eval_string(lr_paramarr_random("outFlight")),"randomTicket");
		lr_output_message(lr_eval_string("{randomTicket}"));
	
		web_submit_form("reservations.pl_2", 
			"Snapshot=t5.inf", 
			ITEMDATA, 
			"Name=outboundFlight", "Value={randomTicket}", ENDITEM, 
			"Name=reserveFlights.x", "Value=3", ENDITEM, 
			"Name=reserveFlights.y", "Value=10", ENDITEM, 
			LAST);
	
		lr_save_string(lr_eval_string("{fName}"),"firstName");
		lr_output_message(lr_eval_string("{firstName}"));
		lr_save_string(lr_eval_string("{sName}"),"secondName");
		lr_output_message(lr_eval_string("{secondName}"));
		lr_save_string(lr_eval_string("{adress}"),"adr");
		lr_save_string(lr_eval_string("{home}"),"hom");
		lr_output_message("Adress %s, %s", lr_eval_string("{adr}"),lr_eval_string("{hom}"));
		lr_save_string(lr_eval_string("{cCard}"),"creditCard");
		lr_save_string(lr_eval_string("{cDate}"),"creditDate");
		lr_output_message("Credit card %s, %s", lr_eval_string("{creditCard}"),lr_eval_string("{creditDate}"));
	
		web_submit_form("reservations.pl_3", 
			"Snapshot=t6.inf", 
			ITEMDATA, 
			"Name=firstName", "Value={firstName}", ENDITEM, 
			"Name=lastName", "Value={secondName}", ENDITEM, 
			"Name=address1", "Value={adr}", ENDITEM, 
			"Name=address2", "Value={hom}", ENDITEM, 
			"Name=pass1", "Value={firstName} {secondName}", ENDITEM, 
			"Name=creditCard", "Value={creditCard}", ENDITEM, 
			"Name=expDate", "Value={creditDate}", ENDITEM, 
			"Name=saveCC", "Value={randBoolean}", ENDITEM, 
			"Name=buyFlights.x", "Value=49", ENDITEM, 
			"Name=buyFlights.y", "Value=14", ENDITEM, 
			LAST);
	
//	}
//	else {
//		web_reg_save_param_ex(
//		    "ParamName=outFlight", 
//		    "LB/IC=name=\"outboundFlight\" value=\"",
//		    "RB/IC=\"",
//		    "Ordinal=all");
//		
//		web_reg_save_param_ex(
//		    "ParamName=returnFlight", 
//		    "LB/IC=name=\"returnFlight\" value=\"",
//		    "RB/IC=\"",
//		    "Ordinal=all");
//		
//		web_submit_form("reservations.pl", 
//			"Snapshot=t4.inf", 
//			ITEMDATA, 
//			"Name=depart", "Value={city1}", ENDITEM, 
//			"Name=departDate", "Value={date1}", ENDITEM, 
//			"Name=arrive", "Value={city2}", ENDITEM, 
//			"Name=returnDate", "Value={date2}", ENDITEM, 
//			"Name=numPassengers", "Value=1", ENDITEM, 
//			"Name=roundtrip", "Value=on", ENDITEM, 
//			"Name=seatPref", "Value={sPref}", ENDITEM, 
//			"Name=seatType", "Value={sType}", ENDITEM, 
//			"Name=findFlights.x", "Value=64", ENDITEM, 
//			"Name=findFlights.y", "Value=11", ENDITEM, 
//			LAST);
//		
//		lr_save_string(lr_eval_string(lr_paramarr_random("outFlight")),"randomTicket1");
//		lr_output_message(lr_eval_string("{randomTicket1}"));
//		lr_save_string(lr_eval_string(lr_paramarr_random("returnFlight")),"randomTicket2");
//		lr_output_message(lr_eval_string("{randomTicket2}"));
//	
//		web_submit_form("reservations.pl_2", 
//			"Snapshot=t5.inf", 
//			ITEMDATA, 
//			"Name=outboundFlight", "Value={randomTicket1}", ENDITEM, 
//			"Name=returnFlight", "Value={randomTicket2}", ENDITEM, 
//			"Name=reserveFlights.x", "Value=3", ENDITEM, 
//			"Name=reserveFlights.y", "Value=10", ENDITEM, 
//			LAST);
//	
//		lr_save_string(lr_eval_string("{fName}"),"firstName");
//		lr_output_message(lr_eval_string("{firstName}"));
//		lr_save_string(lr_eval_string("{sName}"),"secondName");
//		lr_output_message(lr_eval_string("{secondName}"));
//		lr_save_string(lr_eval_string("{adress}"),"adr");
//		lr_save_string(lr_eval_string("{home}"),"hom");
//		lr_output_message("Adress %s, %s", lr_eval_string("{adr}"),lr_eval_string("{hom}"));
//		lr_save_string(lr_eval_string("{cCard}"),"creditCard");
//		lr_save_string(lr_eval_string("{cDate}"),"creditDate");
//		lr_output_message("Credit card %s, %s", lr_eval_string("{creditCard}"),lr_eval_string("{creditDate}"));
//	
//		web_submit_form("reservations.pl_3", 
//			"Snapshot=t6.inf", 
//			ITEMDATA, 
//			"Name=firstName", "Value={firstName}", ENDITEM, 
//			"Name=lastName", "Value={secondName}", ENDITEM, 
//			"Name=address1", "Value={adr}", ENDITEM, 
//			"Name=address2", "Value={hom}", ENDITEM, 
//			"Name=pass1", "Value={firstName} {secondName}", ENDITEM, 
//			"Name=creditCard", "Value={creditCard}", ENDITEM, 
//			"Name=expDate", "Value={creditDate}", ENDITEM, 
//			"Name=saveCC", "Value={randBoolean}", ENDITEM, 
//			"Name=buyFlights.x", "Value=49", ENDITEM, 
//			"Name=buyFlights.y", "Value=14", ENDITEM, 
//			LAST);
//	}
	
	return 0;
}