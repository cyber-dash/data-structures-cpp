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


/*!
 * **单向循环链表结点模板结构体**
 * @tparam TData 数据项类型模板参数
 */
template <typename TData>
struct CircularSinglyLinkedNode {
    /*!
     * @brief **构造函数(下一结点)**
     * @param next 下一结点
     */
    explicit CircularSinglyLinkedNode(CircularSinglyLinkedNode<TData>* next = NULL):
        next(next) {}

    /*!
     * @brief **构造函数(数据项, 下一结点)**
     * @param data 数据项
     * @param next 下一结点
     */
    explicit CircularSinglyLinkedNode(const TData& data, CircularSinglyLinkedNode<TData>* next = NULL) :
        data(data), next(next) {}

    TData data;                               //!< **数据项**
    CircularSinglyLinkedNode<TData>* next;    //!< **下一结点**
};


/*!
 * @brief **循环单链表模板类**
 * @tparam TData 数据项类型模板参数
 * @note
 * 循环单链表模板类
 * --------------
 * --------------
 *
 * first_指向链表首元素, last_指向链表尾元素
 *
 * --------------
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

    /*! @brief **链表是否为空** */
    bool IsEmpty() const { return this->first_ == NULL; }

    // 清空链表
    void Clear();

    // 搜索
    CircularSinglyLinkedNode<TData>* Search(const TData& data);

    // 获取结点
    CircularSinglyLinkedNode<TData>* GetNode(int pos);

    // 插入结点
    bool Insert(int prev_pos, const TData& data);

    // 删除结点
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

    // ---------- 1 非法位置处理 ----------

    if (pos < 0 || pos > length_) {                                                 // if pos < 0 || pos > 链表长度
        return NULL;                                                                // 返回NULL
    }

    // ---------- 2 pos为0情况处理 ----------

    if (pos == 0) {                                                                 // if pos为0
        return last_;                                                               // 返回last_
    }

    // ---------- 3 遍历至目标结点 ----------

    CircularSinglyLinkedNode<TData>* cur = first_;                                  // 初始化cur(遍历指针), 指向first_

    for (int i = 1; i < pos; i++) {                                                 // for loop 遍历pos - 1次
        cur = cur->next;                                                            // cur指向自身next结点
    }

    // ---------- 4 返回结点指针 ----------

    return cur;                                                                     // 返回cur
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
 * 注意和数组索引区别, 本实现的首位置为1, 不是首索引为0
 *
 * ------
 * + **1 合法性判断**\n
 * **if** prev_pos > 链表长度 <b>||</b> prev_pos < 0 :\n
 * &emsp; 返回false\n\n
 * + **2 生成插入结点**\n
 * insertion_node分配内存并初始化\n
 * **if** 结点内存分配失败 :\n
 * &emsp; 返回false\n\n
 * + **3 首结点插入的情况**\n
 * **if** 链表长度为0 :\n
 * &emsp; first_指向insertion_node\n
 * &emsp; first_->next指向first_\n\n
 * &emsp; last_->指向first_\n
 * &emsp; 链表长度设为1\n
 * &emsp; 返回true\n\n
 * + **4 非首结点插入的情况**\n
 * 获取prev_node(前一位置的结点)\n\n
 * insertion_node->next指向prev_node->next\n
 * prev_node->next指向node\n\n
 * **if** 插入链表首位置 :\n
 * &emsp; first_指向insertion_node\n\n
 * **if** 新插入的结点的next指向first_ :\n
 * &emsp; last_指向insertion_node\n\n
 * + **5 **\n
 * 链表长度加1\n\n
 * + **6 退出函数**\n
 * 返回true\n
 */
template<typename TData>
bool CircularSinglyLinkedList<TData>::Insert(int prev_pos, const TData& data) {

    // ---------- 1 合法性判断 ----------

    if (prev_pos > Length() || prev_pos < 0) {                                  // if prev_pos > 链表长度 || prev_pos < 0
        return false;                                                           // 返回false
    }

    // ---------- 2 生成插入结点 ----------

    // insertion_node分配内存并初始化
    CircularSinglyLinkedNode<TData>* insertion_node = new CircularSinglyLinkedNode<TData>(data);
    if (insertion_node == NULL) {                                               // if 结点内存分配失败
        return false;                                                           // 返回false
    }

    // ---------- 3 首结点插入的情况 ----------

    if (length_ == 0) {                                                         // if 链表长度为0
        first_ = insertion_node;                                                // first_指向insertion_node
        first_->next = first_;                                                  // first_->next指向first_

        last_ = first_;                                                         // last_->指向first_

        length_ = 1;                                                            // 链表长度设为1

        return true;                                                            // 返回true
    }

    // ---------- 4 非首结点插入的情况 ----------

    CircularSinglyLinkedNode<TData>* prev_node = this->GetNode(prev_pos);       // 获取prev_node(前一位置的结点)

    insertion_node->next = prev_node->next;                                     // insertion_node->next指向prev_node->next
    prev_node->next = insertion_node;                                           // prev_node->next指向node

    if (prev_pos == 0) {                                                        // if 插入链表首位置
        first_ = insertion_node;                                                // first_指向insertion_node
    }

    if (insertion_node->next == first_) {                                       // if 新插入的结点的next指向first_
        last_ = insertion_node;                                                 // last_指向insertion_node
    }

    // ---------- 4 链表长度加1 ----------

    this->length_++;                                                            // 链表长度加1

    // ---------- 5 退出函数 ----------
    return true;                                                                // 返回true
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
 * 
 * 如果删除first_结点, 则新的first_结点为原first_结点的next(如果原first_->next不为自身)\n
 * 
 * ------------
 * + **1 非法位置处理**\n
 * **if** deletion_pos < 0 或者 deletion_pos > 链表长度:\n
 * &emsp; 返回false\n
 * + **2 链表长度为1的情况**\n
 * **if** 新链表长度为1\n
 * &emsp; (此时, first_/last_指向唯一结点)\n
 * &emsp; first_->data赋给参数data\n
 * &emsp; 释放first_并置NULL\n
 * &emsp; last_置NULL\n
 * &emsp; 长度置0\n
 * &emsp; 返回true\n
 * + **3 删除first_结点的情况**\n
 * **if** pos等于1(删除first_结点):\n
 * &emsp; first_->data赋给参数data\n\n
 * &emsp; 声明指针deletion_node指向首元素结点\n\n
 * &emsp; last_->next指向first_->next\n
 * &emsp; first_指向first_->next\n\n
 * &emsp; 释放deletion_node\n\n
 * &emsp; 链表长度减1\n\n
 * &emsp; 返回true\n\n
 * + **4 其他情况**\n
 * 调用GetNode, 获取prev_node(待删除结点的前一结点)\n
 * 初始化deletion_node(待删除结点)为prev_node->next\n
 * **if** 删除last_结点 :\n
 * &emsp; last_指向prev_node\n
 * deletion_node->data赋给参数data\n
 * prev_node->next指向deletion_node->next\n
 * 释放deletion_node\n
 * deletion_node置NULL\n
 * 链表长度减1\n
 * + **5 退出函数**\n
 * 返回true\n
 */
template<typename TData>
bool CircularSinglyLinkedList<TData>::Remove(int deletion_pos, TData& data) {

    // ---------- 1 非法位置处理 ----------

    if (deletion_pos < 1 || deletion_pos > length_) {                               // if deletion_pos < 0 或者 deletion_pos > 链表长度
        return false;                                                               // 返回false
    }

    // ---------- 2 链表长度为1的情况 ----------

    if (Length() == 1) {                                                            // if 链表长度为1 (此时, first_/last_指向唯一结点)
        data = first_->data;                                                        // first_->data赋给参数data

        delete first_;                                                              // 释放first_并置NULL
        first_ = NULL;
        last_ = NULL;                                                               // last_置NULL

        length_ = 0;                                                                // 长度置0

        return true;                                                                // 返回true
    }

    // ---------- 3 删除first_结点的情况 ----------

    if (deletion_pos == 1) {                                                        // if pos等于1(删除first_结点)
        data = first_->data;                                                        // first_->data赋给参数data

        CircularSinglyLinkedNode<TData>* deletion_node = first_;                    // 声明指针deletion_node指向首元素结点

        last_->next = first_->next;                                                 // last_->next指向first_->next
        first_ = first_->next;                                                      // first_指向first_->next

        delete deletion_node;                                                       // 释放deletion_node
        deletion_node = NULL;

        length_--;                                                                  // 链表长度减1

        return true;                                                                // 返回true
    }

    // ---------- 4 其他情况 ----------

    CircularSinglyLinkedNode<TData>* prev_node = this->GetNode(deletion_pos - 1);   // 调用GetNode, 获取prev_node(待删除结点的前一结点)
    CircularSinglyLinkedNode<TData>* deletion_node = prev_node->next;               // 初始化deletion_node(待删除结点)为prev_node->next
    if (deletion_node == last_) {                                                   // if 删除last_结点
        last_ = prev_node;                                                          // last_指向prev_node
    }

    data = deletion_node->data;                                                     // deletion_node->data赋给参数data

    prev_node->next = deletion_node->next;                                          // prev_node->next指向deletion_node->next

    delete deletion_node;                                                           // 释放deletion_node
    deletion_node = NULL;                                                           // deletion_node置NULL

    length_--;                                                                      // 链表长度减1

    // ---------- 5 退出函数 ----------

    return true;                                                                    // 返回true
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
 * &emsp; 退出函数\n
 * + **2 执行打印**\n
 * 打印 "打印循环单链表: { "\n
 * 初始化cur(遍历指针), 指向first_\n
 * **for loop** 遍历length_次 :\n
 * &emsp; 打印cur->data\n
 * &emsp; **if** 不是length_位置结点 :\n
 * &emsp;&emsp; 打印", "\n
 * &emsp; cur指向cur->next\n
 * 打印 " }"\n
 */
template<typename TData>
void CircularSinglyLinkedList<TData>::Print() {

    // ---------- 1 空链表处理 ----------

    if (this->first_ == NULL) {                                 // if 空链表
        cout << "Empty list" << endl;                           // 打印"Empty list"
        return;                                                 // 退出函数
    }

    // ---------- 2 执行打印 ----------

    cout << "打印循环单链表: { ";                                 // 打印 "打印循环单链表: { "

    CircularSinglyLinkedNode<TData>* cur = this->first_;        // 初始化cur(遍历指针), 指向first_

    for (int pos = 1; pos <= Length(); pos++) {                 // for loop 遍历length_次
        cout << cur->data;                                      // 打印cur->data
        if (pos != Length()) {                                  // if 不是length_位置结点
            cout << ", ";                                       // 打印", "
        }
        cur = cur->next;                                        // cur指向cur->next
    }

    cout << " }" << endl;                                       // 打印 " }"
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
 * + **2 遍历至目标结点**\n
 * 初始化cur(遍历指针), 指向first_\n
 * **for loop** 遍历pos - 1次 :\n
 * &emsp; cur指向自身next结点\n\n
 * + **3 赋值**\n
 * cur->data赋给参数data\n\n
 * + **4 退出函数**\n
 * 返回true\n
 */
template<typename TData>
bool CircularSinglyLinkedList<TData>::GetData(int pos, TData& data) const {

    // ---------- 1 非法位置处理 ----------

    if (pos < 1 || pos > Length() || length_ == 0) {        // if pos < 1 || pos > 链表长度 || 链表长度为0
        return false;                                       // 返回false
    }

    // ---------- 2 遍历至目标结点 ----------

    CircularSinglyLinkedNode<TData>* cur = first_;          // 初始化cur(遍历指针), 指向first_
    for (int i = 1; i < pos; i++) {                         // for loop 遍历pos - 1次
        cur = cur->next;                                    // cur指向自身next结点
    }

    // ---------- 3 赋值 ----------

    data = cur->data;                                       // cur->data赋给参数data

    // ---------- 4 退出函数 ----------

    return true;                                            // 返回true
}


/*!
 * @brief **设置数据项**
 * @tparam TData 数据项类型模板参数
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
 * **if** pos < 1 || pos > 链表长度 || 链表长度为0 :\n
 * &emsp; 返回false\n\n
 * + **2 遍历至目标结点**\n
 * 初始化cur(遍历指针), 指向first_\n
 * **for loop** 遍历pos - 1次 :\n
 * &emsp; cur指向自身next结点\n\n
 * + **3 赋值**\n
 * 参数data赋给cur->data\n\n
 * + **4 退出函数**\n
 * 返回true\n
 */
template<typename TData>
bool CircularSinglyLinkedList<TData>::SetData(int pos, const TData& data) {

    // ---------- 1 非法位置处理 ----------

    if (pos < 1 || pos > Length()) {                            // if pos < 1 || pos > 链表长度 || 链表长度为0
        return false;                                           // 返回false
    }

    // ---------- 2 遍历至目标结点 ----------

    CircularSinglyLinkedNode<TData>* cur = first_;              // 初始化cur(遍历指针), 指向first_
    for (int i = 1; i < pos; i++) {                             // for loop 遍历pos - 1次
        cur = cur->next;                                        // cur指向自身next结点
    }

    // ---------- 3 赋值 ----------

    cur->data = data;                                           // 参数data赋给cur->data

    // ---------- 4 退出函数 ----------

    return true;                                                // 返回true
}


#endif // CYBER_DASH_CIRCULAR_SINGLY_LINKED_LIST_H
