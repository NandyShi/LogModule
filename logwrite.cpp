#include <string>
#include <iostream>
#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/fileappender.h>
#include "wallet_base.h"
#include "wallet.pb.h"
using namespace std;
using namespace log4cplus;

#define DEFAULT_PATH  "log.properties"


void MsgPrintFunc(void *arg,string& Errorcode,string &port) 
{

	log4cplus::PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT("log.properties"));
    log4cplus::Logger logpopular = log4cplus::Logger::getInstance("logPopular");
	if (Errorcode =="0")
	{
		LOG4CPLUS_INFO(logpopular, "" << (const char *)arg);
	}else
	{
		LOG4CPLUS_ERROR(logpopular, "" << (const char *)arg);
	}
	return ;
}

void LogFunc(string logmsg, int errorid)
{
	string Errorcode = "0";
	string port = "\0";
	if (errorid == 0)
	{
		Errorcode = "0";
		MsgPrintFunc((void *)logmsg.c_str(), Errorcode, port);
	}
	if (errorid != 0)
	{
		Errorcode = "1";
		MsgPrintFunc((void *)logmsg.c_str(), Errorcode, port);
	}
	return;
}