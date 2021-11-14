//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2021/4/19.
//

#include "test.h"


void visit(ThreadNode<int>* node_ptr) {
  cout << node_ptr->data << " ";
};


void TestFirst() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|              Test InOrder ThreadTree First Node           |"<<endl;
  cout<<"|                  测试中序线索树第一个线索节点                 |"<<endl;
  cout<<"|                                                           |"<<endl;
  cout<<"|                             0                             |"<<endl;
  cout<<"|                            / \\                            |"<<endl;
  cout<<"|                           /   \\                           |"<<endl;
  cout<<"|                          1     2                          |"<<endl;
  cout<<"|                         / \\   /                           |"<<endl;
  cout<<"|                        3   5 4                            |"<<endl;
  cout<<"|                       /                                   |"<<endl;
  cout<<"|                      6                                    |"<<endl<<endl;

  int count = 7;

  ThreadTree<int> in_order_thread_tree;

  for (int i = 0 ; i < count; i++) {
    in_order_thread_tree.Insert(i);
  }

  in_order_thread_tree.CreateInOrderThread();

  ThreadNode<int>* root_ptr = in_order_thread_tree.Root();

  ThreadNode<int>* first_node_ptr = in_order_thread_tree.First(root_ptr);

  cout << "中序线索第一个线索节点 :" << first_node_ptr->data << endl;

  cout<<endl<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<endl;
}


void TestLast() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|              Test InOrder ThreadTree Last Node            |"<<endl;
  cout<<"|                 测试中序线索树最后一个线索节点                 |"<<endl;
  cout<<"|                                                           |"<<endl;
  cout<<"|                             0                             |"<<endl;
  cout<<"|                            / \\                            |"<<endl;
  cout<<"|                           /   \\                           |"<<endl;
  cout<<"|                          1     2                          |"<<endl;
  cout<<"|                         / \\   /                           |"<<endl;
  cout<<"|                        3   5 4                            |"<<endl;
  cout<<"|                       /                                   |"<<endl;
  cout<<"|                      6                                    |"<<endl<<endl;

  int count = 7;

  ThreadTree<int> in_order_thread_tree;

  for (int i = 0 ; i < count; i++) {
    in_order_thread_tree.Insert(i);
  }

  in_order_thread_tree.CreateInOrderThread();

  ThreadNode<int>* root_ptr = in_order_thread_tree.Root();

  ThreadNode<int>* last_node_ptr = in_order_thread_tree.Last(root_ptr);

  cout << "中序线索最后一个线索节点: " << last_node_ptr->data << endl;

  cout<<endl<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<endl;
}


void TestNext() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|              Test InOrder ThreadTree Next Node            |"<<endl;
  cout<<"|                  测试中序线索树下一个线索节点                 |"<<endl;
  cout<<"|                                                           |"<<endl;
  cout<<"|                             0                             |"<<endl;
  cout<<"|                            / \\                            |"<<endl;
  cout<<"|                           /   \\                           |"<<endl;
  cout<<"|                          1     2                          |"<<endl;
  cout<<"|                         / \\   /                           |"<<endl;
  cout<<"|                        3   5 4                            |"<<endl;
  cout<<"|                       /                                   |"<<endl;
  cout<<"|                      6                                    |"<<endl<<endl;

  int count = 7;

  ThreadTree<int> in_order_thread_tree;

  for (int i = 0 ; i < count; i++) {
    in_order_thread_tree.Insert(i);
  }

  in_order_thread_tree.CreateInOrderThread();

  ThreadNode<int>* first_node_ptr = in_order_thread_tree.First(in_order_thread_tree.Root());

  ThreadNode<int>* second_node_ptr = in_order_thread_tree.Next(first_node_ptr);
  ThreadNode<int>* third_node_ptr = in_order_thread_tree.Next(second_node_ptr);
  ThreadNode<int>* forth_node_ptr = in_order_thread_tree.Next(third_node_ptr);

  cout << "中序线索树第1个线索节点: " << first_node_ptr->data << endl;
  cout << "中序线索树第2个线索节点: " << second_node_ptr->data << endl;
  cout << "中序线索树第3个线索节点: " << third_node_ptr->data << endl;
  cout << "中序线索树第4个线索节点: " << forth_node_ptr->data << endl;

  cout<<endl<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<endl;
}


void TestPrior() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|             Test InOrder ThreadTree Prior Node            |"<<endl;
  cout<<"|                  测试中序线索树前一个线索节点                 |"<<endl;
  cout<<"|                                                           |"<<endl;
  cout<<"|                             0                             |"<<endl;
  cout<<"|                            / \\                            |"<<endl;
  cout<<"|                           /   \\                           |"<<endl;
  cout<<"|                          1     2                          |"<<endl;
  cout<<"|                         / \\   /                           |"<<endl;
  cout<<"|                        3   5 4                            |"<<endl;
  cout<<"|                       /                                   |"<<endl;
  cout<<"|                      6                                    |"<<endl<<endl;

  int count = 7;

  ThreadNode<int>* node_ptr_array[4];
  ThreadTree<int> in_order_thread_tree;

  for (int i = 0 ; i < count; i++) {
    in_order_thread_tree.Insert(i);
  }

  in_order_thread_tree.CreateInOrderThread();

  node_ptr_array[0] = in_order_thread_tree.First(in_order_thread_tree.Root());

  for (int i = 1; i < 4; i++) {
    node_ptr_array[i] = in_order_thread_tree.Next(node_ptr_array[i - 1]);
  }

  for (int i = 3; i >=1; i--) {
    ThreadNode<int>* prior_node_ptr = in_order_thread_tree.Prior(node_ptr_array[i]);
    cout << "中序线索树第" << i << "个线索节点: " << prior_node_ptr->data << endl; // (i - 1) + 1 = i
  }

  cout<<endl<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<endl;
}


/*
 * 中序线索二叉树Parent
 */
void TestParent() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|             Test InOrder ThreadTree Parent Node           |"<<endl;
  cout<<"|                     测试中序线索树父节点                     |"<<endl;
  cout<<"|                                                           |"<<endl;
  cout<<"|                             0                             |"<<endl;
  cout<<"|                            / \\                            |"<<endl;
  cout<<"|                           /   \\                           |"<<endl;
  cout<<"|                          1     2                          |"<<endl;
  cout<<"|                         / \\   /                           |"<<endl;
  cout<<"|                        3   5 4                            |"<<endl;
  cout<<"|                       /                                   |"<<endl;
  cout<<"|                      6                                    |"<<endl<<endl;

  int count = 7;

  ThreadTree<int> in_order_thread_tree;

  for (int i = 0 ; i < count; i++) {
    in_order_thread_tree.Insert(i);
  }

  in_order_thread_tree.CreateInOrderThread();

  ThreadNode<int>* root_ptr = in_order_thread_tree.Root();
  ThreadNode<int>* root_parent_ptr = in_order_thread_tree.Parent(root_ptr);

  ThreadNode<int>* first_node_ptr = in_order_thread_tree.First(root_ptr);
  ThreadNode<int>* first_parent_ptr = in_order_thread_tree.Parent(first_node_ptr);
  ThreadNode<int>* first_parent_parent_ptr = in_order_thread_tree.Parent(first_parent_ptr);

  if (root_parent_ptr != NULL) {
    cout << "根节点的父节点: " << root_parent_ptr->data << endl;
  } else {
    cout<<"根节点的父节点为NULL"<<endl;
  }

  cout << "第一个线索节点: " << first_node_ptr->data << endl;
  cout << "第一个线索节点的父节点: " << first_parent_ptr->data << endl;
  cout << "第一个线索节点的父节点的父节点: " << first_parent_parent_ptr->data << endl;

  cout<<endl<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<endl;
}


void TestInOrderTraverseOfInOrderThread() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|          Test InOrder ThreadTree InOrderTraverse          |"<<endl;
  cout<<"|                    测试中序线索树中序遍历                     |"<<endl;
  cout<<"|                                                           |"<<endl;
  cout<<"|                             0                             |"<<endl;
  cout<<"|                            / \\                            |"<<endl;
  cout<<"|                           /   \\                           |"<<endl;
  cout<<"|                          1     2                          |"<<endl;
  cout<<"|                         / \\   /                           |"<<endl;
  cout<<"|                        3   5 4                            |"<<endl;
  cout<<"|                       /                                   |"<<endl;
  cout<<"|                      6                                    |"<<endl<<endl;

  int count = 7;
  ThreadTree<int> in_order_thread_tree;

  for (int i = 0 ; i < count; i++) {
    in_order_thread_tree.Insert(i);
  }

  in_order_thread_tree.CreateInOrderThread();

  cout<<"中序线索树, 中序遍历: "<<endl;
  in_order_thread_tree.InOrderTraverse(visit);

  cout<<endl<<endl<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<endl;
}


void TestPreOrderTraverseOfInOrderThread() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|          Test InOrder ThreadTree PreOrderTraverse         |"<<endl;
  cout<<"|                    测试中序线索树前序遍历                     |"<<endl;
  cout<<"|                                                           |"<<endl;
  cout<<"|                             0                             |"<<endl;
  cout<<"|                            / \\                            |"<<endl;
  cout<<"|                           /   \\                           |"<<endl;
  cout<<"|                          1     2                          |"<<endl;
  cout<<"|                         / \\   /                           |"<<endl;
  cout<<"|                        3   5 4                            |"<<endl;
  cout<<"|                       /                                   |"<<endl;
  cout<<"|                      6                                    |"<<endl<<endl;

  int count = 7;
  ThreadTree<int> in_order_thread_tree;

  for (int i = 0 ; i < count; i++) {
    in_order_thread_tree.Insert(i);
  }

  in_order_thread_tree.CreateInOrderThread();

  cout<<"中序线索树, 前序遍历: "<<endl;
  in_order_thread_tree.PreOrderTraverse(visit);

  cout<<endl<<endl<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<endl;
}


void TestPostOrderTraverseOfInOrderThread() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|          Test InOrder ThreadTree PostOrderTraverse        |"<<endl;
  cout<<"|                    测试中序线索树后序遍历                     |"<<endl;
  cout<<"|                                                           |"<<endl;
  cout<<"|                             0                             |"<<endl;
  cout<<"|                            / \\                            |"<<endl;
  cout<<"|                           /   \\                           |"<<endl;
  cout<<"|                          1     2                          |"<<endl;
  cout<<"|                         / \\   /                           |"<<endl;
  cout<<"|                        3   5 4                            |"<<endl;
  cout<<"|                       /                                   |"<<endl;
  cout<<"|                      6                                    |"<<endl<<endl;

  int count = 7;
  ThreadTree<int> in_order_thread_tree;

  for (int i = 0 ; i < count; i++) {
    in_order_thread_tree.Insert(i);
  }

  in_order_thread_tree.CreateInOrderThread();

  cout<<"中序线索树, 后序遍历: "<<endl;
  in_order_thread_tree.PostOrderTraverse(visit);

  cout<<endl<<endl<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<endl;
}
