/*!
 * @file test.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 队列测试头文件
 * @version 0.2.1
 * @date 2021-10-9
 */

#ifndef CYBER_DASH_QUEUE_TEST_H
#define CYBER_DASH_QUEUE_TEST_H


 /*! @brief 测试获取队列长度 */
void Test_LinkedQueue_Length();

/*! @brief 测试入队 */
void Test_LinkedQueue_EnQueue();

/*! @brief 测试出队 */
void Test_LinkedQueue_DeQueue();

/*! @brief 测试获取队列头/尾节点 */
void Test_LinkedQueue_GetFrontAndGetRear();

/*! @brief 测试队列是否为空 */
void Test_LinkedQueue_IsEmpty();

/*! @brief 测试重载<< */
void Test_LinkedQueue_Print();


void Test_CircularQueue_Length();

void Test_CircularQueue_EnQueue();

void Test_CircularQueue_DeQueue();

void Test_CircularQueue_GetFrontAndGetRear();

void Test_CircularQueue_IsEmpty();

void Test_CircularQueue_Print();


void Test_DoubleEndedQueue_Length();

void Test_DoubleEndedQueue_EnQueue();

void Test_DoubleEndedQueue_DeQueue();

void Test_DoubleEndedQueue_GetFrontAndGetRear();

void Test_DoubleEndedQueue_IsEmpty();

void Test_DoubleEndedQueue_Print();

// 测试-循环队列-队尾出队和队头入队
void Test_DoubleEndedQueue_PushAndPop();


#endif // CYBER_DASH_QUEUE_TEST_H
