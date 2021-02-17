//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/7/28.
//

#include "link_queue.h"


template<class T>
LinkQueue<T>::~LinkQueue() {
  MakeEmpty();
}


template<class T>
bool LinkQueue<T>::EnQueue(const T& data) {

  LinkNode<T>* new_node_ptr = new LinkNode<T>(data);
  if (new_node_ptr == NULL) {
    return false;
  }

  if (IsEmpty()) {
    front_ptr_ = new_node_ptr;
    rear_ptr_ = new_node_ptr;
  } else {
    rear_ptr_->SetLink(new_node_ptr);
    rear_ptr_ = new_node_ptr;
  }

  return true;
}


template<class T>
bool LinkQueue<T>::DeQueue(T& data) {

  if (IsEmpty()) {
    return false;
  }

  LinkNode<T>* cur_ptr = front_ptr_;

  data = cur_ptr->GetData();
  front_ptr_ = front_ptr_->GetLink();

  delete cur_ptr;

  return true;
}


template<class T>
bool LinkQueue<T>::GetFront(T& data) const {

  if (IsEmpty()) {
    return false;
  }

  data = front_ptr_->GetData();

  return true;
}


template<class T>
bool LinkQueue<T>::IsEmpty() const {
  if (front_ptr_ == NULL) {
    return true;
  } else {
    return false;
  }
}


template<class T>
int LinkQueue<T>::GetSize() const {

  int count = 0;
  LinkNode<T>* cur_ptr = front_ptr_;

  while (cur_ptr != NULL) {
    cur_ptr = cur_ptr->GetLink();
    count++;
  }

  return count;
}


template<class T>
void LinkQueue<T>::MakeEmpty() {

  LinkNode<T>* cur_ptr;

  while (front_ptr_ != NULL) {
    cur_ptr = front_ptr_;
    front_ptr_ = front_ptr_->GetLink();
    delete  cur_ptr;
  }
}


template<class T>
ostream& operator<<(ostream& os, LinkQueue<T>& link_queue) {

  os<<"The size of link queue: "<<link_queue.GetSize()<<endl;

  LinkNode<T>* cur_ptr = link_queue.GetFrontPtr();

  for (int i = 1; cur_ptr != NULL; i++) {
    os<<i<<":"<<cur_ptr->GetData()<<endl;
    cur_ptr = cur_ptr->GetLink();
  }

  return os;
}


template<class T>
void LinkQueue<T>::CyberDashShow() {
  cout<<endl
      <<"*************************************** CyberDash ***************************************"<<endl<<endl
      <<"抖音号\"CyberDash计算机考研\", id: cyberdash_yuan"<<endl<<endl
      <<"CyberDash成员:"<<endl
      <<"元哥(cyberdash@163.com), "<<"北京邮电大学(通信工程本科)/北京邮电大学(信息与通信系统研究生)"<<endl
      <<"磊哥(alei_go@163.com), "<<"山东理工大学(数学本科)/北京邮电大学(计算机研究生)"<<endl<<endl
      <<"数据结构开源代码(C++清华大学殷人昆)魔改升级版本: https://gitee.com/cyberdash/data-structure-cpp"<<endl
      <<endl<<"*************************************** CyberDash ***************************************"<<endl<<endl;
}