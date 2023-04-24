/*!
 * @file huffman_tree.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 哈夫曼树模板类文件
 * @version 0.2.1
 * @date 2023-04-03
 */


#ifndef CYBER_DASH_HUFFMAN_TREE_H
#define CYBER_DASH_HUFFMAN_TREE_H


#include <iostream>
#include <queue>
#include <unordered_map>


using namespace std;


/*!
 * @brief **哈夫曼树结点模板结构体**
 * @tparam TKey 关键字类型模板参数
 * @tparam TWeight 权值类型模板参数
 */
template<typename TKey, typename TWeight>
struct HuffmanTreeNode {
    /*! @brief **默认构造函数** */
    HuffmanTreeNode(): key(TKey()), weight(TWeight()), left_child(NULL), right_child(NULL), parent(NULL) {}

    /*! @brief **构造函数(关键字, 权值, 左孩子, 右孩子和父节点)** */
    HuffmanTreeNode(TKey key, TWeight weight, HuffmanTreeNode* left = NULL, HuffmanTreeNode* right = NULL, HuffmanTreeNode* parent = NULL)
        : key(key), weight(weight), left_child(left), right_child(right), parent(parent) {}

    TKey key;                       //!< **关键字**
    TWeight weight;                 //!< **权值**
    HuffmanTreeNode* left_child;    //!< **左孩子**
    HuffmanTreeNode* right_child;   //!< **右孩子**
    HuffmanTreeNode* parent;        //!< **父结点**
};


template<typename TKey, typename TWeight>
struct Compare {
    bool operator()(HuffmanTreeNode<TKey, TWeight>* node1, HuffmanTreeNode<TKey, TWeight>* node2) {
        return node1->weight > node2->weight;
    }
};


/*!
 * @brief **哈夫曼树模板类**
 * @tparam TKey 关键字类型模板参数
 * @tparam TWeight 权值类型模板参数
 */
template <typename TKey, typename TWeight>
class HuffmanTree {
public:
    // 构造函数
	HuffmanTree(const TKey keys[], const TWeight weights[], int count);

    /*!
     * @brief **析构函数**
     * @note
     * 析构函数
     * -------
     * -------
     *
     * -------
     * 对root_调用ClearSubTreeRecursive_\n
     * root_置NULL\n
     */
	~HuffmanTree() {
        ClearSubTreeRecursive_(root_);
        root_ = NULL;
    }

    unordered_map<TKey, string> GenerateHuffmanCodes();

    /*!
     * @brief **打印**
     * @note
     * 打印
     * ----
     * ----
     *
     * ----
     * 对root_调用PrintSubTreeRecursive_\n
     * 换行\n
     */
	void PrintTree() { PrintSubTreeRecursive_(root_); cout << endl; }

protected:
	HuffmanTreeNode<TKey, TWeight>* root_;  //!< **根结点**

    // 子树清空(递归)
	void ClearSubTreeRecursive_(HuffmanTreeNode<TKey, TWeight>* subtree_root);
    // 合并子树
	void MergeSubTree_(HuffmanTreeNode<TKey, TWeight>* subtree_root_1,
                       HuffmanTreeNode<TKey, TWeight>* subtree_root_2,
                       HuffmanTreeNode<TKey, TWeight>*& new_subtree_root);
    // 打印子树(递归)
	void PrintSubTreeRecursive_(HuffmanTreeNode<TKey, TWeight>* subtree_root);
    // 子树生成哈夫曼编码
    void GenerateHuffmanCodeOfSubTreeRecursive_(HuffmanTreeNode<TKey, TWeight>* node,
                                                const string& current_prefix_code,
                                                unordered_map<TKey, string>& huffman_codes);
};


/*!
 * @brief **构造函数**
 * @tparam TKey 关键字类型模板参数
 * @tparam TWeight 权值类型模板参数
 * @param keys 关键字数组
 * @param weights 权值数组
 * @param count 关键字数量
 * @note
 * 构造函数
 * -------
 * -------
 *
 * -------
 * + **1 初始化最小优先队列**\n
 * 声明min_priority_queue(最小优先队列)\n\n
 * **for loop** 遍历关键字数组和权值数组 :\n
 * &emsp; node(哈夫曼树结点)分配内存并初始化\n
 * &emsp; node入队min_priority_queue\n\n
 * + **2 使用最小优先队列构造哈夫曼树**\n
 * 初始化cur_parent为NULL\n\n
 * **for loop** 遍历count - 1次 :\n
 * &emsp; min_priority_queue队头, 赋值给first\n
 * &emsp; 队头出队\n
 * &emsp; min_priority_queue队头, 赋值给second\n
 * &emsp; 队头出队\n\n
 * &emsp; 使用first和second建子树, 该子树根结点为cur_parent\n
 * &emsp; cur_parent入队min_priority_queue\n\n
 * cur_parent赋值root_\n
 */
template <typename TKey, typename TWeight>
HuffmanTree<TKey, TWeight>::HuffmanTree(const TKey* keys, const TWeight* weights, int count) {

    // ---------- 1 初始化最小优先队列 ----------

    // 声明min_priority_queue(最小优先队列)
    std::priority_queue<HuffmanTreeNode<TKey, TWeight>*, vector<HuffmanTreeNode<TKey, TWeight>*>, Compare<TKey, TWeight> > min_priority_queue;

    for (int i = 0; i < count; i++) {                                           // for loop 遍历关键字数组和权值数组
        // node(哈夫曼树结点)分配内存并初始化
        HuffmanTreeNode<TKey, TWeight>* node = new HuffmanTreeNode<TKey, TWeight>(keys[i], weights[i], NULL, NULL, NULL);

        // node入队min_priority_queue
        min_priority_queue.push(node);
    }

    // ---------- 2 使用最小优先队列构造哈夫曼树 ----------

    HuffmanTreeNode<TKey, TWeight>* cur_parent = NULL;                          // 初始化cur_parent为NULL
    for (int i = 0; i < count - 1; i++) {                                       // for loop 遍历count - 1次

        HuffmanTreeNode<TKey, TWeight>* first = min_priority_queue.top();       // min_priority_queue队头, 赋值给first
        min_priority_queue.pop();                                               // 队头出队

        HuffmanTreeNode<TKey, TWeight>* second = min_priority_queue.top();      // min_priority_queue队头, 赋值给second
        min_priority_queue.pop();                                               // 队头出队

        MergeSubTree_(first, second, cur_parent);                               // 使用first和second建子树, 该子树根结点为cur_parent
        min_priority_queue.push(cur_parent);                                    // cur_parent入队min_priority_queue
    }

    root_ = cur_parent;                                                         // cur_parent赋值root_
}


/*!
 * @brief **子树清空(递归)**
 * @tparam TKey 关键字类型模板参数
 * @tparam TWeight 权值类型模板参数
 * @param subtree_root 子树根结点
 * @note
 * 子树清空(递归)
 * ------------
 * ------------
 *
 * ------------
 * + **1 空树处理**\n
 * **if** 空树 :\n
 * &emsp; 退出函数\n\n
 * + **2 递归**\n
 * 对左孩子调用ClearSubTreeRecursive_\n
 * 对右孩子调用ClearSubTreeRecursive_\n\n
 * + **3 释放根结点**\n
 * delete subtree_root\n
 * subtree_root置空\n
 */
template <typename TKey, typename TWeight>
void HuffmanTree<TKey, TWeight>::ClearSubTreeRecursive_(HuffmanTreeNode<TKey, TWeight>* subtree_root) {

    // ---------- 1 空树处理 ----------

    if (subtree_root == NULL) {                                         // if 空树
        return;                                                         // 退出函数
    }

    // ---------- 2 递归 ----------

    ClearSubTreeRecursive_(subtree_root->left_child);     // 对左孩子调用ClearSubTreeRecursive_
    ClearSubTreeRecursive_(subtree_root->right_child);    // 对右孩子调用ClearSubTreeRecursive_

    // ---------- 3 释放根结点 ----------

    delete subtree_root;                                                // delete subtree_root
    subtree_root = NULL;                                                // subtree_root置空
}


/*!
 * @brief **合并子树**
 * @tparam TKey 关键字类型模板参数
 * @tparam TWeight 权值类型模板参数
 * @param subtree_root_1 子树根结点1
 * @param subtree_root_2 子树根结点2
 * @param new_subtree_root 新子树根结点
 * @note
 * 合并子树
 * -------
 * -------
 *
 * -------
 * 构造新子树根结点\n\n
 * 两个子树根结点的parent指向新子树根结点\n
 *
 */
template <typename TKey, typename TWeight>
void HuffmanTree<TKey, TWeight>::MergeSubTree_(HuffmanTreeNode<TKey, TWeight>* subtree_root_1,
                                               HuffmanTreeNode<TKey, TWeight>* subtree_root_2,
                                               HuffmanTreeNode<TKey, TWeight>*& new_subtree_root)
{
    // 构造新子树根结点
    TKey key;
    new_subtree_root = new HuffmanTreeNode<TKey, TWeight>(key,
                                                          subtree_root_1->weight + subtree_root_2->weight,
                                                          subtree_root_1,
                                                          subtree_root_2,
                                                          NULL);

    // 两个子树根结点的parent指向新子树根结点
    subtree_root_1->parent = new_subtree_root;
    subtree_root_2->parent = new_subtree_root;
}


/*!
 * @brief **打印子树(递归)**
 * @tparam TKey 关键字类型模板参数
 * @tparam TWeight 权值类型模板参数
 * @param subtree_root 子树根结点
 * @note
 * 打印子树(递归)
 * ------------
 * ------------
 *
 * ------------
 * + **1 空树处理**\n
 * **if** 空树 :\n
 * &emsp; 退出函数\n\n
 * + **2 递归**\n
 * 打印子树根结点的weight\n
 * 打印'('\n
 * 对左子树调用PrintSubTreeRecursive_\n
 * 打印','\n
 * 对右子树调用PrintSubTreeRecursive_\n
 * 打印')'\n
 */
template <typename TKey, typename TWeight>
void HuffmanTree<TKey, TWeight>::PrintSubTreeRecursive_(HuffmanTreeNode<TKey, TWeight>* subtree_root) {
    if (subtree_root == NULL) {
        return;
    }

    cout << subtree_root->weight;
    cout << '(';
    PrintSubTreeRecursive_(subtree_root->left_child);
    cout << ',';
    PrintSubTreeRecursive_(subtree_root->right_child);
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
 * 对根结点, 调用GetHuffmanCodeOfSubTree_, 前缀码以""作为起始
 * </span>
 *
 * ------------
 * 声明huffman_codes\n
 * 调用GetHuffmanCodeOfSubTree_, 生成哈夫曼编码\n
 * 返回huffman_codes\n
 */
template <typename TKey, typename TWeight>
unordered_map<TKey, string> HuffmanTree<TKey, TWeight>::GenerateHuffmanCodes() {
    unordered_map<TKey, string> huffman_codes;  // 声明huffman_codes

    string current_prefix_code;
    // 调用GenerateHuffmanCodeOfSubTreeRecursive_, 生成哈夫曼编码
    GenerateHuffmanCodeOfSubTreeRecursive_(root_, current_prefix_code, huffman_codes);

    return huffman_codes;                       // 返回huffman_codes
}


/*!
 * @brief **子树生成哈夫曼编码**
 * @tparam TKey 关键字类型模板参数
 * @tparam TWeight 权值类型模板参数
 * @param node 结点
 * @param current_prefix_code 当前前缀码
 * @param huffman_codes 哈夫曼编码
 * @note
 * 子树生成哈夫曼编码
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 空结点处理**\n
 * **if** node == NULL :\n
 * &emsp; 退出函数\n\n
 * + **2 叶子结点处理**\n
 * **if** node为叶子结点 :\n
 * &emsp; current_prefix_code即为node->key对应的哈夫曼编码\n
 * &emsp; 退出函数\n\n
 * + **3 非叶子结点处理**\n
 * current_prefix_code扩展0, 向左子树递归执行GenerateHuffmanCodeOfSubTreeRecursive_\n
 * current_prefix_code扩展1, 向右子树递归执行GenerateHuffmanCodeOfSubTreeRecursive_\n
 */
template <typename TKey, typename TWeight>
void HuffmanTree<TKey, TWeight>::GenerateHuffmanCodeOfSubTreeRecursive_(HuffmanTreeNode<TKey, TWeight>* node,
                                                                        const string& current_prefix_code,
                                                                        unordered_map<TKey, string>& huffman_codes)
{
    // ---------- 1 空结点处理 ----------

    if (node == NULL) {                                             // if node == NULL
        return;                                                     // 退出函数
    }

    // ---------- 2 叶子结点处理 ----------

    if (node->left_child == NULL && node->right_child == NULL) {    // if node为叶子结点
        huffman_codes[node->key] = current_prefix_code;             // current_prefix_code即为node->key的哈夫曼编码
        return;                                                     // 退出函数
    }

    // ---------- 3 非叶子结点处理 ----------

    // current_prefix_code扩展0
    string str_zero("0");
    // 向左子树递归执行GenerateHuffmanCodeOfSubTreeRecursive_
    GenerateHuffmanCodeOfSubTreeRecursive_(node->left_child, current_prefix_code + str_zero, huffman_codes);

    // current_prefix_code扩展1
    string str_one("1");
    // 向右子树递归执行GenerateHuffmanCodeOfSubTreeRecursive_
    GenerateHuffmanCodeOfSubTreeRecursive_(node->right_child, current_prefix_code + str_one, huffman_codes);
}


#endif // CYBER_DASH_HUFFMAN_TREE_H
