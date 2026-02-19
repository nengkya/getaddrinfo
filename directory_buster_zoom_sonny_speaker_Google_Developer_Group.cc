#include <stdlib.h>
#include <stdio.h> /*fprintf*/
#include "netdb.h" /*getaddrinfo*/
#include <string.h> /*memset*/



int connect_to_host() {

    int int_getaddrinfo_status_code;

    int int_socket_file_descriptor;

    struct addrinfo * struct_addrinfo_hints_pointer, * getaddrinfo_result_pointer, * struct_addrinfo_pointer;

    struct_addrinfo_hints_pointer = (struct addrinfo *)malloc(sizeof * struct_addrinfo_hints_pointer);

    /*without memset, result in bad value for ai_flags*/
    memset(struct_addrinfo_hints_pointer, 0, sizeof * struct_addrinfo_hints_pointer);

    /*
    node = host = domain name dari web server
    restrict = only 1 pointer pointing into memory address, for safety data race condition
    service = port -> 80
    hints = give clue to getaddrinfo about internet protocol or socket type that will be used
    int getaddrinfo(const char * restrict node,
                    const char * restrict service,
                    const struct addrinfo * restrict hints,
                    struct addrinfo ** restrict getaddrinfo_result);
    */
    int_getaddrinfo_status_code = getaddrinfo("esdm.go.id", "80", struct_addrinfo_hints_pointer, &getaddrinfo_result_pointer);

    /*file print format, getaddrinfo string error*/
    fprintf(stderr, "getaddrinfo from esdm.go.id status code %s\n", gai_strerror(int_getaddrinfo_status_code));

    for (struct_addrinfo_pointer = getaddrinfo_result_pointer; struct_addrinfo_pointer != (struct addrinfo *)0; (* struct_addrinfo_pointer).ai_next) {

        /*
        create or open new socket for connection into web server
        int socket(int domain, int type, int protocol);
        */
        int_socket_file_descriptor = socket((* struct_addrinfo_pointer).ai_family,
                                            (* struct_addrinfo_pointer).ai_socktype,
                                            (* struct_addrinfo_pointer).ai_protocol);

        /*
        means this address cannot even create a socket — try the next one."

        without continue, you would :

        attempt connect() on an invalid descriptor

        trigger undefined behavior

        possibly crash
        */
        if (int_socket_file_descriptor == -1) continue;

        /*
        connect the opened port into web server
        socklen_t is an unsigned int
        connect(int socket_file_descriptor, const struct sockaddr * socket_address_pointer, socklen_t address length);
        */
        if (connect(int_socket_file_descriptor, (* struct_addrinfo_pointer).ai_addr, (* struct_addrinfo_pointer).ai_addrlen) == 0) break;

        /*if you do not call close(int_sockect_file_descriptor);, those kernel resources remain allocated*/
        close(int_socket_file_descriptor);

    }

    free(struct_addrinfo_hints_pointer);      struct_addrinfo_hints_pointer = (struct addrinfo *)0;
    freeaddrinfo(getaddrinfo_result_pointer); getaddrinfo_result_pointer    = (struct addrinfo *)0;

    return int_socket_file_descriptor;

}


int check_path() {

    int socket_file_descriptor = connect_to_host();

    /*
    send data over network with previous connect(); established setting, alias kirim send request to the web server with previous connect(); setting

    size_t send(int socket, );
    */
    send();












}









int main() {

    int status; /*404, 200*/

    status = check_path();






}
