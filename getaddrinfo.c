/*
restrict allow to save one assembly instruction

By adding this type qualifier, a programmer hints to the compiler that for the lifetime of the pointer,
no other pointer will be used to access the object to which it points.
This allows the compiler to make optimizations (for example, vectorization) that would not otherwise have been possible.

restrict limits the effects of pointer aliasing, aiding optimizations.
If the declaration of intent is not followed and the object is accessed by an independent pointer, this will result in undefined behavior.

Signals exclusive access: int * restrict ptr;
promises the compiler that ptr and any other pointer to the same data will not overlap or access the same memory in conflicting ways.

Enables optimizations: Without restrict, compilers add safety checks for aliasing (multiple pointers to same memory).
With restrict, they can skip checks, unroll loops, and use SIMD (vector) instructions for speed.

Example: In restricted[i] = array1[i] + array2[i];
if res overlaps with arr1 or arr2, the compiler might struggle.
With int * restrict array1, * restrict restricted, the compiler knows they are separate and can optimize the loop.

int getaddrinfo(const char * restrict node,
                const char * restrict service,
                const struct addrinfo * restrict hints,
                struct addrinfo ** restrict res);

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

AF_INET  for older IPv4 (32-bit) addresses.
AF_INET6 for the newer, vastly larger IPv6 (128-bit) address space.
SOCK_STREAM TCP
SOCK_DGRAM (datagram) UDP
socklen_t Describes the length of a socket address. This is an integer type of at least 32 bits.

struck sockaddr {
    sa_family_t sa_family; //unsigned short
    char sa_data[];
};
*/

#include <netdb.h> /*struct addrinfo*/
#include <stddef.h> /*NULL*/
#include <stdio.h>  /*fprintf*/
#define port80 "80"

int main() {

    int int_getaddrinfo;
    struct addrinfo * hints, ** addrinfo_result;

    hints->ai_family = AF_UNSPEC /*allows ip4 or ip6*/;
    hints->ai_socktype = SOCK_DGRAM; /*User Datagram Protocol*/
    /*
    AI_CANONNAME
    AI_NUMERICHOST
    AI_NUMERICSERV
    AI_V4MAPPED
    AI_ALL
    AI_ADDRCONFIG
    AI_EXTFLAGS
    */
    hints->ai_flags = AI_PASSIVE; /*wildcard ip*/
    /*
    IPPROTO_TCP
    IPPROTO_UDP
    IPPROTO_ICMP    //Internet Control Message Protocol
    IPPROTO_ICMPV6  //ICMP for IPv6
    IPPROTO_RAW     //Raw IP packets
    IPPROTO_SCTP    //Stream Control Transmission Protocol
    */
    hints->ai_protocol = 0; /*any protocol*/

    //int_getaddrinfo = getaddrinfo(NULL, port80, hints, addrinfo_result);
    
    if (int_getaddrinfo = getaddrinfo(NULL, port80, hints, addrinfo_result))
        fprintf(stderr, "%s\n", gai_strerror(int_getaddrinfo));

}
















