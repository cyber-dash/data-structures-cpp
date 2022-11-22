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

    int Length() { return length_; }

    bool IsEmpty() { return length_ == 0; }

    bool Search(const TData& data, int& pos) const;

    bool Insert(int pos, const TData& data);

    bool Remove(int pos, TData& data);

    void Print();

    static const int NOT_IN_USE = -1;
    static const int HEAD = 0;

private:
    int GetInsertIndex_() const;
    bool Extend_(int capacity);
    int GetNodeIndex_(int pos) const;

    StaticLinkedListNode<TData>* mem_data_;    //!< 静态链表, mem_data_[0]为头结点(不保存元素)
    int length_;    //!< 静态链表长度
    int capacity_;  //!< 静态链表容量
};


template <typename TData>
StaticLinkedList<TData>::StaticLinkedList(int capacity) {
    capacity_ = capacity;
    length_ = 0;
    mem_data_ = new StaticLinkedListNode<TData>[capacity + 1];

    mem_data_[HEAD].next = HEAD;
    for (int i = 1; i <= capacity; i++) {
        mem_data_[i].next = StaticLinkedList<TData>::NOT_IN_USE;
    }
}


template<typename TData>
int StaticLinkedList<TData>::GetNodeIndex_(int pos) const {
    if (pos < 1 || pos > length_) {
        return 0;
    }

    int index = mem_data_[HEAD].next;
    for (int i = 1; i < pos; i++) {
        index = mem_data_[index].next;
    }

    return index;
}

template<typename TData>
// int StaticLinkedList<TData>::Search(const TData& data) const {
 bool StaticLinkedList<TData>::Search(const TData& data, int& pos) const {

    if (length_ == 0) {
        return false;
    }

    int cur_pos = 1;
    for (int i = mem_data_[0].next; i <= length_; i = mem_data_[i].next) {
        if (i == 0) {
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

    int index = GetNodeIndex_(pos);
    int insert_index = GetInsertIndex_();
    if (insert_index == HEAD) {
        return false;
    }

    mem_data_[insert_index].next = mem_data_[index].next;
    mem_data_[index].next = insert_index;
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
    mem_data_[delete_index].next = NOT_IN_USE;

    data = mem_data_[delete_index].data;

    length_--;

    return true;
}


template<typename TData>
void StaticLinkedList<TData>::Print() {
    if (length_ == 0) {
        cout << "Empty list" << endl;
    }

    for (int cur = mem_data_[0].next; cur != 0; cur = mem_data_[cur].next) {
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

    for (int i = 0; i <= length_ + 1; i++) {
        new_mem_data[i] = mem_data_[i];
    }

    delete[] mem_data_;
    mem_data_ = new_mem_data;

    return true;
}



template <typename TData>
int StaticLinkedList<TData>::GetInsertIndex_() const {
    if (length_ == capacity_) {
        return 0;
    }

    for (int pos = 1; pos <= length_ + 1; pos++) {
        if (mem_data_[pos].next == StaticLinkedList<TData>::NOT_IN_USE) {
            return pos;
        }
    }

    return 0;
}


#endif // CYBER_DASH_STATIC_LINKED_LIST_H
