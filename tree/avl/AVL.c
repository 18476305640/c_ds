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
int node_remove(Tree *tree, void *key) {
    if(! contain(tree,key)) return NO;
    Tree *tmp = tree;
    while (NULL != tmp) {
        if (tmp->data == key) {
            //找到了要删除的节点tmp
            //如果该节点是叶子节点时
            //要修复的高度的节点
            if(tmp->lchild == NULL && tmp->rchild == NULL) {
                //这是一个叶子节点
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
            } else if (tmp->lchild != NULL) {
                //如果左边不为空的话，将左边最大的节点(tmp)进行值替换
                //将左边最大的替换删除的节点,选中的节点一定是叶子节点
                Node *left_max = tmp->lchild;
                while (left_max->rchild != NULL) {
                    left_max = left_max->rchild;
                }
                tmp->data = left_max->data;
                node_remove(tmp->lchild,left_max->data);
            } else {
                //如果左边为空，那么将右边最小的与要删除的节点（tmp）进行值替换
                //将右边最小的替换删除的节点，选中的节点一定是叶子节点
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

//计算数的高度, 想要计算树的高度，需要添加height属性，更新树的高度
int down_update_height(Tree *tree) {
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
        down_update_height(tmp);
        tmp = tmp->parent;
    }

}

