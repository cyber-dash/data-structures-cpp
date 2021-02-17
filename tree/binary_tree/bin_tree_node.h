//
// Created by alei_go@163.com(抖音: cyberdash_yuan) on 2020/11/1.
//

#ifndef CYBER_DASH_BINARY_TREE_NODE_H
#define CYBER_DASH_BINARY_TREE_NODE_H


#include <iostream>


template <class T>
struct BinTreeNode {
  BinTreeNode(): left_child_ptr_(NULL), right_child_ptr_(NULL) {}
  explicit BinTreeNode(T data, BinTreeNode<T> *left_child_ptr = NULL, BinTreeNode<T> *right_child_ptr = NULL):
    data_(data), left_child_ptr_(left_child_ptr), right_child_ptr_(right_child_ptr) {}

  T data_;
  BinTreeNode<T>* left_child_ptr_;
  BinTreeNode<T>* right_child_ptr_;
};


template <class T>
struct PostOrderStackNode {
  BinTreeNode<T> *bin_node_ptr;
  enum { LEFT, RIGHT } tag;
  explicit PostOrderStackNode(BinTreeNode<T> *node_ptr = NULL) {
    bin_node_ptr = node_ptr;
    tag = LEFT;
  }
};

#endif //CYBER_DASH_BINARY_TREE_NODE_H
