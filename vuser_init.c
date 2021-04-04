vuser_init()
{
	web_reg_save_param_ex(
	    "ParamName=sessionID", 
	    "LB/IC=name=\"userSession\" value=\"",
	    "RB/IC=\"",
	    "Ordinal=1");
	
	web_url("webtours",
		"URL=http://localhost:1080/webtours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_output_message("-----------------------------------------");
	lr_output_message(lr_eval_string("{sessionID}"));
	
		web_submit_form("login.pl", 
		"Snapshot=t2.inf", 
		ITEMDATA, 
		"Name=username", "Value={login}", ENDITEM, 
		"Name=password", "Value={pass}", ENDITEM, 
		"Name=login.x", "Value=0", ENDITEM, 
		"Name=login.y", "Value=0", ENDITEM, 
		LAST);

	return 0;
}
