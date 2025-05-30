# mprpc
![GitHub License](https://img.shields.io/github/license/xykCs/mprpc?color=%23FFD700)

### Introduction
The MPRPC framework primarily includes the content of the following two sections.
- Design the packaging and parsing of RPC method parameters, specifically data serialization and deserialization, using **Protobuf**.
- Network part, including locating the RPC service host, initiating RPC call requests, and responding to RPC call results, using the **Muduo** network library and **Zookeeper** service configuration center.

### QuickStart
Runs on Linux with dependencies:
- Zookeeper 3.4.10 and above
- Muduo Network Library
- CMake 3.0 and above
- g++ 4.8.1 and above

Ensure all necessary dependencies are installed, run the script:
```sh
./autobuild.sh
```

## License
This project is licensed under the MIT License. See the [LICENSE](./LICENSE) file for more details.
