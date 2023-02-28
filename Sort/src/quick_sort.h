/*!
 * @file quick_sort.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 快速排序
 * @version 0.2.1
 * @date 2021-09-19
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#include "util.h"


/*!
 * @brief **快速排序(递归)**
 * @tparam TElement 数组元素类型模板参数
 * @param elements 数组
 * @param size 数组长度
 * @note
 * 快速排序(递归)
 * ------------
 * ------------
 *
 * ------------
 * + **1 初始化左右边界**\n
 * + **2 调用递归函数排序**\n
 */
template<typename TElement>
void QuickSortRecursive(TElement* elements, int size) {
    int left = 0;
    int right = size - 1;

    QuickSortInSubArrayRecursive(elements, left, right);
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
  * &emsp; 当pivot在左侧, 从右向左逼近: 如果右侧遍历至某元素, 不符合排序规则, 与pivot位置元素交换\n
  * &emsp; 当pivot在右侧, 从左向右逼近: 如果左侧遍历至某元素, 不符合排序规则, 与pivot位置元素交换\n
  * </span>
  *
  * ---------------
  * 声明并初始化pivot(轴), 等于left(数组左边界)\n
  * **while loop** left <= right (左右边界还有向中间逼近的可能) :\n
  * &emsp; (右侧逼近)\n
  * &emsp; **for loop** right>= pivot; right-- :\n
  * &emsp;&emsp; **if** pivot位置元素 > right位置元素 :\n
  * &emsp;&emsp;&emsp; 交换pivot和right位置元素\n
  * &emsp;&emsp;&emsp; left(左边界)修改为pivot + 1\n
  * &emsp;&emsp;&emsp; pivot修改为right(右边界)\n
  * &emsp;&emsp;&emsp; break跳出循环(本轮从右向左逼近结束)\n
  * &emsp; (左侧逼近)\n
  * &emsp; **for loop** left <= pivot; right-- :\n
  * &emsp;&emsp; **if** pivot位置元素 < left位置元素 :\n
  * &emsp;&emsp;&emsp; 交换pivot和left位置元素\n
  * &emsp;&emsp;&emsp; right(右边界)修改为pivot - 1\n
  * &emsp;&emsp;&emsp; pivot修改为left(左边界)\n
  * &emsp;&emsp;&emsp; break跳出循环(本轮从左向右逼近结束)\n
  * 返回pivot\n
  */
template<typename TElement>
int Partition(TElement* elements, int left, int right) {

    int pivot = left;

    while (left <= right) {

        for (; right >= pivot; right--) {
            if (elements[pivot] > elements[right]) {
                Swap(elements + pivot, elements + right);
                left = pivot + 1;
                pivot = right;
                break;
            }
        }

        for (; left <= pivot; left++) {
            if (elements[pivot] < elements[left]) {
                Swap(elements + left, elements + pivot);
                right = pivot - 1;
                pivot = left;
                break;
            }
        }
    }

    return pivot;
}


/*!
 * @brief 子数组快速排序(递归)
 * @tparam TElement 数组元素类型模板参数
 * @param elements 数组
 * @param left 左边界
 * @param right 右边界
 */
template<typename TElement>
void QuickSortInSubArrayRecursive(TElement* elements, int left, int right) {

    if (left >= right) {
        return;
    }

    int pivot = Partition(elements, left, right);

    QuickSortInSubArrayRecursive(elements, left, pivot - 1);
    QuickSortInSubArrayRecursive(elements, pivot + 1, right);
}

