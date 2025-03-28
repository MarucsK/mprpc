# mprpc
![GitHub License](https://img.shields.io/github/license/xykCs/mprpc?color=%23FFD700)

### RPC
![image](https://github.com/user-attachments/assets/26516743-01ab-488c-8ed2-51fc3492f547)
The MPRPC framework primarily includes the content of the following two sections.
- Red Section: Design the packaging and parsing of RPC method parameters, specifically data serialization and deserialization, using **Protobuf**.
- Purple Section: Network part, including locating the RPC service host, initiating RPC call requests, and responding to RPC call results, using the **Muduo** network library and **Zookeeper** service configuration center.

Developed based on the Muduo network library and Protobuf, hence named mprpc.

### Program Execution Sequence Diagram
![7107a36cf38b910afdd92dd7fc5bcbc](https://github.com/user-attachments/assets/1ad211ea-f6d4-433a-8e06-53cf70584352)

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
