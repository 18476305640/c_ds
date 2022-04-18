#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"
#include "math.h"
int main() {

    Tree *tree = avl_create();
    add(tree,11);
    add(tree,8);
    add(tree,47);
    add(tree,7);
    add(tree,46);
    add(tree,72);
    add(tree,26);
    add(tree,63);
    add(tree,77);
    add(tree,67);



    node_remove(tree,30);
    node_remove(tree,73);
    node_remove(tree,1);
    node_remove(tree,6);
    tree_print(tree);
    printf("\npause~");
}
