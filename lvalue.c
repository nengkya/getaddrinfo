#include <stddef.h> /*NULL*/
#include <stdio.h>

struct node{

    int value;
    struct node * next;

};


int main() {

	/*
    struct node node1, node2;
	struct node node1 = {0}, node2 = {0};
	*/
	struct node node1 = {.value = 1, .next = 0}, node2 = {.value = 2, .next = NULL};

    node1.next  = &node2;

	/*
	the following expressions are typically lvalues in C:
	variable name (int x; x is an lvalue)
	pointer dereference using the unary * operator (* p)
	array element reference (array[i])
	struct or union member access using . or -> (struct.member or pointer->member)
	string literal ("hello") 
	*/

	if (0 == NULL) printf("0 == NULL\n");

	if (NULL == 0) printf("NULL == 0\n");

	if (NULL == (int *) 0)

		printf("NULL == (void *) 0\n");
	
	"hello";
	
	/*
	gcc -w; inhibit all warnings (strongly discouraged for production code)
	int;
	struct{};
	*/

	node1;

	NULL;
	(void) 0;
	(void *) 0;
	(int) 0;
	0;
	
	* p =  4;

}
