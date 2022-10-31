#ifndef CYBER_DASH_BINARY_SEARCH_TREE_H
#define CYBER_DASH_BINARY_SEARCH_TREE_H


#include <iostream>
#include <cstdlib>


using namespace std;


template <class TKey, class TValue>
class BinarySearchTreeNode {
public:
    BinarySearchTreeNode(): left_child_(NULL), right_child_(NULL) {}
    BinarySearchTreeNode(TKey key, TValue value): value_(value), key_(key), left_child_(NULL), right_child_(NULL) {}
    BinarySearchTreeNode(TKey key, TValue value, BinarySearchTreeNode<TKey, TValue>* left_child, BinarySearchTreeNode<TKey, TValue>* right_child):
        value_(value), key_(key), left_child_(left_child), right_child_(right_child) {}

    BinarySearchTreeNode<TKey, TValue>*& LeftChild() { return this->left_child_; };
    void SetLeftChild(BinarySearchTreeNode<TKey, TValue>* node) { this->left_child_ = node; }

    BinarySearchTreeNode<TKey, TValue>*& RightChild() { return this->right_child_; };
    void SetRightChild(BinarySearchTreeNode<TKey, TValue>* node) { this->right_child_ = node; }

    virtual TKey Key() { return this->key_; }
    virtual void SetKey(const TKey& key) { this->key_ = key; }

    virtual TValue Value() { return this->value_; }
    virtual void SetValue(const TValue& value) { this->value_ = value; }

protected:
    BinarySearchTreeNode<TKey, TValue>* left_child_;
    BinarySearchTreeNode<TKey, TValue>* right_child_;

    TKey key_;
    TValue value_;
};


template <class TKey, class TValue>
class BinarySearchTree {
public:
    BinarySearchTree() : root_node_(NULL) {}
    BinarySearchTree(TKey key, TValue value);

    virtual ~BinarySearchTree() { delete this->root_node_; };

    virtual bool Insert(TKey key, TValue value);
    virtual bool Remove(const TKey& key) { return RemoveInSubTree_(key, root_node_); }

    virtual BinarySearchTreeNode<TKey, TValue>* Search(TKey key) { return SearchInSubTree_(key, this->root_node_); }
    virtual int Height() { return this->SubTreeHeight_(this->root_node_); }

    virtual TValue Min();
    virtual TValue Max();

    BinarySearchTreeNode<TKey, TValue>*& Root() { return this->root_node_; }

    virtual void MakeEmpty() { MakeEmptySubTree_(root_node_); root_node_ = NULL; }
    void PrintTree(void (*visit)(BinarySearchTreeNode<TKey, TValue>*)) { this->PrintSubTree_(this->root_node_, visit); }

    BinarySearchTree<TKey, TValue>& operator=(const BinarySearchTree<TKey, TValue>& origin_BST);

protected:
    BinarySearchTreeNode<TKey, TValue>* root_node_; // 根节点

    // 子树中插入节点(递归)
    bool InsertInSubTree_(TKey key, TValue value, BinarySearchTreeNode<TKey, TValue>*& sub_tree_root);

    // 子树中删除节点(递归)
    bool RemoveInSubTree_(TKey key, BinarySearchTreeNode<TKey, TValue>*& sub_tree_root);

    // 在子树中, 使用关键码进行搜索
    BinarySearchTreeNode<TKey, TValue>* SearchInSubTree_(TKey key, BinarySearchTreeNode<TKey, TValue>* sub_tree_root);

    int SubTreeHeight_(BinarySearchTreeNode<TKey, TValue>* sub_tree_root);

    // 清除子树(递归)
    void MakeEmptySubTree_(BinarySearchTreeNode<TKey, TValue>*& sub_tree_root);

    // 打印子树(递归/中序)
    void PrintSubTree_(BinarySearchTreeNode<TKey, TValue>* sub_tree_root, void (*visit)(BinarySearchTreeNode<TKey, TValue>*)) const;

    // 复制一颗树
    BinarySearchTreeNode<TKey, TValue>* CopySubTreeRecursive_(const BinarySearchTreeNode<TKey, TValue>* origin_tree_root);

    // 子树中关键码最小项
    BinarySearchTreeNode<TKey, TValue>* MinInSubTree_(BinarySearchTreeNode<TKey, TValue>* sub_tree_root) const;

    // 子树中关键码最大项
    BinarySearchTreeNode<TKey, TValue>* MaxInSubTree_(BinarySearchTreeNode<TKey, TValue>* sub_tree_root) const;
};


/**
 * @brief 在子树中, 使用关键码进行搜索
 * @tparam TValue 数据项模板类型
 * @tparam TKey 关键码模板类型
 * @param key 关键码
 * @param sub_tree_root 子树根节点
 * @return 搜索结果
 * @note
 * 1. 如果子树根节点为NULL, 返回NULL
 * 2. 使用当前遍历节点的key, 与参数key作比较, 分别进行递归和返回搜索结果(终止递归)
 */
template <class TKey, class TValue>
BinarySearchTreeNode<TKey, TValue>* BinarySearchTree<TKey, TValue>::SearchInSubTree_(TKey key, BinarySearchTreeNode<TKey, TValue>* sub_tree_root) {
    if (sub_tree_root == NULL) {
        return NULL;
    }

    TKey cur_key = sub_tree_root->Key();

    if (key < cur_key) {
        return SearchInSubTree_(key, sub_tree_root->LeftChild());
    } else if (key > cur_key) {
        return SearchInSubTree_(key, sub_tree_root->RightChild());
    }

    return sub_tree_root;
}


template<class TKey, class TValue>
bool BinarySearchTree<TKey, TValue>::Insert(TKey key, TValue value) {
    if (this->Search(key) != NULL) {
        return true;
    }

    return this->InsertInSubTree_(key, value, this->root_node_);
}


template<class TKey, class TValue>
TValue BinarySearchTree<TKey, TValue>::Min() {
    return MinInSubTree_(root_node_)->Value();
}


/**
 * @brief 子树中插入节点(递归)
 * @tparam TValue 数据项模板类型
 * @tparam TKey 关键码模板类型
 * @param value 数据项
 * @param key 关键码
 * @param sub_tree_root 子树根节点指针
 * @return 是否插入成功
 * @note
 * 如果根节点指针为NULL, 则创建节点
 * 判断插入关键码与子树根节点关键码的大小关系, 在左子树or右子树做插入操作(递归)
 * 如果关键码相同, 则返回false
 */
template <class TKey, class TValue>
bool BinarySearchTree<TKey, TValue>::InsertInSubTree_(TKey key, TValue value, BinarySearchTreeNode<TKey, TValue>*& sub_tree_root) {
    if (sub_tree_root == NULL) {
        sub_tree_root = new BinarySearchTreeNode<TKey, TValue>(key, value);
        /* error handler */

        return true;
    }

    if (key < sub_tree_root->Key()) {
        return InsertInSubTree_(key, value, sub_tree_root->LeftChild());
    } else if (key > sub_tree_root->Key()) {
        return InsertInSubTree_(key, value, sub_tree_root->RightChild());
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
 * @param sub_tree_root 子树根节点
 * @return 是否删除成功
 * @note
 * 1. 如果子树根节点指针为NULL, 则返回false
 * 2. 递归分治, 找到删除节点的位置
 * 3. 如果有两个孩子节点, 使用中序前驱or后继, 替换掉待删除节点
 * 4. 如果只有一个孩子节点, 则将该孩子提升至待删除节点
 */
template <class TKey, class TValue>
bool BinarySearchTree<TKey, TValue>::RemoveInSubTree_(TKey key, BinarySearchTreeNode<TKey, TValue>*& sub_tree_root) {

    if (sub_tree_root == NULL) {
        return false;
    }

    if (key < sub_tree_root->Key()) {
        return RemoveInSubTree_(key, sub_tree_root->LeftChild());
    } else if (key > sub_tree_root->Key()) {
        return RemoveInSubTree_(key, sub_tree_root->RightChild());
    }

    // 删除sub_tree_root, 使用中序前驱or后继替换掉该节点, 此处使用后继
    if (sub_tree_root->LeftChild() != NULL && sub_tree_root->RightChild() != NULL) { // 存在左右孩子

        BinarySearchTreeNode<TKey, TValue>* cur_node = sub_tree_root->RightChild();
        while (cur_node->LeftChild() != NULL) {
            cur_node = cur_node->LeftChild();
        }

        // 拿到后继节点的数据, 作为替换数据
        TValue replace_data = cur_node->Value();
        TKey replace_key = cur_node->Key();

        sub_tree_root->SetValue(replace_data);
        sub_tree_root->SetKey(replace_key);

        // 删除替换数据原先所在的节点
        return RemoveInSubTree_(replace_key, sub_tree_root->RightChild());
    } else {
        BinarySearchTreeNode<TKey, TValue>* delete_node = sub_tree_root;

        if (sub_tree_root->LeftChild() == NULL) {
            sub_tree_root = sub_tree_root->RightChild();
        } else {
            sub_tree_root = sub_tree_root->LeftChild();
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
 * @param sub_tree_root 子树根节点指针
 * @note
 * 如果sub_tree_root为NULL, 则递归结束
 * 对左右子树, 递归执行函数
 * 对子树节点执行delete和置NULL操作
 */
template <class TKey, class TValue>
void BinarySearchTree<TKey, TValue>::MakeEmptySubTree_(BinarySearchTreeNode<TKey, TValue>*& sub_tree_root) {

    if (sub_tree_root == NULL) {
        return;
    }

    MakeEmptySubTree_(sub_tree_root->LeftChild());
    MakeEmptySubTree_(sub_tree_root->RightChild());

    delete sub_tree_root;
    sub_tree_root = NULL;
}


/**
 * @brief 打印子树(递归/中序)
 * @tparam TValue 数据项类型模板
 * @tparam TKey 关键码类型模板
 * @param sub_tree_root 子树根节点指针
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
void BinarySearchTree<TKey, TValue>::PrintSubTree_(BinarySearchTreeNode<TKey, TValue>* sub_tree_root, void (*visit)(BinarySearchTreeNode<TKey, TValue>*)) const {

    if (sub_tree_root == NULL) {
        return;
    }

    visit(sub_tree_root);

    cout << "(";

    PrintSubTree_(sub_tree_root->LeftChild(), visit);

    cout << ",";

    PrintSubTree_(sub_tree_root->RightChild(), visit);

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
BinarySearchTreeNode<TKey, TValue>* BinarySearchTree<TKey, TValue>::CopySubTreeRecursive_(const BinarySearchTreeNode<TKey, TValue>* origin_tree_root) {

    if (origin_tree_root == NULL) {
        return NULL;
    }

    BinarySearchTreeNode<TKey, TValue>* new_tree_root = new BinarySearchTreeNode<TKey, TValue>(
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
 * @param sub_tree_root 子树根节点
 * @return 关键码最小项
 * @note
 * 左孩子节点迭代
 */
template <class TKey, class TValue>
BinarySearchTreeNode<TKey, TValue>* BinarySearchTree<TKey, TValue>::MinInSubTree_(BinarySearchTreeNode<TKey, TValue>* sub_tree_root) const {

    if (sub_tree_root == NULL) {
        return NULL;
    }

    BinarySearchTreeNode<TKey, TValue>* cur_node = sub_tree_root;

    while (cur_node->LeftChild() != NULL) {
        cur_node = cur_node->LeftChild();
    }

    return cur_node;
}


/**
 * @brief 子树中关键码最大项
 * @tparam TValue 数据项模板类型
 * @tparam TKey 关键码模板类型
 * @param sub_tree_root 子树根节点
 * @return 关键码最大项
 * @note
 * 右孩子节点迭代
 */
template <class TKey, class TValue>
BinarySearchTreeNode<TKey, TValue>* BinarySearchTree<TKey, TValue>::MaxInSubTree_(BinarySearchTreeNode<TKey, TValue>* sub_tree_root) const {

    if (sub_tree_root == NULL) {
        return NULL;
    }

    BinarySearchTreeNode<TKey, TValue>* cur_node = sub_tree_root;
    while (cur_node->RightChild() != NULL) {
        cur_node = cur_node->RightChild();
    }

    return cur_node;
}


template<class TKey, class TValue>
BinarySearchTree<TKey, TValue>& BinarySearchTree<TKey, TValue>::operator=(const BinarySearchTree<TKey, TValue>& origin_BST) {

    this->root_node_ = CopySubTreeRecursive_(origin_BST.root_node_);

    return *this;
}


template<class TKey, class TValue>
TValue BinarySearchTree<TKey, TValue>::Max() {
    BinarySearchTreeNode<TKey, TValue>* root_node = this->root_node_;
    BinarySearchTreeNode<TKey, TValue>* max_node = this->BinarySearchTree::MaxInSubTree_(root_node);
    return max_node->Value();
}


template<class TKey, class TValue>
int BinarySearchTree<TKey, TValue>::SubTreeHeight_(BinarySearchTreeNode<TKey, TValue>* sub_tree_root) {
    if (sub_tree_root == NULL) {
        return 0;
    }

    int left_sub_tree_height = SubTreeHeight_(sub_tree_root->LeftChild());
    int right_sub_tree_height = SubTreeHeight_(sub_tree_root->RightChild());

    if (left_sub_tree_height < right_sub_tree_height) {
        return right_sub_tree_height + 1;
    } else {
        return left_sub_tree_height + 1;
    }
}


#endif // CYBER_DASH_BINARY_SEARCH_TREE_H

