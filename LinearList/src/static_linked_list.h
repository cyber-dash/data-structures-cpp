/*!
 * @file static_linked_list.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 静态链表模板类
 * @version 0.2.1
 * @date 2022-11-18
 */

#ifndef CYBER_DASH_STATIC_LINKED_LIST_H
#define CYBER_DASH_STATIC_LINKED_LIST_H


#include <iostream>


using namespace std;


/*! @brief 静态链表结点模板结构体 */
template <typename TData>
struct StaticLinkedListNode {
    StaticLinkedListNode<TData>() : next(0) {}
    explicit StaticLinkedListNode<TData>(TData data) : data(data), next(0) {}
    StaticLinkedListNode<TData>(TData data, int next) : data(data), next(next) {}

    TData data;    //!< 数据项
    int next;      //!< 下一结点的索引
};


/*! @brief 静态链表模板类 */
template <typename TData>
class StaticLinkedList {
public:
    explicit StaticLinkedList(int capacity = 100);

    int Length() const { return length_; }

    int Capacity() const { return capacity_; }

    bool IsEmpty() const { return length_ == 0; }

    bool Search(const TData& data, int& pos) const;

    bool Insert(int pos, const TData& data);

    bool Remove(int pos, TData& data);

    void Print() const;

    static const int NONE = -1;
    static const int HEAD = 0;

private:
    bool GetInsertIndex_(int& index) const;
    bool Extend_(int capacity);
    bool GetNodeIndexByPos_(int pos, int& index) const;

    StaticLinkedListNode<TData>* mem_data_;    //!< 静态链表, mem_data_[0]为头结点(不保存元素)
    int length_;                               //!< 静态链表长度
    int capacity_;                             //!< 静态链表容量
};


/*!
 * @brief **构造函数(容量)**
 * @tparam TData 数据项类型模板参数
 * @param capacity 容量
 * @note
 * 构造函数(容量)
 * ------------
 * ------------
 *
 * ------------
 * + **1 初始化成员变量**\n
 * capacity_(容量)使用参数进行初始化\n
 * length_(当前长度)初始化为0\n
 * mem_data_分配内存, capacity_ + 1个元素, 首元素为头结点\n
 * **if** mem_data_内存分配失败 :\n
 * &emsp; 抛出bad_alloc()异常\n
 * + **2 初始化结点**\n
 * HEAD结点的next指向HEAD(数组索引0)\n
 * **for loop** 数组索引从1到capacity :\n
 * &emsp; 每个数组元素的next指向NONE(索引值-1)\n
 */
template <typename TData>
StaticLinkedList<TData>::StaticLinkedList(int capacity) {
    capacity_ = capacity;
    length_ = 0;
    mem_data_ = new StaticLinkedListNode<TData>[capacity_ + 1];
    if (!mem_data_) {
        throw bad_alloc();
    }

    mem_data_[HEAD].next = HEAD;
    for (int i = 1; i <= capacity; i++) {
        mem_data_[i].next = StaticLinkedList<TData>::NONE;
    }
}


/*!
 * @brief **根据pos获取结点的数组索引**
 * @tparam TData 数据项类型模板参数
 * @param pos 位置
 * @param index 数组索引保存变量
 * @return 执行结果
 * @note
 * 根据pos获取结点的数组索引
 * ----------------------
 * ----------------------
 *
 * <span style="color:#FF8100">
 * pos为0时, 取静态链表head结点(数组索引0元素)\n
 * </span>
 * <span style="color:#038575">
 * (pos < 0)或者(pos > 链表长度)时, 返回false\n
 * </span>
 * <span style="color:#65000b">
 * pos为1时, 取链表第一个元素结点, 与数组的方式有区别\n
 * </span>
 *
 * ----------------------
 * + **1 pos非法情况处理**\n
 * + **2 pos为0情况处理**\n
 * + **3 遍历链表至相应位置并取索引**\n
 * + **4 退出函数**\n
 */
template<typename TData>
bool StaticLinkedList<TData>::GetNodeIndexByPos_(int pos, int& index) const {

    if (pos < 0|| pos > this->length_) {
        return false;
    }

    if (pos == 0) {
        index = HEAD;
        return true;
    }

    int cur_index = this->mem_data_[HEAD].next;
    for (int i = 1; i < pos; i++) {
        cur_index = this->mem_data_[cur_index].next;
    }

    index = cur_index;

    return true;
}


/*!
 * @brief **搜索**
 * @tparam TData 数据项类型模板参数
 * @param data 搜索数据
 * @param pos 位置
 * @return 执行结果
 * @note
 * 搜索
 * ---
 * ---
 *
 * ---
 * + **1 空链表处理**\n
 * + **2 遍历链表搜索**\n
 * + **3 返回false**\n
 */
template<typename TData>
 bool StaticLinkedList<TData>::Search(const TData& data, int& pos) const {

    if (length_ == 0) {
        return false;
    }

    int cur_pos = 1;
    for (int i = mem_data_[HEAD].next; i <= length_; i = mem_data_[i].next) {
        if (i == HEAD) {
            break;
        }

        if (mem_data_[i].data == data) {
            pos = cur_pos;
            return true;
        }

        cur_pos++;
    }

    return false;
}


template <typename TData>
bool StaticLinkedList<TData>::Insert(int pos, const TData& data) {
    if (pos < 0 || pos > length_) {
        return false;
    }

    if (length_ == capacity_) {
        this->Extend_(capacity_);
    }

    int prev_index;
    bool res = GetNodeIndexByPos_(pos, prev_index);
    if (!res) {
        return false;
    }

    int insert_index;
    res = GetInsertIndex_(insert_index);
    if (!res) {
        return false;
    }

    mem_data_[insert_index].next = mem_data_[prev_index].next;
    mem_data_[prev_index].next = insert_index;
    mem_data_[insert_index].data = data;

    length_++;

    return true;
}


template<typename TData>
bool StaticLinkedList<TData>::Remove(int pos, TData& data) {

    if (pos < 1 || pos > length_) {
        return false;
    }

    int prev_index = HEAD;
    for (int i = 1; i < pos; i++) {
        prev_index = mem_data_[prev_index].next;
    }

    int delete_index = mem_data_[prev_index].next;
    int next_index = mem_data_[delete_index].next;

    mem_data_[prev_index].next = next_index;
    mem_data_[delete_index].next = NONE;

    data = mem_data_[delete_index].data;

    length_--;

    return true;
}


template<typename TData>
void StaticLinkedList<TData>::Print() const {
    if (length_ == 0) {
        cout << "Empty list" << endl;
    }

    for (int cur = mem_data_[HEAD].next; cur != HEAD; cur = mem_data_[cur].next) {
        cout << mem_data_[cur].data;
        if (mem_data_[cur].next != HEAD) {
            cout << "-->";
        }
    }

    cout << endl;
}


template <typename TData>
bool StaticLinkedList<TData>::Extend_(int capacity) {
    capacity_ += capacity;
    StaticLinkedListNode<TData>* new_mem_data = new StaticLinkedListNode<TData>[capacity_ + 1];
    if (!new_mem_data) {
        return false;
    }

    for (int i = HEAD; i <= length_; i++) {
        new_mem_data[i] = mem_data_[i];
    }

    for (int i = length_ + 1; i <= capacity_; i++) {
        new_mem_data[i].next = NONE;
    }

    delete[] mem_data_;
    mem_data_ = new_mem_data;

    return true;
}



template <typename TData>
bool StaticLinkedList<TData>::GetInsertIndex_(int& index) const {
    if (length_ == capacity_) {
        return false;
    }

    for (int i = 1; i <= length_ + 1; i++) {
        if (mem_data_[i].next == StaticLinkedList<TData>::NONE) {
            index = i;
            return true;
        }
    }

    return false;
}


#endif // CYBER_DASH_STATIC_LINKED_LIST_H
