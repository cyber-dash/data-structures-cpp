//
// Created by alei_go@163.com(: cyberdash_yuan) on 2020/11/1.
//

#ifndef CYBER_DASH_HUFFMAN_TREE_H
#define CYBER_DASH_HUFFMAN_TREE_H


#include <iostream>
// #include "huffman_tree.h"
#include "min_heap.h"


using namespace std;


template <class T>
struct HuffmanNode {
    HuffmanNode() : left_child(NULL), rightChild(NULL), parent(NULL) {}
    HuffmanNode(double elem, HuffmanNode* left = NULL,
                HuffmanNode* right = NULL, HuffmanNode* pr = NULL) :
        data(elem), left_child(left), rightChild(right), parent(pr) {}

    bool operator <=(HuffmanNode& R) { return data <= R.data; }
    bool operator >(HuffmanNode& R) { return data > R.data; }

    double data;
    HuffmanNode* left_child;
    HuffmanNode* rightChild;
    HuffmanNode* parent;
};

template <class T>
class HuffmanTree {
public:
	HuffmanTree(double w[], int n);
	~HuffmanTree() { deleteTree(root); }

	void showTree() { showTree(root); }

	void CyberDashShow();

protected:
	HuffmanNode<T>* root;
	void deleteTree(HuffmanNode<T>* t);
	void mergeTree(HuffmanNode<T>* ht1, HuffmanNode<T>* ht2, HuffmanNode<T>*& parent);
	void showTree(HuffmanNode<T>* t);
};


template <class T>
HuffmanTree<T>::HuffmanTree(double w[], int n) {
    MinHeap<HuffmanNode<T> > hp;
    HuffmanNode<T>* parent, * first, * second, * work, temp;

    for (int i = 0; i < n; i++) {
        work = new HuffmanNode<T>;
        work->data = w[i];
        work->left_child = NULL;
        work->rightChild = NULL;
        work->parent = work;
        hp.Insert(*work);
    }

    for (int i = 0; i < n - 1; i++) {
        hp.RemoveMin(temp);
        first = temp.parent;
        hp.RemoveMin(temp);
        second = temp.parent;
        mergeTree(first, second, parent);
        hp.Insert(*parent);
    }

    root = parent;
}


template <class T>
void HuffmanTree<T>::deleteTree(HuffmanNode<T>* t) {
    if (t == NULL) {
        return;
    }

    deleteTree(t->left_child);
    deleteTree(t->rightChild);

    delete t;
}

template <class T>
void HuffmanTree<T>::
mergeTree(HuffmanNode<T>* ht1, HuffmanNode<T>* ht2, HuffmanNode<T>*& parent) {
    parent = new HuffmanNode<T>;

    parent->left_child = ht1;
    parent->rightChild = ht2;
    parent->parent = parent;

    parent->data = ht1->data + ht2->data;
    ht1->parent = ht2->parent = parent;
}


template <class T>
void HuffmanTree<T>::showTree(HuffmanNode<T>* t) {
    if (t == NULL) {
        return;
    }

    cout << t->data;
    cout << '(';
    showTree(t->left_child);
    cout << ',';
    showTree(t->rightChild);
    cout << ')';
}


#endif //CYBER_DASH_HUFFMAN_TREE_H
