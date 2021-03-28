#include <iostream>
#ifdef _WIN32 // Windows
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable: 4996)
#else // unix
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#endif

void ClientTCP() {
#ifdef _WIN32
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);
#endif
    int client_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    sockaddr_in SocketConn;
    SocketConn.sin_addr.s_addr = inet_addr("192.168.0.100");
    SocketConn.sin_port = htons(44444);
    SocketConn.sin_family = AF_INET;

    char msg[] = "Hello from C++ by TCP!";
    connect(client_sock, (sockaddr*)&SocketConn, sizeof(sockaddr_in));
    send(client_sock, msg, sizeof(msg), NULL);

#ifdef _WIN32
    closesocket(client_sock);
    WSACleanup();
#else
    close(client_sock);
#endif
}

void ClientUDP() {
#ifdef _WIN32
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);
#endif
    int client_sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    sockaddr_in SocketConn;
    SocketConn.sin_addr.s_addr = inet_addr("192.168.0.100");
    SocketConn.sin_port = htons(55555);
    SocketConn.sin_family = AF_INET;

    char msg[] = "Hello from C++ by UDP!";
    sendto(client_sock, msg, sizeof(msg), NULL, (sockaddr*)&SocketConn, sizeof(sockaddr_in));

#ifdef _WIN32
    closesocket(client_sock);
    WSACleanup();
#else
    close(client_sock);
#endif
}

int main()
{
    std::cout << "Client:\nSelect socket mode TCP[1] or UDP[2]: ";
    char mode;
    std::cin >> mode;
    
    if (mode == '1') {
        ClientTCP();
    }
    else if (mode == '2') {
        ClientUDP();
    }
    else {
        std::cout << "Wrong!\n";
    }
    exit(0);
}
