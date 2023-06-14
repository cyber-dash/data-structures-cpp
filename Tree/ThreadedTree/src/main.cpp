/*!
 * @file main.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 线索树演示
 * @version 0.2.1
 * @date 2021-05-13
 */

#include "test.h"


using namespace std;


/*!
 * @brief **main函数**
 * @return 0
 * @note
 * main函数
 * --------
 * --------
 *
 * --------
 * 测试-中序线索树-获取子树首个线索节点\n
 * 测试-中序线索树-获取子树最后一个线索节点\n
 * 测试-中序线索树-下一个线索节点\n
 * 测试-中序线索树-前一个线索节点\n
 * 测试-中序线索树-父节点\n
 * 测试-中序线索树-中序遍历\n
 * 测试-中序线索树-前序遍历\n
 * 测试-中序线索树-后序遍历\n
 *
 *
 * --------
 */
int main() {

    // 测试-中序线索树-获取子树首个线索节点
    TestInorderThreadedTreeFirst();

    // 测试-中序线索树-获取子树最后一个线索节点
    TestInorderThreadedTreeLast();

    // 测试-中序线索树-下一个线索节点
    TestInorderThreadedTreeNext();

    // 测试-中序线索树-前一个线索节点
    TestInorderThreadedTreePre();

    // 测试-中序线索树-父节点
    TestInorderThreadedTreeParent();

    // 测试-中序线索树-中序遍历
    TestInorderThreadedTreeInorderTraverse();

    // 测试-中序线索树-前序遍历
    TestInorderThreadedTreePreorderTraverse();

    // 测试-中序线索树-后序遍历
    TestInorderThreadedTreePostorderTraverse();

    return 0;
}