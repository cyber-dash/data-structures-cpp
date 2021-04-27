//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2021/4/19.
//

#include "test.h"


void visit(ThreadNode<int>* node_ptr) {
  cout<<node_ptr->data_<<" ";
};


void TestFirst() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                 Test ThreadTree First Node                |"<<endl;
  cout<<"|                     测试线索树第一个线索节点                  |"<<endl;
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

  ThreadNode<int>* root_ptr = in_order_thread_tree.GetRoot();

  ThreadNode<int>* first_node_ptr = in_order_thread_tree.First(root_ptr);

  cout<<"中序线索第一个线索节点 :"<<first_node_ptr->data_<<endl;

  cout<<endl<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<endl;
}


void TestLast() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                 Test ThreadTree Last Node                 |"<<endl;
  cout<<"|                    测试线索树最后一个线索节点                  |"<<endl;
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

  ThreadNode<int>* root_ptr = in_order_thread_tree.GetRoot();

  ThreadNode<int>* last_node_ptr = in_order_thread_tree.Last(root_ptr);

  cout<<"中序线索最后一个线索节点: "<<last_node_ptr->data_<<endl;

  cout<<endl<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<endl;
}


void TestNext() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                 Test ThreadTree Next Node                 |"<<endl;
  cout<<"|                    测试线索树下一个线索节点                    |"<<endl;
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

  cout<<"The nodes count in the binary tree: "<<count<<endl;

  for (int i = 0 ; i < count; i++) {
    in_order_thread_tree.Insert(i);
  }

  in_order_thread_tree.CreateInOrderThread();

  ThreadNode<int>* first_node_ptr = in_order_thread_tree.First(in_order_thread_tree.GetRoot());

  ThreadNode<int>* second_node_ptr = in_order_thread_tree.Next(first_node_ptr);
  ThreadNode<int>* third_node_ptr = in_order_thread_tree.Next(second_node_ptr);
  ThreadNode<int>* forth_node_ptr = in_order_thread_tree.Next(third_node_ptr);

  cout<<"中序线索树第1个线索节点: "<<first_node_ptr->data_<<endl;
  cout<<"中序线索树第2个线索节点: "<<second_node_ptr->data_<<endl;
  cout<<"中序线索树第3个线索节点: "<<third_node_ptr->data_<<endl;
  cout<<"中序线索树第4个线索节点: "<<forth_node_ptr->data_<<endl;

  cout<<endl<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<endl;
}


void TestPrior() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                 Test ThreadTree Prior Node                |"<<endl;
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

  node_ptr_array[0] = in_order_thread_tree.First(in_order_thread_tree.GetRoot());

  for (int i = 1; i < 4; i++) {
    node_ptr_array[i] = in_order_thread_tree.Next(node_ptr_array[i - 1]);
  }

  for (int i = 3; i >=1; i--) {
    ThreadNode<int>* prior_node_ptr = in_order_thread_tree.Prior(node_ptr_array[i]);
    cout<<"中序线索树第"<<i<<"个线索节点: "<<prior_node_ptr->data_<<endl; // (i - 1) + 1 = i
  }

  cout<<endl<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<endl;
}


void TestCreateInOrderThread() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                Test ThreadTree CreateInOrder              |"<<endl;
  cout<<"|                    测试线索树创建中序线索                     |"<<endl;
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

  cout<<"中序线索树, 线索遍历: "<<endl;
  in_order_thread_tree.InOrderTraverse(visit);

  cout<<endl<<endl<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<endl;
}
