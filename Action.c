Action()
{



	web_set_sockets_option("SSL_VERSION", "TLS1.2");
	web_set_max_html_param_len("999999");
	web_set_sockets_option("SSL_VERSION", "AUTO");
	web_set_user("{P_Username}","{P_Password}","finobunipreprod.test.uni.ca:4443");

	/*Possible OAUTH authorization was detected. It is recommended to correlate the authorization parameters.*/

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_auto_header("sec-ch-ua", 
		"\"Google Chrome\";v=\"113\", \"Chromium\";v=\"113\", \"Not-A.Brand\";v=\"24\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");
	
	lr_start_transaction("S03_DEH_Retail_BalanceInquiry_01_Launch");

/*Correlation comment - Do not change!  Original value='aC9DS2IyeTdrMUZJUHgwZjNTVnB0Tm9zK1lwVndHeklMVXB3ZEEwaWlTOTBOeFA2VkdqZk00V3MwLzJ2L0NoRG4vRGpqRFhlMHFrUzZhSmx2Y1YyRFE9PTsyMDIzLTA1LTE4VDE0OjU2OjUxLjUzNzA0Nlo7cllCSVR1QSt0dkF3dU9jcVhmS0gwZz09O3siT3JjaGVzdHJhdGlvblN0ZXAiOjN9' Name ='C_CSRFToken' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=C_CSRFToken",
		"RegExp=x-ms-cpim-csrf=(.*?);",
		SEARCH_FILTERS,
	//	"Scope=Cookies",
		"IgnoreRedirections=No",
		LAST);

/*Correlation comment - Do not change!  Original value='eyJUSUQiOiI5Zjc3NzdiZi0yMjExLTQ0MDAtYWJjMi0yMDkxOGFhZjc4MWQifQ' Name ='C_StateProperties' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=C_StateProperties",
		"RegExp=StateProperties=(.*?)\",\\\r",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		LAST);
		


	web_url("authorize", 
		"URL=https://unisittesting.b2clogin.com/unisittesting.onmicrosoft.com/oauth2/v2.0/authorize?p=B2C_1A_USERNAME_SUSI_UI&client_id=f52c4661-2792-4e8b-801b-0e6d73549c0c&nonce=defaultNonce&redirect_uri=https%3A%2F%2Ffinobunipreprod.test.uni.ca%3A4443%2FuniAzureLogin&scope=openid&response_type=id_token&prompt=login", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t4.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_cookie("MC1=GUID=379a4a8612e647b48206258b071a130a&HASH=379a&LV=202302&V=4&LU=1676351146447; DOMAIN=browser.pipe.aria.microsoft.com");

	web_add_cookie("_clck=4n8zrc|1|fab|0; DOMAIN=browser.pipe.aria.microsoft.com");

	web_add_cookie("_uetvid=dfdc7ed0ce7211edb583578fb86b5ad6; DOMAIN=browser.pipe.aria.microsoft.com");

	web_add_cookie("AMCV_EA76ADE95776D2EC7F000101%40AdobeOrg=1585540135%7CMCIDTS%7C19446%7CMCMID%7C34000134599848532941738590125142691658%7CMCAAMLH-1680727629%7C7%7CMCAAMB-1680727629%7CRKhpRz8krg2tLO6pguXWp5olkAcUniQYPHaMWWgdJ3xzPWQmdj0y%7CMCCIDH%7C-231500260%7CMCOPTOUT-1680130029s%7CNONE%7CMCAID%7CNONE%7CvVersion%7C4.4.0; DOMAIN=browser.pipe.aria.microsoft.com");

	web_add_cookie("mbox=session#8f8f024ac3364f2f9e174a46a5360fa2#1680124689|PC#8f8f024ac3364f2f9e174a46a5360fa2.34_0#1714309528; DOMAIN=browser.pipe.aria.microsoft.com");

	web_add_cookie("MUID=3580A3F8239B636D10EDB149223162B2; DOMAIN=browser.pipe.aria.microsoft.com");



	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("X-CSRF-TOKEN",
		"{C_CSRFToken}");
	
			web_revert_auto_header("Origin");

	web_add_auto_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_auto_header("Sec-Fetch-Dest", 
		"image");

	web_add_auto_header("Sec-Fetch-Site", 
		"cross-site");
			
	web_concurrent_start("perftrace",NULL);

	web_custom_request("perftrace",
		"URL=https://unisittesting.b2clogin.com/unisittesting.onmicrosoft.com/B2C_1A_Username_SUSI_UI/client/perftrace?tx=StateProperties={C_StateProperties}&p=B2C_1A_Username_SUSI_UI",
		"Method=POST",
		"Resource=0",
		"Referer=https://unisittesting.b2clogin.com/unisittesting.onmicrosoft.com/oauth2/v2.0/authorize?p=B2C_1A_USERNAME_SUSI_UI&client_id=f52c4661-2792-4e8b-801b-0e6d73549c0c&nonce=defaultNonce&redirect_uri=https%3A%2F%2Ffinobunipreprod.test.uni.ca%3A4443%2FuniAzureLogin&scope=openid&response_type=id_token&prompt=login",
		"Snapshot=t7.inf",
		"Mode=HTTP",
		"EncType=application/json; charset=UTF-8",
		"Body={\"navigation\":{\"type\":0,\"redirectCount\":0},\"timing\":{\"connectStart\":1684421809942,\"navigationStart\":1684421807788,\"secureConnectionStart\":1684421810176,\"fetchStart\":1684421807842,\"domContentLoadedEventStart\":1684421811907,\"responseStart\":1684421811778,\"domInteractive\":1684421811907,\"domainLookupEnd\":1684421807842,\"responseEnd\":1684421811883,\"redirectStart\":0,\"requestStart\":1684421810265,\"unloadEventEnd\":0,\"unloadEventStart\":0,\"domLoading\":1684421811852,\"domComplete\":1684421811908,\"domainLookupStart\":1684421807842,\"loadEventStart\":1684421811908,\"domContentLoadedEventEnd\":1684421811908,\"loadEventEnd\":1684421811908,\"redirectEnd\":0,\"connectEnd\":1684421810265},\"entries\":[{\"name\":\"https://unisittesting.b2clogin.com/unisittesting.onmicrosoft.com/oauth2/v2.0/authorize?p=B2C_1A_USERNAME_SUSI_UI&client_id=f52c4661-2792-4e8b-801b-0e6d73549c0c&nonce=defaultNonce&redirect_uri=https%3A%2F%2Ffinobunipreprod.test.uni.ca%3A4443%2FuniAzureLogin&scope=openid&response_"
		"type=id_token&prompt=login\",\"entryType\":\"navigation\",\"startTime\":0,\"duration\":4120.39999999851,\"initiatorType\":\"navigation\",\"nextHopProtocol\":\"http/1.1\",\"renderBlockingStatus\":\"non-blocking\",\"workerStart\":0,\"redirectStart\":0,\"redirectEnd\":0,\"fetchStart\":54.09999999962747,\"domainLookupStart\":54.09999999962747,\"domainLookupEnd\":54.09999999962747,\"connectStart\":2153.5999999996275,\"secureConnectionStart\":2387.699999999255,\"connectEnd\":2477.39999999851,\"requestStart\":2477.5,\"responseStart\":3990,\"responseEnd\":4095.0999999996275,\"transferSize\":167820,\"encodedBodySize\":167520,\"decodedBodySize\":167520,\"responseStatus\":200,\"serverTiming\":[],\"unloadEventStart\":0,\"unloadEventEnd\":0,\"domInteractive\":4119,\"domContentLoadedEventStart\":4119,\"domContentLoadedEventEnd\":4119.699999999255,\"domComplete\":4120.299999998882,\"loadEventStart\":4120.39999999851,\"loadEventEnd\":4120.39999999851,\"type\":\"navigate\",\"redirectCount\":0,\"activationStart\":0},{\"name"
		"\":\"https://b2ccsshtmluifiles.blob.core.windows.net/b2cuifiles/h_login.html\",\"entryType\":\"resource\",\"startTime\":4110.199999999255,\"duration\":3106.5,\"initiatorType\":\"xmlhttprequest\",\"nextHopProtocol\":\"\",\"renderBlockingStatus\":\"non-blocking\",\"workerStart\":0,\"redirectStart\":0,\"redirectEnd\":0,\"fetchStart\":4110.199999999255,\"domainLookupStart\":0,\"domainLookupEnd\":0,\"connectStart\":0,\"secureConnectionStart\":0,\"connectEnd\":0,\"requestStart\":0,\"responseStart\":0,\"responseEnd\":7216.699999999255,\"transferSize\":0,\"encodedBodySize\":0,\"decodedBodySize\":0,\"responseStatus\":200,\"serverTiming\":[]}],\"connection\":{\"onchange\":null,\"effectiveType\":\"4g\",\"rtt\":50,\"downlink\":0.05,\"saveData\":false}}",
		LAST);



	web_url("images%2Ffavicon.png", 
		"URL=https://b2ccsshtmluifiles.blob.core.windows.net/b2cuifiles/images%2Ffavicon.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://unisittesting.b2clogin.com/", 
		"Snapshot=t8.inf", 
		LAST);

//	web_add_auto_header("Sec-Fetch-Mode", 
//		"navigate");
//
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"iframe");
//
//	web_add_header("Upgrade-Insecure-Requests", 
//		"1");

	web_url("deh-alerte", 
		"URL=https://www.uni.ca/deh-alerte/?ui_locales=en", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://unisittesting.b2clogin.com/", 
		"Snapshot=t9.inf", 
		"Mode=HTTP", 
		LAST);

//	web_revert_auto_header("sec-ch-ua");
//
//	web_revert_auto_header("sec-ch-ua-mobile");
//
//	web_revert_auto_header("sec-ch-ua-platform");
//
//	
//
//	web_add_auto_header("Origin", 
//		"https://unisittesting.b2clogin.com");
//
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"style");
//
//	web_add_auto_header("Sec-Fetch-Mode", 
//		"cors");
//
//	web_add_auto_header("Sec-Fetch-Site", 
//		"cross-site");
//
//	web_add_auto_header("sec-ch-ua", 
//		"\"Google Chrome\";v=\"113\", \"Chromium\";v=\"113\", \"Not-A.Brand\";v=\"24\"");
//
//	web_add_auto_header("sec-ch-ua-mobile", 
//		"?0");
//
//	web_add_auto_header("sec-ch-ua-platform", 
//		"\"Windows\"");

	web_url("styles%2Fstyle_login.css", 
		"URL=https://b2ccsshtmluifiles.blob.core.windows.net/b2cuifiles/styles%2Fstyle_login.css", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=", 
		"Snapshot=t11.inf", 
		LAST);

	web_url("library%2Fmdb.min.css", 
		"URL=https://b2ccsshtmluifiles.blob.core.windows.net/b2cuifiles/library%2Fmdb.min.css", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=", 
		"Snapshot=t12.inf", 
		LAST);



	web_url("styles%2Flayout.css", 
		"URL=https://b2ccsshtmluifiles.blob.core.windows.net/b2cuifiles/styles%2Flayout.css", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=", 
		"Snapshot=t13.inf", 
		LAST);


//	web_revert_auto_header("Origin");
//
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"image");
//
//	web_add_auto_header("Sec-Fetch-Mode", 
//		"no-cors");

	web_url("images%2Flogo.png", 
		"URL=https://b2ccsshtmluifiles.blob.core.windows.net/b2cuifiles/images%2Flogo.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://unisittesting.b2clogin.com/", 
		"Snapshot=t14.inf", 
		LAST);

//	web_add_auto_header("Sec-Fetch-Dest", 
//		"script");

	web_url("scripts%2Fscript_login.js", 
		"URL=https://b2ccsshtmluifiles.blob.core.windows.net/b2cuifiles/scripts%2Fscript_login.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://unisittesting.b2clogin.com/", 
		"Snapshot=t15.inf", 
		LAST);

	web_url("plugin.cookie.min.js", 
		"URL=https://b2ccsshtmluifiles.blob.core.windows.net/b2cuifiles/scripts/plugin.cookie.min.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://unisittesting.b2clogin.com/", 
		"Snapshot=t16.inf", 
		LAST);

//	web_add_auto_header("Sec-Fetch-Site", 
//		"same-origin");
//
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"image");

	web_url("alert-red.png", 
		"URL=https://www.uni.ca/deh-alerte/alert-red.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://www.uni.ca/deh-alerte/?ui_locales=en", 
		"Snapshot=t17.inf", 
		LAST);

//	web_add_auto_header("Sec-Fetch-Site", 
//		"cross-site");

	web_url("images%2Fsidebar_img.png", 
		"URL=https://b2ccsshtmluifiles.blob.core.windows.net/b2cuifiles/images%2Fsidebar_img.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://b2ccsshtmluifiles.blob.core.windows.net/b2cuifiles/styles%2Flayout.css", 
		"Snapshot=t18.inf", 
		LAST);

//	web_add_auto_header("Sec-Fetch-Site", 
//		"same-origin");

	web_url("alert-yellow.png", 
		"URL=https://www.uni.ca/deh-alerte/alert-yellow.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://www.uni.ca/deh-alerte/?ui_locales=en", 
		"Snapshot=t19.inf", 
		LAST);

//	web_add_auto_header("Sec-Fetch-Site", 
//		"cross-site");
//
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"script");

	web_url("library%2Fmdb.min.js", 
		"URL=https://b2ccsshtmluifiles.blob.core.windows.net/b2cuifiles/library%2Fmdb.min.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://unisittesting.b2clogin.com/", 
		"Snapshot=t20.inf", 
		LAST);
	
	web_concurrent_end(NULL);


	web_revert_auto_header("sec-ch-ua");

	web_revert_auto_header("sec-ch-ua-mobile");

	web_revert_auto_header("sec-ch-ua-platform");

	lr_end_transaction("S03_DEH_Retail_BalanceInquiry_01_Launch", LR_AUTO);
	
	lr_think_time(5);

	lr_start_transaction("S03_DEH_Retail_BalanceInquiry_CombinedLogin");
	
	lr_start_sub_transaction("S03_DEH_Retail_BalanceInquiry_Azure_Login_Combined","S03_DEH_Retail_BalanceInquiry_CombinedLogin");

	lr_start_sub_transaction("S03_DEH_Retail_BalanceInquiry_02_AzureLogin_Main","S03_DEH_Retail_BalanceInquiry_CombinedLogin");


	web_add_cookie("ui_locale=en; DOMAIN=unisittesting.b2clogin.com");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_header("Origin", 
		"https://unisittesting.b2clogin.com");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("X-CSRF-TOKEN",
		"{C_CSRFToken}");

	web_add_auto_header("sec-ch-ua", 
		"\"Google Chrome\";v=\"113\", \"Chromium\";v=\"113\", \"Not-A.Brand\";v=\"24\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_submit_data("SelfAsserted",
		"Action=https://unisittesting.b2clogin.com/unisittesting.onmicrosoft.com/B2C_1A_Username_SUSI_UI/SelfAsserted?tx=StateProperties={C_StateProperties}&p=B2C_1A_Username_SUSI_UI",
		"Method=POST",
		"EncodeAtSign=YES",
		"RecContentType=text/json",
		"Referer=https://unisittesting.b2clogin.com/unisittesting.onmicrosoft.com/oauth2/v2.0/authorize?p=B2C_1A_USERNAME_SUSI_UI&client_id=f52c4661-2792-4e8b-801b-0e6d73549c0c&nonce=defaultNonce&redirect_uri=https%3A%2F%2Ffinobunipreprod.test.uni.ca%3A4443%2FuniAzureLogin&scope=openid&response_type=id_token&prompt=login",
		"Snapshot=t22.inf",
		"Mode=HTTP",
		ITEMDATA,
		"Name=request_type", "Value=RESPONSE", ENDITEM,
		"Name=signInName", "Value={P_Username}", ENDITEM,
		"Name=password", "Value={P_Password}", ENDITEM,
		LAST);

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	
		   web_reg_save_param_regexp(
	  "ParamName=C_token",
	  "RegExp=uniAzureLogin#id_token=(.*?)\">here",
	  SEARCH_FILTERS,
	  "Scope=Body",
	  "IgnoreRedirections=No",
	  LAST);
	
	web_concurrent_start(NULL);


	web_url("confirmed",
		"URL=https://unisittesting.b2clogin.com/unisittesting.onmicrosoft.com/B2C_1A_Username_SUSI_UI/api/CombinedSigninAndSignup/confirmed?rememberMe=false&csrf_token={C_CSRFToken}&tx=StateProperties={C_StateProperties}&p=B2C_1A_Username_SUSI_UI&diags=%7B%22pageViewId%22%3A%22a89d40af-97d6-445d-8d28-1d0ab7660146%22%2C%22pageId%22%3A%22CombinedSigninAndSignup%22%2C%22trace%22%3A%5B%7B%22ac%22%3A%22T005%22%2C%22acST%22%3A1684421811%2C%22acD%22%3A2%7D%2C%7B%22ac%22%3A%22T021%20-%20URL%3Ahttps%3A%2F%2Fb2ccsshtmluifiles.blob.core.windows.net%2Fb2cuifiles%2Fh_login.html%22%2C%22acST%22%3A1684421811%2C%22acD%22%3A3108%7D%2C%7B%22ac%22%3A%22T019%22%2C%22acST%22%3A1684421815%2C%22acD%22%3A2%7D%2C%7B%22ac%22%3A%22T004%22%2C%22acST%22%3A1684421815%2C%22acD%22%3A1%7D%2C%7B%22ac%22%3A%22T003%22%2C%22acST%22%3A1684421815%2C%22acD%22%3A1%7D%2C%7B%22ac%22%3A%22T035%22%2C%22acST%22%3A1684421815%2C%22acD%22%3A0%7D%2C%7B%22ac%22%3A%22T030Online%22%2C%22acST%22%3A1684421815%2C%22acD%22%3A0%7D%2C%7B%22ac%22%3A%22T002%22%2C%22acST%22%3A1"
		"684421850%2C%22acD%22%3A0%7D%2C%7B%22ac%22%3A%22T018T010%22%2C%22acST%22%3A1684421847%2C%22acD%22%3A2844%7D%5D%7D",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://unisittesting.b2clogin.com/",
		"Snapshot=t23.inf",
		"Mode=HTTP",
		LAST);
	
		lr_end_sub_transaction("S03_DEH_Retail_BalanceInquiry_02_AzureLogin_Main",LR_AUTO);
		


		
	lr_start_sub_transaction("S03_DEH_Retail_BalanceInquiry_02_AzureLogin_ExtraRes","S03_DEH_Retail_BalanceInquiry_CombinedLogin");


//	web_add_auto_header("Sec-Fetch-Dest", 
//		"script");
//
//	web_add_auto_header("Sec-Fetch-Mode", 
//		"no-cors");

	web_url("navigator.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/scripts/navigator.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t24.inf", 
		LAST);

	web_url("zipkin-config.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/scripts/zipkin-config.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t25.inf", 
		LAST);

	web_url("zipkin-bundle.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/scripts/zipkin-bundle.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t26.inf", 
		LAST);

//	web_add_auto_header("Sec-Fetch-Dest", 
//		"style");

	web_url("app-address-style.css", 
		"URL=https://finobunipreprod.test.uni.ca:4443/styles/app-address-style.css", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=", 
		"Snapshot=t27.inf", 
		LAST);

//	web_add_auto_header("Sec-Fetch-Dest", 
//		"script");

	web_url("custom-elements-es5-adapter.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@webcomponents/webcomponentsjs/custom-elements-es5-adapter.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t28.inf", 
		LAST);

	web_url("webcomponents-loader.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@webcomponents/webcomponentsjs/webcomponents-loader.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t29.inf", 
		LAST);

	web_url("uuidv4.min.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/uuid/dist/umd/uuidv4.min.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t30.inf", 
		LAST);

	web_url("scripts-common.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/elements/scripts-common.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t31.inf", 
		LAST);

//	web_add_auto_header("Sec-Fetch-Mode", 
//		"cors");
//
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"font");
//
//	web_add_header("Origin", 
//		"https://finobunipreprod.test.uni.ca:4443");

	web_url("Roboto-Light.ttf", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/font-roboto-local/fonts/roboto/Roboto-Light.ttf", 
		"Resource=1", 
		"RecContentType=font/ttf", 
		"Referer=", 
		"Snapshot=t32.inf", 
		LAST);

//	web_set_sockets_option("TLS_SNI", "0");
//
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"style");
//
//	web_add_auto_header("Sec-Fetch-Mode", 
//		"no-cors");

	web_url("app-roboto.css", 
		"URL=https://finobunipreprod.test.uni.ca:4443/styles/UNI/app-roboto.css", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=", 
		"Snapshot=t33.inf", 
		LAST);

//	web_add_auto_header("Sec-Fetch-Dest", 
//		"script");

	web_url("scripts-speedup.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/elements/scripts-speedup.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t34.inf", 
		LAST);

	web_concurrent_end(NULL);


	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_header("correlationId", 
		"{\"uuid\":\"ee98f0b7-f460-4dd9-bd3a-69a5edb0d035\",\"resId\":\"d17f93ef-2d21-4cba-b074-581f7bc7d291\",\"resName\":\"SpeedConfigs\",\"menuId\":\"N.A\",\"buttonId\":\"N.A\"}");

	web_add_header("tenantId", 
		"UNI");
	
		lr_end_sub_transaction("S03_DEH_Retail_BalanceInquiry_02_AzureLogin_ExtraRes",LR_AUTO);
		
		lr_end_sub_transaction("S03_DEH_Retail_BalanceInquiry_Azure_Login_Combined",LR_AUTO);
		
		lr_start_sub_transaction("S03_DEH_Retail_BalanceInquiry_03_Login","S03_DEH_Retail_BalanceInquiry_CombinedLogin");

	web_concurrent_start("SpeedConfigs",NULL);
	
	web_url("SpeedConfigs", 
		"URL=https://finobunipreprod.test.uni.ca:4443/api/SpeedConfigs", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t35.inf", 
		"Mode=HTTP", 
		LAST);

//	web_add_auto_header("Sec-Fetch-Dest", 
//		"font");
//
//	web_add_auto_header("Origin", 
//		"https://finobunipreprod.test.uni.ca:4443");

	web_url("Roboto-Regular.ttf", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/font-roboto-local/fonts/roboto/Roboto-Regular.ttf", 
		"Resource=1", 
		"RecContentType=font/ttf", 
		"Referer=", 
		"Snapshot=t36.inf", 
		LAST);

//	web_add_auto_header("Sec-Fetch-Dest", 
//		"script");

	web_url("elements-applaunch.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/elements/elements-applaunch.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t37.inf", 
		LAST);

	web_url("custom-style.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/elements/custom-style.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t38.inf", 
		LAST);

	web_url("app-fab.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-fab.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t39.inf", 
		LAST);

	web_url("dom-bind.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/elements/dom-bind.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t40.inf", 
		LAST);

//	web_set_sockets_option("TLS_SNI", "1");

	web_url("iron-flex-layout-classes.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-flex-layout/iron-flex-layout-classes.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t41.inf", 
		LAST);

	web_url("iron-flex-layout.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-flex-layout/iron-flex-layout.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t42.inf", 
		LAST);

	web_url("app-styles.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/styles/app-styles.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t43.inf", 
		LAST);

	web_url("corp-app-styles.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/styles/corp-app-styles.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t44.inf", 
		LAST);

	web_url("swiper-min.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/styles/swiper-min.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t45.inf", 
		LAST);

	web_url("iron-pages.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-pages/iron-pages.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t46.inf", 
		LAST);

	web_url("paper-button.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-button/paper-button.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t47.inf", 
		LAST);

	web_url("iron-image.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-image/iron-image.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t48.inf", 
		LAST);

	web_url("iron-media-query.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-media-query/iron-media-query.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t49.inf", 
		LAST);

	web_url("iron-icon.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-icon/iron-icon.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t50.inf", 
		LAST);

//	web_revert_auto_header("Origin");
//
//	web_revert_auto_header("sec-ch-ua");
//
//	web_revert_auto_header("sec-ch-ua-mobile");
//
//	web_revert_auto_header("sec-ch-ua-platform");
//
//		web_add_auto_header("Origin", 
//		"https://finobunipreprod.test.uni.ca:4443");
//
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"script");
//
//	web_add_auto_header("Sec-Fetch-Mode", 
//		"cors");
//
//	web_add_auto_header("Sec-Fetch-Site", 
//		"same-origin");
//
//	web_add_auto_header("sec-ch-ua", 
//		"\"Google Chrome\";v=\"113\", \"Chromium\";v=\"113\", \"Not-A.Brand\";v=\"24\"");
//
//	web_add_auto_header("sec-ch-ua-mobile", 
//		"?0");
//
//	web_add_auto_header("sec-ch-ua-platform", 
//		"\"Windows\"");

	web_url("paper-dialog.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-dialog/paper-dialog.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t52.inf", 
		LAST);

	web_url("paper-checkbox.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-checkbox/paper-checkbox.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t53.inf", 
		LAST);

	web_url("paper-input-container.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-input/paper-input-container.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t54.inf", 
		LAST);

	web_url("paper-item.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-item/paper-item.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t55.inf", 
		LAST);

	web_url("paper-item-body.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-item/paper-item-body.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t56.inf", 
		LAST);

//	web_revert_auto_header("Origin");
//
//	web_revert_auto_header("sec-ch-ua");
//
//	web_revert_auto_header("sec-ch-ua-mobile");
//
//	web_revert_auto_header("sec-ch-ua-platform");
//
//
//	web_add_auto_header("Origin", 
//		"https://finobunipreprod.test.uni.ca:4443");
//
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"script");
//
//	web_add_auto_header("Sec-Fetch-Mode", 
//		"cors");
//
//	web_add_auto_header("Sec-Fetch-Site", 
//		"same-origin");
//
//	web_add_auto_header("sec-ch-ua", 
//		"\"Google Chrome\";v=\"113\", \"Chromium\";v=\"113\", \"Not-A.Brand\";v=\"24\"");
//
//	web_add_auto_header("sec-ch-ua-mobile", 
//		"?0");
//
//	web_add_auto_header("sec-ch-ua-platform", 
//		"\"Windows\"");

	web_url("paper-toast.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-toast/paper-toast.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t58.inf", 
		LAST);

	web_url("paper-input-behavior.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-input/paper-input-behavior.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t59.inf", 
		LAST);

	web_url("paper-icon-button.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-icon-button/paper-icon-button.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t60.inf", 
		LAST);

	web_url("paper-input-error.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-input/paper-input-error.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t61.inf", 
		LAST);

	web_url("paper-listbox.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-listbox/paper-listbox.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t62.inf", 
		LAST);

	web_url("paper-material.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-material/paper-material.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t63.inf", 
		LAST);

	web_url("paper-spinner.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-spinner/paper-spinner.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t64.inf", 
		LAST);

	web_url("gold-cc-expiration-input.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/gold-cc-expiration-input/gold-cc-expiration-input.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t65.inf", 
		LAST);

	web_url("gold-cc-input.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/gold-cc-input/gold-cc-input.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t66.inf", 
		LAST);

	web_url("paper-card.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-card/paper-card.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t67.inf", 
		LAST);

	web_url("oe-combo.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-combo/oe-combo.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t68.inf", 
		LAST);

	web_url("l2t-paper-slider.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@xpertsea/paper-slider/l2t-paper-slider.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t69.inf", 
		LAST);

	web_url("oe-ajax.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-ajax/oe-ajax.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t70.inf", 
		LAST);

	web_url("oe-i18n-msg.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-i18n-msg/oe-i18n-msg.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t71.inf", 
		LAST);

	web_url("oe-input.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-input/oe-input.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t72.inf", 
		LAST);

	web_url("oe-textarea.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-input/oe-textarea.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t73.inf", 
		LAST);

	web_url("oe-vbox.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-ui-misc/oe-vbox.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t74.inf", 
		LAST);

	web_url("app-common-behaviour.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/behaviors/app-common-behaviour.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t75.inf", 
		LAST);

	web_url("oe-hbox.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-ui-misc/oe-hbox.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t76.inf", 
		LAST);

	web_url("app-menu-access-behaviour.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/behaviors/app-menu-access-behaviour.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t77.inf", 
		LAST);

	web_url("keyboard-accessibility.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/behaviors/keyboard-accessibility.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t78.inf", 
		LAST);

	web_url("currency-formator-behaviour.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/behaviors/currency-formator-behaviour.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t79.inf", 
		LAST);

	web_url("app-formator-behaviour.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/behaviors/app-formator-behaviour.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t80.inf", 
		LAST);

	web_url("ev-login.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/ev-login.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t81.inf", 
		LAST);

	web_url("app-dialog.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-dialog.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t82.inf", 
		LAST);

	web_url("app-paper-input.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-paper-input.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t83.inf", 
		LAST);

	web_url("reg-carousel.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_Registration_ui/elements/reg-carousel.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t84.inf", 
		LAST);

	web_url("app-media-query.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-media-query.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t85.inf", 
		LAST);

	web_url("sb-app-localstorage-document.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/sb-app-localstorage-document.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t86.inf", 
		LAST);

	web_url("app-processing-loader.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-processing-loader.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t87.inf", 
		LAST);

	web_url("app-message-handler.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-message-handler.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t88.inf", 
		LAST);

	web_url("key-management.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/key-management.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t89.inf", 
		LAST);

	web_url("custom-navigation.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/custom-navigation.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t90.inf", 
		LAST);

	web_url("firebase-push-notification.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/firebase-push-notification.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t91.inf", 
		LAST);

	web_url("session-timeout.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/session-timeout.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t92.inf", 
		LAST);

	web_url("fin-auth-otp.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/fin-auth-otp.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t93.inf", 
		LAST);

	web_url("fin-auth-transaction-pwd.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/fin-auth-transaction-pwd.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t94.inf", 
		LAST);

	web_url("fin-auth-debit-card.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/fin-auth-debit-card.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t95.inf", 
		LAST);

	web_url("fin-auth-element-wrapper.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/fin-auth-element-wrapper.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t96.inf", 
		LAST);

	web_url("fin-auth-credit-card.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/fin-auth-credit-card.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t97.inf", 
		LAST);

	web_url("stepup-auth.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/stepup-auth.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t98.inf", 
		LAST);

	web_url("app-address.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-address.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t99.inf", 
		LAST);

	web_url("app-aggrid-material-theme.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/styles/app-aggrid-material-theme.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t100.inf", 
		LAST);

	web_url("app-aggrid-styles.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/styles/app-aggrid-styles.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t101.inf", 
		LAST);

	web_url("app-aggrid-custom-styles.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/styles/app-aggrid-custom-styles.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t102.inf", 
		LAST);

	web_url("google-chart.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/google-chart-polymer-3/google-chart.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t103.inf", 
		LAST);

	web_url("polymer-legacy.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/polymer-legacy.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t104.inf", 
		LAST);

	web_url("custom-style-interface.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@webcomponents/shadycss/entrypoints/custom-style-interface.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t105.inf", 
		LAST);

	web_url("style-gather.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/utils/style-gather.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t106.inf", 
		LAST);

	web_url("boot.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/utils/boot.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t107.inf", 
		LAST);

	web_url("mutable-data.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/mixins/mutable-data.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t108.inf", 
		LAST);

	web_url("property-effects.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/mixins/property-effects.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t109.inf", 
		LAST);

	web_url("gesture-event-listeners.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/mixins/gesture-event-listeners.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t110.inf", 
		LAST);

	web_url("settings.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/utils/settings.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t111.inf", 
		LAST);

	web_url("html-tag.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/utils/html-tag.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t112.inf", 
		LAST);

	web_url("mdl-grid-css.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/styles/mdl-grid-css.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t113.inf", 
		LAST);

	web_url("iron-resizable-behavior.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-resizable-behavior/iron-resizable-behavior.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t114.inf", 
		LAST);

	web_url("iron-selectable.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-selector/iron-selectable.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t115.inf", 
		LAST);

	web_url("polymer-element.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/polymer-element.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t116.inf", 
		LAST);

	web_url("paper-material-styles.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-styles/element-styles/paper-material-styles.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t117.inf", 
		LAST);

	web_url("polymer-fn.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/legacy/polymer-fn.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t118.inf", 
		LAST);

	web_url("paper-button-behavior.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-behaviors/paper-button-behavior.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t119.inf", 
		LAST);

	web_url("iron-meta.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-meta/iron-meta.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t120.inf", 
		LAST);

	web_url("polymer.dom.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/legacy/polymer.dom.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t121.inf", 
		LAST);

	web_url("resolve-url.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/utils/resolve-url.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t122.inf", 
		LAST);

	web_url("paper-dialog-shared-styles.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-dialog-behavior/paper-dialog-shared-styles.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t123.inf", 
		LAST);

	web_url("neon-animation-runner-behavior.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/neon-animation/neon-animation-runner-behavior.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t124.inf", 
		LAST);

	web_url("paper-dialog-behavior.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-dialog-behavior/paper-dialog-behavior.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t125.inf", 
		LAST);

	web_url("default-theme.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-styles/default-theme.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t126.inf", 
		LAST);

	web_url("paper-checked-element-behavior.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-behaviors/paper-checked-element-behavior.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t127.inf", 
		LAST);

	web_url("render-status.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/utils/render-status.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t128.inf", 
		LAST);

	web_url("paper-inky-focus-behavior.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-behaviors/paper-inky-focus-behavior.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t129.inf", 
		LAST);

	web_url("typography.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-styles/typography.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t130.inf", 
		LAST);

	web_url("case-map.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/utils/case-map.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t131.inf", 
		LAST);

	web_url("paper-item-shared-styles.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-item/paper-item-shared-styles.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t132.inf", 
		LAST);

	web_url("paper-item-behavior.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-item/paper-item-behavior.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t133.inf", 
		LAST);

	web_url("iron-overlay-behavior.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-overlay-behavior/iron-overlay-behavior.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t134.inf", 
		LAST);

	web_url("iron-a11y-announcer.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-a11y-announcer/iron-a11y-announcer.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t135.inf", 
		LAST);

	web_url("iron-a11y-keys-behavior.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-a11y-keys-behavior/iron-a11y-keys-behavior.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t136.inf", 
		LAST);

	web_url("iron-control-state.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-behaviors/iron-control-state.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t137.inf", 
		LAST);

	web_url("paper-input-addon-behavior.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-input/paper-input-addon-behavior.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t138.inf", 
		LAST);

	web_url("iron-menu-behavior.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-menu-behavior/iron-menu-behavior.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t139.inf", 
		LAST);

	web_url("shadow.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-styles/shadow.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t140.inf", 
		LAST);

	web_url("color.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-styles/color.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t141.inf", 
		LAST);

	web_url("paper-material-shared-styles.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-material/paper-material-shared-styles.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t142.inf", 
		LAST);

	web_url("paper-spinner-behavior.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-spinner/paper-spinner-behavior.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t143.inf", 
		LAST);

	web_url("paper-spinner-styles.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-spinner/paper-spinner-styles.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t144.inf", 
		LAST);

	web_url("iron-input.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-input/iron-input.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t145.inf", 
		LAST);

	web_url("iron-form-element-behavior.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-form-element-behavior/iron-form-element-behavior.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t146.inf", 
		LAST);

	web_url("iron-validatable-behavior.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-validatable-behavior/iron-validatable-behavior.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t147.inf", 
		LAST);

	web_url("date-input.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/gold-cc-expiration-input/date-input.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t148.inf", 
		LAST);

	web_url("cc-validator.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/gold-cc-input/cc-validator.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t149.inf", 
		LAST);

	web_url("gestures.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/utils/gestures.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t150.inf", 
		LAST);

	web_url("oe-common-mixin.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-mixins/oe-common-mixin.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t151.inf", 
		LAST);

	web_url("iron-request.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-ajax/iron-request.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t152.inf", 
		LAST);

	web_url("oe-utils.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-ajax/node_modules/oe-utils/oe-utils.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t153.inf", 
		LAST);

	web_url("oe-field-mixin.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-combo/node_modules/oe-mixins/oe-field-mixin.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t154.inf", 
		LAST);

	web_url("oe-templatize-mixin.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-combo/node_modules/oe-mixins/oe-templatize-mixin.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t155.inf", 
		LAST);

	web_url("class.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/legacy/class.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t156.inf", 
		LAST);

	web_url("oe-common-mixin.js_2", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-combo/node_modules/oe-mixins/oe-common-mixin.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t157.inf", 
		LAST);

	web_url("iron-dropdown.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-dropdown/iron-dropdown.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t158.inf", 
		LAST);

	web_url("iron-icons.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-icons/iron-icons.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t159.inf", 
		LAST);

	web_url("oe-cache-utils.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-utils/oe-cache-utils.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t160.inf", 
		LAST);

	web_url("oe-field-mixin.js_2", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-input/node_modules/oe-mixins/oe-field-mixin.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t161.inf", 
		LAST);

	web_url("oe-i18n-mixin.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-i18n-msg/oe-i18n-mixin.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t162.inf", 
		LAST);

	web_url("paper-input-char-counter.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-input/paper-input-char-counter.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t163.inf", 
		LAST);

	web_url("oe-input-styles.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-input/oe-input-styles.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t164.inf", 
		LAST);

	web_url("iron-autogrow-textarea.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-autogrow-textarea/iron-autogrow-textarea.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t165.inf", 
		LAST);

	web_url("currency-formator-behaviour.js_2", 
		"URL=https://finobunipreprod.test.uni.ca:4443/behaviors/currency-formator-behaviour.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t166.inf", 
		LAST);

	web_url("slide-from-bottom-animation.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/neon-animation/animations/slide-from-bottom-animation.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t167.inf", 
		LAST);

	web_url("slide-down-animation.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/neon-animation/animations/slide-down-animation.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t168.inf", 
		LAST);

	web_url("lodash.min.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/lodash/lodash.min.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t169.inf", 
		LAST);

	web_url("dir-mixin.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/mixins/dir-mixin.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t170.inf", 
		LAST);

	web_url("sb-app-storage-behavior.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/behaviors/sb-app-storage-behavior.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t171.inf", 
		LAST);

	web_url("online-registration.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_Registration_ui/behaviors/online-registration.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t172.inf", 
		LAST);

	web_url("elements.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/elements.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t173.inf", 
		LAST);

	web_url("templatizer-behavior.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/legacy/templatizer-behavior.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t174.inf", 
		LAST);

	web_url("dom-repeat.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/elements/dom-repeat.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t175.inf", 
		LAST);

	web_url("legacy-element-mixin.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/legacy/legacy-element-mixin.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t176.inf", 
		LAST);

	web_url("array-selector.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/elements/array-selector.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t177.inf", 
		LAST);

	web_url("dom-if.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/elements/dom-if.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t178.inf", 
		LAST);

	web_url("mutable-data-behavior.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/legacy/mutable-data-behavior.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t179.inf", 
		LAST);

	web_url("charts-loader.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/google-chart-polymer-3/charts-loader.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t180.inf", 
		LAST);

	web_url("google-chart-styles.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/google-chart-polymer-3/google-chart-styles.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t181.inf", 
		LAST);

	web_url("google-chart-loader.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/google-chart-polymer-3/google-chart-loader.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t182.inf", 
		LAST);

	web_url("custom-style-interface.js_2", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@webcomponents/shadycss/src/custom-style-interface.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t183.inf", 
		LAST);

	web_url("common-utils.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@webcomponents/shadycss/src/common-utils.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t184.inf", 
		LAST);

	web_url("style-settings.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@webcomponents/shadycss/src/style-settings.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t185.inf", 
		LAST);

	web_url("dom-module.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/elements/dom-module.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t186.inf", 
		LAST);

	web_url("mixin.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/utils/mixin.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t187.inf", 
		LAST);

	web_url("path.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/utils/path.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t188.inf", 
		LAST);

	web_url("property-accessors.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/mixins/property-accessors.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t189.inf", 
		LAST);

	web_url("template-stamp.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/mixins/template-stamp.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t190.inf", 
		LAST);

	web_url("element-mixin.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/mixins/element-mixin.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t191.inf", 
		LAST);

	web_url("iron-selection.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-selector/iron-selection.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t192.inf", 
		LAST);

	web_url("iron-button-state.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-behaviors/iron-button-state.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t193.inf", 
		LAST);

	web_url("paper-ripple-behavior.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-behaviors/paper-ripple-behavior.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t194.inf", 
		LAST);

	web_url("neon-animatable-behavior.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/neon-animation/neon-animatable-behavior.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t195.inf", 
		LAST);

	web_url("flattened-nodes-observer.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/utils/flattened-nodes-observer.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t196.inf", 
		LAST);

	web_url("flush.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/utils/flush.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t197.inf", 
		LAST);

	web_url("debounce.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/utils/debounce.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t198.inf", 
		LAST);

	web_url("iron-checked-element-behavior.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-checked-element-behavior/iron-checked-element-behavior.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t199.inf", 
		LAST);

	web_url("roboto.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/font-roboto/roboto.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t200.inf", 
		LAST);

	web_url("iron-fit-behavior.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-fit-behavior/iron-fit-behavior.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t201.inf", 
		LAST);

	web_url("iron-focusables-helper.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-overlay-behavior/iron-focusables-helper.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t202.inf", 
		LAST);

	web_url("iron-overlay-manager.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-overlay-behavior/iron-overlay-manager.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t203.inf", 
		LAST);

	web_url("iron-scroll-manager.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-overlay-behavior/iron-scroll-manager.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t204.inf", 
		LAST);

	web_url("iron-multi-selectable.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-selector/iron-multi-selectable.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t205.inf", 
		LAST);

	web_url("date-validator.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/gold-cc-expiration-input/date-validator.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t206.inf", 
		LAST);

	web_url("async.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/utils/async.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t207.inf", 
		LAST);

	web_url("oe-common-mixin.js_3", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-input/node_modules/oe-mixins/oe-common-mixin.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t208.inf", 
		LAST);

	web_url("templatize.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/utils/templatize.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t209.inf", 
		LAST);

	web_url("observe.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/observe-js/src/observe.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t210.inf", 
		LAST);

	web_url("neon-animation-behavior.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/neon-animation/neon-animation-behavior.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t211.inf", 
		LAST);

	web_url("apply-shim.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@webcomponents/shadycss/entrypoints/apply-shim.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t212.inf", 
		LAST);

	web_url("unresolved.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/utils/unresolved.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t213.inf", 
		LAST);

	web_url("array-splice.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/utils/array-splice.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t214.inf", 
		LAST);

	web_url("document-wait.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@webcomponents/shadycss/src/document-wait.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t215.inf", 
		LAST);

	web_url("common-regex.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@webcomponents/shadycss/src/common-regex.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t216.inf", 
		LAST);

	web_url("iron-iconset-svg.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-iconset-svg/iron-iconset-svg.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t217.inf", 
		LAST);

	web_url("properties-mixin.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/mixins/properties-mixin.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t218.inf", 
		LAST);

	web_url("properties-changed.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/polymer/lib/mixins/properties-changed.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t219.inf", 
		LAST);

	web_url("paper-ripple.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-ripple/paper-ripple.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t220.inf", 
		LAST);

	web_url("iron-overlay-backdrop.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-overlay-behavior/iron-overlay-backdrop.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t221.inf", 
		LAST);

	web_url("iron-validator-behavior.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-validator-behavior/iron-validator-behavior.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t222.inf", 
		LAST);

	web_url("apply-shim.js_2", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@webcomponents/shadycss/src/apply-shim.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t223.inf", 
		LAST);

	web_url("style-util.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@webcomponents/shadycss/src/style-util.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t224.inf", 
		LAST);

	web_url("template-map.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@webcomponents/shadycss/src/template-map.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t225.inf", 
		LAST);

	web_url("apply-shim-utils.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@webcomponents/shadycss/src/apply-shim-utils.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t226.inf", 
		LAST);

	web_url("css-parse.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@webcomponents/shadycss/src/css-parse.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t227.inf", 
		LAST);

	web_url("unscoped-style-handler.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@webcomponents/shadycss/src/unscoped-style-handler.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t228.inf", 
		LAST);

	web_url("uni-login.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/uni-login.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t229.inf", 
		LAST);

//	web_add_auto_header("Sec-Fetch-Site", 
//		"cross-site");
//
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"style");

	web_url("css", 
		"URL=https://fonts.googleapis.com/css?family=Roboto+Mono:400,700|Roboto:400,300,300italic,400italic,500,500italic,700,700italic", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=", 
		"Snapshot=t230.inf", 
		LAST);
	
	web_concurrent_end(NULL);


	web_revert_auto_header("Origin");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");
	
		web_concurrent_start("paykey",NULL);

	web_url("paykey", 
		"URL=https://finobunipreprod.test.uni.ca:4443/paykey", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t231.inf", 
		"Mode=HTTP", 
		LAST);

//	web_add_auto_header("Sec-Fetch-Dest", 
//		"script");
//
	web_add_header("Origin", 
		"https://finobunipreprod.test.uni.ca:4443");

	web_url("app-theme.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/styles/UNI/app-theme.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t232.inf", 
		LAST);

//	web_add_auto_header("Sec-Fetch-Dest", 
//		"empty");
//
	web_add_header("device", 
		"desktop");

	web_add_header("lang", 
		"en-US");

	web_add_header("tenantId", 
		"UNI");

	web_add_header("tenant_id", 
		"UNI");

	web_add_header("x-access-token", 
		"undefined");

	web_url("en-US.json", 
		"URL=https://finobunipreprod.test.uni.ca:4443/locales/en-US.json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t233.inf", 
		"Mode=HTTP", 
		LAST);

//	web_add_auto_header("Sec-Fetch-Dest", 
//		"image");
//
//	web_add_auto_header("Sec-Fetch-Mode", 
//		"no-cors");

	web_url("logo_1.png", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/images/UNI/login/logo_1.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=", 
		"Snapshot=t234.inf", 
		LAST);

	web_url("background_Image.jpg", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_Registration_ui/images/UNI/background_Image.jpg", 
		"Resource=1", 
		"RecContentType=image/jpeg", 
		"Referer=", 
		"Snapshot=t235.inf", 
		LAST);

	web_url("uni_bank_logo.png", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_Registration_ui/images/uni_bank_logo.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=", 
		"Snapshot=t236.inf", 
		LAST);

	web_url("slider-icon.png", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/images/UNI/login/slider-icon.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=", 
		"Snapshot=t237.inf", 
		LAST);

//	web_add_auto_header("Sec-Fetch-Dest", 
//		"script");

	web_add_header("Origin", 
		"https://finobunipreprod.test.uni.ca:4443");

//	web_add_auto_header("Sec-Fetch-Mode", 
//		"cors");

	web_url("elements-common.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/elements/elements-common.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t238.inf", 
		LAST);
		
		web_concurrent_end(NULL);


	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_header("device", 
		"desktop");

	web_add_header("lang", 
		"en-US");

	web_add_header("tenantId", 
		"UNI");

	web_add_header("tenant_id", 
		"UNI");

	web_add_header("x-access-token", 
		"undefined");
		
			web_concurrent_start("CurrencyConfigs",NULL);

	web_url("CurrencyConfigs", 
		"URL=https://finobunipreprod.test.uni.ca:4443/api/CurrencyConfigs", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t239.inf", 
		"Mode=HTTP", 
		LAST);

//	web_add_auto_header("Origin", 
//		"https://finobunipreprod.test.uni.ca:4443");
//
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"script");

	web_url("uni-activation.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/uni-activation.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t240.inf", 
		LAST);

	web_url("uni-showerror.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/uni-showerror.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t241.inf", 
		LAST);

	web_url("app-location.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/app-route/app-location.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t242.inf", 
		LAST);

	web_url("paper-scroll-header-panel.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-scroll-header-panel/paper-scroll-header-panel.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t243.inf", 
		LAST);

	web_url("paper-toolbar.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-toolbar/paper-toolbar.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t244.inf", 
		LAST);

	web_url("paper-tooltip.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-tooltip/paper-tooltip.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t245.inf", 
		LAST);

	web_url("iron-swipeable-container.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-swipeable-container/iron-swipeable-container.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t246.inf", 
		LAST);

	web_url("paper-password-input.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/paper-password-input/paper-password-input.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t247.inf", 
		LAST);

	web_url("match-passwords-validator.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/paper-password-input/match-passwords-validator.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t248.inf", 
		LAST);

	web_url("paper-tabs.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-tabs/paper-tabs.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t249.inf", 
		LAST);

	web_url("iron-form.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-form/iron-form.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t250.inf", 
		LAST);

	web_url("iron-collapse.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-collapse/iron-collapse.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t251.inf", 
		LAST);

//	web_revert_auto_header("Origin");
//
//	web_add_auto_header("Sec-Fetch-Mode", 
//		"no-cors");
//
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"image");

	web_url("uni.png", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/images/UNI/uni.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=", 
		"Snapshot=t252.inf", 
		LAST);

//	web_add_auto_header("Origin", 
//		"https://finobunipreprod.test.uni.ca:4443");
//
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"script");
//
//	web_add_auto_header("Sec-Fetch-Mode", 
//		"cors");

	web_url("iron-list.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-list/iron-list.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t253.inf", 
		LAST);

	web_url("iron-selector.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-selector/iron-selector.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t254.inf", 
		LAST);

	web_url("google-map.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/google-map/google-map.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t255.inf", 
		LAST);

	web_url("google-map-marker.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/google-map/google-map-marker.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t256.inf", 
		LAST);

	web_url("s-circle-progress.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/s-circle-progress/s-circle-progress.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t257.inf", 
		LAST);

	web_url("meta-polymer.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-ui-forms/meta-polymer.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t258.inf", 
		LAST);

	web_url("oe-radio-group.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-radio-group/oe-radio-group.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t259.inf", 
		LAST);

	web_url("oe-toggle.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-toggle/oe-toggle.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t260.inf", 
		LAST);

	web_url("oe-checkbox.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-checkbox/oe-checkbox.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t261.inf", 
		LAST);

	web_url("oe-decimal.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-input/oe-decimal.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t262.inf", 
		LAST);

	web_url("oe-date.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-date/oe-date.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t263.inf", 
		LAST);

	web_url("oe-date-range.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-date-range/oe-date-range.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t264.inf", 
		LAST);

	web_url("oe-info.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-info/oe-info.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t265.inf", 
		LAST);

	web_url("from-account-selector.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/from-account-selector.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t266.inf", 
		LAST);

	web_url("page-title.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/page-title.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t267.inf", 
		LAST);

	web_url("header-panel.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/header-panel.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t268.inf", 
		LAST);

	web_concurrent_end(NULL);


	web_revert_auto_header("Origin");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_header("device", 
		"desktop");

	web_add_header("lang", 
		"en-US");

	web_add_header("tenantId", 
		"UNI");

	web_add_header("tenant_id", 
		"UNI");

//	web_add_header("x-access-token", 
//		"undefined");
	
		web_concurrent_start("Concurrent1",NULL);

	web_url("en-US.json_2", 
		"URL=https://finobunipreprod.test.uni.ca:4443/api/CustomLiterals/render/en-US.json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t269.inf", 
		"Mode=HTTP", 
		LAST);

//	web_add_auto_header("Origin", 
//		"https://finobunipreprod.test.uni.ca:4443");
//
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"script");

	web_url("oe-app-route.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-app-route/oe-app-route.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t270.inf", 
		LAST);

	web_url("desktop-nav.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/desktop-nav.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t271.inf", 
		LAST);

	web_url("paper-dropdown-menu.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-dropdown-menu/paper-dropdown-menu.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t272.inf", 
		LAST);

	web_url("app-sub-header.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-sub-header.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t273.inf", 
		LAST);

	web_url("app-data.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-data.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t274.inf", 
		LAST);

	web_url("supporting-msg.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/supporting-msg.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t275.inf", 
		LAST);

	web_url("app-footer.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-footer.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t276.inf", 
		LAST);

	web_url("uni-footer.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/uni-footer.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t277.inf", 
		LAST);

	web_url("app-success-page.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-success-page.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t278.inf", 
		LAST);

//	web_revert_auto_header("Origin");
//
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"empty");

//	web_add_header("device", 
//		"desktop");
//
//	web_add_header("lang", 
//		"en-US");
//
//	web_add_header("tenantId", 
//		"UNI");
//
//	web_add_header("tenant_id", 
//		"UNI");
//
//	web_add_header("x-access-token", 
//		"undefined");
//
//	web_custom_request("propertyreferences", 
//		"URL=https://finobunipreprod.test.uni.ca:4443/api/propertyreferences?filter[where][propertyName]=SHOW_PHASE2_FUNCTIONALITIES", 
//		"Method=GET", 
//		"Resource=0", 
//		"RecContentType=application/json", 
//		"Referer=", 
//		"Snapshot=t279.inf", 
//		"Mode=HTTP", 
//		"EncType=application/json", 
//		LAST);

//	web_add_auto_header("Origin", 
//		"https://finobunipreprod.test.uni.ca:4443");
//
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"script");

	web_url("share-doc.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/share-doc.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t280.inf", 
		LAST);

	web_url("app-currency-selector.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-currency-selector.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t281.inf", 
		LAST);

	web_url("sb-loader.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/sb-loader.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t282.inf", 
		LAST);

	web_url("app-paper-slider.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-paper-slider.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t283.inf", 
		LAST);

	web_url("app-file-input.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-file-input.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t284.inf", 
		LAST);

	web_url("app-chip-list.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-chip-list.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t285.inf", 
		LAST);

	web_url("app-password.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-password.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t286.inf", 
		LAST);

	web_url("app-slide-in-out-transition.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-slide-in-out-transition.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t287.inf", 
		LAST);

	web_url("currency-formator.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/currency-formator.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t288.inf", 
		LAST);

	web_url("security-question.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/security-question.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t289.inf", 
		LAST);

	web_url("channel-registration.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/channel-registration.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t290.inf", 
		LAST);

	web_url("prelogin-auth.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/prelogin-auth.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t291.inf", 
		LAST);

	web_url("sb-phone.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/primitives/sb-phone.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t292.inf", 
		LAST);

	web_url("iron-query-params.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-location/iron-query-params.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t293.inf", 
		LAST);

	web_url("iron-location.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-location/iron-location.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t294.inf", 
		LAST);

//	web_revert_auto_header("Origin");
//
//	web_add_auto_header("Sec-Fetch-Mode", 
//		"no-cors");
//
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"image");

	web_url("your-bank-logo.gif", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/images/UNI/loader/your-bank-logo.gif", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=", 
		"Snapshot=t295.inf", 
		LAST);

//	web_add_auto_header("Origin", 
//		"https://finobunipreprod.test.uni.ca:4443");
//
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"script");
//
//	web_add_auto_header("Sec-Fetch-Mode", 
//		"cors");

	web_url("app-route-converter-behavior.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/app-route/app-route-converter-behavior.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t296.inf", 
		LAST);

	web_url("paper-input.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-input/paper-input.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t297.inf", 
		LAST);

	web_url("paper-tabs-icons.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-tabs/paper-tabs-icons.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t298.inf", 
		LAST);

	web_url("iron-menubar-behavior.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-menu-behavior/iron-menubar-behavior.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t299.inf", 
		LAST);

	web_url("iron-ajax.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-ajax/iron-ajax.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t300.inf", 
		LAST);

	web_url("paper-tab.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-tabs/paper-tab.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t301.inf", 
		LAST);

//	web_revert_auto_header("Origin");
//
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"empty");

//	web_add_header("device", 
//		"desktop");
//
//	web_add_header("lang", 
//		"en-US");
//
//	web_add_header("tenantId", 
//		"UNI");
//
//	web_add_header("tenant_id", 
//		"UNI");
//
//	web_add_header("x-access-token", 
//		"undefined");
//
//	web_custom_request("propertyreferences_2", 
//		"URL=https://finobunipreprod.test.uni.ca:4443/api/propertyreferences?filter[where][propertyName]=SHOW_PHASE2_FUNCTIONALITIES", 
//		"Method=GET", 
//		"Resource=0", 
//		"RecContentType=application/json", 
//		"Referer=", 
//		"Snapshot=t302.inf", 
//		"Mode=HTTP", 
//		"EncType=application/json", 
//		LAST);

//	web_add_auto_header("Origin", 
//		"https://finobunipreprod.test.uni.ca:4443");
//
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"script");

	web_url("iron-scroll-target-behavior.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-scroll-target-behavior/iron-scroll-target-behavior.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t303.inf", 
		LAST);

	web_url("google-maps-api.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/google-apis/google-maps-api.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t304.inf", 
		LAST);

	web_url("oe-utils-mixin.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-ui-forms/node_modules/oe-mixins/oe-utils-mixin.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t305.inf", 
		LAST);

	web_url("oe-common-mixin.js_4", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-ui-forms/node_modules/oe-mixins/oe-common-mixin.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t306.inf", 
		LAST);

	web_url("oe-utils.js_2", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-utils/oe-utils.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t307.inf", 
		LAST);

	web_url("date-utils.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-utils/date-utils.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t308.inf", 
		LAST);

	web_url("paper-radio-button.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-radio-button/paper-radio-button.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t309.inf", 
		LAST);

	web_url("paper-radio-group.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-radio-group/paper-radio-group.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t310.inf", 
		LAST);

	web_url("oe-field-mixin.js_3", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-mixins/oe-field-mixin.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t311.inf", 
		LAST);

	web_url("paper-toggle-button.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-toggle-button/paper-toggle-button.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t312.inf", 
		LAST);

	web_url("oe-decimal-mixin.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-input/oe-decimal-mixin.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t313.inf", 
		LAST);

	web_url("oe-field-mixin.js_4", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-date/node_modules/oe-mixins/oe-field-mixin.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t314.inf", 
		LAST);

	web_url("oe-date-mixin.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-date/oe-date-mixin.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t315.inf", 
		LAST);

	web_url("oe-datepicker.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-date/oe-datepicker.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t316.inf", 
		LAST);

	web_url("oe-common-mixin.js_5", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-date-range/node_modules/oe-mixins/oe-common-mixin.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t317.inf", 
		LAST);

	web_url("oe-datepicker-dlg.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-date/oe-datepicker-dlg.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t318.inf", 
		LAST);

	web_url("oe-field-mixin.js_5", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-date-range/node_modules/oe-mixins/oe-field-mixin.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t319.inf", 
		LAST);

	web_url("data-mask-mixin.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-info/node_modules/oe-mixins/data-mask-mixin.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t320.inf", 
		LAST);

	web_url("oe-date-range-picker.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-date-range/oe-date-range-picker.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t321.inf", 
		LAST);

	web_url("oe-field-mixin.js_6", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-info/node_modules/oe-mixins/oe-field-mixin.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t322.inf", 
		LAST);

	web_url("sb-alerts.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/sb-alerts.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t323.inf", 
		LAST);

	web_url("go-to.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/go-to.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t324.inf", 
		LAST);

	web_url("log-out.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/log-out.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t325.inf", 
		LAST);

	web_url("paper-menu-button.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-menu-button/paper-menu-button.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t326.inf", 
		LAST);

	web_url("paper-dropdown-menu-shared-styles.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-dropdown-menu/paper-dropdown-menu-shared-styles.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t327.inf", 
		LAST);

	web_url("paper-dropdown-menu-icons.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-dropdown-menu/paper-dropdown-menu-icons.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t328.inf", 
		LAST);

	web_url("create-tabs.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/behaviors/create-tabs.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t329.inf", 
		LAST);

	web_url("oe-common-mixin.js_6", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-app-route/node_modules/oe-mixins/oe-common-mixin.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t330.inf", 
		LAST);

	web_url("pathtoregexp.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-app-route/scripts/pathtoregexp.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t331.inf", 
		LAST);

	web_url("hybrid-app-fix.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-app-route/scripts/hybrid-app-fix.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t332.inf", 
		LAST);

	web_url("navigation-utils.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-app-route/scripts/navigation-utils.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t333.inf", 
		LAST);

	web_url("jspdf.min.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/jspdf/dist/jspdf.min.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t334.inf", 
		LAST);

	web_url("paper-range-slider.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/paper-range-slider/paper-range-slider.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t335.inf", 
		LAST);

	web_url("oe-templatize-mixin.js_2", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-mixins/oe-templatize-mixin.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t336.inf", 
		LAST);

	web_url("authAndSubmit.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_transfer_ui/behaviors/authAndSubmit.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t337.inf", 
		LAST);

	web_url("authAndSubmitCorp.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/behaviors/authAndSubmitCorp.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t338.inf", 
		LAST);

	web_url("log-out-behaviour.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/behaviors/log-out-behaviour.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t339.inf", 
		LAST);

	web_url("prelogin-auth-submit.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/behaviors/prelogin-auth-submit.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t340.inf", 
		LAST);

	web_url("reset-user-verification-behaviour.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/behaviors/reset-user-verification-behaviour.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t341.inf", 
		LAST);

	web_url("oe-common-mixin.js_7", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-date/node_modules/oe-mixins/oe-common-mixin.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t342.inf", 
		LAST);

	web_url("iron-jsonp-library.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-jsonp-library/iron-jsonp-library.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t343.inf", 
		LAST);

	web_url("paper-styles.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-styles/paper-styles.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t344.inf", 
		LAST);

	web_url("oe-common-mixin.js_8", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-info/node_modules/oe-mixins/oe-common-mixin.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t345.inf", 
		LAST);

	web_url("fin-voice-input.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/fin-voice-input.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t346.inf", 
		LAST);

	web_url("fade-out-animation.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/neon-animation/animations/fade-out-animation.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t347.inf", 
		LAST);

	web_url("fade-in-animation.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/neon-animation/animations/fade-in-animation.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t348.inf", 
		LAST);

	web_url("paper-menu-button-animations.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-menu-button/paper-menu-button-animations.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t349.inf", 
		LAST);

	web_url("paper-single-range-slider.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/paper-range-slider/paper-single-range-slider.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t350.inf", 
		LAST);

//	web_revert_auto_header("Origin");
//
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"empty");

	web_add_header("device", 
		"desktop");

	web_add_header("lang", 
		"en-US");

	web_add_header("tenantId", 
		"UNI");

	web_add_header("tenant_id", 
		"UNI");

	web_add_header("x-access-token", 
		"undefined");

	web_custom_request("TypeMappings", 
		"URL=https://finobunipreprod.test.uni.ca:4443/api/TypeMappings", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t351.inf", 
		"Mode=HTTP", 
		LAST);

//	web_add_auto_header("Sec-Fetch-Mode", 
//		"no-cors");
//
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"image");

	web_url("cdic-digital-symbol.svg", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/images/sb_images/cdic-digital-symbol.svg", 
		"Resource=1", 
		"RecContentType=image/svg+xml", 
		"Referer=", 
		"Snapshot=t352.inf", 
		LAST);

//	web_add_auto_header("Origin", 
//		"https://finobunipreprod.test.uni.ca:4443");
//
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"script");
//
//	web_add_auto_header("Sec-Fetch-Mode", 
//		"cors");

	web_url("iron-range-behavior.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-range-behavior/iron-range-behavior.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t353.inf", 
		LAST);

	web_url("paper-progress.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-progress/paper-progress.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t354.inf", 
		LAST);

//	web_revert_auto_header("Origin");
//
//	web_add_auto_header("Sec-Fetch-Mode", 
//		"no-cors");
//
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"image");

	web_url("title.png", 
		"URL=https://finobunipreprod.test.uni.ca:4443/images/UNI/title.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=", 
		"Snapshot=t355.inf", 
		LAST);
	
	web_concurrent_end(NULL);


	web_add_auto_header("Origin", 
		"https://finobunipreprod.test.uni.ca:4443");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("device", 
		"desktop");

	web_add_auto_header("lang", 
		"en-US");

	web_add_auto_header("tenantId", 
		"UNI");

	web_add_auto_header("tenant_id", 
		"UNI");

	web_add_auto_header("x-access-token", 
		"undefined");
	
		   web_reg_save_param("C_userID",
		"LB=\"objectID\":\"",
		"RB=\"",
		LAST);


	web_custom_request("azure", 
		"URL=https://finobunipreprod.test.uni.ca:4443/azure", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t356.inf", 
		"Mode=HTTP", 
		"EncType=application/json", 
		"Body={\"token\":\""
		"{C_token}\"}",
		LAST);
	
		web_concurrent_start("loginmodes",NULL);

/*Correlation comment - Do not change!  Original value='RET0000082' Name ='C_userID1' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=C_userID1",
		"RegExp=Users\"},\"userId\":\"(.*?)\",",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		LAST);

	web_custom_request("loginmodes", 
		"URL=https://finobunipreprod.test.uni.ca:4443/auth/loginmodes", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t357.inf", 
		"Mode=HTTP", 
		"EncType=application/json", 
		"Body={\"channel_id\":\"I\",\"isNotificationsEnabled\":true,\"username\":\"{C_userID}\",\"isAzureLoginFlow\":true}", 
		LAST);

//	web_revert_auto_header("device");
//
//	web_revert_auto_header("lang");
//
//	web_revert_auto_header("tenantId");
//
//	web_revert_auto_header("tenant_id");
//
//	web_revert_auto_header("x-access-token");
//
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"script");

	web_url("elements-speedup.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/elements/elements-speedup.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t358.inf", 
		LAST);

	web_url("elements-common-speedup.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/elements/elements-common-speedup.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t359.inf", 
		LAST);

	web_url("elements-corporate-speedup.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/elements/elements-corporate-speedup.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t360.inf", 
		LAST);

	web_url("elements-dashboard.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/elements-dashboard.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t361.inf", 
		LAST);

	web_url("corporate-dashboard.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/corporate-dashboard.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t362.inf", 
		LAST);

	web_url("paper-badge.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-badge/paper-badge.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t363.inf", 
		LAST);

	web_url("paper-fab.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-fab/paper-fab.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t364.inf", 
		LAST);

	web_url("neon-animated-pages.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/neon-animation/neon-animated-pages.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t365.inf", 
		LAST);

	web_url("profile-main.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/profile-main.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t366.inf", 
		LAST);

	web_url("app-month-selector.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-month-selector.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t367.inf", 
		LAST);

//	web_revert_auto_header("Origin");
//
//	web_revert_auto_header("sec-ch-ua");
//
//	web_revert_auto_header("sec-ch-ua-mobile");
//
//	web_revert_auto_header("sec-ch-ua-platform");

	

//	web_add_auto_header("Origin", 
//		"https://finobunipreprod.test.uni.ca:4443");
//
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"script");
//
//	web_add_auto_header("Sec-Fetch-Mode", 
//		"cors");
//
//	web_add_auto_header("Sec-Fetch-Site", 
//		"same-origin");
//
//	web_add_auto_header("sec-ch-ua", 
//		"\"Google Chrome\";v=\"113\", \"Chromium\";v=\"113\", \"Not-A.Brand\";v=\"24\"");
//
//	web_add_auto_header("sec-ch-ua-mobile", 
//		"?0");
//
//	web_add_auto_header("sec-ch-ua-platform", 
//		"\"Windows\"");

	web_url("low-balance.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/low-balance.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t369.inf", 
		LAST);

	web_url("app-select-address.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-select-address.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t370.inf", 
		LAST);

	web_url("error-msg.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/error-msg.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t371.inf", 
		LAST);

	web_url("service-unavailable.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/service-unavailable.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t372.inf", 
		LAST);

	web_url("profile-info.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/profile-info.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t373.inf", 
		LAST);

//	web_revert_auto_header("Origin");
//
//	web_revert_auto_header("sec-ch-ua");
//
//	web_revert_auto_header("sec-ch-ua-mobile");
//
//	web_revert_auto_header("sec-ch-ua-platform");
//
//
//
//	web_add_auto_header("Origin", 
//		"https://finobunipreprod.test.uni.ca:4443");
//
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"script");
//
//	web_add_auto_header("Sec-Fetch-Mode", 
//		"cors");
//
//	web_add_auto_header("Sec-Fetch-Site", 
//		"same-origin");
//
//	web_add_auto_header("sec-ch-ua", 
//		"\"Google Chrome\";v=\"113\", \"Chromium\";v=\"113\", \"Not-A.Brand\";v=\"24\"");
//
//	web_add_auto_header("sec-ch-ua-mobile", 
//		"?0");
//
//	web_add_auto_header("sec-ch-ua-platform", 
//		"\"Windows\"");

	web_url("service-req-cancel-success.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_servicerequest_ui/elements/service-req-cancel-success.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t375.inf", 
		LAST);

	web_url("geo-coding-reverse.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_transfer_ui/elements/geo-coding-reverse.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t376.inf", 
		LAST);

	web_url("similar-txn-list.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_transfer_ui/elements/similar-txn-list.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t377.inf", 
		LAST);

	web_url("bills-shared-styles.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_transfer_ui/styles/bills-shared-styles.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t378.inf", 
		LAST);

	web_url("app-progress-bar.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-progress-bar.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t379.inf", 
		LAST);

	web_url("password-validator.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/password-validator.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t380.inf", 
		LAST);

	web_url("search-bank-result.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_transfer_ui/elements/search-bank-result.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t381.inf", 
		LAST);

	web_url("biller-header.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_transfer_ui/elements/biller-header.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t382.inf", 
		LAST);

	web_url("edit-contact.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_transfer_ui/elements/edit-contact.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t383.inf", 
		LAST);

	web_url("transaction-filter-dialog.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_transfer_ui/elements/transaction-filter-dialog.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t384.inf", 
		LAST);

	web_url("transaction-record.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_transfer_ui/elements/transaction-record.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t385.inf", 
		LAST);

	web_url("registered-products-landing.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/registered-products-landing.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t386.inf", 
		LAST);

	web_url("registered-products-overview.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/registered-products-overview.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t387.inf", 
		LAST);

	web_url("registered-products-withdraw.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/registered-products-withdraw.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t388.inf", 
		LAST);

	web_url("registered-products-details.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/registered-products-details.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t389.inf", 
		LAST);

	web_url("verification-page.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/verification-page.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t390.inf", 
		LAST);

	web_url("registered-products-contribute.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/registered-products-contribute.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t391.inf", 
		LAST);

	web_url("registered-products-transaction-history.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/registered-products-transaction-history.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t392.inf", 
		LAST);

	web_url("paper-slider.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/paper-slider/paper-slider.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t393.inf", 
		LAST);

	web_url("iron-scroll-threshold.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-scroll-threshold/iron-scroll-threshold.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t394.inf", 
		LAST);

	web_url("iron-a11y-keys.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/iron-a11y-keys/iron-a11y-keys.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t395.inf", 
		LAST);

	web_url("jquery.min.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/jquery/dist/jquery.min.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t396.inf", 
		LAST);

	web_url("oe-block-validator.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-ui-forms/validators/oe-block-validator.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t397.inf", 
		LAST);

	web_url("add-contact.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_transfer_ui/behaviors/add-contact.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t398.inf", 
		LAST);

	web_url("app-stepper.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-stepper.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t399.inf", 
		LAST);

	web_url("app-success-receipt.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-success-receipt.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t400.inf", 
		LAST);

	web_url("app-drop-down.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-drop-down.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t401.inf", 
		LAST);

	web_url("list-search.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/list-search.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t402.inf", 
		LAST);

	web_url("app-swiper.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-swiper.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t403.inf", 
		LAST);

	web_url("app-amount-currency.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_meta_ui/elements/app-amount-currency.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t404.inf", 
		LAST);

	web_url("card-block-success.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_servicerequest_ui/elements/card-block-success.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t405.inf", 
		LAST);

	web_url("disable-card-landing.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_servicerequest_ui/elements/disable-card-landing.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t406.inf", 
		LAST);

	web_url("subscription-details-input.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/subscription-details-input.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t407.inf", 
		LAST);

	web_url("disable-temp-card-landing.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_servicerequest_ui/elements/disable-temp-card-landing.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t408.inf", 
		LAST);

	web_url("profile-summary.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/profile-summary.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t409.inf", 
		LAST);

	web_url("profile-financials.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/profile-financials.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t410.inf", 
		LAST);

	web_url("change-comm-address.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/change-comm-address.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t411.inf", 
		LAST);

	web_url("edit-communication-address.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/edit-communication-address.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t412.inf", 
		LAST);

	web_url("app-file-upload.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/behaviors/app-file-upload.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t413.inf", 
		LAST);

	web_url("app-file-upload.js_2", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/elements/app-file-upload.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t414.inf", 
		LAST);

	web_url("app-listbox.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/app-listbox.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t415.inf", 
		LAST);

	web_url("pagination-behavior.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/behaviors/pagination-behavior.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t416.inf", 
		LAST);

	web_url("app-button.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-button.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t417.inf", 
		LAST);

	web_url("retail-filter.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/retail-filter.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t418.inf", 
		LAST);

	web_url("retail-details-template-holder.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/retail-details-template-holder.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t419.inf", 
		LAST);
	web_concurrent_end(NULL);


	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_header("device", 
		"desktop");

	web_add_header("lang", 
		"en-US");

	web_add_header("tenantId", 
		"UNI");

	web_add_header("tenant_id", 
		"UNI");

	web_add_header("x-access-token", 
		"undefined");

/*Correlation comment - Do not change!  Original value='EqOqItKxSN6BoRwWDRDDE9OTlD04PBZbx3rcqAgRV3xg8ZU11kjHo0VjW3cbbJmh' Name ='C_Authorization' Type ='Manual'*/
//	web_reg_save_param_regexp(
//		"ParamName=C_Authorization",
//		"RegExp=\"preferredTimeZone\":\"\",\"transactionAllowed\":\"Y\",\"id\":\"(.*?)\",",
//		SEARCH_FILTERS,
//		"Scope=Body",
//		"IgnoreRedirections=No",
//		LAST);
	
				web_reg_save_param_ex(
		"ParamName=C_Authorization",
		"LB/IC=\"preferredTimeZone\":\"\",\"transactionAllowed\":\"Y\",\"id\":\"",
		"RB/IC=\",\"ttl\"",
		SEARCH_FILTERS,
		"Scope=Body",
		LAST);
		
		
	//web_concurrent_start("login",NULL);
					


	web_custom_request("login", 
		"URL=https://finobunipreprod.test.uni.ca:4443/auth/login", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t420.inf", 
		"Mode=HTTP", 
		"EncType=application/json", 
//		"Body={\"password\":\"d#demo\",\"roles\":\"consumer\",\"adminFlag\":\"false\",\"bank_id\":\"UNI\",\"loginFlag\":1,\"corpPrincipal\":\"UNI\",\"isNotificationsEnabled\":true,\"loginType\":\"credentials\",\"channelId\":\"I\",\"username\":\"{C_userID}\",\"language_id\":\"001\",\"symKey\":\"nKjmLjdtSQp5OYyZmlry8bI78wPGGZxQjISx106eKJShTxuT9DjFJqo+EN7ZrAFU0vbzXHf0jiKiHadJ/uhxofvKWiaTRSrXfCTqzpG5TxBLqeuRxS9wXmMcYOX6esi2GeCo19AvFklAXncThtgYJtgmiUUw/pUMiI6PH+ZkW2ZPc8PpHTrr/"
//		"YNFV0IyPW1EJ2Av9r0+3fjIECWiiwjMrV3rrJ9NQuyPrmFCWaw0nOZxD7pCwaW4ZPuLtp6hrDyd2wdepnscmYACXpPmmGYEAcqAdIKTlizXbHb24Yk5Ax/ubOyi7MQPy5ZYUkXystqTTzN+stZq1eSneUOPTHSc4Q==\"}", 
		"Body={\"password\":\"d#demo\",\"roles\":\"consumer\",\"adminFlag\":\"false\",\"bank_id\":\"UNI\",\"loginFlag\":1,\"corpPrincipal\":\"UNI\",\"isNotificationsEnabled\":true,\"loginType\":\"credentials\",\"channelId\":\"I\",\"username\":\"{C_userID}\",\"language_id\":\"001\",\"symKey\":\"{P_Symkey}\"}",
		LAST);

//	web_add_auto_header("Sec-Fetch-Dest", 
//		"script");

	web_url("app-file-attachment.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/elements/app-file-attachment.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t421.inf", 
		LAST);

	web_url("view-ticker-messages-carousel.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/view-ticker-messages-carousel.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t422.inf", 
		LAST);

	web_url("corporate-success-page.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/corporate-success-page.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t423.inf", 
		LAST);

	web_url("app-frequency.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/elements/app-frequency.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t424.inf", 
		LAST);

	web_url("credit-card-block-template.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/credit-card-block-template.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t425.inf", 
		LAST);

	web_url("schedule-transaction.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_transfer_ui/elements/schedule-transaction.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t426.inf", 
		LAST);

	web_url("app-card-dashboard.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-card-dashboard.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t427.inf", 
		LAST);

	web_url("biller-offer-offline.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_transfer_ui/elements/biller-offer-offline.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t428.inf", 
		LAST);

	web_url("add-new-contact-auth.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_transfer_ui/elements/add-new-contact-auth.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t429.inf", 
		LAST);
				
	//web_concurrent_end(NULL);


	web_revert_auto_header("Origin");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("device", 
		"desktop");

	web_add_auto_header("lang", 
		"en-US");

	web_add_auto_header("tenantId", 
		"UNI");

	web_add_auto_header("tenant_id", 
		"UNI");

	web_add_auto_header("x-access-token",
		"{C_Authorization}");
	
	web_concurrent_start(NULL);


	web_custom_request("codereferences", 
		"URL=https://finobunipreprod.test.uni.ca:4443/api/codereferences?filter[where][codeType]=CCNV&filter[order]=codeDescription", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t430.inf", 
		"Mode=HTTP", 
		"EncType=application/json", 
		LAST);

//	web_custom_request("propertyreferences_3", 
//		"URL=https://finobunipreprod.test.uni.ca:4443/api/propertyreferences?filter[where][propertyName]=CHILD_ACCNT_SCHEME_CODE", 
//		"Method=GET", 
//		"Resource=0", 
//		"RecContentType=application/json", 
//		"Referer=", 
//		"Snapshot=t431.inf", 
//		"Mode=HTTP", 
//		"EncType=application/json", 
//		LAST);

//	web_custom_request("propertyreferences_4", 
//		"URL=https://finobunipreprod.test.uni.ca:4443/api/propertyreferences?filter[where][propertyName]=SPRINT_15", 
//		"Method=GET", 
//		"Resource=0", 
//		"RecContentType=application/json", 
//		"Referer=", 
//		"Snapshot=t432.inf", 
//		"Mode=HTTP", 
//		"EncType=application/json", 
//		LAST);

//	web_revert_auto_header("device");
//
//	web_revert_auto_header("lang");
//
//	web_revert_auto_header("tenantId");
//
//	web_revert_auto_header("tenant_id");
//
//	web_revert_auto_header("x-access-token");
//
//	web_add_auto_header("Origin", 
//		"https://finobunipreprod.test.uni.ca:4443");
//
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"script");

	web_url("amount-prediction.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_transfer_ui/elements/amount-prediction.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t433.inf", 
		LAST);

	web_url("pay-contact.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_transfer_ui/elements/pay-contact.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t434.inf", 
		LAST);

	web_url("app-toggle-button.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/elements/app-toggle-button.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t435.inf", 
		LAST);

	web_url("search-box.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_transfer_ui/elements/search-box.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t436.inf", 
		LAST);

	web_url("acc-suggestion-list.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/acc-suggestion-list.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t437.inf", 
		LAST);

	web_url("swiper.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/swiper/dist/js/swiper.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t438.inf", 
		LAST);

	web_url("app-download.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/elements/app-download.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t439.inf", 
		LAST);

	web_url("app-data-selection.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/elements/app-data-selection.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t440.inf", 
		LAST);

//	web_revert_auto_header("Origin");
//
//	web_add_auto_header("Sec-Fetch-Mode", 
//		"no-cors");
//
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"image");

	web_url("uni_bank_logo.png_2", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/images/UNI/sb_icons/uni_bank_logo.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=", 
		"Snapshot=t441.inf", 
		LAST);

//	web_add_auto_header("Sec-Fetch-Dest", 
//		"font");
//
//	web_add_auto_header("Origin", 
//		"https://finobunipreprod.test.uni.ca:4443");
//
//	web_add_auto_header("Sec-Fetch-Mode", 
//		"cors");

	web_url("Roboto-Bold.ttf", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/@polymer/font-roboto-local/fonts/roboto/Roboto-Bold.ttf", 
		"Resource=1", 
		"RecContentType=font/ttf", 
		"Referer=", 
		"Snapshot=t442.inf", 
		LAST);

//	web_add_auto_header("Sec-Fetch-Dest", 
//		"script");

	web_url("custom-input-with-default-value.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/custom-input-with-default-value.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t443.inf", 
		LAST);

	web_url("address-template-details-view.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/address-template-details-view.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t444.inf", 
		LAST);

	web_url("change-pickup-address-overlay.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/change-pickup-address-overlay.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t445.inf", 
		LAST);

//	web_revert_auto_header("Origin");
//
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"empty");

	web_add_header("device", 
		"desktop");

	web_add_header("lang", 
		"en-US");

	web_add_header("tenantId", 
		"UNI");

	web_add_header("x-access-token",
		"{C_Authorization}");

	web_add_header("x-forwarded-for", 
		"10.200.25.1");

	web_url("UIRoutes", 
		"URL=https://finobunipreprod.test.uni.ca:4443/api/UIRoutes?filter={%22where%22:{}}", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t446.inf", 
		"Mode=HTTP", 
		LAST);

//	web_add_auto_header("Origin", 
//		"https://finobunipreprod.test.uni.ca:4443");
//
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"script");

	web_url("app-template-swiper.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-template-swiper.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t447.inf", 
		LAST);

	web_url("app-state-selector.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-state-selector.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t448.inf", 
		LAST);

	web_url("service-request-message.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/service-request-message.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t449.inf", 
		LAST);

	web_url("corporate-settings-mobile.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/corporate-settings-mobile.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t450.inf", 
		LAST);

	web_url("app-data-selection-with-chips.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/elements/app-data-selection-with-chips.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t451.inf", 
		LAST);

	web_url("app-next-best-actions.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-next-best-actions.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t452.inf", 
		LAST);

	web_url("address-details-view.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_tfin_ui/elements/address-details-view.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t453.inf", 
		LAST);

	web_url("app-sort-criteria.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-sort-criteria.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t454.inf", 
		LAST);

	web_url("account-transaction-dispute.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_meta_ui/elements/account-transaction-dispute.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t455.inf", 
		LAST);

	web_url("app-tax-identifier.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-tax-identifier.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t456.inf", 
		LAST);

	web_url("drag-and-drop.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/elements/drag-and-drop.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t457.inf", 
		LAST);

	web_url("adhoc-payment.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_transfer_ui/elements/adhoc-payment.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t458.inf", 
		LAST);

	web_url("app-fab-chip.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-fab-chip.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t459.inf", 
		LAST);

	web_url("app-file-download.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/elements/app-file-download.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t460.inf", 
		LAST);

	web_url("loan-data-review-page.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/loan-data-review-page.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t461.inf", 
		LAST);

	web_url("retail-dashboard-behavior.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/behaviors/retail-dashboard-behavior.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t462.inf", 
		LAST);

	web_url("dashboard-landing.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/dashboard-landing.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t463.inf", 
		LAST);

	web_url("dashboard-user-relationship.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/dashboard-user-relationship.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t464.inf", 
		LAST);

	web_url("dashboard-user-actions.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/dashboard-user-actions.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t465.inf", 
		LAST);

	web_url("dashboard-account-inquiry.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/dashboard-account-inquiry.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t466.inf", 
		LAST);

	web_url("dashboard-user-info.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/dashboard-user-info.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t467.inf", 
		LAST);

//	web_add_auto_header("Sec-Fetch-Site", 
//		"cross-site");
//
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"font");

	web_url("KFOmCnqEu92Fr1Mu4mxK.woff2", 
		"URL=https://fonts.gstatic.com/s/roboto/v30/KFOmCnqEu92Fr1Mu4mxK.woff2", 
		"Resource=1", 
		"RecContentType=font/woff2", 
		"Referer=https://fonts.googleapis.com/", 
		"Snapshot=t468.inf", 
		LAST);

//	web_add_auto_header("Sec-Fetch-Dest", 
//		"script");
//
//	web_add_auto_header("Sec-Fetch-Site", 
//		"same-origin");

	web_url("dashboard-user-offers.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/dashboard-user-offers.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t469.inf", 
		LAST);

	web_url("recent-transaction.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/recent-transaction.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t470.inf", 
		LAST);

	web_url("new-user-info-section.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/new-user-info-section.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t471.inf", 
		LAST);

	web_url("profile-contact-details-address-tab.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/profile-contact-details-address-tab.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t472.inf", 
		LAST);

	web_url("profile-contact-details-landing.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/profile-contact-details-landing.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t473.inf", 
		LAST);

	web_url("profile-contact-details-phone-tab.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/profile-contact-details-phone-tab.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t474.inf", 
		LAST);

	web_url("profile-contact-details-email-tab.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/profile-contact-details-email-tab.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t475.inf", 
		LAST);

	web_url("profile-contact-details-address-edit.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/profile-contact-details-address-edit.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t476.inf", 
		LAST);

	web_url("profile-contact-details-email-edit.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/profile-contact-details-email-edit.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t477.inf", 
		LAST);

	web_url("profile-contact-details-phone-edit.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/profile-contact-details-phone-edit.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t478.inf", 
		LAST);

	web_url("employer-details.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/employer-details.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t479.inf", 
		LAST);

	web_url("confirm-pin.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/confirm-pin.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t480.inf", 
		LAST);

	web_url("tax-identifier-input.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/tax-identifier-input.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t481.inf", 
		LAST);

	web_url("new-pin.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/new-pin.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t482.inf", 
		LAST);

	web_url("service-request-summary.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/service-request-summary.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t483.inf", 
		LAST);

	web_url("app-terms-condition.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-terms-condition.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t484.inf", 
		LAST);

	web_url("blue-text-box.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/blue-text-box.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t485.inf", 
		LAST);

	web_url("pay-alias-success.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/pay-alias-success.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t486.inf", 
		LAST);

	web_url("view-tax-statement.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/view-tax-statement.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t487.inf", 
		LAST);

	web_url("contact-payment.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_transfer_ui/behaviors/contact-payment.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t488.inf", 
		LAST);

	web_url("corporate-auth-and-workflow-behaviour.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/behaviors/corporate-auth-and-workflow-behaviour.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t489.inf", 
		LAST);

	web_url("corporate-multiple-approval-auth-and-workflow-behaviour.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/behaviors/corporate-multiple-approval-auth-and-workflow-behaviour.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t490.inf", 
		LAST);

	web_url("corporate-multiple-fin-auth-and-workflow-behaviour.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/behaviors/corporate-multiple-fin-auth-and-workflow-behaviour.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t491.inf", 
		LAST);

	web_url("app-multiple-data-entry-behavior.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/behaviors/app-multiple-data-entry-behavior.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t492.inf", 
		LAST);

	web_url("transaction-type-detail.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/behaviors/transaction-type-detail.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t493.inf", 
		LAST);

	web_url("payment-initiation-behavior.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/behaviors/payment-initiation-behavior.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t494.inf", 
		LAST);

	web_url("authAndSubmit.js_2", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/behaviors/authAndSubmit.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t495.inf", 
		LAST);

	web_url("confidential-fields.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/behaviors/confidential-fields.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t496.inf", 
		LAST);

	web_url("corporate-billers-behaviour.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/behaviors/corporate-billers-behaviour.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t497.inf", 
		LAST);

	web_url("batch-payment.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/behaviors/batch-payment.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t498.inf", 
		LAST);

	web_url("corporate-profile-main.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/corporate-profile-main.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t499.inf", 
		LAST);

	web_url("corp-filters.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/corp_filters/corp-filters.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t500.inf", 
		LAST);

	web_url("corporate-view-history.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/elements/corporate-view-history.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t501.inf", 
		LAST);

	web_url("app-horizontal-rule-stepper.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/elements/app-horizontal-rule-stepper.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t502.inf", 
		LAST);

	web_url("rule-stepper.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/elements/rule-stepper.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t503.inf", 
		LAST);

	web_url("app-awaiting-approvals.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/elements/app-awaiting-approvals.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t504.inf", 
		LAST);

	web_url("advanced-search.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/elements/advanced-search.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t505.inf", 
		LAST);

	web_url("app-nickname.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/elements/app-nickname.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t506.inf", 
		LAST);

	web_url("corporate-preview-confirmation.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/elements/corporate-preview-confirmation.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t507.inf", 
		LAST);

	web_url("app-amount.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/elements/app-amount.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t508.inf", 
		LAST);

	web_url("app-exchange-rate.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/elements/app-exchange-rate.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t509.inf", 
		LAST);

	web_url("app-address-component.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/elements/app-address-component.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t510.inf", 
		LAST);

	web_url("app-email.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/elements/app-email.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t511.inf", 
		LAST);

	web_url("app-link-delink-list.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/elements/app-link-delink-list.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t512.inf", 
		LAST);

	web_url("app-names.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/elements/app-names.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t513.inf", 
		LAST);

	web_url("app-multiple-data-entry.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/elements/app-multiple-data-entry.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t514.inf", 
		LAST);

	web_url("app-fab-radio.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-fab-radio.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t515.inf", 
		LAST);

	web_url("app-code-selector.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-code-selector.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t516.inf", 
		LAST);

	web_url("account-transfer-payment-details.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/account-transfer-payment-details.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t517.inf", 
		LAST);

	web_url("account-transfer-additional-details.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/account-transfer-additional-details.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t518.inf", 
		LAST);

	web_url("payment-preview.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/payment-preview.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t519.inf", 
		LAST);

	web_url("payment-initiation.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/payment-initiation.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t520.inf", 
		LAST);

	web_url("payment-listing-multientry.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/payment-listing-multientry.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t521.inf", 
		LAST);

	web_url("payment-view-details.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/payment-view-details.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t522.inf", 
		LAST);

	web_url("same-day-regular-ach-preview-details.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/same-day-regular-ach-preview-details.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t523.inf", 
		LAST);

	web_url("counterparty-payment-details.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/counterparty-payment-details.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t524.inf", 
		LAST);

	web_url("account-transfer-routing-information.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/account-transfer-routing-information.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t525.inf", 
		LAST);

	web_url("payment-success-page.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/payment-success-page.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t526.inf", 
		LAST);

	web_url("workflow-file-upload.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/workflow-file-upload.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t527.inf", 
		LAST);

	web_url("counterparty-landing.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/counterparty-landing.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t528.inf", 
		LAST);

	web_url("manager-list.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/manager-list.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t529.inf", 
		LAST);

	web_url("corp-admin-roles-details.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_admin_ui/elements/corp-admin-roles-details.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t530.inf", 
		LAST);

	web_url("corp-payee-input.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/corp-payee-input.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t531.inf", 
		LAST);

	web_url("approval-list.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/approval-list.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t532.inf", 
		LAST);

	web_url("corp-admin-menu-option-linkage-listing.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_admin_ui/elements/corp-admin-menu-option-linkage-listing.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t533.inf", 
		LAST);

	web_url("corp-admin-rules-details.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_admin_ui/elements/corp-admin-rules-details.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t534.inf", 
		LAST);

	web_url("corp-admin-usermgmt-user-details.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_admin_ui/elements/corp-admin-usermgmt-user-details.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t535.inf", 
		LAST);

	web_url("corporate-user-linkages.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/corporate-user-linkages.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t536.inf", 
		LAST);

	web_url("ach-payment-additional-details.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/ach-payment-additional-details.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t537.inf", 
		LAST);

	web_url("addenda-update.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/addenda-update.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t538.inf", 
		LAST);

	web_url("counterparty-additional-details.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/counterparty-additional-details.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t539.inf", 
		LAST);

	web_url("bill-payment-details.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/bill-payment-details.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t540.inf", 
		LAST);

	web_url("cra-payment-details.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/cra-payment-details.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t541.inf", 
		LAST);

	web_url("payment-overview-record-details.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/payment-overview-record-details.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t542.inf", 
		LAST);

	web_url("file-upload-transaction.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/file-upload-transaction.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t543.inf", 
		LAST);

	web_url("approval-stepper.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/approval-stepper.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t544.inf", 
		LAST);

	web_url("bills-shared-styles.js_2", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/styles/bills-shared-styles.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t545.inf", 
		LAST);

	web_url("ach-payment-details.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/ach-payment-details.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t546.inf", 
		LAST);

	web_url("corp-bank-code-landing.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/corp-bank-code-landing.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t547.inf", 
		LAST);

	web_url("corp-search-bank-result.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/corp-search-bank-result.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t548.inf", 
		LAST);

	web_url("ach-payment-routing-information.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/ach-payment-routing-information.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t549.inf", 
		LAST);

	web_url("corp-workflow.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/corp-workflow.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t550.inf", 
		LAST);

	web_url("addenda-record-details.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/addenda-record-details.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t551.inf", 
		LAST);

	web_url("corp-search-bank-code.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/corp-search-bank-code.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t552.inf", 
		LAST);

	web_url("addenda-details.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/addenda-details.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t553.inf", 
		LAST);

	web_url("file-upload-format-details.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/file-upload-format-details.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t554.inf", 
		LAST);

	web_url("file-upload-error-details.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/file-upload-error-details.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t555.inf", 
		LAST);

	web_url("corp-admin-financial-workflow-link-delink-listing-preview-component.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_admin_ui/elements/corp-admin-financial-workflow-link-delink-listing-preview-component.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t556.inf", 
		LAST);

	web_url("hybrid-payments-collections-activities.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/corp_HYB/hybrid-payments-collections-activities.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t557.inf", 
		LAST);

	web_url("hybrid-payments-collections-overview.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/corp_HYB/hybrid-payments-collections-overview.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t558.inf", 
		LAST);

	web_url("corporate-inquiry.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_meta_ui/elements/corporate-inquiry.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t559.inf", 
		LAST);

	web_url("corporate-inquiry-search-form.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_meta_ui/elements/corporate-inquiry-search-form.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t560.inf", 
		LAST);

	web_url("corporate-financial-preview-confirmation.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/elements/corporate-financial-preview-confirmation.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t561.inf", 
		LAST);

	web_url("corp-admin-corporatemgmt-entry-limits-details.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_admin_ui/elements/corp-admin-corporatemgmt-entry-limits-details.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t562.inf", 
		LAST);

	web_url("corp-admin-corporatemgmt-aggregate-limits-details.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_admin_ui/elements/corp-admin-corporatemgmt-aggregate-limits-details.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t563.inf", 
		LAST);

	web_url("corp-admin-corporatemgmt-aggregate-frequency-details.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_admin_ui/elements/corp-admin-corporatemgmt-aggregate-frequency-details.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t564.inf", 
		LAST);

	web_url("corporate-dc-copy-details.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_tfin_ui/elements/corporate-dc-copy-details.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t565.inf", 
		LAST);

	web_url("corporate-request-dc-issuance-compare.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_tfin_ui/elements/corporate-request-dc-issuance-compare.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t566.inf", 
		LAST);

	web_url("corporate-trade-finance-request-history.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_tfin_ui/elements/corporate-trade-finance-request-history.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t567.inf", 
		LAST);

	web_url("lc-transfer-details.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_tfin_ui/elements/lc-transfer-details.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t568.inf", 
		LAST);

	web_url("trade-finance-bill-lodgement-details.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_tfin_ui/elements/trade-finance-bill-lodgement-details.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t569.inf", 
		LAST);

	web_url("trade-finance-bill-lodgement-general-details.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_tfin_ui/elements/trade-finance-bill-lodgement-general-details.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t570.inf", 
		LAST);

	web_url("trade-finance-dc-assignment-approval.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_tfin_ui/elements/trade-finance-dc-assignment-approval.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t571.inf", 
		LAST);

	web_url("trade-finance-details.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_tfin_ui/elements/trade-finance-details.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t572.inf", 
		LAST);

	web_url("trade-finance-details-non-template.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_tfin_ui/elements/trade-finance-details-non-template.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t573.inf", 
		LAST);

	web_url("hierarchy-combined-component.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_virtualaccount_ui/elements/hierarchy-combined-component.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t574.inf", 
		LAST);

	web_url("app-hierarchy.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_virtualaccount_ui/elements/app-hierarchy.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t575.inf", 
		LAST);

	web_url("hierarchy-search-bar.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_virtualaccount_ui/elements/hierarchy-search-bar.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t576.inf", 
		LAST);

	web_url("hierarchy-tabular-view.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_virtualaccount_ui/elements/hierarchy-tabular-view.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t577.inf", 
		LAST);

	web_url("corp-account-selector.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/corp-account-selector.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t578.inf", 
		LAST);

	web_url("corporate-liquidity-tree-view.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_account_ui/elements/corporate-liquidity-tree-view.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t579.inf", 
		LAST);

	web_url("app-corp-success-page.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/elements/app-corp-success-page.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t580.inf", 
		LAST);

	web_url("role-list.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/elements/role-list.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t581.inf", 
		LAST);

	web_url("app-multiple-data-listing.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/elements/app-multiple-data-listing.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t582.inf", 
		LAST);

	web_url("corporate-date-format.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/corporate-date-format.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t583.inf", 
		LAST);

	web_url("corporate-profile-info.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/corporate-profile-info.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t584.inf", 
		LAST);

	web_url("corporate-primary-account-selector.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/corporate-primary-account-selector.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t585.inf", 
		LAST);

	web_url("corporate-profile-settings.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/corporate-profile-settings.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t586.inf", 
		LAST);

	web_url("corporate-registered-channel.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/corporate-registered-channel.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t587.inf", 
		LAST);

	web_url("corporate-security-question.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/corporate-security-question.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t588.inf", 
		LAST);

	web_url("corporate-advised-lodge-bill-view-dc-details.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_tfin_ui/elements/corporate-advised-lodge-bill-view-dc-details.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t589.inf", 
		LAST);

	web_url("trade-finance-pending-approval-rejected-inwardbills.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_tfin_ui/elements/trade-finance-pending-approval-rejected-inwardbills.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t590.inf", 
		LAST);

	web_url("corporate-advised-lodge-bill-dc-details-accordion-data.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_tfin_ui/elements/corporate-advised-lodge-bill-dc-details-accordion-data.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t591.inf", 
		LAST);

	web_url("corp-inwardbills-pendingacceptance-general-details.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_tfin_ui/elements/corp-inwardbills-pendingacceptance-general-details.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t592.inf", 
		LAST);

	web_url("trade-finance-pending-approval-accepted-inwardbills.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_tfin_ui/elements/trade-finance-pending-approval-accepted-inwardbills.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t593.inf", 
		LAST);

	web_url("corporate-cheque-deposit.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_servicerequest_ui/elements/corporate-cheque-deposit.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t594.inf", 
		LAST);

	web_url("corporate-mobile-check-deposit.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_servicerequest_ui/elements/corporate-mobile-check-deposit.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t595.inf", 
		LAST);

	web_url("corporate-mobile-check-deposit-review.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_servicerequest_ui/elements/corporate-mobile-check-deposit-review.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t596.inf", 
		LAST);

	web_url("corporate-mobile-check-deposit-success.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_servicerequest_ui/elements/corporate-mobile-check-deposit-success.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t597.inf", 
		LAST);

	web_url("corporate-payable-receivables.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/corp/corporate-payable-receivables.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t598.inf", 
		LAST);

	web_url("corporate-approvals.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/corp/corporate-approvals.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t599.inf", 
		LAST);

	web_url("corporate-financial-schedule.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/corp/corporate-financial-schedule.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t600.inf", 
		LAST);

	web_url("corporate-forex.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/corp/corporate-forex.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t601.inf", 
		LAST);

	web_url("corporate-notes.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/corp/corporate-notes.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t602.inf", 
		LAST);

	web_url("corporate-graph.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/corp/corporate-graph.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t603.inf", 
		LAST);

	web_url("corporate-relevant-activities.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/corporate-relevant-activities.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t604.inf", 
		LAST);

	web_url("primary-account-detail-sharing.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/primary-account-detail-sharing.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t605.inf", 
		LAST);

	web_url("profile-my-consent.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/profile-my-consent.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t606.inf", 
		LAST);

	web_url("profile-details.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/profile-details.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t607.inf", 
		LAST);

	web_url("primary-account-selector.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/primary-account-selector.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t608.inf", 
		LAST);

	web_url("consent-details.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/consent-details.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t609.inf", 
		LAST);

	web_url("change-mpin.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/change-mpin.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t610.inf", 
		LAST);

	web_url("activity-details.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/activity-details.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t611.inf", 
		LAST);

	web_url("consent-services-details.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/consent-services-details.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t612.inf", 
		LAST);

	web_url("bills-common-functions.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_transfer_ui/behaviors/bills-common-functions.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t613.inf", 
		LAST);

	web_url("consolidated-statement.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/consolidated-statement.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t614.inf", 
		LAST);

	web_url("profile-financial-alias-management.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/profile-financial-alias-management.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t615.inf", 
		LAST);

	web_url("filter-search-results.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_transfer_ui/elements/filter-search-results.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t616.inf", 
		LAST);

	web_url("acc-txn-date.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/acc-txn-date.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t617.inf", 
		LAST);

	web_url("acc-txn-list.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/acc-txn-list.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t618.inf", 
		LAST);

	web_url("app-success-animation.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-success-animation.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t619.inf", 
		LAST);

	web_url("jspdf.plugin.autotable.min.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/jspdf-autotable/dist/jspdf.plugin.autotable.min.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t620.inf", 
		LAST);

	web_url("oe-form-validation-mixin.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/oe-ui-forms/node_modules/oe-mixins/form-mixins/oe-form-validation-mixin.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t621.inf", 
		LAST);

	web_url("credit-health.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/credit-health.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t622.inf", 
		LAST);

	web_url("app-button-behavior.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/behaviors/app-button-behavior.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t623.inf", 
		LAST);

	web_url("oe-date-filter.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/oe-date-filter.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t624.inf", 
		LAST);

	web_url("canada-post.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/elements/canada-post.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t625.inf", 
		LAST);

	web_url("app-card-dashboard-search.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-card-dashboard-search.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t626.inf", 
		LAST);

	web_url("app-card.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-card.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t627.inf", 
		LAST);

	web_url("pay-contact-auth.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_transfer_ui/elements/pay-contact-auth.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t628.inf", 
		LAST);

	web_url("add-new-contact-success.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_transfer_ui/elements/add-new-contact-success.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t629.inf", 
		LAST);

	web_url("corporate-change-password.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/corporate-change-password.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t630.inf", 
		LAST);

	web_url("user-relationships.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/user-relationships.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t631.inf", 
		LAST);

	web_url("corporate-combined-statement.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/corporate-combined-statement.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t632.inf", 
		LAST);

	web_url("choose-transaction-dispute-listing.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_meta_ui/elements/choose-transaction-dispute-listing.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t633.inf", 
		LAST);

	web_url("app-my-action.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-my-action.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t634.inf", 
		LAST);

	web_url("dashboard-recent-transactions.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/dashboard-recent-transactions.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t635.inf", 
		LAST);

	web_url("dashboard-quick-links.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/dashboard-quick-links.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t636.inf", 
		LAST);

	web_url("relevant-transaction.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/relevant-transaction.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t637.inf", 
		LAST);

	web_url("dashboard-user-saving.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/dashboard-user-saving.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t638.inf", 
		LAST);

	web_url("dashboard-portfolio.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/dashboard-portfolio.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t639.inf", 
		LAST);

	web_url("dashboard-user-card.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/dashboard-user-card.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t640.inf", 
		LAST);

	web_url("dashboard-user-loan.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/dashboard-user-loan.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t641.inf", 
		LAST);

	web_url("dashboard-user-investment.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/dashboard-user-investment.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t642.inf", 
		LAST);

	web_url("biller-details-new.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_transfer_ui/elements/biller-details-new.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t643.inf", 
		LAST);

	web_url("account-selection.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/account-selection.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t644.inf", 
		LAST);

	web_url("corp-payments-collections.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/behaviors/corp-payments-collections.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t645.inf", 
		LAST);

	web_url("alias-management-behavior.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/behaviors/alias-management-behavior.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t646.inf", 
		LAST);

	web_url("edit-corp-filters.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/corp_filters/edit-corp-filters.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t647.inf", 
		LAST);

	web_url("app-awaiting-approval-status.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/elements/app-awaiting-approval-status.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t648.inf", 
		LAST);

	web_url("sort-corp-filters.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/corp_filters/sort-corp-filters.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t649.inf", 
		LAST);

	web_url("app-data-selection-multi-dialog.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/elements/app-data-selection-multi-dialog.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t650.inf", 
		LAST);

	web_url("corporate-admin-multiple-task-action-linkage-behaviour.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/behaviors/corporate-admin-multiple-task-action-linkage-behaviour.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t651.inf", 
		LAST);

	web_url("payments-collections-activities-behaviour.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/behaviors/payments-collections-activities-behaviour.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t652.inf", 
		LAST);

	web_url("hybrid-payments-collections-upcoming.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/corp_HYB/hybrid-payments-collections-upcoming.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t653.inf", 
		LAST);

	web_url("payments-collections-overview-behaviour.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/behaviors/payments-collections-overview-behaviour.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t654.inf", 
		LAST);

	web_url("hybrid-payments-collections-awaiting-approvals.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/corp_HYB/hybrid-payments-collections-awaiting-approvals.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t655.inf", 
		LAST);

	web_url("corporate-dc-transfer-record-details.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_tfin_ui/elements/corporate-dc-transfer-record-details.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t656.inf", 
		LAST);

	web_url("hybrid-payments-collections-incomplete-transactions.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/elements/corp_HYB/hybrid-payments-collections-incomplete-transactions.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t657.inf", 
		LAST);

	web_url("orgChart.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_virtualaccount_ui/elements/orgChart.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t658.inf", 
		LAST);

	web_url("add-cheque-image.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/add-cheque-image.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t659.inf", 
		LAST);

	web_url("qr-generator.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/qr-generator.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t660.inf", 
		LAST);

	web_url("corporate-date-format-behaviour.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/behaviors/corporate-date-format-behaviour.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t661.inf", 
		LAST);

	web_url("pay-contact-success.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_transfer_ui/elements/pay-contact-success.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t662.inf", 
		LAST);

	web_url("mpin-register-behaviour.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/behaviors/mpin-register-behaviour.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t663.inf", 
		LAST);

	web_url("profile-activity.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/profile-activity.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t664.inf", 
		LAST);

	web_url("app-network-error.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/speedboat_ui/elements/app-network-error.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t665.inf", 
		LAST);

	web_url("bill-component.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_transfer_ui/elements/bill-component.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t666.inf", 
		LAST);

	web_url("Chart.bundle.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/chart.js/dist/Chart.bundle.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t667.inf", 
		LAST);

	web_url("awaiting-approval-role-list.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/corporate_common_ui/elements/awaiting-approval-role-list.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t668.inf", 
		LAST);

	web_url("bill-transaction-history.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_transfer_ui/elements/bill-transaction-history.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t669.inf", 
		LAST);

	web_url("payments-collection-upcoming-behavior.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/behaviors/payments-collection-upcoming-behavior.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t670.inf", 
		LAST);

	web_url("payments-collections-awaiting-approvals-behaviour.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/behaviors/payments-collections-awaiting-approvals-behaviour.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t671.inf", 
		LAST);

	web_url("payments-collections-incomplete-transactions-behaviour.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/crp_transfer_ui/behaviors/payments-collections-incomplete-transactions-behaviour.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t672.inf", 
		LAST);
	
	web_concurrent_end(NULL);


		lr_end_sub_transaction("S03_DEH_Retail_BalanceInquiry_03_Login",LR_AUTO);
		
		lr_start_sub_transaction("S03_DEH_Retail_BalanceInquiry_04_Dashboards","S03_DEH_Retail_BalanceInquiry_CombinedLogin");


	web_revert_auto_header("Origin");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("device", 
		"desktop");

	web_add_auto_header("lang", 
		"en-US");

	web_add_auto_header("tenantId", 
		"UNI");

	web_add_auto_header("x-access-token",
		"{C_Authorization}");

	web_add_auto_header("x-forwarded-for", 
		"10.200.25.1");
	
	web_concurrent_start(NULL);


	web_custom_request("mails",
		"URL=https://finobunipreprod.test.uni.ca:4443/api/CBUsers/{C_userID1}/mails?filter[where][sort_by]=desc(mailDate)&filter[where][folderId]=IB",
		"Method=GET",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t673.inf",
		"Mode=HTTP",
		"EncType=application/json",
		LAST);

	web_custom_request("codereferences_2", 
		"URL=https://finobunipreprod.test.uni.ca:4443/api/codereferences?filter[where][codeType]=CTG", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t674.inf", 
		"Mode=HTTP", 
		"EncType=application/json", 
		LAST);

/*Correlation comment - Do not change!  Original value='000100006390' Name ='C_Account' Type ='Manual'*/
	web_reg_save_param_regexp(
		"ParamName=C_Account",
		"RegExp=\\{\"accountId\":\"(.*?)\",",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		LAST);

	web_custom_request("accounts",
		"URL=https://finobunipreprod.test.uni.ca:4443/api/CBUsers/{C_userID1}/accounts",
		"Method=GET",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t675.inf",
		"Mode=HTTP",
		LAST);

	web_custom_request("codereferences_3", 
		"URL=https://finobunipreprod.test.uni.ca:4443/api/codereferences?filter[where][codeType]=CTAT", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t676.inf", 
		"Mode=HTTP", 
		"EncType=application/json", 
		LAST);

	web_custom_request("codereferences_4", 
		"URL=https://finobunipreprod.test.uni.ca:4443/api/codereferences?filter[where][codeType]=APST", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t677.inf", 
		"Mode=HTTP", 
		"EncType=application/json", 
		LAST);

//	web_revert_auto_header("device");
//
//	web_revert_auto_header("lang");
//
//	web_revert_auto_header("tenantId");
//
//	web_revert_auto_header("x-access-token");
//
//	web_revert_auto_header("x-forwarded-for");
//
//	web_add_auto_header("Sec-Fetch-Mode", 
//		"no-cors");
//
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"image");

	web_url("CAD.png", 
		"URL=https://finobunipreprod.test.uni.ca:4443/images/UNI/country_flags/CAD.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=", 
		"Snapshot=t678.inf", 
		LAST);

	web_concurrent_end(NULL);


	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("device", 
		"desktop");

	web_add_auto_header("lang", 
		"en-US");

	web_add_auto_header("tenantId", 
		"UNI");

	web_add_auto_header("x-access-token",
		"{C_Authorization}");

	web_add_auto_header("x-forwarded-for", 
		"10.200.25.1");
	
	web_concurrent_start(NULL);


	web_custom_request("CBNavigationLinks", 
		"URL=https://finobunipreprod.test.uni.ca:4443/api/CBNavigationLinks?filter=%7B%22where%22%3A%7B%22topLevel%22%3Atrue%7D%2C%22include%22%3A%7B%22relation%22%3A%22children%22%2C%22scope%22%3A%7B%22include%22%3A%7B%22relation%22%3A%22children%22%7D%7D%7D%2C%22order%22%3A%22sequence%20ASC%22%7D", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t679.inf", 
		"Mode=HTTP", 
		"EncType=application/json", 
		LAST);

	web_custom_request("RET0000082",
		"URL=https://finobunipreprod.test.uni.ca:4443/api/CBUsers/{C_userID1}",
		"Method=GET",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t680.inf",
		"Mode=HTTP",
		LAST);

	web_custom_request("operativeaccounts",
		"URL=https://finobunipreprod.test.uni.ca:4443/api/CBUsers/{C_userID1}/operativeaccounts",
		"Method=GET",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t681.inf",
		"Mode=HTTP",
		LAST);

	web_custom_request("retailapplications",
		"URL=https://finobunipreprod.test.uni.ca:4443/api/CBUsers/{C_userID1}/custom/retailapplications",
		"Method=GET",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t682.inf",
		"Mode=HTTP",
		LAST);

	web_custom_request("preferences",
		"URL=https://finobunipreprod.test.uni.ca:4443/api/CBUsers/{C_userID1}/preferences",
		"Method=GET",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t683.inf",
		"Mode=HTTP",
		LAST);

	web_custom_request("transactions",
		"URL=https://finobunipreprod.test.uni.ca:4443/api/operativeaccounts/{C_Account}/transactions?filter[order]=transactionDate%20DESC&filter[limit]=5",
		"Method=GET",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t684.inf",
		"Mode=HTTP",
		"EncType=application/json",
		LAST);

	web_url("en-US.json_3", 
		"URL=https://finobunipreprod.test.uni.ca:4443/api/CustomLiterals/render/en-US.json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t685.inf", 
		"Mode=HTTP", 
		LAST);

	
	web_concurrent_end(NULL);


	web_revert_auto_header("Sec-Fetch-Dest");

	web_revert_auto_header("Sec-Fetch-Mode");

	web_revert_auto_header("Sec-Fetch-Site");

	web_revert_auto_header("device");

	web_revert_auto_header("lang");

	web_revert_auto_header("sec-ch-ua");

	web_revert_auto_header("sec-ch-ua-mobile");

	web_revert_auto_header("sec-ch-ua-platform");

	web_revert_auto_header("tenantId");

	web_revert_auto_header("x-access-token");

	web_revert_auto_header("x-forwarded-for");

	
	lr_end_sub_transaction("S03_DEH_Retail_BalanceInquiry_04_Dashboards",LR_AUTO);

	lr_end_transaction("S03_DEH_Retail_BalanceInquiry_CombinedLogin",LR_AUTO);






	lr_think_time(5);

//	lr_start_transaction("S03_DEH_Retail_BalanceInquiry_05_Select_Assets");
//
//	lr_end_transaction("S03_DEH_Retail_BalanceInquiry_05_Select_Assets",LR_AUTO);
//
//	lr_think_time(5);

	lr_start_transaction("S03_DEH_Retail_BalanceInquiry_06_Select_Account");

	web_add_auto_header("Origin", 
		"https://finobunipreprod.test.uni.ca:4443");

	web_add_auto_header("Sec-Fetch-Dest", 
		"script");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

web_concurrent_start(NULL);
	
	web_url("elements-accounts.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/elements-accounts.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t688.inf", 
		LAST);

	web_url("amount-progress-bar-template.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/amount-progress-bar-template.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t689.inf", 
		LAST);

	web_url("payment-landing.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/payment-landing.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t690.inf", 
		LAST);

	web_url("credit-card-detail.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/credit-card-detail.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t691.inf", 
		LAST);

	web_url("credit-card-auto-pay.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/credit-card-auto-pay.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t692.inf", 
		LAST);

	web_url("credit-card-dashboard.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/credit-card-dashboard.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t693.inf", 
		LAST);

	web_url("credit-card-statement.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/credit-card-statement.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t694.inf", 
		LAST);

	web_url("credit-card-details-template.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/credit-card-details-template.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t695.inf", 
		LAST);

	web_url("google-doughnut-chart-template.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/google-doughnut-chart-template.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t696.inf", 
		LAST);

	//web_set_sockets_option("TLS_SNI", "0");

	web_url("opr-accounts-landing.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/opr-accounts-landing.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t697.inf", 
		LAST);

	web_url("opr-accounts-overview.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/opr-accounts-overview.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t698.inf", 
		LAST);

	web_url("transaction-view.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/transaction-view.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t699.inf", 
		LAST);

	web_url("opr-account-card.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/opr-account-card.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t700.inf", 
		LAST);

//	web_set_sockets_option("TLS_SNI", "1");

	web_url("transactions-list.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/transactions-list.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t701.inf", 
		LAST);

	web_url("upcoming-txns-element.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/upcoming-txns-element.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t702.inf", 
		LAST);

	web_url("retail-interest-and-tax-account-summary.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/retail-interest-and-tax-account-summary.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t703.inf", 
		LAST);

	web_url("retail-interest-and-tax-summary.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/retail-interest-and-tax-summary.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t704.inf", 
		LAST);

	web_url("random-color-picker.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/random-color-picker.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t705.inf", 
		LAST);

	web_url("payment-success.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/payment-success.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t706.inf", 
		LAST);

//	web_set_sockets_option("TLS_SNI", "0");

	web_url("credit-card-payment.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/credit-card-payment.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t707.inf", 
		LAST);

	web_url("credit-card-transaction-history.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/credit-card-transaction-history.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t708.inf", 
		LAST);

	web_url("autopay-active.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/autopay-active.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t709.inf", 
		LAST);

	web_url("autopay-on.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/autopay-on.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t710.inf", 
		LAST);

	web_url("autopay-off.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/autopay-off.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t711.inf", 
		LAST);

	web_url("credit-card-summary.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/credit-card-summary.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t712.inf", 
		LAST);

	web_url("credit-card-statement-element.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/credit-card-statement-element.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t713.inf", 
		LAST);

	web_url("transaction-date.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/transaction-date.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t714.inf", 
		LAST);

	web_url("transaction-element.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/transaction-element.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t715.inf", 
		LAST);

	web_url("credit-card-statement-footer.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/credit-card-statement-footer.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t716.inf", 
		LAST);

	web_url("payment-limit-bottom.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/payment-limit-bottom.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t717.inf", 
		LAST);

	web_url("payment-limit-top.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/payment-limit-top.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t718.inf", 
		LAST);

	web_url("billing-view.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/billing-view.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t719.inf", 
		LAST);

	web_url("unsettled-bills.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/unsettled-bills.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t720.inf", 
		LAST);

	web_url("monthly-bills.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/monthly-bills.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t721.inf", 
		LAST);
web_concurrent_end(NULL);
	
	web_revert_auto_header("Origin");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("device", 
		"desktop");

	web_add_auto_header("lang", 
		"en-US");

	web_add_auto_header("tenantId", 
		"UNI");

	web_add_auto_header("x-access-token",
		"{C_Authorization}");

	web_add_auto_header("x-forwarded-for", 
		"10.200.25.1");

/* Added by Async CodeGen.
ID=LongPoll_0
ScanType = Recording

The following URLs are considered part of this conversation:
	https://finobunipreprod.test.uni.ca:4443/api/propertyreferences?filter[where][propertyName]=MEMBERSHIP_ACCOUNT_SCHEME_CODE

TODO - The following callbacks have been added to AsyncCallbacks.c.
Add your code to the callback implementations as necessary.
	LongPoll_0_RequestCB
	LongPoll_0_ResponseCB
 */
	web_reg_async_attributes("ID=LongPoll_0", 
		"Pattern=LongPoll", 
		"URL=https://finobunipreprod.test.uni.ca:4443/api/propertyreferences?filter[where][propertyName]=MEMBERSHIP_ACCOUNT_SCHEME_CODE", 
		"RequestCB=LongPoll_0_RequestCB", 
		"ResponseCB=LongPoll_0_ResponseCB", 
		LAST);
		



	web_custom_request("propertyreferences_5", 
		"URL=https://finobunipreprod.test.uni.ca:4443/api/propertyreferences?filter[where][propertyName]=MEMBERSHIP_ACCOUNT_SCHEME_CODE", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t722.inf", 
		"Mode=HTTP", 
		"EncType=application/json", 
		LAST);

	web_url("UserFinancials",
		"URL=https://finobunipreprod.test.uni.ca:4443/api/UserFinancials?filter={%22where%22:{%22userid%22:%22{C_userID1}%22,%22timePeriod%22:%22monthly%22}}",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t723.inf",
		"Mode=HTTP",
		LAST);
		
	web_concurrent_start(NULL);

	web_custom_request("RET0000082_2",
		"URL=https://finobunipreprod.test.uni.ca:4443/api/CBUsers/{C_userID1}",
		"Method=GET",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t724.inf",
		"Mode=HTTP",
		LAST);
		


/* Removed by Async CodeGen.
ID = LongPoll_0
 */
	/*
 web_custom_request("propertyreferences_6",
		"URL=https://finobunipreprod.test.uni.ca:4443/api/propertyreferences?filter[where][propertyName]=MEMBERSHIP_ACCOUNT_SCHEME_CODE",
		"Method=GET",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t725.inf",
		"Mode=HTTP",
		"EncType=application/json",
		LAST); 
	*/

//	web_revert_auto_header("device");
//
//	web_revert_auto_header("lang");
//
//	web_revert_auto_header("tenantId");
//
//	web_revert_auto_header("x-access-token");
//
//	web_revert_auto_header("x-forwarded-for");
//
//	web_add_auto_header("Origin", 
//		"https://finobunipreprod.test.uni.ca:4443");
//
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"script");

	web_url("elements-accounts-opr-overview.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/elements-accounts-opr-overview.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t726.inf", 
		LAST);

	web_url("opr-accounts-overview-balance.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/opr-accounts-overview-balance.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t727.inf", 
		LAST);

	web_url("opr-closed-accounts.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/opr-closed-accounts.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t728.inf", 
		LAST);

//	web_revert_auto_header("Origin");
//
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"empty");
//
//	web_add_header("device", 
//		"desktop");
//
//	web_add_header("lang", 
//		"en-US");
//
//	web_add_header("tenantId", 
//		"UNI");
//
//	web_add_header("x-access-token",
//		"{C_Authorization}");
//
//	web_add_header("x-forwarded-for", 
//		"10.200.25.1");
//
///* Removed by Async CodeGen.
//ID = LongPoll_0
// */
//	/*
// web_custom_request("propertyreferences_7",
//		"URL=https://finobunipreprod.test.uni.ca:4443/api/propertyreferences?filter[where][propertyName]=MEMBERSHIP_ACCOUNT_SCHEME_CODE",
//		"Method=GET",
//		"Resource=0",
//		"RecContentType=application/json",
//		"Referer=",
//		"Snapshot=t729.inf",
//		"Mode=HTTP",
//		"EncType=application/json",
//		LAST); 
//	*/
//
//	web_add_auto_header("Origin", 
//		"https://finobunipreprod.test.uni.ca:4443");
//
//	web_add_auto_header("Sec-Fetch-Dest", 
//		"script");

	web_url("opr-inactive-accounts.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/opr-inactive-accounts.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t730.inf", 
		LAST);

	web_url("opr-membership-accounts.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/opr-membership-accounts.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t731.inf", 
		LAST);

	web_url("opr-dormant-accounts.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/opr-dormant-accounts.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t732.inf", 
		LAST);

	web_url("acc-suggestion-card.js", 
		"URL=https://finobunipreprod.test.uni.ca:4443/node_modules/sb_account_ui/elements/acc-suggestion-card.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t733.inf", 
		LAST);
	
	web_concurrent_end(NULL);

	web_revert_auto_header("Origin");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("device", 
		"desktop");

	web_add_auto_header("lang", 
		"en-US");

	web_add_auto_header("tenantId", 
		"UNI");

	web_add_auto_header("x-access-token",
		"{C_Authorization}");

	web_add_auto_header("x-forwarded-for", 
		"10.200.25.1");

/* Removed by Async CodeGen.
ID = LongPoll_0
 */
	/*
 web_custom_request("propertyreferences_8",
		"URL=https://finobunipreprod.test.uni.ca:4443/api/propertyreferences?filter[where][propertyName]=MEMBERSHIP_ACCOUNT_SCHEME_CODE",
		"Method=GET",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t734.inf",
		"Mode=HTTP",
		"EncType=application/json",
		LAST); 
	*/

	web_custom_request("accounts_2",
		"URL=https://finobunipreprod.test.uni.ca:4443/api/CBUsers/{C_userID1}/accounts",
		"Method=GET",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t735.inf",
		"Mode=HTTP",
		LAST);

/* Removed by Async CodeGen.
ID = LongPoll_0
 */
	/*
 web_custom_request("propertyreferences_9",
		"URL=https://finobunipreprod.test.uni.ca:4443/api/propertyreferences?filter[where][propertyName]=MEMBERSHIP_ACCOUNT_SCHEME_CODE",
		"Method=GET",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t736.inf",
		"Mode=HTTP",
		"EncType=application/json",
		LAST); 
	*/

/* Added by Async CodeGen.
ID = LongPoll_0
 */
	web_stop_async("ID=LongPoll_0", 
		LAST);

	lr_end_transaction("S03_DEH_Retail_BalanceInquiry_06_Select_Account",LR_AUTO);

	lr_think_time(5);

	web_revert_auto_header("device");

	web_revert_auto_header("lang");

	web_revert_auto_header("sec-ch-ua");

	web_revert_auto_header("sec-ch-ua-mobile");

	web_revert_auto_header("sec-ch-ua-platform");

	web_revert_auto_header("tenantId");

	web_revert_auto_header("x-access-token");

	web_revert_auto_header("x-forwarded-for");



	lr_start_transaction("S03_DEH_Retail_BalanceInquiry_07_Logout");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_header("Origin", 
		"https://finobunipreprod.test.uni.ca:4443");

	web_add_header("device", 
		"desktop");

	web_add_header("lang", 
		"en-US");

	web_add_auto_header("sec-ch-ua", 
		"\"Google Chrome\";v=\"113\", \"Chromium\";v=\"113\", \"Not-A.Brand\";v=\"24\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_add_header("tenantId", 
		"UNI");

	web_add_header("x-access-token",
		"{C_Authorization}");

	web_add_header("x-forwarded-for", 
		"10.200.25.1");



	web_custom_request("logout",
		"URL=https://finobunipreprod.test.uni.ca:4443/api/CBUsers/logout?={C_Authorization}",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t738.inf",
		"Mode=HTTP",
		"EncType=application/json",
		"Body={\"header\":{},\"data\":{\"tenantId\":\"UNI\",\"remarks\":\"Logged out successfully\"}}",
		LAST);

	web_set_sockets_option("TLS_SNI", "0");

	web_add_auto_header("Sec-Fetch-Site", 
		"cross-site");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("logout_2", 
		"URL=https://unisittesting.b2clogin.com/unisittesting.onmicrosoft.com/B2C_1A_USERNAME_SUSI_UI/oauth2/v2.0/logout?post_logout_redirect_uri=https%3A%2F%2Fb2ccsshtmluifiles.blob.core.windows.net%2Fb2cuifiles%2Flogout.html&state=LE&id_token_hint={C_token}",
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t739.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_auto_header("Sec-Fetch-Dest", 
		"script");

	web_url("jquery-3.5.1.min.js", 
		"URL=https://unisittesting.b2clogin.com/static/library/jquery-3.5.1.min.js?slice=001-000&dc=SAN", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://unisittesting.b2clogin.com/unisittesting.onmicrosoft.com/B2C_1A_USERNAME_SUSI_UI/oauth2/v2.0/logout?post_logout_redirect_uri=https%3A%2F%2Fb2ccsshtmluifiles.blob.core.windows.net%2Fb2cuifiles%2Flogout.html&state=LE&id_token_hint={C_token}",
		"Snapshot=t740.inf", 
		LAST);

	web_set_sockets_option("TLS_SNI", "1");

	web_add_auto_header("Sec-Fetch-Site", 
		"cross-site");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("logout.html", 
		"URL=https://b2ccsshtmluifiles.blob.core.windows.net/b2cuifiles/logout.html?state=LE", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://unisittesting.b2clogin.com/", 
		"Snapshot=t741.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_auto_header("Origin", 
		"https://b2ccsshtmluifiles.blob.core.windows.net");

	web_add_auto_header("Sec-Fetch-Dest", 
		"style");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_url("library%2Fmdb.min.css_2", 
		"URL=https://b2ccsshtmluifiles.blob.core.windows.net/b2cuifiles/library%2Fmdb.min.css", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=", 
		"Snapshot=t742.inf", 
		LAST);

	web_url("styles%2Flayout.css_2", 
		"URL=https://b2ccsshtmluifiles.blob.core.windows.net/b2cuifiles/styles%2Flayout.css", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=", 
		"Snapshot=t743.inf", 
		LAST);

	web_revert_auto_header("Origin");

	web_add_auto_header("Sec-Fetch-Dest", 
		"script");

	web_add_auto_header("Sec-Fetch-Mode", 
		"no-cors");

	web_url("plugin.cookie.min.js_2", 
		"URL=https://b2ccsshtmluifiles.blob.core.windows.net/b2cuifiles/scripts/plugin.cookie.min.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://b2ccsshtmluifiles.blob.core.windows.net/b2cuifiles/logout.html?state=LE", 
		"Snapshot=t744.inf", 
		LAST);

	web_add_auto_header("Sec-Fetch-Dest", 
		"image");

	web_url("images%2Flogo.png_2", 
		"URL=https://b2ccsshtmluifiles.blob.core.windows.net/b2cuifiles/images%2Flogo.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://b2ccsshtmluifiles.blob.core.windows.net/b2cuifiles/logout.html?state=LE", 
		"Snapshot=t745.inf", 
		LAST);

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Dest", 
		"script");

	web_add_header("Origin", 
		"https://b2ccsshtmluifiles.blob.core.windows.net");

	web_url("library%2Fmdb.min.js_2", 
		"URL=https://b2ccsshtmluifiles.blob.core.windows.net/b2cuifiles/library%2Fmdb.min.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t746.inf", 
		LAST);

	web_add_auto_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_auto_header("Sec-Fetch-Dest", 
		"image");

	web_url("images%2Flogout_vector.svg", 
		"URL=https://b2ccsshtmluifiles.blob.core.windows.net/b2cuifiles/images%2Flogout_vector.svg", 
		"Resource=1", 
		"RecContentType=image/svg+xml", 
		"Referer=https://b2ccsshtmluifiles.blob.core.windows.net/b2cuifiles/logout.html?state=LE", 
		"Snapshot=t747.inf", 
		LAST);

	web_add_auto_header("Sec-Fetch-Site", 
		"cross-site");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Dest", 
		"script");

	web_add_header("Origin", 
		"https://b2ccsshtmluifiles.blob.core.windows.net");

	web_url("jquery.min.js_2", 
		"URL=https://cdnjs.cloudflare.com/ajax/libs/jquery/3.6.0/jquery.min.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=", 
		"Snapshot=t748.inf", 
		LAST);

	web_add_auto_header("Sec-Fetch-Dest", 
		"image");

	web_add_auto_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_url("images%2Ffavicon.png_2", 
		"URL=https://b2ccsshtmluifiles.blob.core.windows.net/b2cuifiles/images%2Ffavicon.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://b2ccsshtmluifiles.blob.core.windows.net/b2cuifiles/logout.html?state=LE", 
		"Snapshot=t749.inf", 
		LAST);

	lr_end_transaction("S03_DEH_Retail_BalanceInquiry_07_Logout",LR_AUTO);

	lr_think_time(3);
	
	web_cleanup_auto_headers();

	web_cleanup_cookies();

	return 0;
}