/*!
 * @file binary_search_tree.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 二叉搜索树结点模板类与二叉搜索树模板类
 * @version 0.2.1
 * @date 2023-02-22
 */

#ifndef CYBER_DASH_BINARY_SEARCH_TREE_H
#define CYBER_DASH_BINARY_SEARCH_TREE_H


#include <iostream>
#include <cstdlib>


using namespace std;


/*!
 * @brief **二叉搜索树结点模板类**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 */
template <typename TKey, typename TValue>
class BstNode {
public:
    /*!
     * @brief **默认构造函数**
     * @note
     * 默认构造函数
     * ----------
     * ----------
     *
     * ----------
     * 设置左孩子为NULL, 右孩子为NULL
     */
    BstNode(): left_child_(NULL), right_child_(NULL) {}

    /*!
     * @brief **构造函数(关键字/值)**
     * @param key 关键字
     * @param value 值
     * @note
     * 构造函数(关键字/值)
     * -----------------
     * -----------------
     *
     * -----------------
     * 设置key_, value_, 左孩子为NULL, 右孩子为NULL
     */
    BstNode(TKey key, TValue value): value_(value), key_(key), left_child_(NULL), right_child_(NULL) {}

    /*!
     * @brief **构造函数(关键字/值/左孩子/右孩子)**
     * @param key 关键字
     * @param value 值
     * @param left_child 左孩子
     * @param right_child 右孩子
     * @note
     * 构造函数(关键字/值/左孩子/右孩子)
     * -----------------------------
     * -----------------------------
     *
     * -----------------------------
     * 设置key_, value_, 左孩子, 右孩子
     */
    BstNode(TKey key, TValue value, BstNode<TKey, TValue>* left_child, BstNode<TKey, TValue>* right_child):
        value_(value), key_(key), left_child_(left_child), right_child_(right_child) {}

    /*!
     * @brief **获取左孩子**
     * @return 左孩子
     */
    BstNode<TKey, TValue>*& LeftChild() { return this->left_child_; };
    /*!
     * @brief **设置左孩子**
     * @param node 结点
     */
    void SetLeftChild(BstNode<TKey, TValue>* node) { this->left_child_ = node; }

    /*!
     * @brief **获取右孩子**
     * @return 右孩子
     */
    BstNode<TKey, TValue>*& RightChild() { return this->right_child_; };
    /*!
     * @brief **设置右孩子**
     * @param node 结点
     */
    void SetRightChild(BstNode<TKey, TValue>* node) { this->right_child_ = node; }

    /*!
     * @brief **获取关键字**
     * @return 关键字
     */
    virtual TKey Key() { return this->key_; }
    /*!
     * @brief **设置关键字**
     * @param key 关键字
     */
    virtual void SetKey(const TKey& key) { this->key_ = key; }

    /*!
     * @brief **获取值**
     * @return 值
     */
    virtual TValue Value() { return this->value_; }
    /*!
     * @brief **设置值**
     * @param value 值
     */
    virtual void SetValue(const TValue& value) { this->value_ = value; }

protected:

    BstNode<TKey, TValue>* left_child_;    //!< 左孩子(指针)
    BstNode<TKey, TValue>* right_child_;   //!< 右孩子(指针)

    TKey key_;                             //!< 关键字
    TValue value_;                         //!< 值
};


/*!
 * @brief **二叉搜索树**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 */
template <typename TKey, typename TValue>
class BinarySearchTree {
public:
    /*!
     * @brief **默认构造函数**
     * @note
     * 默认构造函数
     * ----------
     * ----------
     *
     * ----------
     * 根结点为NULL
     */
    BinarySearchTree() : root_(NULL) {}

    /*!
     * @brief **构造函数(关键字/值)**
     * @param key 关键字
     * @param value 值
     * @note
     * 构造函数(关键字/值)
     * ----------------
     * ----------------
     *
     * ----------------
     * 调用Insert, 构造只有一个结点的二叉搜索树
     */
    BinarySearchTree(TKey key, TValue value) { this->InsertRecursive(key, value); }

    /*!
     * @brief **析构函数**
     * @note
     * 析构函数
     * -------
     * -------
     *
     * -------
     * 释放root_
     */
    virtual ~BinarySearchTree() { delete this->root_; };

    /*!
     * @brief **插入结点(递归)**
     * @tparam TKey 关键字类型模板参数
     * @tparam TValue 值类型模板参数
     * @param key 关键字
     * @param value 值
     * @return 执行结果
     * @note
     * 插入结点
     * -------
     * -------
     *
     * -------
     * 调用InsertInSubTree_
     */
    virtual bool InsertRecursive(TKey key, TValue value) { return this->InsertInSubTree_(key, value, this->root_); }

    /*!
     * @brief **删除结点**
     * @param key 关键字
     * @return 执行结果
     * @note
     * 删除结点
     * -------
     * -------
     *
     * -------
     * 对root_调用RemoveInSubTree_
     */
    virtual bool RemoveRecursive(const TKey& key) { return RemoveInSubTree_(root_, key); }

    /*!
     * @brief **搜索**
     * @param key 关键字
     * @return 结点
     * @note
     * 搜索
     * ---
     * ---
     *
     * ---
     * 对根结点调用SearchInSubTree_
     */
    virtual BstNode<TKey, TValue>* Search(TKey key) { return SearchInSubTree_(this->root_, key); }

    /*!
     * @brief **获取高度**
     * @return 高度
     * @note
     * 获取高度
     * -------
     * -------
     *
     * -------
     * 对根结点调用HeightOfSubtreeRecursive_
     */
    virtual int Height() { return this->HeightOfSubtreeRecursive_(this->root_); }

    // 获取最小关键字对应的值
    virtual bool Min(TValue& min_value);
    // 获取最大关键字对应的值
    virtual bool Max(TValue& max_value);

    /*!
     * @brief **获取根结点**
     * @return 根结点
     */
    BstNode<TKey, TValue>*& Root() { return this->root_; }

    /*!
     * @brief **清除结点**
     * @note
     * 清除结点
     * -------
     * -------
     *
     * -------
     * 对根结点调用ClearSubTree_
     */
    virtual void Clear() { ClearSubTree_(root_); }

    /*!
     * @brief **打印(中序)**
     * @param NodePrint 结点打印函数
     * @note
     * 打印(中序)
     * --------
     * --------
     *
     * --------
     * 对根结点调用PrintSubTree_
     */
    void Print(void (*NodePrint)(BstNode<TKey, TValue>*)) { this->PrintSubTreeRecursive_(this->root_, NodePrint); }

    // 重载=
    BinarySearchTree<TKey, TValue>& operator=(const BinarySearchTree<TKey, TValue>& src_bst);

protected:
    // 子树插入节点(递归)
    bool InsertInSubTree_(TKey key, TValue value, BstNode<TKey, TValue>*& subtree_root);

    // 子树删除节点(递归)
    bool RemoveInSubTree_(BstNode<TKey, TValue>*& subtree_root, TKey key);

    // 子树搜索(递归)
    BstNode<TKey, TValue>* SearchInSubTree_(BstNode<TKey, TValue>* subtree_root, TKey key);

    // 子树高度
    int HeightOfSubtreeRecursive_(BstNode<TKey, TValue>* subtree_root);

    // 子树清除(递归)
    void ClearSubTree_(BstNode<TKey, TValue>*& subtree_root);

    // 子树打印(递归)
    void PrintSubTreeRecursive_(BstNode<TKey, TValue>* subtree_root,
                                void (*NodePrint)(BstNode<TKey, TValue>*)) const;

    // 子树复制(递归)
    BstNode<TKey, TValue>* CopySubTreeRecursive_(const BstNode<TKey, TValue>* src_bst_root);

    // 子树中关键码最小项
    BstNode<TKey, TValue>* MinInSubTree_(BstNode<TKey, TValue>* subtree_root) const;

    // 子树中关键码最大项
    BstNode<TKey, TValue>* MaxInSubTree_(BstNode<TKey, TValue>* subtree_root) const;

    // 获取结点的(中序)前一结点
    BstNode<TKey, TValue>* NextNode_(BstNode<TKey, TValue>* node);

    BstNode<TKey, TValue>* root_; //!< 根节点
};


/**
 * @brief **子树搜索(递归)**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 * @param subtree_root 子树根节点
 * @param key 搜索关键字
 * @return 搜索结果
 * @note
 * 子树搜索(递归)
 * --------------
 * --------------
 *
 * <span style="color:#FF9900">
 * 如果子树根节点为NULL, 返回NULL
 * </span>
 *
 * --------------
 * + **1 空子树处理**\n
 * &emsp; **if** 空子树 :\n
 * &emsp;&emsp; 返回NULL\n
 * + **2 分治递归**\n
 * &emsp; 获取subtree_root_key<b>(子树根节点关键字)</b>\n
 * &emsp; **if** 搜索关键字 < 子树根节点关键字 :\n
 * &emsp;&emsp; 对子树的左子树, 递归执行SearchInSubTree_, 返回结果\n
 * &emsp; **else if** 搜索关键字 > 子树根节点关键字 :\n
 * &emsp;&emsp; 对子树的右子树, 递归执行SearchInSubTree_, 返回结果\n
 * &emsp; 返回子树根节点(根结点既是对应的结点)\n
 */
template <typename TKey, typename TValue>
BstNode<TKey, TValue>* BinarySearchTree<TKey, TValue>::SearchInSubTree_(BstNode<TKey, TValue>* subtree_root, TKey key) {

    // ---------- 1 空子树处理 ----------

    if (subtree_root == NULL) {                                     // if 空子树
        return NULL;                                                // 返回NULL
    }

    // ---------- 2 分治递归 ----------

    TKey subtree_root_key = subtree_root->Key();                    // 获取subtree_root_key(子树根节点关键字)

    if (key < subtree_root_key) {                                   // if 搜索关键字 < 子树根节点关键字
        return SearchInSubTree_(subtree_root->LeftChild(), key);    // 对子树的左子树, 递归执行SearchInSubTree_, 返回结果
    } else if (key > subtree_root_key) {                            // else if 搜索关键字 > 子树根节点关键字
        return SearchInSubTree_(subtree_root->RightChild(), key);   // 对子树的右子树, 递归执行SearchInSubTree_, 返回结果
    }

    return subtree_root;                                            // 返回子树根结点(根结点既是对应的结点)
}



/*!
 * @brief **获取最小关键字对应的值**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 * @param min_value 值保存变量
 * @return 执行结果
 * @note
 * 获取最小关键字对应的值
 * -------------------
 * -------------------
 *
 * -------------------
 * 对根结点调用MinInSubTree_, 获取key最小的结点\n
 * **if** node为NULL :\n
 * &emsp; 返回false\n
 * node的value_赋给min_value\n
 * 返回true\n
 */
template<typename TKey, typename TValue>
bool BinarySearchTree<TKey, TValue>::Min(TValue& min_value) {
    // 对根结点调用MinInSubTree_, 获取key最小的结点
    BstNode<TKey, TValue>* node = this->MinInSubTree_(this->Root());
    if (!node) {                                                        // if node为NULL
        return false;                                                   // 返回false
    }

    min_value = node->Value();                                          // node的value_赋给min_value

    return true;                                                        // 返回true
}


/**
 * @brief **子树插入节点(递归)**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 * @param key 关键字
 * @param value 值
 * @param subtree_root 子树根结点
 * @return 执行结果
 * @note
 * 子树插入节点(递归)
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 空子树插入**\n
 * **if** 空子树 :\n
 * &emsp; 子树根结点分配内存\n
 * &emsp; **if** 内存分配失败 :\n
 * &emsp;&emsp; 抛出bad_alloc()\n
 * &emsp; 返回true(结束递归)\n
 * + **2 分治递归**\n
 * **if** key小于子树根结点key :\n
 * &emsp; 对根结点左孩子, 递归调用InsertInSubTree_, 返回结果\n
 * **if** key大于子树根结点key :\n
 * &emsp; 对根结点右孩子, 递归调用InsertInSubTree_, 返回结果\n
 * + **3 返回**\n
 * 返回false(递归失败, 重复插入)
 */
template <typename TKey, typename TValue>
bool BinarySearchTree<TKey, TValue>::InsertInSubTree_(TKey key,
                                                      TValue value,
                                                      BstNode<TKey, TValue>*& subtree_root)
{
    // ---------- 1 空子树插入 ----------

    if (subtree_root == NULL) {                                             // if 空子树
        subtree_root = new BstNode<TKey, TValue>(key, value);               // 子树根结点分配内存
        if (!subtree_root) {                                                // if 内存分配失败
            throw bad_alloc();                                              // 抛出bad_alloc()
        }

        return true;                                                        // 返回true(结束递归)
    }

    // ---------- 2 分治递归 ----------

    if (key < subtree_root->Key()) {                                        // if key小于子树根结点key
        return InsertInSubTree_(key, value, subtree_root->LeftChild());     // 对根结点左孩子, 递归调用InsertInSubTree_, 返回结果
    }

    if (key > subtree_root->Key()) {                                        // if key大于子树根结点key
        return InsertInSubTree_(key, value, subtree_root->RightChild());    // 对根结点右孩子, 递归调用InsertInSubTree_, 返回结果
    }

    // ---------- 3 返回 ----------

    return false;                                                           // 返回false(递归失败, 重复插入)
}




/**
 * @brief 子树删除结点(递归)
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 * @param subtree_root 子树根结点
 * @param key 待删除结点关键字
 * @return 执行结果
 * @note
 * 子树删除节点(递归)
 * ----------------
 * ----------------
 *
 * ----------------
 * + **1 空子树处理**\n
 * **if** 空子树 :\n
 * &emsp; 返回false\n
 * + **2 执行递归**\n
 * **if** 待删除结点在左子树 :\n
 * &emsp; 对LeftChild()递归调用RemoveInSubTree_, 并返回\n
 * **if** 待删除结点在右子树 :\n
 * &emsp; 对RightChild()递归调用RemoveInSubTree_, 并返回\n
 * (接下来处理待删除结点为子树根结点的情况)\n
 * **if** subtree_root同时存在左右孩子 :\n
 * &emsp; 初始化next_node, 指向根结点中序的下一个结点(在右子树内), 作为替换结点\n
 * &emsp; subtree_root的key_和value_设置成next_node的\n
 * &emsp; 在右子树中, 对next_node调用RemoveInSubTree_进行删除\n
 * **else** (subtree_root不存在) \n
 * &emsp; remove_node指向subtree_root\n
 * &emsp; **if** subtree_node左孩子为NULL :\n
 * &emsp;&emsp; subtree_node指向自身右孩子\n
 * &emsp; **else** (subtree_node存在左孩子) :\n
 * &emsp;&emsp; subtree_node指向自身左孩子\n
 * &emsp; 释放remove_node\n
 * &emsp; 返回true\n
 */
template <typename TKey, typename TValue>
bool BinarySearchTree<TKey, TValue>::RemoveInSubTree_(BstNode<TKey, TValue>*& subtree_root, TKey key) {

    // ---------- 1 空子树处理 ----------

    if (subtree_root == NULL) {                             // if 空子树
        return false;                                       // 返回false
    }

    // ---------- 2 执行递归 ----------

    if (key < subtree_root->Key()) {                        // if 待删除结点在左子树
        // 对LeftChild()递归调用RemoveInSubTree_, 并返回
        return RemoveInSubTree_(subtree_root->LeftChild(), key);
    }

    if (key > subtree_root->Key()) {                        // if 待删除结点在右子树
        // 对RightChild()递归调用RemoveInSubTree_, 并返回
        return RemoveInSubTree_(subtree_root->RightChild(), key);
    }

    // (接下来处理待删除结点为子树根结点的情况)

    // if subtree_root同时存在左右孩子
    if (subtree_root->LeftChild() != NULL && subtree_root->RightChild() != NULL) {
        // 初始化next_node, 指向根结点中序的下一个结点(在右子树内), 作为替换结点
        BstNode<TKey, TValue>* next_node = this->NextNode_(subtree_root);

        // subtree_root的key_和value_设置成next_node的
        subtree_root->SetValue(next_node->Value());
        subtree_root->SetKey(next_node->Key());

        // 在右子树中, 对next_node调用RemoveInSubTree_进行删除
        return RemoveInSubTree_(subtree_root->RightChild(), next_node->Key());
    } else {                                                // else (subtree_root不存在)
        BstNode<TKey, TValue>* remove_node = subtree_root;  // remove_node指向subtree_root

        if (subtree_root->LeftChild() == NULL) {            // if subtree_node左孩子为NULL
            subtree_root = subtree_root->RightChild();      // subtree_node指向自身右孩子
        } else {                                            // else (subtree_node存在左孩子)
            subtree_root = subtree_root->LeftChild();       // subtree_node指向自身左孩子
        }

        // 释放remove_node
        delete remove_node;
        remove_node = NULL;

        return true;                                        // 返回true
    }
}


/**
 * @brief **子树清除(递归)**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 * @param subtree_root 子树根结点指针
 * @note
 * 子树清除(递归)
 * ------------
 * ------------
 *
 * ------------
 * + **1 空树处理**\n
 * **if** 空子树 :\n
 * &emsp; 返回\n
 * + **2 分治递归**\n
 * 对左子树执行ClearSubTree_\n
 * 对右子树执行ClearSubTree_\n
 * + **3 释放根结点**\n
 */
template <typename TKey, typename TValue>
void BinarySearchTree<TKey, TValue>::ClearSubTree_(BstNode<TKey, TValue>*& subtree_root) {

    // ---------- 1 空树处理 ----------

    if (subtree_root == NULL) {                     // if 空子树
        return;                                     // 返回
    }

    // ---------- 2 分治递归 ----------

    ClearSubTree_(subtree_root->LeftChild());   // 对左子树执行ClearSubTree_
    ClearSubTree_(subtree_root->RightChild());  // 对右子树执行ClearSubTree_

    // ---------- 3 释放根结点 ----------

    delete subtree_root;
    subtree_root = NULL;
}


/**
 * @brief **子树打印(递归)**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值字类型模板参数
 * @param subtree_root 子树根结点
 * @param NodePrint 结点打印函数
 * @note
 * 子树打印(递归)
 * ------------
 * ------------
 *
 * <span style="color:#FF9900">
 * **分治递归**\n
 * </span>
 *
 * ------------
 * + **1 空树处理**\n
 * **if** 子树根结点为NULL :\n
 * &emsp; 返回\n
 * + **2 分治递归**\n
 * 打印结点\n
 * **if** 子树为叶子类型(没有左右孩子): \n
 * &emsp; 返回\n
 * 打印'('\n
 * 递归调用PrintSubTreeRecursive_, 对左子树进行打印\n
 * 打印','\n
 * 递归调用PrintSubTreeRecursive_, 对右子树进行打印\n
 * 打印')'\n
 */
template <typename TKey, typename TValue>
void BinarySearchTree<TKey, TValue>::PrintSubTreeRecursive_(BstNode<TKey, TValue>* subtree_root,
                                                            void (*NodePrint)(BstNode<TKey, TValue>*)) const
{
    // ---------- 1 空树处理 ----------

    if (subtree_root == NULL) {                                 // if 子树根结点为NULL
        return;                                                 // 返回
    }

    // ---------- 2 分治递归 ----------

    NodePrint(subtree_root);                                        // 打印结点

    // if 子树为叶子类型(没有左右孩子)
    if (subtree_root->LeftChild() == NULL && subtree_root->RightChild() == NULL) {
        return;                                                 // 返回
    }

    cout << "(";                                                // 打印'('

    PrintSubTreeRecursive_(subtree_root->LeftChild(), NodePrint);   // 递归调用PrintSubTreeRecursive_, 对左子树进行打印

    cout << ",";                                                // 打印','

    PrintSubTreeRecursive_(subtree_root->RightChild(), NodePrint);  // 递归调用PrintSubTreeRecursive_, 对右子树进行打印

    cout << ")";                                                // 打印')'
}


/**
 * @brief **子树复制**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 * @param src_bst_root 源子树根结点
 * @return 新树根节点
 * 子树复制
 * -------
 * -------
 *
 * <span style="color:#FF9900">
 * **分治递归**\n
 * </span>
 *
 * -------
 * + **1 源子树空树处理**\n
 * **if** 源子树为空树 :\n
 * &emsp; 返回NULL\n
 * + **2 生成新树根结点**\n
 * 声明new_bst_root(新二叉搜索树根结点), 并分配内存\n
 * **if** 内存分配失败 :\n
 * &emsp; 抛出bad_alloc()\n
 * + **3 左右子树分治递归复制**\n
 * 左子树递归调用CopySubTreeRecursive_, 生成新左子树\n
 * 右子树递归调用CopySubTreeRecursive_, 生成新右子树\n
 * + **4 返回新树根结点**\n
 * 返回new_bst_root\n
 */
template <typename TKey, typename TValue>
BstNode<TKey, TValue>* BinarySearchTree<TKey, TValue>::CopySubTreeRecursive_(const BstNode<TKey, TValue>* src_bst_root) {

    // ---------- 1 源子树空树处理 ----------

    if (src_bst_root == NULL) {     // if 源子树为空树
        return NULL;                // 返回NULL
    }

    // ---------- 2 生成新树根结点 ----------

    // 声明new_bst_root(新二叉搜索树根结点), 并分配内存
    BstNode<TKey, TValue>* new_bst_root = new BstNode<TKey, TValue>(src_bst_root->Value(), src_bst_root->Key());
    if (new_bst_root == NULL) {     // if 内存分配失败
        throw bad_alloc();          // 抛出bad_alloc()
    }

    // ---------- 3 左右子树分治递归复制 ----------

    // 左子树递归调用CopySubTreeRecursive_, 生成新左子树
    new_bst_root->SetLeftChild(CopySubTreeRecursive_(src_bst_root->left_child_));
    // 右子树递归调用CopySubTreeRecursive_, 生成新右子树
    new_bst_root->SetRightChild(CopySubTreeRecursive_(src_bst_root->right_child_));

    // ---------- 4 返回新树根结点 ----------

    return new_bst_root;            // 返回new_bst_root
}


/*!
 * @brief **获取(子树中)关键字最小结点**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 * @param subtree_root 子树根结点
 * @return 最小节点指针
 * @note
 * 获取(子树中)关键字最小结点
 * -----------------------
 * -----------------------
 *
 * -----------------------
 * + **1 空子树处理**\n
 * **if** 子树根结点为NULL :\n
 * &emsp; 返回NULL\n
 * + **2 向左遍历**\n
 * 声明并初始化cur指向子树根结点\n
 * **while loop** cur不为NULL <b>&&</b> cur的左孩子不为NULL :\n
 * &emsp; cur指向自身左孩子\n
 * + **3 返回结果**\n
 * 返回cur\n
 */
template <typename TKey, typename TValue>
BstNode<TKey, TValue>* BinarySearchTree<TKey, TValue>::MinInSubTree_(BstNode<TKey, TValue>* subtree_root) const {

    // ---------- 1 空子树处理 ----------

    if (subtree_root == NULL) {                 // if 子树根结点为NULL
        return NULL;                            // 返回NULL
    }

    // ---------- 2 向左遍历 ----------

    BstNode<TKey, TValue>* cur = subtree_root;  // 声明并初始化cur指向子树根结点

    while (cur && cur->LeftChild() != NULL) {   // while loop cur不为NULL && cur的左孩子不为NULL
        cur = cur->LeftChild();                 // cur指向自身左孩子
    }

    // ---------- 3 返回结果 ----------

    return cur;                                 // 返回cur
}


/*!
 * @brief **获取(子树中)关键字最大结点**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 * @param subtree_root 子树根结点
 * @return 最大节点指针
 * @note
 * 获取(子树中)关键字最大结点
 * -----------------------
 * -----------------------
 *
 * -----------------------
 * + **1 空子树处理**\n
 * **if** 子树根结点为NULL :\n
 * &emsp; 返回NULL\n
 * + **2 向右遍历**\n
 * 声明并初始化cur指向子树根结点\n
 * **while loop** cur不为NULL <b>&&</b> cur的右孩子不为NULL :\n
 * &emsp; cur指向自身右孩子\n
 * + **3 返回结果**\n
 * 返回cur\n
 */
template <typename TKey, typename TValue>
BstNode<TKey, TValue>* BinarySearchTree<TKey, TValue>::MaxInSubTree_(BstNode<TKey, TValue>* subtree_root) const {

    // ---------- 1 空子树处理 ----------

    if (subtree_root == NULL) {                     // if 子树根结点为NULL
        return NULL;                                // 返回NULL
    }

    // ---------- 2 向右遍历 ----------

    BstNode<TKey, TValue>* cur = subtree_root;      // 声明并初始化cur指向子树根结点
    while (cur && cur->RightChild() != NULL) {      // while loop cur不为NULL && cur的右孩子不为NULL
        cur = cur->RightChild();                    // cur指向自身右孩子
    }

    // ---------- 3 返回结果 ----------

    return cur;                                     // 返回cur
}


/*!
 * @brief **重载==**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 * @param src_bst 源二叉搜索树
 * @return 当前变量引用
 * 重载==
 * ------
 * ------
 *
 * ------
 * + **1 复制自身处理**\n
 * **if** 复制自身 :\n
 * &emsp; 返回*this\n
 * + **2 复制**\n
 * 对src_bst的根结点调用CopySubTreeRecursive_, 返回值赋给root_\n
 * + **3 返回*this**\n
 */
template<typename TKey, typename TValue>
BinarySearchTree<TKey, TValue>& BinarySearchTree<TKey, TValue>::operator=(const BinarySearchTree<TKey, TValue>& src_bst) {

    // ---------- 1 复制自身处理 ----------

    if (&src_bst == this) {     // if 复制自身
        return *this;           // 返回*this
    }

    // ---------- 2 复制 ----------

    // 对src_bst的根结点调用CopySubTreeRecursive_, 返回值赋给root_
    this->root_ = CopySubTreeRecursive_(src_bst.root_);

    // ---------- 3 返回*this ----------

    return *this;
}


/*!
 * @brief **获取最大关键字对应的值**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 * @param min_value 值保存变量
 * @return 执行结果
 * @note
 * 获取最大关键字对应的值
 * -------------------
 * -------------------
 *
 * -------------------
 * 对根结点调用MaxInSubTree_, 获取key最大的结点\n
 * **if** node为NULL :\n
 * &emsp; 返回false\n
 * node的value_赋给max_value\n
 * 返回true\n
 */
template<typename TKey, typename TValue>
bool BinarySearchTree<TKey, TValue>::Max(TValue& max_value) {
    // 对根结点调用MaxInSubTree_, 获取key最大的结点
    BstNode<TKey, TValue>* node = this->MaxInSubTree_(this->Root());
    if (!node) {                                                        // if node为NULL
        return false;                                                   // 返回false
    }

    max_value = node->Value();                                          // node的value_赋给max_value

    return true;                                                        // 返回true
}


/*!
 * @brief **子树高度**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 * @param subtree_root 子树根结点
 * @return 高度
 * @note
 * 子树高度
 * -------
 * -------
 *
 * -------
 * + **1 空树处理**\n
 * **if** 空子树 :\n
 * &emsp; 返回0\n
 * + **2 分治递归**\n
 * 取left_subtree_height(左子树高度)和right_subtree_height(右子树高度)\n
 * **if** left_subtree_height < right_subtree_height :\n
 * &emsp; 返回right_subtree_height + 1\n
 * **else** (left_subtree_height >= right_subtree_height) :\n
 * &emsp; 返回left_subtree_height + 1\n
 */
template<typename TKey, typename TValue>
int BinarySearchTree<TKey, TValue>::HeightOfSubtreeRecursive_(BstNode<TKey, TValue>* subtree_root) {

    // ---------- 1 空树处理 ----------

    if (!subtree_root) {    // if 空子树
        return 0;           // 返回0
    }

    // ---------- 2 分治递归 ----------

    // 取left_subtree_height(左子树高度)和right_subtree_height(右子树高度)
    int left_subtree_height = HeightOfSubtreeRecursive_(subtree_root->LeftChild());
    int right_subtree_height = HeightOfSubtreeRecursive_(subtree_root->RightChild());

    if (left_subtree_height < right_subtree_height) {   // if left_subtree_height < right_subtree_height
        return right_subtree_height + 1;                // 返回right_subtree_height + 1
    } else {                                            // else (left_subtree_height >= right_subtree_height)
        return left_subtree_height + 1;                 // 返回left_subtree_height + 1
    }
}


/*!
 * @brief **获取结点的(中序)下一结点**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 * @param node 结点
 * @return 下一结点指针
 * @note
 * 获取结点的(中序)下一结点
 * ---------------------
 * ---------------------
 *
 *
 *
 * ---------------------
 * + **1 合法性判断**\n
 * &emsp; **if** node为NULL :\n
 * &emsp;&emsp; 返回NULL\n
 * + **2 查找结点**\n
 * &emsp; 初始化遍历指针cur, 指向结点的右孩子\n
 * &emsp; **while loop** cur不为NULL <b>&&</b> cur存在左孩子 :\n
 * &emsp;&emsp; cur指向左孩子\n
 * &emsp; 返回cur\n
 */
template<typename TKey, typename TValue>
BstNode<TKey, TValue>* BinarySearchTree<TKey, TValue>::NextNode_(BstNode<TKey, TValue>* node) {

    // ---------- 1 合法性判断 ----------

    if (!node) {                                        // if node为NULL
        return NULL;                                    // 返回NULL
    }

    // ---------- 2 查找结点 ----------

    BstNode<TKey, TValue>* cur = node->RightChild();    // 初始化遍历指针cur, 指向结点的左孩子
    while (cur && cur->LeftChild()) {                   // while loop cur不为NULL && cur存在右孩子 :
        cur = cur->LeftChild();                         // cur指向右孩子
    }

    return cur;                                         // 返回cur
}


#endif // CYBER_DASH_BINARY_SEARCH_TREE_H

