#include <stdio.h> /*FILE*/

int main() {

    /*url port wordlist*/
    FILE * file_pointer = fopen("apache-user-enum-1.0.txt", "r");
    char word[256];

    if (!file_pointer) perror("error fopen\n");

    /*
    file get string
    char * fgets(char *str, int n, FILE * stream);
    */
    fgets(word, sizeof(word), file_pointer);

    connect_to_host();

}
