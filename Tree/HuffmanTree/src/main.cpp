//
// Created by alei_go@163.com(: cyberdash_yuan) on 2020/11/1.
//

#include "huffman_tree.h"

int main() {
    char keys[] = { 'a', 'b', 'c', 'd', 'e' };
	double weights[] = { 2, 4, 6, 1, 10 };
	int size = sizeof(weights) / sizeof(weights[0]);

	HuffmanTree<char, double> huffman_tree(keys, weights, size);

    huffman_tree.PrintTree();

    cout << endl;

    unordered_map<char, string> huffman_codes = huffman_tree.GetHuffmanCode();

    for (unordered_map<char, string>::iterator iter = huffman_codes.begin(); iter != huffman_codes.end(); iter++) {
        cout << iter->first << ": " << iter->second << endl;
    }

	return 0;
}
