//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/7/28.
//

#include "double_link_list.h"
#include <iostream>


using namespace std;


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

