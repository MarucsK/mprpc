# mprpc
![GitHub License](https://img.shields.io/github/license/xykCs/mprpc?color=%23FFD700)

### RPC
![image](https://github.com/user-attachments/assets/26516743-01ab-488c-8ed2-51fc3492f547)
The MPRPC framework primarily includes the content of the following two sections.
- Red Section: Design the packaging and parsing of RPC method parameters, specifically data serialization and deserialization, using **Protobuf**.
- Purple Section: Network part, including locating the RPC service host, initiating RPC call requests, and responding to RPC call results, using the **Muduo** network library and **Zookeeper** service configuration center.

### Program Execution Sequence Diagram
![4bee8815c837bfcaeb3e304cf8ca078](https://github.com/user-attachments/assets/85e65056-329f-44f9-be22-c2a5f9355571)


### QuickStart
This project runs on Linux and requires the following dependencies:
- Zookeeper 3.4.10 and above
- Muduo Network Library
- CMake 3.0 and above
- C++11

Ensure all necessary dependencies are installed, run the autobuild script:
```sh
./autobuild.sh
```
