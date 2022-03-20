/*!
 * @file select_sort.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 选择排序
 * @version 0.2.1
 * @date 2021-09-19
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#include "util.h"


 /*!
  * @brief 选择排序
  * @param arr 数组
  * @param size 数组长度
  */
void SelectSort(int* arr, int size) {

    for (int i = 0; i < size; i++) {

        int select_idx = i;
        int select_value = arr[select_idx];

        for (int j = i + 1; j < size; j++) {
            if (arr[j] < select_value) {
                select_idx = j;
                select_value = arr[j];
            }
        }

        Swap(arr + i, arr + select_idx);
    }
}
