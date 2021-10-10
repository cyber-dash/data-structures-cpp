/*!
 * @file seq_list.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 顺序表模板类
 * @version 0.2.1
 * @date 2021-09-28
 * @copyright Copyright (c) 2021
 * **CyberDash计算机考研**
 */

#ifndef CYBER_DASH_SEQ_LIST_H
#define CYBER_DASH_SEQ_LIST_H


#include <iostream>
#include <cstdlib>
#include "linear_list.h"


using namespace std;


/*!
 * @brief 顺序表模板类
 * @tparam T 类型模板参数
 */
template<class T>
class SeqList: public LinearList<T> {

public:
  // 构造函数(无参数)
  SeqList(): data_array_(NULL), size_(0), last_idx_(-1) {}

  // 构造函数(参数:顺序表总长度)
  SeqList(int size);

  // 复制构造函数(参数:顺序表)
  SeqList(SeqList<T>& seq_list);

  // 析构函数
  ~SeqList() { delete[] data_array_; }

  // 获取总长度
  int Size() const;

  // 获取当前长度
  int Length() const;

  // 搜索
  int Search(T& data) const;

  // 定位
  int Locate(int pos) const;

  // 获取位置pos的数据
  bool GetData(int pos, T& data) const;

  // 设置位置pos的数据
  bool SetData(int pos, const T& data);

  // 位置pos插入数据data
  bool Insert(int pos, const T& data);

  // 删除位置pos的数据
  bool Remove(int pos, T& data);

  // 是否为空
  bool IsEmpty() const;

  // 是否满
  bool IsFull() const;

  // 调整顺序表的长度
  int Resize(int new_size);

  // 输入顺序表
  void Input();

  // 排序
  void Sort();

  // 打印顺序表
  void Output();

  // 赋值运算符重载函数
  SeqList<T>& operator= (const SeqList<T>& seq_list);

  // 我们是CyberDash
  void CyberDashShow();

private:
  T* data_array_; //!< 数据项数组
  int size_; //!< 顺序表总长度
  int last_idx_; //!< 最后一项的数组索引
};


/**
 * @brief 构造函数
 * @tparam T 类型模板参数
 * @param size 顺序表size
 */
template<class T>
SeqList<T>::SeqList(int size) {

  if (size > 0) {
    this->size_ = size;
    this->last_idx_ = -1;
    this->data_array_ = new T[size];
  }

  if (this->data_array_ == NULL) {
    cerr<<"new error"<<endl;
    exit(1);
  }
}


/*!
 * @brief 复制构造函数
 * @tparam T 类型模板参数
 * @param seq_list 顺序表
 */
template<class T>
SeqList<T>::SeqList(SeqList<T>& seq_list) {

  this->size_ = seq_list.Size();
  this->last_idx_ = seq_list.Length() - 1;

  if (this->size_ == 0) {
    return;
  }

  this->data_array_ = new T[this->Size()];
  if (this->data_array_ == NULL) {
    cerr<<"存储分配错误!"<<endl;
    exit(1);
  }

  for (int i = 1; i <= this->last_idx_ + 1; i++) {
    T cur_value;
    seq_list.GetData(i, cur_value);
    this->data_array_[i - 1] = cur_value;
  }
}


/*!
 * @brief 调整顺序表的长度
 * @tparam T 类型模板参数
 * @param new_size 新的总长度
 * @return 新的总长度
 * @note
 * **返回值说明**
 * -2: 分配内存失败
 * -1: 无效参数
 * 0: 新的总长度与原来的相同
 */
template<class T>
int SeqList<T>::Resize(int new_size) {

  if (new_size <= 0) {
    cerr<<"无效的数组大小"<<endl;
    return -1;
  }

  if (new_size == this->Size()) {
    cout<<"重分配数组长度与原数组长度相同"<<endl;
    return 0;
  }

  T* new_data_array = new T[this->Size()];
  if (new_data_array == NULL) {
    cerr<<"存储分配错误"<<endl;
    return -2;
  }

  T* src_ptr = data_array_;
  T* dest_ptr = new_data_array;

  for (int i = 0; i < this->Length(); i++) {
    *(dest_ptr + i) = *(src_ptr + i);
  }

  delete [] data_array_;
  data_array_ = new_data_array;

  size_ = new_size;

  return new_size;
}


/*!
 * @brief 查找数据
 * @tparam T 类型模板参数
 * @param data 数据
 * @return 在顺序表中的位置
 */
template<class T>
int SeqList<T>::Search(T& data) const {

  int pos = 0; // 从1开始, 返回0表示没有查到

  for (int i = 0; i <= last_idx_; i++) {
    if (data_array_[i] == data) {
      pos = i + 1;
      break;
    }
  }

  return pos;
}


/*!
 * @brief 定位
 * @tparam T 类型模板参数
 * @param pos 第pos个
 * @return 位置pos
 * @note
 * pos是以1为起始, 不同于数组以0开始
 */
template<class T>
int SeqList<T>::Locate(int pos) const {
  if (pos >= 1 && pos <= last_idx_ + 1) {
    return pos;
  } else {
    return 0;
  }
};


/*!
 * @brief 获取位置pos的数据
 * @tparam T 类型模板参数
 * @param pos 位置pos
 * @param data 数据(用于保存数据项)
 * @return 是否获取成功
 */
template<class T>
bool SeqList<T>::GetData(int pos, T& data) const {
  if (pos > 0 && pos <= last_idx_ + 1) {
    data = data_array_[pos - 1];
    return true;
  } else {
    return false;
  }
}


/*!
 * @brief 设置位置pos的数据
 * @tparam T 类型模板参数
 * @param pos 位置pos
 * @param data 数据
 * @return 是否设置成功
 */
template<class T>
bool SeqList<T>::SetData(int pos, const T& data) {
  if (pos > 0 && pos <= last_idx_ + 1) {
    data_array_[pos - 1] = data;
    return true;
  } else {
    return false;
  }
}


/*!
 * @brief 在第pos个元素之后, 插入数据
 * @param pos 位置pos
 * @param data 数据项值
 * @return 是否成功
 * @note
 * 区别于数组, 以1开始\n
 * 当pos为0时, 表示插入位置1
 */
template<class T>
bool SeqList<T>::Insert(int pos, const T& data) {

  if (last_idx_ == size_ - 1) {
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


/*!
 * @brief 删除位置pos的数据
 * @tparam T 类型模板参数
 * @param pos 位置pos
 * @param remove_data 被删除的数据项
 * @return 是否删除成功
 */
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


/*!
 * @brief 是否为空表
 * @tparam T 类型模板参数
 * @return 是否为空
 */
template<class T>
bool SeqList<T>::IsEmpty() const {
  if (last_idx_ == -1) {
    return true;
  } else {
    return false;
  }
}


/*!
 * @brief 顺序表是否满
 * @tparam T 类型模板参数
 * @return 是否满
 */
template<class T>
bool SeqList<T>::IsFull() const {
  if (last_idx_ == size_ - 1) {
    return true;
  } else {
    return false;
  }
}


/*!
 * @brief 赋值运算符重载函数
 * @tparam T 类型模板参数
 * @param seq_list 顺序表
 * @return 顺序表引用
 */
template<class T>
SeqList<T>& SeqList<T>::operator=(const SeqList<T>& seq_list) {

  this->size_ = seq_list.Size();
  int p_length = seq_list.Length();

  for (int i = 0; i < p_length; i++) {
    int curData;
    seq_list.GetData(i, curData);

    this->SetData(i, curData);
  }

  return *this;
}


/*!
 * @brief 获取总长度
 * @tparam T 类型模板参数
 * @return 总长度
 */
template<class T>
int SeqList<T>::Size() const {
  return size_;
}


/*!
 * @brief 获取当前长度
 * @tparam T 类型模板参数
 * @return 当前长度
 */
template<class T>
int SeqList<T>::Length() const {
  return last_idx_ + 1;
}


/*!
 * @brief 打印顺序表
 * @tparam T 类型模板参数
 */
template<class T>
void SeqList<T>::Output() {

  if (last_idx_ == -1) {
    cout<<"顺序表为空表:"<<endl;
  } else {
    for (int i = 0; i <= last_idx_; i++) {
      cout<<"#"<<i + 1<<":"<<data_array_[i]<<endl;
    }
  }

}


/*!
 * @brief 排序
 * @tparam T 类型模板参数
 */
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


/*!
 * @brief 我们是CyberDash
 */
template<class T>
void SeqList<T>::CyberDashShow() {
  cout<<endl
      <<"*************************************** CyberDash ***************************************"<<endl<<endl
      <<"抖音号\"CyberDash计算机考研\", id: cyberdash_yuan"<<endl<<endl
      <<"CyberDash成员:"<<endl
      <<"元哥(cyberdash@163.com), "<<"北京邮电大学(通信工程本科)/北京邮电大学(信息与通信系统研究生)"<<endl
      <<"磊哥(alei_go@163.com), "<<"山东理工大学(数学本科)/北京邮电大学(计算机研究生)"<<endl<<endl
      <<"L_Dash(lyu2586@163.com), "<<"北京邮电大学(计算机在读研究生)"<<endl<<endl
      <<"数据结构开源代码(C++清华大学殷人昆)魔改升级版本: https://gitee.com/cyberdash/data-structure-cpp"<<endl
      <<endl<<"*************************************** CyberDash ***************************************"<<endl<<endl;
}

#endif //CYBER_DASH_YUAN_SEQ_LIST_H
