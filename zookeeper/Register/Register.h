/*
 * Register.h
 *
 *  Created on: 2015年6月28日
 *      Author: fighter
 */

#ifndef REGISTER_H_
#define REGISTER_H_

#include <string>
#include <vector>
#include <zookeeper/zookeeper.h>
#include <stdint.h>
#include <glog/logging.h>

namespace fighter {
namespace RPC {

struct serviceinfo
{
	/*
	 * 服务名
	 */
	std::string servicename;
	/*
	 * 服务启动时间
	 */
	time_t startuptime;
	/*
	 *
	 */
	std::string ip;
	/*
	 *
	 */
	std::string port;
};


/*
 * 注册服务对象
 */
class Register {
public:
/*
 *注册服务
 *采用类似java包名的风格
 *服务名:time.service
 * reutrn:0 成功
 * 			-1:失败
 *
 */
	int registe(const serviceinfo & info);

	/*
	 * 查找服务运行的位置
	 * return :0 成功
	 * 		-1:失败
	 */
	int query(std::string servicename,std::vector<serviceinfo > &vecService);

	std::string getErrorStr()
	{
		return errorStr;
	}

	static Register *getInstance(std::string addr)
	{
			return new Register(addr);
	}

	/*
	 * 连接到zookeeper 服务器
	 */
	int connect();

	/*
	 * 关闭连接
	 */
	int close();

	virtual ~Register();

private:
	Register(std::string addr):zookeeper_addr(addr){}

	std::string errorStr;
	std::string zookeeper_addr;

	zhandle_t *zh;
	clientid_t myid;
};

} /* namespace RPC */
} /* namespace fighter */

#endif /* REGISTER_H_ */
