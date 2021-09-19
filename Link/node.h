//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/6/6.
//


#ifndef CYBER_DASH_LINK_NODE_H
#define CYBER_DASH_LINK_NODE_H


template <class T>
struct LinkNode {

  T data_;

  LinkNode<T> *link_;

  explicit LinkNode(LinkNode<T>* ptr = NULL) { link_ = ptr; }
  explicit LinkNode(const T& data, LinkNode<T> *ptr = NULL) {
    data_ = data;
    link_ = ptr;
  }
};


#endif //CYBER_DASH_LINK_NODE_H
