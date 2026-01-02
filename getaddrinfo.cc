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
if restricted overlaps with array1 or array2, the compiler might struggle.
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

Protocol Family (e.g., TCP/IP) defines the rules,
while Address Family defines the address structure (e.g., 32-bit IP) for those rules.
AF_LOCAL
This designates the address format that goes with the local namespace (PF_LOCAL is the name of that namespace)
AF_UNIX
This is a synonym for AF_LOCAL. Although AF_LOCAL is mandated by POSIX,
AF_UNIX is portable to more systems.
AF_UNIX was the traditional name stemming (NLP) untuk mengurangi kata-kata berimbuhan) from BSD,
so even most POSIX systems support it.
It is also the name of choice in the Unix98 specification. (The same is true for PF_UNIX vs. PF_LOCAL).
AF_FILE
This is another synonym for AF_LOCAL, for compatibility. (PF_FILE is likewise a synonym for PF_LOCAL.)
AF_INET
This designates the address format that goes with the Internet namespace. (PF_INET is the name of that namespace.)
AF_INET6
This is similar to AF_INET, but refers to the IPv6 protocol. (PF_INET6 is the name of the corresponding namespace.)
AF_UNSPEC
This designates no particular address format.
It is used only in rare cases, such as to clear out the default destination address of a “connected” datagram socket
The corresponding namespace designator symbol PF_UNSPEC exists for completeness, but there is no reason to use it in a program.
AF_INET  for older IPv4 (32-bit) addresses.
AF_INET6 for the newer, vastly larger IPv6 (128-bit) address space.
SOCK_STREAM           TCP
SOCK_DGRAM (datagram) UDP
socklen_t Describes the length of a socket address. This is an integer type of at least 32 bits.

struck sockaddr {
    sa_family_t sa_family; //unsigned short AF_xxx
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

    if (int_getaddrinfo = getaddrinfo(NULL, port80, hints, addrinfo_result))
        fprintf(stderr, "%d\n", gai_strerror(int_getaddrinfo));

}
