//
// Created by 21192 on 2022/4/14.
//
#define OK 1
#define NO 0

typedef struct node {
    void *data;
    struct Node *lchild,*rchild;
    struct Node *parent;
} Tree,Node;

Tree* bst_create();
int add(Tree *tree, void *value);
void bst_print(Tree *tree);
int contain(Tree *tree, void *key);


