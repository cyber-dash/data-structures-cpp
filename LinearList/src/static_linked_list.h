/*!
 * @file static_linked_list.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 静态链表模板类
 * @version 0.2.1
 * @date 2022-11-18
 */

#ifndef CYBER_DASH_STATIC_LINKED_LIST_H
#define CYBER_DASH_STATIC_LINKED_LIST_H


/*! @brief 静态链表结点模板结构体 */
template <typename TData>
struct StaticLinkedListNode {
    int pos;       //!< 位置
    TData data;    //!< 数据项
    int next;      //!< 下一结点的索引
};


/*! @brief 静态链表模板类 */
template <typename TData>
class StaticLinkedList {
public:
    explicit StaticLinkedList(int capacity = 100);

    int GetNode(int pos) const;

    int Search(const TData& data) const;

    bool Insert(int pos, const TData& data);
private:
    int GetInsertIndex_();
    bool Extend_(int capacity);
    StaticLinkedListNode<TData>* mem_data_;    //!< 静态链表, mem_data_[0]为头结点(不保存元素)
    int length_;    //!< 静态链表长度
    int capacity_;  //!< 静态链表容量
};


template <typename TData>
StaticLinkedList<TData>::StaticLinkedList(int capacity) {
    capacity_ = capacity;
    length_ = 0;
    mem_data_ = new StaticLinkedListNode<TData>(capacity + 1);

    mem_data_[0].next = 1;
    for (int i = 1; i <= capacity; i++) {
        mem_data_[i].next = 0;
    }
}

template<typename TData>
int StaticLinkedList<TData>::GetNode(int pos) const {
    if (pos < 1 || pos > length_) {
        return 0;
    }

    int index = mem_data_[0].next;
    for (int i = 1; i < pos; i++) {
        index = mem_data_[index].next;
    }

    return index;
}

template<typename TData>
int StaticLinkedList<TData>::Search(const TData& data) const {

    if (length_ == 0) {
        return 0;
    }

    int index = mem_data_[0].next;
    bool existent = false;
    for (; index <= length_;) {
        if (mem_data_[index].data == data) {
            existent = true;
        }

        index = mem_data_[index].next;
    }

    if (existent) {
        return index;
    }

    return 0;
}


template <typename TData>
bool StaticLinkedList<TData>::Insert(int pos, const TData& data) {
    if (pos < 0 || pos > length_) {
        return false;
    }

    if (length_ == capacity_) {
        Extend_(capacity_);
    }

    int index = GetNode(pos);
}


template <typename TData>
bool StaticLinkedList<TData>::Extend_(int capacity) {
    capacity_ += capacity;
    StaticLinkedListNode<TData>* new_mem_data = new StaticLinkedListNode<TData>*(capacity_ + 1);
    if (!new_mem_data) {
        return false;
    }

    for (int i = 0; i <= length_ + 1; i++) {
        new_mem_data[i] = mem_data_[i];
    }

    delete[] mem_data_;
    mem_data_ = new_mem_data;
}


#endif // CYBER_DASH_STATIC_LINKED_LIST_H
