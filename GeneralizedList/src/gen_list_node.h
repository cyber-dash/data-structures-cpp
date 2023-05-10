#ifndef CYBER_DASH_GEN_LIST_NODE_H
#define CYBER_DASH_GEN_LIST_NODE_H


#include <iostream>
#include <cstdlib>


template<class T>
class GenListNode;


template<class T>
union GenNodeUnion {
  int ref_count; //!< 引用计数
  T value; //!< 数据
  GenListNode<T>* ref_node; //!< 下一个表的地址
};


template<class T>
class Item {
public:
  /*!
   * @brief 构造函数
   */
  Item(): type(GenListNode<T>::REF_TYPE) {
    this->union_info.ref_count = 0;
  }

  /*!
   * @brief 复制构造函数
   * @param item 节点数据
   */
  Item(Item<T>& item): type(item.union_type_) {
    this->union_info = item.union_info;
  }

  int type; //!< 类型
  GenNodeUnion<T> union_info; //!< union信息
};


template<class T>
class GenListNode {

public:

  /*! @brief 构造函数(空表) */
  GenListNode(): type(GenListNode<T>::REF_TYPE), next(NULL) { union_info.ref_count = 0; }

  /*!
   * @brief 构造函数(使用结点)
   * @param node 广义表节点(引用)
   */
  GenListNode(GenListNode<T>& node):
      type(node.type), next(node.next), union_info(node.union_info) {}

  int type; //!< 类型
  GenNodeUnion<T> union_info; //!< Union类型
  GenListNode<T>* next; //!< 下一节点指针

  static const int REF_TYPE = 0; //!< 引用类型
  static const int ELEM_TYPE = 1; //!< 数据节点类型
  static const int CHILD_LIST_TYPE = 2; //!< 子表类型
};


#endif // CYBER_DASH_GEN_LIST_NODE_H
