//
// Created by alei_go@163.com(抖音: cyberdash_yuan) on 2020/11/1.
//

#include <iostream>
#include "thread_node.h"
#include "thread_tree.h"
#include "thread_tree.cpp"


using namespace std;


void visit(ThreadNode<int> *p) {
  cout << p->data << " ";
};


int main(void) {
  int num;
  int i = 0;

  ThreadTree<int> tree;

  cout << "Input the nodes num in the binary tree: ";
  cin >> num;

  for (i = 0 ; i < num; i++) {
    tree.Insert(i);
  }

  tree.createInThread();


  cout  << "pre order: " << endl;
  tree.PreOrder(visit);
  cout << endl;
  cout  << "in order: " << endl;
  tree.InOrder(visit);
  cout << endl;
  cout  << "post order: " << endl;
  tree.PostOrder(visit);
  cout << endl;


  ThreadNode<int> *node = tree.First(tree.GetRoot());
  cout << "first element is :" << node->data << endl;

  node = tree.Next(node);
  cout << "next element is :" << node->data << endl;

  node = tree.Last(tree.GetRoot());
  cout << "last element is :" << node->data << endl;

  node = tree.Prior(node);
  cout << "prior element is :" << node->data << endl;

  ThreadNode<int> *t_first = tree.First(tree.GetRoot());
  ThreadNode<int> *tmp = new ThreadNode<int>(111);

  tree.InsertRight(tree.First(tree.GetRoot()), tmp);

  tmp = new ThreadNode<int>(222);
  tree.InsertLeft(tree.First(tree.GetRoot()), tmp);

  cout  << "in order: " << endl;
  tree.InOrder(visit);
  cout << endl;

  tree.DeleteRight(t_first);
  tree.DeleteLeft(t_first);

  cout  << "in order: " << endl;
  tree.InOrder(visit);
  cout << endl;

  tree.CyberDashShow();
}
