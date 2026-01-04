#include <string.h> /*strerror*/
#include <errno.h>
#include <stdio.h>
#include <netdb.h> /*struct addrinfo*/
#include <stdlib.h>

int main() {
    
    int int_socket_file_descriptor, int_getaddrinfo_status_code, int_getnameinfo_status_code;
    struct addrinfo * hints, ** getaddrinfo_result, * getaddrinfo_pointer;
    char host[NI_MAXHOST];    /*#define NameInfo_MAXHOST 1025*/
    char service[NI_MAXSERV]; /*#define NameInfo_MAXSERV   32*/
    char buffer[500];

    socklen_t socklen_t_peer_address_name_length;
    struct sockaddr_storage peer_address;

    int_getaddrinfo_status_code = getaddrinfo("esdm.go.id", "80", hints, getaddrinfo_result);

    fprintf(stderr, "getaddrinfo: %s getaddrinfo from esdm.go.id port 80\n", gai_strerror(int_getaddrinfo_status_code));

    int_socket_file_descriptor = socket((**getaddrinfo_result).ai_family, (**getaddrinfo_result).ai_socktype, (**getaddrinfo_result).ai_protocol);

    fprintf(stderr, "socket error code: %d ", errno);
    fprintf(stderr, "(%s) client open socket port 80 for esdm.go.id\n", strerror(errno));

    if (-1 != connect(int_socket_file_descriptor, (**getaddrinfo_result).ai_addr, (**getaddrinfo_result).ai_addrlen))
        printf("socket port 80 succed connecting into esdm.go.id\n");

    socklen_t_peer_address_name_length = sizeof(peer_address);

    recvfrom(int_socket_file_descriptor, );

    /*
    int getnameinfo(socklen_t hostlen, //uint32_t
                    socklen_t servlen;
                    const struct sockaddr * restrict addr,
                    socklen_t addrlen,
                    char host[_Nullable restrict hostlen],
                    socklen_t hostlen,
                    char serv[_Nullable restrict servlen],
                    socklen_t servlen,
                    int flags);
    int_getnameinfo_status_code = getnameinfo((struct sockaddr*)&peer_address,
                                              socklen_t_peer_address_name_length,
                                              host,
                                              NI_MAXHOST,
                                              service,
                                              NI_MAXSERV,
                                              NI_NUMERICSERV
                                             );
    fprintf(stderr, "%s\n", gai_strerror(int_getnameinfo_status_code));
    */

}
