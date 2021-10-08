//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/6/2.
//

#include "util.h"


void InsertSort(int *arr, int arr_size) {

    for (int i = 1; i < arr_size; i++) {

        int cur_idx = i;

        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] > arr[cur_idx]) {
                swap(arr + i, arr + j); 
                cur_idx = j;
            } else {
                break;
            }   
        }   
    }   
}
