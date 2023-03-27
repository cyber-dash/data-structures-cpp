/*!
 * @file preorder_threaded_binary_tree.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 前序线索树模板类
 * @version 0.2.1
 * @date 2021-05-13
 */

#ifndef MAIN_PREORDER_THREADED_BINARY_TREE_H
#define MAIN_PREORDER_THREADED_BINARY_TREE_H


#include "threaded_node.h"


template <typename TData>
class PreorderThreadedBinaryTree {
public:
    PreorderThreadedBinaryTree() : root_(NULL) {}
    /* 前序线索树 */

    // 创建前序线索
    void CreateThreadRecursive();
    // 前序线索二叉树下一个结点
    ThreadedNode<TData>* Next(ThreadedNode<TData>* node);
    // 前序线索二叉树前一个结点
    ThreadedNode<TData>* Pre(ThreadedNode<TData>* node);
    ThreadedNode<TData>* Last(ThreadedNode<TData>* subtree_root);

private:
    ThreadedNode<TData>* root_;
    // 子树创建前序线索
    void CreateThreadInSubtreeRecursive_(ThreadedNode<TData>*& node, ThreadedNode<TData>*& pre_node);
};


template <typename TData>
void PreorderThreadedBinaryTree<TData>::CreateThreadRecursive() {
    ThreadedNode<TData>* pre_node = NULL;

    if (root_ != NULL) {
        CreateThreadInSubtreeRecursive_(root_, pre_node);
        pre_node->right_child = NULL;
        pre_node->right_tag = 1;
    }
}

template <class T>
ThreadedNode<T> *PreorderThreadedBinaryTree<T>::Next(ThreadedNode<T>* node_ptr) {

    if (node_ptr->left_tag != THREADED_NODE_POINTER) {
        return node_ptr->left_child;
    }

    return node_ptr->right_child;
}


template <class T>
ThreadedNode<T> *PreorderThreadedBinaryTree<T>::Pre(ThreadedNode<T>* node) {

    if (node->left_tag == THREADED_NODE_POINTER) {
        return node->left_child;
    }

    ThreadedNode<T> *parent = Parent_(node);

    if (parent == NULL) {
        return NULL;
    }

    if (parent->left_tag == 1 || parent->left_child == node) {
        return parent;
    }

    return Last(parent->left_child);
}


template <typename TData>
ThreadedNode<TData>* PreorderThreadedBinaryTree<TData>::Last(ThreadedNode<TData>* subtree_root) {
    if (!subtree_root) {
        throw invalid_argument("NULL pointer");
    }

    ThreadedNode<TData>* cur = subtree_root;

    while (cur->right_child != NULL && cur->right_tag == CHILD_POINTER) {
        cur = cur->right_child;
    }

    return cur;
}


/**
 *
 * @tparam T
 * @param node
 * @param pre_node
 */
template <class T>
void PreorderThreadedBinaryTree<T>::CreateThreadInSubtreeRecursive_(ThreadedNode<T>*& node, ThreadedNode<T>*& pre_node) {

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
    // CreateThreadInSubtreeRecursive_(node_ptr->left_child_, pre_node_ptr); // 左子树遍历
    if (node->left_tag == CHILD_POINTER) {
        CreateThreadInSubtreeRecursive_(node->left_child, pre_node); // 左子树遍历
    }

    // 右子树分治
    CreateThreadInSubtreeRecursive_(node->right_child, pre_node); // 右子树遍历
}


#endif //MAIN_PREORDER_THREADED_BINARY_TREE_H
