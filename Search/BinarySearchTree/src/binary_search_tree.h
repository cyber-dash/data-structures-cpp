#ifndef CYBER_DASH_BINARY_SEARCH_TREE_H
#define CYBER_DASH_BINARY_SEARCH_TREE_H


#include <iostream>
#include <cstdlib>


using namespace std;


template <class Value, class Key>
class BSTNode {
public:
    BSTNode() : left_child_(NULL), right_child_(NULL) {}
    BSTNode(Value value, Key key) : value_(value), key_(key), left_child_(NULL), right_child_(NULL) {}
    BSTNode(Value value, Key key, BSTNode<Value, Key>* left_child_ptr, BSTNode<Value, Key>* right_child_ptr) :
        value_(value), key_(key), left_child_(left_child_ptr), right_child_(right_child_ptr) {}

    BSTNode<Value, Key>*& LeftChild() { return this->left_child_; };
    BSTNode<Value, Key>*& RightChild() { return this->right_child_; };

    void SetLeftChildPtr(BSTNode<Value, Key>* node_ptr) { this->left_child_ = node_ptr; }
    void SetRightChildPtr(BSTNode<Value, Key>* node_ptr) { this->right_child_ = node_ptr; }

    virtual void SetKey(const Key& key) { this->key_ = key; }
    virtual Key GetKey() { return this->key_; }

    virtual void SetValue(const Value& value) { this->value_ = value; }
    virtual Value GetValue() { return this->value_; }

protected:
    BSTNode<Value, Key>* left_child_;
    BSTNode<Value, Key>* right_child_;

    Key key_;
    Value value_;
};


template <class Value, class Key>
class BST {
public:
    BST() : root_node_ptr_(NULL) {}
    BST(Key key, Value value);

    virtual ~BST() { delete this->root_node_ptr_; };

    virtual bool Insert(Value value, Key key);
    virtual bool Remove(const Key& key) { return RemoveInSubTree_(key, root_node_ptr_); }
    BSTNode<Value, Key>* Search(Key key) { return SearchInSubTree_(key, this->root_node_ptr_); }
    virtual int Height() { return this->SubTreeHeight_(this->root_node_ptr_); }

    virtual Value Min();
    virtual Value Max();

    virtual void MakeEmpty() { MakeEmptySubTree_(root_node_ptr_); root_node_ptr_ = NULL; }
    void PrintTree(void (*visit)(BSTNode<Value, Key>*)) { this->PrintSubTree_(this->root_node_ptr_, visit); }

    BST<Value, Key>& operator=(const BST<Value, Key>& origin_BST);

protected:
    BSTNode<Value, Key>* root_node_ptr_; // 根节点

    // 子树中插入节点(递归)
    bool InsertInSubTree_(Value value, Key key, BSTNode<Value, Key>*& sub_tree_root_ptr);

    // 子树中删除节点(递归)
    bool RemoveInSubTree_(Key key, BSTNode<Value, Key>*& sub_tree_root_ptr);

    // 在子树中, 使用关键码进行搜索
    BSTNode<Value, Key>* SearchInSubTree_(Key key, BSTNode<Value, Key>* sub_tree_root_ptr);

    int SubTreeHeight_(BSTNode<Value, Key>* sub_tree_root_ptr);

    // 清除子树(递归)
    void MakeEmptySubTree_(BSTNode<Value, Key>*& sub_tree_root_ptr);

    // 打印子树(递归/中序)
    void PrintSubTree_(BSTNode<Value, Key>* sub_tree_root_ptr, void (*visit)(BSTNode<Value, Key>* p)) const;

    // 复制一颗树
    BSTNode<Value, Key>* Copy_(const BSTNode<Value, Key>* origin_tree_root_ptr);

    // 子树中关键码最小项
    BSTNode<Value, Key>* MinInSubTree_(BSTNode<Value, Key>* sub_tree_root_ptr) const;

    // 子树中关键码最大项
    BSTNode<Value, Key>* MaxInSubTree_(BSTNode<Value, Key>* sub_tree_root_ptr) const;
};


/**
 * @brief 在子树中, 使用关键码进行搜索
 * @tparam Value 数据项模板类型
 * @tparam Key 关键码模板类型
 * @param key 关键码
 * @param sub_tree_root_ptr 子树根节点
 * @return 搜索结果
 * @note
 * 1. 如果子树根节点为NULL, 返回NULL
 * 2. 使用当前遍历节点的key, 与参数key作比较, 分别进行递归和返回搜索结果(终止递归)
 */
template <class Value, class Key>
BSTNode<Value, Key>* BST<Value, Key>::SearchInSubTree_(Key key, BSTNode<Value, Key>* sub_tree_root_ptr) {
    if (sub_tree_root_ptr == NULL) {
        return NULL;
    }

    Key cur_key = sub_tree_root_ptr->GetKey();

    if (key < cur_key) {
        return SearchInSubTree_(key, sub_tree_root_ptr->LeftChild());
    }
    else if (key > cur_key) {
        return SearchInSubTree_(key, sub_tree_root_ptr->RightChild());
    }
    else {
        return sub_tree_root_ptr;
    }
}


template<class Value, class Key>
bool BST<Value, Key>::Insert(Value value, Key key) {
    if (this->Search(key) != NULL) {
        return true;
    }

    return this->InsertInSubTree_(value, key, this->root_node_ptr_);
}


template<class Value, class Key>
Value BST<Value, Key>::Min() {
    return MinInSubTree_(root_node_ptr_)->GetValue();
}


/**
 * @brief 子树中插入节点(递归)
 * @tparam Value 数据项模板类型
 * @tparam Key 关键码模板类型
 * @param value 数据项
 * @param key 关键码
 * @param sub_tree_root_ptr 子树根节点指针
 * @return 是否插入成功
 * @note
 * 如果根节点指针为NULL, 则创建节点
 * 判断插入关键码与子树根节点关键码的大小关系, 在左子树or右子树做插入操作(递归)
 * 如果关键码相同, 则返回false
 */
template <class Value, class Key>
bool BST<Value, Key>::InsertInSubTree_(Value value, Key key, BSTNode<Value, Key>*& sub_tree_root_ptr) {
    if (sub_tree_root_ptr == NULL) {
        sub_tree_root_ptr = new BSTNode<Value, Key>(value, key);
        /* error handler */

        return true;
    }

    if (key < sub_tree_root_ptr->GetKey()) {
        return InsertInSubTree_(value, key, sub_tree_root_ptr->LeftChild());
    }
    else if (key > sub_tree_root_ptr->GetKey()) {
        return InsertInSubTree_(value, key, sub_tree_root_ptr->RightChild());
    }
    else {
        return false;
    }
}


template <class Value, class Key>
BST<Value, Key>::BST(Key key, Value value) {
    this->Insert(value, key);
}


/**
 * @brief 子树中删除节点(递归)
 * @tparam Value 数据项模板类型
 * @tparam Key 关键码模板类型
 * @param key 待删除节点的数据码
 * @param sub_tree_root_ptr 子树根节点
 * @return 是否删除成功
 * @note
 * 1. 如果子树根节点指针为NULL, 则返回false
 * 2. 递归分治, 找到删除节点的位置
 * 3. 如果有两个孩子节点, 使用中序前驱or后继, 替换掉待删除节点
 * 4. 如果只有一个孩子节点, 则将该孩子提升至待删除节点
 */
template <class Value, class Key>
bool BST<Value, Key>::RemoveInSubTree_(Key key, BSTNode<Value, Key>*& sub_tree_root_ptr) {

    if (sub_tree_root_ptr == NULL) {
        return false;
    }

    if (key < sub_tree_root_ptr->GetKey()) {
        return RemoveInSubTree_(key, sub_tree_root_ptr->LeftChild());
    }
    else if (key > sub_tree_root_ptr->GetKey()) {
        return RemoveInSubTree_(key, sub_tree_root_ptr->RightChild());
    }

    // 删除sub_tree_root_ptr, 使用中序前驱or后继替换掉该节点, 此处使用后继
    if (sub_tree_root_ptr->LeftChild() != NULL && sub_tree_root_ptr->RightChild() != NULL) { // 存在左右孩子

        BSTNode<Value, Key>* cur_node_ptr = sub_tree_root_ptr->RightChild();
        while (cur_node_ptr->LeftChild() != NULL) {
            cur_node_ptr = cur_node_ptr->LeftChild();
        }

        // 拿到后继节点的数据, 作为替换数据
        Value replace_data = cur_node_ptr->GetValue();
        Key replace_key = cur_node_ptr->GetKey();

        sub_tree_root_ptr->SetValue(replace_data);
        sub_tree_root_ptr->SetKey(replace_key);

        // 删除替换数据原先所在的节点
        return RemoveInSubTree_(replace_key, sub_tree_root_ptr->RightChild());
    }
    else {
        BSTNode<Value, Key>* delete_node_ptr = sub_tree_root_ptr;

        if (sub_tree_root_ptr->LeftChild() == NULL) {
            sub_tree_root_ptr = sub_tree_root_ptr->RightChild();
        }
        else {
            sub_tree_root_ptr = sub_tree_root_ptr->LeftChild();
        }

        delete delete_node_ptr;
        delete_node_ptr = NULL;

        return true;
    }
}


/**
 * @brief 清除子树(递归)
 * @tparam Value 数据项类型模板
 * @tparam Key 关键码类型模板
 * @param sub_tree_root_ptr 子树根节点指针
 * @note
 * 如果sub_tree_root_ptr为NULL, 则递归结束
 * 对左右子树, 递归执行函数
 * 对子树节点执行delete和置NULL操作
 */
template <class Value, class Key>
void BST<Value, Key>::MakeEmptySubTree_(BSTNode<Value, Key>*& sub_tree_root_ptr) {

    if (sub_tree_root_ptr == NULL) {
        return;
    }

    MakeEmptySubTree_(sub_tree_root_ptr->LeftChild());
    MakeEmptySubTree_(sub_tree_root_ptr->RightChild());

    delete sub_tree_root_ptr;
    sub_tree_root_ptr = NULL;
}


/**
 * @brief 打印子树(递归/中序)
 * @tparam Value 数据项类型模板
 * @tparam Key 关键码类型模板
 * @param sub_tree_root_ptr 子树根节点指针
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
template <class Value, class Key>
void BST<Value, Key>::PrintSubTree_(BSTNode<Value, Key>* sub_tree_root_ptr, void (*visit)(BSTNode<Value, Key>*)) const {

    if (sub_tree_root_ptr == NULL) {
        return;
    }

    visit(sub_tree_root_ptr);

    cout << "(";

    PrintSubTree_(sub_tree_root_ptr->LeftChild(), visit);

    cout << ",";

    PrintSubTree_(sub_tree_root_ptr->RightChild(), visit);

    cout << ")";
}


/**
 * @brief 复制一颗树
 * @tparam Value 数据项模板类型
 * @tparam Key 关键码模板类型
 * @param origin_tree_root_ptr 源子树
 * @return 新树的根节点
 */
template <class Value, class Key>
BSTNode<Value, Key>* BST<Value, Key>::Copy_(const BSTNode<Value, Key>* origin_tree_root_ptr) {

    if (origin_tree_root_ptr == NULL) {
        return NULL;
    }

    BSTNode<Value, Key>* new_tree_root_ptr = new BSTNode<Value, Key>(
        origin_tree_root_ptr->GetValue(),
        origin_tree_root_ptr->GetKey());
    /* error handler */

    new_tree_root_ptr->SetLeftChildPtr(Copy_(origin_tree_root_ptr->left_child_));
    new_tree_root_ptr->SetRightChildPtr(Copy_(origin_tree_root_ptr->right_child_));

    return new_tree_root_ptr;
}


/**
 * @brief 子树中关键码最小项
 * @tparam Value 数据项模板类型
 * @tparam Key 关键码模板类型
 * @param sub_tree_root_ptr 子树根节点
 * @return 关键码最小项
 * @note
 * 左孩子节点迭代
 */
template <class Value, class Key>
BSTNode<Value, Key>* BST<Value, Key>::MinInSubTree_(BSTNode<Value, Key>* sub_tree_root_ptr) const {

    if (sub_tree_root_ptr == NULL) {
        return NULL;
    }

    BSTNode<Value, Key>* cur_node_ptr = sub_tree_root_ptr;

    while (cur_node_ptr->LeftChild() != NULL) {
        cur_node_ptr = cur_node_ptr->LeftChild();
    }

    return cur_node_ptr;
}


/**
 * @brief 子树中关键码最大项
 * @tparam Value 数据项模板类型
 * @tparam Key 关键码模板类型
 * @param sub_tree_root_ptr 子树根节点
 * @return 关键码最大项
 * @note
 * 右孩子节点迭代
 */
template <class Value, class Key>
BSTNode<Value, Key>* BST<Value, Key>::MaxInSubTree_(BSTNode<Value, Key>* sub_tree_root_ptr) const {

    if (sub_tree_root_ptr == NULL) {
        return NULL;
    }

    BSTNode<Value, Key>* cur_node_ptr = sub_tree_root_ptr;
    while (cur_node_ptr->RightChild() != NULL) {
        cur_node_ptr = cur_node_ptr->RightChild();
    }

    return cur_node_ptr;
}


template<class Value, class Key>
BST<Value, Key>& BST<Value, Key>::operator=(const BST<Value, Key>& origin_BST) {

    this->root_node_ptr_ = this->Copy_(origin_BST.root_node_ptr_);

    return *this;
}


template<class Value, class Key>
Value BST<Value, Key>::Max() {
    BSTNode<Value, Key>* root_node_ptr = this->root_node_ptr_;
    BSTNode<Value, Key>* max_node = this->BST::MaxInSubTree_(root_node_ptr);
    return max_node->GetValue();
}


template<class Value, class Key>
int BST<Value, Key>::SubTreeHeight_(BSTNode<Value, Key>* sub_tree_root_ptr) {
    if (sub_tree_root_ptr == NULL) {
        return 0;
    }

    int left_sub_tree_height = SubTreeHeight_(sub_tree_root_ptr->LeftChild());
    int right_sub_tree_height = SubTreeHeight_(sub_tree_root_ptr->RightChild());

    if (left_sub_tree_height < right_sub_tree_height) {
        return right_sub_tree_height + 1;
    }
    else {
        return left_sub_tree_height + 1;
    }
}


#endif // CYBER_DASH_BINARY_SEARCH_TREE_H

