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


void quick_sort(int *arr, int left, int right) {

    if (left >= right) {
        return;
    }

    int pivot = split(arr, left, right);

    quick_sort(arr, left, pivot - 1);
    quick_sort(arr, pivot + 1, right);
}


