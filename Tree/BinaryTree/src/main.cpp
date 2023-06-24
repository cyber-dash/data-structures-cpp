/*!
 * @file main.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 二叉树demo演示
 * @version 0.2.1
 * @date 2020-11-01
 */

#include "test.h"


using namespace std;


/*!
 * @brief **main函数**
 * @return 0
 * @note
 * main函数
 * -------
 * -------
 *
 * -------
 * 测试-二叉树-复制构造函数\n
 * 测试-二叉树-高度\n
 * 测试-二叉树-获取父节点\n
 * 测试-二叉树-前序遍历\n
 * 测试-二叉树-中序遍历\n
 * 测试-二叉树-后序遍历\n
 * 测试-二叉树-层序遍历\n
 * 测试-二叉树-是否存在结点\n
 * 测试-二叉树-前序遍历与中序遍历生成二叉树\n
 *
 *
 * -------
 */
int main() {

    // 测试-二叉树-复制构造函数
	BinaryTreeTest::TestCopyConstructor();

    // 测试-二叉树-高度
	BinaryTreeTest::TestHeight();

    // 测试-二叉树-获取父节点
	BinaryTreeTest::TestParent();

    // 测试-二叉树-前序遍历
    BinaryTreeTest::TestPreorderTraversal();

    // 测试-二叉树-中序遍历
    BinaryTreeTest::TestInorderTraversal();

    // 测试-二叉树-后序遍历
    BinaryTreeTest::TestPostorderTraversal();

    // 测试-二叉树-层序遍历
    BinaryTreeTest::TestLevelOrderTraversal();

    // 测试-二叉树-是否存在结点
    BinaryTreeTest::TestExist();

    // 测试-二叉树-前序遍历与中序遍历生成二叉树
    BinaryTreeTest::TestCreateByPreorderAndInorderList();

	return 0;
}
