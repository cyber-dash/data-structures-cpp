/*!
 * @file binary_tree.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 二叉树模板类
 * @version 0.2.1
 * @date 2020-11-01
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#ifndef CYBER_DASH_BINARY_TREE_H
#define CYBER_DASH_BINARY_TREE_H


#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>
#include "binary_tree.h"


using namespace std;


/*!
 * @brief 二叉树结点模板结构体
 * @tparam T 类型模板参数
 */
template <class T>
struct BinTreeNode {
    /*! @brief 构造函数(无参数) */
    BinTreeNode() : left_child(NULL), right_child(NULL) {}
    /*! @brief 构造函数(数据项和左右孩子) */
    BinTreeNode(T data, BinTreeNode<T>* left_child = NULL, BinTreeNode<T>* right_child = NULL) :
        data(data), left_child(left_child), right_child(right_child) {}

    T data; //!< 二叉树结点数据项
    BinTreeNode<T>* left_child; //!< 左孩子结点指针
    BinTreeNode<T>* right_child; //!< 右孩子结点指针
};


/*!
 * @brief 后序遍历栈结点模板类
 * @tparam T 类型模板参数
 */
template <class T>
struct PostOrderStackNode {
    /*! @brief 构造函数 */
    explicit PostOrderStackNode(BinTreeNode<T>* node = NULL) {
        this->node = node;
        tag = LEFT;
    }

    BinTreeNode<T>* node; //!< 二叉树结点指针
    enum { LEFT, RIGHT } tag; //!< 标签
};


/*!
 * @brief 二叉树模板类
 * @tparam T 类型模板参数
 */
template <class T>
class BinaryTree {
public:
    /*! @brief 构造函数(无参数) */
    BinaryTree() : root_(NULL) {}
    /*! @brief 构造函数(根节点数据项) */
    BinaryTree(T data) { this->SubTreeInsert_(this->root_, data); }
    /*! @brief 复制构造函数 */
    BinaryTree(const BinaryTree<T>& bin_tree) { this->root_ = this->Copy_(bin_tree.Root()); }
    /*! @brief 析构函数 */
    ~BinaryTree() { this->SubTreeDestroy_(root_); }

    /* 基础函数 */
    /*!
     * @brief 获取根节点
     * @return 根结点指针
     * */
    BinTreeNode<T>* Root() const { return this->root_; }

    /*!
     * @brief 是否为空树
     * @return 是否为空
     */
    bool IsEmpty() { return this->root_ == NULL; }

    /*!
     * @brief 获取根节点
     * @return 根结点指针
     */
    BinTreeNode<T>* GetRoot() const { return this->root_; }

    /*!
     * @brief获取父节点
     * @return 父节点指针
     */
    BinTreeNode<T>* Parent(BinTreeNode<T>* node) {
        return (this->root_ == NULL || this->root_ == node) ? NULL : this->Parent_(this->root_, node);
    }

    /*!
     * @brief 左孩子
     * @return 左孩子指针
     */
    BinTreeNode<T>* LeftChild(BinTreeNode<T>* node) { return (node != NULL) ? node->left_child : NULL; }

    /*!
     * @brief 左孩子
     * @return 左孩子指针
     */
    BinTreeNode<T>* RightChild(BinTreeNode<T>* node) { return (node != NULL) ? node->right_child : NULL; }

    /*!
     * @brief 获取树的高度
     * @return 高度
     */
    int Height() { return this->SubTreeHeight_(this->root_); }

    /*!
     * @brief 获取树的结点数
     * @return 结点数
     */
    int Size() { return this->SubTreeSize_(this->root_); }

    /*!
     * @brief 插入结点
     * @param data 数据项
     * @return 是否成功
     */
    bool Insert(T data) { return this->SubTreeInsert_(this->root_, data); }

    /*!
     * @brief 查询数据项
     * @param data 数据
     * @return 是否在树中
     */
    bool Find(T data) { return this->SubTreeFind_(this->root_, data); }

    /* 遍历系列 */
    /*!
     * @brief 前序遍历(使用递归)
     * @param visit 结点遍历函数
     */
    void PreOrder(void (*visit)(BinTreeNode<T>* node)) { this->SubTreePreOrder_(this->root_, visit); }

    /*!
     * @brief 前序遍历(使用非递归)
     * @param visit 结点遍历函数
     */
    void PreOrderNonRecursive(void (*visit)(BinTreeNode<T>* node)) {
        this->SubTreePreOrderNonRecursive_(this->root_, visit);
    }

    /*!
     * @brief 中序遍历(使用递归)
     * @param visit 结点遍历函数
     */
    void InOrder(void (*visit)(BinTreeNode<T>* node)) { this->SubTreeInOrder_(this->root_, visit); }

    /*!
     * @brief 中序遍历(使用非递归)
     * @param visit 结点遍历函数
     */
    void InOrderNonRecursive(void (*visit)(BinTreeNode<T>* node)) {
        this->SubTreeInOrderNonRecursive_(this->root_, visit);
    }

    /*!
     * @brief 后序遍历(使用递归)
     * @param visit 结点遍历函数
     */
    void PostOrder(void (*visit)(BinTreeNode<T>* node)) { this->SubTreePostOrder_(this->root_, visit); }

    /*!
     * @brief 后序遍历(使用非递归)
     * @param visit 结点遍历函数
     */
    void PostOrderNonRecursive(void (*visit)(BinTreeNode<T>* node)) {
        this->SubTreePostOrderNonRecursive_(this->root_, visit);
    }

    /*!
     * @brief 层序遍历
     * @param visit 结点遍历函数
     */
    void LevelOrder(void (*visit)(BinTreeNode<T>* node)) { this->SubTreeLevelOrder_(this->root_, visit); }

    /*!
     * @brief 使用前序遍历和中序遍历结果, 创建二叉树
     * @param pre_order_str 前序遍历字符串
     * @param in_order_str 中序遍历字符串
     * @param str_length 字符串长度
     */
    void CreateBinTreeByPreAndInOrderString(T* pre_order_str, T* in_order_str, int str_length) {
        this->CreateSubBinTreeByPreAndInOrderString_(pre_order_str, in_order_str, str_length, this->root_);
    }

    /* 打印输出系列 */
    /*!
     * @brief 打印二叉树(使用'(', ',',')')
     */
    void Print() { this->SubTreePrint_(this->root_); };

    /*!
     * @brief 使用输入流创建二叉树
     * @param in 输入流
     */
    void CreateBinTree(istream& in) { this->CreateBinTree_(in, this->root_); }

    //
    // void Traverse(BinTreeNode<T>* sub_tree_root, ostream& out);

    /*! 我们是CyberDash:-) */
    void CyberDashShow();

    // 判断两颗二叉树是否相同(递归)
    static bool Equal(BinTreeNode<T>* root_ptr_a, BinTreeNode<T>* root_ptr_b);

protected:
    BinTreeNode<T>* root_; //!< 根结点

    // void CreateBinTree_(istream& in, BinTreeNode<T>*& subTree);

    // 子树插入数据
    bool SubTreeInsert_(BinTreeNode<T>*& sub_tree_root, T data);
    // 删除子树
    void SubTreeDestroy_(BinTreeNode<T>*& sub_tree_root);
    // 查找数据是否在(子)树中(递归)
    bool SubTreeFind_(BinTreeNode<T>* sub_tree_root, T value) const;
    // 复制二叉树
    BinTreeNode<T>* Copy_(BinTreeNode<T>* src_sub_tree_root);
    // 求子树的高度(递归)
    int SubTreeHeight_(BinTreeNode<T>* sub_tree_root) const;
    // 求子树的Size(递归)
    int SubTreeSize_(BinTreeNode<T>* sub_tree_root) const;
    // 子树获取节点的父节点
    BinTreeNode<T>* Parent_(BinTreeNode<T>* sub_tree_root, BinTreeNode<T>* node);

    // 子树前序遍历(递归)
    void SubTreePreOrder_(BinTreeNode<T>* sub_tree_root, void (*visit)(BinTreeNode<T>* node));
    // 子树前序遍历(非递归)
    void SubTreePreOrderNonRecursive_(BinTreeNode<T>* sub_tree_root, void (*visit)(BinTreeNode<T>* node));
    // 子树中序遍历(递归)
    void SubTreeInOrder_(BinTreeNode<T>* sub_tree_root, void (*visit)(BinTreeNode<T>* node));
    // 子树中序遍历(非递归)
    void SubTreeInOrderNonRecursive_(BinTreeNode<T>* sub_tree_root, void (*visit)(BinTreeNode<T>* node));
    // 子树后序遍历(递归)
    void SubTreePostOrder_(BinTreeNode<T>* sub_tree_root, void (*visit)(BinTreeNode<T>* node));
    // 子树后序遍历(非递归)
    void SubTreePostOrderNonRecursive_(BinTreeNode<T>* sub_tree_root, void (*visit)(BinTreeNode<T>* node));
    // 子树层序遍历
    void SubTreeLevelOrder_(BinTreeNode<T>* sub_tree_root, void (*visit)(BinTreeNode<T>* node));
    // 子树打印
    void SubTreePrint_(BinTreeNode<T>* sub_tree_root);

    // 使用前序遍历和中序遍历结果, 创建二叉子树(递归)
    void CreateSubBinTreeByPreAndInOrderString_(T* pre_order_str, T* in_order_str,
        int str_length, BinTreeNode<T>*& sub_tree_root);

    // 判断两颗树相同
    template<class U>
    friend bool operator == (const BinaryTree<T>& bin_tree_1, const BinaryTree<T>& bin_tree_2);
    // 输入二叉树
    template<class U>
    friend istream& operator >> (istream& in, BinaryTree<T>& bin_tree);
    // 输出二叉树
    template<class U>
    friend ostream& operator << (ostream& out, BinaryTree<T>& bin_tree);
};


/*!
 * @brief 子树插入数据
 * @tparam T 类型模板参数
 * @param sub_tree_root 子树根结点
 * @param data 结点数据项
 * @return 是否插入成功
 */
template<class T>
bool BinaryTree<T>::SubTreeInsert_(BinTreeNode<T>*& sub_tree_root, T data) {

    if (sub_tree_root == NULL) {
        sub_tree_root = new BinTreeNode<T>(data);
        if (sub_tree_root == NULL) {
            cerr << "存储分配错误!" << endl;
            return false;
        }

        return true;
    }

    bool insert_done = false;

    int left_sub_tree_height = SubTreeHeight_(sub_tree_root->left_child);
    int right_sub_tree_height = SubTreeHeight_(sub_tree_root->right_child);

    if (left_sub_tree_height > right_sub_tree_height) {
        insert_done = SubTreeInsert_(sub_tree_root->right_child, data);
    }
    else {
        insert_done = SubTreeInsert_(sub_tree_root->left_child, data);
    }

    return insert_done;
}


/*!
 * @brief 删除子树
 * @param sub_tree_root 子树根节点
 */
template <class T>
void BinaryTree<T>::SubTreeDestroy_(BinTreeNode<T>*& sub_tree_root) {
    if (sub_tree_root == NULL) {
        return;
    }

    this->SubTreeDestroy_(sub_tree_root->left_child);
    this->SubTreeDestroy_(sub_tree_root->right_child);

    delete sub_tree_root;
    sub_tree_root = NULL;
}


/**
 * @brief 查找数据是否在(子)树中(递归)
 * @tparam T 结点数据模板类型
 * @param sub_tree_root 子树根节点指针
 * @param value 被查找数据
 * @return 是否存在
 */
template<class T>
bool BinaryTree<T>::SubTreeFind_(BinTreeNode<T>* sub_tree_root, T value) const {

    if (sub_tree_root == NULL) {
        return false;
    }

    if (sub_tree_root->data == value) {
        return true;
    }

    if (SubTreeFind_(sub_tree_root->left_child, value)) {
        return true;
    }

    return SubTreeFind_(sub_tree_root->right_child, value);
}


/*!
 * @brief 复制二叉树(递归)
 * @tparam T 类型模板参数
 * @param src_sub_tree_root 源树根节点
 * @return 新树根节点
 */
template<class T>
BinTreeNode<T>* BinaryTree<T>::Copy_(BinTreeNode<T>* src_sub_tree_root) {
    if (src_sub_tree_root == NULL) {
        return NULL;
    }

    BinTreeNode<T>* new_sub_tree_root = new BinTreeNode<T>();
    /* Null handler */

    new_sub_tree_root->data = src_sub_tree_root->data;
    new_sub_tree_root->left_child = this->Copy_(src_sub_tree_root->left_child);
    new_sub_tree_root->right_child = this->Copy_(src_sub_tree_root->right_child);

    return new_sub_tree_root;
}


/*!
 * @brief 求子树的高度(递归)
 * @tparam T 节点数据模板类型
 * @param sub_tree_root 子树根节点指针
 * @return 子树高度
 */
template<class T>
int BinaryTree<T>::SubTreeHeight_(BinTreeNode<T>* sub_tree_root) const {
    // 如果子树根节点为空, 则返回0
    if (sub_tree_root == NULL) {
        return 0;
    }

    int left_sub_tree_height = SubTreeHeight_(sub_tree_root->left_child); // 递归求左子树高度
    int right_sub_tree_height = SubTreeHeight_(sub_tree_root->right_child); // 递归求右子树高度

    // 树高度 = 最高的左右子树高度 + 1
    if (left_sub_tree_height < right_sub_tree_height) {
        return right_sub_tree_height + 1;
    }
    else {
        return left_sub_tree_height + 1;
    }
}


/*!
 * @brief 求子树的size(递归)
 * @tparam T 节点数据模板类型
 * @param sub_tree_root 子树根节点指针
 * @return 子树size
 */
template<class T>
int BinaryTree<T>::SubTreeSize_(BinTreeNode<T>* sub_tree_root) const {
    if (sub_tree_root == NULL) {
        return 0;
    }

    int left_sub_tree_size = SubTreeSize_(sub_tree_root->left_child); // 递归求左子树size
    int right_sub_tree_size = SubTreeSize_(sub_tree_root->right_child); // 递归求右子树size

    int sub_tree_size = 1 + left_sub_tree_size + right_sub_tree_size;

    return sub_tree_size;
}


/*!
 * @brief 子树获取节点的父节点
 * @tparam T 节点数据模板类型
 * @param sub_tree_root 子树根节点指针
 * @param node 节点指针
 * @return 节点的(位于子树内的)父节点指针
 */
template<class T>
BinTreeNode<T>* BinaryTree<T>::Parent_(BinTreeNode<T>* sub_tree_root, BinTreeNode<T>* node) {

    // 如果子树根为NULL, 则返回NULL
    if (sub_tree_root == NULL) {
        return NULL;
    }

    // 如果子树根的左孩子or右孩子, 就是node_ptr的父节点, 则返回子树根结点
    if (sub_tree_root->left_child == node || sub_tree_root->right_child == node) {
        return sub_tree_root;
    }

    BinTreeNode<T>* parent = this->Parent_(sub_tree_root->left_child, node);

    if (parent == NULL) {
        parent = Parent_(sub_tree_root->right_child, node);
    }

    return parent;
}


/*
template<class T>
void BinaryTree<T>::Traverse(BinTreeNode<T> *sub_tree_root, ostream& out) {
  if (sub_tree_root != NULL) {
    out << sub_tree_root->data << ' ';
    Traverse(sub_tree_root->left_child, out);
    Traverse(sub_tree_root->right_child, out);
  }
}
 */


 /*!
  * @brief 子树前序遍历(递归)
  * @tparam T 节点数据模板类型
  * @param sub_tree_root 子树根节点指针
  * @param visit 访问函数
  */
template<class T>
void BinaryTree<T>::SubTreePreOrder_(BinTreeNode<T>* sub_tree_root, void (*visit)(BinTreeNode<T>* node)) {
    if (sub_tree_root == NULL) {
        return;
    }

    visit(sub_tree_root);

    SubTreePreOrder_(sub_tree_root->left_child, visit);
    SubTreePreOrder_(sub_tree_root->right_child, visit);
}


/**
 * @brief 子树前序遍历(非递归)
 * @tparam T 节点数据模板类型
 * @param sub_tree_root 子树根节点指针
 * @param visit 访问函数
 */
template<class T>
void BinaryTree<T>::SubTreePreOrderNonRecursive_(BinTreeNode<T>* sub_tree_root, void (*visit)(BinTreeNode<T>*)) {

    // (栈初始化)声明前序遍历栈, 子树根节点指针入栈
    stack<BinTreeNode<T>*> pre_traverse_stack;
    pre_traverse_stack.push(sub_tree_root);

    while (!pre_traverse_stack.empty()) {

        // 出栈
        BinTreeNode<T>* cur_node_ptr = pre_traverse_stack.top();
        pre_traverse_stack.pop();

        // 访问
        visit(cur_node_ptr);

        // 孩子节点入栈
        if (cur_node_ptr->right_child != NULL) {
            pre_traverse_stack.push(cur_node_ptr->right_child);
        }

        if (cur_node_ptr->left_child != NULL) {
            pre_traverse_stack.push(cur_node_ptr->left_child);
        }
    }
}


/*!
 * @brief 子树中序遍历(递归)
 * @tparam T 节点数据模板类型
 * @param sub_tree_root 子树根节点指针
 * @param visit 访问函数
 */
template<class T>
void BinaryTree<T>::SubTreeInOrder_(BinTreeNode<T>* sub_tree_root,
    void (*visit)(BinTreeNode<T>*))
{
    if (sub_tree_root == NULL) {
        return;
    }

    SubTreeInOrder_(sub_tree_root->left_child, visit);

    visit(sub_tree_root);

    SubTreeInOrder_(sub_tree_root->right_child, visit);
}


/**
 * @brief 子树中序遍历(非递归)
 * @tparam T 节点数据模板类型
 * @param sub_tree_root 子树根节点指针
 * @param visit 访问函数
 */
template<class T>
void BinaryTree<T>::SubTreeInOrderNonRecursive_(BinTreeNode<T>* sub_tree_root, void (*visit)(BinTreeNode<T>* node)) {

    stack<BinTreeNode<T>*> in_traverse_stack;
    BinTreeNode<T>* cur_node = sub_tree_root;

    while (cur_node != NULL || !in_traverse_stack.empty()) {

        while (cur_node != NULL) {
            in_traverse_stack.push(cur_node);
            cur_node = cur_node->left_child;
        }

        if (!in_traverse_stack.empty()) {

            cur_node = in_traverse_stack.top();
            in_traverse_stack.pop();

            visit(cur_node);

            cur_node = cur_node->right_child;
        }
    }
}


/*!
 * @brief 子树后序遍历(递归)
 * @tparam T 节点数据模板类型
 * @param sub_tree_root 子树根节点指针
 * @param visit 访问函数
 */
template<class T>
void BinaryTree<T>::SubTreePostOrder_(BinTreeNode<T>* sub_tree_root,
    void (*visit)(BinTreeNode<T>*))
{
    if (sub_tree_root == NULL) {
        return;
    }

    SubTreePostOrder_(sub_tree_root->left_child, visit);
    SubTreePostOrder_(sub_tree_root->right_child, visit);

    visit(sub_tree_root);
}


/**
 * @brief 子树后序遍历(非递归)
 * @tparam T 节点数据模板类型
 * @param sub_tree_root 子树根节点指针
 * @param visit 访问函数
 */
template <class T>
void BinaryTree<T>::SubTreePostOrderNonRecursive_(BinTreeNode<T>* sub_tree_root, void (*visit)(BinTreeNode<T>*)) {

    stack<PostOrderStackNode<T> > post_traverse_stack;

    BinTreeNode<T>* cur_node = sub_tree_root;

    do {
        while (cur_node != NULL) {
            PostOrderStackNode<T> traverse_node(cur_node);
            post_traverse_stack.push(traverse_node);
            cur_node = cur_node->left_child;
        }

        bool left_unfinished = true;
        while (left_unfinished && !post_traverse_stack.empty()) {

            PostOrderStackNode<T> cur_traverse_node = post_traverse_stack.top();
            post_traverse_stack.pop();

            cur_node = cur_traverse_node.node;

            switch (cur_traverse_node.tag) {
            case PostOrderStackNode<T>::LEFT:
                cur_traverse_node.tag = PostOrderStackNode<T>::RIGHT;
                post_traverse_stack.push(cur_traverse_node);
                cur_node = cur_node->right_child;

                left_unfinished = false;

                break;
            case PostOrderStackNode<T>::RIGHT:
                visit(cur_node);

                break;
            }
        }
    } while (!post_traverse_stack.empty());
}


/**
 * @brief 子树层序遍历
 * @tparam T 节点数据模板类型
 * @param sub_tree_root 子树根节点指针
 * @param visit 访问函数
 */
template<class T>
void BinaryTree<T>::SubTreeLevelOrder_(BinTreeNode<T>* sub_tree_root, void (*visit)(BinTreeNode<T>* node_ptr)) {

    queue<BinTreeNode<T>*> level_traverse_queue;

    BinTreeNode<T>* cur_node = sub_tree_root;
    level_traverse_queue.push(cur_node);

    while (!level_traverse_queue.empty()) {
        cur_node = level_traverse_queue.front();
        level_traverse_queue.pop();

        visit(cur_node);

        if (cur_node->left_child != NULL) {
            level_traverse_queue.push(cur_node->left_child);
        }

        if (cur_node->right_child != NULL) {
            level_traverse_queue.push(cur_node->right_child);
        }
    }
}


/*!
 * @brief 子树打印
 * @tparam T 结点数据模板类型
 * @param sub_tree_root 子树根节点
 */
template<class T>
void BinaryTree<T>::SubTreePrint_(BinTreeNode<T>* sub_tree_root) {

    if (sub_tree_root == NULL) {
        return;
    }

    cout << sub_tree_root->data;

    if (sub_tree_root->left_child != NULL || sub_tree_root->right_child != NULL) {

        cout << '(';

        this->SubTreePrint_(sub_tree_root->left_child);

        cout << ',';

        if (sub_tree_root->right_child != NULL) {
            this->SubTreePrint_(sub_tree_root->right_child);
        }

        cout << ')';
    }
}


/*!
 * @brief 使用前序遍历和中序遍历结果, 创建二叉子树(递归)
 * @param pre_order_str 前序遍历字符串
 * @param in_order_str 后序遍历字符串
 * @param str_length 字符串长度
 * @param sub_tree_root 子树根结点
 */
template<class T>
void BinaryTree<T>::CreateSubBinTreeByPreAndInOrderString_(T* pre_order_str, T* in_order_str,
    int str_length, BinTreeNode<T>*& sub_tree_root)
{
    if (str_length == 0) {
        return;
    }

    int pivot = 0;
    T cur_root_value = pre_order_str[0];

    while (cur_root_value != in_order_str[pivot]) {
        pivot++;
    }

    sub_tree_root = new BinTreeNode<T>(cur_root_value);
    if (sub_tree_root == NULL) {
        cerr << "存储分配错误!" << endl;
        exit(1);
    }

    CreateSubBinTreeByPreAndInOrderString_(pre_order_str + 1,
        in_order_str,
        pivot,
        sub_tree_root->left_child);

    CreateSubBinTreeByPreAndInOrderString_(pre_order_str + pivot + 1,
        in_order_str + pivot + 1,
        str_length - pivot - 1,
        sub_tree_root->right_child);
}


/*!
 * @brief 判断两颗二叉树是否相同(递归)
 * @tparam T 结点数据模板类型
 * @param root_ptr_a 根节点a
 * @param root_ptr_b 根节点2
 * @return 是否相同
 */
template<class T>
bool BinaryTree<T>::Equal(BinTreeNode<T>* root_ptr_a, BinTreeNode<T>* root_ptr_b) {
    if (root_ptr_a == NULL && root_ptr_b == NULL) {
        return true;
    }

    if (root_ptr_a != NULL && root_ptr_b != NULL && root_ptr_a->data == root_ptr_b->data
        && BinaryTree<T>::Equal(root_ptr_a->left_child, root_ptr_b->left_child)
        && BinaryTree<T>::Equal(root_ptr_a->right_child, root_ptr_b->right_child))
    {
        return true;
    }
    else {
        return false;
    }
}


/*
template<class T>
void BinaryTree<T>::CreateBinTree_(istream& in, BinTreeNode<T>*& subTree) {
  T item;

  if (!in.eof()) {
    in >> item;
    if (item != value_) {
      subTree = new BinTreeNode<T>(item);
      if(subTree == NULL) {
        cerr << "存储分配错误!" << endl;
        exit(1);
      }
      CreateBinTree_(in, subTree->left_child);
      CreateBinTree_(in, subTree->right_child);
    } else {
      subTree = NULL;
    }
  }
}
 */


 /*!
  * @brief 重载==
  * @tparam T 类型模板参数
  * @param bin_tree_1 二叉树1
  * @param bin_tree_2 二叉树2
  * @return
  */
template<class T>
bool operator == (const BinaryTree<T>& bin_tree_1, const BinaryTree<T>& bin_tree_2) {
    return (BinaryTree<T>::Equal(bin_tree_1.GetRoot(), bin_tree_2.GetRoot()));
}


template<class T>
istream& operator >> (istream& in, BinaryTree<T>& Tree) {
    Tree.CreateBinTree(in);
    return in;
}


template<class T>
ostream& operator << (ostream& out, BinaryTree<T>& Tree) {
    out << "二叉树的前序遍历\n";
    Tree.Traverse(Tree.GetRoot(), out);
    out << endl;
    return out;
}


/**
 * 我们是CyberDash :-)
 */
template<class T>
void BinaryTree<T>::CyberDashShow() {
    cout << endl
        << "*************************************** CyberDash ***************************************" << endl << endl
        << "抖音号\"CyberDash计算机考研\", id: cyberdash_yuan" << endl << endl
        << "CyberDash成员:" << endl
        << "元哥(cyberdash@163.com), " << "北京邮电大学(通信工程本科)/北京邮电大学(信息与通信系统研究生)" << endl
        << "磊哥(alei_go@163.com), " << "山东理工大学(数学本科)/北京邮电大学(计算机研究生)" << endl << endl
        << "L_Dash(yuleen_@outlook.com), " << "北京邮电大学(计算机研究生在读)" << endl << endl
        << "数据结构开源代码(C++清华大学殷人昆)魔改升级版本: https://gitee.com/cyberdash/data-structure-cpp" << endl
        << endl << "*************************************** CyberDash ***************************************" << endl << endl;
}


#endif //CYBER_DASH_BINARY_TREE_H
