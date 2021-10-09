//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/6/2.
//

#include "util.h"


int split(int *arr, int left, int right) {

    int pivot = left;

    while (left <= right) {

        for (; right >= pivot; right--) {
            if (arr[pivot] > arr[right]) {
                swap(arr + pivot, arr + right);
                left = pivot + 1;
                pivot = right;
                break;
            }
        }

        for (; left <= pivot; left++) {
            if (arr[pivot] < arr[left]) {
                swap(arr + left, arr + pivot);
                right = pivot - 1;
                pivot = left;
                break;
            }
        }
    }

    return pivot;
}


void QuickSort(int *arr, int left, int right) {

    if (begin >= end) {
        return;
    }

    int pivot = split(arr, begin, end);

  QuickSort(arr, begin, pivot - 1);
  QuickSort(arr, pivot + 1, end);
}


