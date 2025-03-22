# mprpc
![GitHub License](https://img.shields.io/github/license/xykCs/mprpc?color=%23FFD700)

### RPC
![image](https://github.com/user-attachments/assets/26516743-01ab-488c-8ed2-51fc3492f547)
The MPRPC framework primarily includes the content of the following two sections.
- Red Section: Design the packaging and parsing of RPC method parameters, specifically data serialization and deserialization, using **Protobuf**.
- Purple Section: Network part, including locating the RPC service host, initiating RPC call requests, and responding to RPC call results, using the **Muduo** network library and **Zookeeper** service configuration center.

### Project Architecture Diagram
![13e425432c3e379132edde527c6ebe3](https://github.com/user-attachments/assets/221a6b22-1f15-4939-ac26-9df9ba956ab6)
### QuickStart
This project runs on Linux and requires the following dependencies:
- Zookeeper 3.4.10 and above
- Muduo Network Library
- CMake 3.0 and above
- C++11

```sh
./autobuild.sh
```
