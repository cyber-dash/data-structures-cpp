/*!
 * @file test.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 队列测试头文件
 * @version 0.2.1
 * @date 2021-10-9
 */

#ifndef CYBER_DASH_QUEUE_TEST_H
#define CYBER_DASH_QUEUE_TEST_H


// 测试-链式队列-入队
void Test_LinkedQueue_Length();

// 测试-链式队列-入队
void Test_LinkedQueue_EnQueue();

// 测试-链式队列-出队
void Test_LinkedQueue_DeQueue();

// 测试-链式队列-获取队头/获取队尾
void Test_LinkedQueue_GetFrontAndGetRear();

// 测试-链式队列-清空
void Test_LinkedQueue_IsEmpty();

// 测试-链式队列-operator<<
void Test_LinkedQueue_Print();

// 测试-循环队列-长度
void Test_CircularQueue_Length();

// 测试-循环队列-入队
void Test_CircularQueue_EnQueue();

// 测试-循环队列-出队
void Test_CircularQueue_DeQueue();

// 测试-循环队列-获取队头/获取队尾
void Test_CircularQueue_GetFrontAndGetRear();

// 测试-循环队列-清空
void Test_CircularQueue_Clear();

// 测试-循环队列-operator<<
void Test_CircularQueue_Print();

// 测试-双端队列-长度
void Test_DoubleEndedQueue_Length();

// 测试-双端队列-入队
void Test_DoubleEndedQueue_EnQueue();

// 测试-双端队列-出队
void Test_DoubleEndedQueue_DeQueue();

// 测试-双端队列-获取队头/获取队尾
void Test_DoubleEndedQueue_GetFrontAndGetRear();

// 测试-双端队列-清空
void Test_DoubleEndedQueue_IsEmpty();

// 测试-双端队列-operator<<
void Test_DoubleEndedQueue_Print();

// 测试-双端队列-双向Push/双向Pop
void Test_DoubleEndedQueue_PushAndPop();


#endif // CYBER_DASH_QUEUE_TEST_H
