﻿/*!
 * @file test.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 二叉树测试类
 * @version 0.2.1
 * @date 2020-05-04
 */

#ifndef CYBER_DASH_BINARY_TREE_TEST_H
#define CYBER_DASH_BINARY_TREE_TEST_H


#include "binary_tree.h"

 /*!
  * @brief 二叉树测试类
  */
class BinaryTreeTest {
public:
    /*! @brief 测试复制构造函数 */
    static void TestCopyConstructor();

    /*! @brief 测试二叉树深度 */
    static void TestHeight();

    /*! @brief 测试父节点函数Parent */
    static void TestParent();

    /*! @brief 测试前序遍历 */
    static void TestPreorderTraversal();

    /*! @brief 测试中序遍历 */
    static void TestInorderTraversal();

    /*! @brief 测试后序遍历 */
    static void TestPostorderTraversal();

    /*! @brief 测试层序遍历 */
    static void TestLevelOrderTraversal();

    /*! @brief 测试查找是否在二叉树 */
    static void TestExist();

    /*! @brief 测试使用前序遍历和后序遍历结果创建二叉树 */
    static void TestCreateByPreorderAndInorderList();

    /*! @brief 测试是否为空 */
    static void TestIsEmpty();
};


/*!
 * @brief 结点打印函数
 * @param node 二叉树结点
 */
void VisitAndCout(BinaryTreeNode<int>* node) {
    cout << node->data << " ";
};


/*!
 * @brief **测试二叉树复制构造函数**
 * @note
 * 测试二叉树复制构造函数
 * ------------------
 * ------------------
 *
 * ------------------
 * + **1 构造二叉树**\n
 * **for loop** 循环7次 :\n
 * &emsp; 插入i \n\n
 * + **2 调用复制构造函数**\n
 * 对binary_tree调用复制构造函数, 初始化binary_tree_2\n\n
 * + **3 打印binary_tree_2**\n
 * 打印\n
 */
void BinaryTreeTest::TestCopyConstructor() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|              Test BinaryTree CopyConstructor              |" << endl;
    cout << "|                     测试二叉树复制构造函数                   |" << endl;

    // ---------- 1 构造二叉树 ----------

    int num = 7;
    BinaryTree<int> binary_tree;

    for (int i = 0; i < num; i++) {                 // for loop 循环7次
        binary_tree.InsertRecursive(i);             // 插入i
    }

    // ---------- 2 调用复制构造函数 ----------

    BinaryTree<int> binary_tree_2(binary_tree);     // 对binary_tree调用复制构造函数, 初始化binary_tree_2

    // ---------- 3 打印binary_tree_2 ----------

    cout << binary_tree_2;                          // 打印

    cout << endl << "------------------------- CyberDash -------------------------" << endl;
}


/*!
 * @brief **测试二叉树高度**
 * @note
 * 测试二叉树高度
 * ------------------
 * ------------------
 *
 * ------------------
 * + **1 构造二叉树**\n
 * **for loop** 循环7次 :\n
 * &emsp; 插入i \n\n
 * + **2 获取高度**\n
 * 调用Height(), 获取高度\n\n
 * + **3 打印binary_tree_2**\n
 * 打印高度\n
 */
void BinaryTreeTest::TestHeight() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                   Test BinaryTree Height                  |" << endl;
    cout << "|                        测试二叉树高度                       |" << endl;
    cout << "|                                                           |" << endl;
    cout << "|                             0                             |" << endl;
    cout << "|                            / \\                            |" << endl;
    cout << "|                           /   \\                           |" << endl;
    cout << "|                          1     2                          |" << endl;
    cout << "|                         / \\   /                           |" << endl;
    cout << "|                        3   5 4                            |" << endl;
    cout << "|                       /                                   |" << endl;
    cout << "|                      6                                    |" << endl << endl;

    int num = 7;
    BinaryTree<int> binary_tree;

    for (int i = 0; i < num; i++) {
        binary_tree.InsertRecursive(i);
    }

    int height = binary_tree.Height();

    cout << "二叉树高度: " << height << endl;

    cout << "------------------------- CyberDash -------------------------" << endl;
    cout << endl;
}


/*!
 * @brief **测试二叉树父节点**
 * @note
 * 测试二叉树父节点
 * -------------
 * -------------
 *
 * -------------
 * + **1 构造二叉树**\n
 * **for loop** 循环7次 :\n
 * &emsp; 插入i \n\n
 * + **2 初始化测试结点**\n
 * root指向根结点\n
 * root_parent指向根结点的父节点\n
 * node指向结点3\n
 * node_parent指向结点3的父节点\n\n
 * + **3 打印测试结点信息**\n
 * 打印信息\n
 */
void BinaryTreeTest::TestParent() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                  Test BinaryTree Parent                   |" << endl;
    cout << "|                       测试二叉树父节点                       |" << endl;
    cout << "|                                                           |" << endl;
    cout << "|                             0                             |" << endl;
    cout << "|                            / \\                            |" << endl;
    cout << "|                           /   \\                           |" << endl;
    cout << "|                          1     2                          |" << endl;
    cout << "|                         / \\   /                           |" << endl;
    cout << "|                        3   5 4                            |" << endl;
    cout << "|                       /                                   |" << endl;
    cout << "|                      6                                    |" << endl << endl;

    int num = 7;
    BinaryTree<int> binary_tree;

    for (int i = 0; i < num; i++) {
        binary_tree.InsertRecursive(i);
    }

    BinaryTreeNode<int>* root = binary_tree.Root();
    BinaryTreeNode<int>* root_parent = binary_tree.Parent(root);

    BinaryTreeNode<int>* node = root->left_child->left_child;
    BinaryTreeNode<int>* node_parent = binary_tree.Parent(node);

    if (root_parent == NULL) {
        cout << "根节点的父节点为NULL" << endl;
    } else {
        cout << "根节点的父节点: " << root_parent->data << endl;
    }

    cout << node->data << "的父节点： " << node_parent->data << endl;

    cout << "------------------------- CyberDash -------------------------" << endl;
    cout << endl;
}


void BinaryTreeTest::TestPreorderTraversal() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|              Test BinaryTree PreorderTraversalRecursive            |" << endl;
    cout << "|                      测试二叉树前序遍历                     |" << endl;
    cout << "|                                                           |" << endl;
    cout << "|                             0                             |" << endl;
    cout << "|                            / \\                            |" << endl;
    cout << "|                           /   \\                           |" << endl;
    cout << "|                          1     2                          |" << endl;
    cout << "|                         / \\   /                           |" << endl;
    cout << "|                        3   5 4                            |" << endl;
    cout << "|                       /                                   |" << endl;
    cout << "|                      6                                    |" << endl << endl;

    int num = 7;
    BinaryTree<int> binary_tree;

    for (int i = 0; i < num; i++) {
        binary_tree.InsertRecursive(i);
    }

    cout << "前序遍历(递归):" << endl;
    binary_tree.PreorderTraversalRecursive(VisitAndCout);
    cout << endl;

    cout << "前序遍历(非递归):" << endl;
    binary_tree.PreorderTraversal(VisitAndCout);
    cout << endl;

    cout << "------------------------- CyberDash -------------------------" << endl;
    cout << endl;
}


void BinaryTreeTest::TestInorderTraversal() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|               Test BinaryTree InorderTraversal            |" << endl;
    cout << "|                       测试二叉树中序遍历                     |" << endl;
    cout << "|                                                           |" << endl;
    cout << "|                             0                             |" << endl;
    cout << "|                            / \\                            |" << endl;
    cout << "|                           /   \\                           |" << endl;
    cout << "|                          1     2                          |" << endl;
    cout << "|                         / \\   /                           |" << endl;
    cout << "|                        3   5 4                            |" << endl;
    cout << "|                       /                                   |" << endl;
    cout << "|                      6                                    |" << endl << endl;

    int num = 7;
    BinaryTree<int> binary_tree;

    for (int i = 0; i < num; i++) {
        binary_tree.InsertRecursive(i);
    }

    cout << "中序遍历(递归):" << endl;
    binary_tree.InorderTraversal(VisitAndCout);
    cout << endl;

    cout << "中序遍历(非递归):" << endl;
    binary_tree.InorderTraversal(VisitAndCout);
    cout << endl;

    cout << "------------------------- CyberDash -------------------------" << endl;
    cout << endl;
}


void BinaryTreeTest::TestPostorderTraversal() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|              Test BinaryTree PostorderTraversalRecursive           |" << endl;
    cout << "|                      测试二叉树后序遍历                     |" << endl;
    cout << "|                                                           |" << endl;
    cout << "|                             0                             |" << endl;
    cout << "|                            / \\                            |" << endl;
    cout << "|                           /   \\                           |" << endl;
    cout << "|                          1     2                          |" << endl;
    cout << "|                         / \\   /                           |" << endl;
    cout << "|                        3   5 4                            |" << endl;
    cout << "|                       /                                   |" << endl;
    cout << "|                      6                                    |" << endl << endl;

    int num = 7;
    BinaryTree<int> binary_tree;

    for (int i = 0; i < num; i++) {
        binary_tree.InsertRecursive(i);
    }

    cout << "后序遍历(递归):" << endl;
    binary_tree.PostorderTraversalRecursive(VisitAndCout);
    cout << endl;

    cout << "后序遍历(非递归):" << endl;
    binary_tree.PostorderTraversal(VisitAndCout);
    cout << endl;

    cout << "------------------------- CyberDash -------------------------" << endl;
    cout << endl;
}


// 测试层序遍历
void BinaryTreeTest::TestLevelOrderTraversal() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|              Test BinaryTree LevelOrderTraversal          |" << endl;
    cout << "|                      测试二叉树层序遍历                     |" << endl;
    cout << "|                                                           |" << endl;
    cout << "|                             0                             |" << endl;
    cout << "|                            / \\                            |" << endl;
    cout << "|                           /   \\                           |" << endl;
    cout << "|                          1     2                          |" << endl;
    cout << "|                         / \\   /                           |" << endl;
    cout << "|                        3   5 4                            |" << endl;
    cout << "|                       /                                   |" << endl;
    cout << "|                      6                                    |" << endl << endl;

    int num = 7;
    BinaryTree<int> binary_tree;

    for (int i = 0; i < num; i++) {
        binary_tree.InsertRecursive(i);
    }

    binary_tree.LevelOrderTraversal(VisitAndCout);

    cout << endl;
    cout << "------------------------- CyberDash -------------------------" << endl;
    cout << endl;
}


void BinaryTreeTest::TestExist() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                    Test BinaryTree Exist                  |" << endl;
    cout << "|                     测试二叉树结点是否存在                   |" << endl;
    cout << "|                                                           |" << endl;
    cout << "|                             0                             |" << endl;
    cout << "|                            / \\                            |" << endl;
    cout << "|                           /   \\                           |" << endl;
    cout << "|                          1     2                          |" << endl;
    cout << "|                         / \\   /                           |" << endl;
    cout << "|                        3   5 4                            |" << endl;
    cout << "|                       /                                   |" << endl;
    cout << "|                      6                                    |" << endl << endl;

    int num = 7;
    BinaryTree<int> binary_tree;

    for (int i = 0; i < num; i++) {
        binary_tree.InsertRecursive(i);
    }

    bool in_tree = binary_tree.Exist(5);

    if (in_tree) {
        cout << "5 is in the tree" << endl;
    }
    else {
        cout << "5 isn't in the tree" << endl;
    }

    in_tree = binary_tree.Exist(7);

    if (in_tree) {
        cout << "7 is in the tree" << endl;
    }
    else {
        cout << "7 isn't in the tree" << endl;
    }

    cout << "------------------------- CyberDash -------------------------" << endl;
    cout << endl;
}


void BinaryTreeTest::TestCreateByPreorderAndInorderList() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|     Test BinaryTree TestCreateByPreorderAndInorderList    |" << endl;
    cout << "|                 测试前序遍历与中序遍历生成二叉树              |" << endl << endl << endl;

    BinaryTree<int> binary_tree;

    int list_length = 10;
    int preorder_list[] = { 0, 1, 3, 6, 5, 9, 2, 4, 8, 7 };  // 前序遍历结果
    int inorder_list[] = { 6, 3, 1, 9, 5, 0, 8, 4, 2, 7 };   // 中序遍历结果

    cout << "前序遍历序列: ";
    for (int i = 0; i < list_length; i++) {
        cout << preorder_list[i] << " ";
    }
    cout << endl << endl;

    cout << "中序遍历序列: ";
    for (int i = 0; i < list_length; i++) {
        cout << inorder_list[i] << " ";
    }
    cout << endl << endl;

    bool res = binary_tree.CreateByPreorderAndInorderList(preorder_list, inorder_list, list_length);
    if (!res) {
        cout << "生成二叉树失败:" << endl;
    }

    cout << "打印二叉树:" << endl;
    binary_tree.Print();

    cout << endl << endl;
    cout << "------------------------- CyberDash -------------------------" << endl;
    cout << endl;
}


#endif // CYBER_DASH_BINARY_TREE_TEST_H
