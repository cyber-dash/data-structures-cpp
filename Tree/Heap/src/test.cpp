/*!
 * @file test.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 测试.cpp文件
 * @version 0.2.1
 * @date 2021-07-14
 */

#include "test.h"
#include "min_heap.h"


/*!
 * @brief **测试-堆**
 * @note
 * 测试-堆
 * ------
 * ------
 *
 * ------
 * 声明数组arr\n
 * 初始化heap\n
 * heap插入99, 0, 100三个数\n
 * 检查是否满/是否空\n
 * 依次pop堆顶并打印堆顶\n
 *
 *
 * ------
 */
void TestHeap() {

    // 声明数组arr
    int arr[] = { 3,2,6,7,8,4,5,34 };

    // 初始化heap
    MinHeap<int> heap(arr, 8, 200);

    // heap插入99, 0, 100三个数
    heap.Insert(99);
    heap.Insert(0);
    heap.Insert(100);

    // 检查是否满/是否空
    cout << "is full:" << heap.IsFull() << endl;
    cout << "is empty:" << heap.IsEmpty() << endl;

    // 依次pop堆顶并打印堆顶
    while (!heap.IsEmpty()) {
        int item;
        heap.Pop(item);
        cout << item << " ";
    }
}
