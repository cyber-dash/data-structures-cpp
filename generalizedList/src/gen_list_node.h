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
  int ref_count; // 引用计数
  T value; // 数据
  GenListNode<T>* ref_node_ptr; // 下一个表的地址
};


template<class T>
class Item {
public:
  Item() {
    this->type = GenListNode<T>::REF_TYPE;
    this->union_info.ref_count = 0;
  }

  Item(Item<T>& item) {
    this->type = item.union_type_;
    this->union_info = item.union_info;
  }

  int type;
  GenNodeUnion<T> union_info;
};


template<class T>
class GenListNode {

public:

  // default: Empty
  GenListNode(): type(GenListNode<T>::REF_TYPE), next(NULL) { union_info.ref_count = 0; }

  GenListNode(GenListNode<T>& node):
      type(node.type), next(node.next), union_info(node.union_info) {}

  int type;
  GenNodeUnion<T> union_info;
  GenListNode<T>* next;

  static const int REF_TYPE = 0;
  static const int ELEM_TYPE = 1;
  static const int CHILD_LIST_TYPE = 2;
};


#endif // CYBER_DASH_GEN_LIST_NODE_H
