#include "Register.h"
#include <cstdio>
#include <glog/logging.h>
#include <time.h>

using namespace fighter::RPC;

int main(int argc,char **argv)
{

	google::InitGoogleLogging(argv[0]);
	google::LogToStderr();

	LOG(INFO)<<"start";

	Register  *mregister=Register::getInstance("localhost:2181");


	mregister->connect();

	serviceinfo info;
	info.servicename="time";
	info.ip="192.168.1.5";
	info.port="5600";
	info.startuptime=time(NULL);

	mregister->registe(info);


	sleep(1000);

	mregister->close();

	return 0;
}
