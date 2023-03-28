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

    // 测试中序线索树First
    TestInorderThreadedTreeFirst();

    // 测试中序线索树Last
    TestInorderThreadedTreeLast();

    // 测试中序线索树Next
    TestInorderThreadedTreeNext();

    // 测试中序线索树Pre
    TestInorderThreadedTreePre();

    // 测试中序线索树Parent
    TestInorderThreadedTreeParent();

    // 测试中序线索树中序遍历
    TestInorderThreadedTreeInorderTraverse();

    // 测试中序线索树前序遍历
    TestInorderThreadedTreePreorderTraverse();

    // 测试中序线索树后序遍历
    TestInorderThreadedTreePostorderTraverse();

    return 0;
}