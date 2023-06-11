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
 */
int main() {

    /*
    TestLength();

	TestEnQueue();

	TestDeQueue();

	TestGetFrontAndGetRear();

	TestIsEmpty();

    TestPrint();
     */

    /*
    Test_CircularQueue_Length();

    Test_CircularQueue_EnQueue();

    Test_CircularQueue_DeQueue();

    Test_CircularQueue_GetFrontAndGetRear();

    Test_CircularQueue_IsEmpty();

    Test_CircularQueue_Print();
     */

    Test_DoubleEndedQueue_Length();

    Test_DoubleEndedQueue_EnQueue();

    Test_DoubleEndedQueue_DeQueue();

    Test_DoubleEndedQueue_GetFrontAndGetRear();

    Test_DoubleEndedQueue_IsEmpty();

    Test_DoubleEndedQueue_Print();

    Test_DoubleEndedQueue_PushAndPop();

    return 0;
}
