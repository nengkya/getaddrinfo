#include <netdb.h> /*struct addrinfo*/
#include <stddef.h> /*NULL*/
#include <stdio.h>  /*fprintf*/
#include <stdlib.h> /*exit*/
#include <string.h> /*memset*/
#include <unistd.h> /*close*/

int main() {

    int int_getaddrinfo_status_code, iteration = 0, int_socket_file_descriptor;
    struct addrinfo * hints, ** getaddrinfo_result, * getaddrinfo_pointer;

    (* hints).ai_family = AF_UNSPEC;    /*allows ip4 or ip6*/
    (* hints).ai_socktype = SOCK_DGRAM; /*User Datagram Protocol, SOCK_STREAM TCP*/
    (* hints).ai_flags = AI_PASSIVE;    /*wildcard ip*/
    (* hints).ai_protocol = 0;          /*any protocol*/

    int_getaddrinfo_status_code = getaddrinfo(NULL, "8330", hints, getaddrinfo_result);
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(int_getaddrinfo_status_code));

    /*
    getaddrinfo() returns a list of address structures.
    Try each address until we successfully bind(2).
    If socket(2) (or bind(2)) fails,
    we (close the socket and) try the next address.
    */
    for (getaddrinfo_pointer = *getaddrinfo_result; getaddrinfo_pointer != NULL; iteration++, getaddrinfo_pointer = getaddrinfo_pointer->ai_next) {

        iteration++;
        int_socket_file_descriptor = socket((*getaddrinfo_pointer).ai_family,
                                            (*getaddrinfo_pointer).ai_socktype,
                                            (*getaddrinfo_pointer).ai_protocol);

        if (bind(int_socket_file_descriptor, getaddrinfo_pointer->ai_addr, getaddrinfo_pointer->ai_addrlen) == 0) {
            printf("iteration %d: (*(*getaddrinfo_pointer).ai_addr).sa_family: %d\n", iteration, (*(*getaddrinfo_pointer).ai_addr).sa_family);
            break;
        }

    }

}
