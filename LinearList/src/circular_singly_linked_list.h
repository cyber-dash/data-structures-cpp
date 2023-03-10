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
    CircularSinglyLinkedList(): length_(0), first_(NULL), last_(NULL) {}

    // 析构函数
    ~CircularSinglyLinkedList();

    /*! @brief **长度** */
    int Length() const { return this->length_; }

    /*! @brief **判断链表是否为空** */
    bool IsEmpty() const { return this->first_ == NULL; }

    // 清空链表
    void Clear();

    // 搜索
    CircularSinglyLinkedNode<TData>* Search(const TData& data);

    // 定位
    CircularSinglyLinkedNode<TData>* GetNode(int pos);

    bool Insert(int pos, const TData& data);

    bool Remove(int pos, TData& data);

    // 获取结点数据
    bool GetData(int pos, TData& data) const;

    // 设置结点数据
    bool SetData(int pos, const TData& data);

    // 打印双向链表
    void Print();

private:
    CircularSinglyLinkedNode<TData>* first_;
    CircularSinglyLinkedNode<TData>* last_;
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
 * **III first_和last_置空 **\n
 * **IV 长度调整 **\n
 */
template<typename TData>
void CircularSinglyLinkedList<TData>::Clear() {
    // ----- I 空链表处理 -----
    if (this->first_ == NULL) {
        return;
    }

    // ----- II 遍历并删除各个结点 -----
    for (int i = 1; i <= length_; i++) {
        CircularSinglyLinkedNode<TData>* temp = this->first_;
        this->first_ = temp->next;

        delete temp;
        temp = NULL;
    }

    // ----- III first_和last_置空 -----
    this->first_ = NULL;
    this->last_ = NULL;

    // ----- IV 长度调整 -----
    this->length_ = 0;
}


template<typename TData>
CircularSinglyLinkedNode<TData>* CircularSinglyLinkedList<TData>::Search(const TData& data) {

    CircularSinglyLinkedNode<TData>* cur = first_;
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

    CircularSinglyLinkedNode<TData>* cur = first_;

    for (int i = 1; i < pos; i++) {
        cur = cur->next;
    }

    return cur;
}


template<typename TData>
bool CircularSinglyLinkedList<TData>::Insert(int pos, const TData& data) {
    if (pos > Length() || pos < 0) {
        return false;
    }

    CircularSinglyLinkedNode<TData>* node = new CircularSinglyLinkedNode<TData>(data);
    if (node == NULL) {     // if 生成结点失败
        return false;       // 返回false
    }

    if (length_ == 0) {
        first_ = node;
        first_->next = first_;

        last_ = first_;

        length_ = 1;

        return true;
    }

    CircularSinglyLinkedNode<TData>* cur = first_;
    for (int i = 1; i < pos; i++) {
        cur = cur->next;
    }

    node->next = cur->next;     // node->next指向cur->next
    cur->next = node;           // cur->next指向node

    // 如果插入结点的next指向了first_, 则将其设置为last_
    if (node->next == first_) {
        last_ = node;
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
 * 如果删除first_结点, 则新的first_结点为原first_结点的next(如果原first_->next不为自身)
 * ------------
 * **1 非法位置处理**\n
 * **if** pos < 0 或者 pos > 链表长度:\n
 * &emsp; 返回false\n
 * **2 链表长度为1的情况**\n
 * **if** 链表长度为1\n
 * &emsp; (此时, first_/last_指向唯一结点)\n
 * &emsp; first_->data赋给参数data\n
 * &emsp; 释放first_并置NULL\n
 * &emsp; last_置NULL\n
 * &emsp; 长度置0\n
 * **3 删除first_结点的情况**\n
 * **if** pos等于1(删除first_结点):\n
 * first_->data赋给参数data\n
 * 声明指针deletion_node指向首元素结点\n
 * last_->next指向first_->next\n
 * first_指向first_->next
 * 释放deletion_node\n
 * 链表长度减1\n
 * 返回true\n
 * **4 其他情况**\n
 * **5 退出函数**\n
 */
template<typename TData>
bool CircularSinglyLinkedList<TData>::Remove(int pos, TData& data) {
    // ----- I 错误位置处理 -----
    if (pos < 0 || pos > length_) {
        return false;
    }

    // ----- II 只有一个结点的情况 -----
    if (Length() == 1) {
        data = first_->data;

        delete first_;
        first_ = NULL;
        last_ = NULL;

        length_ = 0;

        return true;
    }

    // ----- III 删除first_结点的情况 -----
    if (pos == 1) {
        data = first_->data;

        CircularSinglyLinkedNode<TData>* deletion_node = first_;

        last_->next = first_->next;
        first_ = first_->next;

        delete deletion_node;
        deletion_node = NULL;

        length_--;

        return true;
    }

    // ----- IV 其他情况 -----
    CircularSinglyLinkedNode<TData>* cur = first_;
    for (int i = 1; i < pos - 1; i++) {
        cur = cur->next;
    }

    // 删除cur->next
    if (cur->next == last_) {
        last_ = cur;
    }

    data = cur->next->data;

    CircularSinglyLinkedNode<TData>* deletion_node = cur->next;
    cur->next = cur->next->next;

    delete deletion_node;
    deletion_node = NULL;

    // ----- V 长度调整 -----
    length_--;

    return true;
}


template<typename TData>
void CircularSinglyLinkedList<TData>::Print() {

    if (this->first_ == NULL) {
        cout << "Empty list" << endl;
        return;
    }

    cout << "打印循环单链表: { ";
    CircularSinglyLinkedNode<TData>* cur = this->first_;
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

    CircularSinglyLinkedNode<TData>* cur = first_;
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

    CircularSinglyLinkedNode<TData>* cur = first_;
    for (int i = 1; i < pos; i++) {
        cur = cur->next;
    }

    cur->data = data;

    return true;
}


#endif // CYBER_DASH_CIRCULAR_SINGLY_LINKED_LIST_H
