/*!
 * @file bubble_sort.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 冒泡排序
 * @version 0.2.1
 * @date 2021-09-19
 */

#include "util.h"


/*!
 * @brief **冒泡排序(升序规则)**
 * @tparam TElement 数组元素类型模板参数
 * @param elements 数组
 * @param size 数组长度
 * @note
 * 冒泡排序(升序规则)
 * ---------------
 * ---------------
 *
 * ---------------
 * **for loop** counter(计数器)从0到size - 2, 遍历size - 1次 :\n
 * &emsp; **for loop** i(数组索引)从0到size - counter - 2, 相邻比较size - counter - 1次 :\n
 * &emsp;&emsp; **if** 索引i元素 > 索引i + 1元素(不符合排序规则) :\n
 * &emsp;&emsp;&emsp; 索引i元素和索引i + 1元素交换位置(冒泡)\n
 */
template<typename TElement>
void BubbleSort(TElement* elements, int size) {
    for (int counter = 0; counter < size - 1; counter++) {  // for loop counter(计数器)从0到size - 2, 遍历size - 1次
        for (int i = 0; i < size - counter - 1; i++) {      // i(数组索引)从0到size - counter - 2, 相邻比较size - counter - 1次
            if (elements[i] > elements[i + 1]) {            // if 索引i元素 > 索引i + 1元素(不符合排序规则)
                Swap(elements + i, elements + i + 1);       // 索引i元素和索引i + 1元素交换位置(冒泡)
            }
        }
    }
}
