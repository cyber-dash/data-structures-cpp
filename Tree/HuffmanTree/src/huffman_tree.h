//
// Created by alei_go@163.com(: cyberdash_yuan) on 2020/11/1.
//

#ifndef CYBER_DASH_HUFFMAN_TREE_H
#define CYBER_DASH_HUFFMAN_TREE_H


#include <iostream>
#include "min_heap.h"


using namespace std;


template <class T>
struct HuffmanNode {
    HuffmanNode(): weight(0), left_child(NULL), right_child(NULL), parent(NULL) {}
    HuffmanNode(double weight, HuffmanNode* left = NULL,
                HuffmanNode* right = NULL, HuffmanNode* pr = NULL) :
        weight(weight), left_child(left), right_child(right), parent(pr) {}

    bool operator<=(HuffmanNode& node) { return weight <= node.weight; }
    bool operator>(HuffmanNode& node) { return weight > node.weight; }

    double weight;
    HuffmanNode* left_child;
    HuffmanNode* right_child;
    HuffmanNode* parent;
};

template <class T>
class HuffmanTree {
public:
	HuffmanTree(const double weight[], int n);
	~HuffmanTree() { deleteTree(root); }

	void showTree() { showTree(root); }

protected:
	HuffmanNode<T>* root;
	void deleteTree(HuffmanNode<T>* t);
	void mergeTree(HuffmanNode<T>* ht1, HuffmanNode<T>* ht2, HuffmanNode<T>*& parent);
	void showTree(HuffmanNode<T>* t);
};


template <class T>
HuffmanTree<T>::HuffmanTree(const double* weight, int n) {
    MinHeap<HuffmanNode<T> > hp;
    HuffmanNode<T>* parent, * first, * second, * work, temp;

    for (int i = 0; i < n; i++) {
        work = new HuffmanNode<T>(weight[i], NULL, NULL, NULL);
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
    deleteTree(t->right_child);

    delete t;
}

template <class T>
void HuffmanTree<T>::
mergeTree(HuffmanNode<T>* ht1, HuffmanNode<T>* ht2, HuffmanNode<T>*& parent) {
    parent = new HuffmanNode<T>(ht1->weight + ht2->weight, ht1, ht2, NULL);

    parent->parent = parent;

    ht1->parent = ht2->parent = parent;
}


template <class T>
void HuffmanTree<T>::showTree(HuffmanNode<T>* t) {
    if (t == NULL) {
        return;
    }

    cout << t->weight;
    cout << '(';
    showTree(t->left_child);
    cout << ',';
    showTree(t->right_child);
    cout << ')';
}


#endif //CYBER_DASH_HUFFMAN_TREE_H
