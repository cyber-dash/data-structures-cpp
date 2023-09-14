﻿/*!
 * @file test.cpp
 * @author CyberDash, cyberdash@163.com(id:cyberdash_yuan)
 * @brief 测试函数cpp文件
 * @version 0.2.1
 * @date 2021-09-19
 */

#include "test.h"
#include "heap_sort.h"
#include "bubble_sort.h"
#include "selection_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "shell_sort.h"
#include "radix_sort_for_linked_list.h"
#include "radix_sort.h"
#include "util.h"
#include <iostream>


using namespace std;


/*!
 * @brief **测试-排序-冒泡排序**
 * @note
 * 测试-排序-冒泡排序
 * ---------------
 * ---------------
 *
 * ---------------
 * 初始化无序数组{ 3, 1, 4, 1, 5, 9, 2, 6 }\n
 * 打印数组\n\n
 * 执行冒泡排序\n
 * 打印数组\n
 *
 *
 * ---------------
 */
void TestBubbleSort() {

	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                      Test Bubble Sort                     |" << endl;
	cout << "|                      测试-排序-冒泡排序                      |" << endl << endl << endl;

    int array[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
	int array_size = sizeof(array) / sizeof(int);

	cout << "排序前:" << endl;
	PrintArray<int>(array, array_size);

    cout << endl;

	BubbleSort<int>(array, array_size);

	cout << "排序后:" << endl;
	PrintArray(array, array_size);

	cout << "------------------------- CyberDash -------------------------" << endl;
}


/*!
 * @brief **测试-排序-选择排序**
 * @note
 * 测试-排序-选择排序
 * ---------------
 * ---------------
 *
 * ---------------
 * 初始化无序数组{ 3, 1, 4, 1, 5, 9, 2, 6 }\n
 * 打印数组\n\n
 * 执行选择排序\n
 * 打印数组\n
 *
 *
 * ---------------
 */
void TestSelectionSort() {

	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                      Test Select Sort                     |" << endl;
	cout << "|                      测试-排序-选择排序                      |" << endl;

    // 初始化无序数组{ 3, 1, 4, 1, 5, 9, 2, 6 }
    int array[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
	int array_size = sizeof(array) / sizeof(int);

    // 打印数组
	cout << "排序前:" << endl;
	PrintArray<int>(array, array_size);

    cout << endl;

    // 执行选择排序
	SelectionSort<int>(array, array_size);

    // 打印数组
	cout << "排序后:" << endl;
	PrintArray<int>(array, array_size);

	cout << "------------------------- CyberDash -------------------------" << endl;
}


/*!
 * @brief **测试-排序-插入排序**
 * @note
 * 测试-排序-插入排序
 * ---------------
 * ---------------
 *
 * ---------------
 * 初始化无序数组{ 3, 1, 4, 1, 5, 9, 2, 6 }\n
 * 打印数组\n\n
 * 执行插入排序\n
 * 打印数组\n
 *
 *
 * ---------------
 */
void TestInsertSort() {

	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                      Test Insert Sort                     |" << endl;
	cout << "|                      测试-排序-插入排序                      |" << endl;

    // 初始化无序数组{ 3, 1, 4, 1, 5, 9, 2, 6 }
    int array[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
	int array_size = sizeof(array) / sizeof(int);

    // 打印数组
	cout << "排序前:" << endl;
	PrintArray<int>(array, array_size);

    // 执行插入排序
	InsertionSort<int>(array, array_size);

    // 打印数组
	cout << "排序后:" << endl;
	PrintArray<int>(array, array_size);

	cout << "------------------------- CyberDash -------------------------" << endl;
}


/*!
 * @brief **测试-排序-归并排序(递归)**
 * @note
 * 测试-排序-归并排序(递归)
 * --------------------
 * --------------------
 *
 * --------------------
 * 初始化无序数组{ 3, 1, 4, 1, 5, 9, 2, 6 }\n
 * 打印数组\n\n
 * 执行归并排序(递归)\n
 * 打印数组\n
 *
 *
 * --------------------
 */
void TestMergeSortRecursive() {

	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                  Test MergeSortRecursive                  |" << endl;
	cout << "|                   测试-排序-归并排序(递归)                   |" << endl;

    // 初始化无序数组{ 3, 1, 4, 1, 5, 9, 2, 6 }
    int array[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
	int array_size = sizeof(array) / sizeof(int);

    // 打印数组
	cout << "排序前:" << endl;
	PrintArray<int>(array, array_size);

    // 执行归并排序(递归)
    MergeSortRecursive<int>(array, array_size);

    // 打印数组
	cout << "排序后:" << endl;
	PrintArray<int>(array, array_size);

	cout << "------------------------- CyberDash -------------------------" << endl;
}


/*!
 * @brief **测试-排序-归并排序**
 * @note
 * 测试-排序-归并排序
 * ---------------
 * ---------------
 *
 * ---------------
 * 初始化无序数组{ 3, 1, 4, 1, 5, 9, 2, 6 }\n
 * 打印数组\n\n
 * 执行归并排序\n
 * 打印数组\n
 *
 *
 * ---------------
 */
void TestMergeSort() {

	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                       Test MergeSort                      |" << endl;
	cout << "|                      测试-排序-归并排序                      |" << endl;

    // 初始化无序数组{ 3, 1, 4, 1, 5, 9, 2, 6 }
    int array[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
	int array_size = sizeof(array) / sizeof(int);

    // 打印数组
	cout << "排序前:" << endl;
	PrintArray<int>(array, array_size);

    // 执行归并排序
    MergeSort<int>(array, array_size);

    // 打印数组
	cout << "排序后:" << endl;
	PrintArray<int>(array, array_size);

	cout << "-------------------------------------------------------------" << endl;
}


/*!
 * @brief **测试-排序-快速排序(递归)**
 * @note
 * 测试-排序-快速排序(递归)
 * --------------------
 * --------------------
 *
 * --------------------
 * 初始化无序数组{ 3, 1, 4, 1, 5, 9, 2, 6 }\n
 * 打印数组\n\n
 * 执行快速排序(递归)\n
 * 打印数组\n
 *
 *
 * --------------------
 */
void TestQuickSortRecursive() {
	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                      Test QuickSort                       |" << endl;
	cout << "|                   测试-排序-快速排序(递归)                   |" << endl;

    // 初始化无序数组{ 3, 1, 4, 1, 5, 9, 2, 6 }
    int array[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
	int array_size = sizeof(array) / sizeof(int);

    // 打印数组
	cout << "排序前:" << endl;
	PrintArray<int>(array, array_size);

    // 执行快速排序(递归)
    QuickSort<int>(array, array_size);

    // 打印数组
	cout << "排序后:" << endl;
	PrintArray<int>(array, array_size);

	cout << "-------------------------------------------------------------" << endl;
}


/*!
 * @brief **测试-排序-堆排序**
 * @note
 * 测试-排序-堆排序
 * --------------
 * --------------
 *
 * --------------
 * 初始化无序数组{ 3, 1, 4, 1, 5, 9, 2, 6 }\n
 * 打印数组\n\n
 * 执行堆排序\n
 * 打印数组\n
 *
 *
 * --------------------
 */
void TestHeapSort() {
	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                       Test Heap Sort                      |" << endl;
	cout << "|                         测试-堆排序                         |" << endl;

    // 初始化无序数组{ 3, 1, 4, 1, 5, 9, 2, 6 }
	int array[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
	int array_size = sizeof(array) / sizeof(int);

    // 打印数组
	cout << "排序前:" << endl;
	PrintArray<int>(array, array_size);

    // 执行堆排序
	HeapSort<int>(array, array_size);

    // 打印数组
	cout << "排序后:" << endl;
	PrintArray<int>(array, array_size);

	cout << "------------------------- CyberDash -------------------------" << endl;
}


/*!
 * @brief **测试-排序-希尔排序**
 * @note
 * 测试-排序-希尔排序
 * --------------
 * --------------
 *
 * --------------
 * 初始化无序数组{ 3, 1, 4, 1, 5, 9, 2, 6 }\n
 * 打印数组\n\n
 * 执行希尔排序\n
 * 打印数组\n
 *
 *
 * --------------------
 */
void TestShellSort() {
	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                      Test Shell Sort                      |" << endl;
	cout << "|                      测试-排序-希尔排序                      |" << endl;

    // 初始化无序数组{ 3, 1, 4, 1, 5, 9, 2, 6 }
	int array[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
	int array_size = sizeof(array) / sizeof(int);

    // 打印数组
	cout << "排序前:" << endl;
	PrintArray<int>(array, array_size);

    // 执行希尔排序
	int gaps[3] = { 3, 2, 1 };
    int gaps_count = 3;

	ShellSort<int>(array, gaps, array_size, gaps_count);

    // 打印数组
	cout << "排序后:" << endl;
	PrintArray<int>(array, array_size);

	cout << "------------------------- CyberDash -------------------------" << endl;
}


/*!
 * @brief **测试-排序-基数排序(链表)**
 * @note
 * 测试-排序-基数排序(链表)
 * --------------
 * --------------
 *
 * --------------
 */
void TestRadixSort() {
	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                      Test Radix Sort                      |" << endl;
	cout << "|                    测试-排序-基数排序(链表)                  |" << endl;


    /// ### 1 初始化静态链表 ###
    radix_static_linked_list_t<char> radix_static_linked_list;

    /// - 5位数值正整数
    radix_static_linked_list.number_of_digit = 5;  // 元素位数
    /// - 9个数(静态链表长度9)
    radix_static_linked_list.length = 9;        // 静态链表长度

    /// - 静态链表表头初始化
    StaticLinkedListNode<char> element_zero;
    element_zero.key[0] = 0;
    element_zero.key[1] = 0;
    element_zero.key[2] = 0;
    element_zero.key[3] = 0;
    element_zero.key[4] = 0;
    element_zero.next = 1;

    radix_static_linked_list.elements[0] = element_zero;

    srand((unsigned)time(NULL));

    /// ### 2 随机构造基数排序静态链表 ###
    /// &emsp; **for loop** 静态链表长度 : \n
    for (int i = 1; i <= radix_static_linked_list.length; i++) {
        /// &emsp;&emsp; 声明当前静态链表元素\n
        StaticLinkedListNode<char> node;

        /// &emsp;&emsp; **for loop** 元素位数 :\n
        /// &emsp;&emsp;&emsp; 首位随机赋值'1' - '9' \n
        /// &emsp;&emsp;&emsp; 第一个越界位赋值'\0'(字符串结束字符) \n
        /// &emsp;&emsp;&emsp; 其他位随机赋值'0' - '9' \n
        for (int j = 0; j <= radix_static_linked_list.number_of_digit; j++) {
            if (j == 0) {
                node.key[j] = NUM_1_ASCII_CODE + (rand() % 9);
            } else if (j == radix_static_linked_list.number_of_digit) {
                node.key[j] = 0;
            } else {
                node.key[j] = NUM_0_ASCII_CODE + (rand() % 10);
            }
        }

        /// &emsp;&emsp; next指向下一个元素, 如果是最后一个元素next则指向0
        if (i != radix_static_linked_list.length) {
            node.next = i + 1;
        } else {
            node.next = 0;
        }

        /// &emsp;&emsp; 将当前元素赋给静态链表elements[i]
        radix_static_linked_list.elements[i] = node;
    }

    /// ### 4 排序前静态链表打印 ###
    printf("排序前:\n");
    RadixArrayOutput((StaticLinkedListNode<char>*)&radix_static_linked_list.elements,
                     radix_static_linked_list.length);

    /// ### 5 调用RadixSort执行基数排序 ###
    RadixSort(&radix_static_linked_list);

    /// ### 6 排序后静态链表打印 ###
    printf("排序后:\n");
    RadixArrayOutput((StaticLinkedListNode<char>*)&radix_static_linked_list.elements,
                     radix_static_linked_list.length);


	cout << "------------------------- CyberDash -------------------------" << endl;
}


/*!
 * @brief **测试-排序-基数排序(数组)**
 * @note
 * 测试-排序-基数排序(数组)
 * --------------
 * --------------
 *
 * --------------
 * 初始化无序数组{ 3, 1, 4, 1, 5, 9, 2, 6 }\n
 * 打印数组\n\n
 * 执行基数排序(数组)\n
 * 打印数组\n
 *
 *
 * --------------------
 */
void TestRadixSortForArray() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                      Test Radix Sort                      |" << endl;
    cout << "|                    测试-排序-基数排序(数组)                  |" << endl;

    // 初始化无序数组{ 3, 1, 4, 1, 5, 9, 2, 6 }
    int array[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
    int array_size = sizeof(array) / sizeof(int);

    // 打印数组
    cout << "排序前:" << endl;
    PrintArray<int>(array, array_size);

    // 执行基数排序(数组)
    RadixSort(array, array_size);

    // 打印数组
    cout << "排序后:" << endl;
    PrintArray<int>(array, array_size);

    cout << "------------------------- CyberDash -------------------------" << endl;
}
