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
class CircularDoublyLinkedList : public LinearList<TData> {
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
    CircularDoublyLinkedNode<TData>* Head() const { return this->first_; }

    // 搜索
    CircularDoublyLinkedNode<TData>* Search(const TData& data);

    // 获取结点(按方向)
    CircularDoublyLinkedNode<TData>* GetNodeByDirection(int pos, int direction);

    // 获取结点(按next方向)
    CircularDoublyLinkedNode<TData>* GetNode(int pos);

    // 插入结点(按方向)
    bool InsertByDirection(int pos, const TData& data, int direction);

    // 插入结点(按next方向)
    bool Insert(int pos, const TData& data);

    // 删除结点(按方向)
    bool RemoveByDirection(int pos, TData& data, int direction);

    // 删除结点(按next方向)
    bool Remove(int pos, TData& data);

    // 获取结点数据(按next方向)
    bool GetData(int pos, TData& data) const;

    // 设置结点数据(按next方向)
    bool SetData(int pos, const TData& data);

    // 打印
    void Print();

    static const int BACKWARD_DIRECTION = 0;    // prev方向
    static const int FORWARD_DIRECTION = 1;     // next方向

private:
    CircularDoublyLinkedNode<TData>* first_;     // 首元素结点(指针)
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
 *
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
    while (first_ != NULL) {
        CircularDoublyLinkedNode<TData>* deletion_node = this->first_;
        first_ = deletion_node->next;

        delete deletion_node;                                         // 释放cur指向的结点
        deletion_node = NULL;
    }

    this->length_ = 0;
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
 * @brief 搜索
 * @param data 数据
 * @return 结点指针
 * @note
 * 返回数据项等于数据的结点,
 * 若没有, 则返回NULL
 */
template<typename TData>
CircularDoublyLinkedNode<TData>* CircularDoublyLinkedList<TData>::Search(const TData& data) {
    CircularDoublyLinkedNode<TData>* cur = this->first_;
    for (int pos = 1; pos <= this->Length(); pos++, cur = cur->next) {
        if (cur->data == data) {
            return cur;
        }
    }

    return NULL;
}


/*!
 * @brief 获取结点(按方向)
 * @param pos 位置
 * @param direction 方向
 * @return 结点指针
 * @note
 * 获取结点(按方向)
 * --------------
 * --------------
 *
 * CircularDoublyLinkedList::BACKWARD_DIRECTION, 从head->next_开始, 向next指针方向找位置
 * CircularDoublyLinkedList::BACKWARD_DIRECTION, 从head->next_开始, 向prev指针方向找位置
 * 链表结点从1开始, 当pos为0时, 返回first_结点的地址
 *
 * --------------
 * **I&nbsp;&nbsp; 位置0处理** \n
 * **II&nbsp; 位置溢出处理** \n
 * **III 按方向遍历至pos位置** \n
 */
template<typename TData>
CircularDoublyLinkedNode<TData>* CircularDoublyLinkedList<TData>::GetNodeByDirection(int pos, int direction) {

    if (pos <= 0 || length_ < pos) {
        return NULL;
    }

    CircularDoublyLinkedNode<TData>* cur = first_;

    for (int i = 1; i < pos; i++) {
        if (direction == CircularDoublyLinkedList::BACKWARD_DIRECTION) {
            cur = cur->prev;
        } else {
            cur = cur->next;
        }
    }

    return cur;
}


/*!
 * @brief **获取结点(forward方向)**
 * @tparam TData 数据项类型模板参数
 * @param pos 位置
 * @return 结点指针
 * 获取结点(forward方向)
 * -------------------
 * -------------------
 *
 * -------------------
 * 使用DoublyLinkedList::FORWARD_DIRECTION, 调用GetDataByDirection
 */
template<typename TData>
CircularDoublyLinkedNode<TData>* CircularDoublyLinkedList<TData>::GetNode(int pos) {
    return this->GetNodeByDirection(pos, CircularDoublyLinkedList::FORWARD_DIRECTION);
}


/*!
 * @brief 插入(按方向)
 * @tparam TData 数据项类型模板参数
 * @param pos 位置
 * @param data 数据
 * @param direction 方向
 * @return 执行结果
 * 插入(按方向)
 * ----------
 * ----------
 *
 * 在pos位置插入, 原本pos位置和之后的元素向后移动
 * CircularDoublyLinkedList::BACKWARD_DIRECTION, 从head->next开始, 向next指针方向找插入位置, 并插入
 * CircularDoublyLinkedList::BACKWARD_DIRECTION, 从head->next开始, 向prev指针方向找插入位置, 并插入
 *
 * ----------
 */
template<typename TData>
bool CircularDoublyLinkedList<TData>::InsertByDirection(int pos, const TData& data, int direction) {

    if (Length() < pos || pos < 0) {
        return false;
    }

    // ----- II 生成新结点 -----
    CircularDoublyLinkedNode<TData>* node = new CircularDoublyLinkedNode<TData>(data);
    if (node == NULL) {     // if 生成结点失败
        return false;       // 返回false
    }

    if (first_ == NULL) {
        first_ = node;
        node->next = node;
        node->prev = node;
        this->length_ = 1;
        return true;
    }

    // ----- I 获取插入结点的前驱结点 -----
    CircularDoublyLinkedNode<TData>* cur = first_;
    for (int i = 1; i < pos; i++) {
        if (direction == CircularDoublyLinkedList::BACKWARD_DIRECTION) {
            cur = cur->prev;
        } else if (direction == CircularDoublyLinkedList::FORWARD_DIRECTION) {
            cur = cur->next;
        }
    }

    // ----- III 执行插入 -----
    if (direction == CircularDoublyLinkedList::BACKWARD_DIRECTION) {        // if 向prev指针方向插入(backward):
        node->prev = cur->prev;     // node->prev指向cur->prev
        cur->prev = node;           // cur->prev指向node
        node->prev->next = node;    // node->prev->next指向node
        node->next = cur;           // node->next指向cur
    } else if (direction == CircularDoublyLinkedList::FORWARD_DIRECTION) { // else if** 向next指针方向插入(backward):
        node->next = cur->next;     // node->next指向cur->next
        cur->next = node;           // cur->next指向node
        node->next->prev = node;    // node->next->prev指向node
        node->prev = cur;           // node->prev指向cur
    }

    // ----- IV 链表长度调整 -----
    this->length_++;                        // 链表长度加1

    return true;
}


/*!
 * @brief **插入(forward方向)**
 * @tparam TData 数据项类型模板参数
 * @param pos 位置
 * @param data 数据
 * @return 执行结果
 * 插入(forward方向)
 * ----------------
 * ----------------
 *
 * ----------------
 * 使用DoublyLinkedList::FORWARD_DIRECTION调用InsertByDirection
 */
template<typename TData>
bool CircularDoublyLinkedList<TData>::Insert(int pos, const TData& data) {
    return this->InsertByDirection(pos, data, CircularDoublyLinkedList::FORWARD_DIRECTION);
}


/*!
 * @brief **删除(结点)元素(按方向)**
 * @tparam TData 数据项类型模板参数
 * @param pos 位置
 * @param data 数据项保存变量
 * @param direction 方向
 * @return 执行结果
 */
template<typename TData>
bool CircularDoublyLinkedList<TData>::RemoveByDirection(int pos, TData &data, int direction) {
    CircularDoublyLinkedNode<TData>* cur = GetNodeByDirection(pos, direction);
    if (cur == NULL) {
        return false;
    }

    if (Length() == 1) {
        data = cur->data;

        delete cur;
        this->first_ = NULL;

        length_ = 0;

        return true;
    }

    if (cur == first_) {
        if (direction == CircularDoublyLinkedList<TData>::FORWARD_DIRECTION) {
            first_ = cur->next;
        } else if (direction == CircularDoublyLinkedList<TData>::BACKWARD_DIRECTION) {
            first_ = cur->prev;
        }
    }

    cur->next->prev = cur->prev;
    cur->prev->next = cur->next;
    data = cur->data;

    delete cur;
    cur = NULL;

    this->length_--;

    return true;
}


template<typename TData>
bool CircularDoublyLinkedList<TData>::Remove(int pos, TData& data) {
    return this->RemoveByDirection(pos, data, CircularDoublyLinkedList::FORWARD_DIRECTION);
}


/*!
 * @brief 获取结点数据
 * @tparam TData 类型模板参数
 * @param pos 位置
 * @param data 数据
 * @return 是否获取成功
 */
template<typename TData>
bool CircularDoublyLinkedList<TData>::GetData(int pos, TData& data) const {
    if (pos < 1 || pos > Length()) {
        return false;
    }

    CircularDoublyLinkedNode<TData>* cur = this->first_;

    while (pos > 1) {
        cur = cur->next;
        pos--;
    }

    data = cur->data;

    return true;
}


/*!
 * @brief 设置结点数据
 * @tparam TData 类型模板参数
 * @param pos 位置
 * @param data 数据
 * @return 是否设置成功
 */
template<typename TData>
bool CircularDoublyLinkedList<TData>::SetData(int pos, const TData& data) {

    if (pos < 1 || pos > Length()) {
        return false;
    }

    CircularDoublyLinkedNode<TData>* cur = this->first_;

    while (pos > 1) {
        cur = cur->next;
        pos--;
    }

    cur->data = data;

    return true;
}


/*!
 * @brief 打印双向链表
 * @tparam TData 类型模板参数
 */
template<typename TData>
void CircularDoublyLinkedList<TData>::Print() {
    if (this->first_ == NULL) {
        cout << "Empty list" << endl;
        return;
    }

    cout << "向next方向(forward)遍历输出：" << endl;
    CircularDoublyLinkedNode<TData>* cur = this->Head();
    for (int pos = 1; pos <= Length(); pos++) {
        cout << cur->data << "; ";
        cur = cur->next;
    }
    cout << endl;

    cout << "向prev方向(backward)遍历输出：" << endl;
    for (int pos = 1; pos <= Length(); pos++) {
        cout << cur->data << "; ";
        cur = cur->prev;
    }
    cout << endl;
}


#endif // CYBER_DASH_CIRCULAR_DOUBLY_LINKED_LIST_H
