//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/6/2.
//

#include "util.h"


<<<<<<< 9e71d6d80513a1d56b8c861d32bb2365359fe174
void merge(int* sort_array, int* unsort_array, int left, int mid, int right) {
  for (int k = left; k <= right; k++) {
    unsort_array[k] = sort_array[k];
  }

  int index1 = left;
  int index2 = mid + 1;
  int index = left;

  while (index1 <= mid && index2 <= right) {
    if (unsort_array[index1] <= unsort_array[index2]) {
      sort_array[index] = unsort_array[index1];
      index++;
      index1++;
    } else {
      sort_array[index] = unsort_array[index2];
      index++;
      index2++;
    }
  }

  while (index1 <= mid) {
    sort_array[index++] = unsort_array[index1++];
  }

  while (index2 <= right) {
    sort_array[index++] = unsort_array[index2++];
=======
void merge(int* arr1, int* arr2, int left, int mid, int right) {
  for (int k = left; k <= right; k++) {
    arr2[k] = arr1[k];
  }

  int s1 = left;
  int s2 = mid + 1;
  int t = left;

  while (s1 <= mid && s2 <= right) {
    if (arr2[s1] <= arr2[s2]) {
      arr1[t] = arr2[s1];
      t++;
      s1++;
    } else {
      arr1[t] = arr2[s2];
      t++;
      s2++;
    }
  }

  while (s1 <= mid) {
    arr1[t++] = arr2[s1++];
  }

  while (s2 <= right) {
    arr1[t++] = arr2[s2++];
>>>>>>> remove the cpp file in binary_tree
  }
}


void merge_sort_recur(int* arr1, int* arr2, int left, int right) {
  if (left >= right) {
    return;
  }

  int mid = (left + right) / 2;
  merge_sort_recur(arr1, arr2, left, mid);
  merge_sort_recur(arr1, arr2, mid + 1, right);

  merge(arr1, arr2, left, mid, right);
}


void merge_sort(int *arr, int array_size) {

  int* arr2 = new int[array_size];

  int left = 0;
  int right = array_size - 1;

  merge_sort_recur(arr, arr2, left, right);
}
