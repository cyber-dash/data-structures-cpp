//
// Created by svenlee on 2021/4/19.
//

#include "test.h"


void visit(ThreadNode<int> *p) {
  cout << p->data_ << " ";
};


ThreadTree<int> in_order_thread_tree;
ThreadTree<int> pre_order_thread_tree;
ThreadTree<int> post_order_thread_tree;


void CreateInOrderThreadTreeTest() {

  int count = 10;

  cout << "The nodes count in the binary tree: " << count << endl;

  for (int i = 0 ; i < count; i++) {
    in_order_thread_tree.Insert(i);
  }

  in_order_thread_tree.CreateInOrderThread();

  cout  << "pre order: " << endl;
  in_order_thread_tree.PreOrderTraverse(visit);
  cout << endl;
}
