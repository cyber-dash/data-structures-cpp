//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/7/28.
//

#ifndef CYBER_DASH_DOUBLE_LINK_LIST_H
#define CYBER_DASH_DOUBLE_LINK_LIST_H


#include <iostream>
#include "double_node.h"


template<class T>
class DoubleLinkList {

public:

  DoubleLinkList(T data);
  ~DoubleLinkList();

  // void MakeEmpty();
  int Length() const { return length_; }
  bool IsEmpty() const;
  DoubleLinkNode<T>* GetHead() const { return head_ptr_; }
  DoubleLinkNode<T>* Search(const T& data);
  DoubleLinkNode<T>* Locate(int pos, int direction);
  bool Insert(int pos, const T& data, int direction);
  bool Remove(int pos, T& data, int direction);
  void Output();

private:
  DoubleLinkNode<T>* head_ptr_;
  int length_;
  int size_;
};



#endif //MAIN_DOUBLE_LINK_LIST_H
