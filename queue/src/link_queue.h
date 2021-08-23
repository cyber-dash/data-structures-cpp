/**
 * @file link_queue.h
 * @author cyberdash@163.com(抖音: cyberdash_yuan)
 * @brief 链表实现队列
 * @version 0.1
 * @date 2021-07-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef CYBER_DASH_LINK_QUEUE_H
#define CYBER_DASH_LINK_QUEUE_H

#include <cstdlib>
#include "queue.h"
#include <iostream>

using namespace std;

/**
 * @brief 链表队列结点
 * 
 * @tparam T 结点类型
 */
template <class T>
class LinkNode{

public:
  /**
  * @brief  构造一个空结点
  * 
  * @param  ptr 指针(可选) 指向下一个结点
  */
  LinkNode(LinkNode<T> *ptr = NULL): link_(ptr) {}

  /**
   * @brief 构造一个结点
   * 
   * @param data 当前结点存储的数据
   * @param ptr 指针(可选) 指向下一个结点
   */
  LinkNode(const T &data, LinkNode<T> *ptr = NULL): data_(data), link_(ptr) {}

  /**
   * @brief 获取当前结点值
   * 
   * @return T 结点值
   */
  T GetData() { return data_; }

  /**
   * @brief 设置当前结点值
   * 
   * @param data 输入的结点值
   * @return true 设置成功
   * @return false 设置失败
   */
  bool SetData(const T &data)
  {
    data_ = data;
    return true;
  }

  /**
   * @brief 获取下一结点
   * 
   * @return LinkNode<T>* 返回下一结点
   */
  LinkNode<T> *GetLink() { return link_; }

  /**
   * @brief 设置下一结点
   * 
   * @param ptr 指针 指向下一结点
   * @return true 设置成功
   * @return false 设置失败
   */
  bool SetLink(LinkNode<T> *ptr)
  {
    link_ = ptr;
    return true;
  }

private:
  /**
   * @brief 结点值
   * 
   */
  T data_;
  /**
   * @brief 下一结点
   * 
   */
  LinkNode<T> *link_;
};

/**
 * @brief 链表队列
 * 
 * @tparam T 队列存储类型
 */
template <class T>
class LinkQueue: public Queue<T>{

public:
  /**
 * @brief 构造链表队列
 * 
 */
  LinkQueue(): front_ptr_(NULL), rear_ptr_(NULL) {}
  ~LinkQueue();

  /**
   * @brief 入队操作
   * 
   * @param data 加入队列的值
   * @return true 
   * @return false 
   */
  bool EnQueue(const T &data);

  /**
   * @brief 出队操作
   * 
   * @param data 引用方式返回出队结点的值
   * @return true 
   * @return false 
   */
  bool DeQueue(T &data);

  /**
   * @brief 获取队列头结点
   * 
   * @param data 引用方式返回队列头结点的值
   * @return true 正确返回
   * @return false 运行出错
   */
  bool GetFront(T &data) const;

  /**
   * @brief 获取队列尾结点
   * 
   * @param data 引用方式返回队列尾结点的值
   * @return true 正确返回
   * @return false 运行出错
   */
  bool GetRear(T &data) const;

  /**
   * @brief 判断队列是否为空
   * 
   * @return true 空
   * @return false 不为空
   */
  bool IsEmpty() const;

  /**
   * @brief 获取队列长度
   * 
   * @return int 队列长度
   */
  int GetSize() const;

  /**
   * @brief 清空队列
   * 
   */
  void MakeEmpty();

  /**
   * @brief 获取队列前置结点
   * 
   * @return LinkNode<T>* 前置结点
   */
  LinkNode<T>* GetFrontPtr() { return front_ptr_; }

  /**
   * @brief 获取队列后置结点
   * 
   * @return LinkNode<T>* 后置结点
   */
  LinkNode<T>* GetRearPtr() { return rear_ptr_; }

  template<class U>
  friend ostream& operator<<(ostream& os, LinkQueue<T>& link_queue);
  
  /**
   * @brief CAST
   * 
   */
  void CyberDashShow();

private:
  LinkNode<T>* front_ptr_;
  LinkNode<T>* rear_ptr_;
};

/**
 * @brief 析构函数
 * @tparam T
 * @note 显式销毁时调用
 */
template<class T>
LinkQueue<T>::~LinkQueue() {
  MakeEmpty();
}

/**
 * @brief 入队操作
 * @tparam T 队列元素类型
 * @param data 入队结点值
 * @return 执行是否成功
 * @note
 */
template<class T>
bool LinkQueue<T>::EnQueue(const T& data) {

  LinkNode<T>* new_node_ptr = new LinkNode<T>(data);
  if (new_node_ptr == NULL) {
    return false;
  }

  if (IsEmpty()) {
    this->front_ptr_ = new_node_ptr;
    this->rear_ptr_ = new_node_ptr;
  } else {
    this->rear_ptr_->SetLink(new_node_ptr);
    this->rear_ptr_ = new_node_ptr;
  }

  return true;
}

/**
 * @brief 出队操作
 * @tparam T 队列元素类型
 * @param data 引用方式返回出队结点值
 * @return 执行是否成功
 * @note
 */
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

/**
 * @brief 获取队列前置结点值
 * @tparam T 队列元素类型
 * @param data 引用方式返回队列前置结点值
 * @return 执行是否成功
 * @note
 */
template<class T>
bool LinkQueue<T>::GetFront(T& data) const {

  if (IsEmpty()) {
    return false;
  }

  data = this->front_ptr_->GetData();

  return true;
}

/**
 * @brief 获取队列后置结点值
 * @tparam T 队列元素类型
 * @param data 引用方式返回队列后置结点值
 * @return 执行是否成功
 * @note
 */
template<class T>
bool LinkQueue<T>::GetRear(T& data) const {

  if (IsEmpty()) {
    return false;
  }

  data = this->rear_ptr_->GetData();

  return true;
}

/**
 * @brief 判断队列是否为空
 * @tparam T 队列元素类型
 * @return 若为空返回true 不空返回false
 * @note
 */
template<class T>
bool LinkQueue<T>::IsEmpty() const {
  if (front_ptr_ == NULL) {
    return true;
  } else {
    return false;
  }
}

/**
 * @brief 获取队列长度
 * @tparam T 队列元素类型
 * @return 队列长度
 * @note
 */
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

/**
 * @brief 清空队列
 * @tparam T 队列元素类型
 * @note
 */
template<class T>
void LinkQueue<T>::MakeEmpty() {

  LinkNode<T>* cur_ptr;

  while (front_ptr_ != NULL) {
    cur_ptr = front_ptr_;
    front_ptr_ = front_ptr_->GetLink();
    delete  cur_ptr;
  }
}

/**
 * @brief
 * @tparam T
 * @param os
 * @param link_queue
 * @return
 */
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

#endif //CYBER_DASH_LINK_QUEUE_H
