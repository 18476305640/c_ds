#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"
#include "math.h"
int main() {

    Tree *tree = avl_create();
    add(tree,44);
    add(tree,16);
    add(tree,56);
    add(tree,12);
    add(tree,21);
    add(tree,96);
    add(tree,35);
    add(tree,78);
    tree_print(tree);
    printf("height=%d\n",tree_height(tree));
    printf("pause~");
}
