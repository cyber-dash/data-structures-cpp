//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/7/28.
//

#ifndef CYBER_DASH_LINK_STACK_H
#define CYBER_DASH_LINK_STACK_H


#include <iostream>
#include "stack.h"


using namespace std;


template <class T>
struct LinkNode {

  T data_;

  LinkNode<T> *link_;

  explicit LinkNode(LinkNode<T>* ptr = NULL): link_(ptr) {}
  explicit LinkNode(const T& data, LinkNode<T> *ptr = NULL): data_(data), link_(ptr) {}
};


//! 栈结构体
template <class T>
class LinkStack: public Stack<T>{

public:
  /*! @brief 构造函数 */
  LinkStack(): top_ptr_(NULL) {}
  /*! @brief 析构函数 */
  ~LinkStack();
  /*! @brief 入栈一个元素 */
  void Push(const T& data);
  /*! @brief 出栈一个元素 */
  bool Pop(T& data);
  /*! @brief 获取栈顶元素 */
  bool GetTop(T& data) const;
  /*! @brief 判断栈是否为空 */
  bool IsEmpty() const;
  /*! @brief 获取栈大小 */
  int GetSize() const;
  /*! @brief 清空一个栈 */
  void MakeEmpty();

  /*! @brief 获取栈顶元素指针 */
  LinkNode<T>* GetTopPtr();

  template<class U>
  friend ostream& operator<<(ostream& os, LinkStack<T>& stack);

  void CyberDashShow();

private:
  LinkNode<T>* top_ptr_;     // 元素

};

/**
 * @brief 析构函数
 * @tparam T 栈元素类型
 * @note 显式销毁时调用
 */
template<class T>
LinkStack<T>::~LinkStack<T>() {
  MakeEmpty();
}


/**
 * @brief 获取栈顶元素指针
 * @tparam T 栈元素类型
 * @return 返回栈顶元素指针
 * @note
 */
template<class T>
LinkNode<T>* LinkStack<T>::GetTopPtr() {
  return top_ptr_;
}


/**
 * @brief 入栈操作
 * @tparam T 栈元素类型
 * @note
 * 将元素压入栈顶
 */
template <class T>
void LinkStack<T>::Push(T const& data)
{
  LinkNode<T>* link_node = new LinkNode<T>(data);

  link_node->link_ = top_ptr_;
  top_ptr_ = link_node;
}


/**
 * @brief 出栈操作
 * @tparam T 栈元素类型
 * @return 返回操作是否执行成功
 * @note
 * 获取成功之后需要将栈顶元素删除
 */
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


/**
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
    // throw out_of_range("Stack<>::top(): empty stack");
    return false;
  }

  data = top_ptr_->data_;

  return true;
}

/**
 * @brief 获取栈的大小
 * @return 返回栈的大小
 * @note
 * 需要遍历栈大小，时间复杂度O(n)
 */
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


/**
 * @brief 判断栈是否为空
 * @return 如果栈为空，则返回true，否则返回false
 * @note
 */
template<class T>
bool LinkStack<T>::IsEmpty() const {
  if (top_ptr_ == NULL) {
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

  LinkNode<T>* cur_ptr;

  while (top_ptr_ != NULL) {
    cur_ptr = top_ptr_;
    top_ptr_ = top_ptr_->link_;
    delete cur_ptr;
  }
}


/**
 * @brief
 * @tparam T 栈元素类型
 * @param os
 * @param link_stack
 * @return
 */
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


#endif //CYBER_DASH_LINK_STACK_H
