#include <netdb.h> /*struct addrinfo*/
#include <stddef.h> /*NULL*/
#include <stdio.h>  /*fprintf*/
#include <stdlib.h> /*exit*/
#include <string.h> /*memset*/
#include <unistd.h> /*close*/
#define port80 "80"

int main() {

    int int_socket_file_descriptor;
    struct addrinfo hints, * getaddrinfo_result, * getaddrinfo_pointer;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC /*allows ip4 or ip6*/;
    hints.ai_socktype = SOCK_DGRAM; /*User Datagram Protocol*/
    hints.ai_flags = AI_PASSIVE; /*wildcard ip*/
    hints.ai_protocol = 0; /*any protocol*/
    hints.ai_canonname = NULL;
    hints.ai_addr = NULL;
    hints.ai_next = NULL;

    getaddrinfo(NULL, "8010", &hints, &getaddrinfo_result);

    /*
    getaddrinfo() returns a list of address structures.
    Try each address until we successfully bind(2).
    If socket(2) (or bind(2)) fails,
    we (close the socket and) try the next address.
    */
    for (getaddrinfo_pointer = getaddrinfo_result; getaddrinfo_pointer != NULL; getaddrinfo_pointer = getaddrinfo_pointer->ai_next) {

        int_socket_file_descriptor = socket(getaddrinfo_pointer->ai_family,
                                            getaddrinfo_pointer->ai_socktype,
                                            getaddrinfo_pointer->ai_protocol);

        if (bind(int_socket_file_descriptor, getaddrinfo_pointer->ai_addr, getaddrinfo_pointer->ai_addrlen) == 0) {
            printf("Open port %d\n", getaddrinfo_pointer->ai_addr->sa_family);
            break;
        }
    }

   if (getaddrinfo_pointer == NULL) {               /* No address succeeded */
               fprintf(stderr, "Could not bind\n");
               exit(EXIT_FAILURE);
           }
}
