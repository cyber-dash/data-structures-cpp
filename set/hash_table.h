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
  KindOfStatus* info_;
  int FindPos(const Key key) const;
  int operator == (Elem& elem);
  int operator != (Elem& elem);
};

#endif // CYBER_DASH_HASH_TABLE_H
