/*!
 * @file double_ended_queue.h
 * @author cyberdash@163.com(抖音: cyberdash_yuan)
 * @brief 循环双端队列
 * @version 0.2.1
 * @date 2023-06-03
 */

#ifndef CYBER_DASH_DOUBLE_ENDED_QUEUE_H
#define CYBER_DASH_DOUBLE_ENDED_QUEUE_H


#include <cstdlib>
#include <iostream>
#include "queue.h"


using namespace std;


template<typename TData> class DoubleEndedQueue;
template<typename TData> ostream& operator<<(ostream& os, const DoubleEndedQueue<TData>& circular_queue);


/*!
 * @brief **双端队列**
 * @tparam TData 数据项类型模板参数
 */
template<typename TData>
class DoubleEndedQueue {

public:
    /*!
     * @brief **构造函数**
     * @param capacity 容量
     * @note
     * 构造函数
     * -------
     * -------
     *
     * -------
     * capacity_使用参数capacity, front(队头索引)初始化为-1, rear(队尾索引)初始化为-1\n\n
     * mem_data_分配内存\n
     * **if** 内存分配失败 :\n
     * &emsp; 抛出bad_alloc()\n
     *
     *
     * -------
     */
    DoubleEndedQueue(int capacity = 20) : capacity_(capacity), front_(-1), rear_(-1) {
        this->mem_data_ = new TData[this->capacity_];
        if (!this->mem_data_) {
            throw bad_alloc();
        }
    }

    /*!
     * @brief **析构函数**
     * @note
     * 析构函数
     * -------
     * -------
     *
     * -------
     * 释放mem_data_
     *
     *
     * -------
     */
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

    // 判断是否空队
    bool IsEmpty() const;

    // 判断是否满队
    bool IsFull() const;

    // 获取长度
    int Length() const;

    // 清空队列
    void Clear();

    // 重载<<(打印队列)
    friend ostream& operator<< <>(ostream& os, const DoubleEndedQueue<TData>& seq_queue);

private:
    TData* mem_data_;               //<! 元素数组
    int capacity_;                  //<! 容量
    int front_;                     //<! 队头索引
    int rear_;                      //<! 队尾索引
};


// 队尾入队
/*!
 * @brief **队尾入队**
 * @tparam TData 数据项类型模板参数
 * @param data 数据项
 * @return 执行结果
 * @note
 * 队尾入队
 * -------
 * -------
 *
 * -------
 */
template<typename TData>
bool DoubleEndedQueue<TData>::PushBack(const TData& data) {
    if (IsFull()) {
        return false;
    }

    if (Length() == 0) {
        this->front_ = 0;
        // this->rear_ = 0;

        // this->mem_data_[0] = data;

        // return true;
    }

    this->rear_ = (this->rear_ + 1 + this->capacity_) % this->capacity_;
    this->mem_data_[this->rear_] = data;

    return true;
}


// 队头入队
template<typename TData>
bool DoubleEndedQueue<TData>::PushFront(const TData& data) {
    if (IsFull()) {
        return false;
    }

    if (Length() == 0) {
        // this->front_ = 0;
        this->rear_ = 0;

        // this->mem_data_[0] = data;

        // return true;
    }

    this->front_ = (this->front_ - 1 + this->capacity_) % this->capacity_;
    this->mem_data_[this->front_] = data;

    return true;
}



// 队头出队(保存数据)
template<typename TData>
bool DoubleEndedQueue<TData>::PopFront(TData& data) {

    if (IsEmpty()) {
        return false;
    }

    data = this->mem_data_[this->front_];
    if (Length() == 1) {
        this->front_ = -1;
        this->rear_ = -1;
    } else {
        front_ = (front_ + 1 + capacity_) % capacity_;
    }

    return true;
}


// 队头出队(不保存数据)
template<typename TData>
bool DoubleEndedQueue<TData>::PopFront() {
    if (IsEmpty()) {
        return false;
    }

    if (Length() == 1) {
        this->front_ = -1;
        this->rear_ = -1;
    } else {
        front_ = (front_ + 1 + capacity_) % capacity_;
    }

    return true;
}


template<typename TData>
bool DoubleEndedQueue<TData>::PopBack(TData& data) {

    if (IsEmpty()) {
        return false;
    }

    data = this->mem_data_[this->rear_];

    if (Length() == 1) {
        this->front_ = -1;
        this->rear_ = -1;
    } else {
        rear_ = (rear_ - 1 + capacity_) % capacity_;
    }

    return true;
}


// 队尾出队(不保存数据)
template<typename TData>
bool DoubleEndedQueue<TData>::PopBack() {
    if (IsEmpty()) {
        return false;
    }

    if (Length() == 1) {
        this->front_ = -1;
        this->rear_ = -1;
    } else {
        rear_ = (rear_ - 1 + capacity_) % capacity_;
    }

    return true;
}


// 获取队头数据
template<typename TData>
bool DoubleEndedQueue<TData>::Front(TData& data) const {
    if (IsEmpty()) {
        return false;
    }

    data = this->mem_data_[front_];

    return true;
}


// 获取队尾数据
template<typename TData>
bool DoubleEndedQueue<TData>::Rear(TData& data) const {
    if (IsEmpty()) {
        return false;
    }

    data = this->mem_data_[rear_];

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
    if (this->rear_ == -1 && this->front_ == -1) {
        return 0;
    }

    return (rear_ - front_ + 1 + capacity_) % capacity_;
}


// 清空队列
template<typename TData>
void DoubleEndedQueue<TData>::Clear() {
    this->rear_ = -1;
    this->front_ = -1;
}


template<typename TData>
ostream& operator<<(ostream& os, const DoubleEndedQueue<TData>& circular_queue) {

    os << "The size of link queue: " << circular_queue.Length() << endl;   // 打印队列长度

    for (int i = 0; i < circular_queue.Length(); i++) {                             // for loop 遍历队列
        int actual_index = (circular_queue.front_ + i + circular_queue.capacity_) % circular_queue.capacity_;
        os <<  circular_queue.mem_data_[actual_index] << endl;                   // 打印当前结点数据项
    }

    return os;                                                      // 返回os
}

#endif // CYBER_DASH_DOUBLE_ENDED_QUEUE_H
