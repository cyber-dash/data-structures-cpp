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


template<class T>
DoubleLinkList<T>::DoubleLinkList(T data) {
  head_ptr_ = new DoubleLinkNode<T>(data);
  if (head_ptr_ == NULL) {
    cerr<<"存储分配出错!"<<endl;
    exit(1);
  }

  head_ptr_->next_ = head_ptr_;
  head_ptr_->prev_ = head_ptr_;
}


#endif // CYBER_DASH_DOUBLE_LINK_LIST_H
