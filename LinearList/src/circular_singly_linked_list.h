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
     * @brief **构造函数(下一结点)**
     * @param next 下一结点(指针)
     */
    explicit CircularSinglyLinkedNode(CircularSinglyLinkedNode<TData>* next = NULL):
        next(next) {}

    /*!
     * @brief **构造函数(数据项/下一结点)**
     * @param data 数据项
     * @param next 下一结点指针
     */
    explicit CircularSinglyLinkedNode(const TData& data, CircularSinglyLinkedNode<TData>* next = NULL) :
        data(data), next(next) {}

    TData data;                               //!< **数据项**
    CircularSinglyLinkedNode<TData>* next;    //!< **下一结点**
};


/*!
 * @brief **循环单链表模板类**
 * @tparam TData 数据项类型模板参数
 */
template<typename TData>
class CircularSinglyLinkedList : public LinearList<TData> {
public:
    /*! @brief 默认构造函数 */
    CircularSinglyLinkedList(): first_(NULL), last_(NULL), length_(0) {}

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

    // 获取结点
    CircularSinglyLinkedNode<TData>* GetNode(int pos);

    bool Insert(int prev_pos, const TData& data);

    bool Remove(int deletion_pos, TData& data);

    // 获取结点数据
    bool GetData(int pos, TData& data) const;

    // 设置结点数据
    bool SetData(int pos, const TData& data);

    // 打印双向链表
    void Print();

private:
    CircularSinglyLinkedNode<TData>* first_;            //!< **首结点**
    CircularSinglyLinkedNode<TData>* last_;             //!< **末结点**
    int length_;                                        //!< **长度**
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
 * **if** 空链表 :\n
 * &emsp; 退出函数(已经清空) \n\n
 * **II&nbsp; 遍历并删除各个结点**\n
 * **for loop** 遍历length_次 :\n
 * &emsp; 初始化deletion_node(待删除结点指针), 指向first_\n
 * &emsp; first_指向deletion_node->next\n
 * &emsp; 释放deletion_node\n
 * &emsp; deletion_node置NULL\n\n
 * **III first_和last_置空 **\n
 * first_置NULL\n
 * last_置NULL\n\n
 * **IV 长度调整 **\n
 * length_设置为0\n
 */
template<typename TData>
void CircularSinglyLinkedList<TData>::Clear() {

    // ---------- I 空链表处理 ----------

    if (this->first_ == NULL) {                                         // if 空链表
        return;                                                         // 退出函数(已经清空)
    }

    // ---------- II 遍历并删除各个结点 ----------

    for (int i = 1; i <= length_; i++) {                                // for loop 遍历length_次
        CircularSinglyLinkedNode<TData>* deletion_node = this->first_;  // 初始化deletion_node(待删除结点指针), 指向first_
        this->first_ = deletion_node->next;                             // first_指向deletion_node->next

        delete deletion_node;                                           // 释放deletion_node
        deletion_node = NULL;                                           // deletion_node置NULL
    }

    // ---------- III first_和last_置空 ----------

    this->first_ = NULL;                                                // first_置NULL
    this->last_ = NULL;                                                 // last_置NULL

    // ---------- IV 长度调整 ----------

    this->length_ = 0;                                                  // length_设置为0
}


/*!
 * @brief **搜索**
 * @tparam TData 数据项类型模板参数
 * @param data 搜索数据项
 * @return 结点(指针)
 * @note
 * 搜索
 * ---
 * ---
 *
 * ---
 * 初始化cur(遍历指针), 指向first_\n
 * **for loop** 遍历length_次 :\n
 * &emsp; **if** 当前结点data等于参数data :\n
 * &emsp;&emsp; 返回cur\n
 * &emsp; cur指向cur->next\n
 * 返回NULL\n
 */
template<typename TData>
CircularSinglyLinkedNode<TData>* CircularSinglyLinkedList<TData>::Search(const TData& data) {

    CircularSinglyLinkedNode<TData>* cur = first_;      // 初始化cur(遍历指针), 指向first_

    for (int i = 1; i <= length_; i++) {                // for loop 遍历length_次
        if (cur->data == data) {                        // if 当前结点data等于参数data
            return cur;                                 // 返回cur
        }
        cur = cur->next;                                // cur指向cur->next
    }

    return NULL;                                        // 返回NULL
}


/*!
 * @brief **析构函数**
 * @tparam TData 数据项类型模板参数
 * @note
 * 析构函数
 * -------
 * -------
 *
 * -------
 * 调用Clear()\n
 */
template<typename TData>
CircularSinglyLinkedList<TData>::~CircularSinglyLinkedList() {
    this->Clear();
}


/*!
 * @brief **获取结点**
 * @tparam TData 数据项类型模板参数
 * @param pos 位置
 * @return 结点(指针)
 * @note
 * 获取结点
 * -------
 * -------
 *
 * 特殊边界条件: 当只有1个结点时, pos 0为first_, 同时也是last_
 *
 * -------
 * + **1 非法位置处理**\n
 * **if** pos < 0 || pos > 链表长度 :\n
 * &emsp; 返回NULL\n
 * + **2 pos为0情况处理**\n
 * **if** pos为0 :\n
 * &emsp; 返回last_\n
 * + **3 遍历至目标结点**\n
 * 初始化cur(遍历指针), 指向first_\n
 * **for loop** 遍历pos - 1次 :\n
 * &emsp; cur指向自身next结点\n
 * + **4 返回结点指针**\n
 * 返回cur\n
 */
template<typename TData>
CircularSinglyLinkedNode<TData>* CircularSinglyLinkedList<TData>::GetNode(int pos) {
    if (pos < 0 || pos > length_) {
        return NULL;
    }

    if (pos == 0) {
        return last_;
    }

    CircularSinglyLinkedNode<TData>* cur = first_;

    for (int i = 1; i < pos; i++) {
        cur = cur->next;
    }

    return cur;
}


/*!
 * @brief **插入结点**
 * @tparam TData 数据项类型模板参数
 * @param prev_pos 插入位置的前一位置
 * @param data 数据项
 * @return 执行结果
 * @note
 * 插入结点
 * ------
 * ------
 *
 * ------
 */
template<typename TData>
bool CircularSinglyLinkedList<TData>::Insert(int prev_pos, const TData& data) {
    if (prev_pos > Length() || prev_pos < 0) {
        return false;
    }

    CircularSinglyLinkedNode<TData>* insertion_node = new CircularSinglyLinkedNode<TData>(data);
    if (insertion_node == NULL) {     // if 生成结点失败
        return false;       // 返回false
    }

    if (length_ == 0) {
        first_ = insertion_node;
        first_->next = first_;

        last_ = first_;

        length_ = 1;

        return true;
    }

    CircularSinglyLinkedNode<TData>* prev_node = this->GetNode(prev_pos);

    insertion_node->next = prev_node->next;     // insertion_node->next指向cur->next
    prev_node->next = insertion_node;           // prev_node->next指向node

    if (prev_pos == 0) {
        first_ = insertion_node;
    }

    // 如果插入结点的next指向了first_, 则将其设置为last_
    if (insertion_node->next == first_) {
        last_ = insertion_node;
    }

    this->length_++;

    return true;
}


/*!
 * @brief **删除结点**
 * @tparam TData 数据项类型模板参数
 * @param deletion_pos 位置
 * @param data 数据项保存变量
 * @return 执行结果
 * @note
 * 删除(结点)元素
 * ------------
 * ------------
 * 如果删除first_结点, 则新的first_结点为原first_结点的next(如果原first_->next不为自身)
 * ------------
 * **1 非法位置处理**\n
 * **if** deletion_pos < 0 或者 deletion_pos > 链表长度:\n
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
bool CircularSinglyLinkedList<TData>::Remove(int deletion_pos, TData& data) {
    // ----- I 错误位置处理 -----
    if (deletion_pos < 0 || deletion_pos > length_) {
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
    if (deletion_pos == 1) {
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
    CircularSinglyLinkedNode<TData>* prev_node = this->GetNode(deletion_pos - 1);
    CircularSinglyLinkedNode<TData>* deletion_node = prev_node->next;
    if (deletion_node == last_) {
        last_ = prev_node;
    }

    data = deletion_node->data;

    prev_node->next = deletion_node->next;

    delete deletion_node;
    deletion_node = NULL;

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


/*!
 * @brief **获取数据项**
 * @tparam TData 数据项类型模板参数
 * @param pos 位置
 * @param data 数据项保存变量
 * @return 执行结果
 * @note
 * 获取数据项
 * --------
 * --------
 *
 * --------
 * + **1 非法位置处理**\n
 * **if** pos < 1 || pos > 链表长度 || 链表长度为0 :\n
 * &emsp; 返回false\n\n
 * + **2 pos为0情况处理**\n
 * **if** pos为0 :\n
 * &emsp; last_->data赋给参数data\n
 * &emsp; 返回true\n\n
 * + **3 遍历至目标结点**\n
 * 初始化cur(遍历指针), 指向first_\n
 * **for loop** 遍历pos - 1次 :\n
 * &emsp; cur指向自身next结点\n\n
 * + **4 赋值**\n
 * cur->data赋给参数data\n\n
 * + **5 退出函数**\n
 * 返回true\n
 */
template<typename TData>
bool CircularSinglyLinkedList<TData>::GetData(int pos, TData& data) const {

    if (pos < 0 || pos > Length() || length_ == 0) {
        return false;
    }

    // ---------- 2 pos为0情况处理 ----------

    if (pos == 0) {                                         // if pos为0
        data = last_->data;                                 // last_->data赋给参数data
        return true;                                        // 返回true
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
