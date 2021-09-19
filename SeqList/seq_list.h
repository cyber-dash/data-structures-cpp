//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/7/14.
//

#ifndef CYBER_DASH_SEQ_LIST_H
#define CYBER_DASH_SEQ_LIST_H


#include <iostream>
#include <cstdlib>
#include "LinearList.h"


using namespace std;


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
  bool SetData(int pos, const T& data) const;
  bool Insert(int i, const T& x);
  bool Remove(int i, T& x);
  bool IsEmpty();
  bool IsFull();
  int Resize(int new_size);
  void Input();
  void Sort();
  void Output();
  SeqList<T>& operator= (const SeqList<T>& seq_list);
  void CyberDashShow();

private:
  T* data_array_;
  int max_size_;
  int last_idx_;
};


template<class T>
SeqList<T>::SeqList() {
  data_array_ = NULL;
  max_size_ = 0;
  last_idx_ = -1;
}


/**
 * 构造函数
 * @tparam T 顺序表元素类型
 * @param size 顺序表size
 */
template<class T>
SeqList<T>::SeqList(int size) {

  if (size > 0) {
    max_size_ = size;
    last_idx_ = -1;
  }

  data_array_ = new T[max_size_];
  if (data_array_ == NULL) {
    cerr<<"new error"<<endl;
    exit(1);
  }
}


template<class T>
SeqList<T>::SeqList(SeqList<T>& seq_list) {

  max_size_ = seq_list.Size();
  last_idx_ = seq_list.Length() - 1;

  T cur_value;

  data_array_ = new T[max_size_];
  if (data_array_ == NULL) {
    cerr<<"存储分配错误!"<<endl;
    exit(1);
  }

  for (int i = 1; i <= last_idx_ + 1; i++) {
    seq_list.GetData(i, cur_value);
    data_array_[i - 1] = cur_value;
  }
}


template<class T>
int SeqList<T>::Resize(int new_size) {

  if (new_size <= 0) {
    cerr<<"无效的数组大小"<<endl;
    return -1;
  }

  if (new_size == max_size_) {
    cout<<"重分配数组长度与原数组长度相同"<<endl;
    return 0;
  }

  T* new_array = new T[max_size_];
  if (new_array == NULL) {
    cerr<<"存储分配错误"<<endl;
    return -2;
  }

  T* src_ptr = data_array_;
  T* dest_ptr = new_array;

  for (int i = 0; i <= last_idx_; i++) {
    *(dest_ptr + i) = *(src_ptr + i);
  }

  delete [] data_array_;
  data_array_ = new_array;

  max_size_ = new_size;

  return new_size;
}


template<class T>
int SeqList<T>::Search(T& data) const {

  int pos = 0; // not array index

  for (int i = 0; i <= last_idx_; i++) {
    if (data_array_[i] == data) {
      pos = i + 1;
      break;
    }
  }

  return pos;
}


template<class T>
int SeqList<T>::Locate(int pos) const {
  if (pos >= 1 && pos <= last_idx_ + 1) {
    return pos;
  } else {
    return 0;
  }
};


template<class T>
bool SeqList<T>::GetData(int pos, T& data) const {
  if (pos > 0 && pos <= last_idx_ + 1) {
    data = data_array_[pos - 1];
    return true;
  } else {
    return false;
  }
}


template<class T>
// bool SeqList<T>::SetData(int pos, T& data) const {
bool SeqList<T>::SetData(int pos, const T& data) const {
  if (pos > 0 && pos <= last_idx_ + 1) {
    data_array_[pos - 1] = data;
    return true;
  } else {
    return false;
  }
}


template<class T>
bool SeqList<T>::Insert(int pos, const T& data) {

  if (last_idx_ == max_size_ - 1) {
    return false;
  }

  if (pos < 0 || pos > last_idx_ + 1) {
    return false;
  }

  for (int i = last_idx_; i >= pos; i--) {
    data_array_[i + 1] = data_array_[i];
  }

  data_array_[pos] = data;

  last_idx_++;

  return true;
}


template<class T>
bool SeqList<T>::Remove(int pos, T& remove_data) {

  if (last_idx_ == -1) {
    return false;
  }

  if (pos < 1 || pos > last_idx_ + 1) {
    return false;
  }

  remove_data = data_array_[pos - 1];

  for (int i = pos; i <= last_idx_; i++) {
    data_array_[i - 1] = data_array_[i];
  }

  last_idx_--;

  return true;
}


template<class T>
bool SeqList<T>::IsEmpty() {
  if (last_idx_ == -1) {
    return true;
  } else {
    return false;
  }
}


template<class T>
bool SeqList<T>::IsFull() {
  if (last_idx_ == max_size_ - 1) {
    return true;
  } else {
    return false;
  }
}


template<class T>
SeqList<T>& SeqList<T>::operator=(const SeqList<T>& seq_list) {

  this->max_size_ = seq_list.Size();
  int p_length = seq_list.Length();

  for (int i = 0; i < p_length; i++) {
    int curData;
    seq_list.GetData(i, curData);

    this->SetData(i, curData);
  }

  return *this;
}


template<class T>
int SeqList<T>::Size() const {
  return max_size_;
}


template<class T>
int SeqList<T>::Length() const {
  return last_idx_ + 1;
}


template<class T>
void SeqList<T>::Output() {

  // cout<<"顺序表最后元素位置:"<<last_idx_ + 1<<endl;

  if (last_idx_ == -1) {
    cout<<"顺序表为空表:"<<endl;
  } else {
    for (int i = 0; i <= last_idx_; i++) {
      cout<<"#"<<i + 1<<":"<<data_array_[i]<<endl;
    }
  }

}


template<class T>
void SeqList<T>::Sort() {

    int length = this->Length();
    for (int i = 1; i < length; i++) {
        for (int j = 1; j <= length - i; j++) {

            T j_data;
            this->GetData(j, j_data);

            T j_next_data;
            this->GetData(j + 1, j_next_data);

            if (j_data > j_next_data) {
                this->SetData(j, j_next_data);
                this->SetData(j + 1, j_data);
            }
        }
    }
}


template<class T>
void SeqList<T>::CyberDashShow() {
  cout<<endl
      <<"*************************************** CyberDash ***************************************"<<endl<<endl
      <<"抖音号\"CyberDash计算机考研\", id: cyberdash_yuan"<<endl<<endl
      <<"CyberDash成员:"<<endl
      <<"元哥(cyberdash@163.com), "<<"北京邮电大学(通信工程本科)/北京邮电大学(信息与通信系统研究生)"<<endl
      <<"磊哥(alei_go@163.com), "<<"山东理工大学(数学本科)/北京邮电大学(计算机研究生)"<<endl<<endl
      <<"数据结构开源代码(C++清华大学殷人昆)魔改升级版本: https://gitee.com/cyberdash/data-structure-cpp"<<endl
      <<endl<<"*************************************** CyberDash ***************************************"<<endl<<endl;
}

#endif //CYBER_DASH_YUAN_SEQ_LIST_H
