//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/6/6.
//

#include <iostream>
#include <cstddef>
#include "link_list.h"
#include "node.h"


using namespace std;


template<class T>
LinkList<T>::LinkList() {
  head_ptr_ = NULL;
  length_ = 0;
};


template<class T>
LinkList<T>::LinkList(const T& data) {
  head_ptr_ = new LinkNode<T>(data);
}


template<class T>
LinkList<T>::LinkList(LinkNode<T>*& node) {

  if (node == NULL) {
    LinkNode<T>();
    return;
  }

  head_ptr_ = node;
  length_ = 0;

  LinkNode<T>* cur_ptr = head_ptr_;

  while (cur_ptr != NULL) {
    length_++;
    cur_ptr = cur_ptr->link_;
  }
}


template<class T>
LinkList<T>::LinkList(LinkList<T>& link_list) {

  if (link_list.Length() == 0) {
    head_ptr_ = NULL;
    length_ = 0;
    return;
  }

  LinkNode<T>* cur_src_ptr = link_list.GetHead();

  if (link_list.Length() == 1) {
    head_ptr_ = new LinkNode<T>(cur_src_ptr->data_);
    head_ptr_->link_ = NULL;
    length_ = 1;
    return;
  }

  head_ptr_ = new LinkNode<T>();

  LinkNode<T>* cur_dest_ptr = head_ptr_;

  while (cur_src_ptr->link_ != NULL) {
    cur_dest_ptr->data_ = cur_src_ptr->data_;

    cur_dest_ptr->link_ = new LinkNode<T>();

    cur_dest_ptr = cur_dest_ptr->link_;
    cur_src_ptr = cur_src_ptr->link_;

    length_++;
  }

  cur_dest_ptr->data_ = cur_src_ptr->data_;
  cur_dest_ptr->link_ = NULL;
}


template<class T>
bool LinkList<T>::GetData(int pos, T& data) const {

  if (pos < 1 || pos > Length()) {
    return false;
  }

  LinkNode<T>* cur = head_ptr_;

  while (pos - 1 > 0) {
    cur = cur->link_;
    pos--;
  }

  data = cur->data_;

  return true;
}


template<class T>
bool LinkList<T>::SetData(int pos, T& data) {

  if (pos < 1 || pos > Length()) {
    return false;
  }

  LinkNode<T>* cur = head_ptr_;

  while (pos - 1 > 0) {
    cur = cur->link_;
    pos--;
  }

  cur->data_ = data;

  return true;
}


template<class T>
void LinkList<T>::MakeEmpty() {

}


template<class T>
void LinkList<T>::Output() {

  if (head_ptr_ == NULL) {
    cout<<"Empty list"<<endl;
    return;
  }

  LinkNode<T>* cur = GetHead();
  while(cur != NULL) {
    cout<<cur->data_<<" ";
    cur = cur->link_;
  }
  cout<<endl;

}


template<class T>
bool LinkList<T>::Insert(int pos, LinkNode<T>* node) {

  if (pos < 0 || pos > Length()) {
    return false;
  }

  if (node == NULL) {
    return false;
  }

  if (head_ptr_ == NULL) {
    node->link_ = head_ptr_;
    head_ptr_ = node;
    length_ = 1;
    return true;
  }

  if (pos == 0) {

    node->link_ = head_ptr_;
    head_ptr_ = node;
  } else {

    LinkNode<T>* cur = head_ptr_;
    while (pos - 1 > 0) {
      cur = cur->link_;
      pos--;
    }

    node->link_ = cur->link_;
    cur->link_ = node;
  }

  length_++;

  return true;
}


template<class T>
bool LinkList<T>::Insert(int pos, T &data) {

  if (pos < 0 || pos > Length()) {
    return false;
  }

  LinkNode<T>* node = new LinkNode<T>(data);

  if (head_ptr_ == NULL) {
    node->link_ = head_ptr_;
    head_ptr_ = node;
    length_ = 1;
    return true;
  }

  if (pos == 0) {

    node->link_ = head_ptr_;
    head_ptr_ = node;
  } else {

    LinkNode<T>* cur = head_ptr_;
    while (pos - 1 > 0) {
      cur = cur->link_;
      pos--;
    }

    node->link_ = cur->link_;
    cur->link_ = node;
  }

  length_++;

  return true;
}


template<class T>
bool LinkList<T>::IsEmpty() const {

  if (length_ == 0) {
    return true;
  } else {
    return false;
  }
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
