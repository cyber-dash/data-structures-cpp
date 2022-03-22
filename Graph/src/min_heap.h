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
 * @tparam Weight 类型模板参数
 */
template <class Weight>
class MinHeap {
public:
  MinHeap(int size = DEFAULT_SIZE);
  MinHeap(Weight arr[], int arr_size);
  ~MinHeap() {delete[] heap_array_;}

  bool Insert(const Weight& item);
  bool RemoveMin(Weight& value);
  bool IsEmpty() const { return current_size_ == 0 ? true : false; }
  bool IsFull() const { return current_size_ == max_size_ ? true : false; }
  void MakeEmpty() { current_size_ = 0; }

  void CyberDashShow();

private:
  Weight* heap_array_;
  int current_size_;
  int max_size_;
  void siftDown(int start, int end);
  void siftUp(int start);
};


template <class Weight>
MinHeap<Weight>::MinHeap(int size) {

  max_size_ = (size > DEFAULT_SIZE) ? size : DEFAULT_SIZE;

  heap_array_ = new Weight[max_size_];
  if (heap_array_ == NULL) {
    cerr << "堆存储分配失败！" << endl;
    exit(1);
  }

  current_size_ = 0;
}


template <class Weight>
MinHeap<Weight>::MinHeap(Weight arr[], int arr_size) {
  max_size_ = (arr_size > DEFAULT_SIZE) ? arr_size : DEFAULT_SIZE;
  heap_array_ = new Weight[max_size_];

  if (heap_array_ == NULL) {
    cerr << "堆存储分配失败！" << endl;
    exit(1);
  }

  for (int i = 0; i < arr_size; i++) {
    heap_array_[i] = arr[i];
  }

  current_size_ = arr_size;

  int current_index_ = (current_size_ - 2) / 2;

  while (current_index_ >= 0) {
    siftDown(current_index_, current_size_ - 1);
    current_index_--;
  }
}


template <class Weight>
void MinHeap<Weight>::siftDown(int start, int end) {

  int cur = start;

  int left_child = 2 * cur + 1;
  int right_child = left_child + 1;

  int min_child = left_child;

  Weight cur_value = heap_array_[cur];

  while (left_child <= end) {

    // find the min child
    if (left_child < end && heap_array_[left_child] > heap_array_[right_child]) {
      min_child = right_child;
    }

    if (cur_value <= heap_array_[min_child]) {
      break;
    } else {
      heap_array_[cur] =  heap_array_[min_child];
      cur = min_child;

      left_child = 2 * min_child + 1;
      right_child = left_child + 1;
      min_child = left_child;
    }
  }

  heap_array_[cur] = cur_value;
}


template <class Weight>
void MinHeap<Weight>::siftUp(int start) {
  int j = start, i = (j - 1) / 2;
  Weight temp = heap_array_[j];

  while (j > 0) {
    if (heap_array_[i] <= temp) {
      break;
    } else {
      heap_array_[j] = heap_array_[i];
      j = i;
      i = (i - 1) / 2;
    }
  }

  heap_array_[j] = temp;
}


template <class Weight>
bool MinHeap<Weight>::Insert(const Weight& item) {

  if (current_size_ == max_size_) {
    cerr << "Heap Full." << endl;
    return false;
  }

  heap_array_[current_size_] = item;

  siftUp(current_size_);

  current_size_++;

  return true;
}


template <class Weight>
bool MinHeap<Weight>::RemoveMin(Weight& x) {
  if (!current_size_) {
    cerr << "Heap Empty." << endl;
    return false;
  }

  x = heap_array_[0];
  heap_array_[0] = heap_array_[current_size_ - 1];
  current_size_--;

  siftDown(0, current_size_ - 1);

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
