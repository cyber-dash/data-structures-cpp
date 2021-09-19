//
// Created by alei_go@163.com(抖音: cyberdash_yuan) on 2020/11/1.
//

#ifndef CYBER_DASH_TREE_NODE_H
#define CYBER_DASH_TREE_NODE_H

#include <iostream>

template <class T>
struct TreeNode {
  T data;
  TreeNode<T> *firstChild, *nextSibling;
  TreeNode(T value = 0, TreeNode<T> *fc = NULL, TreeNode<T> *ns = NULL) :
    data(value), firstChild(fc), nextSibling(ns) {}
};

#endif //CYBER_DASH_TREE_NODE_H
