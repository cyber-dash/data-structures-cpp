/*!
 * @file test.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 线索树测试h文件
 * @version 0.2.1
 * @date 2021-05-13
 */

#ifndef CYBER_DASH_THREAD_TREE_TEST_H
#define CYBER_DASH_THREAD_TREE_TEST_H


#include "threaded_node.h"


void visit(ThreadedNode<int> *node);

// 测试-中序线索树-获取子树首个线索节点
void TestInorderThreadedTreeFirst();

// 测试-中序线索树-获取子树最后一个线索节点
void TestInorderThreadedTreeLast();

// 测试-中序线索树-下一个线索节点
void TestInorderThreadedTreeNext();

// 测试-中序线索树-前一个线索节点
void TestInorderThreadedTreePre();

// 测试-中序线索树-父节点
void TestInorderThreadedTreeParent();

// 测试-中序线索树-中序遍历
void TestInorderThreadedTreeInorderTraverse();

// 测试-中序线索树-前序遍历
void TestInorderThreadedTreePreorderTraverse();

// 测试-中序线索树-后序遍历
void TestInorderThreadedTreePostorderTraverse();


#endif //CYBER_DASH_THREAD_TREE_TEST_H
