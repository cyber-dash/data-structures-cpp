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
 * @brief **(后序遍历)回溯栈结点模板类**
 * @tparam TData 数据项类型模板参数
 */
template <class TData>
struct BacktrackingStackNode {
    /*! @brief 构造函数 */
    explicit BacktrackingStackNode(BinaryTreeNode<TData>* node = NULL) : node(node), tag(LEFT_BACK_TRACKING) {}

    BinaryTreeNode<TData>* node;    //!< 二叉树结点指针
    enum { LEFT_BACK_TRACKING, RIGHT_BACK_TRACKING } tag;       //!< 标签
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
    // BinaryTreeNode<TData>* GetRoot() const { return this->root_; }

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
    void InorderTraversal(void (*visit)(BinaryTreeNode<TData>* node)) {
        this->InorderTraversalOfSubTreeRecursive_(this->root_, visit);
    }

    /*!
     * @brief 中序遍历(使用非递归)
     * @param visit 结点遍历函数
     */
    void InorderTraversalNonRecursive(void (*visit)(BinaryTreeNode<TData>* node)) {
        this->InorderTraversalOfSubTreeNonRecursive_(this->root_, visit);
    }

    /*!
     * @brief 后序遍历(使用递归)
     * @param visit 结点遍历函数
     */
    void PostorderTraversal(void (*visit)(BinaryTreeNode<TData>* node)) {
        this->PostorderTraversalOfSubtreeRecursive_(this->root_, visit);
    }

    /*!
     * @brief 后序遍历(使用非递归)
     * @param visit 结点遍历函数
     */
    void PostorderTraversalNonRecursive(void (*visit)(BinaryTreeNode<TData>* node)) {
        this->PostorderTraversalOfSubtreeNonRecursive_(this->root_, visit);
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
    bool CreateByPreorderAndInorderList(TData* preorder_list, TData* inorder_list, int length) {
        bool res = this->CreateSubtreeByPreorderAndInorderList_(preorder_list, inorder_list, length, this->root_);
        return res;
    }

    /* 打印输出系列 */
    /*!
     * @brief 打印二叉树(使用'(', ',',')')
     */
    void Print() { this->PrintSubTree_(this->root_); };

    // 使用输入流创建二叉树
    // void CreateByInStream(istream& in) { this->CreateBinTree_(in, this->root_); }

    // 判断两颗二叉树是否相同(递归)
    static bool Equal(BinaryTreeNode<TData>* root1, BinaryTreeNode<TData>* root2);

protected:
    BinaryTreeNode<TData>* root_; //!< 根结点

    // void CreateBinTree_(istream& in, BinaryTreeNode<TData>*& subTree);

    // 子树插入数据
    bool InsertInSubTreeRecursive_(BinaryTreeNode<TData>*& sub_tree_root, TData data);
    // 删除子树
    void DestroySubTreeRecursive_(BinaryTreeNode<TData>*& sub_tree_root);
    // 查找数据是否在(子)树中(递归)
    bool ExistInSubTree_(BinaryTreeNode<TData>* subtree_root, TData data) const;
    // 复制二叉树
    bool DuplicateSubTreeRecursive_(BinaryTreeNode<TData>* src_subtree_root, BinaryTreeNode<TData>*& target_subtree_root);
    // 求子树的高度(递归)
    int HeightOfSubTreeRecursive_(BinaryTreeNode<TData>* subtree_root) const;
    // 求子树的Size(递归)
    int SizeOfSubTree_(BinaryTreeNode<TData>* subtree_root) const;
    // 子树获取节点的父节点
    BinaryTreeNode<TData>* Parent_(BinaryTreeNode<TData>* subtree_root, BinaryTreeNode<TData>* node) const;

    // 子树前序遍历(递归)
    void PreOrderTraversalOfSubTreeRecursive_(BinaryTreeNode<TData>* subtree_root,
                                              void (*visit)(BinaryTreeNode<TData>* node));
    // 子树前序遍历(非递归)
    void PreOrderTraversalOfSubTreeNonRecursive_(BinaryTreeNode<TData>* subtree_root,
                                                 void (*visit)(BinaryTreeNode<TData>* node));
    // 子树中序遍历(递归)
    void InorderTraversalOfSubTreeRecursive_(BinaryTreeNode<TData>* sub_tree_root,
                                             void (*visit)(BinaryTreeNode<TData>* node));
    // 子树中序遍历(非递归)
    void InorderTraversalOfSubTreeNonRecursive_(BinaryTreeNode<TData>* sub_tree_root,
                                                void (*visit)(BinaryTreeNode<TData>* node));
    // 子树后序遍历(递归)
    void PostorderTraversalOfSubtreeRecursive_(BinaryTreeNode<TData>* sub_tree_root,
                                               void (*visit)(BinaryTreeNode<TData>* node));
    // 子树后序遍历(非递归)
    void PostorderTraversalOfSubtreeNonRecursive_(BinaryTreeNode<TData>* subtree_root,
                                                  void (*visit)(BinaryTreeNode<TData>* node));
    // 子树层序遍历
    void LevelOrderTraversalOfSubtree_(BinaryTreeNode<TData>* subtree_root,
                                       void (*visit)(BinaryTreeNode<TData>* node));
    // 子树打印
    void PrintSubTree_(BinaryTreeNode<TData>* subtree_root);

    // 使用前序遍历和中序遍历结果, 创建二叉子树(递归)
    // void CreateSubtreeByPreorderAndInorderList_(TData* preorder_list,
    bool CreateSubtreeByPreorderAndInorderList_(TData* preorder_list,
                                                TData* inorder_list,
                                                int length,
                                                BinaryTreeNode<TData>*& subtree_root);

    // 判断两颗树相同
    template<class TData>
    friend bool operator == (const BinaryTree<TData>& binary_tree_1, const BinaryTree<TData>& binary_tree_2);
    // 输入二叉树
    // template<class TData>
    // friend istream& operator >> (istream& in, BinaryTree<TData>& binary_tree);
    // 输出二叉树
    template<class TData>
    friend ostream& operator << (ostream& out, BinaryTree<TData>& binary_tree);
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
 * @tparam TData 结点数据模板类型
 * @param subtree_root 子树根节点指针
 * @param data 被查找数据
 * @return 是否存在
 */
template<class TData>
bool BinaryTree<TData>::ExistInSubTree_(BinaryTreeNode<TData>* subtree_root, TData data) const {

    if (subtree_root == NULL) {
        return false;
    }

    if (subtree_root->data == data) {
        return true;
    }

    bool existed = ExistInSubTree_(subtree_root->left_child, data);
    if (existed) {
        return true;
    }

    existed = ExistInSubTree_(subtree_root->right_child, data);

    return existed;
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
 * @param subtree_root 子树根节点指针
 * @return 子树高度
 */
template<class TData>
int BinaryTree<TData>::HeightOfSubTreeRecursive_(BinaryTreeNode<TData>* subtree_root) const {
    // 如果子树根节点为空, 则返回0
    if (subtree_root == NULL) {
        return 0;
    }

    int left_subtree_height = HeightOfSubTreeRecursive_(subtree_root->left_child); // 递归求左子树高度
    int right_subtree_height = HeightOfSubTreeRecursive_(subtree_root->right_child); // 递归求右子树高度

    // 树高度 = 最高的左右子树高度 + 1
    int subtree_height = 0;
    if (left_subtree_height < right_subtree_height) {
        subtree_height = right_subtree_height + 1;
    } else {
        subtree_height = left_subtree_height + 1;
    }

    return subtree_height;
}


/*!
 * @brief 求子树的size(递归)
 * @tparam TData 节点数据模板类型
 * @param subtree_root 子树根节点指针
 * @return 子树size
 */
template<class TData>
int BinaryTree<TData>::SizeOfSubTree_(BinaryTreeNode<TData>* subtree_root) const {
    if (subtree_root == NULL) {
        return 0;
    }

    int left_subtree_size = SizeOfSubTree_(subtree_root->left_child); // 递归求左子树size
    int right_subtree_size = SizeOfSubTree_(subtree_root->right_child); // 递归求右子树size

    int subtree_size = 1 + left_subtree_size + right_subtree_size;

    return subtree_size;
}


/*!
 * @brief 子树获取节点的父节点
 * @tparam TData 节点数据模板类型
 * @param subtree_root 子树根节点指针
 * @param node 节点指针
 * @return 节点的(位于子树内的)父节点指针
 */
template<class TData>
BinaryTreeNode<TData>* BinaryTree<TData>::Parent_(BinaryTreeNode<TData>* subtree_root,
                                                  BinaryTreeNode<TData>* node) const
{
    // 如果子树根为NULL, 则返回NULL
    if (subtree_root == NULL) {
        return NULL;
    }

    // 如果子树根的左孩子or右孩子, 就是node_ptr的父节点, 则返回子树根结点
    if (subtree_root->left_child == node || subtree_root->right_child == node) {
        return subtree_root;
    }

    BinaryTreeNode<TData>* parent = Parent_(subtree_root->left_child, node);

    if (parent == NULL) {
        parent = Parent_(subtree_root->right_child, node);
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
  * @tparam TData 节点数据模板类型
  * @param subtree_root 子树根节点指针
  * @param visit 访问函数
  */
template<class TData>
void BinaryTree<TData>::PreOrderTraversalOfSubTreeRecursive_(BinaryTreeNode<TData>* subtree_root,
                                                             void (*visit)(BinaryTreeNode<TData>* node))
{
    if (subtree_root == NULL) {
        return;
    }

    visit(subtree_root);

    PreOrderTraversalOfSubTreeRecursive_(subtree_root->left_child, visit);
    PreOrderTraversalOfSubTreeRecursive_(subtree_root->right_child, visit);
}


/**
 * @brief 子树前序遍历(非递归)
 * @tparam TData 节点数据模板类型
 * @param subtree_root 子树根节点指针
 * @param visit 访问函数
 */
template<class TData>
void BinaryTree<TData>::PreOrderTraversalOfSubTreeNonRecursive_(BinaryTreeNode<TData>* subtree_root,
                                                                void (*visit)(BinaryTreeNode<TData>*))
{

    // (栈初始化)声明前序遍历栈, 子树根节点指针入栈
    stack<BinaryTreeNode<TData>*> pre_traverse_stack;
    pre_traverse_stack.push(subtree_root);

    while (!pre_traverse_stack.empty()) {

        // 出栈
        BinaryTreeNode<TData>* cur_node_ptr = pre_traverse_stack.top();
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
void BinaryTree<T>::InorderTraversalOfSubTreeRecursive_(BinaryTreeNode<T>* sub_tree_root,
                                                        void (*visit)(BinaryTreeNode<T>*))
{
    if (sub_tree_root == NULL) {
        return;
    }

    InorderTraversalOfSubTreeRecursive_(sub_tree_root->left_child, visit);

    visit(sub_tree_root);

    InorderTraversalOfSubTreeRecursive_(sub_tree_root->right_child, visit);
}


/**
 * @brief 子树中序遍历(非递归)
 * @tparam T 节点数据模板类型
 * @param sub_tree_root 子树根节点指针
 * @param visit 访问函数
 */
template<class T>
void BinaryTree<T>::InorderTraversalOfSubTreeNonRecursive_(BinaryTreeNode<T>* sub_tree_root, void (*visit)(BinaryTreeNode<T>* node)) {

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
void BinaryTree<T>::PostorderTraversalOfSubtreeRecursive_(BinaryTreeNode<T>* sub_tree_root,
                                                          void (*visit)(BinaryTreeNode<T>*))
{
    if (sub_tree_root == NULL) {
        return;
    }

    PostorderTraversalOfSubtreeRecursive_(sub_tree_root->left_child, visit);
    PostorderTraversalOfSubtreeRecursive_(sub_tree_root->right_child, visit);

    visit(sub_tree_root);
}


/**
 * @brief 子树后序遍历(非递归)
 * @tparam TData 节点数据模板类型
 * @param subtree_root 子树根节点指针
 * @param visit 访问函数
 */
template <class TData>
void BinaryTree<TData>::PostorderTraversalOfSubtreeNonRecursive_(BinaryTreeNode<TData>* subtree_root,
                                                                 void (*visit)(BinaryTreeNode<TData>*))
{
    stack<BacktrackingStackNode<TData> > backtracking_stack;

    BinaryTreeNode<TData>* cur_tree_node = subtree_root;

    do {
        // 一直向左子树方向试探(等于在做深度优先)
        while (cur_tree_node != NULL) {
            BacktrackingStackNode<TData> node(cur_tree_node);
            backtracking_stack.push(node);
            cur_tree_node = cur_tree_node->left_child;
        }

        bool cur_tree_node_left_backtracking_unfinished = true;
        while (cur_tree_node_left_backtracking_unfinished && !backtracking_stack.empty()) {

            BacktrackingStackNode<TData> cur_backtracking_node = backtracking_stack.top();
            backtracking_stack.pop();

            cur_tree_node = cur_backtracking_node.node;

            if (cur_backtracking_node.tag == BacktrackingStackNode<TData>::LEFT_BACK_TRACKING) {
                cur_backtracking_node.tag = BacktrackingStackNode<TData>::RIGHT_BACK_TRACKING;
                backtracking_stack.push(cur_backtracking_node);
                cur_tree_node = cur_tree_node->right_child;

                cur_tree_node_left_backtracking_unfinished = false;

            } else if (cur_backtracking_node.tag == BacktrackingStackNode<TData>::RIGHT_BACK_TRACKING) {
                visit(cur_tree_node);
            }
        }
    } while (!backtracking_stack.empty());
}


/**
 * @brief 子树层序遍历
 * @tparam TData 节点数据模板类型
 * @param subtree_root 子树根节点指针
 * @param visit 访问函数
 */
template<class TData>
void BinaryTree<TData>::LevelOrderTraversalOfSubtree_(BinaryTreeNode<TData>* subtree_root,
                                                      void (*visit)(BinaryTreeNode<TData>* node))
{
    queue<BinaryTreeNode<TData>*> traversal_queue;

    BinaryTreeNode<TData>* cur = subtree_root;
    traversal_queue.push(cur);

    while (!traversal_queue.empty()) {
        cur = traversal_queue.front();
        traversal_queue.pop();

        visit(cur);

        if (cur->left_child != NULL) {
            traversal_queue.push(cur->left_child);
        }

        if (cur->right_child != NULL) {
            traversal_queue.push(cur->right_child);
        }
    }
}


/*!
 * @brief 子树打印
 * @tparam TData 结点数据模板类型
 * @param subtree_root 子树根节点
 */
template<class TData>
void BinaryTree<TData>::PrintSubTree_(BinaryTreeNode<TData>* subtree_root) {

    if (subtree_root == NULL) {
        return;
    }

    cout << subtree_root->data;

    if (subtree_root->left_child != NULL || subtree_root->right_child != NULL) {

        cout << '(';

        this->PrintSubTree_(subtree_root->left_child);

        cout << ',';

        if (subtree_root->right_child != NULL) {
            this->PrintSubTree_(subtree_root->right_child);
        }

        cout << ')';
    }
}


/*!
 * @brief 使用前序遍历和中序遍历结果, 创建二叉子树(递归)
 * @param preorder_list 前序遍历字符串
 * @param inorder_list 后序遍历字符串
 * @param length 字符串长度
 * @param subtree_root 子树根结点
 */
template<class TData>
// void BinaryTree<TData>::CreateSubtreeByPreorderAndInorderList_(TData* preorder_list,
bool BinaryTree<TData>::CreateSubtreeByPreorderAndInorderList_(TData* preorder_list,
                                                               TData* inorder_list,
                                                               int length,
                                                               BinaryTreeNode<TData>*& subtree_root)
{
    if (length == 0) {
        return true;
    }

    int pivot = 0;
    TData cur_root_data = *preorder_list;

    while (cur_root_data != inorder_list[pivot]) {
        pivot++;
    }

    subtree_root = new BinaryTreeNode<TData>(cur_root_data);
    if (subtree_root == NULL) {
        cerr << "存储分配错误!" << endl;
        return false;
    }

    bool res = CreateSubtreeByPreorderAndInorderList_(preorder_list + 1,
                                                      inorder_list,
                                                      pivot,
                                                      subtree_root->left_child);
    if (!res) {
        return false;
    }

    res = CreateSubtreeByPreorderAndInorderList_(preorder_list + pivot + 1,
                                                 inorder_list + pivot + 1,
                                                 length - pivot - 1,
                                                 subtree_root->right_child);

    return res;
}


/*!
 * @brief 判断两颗二叉树是否相同(递归)
 * @tparam TData 结点数据模板类型
 * @param root1 根节点a
 * @param root2 根节点2
 * @return 是否相同
 */
template<class TData>
bool BinaryTree<TData>::Equal(BinaryTreeNode<TData>* root1, BinaryTreeNode<TData>* root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    }

    if (root1 != NULL && root2 != NULL && root1->data == root2->data
        && BinaryTree<TData>::Equal(root1->left_child, root2->left_child)
        && BinaryTree<TData>::Equal(root1->right_child, root2->right_child))
    {
        return true;
    } else {
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
  * @tparam TData 类型模板参数
  * @param binary_tree_1 二叉树1
  * @param binary_tree_2 二叉树2
  * @return
  */
template<class TData>
bool operator == (const BinaryTree<TData>& binary_tree_1, const BinaryTree<TData>& binary_tree_2) {
    return (BinaryTree<TData>::Equal(binary_tree_1.Root(), binary_tree_2.Root()));
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
    Tree.Traverse(Tree.Root(), out);
    out << endl;
    return out;
}


#endif //CYBER_DASH_BINARY_TREE_H
