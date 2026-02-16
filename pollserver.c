#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <poll.h>


#define PORT "3000"

const char *inet_ntop2(void *addr,char *buf,size_t size){
    struct sockaddr_storage *sas=addr;
    struct sockaddr_in *sa4;
    struct sockaddr_in6 *sa6;
    void *src;

    switch(sas->ss_family){
        case AF_INET:
            sa4=(struct sockaddr_in *)sas;
            src=&sa4->sin_addr;
            break;
        case AF_INET6:
            sa6=(struct sockaddr_int6 *)sas;
            src = &(sa6->sin6_addr);
            break;
        default:
            return NULL;
    }
    return inet_ntop(sas->ss_family,src,buf,size);

}