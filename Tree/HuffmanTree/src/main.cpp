//
// Created by alei_go@163.com(: cyberdash_yuan) on 2020/11/1.
//

#include "huffman_tree.h"

int main() {
    string keys[] = { "蔡徐坤", "王一博", "肖战", "李现", "邓超" };
	double weights[] = { 25, 4, 10, 5.373, 1.2 };
    int size = 5;

	HuffmanTree<string, double> huffman_tree(keys, weights, size);

    huffman_tree.PrintTree();

    unordered_map<string, string> huffman_codes = huffman_tree.GetHuffmanCodes();

    for (unordered_map<string, string>::iterator iter = huffman_codes.begin(); iter != huffman_codes.end(); iter++) {
        cout << iter->first << ": " << iter->second << endl;
    }

	return 0;
}
