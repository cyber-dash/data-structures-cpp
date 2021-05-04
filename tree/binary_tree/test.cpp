//
// Created by cyberdash@163.com on 2021/5/4.
//

#include "test.h"
#include "binary_tree.h"


// 测试二叉树深度
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
