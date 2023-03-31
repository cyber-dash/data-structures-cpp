//
// Created by alei_go@163.com(: cyberdash_yuan) on 2020/11/1.
//

#ifndef CYBER_DASH_HUFFMAN_TREE_H
#define CYBER_DASH_HUFFMAN_TREE_H


#include <iostream>
#include <queue>
#include <unordered_map>


using namespace std;


/*!
 * @brief **哈夫曼树结点模板结构体**
 * @tparam TKey
 * @tparam TWeight
 */
template<typename TKey, typename TWeight>
struct HuffmanTreeNode {
    HuffmanTreeNode(): key(TKey()), weight(TWeight()), left_child(NULL), right_child(NULL), parent(NULL) {}

    HuffmanTreeNode(TKey key, TWeight weight, HuffmanTreeNode* left = NULL, HuffmanTreeNode* right = NULL, HuffmanTreeNode* parent = NULL)
        : key(key), weight(weight), left_child(left), right_child(right), parent(parent) {}

    TKey key;
    TWeight weight;
    HuffmanTreeNode* left_child;
    HuffmanTreeNode* right_child;
    HuffmanTreeNode* parent;
};


template<typename TKey, typename TWeight>
bool operator<(const HuffmanTreeNode<TKey, TWeight>& node1, const HuffmanTreeNode<TKey, TWeight>& node2) {
    return node1.weight > node2.weight;
}


template <typename TKey, typename TWeight>
class HuffmanTree {
public:
	HuffmanTree(const TKey keys[], const TWeight weights[], int count);
	~HuffmanTree() { ClearSubTree(root_); }

    unordered_map<TKey, string> GetHuffmanCodes();

	void PrintTree() { PrintSubTree_(root_); cout << endl; }

protected:
	HuffmanTreeNode<TKey, TWeight>* root_;

	void ClearSubTree(HuffmanTreeNode<TKey, TWeight>* subtree_root);
	void MergeTree_(HuffmanTreeNode<TKey, TWeight>* subtree_root_1,
                    HuffmanTreeNode<TKey, TWeight>* subtree_root_2,
                    HuffmanTreeNode<TKey, TWeight>*& new_subtree_root);
	void PrintSubTree_(HuffmanTreeNode<TKey, TWeight>* subtree_root);
    void GetHuffmanCodeOfSubTree_(HuffmanTreeNode<TKey, TWeight>* node,
                                  const string& code,
                                  unordered_map<TKey, string>& huffman_codes);
};


template <typename TKey, typename TWeight>
HuffmanTree<TKey, TWeight>::HuffmanTree(const TKey* keys, const TWeight* weights, int count) {

    std::priority_queue<HuffmanTreeNode<TKey, TWeight> > min_priority_queue;

    for (int i = 0; i < count; i++) {
        HuffmanTreeNode<TKey, TWeight>* node = new HuffmanTreeNode<TKey, TWeight>(keys[i], weights[i], NULL, NULL, NULL);
        node->parent = node;

        min_priority_queue.push(*node);
    }

    HuffmanTreeNode<TKey, TWeight>* parent = NULL;
    for (int i = 0; i < count - 1; i++) {

        HuffmanTreeNode<TKey, TWeight> node = min_priority_queue.top();
        min_priority_queue.pop();
        HuffmanTreeNode<TKey, TWeight>* first = node.parent;

        node = min_priority_queue.top();
        min_priority_queue.pop();
        HuffmanTreeNode<TKey, TWeight>* second = node.parent;

        MergeTree_(first, second, parent);
        min_priority_queue.push(*parent);
    }

    root_ = parent;
}


template <typename TKey, typename TWeight>
void HuffmanTree<TKey, TWeight>::ClearSubTree(HuffmanTreeNode<TKey, TWeight>* subtree_root) {
    if (subtree_root == NULL) {
        return;
    }

    ClearSubTree(subtree_root->left_child);
    ClearSubTree(subtree_root->right_child);

    delete subtree_root;
}


template <typename TKey, typename TWeight>
void HuffmanTree<TKey, TWeight>::MergeTree_(HuffmanTreeNode<TKey, TWeight>* subtree_root_1,
                                            HuffmanTreeNode<TKey, TWeight>* subtree_root_2,
                                            HuffmanTreeNode<TKey, TWeight>*& new_subtree_root)
{
    TKey key;
    new_subtree_root = new HuffmanTreeNode<TKey, TWeight>(key,
                                                          subtree_root_1->weight + subtree_root_2->weight,
                                                          subtree_root_1,
                                                          subtree_root_2,
                                                          NULL);

    new_subtree_root->parent = new_subtree_root;

    subtree_root_1->parent = new_subtree_root;
    subtree_root_2->parent = new_subtree_root;
}


template <typename TKey, typename TWeight>
void HuffmanTree<TKey, TWeight>::PrintSubTree_(HuffmanTreeNode<TKey, TWeight>* subtree_root) {
    if (subtree_root == NULL) {
        return;
    }

    cout << subtree_root->weight;
    cout << '(';
    PrintSubTree_(subtree_root->left_child);
    cout << ',';
    PrintSubTree_(subtree_root->right_child);
    cout << ')';
}


/*!
 * @brief **生成哈夫曼编码**
 * @tparam TKey 关键字类型模板参数
 * @tparam TWeight 权值类型模板参数
 * @return 哈夫曼编码
 * @note
 * 生成哈夫曼编码
 * ------------
 * ------------
 *
 * <span style="color:#D40000;font-size:larger">
 * 对根结点, 调用GetHuffmanCodeOfSubTree_, 编码以""作为起始
 * </span>
 *
 * ------------
 * 声明huffman_codes\n
 * 调用GetHuffmanCodeOfSubTree_\n
 * 返回huffman_codes\n
 */
template <typename TKey, typename TWeight>
unordered_map<TKey, string> HuffmanTree<TKey, TWeight>::GetHuffmanCodes() {
    unordered_map<TKey, string> huffman_codes;

    GetHuffmanCodeOfSubTree_(root_, "", huffman_codes);

    return huffman_codes;
}


template <typename TKey, typename TWeight>
void HuffmanTree<TKey, TWeight>::GetHuffmanCodeOfSubTree_(HuffmanTreeNode<TKey, TWeight>* node,
                                                          const string& code,
                                                          unordered_map<TKey, string>& huffman_codes)
{
    if (node == NULL) {
        return;
    }

    if (node->left_child == NULL && node->right_child == NULL) {
        huffman_codes[node->key] = code;
        return;
    }

    string str_zero("0");
    GetHuffmanCodeOfSubTree_(node->left_child, code + str_zero, huffman_codes);

    string str_one("1");
    GetHuffmanCodeOfSubTree_(node->right_child, code + str_one, huffman_codes);
}


#endif //CYBER_DASH_HUFFMAN_TREE_H
