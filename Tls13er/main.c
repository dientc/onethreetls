#include <stdio.h>

extern 
void sha256_string(
        char *string, 
        char outputBuffer[65]
        );

extern
int run_tcp_server();

extern
int run_tcp_client();

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Run: main.exe 0/1\n");

        return 0;
    }

    if (0 == atoi(argv[1]))
    {
        printf("start a tcp server\n");
        run_tcp_server();
    } else if (1 == atoi(argv[1]))
    {
        printf("start a tcp client\n");
        run_tcp_client();
    } else  
    {
        printf("unexpected input\n");
    }

    return 0;
}