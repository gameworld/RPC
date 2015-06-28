/*
 * time service 客户端
 */

#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include "gen-cpp/timeservice.h"
#include <iostream>
#include<time.h>
#include <cstdio>

using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using namespace  fighter::time;

int main()
{
	  boost::shared_ptr<TTransport> socket(new TSocket("localhost", 9090));
	  boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
	  boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

	  timeserviceClient client(protocol);

	  try
	  {

		  transport->open();

		  printf("打开成功");
		  printf("当前时间%zu\n",time(NULL));
		  printf("服务器返回时间%lu\n",client.time());
		  std::string timestr;
		  client.timeStr(timestr);
		  printf("字符串%s\n",timestr.c_str());
		  printf("星期几%d\n",client.getWeekDay());

		  transport->close();
	  }
	  catch (TException& tx) {
	     std::cout << "ERROR: " << tx.what() << std::endl;
	   }

}
