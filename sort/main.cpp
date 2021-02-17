//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/6/2.
//

#include <iostream>
#include "sort.h"
#include "util.h"


using namespace std;


int main(int argc, char** argv) {

  // 快速排序
  int heap_sort_array[] = { 8, 4, 2, 1, 5, 7 };
  int heap_sort_array_size = sizeof(heap_sort_array) / sizeof(int);

  cout<<"Before heap sort:"<<endl;
  array_show(heap_sort_array, heap_sort_array_size);

  heap_sort(heap_sort_array, heap_sort_array_size);

  cout<<"After heap sort:"<<endl;
  array_show(heap_sort_array, heap_sort_array_size);
  cout<<endl;

  // quick_sort(arr, 0, array_size - 1); // 快速排序
  // insert_sort(arr, array_size); // 插入排序
  // select_sort(arr, array_size); // 选择排序
  // bubble_sort(arr, array_size); // 选择排序

  // array_show(arr, array_size);

  CyberDashShow();

  return 0;
}

