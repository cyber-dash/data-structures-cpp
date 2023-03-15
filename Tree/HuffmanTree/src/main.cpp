//
// Created by alei_go@163.com(: cyberdash_yuan) on 2020/11/1.
//

#include "huffman_tree.h"

int main() {
	double w[] = { 2,4,6,1,10 };
	int n = sizeof(w) / sizeof(w[0]);

	HuffmanTree<double> htree(w, n);

	htree.showTree();

	return 0;
}
