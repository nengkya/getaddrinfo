#include <stdio.h>
#include "stdlib.h"


struct object {

    struct object_control * pointer_to_struct_object_control;

    int int_value;

};


struct object_control {

    int int_strong;

    int int_weak;

    struct object * pointer_to_struct_object; 

};


struct object * new_object(int int_value) {

    struct object_control * pointer_to_struct_object_control = (struct object_control *)malloc(sizeof * pointer_to_struct_object_control);

    struct object * pointer_to_struct_object                 = (struct object         *)malloc(sizeof * pointer_to_struct_object);

    (* pointer_to_struct_object_control).int_strong = 1;

    (* pointer_to_struct_object_control).int_weak   = 0;

    (* pointer_to_struct_object_control).pointer_to_struct_object = pointer_to_struct_object;

    (* pointer_to_struct_object).pointer_to_struct_object_control = pointer_to_struct_object_control;

    printf("create object at address %p\n", (void *)pointer_to_struct_object);

    return pointer_to_struct_object;

}


struct new_weak_pointer {

    struct object_control * pointer_to_object_control;

};











int main() {

    struct object * struct_object = new_object(12);

    struct weak_pointer struct_weak_pointer = new_weak_pointer(struct_object);








    return 0;

}
