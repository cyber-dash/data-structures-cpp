/**
 * @file link_queue.h
 * @author cyberdash@163.com(抖音: cyberdash_yuan)
 * @brief 链表实现队列
 * @version 0.2.1
 * @date 2021-07-28
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#ifndef CYBER_DASH_LINK_QUEUE_H
#define CYBER_DASH_LINK_QUEUE_H


#include <cstdlib>
#include "queue.h"
#include <iostream>


using namespace std;


/*!
 * @brief 链表队列结点模板结构体
 * @tparam T 类型模板参数
 */
template <class T>
class LinkNode{

public:
  /*!
   * @brief 构造函数(下一结点指针)
   * @param node 下一结点指针
   */
  LinkNode(LinkNode<T>* node = NULL): link_(node) {}

  /**
   * @brief 构造函数(数据项&下一结点指针)
   * @param data 数据项
   * @param node 下一结点指针
   */
  LinkNode(const T& data, LinkNode<T>* node = NULL): data_(data), link_(node) {}

  /**
   * @brief 获取当前结点值
   * @return T 类型模板参数
   */
  T GetData() { return data_; }

  /*!
   * @brief 设置当前结点值
   * @param data 输入的结点值
   * @return 是否成功
   */
  bool SetData(const T& data)
  {
    data_ = data;
    return true;
  }

  /*!
   * @brief 获取下一结点
   * @return LinkNode<T>* 返回下一结点
   */
  LinkNode<T>* GetLink() { return link_; }

  /*!
   * @brief 设置下一结点
   * @param node 下一结点指针
   * @return 是否成功
   */
  bool SetLink(LinkNode<T>* node)
  {
    link_ = node;
    return true;
  }

private:
  T data_; //!< 结点数据项
  LinkNode<T>* link_; //!< 下一结点
};


/**
 * @brief 链表队列模板类
 * @tparam T 类型模板参数
 */
template <class T>
class LinkQueue: public Queue<T> {

public:
  /*! @brief 构造函数 */
  LinkQueue(): front_(NULL), rear_(NULL) {}

  /*! @brief 析构函数 */
  ~LinkQueue() { MakeEmpty(); }

  /*!
   * @brief 入队
   * @param data 数据项
   * @return 是否入队成功
   */
  bool EnQueue(const T& data);

  // 出队(保存数据)
  bool DeQueue(T& data);

  // 出队(不保存数据)
  bool DeQueue();

  // 获取队头数据
  bool GetFront(T& data) const;

  // 获取队尾数据
  bool GetRear(T& data) const;

  // 判断队列是否为空
  bool IsEmpty() const;

  // 获取队列长度
  int GetSize() const;

  // 清空队列
  void MakeEmpty();

  /*!
   * @brief 获取队头结点指针
   * @return 队头结点指针
   */
  LinkNode<T>* GetFrontPtr() { return this->front_; }

  /*!
   * @brief 获取队尾结点指针
   * @return LinkNode<T>* 队尾结点指针
   */
  LinkNode<T>* GetRearPtr() { return this->rear_; }

  // 重载<<(打印队列)
  template<class U>
  friend ostream& operator<<(ostream& os, LinkQueue<T>& link_queue);
  
  // 我们是CyberDash:-)
  void CyberDashShow();

private:
  LinkNode<T>* front_; //!< 队头指针
  LinkNode<T>* rear_; //!< 队尾指针
};


/*!
 * @brief 入队
 * @tparam T 类型模板参数
 * @param data 数据
 * @return 是否成功
 */
template<class T>
bool LinkQueue<T>::EnQueue(const T& data) {

  LinkNode<T>* new_node = new LinkNode<T>(data);
  if (new_node == NULL) {
    return false;
  }

  if (IsEmpty()) {
    this->front_ = new_node;
    this->rear_ = new_node;
  } else {
    this->rear_->SetLink(new_node);
    this->rear_ = new_node;
  }

  return true;
}


/*!
 * @brief 出队(保存数据)
 * @tparam T 类型模板参数
 * @param data 数据(保存出队结点的数据项)
 * @return 是否出队成功
 */
template<class T>
bool LinkQueue<T>::DeQueue(T& data) {

  if (IsEmpty()) {
    return false;
  }

  LinkNode<T>* cur = front_;

  data = cur->GetData();
  this->front_ = this->front_->GetLink();

  delete cur;
  cur = NULL;

  return true;
}


/*!
 * @brief 出队(不保存数据)
 * @tparam T 类型模板参数
 * @param data 数据(保存出队结点的数据项)
 * @return 是否出队成功
 */
template<class T>
bool LinkQueue<T>::DeQueue() {

  if (IsEmpty()) {
    return false;
  }

  LinkNode<T>* cur = this->front_;

  this->front_ = this->front_->GetLink();

  delete cur;
  cur = NULL;

  return true;
}


/*!
 * @brief 获取队头数据
 * @tparam T 类型模板参数
 * @param data 数据(用于保存队头数据项)
 * @return 是否成功
 */
template<class T>
bool LinkQueue<T>::GetFront(T& data) const {

  if (IsEmpty()) {
    return false;
  }

  data = this->front_->GetData();

  return true;
}


/*!
 * @brief 获取队尾数据
 * @tparam T 类型模板参数
 * @param data 数据(用于保存数据项)
 * @return 是否成功
 */
template<class T>
bool LinkQueue<T>::GetRear(T& data) const {

  if (IsEmpty()) {
    return false;
  }

  data = this->rear_->GetData();

  return true;
}


/*!
 * @brief 判断队列是否为空
 * @tparam T 类型模板参数
 * @return 是否为空
 */
template<class T>
bool LinkQueue<T>::IsEmpty() const {
  if (this->front_ == NULL) {
    return true;
  } else {
    return false;
  }
}


/*!
 * @brief 获取队列长度
 * @tparam T 类型模板参数
 * @return 队列长度
 */
template<class T>
int LinkQueue<T>::GetSize() const {

  int count = 0;
  LinkNode<T>* cur = this->front_;

  while (cur != NULL) {
    cur = cur->GetLink();
    count++;
  }

  return count;
}


/*!
 * @brief 清空队列
 * @tparam T 类型模板参数
 */
template<class T>
void LinkQueue<T>::MakeEmpty() {
  while (!this->IsEmpty()) {
    this->DeQueue();
  }
}


/*!
 * @brief 重载<<(打印队列)
 * @tparam T 类型模板参数
 * @param os 输出流
 * @param link_queue 链表队列
 * @return 输出流
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
      <<"L_Dash"<<endl<<endl
      <<"数据结构开源代码(C++清华大学殷人昆)魔改升级版本: https://gitee.com/cyberdash/data-structure-cpp"<<endl
      <<endl<<"*************************************** CyberDash ***************************************"<<endl<<endl;
}

#endif //CYBER_DASH_LINK_QUEUE_H
