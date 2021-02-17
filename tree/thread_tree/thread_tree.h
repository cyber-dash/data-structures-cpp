//
// Created by alei_go@163.com(抖音: cyberdash_yuan) on 2020/11/1.
//

#ifndef CYBER_DASH_THREAD_TREE_H
#define CYBER_DASH_THREAD_TREE_H


#include "thread_node.h"


template <class T>
class ThreadTree {
public:
  ThreadTree(): root(NULL) {}
  void createInThread(void);
  void createPreThread(void);
  void createPostThread(void);
  ThreadNode<T> *GetRoot(void) {return root;}
  ThreadNode<T> *First(ThreadNode<T> *current);
  ThreadNode<T> *Last(ThreadNode<T> *current);
  ThreadNode<T> *Next(ThreadNode<T> *current);
  ThreadNode<T> *Prior(ThreadNode<T> *current);
  ThreadNode<T> *PreOrderNext(ThreadNode<T> *current);
  ThreadNode<T> *PreOrderPrior(ThreadNode<T> *current);
  ThreadNode<T> *PostOrderNext(ThreadNode<T> *current);
  ThreadNode<T> *PostOrderPrior(ThreadNode<T> *current);
  void InOrder(void (*visit)(ThreadNode<T> *p));
  void PreOrder(void (*visit)(ThreadNode<T> *p));
  void PostOrder(void (*visit)(ThreadNode<T> *p));

  bool Insert(T& item) { return Insert(root, item);}
  void InsertRight(ThreadNode<T> *s, ThreadNode<T> *r);
  void InsertLeft(ThreadNode<T> *s, ThreadNode<T> *r);
  void DeleteRight(ThreadNode<T> *s);
  void DeleteLeft(ThreadNode<T> *s);

  void CyberDashShow();

protected:
  ThreadNode<T> *root;
  void createInThread(ThreadNode<T> *current, ThreadNode<T> *& pre);
  void createPreThread(ThreadNode<T> *current, ThreadNode<T> *& pre);
  void createPostThread(ThreadNode<T> *current, ThreadNode<T> *& pre);
  ThreadNode<T> *Parent(ThreadNode<T> *t);

  bool Insert(ThreadNode<T> *& subTree, T& x);
};


#endif //CYBER_DASH_THREAD_TREE_H
