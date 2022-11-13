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
  * @brief **双向循环链表结点模板类**
  * @tparam TData 数据项类型模板参数
  */
template <typename TData>
struct CircularDoublyLinkedNode {
    /*!
     * @brief **构造函数(next与prev)**
     * @param next 下一结点(指针)
     * @param prev 上一结点(指针)
     */
    explicit CircularDoublyLinkedNode(CircularDoublyLinkedNode<TData>* next = NULL, CircularDoublyLinkedNode<TData>* prev = NULL) :
        prev(prev), next(next) {}

    /*!
     * @brief **构造函数(data, next和prev)**
     * @param data 数据项
     * @param next 下一结点指针
     * @param prev 上一结点指针
     */
    explicit CircularDoublyLinkedNode(const TData& data, CircularDoublyLinkedNode<TData>* next = NULL, CircularDoublyLinkedNode<TData>* prev = NULL) :
        data(data), prev(prev), next(next) {}

    TData data;                               //!< 数据项
    CircularDoublyLinkedNode<TData>* next;    //!< 下一结点
    CircularDoublyLinkedNode<TData>* prev;    //!< 上一结点
};


/*!
 * @brief **双向循环链表模板类**
 * @tparam TData 数据项类型模板参数
 */
template<typename TData>
class CircularDoublyLinkedList : public LinearList<TData> {
public:
    // 默认构造函数
    CircularDoublyLinkedList();

    // 析构函数
    ~CircularDoublyLinkedList();

    /*! @brief **长度** */
    int Length() const { return this->length_; }

    /*! @brief **判断链表是否为空** */
    bool IsEmpty() const { return this->head_ == NULL; }

    // 清空链表
    void Clear();

    /*! @brief 获取链表头结点 */
    CircularDoublyLinkedNode<TData>* Head() const { return this->head_; }

    // 搜索
    CircularDoublyLinkedNode<TData>* Search(const TData& data);

    // 获取结点(按方向)
    CircularDoublyLinkedNode<TData>* GetNodeByDirection(int pos, int direction);

    // 定位
    CircularDoublyLinkedNode<TData>* GetNode(int pos);

    // 按方向插入
    bool InsertByDirection(int pos, const TData& data, int direction);

    // 向后插入
    bool Insert(int pos, const TData& data);

    // 按方向删除结点
    bool RemoveByDirection(int pos, TData& data, int direction);

    // 向后删除节点
    bool Remove(int pos, TData& data);

    // 获取结点数据
    bool GetData(int pos, TData& data) const;

    // 设置结点数据
    bool SetData(int pos, const TData& data);

    // 打印双向链表
    void Print();

    static const int BACKWARD_DIRECTION = 0;
    static const int FORWARD_DIRECTION = 1;

private:
    CircularDoublyLinkedNode<TData>* head_;
    int length_;
};


/*!
 * @brief **默认构造函数**
 * @note
 * 默认构造函数
 * ----------
 * ----------
 *
 * ----------
 */
template<typename TData>
CircularDoublyLinkedList<TData>::CircularDoublyLinkedList() {
    this->head_ = NULL;
    this->length_ = 0;
}


/*!
 * @brief **清空链表**
 * @note
 * 清空链表
 * -------
 * -------
 *
 * <span style="color:#FF8100">
 *
 * </span>
 *
 * -------
 * **I&nbsp;&nbsp; 清空链表**\n
 * **while** head_不为NULL:\n
 * &emsp; 声明指针cur, 指向head_\n
 * &emsp; head_指向cur->next\n
 * &emsp; 释放cur指向的结点\n
 * **II&nbsp; 调整长度**\n
 * length_设置为0\n
 */
template<typename TData>
void CircularDoublyLinkedList<TData>::Clear() {
    while (head_ != NULL) {
        CircularDoublyLinkedNode<TData>* cur = this->head_;
        head_ = cur->next;

        delete cur;                                         // 释放cur指向的结点
        cur = NULL;
    }

    this->length_ = 0;
}


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
    CircularDoublyLinkedNode<TData>* cur = this->head_;
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
 * 链表结点从1开始, 当pos为0时, 返回head_结点的地址
 *
 * --------------
 * **I&nbsp;&nbsp; 位置0处理** \n
 * **II&nbsp; 位置溢出处理** \n
 * **III 按方向遍历至pos位置** \n
 */
template<typename TData>
CircularDoublyLinkedNode<TData>* CircularDoublyLinkedList<TData>::GetNodeByDirection(int pos, int direction) {

    if (pos == 0) {
        return NULL;
    }

    if (this->Length() < pos) {
        return NULL;
    }

    CircularDoublyLinkedNode<TData>* cur = head_;

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

    if (head_ == NULL) {
        head_ = node;
        node->next = node;
        node->prev = node;
        this->length_ = 1;
        return true;
    }

    // ----- I 获取插入结点的前驱结点 -----
    CircularDoublyLinkedNode<TData>* cur = head_;
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
        this->head_ = NULL;

        return true;
    }

    if (cur == head_) {
        if (direction == CircularDoublyLinkedList<TData>::FORWARD_DIRECTION) {
            head_ = cur->next;
        } else if (direction == CircularDoublyLinkedList<TData>::BACKWARD_DIRECTION) {
            head_ = cur->prev;
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

    CircularDoublyLinkedNode<TData>* cur = this->head_;

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

    CircularDoublyLinkedNode<TData>* cur = this->head_;

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
    if (this->head_ == NULL) {
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

    cout << "向prev方向(FORWARD)遍历输出：" << endl;
    for (int pos = 1; pos <= Length(); pos++) {
        cout << cur->data << "; ";
        cur = cur->prev;
    }
    cout << endl;
}


#endif // CYBER_DASH_CIRCULAR_DOUBLY_LINKED_LIST_H
