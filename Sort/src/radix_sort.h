/*!
 * @file radix_sort.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 基数排序
 * @version 0.2.1
 * @date 2021-09-19
 */

#ifndef CYBER_DASH_RADIX_SORT_H
#define CYBER_DASH_RADIX_SORT_H


#include <iostream>
using namespace std;


/*!
 * @brief **获取数组中最大的元素**
 * @param elements 数组
 * @param size 数组长度
 * @return 最大元素值
 * @note
 * 获取数组中最大的元素
 * -----------------
 * -----------------
 *
 * -----------------
 * 初始化max_element为elements[0]\n\n
 * **for loop** 遍历数组索引, 从1到size - 1 :\n
 * &emsp; **if** 当前元素 > max_element :\n
 * &emsp;&emsp; max_element <--- 当前元素\n
 * 返回max_element\n
 */
int Max(const int* elements, int size) {
    int max_element = elements[0];

    for (int i = 1; i < size; i++) {
        if (elements[i] > max_element) {
            max_element = elements[i];
        }
    }

    return max_element;
}


/*!
 * @brief **桶排序**
 * @param elements 数组
 * @param size 数组长度
 * @param power_value 幂值
 * @note
 * 桶排序
 * -----
 * -----
 *
 * -----
 * + **1 初始化缓存数组和桶数组**\n
 * 初始化caches(缓存数组)\n
 * 初始化buckets(桶数组)\n
 * + **2 使用power构造buckets(每个bucket, 对应digit有多少个数)**\n
 * **for loop** 遍历数组 :\n
 * &emsp; 计算digit, 等于(elements[i] / power_value) % 10\n
 * &emsp; buckets[digit]++\n
 * + **3 将buckets改造成digit在数组中的分布**\n
 * **for loop** 1到9 :\n
 * &emsp; buckets[i] = buckets[i] + buckets[i - 1]\n
 * + **4 从后向前遍历elements, 利用buckets, 构造caches**\n
 * **for loop** size - 1 到 0 :\n
 * &emsp; 计算digit, 等于(elements[i] / power_value) % 10\n
 * &emsp; caches[buckets[digit] - 1 ] = elements[i]\n
 * &emsp; buckets[digit]--\n
 * + **5 将caches赋值到elements**\n
 * **for loop** 遍历caches :\n
 * &emsp; caches[i]赋给elements[i]\n
 * + **6 收尾工作**\n
 * delete[] caches\n
 */
void BucketSort(int* elements, int size, int power_value) {

    // ---------- 1 初始化缓存数组和桶数组 ----------

    int* caches = new int[size];                            // 初始化caches(缓存数组)
    int buckets[10] = { 0 };                                // 初始化buckets(桶数组)

    // ---------- 2 使用power构造buckets(每个bucket, 对应digit有多少个数) ----------

    for (int i = 0; i < size; i++) {                        // for loop 遍历数组
        int digit = (elements[i] / power_value) % 10;       // 计算digit, 等于(elements[i] / power_value) % 10
        buckets[digit]++;                                   // buckets[digit]++
    }

    // ---------- 3 将buckets改造成digit在数组中的分布 ----------

    for (int i = 1; i < 10; i++) {                          // for loop 1到9
        buckets[i] += buckets[i - 1];                       // buckets[i] = buckets[i] + buckets[i - 1]
    }

    // ---------- 4 从后向前遍历elements, 利用buckets, 构造caches ----------

    for (int i = size - 1; i >= 0; i--) {                   // for loop size - 1 到 0
        int digit = (elements[i] / power_value) % 10;       // 计算digit, 等于(elements[i] / power_value) % 10
        caches[buckets[digit] - 1 ] = elements[i];          // caches[buckets[digit] - 1 ] = elements[i]
        buckets[digit]--;                                   // buckets[digit]--
    }

    // ---------- 5 将caches赋值到elements ----------

    for (int i = 0; i < size; i++) {                        // for loop 遍历caches
        elements[i] = caches[i];                            // caches[i]赋给elements[i]
    }

    // ---------- 6 收尾工作 ----------

    delete[] caches;                                        // delete[] caches
}


/*!
 * @brief **基数排序**
 * @param elements 数组
 * @param size 数组长度
 * @note
 * 基数排序
 * -------
 * -------
 *
 * -------
 * 获取max_element(数组最大元素)\n
 * **for loop** 遍历10的幂值 :\n
 * &emsp; 调用BucketSort进行排序\n
 */
void RadixSort(int* elements, int size) {
    int max_element = Max(elements, size);                                          // 获取max_element(数组最大元素)

    for (int power_value = 1; max_element / power_value > 0; power_value *= 10) {   // for loop 遍历10的幂值
        BucketSort(elements, size, power_value);                                    // 调用BucketSort进行排序
    }
}


#endif // CYBER_DASH_RADIX_SORT_H
