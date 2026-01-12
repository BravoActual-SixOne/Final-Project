#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "TcpClient.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdexcept>

#pragma comment(lib, "ws2_32.lib")

TcpClient::TcpClient(const std::string& h, int p)
    : host(h), port(p) {}

std::string TcpClient::sendCommand(const std::string& command) {
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET)
        throw std::runtime_error("Socket error");

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(host.c_str());

    if (connect(sock, (sockaddr*)&addr, sizeof(addr)) < 0) {
        closesocket(sock);
        WSACleanup();
        throw std::runtime_error("Server not available");
    }

    send(sock, command.c_str(), command.size(), 0);

    char buffer[4096];
    int bytes = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (bytes <= 0) {
        closesocket(sock);
        WSACleanup();
        throw std::runtime_error("Connection closed or receive error");
    }
    buffer[bytes] = '\0';

    closesocket(sock);
    WSACleanup();

    return std::string(buffer);
}
