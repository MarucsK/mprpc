#pragma once
#include "google/protobuf/service.h"
#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>
#include <muduo/net/TcpConnection.h>
#include <string>
#include <functional>
#include <google/protobuf/descriptor.h>
#include <unordered_map>

// 发布rpc服务
class RpcProvider
{
public:
    // roc提供给外部使用, 发布rpc方法的函数接口
    void NotifyService(google::protobuf::Service *service);

    // 启动rpc服务节点，开始提供rpc远程网络调用服务
    void Run();

private:
    muduo::net::EventLoop m_eventLoop;

    struct ServiceInfo
    {
        google::protobuf::Service *m_service; // Service*
        std::unordered_map<std::string, const google::protobuf::MethodDescriptor *> m_methodMap; // <method_name, MethodDescriptor*>
    };
    std::unordered_map<std::string, ServiceInfo> m_serviceMap; // <service_name, ServiceInfo>

    void OnConnection(const muduo::net::TcpConnectionPtr&);
    void OnMessage(const muduo::net::TcpConnectionPtr&, muduo::net::Buffer*, muduo::Timestamp);
    // Closure回调操作，用于序列化rpc的响应和网络发送
    void SendRpcResponse(const muduo::net::TcpConnectionPtr&, google::protobuf::Message*);
};