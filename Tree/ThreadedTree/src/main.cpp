/*!
 * @file main.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 线索树演示
 * @version 0.2.1
 * @date 2021-05-13
 */

#include "test.h"


using namespace std;


int main() {

    // 测试First
    TestFirst();

    // 测试Last
    TestLast();

    // 测试Next(中序)
    TestNext();

    // 测试Prior(中序)
    TestPrior();

    // 测试Parent(中序)
    TestParent();

    // 测试中序线索树中序遍历
    TestInOrderTraverseOfInOrderThread();

    // 测试中序线索树前序遍历
    TestPreOrderTraverseOfInOrderThread();

    // 测试中序线索树后序遍历
    TestPostOrderTraverseOfInOrderThread();

    return 0;
}