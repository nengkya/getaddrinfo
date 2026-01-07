#include <netdb.h> /*getaddrinfo*/
#include <stddef.h> /*NULL*/
#include <stdio.h>
#include <string.h> /*memset*/
#include <stdlib.h>


char ** wordlist;
int line;


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

        struct sockaddr_in * ip4 = (struct sockaddr_in *)(* getaddrinfo_pointer).ai_addr;

        internet_address = &((*ip4).sin_addr);

    }

}


void load_wordlist() {

    FILE * FILE_pointer = fopen("directory_list.txt", "r");
    char * line_of_wordlist = (char *)malloc(256);

    if (!FILE_pointer) perror("failed open wordlist file !");

    /*file get string*/
    while (fgets(line_of_wordlist, sizeof(line_of_wordlist), FILE_pointer)) {

        printf("%s %ld %ld\n", line_of_wordlist, strlen(line_of_wordlist), sizeof(line_of_wordlist));

        /*string complementary span; remove \n*/
        line_of_wordlist[strcspn(line_of_wordlist, "\n")] = 0;
        
        //printf("%s %ld %ld\n", line_of_wordlist, strlen(line_of_wordlist), sizeof(line_of_wordlist));
 
        char * directory_path = (char *)malloc(sizeof(line_of_wordlist));
 
        //sprintf();

        break;

    }

    line++;

}




int main() {

    resolve_hostname();
    load_wordlist();


}























