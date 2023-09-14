/*!
 * @file selection_sort.h
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
  * <span style="color:#650000">
  * cur_unsorted_region_first_index: 当前无序区首元素的数组索引\n
  * </span>
  * \n
  * 从无序区选出最大or最小(按照排序规则)的元素, 与无序区首个元素交换位置, 重复size - 1次\n
  *
  * ---------------
  * **for loop** 每趟选择前, 无序区首元素索引 :\n
  * &emsp; 初始化selected_index(当前选择元素的索引), 等于当前无序区首元素索引\n
  * &emsp; 初始化selected_element(当前选择元素), 等于当前无序区首元素\n
  * &emsp; **for loop** 当前无序区首元素之后的元素的索引 :\n
  * &emsp;&emsp; **if** elements[i](当前元素) < 当前选择元素 :\n
  * &emsp;&emsp;&emsp; 当前元素设置为当前选择元素\n
  * &emsp;&emsp;&emsp; 当前选择元素的索引值为i\n
  * &emsp; 当前无序区首元素与(最终的)选择元素交换位置(交换后无序区收缩, 有序区扩展)\n
  *
  *
  * ---------------
  */
template<typename TElement>
void SelectionSort(TElement* elements, int size) {

    // for loop 每趟选择前, 无序区首元素索引
    for (int cur_unsorted_region_first_index = 0;
         cur_unsorted_region_first_index < size - 1;
         cur_unsorted_region_first_index++)
    {
        int selected_index = cur_unsorted_region_first_index;               // 初始化selected_index(当前选择元素的索引), 等于当前无序区首元素索引
        TElement selected_element = elements[selected_index];               // 初始化selected_element(当前选择元素), 等于当前无序区首元素

        for (int i = cur_unsorted_region_first_index + 1; i < size; i++) {  // for loop 当前无序区首元素之后的元素的索引
            if (elements[i] < selected_element) {                           // if elements[i](当前元素) < 当前选择元素
                selected_element = elements[i];                             // 当前元素设置为当前选择元素
                selected_index = i;                                         // 当前选择元素的索引值为i
            }
        }

        // 当前无序区首元素与(最终的)选择元素交换位置(交换后无序区收缩, 有序区扩展)
        Swap(elements + cur_unsorted_region_first_index, elements + selected_index);
    }
}
