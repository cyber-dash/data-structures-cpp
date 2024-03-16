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


/*!
 * @brief **双向链表结点模板结构体**
 * @tparam TData 数据项类型模板参数
 * @note
 * 双向链表结点模板结构体
 * -------------------
 * -------------------
 *
 * -------------------
 */
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

    TData data;                       //!< **数据项**
    DoublyLinkedNode<TData>* next;    //!< **下一结点**
    DoublyLinkedNode<TData>* prev;    //!< **上一结点**
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

    /*!
     * @brief **判断是否为空链表**
     * @return 是否为空链表
     */
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
    // 子链表搜索(递归)
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
 * + **1 初始化头结点和尾结点**\n\n
 * head_分配内存并初始化\n
 * **if** 内存分配失败 :\n
 * &emsp; 抛出bad_alloc()\n\n
 * tail_分配内存并初始化\n
 * **if** 内存分配失败 :\n
 * &emsp; 抛出bad_alloc()\n\n
 * + **2 初始化头结点和尾结点**\n\n
 * head_的next(下一结点), 指向tail_\n
 * head_的prev(前一结点), 为NULL\n\n
 * tail_的next(下一结点), 为NULL\n
 * tail_的prev(前一结点), 指向head_\n\n
 * length_设为0\n
 *
 *
 * -----------
 */
template<typename TData>
DoublyLinkedList<TData>::DoublyLinkedList() {

    // ---------- 1 初始化头结点和尾结点 ----------

    head_ = new DoublyLinkedNode<TData>();                                              // head_分配内存并初始化
    if (head_ == NULL) {                                                                // if 内存分配失败
        throw bad_alloc();                                                              // 抛出bad_alloc()
    }

    tail_ = new DoublyLinkedNode<TData>();                                              // tail_分配内存并初始化
    if (tail_ == NULL) {                                                                // if 内存分配失败
        throw bad_alloc();                                                              // 抛出bad_alloc()
    }

    // ---------- 2 初始化头结点和尾结点 ----------

    head_->next = tail_;                                                                // head_的next(下一结点), 指向tail_
    head_->prev = NULL;                                                                 // head_的prev(前一结点), 为NULL

    tail_->next = NULL;                                                                 // tail_的next(下一结点), 为NULL
    tail_->prev = head_;                                                                // tail_的prev(前一结点), 指向head_

    length_ = 0;                                                                        // length_设为0
}


/*!
 * @brief **析构函数**
 * @tparam TData 数据项类型模板参数
 * @note
 * 析构函数
 * ------
 * ------
 *
 * ------
 * 调用Clear()\n
 *
 *
 * ------
 */
template<typename TData>
DoublyLinkedList<TData>::~DoublyLinkedList() {
    this->Clear();
    delete this->head_;
    delete this->tail_;
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
 * &emsp;&emsp; 返回cur\n\n
 * return NULL(未搜索到时返回NULL)\n
 *
 *
 * ----
 */
template<typename TData>
DoublyLinkedNode<TData>* DoublyLinkedList<TData>::Search(const TData& data) const {
    for (DoublyLinkedNode<TData>* cur = head_->next; cur != NULL; cur = cur->next) {    // for loop 遍历指针cur, 从head_->next遍历到最后一个结点
        if (cur->data == data) {                                                        // if 当前结点data等于参数data
            return cur;                                                                 // 返回cur
        }
    }

    return NULL;                                                                        // return NULL(未搜索到时返回NULL)
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
 *
 *
 * ---------
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
 * + **1 空链表处理**\n\n
 * **if** 子链表首个结点为NULL :\n
 * &emsp; 返回NULL\n\n
 * + **2 子链表首个元素结点既是搜索结点的处理**\n\n
 * **if** 子链表首个元素结点的数据项 == data :\n
 * &emsp; 返回该结点(指针)\n\n
 * + **3 递归搜索**\n\n
 * 对sub_list_first_element->next(子链表首个元素结点的下一结点)递归调用SearchInSubListRecursive_, 返回结果\n
 *
 *
 * --------------
 */
template<typename TData>
DoublyLinkedNode<TData>* DoublyLinkedList<TData>::SearchInSubListRecursive_(DoublyLinkedNode<TData>* sub_list_first_element,
                                                                            const TData& data) const
{
    // ---------- 1 空链表处理 ----------

    if (sub_list_first_element == NULL) {                                       // if 子链表首个结点为NULL
        return NULL;                                                            // 返回NULL
    }

    // ---------- 2 子链表首个元素结点既是搜索结点的处理 ----------

    if (sub_list_first_element->data == data) {                                 // if 子链表首个元素结点的数据项 == data
        return sub_list_first_element;                                          // 返回该结点(指针)
    }

    // ---------- 3 递归搜索 ----------

    return SearchInSubListRecursive_(sub_list_first_element->next, data);       // 对sub_list_first_element->next(子链表首个元素结点的下一结点)递归调用SearchInSubListRecursive_, 返回结果
}


/*!
 * @brief **插入结点**
 * @tparam TData 数据项类型模板参数
 * @param prev_pos 插入位置的前一位置
 * @param data 数据项
 * @return 执行结果
 * @note
 * 插入结点
 * -------
 * -------
 * 
 * -------
 * + **1 非法位置处理**\n\n
 * **if** prev_pos > 链表长度 || prev_pos < 0 :\n
 * &emsp; 返回false\n\n
 * + **2 构造插入结点**\n\n
 * 分配内存并初始化new_node(插入结点)\n
 * **if** 内存分配失败 :\n
 * &emsp; 返回false\n\n
 * + **3 插入**\n\n
 * 获取prev_pos位置的结点prev_node(插入结点的前一结点)\n\n
 * 插入结点的next, 指向插入结点的前一结点的next\n
 * 插入结点的前一结点的next, 指向插入结点\n\n
 * 插入结点的下一结点的prev, 指向插入结点\n
 * 插入结点的prev, 指向插入结点的前一结点\n\n
 * + **4 调整长度**\n\n
 * length_加1\n\n
 * + **5 退出函数**\n\n
 * 返回true\n
 *
 *
 * -------
 */
template<typename TData>
bool DoublyLinkedList<TData>::Insert(int prev_pos, const TData& data) {

    // ---------- 1 非法位置处理 ----------

    if (prev_pos > length_ || prev_pos < 0) {                                       // if prev_pos > 链表长度 || prev_pos < 0
        return false;                                                               // 返回false
    }

    // ---------- 2 构造插入结点 ----------
    DoublyLinkedNode<TData>* new_node = new DoublyLinkedNode<TData>(data);          // 分配内存并初始化new_node(插入结点)
    if (!new_node) {
        return false;                                                               // if 内存分配失败
    }

    // ---------- 3 插入 ----------

    DoublyLinkedNode<TData>* prev_node = this->GetNode(prev_pos);                   // 获取prev_pos位置的结点prev_node(插入结点的前一结点)

    new_node->next = prev_node->next;                                               // 插入结点的next, 指向插入结点的前一结点的next
    prev_node->next = new_node;                                                     // 插入结点的前一结点的next, 指向插入结点

    new_node->next->prev = new_node;                                                // 插入结点的下一结点的prev, 指向插入结点
    new_node->prev = prev_node;                                                     // 插入结点的prev, 指向插入结点的前一结点

    // ---------- 4 调整长度 ----------

    length_++;                                                                      // length_加1

    // ---------- 5 退出函数 ----------

    return true;                                                                    // 返回true
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
 * + **1 非法位置处理**\n\n
 * **if** pos < 1 || pos > 链表长度 :\n
 * &emsp; 返回NULL\n\n
 * + **2 遍历至pos位置结点**\n\n
 * 初始化cur(遍历指针), 指向head_->next\n
 * **for loop** 1至pos :\n
 * &emsp; cur指向cur的next结点\n\n
 * + **3 返回结果**\n\n
 * 返回cur\n
 *
 *
 * -------
 */
template<typename TData>
DoublyLinkedNode<TData>* DoublyLinkedList<TData>::GetNode(int pos) const {

    // ---------- 1 非法位置处理 ----------

    if (pos < 0 || pos > Length()) {                                        // if pos < 1 || pos > 链表长度
        return NULL;                                                        // 返回NULL
    }

    // ---------- 2 遍历至pos位置结点 ----------

    DoublyLinkedNode<TData>* cur = head_;                                   // 初始化cur(遍历指针), 指向head_->next
    for (int i = 0; i < pos; i++) {                                         // for loop 1至pos
        cur = cur->next;                                                    // cur指向cur的next结点
    }

    // ---------- 3 返回结果 ----------

    return cur;                                                             // 返回cur
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
 * + **1 非法位置处理**\n\n
 * **if** pos < 1 || pos > 链表长度 :\n
 * &emsp; 返回NULL\n\n
 * + **2 遍历至pos位置结点**\n\n
 * 初始化cur(遍历指针), 指向head_->next\n
 * **for loop** 1至pos :\n
 * &emsp; cur指向cur的next结点\n\n
 * + **3 取值**\n\n
 * 取cur->data值, 赋给参数data\n\n
 * + **4 退出函数**\n\n
 * 返回true\n
 *
 *
 * -----------
 */
template<typename TData>
bool DoublyLinkedList<TData>::GetData(int pos, TData& data) const {

    // ---------- 1 非法位置处理 ----------

    if (pos < 1 || pos > Length()) {                                                        // if pos < 1 || pos > 链表长度
        return false;                                                                       // 返回NULL
    }

    // ---------- 2 遍历至pos位置结点 ----------

    DoublyLinkedNode<TData>* cur = head_->next;                                             // 初始化cur(遍历指针), 指向head_->next
    for (int i = 1; i < pos; i++) {                                                         // for loop 1至pos
        cur = cur->next;                                                                    // cur指向cur的next结点
    }

    // ---------- 3 取值 ----------

    data = cur->data;                                                                       // 取cur->data值, 赋给参数data

    // ---------- 4 退出函数 ----------

    return true;                                                                            // 返回true
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
 * + **1 非法位置处理**\n\n
 * **if** pos < 1 || pos > 链表长度 :\n
 * &emsp; 返回NULL\n\n
 * + **2 遍历至pos位置结点**\n\n
 * 初始化cur(遍历指针), 指向head_(头结点)\n
 * **for loop** 0至pos :\n
 * &emsp; cur指向cur的next结点\n\n
 * + **3 赋值**\n\n
 * data赋给cur->data\n\n
 * + **4 退出函数**\n\n
 * 返回true\n
 *
 *
 * --------
 */
template<typename TData>
bool DoublyLinkedList<TData>::SetData(int pos, const TData& data) {

    // ---------- 1 非法位置处理 ----------

    if (pos < 1 || pos > Length()) {                                        // if pos < 1 || pos > 链表长度
        return false;                                                       // 返回NULL
    }

    // ---------- 2 遍历至pos位置结点 ----------

    DoublyLinkedNode<TData>* cur = head_;                                   // 初始化cur(遍历指针), 指向head_(头结点)
    for (int i = 0; i < pos; i++) {                                         // for loop 0至pos :\n
        cur = cur->next;                                                    // cur指向cur的next结点
    }

    // ---------- 3 赋值 ----------

    cur->data = data;                                                       // data赋给cur->data

    // ---------- 4 退出函数 ----------

    return true;                                                            // 返回true
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
 * + **1 非法位置处理**\n\n
 * **if** pos < 0 || pos > 链表长度 :\n
 * &emsp; 返回false\n\n
 * + **2 遍历到待删除结点**\n\n
 * 调用GetNode获取待删除结点(指针)target_node\n\n
 * + **3 删除**\n\n
 * <span style="color:#003153">3.1 调整指针\n</span>
 * 待删除结点的next(下一结点), 指向待删除结点的prev(前一结点)\n
 * 待删除结点的prev(前一结点), 指向待删除结点的next(下一结点)\n\n
 * <span style="color:#003153">3.2 取待删除结点的数据项\n</span>
 * 取待删除结点的data, 赋给参数data\n\n
 * <span style="color:#003153">3.3 释放内存\n</span>
 * 释放target_node\n
 * target_node置NULL\n\n
 * + **4 长度调整**\n\n
 * length_减1\n\n
 * + **5 退出函数**\n\n
 * 返回true\n
 *
 *
 * -------
 */
template<typename TData>
bool DoublyLinkedList<TData>::Remove(int target_pos, TData& data) {

    // ---------- 1 非法位置处理 ----------

    if (target_pos > Length() || target_pos < 1) {                                          // if pos < 0 || pos > 链表长度
        return false;                                                                       // 返回false
    }

    // ---------- 2 遍历到待删除结点 ----------

    DoublyLinkedNode<TData>* target_node = this->GetNode(target_pos);                       // 调用GetNode获取待删除结点(指针)target_node

    // ----------3 删除 ----------

    // (3.1 调整指针)
    target_node->next->prev = target_node->prev;                                            // 待删除结点的next(下一结点), 指向待删除结点的prev(前一结点)
    target_node->prev->next = target_node->next;                                            // 待删除结点的prev(前一结点), 指向待删除结点的next(下一结点)

    // (3.2 取待删除结点的数项)
    data = target_node->data;                                                               // 取待删除结点的data, 赋给参数data

    // (3.3 释放内存)
    delete target_node;                                                                     // 释放target_node
    target_node = NULL;                                                                     // target_node置NULL

    // ---------- 4 长度调整 ----------

    length_--;                                                                              // length_减1

    // ---------- 5 退出函数 ----------

    return true;                                                                            // 返回true
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
 * **for loop** 遍历结点数量次数 :\n
 * &emsp; 删除位置1的结点\n
 *
 *
 * ---
 */
template<typename TData>
void DoublyLinkedList<TData>::Clear() {
    int length = this->length_;
    for (int i = 1; i <= length; i++) {                                                    // for loop 遍历结点数量次数
        TData target_data;
        this->Remove(1, target_data);                                                     // 删除位置1的结点
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
 * + **1 空链表处理**\n\n
 * **if** 空链表 :\n
 * &emsp; 打印"Empty list"\n
 * &emsp; 退出函数\n\n
 * + **2 打印**\n\n
 * 初始化cur(遍历指针), 指向head_->next\n\n
 * **for loop** 位置从1到length_ :\n
 * &emsp; 打印当前结点的data\n\n
 * &emsp; **if** 不是最后一个结点: \n
 * &emsp;&emsp; 打印 "<-->"\n\n
 * &emsp; cur指向cur->next\n
 *
 *
 * ---
 */
template<typename TData>
void DoublyLinkedList<TData>::Print() {

    // ---------- 1 空链表处理 ----------

    if (this->length_ == 0) {                                                               // if 空链表
        cout << "Empty list" << endl;                                                       // 打印"Empty list"
        return;                                                                             // 退出函数
    }

    // ---------- 2 打印 ----------

    cout << "打印双向链表: { ";
    DoublyLinkedNode<TData>* cur = this->head_->next;                                       // 初始化cur(遍历指针), 指向head_->next
    for (int pos = 1; pos <= Length(); pos++) {                                             // for loop 位置从1到length_
        cout << cur->data;                                                                  // 打印当前结点的data
        if (pos != Length()) {                                                              // if 不是最后一个结点
            cout << "<-->";                                                                 // 打印 "<-->"
        }
        cur = cur->next;                                                                    // cur指向cur->next
    }
    cout << " }" << endl;
}


#endif // CYBER_DASH_DOUBLY_LINKED_LIST_H
