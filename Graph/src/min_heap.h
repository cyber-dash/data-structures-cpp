/*!
 * @file min_heap.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 最小堆实现
 * @version 0.2.1
 * @date 2021-07-14
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#ifndef CYBER_DASH_MIN_HEAP_H
#define CYBER_DASH_MIN_HEAP_H

#include <iostream>
#include <cstdlib>


using namespace std;


#define DEFAULT_SIZE 200


/*!
 * @brief 最小堆模板类
 * @tparam T 类型模板参数
 */
template <class T>
class MinHeap {
public:
  MinHeap(int size = DEFAULT_SIZE);
  MinHeap(T arr[], int arr_size);
  ~MinHeap() { delete[] item_array_; }

  bool Insert(const T& item);
  bool Pop(T& item);
  bool Top(T& item);
  bool IsEmpty() const { return heap_size_ == 0; }
  bool IsFull() const { return heap_size_ == max_size_; }
  int Size() { return heap_size_; }
  void MakeEmpty() { heap_size_ = 0; }  // todo: 其余操作

  void CyberDashShow();

private:
  T* item_array_;    //!< 堆元素数组
  int heap_size_;    //!< 当前堆size
  int max_size_;     //!< 最大size
  void SiftDown_(int idx);
  void SiftUp_(int idx);
  void Swap_(T& item1, T& item2);
};


template <class T>
MinHeap<T>::MinHeap(int size) {
  max_size_ = (size > DEFAULT_SIZE) ? size : DEFAULT_SIZE;
  item_array_ = new T[max_size_];
  heap_size_ = 0;
}


template <class T>
MinHeap<T>::MinHeap(T arr[], int arr_size) {
  max_size_ = (arr_size > DEFAULT_SIZE) ? arr_size : DEFAULT_SIZE;
  item_array_ = new T[max_size_];
  for (int i = 0; i < arr_size; i++) {
    item_array_[i] = arr[i];
  }

  heap_size_ = arr_size;

  for (int cur_idx = (heap_size_ - 2) / 2; cur_idx >= 0; cur_idx--) {
    SiftDown_(cur_idx);
  }
}


template <class T>
void MinHeap<T>::SiftDown_(int idx) {
  for (int child_idx = 2 * idx + 1; child_idx < heap_size_; idx = child_idx, child_idx = child_idx * 2 + 1) {

    //! index的孩子结点中, 权重较大的结点索引, 赋给child_idx
    if (child_idx < heap_size_ && item_array_[child_idx] > item_array_[child_idx + 1]) {
        child_idx++;
    }

    //! 如果父节点 >= 子节点, sift down结束
    if (item_array_[idx] <= item_array_[child_idx]) {
      break;
    }

    //! 交换父子结点
    Swap_(item_array_[idx], item_array_[child_idx]);
  }
}


template <class T>
void MinHeap<T>::SiftUp_(int idx) {
  for (int parent_idx = (idx - 1) / 2; parent_idx >= 0; idx = parent_idx, parent_idx = (idx - 1) / 2) {
    if (item_array_[parent_idx] <= item_array_[idx]) {
      break;
    }

    Swap_(item_array_[parent_idx], item_array_[idx]);
  }
}


template <class T>
void MinHeap<T>::Swap_(T& item1, T& item2) {
  T tmp = item1;
  item1 = item2;
  item2 = tmp;
}


template <class T>
bool MinHeap<T>::Insert(const T& item) {

  if (heap_size_ == max_size_) {
    cerr << "Heap Full." << endl;
    return false;
  }

  item_array_[heap_size_] = item;

  SiftUp_(heap_size_);

  heap_size_++;

  return true;
}


template <class T>
bool MinHeap<T>::Pop(T& item) {
  if (!heap_size_) {
    cerr << "Heap Empty." << endl;
    return false;
  }

  item = item_array_[0];
  item_array_[0] = item_array_[heap_size_ - 1];
  heap_size_--;

  SiftDown_(0);

  return true;
}


template <class T>
bool MinHeap<T>::Top(T& item) {
    if (!heap_size_) {
        cerr << "Heap Empty." << endl;
        return false;
    }

    item = item_array_[0];

    return true;
}


template<class Vertex>
void MinHeap<Vertex>::CyberDashShow() {
  cout<<endl
      <<"*************************************** CyberDash ***************************************"<<endl<<endl
      <<"抖音号\"CyberDash计算机考研\", id: cyberdash_yuan"<<endl<<endl
      <<"CyberDash成员:"<<endl
      <<"元哥(cyberdash@163.com), "<<"北京邮电大学(通信工程本科)/北京邮电大学(信息与通信系统研究生)"<<endl
      <<"磊哥(alei_go@163.com), "<<"山东理工大学(数学本科)/北京邮电大学(计算机研究生)"<<endl<<endl
      <<"数据结构开源代码(C++版本): https://gitee.com/cyberdash/data-structure-cpp"<<endl
      <<endl<<"*************************************** CyberDash ***************************************"<<endl<<endl;
}


#endif // CYBER_DASH_MIN_HEAP_H
