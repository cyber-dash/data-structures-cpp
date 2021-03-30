//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/6/2.
//

#include "util.h"


void merge(int* array, int* cache_array, int left, int mid, int right) {

  for (int i = left; i <= right; i++) {
    cache_array[i] = array[i];
  }

  int left_cache_index = left;
  int right_cache_index = mid + 1;

  int array_index = left;

  while (left_cache_index <= mid && right_cache_index <= right) {

    if (cache_array[left_cache_index] <= cache_array[right_cache_index]) {
      array[array_index] = cache_array[left_cache_index];
      left_cache_index++;
    } else {
      array[array_index] = cache_array[right_cache_index];
      right_cache_index++;
    }

    array_index++;
  }

  while (left_cache_index <= mid) {
    array[array_index] = cache_array[left_cache_index];
    left_cache_index++;
    array_index++;
  }

  while (right_cache_index <= right) {
    array[array_index] = cache_array[right_cache_index];
    right_cache_index++;
    array_index++;
  }
}


void merge_sort_recur(int* array, int* cache_array, int left, int right) {

  if (left >= right) {
    return;
  }

  int mid = (left + right) / 2;

  merge_sort_recur(array, cache_array, left, mid);
  merge_sort_recur(array, cache_array, mid + 1, right);

  merge(array, cache_array, left, mid, right);
}


void merge_sort(int *arr, int array_size) {

  int* cache_array = new int[array_size];

  int left = 0;
  int right = array_size - 1;

  merge_sort_recur(arr, cache_array, left, right);
}
