/*!
 * @file insert_sort.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 插入排序
 * @version 0.2.1
 * @date 2021-09-19
 */

#include "util.h"


 /*!
  * @brief 插入排序
  * @param array 数组
  * @param size 数组长度
  */
template<typename TValue>
void InsertSort(TValue* array, int size) {
    for (int cur_unsorted_region_first_index = 1;
         cur_unsorted_region_first_index < size;
         cur_unsorted_region_first_index++)
    {
        int cur_insert_element_index = cur_unsorted_region_first_index;

        for (int cur_sorted_region_index = cur_unsorted_region_first_index - 1;
             cur_sorted_region_index >= 0;
             cur_sorted_region_index--)
        {
            if (array[cur_sorted_region_index] > array[cur_insert_element_index]) {
                Swap(array + cur_insert_element_index, array + cur_sorted_region_index);
                cur_insert_element_index = cur_sorted_region_index;
            } else {
                break;
            }
        }
    }
}
