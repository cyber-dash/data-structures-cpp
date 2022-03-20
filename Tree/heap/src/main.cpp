//
// Created by alei_go@163.com(: cyberdash_yuan) on 2020/11/1.
//

#include <iostream>

using namespace std;

#include "min_heap.h"
#include "min_heap.cpp"

int main(void) {
    int arr[] = { 3,2,6,7,8,4,5,34 };

    MinHeap<int> heap(arr, sizeof(arr) / sizeof(arr[0]));

    heap.Insert(99);
    heap.Insert(0);
    heap.Insert(100);

    cout << "is full:" << heap.IsFull() << endl;
    cout << "is empty:" << heap.IsEmpty() << endl;

    int item;

    while (!heap.IsEmpty()) {
        heap.RemoveMin(item);
        cout << item << " ";
    }

    return 0;
}