//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/6/6.
//
/*!
 * @file link_list.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 稀疏矩阵
 * @version 0.2.1
 * @date 2020-06-06
 *
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#ifndef CYBER_DASH_LINK_LIST_H
#define CYBER_DASH_LINK_LIST_H


#include <iostream>
#include "node.h"


template<class T>
class LinkList {

public:

  LinkList();
  LinkList(const T& data);
  LinkList(LinkNode<T>*& node);
  LinkList(LinkList<T>& link_list);
  ~LinkList();

  void MakeEmpty();
  int Length() const { return length_; }
  LinkNode<T>* GetHead() const { return head_ptr_; }
  LinkNode<T>* Search();
  LinkNode<T>* Locate(int pos);
  bool GetData(int pos, T& data) const;
  bool SetData(int pos, T& data);
  bool Insert(int pos, T& data);
  bool Remove(int pos, T& data);
  bool IsEmpty() const;
  bool IsFull() const;
  bool Insert(int pos, LinkNode<T>* node);
  void Output();
  void CyberDashShow();

private:
  LinkNode<T>* head_ptr_;
  int length_;
  int size_;
};


#endif // CYBER_DASH_LINK_LIST_H
