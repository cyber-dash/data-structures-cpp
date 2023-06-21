/*!
 * @file main.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 测试demo演示
 * @version 0.2.1
 * @date 2021-09-19
 */

#include "test.h"


/*!
 * @brief **main函数**
 * @return 0
 * @note
 * main函数
 * -------
 * -------
 *
 * -------
 * 测试-排序-冒泡排序\n
 * 测试-排序-选择排序\n
 * 测试-排序-插入排序\n
 * 测试-排序-归并排序(递归)\n
 * 测试-排序-归并排序\n
 * 测试-排序-快速排序(递归)\n
 * 测试-排序-堆排序\n
 * 测试-排序-希尔排序\n
 * 测试-排序-基数排序(链表)\n
 * 测试-排序-基数排序(数组)\n
 *
 *
 * -------
 */
int main() {

    // 测试-排序-冒泡排序
	TestBubbleSort();

    // 测试-排序-选择排序
	TestSelectionSort();

    // 测试-排序-插入排序
	TestInsertSort();

    // 测试-排序-归并排序(递归)
    TestMergeSortRecursive();

    // 测试-排序-归并排序
    TestMergeSort();

    // 测试-排序-快速排序(递归)
	TestQuickSortRecursive();

    // 测试-排序-堆排序
	TestHeapSort();

    // 测试-排序-希尔排序
	TestShellSort();

    // 测试-排序-基数排序(链表)
	TestRadixSort();

    // 测试-排序-基数排序(数组)
    TestRadixSortForArray();

	return 0;
}
