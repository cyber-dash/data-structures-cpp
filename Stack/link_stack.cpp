//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/7/28.
//

#include <cstdlib>
#include <stdexcept>

#include "link_node.h"
#include "link_stack.h"


using namespace std;


template<class T>
LinkStack<T>::~LinkStack<T>() {
  MakeEmpty();
}


template<class T>
LinkNode<T>* LinkStack<T>::GetTopPtr() {
  return top_ptr_;
}


template <class T>
void LinkStack<T>::Push(T const& data)
{
  LinkNode<T>* link_node = new LinkNode<T>(data);

  link_node->link_ = top_ptr_;
  top_ptr_ = link_node;
}


template <class T>
bool LinkStack<T>::Pop(T& data)
{
  if (IsEmpty()) {
    // throw out_of_range("Stack<>::pop(): empty stack");
    return false;
  }

  LinkNode<T>* cur_top_ptr = top_ptr_;
  top_ptr_ = top_ptr_->link_;

  data = cur_top_ptr->data_;

  delete cur_top_ptr;

  return true;
}


template <class T>
bool LinkStack<T>::GetTop(T& data) const
{
  if (IsEmpty()) {
    // throw out_of_range("Stack<>::top(): empty stack");
    return false;
  }

  data = top_ptr_->data_;

  return true;
}


template<class T>
int LinkStack<T>::GetSize() const {

  int count = 0;
  LinkNode<T>* cur_ptr = top_ptr_;

  while (cur_ptr != NULL) {
    count++;
    cur_ptr = cur_ptr->link_;
  }

  return count;
}


template<class T>
bool LinkStack<T>::IsEmpty() const {
  if (top_ptr_ == NULL) {
    return true;
  } else {
    return false;
  }
}


template<class T>
void LinkStack<T>::MakeEmpty() {

  LinkNode<T>* cur_ptr;

  while (top_ptr_ != NULL) {
    cur_ptr = top_ptr_;
    top_ptr_ = top_ptr_->link_;
    delete cur_ptr;
  }
}


template<class T>
ostream& operator<<(ostream &os, LinkStack<T> &stack) {

  os<<"栈中元素个数: "<<stack.GetSize()<<endl;

  LinkNode<T>* cur_ptr = stack.GetTopPtr();

  for (int i = 1; cur_ptr != NULL; i++) {
    os<<i<<":"<<cur_ptr->data_<<endl;
    cur_ptr = cur_ptr->link_;
  }

  return os;
}


template<class T>
void LinkStack<T>::CyberDashShow() {
  cout<<endl
      <<"*************************************** CyberDash ***************************************"<<endl<<endl
      <<"抖音号\"CyberDash计算机考研\", id: cyberdash_yuan"<<endl<<endl
      <<"CyberDash成员:"<<endl
      <<"元哥(cyberdash@163.com), "<<"北京邮电大学(通信工程本科)/北京邮电大学(信息与通信系统研究生)"<<endl
      <<"磊哥(alei_go@163.com), "<<"山东理工大学(数学本科)/北京邮电大学(计算机研究生)"<<endl<<endl
      <<"数据结构开源代码(C++清华大学殷人昆)魔改升级版本: https://gitee.com/cyberdash/data-structure-cpp"<<endl
      <<endl<<"*************************************** CyberDash ***************************************"<<endl<<endl;
}