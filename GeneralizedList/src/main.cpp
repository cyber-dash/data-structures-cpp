/*!
 * @file main.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 广义表Demo演示
 * @version 0.2.1
 * @date 2021-05-19
 */

#include "test.h"


using namespace std;


/*!
 * @brief main函数
 * @return 0
 * @note
 * main函数
 * -------
 * -------
 *
 * -------
 * 测试-简单广义表-深度\n
 * 测试-简单广义表-长度\n
 *
 *
 * -------
 */
int main() {

    // TestDepth();         这两个函数也可以执行
    // TestLength();

    // 测试-简单广义表-深度
    TestSimpleGenListDepth();


    // 测试-简单广义表-长度
    TestSimpleGenListLength();

    return 0;
}