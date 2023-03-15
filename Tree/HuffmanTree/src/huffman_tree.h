//
// Created by alei_go@163.com(: cyberdash_yuan) on 2020/11/1.
//

#ifndef CYBER_DASH_HUFFMAN_TREE_H
#define CYBER_DASH_HUFFMAN_TREE_H


#include <iostream>
#include "min_heap.h"


using namespace std;


template<typename TWeight>
struct HuffmanTreeNode {
    HuffmanTreeNode(): weight(TWeight()), left_child(NULL), right_child(NULL), parent(NULL) {}

    HuffmanTreeNode(TWeight weight, HuffmanTreeNode* left = NULL, HuffmanTreeNode* right = NULL, HuffmanTreeNode* parent = NULL)
        : weight(weight), left_child(left), right_child(right), parent(parent) {}

    bool operator<=(const HuffmanTreeNode& node) { return weight <= node.weight; }
    bool operator>(const HuffmanTreeNode& node) { return weight > node.weight; }

    TWeight weight;
    HuffmanTreeNode* left_child;
    HuffmanTreeNode* right_child;
    HuffmanTreeNode* parent;
};


template <class TWeight>
class HuffmanTree {
public:
	HuffmanTree(const TWeight weight[], int n);
	~HuffmanTree() { ClearSubTree(root_); }

	void showTree() { showTree(root_); }

protected:
	HuffmanTreeNode<TWeight>* root_;
	void ClearSubTree(HuffmanTreeNode<TWeight>* t);
	void mergeTree(HuffmanTreeNode<TWeight>* ht1, HuffmanTreeNode<TWeight>* ht2, HuffmanTreeNode<TWeight>*& parent);
	void showTree(HuffmanTreeNode<TWeight>* t);
};


template <class TWeight>
HuffmanTree<TWeight>::HuffmanTree(const TWeight* weight, int n) {
    MinHeap<HuffmanTreeNode<TWeight> > hp;

    for (int i = 0; i < n; i++) {
        HuffmanTreeNode<TWeight>* work = new HuffmanTreeNode<TWeight>(weight[i], NULL, NULL, NULL);
        work->parent = work;
        hp.Insert(*work);
    }

    HuffmanTreeNode<TWeight>* parent = NULL;
    for (int i = 0; i < n - 1; i++) {
        HuffmanTreeNode<TWeight> temp;

        hp.RemoveMin(temp);
        HuffmanTreeNode<TWeight>* first = temp.parent;
        hp.RemoveMin(temp);
        HuffmanTreeNode<TWeight>* second = temp.parent;

        mergeTree(first, second, parent);
        hp.Insert(*parent);
    }

    root_ = parent;
}


template <class TWeight>
void HuffmanTree<TWeight>::ClearSubTree(HuffmanTreeNode<TWeight>* t) {
    if (t == NULL) {
        return;
    }

    ClearSubTree(t->left_child);
    ClearSubTree(t->right_child);

    delete t;
}


template <class TWeight>
void HuffmanTree<TWeight>::
mergeTree(HuffmanTreeNode<TWeight>* ht1, HuffmanTreeNode<TWeight>* ht2, HuffmanTreeNode<TWeight>*& parent) {
    parent = new HuffmanTreeNode<TWeight>(ht1->weight + ht2->weight, ht1, ht2, NULL);

    parent->parent = parent;

    ht1->parent = ht2->parent = parent;
}


template <class TWeight>
void HuffmanTree<TWeight>::showTree(HuffmanTreeNode<TWeight>* t) {
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
