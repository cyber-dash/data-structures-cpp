﻿/*!
 * @file doubly_linked_list.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 双向链表
 * @version 0.9.0
 * @date 2022-11-13
 */

#ifndef CYBER_DASH_DOUBLY_LINKED_LIST_H
#define CYBER_DASH_DOUBLY_LINKED_LIST_H


#include <cstddef>
#include <iostream>
#include "linear_list.h"


using namespace std;


template <typename TData>
struct DoublyLinkedNode {
    /*!
     * @brief **构造函数(next与prev)**
     * @param next 下一结点(指针)
     * @param prev 上一结点(指针)
     */
    explicit DoublyLinkedNode(DoublyLinkedNode<TData>* next = NULL, DoublyLinkedNode<TData>* prev = NULL) :
        prev(prev), next(next) {}

    /*!
     * @brief **构造函数(data, next和prev)**
     * @param data 数据项
     * @param next 下一结点指针
     * @param prev 上一结点指针
     */
    explicit DoublyLinkedNode(const TData& data, DoublyLinkedNode<TData>* next = NULL, DoublyLinkedNode<TData>* prev = NULL) :
        data(data), prev(prev), next(next) {}

    TData data;                               //!< 数据项
    DoublyLinkedNode<TData>* next;    //!< 下一结点
    DoublyLinkedNode<TData>* prev;    //!< 上一结点
};


template<typename TData>
class DoublyLinkedList : public LinearList<TData> {
public:
    // 默认构造函数
    DoublyLinkedList();

    // 析构函数
    ~DoublyLinkedList();

    bool IsEmpty() const { return this->head_->next == head_; }

    bool Insert(int pos, const TData& data);

    DoublyLinkedNode<TData>* GetNode(int pos) { return NULL; }  // todo:

    bool GetData(int pos, TData& data) const { return true; }   // todo:

    bool SetData(int pos, const TData& data) { return true; }   // todo:

    bool Remove(int pos, TData& data);

    void Print();

    /*! @brief **长度** */
    int Length() const { return this->length_; }
private:
    DoublyLinkedNode<TData>* head_;
    int length_;
};


template<typename TData>
DoublyLinkedList<TData>::DoublyLinkedList() {
    head_ = new DoublyLinkedNode<TData>();
    head_->next = head_;
    head_->prev = head_;

    length_ = 0;
}


template<typename TData>
bool DoublyLinkedList<TData>::Insert(int pos, const TData& data) {
    if (pos > length_ || pos < 0) {
        return false;
    }

    DoublyLinkedNode<TData>* node = new DoublyLinkedNode<TData>(data);
    if (!node) {
        return false;
    }

    DoublyLinkedNode<TData>* cur = head_;
    while (pos > 0) {
        cur = cur->next;
        pos--;
    }

    node->next = cur->next;     // node->next指向cur->next
    cur->next = node;           // cur->next指向node
    node->next->prev = node;    // node->next->prev指向node
    node->prev = cur;           // node->prev指向cur

    length_++;

    return true;
}


template<typename TData>
bool DoublyLinkedList<TData>::Remove(int pos, TData& data) {

    if (Length() < pos || pos < 0) {
        return false;
    }

    DoublyLinkedNode<TData>* cur = head_->next;
    while (pos > 1) {
        cur = cur->next;
        pos--;
    }

    cur->next->prev = cur->prev;
    cur->prev->next = cur->next;
    data = cur->data;

    delete cur;
    cur = NULL;

    return true;
}

template<typename TData>
void DoublyLinkedList<TData>::Print() {
    if (this->length_ == 0) {
        cout << "Empty list" << endl;
        return;
    }

    DoublyLinkedNode<TData>* cur = head_->next;
    while (cur != head_) {
        cout<<cur->data<<"; ";
        cur = cur->next;
    }

    cout<<endl;
}


#endif // CYBER_DASH_DOUBLY_LINKED_LIST_H
