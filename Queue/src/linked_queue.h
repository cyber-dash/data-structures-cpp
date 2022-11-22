/**
 * @file link_queue.h
 * @author cyberdash@163.com(抖音: cyberdash_yuan)
 * @brief 链表实现队列
 * @version 0.2.1
 * @date 2021-07-28
 */

#ifndef CYBER_DASH_LINK_QUEUE_H
#define CYBER_DASH_LINK_QUEUE_H


#include <cstdlib>
#include "queue.h"
#include <iostream>


using namespace std;


/*!
 * @brief 链表队列结点模板结构体
 * @tparam TData 数据项类型模板参数
 */
template <class TData>
class LinkedNode {

public:
    LinkedNode() : next_(NULL) {}
    /*!
     * @brief 构造函数(下一结点指针)
     * @param node 下一结点指针
     */
    explicit LinkedNode(LinkedNode<TData>* node = NULL) : next_(node) {}

    /**
     * @brief 构造函数(数据项&下一结点指针)
     * @param data 数据项
     * @param node 下一结点指针
     */
    explicit LinkedNode(const TData& data, LinkedNode<TData>* node = NULL) : data_(data), next_(node) {}

    /**
     * @brief 获取当前结点值
     * @return TData 类型模板参数
     */
    TData GetData() { return data_; }

    /*!
     * @brief 设置当前结点值
     * @param data 输入的结点值
     * @return 是否成功
     */
    void SetData(const TData& data) { data_ = data; }

    /*!
     * @brief 获取下一结点
     * @return LinkedNode<TData>* 返回下一结点
     */
    LinkedNode<TData>* Next() { return next_; }

    /*!
     * @brief 设置下一结点
     * @param node 下一结点指针
     * @return 是否成功
     */
    void SetNext(LinkedNode<TData>* const& node) { next_ = node; }

private:
    TData data_; //!< 结点数据项
    LinkedNode<TData>* next_; //!< 下一结点
};


/**
 * @brief 链表队列模板类
 * @tparam TData 类型模板参数
 */
template <typename TData>
class LinkedQueue : public Queue<TData> {

public:
    /*! @brief 默认构造函数 */
    LinkedQueue() : front_(NULL), rear_(NULL) {}

    /*! @brief 析构函数 */
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
    template<typename TData>
    friend ostream& operator<<(ostream& os, const LinkedQueue<TData>& linked_queue);

private:

    /*!
     * @brief 获取队头结点指针
     * @return 队头结点指针
     */
    LinkedNode<TData>* FrontNode_() const { return this->front_; }

    /*!
     * @brief 获取队尾结点指针
     * @return LinkedNode<TData>* 队尾结点指针
     */
    LinkedNode<TData>* RearNode_() const { return this->rear_; }

    LinkedNode<TData>* front_; //!< 队头指针
    LinkedNode<TData>* rear_; //!< 队尾指针
};


/*!
 * @brief 入队
 * @tparam TData 类型模板参数
 * @param data 数据
 * @return 是否成功
 */
template<class TData>
bool LinkedQueue<TData>::EnQueue(const TData& data) {

    LinkedNode<TData>* node = new LinkedNode<TData>(data);
    if (node == NULL) {
        return false;
    }

    if (IsEmpty()) {
        this->front_ = node;
        this->rear_ = node;
    } else {
        this->rear_->SetNext(node);
        this->rear_ = node;
    }

    return true;
}


/*!
 * @brief 出队(保存数据)
 * @tparam TData 类型模板参数
 * @param data 数据(保存出队结点的数据项)
 * @return 是否出队成功
 */
template<class TData>
bool LinkedQueue<TData>::DeQueue(TData& data) {

    if (IsEmpty()) {
        return false;
    }

    LinkedNode<TData>* temp = front_;

    data = temp->GetData();
    this->front_ = this->front_->Next();

    delete temp;
    temp = NULL;

    return true;
}


/*!
 * @brief 出队(不保存数据)
 * @tparam TData 类型模板参数
 * @param data 数据(保存出队结点的数据项)
 * @return 是否出队成功
 */
template<class TData>
bool LinkedQueue<TData>::DeQueue() {

    if (IsEmpty()) {
        return false;
    }

    LinkedNode<TData>* temp = this->front_;

    this->front_ = this->front_->Next();

    delete temp;
    temp = NULL;

    return true;
}


/*!
 * @brief 获取队头数据
 * @tparam TData 类型模板参数
 * @param data 数据(用于保存队头数据项)
 * @return 是否成功
 */
template<class TData>
bool LinkedQueue<TData>::Front(TData& data) const {

    if (IsEmpty()) {
        return false;
    }

    data = this->front_->GetData();

    return true;
}


/*!
 * @brief 获取队尾数据
 * @tparam TData 类型模板参数
 * @param data 数据(用于保存数据项)
 * @return 是否成功
 */
template<class TData>
bool LinkedQueue<TData>::Rear(TData& data) const {

    if (IsEmpty()) {
        return false;
    }

    data = this->rear_->GetData();

    return true;
}


/*!
 * @brief 判断队列是否为空
 * @tparam TData 类型模板参数
 * @return 是否为空
 */
template<typename TData>
bool LinkedQueue<TData>::IsEmpty() const {
    if (this->front_ == NULL) {
        return true;
    }
    else {
        return false;
    }
}


/*!
 * @brief 获取队列长度
 * @tparam TData 类型模板参数
 * @return 队列长度
 */
template<typename TData>
int LinkedQueue<TData>::Length() const {

    int count = 0;

    for (LinkedNode<TData>* cur = this->front_; cur != NULL; cur = cur->Next()) {
        count++;
    }

    return count;
}


/*!
 * @brief 清空队列
 * @tparam TData 类型模板参数
 */
template<typename TData>
void LinkedQueue<TData>::Clear() {
    while (!this->IsEmpty()) {
        this->DeQueue();
    }
}


/*!
 * @brief 重载<<(打印队列)
 * @tparam TData 类型模板参数
 * @param os 输出流
 * @param linked_queue 链表队列
 * @return 输出流
 */
template<typename TData>
ostream& operator<<(ostream& os, const LinkedQueue<TData>& linked_queue) {

    os << "The size of link queue: " << linked_queue.Length() << endl;

    LinkedNode<TData>* cur = linked_queue.FrontNode_();

    for (int i = 1; cur != NULL; i++) {
        os << i << ":" << cur->GetData() << endl;
        cur = cur->Next();
    }

    return os;
}


#endif //CYBER_DASH_LINK_QUEUE_H
