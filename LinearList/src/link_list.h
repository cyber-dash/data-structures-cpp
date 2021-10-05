/*!
 * @file link_list.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 单向链表模板类
 * @version 0.2.1
 * @date 2020-06-06
 * @copyright Copyright (c) 2021
 * **CyberDash计算机考研**
 */

#ifndef CYBER_DASH_LINK_LIST_H
#define CYBER_DASH_LINK_LIST_H


#include <iostream>
#include <cstddef>
#include "linear_list.h"


using namespace std;


/*!
 * @brief 单链表结点模板类
 * @tparam T 类型模板参数
 */
template <class T>
struct LinkNode {
  /*! @brief 构造函数(下一结点地址) */
  explicit LinkNode(LinkNode<T>* node = NULL) { this->next = node; }

  /*!
   * @brief 构造函数(数据项和下一结点地址)
   * @param data 数据项
   * @param ptr 下一节点地址
   */
  explicit LinkNode(const T& data, LinkNode<T>* node = NULL) {
    this->data = data;
    this->next = node;
  }

  T data; //!< 链表数据项
  LinkNode<T>* next; //!< 下一结点
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
  // 复制构造函数
  LinkList(const LinkList<T>& link_list);
  // 析构函数
  ~LinkList();
  // 清除链表
  void MakeEmpty();
  /*! @brief 链表长度 */
  int Length() const { return this->length_; }
  /*! @brief 链表头结点 */
  LinkNode<T>* Head() const { return this->head_; }
  // 搜索数据项为data的元素
  LinkNode<T>* Search(T data);
  // 位置pos的结点地址
  LinkNode<T>* Locate(int pos);
  // 获取第pos个结点的数据
  bool GetData(int pos, T& data) const;
  // 设置第pos个结点的数据
  bool SetData(int pos, const T& data);
  // 在第pos个元素(数组索引pos - 1)之后, 插入数据
  bool Insert(int pos, const T& data);
  // 在第pos个元素(数组索引pos - 1)之后, 插入结点
  bool Insert(int pos, LinkNode<T>* node_ptr);
  // 删除第pos个结点
  bool Remove(int pos, T& data);
  // 是否为空链表
  bool IsEmpty() const;
  // 打印链表
  void Output();
  // 我们是CyberDash
  void CyberDashShow();

private:
  LinkNode<T>* head_; //!< 链表头结点
  int length_; //!< 链表长度
};


/*!
 * @brief 构造函数(无参数)
 * @tparam T 类型参数模板
 */
template<class T>
LinkList<T>::LinkList() {
  this->head_ = new LinkNode<T>();
  /* error handler */
  this->length_ = 0;
};


/*!
 * @brief 复制构造函数
 * @tparam T 类型模板参数
 * @param link_list 链表引用
 */
template<class T>
LinkList<T>::LinkList(const LinkList<T>& link_list) {

  this->head_ = new LinkNode<T>();
  LinkNode<T>* dest_ptr = this->Head();

  LinkNode<T>* src_ptr = link_list.Head();

  while (src_ptr->next != NULL) {

    T data = src_ptr->next->data;
    dest_ptr->next = new LinkNode<T>(data);

    dest_ptr = dest_ptr->next;
    src_ptr = src_ptr->next;

    length_++;
  }

  dest_ptr->next = NULL;
}


template<class T>
LinkList<T>::~LinkList() {
  LinkNode<T>* cur = this->head_;

  while (cur->next != NULL) {
    LinkNode<T>* delete_node = cur->next;

    cur->next = delete_node->next;
    delete delete_node;
  }

  delete this->head_;
  this->head_ = NULL;
}


/*!
 * @brief 获取第pos个结点的数据
 * @tparam T 类型模板参数
 * @param pos 第pos个
 * @param data 数据(用于保存数据项)
 * @return 是否获取成功
 */
template<class T>
bool LinkList<T>::GetData(int pos, T& data) const {

  if (pos < 1 || pos > this->Length()) {
    return false;
  }

  LinkNode<T>* cur = this->head_;

  while (pos > 0) {
    cur = cur->next;
    pos--;
  }

  data = cur->data;

  return true;
}


/*!
 * @brief 设置第pos个结点的数据
 * @tparam T 类型模板参数
 * @param pos 第pos个
 * @param data 数据
 * @return 是否设置成功
 */
template<class T>
bool LinkList<T>::SetData(int pos, const T& data) {

  if (pos < 1 || pos > Length()) {
    return false;
  }

  LinkNode<T>* cur = this->head_;

  while (pos > 0) {
    cur = cur->next;
    pos--;
  }

  cur->data = data;

  return true;
}


/*!
 * @brief 清除链表
 * @tparam T 类型模板参数
 */
template<class T>
void LinkList<T>::MakeEmpty() {

  LinkNode<T>* cur = this->head_;

  while (cur->next != NULL) {
    LinkNode<T>* delete_node_ptr = cur;
    cur = cur->next;

    delete delete_node_ptr;
    this->length_--;
  }
}


/*!
 * @brief 打印链表
 * @tparam T 类型模板参数
 */
template<class T>
void LinkList<T>::Output() {

  if (head_ == NULL) {
    cout << "Empty list" << endl;
    return;
  }

  LinkNode<T>* cur = Head()->next;
  while(cur != NULL) {
    cout << cur->data << " ";
    cur = cur->next;
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

  LinkNode<T>* cur = this->head_;
  while (pos > 0) {
    cur = cur->next;
    pos--;
  }

  node_ptr->next = cur->next;
  cur->next = node_ptr;

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

  LinkNode<T>* cur = head_;
  while (pos > 0) {
    cur = cur->next;
    pos--;
  }

  node_ptr->next = cur->next;
  cur->next = node_ptr;

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
  if (this->head_->next == NULL) {
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


/*!
 * @brief 搜索数据项为data的元素
 * @tparam T 类型模板参数
 * @param data 数据
 * @return 对应的结点指针
 */
template<class T>
LinkNode<T>* LinkList<T>::Search(T data) {

  LinkNode<T>* cur = this->head_->next;
  if (cur == NULL) { // 空链表
    return NULL;
  }

  while (cur != NULL) {
    if (cur->data == data) {
      return cur;
    }

    cur = cur->next;
  }

  return NULL;
}


/*!
 * @brief 位置pos的结点地址
 * @tparam T 类型模板结点
 * @param pos 位置pos
 * @return 结点指针
 */
template<class T>
LinkNode<T>* LinkList<T>::Locate(int pos) {
  if (pos < 1 || pos > this->Length()) {
    return NULL;
  }

  LinkNode<T>* cur = this->Head()->next;
  for (int i = 1; i < pos; i++) {
    cur = cur->next;
  }

  return cur;
}


/*!
 * @brief 删除第pos个结点
 * @tparam T 类型模板参数
 * @param pos 第pos个
 * @param data 数据(用于保存被删除结点数据项)
 * @return 是否删除成功
 * @note
 * 从1开始计数
 */
template<class T>
bool LinkList<T>::Remove(int pos, T &data) {

  if (this->Length() == 0 || pos < 1 || pos > this->Length()) {
    return false;
  }

  LinkNode<T>* cur = this->head_;

  for (int i = 1; i < pos; i++) {
    cur = cur->next;
  }

  LinkNode<T>* delete_node_ptr = cur->next;
  cur->next = delete_node_ptr->next;

  data = delete_node_ptr->data;
  this->length_--;

  if (delete_node_ptr != NULL) {
    delete delete_node_ptr;
  }

  return true;
}


#endif // CYBER_DASH_LINK_LIST_H
