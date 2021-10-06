#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

static bool stop = false;

static void handle_term(int sig)
{
    stop = true;
}

int main(int argc, char* argv[])
{
    signal(SIGTERM, handle_term);
    if (argc < 3)
    {
        printf("use 3 xxx xxx xxx");
        return 1;
    }
    const char* ip = argv[1];
    int port = atoi(argv[2]);
    int backlog = atoi(argv[3]);

    
}