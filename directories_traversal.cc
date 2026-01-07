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

    fprintf(stderr, "getaddrinfo from esdm.go.id status code: %s\n", gai_strerror(int_getaddrinfo_status_code));

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
        struct sockaddr_in * ip4 = (struct sockaddr_in *)(* getaddrinfo_pointer).ai_addr;

        internet_address = &((*ip4).sin_addr);

        /*internet network to presentation; 1011.0001.1101.1111 to 192.186.0.1*/


    }

}


int main() {

    resolve_hostname();



}
