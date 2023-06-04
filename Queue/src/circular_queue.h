//
// Created by fenix on 2023/6/3.
//

#ifndef CYBER_DASH_SEQ_QUEUE_H
#define CYBER_DASH_SEQ_QUEUE_H


#include <cstdlib>
#include "queue.h"
#include <iostream>


using namespace std;


template<typename TData> class CircularQueue;
template<typename TData> ostream& operator<<(ostream& os, const CircularQueue<TData>& circular_queue);


template<typename TData>
class CircularQueue: public Queue<TData> {

public:
    /*! @brief **默认构造函数** */
    CircularQueue(int capacity = 20) : capacity_(capacity), front_(-1), rear_(-1) {
        this->mem_data_ = new TData[this->capacity_];
        if (!this->mem_data_) {
            throw bad_alloc();
        }
    }

    ~CircularQueue() { delete[] this->mem_data_; }

    // 入队
    bool EnQueue(const TData& data);

    // 出队(保存数据)
    bool DeQueue(TData& data);

    // 出队(不保存数据)
    bool DeQueue();

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
    friend ostream& operator<< <>(ostream& os, const CircularQueue<TData>& seq_queue);

private:
    TData* mem_data_;
    int capacity_;
    int front_;
    int rear_;
};


/*!
 * @brief **入队**
 * @tparam TData  数据项类型模板参数
 * @param data 数据项值
 * @return 执行结果
 * @note
 * 入队
 * <hr>
 *
 * <hr>
 * + **1**
 */
template<typename TData>
bool CircularQueue<TData>::EnQueue(const TData& data) {
    if (IsFull()) {
        return false;
    }

    if (Length() == 0) {
        this->front_ = 0;
        this->rear_ = 0;

        this->mem_data_[0] = data;

        return true;
    }

    this->rear_ = (this->rear_ + 1 + this->capacity_) % this->capacity_;
    this->mem_data_[this->rear_] = data;

    return true;
}


// 出队(保存数据)
template<typename TData>
bool CircularQueue<TData>::DeQueue(TData& data) {

    if (IsEmpty()) {
        return false;
    }

    if (Length() == 1) {
        this->front_ = -1;
        this->rear_ = -1;

        return true;
    }

    data = this->mem_data_[this->front_];
    front_ = (front_ + 1 + capacity_) % capacity_;

    return true;
}


// 出队(不保存数据)
template<typename TData>
bool CircularQueue<TData>::DeQueue() {
    if (IsEmpty()) {
        return false;
    }

    if (Length() == 1) {
        this->front_ = -1;
        this->rear_ = -1;

        return true;
    }

    front_ = (front_ + 1 + capacity_) % capacity_;

    return true;
}


// 获取队头数据
template<typename TData>
bool CircularQueue<TData>::Front(TData& data) const {
    if (IsEmpty()) {
        return false;
    }

    data = this->mem_data_[front_];

    return true;
}


// 获取队尾数据
template<typename TData>
bool CircularQueue<TData>::Rear(TData& data) const {
    if (IsEmpty()) {
        return false;
    }

    data = this->mem_data_[rear_];

    return true;
}

// 判断队列是否为空
template<typename TData>
bool CircularQueue<TData>::IsEmpty() const {
    return this->Length() == 0;
}

// 判断队列是否为空
template<typename TData>
bool CircularQueue<TData>::IsFull() const {
    return this->Length() == capacity_;
}

// 获取队列长度
template<typename TData>
int CircularQueue<TData>::Length() const {
    if (this->rear_ == -1 && this->front_ == -1) {
        return 0;
    }

    return (rear_ - front_ + 1 + capacity_) % capacity_;
}


// 清空队列
template<typename TData>
void CircularQueue<TData>::Clear() {
    this->rear_ = -1;
    this->front_ = -1;
}


template<typename TData>
ostream& operator<<(ostream& os, const CircularQueue<TData>& circular_queue) {

    os << "The size of link queue: " << circular_queue.Length() << endl;   // 打印队列长度

    for (int i = 0; i < circular_queue.Length(); i++) {                             // for loop 遍历队列
        int actual_index = (circular_queue.front_ + i + circular_queue.capacity_) % circular_queue.capacity_;
        os <<  circular_queue.mem_data_[actual_index] << endl;                   // 打印当前结点数据项
    }

    return os;                                                      // 返回os
}


#endif // CYBER_DASH_SEQ_QUEUE_H
