//
// Created by svenlee on 2023/3/15.
//

#ifndef MAIN_POSTORDER_THREADED_BINARY_TREE_H
#define MAIN_POSTORDER_THREADED_BINARY_TREE_H

#include "threaded_node.h"

template <class T>
class PostorderThreadedBinaryTree {
public:
    PostorderThreadedBinaryTree() : root_(NULL) {}
    // 创建前序线索
    void CreatePostThread();
    ThreadedNode<T>* PostOrderNext(ThreadedNode<T>* node_ptr);
    ThreadedNode<T>* PostOrderPrior(ThreadedNode<T> *current);
private:
    ThreadedNode<T>* root_;
    // 子树创建后续线索
    // void CreateSubPostOrderThread_(ThreadedNode<T>*& node, ThreadedNode<T>*& post_node);
    // 子树创建后序线索
    void CreatePostOrderThread_(ThreadedNode<T>*& node, ThreadedNode<T>*& pre_node);
};


/**
 *
 * @tparam T
 */
template <class T>
void PostorderThreadedBinaryTree<T>::CreatePostThread() {
    if (root_ == NULL) {
        return;
    }

    ThreadedNode<T>* pre_node_ptr = NULL;

    CreatePostOrderThread_(root_, pre_node_ptr);

    pre_node_ptr->right_child = NULL;
    pre_node_ptr->right_tag = 1;
}


/**
 * @brief
 * @tparam T
 * @param node
 * @param pre_node
 */
template <class T>
void PostorderThreadedBinaryTree<T>::CreatePostOrderThread_(ThreadedNode<T>*& node, ThreadedNode<T>*& pre_node) {
    if (node == NULL) {
        return;
    }

    CreatePostOrderThread_(node->left_child, pre_node);

    CreatePostOrderThread_(node->right_child, pre_node);

    if (node->left_child == NULL) {
        node->left_child = pre_node;
        node->left_tag = IS_THREAD_NODE;
    }

    if (pre_node != NULL && pre_node->right_child == NULL) {
        pre_node->right_child = node;
        pre_node->right_tag = IS_THREAD_NODE;
    }

    pre_node = node;
}


template <class T>
ThreadedNode<T> *PostorderThreadedBinaryTree<T>::PostOrderNext(ThreadedNode<T> *current) {
    if (current->right_tag == 1) {
        return current->right_child;
    }

    ThreadedNode<T>* parent = Parent_(current);
    if (parent == NULL) {
        return NULL;
    }

    if (parent->right_tag == 1 || parent->right_child == current) {
        return parent;
    }

    return First(parent->right_child);
}


template <class T>
ThreadedNode<T> *PostorderThreadedBinaryTree<T>::PostOrderPrior(ThreadedNode<T> *current) {
    if (current->left_tag == 1) {
        return current->left_child;
    }

    if (current->right_tag == 1) {
        return current->left_child;
    }

    return current->right_child;
}

#endif //MAIN_POSTORDER_THREADED_BINARY_TREE_H
