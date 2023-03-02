/*!
 * @file insert_sort.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 插入排序
 * @version 0.2.1
 * @date 2021-09-19
 */

#include "util.h"


 /*!
  * @brief **插入排序(升序规则)**
  * @tparam TElement 数组元素类型模板参数
  * @param elements 数组
  * @param size 数组长度
  * @note
  * 插入排序(升序规则)
  * ---------------
  * ---------------
  *
  * <span style="color:#650000">
  * cur_unsorted_region_first_index: 当前无序区首元素的数组索引\n
  * </span>
  * <span style="color:#d40000">
  * cur_insert_element_index: 当前插入元素的数组索引\n
  * </span>
  * <span style="color:#003153">
  * cur_sorted_region_index: 当前有序区的遍历索引\n
  * </span>
  * \n
  * 从无序区选1个元素, 通常是无序区首元素, 插入到有序区, 重复size - 1次
  *
  * ---------------
  * **for loop** 无序区首元素的数组索引, 从1到size - 1 :\n
  * &emsp; 取无序区首元素作为插入元素\n
  * &emsp; **for loop** 有序区从后向前遍历: \n
  * &emsp;&emsp; **if** 当前有序区遍历元素 > 当前插入元素 :\n
  * &emsp;&emsp;&emsp; 当前有序区遍历元素与当前插入元素, 做交换\n
  * &emsp;&emsp;&emsp; 当前插入元素的数组索引更新\n
  * &emsp;&emsp; **else** (当前有序区遍历元素 > 当前插入元素) :\n
  * &emsp;&emsp;&emsp; break跳出循环(已插入到对应的位置)\n
  */
template<typename TElement>
void InsertSort(TElement* elements, int size) {
     // for loop 无序区首元素的数组索引, 从1到size - 1
    for (int cur_unsorted_region_first_index = 1;
         cur_unsorted_region_first_index < size;
         cur_unsorted_region_first_index++)
    {
        // 取无序区首元素作为插入元素
        int cur_insert_element_index = cur_unsorted_region_first_index;

        // for loop 有序区从后向前遍历
        for (int cur_sorted_region_index = cur_unsorted_region_first_index - 1;
             cur_sorted_region_index >= 0;
             cur_sorted_region_index--)
        {
            // if 当前有序区遍历元素 > 当前插入元素
            if (elements[cur_sorted_region_index] > elements[cur_insert_element_index]) {
                // 当前有序区遍历元素与当前插入元素, 做交换
                Swap(elements + cur_insert_element_index, elements + cur_sorted_region_index);
                // 当前插入元素的数组索引更新
                cur_insert_element_index = cur_sorted_region_index;
            } else {                        // else (当前有序区遍历元素 > 当前插入元素)
                break;                      // break跳出循环(已插入到对应的位置)
            }
        }
    }
}
