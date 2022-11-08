/*!
 * @file doubly_linked_list.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 双向链表(循环)
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
  * @brief 双向链表结点模板类
  * @tparam T 类型模板参数
  */
template <class T>
struct DoublyLinkedNode {
    /*!
     * @brief 构造函数(下一结点与上一结点指针)
     * @param next 下一结点指针
     * @param prev 上一结点指针
     */
    explicit DoublyLinkedNode(DoublyLinkedNode<T>* next = NULL, DoublyLinkedNode<T>* prev = NULL) : prev(prev), next(next) {}

    /*!
     * @brief 构造函数(数据项, 上一结点和下一结点指针)
     * @param data 数据项
     * @param next 下一结点指针
     * @param prev 上一结点指针
     */
    explicit DoublyLinkedNode(const T& data, DoublyLinkedNode<T>* next = NULL, DoublyLinkedNode<T>* prev = NULL) :
        data(data), prev(prev), next(next) {}

    T data; //!< 链表数据项
    DoublyLinkedNode<T>* next; //!< 下一结点
    DoublyLinkedNode<T>* prev; //!< 上一结点
};


/*!
 * @brief 双向链表模板类
 * @tparam T 类型模板参数
 */
template<class T>
class DoublyLinkedList : public LinearList<T> {
public:
    /*! @brief 构造函数(无参数) */
    DoublyLinkedList();

    /*! @brief 析构函数 */
    ~DoublyLinkedList();

    /*! @brief 长度 */
    int Length() const { return this->length_; }

    /*! @brief 是否为空 */
    bool IsEmpty() const { return this->head_->next == this->head_; }

    /*! @brief 获取链表头结点 */
    DoublyLinkedNode<T>* Head() const { return this->head_; }

    // 搜索
    DoublyLinkedNode<T>* Search(const T& data);

    // 按方向定位
    DoublyLinkedNode<T>* LocateByDirection(int pos, int direction);

    // 定位
    DoublyLinkedNode<T>* Locate(int pos);

    // 按方向插入
    bool InsertByDirection(int pos, const T& data, int direction);

    // 向后插入
    bool Insert(int pos, const T& data);

    // 按方向删除结点
    bool RemoveByDirection(int pos, T& data, int direction);

    // 向后删除节点
    bool Remove(int pos, T& data);

    // 获取结点数据
    bool GetData(int pos, T& data) const;

    // 设置结点数据
    bool SetData(int pos, const T& data);

    //约瑟夫环
    int JosephProblem(DoublyLinkedNode<T>* head, int m);

    // 打印双向链表
    void Print();

    // 我们是CyberDash
    void CyberDashShow();

    static const int PREV_DIRECTION = 0;
    static const int NEXT_DIRECTION = 1;

private:
    DoublyLinkedNode<T>* head_;
    int length_;
};


/*!
 * @brief 构造函数(无参数)
 */
template<class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    this->head_ = new DoublyLinkedNode<T>();
    /* error handler */

    this->head_->next = this->head_;
    this->head_->prev = this->head_;

    this->length_ = 0;
}


/*!
 * @brief 析构函数
 */
template<class T>
DoublyLinkedList<T>::~DoublyLinkedList() {

    while (this->head_->next != this->head_) {
        DoublyLinkedNode<T>* delete_node = this->head_->next;
        this->head_->next = delete_node->next;

        delete delete_node;
    }

    delete this->head_;
    this->head_ = NULL;
}


/*!
 * @brief 搜索
 * @param data 数据
 * @return 结点指针
 * @note
 * 返回数据项等于数据的结点,
 * 若没有, 则返回NULL
 */
template<class T>
DoublyLinkedNode<T>* DoublyLinkedList<T>::Search(const T& data) {
    DoublyLinkedNode<T>* cur = this->head_->next;
    while (cur != this->head_ && cur->data != data) {
        cur = cur->next;
    }

    if (cur != this->head_) {
        return cur;
    }

    return NULL;
}


/*!
 * @brief 按方向定位
 * @param pos 位置
 * @param direction 方向(0为向前，非0为向后)
 * @return 结点指针
 * @note
 * 书上的逻辑
 * 如果是空链表, 当定位位置0时, 返回头节点的地址
 * 如果不是空链表
 *  定位到, 则返回地址
 *  定位不到, 返回NULL
 */
template<class T>
DoublyLinkedNode<T>* DoublyLinkedList<T>::LocateByDirection(int pos, int direction) {

    if (this->head_->next == head_ || pos == 0) {
        return this->head_;
    }

    DoublyLinkedNode<T>* cur;
    if (direction == DoublyLinkedList::PREV_DIRECTION) {
        cur = head_->prev;
    }
    else {
        cur = head_->next;
    }

    for (int i = 1; i < pos; i++) {
        if (cur == this->head_) {
            return NULL;
        }

        if (direction == DoublyLinkedList::PREV_DIRECTION) {
            cur = cur->prev;
        } else {
            cur = cur->next;
        }
    }

    if (cur != this->head_) {
        return cur;
    }

    return NULL;
}


/*!
 * @brief 向后定位
 * @tparam T 类型模板参数
 * @param pos 位置
 * @return 结点指针
 */
template<class T>
DoublyLinkedNode<T>* DoublyLinkedList<T>::Locate(int pos) {
    return this->LocateByDirection(pos, DoublyLinkedList::NEXT_DIRECTION);
}


/*!
 * @brief 按方向插入
 * @tparam T 类型模板参数
 * @param pos 位置
 * @param data 数据
 * @param direction 方向
 * @return 是否插入成功
 */
template<class T>
bool DoublyLinkedList<T>::InsertByDirection(int pos, const T& data, int direction) {

    DoublyLinkedNode<T>* cur = LocateByDirection(pos, direction);
    if (cur == NULL) {
        return false;
    }

    DoublyLinkedNode<T>* new_node = new DoublyLinkedNode<T>(data);
    if (new_node == NULL) {
        return false;
    }

    if (direction == DoublyLinkedList::PREV_DIRECTION) {
        new_node->prev = cur->prev;
        cur->prev = new_node;
        new_node->prev->next = new_node;
        new_node->next = cur;
    } else {
        new_node->next = cur->next;
        cur->next = new_node;
        new_node->next->prev = new_node;
        new_node->prev = cur;
    }

    this->length_++;

    return true;
}


/*!
 * @brief 向后插入
 * @tparam T 类型模板参数
 * @param pos 位置
 * @param data 数据
 * @return 是否插入成功
 */
template<class T>
bool DoublyLinkedList<T>::Insert(int pos, const T& data) {
    return this->InsertByDirection(pos, data, DoublyLinkedList::NEXT_DIRECTION);
}


/*!
 * @brief 按方向删除结点
 * @tparam T 类型模板参数
 * @param pos 位置
 * @param data 数据(保存被删除结点数据项)
 * @param direction 方向
 * @return 是否删除成功
 */
template<class T>
bool DoublyLinkedList<T>::RemoveByDirection(int pos, T& data, int direction) {
    DoublyLinkedNode<T>* cur = LocateByDirection(pos, direction);
    if (cur == NULL) {
        return false;
    }

    cur->next->prev = cur->prev;
    cur->prev->next = cur->next;
    data = cur->data;

    delete cur;
    this->length_--;

    return true;
}


/*!
 * @brief 向后删除节点
 * @tparam T 类型模板参数
 * @param pos 位置
 * @param data 数据(保存被删除结点数据项)
 * @return 是否删除成功
 */
template<class T>
bool DoublyLinkedList<T>::Remove(int pos, T& data) {
    return this->RemoveByDirection(pos, data, DoublyLinkedList::NEXT_DIRECTION);
}


/*!
 * @brief 获取结点数据
 * @tparam T 类型模板参数
 * @param pos 位置
 * @param data 数据
 * @return 是否获取成功
 */
template<class T>
bool DoublyLinkedList<T>::GetData(int pos, T& data) const {
    if (pos < 1 || pos > Length()) {
        return false;
    }

    DoublyLinkedNode<T>* cur = this->head_;

    while (pos > 0) {
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
template<class T>
bool DoublyLinkedList<T>::SetData(int pos, const T& data) {

    if (pos < 1 || pos > Length()) {
        return false;
    }

    DoublyLinkedNode<T>* cur = this->head_;

    while (pos > 0) {
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
template<class T>
int DoublyLinkedList<T>::JosephProblem(DoublyLinkedNode<T>* head, int m) {
    return -1; // todo: 
}


/*!
 * @brief 打印双向链表
 * @tparam T 类型模板参数
 */
template<class T>
void DoublyLinkedList<T>::Print() {
    if (this->head_ == NULL) {
        cout << "Empty list" << endl;
        return;
    }

    cout << "向后遍历输出：" << endl;
    DoublyLinkedNode<T>* cur = this->Head()->next;
    while (cur != this->head_) {
        cout << cur->data << "; ";
        cur = cur->next;
    }
    cout << endl;

    cout << "向前遍历输出" << endl;
    cur = cur->prev;
    while (cur != this->head_) {
        cout << cur->data << "; ";
        cur = cur->prev;
    }
    cout << endl;

    cout << endl;
}




template<class T>
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
