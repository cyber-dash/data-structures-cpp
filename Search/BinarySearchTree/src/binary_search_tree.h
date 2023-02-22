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

    TKey key_;                                          //!< 关键字
    TValue value_;                                      //!< 值
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
    BinarySearchTree(TKey key, TValue value);

    virtual ~BinarySearchTree() { delete this->root_; };

    virtual bool Insert(TKey key, TValue value);
    virtual bool Remove(const TKey& key) { return RemoveInSubTree_(key, root_); }

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
    virtual int Height() { return this->HeightOfSubtreeRecursive_(this->root_); }

    virtual TValue Min();
    virtual TValue Max();

    BstNode<TKey, TValue>*& Root() { return this->root_; }

    virtual void MakeEmpty() { MakeEmptySubTree_(root_); root_ = NULL; }
    void PrintTree(void (*visit)(BstNode<TKey, TValue>*)) { this->PrintSubTree_(this->root_, visit); }

    BinarySearchTree<TKey, TValue>& operator=(const BinarySearchTree<TKey, TValue>& origin_BST);

protected:
    // 子树中插入节点(递归)
    bool InsertInSubTree_(TKey key, TValue value, BstNode<TKey, TValue>*& subtree_root);

    // 子树中删除节点(递归)
    bool RemoveInSubTree_(TKey key, BstNode<TKey, TValue>*& subtree_root);

    // 子树搜索(递归)
    BstNode<TKey, TValue>* SearchInSubTree_(BstNode<TKey, TValue>* subtree_root, TKey key);

    int HeightOfSubtreeRecursive_(BstNode<TKey, TValue>* subtree_root);

    // 清除子树(递归)
    void MakeEmptySubTree_(BstNode<TKey, TValue>*& subtree_root);

    // 打印子树(递归/中序)
    void PrintSubTree_(BstNode<TKey, TValue>* subtree_root,
                       void (*visit)(BstNode<TKey, TValue>*)) const;

    // 复制一颗树
    BstNode<TKey, TValue>* CopySubTreeRecursive_(const BstNode<TKey, TValue>* origin_tree_root);

    // 子树中关键码最小项
    BstNode<TKey, TValue>* MinInSubTree_(BstNode<TKey, TValue>* subtree_root) const;

    // 子树中关键码最大项
    BstNode<TKey, TValue>* MaxInSubTree_(BstNode<TKey, TValue>* subtree_root) const;

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


template<class TKey, class TValue>
bool BinarySearchTree<TKey, TValue>::Insert(TKey key, TValue value) {
    if (this->Search(key) != NULL) {
        return true;
    }

    return this->InsertInSubTree_(key, value, this->root_);
}


template<class TKey, class TValue>
TValue BinarySearchTree<TKey, TValue>::Min() {
    return MinInSubTree_(root_)->Value();
}


/**
 * @brief 子树中插入节点(递归)
 * @tparam TValue 数据项模板类型
 * @tparam TKey 关键码模板类型
 * @param value 数据项
 * @param key 关键码
 * @param subtree_root 子树根节点指针
 * @return 是否插入成功
 * @note
 * 如果根节点指针为NULL, 则创建节点
 * 判断插入关键码与子树根节点关键码的大小关系, 在左子树or右子树做插入操作(递归)
 * 如果关键码相同, 则返回false
 */
template <class TKey, class TValue>
bool BinarySearchTree<TKey, TValue>::InsertInSubTree_(TKey key,
                                                      TValue value,
                                                      BstNode<TKey, TValue>*& subtree_root)
{
    if (subtree_root == NULL) {
        subtree_root = new BstNode<TKey, TValue>(key, value);
        if (!subtree_root) {
            throw bad_alloc();
        }

        return true;
    }

    if (key < subtree_root->Key()) {
        return InsertInSubTree_(key, value, subtree_root->LeftChild());
    }

    if (key > subtree_root->Key()) {
        return InsertInSubTree_(key, value, subtree_root->RightChild());
    }

    return false;
}


template <class TKey, class TValue>
BinarySearchTree<TKey, TValue>::BinarySearchTree(TKey key, TValue value) {
    this->Insert(key, value);
}


/**
 * @brief 子树中删除节点(递归)
 * @tparam TValue 数据项模板类型
 * @tparam TKey 关键码模板类型
 * @param key 待删除节点的数据码
 * @param subtree_root 子树根节点
 * @return 是否删除成功
 * @note
 * 1. 如果子树根节点指针为NULL, 则返回false
 * 2. 递归分治, 找到删除节点的位置
 * 3. 如果有两个孩子节点, 使用中序前驱or后继, 替换掉待删除节点
 * 4. 如果只有一个孩子节点, 则将该孩子提升至待删除节点
 */
template <class TKey, class TValue>
bool BinarySearchTree<TKey, TValue>::RemoveInSubTree_(TKey key, BstNode<TKey, TValue>*& subtree_root) {

    if (subtree_root == NULL) {
        return false;
    }

    if (key < subtree_root->Key()) {
        return RemoveInSubTree_(key, subtree_root->LeftChild());
    }

    if (key > subtree_root->Key()) {
        return RemoveInSubTree_(key, subtree_root->RightChild());
    }

    // 删除subtree_root, 使用中序前驱or后继替换掉该节点, 此处使用后继
    if (subtree_root->LeftChild() != NULL && subtree_root->RightChild() != NULL) { // 存在左右孩子

        BstNode<TKey, TValue>* cur_node = subtree_root->RightChild();
        while (cur_node->LeftChild() != NULL) {
            cur_node = cur_node->LeftChild();
        }

        // 拿到后继节点的数据, 作为替换数据
        TValue replace_data = cur_node->Value();
        TKey replace_key = cur_node->Key();

        subtree_root->SetValue(replace_data);
        subtree_root->SetKey(replace_key);

        // 删除替换数据原先所在的节点
        return RemoveInSubTree_(replace_key, subtree_root->RightChild());
    } else {
        BstNode<TKey, TValue>* delete_node = subtree_root;

        if (subtree_root->LeftChild() == NULL) {
            subtree_root = subtree_root->RightChild();
        } else {
            subtree_root = subtree_root->LeftChild();
        }

        delete delete_node;
        delete_node = NULL;

        return true;
    }
}


/**
 * @brief 清除子树(递归)
 * @tparam TValue 数据项类型模板
 * @tparam TKey 关键码类型模板
 * @param subtree_root 子树根节点指针
 * @note
 * 如果subtree_root为NULL, 则递归结束
 * 对左右子树, 递归执行函数
 * 对子树节点执行delete和置NULL操作
 */
template <class TKey, class TValue>
void BinarySearchTree<TKey, TValue>::MakeEmptySubTree_(BstNode<TKey, TValue>*& subtree_root) {

    if (subtree_root == NULL) {
        return;
    }

    MakeEmptySubTree_(subtree_root->LeftChild());
    MakeEmptySubTree_(subtree_root->RightChild());

    delete subtree_root;
    subtree_root = NULL;
}


/**
 * @brief 打印子树(递归/中序)
 * @tparam TValue 数据项类型模板
 * @tparam TKey 关键码类型模板
 * @param subtree_root 子树根节点指针
 * @param visit 访问函数
 * @note
 * 打印格式: "[子树根节点]([子树根节点左子树], [子树根节点右子树])"
 *
 * 1. 访问/打印子树根节点
 * 2. 打印“(”
 * 3. 访问/打印子树根节点的左子树
 * 4. 打印“,”
 * 5. 访问/打印子树根节点的右子树
 * 6. 打印“)”
 */
template <class TKey, class TValue>
void BinarySearchTree<TKey, TValue>::PrintSubTree_(BstNode<TKey, TValue>* subtree_root,
                                                   void (*visit)(BstNode<TKey, TValue>*)) const
{
    if (subtree_root == NULL) {
        return;
    }

    visit(subtree_root);

    cout << "(";

    PrintSubTree_(subtree_root->LeftChild(), visit);

    cout << ",";

    PrintSubTree_(subtree_root->RightChild(), visit);

    cout << ")";
}


/**
 * @brief 复制一颗树
 * @tparam TValue 数据项模板类型
 * @tparam TKey 关键码模板类型
 * @param origin_tree_root 源子树
 * @return 新树的根节点
 */
template <class TKey, class TValue>
BstNode<TKey, TValue>* BinarySearchTree<TKey, TValue>::CopySubTreeRecursive_(const BstNode<TKey, TValue>* origin_tree_root) {

    if (origin_tree_root == NULL) {
        return NULL;
    }

    BstNode<TKey, TValue>* new_tree_root = new BstNode<TKey, TValue>(
            origin_tree_root->Value(),
        origin_tree_root->Key());
    /* error handler */

    new_tree_root->SetLeftChild(CopySubTreeRecursive_(origin_tree_root->left_child_));
    new_tree_root->SetRightChild(CopySubTreeRecursive_(origin_tree_root->right_child_));

    return new_tree_root;
}


/**
 * @brief 子树中关键码最小项
 * @tparam TValue 数据项模板类型
 * @tparam TKey 关键码模板类型
 * @param subtree_root 子树根节点
 * @return 关键码最小项
 * @note
 * 左孩子节点迭代
 */
template <class TKey, class TValue>
BstNode<TKey, TValue>* BinarySearchTree<TKey, TValue>::MinInSubTree_(BstNode<TKey, TValue>* subtree_root) const {

    if (subtree_root == NULL) {
        return NULL;
    }

    BstNode<TKey, TValue>* cur_node = subtree_root;

    while (cur_node->LeftChild() != NULL) {
        cur_node = cur_node->LeftChild();
    }

    return cur_node;
}


/**
 * @brief 子树中关键码最大项
 * @tparam TValue 数据项模板类型
 * @tparam TKey 关键码模板类型
 * @param subtree_root 子树根节点
 * @return 关键码最大项
 * @note
 * 右孩子节点迭代
 */
template <class TKey, class TValue>
BstNode<TKey, TValue>* BinarySearchTree<TKey, TValue>::MaxInSubTree_(BstNode<TKey, TValue>* subtree_root) const {

    if (subtree_root == NULL) {
        return NULL;
    }

    BstNode<TKey, TValue>* cur_node = subtree_root;
    while (cur_node->RightChild() != NULL) {
        cur_node = cur_node->RightChild();
    }

    return cur_node;
}


template<class TKey, class TValue>
BinarySearchTree<TKey, TValue>& BinarySearchTree<TKey, TValue>::operator=(const BinarySearchTree<TKey, TValue>& origin_BST) {

    this->root_ = CopySubTreeRecursive_(origin_BST.root_);

    return *this;
}


template<class TKey, class TValue>
TValue BinarySearchTree<TKey, TValue>::Max() {
    BstNode<TKey, TValue>* root_node = this->root_;
    BstNode<TKey, TValue>* max_node = this->BinarySearchTree::MaxInSubTree_(root_node);
    return max_node->Value();
}


template<class TKey, class TValue>
int BinarySearchTree<TKey, TValue>::HeightOfSubtreeRecursive_(BstNode<TKey, TValue>* subtree_root) {
    if (subtree_root == NULL) {
        return 0;
    }

    int left_subtree_height = HeightOfSubtreeRecursive_(subtree_root->LeftChild());
    int right_subtree_height = HeightOfSubtreeRecursive_(subtree_root->RightChild());

    if (left_subtree_height < right_subtree_height) {
        return right_subtree_height + 1;
    } else {
        return left_subtree_height + 1;
    }
}


#endif // CYBER_DASH_BINARY_SEARCH_TREE_H

