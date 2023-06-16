/*!
 * @file linked_stack.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 链式栈头文件
 * @version 0.2.1
 * @date 2020-07-15
 */

#ifndef CYBER_DASH_LINKED_STACK_H
#define CYBER_DASH_LINKED_STACK_H


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
template <typename TData>
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
     * ------------------------
     * ------------------------
     *
     * ------------------------
     */
    explicit LinkedNode(const TData& data, LinkedNode<TData>* next = NULL) : data(data), next(next) {}

    TData data;                 //!< **数据项**
    LinkedNode<TData>* next;    //!< **下一结点**
};


// 链式栈模板类
template <typename TData> class LinkedStack;
// 重载<<
template <typename TData> ostream& operator<<(ostream& os, const LinkedStack<TData>& stack);


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
template <typename TData>
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

    // 重载<<
    friend ostream& operator<< <>(ostream& os, const LinkedStack<TData>& stack);

private:

    LinkedNode<TData>* top_;     //!< **栈顶结点指针**
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
 *
 *
 * -------
 */
template<typename TData>
LinkedStack<TData>::~LinkedStack() {
    Clear();
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
 * + **1 生成结点**\n
 * 分配内存并初始化node\n
 * **if** 内存分配失败 :\n
 * &emsp; 抛出bad_alloc()\n\n
 * + **2 执行入栈**\n
 * node->next指向top_\n
 * top_指向node\n\n
 * + **3 退出函数**\n
 * 返回true\n
 *
 *
 * ----
 */
template <typename TData>
bool LinkedStack<TData>::Push(const TData& data) {

    // ---------- 1 生成结点 ----------

    LinkedNode<TData>* node = new LinkedNode<TData>(data);                              // 分配内存并初始化node
    if (!node) {                                                                        // if 内存分配失败
        throw bad_alloc();                                                              // 抛出bad_alloc()
    }

    // ---------- 2 执行入栈 ----------

    node->next = this->top_;                                                            // node->next指向top_
    this->top_ = node;                                                                  // top_指向node

    // ---------- 3 退出函数 ----------

    return true;                                                                        // 返回true
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
 * + **1 空栈判断**\n
 * **if** 空栈 :\n
 * &emsp; 返回false\n\n
 * + **2 出栈操作**\n
 * 初始化temp, 指向top_\n
 * top_指向top_->next\n\n
 * temp->data赋给参数data\n\n
 * 释放temp\n
 * temp置NULL\n\n
 * + **3 退出函数**\n
 * 返回true\n
 *
 *
 * --------------
 */
template <typename TData>
bool LinkedStack<TData>::Pop(TData& data) {

    // ---------- 1 空栈判断 ----------

    if (IsEmpty()) {                                                            // if 空栈
        return false;                                                           // 返回false
    }

    // ---------- 2 出栈操作 ----------

    LinkedNode<TData>* temp = this->top_;                                       // 初始化temp, 指向top_
    this->top_ = this->top_->next;                                              // top_指向top_->next

    data = temp->data;                                                          // temp->data赋给参数data

    delete temp;                                                                // 释放temp
    temp = NULL;                                                                // temp置NULL

    // ---------- 3 退出函数 ----------

    return true;                                                                // 返回true
}


/**
 * @brief **出栈(不保存数据项)**
 * @tparam TData 数据项类型模板参数
 * @return 执行结果
 * @note
 * 出栈(不保存数据项)
 * ----------------
 * ----------------
 *
 * ----------------
 * + **1 空栈判断**\n
 * **if** 空栈 :\n
 * &emsp; 返回false\n\n
 * + **2 出栈操作**\n
 * 初始化temp, 指向top_\n
 * top_指向top_->next\n\n
 * 释放temp\n
 * temp置NULL\n\n
 * + **3 退出函数**\n
 * 返回true\n
 *
 *
 * ----------------
 */
template <typename TData>
bool LinkedStack<TData>::Pop() {

    // ---------- 1 空栈判断 ----------

    if (IsEmpty()) {                                                            // if 空栈
        return false;                                                           // 返回false
    }

    // ---------- 2 出栈操作 ----------

    LinkedNode<TData>* temp = this->top_;                                       // 初始化temp, 指向top_
    this->top_ = this->top_->next;                                              // top_指向top_->next

    delete temp;                                                                // 释放temp
    temp = NULL;                                                                // temp置NULL

    // ---------- 3 退出函数 ----------

    return true;                                                                // 返回true
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
 * + **1 空栈处理**\n
 * **if** 空栈 :\n
 * &emsp; 返回false\n\n
 * + **2 读栈顶数据项**\n
 * top_->data赋给参数data\n\n
 * + **3 退出函数**\n
 * 返回true\n
 *
 *
 * ------------
 */
template <typename TData>
bool LinkedStack<TData>::Top(TData& data) const {

    // ---------- 1 空栈处理 ----------

    if (IsEmpty()) {                                                                // if 空栈
        return false;                                                               // 返回false
    }

    // ---------- 2 读栈顶数据项 ----------

    data = this->top_->data;                                                        // top_->data赋给参数data

    // ---------- 3 退出函数 ----------

    return true;                                                                    // 返回true
}


/*!
 * @brief **获取长度**
 * @tparam TData 数据项类型模板参数
 * @return 长度
 * @note
 * 获取长度
 * -------
 * -------
 *
 * -------
 * 初始化length(长度)为0\n
 * 初始化cur(遍历指针), 指向top_\n\n
 * **while loop** cur不为NULL :\n
 * &emsp; length加1\n
 * &emsp; cur指向cur->next\n\n
 * 返回length\n
 *
 *
 * -------
 */
template<typename TData>
int LinkedStack<TData>::Length() const {

    int length = 0;                                                         // 初始化length(长度)为0
    LinkedNode<TData>* cur = this->top_;                                    // 初始化cur(遍历指针), 指向top_

    while (cur != NULL) {                                                   // while loop cur不为NULL
        length++;                                                           // length加1
        cur = cur->next;                                                    // cur指向cur->next
    }

    return length;                                                          // 返回length
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
 * 返回 top_ == NULL\n
 *
 *
 * ---------
 */
template<typename TData>
bool LinkedStack<TData>::IsEmpty() const {
    if (this->top_ == NULL) {
        return true;
    } else {
        return false;
    }
}


/**
 * @brief **清空**
 * @tparam TData 数据项类型模板参数
 * @note
 * 清空
 * ----
 * ----
 *
 * ----
 * **while loop** top_不为NULL :\n
 * &emsp; 初始化deletion_node, 指向top_\n
 * &emsp; top_指向top_->next\n\n
 * &emsp; 释放deletion_node\n
 * &emsp; deletion_node置NULL\n
 *
 *
 * ----
 */
template<typename TData>
void LinkedStack<TData>::Clear() {
    while (this->top_ != NULL) {                                                    // while loop top_不为NULL
        LinkedNode<TData>* target = this->top_;                                     // 初始化deletion_node, 指向top_
        top_ = top_->next;                                                          // top_指向top_->next

        delete target;                                                              // 释放deletion_node
        target = NULL;                                                              // deletion_node置NULL
    }
}


/**
 * @brief **重载&lt;&lt;**
 * @tparam TData 数据项类型模板参数
 * @param os 输出流
 * @param stack 栈
 * @return 输出流
 * 重载<<
 * ------
 * ------
 *
 * ------
 * 打印栈元素个数\n\n
 * 初始化cur(遍历指针)指向栈顶\n\n
 * **for loop** 使用cur遍历栈 :\n
 * &emsp; 打印cur->data\n
 * &emsp; cur指向cur->next\n\n
 * 返回os\n
 *
 *
 * ------
 */
template<typename TData>
ostream& operator<<(ostream& os, const LinkedStack<TData>& stack) {

    os << "栈中元素个数: " << stack.Length() << endl;                         // 打印栈元素个数

    LinkedNode<TData>* cur = stack.top_;                                    // 初始化cur(遍历指针)指向栈顶

    for (int i = 1; cur != NULL; i++) {                                     // for loop 使用cur遍历栈
        os << cur->data << endl;                                            // 打印cur->data
        cur = cur->next;                                                    // cur指向cur->next
    }

    return os;                                                              // 返回os
}


#endif //CYBER_DASH_LINKED_STACK_H
