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
    CircularDoublyLinkedNode<TData>* Head() const { return this->first_; }

    // 搜索
    CircularDoublyLinkedNode<TData>* Search(const TData& data);

    // 获取结点(按方向)
    CircularDoublyLinkedNode<TData>* GetNodeByDirection(int step, int direction);

    // 获取结点
    CircularDoublyLinkedNode<TData>* GetNode(int pos);

    // 插入结点
    bool Insert(int pos, const TData& data);

    // 删除结点(按方向)
    bool RemoveByDirection(int step, TData& data, int direction);

    // 删除结点
    bool Remove(int pos, TData& data);

    // 获取结点数据
    bool GetData(int pos, TData& data) const;

    // 设置结点数据
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
 * @param step 步数
 * @param direction 方向
 * @return 结点指针
 * @note
 * 获取结点(按方向)
 * --------------
 * --------------
 *
 * CircularDoublyLinkedList::BACKWARD_DIRECTION, 从first_->next开始, 向next指针方向
 * CircularDoublyLinkedList::FORWARD_DIRECTION, 从first_->prev开始, 向prev指针方向
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

    if (step < 0 || step >= length_) {
        return NULL;
    }

    CircularDoublyLinkedNode<TData>* cur = first_;

    for (int i = 1; i <= step; i++) {
        if (direction == CircularDoublyLinkedList::BACKWARD_DIRECTION) {
            cur = cur->prev;
        } else {
            cur = cur->next;
        }
    }

    return cur;
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
 * 计算step = pos - 1\n
 * 按照FORWARD_DIRECTION方向, 调用GetDataByDirection\n
 */
template<typename TData>
CircularDoublyLinkedNode<TData>* CircularDoublyLinkedList<TData>::GetNode(int pos) {
    int step = pos - 1;
    return this->GetNodeByDirection(step, CircularDoublyLinkedList::FORWARD_DIRECTION);
}


/*!
 * @brief **插入结点**
 * @tparam TData 数据项类型模板参数
 * @param pos 位置
 * @param data 数据
 * @return 执行结果
 * 插入结点
 * -------
 * -------
 *
 * 在pos位置之后的位置插入
 *
 * -------
 */
template<typename TData>
bool CircularDoublyLinkedList<TData>::Insert(int pos, const TData& data) {

    if (Length() < pos || pos < 0) {
        return false;
    }

    // ----- II 生成新结点 -----
    CircularDoublyLinkedNode<TData>* insertion_node = new CircularDoublyLinkedNode<TData>(data);
    if (insertion_node == NULL) {     // if 生成结点失败
        return false;       // 返回false
    }

    if (first_ == NULL) {
        first_ = insertion_node;
        insertion_node->next = insertion_node;
        insertion_node->prev = insertion_node;
        this->length_ = 1;
        return true;
    }

    // ----- I 获取插入结点的前驱结点 -----
    CircularDoublyLinkedNode<TData>* cur = first_;
    for (int i = 1; i < pos; i++) {
        cur = cur->next;
    }

    // ----- III 执行插入 -----
    insertion_node->next = cur->next;     // insertion_node->next指向cur->next
    cur->next = insertion_node;           // cur->next指向node
    insertion_node->next->prev = insertion_node;    // insertion_node->next->prev指向node
    insertion_node->prev = cur;           // insertion_node->prev指向cur

    // ----- IV 链表长度调整 -----
    this->length_++;                        // 链表长度加1

    return true;
}


/*!
 * @brief **删除(结点)元素(按方向)**
 * @tparam TData 数据项类型模板参数
 * @param step 位置
 * @param data 数据项保存变量
 * @param direction 方向
 * @return 执行结果
 */
template<typename TData>
bool CircularDoublyLinkedList<TData>::RemoveByDirection(int step, TData &data, int direction) {
    CircularDoublyLinkedNode<TData>* cur = GetNodeByDirection(step, direction);
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
    int step = pos - 1;
    return this->RemoveByDirection(step, data, CircularDoublyLinkedList::FORWARD_DIRECTION);
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
