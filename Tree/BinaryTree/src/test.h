/*!
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
 * @brief **二叉树测试类**
 */
class BinaryTreeTest {
public:
    // 测试-二叉树-复制构造函数
    static void TestCopyConstructor();

    // 测试-二叉树-高度
    static void TestHeight();

    // 测试-二叉树-获取父节点
    static void TestParent();

    // 测试-二叉树-前序遍历
    static void TestPreorderTraversal();

    // 测试-二叉树-中序遍历
    static void TestInorderTraversal();

    // 测试-二叉树-后序遍历
    static void TestPostorderTraversal();

    // 测试-二叉树-层序遍历
    static void TestLevelOrderTraversal();

    // 测试-二叉树-是否存在结点
    static void TestExist();

    // 测试使用前序遍历和后序遍历结果创建二叉树
    static void TestCreateByPreorderAndInorderList();

    // 测试是否为空
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
 * @brief **测试-二叉树-复制构造函数**
 * @note
 * 测试-二叉树-复制构造函数
 * ---------------------
 * ---------------------
 *
 * ---------------------
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
 * @brief **测试-二叉树-高度**
 * @note
 * 测试-二叉树-高度
 * ------------------
 * ------------------
 *
 * ------------------
 * + **1 构造二叉树**\n
 * **for loop** 循环7次 :\n
 * &emsp; 插入i \n\n
 * + **2 获取高度**\n
 * 调用Height(), 获取高度\n\n
 * + **3 打印高度**\n
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

    // ---------- 1 构造二叉树 ----------

    int num = 7;
    BinaryTree<int> binary_tree;

    for (int i = 0; i < num; i++) {                 // for loop 循环7次
        binary_tree.InsertRecursive(i);             // 插入i
    }

    // ---------- 2 获取高度 ----------

    int height = binary_tree.Height();              // 调用Height(), 获取高度

    // ---------- 3 打印高度 ----------

    cout << "二叉树高度: " << height << endl;        // 打印高度

    cout << "------------------------- CyberDash -------------------------" << endl << endl;
}


/*!
 * @brief **测试-二叉树-获取父节点**
 * @note
 * 测试-二叉树-获取父节点
 * -------------------
 * -------------------
 *
 * -------------------
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

    // ---------- 1 构造二叉树 ----------

    int num = 7;
    BinaryTree<int> binary_tree;

    for (int i = 0; i < num; i++) {                                 // for loop 循环7次
        binary_tree.InsertRecursive(i);                             // 插入i
    }

    // ---------- 2 初始化测试结点 ----------

    BinaryTreeNode<int>* root = binary_tree.Root();                 // root指向根结点
    BinaryTreeNode<int>* root_parent = binary_tree.Parent(root);    // root_parent指向根结点的父节点

    BinaryTreeNode<int>* node = root->left_child->left_child;       // node指向结点3
    BinaryTreeNode<int>* node_parent = binary_tree.Parent(node);    // node_parent指向结点3的父节点

    // ----------3 打印测试结点信息 ----------

    // 打印信息
    if (!root_parent) {
        cout << "根节点的父节点为NULL" << endl;
    } else {
        cout << "根节点的父节点: " << root_parent->data << endl;
    }

    cout << node->data << "的父节点： " << node_parent->data << endl;

    cout << "------------------------- CyberDash -------------------------" << endl << endl;
}


/*!
 * @brief **测试-二叉树-前序遍历**
 * @note
 * 测试-二叉树-前序遍历
 * -----------------
 * -----------------
 *
 * -----------------
 * + **1 构造二叉树**\n
 * **for loop** 循环7次 :\n
 * &emsp; 插入i \n\n
 * + **2 前序遍历测试**\n
 * 前序遍历测试\n
 * 前序遍历(递归)测试\n
 */
void BinaryTreeTest::TestPreorderTraversal() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|              Test BinaryTree PreorderTraversal            |" << endl;
    cout << "|                       测试二叉树前序遍历                     |" << endl;
    cout << "|                                                           |" << endl;
    cout << "|                             0                             |" << endl;
    cout << "|                            / \\                            |" << endl;
    cout << "|                           /   \\                           |" << endl;
    cout << "|                          1     2                          |" << endl;
    cout << "|                         / \\   /                           |" << endl;
    cout << "|                        3   5 4                            |" << endl;
    cout << "|                       /                                   |" << endl;
    cout << "|                      6                                    |" << endl << endl;

    // ---------- 1 构造二叉树 ----------

    int num = 7;
    BinaryTree<int> binary_tree;

    for (int i = 0; i < num; i++) {                         // for loop 循环7次
        binary_tree.InsertRecursive(i);                     // 插入i
    }

    // ---------- 2 前序遍历测试 ----------

    cout << "前序遍历:" << endl;
    binary_tree.PreorderTraversal(VisitAndCout);            // 前序遍历测试
    cout << endl;

    cout << "前序遍历(递归):" << endl;
    binary_tree.PreorderTraversalRecursive(VisitAndCout);   // 前序遍历(递归)测试

    cout << endl << "------------------------- CyberDash -------------------------" << endl << endl;
}


/*!
 * @brief **测试-二叉树-中序遍历**
 * @note
 * 测试-二叉树-中序遍历
 * -----------------
 * -----------------
 *
 * -----------------
 * + **1 构造二叉树**\n
 * **for loop** 循环7次 :\n
 * &emsp; 插入i \n\n
 * + **2 中序遍历测试**\n
 * 中序遍历测试\n
 * 中序遍历(递归)测试\n
 */
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

    // ---------- 1 构造二叉树 ----------

    int num = 7;
    BinaryTree<int> binary_tree;

    for (int i = 0; i < num; i++) {                         // for loop 循环7次
        binary_tree.InsertRecursive(i);                     // 插入i
    }

    // ---------- 2 中序遍历测试 ----------
    cout << "中序遍历:" << endl;
    binary_tree.InorderTraversal(VisitAndCout);             // 中序遍历测试
    cout << endl;

    cout << "中序遍历(递归):" << endl;
    binary_tree.InorderTraversalRecursive(VisitAndCout);    // 中序遍历(递归)测试

    cout << endl << "------------------------- CyberDash -------------------------" << endl << endl;
}


/*!
 * @brief **测试-二叉树-后序遍历**
 * @note
 * 测试-二叉树-后序遍历
 * -----------------
 * -----------------
 *
 * -----------------
 * + **1 构造二叉树**\n
 * **for loop** 循环7次 :\n
 * &emsp; 插入i \n\n
 * + **2 后序遍历测试**\n
 * 后序遍历测试\n
 * 后序遍历(递归)测试\n
 */
void BinaryTreeTest::TestPostorderTraversal() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|              Test BinaryTree PostorderTraversal           |" << endl;
    cout << "|                      测试二叉树后序遍历                      |" << endl;
    cout << "|                                                           |" << endl;
    cout << "|                             0                             |" << endl;
    cout << "|                            / \\                            |" << endl;
    cout << "|                           /   \\                           |" << endl;
    cout << "|                          1     2                          |" << endl;
    cout << "|                         / \\   /                           |" << endl;
    cout << "|                        3   5 4                            |" << endl;
    cout << "|                       /                                   |" << endl;
    cout << "|                      6                                    |" << endl << endl;

    // ---------- 1 构造二叉树 ----------

    int num = 7;
    BinaryTree<int> binary_tree;

    for (int i = 0; i < num; i++) {                         // for loop 循环7次
        binary_tree.InsertRecursive(i);                     // 插入i
    }

    // ---------- 2 后序遍历测试 ----------

    cout << "后序遍历:" << endl;
    binary_tree.PostorderTraversal(VisitAndCout);           // 后序遍历测试
    cout << endl;

    cout << "后序遍历(递归):" << endl;
    binary_tree.PostorderTraversalRecursive(VisitAndCout);  // 后序遍历(递归)测试

    cout << endl << "------------------------- CyberDash -------------------------" << endl << endl;
}


/*!
 * @brief **测试-二叉树-层序遍历**
 * @note
 * 测试-二叉树-层序遍历
 * -----------------
 * -----------------
 *
 * -----------------
 * + **1 构造二叉树**\n
 * **for loop** 循环7次 :\n
 * &emsp; 插入i \n\n
 * + **2 层遍历测试**\n
 * 层序遍历测试\n
 */
void BinaryTreeTest::TestLevelOrderTraversal() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|              Test BinaryTree LevelOrderTraversal          |" << endl;
    cout << "|                      测试二叉树层序遍历                      |" << endl;
    cout << "|                                                           |" << endl;
    cout << "|                             0                             |" << endl;
    cout << "|                            / \\                            |" << endl;
    cout << "|                           /   \\                           |" << endl;
    cout << "|                          1     2                          |" << endl;
    cout << "|                         / \\   /                           |" << endl;
    cout << "|                        3   5 4                            |" << endl;
    cout << "|                       /                                   |" << endl;
    cout << "|                      6                                    |" << endl << endl;

    // ---------- 1 构造二叉树 ----------

    int num = 7;
    BinaryTree<int> binary_tree;

    for (int i = 0; i < num; i++) {                 // for loop 循环7次
        binary_tree.InsertRecursive(i);             // 插入i
    }

    // ---------- 2 层遍历测试 ----------

    binary_tree.LevelOrderTraversal(VisitAndCout);  // 层序遍历测试

    cout << endl << "------------------------- CyberDash -------------------------" << endl << endl;
}


/*!
 * @brief **测试-二叉树-是否存在结点**
 * @note
 * 测试-二叉树-是否存在结点
 * ---------------------
 * ---------------------
 *
 * ---------------------
 * + **1 构造二叉树**\n
 * **for loop** 循环7次 :\n
 * &emsp; 插入i \n\n
 * + **2 是否存在结点测试**\n
 * 测试5是否存在于树中\n
 * 测试7是否存在于树中\n
 */
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

    // ---------- 1 构造二叉树 ----------

    int num = 7;
    BinaryTree<int> binary_tree;

    for (int i = 0; i < num; i++) {                 // for loop 循环7次
        binary_tree.InsertRecursive(i);             // 插入i
    }

    // ---------- 2 是否存在结点测试 ----------

    bool in_tree = binary_tree.Exist(5);            // 测试5是否存在于树中

    if (in_tree) {
        cout << "5 is in the tree" << endl;
    }
    else {
        cout << "5 isn't in the tree" << endl;
    }

    in_tree = binary_tree.Exist(7);                 // 测试7是否存在于树中

    if (in_tree) {
        cout << "7 is in the tree" << endl;
    } else {
        cout << "7 isn't in the tree" << endl;
    }

    cout << "------------------------- CyberDash -------------------------" << endl << endl;
}


/*!
 * @brief **测试-二叉树-前序遍历与中序遍历生成二叉树**
 * @note
 * 测试-二叉树-前序遍历与中序遍历生成二叉树
 * ----------------------------------
 * ----------------------------------
 *
 * ----------------------------------
 * + **1 初始化前序遍历和中序遍历序列**\n
 * 初始化前序遍历序列: { 0, 1, 3, 6, 5, 9, 2, 4, 8, 7 }\n
 * 初始化中序遍历序列: { 6, 3, 1, 9, 5, 0, 8, 4, 2, 7 }\n\n
 * + **2 建树**\n
 * 调用CreateByPreorderAndInorderList, 建树\n\n
 * + **3 打印树**\n
 * 打印二叉树\n
 */
void BinaryTreeTest::TestCreateByPreorderAndInorderList() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|     Test BinaryTree TestCreateByPreorderAndInorderList    |" << endl;
    cout << "|                测试前序遍历与中序遍历生成二叉树           |" << endl << endl << endl;

    // ---------- 1 初始化前序遍历和中序遍历序列 ----------

    BinaryTree<int> binary_tree;

    int list_length = 10;
    int preorder_list[] = { 0, 1, 3, 6, 5, 9, 2, 4, 8, 7 };                                             // 初始化前序遍历序列: { 0, 1, 3, 6, 5, 9, 2, 4, 8, 7 }
    int inorder_list[] = { 6, 3, 1, 9, 5, 0, 8, 4, 2, 7 };                                              // 初始化中序遍历序列: { 6, 3, 1, 9, 5, 0, 8, 4, 2, 7 }

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

    // ---------- 2 建树 ----------

    bool res = binary_tree.CreateByPreorderAndInorderList(preorder_list, inorder_list, list_length);    // 调用CreateByPreorderAndInorderList, 建树
    if (!res) {
        cout << "生成二叉树失败:" << endl;
    }

    // ---------- 3 打印树 ----------

    cout << "打印二叉树:" << endl;
    binary_tree.Print();                                                                                // 打印二叉树

    cout << endl << endl;
    cout << "------------------------- CyberDash -------------------------" << endl;
    cout << endl;
}


#endif // CYBER_DASH_BINARY_TREE_TEST_H
