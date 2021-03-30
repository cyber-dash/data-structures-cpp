//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/6/2.
//

#ifndef CYBER_DASH_SORT_H
#define CYBER_DASH_SORT_H


void bubble_sort(int *arr, int arr_size);

void select_sort(int *arr, int arr_size);

void insert_sort(int *arr, int arr_size);

void quick_sort(int *arr, int begin, int end);

void merge_sort(int* arr, int arr_size);
void merge_sort_unrecur(int* array, int array_size);

void heap_sort(int* array, int array_size);


#endif //CYBER_DASH_SORT_H
