/*!
 * @file circular_doubly_linked_list.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 双向循环链表
 * @version 0.9.0
 * @date 2020-07-28
 */

#ifndef CYBER_DASH_CIRCULAR_DOUBLY_LINKED_LIST_H
#define CYBER_DASH_CIRCULAR_DOUBLY_LINKED_LIST_H


#include <iostream>
#include <cstddef>
#include "linear_list.h"


 /*!
  * @brief **双向循环链表结点模板结构体**
  * @tparam TData 数据项类型模板参数
  */
template <typename TData>
struct CircularDoublyLinkedNode {
    /*!
     * @brief **构造函数(下一结点/前一节点)**
     * @param next 下一结点(指针)
     * @param prev 上一结点(指针)
     */
    explicit CircularDoublyLinkedNode(CircularDoublyLinkedNode<TData>* next = NULL,
                                      CircularDoublyLinkedNode<TData>* prev = NULL)
        : next(next), prev(prev) {}

    /*!
     * @brief **构造函数(数据项/前一结点/前一结点)**
     * @param data 数据项
     * @param next 下一结点(指针)
     * @param prev 上一结点(指针)
     */
    explicit CircularDoublyLinkedNode(const TData& data,
                                      CircularDoublyLinkedNode<TData>* next = NULL,
                                      CircularDoublyLinkedNode<TData>* prev = NULL)
        : data(data), next(next), prev(prev) {}

    TData data;                               //!< 数据项
    CircularDoublyLinkedNode<TData>* next;    //!< 下一结点
    CircularDoublyLinkedNode<TData>* prev;    //!< 上一结点
};


/*!
 * @brief **循环双向链表模板类**
 * @tparam TData 数据项类型模板参数
 */
template<typename TData>
class CircularDoublyLinkedList: public LinearList<TData> {
public:
    /*! @brief 默认构造函数 */
    CircularDoublyLinkedList(): first_(NULL), length_(0) {}

    // 析构函数
    ~CircularDoublyLinkedList();

    /*! @brief **长度** */
    int Length() const { return this->length_; }

    /*! @brief **判断是否为空链表** */
    bool IsEmpty() const { return this->first_ == NULL; }

    // 清空
    void Clear();

    /*! @brief 获取链表头结点 */
    CircularDoublyLinkedNode<TData>* First() const { return this->first_; }

    // 搜索
    CircularDoublyLinkedNode<TData>* Search(const TData& data);

    // 获取结点(按方向)
    CircularDoublyLinkedNode<TData>* GetNodeByDirection(int step, int direction);

    // 获取结点
    CircularDoublyLinkedNode<TData>* GetNode(int pos);

    // 插入结点
    bool Insert(int prev_pos, const TData& data);

    // 删除结点(按方向)
    bool RemoveByDirection(int step, TData& data, int direction);

    // 删除结点
    bool Remove(int deletion_pos, TData& data);

    // 获取结点数据
    bool GetData(int pos, TData& data) const;

    // 设置结点数据
    bool SetData(int pos, const TData& data);

    // 打印
    void Print();

    static const int BACKWARD_DIRECTION = 0;    // prev方向
    static const int FORWARD_DIRECTION = 1;     // next方向

private:
    CircularDoublyLinkedNode<TData>* first_;    // 首元素结点(指针)
    int length_;                                // 长度
};


/*!
 * @brief **清空**
 * @note
 * 清空
 * ---
 * ---
 *
 * <span style="color:#FF8100">
 * </span>
 *
 * ---
 * + **1 释放结点内存**\n
 * **while** first_(首元素结点)不为NULL:\n
 * &emsp; (删除当前头结点)\n
 * &emsp; 声明deletion_node(删除结点), 指向first_\n
 * &emsp; first_指向cur->next\n
 * &emsp; 释放deletion_node指向的结点\n
 * &emsp; deletion_node置NULL\n
 * + **2 调整长度**\n
 * length_设置为0\n
 */
template<typename TData>
void CircularDoublyLinkedList<TData>::Clear() {
    // ---------- 1 释放结点内存 ----------

    while (first_ != NULL) {                                            // while first_(首元素结点)不为NULL
        // (删除当前头结点)
        CircularDoublyLinkedNode<TData>* deletion_node = this->first_;  // 声明deletion_node(删除结点), 指向first_
        first_ = deletion_node->next;                                   // first_指向cur->next

        delete deletion_node;                                           // 释放deletion_node指向的结点
        deletion_node = NULL;                                           // deletion_node置NULL
    }

    // ---------- 2 调整长度 ----------

    this->length_ = 0;                                                  // length_设置为0
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
 * 调用Clear()函数\n
 */
template<typename TData>
CircularDoublyLinkedList<TData>::~CircularDoublyLinkedList() {
    this->Clear();
}


/*!
 * @brief **搜索**
 * @param data 数据项
 * @return 结点指针
 * @note
 * 搜索
 * ---
 * ---
 *
 * ---
 * 初始化cur(遍历指针), 指向first_(首个结点)\n
 * **for loop** 遍历链表每个结点, 从pos(位置)等于1开始, 每次遍历结束cur指向自身next :\n
 * **if** cur->data等于参数data :\n
 * &emsp; 返回cur\n
 * 返回NULL(没有对应结点)\n
 */
template<typename TData>
CircularDoublyLinkedNode<TData>* CircularDoublyLinkedList<TData>::Search(const TData& data) {
    CircularDoublyLinkedNode<TData>* cur = this->first_;    // 初始化cur(遍历指针), 指向first_(首个结点)

    // for loop 遍历链表每个结点, 从pos(位置)等于1开始, 每次遍历结束cur指向自身next
    for (int pos = 1; pos <= this->Length(); pos++, cur = cur->next) {
        if (cur->data == data) {                            // if cur->data等于参数data
            return cur;                                     // 返回cur
        }
    }

    return NULL;                                            // 返回NULL(没有对应结点)
}


/*!
 * @brief 获取结点(按方向)
 * @param step 步数
 * @param direction 方向
 * @return 结点指针
 * @note
 * 获取结点(按方向)
 * --------------
 * --------------
 *
 * CircularDoublyLinkedList::BACKWARD_DIRECTION, 向next指针方向
 * CircularDoublyLinkedList::FORWARD_DIRECTION, 向prev指针方向
 *
 * --------------
 * + **1 非法步数处理** \n
 * **if** step < 0 || step >= 链表长度 :\n
 * &emsp; 返回NULL\n
 * + **2 按方向遍历至pos位置** \n
 * 初始化cur(遍历指针), 指向first_(首结点) \n
 * **for loop** 循环step次 :\n
 * &emsp; **if** 向prev方向 :\n
 * &emsp;&emsp; cur指向cur->prev\n
 * &emsp; **else** (向next方向) :\n
 * &emsp;&emsp; cur指向cur->next\n
 * + **3 返回结果** \n
 * 返回cur\n
 */
template<typename TData>
CircularDoublyLinkedNode<TData>* CircularDoublyLinkedList<TData>::GetNodeByDirection(int step, int direction) {

    // ---------- 1 非法步数处理 ----------

    if (step < 0 || step >= length_) {              // if step < 0 || step >= 链表长度
        return NULL;                                // 返回NULL
    }

    // ---------- 2 按方向遍历至pos位置 ----------

    CircularDoublyLinkedNode<TData>* cur = first_;  // 初始化cur(遍历指针), 指向first_(首结点)

    for (int i = 1; i <= step; i++) {               // for loop 循环step次
        if (direction == BACKWARD_DIRECTION) {      // if 向prev方向
            cur = cur->prev;                        // cur指向cur->prev
        } else {                                    // else (向next方向)
            cur = cur->next;                        // cur指向cur->next
        }
    }

    // ---------- 3 返回结果 ----------

    return cur;                                     // 返回cur
}


/*!
 * @brief **获取结点**
 * @tparam TData 数据项类型模板参数
 * @param pos 位置
 * @return 结点指针
 * 获取结点
 * -------------------
 * -------------------
 *
 * -------------------
 * + **1 pos为0情况处理**\n
 * **if** pos等于0 :\n
 * &emsp; 返回first_->prev\n
 * + **2 调用GetDataByDirection**\n
 * 计算step = pos - 1\n
 * 按照FORWARD_DIRECTION方向, 调用GetDataByDirection\n
 */
template<typename TData>
CircularDoublyLinkedNode<TData>* CircularDoublyLinkedList<TData>::GetNode(int pos) {

    // ---------- 1 pos为0情况处理 ----------

    if (pos == 0) {                 // if pos等于0
        return first_->prev;        // 返回first_->prev
    }

    // ---------- 2 调用GetDataByDirection ----------

    int step = pos - 1;             // 计算step = pos - 1

    // 按照FORWARD_DIRECTION方向, 调用GetDataByDirection
    return this->GetNodeByDirection(step, CircularDoublyLinkedList::FORWARD_DIRECTION);
}


/*!
 * @brief **插入结点**
 * @tparam TData 数据项类型模板参数
 * @param prev_pos 位置
 * @param data 数据
 * @return 执行结果
 * 插入结点
 * -------
 * -------
 *
 * 在pos位置之后的位置插入
 *
 * -------
 * + **1 非法位置判断**\n
 * **if** prev_pos < 0 || prev_pos > 链表长度 :\n
 * &emsp; 返回false\n
 * + **2 构造插入结点**\n
 * 分配内存并初始化插入结点\n
 * **if** 内存分配失败 :\n
 * &emsp; 抛出bad_alloc()\n
 * + **3 空链表插入**\n
 * **if** 空链表 :\n
 * &emsp; first_指向insertion_node\n
 * &emsp; insertion_node->next指向自身\n
 * &emsp; insertion_node->prev指向自身\n
 * &emsp; 链表长度设置为1\n
 * &emsp; 返回true\n
 * + **4 插入**\n
 * <span style="color:#003153">4.1 获取prev_node(指向插入位置前一位置结点的指针)\n</span>
 * 调用GetNode获取prev_node\n
 * <span style="color:#003153">4.2 插入\n</span>
 * 插入结点的next, 指向插入结点的前一结点的next\n
 * 插入结点的前一结点的next, 指向插入结点\n\n
 * 插入结点的下一结点的prev, 指向插入结点\n
 * 插入结点的prev, 指向插入结点的前一结点\n\n
 * <span style="color:#003153">4.3 插入结点作为首结点的情况\n</span>
 * **if** prev_pos为0(插入结点作为首结点) :\n
 * &emsp; first_指向新插入的结点\n
 * <span style="color:#003153">4.4 调整长度\n</span>
 * length_加1\n\n
 * + **5 返回**\n
 * 返回true\n
 */
template<typename TData>
bool CircularDoublyLinkedList<TData>::Insert(int prev_pos, const TData& data) {

    // ---------- 1 非法位置判断 ----------

    if (prev_pos < 0 || prev_pos > length_) {                               // if prev_pos < 0 || prev_pos > 链表长度
        return false;                                                       // 返回false
    }

    // ---------- 2 构造插入结点 ----------

    // 分配内存并初始化插入结点
    CircularDoublyLinkedNode<TData>* insertion_node = new CircularDoublyLinkedNode<TData>(data);
    if (insertion_node == NULL) {                                           // if 内存分配失败
        throw bad_alloc();                                                  // 抛出bad_alloc()
    }

    // ---------- 3 空链表插入 ----------

    if (first_ == NULL) {                                                   // if 空链表
        first_ = insertion_node;                                            // first_指向insertion_node

        insertion_node->next = insertion_node;                              // insertion_node->next指向自身
        insertion_node->prev = insertion_node;                              // insertion_node->prev指向自身

        this->length_ = 1;                                                  // 链表长度设置为1

        return true;                                                        // 返回true
    }

    // ---------- 4 插入 ----------

    // -- 4.1 获取prev_node(指向插入位置前一位置结点的指针) --
    CircularDoublyLinkedNode<TData>* prev_node = this->GetNode(prev_pos);   // 调用GetNode获取prev_node

    // -- 4.2 插入 --
    insertion_node->next = prev_node->next;                                 // 插入结点的next, 指向插入结点的前一结点的next
    prev_node->next = insertion_node;                                       // 插入结点的前一结点的next, 指向插入结点
    insertion_node->next->prev = insertion_node;                            // 插入结点的下一结点的prev, 指向插入结点
    insertion_node->prev = prev_node;                                       // 插入结点的prev, 指向插入结点的前一结点

    // -- 4.3 插入结点作为首结点的情况 --
    if (prev_pos == 0) {                                                    // if prev_pos为0(插入结点作为首结点)
        first_ = insertion_node;                                            // first_指向新插入的结点
    }

    // -- 4.4 调整长度 --
    this->length_++;                                                        // length_加1

    // ---------- 5 返回 ----------

    return true;                                                            // 返回true
}


/*!
 * @brief **删除(结点)元素(按方向)**
 * @tparam TData 数据项类型模板参数
 * @param step 步数
 * @param data 数据项保存变量
 * @param direction 方向
 * @return 执行结果
 * @note
 * 删除(结点)元素(按方向)
 * -------------------
 * -------------------
 *
 * -------------------
 * + **1 非法情况处理**\n
 * **if** first_为NULL :\n
 * &emsp; 返回false\n\n
 * + **2 获取结点指针**\n
 * 调用GetNodeByDirection, 获取deletion_node(指向待删除结点的指针)\n
 * **if** deletion_node为NULL :\n
 * &emsp; 返回false\n\n
 * + **3 只有1个结点的情况处理**\n
 * **if** 链表长度为1 :\n
 * &emsp; deletion_node的data赋给参数data\n
 * &emsp; 释放deletion_node\n
 * &emsp; deletion_node置NULL\n
 * &emsp; length_设为0\n
 * &emsp; 返回true\n
 * + **4 删除**\n
 * <span style="color:#003153">4.1 如果删除首结点, first_调整\n</span>
 * **if** 删除首结点 :\n
 * &emsp; **if** next方向 :\n
 * &emsp;&emsp; first_指向deletion_node->next\n
 * &emsp; **else if** next方向 :\n
 * &emsp;&emsp; first_指向deletion_node->next\n\n
 * <span style="color:#003153">4.2 删除操作\n</span>
 * deletion_node的下一结点的prev, 指向deletion_node的前一结点\n
 * deletion_node的前一结点的prev, 指向deletion_node的下一结点\n
 * deletion_node的data, 赋给参数data\n\n
 * 释放deletion_node\n
 * deletion_node置为NULL\n\n
 * <span style="color:#003153">4.4 调整长度\n</span>
 * 链表长度减1\n\n
 * + **5 返回结果**\n
 * 返回true\n
 */
template<typename TData>
bool CircularDoublyLinkedList<TData>::RemoveByDirection(int step, TData &data, int direction) {

    // --------- 1 非法情况处理 ---------

    if (first_ == NULL) {                                   // if first_为NULL
        return false;                                       // 返回false
    }

    // --------- 2 获取结点指针 ---------

    // 调用GetNodeByDirection, 获取deletion_node(指向待删除结点的指针)
    CircularDoublyLinkedNode<TData>* deletion_node = GetNodeByDirection(step, direction);
    if (deletion_node == NULL) {                            // if deletion_node为NULL
        return false;                                       // 返回false
    }

    // --------- 3 只有1个结点的情况处理 ---------

    if (length_ == 1) {                                     // if 链表长度为1
        data = deletion_node->data;                         // deletion_node的data赋给参数data

        delete deletion_node;                               // 释放deletion_node
        this->first_ = NULL;                                // deletion_node置NULL

        length_ = 0;                                        // length_设为0

        return true;                                        // 返回true
    }

    // --------- 4 删除 ---------

    // -- 4.1 如果删除首结点, first_调整 --
    if (deletion_node == first_) {                          // if 删除首结点
        if (direction == FORWARD_DIRECTION) {               // if next方向
            first_ = deletion_node->next;                   // first_指向deletion_node->next
        } else if (direction == BACKWARD_DIRECTION) {       // else if next方向
            first_ = deletion_node->prev;                   // first_指向deletion_node->next
        }
    }

    // -- 4.2 删除操作 --
    deletion_node->next->prev = deletion_node->prev;        // deletion_node的下一结点的prev, 指向deletion_node的前一结点
    deletion_node->prev->next = deletion_node->next;        // deletion_node的前一结点的prev, 指向deletion_node的下一结点

    data = deletion_node->data;                             // deletion_node的data, 赋给参数data

    delete deletion_node;                                   // 释放deletion_node
    deletion_node = NULL;                                   // deletion_node置为NULL

    // -- 4.4 调整长度 --
    this->length_--;                                        // 链表长度减1

    // --------- 5 返回结果 ---------

    return true;                                            // 返回true
}


/*!
 * @brief **删除结点**
 * @tparam TData 数据项类型模板参数
 * @param deletion_pos 待删除结点位置
 * @param data 数据项保存变量
 * @return 执行结果
 * @note
 * 删除结点
 * ------
 * ------
 *
 * ------
 * 初始化step等于deletion_pos - 1\n
 * 调用RemoveByDirection, 返回执行结果\n
 */
template<typename TData>
bool CircularDoublyLinkedList<TData>::Remove(int deletion_pos, TData& data) {
    // 初始化step等于deletion_pos - 1
    int step = deletion_pos - 1;

    // 调用RemoveByDirection, 返回执行结果
    return this->RemoveByDirection(step, data, CircularDoublyLinkedList::FORWARD_DIRECTION);
}


/*!
 * @brief **获取结点数据**
 * @tparam TData 数据项类型模板参数
 * @param pos 位置
 * @param data 数据项保存变量
 * @return 执行结果
 * @note
 * 获取结点数据
 * ----------
 * ----------
 *
 * 不推荐调用GetData(0)
 *
 * ----------
 * + **1 非法情况处理**\n
 * **if** pos < 1 || pos > 链表长度 || 空链表 :\n
 * &emsp; 返回false\n\n
 * + **2 pos为0情况处理**\n
 * **if** pos为0 :\n
 * &emsp; first->prev->data赋给参数data\n
 * &emsp; 返回true\n\n
 * + **3 遍历至pos位置结点**\n
 * 初始化cur(遍历指针), 指向首结点\n
 * **for loop** 遍历pos - 1次 :\n
 * &emsp; cur指向cur->next\n\n
 * + **4 赋值**\n
 * cur->data赋给参数data\n\n
 * + **5 退出函数**\n
 * 返回true\n
 */
template<typename TData>
bool CircularDoublyLinkedList<TData>::GetData(int pos, TData& data) const {

    // ---------- 1 非法情况处理 ----------

    if (pos < 0 || pos > length_ || length_ == 0) {         // if pos < 1 || pos > 链表长度 || 空链表
        return false;                                       // 返回false
    }

    // ---------- 2 pos为0情况处理 ----------

    if (pos == 0) {                                         // if pos为0
        data = first_->prev->data;                          // first->prev->data赋给参数data
        return true;                                        // 返回true
    }

    // ---------- 3 遍历至pos位置结点 ----------

    CircularDoublyLinkedNode<TData>* cur = this->first_;    // 初始化cur(遍历指针), 指向首结点

    for (int i = 1; i < pos; i++) {                         // for loop 遍历pos - 1次
        cur = cur->next;                                    // cur指向cur->next
    }

    // ---------- 4 赋值 ----------

    data = cur->data;                                       // cur->data赋给参数data

    // ---------- 5 退出函数 ----------

    return true;                                            // 返回true
}


/*!
 * @brief **设置结点数据**
 * @tparam TData 数据项类型模板参数
 * @param pos 位置
 * @param data 数据项
 * @return 执行结果
 * @note
 * 设置结点数据
 * ----------
 * ----------
 *
 * ----------
 * + **1 非法情况处理**\n
 * **if** pos < 1 || pos > 链表长度 :\n
 * &emsp; 返回false\n\n
 * + **2 遍历至pos位置结点**\n
 * 初始化cur(遍历指针), 指向首结点\n
 * **for loop** 遍历pos - 1次 :\n
 * &emsp; cur指向cur->next\n\n
 * + **3 赋值**\n
 * 参数data赋给cur->data\n\n
 * + **4 退出函数**\n
 * 返回true\n
 */
template<typename TData>
bool CircularDoublyLinkedList<TData>::SetData(int pos, const TData& data) {

    // ---------- 1 非法情况处理 ----------

    if (pos < 1 || pos > Length()) {                        // if pos < 1 || pos > 链表长度
        return false;                                       // 返回false
    }

    // ---------- 2 遍历至pos位置结点 ----------

    CircularDoublyLinkedNode<TData>* cur = this->first_;    // 初始化cur(遍历指针), 指向首结点

    for (int i = 1; i < pos; i++) {                         // for loop 遍历pos - 1次
        cur = cur->next;                                    // cur指向cur->next
    }

    // ---------- 3 赋值 ----------

    cur->data = data;                                       // 参数data, 赋给cur->data

    // ---------- 4 退出函数 ----------

    return true;                                            // 返回true
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
 * + **2 forward方向打印**\n
 * 打印 "next方向(forward)遍历打印："\n
 * 初始化cur(遍历指针), 指向first_\n
 * **for loop** 从位置1开始, next方向遍历链表 :\n
 * &emsp; 打印当前结点data和';'\n
 * &emsp; cur指向下一结点\n
 * **for loop** 从位置1开始, prev方向遍历链表 :\n
 * &emsp; 打印当前结点data和';'\n
 * &emsp; cur指向前一结点\n
 */
template<typename TData>
void CircularDoublyLinkedList<TData>::Print() {

    // ---------- 1 空链表处理 ----------

    if (this->first_ == NULL) {                             // if 空链表
        cout << "Empty list" << endl;                       // 打印"Empty list"
        return;                                             // 退出函数
    }

    // ---------- 2 forward方向打印 ----------

    cout << "next方向(forward)遍历打印：" << endl;            // 打印 "next方向(forward)遍历打印："
    CircularDoublyLinkedNode<TData>* cur = this->First();   // 初始化cur(遍历指针), 指向first_

    for (int pos = 1; pos <= Length(); pos++) {             // for loop 从位置1开始, next方向遍历链表
        cout << cur->data << "; ";                          // 打印当前结点data和';'
        cur = cur->next;                                    // cur指向下一结点
    }
    cout << endl;

    cout << "prev方向(backward)遍历打印：" << endl;
    for (int pos = 1; pos <= Length(); pos++) {             // for loop 从位置1开始, prev方向遍历链表
        cout << cur->data << "; ";                          // 打印当前结点data和';'
        cur = cur->prev;                                    // cur指向前一结点
    }
    cout << endl;
}


#endif // CYBER_DASH_CIRCULAR_DOUBLY_LINKED_LIST_H
