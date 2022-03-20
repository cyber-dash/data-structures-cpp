//
// Created by cyberdash@163.com on 2021/5/17.
//

#ifndef MAIN_DATA_LIST_H
#define MAIN_DATA_LIST_H


#include <iostream>

using namespace std;


const int DEFAULT_SIZE = 100;


template<class Elem, class Key>
class DataNode {
public:
    DataNode() {};
    DataNode(const Key& key) : key_(key) {}
    DataNode(const Key& key, const Elem& elem) : key_(key), elem_(elem) {}
    Key GetKey() const { return key_; }
    void SetKey(const Key& key) { key_ = key; }

    Elem GetElem() const { return elem_; }
    void SetElem(const Elem& elem) { elem_ = elem; }
private:
    Key key_;
    Elem elem_;
};


template<class Elem, class Key>
class DataList {
public:
    DataList(int size = DEFAULT_SIZE) : array_size_(size), current_size_(0)
    {
        element_array_ = new DataNode<Elem, Key>[size];
        /* error handler */
    }
    DataList(DataList<Elem, Key>& data_list);

    virtual ~DataList() { delete[] element_array_; }
    virtual int Length() { return current_size_; }
    virtual bool GetKey(int i, Key& key) const;
    virtual bool SetKey(int i, Key key);
    virtual int SeqSearch(const Key& key) const = 0;
    virtual bool Insert(const Key& key, const Elem& elem);
    virtual bool Remove(const Key& key, Elem& elem);

    template<class U>
    friend int operator << (ostream& out, const DataList<Elem, Key>& data_list);

    template<class U>
    friend int operator >> (ostream& in, DataList<Elem, Key>& data_list);

protected:
    DataNode<Elem, Key>* element_array_;
    int array_size_;
    int current_size_;
};


template<class Elem, class Key>
bool DataList<Elem, Key>::GetKey(int i, Key& key) const {
    if (i < 0 || i > current_size_) {
        return false;
    }

    key = element_array_[i - 1].GetKey();

    return true;
}


template<class Elem, class Key>
bool DataList<Elem, Key>::SetKey(int i, Key key) {
    if (i < 0 || i > current_size_) {
        return false;
    }

    element_array_[i - 1].SetKey(key);

    return true;
}


template<class Elem, class Key>
bool DataList<Elem, Key>::Insert(const Key& key, const Elem& elem) {
    if (current_size_ == array_size_) {
        return false;
    }

    element_array_[current_size_].SetKey(key);
    element_array_[current_size_].SetElem(elem);
    current_size_++;

    return true;
}


template<class Elem, class Key>
bool DataList<Elem, Key>::Remove(const Key& key, Elem& elem) {
    if (current_size_ == 0) {
        return false;
    }

    // 遍历, 找到对应elem相同的, 如果没有则遍历至数组索引current_size_
    int i;
    for (i = 0; i < current_size_ && element_array_[i].GetKey() != key; i++) {
    }

    if (i == current_size_) {
        return false;
    }

    elem = element_array_[i].GetElem();

    element_array_[i] = element_array_[current_size_ - 1];
    current_size_--;

    return true;
}


#endif // MAIN_DATA_LIST_H
