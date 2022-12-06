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


template<typename TValue>
void QuickSort(TValue* array, int size) {
    int left = 0;
    int right = size - 1;

    SubarrayQuickSort(array, left, right);
}

 /*!
  * @brief 划分函数
  * @param array 数组
  * @param left 左边界
  * @param right 右边界
  * @return 轴
  */
template<typename TValue>
int Split(TValue* array, int left, int right) {

    int pivot = left;

    while (left <= right) {

        for (; right >= pivot; right--) {
            if (array[pivot] > array[right]) {
                Swap(array + pivot, array + right);
                left = pivot + 1;
                pivot = right;
                break;
            }
        }

        for (; left <= pivot; left++) {
            if (array[pivot] < array[left]) {
                Swap(array + left, array + pivot);
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
template<typename TValue>
void SubarrayQuickSort(TValue* arr, int left, int right) {

    if (left >= right) {
        return;
    }

    int pivot = Split(arr, left, right);

    SubarrayQuickSort(arr, left, pivot - 1);
    SubarrayQuickSort(arr, pivot + 1, right);
}

