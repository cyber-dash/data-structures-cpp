/*!
 * @file bubble_sort.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 冒泡排序
 * @version 0.2.1
 * @date 2021-09-19
 */

#include "util.h"


template<typename TValue>
void BubbleSort(TValue* array, int size) {
    for (int counter = 0; counter < size; counter++) {
        for (int i = 0; i < size - counter - 1; i++) {
            if (array[i] > array[i + 1]) {
                Swap(array + i, array + i + 1);
            }
        }
    }
}
