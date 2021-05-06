//
// Created by cyberdash@163.com on 2021/5/4.
//

#include "test.h"
#include "binary_tree.h"


void visit(BinTreeNode<int>* node_ptr) {
  cout<<node_ptr->data_ <<" ";
};


/**
 * 测试二叉树深度
 */
void TestBinaryTreeHeight() {

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

  int i = 0;
  for (i = 0 ; i < num; i++) {
    bin_tree.Insert(i);
  }

  int height = bin_tree.Height();

  cout<<"二叉树深度: "<<height<<endl;

  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<endl;
}

// 测试是否为空
void TestIsEmpty() {

}


// 测试二叉树深度
void TestBinaryTreeChildFunction() {

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

  int i = 0;
  for (i = 0 ; i < num; i++) {
    bin_tree.Insert(i);
  }

  BinTreeNode<int>* root_ptr = bin_tree.GetRoot();
  BinTreeNode<int>* root_left_child_ptr = bin_tree.LeftChild(root_ptr);
  BinTreeNode<int>* root_right_child_ptr = bin_tree.RightChild(root_ptr);

  cout<<"根节点: "<<root_ptr->data_<<endl;
  cout<<"根节点左孩子: "<<root_left_child_ptr->data_<<endl;
  cout<<"根节点右孩子: "<<root_right_child_ptr->data_<<endl;

  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<endl;
}


// 测试二叉树深度
void TestParent() {

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

  int i = 0;
  for (i = 0 ; i < num; i++) {
    bin_tree.Insert(i);
  }

  BinTreeNode<int>* root_ptr = bin_tree.GetRoot();
  BinTreeNode<int>* root_parent_ptr = bin_tree.Parent(root_ptr);

  BinTreeNode<int>* target_ptr = bin_tree.LeftChild(bin_tree.LeftChild(root_ptr));
  BinTreeNode<int>* target_parent_ptr = bin_tree.Parent(target_ptr);

  if (root_parent_ptr == NULL) {
    cout<<"根节点的父节点为NULL"<<endl;
  } else {
    cout<<"根节点的父节点: "<<root_parent_ptr->data_<<endl;
  }

  cout<<target_ptr->data_<<"的父节点： "<<target_parent_ptr->data_<<endl;

  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<endl;
}


void TestPreOrder() {

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

  int i = 0;
  for (i = 0 ; i < num; i++) {
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


void TestInOrder() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                   Test BinaryTree InOrder                 |"<<endl;
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

  int i = 0;
  for (i = 0 ; i < num; i++) {
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


void TestPostOrder() {

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

  int i = 0;
  for (i = 0 ; i < num; i++) {
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
void TestLevelOrder() {

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

  int i = 0;
  for (i = 0 ; i < num; i++) {
    bin_tree.Insert(i);
  }

  bin_tree.LevelOrder(visit);

  cout<<endl;
  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<endl;
}


void TestFind() {

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

  int i = 0;
  for (i = 0 ; i < num; i++) {
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


void TestPrint();


void TestCreateBinTreeByPreAndInOrderString() {
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
