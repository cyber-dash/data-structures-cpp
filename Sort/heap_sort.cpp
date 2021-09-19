//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/6/2.
//

#include "util.h"


void build_heap(int* arr, int arr_size) {

  int edge_pos = (arr_size - 2) / 2;

  for (int i = edge_pos; i >= 0; i--) {

    for (int j = i; j <= edge_pos; ) {

      int left_child_idx = 2 * j + 1;
      int right_child_idx = 2 * j + 2;

      int min_child_idx;

      if (left_child_idx >= arr_size) {
        break;
      } else if (right_child_idx >= arr_size) {
        min_child_idx = left_child_idx;
      } else {
        if (arr[left_child_idx] >= arr[right_child_idx]) {
          min_child_idx = right_child_idx;
        } else {
          min_child_idx = left_child_idx;
        }
      }

      if (arr[j] > arr[min_child_idx]) {
        swap(arr + j, arr + min_child_idx);
      }

      j = min_child_idx; // next step
    }
  }
}


void heap_sort(int* arr, int arr_size) {

  int *tmp = new int[arr_size]();
  for (int i = 0; i < arr_size; i++) {
    tmp[i] = arr[i];
  }

  for (int i = 0; i < arr_size; i++) {

    int cur_heap_size = arr_size - i;
    int heap_end_idx = arr_size - 1 - i;

    build_heap(tmp, cur_heap_size);

    arr[i] = tmp[0];

    swap(tmp, tmp + heap_end_idx);
  }

  delete[] tmp;
}
