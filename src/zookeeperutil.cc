#include "zookeeperutil.h"
#include "mprpcapplication.h"
#include <semaphore.h>
#include <iostream>

// 全局的watcher观察器   zkserver给zkclient的通知
void global_watcher(zhandle_t *zh, int type,
                   int state, const char *path, void *watcherCtx)
{
    if (type == ZOO_SESSION_EVENT)  // 回调的消息类型是和会话相关的消息类型
	{
		if (state == ZOO_CONNECTED_STATE)  // zkclient和zkserver连接成功
		{
			sem_t *sem = (sem_t*)zoo_get_context(zh);
            sem_post(sem);
		}
	}
}

ZkClient::ZkClient() : m_zhandle(nullptr)
{}

ZkClient::~ZkClient()
{
    if (m_zhandle != nullptr)
    {
        zookeeper_close(m_zhandle); // 关闭句柄，释放资源
    }
}

// 连接zkserver
void ZkClient::Start()
{
    std::string host = MprpcApplication::GetInstance().GetConfig().Load("zookeeperip");
    std::string port = MprpcApplication::GetInstance().GetConfig().Load("zookeeperport");
    std::string connstr = host + ":" + port;
    
	/*
	zookeeper_mt：多线程版本
	zookeeper的API客户端程序提供了三个线程
		API调用线程 
		网络I/O线程  poll
		watcher回调线程 pthread_create
	*/
	// 【异步】建立rpcserver(zkclient)与zookeeper(zkserver)连接, 并返回一个句柄
	// 程序获得返回的句柄后, 其实连接还不一定建立好(因为发起连接建立的函数 和 负责建立连接的函数 不在同一个线程)
    m_zhandle = zookeeper_init(connstr.c_str(), global_watcher, 30000, nullptr, nullptr, 0);
    if (nullptr == m_zhandle) 
    {
        std::cout << "zookeeper_init error!" << std::endl;
        exit(EXIT_FAILURE);
    }
	// 等待异步连接成功
    sem_t sem;
    sem_init(&sem, 0, 0);
    zoo_set_context(m_zhandle, &sem); // 将sem传递给m_zhandle
	// 在global_watcher中可以将sem取出来使用
	// global_watcher发现state==ZOO_CONNECTED_STATE说明连接建立成功
	// 此时调用sem_post(sem)解除主线程阻塞(解除ZkClient::Start()中的阻塞)
	// 此同步机制保证: 当ZkClient::Start()执行完后, callee端和zookeeper确定建立好连接
    sem_wait(&sem);
    std::cout << "zookeeper_init success!" << std::endl;
}

// 创建znode
void ZkClient::Create(const char *path, const char *data, int datalen, int state)
{
    char path_buffer[128];
    int bufferlen = sizeof(path_buffer);
    int flag;
	// 先判断path表示的znode节点是否存在，存在则不再重复创建
	flag = zoo_exists(m_zhandle, path, 0, nullptr);
	if (ZNONODE == flag) // znode不存在
	{
		// 创建指定path的znode节点
		flag = zoo_create(m_zhandle, path, data, datalen,
			&ZOO_OPEN_ACL_UNSAFE, state, path_buffer, bufferlen);
		if (flag == ZOK)
		{
			std::cout << "znode create success... path:" << path << std::endl;
		}
		else
		{
			std::cout << "flag:" << flag << std::endl;
			std::cout << "znode create error... path:" << path << std::endl;
			exit(EXIT_FAILURE);
		}
	}
}

// 根据指定path, 获取znode节点的值
std::string ZkClient::GetData(const char *path)
{
    char buffer[64];
	int bufferlen = sizeof(buffer);
	int flag = zoo_get(m_zhandle, path, 0, buffer, &bufferlen, nullptr);
	if (flag != ZOK)
	{
		std::cout << "get znode error... path:" << path << std::endl;
		return "";
	}
	else
	{
		return buffer;
	}
}