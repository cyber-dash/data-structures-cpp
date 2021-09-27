/*!
 * @file link_list.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 双向链表
 * @version 0.2.1
 * @date 2020-07-28
 * @copyright Copyright (c) 2021
 * **CyberDash计算机考研**
 */

#ifndef CYBER_DASH_DOUBLE_LINK_LIST_H
#define CYBER_DASH_DOUBLE_LINK_LIST_H


#include <iostream>


template <class T>
struct DoubleLinkNode {

  explicit DoubleLinkNode(DoubleLinkNode<T>* next = NULL, DoubleLinkNode<T>* prev = NULL): prev_(prev), next_(next) {}
  explicit DoubleLinkNode(const T& data, DoubleLinkNode<T>* next = NULL, DoubleLinkNode<T>* prev = NULL):
      data_(data), prev_(prev), next_(next) {}

  T data_;
  DoubleLinkNode<T>* next_;
  DoubleLinkNode<T>* prev_;
};


template<class T>
class DoubleLinkList {

public:

  DoubleLinkList(T data);
  ~DoubleLinkList();

  int Length() const { return this->length_; }
  bool IsEmpty() const;
  DoubleLinkNode<T>* GetHead() const { return this->head_ptr_; }
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
