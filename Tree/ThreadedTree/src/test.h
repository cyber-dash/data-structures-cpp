﻿/*!
 * @file test.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 线索树测试h文件
 * @version 0.2.1
 * @date 2021-05-13
 */

#ifndef CYBER_DASH_THREAD_TREE_TEST_H
#define CYBER_DASH_THREAD_TREE_TEST_H


#include "threaded_node.h"


void visit(ThreadedNode<int> *p);

void TestInorderThreadedTreeFirst();

void TestInorderThreadedTreeLast();

void TestInorderThreadedTreeNext();

void TestInorderThreadedTreePre();

void TestInorderThreadedTreeParent();

void TestInorderThreadedTreeInorderTraverse();

void TestInorderThreadedTreePreorderTraverse();

void TestInorderThreadedTreePostorderTraverse();


#endif //CYBER_DASH_THREAD_TREE_TEST_H