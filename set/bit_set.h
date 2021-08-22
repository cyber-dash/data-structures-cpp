//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2021/5/16.
//

#ifndef CYBER_DASH_BIT_SET_H
#define CYBER_DASH_BIT_SET_H

// #include<assert.h>
#include<iostream>


// enum bool {false,true};
const int DefaultSize = 50;


template<typename T>
class BitSet: public Set<T> {
public:

  BitSet(int size = DefaultSize);
  BitSet(const BitSet<T>& bit_set);
  ~BitSet(){ delete[] bit_vector_; };
  void makeEmpty();
  bool GetMember(const T &x);
  void PutMember(const T &x, int v);
  bool AddMember(const T &x);
  bool DelMember(const T &x);
  BitSet<T>& operator = (const BitSet<T> &R);
  BitSet<T> operator + (const BitSet<T> &R);
  BitSet<T> operator * (const BitSet<T> &R);
  BitSet<T> operator - (const BitSet<T> &R);
  bool Contains(const T x);
  bool SubSet(BitSet<T>& bit_set);
  bool operator == (BitSet<T>& bit_set);
  friend istream& operator >> (istream &in, BitSet<T>& bit_set);
  friend ostream& operator << (ostream &out, BitSet<T>& bit_set);

private:
  int set_size_;
  int vector_size_;
  unsigned short* bit_vector_;
};


template<typename T>
void BitSet<T>::makeEmpty() {
  for (int i = 0; i < vector_size_; i++)
  {
    bit_vector_[i]=0;
  }
}

template<typename T>
BitSet<T>::BitSet(int size) {

}

template<typename T>
BitSet<T>::BitSet(const BitSet<T> &bit_set) {

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

ostream &operator<<(ostream &out, BitSet<T> &bit_set) {
  return <#initializer#>;
}

istream &operator>>(istream &in, BitSet<T> &bit_set) {
  return <#initializer#>;
}


#endif // CYBER_DASH_BIT_SET_H
