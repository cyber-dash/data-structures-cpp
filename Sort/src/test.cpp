/*!
 * @file test.cpp
 * @author CyberDash, cyberdash@163.com(id:cyberdash_yuan)
 * @brief .cppļ
 * @version 0.2.1
 * @date 2021-09-19
 * @copyright Copyright (c) 2021
 *  CyberDash
 */

#include "test.h"
#include "sort.h"
#include "util.h"
#include <iostream>


using namespace std;


void TestBubbleSort() {

	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                      Test Bubble Sort                     |" << endl;
	cout << "|                        测试冒泡排序                         |" << endl;

	int array[] = { 1, 4, 2, 8, 5, 7 };
	int array_size = sizeof(array) / sizeof(int);

	cout << "排序后:" << endl;
	PrintArray(array, array_size);

	BubbleSort(array, array_size);

	cout << "排序前:" << endl;
	PrintArray(array, array_size);

	cout << "------------------------- CyberDash -------------------------" << endl;
}


void TestSelectSort() {

	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                      Test Select Sort                     |" << endl;
	cout << "|                        测试选择排序                         |" << endl;

	int array[] = { 1, 4, 2, 8, 5, 7 };
	int array_size = sizeof(array) / sizeof(int);

	cout << "排序后:" << endl;
	PrintArray(array, array_size);

	SelectSort(array, array_size);

	cout << "排序前:" << endl;
	PrintArray(array, array_size);

	cout << "------------------------- CyberDash -------------------------" << endl;
}


void TestInsertSort() {

	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                      Test Insert Sort                     |" << endl;
	cout << "|                         测试插入排序                        |" << endl;

	int array[] = { 1, 4, 2, 8, 5, 7 };
	int array_size = sizeof(array) / sizeof(int);

	cout << "排序前:" << endl;
	PrintArray(array, array_size);

	InsertSort(array, array_size);

	cout << "排序后:" << endl;
	PrintArray(array, array_size);

	cout << "------------------------- CyberDash -------------------------" << endl;
}


void TestMergeSort() {

	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                      Test Merge Sort                      |" << endl;
	cout << "|                         测试归并排序                        |" << endl;

	// int array[] = { 1, 4, 2, 8, 5, 7 };
    int array[] = { 4, 2, 8, 5, 7, 1 };
	int array_size = sizeof(array) / sizeof(int);

	cout << "排序前:" << endl;
	PrintArray(array, array_size);

	MergeSort(array, array_size);

	cout << "排序后:" << endl;
	PrintArray(array, array_size);

	cout << "------------------------- CyberDash -------------------------" << endl;
}


void TestMergeSortNonRecursive() {

	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|               Test Merge Sort(NonRecursive)               |" << endl;
	cout << "|                     测试快速排序(非递归)                     |" << endl;

	int array[] = { 1, 4, 2, 8, 5, 7 };
	int array_size = sizeof(array) / sizeof(int);

	cout << "排序前:" << endl;
	PrintArray(array, array_size);

	MergeSortNonRecursive(array, array_size);

	cout << "排序后:" << endl;
	PrintArray(array, array_size);

	cout << "-------------------------------------------------------------" << endl;
}


void TestQuickSort() {
	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                      Test Quick Sort                      |" << endl;
	cout << "|                        测试快速排序                         |" << endl;

	int array[] = { 1, 4, 2, 8, 5, 7 };
	int array_size = sizeof(array) / sizeof(int);

	cout << "排序前:" << endl;
	PrintArray(array, array_size);

	QuickSort(array, 0, array_size - 1);

	cout << "排序后:" << endl;
	PrintArray(array, array_size);

	cout << "-------------------------------------------------------------" << endl;
}



void TestHeapSort() {
	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                       Test Heap Sort                      |" << endl;
	cout << "|                         测试堆排序                         |" << endl;

	int array[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
	int array_size = sizeof(array) / sizeof(int);

	cout << "排序前:" << endl;
	PrintArray(array, array_size);

	HeapSort(array, array_size);

	cout << "排序后:" << endl;
	PrintArray(array, array_size);

	cout << "------------------------- CyberDash -------------------------" << endl;
}
