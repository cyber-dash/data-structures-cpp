//
// Created by cyberdash@163.com on 2021/5/17.
//

#ifndef MAIN_DATA_LIST_H
#define MAIN_DATA_LIST_H


#include <iostream>

using namespace std;


const int DEFAULT_SIZE = 100;

// template<class Elem, class Key>
// class DataList;


template<class Elem, class Key>
class DataNode {
  // friend class DataList<Elem, Key>;
public:
  DataNode() {};
  DataNode(const Key& key): key_(key) {}
  DataNode(const Key& key, const Elem& elem): key_(key), elem_(elem) {}
  Key GetKey() const { return key_; }
  void SetKey(Key key) { key_ = key; }

  Elem GetElem() const { return elem_; }
  void SetElem(Elem elem) { elem_ = elem; }
private:
  Key key_;
  Elem elem_;
};


template<class Elem, class Key>
class DataList {
public:
  DataList(int size = DEFAULT_SIZE): array_size_(size), current_size_(0)
  {
    element_array_ = new DataNode<Elem, Key>();
    /* error handler */
  }
  DataList(DataList<Elem, Key>& data_list);

  virtual ~DataList() { delete[] element_array_; }
  virtual int Length() { return current_size_; }
  virtual bool GetKey(int i, Key& key) const;
  virtual bool SetKey(int i, Key key);
  virtual int SeqSearch(const Key key) const = 0;
  virtual bool Insert(Elem& elem);
  virtual bool Remove(const Key key, Elem& elem);

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
bool DataList<Elem, Key>::Insert(Elem& elem) {
  if (current_size_ == array_size_) {
    return false;
  }

  // element_array_[current_size_] = elem;
  element_array_[current_size_].SetElem(elem);
  current_size_++;

  return true;
}


template<class Elem, class Key>
bool DataList<Elem, Key>::Remove(const Key key, Elem& elem) {
  if (current_size_ == 0) {
    return false;
  }

  int i = 0;
  for (int i = 0; i < current_size_ && element_array_[i].GetElem() != elem; i++) {
  }

  if (i == current_size_) {
    return false;
  }

  elem = element_array_[i].GetElem();

  element_array_[i] = element_array_[current_size_ - 1];
  current_size_--;

  return true;
}

/*
template<class Elem, class Key>
int DataList<Elem, Key>::SeqSearch(const Key key) const {
  return 0;
}
 */


#endif //MAIN_DATA_LIST_H
