#include <stdio.h>

#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

char arr[10000][100];

int run_tcp_server()
{
    int wsRet = 0;

    WSADATA WSAData;
    SOCKET s, conn;
    SOCKADDR_IN serverAddr, clientAddr;

    wsRet = WSAStartup(MAKEWORD(2, 0), &WSAData);
    s = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(89000);

    wsRet |= bind(s, (SOCKADDR *)&serverAddr, sizeof(serverAddr));
    wsRet |= listen(s, 0);

    printf("Listening for incoming connections...\n");

    char buffer[1024];
    int clientAddrSize = sizeof(clientAddr);
    conn = accept(s, (SOCKADDR *)&clientAddr, &clientAddrSize);
    if (conn != INVALID_SOCKET)
    {
        printf("            Client connected!\n");
        wsRet = recv(conn, buffer, sizeof(buffer), 0);
        printf("            Client says: %s \n", buffer);
        int answer = reply(buffer);

        wsRet = send(conn, arr[answer], sizeof(arr[answer]), 0);
        Beep(1000, 1000);
        memset(buffer, 0, sizeof(buffer));

        wsRet = closesocket(conn);
        printf("Client disconnected.\n");
    } else 
    {
        printf("client connection failure!\n");
    }

    return 0;
}

int run_tcp_client()
{
    int wsRet = 0;

    WSADATA WSAData;
    SOCKET s;
    SOCKADDR_IN addr;

    wsRet = WSAStartup(MAKEWORD(2, 0), &WSAData);
    s = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_addr.s_addr = inet_addr("10.46.30.186");
    addr.sin_family = AF_INET;
    addr.sin_port = htons(89000);

    wsRet = connect(s, (SOCKADDR *)&addr, sizeof(addr));

    printf("Connected to server!\n");

    char buffer[1024], reply[1000];

    printf("Enter a message:");

    gets(buffer);
    wsRet = send(s, buffer, sizeof(buffer), 0);

    printf("Message sent!\n");
    Beep(1000, 1000);

    wsRet = recv(s, reply, sizeof(reply), 0);
    printf("\n          Server reply : %s\n", reply);

    wsRet = closesocket(s);
    wsRet = WSACleanup();

    printf("Socket closed.");

    return 0;
}