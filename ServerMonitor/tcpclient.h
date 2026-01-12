#pragma once
#include <string>

class TcpClient {
public:
    TcpClient(const std::string& host = "127.0.0.1", int port = 7777);

    std::string sendCommand(const std::string& command);

private:
    std::string host;
    int port;
};
