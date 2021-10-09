//
// Created by cyberdash@163.com on 2021/9/18.
//

#ifndef CYBER_DASH_HASH_TABLE_H
#define CYBER_DASH_HASH_TABLE_H


// todo: 此部分书上代码漏洞太多, 未测试

enum KindOfStatus { Active, Empty, Deleted }; // 桶的状态


template <class Elem, class Key>
class HashTableByLinearProbing {
public:
  HashTableByLinearProbing(int divisor, int size);
  ~HashTableByLinearProbing();
  HashTableByLinearProbing<Elem, Key>& operator=(const HashTableByLinearProbing<Elem, Key>& hash_table);

  //
  bool Search(const key key, Elem& elem) const;

  //
  bool Insert(const Elem& elem);

  // 在散列表中删除elem
  bool Remove(Key key, Elem& elem);

  // 散列表置空
  void MakeEmpty();

  //
  int TableSize() const { return this->table_size_; }

  //
  int CurrentSize() const { return this->current_size_; }

  //
  Elem* ElemTable() const;

  //
  KindOfStatus* StatusTable() const;

private:
  int divisor_; // 除数
  int current_size_; // 当前的size
  int table_size_; // 哈希表size
  Elem* elem_table_; // 元素表
  KindOfStatus* status_info_;
  int FindPos(const Key key) const;
  int operator == (Elem& elem);
  int operator != (Elem& elem);
};


template <class Elem, class Key>
HashTableByLinearProbing<Elem, Key>::HashTableByLinearProbing(int divisor, int size) {
  this->divisor_ = divisor;
  this->table_size_ = size;
  this->current_size_ = 0;
  this->elem_table_ = new Elem[this->table_size_];
  this->status_info_ = new KindOfStatus[this->table_size_];

  for (int i = 0; i < this->table_size_; i++) {
    this->status_info_[i] = Empty;
  }
}


/**
 * @brief 析构函数
 * @tparam Elem
 * @tparam Key
 */
template<class Elem, class Key>
HashTableByLinearProbing<Elem, Key>::~HashTableByLinearProbing() {
  delete[] this->elem_table_;
  delete[] this->status_info_;
}


/**
 * @brief 使用线性探查法
 * @tparam Elem 数据项模板类型
 * @tparam Key 关键码模板类型
 * @param key 关键码
 * @return 数据的索引值
 */
template <class Elem, class Key>
int HashTableByLinearProbing<Elem, Key>::FindPos(const Key key) const {

  int pos = key % this->divisor_;
  int i = pos;

  do {
    if (this->status_info_[i] == Active) && this->elem_table_[i] == key) {
      return i; // 找到存储key的桶, 返回
    }

    i = (i + 1) % this->table_size_; // 不在桶i内, 查桶i + 1

  } while (i != pos);

  return i; // 找了一圈桶没有找到
}


/**
 * @brief 使用线性探查法在散列表中搜索key
 * @tparam Elem
 * @tparam Key
 * @param key
 * @param elem
 * @return 是否存在于散列表中
 */
template <class Elem, class Key>
bool HashTableByLinearProbing<Elem, Key>::Search(const Key key, Elem& elem) {
  int pos = this->FindPos(key);

  if (this->status_info_[pos] != Active || this->elem_table_[pos] != key) {
    return false;
  }

  elem = this->elem_table_[pos];

  return true;
}


template <class Elem, class Key>
void HashTableByLinearProbing<Elem, Key>::MakeEmpty() {
  for (int i = 0; i < this->table_size_; i++) {
    this->status_info_[i] = Empty;
  }

  this->current_size_ = 0;
}


template <class Elem, class Key>
HashTableByLinearProbing<Elem, Key>& HashTableByLinearProbing<Elem, Key>::operator=(const HashTableByLinearProbing<Elem, Key>& hash_table) {
  if (this == &hash_table) {
    return *this;
  }

  delete[] this->table_size_;
  delete[] this->status_info_;

  this->table_size_ = hash_table.TableSize();
  this->elem_table_ = new Elem[this->table_size_];
  this->status_info_ = new KindOfStatus[this->table_size_];

  for (int i = 0; i < this->table_size_; i++) {
    this->table_[i] = hash_table.ElemTable()[i];
    this->status_info_[i] = hash_table.StatusTable()[i];
  }

  this->current_size_ = hash_table.CurrentSize();
}


/**
 * @brief
 * @tparam Elem
 * @tparam Key
 * @param elem
 * @return
 */
template <class Elem, class Key>
bool HashTableByLinearProbing<Elem, Key>::Insert(const Elem& elem) {
  Key key = elem;
  int pos = this->FindPos(key);

  if (this->StatusTable()[pos] == Active && this->ElemTable()[pos] == elem) {
    cout<<"表中已有此元素, 不能插入"<<endl;
    return false;
  }

  this->elem_table_[pos] = elem;
  this->status_info_[pos] = Active;
  this->current_size_++;

  return true;
}


template<class Elem, class Key>
bool HashTableByLinearProbing<Elem, Key>::Remove(const Key key, Elem& elem) {
  int pos = this->FindPos(key);

  if (this->status_info_[pos] == Active && this->ElemTable()[pos] == key) {
    this->status_info_[pos] = Deleted;
    this->current_size_--;

    elem = key;

    return true;
  }

  return false;
}


/**
 * @brief 获取elem_table_数组起始地址
 * @tparam Elem 模板数据类型
 * @tparam Key 关键码模板类型
 * @return elem_table_数组的地址
 */
template<class Elem, class Key>
Elem *HashTableByLinearProbing<Elem, Key>::ElemTable() const {
  return this->elem_table_;
}


/**
 * @brief 获取status_info_数组的起始地址
 * @tparam Elem
 * @tparam Key
 * @return
 */
template<class Elem, class Key>
KindOfStatus *HashTableByLinearProbing<Elem, Key>::StatusTable() const {
  return this->status_info_;
}


#endif // CYBER_DASH_HASH_TABLE_H
