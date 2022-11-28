/*!
 * @file binary_tree.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 二叉树模板类
 * @version 0.2.1
 * @date 2020-11-01
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
 * @tparam TData 数据项类型模板参数
 */
template <class TData>
struct BinaryTreeNode {
    /*!
     * @brief 默认构造函数
     * @note
     */
    BinaryTreeNode() : left_child(NULL), right_child(NULL) {}
    /*! @brief 构造函数(数据项和左右孩子) */
    BinaryTreeNode(TData data, BinaryTreeNode<TData>* left_child = NULL, BinaryTreeNode<TData>* right_child = NULL) :
        data(data), left_child(left_child), right_child(right_child) {}

    TData data;                           //!< 二叉树结点数据项
    BinaryTreeNode<TData>* left_child;    //!< 左孩子结点指针
    BinaryTreeNode<TData>* right_child;   //!< 右孩子结点指针
};


/*!
 * @brief 后序遍历栈结点模板类
 * @tparam TData 数据项类型模板参数
 */
template <class TData>
struct PostOrderStackNode {
    /*! @brief 构造函数 */
    explicit PostOrderStackNode(BinaryTreeNode<TData>* node = NULL) : node(node), tag(LEFT) {}

    BinaryTreeNode<TData>* node;    //!< 二叉树结点指针
    enum { LEFT, RIGHT } tag;       //!< 标签
};


/*!
 * @brief 二叉树模板类
 * @tparam TData 类型模板参数
 */
template <class TData>
class BinaryTree {
public:
    /*! @brief 默认构造函数*/
    BinaryTree() : root_(NULL) {}
    /*! @brief 构造函数(根节点数据项) */
    BinaryTree(const TData& data) { this->InsertInSubTreeRecursive_(this->root_, data); }
    /*! @brief 复制构造函数 */
    BinaryTree(const BinaryTree<TData>& binary_tree);
    /*! @brief 析构函数 */
    ~BinaryTree() { this->DestroySubTreeRecursive_(root_); }

    /* 基础函数 */
    /*!
     * @brief 获取根节点
     * @return 根结点指针
     * */
    BinaryTreeNode<TData>* Root() const { return this->root_; }

    /*!
     * @brief 是否为空树
     * @return 是否为空
     */
    bool IsEmpty() { return this->root_ == NULL; }

    /*!
     * @brief 获取根节点
     * @return 根结点指针
     */
    BinaryTreeNode<TData>* GetRoot() const { return this->root_; }

    /*!
     * @brief获取父节点
     * @return 父节点指针
     */
    BinaryTreeNode<TData>* Parent(BinaryTreeNode<TData>* node) const {
        return (this->root_ == NULL || this->root_ == node) ? NULL : this->Parent_(this->root_, node);
    }

    /*!
     * @brief 左孩子
     * @return 左孩子指针
     */
    BinaryTreeNode<TData>* LeftChild(BinaryTreeNode<TData>* node) { return (node != NULL) ? node->left_child : NULL; }

    /*!
     * @brief 左孩子
     * @return 左孩子指针
     */
    BinaryTreeNode<TData>* RightChild(BinaryTreeNode<TData>* node) { return (node != NULL) ? node->right_child : NULL; }

    /*!
     * @brief 获取树的高度
     * @return 高度
     */
    int Height() { return this->HeightOfSubTreeRecursive_(this->root_); }

    /*!
     * @brief 获取树的结点数
     * @return 结点数
     */
    int Size() { return this->SizeOfSubTree_(this->root_); }

    /*!
     * @brief 插入结点
     * @param data 数据项
     * @return 是否成功
     */
    bool Insert(const TData& data) { return this->InsertInSubTreeRecursive_(this->root_, data); }

    /*!
     * @brief 查询数据项
     * @param data 数据
     * @return 是否在树中
     */
    bool Exist(TData data) { return this->ExistInSubTree_(this->root_, data); }

    /* 遍历系列 */
    /*!
     * @brief 前序遍历(使用递归)
     * @param visit 结点遍历函数
     */
    void PreOrderTraversal(void (*visit)(BinaryTreeNode<TData>* node)) {
        this->PreOrderTraversalOfSubTreeRecursive_(this->root_, visit);
    }

    /*!
     * @brief 前序遍历(使用非递归)
     * @param visit 结点遍历函数
     */
    void PreOrderTraversalNonRecursive(void (*visit)(BinaryTreeNode<TData>* node)) {
        this->PreOrderTraversalOfSubTreeNonRecursive_(this->root_, visit);
    }

    /*!
     * @brief 中序遍历(使用递归)
     * @param visit 结点遍历函数
     */
    void InOrderTraversal(void (*visit)(BinaryTreeNode<TData>* node)) {
        this->InOrderTraversalOfSubTreeRecursive_(this->root_, visit);
    }

    /*!
     * @brief 中序遍历(使用非递归)
     * @param visit 结点遍历函数
     */
    void InOrderTraversalNonRecursive(void (*visit)(BinaryTreeNode<TData>* node)) {
        this->InOrderTraversalOfSubTreeNonRecursive_(this->root_, visit);
    }

    /*!
     * @brief 后序遍历(使用递归)
     * @param visit 结点遍历函数
     */
    void PostOrderTraversal(void (*visit)(BinaryTreeNode<TData>* node)) {
        this->PostOrderTraversalOfSubtreeRecursive_(this->root_, visit);
    }

    /*!
     * @brief 后序遍历(使用非递归)
     * @param visit 结点遍历函数
     */
    void PostOrderTraversalNonRecursive(void (*visit)(BinaryTreeNode<TData>* node)) {
        this->PostOrderTraversalOfSubtreeNonRecursive_(this->root_, visit);
    }

    /*!
     * @brief 层序遍历
     * @param visit 结点遍历函数
     */
    void LevelOrderTraversal(void (*visit)(BinaryTreeNode<TData>* node)) {
        this->LevelOrderTraversalOfSubtree_(this->root_, visit);
    }

    /*!
     * @brief 使用前序遍历和中序遍历结果, 创建二叉树
     * @param preorder_list 前序遍历字符串
     * @param inorder_list 中序遍历字符串
     * @param length 字符串长度
     */
    void CreateByPreorderAndInorderList(TData* preorder_list, TData* inorder_list, int length) {
        this->CreateSubtreeByPreorderAndInorderList_(preorder_list, inorder_list, length, this->root_);
    }

    /* 打印输出系列 */
    /*!
     * @brief 打印二叉树(使用'(', ',',')')
     */
    void Print() { this->PrintSubTree_(this->root_); };

    // 使用输入流创建二叉树
    // void CreateByInStream(istream& in) { this->CreateBinTree_(in, this->root_); }

    // 判断两颗二叉树是否相同(递归)
    static bool Equal(BinaryTreeNode<TData>* root_a, BinaryTreeNode<TData>* root_b);

protected:
    BinaryTreeNode<TData>* root_; //!< 根结点

    // void CreateBinTree_(istream& in, BinaryTreeNode<TData>*& subTree);

    // 子树插入数据
    bool InsertInSubTreeRecursive_(BinaryTreeNode<TData>*& sub_tree_root, TData data);
    // 删除子树
    void DestroySubTreeRecursive_(BinaryTreeNode<TData>*& sub_tree_root);
    // 查找数据是否在(子)树中(递归)
    bool ExistInSubTree_(BinaryTreeNode<TData>* sub_tree_root, TData value) const;
    // 复制二叉树
    bool DuplicateSubTreeRecursive_(BinaryTreeNode<TData>* src_subtree_root, BinaryTreeNode<TData>*& target_subtree_root);
    // 求子树的高度(递归)
    int HeightOfSubTreeRecursive_(BinaryTreeNode<TData>* sub_tree_root) const;
    // 求子树的Size(递归)
    int SizeOfSubTree_(BinaryTreeNode<TData>* sub_tree_root) const;
    // 子树获取节点的父节点
    BinaryTreeNode<TData>* Parent_(BinaryTreeNode<TData>* sub_tree_root, BinaryTreeNode<TData>* node) const;

    // 子树前序遍历(递归)
    void PreOrderTraversalOfSubTreeRecursive_(BinaryTreeNode<TData>* sub_tree_root,
                                              void (*visit)(BinaryTreeNode<TData>* node));
    // 子树前序遍历(非递归)
    void PreOrderTraversalOfSubTreeNonRecursive_(BinaryTreeNode<TData>* sub_tree_root,
                                                 void (*visit)(BinaryTreeNode<TData>* node));
    // 子树中序遍历(递归)
    void InOrderTraversalOfSubTreeRecursive_(BinaryTreeNode<TData>* sub_tree_root,
                                             void (*visit)(BinaryTreeNode<TData>* node));
    // 子树中序遍历(非递归)
    void InOrderTraversalOfSubTreeNonRecursive_(BinaryTreeNode<TData>* sub_tree_root,
                                                void (*visit)(BinaryTreeNode<TData>* node));
    // 子树后序遍历(递归)
    void PostOrderTraversalOfSubtreeRecursive_(BinaryTreeNode<TData>* sub_tree_root,
                                               void (*visit)(BinaryTreeNode<TData>* node));
    // 子树后序遍历(非递归)
    void PostOrderTraversalOfSubtreeNonRecursive_(BinaryTreeNode<TData>* sub_tree_root,
                                                  void (*visit)(BinaryTreeNode<TData>* node));
    // 子树层序遍历
    void LevelOrderTraversalOfSubtree_(BinaryTreeNode<TData>* sub_tree_root,
                                       void (*visit)(BinaryTreeNode<TData>* node));
    // 子树打印
    void PrintSubTree_(BinaryTreeNode<TData>* sub_tree_root);

    // 使用前序遍历和中序遍历结果, 创建二叉子树(递归)
    void CreateSubtreeByPreorderAndInorderList_(TData* preorder_list,
                                                TData* inorder_list,
                                                int length,
                                                BinaryTreeNode<TData>*& sub_tree_root);

    // 判断两颗树相同
    template<class TData>
    friend bool operator == (const BinaryTree<TData>& bin_tree_1, const BinaryTree<TData>& bin_tree_2);
    // 输入二叉树
    // template<class TData>
    // friend istream& operator >> (istream& in, BinaryTree<TData>& bin_tree);
    // 输出二叉树
    template<class TData>
    friend ostream& operator << (ostream& out, BinaryTree<TData>& bin_tree);
};


template<class TData>
BinaryTree<TData>::BinaryTree(const BinaryTree<TData>& binary_tree) {
    bool res = this->DuplicateSubTreeRecursive_(binary_tree.Root(), this->root_);
    if (!res) {
        throw std::exception("DuplicateSubTreeRecursive_ error");
    }
}


/*!
 * @brief 子树插入数据
 * @tparam TData 类型模板参数
 * @param sub_tree_root 子树根结点
 * @param data 结点数据项
 * @return 是否插入成功
 */
template<class TData>
bool BinaryTree<TData>::InsertInSubTreeRecursive_(BinaryTreeNode<TData>*& sub_tree_root, TData data) {

    if (sub_tree_root == NULL) {
        sub_tree_root = new BinaryTreeNode<TData>(data);
        if (sub_tree_root == NULL) {
            cerr << "存储分配错误!" << endl;
            return false;
        }

        return true;
    }

    bool res = false;

    int left_sub_tree_height = HeightOfSubTreeRecursive_(sub_tree_root->left_child);
    int right_sub_tree_height = HeightOfSubTreeRecursive_(sub_tree_root->right_child);

    if (left_sub_tree_height > right_sub_tree_height) {
        res = InsertInSubTreeRecursive_(sub_tree_root->right_child, data);
        if (!res) {
            return false;
        }
    } else {
        res = InsertInSubTreeRecursive_(sub_tree_root->left_child, data);
        if (!res) {
            return false;
        }
    }

    return true;
}


/*!
 * @brief 删除子树
 * @param sub_tree_root 子树根节点
 */
template <class T>
void BinaryTree<T>::DestroySubTreeRecursive_(BinaryTreeNode<T>*& sub_tree_root) {
    if (sub_tree_root == NULL) {
        return;
    }

    this->DestroySubTreeRecursive_(sub_tree_root->left_child);
    this->DestroySubTreeRecursive_(sub_tree_root->right_child);

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
bool BinaryTree<T>::ExistInSubTree_(BinaryTreeNode<T>* sub_tree_root, T value) const {

    if (sub_tree_root == NULL) {
        return false;
    }

    if (sub_tree_root->data == value) {
        return true;
    }

    if (ExistInSubTree_(sub_tree_root->left_child, value)) {
        return true;
    }

    return ExistInSubTree_(sub_tree_root->right_child, value);
}


 /*!
  * @brief **复制二叉树(递归)**
  * @tparam TData
  * @param src_subtree_root
  * @param target_subtree_root
  * @return
  */
template<class TData>
bool BinaryTree<TData>::DuplicateSubTreeRecursive_(BinaryTreeNode<TData>* src_subtree_root,
                                                   BinaryTreeNode<TData>*& target_subtree_root)
{
    if (src_subtree_root == NULL) {
        target_subtree_root = NULL;
        return true;
    }

    target_subtree_root = new BinaryTreeNode<TData>(src_subtree_root->data);
    if (!target_subtree_root) {
        return false;
    }

    bool res = this->DuplicateSubTreeRecursive_(src_subtree_root->left_child, target_subtree_root->left_child);
    if (!res) {
        return false;
    }

    res = this->DuplicateSubTreeRecursive_(src_subtree_root->right_child, target_subtree_root->right_child);
    if (!res) {
        return false;
    }

    return true;
}


/*!
 * @brief 求子树的高度(递归)
 * @tparam TData 节点数据模板类型
 * @param sub_tree_root 子树根节点指针
 * @return 子树高度
 */
template<class TData>
int BinaryTree<TData>::HeightOfSubTreeRecursive_(BinaryTreeNode<TData>* sub_tree_root) const {
    // 如果子树根节点为空, 则返回0
    if (sub_tree_root == NULL) {
        return 0;
    }

    int left_sub_tree_height = HeightOfSubTreeRecursive_(sub_tree_root->left_child); // 递归求左子树高度
    int right_sub_tree_height = HeightOfSubTreeRecursive_(sub_tree_root->right_child); // 递归求右子树高度

    // 树高度 = 最高的左右子树高度 + 1
    if (left_sub_tree_height < right_sub_tree_height) {
        return right_sub_tree_height + 1;
    } else {
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
int BinaryTree<T>::SizeOfSubTree_(BinaryTreeNode<T>* sub_tree_root) const {
    if (sub_tree_root == NULL) {
        return 0;
    }

    int left_sub_tree_size = SizeOfSubTree_(sub_tree_root->left_child); // 递归求左子树size
    int right_sub_tree_size = SizeOfSubTree_(sub_tree_root->right_child); // 递归求右子树size

    int sub_tree_size = 1 + left_sub_tree_size + right_sub_tree_size;

    return sub_tree_size;
}


/*!
 * @brief 子树获取节点的父节点
 * @tparam TData 节点数据模板类型
 * @param sub_tree_root 子树根节点指针
 * @param node 节点指针
 * @return 节点的(位于子树内的)父节点指针
 */
template<class TData>
BinaryTreeNode<TData>* BinaryTree<TData>::Parent_(BinaryTreeNode<TData>* sub_tree_root, BinaryTreeNode<TData>* node) const {

    // 如果子树根为NULL, 则返回NULL
    if (sub_tree_root == NULL) {
        return NULL;
    }

    // 如果子树根的左孩子or右孩子, 就是node_ptr的父节点, 则返回子树根结点
    if (sub_tree_root->left_child == node || sub_tree_root->right_child == node) {
        return sub_tree_root;
    }

    BinaryTreeNode<TData>* parent = this->Parent_(sub_tree_root->left_child, node);

    if (parent == NULL) {
        parent = Parent_(sub_tree_root->right_child, node);
    }

    return parent;
}


/*
template<class TData>
void BinaryTree<TData>::Traverse(BinaryTreeNode<TData> *sub_tree_root, ostream& out) {
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
void BinaryTree<T>::PreOrderTraversalOfSubTreeRecursive_(BinaryTreeNode<T>* sub_tree_root, void (*visit)(BinaryTreeNode<T>* node)) {
    if (sub_tree_root == NULL) {
        return;
    }

    visit(sub_tree_root);

     PreOrderTraversalOfSubTreeRecursive_(sub_tree_root->left_child, visit);
     PreOrderTraversalOfSubTreeRecursive_(sub_tree_root->right_child, visit);
}


/**
 * @brief 子树前序遍历(非递归)
 * @tparam T 节点数据模板类型
 * @param sub_tree_root 子树根节点指针
 * @param visit 访问函数
 */
template<class T>
void BinaryTree<T>::PreOrderTraversalOfSubTreeNonRecursive_(BinaryTreeNode<T>* sub_tree_root, void (*visit)(BinaryTreeNode<T>*)) {

    // (栈初始化)声明前序遍历栈, 子树根节点指针入栈
    stack<BinaryTreeNode<T>*> pre_traverse_stack;
    pre_traverse_stack.push(sub_tree_root);

    while (!pre_traverse_stack.empty()) {

        // 出栈
        BinaryTreeNode<T>* cur_node_ptr = pre_traverse_stack.top();
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
void BinaryTree<T>::InOrderTraversalOfSubTreeRecursive_(BinaryTreeNode<T>* sub_tree_root,
                                                        void (*visit)(BinaryTreeNode<T>*))
{
    if (sub_tree_root == NULL) {
        return;
    }

    InOrderTraversalOfSubTreeRecursive_(sub_tree_root->left_child, visit);

    visit(sub_tree_root);

    InOrderTraversalOfSubTreeRecursive_(sub_tree_root->right_child, visit);
}


/**
 * @brief 子树中序遍历(非递归)
 * @tparam T 节点数据模板类型
 * @param sub_tree_root 子树根节点指针
 * @param visit 访问函数
 */
template<class T>
void BinaryTree<T>::InOrderTraversalOfSubTreeNonRecursive_(BinaryTreeNode<T>* sub_tree_root, void (*visit)(BinaryTreeNode<T>* node)) {

    stack<BinaryTreeNode<T>*> in_traverse_stack;
    BinaryTreeNode<T>* cur_node = sub_tree_root;

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
void BinaryTree<T>::PostOrderTraversalOfSubtreeRecursive_(BinaryTreeNode<T>* sub_tree_root,
                                                          void (*visit)(BinaryTreeNode<T>*))
{
    if (sub_tree_root == NULL) {
        return;
    }

    PostOrderTraversalOfSubtreeRecursive_(sub_tree_root->left_child, visit);
    PostOrderTraversalOfSubtreeRecursive_(sub_tree_root->right_child, visit);

    visit(sub_tree_root);
}


/**
 * @brief 子树后序遍历(非递归)
 * @tparam T 节点数据模板类型
 * @param sub_tree_root 子树根节点指针
 * @param visit 访问函数
 */
template <class T>
void BinaryTree<T>::PostOrderTraversalOfSubtreeNonRecursive_(BinaryTreeNode<T>* sub_tree_root, void (*visit)(BinaryTreeNode<T>*)) {

    stack<PostOrderStackNode<T> > post_traverse_stack;

    BinaryTreeNode<T>* cur_node = sub_tree_root;

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
void BinaryTree<T>::LevelOrderTraversalOfSubtree_(BinaryTreeNode<T>* sub_tree_root, void (*visit)(BinaryTreeNode<T>* node_ptr)) {

    queue<BinaryTreeNode<T>*> level_traverse_queue;

    BinaryTreeNode<T>* cur_node = sub_tree_root;
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
void BinaryTree<T>::PrintSubTree_(BinaryTreeNode<T>* sub_tree_root) {

    if (sub_tree_root == NULL) {
        return;
    }

    cout << sub_tree_root->data;

    if (sub_tree_root->left_child != NULL || sub_tree_root->right_child != NULL) {

        cout << '(';

        this->PrintSubTree_(sub_tree_root->left_child);

        cout << ',';

        if (sub_tree_root->right_child != NULL) {
            this->PrintSubTree_(sub_tree_root->right_child);
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
void BinaryTree<T>::CreateSubtreeByPreorderAndInorderList_(T* pre_order_str, T* in_order_str,
                                                           int str_length, BinaryTreeNode<T>*& sub_tree_root)
{
    if (str_length == 0) {
        return;
    }

    int pivot = 0;
    T cur_root_value = pre_order_str[0];

    while (cur_root_value != in_order_str[pivot]) {
        pivot++;
    }

    sub_tree_root = new BinaryTreeNode<T>(cur_root_value);
    if (sub_tree_root == NULL) {
        cerr << "存储分配错误!" << endl;
        exit(1);
    }

    CreateSubtreeByPreorderAndInorderList_(pre_order_str + 1,
                                           in_order_str,
                                           pivot,
                                           sub_tree_root->left_child);

    CreateSubtreeByPreorderAndInorderList_(pre_order_str + pivot + 1,
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
bool BinaryTree<T>::Equal(BinaryTreeNode<T>* root_ptr_a, BinaryTreeNode<T>* root_ptr_b) {
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
template<class TData>
void BinaryTree<TData>::CreateBinTree_(istream& in, BinaryTreeNode<TData>*& subTree) {
  TData item;

  if (!in.eof()) {
    in >> item;
    if (item != value_) {
      subTree = new BinaryTreeNode<TData>(item);
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


/*
template<class T>
istream& operator >> (istream& in, BinaryTree<T>& Tree) {
    Tree.CreateByInStream(in);
    return in;
}
 */


template<class T>
ostream& operator << (ostream& out, BinaryTree<T>& Tree) {
    out << "二叉树的前序遍历\n";
    Tree.Traverse(Tree.GetRoot(), out);
    out << endl;
    return out;
}


#endif //CYBER_DASH_BINARY_TREE_H
