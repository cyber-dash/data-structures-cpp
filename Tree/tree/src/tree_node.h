//
// Created by alei_go@163.com(抖音: cyberdash_yuan) on 2020/11/1.
//

#ifndef CYBER_DASH_TREE_NODE_H
#define CYBER_DASH_TREE_NODE_H


#include <iostream>


template <class T>
struct TreeNode {
  TreeNode(T data = 0, TreeNode<T>* first_child = NULL, TreeNode<T>* next_sibling = NULL):
    data(data), first_child(first_child), next_sibling(next_sibling) {}

  T data;
  TreeNode<T>* first_child;
  TreeNode<T>* next_sibling;
};


#endif //CYBER_DASH_TREE_NODE_H
