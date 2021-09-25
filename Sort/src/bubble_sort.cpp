//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/6/2.
//

#include "util.h"


void bubble_sort(int *arr, int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        for (int j = 0; j < arr_size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr + j, arr + j + 1);
            }
        }
    }
}
