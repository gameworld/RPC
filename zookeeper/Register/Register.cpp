/*
 * Register.cpp
 *
 *  Created on: 2015年6月28日
 *      Author: fighter
 */

#include "Register.h"

namespace fighter {
namespace RPC {


static void watcher(zhandle_t *zzh, int type, int state, const char *path,
             void *watcherCtx) {
	LOG(INFO)<<"something happen";
	LOG(INFO)<<path;
}

Register::~Register() {
	// TODO Auto-generated destructor stub
}


int Register::query(std::string servicename,std::vector<serviceinfo > &vecService)
{


}

int Register::registe(const serviceinfo & info)
{
		std::string name="/Register_"+info.servicename;
		char buf[1024];
		int bufflen=sizeof(buf);
		struct Stat stat;
		//首先查询节点是否存在
		int ret=zoo_exists(zh,name.c_str(),1,&stat);



		LOG(INFO)<<ret;
		switch(ret)
		{
		case ZOK:{
			LOG(INFO)<<"OK\n";
		} break;
		case ZNONODE:{
			LOG(INFO)<<"ZNONODE\n";
		}break;

		default:
			LOG(INFO)<<"other\n";

		}
		LOG(INFO)<<stat.ctime;

		LOG(INFO)<<bufflen;

		/*
		 * 创建节点
		 */
		char path_buffer[64];

		ret=zoo_create(zh,name.c_str(),"app",3,&ZOO_OPEN_ACL_UNSAFE, ZOO_EPHEMERAL,path_buffer,sizeof(path_buffer)-1);


		LOG(INFO)<<ret;


		return 0;
}

int Register::connect()
{
	  zoo_set_debug_level(ZOO_LOG_LEVEL_DEBUG);
	zh=zookeeper_init(zookeeper_addr.c_str(),watcher,10000,&myid,0,0);
	if(!zh)
	{

	}

	LOG(INFO)<<"InitSucc\n";



	return 0;

}

int Register::close()
{
	LOG(INFO)<<"close\n";
	 zookeeper_close(zh);
}

} /* namespace RPC */
} /* namespace fighter */
