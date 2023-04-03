/*!
 * @file test.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 哈夫曼树测试.cpp文件
 * @version 0.2.1
 * @date 2023-04-03
 */

#include "test.h"
#include "huffman_tree.h"


void TestHuffmanCode() {


    string keys[] = { "a", "b", "c", "d", "e" };
    double weights[] = { 25, 4, 10, 5.373, 1.2 };
    int size = 5;

    HuffmanTree<string, double> huffman_tree(keys, weights, size);

    huffman_tree.PrintTree();

    unordered_map<string, string> huffman_codes = huffman_tree.GetHuffmanCodes();

    for (unordered_map<string, string>::iterator iter = huffman_codes.begin(); iter != huffman_codes.end(); iter++) {
        cout << iter->first << ": " << iter->second << endl;
    }
}
