//
// Created by svenlee on 2023/3/15.
//

#ifndef MAIN_PREORDER_THREADED_BINARY_TREE_H
#define MAIN_PREORDER_THREADED_BINARY_TREE_H

#include "threaded_node.h"

template <class T>
class PreorderThreadedBinaryTree {
public:
    PreorderThreadedBinaryTree() : root_(NULL) {}
    /* 前序线索树 */

    // 创建前序线索
    void CreatePreOrderThread();
    // 前序线索二叉树下一个结点
    ThreadedNode<T>* PreOrderNext(ThreadedNode<T>* node_ptr);
    // 前序线索二叉树前一个结点
    ThreadedNode<T>* PreOrderPrior(ThreadedNode<T> *current);

private:
    ThreadedNode<T>* root_;
    // 子树创建前序线索
    void CreateSubPreOrderThread_(ThreadedNode<T>*& node, ThreadedNode<T>*& pre_node);
};


template <class T>
void PreorderThreadedBinaryTree<T>::CreatePreOrderThread() {
    ThreadedNode<T> *node_ptr = NULL;

    if (root_ != NULL) {
        CreateSubPreOrderThread_(root_, node_ptr);
        node_ptr->right_child = NULL;
        node_ptr->right_tag = 1;
    }
}

template <class T>
ThreadedNode<T> *PreorderThreadedBinaryTree<T>::PreOrderNext(ThreadedNode<T>* node_ptr) {

    if (node_ptr->left_tag != THREADED_NODE_POINTER) {
        return node_ptr->left_child;
    }

    return node_ptr->right_child;
}


template <class T>
ThreadedNode<T> *PreorderThreadedBinaryTree<T>::PreOrderPrior(ThreadedNode<T> *current) {

    if (current->left_tag == THREADED_NODE_POINTER) {
        return current->left_child;
    }

    ThreadedNode<T> *parent = Parent_(current);

    if (parent == NULL) {
        return NULL;
    }

    if (parent->left_tag == 1 || parent->left_child == current) {
        return parent;
    }

    return Last(parent->left_child);
}


/**
 *
 * @tparam T
 * @param node
 * @param pre_node
 */
template <class T>
void PreorderThreadedBinaryTree<T>::CreateSubPreOrderThread_(ThreadedNode<T>*& node, ThreadedNode<T>*& pre_node) {

    if (node == NULL) {
        return;
    }

    // (利用left_child_)
    // 如果left_child_指针为NULL,
    // 则将node_ptr->left_child_指向pre_node_ptr, 加入线索树
    if (node->left_child == NULL) {
        node->left_child = pre_node;
        node->left_tag = THREADED_NODE_POINTER;
    }

    // (利用right_child_)
    // 如果前一节点pre_node_ptr不为NULL, 并且它的right_child_不为NULL,
    // 则前一节点的right_child_指向node_ptr, 加入线索树
    if (pre_node != NULL && pre_node->right_child == NULL) {
        pre_node->right_child = node;
        pre_node->right_tag = THREADED_NODE_POINTER;
    }

    pre_node = node; // pre_node_ptr节点后移

    // 左子树分治
    // CreateSubPreOrderThread_(node_ptr->left_child_, pre_node_ptr); // 左子树遍历
    if (node->left_tag == CHILD_POINTER) {
        CreateSubPreOrderThread_(node->left_child, pre_node); // 左子树遍历
    }

    // 右子树分治
    CreateSubPreOrderThread_(node->right_child, pre_node); // 右子树遍历
}


#endif //MAIN_PREORDER_THREADED_BINARY_TREE_H
