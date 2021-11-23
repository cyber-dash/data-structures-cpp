/*!
 * @file test.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 子女兄弟树测试.h文件
 * @version 0.2.1
 * @date 2020-11-01
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#ifndef CYBER_DASH_CHILD_SIBLING_TREE_TEST_H
#define CYBER_DASH_CHILD_SIBLING_TREE_TEST_H


#include <iostream>
#include "child_sibling_tree.h"


using namespace std;

void visit(ChildSiblingNode<int>* node);

void TestChildSiblingTreeCreateTreeByStr();

void TestChildSiblingTreeDepth();

void TestChildSiblingTreeNodeCount();

void TestChildSiblingTreePreOrder();

void TestChildSiblingTreePostOrder();

void TestChildSiblingTreeLevelOrder();


#endif // CYBER_DASH_CHILD_SIBLING_TREE_TEST_H
