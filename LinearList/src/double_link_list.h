/*!
 * @file link_list.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 双向链表(循环)
 * @version 0.2.1
 * @date 2020-07-28
 * @copyright Copyright (c) 2021
 * **CyberDash计算机考研**
 */

#ifndef CYBER_DASH_DOUBLE_LINK_LIST_H
#define CYBER_DASH_DOUBLE_LINK_LIST_H


#include "LinearList.h"
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
class DoubleLinkList: public LinearList<T> {

public:

  DoubleLinkList(T data);
  ~DoubleLinkList();

  int Length() const { return this->length_; }
  bool IsEmpty() const;
  DoubleLinkNode<T>* Head() const { return this->head_ptr_; }
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

template<class T>
bool DoubleLinkList<T>::IsEmpty()const{
  return head_ptr_>next_ == head_ptr_;
}

template<class T>
DoubleLinkNode<T>* DoubleLinkList<T>::Search(const T& data){
  DoubleLinkNode<T>* current = head_ptr_->next_;
  while (current != head_ptr_ && current->data_ != data)
  {
      current = current->next_;
  }

  if(current != head_ptr_){
    return current;
  }
  return nullptr;
}

template<class T>
DoubleLinkNode<T>* DoubleLinkList<T>::Locate(int pos, int direction){
  if(head_ptr_->next_ == head_ptr_ || i == 0){
    return head_ptr_;
  }

  DoubleLinkNode<T>* current;
  if(direction == 0){
    current = head_ptr_->next_;
  }else{
    current = head_ptr_->prev_;
  }

  for(int i = 0;i < pos;i++){
    if(current == head_ptr_){
      return nullptr;
    }
    
    //direction==0 向前搜索，direction!=0向后搜索
    if(direction == 0){
      current = current->prev_;
    }
    else{
      current = current->next_;
    }
  }

  if(current != head_ptr_){
    return current;
  }

  return nullptr;
}

template<class T>
bool DoubleLinkList<T>::Insert(int pos, const T& data, int direction){
  DoubleLinkNode<T>* current = Locate(pos,direction);
  if(current == nullptr){
    return false;
  }

  DoubleLinkNode<T>* newNode = new DoubleLinkNode<T>(data);
  if(newNode == nullptr){
    cerr<<"存储分配失败！"<<endl;
    exit(1);
  }

  if(direction == 0){
    newNode->prev_ = current->prev_;
    current->prev_ = newNode;
    newNode->prev_->next_ = newNode;
    newNode->next_ = current;
  }
  else{
    newNode->next_ = current->next_;
    current->next_ = newNode;
    newNode->next_->prev_ = newNode;
    newNode->prev_ = current;
  }

  return true;
}

template<class T>
bool DoubleLinkList<T>::Remove(int pos, T& data, int direction){
  DoubleLinkNode<T>* current = Locate(pos,direction);
  if(current == nullptr){
    return false;
  }

  current->next_->prev_ = current->prev_;
  current->prev_->next_ = current->next_;
  data = current->data_;
  delete current;
  return true;
}

template<class T>
void DoubleLinkList<T>::Output(){

}

#endif // CYBER_DASH_DOUBLE_LINK_LIST_H
