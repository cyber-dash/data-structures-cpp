//
// Created by svenlee on 2021/4/19.
//

#include "test.h"


void visit(ThreadNode<int> *p) {
  cout << p->data_ << " ";
};


// ThreadTree<int> in_order_thread_tree;
ThreadTree<int> pre_order_thread_tree;
ThreadTree<int> post_order_thread_tree;


void FirstNodeTest() {

  int count = 7;

  ThreadTree<int> test_tree;

  cout<<"The nodes count in the binary tree: "<<count<<endl;

  for (int i = 0 ; i < count; i++) {
    test_tree.Insert(i);
  }

  test_tree.CreateInOrderThread();

  ThreadNode<int>* root_ptr = test_tree.GetRoot();

  ThreadNode<int>* first_node_ptr = test_tree.First(root_ptr);

  cout<<first_node_ptr->data_<<endl;
}


void LastNodeTest() {

  int count = 7;

  ThreadTree<int> test_tree;

  cout<<"The nodes count in the binary tree: "<<count<<endl;

  for (int i = 0 ; i < count; i++) {
    test_tree.Insert(i);
  }

  test_tree.CreateInOrderThread();

  ThreadNode<int>* root_ptr = test_tree.GetRoot();

  ThreadNode<int>* last_node_ptr = test_tree.Last(root_ptr);

  cout<<last_node_ptr->data_<<endl;
}


void NextNodeTest() {

  int count = 7;

  ThreadTree<int> test_tree;

  cout<<"The nodes count in the binary tree: "<<count<<endl;

  for (int i = 0 ; i < count; i++) {
    test_tree.Insert(i);
  }

  test_tree.CreateInOrderThread();

  ThreadNode<int>* first_node_ptr = test_tree.First(test_tree.GetRoot());

  ThreadNode<int>* second_node_ptr = test_tree.Next(first_node_ptr);
  ThreadNode<int>* third_node_ptr = test_tree.Next(second_node_ptr);
  ThreadNode<int>* forth_node_ptr = test_tree.Next(third_node_ptr);

  cout<<"first node data: "<<first_node_ptr->data_<<endl;
  cout<<"second node data: "<<second_node_ptr->data_<<endl;
  cout<<"third node data: "<<third_node_ptr->data_<<endl;
  cout<<"forth node data: "<<forth_node_ptr->data_<<endl;
}


void CreateInOrderThreadTreeTest() {

  int count = 7;
  ThreadTree<int> in_order_thread_tree;

  cout << "The nodes count in the binary tree: " << count << endl;

  for (int i = 0 ; i < count; i++) {
    in_order_thread_tree.Insert(i);
  }

  in_order_thread_tree.CreateInOrderThread();

  cout  << "In order: " << endl;
  // in_order_thread_tree.PreOrderTraverse(visit);
  in_order_thread_tree.InOrderTraverse(visit);
  cout << endl;
}
