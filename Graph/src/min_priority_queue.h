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


/*!
 * 最小优先队列
 * @tparam TElement 队列元素类型模板参数
 */
template <typename TElement>
class MinPriorityQueue {
public:
    /*!
     * @brief **默认构造函数**
     * @note
     * 默认构造函数
     * ----------
     * ----------
     *
     * ----------
     */
    MinPriorityQueue(): min_heap_() {}

    /*!
     * @brief **构造函数(元素数组首地址和堆size)**
     * @param elements 元素数组首地址
     * @param size 堆size
     * @note
     * 构造函数(元素数组首地址和堆size)
     * ----------------------------
     * ----------------------------
     *
     * 使用elements和size对min_heap_进行初始化
     *
     * ----------------------------
     */
    MinPriorityQueue(TElement elements[], int size): min_heap_(elements, size) { }

    /*!
     * @brief **入队**
     * @param element 元素
     * @return 执行结果
     * @note
     * 入队
     * ---
     * ---
     *
     * ---
     * min_heap_插入element
     */
    bool Enqueue(const TElement& element) { return min_heap_.Insert(element); }

    /*!
     * @brief **出队**
     * @param item 元素保存变量
     * @return 执行结果
     * @note
     * 出队
     * ---
     * ---
     *
     * ---
     * 执行min_heap_.Pop
     */
    bool Dequeue(TElement& item) { return min_heap_.Pop(item); }

    /*!
     * @brief **获取队头**
     * @param item 元素保存变量
     * @return 执行结果
     * @note
     * 获取队头
     * -------
     * -------
     *
     * -------
     * min_heap_调用Top
     */
    bool Front(TElement& item) { return min_heap_.Top(item); }

    /*!
     * @brief **获取队列长度**
     * @return 队列长度
     * @note
     * 获取队列长度
     * ----------
     * ----------
     *
     * ----------
     * 返回min_heap_.Size()
     */
    int Size() { return min_heap_.Size(); }

    /*!
     * @brief **清空队列**
     * @note
     * 清空队列
     * -------
     * -------
     *
     * -------
     * 调用min_heap_.Clear()
     */
    void Clear() { min_heap_.Clear(); }

private:
    MinHeap<TElement> min_heap_;    //!< 小顶堆
};


#endif // CYBER_DASH_MIN_PRIORITY_QUEUE_H
