/*!
 * @file heap_sort.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 堆排序
 * @version 0.2.1
 * @date 2021-09-19
 */

#include "util.h"


/*!
 * 大顶堆SiftDown
 * @param heap_array 数组
 * @param index 执行SiftDown的数组索引
 * @param heap_size 堆size
 */
template<typename TElement>
void MaxHeapSiftDown(TElement* heap_array, int index, int heap_size) {
    for (int child_index = 2 * index + 1;
         child_index < heap_size;
         index = child_index, child_index = child_index * 2 + 1)
    {
        //! index的孩子结点中, 权重较大的结点索引, 赋给child_index
        if (child_index < heap_size && heap_array[child_index] < heap_array[child_index + 1]) {
            child_index++;
        }

    //! 如果父节点 >= 子节点, sift down结束
        if (heap_array[index] >= heap_array[child_index]) {
            break;
        }

    //! 交换父子结点
        Swap(heap_array + index, heap_array + child_index);
    }
}


/*!
 * 大顶堆SiftUp
 * @param heap_array 数组
 * @param index 执行SiftUp的数组索引
 */
template<typename TElement>
void MaxHeapSiftUp(TElement* heap_array, int index) {
    for (int parent_index = (index - 1) / 2;
         parent_index >= 0;
         index = parent_index, parent_index = (index - 1) / 2)
    {
        if (heap_array[parent_index] >= heap_array[index]) {
            break;
        }

        Swap(heap_array + parent_index, heap_array + index);
    }
}


/*!
 * 构造堆(使用SiftDown)
 * @param heap_array 数组
 * @param heap_size 数组长度
 */
template<typename TElement>
void BuildHeapBySiftDown(TElement* heap_array, int heap_size) {
    int pivot = (heap_size - 2) / 2;
    for (int i = pivot; i >= 0; i--) {
        MaxHeapSiftDown(heap_array, i, heap_size);
    }
}


/*!
 * 构造堆(使用SiftUp)
 * @param heap_array 数组
 * @param heap_size 数组长度
 */
template<typename TElement>
void BuildHeapBySiftUp(TElement* heap_array, int heap_size) {
    int pivot = (heap_size - 2) / 2;
    for (int i = heap_size - 1; i > pivot; i--) {
        MaxHeapSiftUp(heap_array, i);
    }
}


/*!
 * 堆排序
 * @param heap_array 数组
 * @param length 数组长度
 */
template<typename TElement>
void HeapSort(TElement* heap_array, int length) {

    BuildHeapBySiftDown(heap_array, length);

    for (int i = length - 1; i > 0; i--) {
        Swap(heap_array, heap_array + i);
        MaxHeapSiftDown(heap_array, 0, i - 1);
    }
}
