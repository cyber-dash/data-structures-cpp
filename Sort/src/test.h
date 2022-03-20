/*!
 * @file test.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 排序测试.h文件
 * @version 0.2.1
 * @date 2021-09-19
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#ifndef CYBER_DASH_SORT_TEST_H
#define CYBER_DASH_SORT_TEST_H


#include "util.h"


 /*! 测试冒泡排序 */
void TestBubbleSort();

/*! 测试选择排序 */
void TestSelectSort();

/*! 测试插入排序 */
void TestInsertSort();

/*! 测试归并排序 */
void TestMergeSort();

/*! 测试归并排序(非递归) */
void TestMergeSortNonRecursive();

/*! 测试快速排序 */
void TestQuickSort();

/*! 测试堆排序 */
void TestHeapSort();


#endif //CYBER_DASH_SORT_TEST_H
