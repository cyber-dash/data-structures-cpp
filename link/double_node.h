//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/6/6.
//

#ifndef CYBER_DASH_DOUBLE_LINK_NODE_H
#define CYBER_DASH_DOUBLE_LINK_NODE_H


template <class T>
struct DoubleLinkNode {

  T data_;

  DoubleLinkNode<T> *next_;
  DoubleLinkNode<T> *prev_;

  explicit DoubleLinkNode(DoubleLinkNode<T>* next = NULL, DoubleLinkNode<T>* prev = NULL): prev_(prev), next_(next) {}

  explicit DoubleLinkNode(const T& data, DoubleLinkNode<T>* next = NULL, DoubleLinkNode<T>* prev = NULL):
    data_(data), prev_(prev), next_(next) {}
};


#endif //CYBER_DASH_DOUBLE_LINK_NODE_H