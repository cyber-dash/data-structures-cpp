/*!
 * @file sort.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 排序.h文件
 * @version 0.2.1
 * @date 2021-09-19
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#ifndef CYBER_DASH_SORT_H
#define CYBER_DASH_SORT_H


void BubbleSort(int* arr, int size);

void SelectSort(int* arr, int size);

void InsertSort(int* arr, int size);

void QuickSort(int* arr, int begin, int end);

void MergeSort(int* array, int size);

void MergeSortNonRecursive(int* array, int size);

void HeapSort(int* array, int size);


#endif //CYBER_DASH_SORT_H
