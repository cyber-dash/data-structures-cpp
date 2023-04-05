/*!
 * @file postorder_threaded_binary_tree.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 后序线索树模板类
 * @version 0.2.1
 * @date 2021-05-13
 */

#ifndef CYBER_DASH_POSTORDER_THREADED_BINARY_TREE_H
#define CYBER_DASH_POSTORDER_THREADED_BINARY_TREE_H


#include "threaded_node.h"


template <typename TData>
class PostorderThreadedBinaryTree {
public:
    PostorderThreadedBinaryTree() : root_(NULL) {}
    // 创建前序线索
    void CreateThreadRecursive();
    ThreadedNode<TData>* Next(ThreadedNode<TData>* node);
    ThreadedNode<TData>* Pre(ThreadedNode<TData>* node);
private:
    ThreadedNode<TData>* root_;
    // 子树创建后序线索
    void CreateThreadInSubtreeRecursive_(ThreadedNode<TData>*& node, ThreadedNode<TData>*& pre_node);
};


/**
 *
 * @tparam T
 */
template <class T>
void PostorderThreadedBinaryTree<T>::CreateThreadRecursive() {
    if (root_ == NULL) {
        return;
    }

    ThreadedNode<T>* pre_node_ptr = NULL;

    CreateThreadInSubtreeRecursive_(root_, pre_node_ptr);

    pre_node_ptr->right_child = NULL;
    pre_node_ptr->right_tag = THREADED_NODE_POINTER;
}


/**
 * @brief
 * @tparam T
 * @param node
 * @param pre_node
 */
template <class T>
void PostorderThreadedBinaryTree<T>::CreateThreadInSubtreeRecursive_(ThreadedNode<T>*& node, ThreadedNode<T>*& pre_node) {
    if (node == NULL) {
        return;
    }

    CreateThreadInSubtreeRecursive_(node->left_child, pre_node);

    CreateThreadInSubtreeRecursive_(node->right_child, pre_node);

    if (node->left_child == NULL) {
        node->left_child = pre_node;
        node->left_tag = THREADED_NODE_POINTER;
    }

    if (pre_node != NULL && pre_node->right_child == NULL) {
        pre_node->right_child = node;
        pre_node->right_tag = THREADED_NODE_POINTER;
    }

    pre_node = node;
}


template <class T>
ThreadedNode<T> *PostorderThreadedBinaryTree<T>::Next(ThreadedNode<T>* node) {
    if (node->right_tag == THREADED_NODE_POINTER) {
        return node->right_child;
    }

    ThreadedNode<T>* parent = Parent_(node);
    if (parent == NULL) {
        return NULL;
    }

    if (parent->right_tag == THREADED_NODE_POINTER || parent->right_child == node) {
        return parent;
    }

    return First(parent->right_child);
}


template <class T>
ThreadedNode<T> *PostorderThreadedBinaryTree<T>::Pre(ThreadedNode<T>* node) {
    if (node->left_tag == THREADED_NODE_POINTER) {
        return node->left_child;
    }

    if (node->right_tag == THREADED_NODE_POINTER) {
        return node->left_child;
    }

    return node->right_child;
}

#endif // CYBER_DASH_POSTORDER_THREADED_BINARY_TREE_H
