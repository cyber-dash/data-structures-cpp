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

    TestLength();   // 测试-链式队列-长度

	TestEnQueue();

	TestDeQueue();

	TestGetFrontAndGetRear();

	TestIsEmpty();

    TestPrint();

	return 0;
}
