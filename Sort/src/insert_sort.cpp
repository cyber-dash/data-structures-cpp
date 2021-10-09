/*!
 * @file insert_sort.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 插入排序
 * @version 0.2.1
 * @date 2021-09-19
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#include "util.h"


/*!
 * @brief 插入排序
 * @param arr 数组
 * @param size 数组长度
 */
void InsertSort(int* arr, int size) {

    for (int i = 1; i < size; i++) {

        int cur_idx = i;

        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] > arr[cur_idx]) {
              Swap(arr + i, arr + j);
                cur_idx = j;
            } else {
                break;
            }   
        }   
    }   
}
