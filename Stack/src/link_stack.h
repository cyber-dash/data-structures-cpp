/*!
 * @file link_stack.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 链式栈模板类
 * @version 0.2.1
 * @date 2020-07-28
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#ifndef CYBER_DASH_LINK_STACK_H
#define CYBER_DASH_LINK_STACK_H


#include <iostream>
#include "stack.h"


using namespace std;


/*!
 * @brief 结点模板结构体
 * @tparam T 类型模板参数
 */
template <class T>
struct LinkNode {
  explicit LinkNode(LinkNode<T>* node = NULL): link(node) {}
  explicit LinkNode(const T& data, LinkNode<T>* node = NULL): data(data), link(node) {}

  T data; //!< 数据项
  LinkNode<T>* link; //!< 下一结点
};


/*!
 * @brief 链式栈模板类
 * @tparam T 类型模板参数
 */
template <class T>
class LinkStack: public Stack<T>{

public:
  /*! @brief 构造函数 */
  LinkStack(): top_(NULL) {}
  // 析构函数
  ~LinkStack();
  // 入栈
  void Push(const T& data);
  // 出栈(保存数据)
  bool Pop(T& data);
  // 出栈(不保存数据)
  bool Pop();
  // 获取栈顶数据
  bool GetTop(T& data) const;
  // 判断栈是否为空
  bool IsEmpty() const;
  // 获取栈大小
  int GetSize() const;
  // 清空
  void MakeEmpty();

  // 获取栈顶结点指针
  LinkNode<T>* GetTopPtr();

  // 重载<<(打印栈)
  template<class U>
  friend ostream& operator<<(ostream& os, LinkStack<T>& stack);

  void CyberDashShow();

private:
  LinkNode<T>* top_;     //!< 栈顶结点指针
};

/*!
 * @brief 析构函数
 * @tparam T 类型模板参数
 * @note 显式销毁时调用
 */
template<class T>
LinkStack<T>::~LinkStack<T>() {
  MakeEmpty();
}


/*!
 * @brief 获取栈顶结点指针
 * @tparam T 类型模板参数
 * @return 栈顶结点指针
 */
template<class T>
LinkNode<T>* LinkStack<T>::GetTopPtr() {
  return top_;
}


/*!
 * @brief 入栈
 * @tparam T 类型模板参数
 */
template <class T>
void LinkStack<T>::Push(const T& data)
{
  LinkNode<T>* node = new LinkNode<T>(data);

  node->link = this->top_;
  this->top_ = node;
}


/**
 * @brief 出栈(保存数据项)
 * @tparam T 类型模板参数
 * @param data 数据(保存数据项)
 * @return 是否成功
 */
template <class T>
bool LinkStack<T>::Pop(T& data)
{
  if (IsEmpty()) {
    return false;
  }

  LinkNode<T>* delete_node = this->top_;
  this->top_ = this->top_->link;

  data = delete_node->data;

  delete delete_node;
  delete_node = NULL;

  return true;
}


/**
 * @brief 出栈(不保存数据项)
 * @tparam T 类型模板参数
 * @param data 数据(保存数据项)
 * @return 是否成功
 */
template <class T>
bool LinkStack<T>::Pop()
{
  if (IsEmpty()) {
    return false;
  }

  LinkNode<T>* delete_node = this->top_;
  this->top_ = this->top_->link;

  delete delete_node;
  delete_node = NULL;

  return true;
}


/*!
 * @brief 获取栈顶元素
 * @tparam T 栈元素类型
 * @return 返回操作是否执行成功
 * @note
 * 仅仅获取栈顶元素，不需要将栈顶元素删除
 */
template <class T>
bool LinkStack<T>::GetTop(T& data) const
{
  if (IsEmpty()) {
    return false;
  }

  data = this->top_->data;

  return true;
}


/*!
 * @brief 获取栈的大小
 * @return 栈的大小
 */
template<class T>
int LinkStack<T>::GetSize() const {

  int count = 0;
  LinkNode<T>* cur = this->top_;

  while (cur != NULL) {
    count++;
    cur = cur->link;
  }

  return count;
}


/*!
 * @brief 判断栈是否为空
 * @return 是否为空
 */
template<class T>
bool LinkStack<T>::IsEmpty() const {
  if (this->top_ == NULL) {
    return true;
  } else {
    return false;
  }
}


/**
 * @brief 清空栈
 * @tparam T 栈元素类型
 * @note
 * 需要释放栈中每个元素
 */
template<class T>
void LinkStack<T>::MakeEmpty() {
  while (this->top_ != NULL) {
    LinkNode<T>* cur = this->top_;
    top_ = top_->link;

    delete cur;
    cur = NULL;
  }
}


/**
 * @brief 重载<<(打印栈)
 * @tparam T 类型模板参数
 * @param os 输出流
 * @param link_stack 栈
 * @return 输出流
 */
template<class T>
ostream& operator<<(ostream& os, LinkStack<T>& stack) {

  os<<"栈中元素个数: "<<stack.GetSize()<<endl;

  LinkNode<T>* cur = stack.GetTopPtr();

  for (int i = 1; cur != NULL; i++) {
    os << i << ":" << cur->data << endl;
    cur = cur->link;
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
      <<"L_Dash(lyu2586@163.com), "<<"北京邮电大学(计算机在读研究生)"<<endl<<endl
      <<"数据结构开源代码(C++清华大学殷人昆)魔改升级版本: https://gitee.com/cyberdash/data-structure-cpp"<<endl
      <<endl<<"*************************************** CyberDash ***************************************"<<endl<<endl;
}


#endif //CYBER_DASH_LINK_STACK_H
