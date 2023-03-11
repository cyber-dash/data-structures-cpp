/*!
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
        next(next), prev(prev) {}

    /*!
     * @brief **构造函数(data, next和prev)**
     * @param data 数据项
     * @param next 下一结点指针
     * @param prev 上一结点指针
     */
    explicit DoublyLinkedNode(const TData& data, DoublyLinkedNode<TData>* next = NULL, DoublyLinkedNode<TData>* prev = NULL) :
        data(data), next(next), prev(prev) {}

    TData data;                       //!< 数据项
    DoublyLinkedNode<TData>* next;    //!< 下一结点
    DoublyLinkedNode<TData>* prev;    //!< 上一结点
};


/*!
 * @brief **双向链表模板类**
 * @tparam TData 数据项类型模板参数
 */
template<typename TData>
class DoublyLinkedList : public LinearList<TData> {
public:
    // 默认构造函数
    DoublyLinkedList();

    // 析构函数
    ~DoublyLinkedList();

    // 判断是否为空
    bool IsEmpty() const { return this->head_->next == head_; }

    // 插入结点
    bool Insert(int pos, const TData& data);

    // 获取结点
    DoublyLinkedNode<TData>* GetNode(int pos) const;

    // 搜索
    DoublyLinkedNode<TData>* Search(const TData& data) const;

    // 搜索(递归)
    DoublyLinkedNode<TData>* SearchRecursive(const TData& data) const;

    // 获取结点数据项
    bool GetData(int pos, TData& data) const;

    // 设置结点数据项
    bool SetData(int pos, const TData& data);

    // 删除结点
    bool Remove(int pos, TData& data);

    // 清空
    void Clear();

    // 打印
    void Print();

    /*! @brief **长度** */
    int Length() const { return this->length_; }
private:
    DoublyLinkedNode<TData>* SearchInSubListRecursive_(DoublyLinkedNode<TData>* sub_list_first_element, const TData& data) const;

    DoublyLinkedNode<TData>* head_;     //!< **头结点**
    DoublyLinkedNode<TData>* tail_;     //!< **尾结点**
    int length_;                        //!< **长度**
};


/*!
 * @brief **默认构造函数**
 * @tparam TData 数据项类型模板参数
 * @note
 * 默认构造函数
 * -----------
 * -----------
 * 
 * -----------
 * + **1 初始化头结点和尾结点**\n
 * head_分配内存并初始化\n
 * **if** 内存分配失败 :\n
 * &emsp; 抛出bad_alloc()\n\n
 * tail_分配内存并初始化\n
 * **if** 内存分配失败 :\n
 * &emsp; 抛出bad_alloc()\n\n
 * + **2 初始化头结点和尾结点**\n
 * head_的next(下一结点), 指向tail_\n
 * head_的prev(前一结点), 为NULL\n\n
 * tail_的next(下一结点), 为NULL\n
 * tail_的prev(前一结点), 指向head_\n\n
 * lenght_设为0\n
 */
template<typename TData>
DoublyLinkedList<TData>::DoublyLinkedList() {
    head_ = new DoublyLinkedNode<TData>();
    if (head_ == NULL) {
        throw bad_alloc();
    }

    tail_ = new DoublyLinkedNode<TData>();
    if (tail_ == NULL) {
        throw bad_alloc();
    }

    head_->next = tail_;
    head_->prev = NULL;

    tail_->next = NULL;
    tail_->prev = head_;

    length_ = 0;
}


/*!
 * @brief **搜索**
 * @tparam TData 数据项类型模板参数
 * @param data 搜索数据项
 * @return 结点指针
 * @note
 * 搜索
 * ----
 * ----
 * 
 * ----
 * **for loop** 遍历指针cur, 从head_->next遍历到最后一个结点 :\n
 * &emsp; **if** 当前结点data等于参数data :\n
 * &emsp;&emsp; 返回cur\n
 * return NULL(未搜索到时返回NULL)\n
 */
template<typename TData>
DoublyLinkedNode<TData>* DoublyLinkedList<TData>::Search(const TData& data) const {
    for (DoublyLinkedNode<TData>* cur = head_->next; cur != NULL; cur = cur->next) {
        if (cur->data == data) {
            return cur;
        }
    }

    return NULL;
}


/*!
 * @brief **搜索(递归)**
 * @tparam TData 数据项类型模板参数
 * @param data 搜索数据项
 * @return 结点指针
 * @note
 * 搜索(递归)
 * ---------
 * ---------
 * 
 * ---------
 * 对head_(头结点)调用SearchInSubListRecursive_, 返回结果\n
 */
template<typename TData>
DoublyLinkedNode<TData>* DoublyLinkedList<TData>::SearchRecursive(const TData &data) const {

    DoublyLinkedNode<TData>* node = SearchInSubListRecursive_(head_, data);

    return node;
}


/*!
 * @brief **子链表搜索(递归)**
 * @tparam TData 数据项类型模板参数
 * @param sub_list_first_element 子链表首个元素结点
 * @param data 搜索数据项
 * @return 结点指针
 * @note
 * 子链表搜索(递归)
 * --------------
 * --------------
 * 
 * --------------
 * + **1 空链表处理**\n
 * **if** 子链表首个结点为NULL :\n
 * &emsp; 返回NULL\n\n
 * + **2 子链表首个元素结点既是搜索结点的处理**\n
 * **if** 子链表首个元素结点的数据项 == data :\n
 * &emsp; 返回该结点(指针)\n\n
 * + **3 递归搜索**\n
 * 对sub_list_first_element->next(子链表首个元素结点的下一结点)递归调用SearchInSubListRecursive_, 返回结果\n
 */
template<typename TData>
DoublyLinkedNode<TData>* DoublyLinkedList<TData>::SearchInSubListRecursive_(DoublyLinkedNode<TData>* sub_list_first_element,
                                                                            const TData& data) const
{
    if (sub_list_first_element == NULL) {
        return NULL;
    }

    if (sub_list_first_element->data == data) {
        return sub_list_first_element;
    }

    return SearchInSubListRecursive_(sub_list_first_element->next, data);
}


/*!
 * @brief **插入结点**
 * @tparam TData 数据项类型模板参数
 * @param pos 插入位置的前一位置
 * @param data 插入数据项
 * @return 执行结果
 * @note
 * 插入结点
 * -------
 * -------
 * 
 * -------
 * + **1 非法位置处理**\n
 * **if** pos > 链表长度 || pos < 0 :\n
 * &emsp; 返回false\n\n
 * + **2 构造插入结点**\n
 * 分配内存并初始化insertion_node(插入结点)\n
 * **if** 内存分配失败 :\n
 * &emsp; 返回false\n\n
 * + **3 插入**\n
 * <span style="color:#003153">3.1 遍历至pos位置(插入位置前一位置)\n</span>
 * 初始化cur(遍历指针)指向head_(头结点)\n
 * **while loop** pos > 0 :\n
 * &emsp; cur指向下一结点\n
 * &emsp; pos减1\n\n
 * <span style="color:#003153">3.2 插入\n</span>
 * 插入结点的next, 指向插入结点的前一结点的next\n
 * 插入结点的前一结点的next, 指向插入结点\n\n
 * 插入结点的下一结点的prev, 指向插入结点\n
 * 插入结点的prev, 指向插入结点的前一结点\n\n
 * <span style="color:#003153">3.3 调整长度\n</span>
 * length_加1\n\n
 * + **4 返回**\n
 * 返回true\n
 */
template<typename TData>
bool DoublyLinkedList<TData>::Insert(int pos, const TData& data) {
    if (pos > length_ || pos < 0) {
        return false;
    }

    DoublyLinkedNode<TData>* insertion_node = new DoublyLinkedNode<TData>(data);
    if (!insertion_node) {
        return false;
    }

    DoublyLinkedNode<TData>* cur = head_;
    while (pos > 0) {
        cur = cur->next;
        pos--;
    }

    insertion_node->next = cur->next;
    cur->next = insertion_node;

    insertion_node->next->prev = insertion_node;
    insertion_node->prev = cur;

    length_++;

    return true;
}


/*!
 * @brief **获取结点**
 * @tparam TData 数据项类型模板参数
 * @param pos 位置
 * @return 结点指针
 * @note
 * 获取结点
 * -------
 * -------
 *
 * -------
 * + **1 非法位置处理**\n
 * **if** pos < 1 || pos > 链表长度 :\n
 * &emsp; 返回NULL\n
 * + **2 遍历至pos位置结点**\n
 * 初始化cur(遍历指针), 指向head_->next\n
 * **for loop** 1至pos :\n
 * &emsp; cur指向cur的next结点\n
 * + **3 返回结果**\n
 * 返回cur\n
 */
template<typename TData>
DoublyLinkedNode<TData>* DoublyLinkedList<TData>::GetNode(int pos) const {
    if (pos < 1 || pos > Length()) {
        return NULL;
    }

    DoublyLinkedNode<TData>* cur = head_->next;
    for (int i = 1; i < pos; i++) {
        cur = cur->next;
    }

    return cur;
}


/*!
 * @brief **获取结点数据项**
 * @tparam TData 数据项类型模板参数
 * @param pos 位置
 * @param data 数据项保存变量
 * @return 执行结果
 * @note
 * 获取结点数据项
 * -----------
 * -----------
 *
 * -----------
 * + **1 非法位置处理**\n
 * **if** pos < 1 || pos > 链表长度 :\n
 * &emsp; 返回NULL\n
 * + **2 遍历至pos位置结点**\n
 * 初始化cur(遍历指针), 指向head_->next\n
 * **for loop** 1至pos :\n
 * &emsp; cur指向cur的next结点\n
 * + **3 取值**\n
 * 取cur->data值, 赋给参数data\n
 * + **4 退出函数**\n
 * 返回true\n
 */
template<typename TData>
bool DoublyLinkedList<TData>::GetData(int pos, TData& data) const {
    if (pos < 1 || pos > Length()) {
        return false;
    }

    DoublyLinkedNode<TData>* cur = head_->next;
    for (int i = 1; i < pos; i++) {
        cur = cur->next;
    }

    data = cur->data;

    return true;
}


/*!
 * @brief **设置数据项**
 * @tparam TData 类型模板参数
 * @param pos 位置
 * @param data 数据项
 * @return 执行结果
 * @note
 * 设置数据项
 * --------
 * --------
 *
 * --------
 * + **1 非法位置处理**\n
 * **if** pos < 1 || pos > 链表长度 :\n
 * &emsp; 返回NULL\n
 * + **2 遍历至pos位置结点**\n
 * 初始化cur(遍历指针), 指向head_(头结点)\n
 * **for loop** 1至pos :\n
 * &emsp; cur指向cur的next结点\n
 * + **3 赋值**\n
 * data赋给cur->data\n
 * + **4 退出函数**\n
 * 返回true\n
 */
template<typename TData>
bool DoublyLinkedList<TData>::SetData(int pos, const TData& data) {
    if (pos < 1 || pos > Length()) {
        return false;
    }

    DoublyLinkedNode<TData>* cur = head_;
    for (int i = 1; i < pos; i++) {
        cur = cur->next;
    }

    cur->data = data;

    return true;
}


/*!
 * @brief **删除结点**
 * @tparam TData 数据项类型模板参数
 * @param pos 位置
 * @param data 数据项保存变量
 * @return 执行结果
 * @note
 * 删除结点
 * -------
 * -------
 *
 * -------
 * + **1 非法位置处理**\n
 * **if** pos < 0 || pos > 链表长度 :\n
 * &emsp; 返回false\n\n
 * + **2 遍历到待删除结点**\n
 * 调用GetNode获取待删除结点(指针)deletion_node\n\n
 * + **3 删除**\n
 * <span style="color:#003153">3.1 调整指针\n</span>
 * 待删除结点的next(下一结点), 指向待删除结点的prev(前一结点)\n
 * 待删除结点的prev(前一结点), 指向待删除结点的next(下一结点)\n\n
 * <span style="color:#003153">3.2 取待删除结点的数据项\n</span>
 * 取待删除结点的data, 赋给参数data\n\n
 * <span style="color:#003153">3.3 释放内存\n</span>
 * 释放deletion_node\n
 * deletion_node置NULL\n\n
 * + **4 长度调整**\n
 * length_减1\n\n
 * + **4 退出函数**\n
 * 返回true\n
 */
template<typename TData>
bool DoublyLinkedList<TData>::Remove(int pos, TData& data) {

    if (pos > Length() || pos < 0) {
        return false;
    }

    DoublyLinkedNode<TData>* deletion_node = this->GetNode(pos);

    deletion_node->next->prev = deletion_node->prev;
    deletion_node->prev->next = deletion_node->next;

    data = deletion_node->data;

    delete deletion_node;
    deletion_node = NULL;

    length_--;

    return true;
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
 * **for loop** 遍历length_次 :\n
 * &emsp; 删除位置1的结点\n
 */
template<typename TData>
void DoublyLinkedList<TData>::Clear() {
    for (int pos = 1; pos <= length_; pos++) {
        TData deletion_data;
        this->Remove(1, deletion_data);
    }
}


/*!
 * @brief **打印**
 * @tparam TData 数据项类型模板参数
 * @note
 * 打印
 * ---
 * ---
 *
 * ---
 * + **1 空链表处理**\n
 * **if** 空链表 :\n
 * &emsp; 打印"Empty list"\n
 * &emsp; 退出函数\n\n
 * + **2 打印**\n
 * 初始化cur(遍历指针), 指向head_->next\n
 * **for loop** 位置从1到length_ :\n
 * &emsp; 打印当前结点的data\n
 * &emsp; **if** 不是最后一个结点: \n
 * &emsp;&emsp; 打印 "<-->"\n
 * &emsp; cur指向cur->next\n
 */
template<typename TData>
void DoublyLinkedList<TData>::Print() {
    if (this->length_ == 0) {
        cout << "Empty list" << endl;
        return;
    }

    cout << "打印循环单链表: { ";
    DoublyLinkedNode<TData>* cur = this->head_->next;
    for (int pos = 1; pos <= Length(); pos++) {
        cout << cur->data;
        if (pos != Length()) {
            cout << "<-->";
        }
        cur = cur->next;
    }
    cout << " }" << endl;
}


#endif // CYBER_DASH_DOUBLY_LINKED_LIST_H
