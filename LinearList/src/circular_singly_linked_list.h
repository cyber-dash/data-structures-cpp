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
    CircularSinglyLinkedList();

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


template<typename TData>
CircularSinglyLinkedList<TData>::CircularSinglyLinkedList() {
    this->head_ = NULL;
    this->tail_ = NULL;
    this->length_ = 0;
}


template<typename TData>
void CircularSinglyLinkedList<TData>::Clear() {
    if (this->head_ == NULL) {
        return;
    }

    for (int i = 1; i < length_ - 1; i++) {
        CircularSinglyLinkedNode<TData>* cur = this->head_;
        this->head_ = cur->next;

        delete cur;
        cur = NULL;
    }

    delete this->head_;
    this->head_ = NULL;
    this->tail_ = NULL;

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
CircularSinglyLinkedNode<TData>* CircularSinglyLinkedList<TData>::GetNode(int pos) {

    if (pos < 0 || pos > Length()) {
        return NULL;
    }

    CircularSinglyLinkedNode<TData>* cur = head_;
    for (int i = 1; i < pos; i++) {
        cur = cur->next;
    }

    return cur;
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
        tail_ = node;
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


template<typename TData>
bool CircularSinglyLinkedList<TData>::Remove(int pos, TData& data) {
    if (pos < 0 || pos > length_) {
        return false;
    }

    if (Length() == 1) {
        data = head_->data;

        delete head_;
        head_ = NULL;
        tail_ = NULL;

        length_ = 0;

        return true;
    }

    // 删除head_
    if (pos == 1) {
        data = head_->data;

        CircularSinglyLinkedNode<TData>* temp = head_;
        tail_->next = head_->next;
        head_ = head_->next;

        delete temp;
        temp = NULL;

        length_--;

        return true;
    }

    // cur遍历到被删除结点的前驱
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

    length_--;

    return true;
}


template<typename TData>
void CircularSinglyLinkedList<TData>::Print() {

    if (this->head_ == NULL) {
        cout << "Empty list" << endl;
        return;
    }

    cout << "向next方向(forward)遍历输出：" << endl;
    CircularSinglyLinkedNode<TData>* cur = this->head_;
    for (int pos = 1; pos <= Length(); pos++) {
        cout << cur->data << "; ";
        cur = cur->next;
    }
    cout << endl;
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
