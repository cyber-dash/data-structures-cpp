/*!
 * @file doubly_linked_list.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 双向循环链表
 * @version 0.2.1
 * @date 2020-07-28
 * @copyright Copyright (c) 2021
 * **CyberDash计算机考研**
 */

#ifndef CYBER_DASH_DOUBLY_LINKED_LIST_H
#define CYBER_DASH_DOUBLY_LINKED_LIST_H


#include <iostream>
#include <cstddef>
#include "linear_list.h"


 /*!
  * @brief **双向循环链表结点模板类**
  * @tparam TData 数据项类型模板参数
  */
template <typename TData>
struct DoublyLinkedNode {
    /*!
     * @brief **构造函数(next与prev)**
     * @param next 下一结点(指针)
     * @param prev 上一结点(指针)
     */
    explicit DoublyLinkedNode(DoublyLinkedNode<TData>* next = NULL, DoublyLinkedNode<TData>* prev = NULL) : prev(prev), next(next) {}

    /*!
     * @brief **构造函数(data, next和prev)**
     * @param data 数据项
     * @param next 下一结点指针
     * @param prev 上一结点指针
     */
    explicit DoublyLinkedNode(const TData& data, DoublyLinkedNode<TData>* next = NULL, DoublyLinkedNode<TData>* prev = NULL) :
        data(data), prev(prev), next(next) {}

    TData data;                       //!< 数据项
    DoublyLinkedNode<TData>* next;    //!< 下一结点
    DoublyLinkedNode<TData>* prev;    //!< 上一结点
};


/*!
 * @brief **双向循环链表模板类**
 * @tparam TData 数据项类型模板参数
 */
template<typename TData>
class DoublyLinkedList : public LinearList<TData> {
public:
    // 默认构造函数
    DoublyLinkedList();

    // 析构函数
    ~DoublyLinkedList();

    /*! @brief **长度** */
    int Length() const { return this->length_; }

    /*! @brief **判断链表是否为空** */
    bool IsEmpty() const { return this->head_->next == this->head_; }

    /*! @brief 获取链表头结点 */
    DoublyLinkedNode<TData>* Head() const { return this->head_; }

    // 搜索
    DoublyLinkedNode<TData>* Search(const TData& data);

    // 获取结点(按方向)
    DoublyLinkedNode<TData>* GetNodeByDirection(int pos, int direction);

    // 定位
    DoublyLinkedNode<TData>* GetNode(int pos);

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

    //约瑟夫环
    int JosephProblem(DoublyLinkedNode<TData>* head, int m);

    // 打印双向链表
    void Print();

    // 我们是CyberDash
    void CyberDashShow();

    static const int BACKWARD_DIRECTION = 0;
    static const int FORWARD_DIRECTION = 1;

private:
    DoublyLinkedNode<TData>* head_;
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
DoublyLinkedList<TData>::DoublyLinkedList() {
    this->head_ = NULL;

    this->length_ = 0;
}


/*!
 * @brief **析构函数**
 * @note
 * 析构函数
 * -------
 * -------
 *
 * <span style="color:#FF8100">
 *
 * </span>
 *
 * -------
 * **I&nbsp;&nbsp; 清空链表**\n
 * **while** head_->next未指向head_ :\n
 * &emsp; 声明指针cur, 指向head_->next\n
 * &emsp; head_->next指向cur->next\n
 * &emsp; 释放cur指向的结点\n
 * **II**&nbsp; 删除head_\n
 * &emsp; 释放head_结点\n
 */
template<typename TData>
DoublyLinkedList<TData>::~DoublyLinkedList() {

    while (head_ != NULL) {
        DoublyLinkedNode<TData>* cur = this->head_;
        head_ = cur->next;

        delete cur;                                         // 释放cur指向的结点
        cur = NULL;
    }
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
DoublyLinkedNode<TData>* DoublyLinkedList<TData>::Search(const TData& data) {
    DoublyLinkedNode<TData>* cur = this->head_;
    for (int pos = 1; pos <= this->Length(); pos++) {
        if (cur->data == data) {
            return cur;
        }
    }

    /*
    while (cur != this->head_ && cur->data != data) {
        cur = cur->next;
    }

    if (cur != this->head_) {
        return cur;
    }
     */

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
 * DoublyLinkedList::BACKWARD_DIRECTION, 从head->next_开始, 向next指针方向找位置
 * DoublyLinkedList::BACKWARD_DIRECTION, 从head->next_开始, 向prev指针方向找位置
 * 链表结点从1开始, 当pos为0时, 返回head_结点的地址
 *
 * --------------
 * **I&nbsp;&nbsp; 位置0处理** \n
 * **II&nbsp; 位置溢出处理** \n
 * **III 按方向遍历至pos位置** \n
 */
template<typename TData>
DoublyLinkedNode<TData>* DoublyLinkedList<TData>::GetNodeByDirection(int pos, int direction) {

    if (pos == 0) {
        return NULL;
    }

    if (this->Length() < pos) {
        return NULL;
    }

    DoublyLinkedNode<TData>* cur = head_;
    /*
    if (direction == DoublyLinkedList::BACKWARD_DIRECTION) {
        cur = head_->prev;
    } else if (direction == DoublyLinkedList::FORWARD_DIRECTION) {
        cur = head_->next;
    }
     */

    for (int i = 1; i < pos; i++) {
        /*
        if (cur == this->head_) {
            return NULL;
        }
         */

        if (direction == DoublyLinkedList::BACKWARD_DIRECTION) {
            cur = cur->prev;
        } else {
            cur = cur->next;
        }
    }

    /*
    if (cur != this->head_) {
        return cur;
    }
     */

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
DoublyLinkedNode<TData>* DoublyLinkedList<TData>::GetNode(int pos) {
    return this->GetNodeByDirection(pos, DoublyLinkedList::FORWARD_DIRECTION);
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
 * DoublyLinkedList::BACKWARD_DIRECTION, 从head->next开始, 向next指针方向找插入位置, 并插入
 * DoublyLinkedList::BACKWARD_DIRECTION, 从head->next开始, 向prev指针方向找插入位置, 并插入
 *
 * ----------
 */
template<typename TData>
bool DoublyLinkedList<TData>::InsertByDirection(int pos, const TData& data, int direction) {

    if (Length() < pos) {
        return false;
    }

    // ----- II 生成新结点 -----
    DoublyLinkedNode<TData>* node = new DoublyLinkedNode<TData>(data);
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
    DoublyLinkedNode<TData>* cur = head_;
    for (int i = 0; i < pos; i++) {
        if (direction == DoublyLinkedList::BACKWARD_DIRECTION) {
            cur = cur->prev;
        } else if (direction == DoublyLinkedList::FORWARD_DIRECTION) {
            cur = cur->next;
        }
    }

    // ----- III 执行插入 -----
    if (direction == DoublyLinkedList::BACKWARD_DIRECTION) {        // if 向prev指针方向插入(backward):
        node->prev = cur->prev;     // node->prev指向cur->prev
        cur->prev = node;           // cur->prev指向node
        node->prev->next = node;    // node->prev->next指向node
        node->next = cur;           // node->next指向cur
    } else if (direction == DoublyLinkedList::FORWARD_DIRECTION) { // else if** 向next指针方向插入(backward):
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
bool DoublyLinkedList<TData>::Insert(int pos, const TData& data) {
    return this->InsertByDirection(pos, data, DoublyLinkedList::FORWARD_DIRECTION);
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
bool DoublyLinkedList<TData>::RemoveByDirection(int pos, TData &data, int direction) {
    DoublyLinkedNode<TData>* cur = GetNodeByDirection(pos, direction);
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
        if (direction == DoublyLinkedList<TData>::FORWARD_DIRECTION) {
            head_ = cur->next;
        } else if (direction == DoublyLinkedList<TData>::BACKWARD_DIRECTION) {
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


template<typename T>
bool DoublyLinkedList<T>::Remove(int pos, T& data) {
    return this->RemoveByDirection(pos, data, DoublyLinkedList::FORWARD_DIRECTION);
}


/*!
 * @brief 获取结点数据
 * @tparam T 类型模板参数
 * @param pos 位置
 * @param data 数据
 * @return 是否获取成功
 */
template<typename T>
bool DoublyLinkedList<T>::GetData(int pos, T& data) const {
    if (pos < 1 || pos > Length()) {
        return false;
    }

    DoublyLinkedNode<T>* cur = this->head_;

    while (pos > 1) {
        cur = cur->next;
        pos--;
    }

    data = cur->data;

    return true;
}


/*!
 * @brief 设置结点数据
 * @tparam T 类型模板参数
 * @param pos 位置
 * @param data 数据
 * @return 是否设置成功
 */
template<typename T>
bool DoublyLinkedList<T>::SetData(int pos, const T& data) {

    if (pos < 1 || pos > Length()) {
        return false;
    }

    DoublyLinkedNode<T>* cur = this->head_;

    while (pos > 1) {
        cur = cur->next;
        pos--;
    }

    cur->data = data;

    return true;
}

/*!
 * @brief 约瑟夫环问题
 * @param head 首位结点
 * @param m 数到m就出列
 * @return 剩余的结点值
 */
template<typename T>
int DoublyLinkedList<T>::JosephProblem(DoublyLinkedNode<T>* head, int m) {
    return -1; // todo: 
}


/*!
 * @brief 打印双向链表
 * @tparam T 类型模板参数
 */
template<typename T>
void DoublyLinkedList<T>::Print() {
    if (this->head_ == NULL) {
        cout << "Empty list" << endl;
        return;
    }

    cout << "向前遍历输出：" << endl;
    DoublyLinkedNode<T>* cur = this->Head();
    /*
    while (cur != this->head_) {
        cout << cur->data << "; ";
        cur = cur->next;
    }
     */
    for (int pos = 1; pos <= Length(); pos++) {
        cout << cur->data << "; ";
        cur = cur->next;
    }
    cout << endl;

    /*
    cout << "向前遍历输出" << endl;
    cur = cur->prev;
    while (cur != this->head_) {
        cout << cur->data << "; ";
        cur = cur->prev;
    }
     */
    cout << "向后遍历输出：" << endl;
    for (int pos = 1; pos <= Length(); pos++) {
        cout << cur->data << "; ";
        cur = cur->prev;
    }
    cout << endl;
}




template<typename T>
void DoublyLinkedList<T>::CyberDashShow() {
    cout << endl
        << "*************************************** CyberDash ***************************************" << endl << endl
        << "抖音号\"CyberDash计算机考研\", id: cyberdash_yuan" << endl << endl
        << "CyberDash成员:" << endl
        << "元哥(cyberdash@163.com), " << "北京邮电大学(通信工程本科)/北京邮电大学(信息与通信系统研究生)" << endl
        << "磊哥(alei_go@163.com), " << "山东理工大学(数学本科)/北京邮电大学(计算机研究生)" << endl << endl
        << "L_Dash(lyu2586@163.com), " << "北京邮电大学(计算机在读研究生)" << endl << endl
        << "数据结构开源代码(C++清华大学殷人昆)魔改升级版本: https://gitee.com/cyberdash/data-structure-cpp" << endl
        << endl << "*************************************** CyberDash ***************************************" << endl << endl;
}



#endif // CYBER_DASH_DOUBLY_LINKED_LIST_H
