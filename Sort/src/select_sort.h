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
  * @param array 数组
  * @param size 数组长度
  */
template<typename TValue>
void SelectSort(TValue* array, int size) {

    for (int i = 0; i < size - 1; i++) {

        int select_index = i;
        TValue select_value = array[select_index];

        for (int j = i + 1; j < size; j++) {
            if (array[j] < select_value) {
                select_index = j;
                select_value = array[j];
            }
        }

        Swap(array + i, array + select_index);
    }
}
