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
class BitSet: public Set<T> {
public:

  BitSet(int size);
  BitSet(const BitSet<T>& bit_set);

  // 析构函数
  ~BitSet() { delete[] this->bit_vector_; };

  // 置空集合
  void MakeEmpty();

  int GetSetSize();
  void SetSetSize(int set_size);

  int GetVectorSize();
  void SetVectorSize(int vector_size);

  unsigned short GetMember(const T& x);
  void PutMember(const T& x, int v);
  bool AddMember(const T& x);
  bool DelMember(const T& x);
  bool Contains(T x);
  bool SubSet(BitSet<T>& bit_set);

  BitSet<T>& operator = (const BitSet<T>& bit_set);
  BitSet<T>& operator + (const BitSet<T>& bit_set);
  BitSet<T>& operator * (const BitSet<T>& bit_set);
  BitSet<T>& operator - (const BitSet<T>& bit_set);
  bool operator == (BitSet<T>& bit_set);

  friend istream& operator >> (istream &in, BitSet<T>& bit_set);
  friend ostream& operator << (ostream &out, BitSet<T>& bit_set);

private:
  int set_size_; // 集合大小
  int vector_size_; // 位数组大小
  unsigned short* bit_vector_; // 存储集合元素的位数组
};


template<typename T>
void BitSet<T>::MakeEmpty() {
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
BitSet<T>::BitSet(int size): set_size_(size) {
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
BitSet<T>::BitSet(const BitSet<T>& src_bit_set) {
  this->set_size_ = src_bit_set.set_size_;
  this->vector_size_ = src_bit_set.
}


template<typename T>
bool BitSet<T>::GetMember(const T &x) {
  return false;
}

template<typename T>
void BitSet<T>::PutMember(const T &x, int v) {

}

template<typename T>
bool BitSet<T>::AddMember(const T &x) {
  return false;
}

template<typename T>
bool BitSet<T>::DelMember(const T &x) {
  return false;
}

template<typename T>
BitSet<T> &BitSet<T>::operator=(const BitSet<T> &R) {
  return <#initializer#>;
}

template<typename T>
BitSet<T> BitSet<T>::operator+(const BitSet<T> &R) {
  return BitSet<T>();
}

template<typename T>
BitSet<T> BitSet<T>::operator*(const BitSet<T> &R) {
  return BitSet<T>();
}

template<typename T>
BitSet<T> BitSet<T>::operator-(const BitSet<T> &R) {
  return BitSet<T>();
}

template<typename T>
bool BitSet<T>::Contains(const T x) {
  return false;
}

template<typename T>
bool BitSet<T>::SubSet(BitSet<T> &bit_set) {
  return false;
}

template<typename T>
bool BitSet<T>::operator==(BitSet<T> &bit_set) {
  return false;
}

istream &operator>>(istream &in, BitSet<T> &bit_set) {
  return <#initializer#>;
}

ostream &operator<<(ostream &out, BitSet<T> &bit_set) {
  return <#initializer#>;
}

istream &operator>>(istream &in, BitSet<T> &bit_set) {
  return <#initializer#>;
}


#endif // CYBER_DASH_BIT_SET_H
