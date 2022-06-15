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


#define DEFAULT_SIZE 10


/*!
 * @brief 最小堆模板类
 * @tparam T 类型模板参数
 */
template <class T>
class MinHeap {
public:
  MinHeap(int size = DEFAULT_SIZE);
  MinHeap(T arr[], int arr_size);
  ~MinHeap() { delete[] heap_item_array_; }

  bool Insert(const T& item);
  bool HeapTopPop(T& item);
  bool IsEmpty() const { return heap_size_ == 0; }
  bool IsFull() const { return heap_size_ == max_size_; }
  void MakeEmpty() { heap_size_ = 0; }  // todo: 其余操作

  void CyberDashShow();

private:
  T* heap_item_array_; //!< 堆元素数组
  int heap_size_;      //!< 当前堆size
  int max_size_;       //!< 最大size
  void SiftDown_(int idx, int end);
  void SiftUp_(int start);
  void Swap(T& item1, T& item2);
};


template <class T>
MinHeap<T>::MinHeap(int size) {
  max_size_ = (size > DEFAULT_SIZE) ? size : DEFAULT_SIZE;
  heap_item_array_ = new T[max_size_];
  heap_size_ = 0;
}


template <class T>
MinHeap<T>::MinHeap(T arr[], int arr_size) {
  max_size_ = (arr_size > DEFAULT_SIZE) ? arr_size : DEFAULT_SIZE;
  heap_item_array_ = new T[max_size_];
  for (int i = 0; i < arr_size; i++) {
      heap_item_array_[i] = arr[i];
  }

  heap_size_ = arr_size;

  for (int cur_idx = (heap_size_ - 2) / 2; cur_idx >= 0; cur_idx--) {
      SiftDown_(cur_idx, heap_size_ - 1);
  }
}


template <class T>
void MinHeap<T>::SiftDown_(int idx, int end) {

  int cur = idx;

  int left_child = 2 * cur + 1;
  int right_child = left_child + 1;

  int min_child = left_child;

  T cur_value = heap_item_array_[cur];

  while (left_child <= end) {

    // find the min child
    if (left_child < end && heap_item_array_[left_child] > heap_item_array_[right_child]) {
      min_child = right_child;
    }

    if (cur_value <= heap_item_array_[min_child]) {
      break;
    }
    heap_item_array_[cur] =  heap_item_array_[min_child];
    cur = min_child;

    left_child = 2 * min_child + 1;
    right_child = left_child + 1;
    min_child = left_child;
  }

  heap_item_array_[cur] = cur_value;
}


template <class T>
void MinHeap<T>::SiftUp_(int start) {
  int idx = start, i = (idx - 1) / 2;
  T temp = heap_item_array_[idx];

  while (idx > 0) {
    if (heap_item_array_[i] <= temp) {
      break;
    } else {
        heap_item_array_[idx] = heap_item_array_[i];
        idx = i;
      i = (i - 1) / 2;
    }
  }

  heap_item_array_[idx] = temp;
}


template <class T>
void MinHeap<T>::Swap(T& item1, T& item2) {
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

  heap_item_array_[heap_size_] = item;

  SiftUp_(heap_size_);

  heap_size_++;

  return true;
}


template <class T>
bool MinHeap<T>::HeapTopPop(T& item) {
  if (!heap_size_) {
    cerr << "Heap Empty." << endl;
    return false;
  }

    item = heap_item_array_[0];
  heap_item_array_[0] = heap_item_array_[heap_size_ - 1];
  heap_size_--;

  SiftDown_(0, heap_size_ - 1);

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
      <<"数据结构开源代码(C++清华大学殷人昆)魔改升级版本: https://gitee.com/cyberdash/data-structure-cpp"<<endl
      <<endl<<"*************************************** CyberDash ***************************************"<<endl<<endl;
}


#endif //CYBER_DASH_MIN_HEAP_H
