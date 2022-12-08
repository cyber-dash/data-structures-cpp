/*!
 * @file link_stack.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 链式栈模板类
 * @version 0.2.1
 * @date 2020-07-28
 */

#ifndef CYBER_DASH_LINK_STACK_H
#define CYBER_DASH_LINK_STACK_H


#include <iostream>
#include "stack.h"


using namespace std;


/*!
 * @brief **结点模板结构体**
 * @tparam TData 数据项类型模板参数
 * @note
 * 结点模板结构体
 * ------------
 * ------------
 *
 * ------------
 */
template <class TData>
struct LinkedNode {
    /*!
     * @brief **构造函数(下一结点)**
     * @param next 下一结点
     * @note
     * 构造函数(next结点)
     * ----------------
     * ----------------
     *
     * ----------------
     */
    explicit LinkedNode(LinkedNode<TData>* next = NULL) : next(next) {}

    /*!
     * @brief **构造函数(数据项, next结点)**
     * @param data 数据项值
     * @param next next结点
     * @note
     * 构造函数(数据项值, next结点)
     * ----------------
     * ----------------
     *
     * ----------------
     */
    explicit LinkedNode(const TData& data, LinkedNode<TData>* next = NULL) : data(data), next(next) {}

    TData data;                 //!< 数据项
    LinkedNode<TData>* next;    //!< 下一结点
};


template <class TData> class LinkedStack;
template<class TData> ostream& operator<<(ostream& os, LinkedStack<TData>& stack);

/*!
 * @brief **链式栈模板类**
 * @tparam TData 数据项类型模板参数
 * @note
 * 链式栈模板类
 * ----------
 * ----------
 *
 * ----------
 */
template <class TData>
class LinkedStack: public Stack<TData> {

public:
    /*!
     * @brief **默认构造函数**
     * @note
     * 默认构造函数
     * -----------
     * -----------
     *
     * -----------
     */
    LinkedStack(): top_(NULL) {}
    // 析构函数
    ~LinkedStack();
    // 入栈
    bool Push(const TData& data);
    // 出栈(保存数据)
    bool Pop(TData& data);
    // 出栈(不保存数据)
    bool Pop();
    // 获取栈顶数据
    bool Top(TData& data) const;
    // 判断栈是否为空
    bool IsEmpty() const;
    // 获取栈大小
    int Length() const;
    // 清空
    void Clear();

    // 重载<<(打印栈)
    friend ostream& operator<< <>(ostream& os, LinkedStack<TData>& stack);

private:

    // 获取栈顶结点指针
    LinkedNode<TData>* TopNode_() const;
    LinkedNode<TData>* top_;     //!< 栈顶结点指针
};


/*!
 * @brief **析构函数**
 * @tparam TData 数据项类型模板参数
 * @note
 * 析构函数
 * -------
 * -------
 *
 * 要不你还是把我删了吧
 *
 * -------
 * 调用Clear()函数
 */
template<class TData>
LinkedStack<TData>::~LinkedStack<TData>() {
    Clear();
}


/*!
 * @brief **获取栈顶结点指针**
 * @tparam TData 数据项类型模板参数
 * @return 栈顶结点指针
 * @note
 * 获取栈顶结点指针
 * --------------
 * --------------
 *
 * --------------
 */
template<class TData>
LinkedNode<TData>* LinkedStack<TData>::TopNode_() const {
    return top_;
}


/*!
 * @brief **入栈**
 * @tparam TData 数据项类型模板参数
 * @param data 数据项值
 * @note
 * 入栈
 * ----
 * ----
 *
 * ----
 */
template <class TData>
bool LinkedStack<TData>::Push(const TData& data) {
    LinkedNode<TData>* node = new LinkedNode<TData>(data);
    if (!node) {
        return false;
    }

    node->next = this->top_;
    this->top_ = node;

    return true;
}


/**
 * @brief **出栈(保存数据项)**
 * @tparam TData 数据项类型模板参数
 * @param data 数据项保存变量
 * @return 执行结果
 * @note
 * 出栈(保存数据项)
 * --------------
 * --------------
 *
 * --------------
 */
template <class TData>
bool LinkedStack<TData>::Pop(TData& data) {
    if (IsEmpty()) {
        return false;
    }

    LinkedNode<TData>* temp = this->top_;
    this->top_ = this->top_->next;

    data = temp->data;

    delete temp;
    temp = NULL;

    return true;
}


/**
 * @brief **出栈(不保存数据项)**
 * @tparam TData 数据项类型模板参数
 * @param data 数据项保存变量
 * @return 执行结果
 * @note
 * 出栈(不保存数据项)
 * ----------------
 * ----------------
 *
 * ----------------
 */
template <class TData>
bool LinkedStack<TData>::Pop() {
    if (IsEmpty()) {
        return false;
    }

    LinkedNode<TData>* temp = this->top_;
    this->top_ = this->top_->next;

    delete temp;
    temp = NULL;

    return true;
}


/*!
 * @brief **获取栈顶数据项**
 * @tparam TData 数据项类型模板参数
 * @return 执行结果
 * @note
 * 获取栈顶数据项
 * ------------
 * ------------
 *
 * ------------
 */
template <class TData>
bool LinkedStack<TData>::Top(TData& data) const {
    if (IsEmpty()) {
        return false;
    }

    data = this->top_->data;

    return true;
}


/*!
 * @brief **获取栈长度**
 * @tparam TData 数据项类型模板参数
 * @return 栈长度
 * @note
 * 获取栈长度
 * ---------
 * ---------
 *
 * ---------
 */
template<class TData>
int LinkedStack<TData>::Length() const {

    int length = 0;
    LinkedNode<TData>* cur = this->top_;

    while (cur != NULL) {
        length++;
        cur = cur->next;
    }

    return length;
}


/*!
 * @brief **栈是否为空**
 * @tparam TData 数据项类型模板参数
 * @return 结果
 * @note
 * 栈是否为空
 * ---------
 * ---------
 *
 * ---------
 */
template<class TData>
bool LinkedStack<TData>::IsEmpty() const {
    if (this->top_ == NULL) {
        return true;
    } else {
        return false;
    }
}


/**
 * @brief **栈清空**
 * @tparam TData 数据项类型模板参数
 * @note
 * 栈清空
 * -----
 * -----
 *
 * -----
 */
template<class TData>
void LinkedStack<TData>::Clear() {
    while (this->top_ != NULL) {
        LinkedNode<TData>* cur = this->top_;
        top_ = top_->next;

        delete cur;
        cur = NULL;
    }
}


 /**
  * @brief **重载<<**
  * @tparam TData 数据项类型模板参数
  * @param os 输出流
  * @param stack 栈
  * @return 输出流
  * 重载<<
  * ------
  * ------
  *
  * ------
  */
template<class TData>
ostream& operator<<(ostream& os, LinkedStack<TData>& stack) {

    os << "栈中元素个数: " << stack.Length() << endl;

    LinkedNode<TData>* cur = stack.TopNode_();

    for (int i = 1; cur != NULL; i++) {
        os << i << ":" << cur->data << endl;
        cur = cur->next;
    }

    return os;
}


#endif //CYBER_DASH_LINK_STACK_H
