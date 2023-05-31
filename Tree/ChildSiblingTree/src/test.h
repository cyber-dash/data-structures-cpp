/*!
 * @file test.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 子女兄弟树测试.h文件
 * @version 0.2.1
 * @date 2020-11-01
 */

#ifndef CYBER_DASH_CHILD_SIBLING_TREE_TEST_H
#define CYBER_DASH_CHILD_SIBLING_TREE_TEST_H


#include <iostream>
#include "child_sibling_tree.h"


using namespace std;


// 测试-子女兄弟树-建树
void TestChildSiblingTreeCreateTreeByStr();

// 测试-子女兄弟树-高度
void TestChildSiblingTreeHeightRecursive();

// 测试-子女兄弟树-结点数量
void TestChildSiblingTreeNodeCount();

// 测试-子女兄弟树-前根遍历
void TestChildSiblingTreePreorder();

// 测试-子女兄弟树-后根遍历
void TestChildSiblingTreePostOrder();

// 测试-子女兄弟树-层序遍历
void TestChildSiblingTreeLevelOrder();


#endif // CYBER_DASH_CHILD_SIBLING_TREE_TEST_H
