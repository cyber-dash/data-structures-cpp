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
#include <cstddef>


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

  DoubleLinkList();
  DoubleLinkList(T data);
  ~DoubleLinkList();

  int Length() const override { return this->length_; }
  bool IsEmpty() const;
  DoubleLinkNode<T>* Head() const { return this->head_ptr_; }
  DoubleLinkNode<T>* Search(const T& data);
  DoubleLinkNode<T>* Locate(int pos, int direction);
  bool Insert(int pos, const T& data, int direction);
  bool Remove(int pos, T& data, int direction);
  bool GetData(int pos, T& data) const;
  bool SetData(int pos, const T& data);
  void Output();
  void CyberDashShow();

private:
  DoubleLinkNode<T>* head_ptr_;
  int length_;
  int size_;
};

template<class T>
DoubleLinkList<T>::DoubleLinkList() {
  head_ptr_ = new DoubleLinkNode<T>();
  if (head_ptr_ == NULL) {
    cerr<<"存储分配出错!"<<endl;
    exit(1);
  }

  head_ptr_->next_ = head_ptr_;
  head_ptr_->prev_ = head_ptr_;
  this->length_ = 0;
}

template<class T>
DoubleLinkList<T>::DoubleLinkList(T data) {
  head_ptr_ = new DoubleLinkNode<T>(data);
  if (head_ptr_ == NULL) {
    cerr<<"存储分配出错!"<<endl;
    exit(1);
  }

  head_ptr_->next_ = head_ptr_;
  head_ptr_->prev_ = head_ptr_;
  this->length_ = 1;
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

  this->length_++;
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

  this->length_--;
  return true;
}

template<class T>
bool DoubleLinkList<T>::GetData(int pos, T& data) const{
  if (pos < 1 || pos > Length()) {
    return false;
  }

  DoubleLinkList<T>* current = head_ptr_;

  while (pos - 1 > 0) {
    current = current->link_;
    pos--;
  }

  data = current->data_;

  return true
}

template<class T>
bool DoubleLinkList<T>::SetData(int pos,const T& data) {

  if (pos < 1 || pos > Length()) {
    return false;
  }

  DoubleLinkList<T>* current = head_ptr_;

  while (pos - 1 > 0) {
    currrent = current->link_;
    pos--;
  }

  current->data_ = data;

  return true;
}

template<class T>
void DoubleLinkList<T>::Output(){
  if (head_ptr_ == NULL) {
    cout<<"Empty list"<<endl;
    return;
  }

  DoubleLinkNode<T>* current = Head();
  cout<<"向后遍历输出："<<" ";
  current = current->next_;
  while(current != head_ptr_) {
    cout<<current->data_<<" ";
    current = current->next_;
  }

  count<<"向前遍历输出"<<" ";
  current = current->prev_;
  while(current != head_ptr_) {
    cout<<current->data_<<" ";
    current = current->prev_;
  }

  cout<<endl
}

template<class T>
void LinkList<T>::CyberDashShow() {
  cout<<endl
      <<"*************************************** CyberDash ***************************************"<<endl<<endl
      <<"抖音号\"CyberDash计算机考研\", id: cyberdash_yuan"<<endl<<endl
      <<"CyberDash成员:"<<endl
      <<"元哥(cyberdash@163.com), "<<"北京邮电大学(通信工程本科)/北京邮电大学(信息与通信系统研究生)"<<endl
      <<"磊哥(alei_go@163.com), "<<"山东理工大学(数学本科)/北京邮电大学(计算机研究生)"<<endl<<endl
      <<"数据结构开源代码(C++清华大学殷人昆)魔改升级版本: https://gitee.com/cyberdash/data-structure-cpp"<<endl
      <<endl<<"*************************************** CyberDash ***************************************"<<endl<<endl;
}

#endif // CYBER_DASH_DOUBLE_LINK_LIST_H
