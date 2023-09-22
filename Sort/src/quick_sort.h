﻿/*!
 * @file quick_sort.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 快速排序
 * @version 0.2.1
 * @date 2021-09-19
 */

#include "util.h"


/*!
 * @brief **快速排序**
 * @tparam TElement 数组元素类型模板参数
 * @param elements 数组
 * @param size 数组长度
 * @note
 * 快速排序
 * -------
 * -------
 *
 * -------
 * + **1 初始化左右边界**\n\n
 * left<span style="color:#283593;font-weight:bold">(左边界)</span>设为0\n
 * right<span style="color:#283593;font-weight:bold">(右边界)</span>设为size - 1\n\n
 * + **2 调用子数组递归函数排序**\n\n
 * 调用QuickSortInSubArrayRecursive\n
 *
 *
 * -------
 */
template<typename TElement>
void QuickSort(TElement* elements, int size) {

    // ---------- 1 初始化左右边界 ----------

    int left = 0;                                                   // left(左边界)设为0
    int right = size - 1;                                           // right(右边界)设为size - 1

    // ---------- 2 调用子数组递归函数排序 ----------

    QuickSortInSubArrayRecursive(elements, left, right);            // 调用QuickSortInSubArrayRecursive
}


 /*!
  * @brief **划分函数(升序规则)**
  * @tparam TElement 数组元素类型模板参数
  * @param elements 数组
  * @param left 左边界数组索引
  * @param right 右边界数组索引
  * @return 轴
  * @note
  * 划分函数(升序规则)
  * ---------------
  * ---------------
  *
  * <span style="color:#DF5A00">
  * 左右逼近:\n
  * &emsp; WHEN: pivot在左侧, DO: 从右向左逼近: IF: 右侧遍历至某元素, 不符合排序规则, THEN: 与pivot位置元素交换\n
  * &emsp; WHEN: pivot在右侧, DO: 从左向右逼近: IF: 左侧遍历至某元素, 不符合排序规则, THEN: 与pivot位置元素交换\n
  * </span>
  *
  * ---------------
  * 声明并初始化pivot<span style="color:#283593;font-weight:bold">(轴)</span>, 等于left<span style="color:#283593;font-weight:bold">(数组左边界)</span>\n\n
  * **while loop** left <= right <span style="color:#008040;font-weight:bold">(左右边界还有向中间逼近的可能)</span> :\n\n
  * <span style="color:#bc8f8f">
  * &emsp; (右侧逼近)\n
  * </span>
  * &emsp; **for loop** right>= pivot; right-- :\n
  * &emsp;&emsp; **if** pivot位置元素 > right位置元素 :\n\n
  * &emsp;&emsp;&emsp; 交换pivot和right位置元素\n\n
  * &emsp;&emsp;&emsp; left<span style="color:#283593;font-weight:bold">(左边界)</span>修改为pivot + 1\n
  * &emsp;&emsp;&emsp; pivot修改为right<span style="color:#283593;font-weight:bold">(右边界)</span>\n\n
  * &emsp;&emsp;&emsp; break跳出循环<span style="color:#008040;font-weight:bold">(本轮从右向左逼近结束)</span>\n\n
  * <span style="color:#bc8f8f">
  * &emsp; (左侧逼近)\n
  * </span>
  * &emsp; **for loop** left <= pivot; left++ :\n
  * &emsp;&emsp; **if** pivot位置元素 < left位置元素 :\n\n
  * &emsp;&emsp;&emsp; 交换pivot和left位置元素\n\n
  * &emsp;&emsp;&emsp; right<span style="color:#283593;font-weight:bold">(右边界)</span>修改为pivot - 1\n
  * &emsp;&emsp;&emsp; pivot修改为left<span style="color:#283593;font-weight:bold">(左边界)</span>\n\n
  * &emsp;&emsp;&emsp; break跳出循环<span style="color:#008040;font-weight:bold">(本轮从左向右逼近结束)</span>\n\n
  * 返回pivot\n
  *
  *
  * ---------------
  */
template<typename TElement>
int Partition(TElement* elements, int left, int right) {

    int pivot = left;                                               // 声明并初始化pivot(轴), 等于left(数组左边界)

    while (left <= right) {                                         // while loop left <= right (左右边界还有向中间逼近的可能)

        // (右侧逼近)
        for (; right >= pivot; right--) {                           // for loop right>= pivot; right--
            if (elements[pivot] > elements[right]) {                // if pivot位置元素 > right位置元素

                Swap(elements + pivot, elements + right);           // 交换pivot和right位置元素

                left = pivot + 1;                                   // left(左边界)修改为pivot + 1
                pivot = right;                                      // pivot修改为right(右边界)

                break;                                              // break跳出循环(本轮从右向左逼近结束)
            }
        }

        // (左侧逼近)
        for (; left <= pivot; left++) {                             // for loop left <= pivot; left++
            if (elements[pivot] < elements[left]) {                 // if pivot位置元素 < left位置元素

                Swap(elements + left, elements + pivot);            // 交换pivot和left位置元素

                right = pivot - 1;                                  // right(右边界)修改为pivot - 1
                pivot = left;                                       // pivot修改为left(左边界)

                break;                                              // break跳出循环(本轮从左向右逼近结束)
            }
        }
    }

    return pivot;                                                   // 返回pivot
}


/*!
 * @brief **子数组快速排序(递归)**
 * @tparam TElement 数组元素类型模板参数
 * @param elements 数组
 * @param left 左边界
 * @param right 右边界
 * @note
 * 子数组快速排序(递归)
 * -----------------
 * -----------------
 *
 * -----------------
 * + **1 边界条件判断**\n\n
 * **if** left >= right :\n
 * &emsp; 退出函数\n\n
 * + **2 划分区域**\n\n
 * 调用Partition划分数组, 取返回值为pivot<span style="color:#283593;font-weight:bold">(轴)</span>\n\n
 * + **3 分治递归**\n\n
 * 对轴的左侧区域进行递归\n
 * 对轴的右侧区域进行递归\n
 *
 *
 * -----------------
 */
template<typename TElement>
void QuickSortInSubArrayRecursive(TElement* elements, int left, int right) {

    // ---------- 1 边界条件判断 ----------

    if (left >= right) {                                            // if left >= right
        return;                                                     // 退出函数
    }

    // ---------- 2 划分区域 ----------

    int pivot = Partition(elements, left, right);                   // 调用Partition划分数组, 取返回值为pivot(轴)

    // ---------- 3 分治递归 ----------

    QuickSortInSubArrayRecursive(elements, left, pivot - 1);        // 对轴的左侧区域进行递归
    QuickSortInSubArrayRecursive(elements, pivot + 1, right);       // 对轴的右侧区域进行递归
}
