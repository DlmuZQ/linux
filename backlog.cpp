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

    //create socket
    int sockfd = socket(PF_INET, SOCK_STREAM, 0);
    assert(sockfd > 0);

    //set address 
    struct sockaddr_in address;
    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &address.sin_addr);
    address.sin_port = htons(port);

    //rename 
    int ret = bind(sockfd, (struct sockaddr *)&address, sizeof(address));
    assert(ret != -1);

    //listen
    ret = listen(sock, backlog);
    assert(ret != -1);

    //wait to quit
    while (!stop)
    {
        printf(".....");
        sleep(1);
    }
    //close
    close(sockfd);
    printf("quit...");
    return 0;
}