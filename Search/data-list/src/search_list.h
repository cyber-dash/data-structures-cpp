//
// Created by cyberdash@163.com on 2021/5/29.
//

#ifndef CYBER_DASH_SEARCH_LIST_H
#define CYBER_DASH_SEARCH_LIST_H


#include "data_list.h"


template<class Elem, class Key>
class SearchList: public DataList<Elem, Key> {
public:
  SearchList(int size = DEFAULT_SIZE): DataList<Elem, Key>(size) {}
  int SeqSearch(const Key& key) const;
  virtual int SeqSearchRecursive(const Key& key, int pos) const;
};


/**
 * @brief 搜索关键码为key的数据元素
 * @tparam Elem
 * @tparam Key 搜索码模板类型
 * @param key 搜索码
 * @return 数据所在的位置
 */
template<class Elem, class Key>
int SearchList<Elem, Key>::SeqSearch(const Key& key) const {

  int i = 0;
  while (this->element_array_[i].GetKey() != key) {
    i++;
  }

  return i + 1;
}


template<class Elem, class Key>
int SearchList<Elem, Key>::SeqSearchRecursive(const Key& key, int pos) const {
  if (pos > this->current_size_) {
    return 0;
  }

  if (this->element_array_[pos - 1].GetKey() == key) {
    return pos;
  } else {
    return SeqSearchRecursive(key, pos + 1);
  }
}


#endif // CYBER_DASH_SEARCH_LIST_H
