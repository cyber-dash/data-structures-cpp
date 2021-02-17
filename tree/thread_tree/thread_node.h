//
// Created by alei_go@163.com(抖音: cyberdash_yuan) on 2020/11/1.
//

#ifndef CYBER_DASH_THREAD_TREE_NODE_H
#define CYBER_DASH_THREAD_TREE_NODE_H


#include <iostream>
template <class T>
struct ThreadNode {
  int ltag, rtag;
  ThreadNode<T> *leftChild, *rightChild;
  T data;
  ThreadNode(const T item) : data(item), leftChild(NULL), 
  rightChild(NULL), ltag(0), rtag(0) {}
};

#endif //CYBER_DASH_THREAD_TREE_NODE_H

