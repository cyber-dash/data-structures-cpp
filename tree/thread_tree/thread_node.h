//
// Created by alei_go@163.com(抖音: cyberdash_yuan) on 2020/11/1.
//

#ifndef CYBER_DASH_THREAD_TREE_NODE_H
#define CYBER_DASH_THREAD_TREE_NODE_H


#include <iostream>


const int IS_CHILD = 0;
const int IS_THREAD_NODE = 1;


template <class T>
struct ThreadNode {

  int left_tag_;
  int right_tag_;

  ThreadNode<T>* left_child_;
  ThreadNode<T>* right_child_;
  T data_;

  ThreadNode(const T data):
      data_(data),
      left_child_(NULL), right_child_(NULL),
      left_tag_(IS_CHILD), right_tag_(IS_CHILD) {}
};


#endif //CYBER_DASH_THREAD_TREE_NODE_H
