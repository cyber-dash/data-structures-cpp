/*!
 * @file circular_queue.h
 * @author cyberdash@163.com(抖音: cyberdash_yuan)
 * @brief 循环队列
 * @version 0.2.1
 * @date 2021-07-28
 */

#ifndef CYBER_DASH_CIRCULAR_QUEUE_H
#define CYBER_DASH_CIRCULAR_QUEUE_H


#include <cstdlib>
#include <iostream>
#include "queue.h"


using namespace std;


template<typename TData> class CircularQueue;
template<typename TData> ostream& operator<<(ostream& os, const CircularQueue<TData>& circular_queue);


template<typename TData>
class CircularQueue: public Queue<TData> {

public:
    /*!
     * @brief **构造函数**
     * @param capacity 容量(队列最大长度)
     * @note
     * 构造函数
     * -------
     * -------
     *
     * 默认容量20
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
    CircularQueue(int capacity = 20) : capacity_(capacity), front_(-1), rear_(-1) {
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
     * 释放this->mem_data_
     */
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
    TData* mem_data_;               //!< **元素数组**
    int capacity_;                  //!< **容量**
    int front_;                     //!< **队头索引**
    int rear_;                      //!< **队尾索引**
};


/*!
 * @brief **入队**
 * @tparam TData  数据项类型模板参数
 * @param data 数据项值
 * @return 执行结果
 * @note
 * 入队
 * ---
 * ---
 *
 * ---
 * + **1 合法性判断**\n\n
 * **if** 容量已满 :\n
 * &emsp; 返回false\n\n
 * + **2 空队的特殊处理**\n\n
 * **if** 空队 :\n
 * &emsp; front_置为0\n\n
 * + **3 入队操作**\n\n
 * rear_值更新\n
 * mem_data_[rear_]的值设为参数data\n\n
 * + **4 退出函数**\n\n
 * 返回true\n
 *
 *
 * ---
 */
template<typename TData>
bool CircularQueue<TData>::EnQueue(const TData& data) {

    // ---------- 1 合法性判断 ----------

    if (IsFull()) {                                                                         // if 容量已满
        return false;                                                                       // 返回false
    }

    // ---------- 2 空队的特殊处理 ----------

    if (Length() == 0) {                                                                    // if 空队
        this->front_ = 0;                                                                   // front_置为0
    }

    // ---------- 3 入队操作 ----------

    this->rear_ = (this->rear_ + 1 + this->capacity_) % this->capacity_;                    // rear_值更新
    this->mem_data_[this->rear_] = data;                                                    // mem_data_[rear_]的值设为参数data

    // ---------- 4 退出函数 ----------

    return true;                                                                            // 返回true
}


/*!
 * @brief **出队(保存数据)**
 * @tparam TData 数据项类型模板参数
 * @param data 数据项保存变量
 * @return 执行结果
 * @note
 * 出队(保存数据)
 * ------------
 * ------------
 *
 * ------------
 * + **1 合法性判断**\n\n
 * **if** 空队:\n
 * &emsp; 返回false\n\n
 * + **2 取队尾值和索引处理**\n\n
 * mem_data_[front_]赋给参数data\n\n
 * **if** 队列长度为1 :\n
 * &emsp; front_置为-1\n
 * &emsp; rear_置为-1\n
 * **else**\n
 * front_值更新\n\n
 * + **3 退出函数**\n\n
 * 返回true\n
 *
 *
 * ------------
 */
template<typename TData>
bool CircularQueue<TData>::DeQueue(TData& data) {

    // ---------- 1 合法性判断 ----------

    if (IsEmpty()) {                                                                        // if 空队
        return false;                                                                       // 返回false
    }

    // ---------- 2 取队尾值和索引处理 ----------

    data = this->mem_data_[this->front_];                                                   // mem_data_[front_]赋给参数data

    if (Length() == 1) {                                                                    // if 队列长度为1
        this->front_ = -1;                                                                  // front_置为-1
        this->rear_ = -1;                                                                   // rear_置为-1
    } else {
        front_ = (front_ + 1 + capacity_) % capacity_;                                      // front_值更新
    }

    // ---------- 4 退出函数 ----------

    return true;                                                                            // 返回true
}


/*!
 * @brief **出队(保存数据)**
 * @tparam TData 数据项类型模板参数
 * @param data 数据项保存变量
 * @return 执行结果
 * @note
 * 出队(保存数据)
 * ------------
 * ------------
 *
 * ------------
 * + **1 合法性判断**\n\n
 * **if** 空队:\n
 * &emsp; 返回false\n\n
 * + **2 取队尾值和索引处理**\n\n
 * **if** 队列长度为1 :\n
 * &emsp; front_置为-1\n
 * &emsp; rear_置为-1\n
 * **else**\n
 * front_值更新\n\n
 * + **3 退出函数**\n\n
 * 返回true\n
 *
 *
 * ------------
 */
template<typename TData>
bool CircularQueue<TData>::DeQueue() {

    // ---------- 1 合法性判断 ----------

    if (IsEmpty()) {                                                                        // if 空队
        return false;                                                                       // 返回false
    }

    // ---------- 2 长度为1的队列的特殊处理 ----------

    if (Length() == 1) {                                                                    // if 队列长度为1
        this->front = -1;                                                                   // front_置为-1
        this->rear_ = -1;                                                                   // rear_置为-1
    } else {
        front_ = (front_ + 1 + capacity_) % capacity_;                                      // front_值更新
    }

    // ---------- 3 退出函数 ----------

    return true;                                                                            // 返回true
}


/*!
 * @brief **获取队头数据**
 * @tparam TData 数据项类型模板参数
 * @param data 数据项保存变量
 * @return 执行结果
 * @note
 * 获取队头数据
 * ----------
 * ----------
 *
 * ----------
 * + **1 非法情况处理**\n\n
 * **if** 空队 :\n
 * &emsp; 返回false\n\n
 * + **2 取队头数据**\n\n
 * mem_data_[front_]赋给data\n\n
 * + **3 退出函数**\n\n
 * 返回false\n
 *
 *
 * -------
 */
template<typename TData>
bool CircularQueue<TData>::Front(TData& data) const {

    // ---------- 1 非法情况处理 ----------

    if (IsEmpty()) {                                                                        // if 空队
        return false;                                                                       // 返回false
    }

    // ---------- 2 取队头数据 ----------

    data = this->mem_data_[front_];                                                         // mem_data_[front_]赋给data

    // ---------- 3 退出函数 ----------

    return true;                                                                            // 返回false
}


/*!
 * @brief **获取队尾数据**
 * @tparam TData 数据项类型模板参数
 * @param data 数据项保存变量
 * @return 执行结果
 * @note
 * 获取队尾数据
 * ----------
 * ----------
 *
 * ----------
 * + **1 非法操作处理**\n\n
 * **if** 空队 :\n
 * &emsp; 返回false\n\n
 * + **2 获取队尾数据**\n\n
 * mem_data_[rear_]赋给参数data\n\n
 * + **3 退出函数**\n\n
 * 返回true\n
 *
 *
 * -------
 */
template<typename TData>
bool CircularQueue<TData>::Rear(TData& data) const {

    // ---------- 1 非法操作处理 ----------

    if (IsEmpty()) {                                                                        // if 空队
        return false;                                                                       // 返回false
    }

    // ---------- 2 获取队尾数据 ----------

    data = this->mem_data_[rear_];                                                          // mem_data_[rear_]赋给参数data

    // ---------- 3 退出函数 ----------

    return true;                                                                            // 返回true
}


/*!
 * @brief **判断是否为空**
 * @tparam TData 数据项类型模板参数
 * @return 是否为空
 * @note
 * 判断是否为空
 * ----------
 * ----------
 *
 * ----------
 * 返回Length() == 0
 *
 *
 * -------
 */
template<typename TData>
bool CircularQueue<TData>::IsEmpty() const {
    return this->Length() == 0;
}


/*!
 * @brief **判断是否满队**
 * @tparam TData 数据项类型模板参数
 * @return 是否满队
 * @note
 * 判断是否满队
 * ----------
 * ----------
 *
 * ----------
 * 返回Length() == capacity_
 *
 *
 * -------
 */
template<typename TData>
bool CircularQueue<TData>::IsFull() const {
    return this->Length() == capacity_;
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
 * + **1 空队情况**\n\n
 * **if** rear_和front_都为-1 :\n
 * &emsp; 返回0\n\n
 * + **2 非空队情况**\n\n
 * 返回(rear_ - front_ + 1 + capacity_) % capacity_\n
 *
 *
 * -------
 */
template<typename TData>
int CircularQueue<TData>::Length() const {

    // ---------- 1 空队情况 ----------

    if (this->rear_ == -1 && this->front_ == -1) {                                          // if rear_和front_都为-1
        return 0;                                                                           // 返回0
    }

    // ---------- 2 非空队情况 ----------

    return (rear_ - front_ + 1 + capacity_) % capacity_;                                    // 返回(rear_ - front_ + 1 + capacity_) % capacity_
}


/*!
 * @brief **清空**
 * @tparam TData 数据项类型模板参数
 * @note
 * 清空
 * ---
 * ---
 *
 * ---
 * rear_和front_都设为-1
 *
 *
 * -------
 */
template<typename TData>
void CircularQueue<TData>::Clear() {
    this->rear_ = -1;
    this->front_ = -1;
}


/*!
 * @brief **重载<<**
 * @tparam TData 数据项类型模板参数
 * @param os 输出流
 * @param circular_queue 循环队列
 * @return 输出流(引用)
 * @note
 * 重载<<
 * -----
 * -----
 *
 * -----
 * 打印队列长度\n\n
 * **for loop** 遍历队列: \n
 * &emsp; 获取当前结点的数组索引\n
 * &emsp; 打印当前结点的数据项\n\n
 * 返回os\n
 *
 *
 * -------
 */
template<typename TData>
ostream& operator<<(ostream& os, const CircularQueue<TData>& circular_queue) {

    os << "The size of link queue: " << circular_queue.Length() << endl;                                        // 打印队列长度

    for (int i = 0; i < circular_queue.Length(); i++) {                                                         // for loop 遍历队列
        int actual_index = (circular_queue.front_ + i + circular_queue.capacity_) % circular_queue.capacity_;   // 获取当前结点的数组索引
        os <<  circular_queue.mem_data_[actual_index] << endl;                                                  // 打印当前结点数据项
    }

    return os;                                                                                                  // 返回os
}


#endif // CYBER_DASH_CIRCULAR_QUEUE_H
