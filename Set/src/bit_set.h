//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2021/5/16.
//

#ifndef CYBER_DASH_BIT_SET_H
#define CYBER_DASH_BIT_SET_H

#include "set.h"
#include <iostream>

// enum bool {false,true};
// const int DefaultSize = 50;


template<typename T>
class LinkedSet: public Set<T> {
public:

  LinkedSet(int size);
  LinkedSet(const LinkedSet<T>& bit_set);

  // 析构函数
  ~LinkedSet() { delete[] this->bit_vector_; };

  // 置空集合
  void MakeEmpty();

  int GetSetSize();
  void SetSetSize(int set_size);

  int GetVectorSize();
  void SetVectorSize(int vector_size);

  unsigned short GetMember(const T& x);
  void PutMember(const T& x, int v);
  bool AddMember(const T& member);
  bool DelMember(const T& x);
  bool Contains(T x);
  bool SubSet(LinkedSet<T>& bit_set);

  LinkedSet<T>& operator = (const LinkedSet<T>& bit_set);
  LinkedSet<T>& operator + (const LinkedSet<T>& bit_set);
  LinkedSet<T>& operator * (const LinkedSet<T>& bit_set);
  LinkedSet<T>& operator - (const LinkedSet<T>& bit_set);
  bool operator == (LinkedSet<T>& bit_set);

  friend istream& operator >> (istream &in, LinkedSet<T>& bit_set);
  friend ostream& operator << (ostream &out, LinkedSet<T>& bit_set);

private:
  int set_size_; // 集合大小
  int vector_size_; // 位数组大小
  unsigned short* bit_vector_; // 存储集合元素的位数组
};


template<typename T>
void LinkedSet<T>::MakeEmpty() {
  for (int i = 0; i < this->vector_size_; i++) {
    this->bit_vector_[i]=0;
  }
}


/**
 * @brief 构造函数
 * @tparam T 模板数据类型
 * @param size 集合大小
 */
template<typename T>
LinkedSet<T>::LinkedSet(int size): set_size_(size) {
  this->vector_size_ = (this->set_size_ + 15) >> 4;
  this->bit_vector_ = new unsigned short [this->vector_size_];
  /* error handler */

  // init
  for (int i = 0; i < this->vector_size_; i++) {
    this->bit_vector_[i] = 0;
  }
}


/**
 * @brief 构造函数
 * @tparam T 模板数据类型
 * @param bit_set (源)集合
 */
template<typename T>
LinkedSet<T>::LinkedSet(const LinkedSet<T>& src_bit_set) {
  this->SetSetSize(src_bit_set.GetSetSize());
  this->SetVectorSize(src_bit_set.GetVectorSize());

  this->bit_vector_ = new unsigned short [this->vector_size_];
  /* error handler */

  // init
  for (int i = 0; i < this->vector_size_; i++) {
    this->bit_vector_[i] = 0;
  }
}


template<typename T>
unsigned short LinkedSet<T>::GetMember(const T &x) {
  int ad = x / 16;
  int id = x % 16;
  unsigned short elem = this->bit_vector_[ad];

  return ((elem >> (15 - id)) % 2);
}


template<typename T>
void LinkedSet<T>::PutMember(const T &x, int v) {
  int ad = x / 16;
  int id = x % 16;
  unsigned short elem = this->bit_vector_[ad];
  unsigned short temp = elem >> (15 - id);

  elem = elem << (id + 1);

  if (temp % 2 == 0 && v  == 0) {
    temp = temp + 1;
  } else if (temp % 2 == 1 && v == 0) {
    temp = temp - 1;
  }

  this->bit_vector_[ad] = (temp << (15 - id)) | (elem >> (id + 1))
}


template<typename T>
bool LinkedSet<T>::AddMember(const T& member) {
  if (member < 0 && member > this->set_size_ ) {
    return false;
  }
  
  if (this->GetMember(member) == 0) {
    this->PutMember(member, 1);
    return true;
  }

  return false;
}


template<typename T>
bool LinkedSet<T>::DelMember(const T &x) {
  if (member < 0 && member > this->set_size_ ) {
    return false;
  }

  if (this->GetMember(member) == 1) {
    this->PutMember(member, 0);
    return true;
  }

  return false;
}


// todo
template<typename T>
LinkedSet<T> &LinkedSet<T>::operator=(const LinkedSet<T> &R) {
  return <#initializer#>;
}


template<typename T>
LinkedSet<T> LinkedSet<T>::operator+(const LinkedSet<T> &R) {
  return <#initializer#>;
}


template<typename T>
LinkedSet<T> LinkedSet<T>::operator*(const LinkedSet<T> &R) {
  return <#initializer#>;
}


template<typename T>
LinkedSet<T> LinkedSet<T>::operator-(const LinkedSet<T> &R) {
  return LinkedSet<T>();
}


template<typename T>
bool LinkedSet<T>::Contains(const T x) {
  return false;
}


template<typename T>
bool LinkedSet<T>::SubSet(LinkedSet<T> &bit_set) {
  return false;
}


template<typename T>
bool LinkedSet<T>::operator==(LinkedSet<T> &bit_set) {
  return <#initializer#>;
}


istream &operator>>(istream &in, BitSet<T> &bit_set) {
  return <#initializer#>;
}


ostream& operator<<(ostream &out, BitSet<T> &bit_set) {
  return out;
}


istream& operator>>(istream &in, BitSet<T> &bit_set) {
  return in;
}


#endif // CYBER_DASH_BIT_SET_H
