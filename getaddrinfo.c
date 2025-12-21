#include <netdb.h> /*struct addrinfo*/
#include <stddef.h> /*NULL*/
#include <stdio.h>  /*fprintf*/
#include <stdlib.h> /*exit*/
#include <string.h> /*memset*/
#define port80 "80"

int main() {

    int int_getaddrinfo, int_socket_file_descriptor;
    struct addrinfo * hints, * getaddrinfo_result, * getaddrinfo_pointer;

    memset(hints, 0, sizeof(hints));
    hints->ai_family = AF_UNSPEC /*allows ip4 or ip6*/;
    hints->ai_socktype = SOCK_DGRAM; /*User Datagram Protocol*/
    hints->ai_flags = AI_PASSIVE; /*wildcard ip*/
    hints->ai_protocol = 0; /*any protocol*/
    hints->ai_canonname = NULL;
    hints->ai_addr = NULL;
    hints->ai_next = NULL;

    if (int_getaddrinfo = getaddrinfo(NULL, port80, hints, &getaddrinfo_result))
        fprintf(stderr, "%s\n", gai_strerror(int_getaddrinfo));

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
        if (int_socket_file_descriptor = -1) continue;

        if (0 == bind(int_socket_file_descriptor, getaddrinfo_pointer->ai_addr, getaddrinfo_pointer->ai_addrlen)) {
            /*printf("Open port %d\n", getaddrinfo_pointer->ai_addr->sa_family);*/
            break;
        }

    }

    freeaddrinfo(getaddrinfo_result);
    /*no address succeeded*/
    if (getaddrinfo_pointer == NULL) {
        fprintf(stderr, "Could not bind\n");
        exit(EXIT_FAILURE);
    }

}
