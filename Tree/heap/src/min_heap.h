//
// Created by alei_go@163.com(∂∂“Ù: cyberdash_yuan) on 2020/11/1.
//

#ifndef CYBER_DASH_MIN_HEAP_H
#define CYBER_DASH_MIN_HEAP_H


#define DEFAULT_SIZE 10


template <class E>
class MinHeap {
public:
  MinHeap(int size = DEFAULT_SIZE);
  MinHeap(E arr[], int arr_size);
  ~MinHeap() {delete[] heap_array_;}

  bool Insert(const E& item);
  bool RemoveMin(E& value);
  bool IsEmpty() const { return current_size_ == 0 ? true : false; }
  bool IsFull() const { return current_size_ == max_size_ ? true : false; }
  void MakeEmpty() { current_size_ = 0; }

  void CyberDashShow();

private:
  E* heap_array_;
  int current_size_;
  int max_size_;
  void siftDown(int start, int end);
  void siftUp(int start);
};

#endif //CYBER_DASH_MIN_HEAP_H

