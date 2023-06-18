/*!
 * @file main.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 队列main文件
 * @version 0.2.1
 * @date 2021-07-14
 */

#include "test.h"


/*!
 * @brief **main函数**
 * @return 0
 * @note
 * main函数
 * -------
 * -------
 *
 * -------
 * 测试-链式队列-长度\n
 * 测试-链式队列-入队\n
 * 测试-链式队列-出队\n
 * 测试-链式队列-获取队头/获取队尾\n
 * 测试-链式队列-清空\n
 * 测试-链式队列-operator<<\n\n
 * 测试-循环队列-长度\n
 * 测试-循环队列-入队\n
 * 测试-循环队列-出队\n
 * 测试-循环队列-获取队头/获取队尾\n
 * 测试-循环队列-清空\n
 * 测试-循环队列-operator<<\n\n
 * 测试-双端队列-长度\n
 * 测试-双端队列-入队\n
 * 测试-双端队列-出队\n
 * 测试-双端队列-获取队头/获取队尾\n
 * 测试-双端队列-清空\n
 * 测试-双端队列-operator<<\n
 * 测试-双端队列-双向Push/双向Pop\n
 *
 *
 * -------
 */
int main() {

    // 测试-链式队列-长度
    Test_LinkedQueue_Length();

    // 测试-链式队列-入队
    Test_LinkedQueue_EnQueue();

    // 测试-链式队列-出队
    Test_LinkedQueue_DeQueue();

    // 测试-链式队列-获取队头/获取队尾
    Test_LinkedQueue_GetFrontAndGetRear();

    // 测试-链式队列-清空
    Test_LinkedQueue_IsEmpty();

    // 测试-链式队列-operator<<
    Test_LinkedQueue_Print();

    // 测试-循环队列-长度
    Test_CircularQueue_Length();

    // 测试-循环队列-入队
    Test_CircularQueue_EnQueue();

    // 测试-循环队列-出队
    Test_CircularQueue_DeQueue();

    // 测试-循环队列-获取队头/获取队尾
    Test_CircularQueue_GetFrontAndGetRear();

    // 测试-循环队列-清空
    Test_CircularQueue_Clear();

    // 测试-循环队列-operator<<
    Test_CircularQueue_Print();

    // 测试-双端队列-长度
    Test_DoubleEndedQueue_Length();

    // 测试-双端队列-入队
    Test_DoubleEndedQueue_EnQueue();

    // 测试-双端队列-出队
    Test_DoubleEndedQueue_DeQueue();

    // 测试-双端队列-获取队头/获取队尾
    Test_DoubleEndedQueue_GetFrontAndGetRear();

    // 测试-双端队列-清空
    Test_DoubleEndedQueue_IsEmpty();

    // 测试-双端队列-operator<<
    Test_DoubleEndedQueue_Print();

    // 测试-双端队列-双向Push/双向Pop
    Test_DoubleEndedQueue_PushAndPop();

    return 0;
}
