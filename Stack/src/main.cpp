/*!
 * @file main.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 主函数文件
 * @version 0.2.1
 * @date 2020-07-15
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
 * 测试-链式栈-入栈\n
 * 测试-链式栈-出栈\n
 * 测试-顺序栈-入栈\n\n
 * 测试-链式栈-取栈顶\n
 * 测试-顺序栈-出栈\n
 * 测试-顺序栈-取栈顶\n
 *
 *
 * -------
 */
int main() {

    TestLinkedStackPush();                      // 测试-链式栈-入栈
    TestLinkedStackPop();                       // 测试-链式栈-出栈
    TestSeqStackPush();                         // 测试-顺序栈-入栈

    TestLinkedStackTop();                       // 测试-链式栈-取栈顶
    TestSeqStackPop();                          // 测试-顺序栈-出栈
    TestSeqStackTop();                          // 测试-顺序栈-取栈顶

	return 0;
}
