//
// Created by cyberdash@163.com on 2022/6/16.
//

#ifndef CYBER_DASH_PRIORITY_QUEUE_H
#define CYBER_DASH_PRIORITY_QUEUE_H


#include "./min_heap.h"


template <class T>
class MinPriorityQueue {

public:
    MinPriorityQueue(): min_heap_() { }
    MinPriorityQueue(T arr[], int size): min_heap_(arr, size) { }

    bool Enqueue(const T& item) { return min_heap_.Insert(item); }
    bool Dequeue(T& item) { return min_heap_.Pop(item); }
    bool Top(T& item) { return min_heap_.Top(item); }
    int Size() { return min_heap_.Size(); }
    void Clear() { min_heap_.MakeEmpty(); }

private:
    MinHeap<T> min_heap_;
};


#endif // CYBER_DASH_PRIORITY_QUEUE_H
