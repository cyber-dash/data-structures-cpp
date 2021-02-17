//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/7/14.
//

#ifndef CYBER_DASH_YUAN_SEQ_LIST_H
#define CYBER_DASH_YUAN_SEQ_LIST_H


#include <iostream>
#include <cstdlib>
#include "LinearList.h"


const int kDefaultSize = 100;


template<class T>
class SeqList: public LinearList<T> {

public:
  SeqList();
  SeqList(int sz = kDefaultSize);
  SeqList(SeqList<T>& L);
  ~SeqList() { delete[] data_array_; }
  int Size() const;
  int Length() const;
  int Search(T& x) const;
  int Locate(int pos) const;
  bool GetData(int pos, T& data) const;
  bool SetData(int pos, T& data) const;
  bool Insert(int i, T& x);
  bool Remove(int i, T& x);
  bool IsEmpty();
  bool IsFull();
  int Resize(int new_size);
  void Input();
  void Output();
  SeqList<T>& operator = (const SeqList<T>& L);
  void CyberDashShow();

private:
  T* data_array_;
  int max_size_;
  int last_idx_;
};


#endif //CYBER_DASH_YUAN_SEQ_LIST_H
