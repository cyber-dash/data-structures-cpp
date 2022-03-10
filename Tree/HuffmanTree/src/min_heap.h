//
// Created by alei_go@163.com(∂∂“Ù: cyberdash_yuan) on 2020/11/1.
//

#ifndef CYBER_DASH_MIN_HEAP_H
#define CYBER_DASH_MIN_HEAP_H


#define DEFAULT_SIZE 10


template <class E>
class MinHeap {
public:
  MinHeap(int sz = DEFAULT_SIZE);
  MinHeap(E arr[], int n);
  ~MinHeap() {delete []heap;}

  bool Insert(const E& x);
  bool RemoveMin(E& x);
  bool IsEmpty() const { return currentSize == 0 ? true : false; }
  bool IsFull() const { return currentSize == maxHeapSize ? true : false; }
  void MakeEmpty() { currentSize = 0; }

private:
  E *heap;
  int currentSize;
  int maxHeapSize;
  void siftDown(int start, int m);
  void siftUp(int start);
};


#endif //CYBER_DASH_MIN_HEAP_H

