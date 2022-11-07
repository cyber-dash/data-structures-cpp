/*!
 * @file linked_list.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 单向链表模板类
 * @version 0.2.1
 * @date 2020-06-06
 * @copyright Copyright (c) 2021
 * **CyberDash计算机考研**
 */

#ifndef CYBER_DASH_LINKED_LIST_H
#define CYBER_DASH_LINKED_LIST_H


#include <iostream>
#include <cstddef>
#include "linear_list.h"


using namespace std;


/*!
 * @brief **单链表结点模板结构体**
 * @tparam TData 数据项类型模板参数
 */
template <typename TData>
struct LinkedNode {
    /*!
     * @brief **构造函数(下一结点地址)**
     * @param node 下一结点
     */
    explicit LinkedNode(LinkedNode<TData>* node = NULL) { this->next = node; }

    /*!
     * @brief **构造函数(数据项和下一结点地址)**
     * @param data 数据项
     * @param ptr 下一结点
     */
    explicit LinkedNode(const TData& data, LinkedNode<TData>* node = NULL) {
        this->data = data;
        this->next = node;
    }

    TData data;                 //!< 链表数据项
    LinkedNode<TData>* next;    //!< 下一结点
};


/*!
 * @brief **单链表模板类**
 * @tparam TData 数据项类型模板参数
 */
template<typename TData>
class LinkedList : public LinearList<TData> {
public:
    // 构造函数(无参数)
    LinkedList();
    // 复制构造函数
    LinkedList(const LinkedList<TData>& link_list);
    // 析构函数
    ~LinkedList();
    // 清除链表
    void Clear();
    /*! @brief 链表长度 */
    int Length() const { return this->length_; }
    /*! @brief 链表头结点 */
    LinkedNode<TData>* Head() const { return this->head_; }
    // 搜索
    LinkedNode<TData>* Search(TData data);
    // 查找
    LinkedNode<TData>* Find(int pos);
    // 获取结点数据
    bool GetData(int pos, TData& data) const;
    // 设置结点数据
    bool SetData(int pos, const TData& data);
    // 在第pos个元素(数组索引pos - 1)之后, 插入数据
    bool Insert(int pos, const TData& data);
    // 在第pos个元素(数组索引pos - 1)之后, 插入结点
    bool Insert(int pos, LinkedNode<TData>* node);
    // 删除结点
    bool Remove(int pos, TData& data);
    // 是否为空链表
    bool IsEmpty() const;
    // 打印链表
    void Print();
    // 我们是CyberDash
    void CyberDashShow();

private:
    LinkedNode<TData>* head_; //!< 链表头结点
    int length_; //!< 链表长度
};


/*!
 * @brief 构造函数(无参数)
 * @tparam TData 类型参数模板
 */
template<typename TData>
LinkedList<TData>::LinkedList() {
    this->head_ = new LinkedNode<TData>();
    /* error handler */
    this->length_ = 0;
};


/*!
 * @brief 复制构造函数
 * @tparam TData 类型模板参数
 * @param link_list 链表引用
 */
template<typename TData>
LinkedList<TData>::LinkedList(const LinkedList<TData>& link_list) {

    this->head_ = new LinkedNode<TData>();
    LinkedNode<TData>* dest_list_cur = this->Head();

    LinkedNode<TData>* src_list_cur = link_list.Head();

    while (src_list_cur->next != NULL) {

        TData data = src_list_cur->next->data;
        dest_list_cur->next = new LinkedNode<TData>(data);

        dest_list_cur = dest_list_cur->next;
        src_list_cur = src_list_cur->next;

        length_++;
    }

    dest_list_cur->next = NULL;
}


/*!
 * @brief 析构函数
 * @tparam TData
 */
template<typename TData>
LinkedList<TData>::~LinkedList() {
    this->Clear();

    delete this->head_;
    this->head_ = NULL;
}


/*!
 * @brief **获取结点数据**
 * @tparam TData 数据项类型模板参数
 * @param pos 结点位置
 * @param data 数据保存变量
 * @return 执行结果
 * @note
 * 获取结点数据
 * -----------
 * -----------
 *
 * -----------
 */
template<typename TData>
bool LinkedList<TData>::GetData(int pos, TData& data) const {

    if (pos < 1 || pos > this->Length()) {
        return false;
    }

    LinkedNode<TData>* cur = this->head_;

    while (pos > 0) {
        cur = cur->next;
        pos--;
    }

    data = cur->data;

    return true;
}


/*!
 * @brief **设置结点数据**
 * @tparam TData 数据项类型模板参数
 * @param pos 结点位置
 * @param data 数据
 * @return 执行结果
 * @note
 * 设置结点数据
 * -----------
 * -----------
 *
 * -----------
 */
template<typename TData>
bool LinkedList<TData>::SetData(int pos, const TData& data) {

    if (pos < 1 || pos > Length()) {
        return false;
    }

    LinkedNode<TData>* cur = this->head_;

    while (pos > 0) {
        cur = cur->next;
        pos--;
    }

    cur->data = data;

    return true;
}


/*!
 * @brief **清除链表**
 * @tparam TData 数据项类型模板参数
 * @note
 * 清除链表
 * -------
 * -------
 *
 * <span style="color:#FF8100">
 * 保留head结点, 删除其他所有结点
 * </span>
 *
 * -------
 * **while** head_->next存在 :\n
 * &emsp; **I**&nbsp;&nbsp; head_->next指向head_->next->next\n
 * &emsp;&emsp; 声明指针cur, 指向head_->next\n
 * &emsp;&emsp; head_->next指向cur->next\n
 * &emsp; **II**&nbsp; 删除head_->next\n
 * &emsp;&emsp; 释放cur指向的结点\n
 * &emsp; **III** 调整链表长度\n
 * &emsp;&emsp; 链表长度减1\n
 */
template<typename TData>
void LinkedList<TData>::Clear() {

    while (this->head_->next != NULL) {

        LinkedNode<TData>* cur = this->head_->next;
        this->head_->next = cur->next;

        delete cur;

        this->length_--;
    }
}


/*!
 * @brief **打印链表**
 * @tparam TData 类型模板参数
 * @note
 * 打印链表
 * -------
 * -------
 *
 * -------
 */
template<typename TData>
void LinkedList<TData>::Print() {

    if (this->head_->next == NULL) {
        cout << "Empty list" << endl;
        return;
    }

    LinkedNode<TData>* cur = Head()->next;
    while (cur != NULL) {
        cout << cur->data << " ";
        cur = cur->next;
    }

    cout << endl;
}


/*!
 * @brief 插入(数据)
 * @tparam TData 数据项类型模板参数
 * @param pos 位置
 * @param data 数据项值
 * @return 执行结果
 * @note
 * 插入(数据)
 * ---------
 * ---------
 *
 * <span style="color:#FF8100">
 * 在位置pos后插入, 作为pos + 1位置的数据\n
 * pos + 1和其后的数据的所有位置加1\n
 * 从1开始, 区别从0开始\n
 * </span>
 *
 * ---------
 * **I&nbsp;&nbsp; 非法位置处理**\n
 * **II&nbsp; 插入空节点处理**\n
 * **III 遍历至插入位置**\n
 * **IV 执行插入**\n
 * **V&nbsp; 调整链表长度**\n
 */
template<typename T>
bool LinkedList<T>::Insert(int pos, const T& data) {

    if (pos < 0 || pos > Length()) {
        return false;
    }

    LinkedNode<T>* node = new LinkedNode<T>(data);

    LinkedNode<T>* cur = this->head_;
    while (pos > 0) {
        cur = cur->next;
        pos--;
    }

    node->next = cur->next;
    cur->next = node;

    this->length_++;

    return true;
}


/*!
 * @brief **插入(结点)**
 * @tparam TData 数据项类型模板参数
 * @param pos 位置pos
 * @param node 结点
 * @return 执行结果
 * @note
 * 插入(结点)
 * ---------
 * ---------
 *
 * <span style="color:#FF8100">
 * 在位置pos后插入, 作为pos + 1位置的数据\n
 * pos + 1和其后的数据的所有位置加1\n
 * 从1开始, 区别从0开始\n
 * </span>
 *
 * ---------
 * **I&nbsp;&nbsp; 非法位置处理**\n
 * **II&nbsp; 插入空节点处理**\n
 * **III 遍历至插入位置**\n
 * **IV 执行插入**\n
 * **V&nbsp; 调整链表长度**\n
 */
template<typename TData>
bool LinkedList<TData>::Insert(int pos, LinkedNode<TData>* node) {

    if (pos < 0 || pos > this->Length()) {
        return false;
    }

    if (node == NULL) {
        return false;
    }

    LinkedNode<TData>* cur = this->head_;
    while (pos > 0) {
        cur = cur->next;
        pos--;
    }

    node->next = cur->next;
    cur->next = node;

    this->length_++;

    return true;
}


/*!
 * @brief **是否为空链表**
 * @tparam TData 数据项类型模板参数
 * @return 结果
 * @note
 * 是否为空链表
 * -----------
 * -----------
 *
 * <span style="color:#FF8100">
 * It's a long road, when you face the world alone
 * </span>
 *
 * -----------
 * **if** head_->next为NULL:\n
 * &emsp; 则为空链表\n
 * **else**\n
 * &emsp; 不是空链表\n
 */
template<typename TData>
bool LinkedList<TData>::IsEmpty() const {
    if (this->Head()->next == NULL) {
        return true;
    } else {
        return false;
    }
}


/*!
 * @brief **搜索**
 * @tparam TData 数据项类型模板参数
 * @param data 搜索数据
 * @return 搜索结果
 * @note
 * 搜索
 * --------------------
 * --------------------
 *
 * <span style="color:#FF8100">
 * 时间复杂度O(1)
 * </span>
 *
 * --------------------
 * **I&nbsp;&nbsp; 初始化遍历指针**\n
 * &emsp; 声明遍历指针cur, 并初始化指向head_->next\n
 * &emsp; **if** cur为NULL:\n
 * &emsp;&emsp; 返回NULL\n
 * **II&nbsp; 遍历链表进行搜索**\n
 * &emsp; **while** cur不为NULL:\n
 * &emsp;&emsp; **if** cur->data等于搜索数据项:\n
 * &emsp;&emsp;&emsp; 搜索到相应数据, 跳出循环\n
 * &emsp;&emsp; cur指向cur->next\n
 * **III 返回搜索结果**\n
 */
template<typename TData>
LinkedNode<TData>* LinkedList<TData>::Search(TData data) {

    // ----- I 初始化遍历指针 -----
    LinkedNode<TData>* cur = this->head_->next; // 声明遍历指针cur, 并初始化指向head_->next
    if (cur == NULL) {  // if cur为NULL:
        return NULL;    // 返回NULL
    }

    // ----- II 遍历链表进行搜索 -----
    while (cur != NULL) {           // while cur不为NULL:
        if (cur->data == data) {    // if cur->data等于搜索数据项:
            break;                  // 搜索到相应数据, 跳出循环
        }

        cur = cur->next;    // cur指向cur->next
    }

    // ----- III 返回搜索结果 -----
    return cur;
}


/*!
 * @brief **查找位置pos的结点**
 * @tparam TData 数据项类型模板结点
 * @param pos 位置
 * @return 结点指针
 * @note
 * 寻找位置pos的结点
 * ---------------
 * ---------------
 *
 * ---------------
 */
template<typename TData>
LinkedNode<TData>* LinkedList<TData>::Find(int pos) {
    if (pos < 1 || pos > this->Length()) {
        return NULL;
    }

    LinkedNode<TData>* cur = this->Head();
    for (int i = 1; i <= pos; i++) {
        cur = cur->next;
    }

    return cur;
}


/*!
 * @brief 删除第pos个结点
 * @tparam TData 类型模板参数
 * @param pos 第pos个
 * @param data 数据(用于保存被删除结点数据项)
 * @return 是否删除成功
 * @note
 * 从1开始计数
 */
template<typename TData>
bool LinkedList<TData>::Remove(int pos, TData& data) {

    if (this->Length() == 0 || pos < 1 || pos > this->Length()) {
        return false;
    }

    LinkedNode<TData>* cur = this->head_;

    for (int i = 1; i < pos; i++) {
        cur = cur->next;
    }

    LinkedNode<TData>* delete_node_ptr = cur->next;
    cur->next = delete_node_ptr->next;

    data = delete_node_ptr->data;
    this->length_--;

    if (delete_node_ptr != NULL) {
        delete delete_node_ptr;
    }

    return true;
}


#endif // CYBER_DASH_LINKED_LIST_H
