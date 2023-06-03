/**
 * @file linked_queue.h
 * @author cyberdash@163.com(抖音: cyberdash_yuan)
 * @brief 链式实现队列
 * @version 0.2.1
 * @date 2021-07-28
 */

#ifndef CYBER_DASH_LINKED_QUEUE_H
#define CYBER_DASH_LINKED_QUEUE_H


#include <cstdlib>
#include "queue.h"
#include <iostream>


using namespace std;


/*!
 * @brief **链式队列结点模板结构体**
 * @tparam TData 数据项类型模板参数
 */
template <typename TData>
class LinkedNode {

public:
    LinkedNode() : next_(NULL) {}

    /*!
     * @brief **构造函数(下一结点)**
     * @param node 下一结点
     */
    explicit LinkedNode(LinkedNode<TData>* node = NULL) : next_(node) {}

    /**
     * @brief **构造函数(数据项,下一结点指针)**
     * @param data 数据项
     * @param node 下一结点
     */
    explicit LinkedNode(const TData& data, LinkedNode<TData>* node = NULL) : data_(data), next_(node) {}

    /**
     * @brief **获取数据项**
     * @return 数据项
     */
    TData GetData() { return data_; }

    /*!
     * @brief **设置数据项**
     * @param data 输入的结点值
     */
    void SetData(const TData& data) { data_ = data; }

    /*!
     * @brief **获取下一结点**
     * @return 返回下一结点
     */
    LinkedNode<TData>* Next() { return next_; }

    /*!
     * @brief **设置下一结点**
     * @param node 下一结点
     */
    void SetNext(LinkedNode<TData>* const& node) { next_ = node; }

private:
    TData data_;                 //!< **数据项**
    LinkedNode<TData>* next_;    //!< **下一结点**
};


template<typename TData> class LinkedQueue;
template<typename TData> ostream& operator<<(ostream& os, const LinkedQueue<TData>& linked_queue);

/**
 * @brief **链式队列模板类**
 * @tparam TData 数据项类型模板参数
 */
template<typename TData>
class LinkedQueue: public Queue<TData> {

public:
    /*! @brief **默认构造函数** */
    LinkedQueue() : front_(NULL), rear_(NULL) {}

    /*!
     * @brief **析构函数**
     * @note
     * 析构函数
     * -------
     * -------
     *
     * -------
     * 调用Clear()
     */
    ~LinkedQueue() { Clear(); }

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

    // 获取队列长度
    int Length() const;

    // 清空队列
    void Clear();

    // 重载<<(打印队列)
    friend ostream& operator<< <>(ostream& os, const LinkedQueue<TData>& linked_queue);

private:

    /*!
     * @brief **获取队头结点**
     * @return 队头结点
     * @note
     * 获取队头结点
     * ----------
     * ----------
     *
     * ----------
     * 返回front_
     */
    LinkedNode<TData>* FrontNode_() const { return this->front_; }

    /*!
     * @brief **获取队尾结点**
     * @return 队尾结点
     * @note
     * 获取队尾结点
     * ----------
     * ----------
     *
     * ----------
     * 返回rear_
     */
    LinkedNode<TData>* RearNode_() const { return this->rear_; }

    LinkedNode<TData>* front_;    //!< **队头**
    LinkedNode<TData>* rear_;     //!< **队尾**
};


/*!
 * @brief **入队**
 * @tparam TData 数据项类型模板参数
 * @param data 数据项值
 * @return 执行结果
 * @note
 * 入队
 * ---
 * ---
 *
 * ---
 * + **1 构造结点**\n
 * node初始化并分配内存\n
 * **if** 内存分配失败 :\n
 * &emsp; 抛出bad_alloc()\n\n
 * + **2 入队**\n
 * **if** 空队列 :\n
 * &emsp; front_指向node\n
 * &emsp; rear_指向node\n
 * **else**\n
 * &emsp; rear_->next指向node\n
 * &emsp; rear_指向node\n\n
 * + **3 退出函数**\n
 * 返回true\n
 */
template<typename TData>
bool LinkedQueue<TData>::EnQueue(const TData& data) {

    // ---------- 1 构造结点 ----------

    LinkedNode<TData>* node = new LinkedNode<TData>(data);          // node初始化并分配内存
    if (node == NULL) {                                             // if 内存分配失败
        throw bad_alloc();                                          // 抛出bad_alloc()
    }

    // ---------- 2 入队 ----------

    if (IsEmpty()) {                                                // if 空队列
        this->front_ = node;                                        // front_指向node
        this->rear_ = node;                                         // rear_指向node
    } else {                                                        // else
        this->rear_->SetNext(node);                                 // rear_->next指向node
        this->rear_ = node;                                         // rear_指向node
    }

    // ---------- 3 退出函数 ----------

    return true;                                                    // 返回true
}


/*!
 * @brief **出队**
 * @tparam TData 数据项类型模板参数
 * @param data 数据项保存变量
 * @return 执行结果
 * @note
 * 出队
 * ---
 * ---
 *
 * ---
 * + **1 空队处理**\n
 * **if** 空队 :\n
 * &emsp; 返回false\n\n
 * + **2 参数data赋值**\n
 * 初始化temp, 指向front_(队头)\n
 * 队头数据项赋给data\n\n
 * + **3 出队操作**\n
 * front_指向front_->next_\n
 * 释放temp\n
 * temp置NULL\n\n
 * + **4 退出函数**\n
 * 返回true\n
 */
template<typename TData>
bool LinkedQueue<TData>::DeQueue(TData& data) {

    // ---------- 1 空队处理 ----------

    if (IsEmpty()) {                                                // if 空队
        return false;                                               // 返回false
    }

    // ---------- 2 参数data赋值 ----------

    LinkedNode<TData>* temp = front_;                               // 初始化temp, 指向front_(队头)
    data = temp->GetData();                                         // 队头数据项赋给data

    // ---------- 3 出队操作 ----------

    this->front_ = this->front_->Next();                            // front_指向front_->next_

    delete temp;                                                    // 释放temp
    temp = NULL;                                                    // temp置NULL

    // ---------- 4 退出函数 ----------

    return true;                                                    // 返回true
}


/*!
 * @brief **出队(不保存数据项)**
 * @tparam TData 数据项类型模板参数
 * @return 执行结果
 * @note
 * 出队(不保存数据项)
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 空队处理**\n
 * **if** 空队 :\n
 * &emsp; 返回false\n\n
 * + **2 出队操作**\n
 * 初始化temp, 指向front_(队头)\n
 * front_指向front_->next_\n
 * 释放temp\n
 * temp置NULL\n\n
 * + **3 退出函数**\n
 * 返回true\n
 */
template<typename TData>
bool LinkedQueue<TData>::DeQueue() {

    // ---------- 1 空队处理 ----------

    if (IsEmpty()) {                                                // if 空队
        return false;                                               // 返回false
    }

    // ---------- 2 出队操作 ----------

    LinkedNode<TData>* temp = this->front_;                         // 初始化temp, 指向front_(队头)

    this->front_ = this->front_->Next();                            // front_指向front_->next_

    delete temp;                                                    // 释放temp
    temp = NULL;                                                    // temp置NULL

    // ---------- 3 退出函数 ----------

    return true;                                                    // 返回true
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
 * + **1 空队处理**\n
 * **if** 空队 :\n
 * &emsp; 返回false\n\n
 * + **2 保存队头数据**\n
 * 队头数据项赋给data\n\n
 * + **3 退出函数**\n
 * 返回true\n
 */
template<typename TData>
bool LinkedQueue<TData>::Front(TData& data) const {

    // ---------- 1 空队处理 ----------

    if (IsEmpty()) {                                                // if 空队
        return false;                                               // 返回false
    }

    // ---------- 2 保存队头数据 ----------

    data = this->front_->GetData();                                 // 队头数据项赋给data

    // ---------- 3 退出函数 ----------

    return true;                                                    // 返回true
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
 * + **1 空队处理**\n
 * **if** 空队 :\n
 * &emsp; 返回false\n\n
 * + **2 保存队尾数据**\n
 * 队尾数据项赋给data\n\n
 * + **3 退出函数**\n
 * 返回true\n
 */
template<typename TData>
bool LinkedQueue<TData>::Rear(TData& data) const {

    // ---------- 1 空队处理 ----------

    if (IsEmpty()) {                                                // if 空队
        return false;                                               // 返回false
    }

    // ---------- 2 保存队尾数据 ----------

    data = this->rear_->GetData();                                  // 队尾数据项赋给data

    // ---------- 3 退出函数 ----------

    return true;                                                    // 返回true
}


/*!
 * @brief **判断队列是否为空**
 * @tparam TData 数据项类型模板参数
 * @return 是否为空
 * @note
 * 判断队列是否为空
 * -------------
 * -------------
 *
 * -------------
 * 返回this->front_ == NULL
 */
template<typename TData>
bool LinkedQueue<TData>::IsEmpty() const {
    return this->front_ == NULL;
}


/*!
 * @brief **获取队列长度**
 * @tparam TData 数据项类型模板参数
 * @return 队列长度
 * @note
 * 获取队列长度
 * ----------
 * ----------
 *
 * ----------
 * 初始化count(队列结点数量)为0\n\n
 * **for loop** cur指向front_; cur != NULL; cur指向自身next :\n
 * &emsp; count加1\n\n
 * 返回count\n
 */
template<typename TData>
int LinkedQueue<TData>::Length() const {

    int count = 0;                                                  // 初始化count(队列结点数量)为0

    // for loop cur指向front_; cur != NULL; cur指向自身next
    for (LinkedNode<TData>* cur = this->front_; cur != NULL; cur = cur->Next()) {
        count++;                                                    // count加1
    }

    return count;                                                   // 返回count
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
 * **while loop** 当前队列不为NULL: \n
 * &emsp; 队头出队\n
 */
template<typename TData>
void LinkedQueue<TData>::Clear() {
    while (!this->IsEmpty()) {                                      // while loop 当前队列不为NULL
        this->DeQueue();                                            // 队头出队
    }
}


/*!
 * @brief **重载<<**
 * @tparam TData 数据项类型模板参数
 * @param os 输出流
 * @param linked_queue 链式队列
 * @return 输出流
 * @note
 * 重载<<
 * -----
 * -----
 *
 * -----
 * 打印队列长度\n\n
 * **for loop** 遍历队列 :\n
 * &emsp; 打印当前结点数据项\n\n
 * 返回os\n
 */
template<typename TData>
ostream& operator<<(ostream& os, const LinkedQueue<TData>& linked_queue) {

    os<<"The size of link queue: "<<linked_queue.Length()<< endl;   // 打印队列长度

    LinkedNode<TData>* cur = linked_queue.FrontNode_();

    for (int i = 1; cur != NULL; i++) {                             // for loop 遍历队列
        os << i << ":" << cur->GetData() << endl;                   // 打印当前结点数据项
        cur = cur->Next();
    }

    return os;                                                      // 返回os
}


#endif //CYBER_DASH_LINKED_QUEUE_H
