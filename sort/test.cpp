//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2/22/2021.
//

#include "test.h"
#include "sort.h"
#include "util.h"
#include <iostream>


using namespace std;


void TestBubbleSort() {
  cout<<endl;
  cout<<"************************* CyberDash *************************"<<endl;
  cout<<"*                      Test Bubble Sort                     *"<<endl;
  cout<<"*                        测试冒泡排序                         *"<<endl;
  cout<<"************************* CyberDash *************************"<<endl<<endl;

  int array[] = { 1, 4, 2, 8, 5, 7 };
  int array_size = sizeof(array) / sizeof(int);

  cout<<"Before bubble sort:"<<endl;
  array_show(array, array_size);

  bubble_sort(array, array_size);

  cout<<"After bubble sort:"<<endl;
  array_show(array, array_size);
}


void TestSelectSort() {
  cout<<endl;
  cout<<"************************* CyberDash *************************"<<endl;
  cout<<"*                      Test Select Sort                     *"<<endl;
  cout<<"*                        测试选择排序                         *"<<endl;
  cout<<"************************* CyberDash *************************"<<endl<<endl;

  int array[] = { 1, 4, 2, 8, 5, 7 };
  int array_size = sizeof(array) / sizeof(int);

  cout<<"Before select sort:"<<endl;
  array_show(array, array_size);

  select_sort(array, array_size);

  cout<<"After select sort:"<<endl;
  array_show(array, array_size);
}


void TestInsertSort() {
  cout<<endl;
  cout<<"************************* CyberDash *************************"<<endl;
  cout<<"*                      Test Insert Sort                     *"<<endl;
  cout<<"*                         测试插入排序                        *"<<endl;
  cout<<"************************* CyberDash *************************"<<endl<<endl;

  int array[] = { 1, 4, 2, 8, 5, 7 };
  int array_size = sizeof(array) / sizeof(int);

  cout<<"Before insert sort:"<<endl;
  array_show(array, array_size);

  insert_sort(array, array_size);

  cout<<"After insert sort:"<<endl;
  array_show(array, array_size);
}


void TestMergeSort() {

}


void TestQuickSort() {
  cout<<endl;
  cout<<"*************************  CyberDash  *************************"<<endl;
  cout<<"*                      Test Quick Sort                        *"<<endl;
  cout<<"*                        测试快速排序                           *"<<endl;
  cout<<"*************************  CyberDash  *************************"<<endl<<endl;

  int array[] = { 1, 4, 2, 8, 5, 7 };
  int array_size = sizeof(array) / sizeof(int);

  cout<<"Before quick sort:"<<endl;
  array_show(array, array_size);

  quick_sort(array, 0, array_size - 1);

  cout<<"After quick sort:"<<endl;
  array_show(array, array_size);
}



void TestHeapSort() {
  cout<<endl;
  cout<<"************************* CyberDash *************************"<<endl;
  cout<<"*                       Test Heap Sort                      *"<<endl;
  cout<<"*                         测试堆排序                          *"<<endl;
  cout<<"************************* CyberDash *************************"<<endl<<endl;

  int array[] = { 1, 4, 2, 8, 5, 7 };
  int array_size = sizeof(array) / sizeof(int);

  cout<<"Before heap sort:"<<endl;
  array_show(array, array_size);

  heap_sort(array, array_size);

  cout<<"After heap sort:"<<endl;
  array_show(array, array_size);
}

