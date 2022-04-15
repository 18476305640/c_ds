#include "BST.h"
#include <stdio.h>
#include <stdlib.h>

Tree* bst_create() {
    Tree *tree = (Tree*)malloc(sizeof(Tree));
    tree->data = NULL;
    tree->lchild = NULL;
    tree->rchild = NULL;
    tree->parent = NULL;
    return tree;
}
int add(Tree *tree, void *value) {
    //第一个元素
    if (tree->data == NULL) {
        tree->data = value;
        return OK;
    }

    //创建一个节点
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->lchild = NULL;
    node->rchild = NULL;
    node->parent = NULL;

    //判断要放在哪里
    Node *tmp = tree;
    while (tmp != NULL) {

        if (tmp->data > value) {
            if (NULL == tmp->lchild) {
                //放在左边
                node->parent = tmp;
                tmp->lchild = node;
                return OK;
            } else {
                //向左边走
                tmp = tmp->lchild;
            }
        } else if (tmp->data < value) {
            if (NULL == tmp->rchild) {
                //放在右边
                node->parent = tmp;
                tmp->rchild = node;
                return OK;
            } else {
                //向右边走
                tmp = tmp->rchild;
            }
        } else{
            //值重复了，需要释放创建的节点
            free(node);
            return NO;
        }
    }


    return OK;

}
void bst_print(Tree *tree) {
    if (tree == NULL) return;
    Node *parent = tree->parent;
    if (parent == NULL) {
        printf("%d(NULL) ",tree->data);
    } else{
        printf("%d(%d) ",tree->data,parent->data);
    }

    bst_print(tree->lchild);
    bst_print(tree->rchild);


}

int contain(Tree *tree, void *key) {
    Tree *tmp = tree;
    while (NULL != tmp) {
        if (tmp->data == key) {
            return OK;
        }
        if (tmp->data > key) {
            tmp = tmp->lchild;
        } else {
            tmp = tmp->rchild;

        }
    }

    return NO;
}
