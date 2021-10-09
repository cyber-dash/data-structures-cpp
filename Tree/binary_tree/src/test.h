/*!
 * @file test.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 二叉树测试类
 * @version 0.2.1
 * @date 2020-05-04
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
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

  /*! @brief 测试LeftChild和RightChild */
  static void TestChild();

  /*! @brief 测试父节点函数Parent */
  static void TestParent();

  /*! @brief 测试前序遍历 */
  static void TestPreOrder();

  /*! @brief 测试中序遍历 */
  static void TestInOrder();

  /*! @brief 测试后序遍历 */
  static void TestPostOrder();

  /*! @brief 测试层序遍历 */
  static void TestLevelOrder();

  /*! @brief 测试查找是否在二叉树 */
  static void TestFind();

  /*! @brief 测试使用前序遍历和后序遍历结果创建二叉树 */
  static void TestCreateBinTreeByPreAndInOrderString();

  /*! @brief 测试是否为空 */
  static void TestIsEmpty();
};


/*!
 * @brief 结点打印函数
 * @param node 二叉树结点
 */
void visit(BinTreeNode<int>* node) {
  cout << node->data << " ";
};


void BinaryTreeTest::TestCopyConstructor() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|              Test BinaryTree CopyConstructor              |"<<endl;
  cout<<"|                     测试二叉树复制构造函数                   |"<<endl;

  int num = 7;
  BinaryTree<int> bin_tree;

  for (int i = 0 ; i < num; i++) {
    bin_tree.Insert(i);
  }

  BinaryTree<int> bin_tree_2(bin_tree);

  bin_tree_2.Print();

  cout << endl << "------------------------- CyberDash -------------------------"<<endl;
}


void BinaryTreeTest::TestHeight() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                   Test BinaryTree Height                  |"<<endl;
  cout<<"|                        测试二叉树高度                       |"<<endl;
  cout<<"|                                                           |"<<endl;
  cout<<"|                             0                             |"<<endl;
  cout<<"|                            / \\                            |"<<endl;
  cout<<"|                           /   \\                           |"<<endl;
  cout<<"|                          1     2                          |"<<endl;
  cout<<"|                         / \\   /                           |"<<endl;
  cout<<"|                        3   5 4                            |"<<endl;
  cout<<"|                       /                                   |"<<endl;
  cout<<"|                      6                                    |"<<endl<<endl;

  int num = 7;
  BinaryTree<int> bin_tree;

  for (int i = 0 ; i < num; i++) {
    bin_tree.Insert(i);
  }

  int height = bin_tree.Height();

  cout<<"二叉树深度: "<<height<<endl;

  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<endl;
}


void BinaryTreeTest::TestIsEmpty() {

}


void BinaryTreeTest::TestChild() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|            Test BinaryTree LeftChild & RightChild         |"<<endl;
  cout<<"|                     测试二叉树左右孩子函数                   |"<<endl;
  cout<<"|                                                           |"<<endl;
  cout<<"|                             0                             |"<<endl;
  cout<<"|                            / \\                            |"<<endl;
  cout<<"|                           /   \\                           |"<<endl;
  cout<<"|                          1     2                          |"<<endl;
  cout<<"|                         / \\   /                           |"<<endl;
  cout<<"|                        3   5 4                            |"<<endl;
  cout<<"|                       /                                   |"<<endl;
  cout<<"|                      6                                    |"<<endl<<endl;

  int num = 7;
  BinaryTree<int> bin_tree;

  for (int i = 0 ; i < num; i++) {
    bin_tree.Insert(i);
  }

  BinTreeNode<int>* root_ptr = bin_tree.GetRoot();
  BinTreeNode<int>* root_left_child_ptr = bin_tree.LeftChild(root_ptr);
  BinTreeNode<int>* root_right_child_ptr = bin_tree.RightChild(root_ptr);

  cout << "根节点: " << root_ptr->data << endl;
  cout << "根节点左孩子: " << root_left_child_ptr->data << endl;
  cout << "根节点右孩子: " << root_right_child_ptr->data << endl;

  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<endl;
}


void BinaryTreeTest::TestParent() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                  Test BinaryTree Parent                   |"<<endl;
  cout<<"|                       测试二叉树父节点                      |"<<endl;
  cout<<"|                                                           |"<<endl;
  cout<<"|                             0                             |"<<endl;
  cout<<"|                            / \\                            |"<<endl;
  cout<<"|                           /   \\                           |"<<endl;
  cout<<"|                          1     2                          |"<<endl;
  cout<<"|                         / \\   /                           |"<<endl;
  cout<<"|                        3   5 4                            |"<<endl;
  cout<<"|                       /                                   |"<<endl;
  cout<<"|                      6                                    |"<<endl<<endl;

  int num = 7;
  BinaryTree<int> bin_tree;

  for (int i = 0 ; i < num; i++) {
    bin_tree.Insert(i);
  }

  BinTreeNode<int>* root_ptr = bin_tree.GetRoot();
  BinTreeNode<int>* root_parent_ptr = bin_tree.Parent(root_ptr);

  BinTreeNode<int>* target_ptr = bin_tree.LeftChild(bin_tree.LeftChild(root_ptr));
  BinTreeNode<int>* target_parent_ptr = bin_tree.Parent(target_ptr);

  if (root_parent_ptr == NULL) {
    cout<<"根节点的父节点为NULL"<<endl;
  } else {
    cout << "根节点的父节点: " << root_parent_ptr->data << endl;
  }

  cout << target_ptr->data << "的父节点： " << target_parent_ptr->data << endl;

  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<endl;
}


void BinaryTreeTest::TestPreOrder() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                  Test BinaryTree PreOrder                 |"<<endl;
  cout<<"|                      测试二叉树前序遍历                      |"<<endl;
  cout<<"|                                                           |"<<endl;
  cout<<"|                             0                             |"<<endl;
  cout<<"|                            / \\                            |"<<endl;
  cout<<"|                           /   \\                           |"<<endl;
  cout<<"|                          1     2                          |"<<endl;
  cout<<"|                         / \\   /                           |"<<endl;
  cout<<"|                        3   5 4                            |"<<endl;
  cout<<"|                       /                                   |"<<endl;
  cout<<"|                      6                                    |"<<endl<<endl;

  int num = 7;
  BinaryTree<int> bin_tree;

  for (int i = 0 ; i < num; i++) {
    bin_tree.Insert(i);
  }

  cout<<"前序遍历(递归):"<<endl;
  bin_tree.PreOrder(visit);
  cout<<endl;

  cout<<"前序遍历(非递归):"<<endl;
  bin_tree.PreOrderNonRecursive(visit);
  cout<<endl;

  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<endl;
}


void BinaryTreeTest::TestInOrder() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                   Test BinaryTree SubTreeInOrder_                 |"<<endl;
  cout<<"|                      测试二叉树中序遍历                      |"<<endl;
  cout<<"|                                                           |"<<endl;
  cout<<"|                             0                             |"<<endl;
  cout<<"|                            / \\                            |"<<endl;
  cout<<"|                           /   \\                           |"<<endl;
  cout<<"|                          1     2                          |"<<endl;
  cout<<"|                         / \\   /                           |"<<endl;
  cout<<"|                        3   5 4                            |"<<endl;
  cout<<"|                       /                                   |"<<endl;
  cout<<"|                      6                                    |"<<endl<<endl;

  int num = 7;
  BinaryTree<int> bin_tree;

  for (int i = 0 ; i < num; i++) {
    bin_tree.Insert(i);
  }

  cout<<"中序遍历(递归):"<<endl;
  bin_tree.InOrder(visit);
  cout<<endl;

  cout<<"中序遍历(非递归):"<<endl;
  bin_tree.InOrderNonRecursive(visit);
  cout<<endl;

  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<endl;
}


void BinaryTreeTest::TestPostOrder() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                 Test BinaryTree PostOrder                 |"<<endl;
  cout<<"|                      测试二叉树后序遍历                      |"<<endl;
  cout<<"|                                                           |"<<endl;
  cout<<"|                             0                             |"<<endl;
  cout<<"|                            / \\                            |"<<endl;
  cout<<"|                           /   \\                           |"<<endl;
  cout<<"|                          1     2                          |"<<endl;
  cout<<"|                         / \\   /                           |"<<endl;
  cout<<"|                        3   5 4                            |"<<endl;
  cout<<"|                       /                                   |"<<endl;
  cout<<"|                      6                                    |"<<endl<<endl;

  int num = 7;
  BinaryTree<int> bin_tree;

  for (int i = 0 ; i < num; i++) {
    bin_tree.Insert(i);
  }

  cout<<"后序遍历(递归):"<<endl;
  bin_tree.PostOrder(visit);
  cout<<endl;

  cout<<"后序遍历(非递归):"<<endl;
  bin_tree.PostOrderNonRecursive(visit);
  cout<<endl;

  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<endl;
}


// 测试层序遍历
void BinaryTreeTest::TestLevelOrder() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                 Test BinaryTree LevelOrder                |"<<endl;
  cout<<"|                      测试二叉树层序遍历                      |"<<endl;
  cout<<"|                                                           |"<<endl;
  cout<<"|                             0                             |"<<endl;
  cout<<"|                            / \\                            |"<<endl;
  cout<<"|                           /   \\                           |"<<endl;
  cout<<"|                          1     2                          |"<<endl;
  cout<<"|                         / \\   /                           |"<<endl;
  cout<<"|                        3   5 4                            |"<<endl;
  cout<<"|                       /                                   |"<<endl;
  cout<<"|                      6                                    |"<<endl<<endl;

  int num = 7;
  BinaryTree<int> bin_tree;

  for (int i = 0 ; i < num; i++) {
    bin_tree.Insert(i);
  }

  bin_tree.LevelOrder(visit);

  cout<<endl;
  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<endl;
}


void BinaryTreeTest::TestFind() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                    Test BinaryTree Find                   |"<<endl;
  cout<<"|                        测试二叉树查找                       |"<<endl;
  cout<<"|                                                           |"<<endl;
  cout<<"|                             0                             |"<<endl;
  cout<<"|                            / \\                            |"<<endl;
  cout<<"|                           /   \\                           |"<<endl;
  cout<<"|                          1     2                          |"<<endl;
  cout<<"|                         / \\   /                           |"<<endl;
  cout<<"|                        3   5 4                            |"<<endl;
  cout<<"|                       /                                   |"<<endl;
  cout<<"|                      6                                    |"<<endl<<endl;

  int num = 7;
  BinaryTree<int> bin_tree;

  for (int i = 0 ; i < num; i++) {
    bin_tree.Insert(i);
  }

  bool in_tree = bin_tree.Find(5);

  if (in_tree) {
    cout<<"5 is in the tree"<<endl;
  } else {
    cout<<"5 isn't in the tree"<<endl;
  }

  in_tree = bin_tree.Find(7);

  if (in_tree) {
    cout<<"7 is in the tree"<<endl;
  } else {
    cout << "7 isn't in the tree" << endl;
  }

  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<endl;
}


void BinaryTreeTest::TestCreateBinTreeByPreAndInOrderString() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|  Test BinaryTree TestCreateBinTreeByPreAndInOrderString   |"<<endl;
  cout<<"|                测试前序遍历与中序遍历生成二叉树                |"<<endl;

  BinaryTree<int> bin_tree;

  int pre_order_traverse_arr[] = { 0, 1, 3, 6, 5, 9, 2, 4, 8, 7 }; // 前序遍历结果
  int in_order_traverse_arr[] = { 6, 3, 1, 9, 5, 0, 8, 4, 2, 7 }; // 中序遍历结果
  bin_tree.CreateBinTreeByPreAndInOrderString(
    pre_order_traverse_arr,
    in_order_traverse_arr,
    10);

  cout<<"打印二叉树:"<<endl;
  bin_tree.Print();

  cout<<endl;
  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<endl;
}


#endif // CYBER_DASH_BINARY_TREE_TEST_H
