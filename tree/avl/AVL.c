#include "AVL.h"


Tree* avl_create() {
    Tree *tree = (Tree*)malloc(sizeof(Tree));
    tree->data = NULL;
    tree->lchild = NULL;
    tree->rchild = NULL;
    tree->parent = NULL;
    tree->height = 1;
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
    node->height = 1; //节点加入树中，一定是叶子节点

    //判断要放在哪里
    Node *tmp = tree;
    while (tmp != NULL) {

        if (tmp->data > value) {
            if (NULL == tmp->lchild) {
                //放在左边
                node->parent = tmp;
                tmp->lchild = node;
                //更新树的高度
                up_update_height(node->parent);
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
                //更新树的高度
                up_update_height(node->parent);
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
void tree_print(Tree *tree) {
    if (tree == NULL) return;
    Node *parent = tree->parent;
    if (parent == NULL) {
        printf("%d(NULL)(h=%d) ",tree->data,tree->height);
    } else{
        printf("%d(%d)(h=%d) ",tree->data,parent->data,tree->height);
    }

    tree_print(tree->lchild);
    tree_print(tree->rchild);


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
//节点的删除：分三种情况
int node_remove(Tree *tree, void *key) {
    if(! contain(tree,key)) return NO;
    Tree *tmp = tree;
    while (NULL != tmp) {
        if (tmp->data == key) {
            //找到了要删除的节点tmp
            if(tmp->lchild == NULL && tmp->rchild == NULL) {
                //这是一个叶子节点，让父节点的指向该节点变为NULL
                Node *parent = tmp->parent;
                if (parent->rchild == tmp) {
                    //要删除的节点是双亲的右节点
                    parent->rchild = NULL;
                } else {
                    //要删除的节点是双亲的左节点
                    parent->lchild = NULL;
                }
                //释放掉被删除的节点
                free(tmp);
                //从tmp的父节点开始向上维护树的高度
                up_update_height(parent);
            } else if (tmp->lchild == NULL || tmp->rchild == NULL) {
                //度为1的分支节点, 将子节点替换要删除的节点
                Node *del_parent = tmp->parent;
                Node *target = (tmp->lchild != NULL)?tmp->lchild:tmp->rchild;
                target->parent = del_parent;
                if (tmp == del_parent->lchild) {
                    //tmp是双亲的左子节点
                    del_parent->lchild = target;
                } else{
                    //tmp 是双亲的右子节点
                    del_parent->rchild = target;
                }
                free(tmp);
                up_update_height(target->parent);


            } else {
                //度为2的分支节点, 左边最大或右边最小
                Node *right_min = tmp->rchild;
                while (right_min->lchild != NULL) {
                    right_min = right_min->lchild;
                }
                tmp->data = right_min->data;
                node_remove(tmp->rchild,right_min->data);

            }

            return OK;
        }else if(tmp->data > key) {
            tmp = tmp->lchild;
        } else {
            tmp = tmp->rchild;

        }

    }
    return NO;
}

//计算树的高度, 想要计算树的高度，需要添加height属性，更新树的高度
void down_update_height(Tree *tree) {
    //如果是叶子节点，高度是1
    if (tree->rchild == NULL && tree->lchild == NULL) {
        tree->height = 1;
    }
    //如果不是叶子节点，那么高度肯定大于1
    Tree *left_tree = tree->lchild;
    Tree *right_tree = tree->rchild;

    int left_height = 0;
    int right_height = 0;
    if (left_tree != NULL ){
        if (left_tree->height == NULL){
            down_update_height(tree->lchild);
        }
        left_height = left_tree->height;
    }

    if (right_tree != NULL ){
        if (right_tree->height == NULL){
            down_update_height(tree->rchild);
        }
        right_height = right_tree->height;
    }

    //下面的高度+1 == tree的高度
    tree->height = ((left_height > right_height)? left_height:right_height) + 1 ;
}
//更新当前与祖先的高度
void up_update_height(Tree *tree) {
    Tree *tmp = tree;
    while (tmp != NULL) {
        //向上更新，本质也是用的是向下更新down_update_height
        down_update_height(tmp);
        tmp = tmp->parent;
    }

}

