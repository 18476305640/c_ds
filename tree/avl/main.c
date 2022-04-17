#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"
#include "math.h"
int main() {

    Tree *tree = avl_create();
    add(tree,89);
    add(tree,28);
    add(tree,97);
    add(tree,2);
    add(tree,30);
    add(tree,91);
    add(tree,99);
    add(tree,1);
    add(tree,6);
    add(tree,73);
    add(tree,50);



    node_remove(tree,30);
    node_remove(tree,73);
    node_remove(tree,1);
    node_remove(tree,6);
    tree_print(tree);
    printf("pause~");
}
