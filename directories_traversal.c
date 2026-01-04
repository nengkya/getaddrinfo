#include <netdb.h> /*getaddrinfo*/
#include <stddef.h> /*NULL*/
#include <stdio.h>
#include <string.h> /*memset*/
#include <stdlib.h>

void resolve_hostname() {

    int int_getaddrinfo_status_code;
    struct addrinfo * hints, * getaddrinfo_pointer, ** getaddrinfo_result;
    void * internet_address;

    getaddrinfo_result = (struct addrinfo **)malloc(sizeof(struct addrinfo));

    int_getaddrinfo_status_code = getaddrinfo("esdm.go.id", NULL, hints, getaddrinfo_result); /*port NULL*/

    fprintf(stderr, "getaddrinfo status code: %s\n", gai_strerror(int_getaddrinfo_status_code));

    getaddrinfo_pointer = *getaddrinfo_result;

    if ((* getaddrinfo_pointer).ai_family == AF_INET) {

        printf("(*getaddrinfo).ai_family == AF_INET\n");

        /*
        struct addrinfo {
            int ai_flags;
            int ai_family;
            int ai_socktype;
            int ai_protocol;
            socklen_t ai_addrlen;
            struct sockaddr * ai_addr;
            char * ai_canonname;
            struct addrinfo * ai_next;
        };

        struct sockaddr {
            sa_family_t     sa_family; //address family uint32_t
            char            sa_data[]; //socket address
        };

        struct sockaddr_in {
            short            sin_family;  // e.g. AF_INET
            unsigned short   sin_port;    // Port number
            struct in_addr   sin_addr;    // IPv4 address structure
            char             sin_zero[8]; // Padding to make it the same size as struct sockaddr
        };

        struct in_addr {
            unsigned long s_addr; //or in_addr_t, a 32-bit unsigned integer
            uint32_t      s_addr; //address in network byte order
        };
        */
        struct sock_addrin * ip4 = (struct sock_addrin *)(* getaddrinfo_pointer).ai_addr;
        //struct sock_addrin * ip  = (struct sockaddr_in *)(* getaddrinfo_pointer).ai_addr;

        //printf("%ld\n", sizeof(ip));
        printf("%ld\n", sizeof(ip4));

        //internet_address = &((*ip4).sin_addr);

    }

}


int main() {

    resolve_hostname();



}
