//
// Created by 21192 on 2022/4/16.
//
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define NO 0

typedef struct node {
    void *data;
    struct Node *lchild,*rchild;
    struct Node *parent;
} Tree,Node;

Tree* avl_create();
int add(Tree *tree, void *value);
void tree_print(Tree *tree);
int contain(Tree *tree, void *key);
int node_remove(Tree *tree, void *key);