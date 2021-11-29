//
// Created by alei_go@163.com(抖音: cyberdash_yuan) on 2020/11/1.
//

#ifndef CYBER_DASH_HUFFMAN_TREE_NODE_H
#define CYBER_DASH_HUFFMAN_TREE_NODE_H


#include <iostream>


template <class T>
struct HuffmanNode {
	HuffmanNode(): left_child(NULL), rightChild(NULL), parent(NULL) {}
	HuffmanNode(float elem, HuffmanNode *left = NULL,
		HuffmanNode *right = NULL, HuffmanNode *pr = NULL):
      data(elem), left_child(left), rightChild(right), parent(pr) {}

	bool operator <=(HuffmanNode &R) { return data <= R.data; }
	bool operator >(HuffmanNode &R) { return data > R.data; }

  float data;
  HuffmanNode* left_child;
  HuffmanNode* rightChild;
  HuffmanNode* parent;
};


#endif //CYBER_DASH_HUFFMAN_TREE_NODE_H
