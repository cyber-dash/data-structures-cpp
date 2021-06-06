//
// Created by cyberdash@163.com on 2021/5/31.
//

#ifndef CYBER_DASH_SORTED_LIST_H
#define CYBER_DASH_SORTED_LIST_H


#include "data_list.h"


template<class Elem, class Key>
class SortedList: public DataList<Elem, Key> {
public:
  SortedList(int size = DEFAULT_SIZE): DataList<Elem, Key>(size) {}
  ~SortedList() {}
  int SeqSearch(const Key& key) const;
  int BinarySearch(const Key& key) const;
  int BinarySearchRecursive(const Key& key, int low, int high) const;
  bool Insert(const Key& key, const Elem& elem);
  int Begin() { return (this->current_size_ == 0) ? 0 : 1; }
  int Next(int i) { return (i >= 1 && i <= this->current_size_) ? i + 1 : 0; }
};


template<class Elem, class Key>
int SortedList<Elem, Key>::SeqSearch(const Key& key) const {
  for (int i = 1; i <= this->current_size_; i++) {
    if (this->element_array_[i - 1].GetKey() == key) {
      return i;
    } else if (this->element_array_[i - 1].GetKey() > key) {
      break;
    }
  }

  return 0;
}


template<class Elem, class Key>
bool SortedList<Elem, Key>::Insert(const Key& key, const Elem& elem) {
  if (this->current_size_ >= this->array_size_) {
    return false;
  }

  int insert_pos = 1;
  while (insert_pos <= this->current_size_ && this->element_array_[insert_pos - 1].GetKey() <= key) {
    insert_pos++;
  }

  for (int i = this->current_size_; i >= insert_pos; i--) {
    this->element_array_[i] = this->element_array_[i - 1];
  }

  this->element_array_[insert_pos - 1].SetKey(key);
  this->element_array_[insert_pos - 1].SetElem(elem);

  this->current_size_++;
}


template<class Elem, class Key>
int SortedList<Elem, Key>::BinarySearch(const Key& key) const {

  int high = this->current_size_ - 1;
  int low = 0;
  int mid;

  while (low <= high) {
    mid = (low + high) / 2;

    if (key > this->element_array_[mid].GetKey()) {
      low = mid +1;
    } else if (key < this->element_array_[mid].GetKey()) {
      high = mid - 1;
    } else {
      return mid + 1;
    }
  }

  return 0;
}


template<class Elem, class Key>
int SortedList<Elem, Key>::BinarySearchRecursive(const Key& key, int low, int high) const {

  int mid = 0;

  if (low <= high) {
    mid = (low + high) / 2;
    if (key == this->element_array_[mid - 1].GetKey()) {
      return mid;
    } else if (key > this->element_array_[mid - 1].GetKey()) {
      mid = BinarySearchRecursive(key, mid + 1, high);
    } else if (key < this->element_array_[mid - 1].GetKey()) {
      mid = BinarySearchRecursive(key, low, mid - 1);
    }
  }

  return mid;
}


#endif // CYBER_DASH_SORTED_LIST_H
