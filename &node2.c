struct node{

    int value;
    struct node * next;

};


int main() {

	struct node node1 = {.value = 1, .next = 0}, node2 = {.value = 2, .next = NULL};

    node1.next  = &node2;

}
