/*!
 * @file HeapSort.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 堆排序
 * @version 0.2.1
 * @date 2021-09-19
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#include "util.h"


void BuildHeap(int* arr, int size) {

  int pivot = (size - 2) / 2;

  for (int i = pivot; i >= 0; i--) {

    for (int j = i; j <= pivot; ) {

      int left_child = 2 * j + 1;
      int right_child = 2 * j + 2;

      int min_child;

      if (left_child >= size) {
        break;
      } else if (right_child >= size) {
        min_child = left_child;
      } else {
        if (arr[left_child] >= arr[right_child]) {
          min_child = right_child;
        } else {
          min_child = left_child;
        }
      }

      if (arr[j] > arr[min_child]) {
        swap(arr + j, arr + min_child);
      }

      j = min_child; // next step
    }
  }
}


void HeapSort(int* arr, int size) {

  int *tmp = new int[size]();
  for (int i = 0; i < size; i++) {
    tmp[i] = arr[i];
  }

  for (int i = 0; i < size; i++) {

    int cur_heap_size = size - i;
    int heap_end_idx = size - 1 - i;

    BuildHeap(tmp, cur_heap_size);

    arr[i] = tmp[0];

    swap(tmp, tmp + heap_end_idx);
  }

  delete[] tmp;
}
