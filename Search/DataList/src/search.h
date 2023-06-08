/*!
 * @file search.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 线性表查找
 * @version 0.2.1
 * @date 2021-05-29
 */

#ifndef CYBER_DASH_SEARCH_IN_DATA_LIST_H
#define CYBER_DASH_SEARCH_IN_DATA_LIST_H


/*!
 * @brief **顺序查找**
 * @tparam Element 数组元素类型模板参数
 * @param elements 数组
 * @param size 数组长度
 * @param element 查找元素
 * @return 数组索引
 * @note
 * 顺序查找
 * -------
 * -------
 *
 * one by one
 *
 * -------
 * + **1 空列表处理**\n\n
 * **if** 空列表 :\n
 * &emsp; 返回-1\n\n
 * + **2 遍历查找**\n\n
 * 初始化i(数组索引)为0\n
 * **while loop** i < 列表长度 && 当前元素 != element :\n
 * &emsp; i向后移动1位\n\n
 * + **3 返回结果**\n\n
 * **if** i == 列表长度 :\n
 * &emsp; 返回-1\n\n
 * 返回i\n
 */
template<typename Element>
int SequentialSearch(Element* elements, int size, Element element) {

    // ---------- 1 空列表处理 ----------

    if (size == 0) {                                                                            // if 空列表
        return -1;                                                                              // 返回-1
    }

    // ---------- 2 遍历查找 ----------

    int i = 0;                                                                                  // 初始化i(数组索引)为0
    while (i < size && elements[i] != element) {                                                // while loop i < 列表长度 && 当前元素 != element
        i++;                                                                                    // i向后移动1位
    }

    // ---------- 3 返回结果 ----------

    if (i == size) {                                                                            // if i == 列表长度
        return -1;                                                                              // 返回-1
    }

    return i;                                                                                   // 返回i
}


/*!
 * @brief **二分查找**
 * @tparam Element 数组元素类型模板参数
 * @param elements 升序数组
 * @param size 升序数组长度
 * @param element 查找元素
 * @return 数组索引
 * @note
 * 顺序查找
 * -------
 * -------
 *
 * 数组必须是升序的
 *
 * -------
 * + **1 初始化左右边界**\n\n
 * 初始化left(左边界)为0\n
 * 初始化right(右边界)为size - 1\n\n
 * + **2 查找**\n\n
 * **while loop** 左边界 <= 右边界 :\n
 * &emsp; 取mid\n\n
 * &emsp; **if** 查找元素 > 中间元素 :\n
 * &emsp;&emsp; 左边界改为mid + 1\n
 * &emsp; **else if** 查找元素 < 中间元素 :\n
 * &emsp;&emsp; 右边界改为mid - 1\n
 * &emsp; **else**\n
 * &emsp;&emsp; 返回mid\n\n
 * + **3 退出函数**\n\n
 * 返回-1\n
 */
template<typename Element>
int BinarySearch(Element* elements, int size, Element element) {

    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (element > elements[mid]) {
            left = mid + 1;
        } else if (element < elements[mid]) {
            right = mid - 1;
        } else {
            return mid;
        }
    }

    return -1;
}


#endif //CYBER_DASH_SEARCH_IN_DATA_LIST_H