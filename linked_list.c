#include <stdio.h> /*fprintf*/
#include <stdlib.h> /*NULL, malloc*/


struct node{

    int value;
    struct node * next;

};

int create_list(struct node * out_head) {

    struct node n1;
    struct node n2;

    n1.value = 1;
    n1.next  = &n2;

    * out_head = n1; //return list to caller

    return 0;
}

int main() {

	struct node head = {0};

	create_list(&head);

	struct node * temp = head.next;

	int a = temp->value;	

	printf("%d\n", a);

}
