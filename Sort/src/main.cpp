/*!
 * @file main.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 测试demo演示
 * @version 0.2.1
 * @date 2021-09-19
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#include "test.h"


int main() {

	TestBubbleSort();

	TestSelectSort();

	TestInsertSort();

    TestMergeSort();

	TestMergeSortNonRecursive();

	TestQuickSort();

	TestHeapSort();

	CyberDashShow();

	return 0;
}
