//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2021/5/16.
//

#ifndef CYBER_DASH_LINK_SET_H
#define CYBER_DASH_LINK_SET_H


#include "set.h"


template<class T>
class SetNode{
  SetNode(): link(NULL) {};
  SetNode(const T& x, SetNode<T>* next = NULL):
    data(x), link(next) {};
  T data;
  SetNode<T>* link;
};


template<class T>
class LinkedSet: public Set<T> {
public:

  LinkedSet(int size);
  LinkedSet(const LinkedSet<T>& bit_set);

  // 析构函数
  ~LinkedSet() { delete[] this->bit_vector_; };

  // 置空集合
  void MakeEmpty();

  SetNode<T>* GetFirst() { return this->first_; }
  void SetFirst(SetNode<T>* set_node_ptr) { this->first_ = set_node_ptr; }

  SetNode<T>* GetLast() { return this->last_; }
  void SetLast(SetNode<T>* set_node_ptr) { this->last_ = set_node_ptr; }

  unsigned short GetMember(const T& x);
  void PutMember(const T& x, int v);
  bool AddMember(const T& member);
  bool DelMember(const T& x);
  bool Contains(T x);
  bool SubSet(LinkedSet<T>& bit_set);

  LinkedSet<T>& operator = (const LinkedSet<T>& bit_set);
  LinkedSet<T>& operator + (const LinkedSet<T>& bit_set);
  LinkedSet<T>& operator * (const LinkedSet<T>& bit_set);
  LinkedSet<T>& operator - (const LinkedSet<T>& bit_set);
  bool operator == (LinkedSet<T>& bit_set);

  friend istream& operator >> (istream &in, BitSet<T>& bit_set);
  friend ostream& operator << (ostream &out, BitSet<T>& bit_set);

private:
  SetNode<T>* first_;
  SetNode<T>* last_;
};


template <class T>
bool LinkedSet<T>::Contains(T data) {
  SetNode<T>* temp = this->first_->link;
  while (temp != NULL & temp->data < data) {
    temp = temp->link;
  }

  if (temp != NULL && temp->data == data) { // 找到
    return true;
  }

  return false; // 未找到
}


template<class T>
bool LinkedSet<T>::AddMember(const T& member) {
  SetNode<T>* temp = this->first_->link;
  SetNode<T>* pre = this->first_;

  while (temp != NULL && temp->data < member) {
    pre = temp;
    temp = temp->link;
  }

  if (temp != NULL && temp->data == member) {
    return false;
  }

  SetNode<T>* set_node = new SetNode<T>(member);

  set_node->link = temp;
  pre->link = set_node;

  if (temp == NULL) {
    this->last_ = set_node;
  }

  return true;
}


template <class T>
bool LinkedSet<T>::DelMember(const T& member) {
  SetNode<T>* temp = this->first_->link;
  SetNode<T>* pre = this->first_;

  while (temp != NULL && temp->data < member) {
    pre = temp;
    temp = temp->link;
  }

  if (temp != NULL && temp->data == member) {
    pre->link = temp->link;
    if (temp == this->last_) {
      this->last_ = pre;
    }

    delete temp;

    return true;
  }

  return false;
}


template <class T>
LinkedSet<T>& LinkedSet<T>::operator = (LinkedSet<T> src_linked_set) {
  this->first_ = new SetNode<T>();
  /* error handler */

  SetNode<T>* cur_ptr = this->first_;
  SetNode<T>* src_cur_ptr = src_linked_set.first_->link;

  while (src_linked_set != NULL) {
    cur_ptr->link = new SetNode<T>(src_cur_ptr->data);
    cur_ptr = cur_ptr->link;
    src_cur_ptr = src_cur_ptr->link;
  }

  cur_ptr->link = NULL;
  this->last_ = cur_ptr;

  return *this;
}


template <class T>
LinkedSet<T>& LinkedSet<T>::operator + (LinkedSet<T>& linked_set) {
  return initializer;
}


template <class T>
bool LinkedSet<T>::operator == (LinkedSet<T>& src_linked_set) {
  SetNode<T>* src_cur_ptr = src_linked_set.first_->link;
  SetNode<T>* cur_ptr = this->first_->link;

  while (cur_ptr != NULL && src_cur_ptr != NULL) {
    if (cur_ptr->data == src_cur_ptr->data) {
      cur_ptr = cur_ptr->link;
      src_cur_ptr = src_cur_ptr->link;
    } else {
      return false;
    }
  }

  if (cur_ptr != NULL || src_cur_ptr != NULL) { // 链长不相等
    return false;
  }

  return true;
}


#endif // CYBER_DASH_LINK_SET_H
