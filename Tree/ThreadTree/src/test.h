//
// Created by cyberdash@163.com(: cyberdash_yuan) on 2021/4/19.
//

#ifndef CYBER_DASH_THREAD_TREE_TEST_H
#define CYBER_DASH_THREAD_TREE_TEST_H


#include "threaded_node.h"


void visit(ThreadedNode<int> *p);

void TestFirst();

void TestLast();

void TestNext();

void TestPrior();

void TestParent();

void TestInOrderTraverseOfInOrderThread();

void TestPreOrderTraverseOfInOrderThread();

void TestPostOrderTraverseOfInOrderThread();


#endif //CYBER_DASH_THREAD_TREE_TEST_H
