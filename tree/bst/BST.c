#include "BST.h"

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
void tree_print(Tree *tree) {
    if (tree == NULL) return;
    Node *parent = tree->parent;
    if (parent == NULL) {
        printf("%d(NULL) ",tree->data);
    } else{
        printf("%d(%d) ",tree->data,parent->data);
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
                //释放
                free(tmp);
            } else if (tmp->lchild != NULL) {
                //如果左边不为空的话，将左边最大的节点(tmp)进行值替换
                //将左边最大的替换删除的节点,选中的节点一定是叶子节点
                Node *left_max = tmp->lchild;
                while (left_max->rchild != NULL) {
                    left_max = tmp->rchild;
                }
                tmp->data = left_max->data;
                node_remove(tmp->lchild,left_max->data);
            } else {
                //如果左边为空，那么将右边最小的与要删除的节点（tmp）进行值替换
                //将右边最小的替换删除的节点，选中的节点一定是叶子节点
                Node *right_min = tmp->rchild;
                while (right_min->lchild != NULL) {
                    right_min = tmp->lchild;
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