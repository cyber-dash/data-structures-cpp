/*!
 * @file min_priority_queue.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 最小优先队列
 * @version 1.0.0
 * @date 2022-06-16
 */

#ifndef CYBER_DASH_MIN_PRIORITY_QUEUE_H
#define CYBER_DASH_MIN_PRIORITY_QUEUE_H


#include "min_heap.h"


template <typename TElement>
class MinPriorityQueue {

public:
    MinPriorityQueue(): min_heap_() {}
    MinPriorityQueue(TElement elements[], int size): min_heap_(elements, size) { }

    bool Enqueue(const TElement& element) { return min_heap_.Insert(element); }
    bool Dequeue(TElement& item) { return min_heap_.Pop(item); }
    bool Top(TElement& item) { return min_heap_.Top(item); }
    int Size() { return min_heap_.Size(); }
    void Clear() { min_heap_.Clear(); }

private:
    MinHeap<TElement> min_heap_;
};


#endif // CYBER_DASH_MIN_PRIORITY_QUEUE_H
