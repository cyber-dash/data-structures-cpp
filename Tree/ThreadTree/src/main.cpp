//
// Created by alei_go@163.com(抖音: cyberdash_yuan) on 2020/11/1.
//

#include "test.h"


using namespace std;


int main() {

    // 测试First
    TestFirst();

    // 测试Last
    TestLast();

    // 测试Next(中序)
    TestNext();

    // 测试Prior(中序)
    TestPrior();

    // 测试Parent(中序)
    TestParent();

    // 测试中序线索树中序遍历
    TestInOrderTraverseOfInOrderThread();

    // 测试中序线索树前序遍历
    TestPreOrderTraverseOfInOrderThread();

    // 测试中序线索树后序遍历
    TestPostOrderTraverseOfInOrderThread();

    /*
    int num;
    int i = 0;

    ThreadTree<int> tree;

    cout << "Input the nodes num in the binary tree: ";
    cin >> num;

    for (i = 0 ; i < num; i++) {
      tree.Insert_(i);
    }

    tree.CreateInOrderThread();

    cout  << "pre order: " << endl;
    tree.PreOrderTraverse(visit);
    cout << endl;
    cout  << "in order: " << endl;
    tree.InOrderTraverse(visit);
    cout << endl;
    cout  << "post order: " << endl;
    tree.PostOrderTraverse(visit);
    cout << endl;

    ThreadNode<int> *node = tree.First(tree.GetRoot());
    cout << "first element is :" << node->data_ << endl;

    node = tree.Next(node);
    cout << "next element is :" << node->data_ << endl;

    node = tree.Last(tree.GetRoot());
    cout << "last element is :" << node->data_ << endl;

    node = tree.Prior(node);
    cout << "prior element is :" << node->data_ << endl;

    ThreadNode<int> *t_first = tree.First(tree.GetRoot());
    ThreadNode<int> *tmp = new ThreadNode<int>(111);

    tree.InsertRight(tree.First(tree.GetRoot()), tmp);

    tmp = new ThreadNode<int>(222);
    tree.InsertLeft(tree.First(tree.GetRoot()), tmp);

    cout  << "in order: " << endl;
    tree.InOrderTraverse(visit);
    cout << endl;

    tree.DeleteRight(t_first);
    tree.DeleteLeft(t_first);

    cout  << "in order: " << endl;
    tree.InOrderTraverse(visit);
    cout << endl;

    tree.CyberDashShow();
     */
}