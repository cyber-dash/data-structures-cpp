//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/6/2.
//

#include "util.h"


void SelectSort(int *arr, int arr_size) {

    for (int i = 0; i < arr_size; i++) {

        int select_idx = i;
        int select_value = arr[select_idx];

        for (int j = i + 1; j < arr_size; j++) {
            if (arr[j] < select_value) {
                select_idx = j;
                select_value = arr[j];
            }
        }

        swap(arr + i, arr + select_idx);
    }
}