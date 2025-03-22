# mprpc
![GitHub License](https://img.shields.io/github/license/xykCs/mprpc?color=%23FFD700)

### RPC理论
![image](https://github.com/user-attachments/assets/26516743-01ab-488c-8ed2-51fc3492f547)
Red Section: Design the packaging and parsing of RPC method parameters, specifically data serialization and deserialization, using **Protobuf**.

Purple Section: Network part, including locating the RPC service host, initiating RPC call requests, and responding to RPC call results, using the **Muduo** network library and **Zookeeper** service configuration center.
