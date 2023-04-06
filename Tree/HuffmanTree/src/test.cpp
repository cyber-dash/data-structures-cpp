/*!
 * @file test.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 哈夫曼树测试.cpp文件
 * @version 0.2.1
 * @date 2023-04-03
 */

#include "test.h"
#include "huffman_tree.h"


/*!
 * @brief **测试-哈夫曼编码**
 * @note
 * 测试-哈夫曼编码
 * ------------
 * ------------
 *
 * ------------
 * + **1 构造哈夫曼树**\n
 * 使用数据
 * ```
 * Beijing: 25,
 * Shanghai: 4,
 * Guangzhou: 10,
 * Shenzhen: 5.373,
 * Chengdu: 1.2,
 * ```
 * 创建哈夫曼树\n
 * 打印哈夫曼树\n\n
 * + **2 进行哈夫曼编码**\n
 * 调用GetHuffmanCodes, 进行哈夫曼编码\n
 * 打印哈夫曼编码结果\n
 */
void TestHuffmanCode() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                      Test HuffmanCode                     |" << endl;
    cout << "|                        测试哈夫曼编码                       |" << endl;

    // ---------- 1 构造哈夫曼树 ----------

    string keys[] = { "Beijing", "Shanghai", "Guangzhou", "Shenzhen", "Chengdu" };
    double weights[] = { 25, 4, 10, 5.373, 1.2 };
    int size = 5;

    // 创建哈夫曼树
    HuffmanTree<string, double> huffman_tree(keys, weights, size);

    // 打印哈夫曼树
    huffman_tree.PrintTree();

    // ---------- 2 进行哈夫曼编码 ----------

    // 调用GetHuffmanCodes, 进行哈夫曼编码
    unordered_map<string, string> huffman_codes = huffman_tree.GetHuffmanCodes();

    // 打印哈夫曼编码结果
    for (unordered_map<string, string>::iterator iter = huffman_codes.begin(); iter != huffman_codes.end(); iter++) {
        cout << iter->first << ": " << iter->second << endl;
    }

    cout << "------------------------- CyberDash -------------------------" << endl;
}
