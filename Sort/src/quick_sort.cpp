/*!
 * @file quick_sort.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 快速排序
 * @version 0.2.1
 * @date 2021-09-19
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#include "util.h"


/*!
 * @brief 划分函数
 * @param arr 数组
 * @param left 左边界
 * @param right 右边界
 * @return 轴
 */
int Split(int* arr, int left, int right) {

    int pivot = left;

    while (left <= right) {

        for (; right >= pivot; right--) {
            if (arr[pivot] > arr[right]) {
              Swap(arr + pivot, arr + right);
                left = pivot + 1;
                pivot = right;
                break;
            }
        }

        for (; left <= pivot; left++) {
            if (arr[pivot] < arr[left]) {
              Swap(arr + left, arr + pivot);
                right = pivot - 1;
                pivot = left;
                break;
            }
        }
    }

    return pivot;
}


/*!
 * @brief 快速排序(递归)
 * @param arr 数组
 * @param left 左边界
 * @param right 右边界
 */
void QuickSort(int *arr, int left, int right) {

  if (left >= right) {
    return;
  }

  int pivot = Split(arr, left, right);

  QuickSort(arr, left, pivot - 1);
  QuickSort(arr, pivot + 1, right);
}


