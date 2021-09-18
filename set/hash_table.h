//
// Created by cyberdash@163.com on 2021/9/18.
//

#ifndef CYBER_DASH_HASH_TABLE_H
#define CYBER_DASH_HASH_TABLE_H


enum KindOfStatus { Active, Empty, Deleted };


template <class Elem, class Key>
class HashTable {
public:
  HashTable(int d, int size);
  ~HashTable();
  HashTable<Elem, Key>& operator=(const HashTable<Elem, Key>& hash_table);

  //
  bool Search(const key key, Elem& elem) const;

  //
  bool Insert(const Elem& elem);

  // 在散列表中删除elem
  bool Remove(const Key key, Elem& elem);

  // 散列表置空
  void MakeEmpty();
private:
  int divisor_;
  int current_size_;
  int table_size_;
  Elem* hash_table_;
  KindOfStatus* status_info_;
  int FindPos(const Key key) const;
  int operator == (Elem& elem);
  int operator != (Elem& elem);
};


template <class Elem, class Key>
HashTable<Elem, Key>::HashTable(int d, int size) {
  this->divisor_ = d;
  this->table_size_ = size;
  this->current_size_ = 0;
  this->hash_table_ = new Elem[this->table_size_];
  this->status_info_ = new KindOfStatus[this->table_size_];

  for (int i = 0; i < this->table_size_; i++) {
    this->status_info_[i] = Empty;
  }
}


template <class Elem, class Key>
int HashTable<Elem, Key>::FindPos(const Key key) const {
  int i = key % this->divisor_;
  int j = i;
  do {
    if (this->status_info_[j] == Empty || this->status_info_[j] == Active && this->hash_table_[j] == key) {
      return j;
    }

    j = (j + 1) % this->table_size_;

  } while (j != i);

  return j;
}

#endif // CYBER_DASH_HASH_TABLE_H
