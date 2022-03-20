//
// Created by alei_go@163.com(: cyberdash_yuan) on 2020/11/1.
//

#ifndef CYBER_DASH_HUFFMAN_TREE_H
#define CYBER_DASH_HUFFMAN_TREE_H


#include "huffman_node.h"


template <class T>
class HuffmanTree {
public:
	HuffmanTree(float w[], int n);
	~HuffmanTree() { deleteTree(root); }

	void showTree() { showTree(root); }

	void CyberDashShow();

protected:
	HuffmanNode<T>* root;
	void deleteTree(HuffmanNode<T>* t);
	void mergeTree(HuffmanNode<T>* ht1, HuffmanNode<T>* ht2, HuffmanNode<T>*& parent);
	void showTree(HuffmanNode<T>* t);
};

#endif //CYBER_DASH_HUFFMAN_TREE_H
