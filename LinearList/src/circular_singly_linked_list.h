/*!
 * @file circular_singly_linked_list.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 单向循环链表
 * @version 0.9.0
 * @date 2022-11-13
 */

#ifndef CYBER_DASH_CIRCULAR_SINGLY_LINKED_LIST_H
#define CYBER_DASH_CIRCULAR_SINGLY_LINKED_LIST_H


#include <cstddef>
#include <iostream>
#include "linear_list.h"


using namespace std;


template <typename TData>
struct CircularSinglyLinkedNode {
    /*!
     * @brief **构造函数(next)**
     * @param next 下一结点(指针)
     */
    explicit CircularSinglyLinkedNode(CircularSinglyLinkedNode<TData>* next = NULL):
        next(next) {}

    /*!
     * @brief **构造函数(data, next)**
     * @param data 数据项
     * @param next 下一结点指针
     */
    explicit CircularSinglyLinkedNode(const TData& data, CircularSinglyLinkedNode<TData>* next = NULL) :
        data(data), next(next) {}

    TData data;                               //!< 数据项
    CircularSinglyLinkedNode<TData>* next;    //!< 下一结点
};


template<typename TData>
class CircularSinglyLinkedList : public LinearList<TData> {
public:
    // 默认构造函数
    CircularSinglyLinkedList(): length_(0), head_(NULL), tail_(NULL) {}

    // 析构函数
    ~CircularSinglyLinkedList();

    /*! @brief **长度** */
    int Length() const { return this->length_; }

    /*! @brief **判断链表是否为空** */
    bool IsEmpty() const { return this->head_ == NULL; }

    // 清空链表
    void Clear();

    // 搜索
    CircularSinglyLinkedNode<TData>* Search(const TData& data);

    // 定位
    CircularSinglyLinkedNode<TData>* GetNode(int pos);

    // 向后插入
    bool Insert(int pos, const TData& data);

    // 向后删除节点
    bool Remove(int pos, TData& data);

    // 获取结点数据
    bool GetData(int pos, TData& data) const;

    // 设置结点数据
    bool SetData(int pos, const TData& data);

    // 打印双向链表
    void Print();

private:
    CircularSinglyLinkedNode<TData>* head_;
    CircularSinglyLinkedNode<TData>* tail_;
    int length_;
};


/*!
 * @brief **清空链表**
 * @tparam TData 数据项类型模板参数
 * @note
 * 清空链表
 * -------
 * -------
 *
 * -------
 * **I&nbsp;&nbsp; 空链表处理 **\n
 * **II&nbsp; 遍历并删除各个结点**\n
 * **III head_和tail_置空 **\n
 * **IV 长度调整 **\n
 */
template<typename TData>
void CircularSinglyLinkedList<TData>::Clear() {
    // ----- I 空链表处理 -----
    if (this->head_ == NULL) {
        return;
    }

    // ----- II 遍历并删除各个结点 -----
    for (int i = 1; i <= length_; i++) {
        CircularSinglyLinkedNode<TData>* temp = this->head_;
        this->head_ = temp->next;

        delete temp;
        temp = NULL;
    }

    // ----- III head_和tail_置空 -----
    this->head_ = NULL;
    this->tail_ = NULL;

    // ----- IV 长度调整 -----
    this->length_ = 0;
}


template<typename TData>
CircularSinglyLinkedNode<TData>* CircularSinglyLinkedList<TData>::Search(const TData& data) {

    CircularSinglyLinkedNode<TData>* cur = head_;
    for (int i = 1; i < length_; i++) {
        cur = cur->next;
        if (cur->data == data) {
            return cur;
        }
    }

    return NULL;
}


template<typename TData>
CircularSinglyLinkedList<TData>::~CircularSinglyLinkedList() {
    this->Clear();
}


template<typename TData>
CircularSinglyLinkedNode<TData>* CircularSinglyLinkedList<TData>::GetNode(int pos) {
    if (pos < 1 || length_ < pos) {
        return NULL;
    }

    CircularSinglyLinkedNode<TData>* cur = head_;

    for (int i = 1; i < pos; i++) {
        cur = cur->next;
    }

    return cur;
}


// 在pos后插入
template<typename TData>
bool CircularSinglyLinkedList<TData>::Insert(int pos, const TData& data) {
    if (pos > Length() || pos < 0) {
        return false;
    }

    CircularSinglyLinkedNode<TData>* node = new CircularSinglyLinkedNode<TData>(data);
    if (node == NULL) {     // if 生成结点失败
        return false;       // 返回false
    }

    if (pos == 0) {
        head_ = node;
        head_->next = head_;
        tail_ = NULL;
        length_ = 1;
        return true;
    }

    CircularSinglyLinkedNode<TData>* cur = head_;
    for (int i = 1; i < pos; i++) {
        cur = cur->next;
    }

    node->next = cur->next;     // node->next指向cur->next
    cur->next = node;           // cur->next指向node

    // 如果插入结点的next指向了head_, 则将其设置为tail_
    if (node->next == head_) {
        tail_ = node;
    }

    this->length_++;

    return true;
}


/*!
 * @brief **删除(结点)元素**
 * @tparam TData 数据项类型模板参数
 * @param pos 位置
 * @param data 数据项保存变量
 * @return 执行结果
 * @note
 * 删除(结点)元素
 * ------------
 * ------------
 * 如果删除head_结点, 则新的head_结点为原head_结点的next(如果原head_->next不为自身)
 * ------------
 * **I&nbsp;&nbsp; 错误位置处理**
 * &emsp; **if** pos < 0 或者 pos > 链表长度:\n
 * &emsp;&emsp; 返回false\n
 * **II&nbsp; 只有一个结点的情况**\n
 * &emsp; **if** 链表长度为1\n
 * &emsp;&emsp; (此时, head_指向唯一结点, tail_为NULL)\n
 * &emsp;&emsp; head_->data赋给参数data\n
 * &emsp;&emsp; 释放head_并置NULL\n
 * &emsp;&emsp; tail_置NULL\n
 * &emsp;&emsp; 长度置0\n
 * **III 删除head_结点的情况**
 * &emsp; **if** pos等于1(删除head_结点):\n
 * **IV 其他情况**
 * **V&nbsp; 长度调整**
 */
template<typename TData>
bool CircularSinglyLinkedList<TData>::Remove(int pos, TData& data) {
    // ----- I 错误位置处理 -----
    if (pos < 0 || pos > length_) {
        return false;
    }

    // ----- II 只有一个结点的情况 -----
    if (Length() == 1) {
        data = head_->data;

        delete head_;
        head_ = NULL;
        tail_ = NULL;

        length_ = 0;

        return true;
    }

    // ----- III 删除head_结点的情况 -----
    if (pos == 1) {
        data = head_->data;

        length_--;

        CircularSinglyLinkedNode<TData>* temp = head_;
        if (length_ == 1) {
            tail_ = NULL;
        } else {
            tail_->next = head_->next;
        }
        head_ = head_->next;

        delete temp;
        temp = NULL;

        return true;
    }

    // ----- IV 其他情况 -----
    CircularSinglyLinkedNode<TData>* cur = head_;
    for (int i = 1; i < pos - 1; i++) {
        cur = cur->next;
    }

    // 删除cur->next
    if (cur->next == tail_) {
        tail_ = cur;
    }

    data = cur->next->data;

    CircularSinglyLinkedNode<TData>* temp = cur->next;
    cur->next = cur->next->next;

    delete temp;
    temp = NULL;

    // ----- V 长度调整 -----
    length_--;

    return true;
}


template<typename TData>
void CircularSinglyLinkedList<TData>::Print() {

    if (this->head_ == NULL) {
        cout << "Empty list" << endl;
        return;
    }

    cout << "打印循环单链表: { ";
    CircularSinglyLinkedNode<TData>* cur = this->head_;
    for (int pos = 1; pos <= Length(); pos++) {
        cout << cur->data;
        if (pos != Length()) {
            cout << ", ";
        }
        cur = cur->next;
    }
    cout << " }" << endl;
}


template<typename TData>
bool CircularSinglyLinkedList<TData>::GetData(int pos, TData& data) const {

    if (pos < 1 || pos > Length()) {
        return false;
    }

    CircularSinglyLinkedNode<TData>* cur = head_;
    for (int i = 1; i < pos; i++) {
        cur = cur->next;
    }

    data = cur->data;

    return true;
}


template<typename TData>
bool CircularSinglyLinkedList<TData>::SetData(int pos, const TData& data) {

    if (pos < 1 || pos > Length()) {
        return false;
    }

    CircularSinglyLinkedNode<TData>* cur = head_;
    for (int i = 1; i < pos; i++) {
        cur = cur->next;
    }

    cur->data = data;

    return true;
}


#endif // CYBER_DASH_CIRCULAR_SINGLY_LINKED_LIST_H
