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
 * @tparam TElement 类型模板参数
 */
template <class TElement>
class MinHeap {
public:
  MinHeap(int size = DEFAULT_SIZE);
  MinHeap(TElement arr[], int arr_size);
  ~MinHeap() { delete[] elements_; }

  bool Insert(const TElement& element);
  bool Pop(TElement& element);
  bool Top(TElement& element);
  bool IsEmpty() const { return heap_size_ == 0; }
  bool IsFull() const { return heap_size_ == max_size_; }
  int Size() { return heap_size_; }
  void Clear() { heap_size_ = 0; }  // todo: 其余操作

private:
  TElement* elements_;    //!< 堆元素数组
  int heap_size_;    //!< 当前堆size
  int max_size_;     //!< 最大size
  void SiftDown_(int idx);
  void SiftUp_(int idx);
  void Swap_(TElement& element1, TElement& element2);
};


template <class T>
MinHeap<T>::MinHeap(int size) {
  max_size_ = (size > DEFAULT_SIZE) ? size : DEFAULT_SIZE;
    elements_ = new T[max_size_];
  heap_size_ = 0;
}


template <class T>
MinHeap<T>::MinHeap(T arr[], int arr_size) {
  max_size_ = (arr_size > DEFAULT_SIZE) ? arr_size : DEFAULT_SIZE;
    elements_ = new T[max_size_];
  for (int i = 0; i < arr_size; i++) {
      elements_[i] = arr[i];
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
    if (child_idx < heap_size_ && elements_[child_idx] > elements_[child_idx + 1]) {
        child_idx++;
    }

    //! 如果父节点 >= 子节点, sift down结束
    if (elements_[idx] <= elements_[child_idx]) {
      break;
    }

    //! 交换父子结点
    Swap_(elements_[idx], elements_[child_idx]);
  }
}


template <class T>
void MinHeap<T>::SiftUp_(int idx) {
  for (int parent_idx = (idx - 1) / 2; parent_idx >= 0; idx = parent_idx, parent_idx = (idx - 1) / 2) {
    if (elements_[parent_idx] <= elements_[idx]) {
      break;
    }

    Swap_(elements_[parent_idx], elements_[idx]);
  }
}


template <class T>
void MinHeap<T>::Swap_(T& element1, T& element2) {
  T tmp = element1;
  element1 = element2;
  element2 = tmp;
}


template <class T>
bool MinHeap<T>::Insert(const T& element) {

  if (heap_size_ == max_size_) {
    cerr << "Heap Full." << endl;
    return false;
  }

    elements_[heap_size_] = element;

  SiftUp_(heap_size_);

  heap_size_++;

  return true;
}


template <class T>
bool MinHeap<T>::Pop(T& element) {
  if (!heap_size_) {
    cerr << "Heap Empty." << endl;
    return false;
  }

  element = elements_[0];
    elements_[0] = elements_[heap_size_ - 1];
  heap_size_--;

  SiftDown_(0);

  return true;
}


template <class T>
bool MinHeap<T>::Top(T& element) {
    if (!heap_size_) {
        cerr << "Heap Empty." << endl;
        return false;
    }

    element = elements_[0];

    return true;
}


#endif // CYBER_DASH_MIN_HEAP_H
