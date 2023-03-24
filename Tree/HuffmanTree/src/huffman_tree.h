//
// Created by alei_go@163.com(: cyberdash_yuan) on 2020/11/1.
//

#ifndef CYBER_DASH_HUFFMAN_TREE_H
#define CYBER_DASH_HUFFMAN_TREE_H


#include <iostream>
#include <queue>
#include <unordered_map>


using namespace std;


template<typename TKey, typename TWeight>
struct HuffmanTreeNode {
    HuffmanTreeNode(): key(TKey()), weight(TWeight()), left_child(NULL), right_child(NULL), parent(NULL) {}

    HuffmanTreeNode(TKey key, TWeight weight, HuffmanTreeNode* left = NULL, HuffmanTreeNode* right = NULL, HuffmanTreeNode* parent = NULL)
        : key(key), weight(weight), left_child(left), right_child(right), parent(parent) {}

    bool operator<=(const HuffmanTreeNode& node) { return weight <= node.weight; }
    bool operator>(const HuffmanTreeNode& node) { return weight > node.weight; }

    TKey key;
    TWeight weight;
    HuffmanTreeNode* left_child;
    HuffmanTreeNode* right_child;
    HuffmanTreeNode* parent;
};


template<typename TKey, typename TWeight>
bool operator < (const HuffmanTreeNode<TKey, TWeight>& node1, const HuffmanTreeNode<TKey, TWeight>& node2) {
    return node1.weight > node2.weight;
}


template <typename TKey, typename TWeight>
class HuffmanTree {
public:
	HuffmanTree(const TKey keys[], const TWeight weights[], int n);
	~HuffmanTree() { ClearSubTree(root_); }

    unordered_map<TKey, string> GetHuffmanCode();

	void PrintTree() { PrintSubTree_(root_); }

protected:
	HuffmanTreeNode<TKey, TWeight>* root_;
	void ClearSubTree(HuffmanTreeNode<TKey, TWeight>* t);
	void MergeTree_(HuffmanTreeNode<TKey, TWeight>* ht1, HuffmanTreeNode<TKey, TWeight>* ht2, HuffmanTreeNode<TKey, TWeight>*& parent);
	void PrintSubTree_(HuffmanTreeNode<TKey, TWeight>* t);
    void GetHuffmanCodeOfSubTree_(HuffmanTreeNode<TKey, TWeight>* node,
                                  string code,
                                  unordered_map<TKey, string>& huffmanCodes);
};


template <typename TKey, typename TWeight>
HuffmanTree<TKey, TWeight>::HuffmanTree(const TKey* keys, const TWeight* weights, int n) {

    std::priority_queue<HuffmanTreeNode<TKey, TWeight> > min_queue;

    for (int i = 0; i < n; i++) {
        HuffmanTreeNode<TKey, TWeight>* work = new HuffmanTreeNode<TKey, TWeight>(keys[i], weights[i], NULL, NULL, NULL);
        work->parent = work;

        min_queue.push(*work);
    }

    HuffmanTreeNode<TKey, TWeight>* parent = NULL;
    for (int i = 0; i < n - 1; i++) {

        HuffmanTreeNode<TKey, TWeight> temp = min_queue.top();
        min_queue.pop();
        HuffmanTreeNode<TKey, TWeight>* first = temp.parent;

        temp = min_queue.top();
        min_queue.pop();
        HuffmanTreeNode<TKey, TWeight>* second = temp.parent;

        MergeTree_(first, second, parent);
        min_queue.push(*parent);
    }

    root_ = parent;
}


template <typename TKey, typename TWeight>
void HuffmanTree<TKey, TWeight>::ClearSubTree(HuffmanTreeNode<TKey, TWeight>* t) {
    if (t == NULL) {
        return;
    }

    ClearSubTree(t->left_child);
    ClearSubTree(t->right_child);

    delete t;
}


template <typename TKey, typename TWeight>
void HuffmanTree<TKey, TWeight>::MergeTree_(HuffmanTreeNode<TKey, TWeight>* ht1,
                                            HuffmanTreeNode<TKey, TWeight>* ht2,
                                            HuffmanTreeNode<TKey, TWeight>*& parent)
{
    TKey key(NULL);
    parent = new HuffmanTreeNode<TKey, TWeight>(key, ht1->weight + ht2->weight, ht1, ht2, NULL);

    parent->parent = parent;

    ht1->parent = ht2->parent = parent;
}


template <typename TKey, typename TWeight>
void HuffmanTree<TKey, TWeight>::PrintSubTree_(HuffmanTreeNode<TKey, TWeight>* t) {
    if (t == NULL) {
        return;
    }

    cout << t->weight;
    cout << '(';
    PrintSubTree_(t->left_child);
    cout << ',';
    PrintSubTree_(t->right_child);
    cout << ')';
}


template <typename TKey, typename TWeight>
unordered_map<TKey, string> HuffmanTree<TKey, TWeight>::GetHuffmanCode() {
    unordered_map<TKey, string> huffmanCodes;

    // TKey key(NULL);
    // GetHuffmanCodeOfSubTree_(root_, "", huffmanCodes);
    GetHuffmanCodeOfSubTree_(root_, "", huffmanCodes);

    return huffmanCodes;
}


template <typename TKey, typename TWeight>
void HuffmanTree<TKey, TWeight>::GetHuffmanCodeOfSubTree_(HuffmanTreeNode<TKey, TWeight>* node,
                                                          string code,
                                                          unordered_map<TKey, string>& huffmanCodes)
{
    if (node == NULL) {
        return;
    }

    if (node->left_child == NULL && node->right_child == NULL) {
        huffmanCodes[node->key] = code;
        return;
    }

    string a("0");
    // GetHuffmanCodeOfSubTree_(node->left_child, code + "0", huffmanCodes);
    GetHuffmanCodeOfSubTree_(node->left_child, code + a, huffmanCodes);

    string b("1");
    // GetHuffmanCodeOfSubTree_(node->right_child, code + "1", huffmanCodes);
    GetHuffmanCodeOfSubTree_(node->right_child, code + b, huffmanCodes);
}


#endif //CYBER_DASH_HUFFMAN_TREE_H
