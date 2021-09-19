//
// Created by alei_go@163.com(抖音: cyberdash_yuan) on 2020/11/1.
//

#include "min_heap.cpp"
#include "huffman_tree.h"
#include "huffman_tree.cpp"

int main() {
	float w[] = {2,4,6,1,10};
	int n = sizeof(w) / sizeof(w[0]);

	HuffmanTree<int> htree(w,n);

	htree.showTree();

	htree.CyberDashShow();

	return 0;
}
