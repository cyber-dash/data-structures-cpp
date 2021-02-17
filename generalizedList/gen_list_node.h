//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/7/14.
//

#ifndef CYBER_DASH_GEN_LIST_NODE_H
#define CYBER_DASH_GEN_LIST_NODE_H


#include <iostream>
#include <cstdlib>


template<class T>
class GenListNode;


template<class T>
union GenNodeUnion {
  int ref_count_; // 引用计数
  T value_; // 数据
  GenListNode<T>* ref_node_ptr_; // 下一个表的地址
};


template<class T>
class Item {
public:
  Item() { type_ = 0; union_info_.ref_count_ = 0;}
  Item(Item<T>& item) { type_ = item.union_type_; union_info_ = item.union_info; }

  int type_;
  GenNodeUnion<T> union_info_;
};


template<class T>
class GenListNode {

public:

  // default: Empty
  GenListNode(): type_(GenListNode<T>::REF_TYPE), next_(NULL) { union_info_.ref_count_ = 0; }

  GenListNode(GenListNode<T>& node):
    type_(node.type_), next_(node.next_), union_info_(node.union_info_) {}

  int type_;
  GenNodeUnion<T> union_info_;
  GenListNode<T>* next_;

  static const int REF_TYPE = 0;
  static const int ELEM_TYPE = 1;
  static const int CHILD_LIST_TYPE = 2;
};


#endif // CYBER_DASH_GEN_LIST_NODE_H
