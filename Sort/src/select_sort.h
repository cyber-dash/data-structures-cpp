/*!
 * @file select_sort.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 选择排序
 * @version 0.2.1
 * @date 2021-09-19
 */

#include "util.h"


 /*!
  * @brief **选择排序(升序规则)**
  * @param elements 数组
  * @param size 数组长度
  * @note
  * 选择排序(升序规则)
  * ---------------
  * ---------------
  *
  * ---------------
  */
template<typename TElement>
void SelectSort(TElement* elements, int size) {

    for (int i = 0; i < size - 1; i++) {

        int select_index = i;
        TElement select_value = elements[select_index];

        for (int j = i + 1; j < size; j++) {
            if (elements[j] < select_value) {
                select_index = j;
                select_value = elements[j];
            }
        }

        Swap(elements + i, elements + select_index);
    }
}
