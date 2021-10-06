#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("use 2 xxx xxx");
        return 1;
    }
    const char* ip = argv[1];
    int port = atoi(argv[2]);

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
    ret = listen(sockfd, 5);
    assert(ret != -1);

    sleep(20);

    struct sockaddr_in client;
    socklen_t client_len = sizeof(client);
    int connfd = accept(sockfd, (struct sockaddr *)&client, &client_len);
    if (connfd < 0)
    {
        printf("error");
    }
    else 
    {
        char remote[INET_ADDRSTRLEN];
        printf("ip %s, port %d \n", inet_ntop(AF_INET, &client.sin_addr, remote, INET_ADDRSTRLEN), ntohs(client.sin_port));
        close(connfd);
    }
    //close
    close(sockfd);
    printf("quit...");
    return 0;
}