/*!
 * @file util.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 工具.h文件
 * @version 0.2.1
 * @date 2021-09-19
 */

#ifndef CYBER_DASH_SORT_UTIL_H
#define CYBER_DASH_SORT_UTIL_H


#include <iostream>


using namespace std;


/*!
 * @brief **交换**
 * @tparam TElement 元素类型模板参数
 * @param a a元素
 * @param b b元素
 * @note
 * 交换
 * ---
 * ---
 *
 * ---
 *
 *
 * ---
 */
template<typename TElement>
void Swap(TElement* a, TElement* b) {

    if (*a == *b) {
        return;
    }

    TElement tmp = *a;
    *a = *b;
    *b = tmp;
}

/*!
 * @brief **打印数组**
 * @tparam TElement 数组元素类型模板参数
 * @param array 数组
 * @param size 数组长度
 * @note
 * 打印数组
 * -------
 * -------
 *
 * -------
 *
 *
 * -------
 */
template<typename TElement>
void PrintArray(TElement* array, int size) {

    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }

    cout << endl;
}


#endif //CYBER_DASH_SORT_UTIL_H
