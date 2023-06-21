/*!
 * @file main.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 字符串匹配Demo演示
 * @version 0.2.1
 * @date 2021-08-23
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
 * 测试-字符串-基本函数\n
 * 测试-字符串-BF算法\n
 * 测试-字符串-KMP算法\n
 * 测试-字符串-KMP算法(CyberDash版)\n
 *
 *
 * -------
 */
int main() {

    /// 测试-字符串-基本函数
    TestStringBaseFunctions();

    /// 测试-字符串-BF算法
    TestBruteForceMatch();

    /// 测试-字符串-KMP算法
    TestKmpMatch();

    /// 测试-字符串-KMP算法(CyberDash版)
    TestKmpMatchCyberDash();

    return 0;
}