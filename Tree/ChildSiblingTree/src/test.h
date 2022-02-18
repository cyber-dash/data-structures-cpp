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


// 节点遍历函数
// void visit(ChildSiblingNode<int>* node);

// 测试使用字符串创建子女孩子树
void TestChildSiblingTreeCreateTreeByStr();

// 测试深度
void TestChildSiblingTreeDepth();

// 测试节点数量
void TestChildSiblingTreeNodeCount();

// 测试先根遍历
void TestChildSiblingTreePreOrder();

// 测试后根遍历
void TestChildSiblingTreePostOrder();

// 测试层序遍历
void TestChildSiblingTreeLevelOrder();


#endif // CYBER_DASH_CHILD_SIBLING_TREE_TEST_H
