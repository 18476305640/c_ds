#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
#include "math.h"
int main() {

    Tree *tree = bst_create();
    for (int i = 0; i <1000; ++i) {
        int *a = rand();
        add(tree,a);
    }
    bst_print(tree);
    if (contain(tree,3331)) {
        printf("Found!\n");
    } else {
        printf("No Found~\n");
    }
    printf("pause~");
}
