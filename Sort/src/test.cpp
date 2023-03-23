/*!
 * @file test.cpp
 * @author CyberDash, cyberdash@163.com(id:cyberdash_yuan)
 * @brief 测试函数cpp文件
 * @version 0.2.1
 * @date 2021-09-19
 * @copyright Copyright (c) 2021
 *  CyberDash
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


void TestBubbleSort() {

	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                      Test Bubble Sort                     |" << endl;
	cout << "|                        测试冒泡排序                         |" << endl;

    int array[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
	int array_size = sizeof(array) / sizeof(int);

	cout << "排序后:" << endl;
	PrintArray<int>(array, array_size);

	BubbleSort<int>(array, array_size);

	cout << "排序前:" << endl;
	PrintArray(array, array_size);

	cout << "------------------------- CyberDash -------------------------" << endl;
}


void TestSelectionSort() {

	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                      Test Select Sort                     |" << endl;
	cout << "|                        测试选择排序                         |" << endl;

    int array[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
	int array_size = sizeof(array) / sizeof(int);

	cout << "排序后:" << endl;
	PrintArray<int>(array, array_size);

	SelectionSort<int>(array, array_size);

	cout << "排序前:" << endl;
	PrintArray<int>(array, array_size);

	cout << "------------------------- CyberDash -------------------------" << endl;
}


void TestInsertSort() {

	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                      Test Insert Sort                     |" << endl;
	cout << "|                         测试插入排序                        |" << endl;

    int array[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
	int array_size = sizeof(array) / sizeof(int);

	cout << "排序前:" << endl;
	PrintArray<int>(array, array_size);

	InsertionSort<int>(array, array_size);

	cout << "排序后:" << endl;
	PrintArray<int>(array, array_size);

	cout << "------------------------- CyberDash -------------------------" << endl;
}


void TestMergeSort() {

	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                      Test Merge Sort                      |" << endl;
	cout << "|                         测试归并排序                        |" << endl;

    int array[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
	int array_size = sizeof(array) / sizeof(int);

	cout << "排序前:" << endl;
	PrintArray<int>(array, array_size);

    MergeSortRecursive<int>(array, array_size);

	cout << "排序后:" << endl;
	PrintArray<int>(array, array_size);

	cout << "------------------------- CyberDash -------------------------" << endl;
}


void TestMergeSortNonRecursive() {

	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|               Test Merge Sort(NonRecursive)               |" << endl;
	cout << "|                     测试快速排序(非递归)                     |" << endl;

    int array[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
	int array_size = sizeof(array) / sizeof(int);

	cout << "排序前:" << endl;
	PrintArray<int>(array, array_size);

    MergeSort<int>(array, array_size);

	cout << "排序后:" << endl;
	PrintArray<int>(array, array_size);

	cout << "-------------------------------------------------------------" << endl;
}


void TestQuickSort() {
	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                      Test Quick Sort                      |" << endl;
	cout << "|                        测试快速排序                         |" << endl;

    int array[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
	int array_size = sizeof(array) / sizeof(int);

	cout << "排序前:" << endl;
	PrintArray<int>(array, array_size);

    QuickSortRecursive<int>(array, array_size);

	cout << "排序后:" << endl;
	PrintArray<int>(array, array_size);

	cout << "-------------------------------------------------------------" << endl;
}


void TestHeapSort() {
	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                       Test Heap Sort                      |" << endl;
	cout << "|                         测试堆排序                          |" << endl;

	int array[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
	int array_size = sizeof(array) / sizeof(int);

	cout << "排序前:" << endl;
	PrintArray<int>(array, array_size);

	HeapSort<int>(array, array_size);

	cout << "排序后:" << endl;
	PrintArray<int>(array, array_size);

	cout << "------------------------- CyberDash -------------------------" << endl;
}


void TestShellSort() {
	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                      Test Shell Sort                      |" << endl;
	cout << "|                        测试希尔排序                        |" << endl;

	int array[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
	int array_size = sizeof(array) / sizeof(int);

	cout << "排序前:" << endl;
	PrintArray<int>(array, array_size);

	int gaps[3] = { 3, 2, 1 };
    int gaps_count = 3;

	ShellSort<int>(array, gaps, array_size, gaps_count);

	cout << "排序后:" << endl;
	PrintArray<int>(array, array_size);

	cout << "------------------------- CyberDash -------------------------" << endl;
}


void TestRadixSort() {
	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                      Test Radix Sort                      |" << endl;
	cout << "|                      测试基数(链表)排序                        |" << endl;


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


void TestRadixSortForArray() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                      Test Radix Sort                      |" << endl;
    cout << "|                        测试基数排序                        |" << endl;

    int array[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
    int array_size = sizeof(array) / sizeof(int);

    cout << "排序前:" << endl;
    PrintArray<int>(array, array_size);

    RadixSort(array, array_size);

    cout << "排序后:" << endl;
    PrintArray<int>(array, array_size);

    cout << "------------------------- CyberDash -------------------------" << endl;
}
