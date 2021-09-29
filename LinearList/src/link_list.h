/*!
 * @file link_list.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 单向链表
 * @version 0.2.1
 * @date 2020-06-06
 * @copyright Copyright (c) 2021
 * **CyberDash计算机考研**
 */

#ifndef CYBER_DASH_LINK_LIST_H
#define CYBER_DASH_LINK_LIST_H


#include <iostream>
#include <cstddef>
#include "LinearList.h"


using namespace std;


/*!
 * @brief 单链表结点模板类
 * @tparam T 类型模板参数
 */
template <class T>
struct LinkNode {
  /*! @brief 构造函数(下一结点地址) */
  explicit LinkNode(LinkNode<T>* ptr = NULL) { this->link_ = ptr; }

  /*!
   * @brief 构造函数(数据项和下一结点地址)
   * @param data 数据项
   * @param ptr 下一节点地址
   */
  explicit LinkNode(const T& data, LinkNode<T> *ptr = NULL) {
    this->data_ = data;
    this->link_ = ptr;
  }

  T data_; //!< 链表数据项
  LinkNode<T>* link_; //!< 下一结点
};


/*!
 * @brief 单链表模板类
 * @tparam T 类型模板参数
 */
template<class T>
class LinkList: public LinearList<T> {

public:

  // 构造函数(无参数)
  LinkList();
  // 构造函数(参数为头结点的数据项)
  explicit LinkList(const T& data);
  // 构造函数(参数为节点指针引用)
  explicit LinkList(LinkNode<T>* node);
  // 复制构造函数
  LinkList(LinkList<T>& link_list);
  // 析构函数
  ~LinkList();

  // 清除链表
  void MakeEmpty();
  /*! @brief 链表长度 */
  int Length() const { return length_; }
  /*! @brief 链表头结点 */
  LinkNode<T>* Head() const { return head_ptr_; }
  // 搜索数据项为data的元素
  LinkNode<T>* Search(T data);
  // 位置pos的结点地址
  LinkNode<T>* Locate(int pos);
  // 获取第pos个结点的数据
  bool GetData(int pos, T& data) const;
  // 获取
  bool SetData(int pos, const T& data);
  // 在第pos个元素(数组索引pos - 1)之后, 插入数据
  bool Insert(int pos, const T& data);
  // 在第pos个元素(数组索引pos - 1)之后, 插入结点
  bool Insert(int pos, LinkNode<T>* node_ptr);
  bool Remove(int pos, T& data);
  bool IsEmpty() const;
  void Output();
  void CyberDashShow();

private:
  LinkNode<T>* head_ptr_;
  int length_;
};


template<class T>
LinkList<T>::LinkList() {
  this->head_ptr_ = NULL;
  this->length_ = 0;
};


template<class T>
LinkList<T>::LinkList(const T& data) {
  this->head_ptr_ = new LinkNode<T>(data);
  this->length_ = 1;
}


template<class T>
LinkList<T>::LinkList(LinkNode<T>* node_ptr) {

  if (node_ptr == NULL) {
    LinkNode<T>();
    return;
  }

  this->head_ptr_ = node_ptr;
  this->length_ = 0;

  LinkNode<T>* cur_ptr = head_ptr_;

  while (cur_ptr != NULL) {
    this->length_++;
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

  LinkNode<T>* cur_src_ptr = link_list.Head();

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
bool LinkList<T>::SetData(int pos, const T& data) {

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
    cout << "Empty list" << endl;
    return;
  }

  LinkNode<T>* cur = Head();
  while(cur != NULL) {
    cout << cur->data_ << " ";
    cur = cur->link_;
  }

  cout << endl;
}


/*!
 * @brief 在第pos个元素之后, 插入数据
 * @param pos 位置pos
 * @param data 数据项值
 * @return 是否成功
 * @note
 * 区别于数组, 以1开始\n
 * 当pos为0时, 表示插入位置1
 */
template<class T>
bool LinkList<T>::Insert(int pos, const T& data) {

  if (pos < 0 || pos > Length()) {
    return false;
  }

  LinkNode<T>* node_ptr = new LinkNode<T>(data);

  if (this->head_ptr_ == NULL) {
    node_ptr->link_ = this->head_ptr_;
    this->head_ptr_ = node_ptr;
    this->length_ = 1;
    return true;
  }

  if (pos == 0) {
    node_ptr->link_ = this->head_ptr_;
    this->head_ptr_ = node_ptr;
  } else {
    LinkNode<T>* cur = this->head_ptr_;
    while (pos - 1 > 0) {
      cur = cur->link_;
      pos--;
    }

    node_ptr->link_ = cur->link_;
    cur->link_ = node_ptr;
  }

  length_++;

  return true;
}


/*!
 * @brief 在第pos个元素之后, 插入数据
 * @param pos 位置pos
 * @param node_ptr 数据项对应的结点指针
 * @return 是否成功
 * @note
 * 区别于数组, 以1开始\n
 * 当pos为0时, 表示插入位置1
 */
template<class T>
bool LinkList<T>::Insert(int pos, LinkNode<T>* node_ptr) {

  if (pos < 0 || pos > Length()) {
    return false;
  }

  if (node_ptr == NULL) {
    return false;
  }

  if (head_ptr_ == NULL) {
    node_ptr->link_ = head_ptr_;
    head_ptr_ = node_ptr;
    length_ = 1;
    return true;
  }

  if (pos == 0) {

    node_ptr->link_ = head_ptr_;
    head_ptr_ = node_ptr;
  } else {

    LinkNode<T>* cur = head_ptr_;
    while (pos - 1 > 0) {
      cur = cur->link_;
      pos--;
    }

    node_ptr->link_ = cur->link_;
    cur->link_ = node_ptr;
  }

  length_++;

  return true;
}


/*!
 * @brief 是否为空链表
 * @tparam T 类型模板参数
 * @return 是否为空链表
 */
template<class T>
bool LinkList<T>::IsEmpty() const {
  if (length_ == 0) {
    return true;
  } else {
    return false;
  }
}


/*!
 * @brief
 * @tparam T
 */
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


template<class T>
LinkList<T>::~LinkList() {

}


template<class T>
LinkNode<T>* LinkList<T>::Search(T data) {
  return NULL;
}


template<class T>
LinkNode<T>* LinkList<T>::Locate(int pos) {
  return NULL;
}


/*!
 * @brief 删除第pos个结点
 * @tparam T
 * @param pos
 * @param data
 * @return 是否删除成功
 * @note
 * 从1开始计数
 */
template<class T>
bool LinkList<T>::Remove(int pos, T &data) {

  LinkNode<T>* delete_node_ptr = NULL;
  LinkNode<T>* cur = NULL;
  if (this->Length() == 0 || pos < 1) {
    return false;
  }

  if (pos == 1) {
    delete_node_ptr = this->head_ptr_;
    this->head_ptr_ = this->head_ptr_->link_;
  } else {
    // todo:
  }

  delete delete_node_ptr;

  return true;
}


#endif // CYBER_DASH_LINK_LIST_H
