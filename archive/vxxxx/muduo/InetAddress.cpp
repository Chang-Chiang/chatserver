#include "InetAddress.hpp"

#include <strings.h> // bzero

#include <cstring>

// #define BUFFER_SIZE 64
static const int BUFFER_SIZE = 64;

InetAddress::InetAddress(uint16_t port, std::string ip) {
    bzero(&addr_, sizeof(addr_));
    addr_.sin_family = AF_INET;
    addr_.sin_port = htons(port);
    addr_.sin_addr.s_addr = inet_addr(ip.c_str());
}

std::string InetAddress::toIp() const {
    char buffer[BUFFER_SIZE] = {0};
    inet_ntop(AF_INET, &addr_.sin_addr, buffer, sizeof(buffer));
    return buffer;
}

std::string InetAddress::toIpPort() const {
    // ip : port
    char     buffer[BUFFER_SIZE] = {0};
    size_t   end = strlen(buffer);
    uint16_t port = ntohs(addr_.sin_port);
    sprintf(buffer + end, " : %u", port);

    return buffer;
}

uint16_t InetAddress::toPort() const { return ntohs(addr_.sin_port); }
