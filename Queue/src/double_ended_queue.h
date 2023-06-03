//
// Created by fenix on 2023/6/3.
//

#ifndef CYBER_DASH_DOUBLE_ENDED_QUEUE_H
#define CYBER_DASH_DOUBLE_ENDED_QUEUE_H


#include <cstdlib>
#include "queue.h"
#include <iostream>


using namespace std;


template<typename TData> class DoubleEndedQueue;
template<typename TData> ostream& operator<<(ostream& os, const DoubleEndedQueue<TData>& circular_queue);


template<typename TData>
class DoubleEndedQueue {

public:
    /*! @brief **默认构造函数** */
    DoubleEndedQueue(int capacity = 20) : capacity_(capacity), front_index_(-1), rear_index_(-1) {
        this->mem_data_ = new TData[this->capacity_];
        if (!this->mem_data_) {
            throw bad_alloc();
        }
    }

    ~DoubleEndedQueue() { delete[] this->mem_data_; }

    // 队尾入队
    bool PushBack(const TData& data);
    // 队头入队
    bool PushFront(const TData& data);

    // 队头出队(保存数据)
    bool PopFront(TData& data);
    // 队头出队(不保存数据)
    bool PopFront();

    // 队头出队(保存数据)
    bool PopBack(TData& data);
    // 队头出队(不保存数据)
    bool PopBack();

    // 获取队头数据
    bool Front(TData& data) const;

    // 获取队尾数据
    bool Rear(TData& data) const;

    // 判断队列是否为空
    bool IsEmpty() const;

    // 判断队列是否满
    bool IsFull() const;

    // 获取队列长度
    int Length() const;

    // 清空队列
    void Clear();

    // 重载<<(打印队列)
    friend ostream& operator<< <>(ostream& os, const DoubleEndedQueue<TData>& seq_queue);

private:
    TData* mem_data_;
    int capacity_;
    int front_index_;
    int rear_index_;
};


// 队尾入队
template<typename TData>
bool DoubleEndedQueue<TData>::PushBack(const TData& data) {
    if (IsFull()) {
        return false;
    }

    if (Length() == 0) {
        this->front_index_ = 0;
        this->rear_index_ = 0;

        this->mem_data_[0] = data;

        return true;
    }

    this->rear_index_ = (this->rear_index_ + 1 + this->capacity_) % this->capacity_;
    this->mem_data_[this->rear_index_] = data;

    return true;
}


// 队头入队
template<typename TData>
bool DoubleEndedQueue<TData>::PushFront(const TData& data) {
    if (IsFull()) {
        return false;
    }

    if (Length() == 0) {
        this->front_index_ = 0;
        this->rear_index_ = 0;

        this->mem_data_[0] = data;

        return true;
    }

    this->front_index_ = (this->front_index_ - 1 + this->capacity_) % this->capacity_;
    this->mem_data_[this->front_index_] = data;

    return true;
}



// 队头出队(保存数据)
template<typename TData>
bool DoubleEndedQueue<TData>::PopFront(TData& data) {

    if (IsEmpty()) {
        return false;
    }

    if (Length() == 1) {
        this->front_index_ = -1;
        this->rear_index_ = -1;

        return true;
    }

    data = this->mem_data_[this->front_index_];
    front_index_ = (front_index_ + 1 + capacity_) % capacity_;

    return true;
}


// 队头出队(不保存数据)
template<typename TData>
bool DoubleEndedQueue<TData>::PopFront() {
    if (IsEmpty()) {
        return false;
    }

    if (Length() == 1) {
        this->front_index_ = -1;
        this->rear_index_ = -1;

        return true;
    }

    front_index_ = (front_index_ + 1 + capacity_) % capacity_;

    return true;
}


template<typename TData>
bool DoubleEndedQueue<TData>::PopBack(TData& data) {

    if (IsEmpty()) {
        return false;
    }

    if (Length() == 1) {
        this->front_index_ = -1;
        this->rear_index_ = -1;

        return true;
    }

    data = this->mem_data_[this->rear_index_];
    rear_index_ = (rear_index_ - 1 + capacity_) % capacity_;

    return true;
}


// 队尾出队(不保存数据)
template<typename TData>
bool DoubleEndedQueue<TData>::PopBack() {
    if (IsEmpty()) {
        return false;
    }

    if (Length() == 1) {
        this->front_index_ = -1;
        this->rear_index_ = -1;

        return true;
    }

    rear_index_ = (rear_index_ - 1 + capacity_) % capacity_;

    return true;
}


// 获取队头数据
template<typename TData>
bool DoubleEndedQueue<TData>::Front(TData& data) const {
    if (IsEmpty()) {
        return false;
    }

    data = this->mem_data_[front_index_];

    return true;
}


// 获取队尾数据
template<typename TData>
bool DoubleEndedQueue<TData>::Rear(TData& data) const {
    if (IsEmpty()) {
        return false;
    }

    data = this->mem_data_[rear_index_];

    return true;
}

// 判断队列是否为空
template<typename TData>
bool DoubleEndedQueue<TData>::IsEmpty() const {
    return this->Length() == 0;
}

// 判断队列是否为空
template<typename TData>
bool DoubleEndedQueue<TData>::IsFull() const {
    return this->Length() == capacity_;
}

// 获取队列长度
template<typename TData>
int DoubleEndedQueue<TData>::Length() const {
    if (this->rear_index_ == -1 && this->front_index_ == -1) {
        return 0;
    }

    return (rear_index_ - front_index_ + 1 + capacity_) % capacity_;
}


// 清空队列
template<typename TData>
void DoubleEndedQueue<TData>::Clear() {
    this->rear_index_ = -1;
    this->front_index_ = -1;
}


template<typename TData>
ostream& operator<<(ostream& os, const DoubleEndedQueue<TData>& circular_queue) {

    os << "The size of link queue: " << circular_queue.Length() << endl;   // 打印队列长度

    for (int i = 0; i < circular_queue.Length(); i++) {                             // for loop 遍历队列
        int actual_index = (circular_queue.front_index_ + i + circular_queue.capacity_) % circular_queue.capacity_;
        os <<  circular_queue.mem_data_[actual_index] << endl;                   // 打印当前结点数据项
    }

    return os;                                                      // 返回os
}

#endif // CYBER_DASH_DOUBLE_ENDED_QUEUE_H
