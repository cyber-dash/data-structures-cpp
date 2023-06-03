//
// Created by fenix on 2023/6/3.
//

#ifndef CYBER_DASH_SEQ_STACK_H
#define CYBER_DASH_SEQ_STACK_H


#include <iostream>
#include "stack.h"


using namespace std;


// 链式栈模板类
template <typename TData> class SeqStack;
// 重载<<
template <typename TData> ostream& operator<<(ostream& os, const SeqStack<TData>& seq_stack);

template <typename TData>
class SeqStack: public Stack<TData> {

public:
    SeqStack(int capacity = 20): capacity_(capacity), top_index_(-1) {
        this->capacity_ = capacity;
        this->mem_data_ = new TData[this->capacity_];
        if (!this->mem_data_) {
            throw bad_alloc();
        }
    }

    // 析构函数
    ~SeqStack();
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
    // 判断栈是否满
    bool IsFull() const;
    // 获取栈大小
    int Length() const;
    // 清空
    void Clear();

    // 重载<<
    friend ostream& operator<< <>(ostream& os, const SeqStack<TData>& stack);

private:
    TData* mem_data_;    //!< 数据项数组
    int capacity_;        //!< 栈容量
    int top_index_;     //!< 栈顶索引
};


// 析构函数
template <typename TData>
SeqStack<TData>::~SeqStack() {
    delete[] this->mem_data_;
}


// 入栈
template <typename TData>
bool SeqStack<TData>::Push(const TData& data) {
    if (this->IsFull()) {
        return false;
    }

    this->top_index_++;
    this->mem_data_[this->top_index_] = data;

    return true;
}


// 出栈(保存数据)
template <typename TData>
bool SeqStack<TData>::Pop(TData& data) {
    if (this->Length() == 0) {
        return false;
    }

    data = this->mem_data_[this->top_index_];
    this->top_index_--;

    return true;
}


// 出栈(不保存数据)
template <typename TData>
bool SeqStack<TData>::Pop() {
    if (this->Length() == 0) {
        return false;
    }

    this->top_index_--;

    return true;
}


// 获取栈顶数据
template <typename TData>
bool SeqStack<TData>::Top(TData& data) const {
    if (this->Length() == 0) {
        return false;
    }

    data = this->mem_data_[this->top_index_];

    return true;
}


// 判断栈是否为空
template <typename TData>
bool SeqStack<TData>::IsEmpty() const {
    return this->top_index_ == -1;
}


// 判断栈是否为空
template <typename TData>
bool SeqStack<TData>::IsFull() const {
    return this->top_index_ == this->capacity_ - 1;
}


// 获取栈大小
template <typename TData>
int SeqStack<TData>::Length() const {
    return this->top_index_ + 1;
}


// 清空
template <typename TData>
void SeqStack<TData>::Clear() {
    int length = this->Length();
    if (length == 0) {
        return;
    }

    for (int i = 0; i < length; i++) {
        this->Pop();
    }
}


template<typename TData>
ostream& operator<<(ostream& os, const SeqStack<TData>& seq_stack) {

    os << "栈中元素个数: " << seq_stack.Length() << endl;                         // 打印栈元素个数

    /*
    LinkedNode<TData>* cur = seq_stack.TopNode_();                              // 初始化cur(遍历指针)指向栈顶

    for (int i = 1; cur != NULL; i++) {                                     // for loop 使用cur遍历栈
        os << i << ":" << cur->data << endl;                                // 打印cur->data
        cur = cur->next;                                                    // cur指向cur->next
    }
     */

    for (int i = seq_stack.top_index_; i >= 0; i--) {
        os << seq_stack.mem_data_[i] << endl;                                // 打印cur->data
    }

    return os;                                                              // 返回os
}

#endif // CYBER_DASH_SEQ_STACK_H
