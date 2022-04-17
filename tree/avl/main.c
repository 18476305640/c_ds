#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"
#include "math.h"
int main() {

    Tree *tree = avl_create();
    add(tree,15);
    add(tree,6);
    add(tree,23);
    add(tree,4);
    add(tree,7);
    add(tree,71);
    add(tree,5);
    add(tree,50);


    node_remove(tree,5);
    add(tree,59);
    node_remove(tree,59);
    tree_print(tree);
    printf("pause~");
}
