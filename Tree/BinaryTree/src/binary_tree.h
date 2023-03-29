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
 * @brief **二叉树结点模板结构体**
 * @tparam TData 数据项类型模板参数
 */
template <typename TData>
struct BinaryTreeNode {
    /*! @brief **默认构造函数** */
    BinaryTreeNode() : left_child(NULL), right_child(NULL) {}

    /*! @brief **构造函数(数据项/左右孩子)** */
    explicit BinaryTreeNode(TData data, BinaryTreeNode<TData>* left_child = NULL, BinaryTreeNode<TData>* right_child = NULL)
        : data(data), left_child(left_child), right_child(right_child) {}

    TData data;                           //!< **数据项**
    BinaryTreeNode<TData>* left_child;    //!< **左孩子结点**(指针)
    BinaryTreeNode<TData>* right_child;   //!< **右孩子结点**(指针)
};


/*!
 * @brief <b>(后序遍历)回溯栈结点模板类</b>
 * @tparam TData 数据项类型模板参数
 */
template <typename TData>
struct PostorderBacktrackStackNode {
    /*!
     * @brief **构造函数(二叉树结点)**
     * @param node 二叉树结点
     * @note
     * 构造函数(二叉树结点)
     * -----------------
     * -----------------
     *
     * -----------------
     * 初始化node, tag设置为LEFT_BACK_TRACKING(左孩子回溯)
     */
    explicit PostorderBacktrackStackNode(BinaryTreeNode<TData>* node = NULL) : node(node), tag(LEFT_BACK_TRACKING) {}

    BinaryTreeNode<TData>* node;                                 //!< **二叉树结点指针**
    enum { LEFT_BACK_TRACKING = 0, RIGHT_BACK_TRACKING } tag;    //!< **标签**, 0: 左孩子回溯, 1: 右孩子回溯
};


template <typename TData> class BinaryTree;
// 判断两颗树相同
template<typename TData> bool operator==(const BinaryTree<TData>& binary_tree_1, const BinaryTree<TData>& binary_tree_2);
// 输出二叉树
template<typename TData> ostream& operator<<(ostream& out, BinaryTree<TData>& binary_tree);


/*!
 * @brief 二叉树模板类
 * @tparam TData 数据项类型模板参数
 */
template <typename TData>
class BinaryTree {
public:
    /*! @brief **默认构造函数** */
    BinaryTree() : root_(NULL) {}

    /*!
     * @brief **构造函数(根结点数据项)**
     * @note
     * 构造函数(根结点数据项)
     * ------------------
     * ------------------
     *
     * ------------------
     * 对root_调用InsertInSubTreeRecursive_
     */
    explicit BinaryTree(const TData& data) { this->InsertInSubtreeRecursive_(this->root_, data); }

    // 复制构造函数
    BinaryTree(const BinaryTree<TData>& src_binary_tree);

    /*!
     * @brief **析构函数**
     * @note
     * 析构函数
     * ------
     * ------
     *
     * ------
     * 对root_调用RemoveSubtreeRecursive_
     */
    ~BinaryTree() { this->RemoveSubtreeRecursive_(root_); }

    /*! @brief **获取根节点** */
    BinaryTreeNode<TData>* Root() const { return this->root_; }

    /*! @brief **判断是否为空树** */
    bool IsEmpty() { return this->root_ == NULL; }

    /*!
     * @brief **获取父结点**
     * @param node 结点
     * @return 父结点
     * @note
     * 获取父结点
     * --------
     * --------
     *
     * --------
     * **if** this->root_ == NULL || this->root_ == node :\n
     * &emsp; 返回NULL\n
     * **else** :\n
     * &emsp; 返回this->ParentInSubtree_(this->root_, node)\n
     */
    BinaryTreeNode<TData>* Parent(BinaryTreeNode<TData>* node) const {
        return (this->root_ == NULL || this->root_ == node) ? NULL : this->ParentInSubtree_(this->root_, node);
    }

    /*!
     * @brief **获取高度**
     * @return 高度
     */
    int Height() { return this->HeightOfSubtreeRecursive_(this->root_); }

    /*!
     * @brief **获取结点数**
     * @return 结点数
     */
    int Size() { return this->SizeOfSubTreeRecursive_(this->root_); }

    /*!
     * @brief **插入结点**
     * @param data 数据项
     * @return 是否成功
     */
    bool Insert(const TData& data) { return this->InsertInSubtreeRecursive_(this->root_, data); }

    /*!
     * @brief **查询数据项是否在树中**
     * @param data 数据项
     * @return 是否在树中
     */
    bool Exist(TData data) { return this->ExistInSubTree_(this->root_, data); }

    /*!
     * @brief **前序遍历(递归)**
     * @param visit 结点访问函数
     */
    void PreorderTraversalRecursive(void (*visit)(BinaryTreeNode<TData>*)) {
        this->PreorderTraversalOfSubtreeRecursive_(this->root_, visit);
    }

    /*!
     * @brief **前序遍历**
     * @param visit 结点访问函数
     */
    void PreorderTraversal(void (*visit)(BinaryTreeNode<TData>*)) {
        this->PreorderTraversalOfSubtree_(this->root_, visit);
    }

    /*!
     * @brief **中序遍历(递归)**
     * @param visit 结点访问函数
     */
    void InorderTraversalRecursive(void (*visit)(BinaryTreeNode<TData>* node)) {
        this->InorderTraversalOfSubtreeRecursive_(this->root_, visit);
    }

    /*!
     * @brief **中序遍历**
     * @param visit 结点访问函数
     */
    void InorderTraversal(void (*visit)(BinaryTreeNode<TData>* node)) {
        this->InorderTraversalOfSubtree_(this->root_, visit);
    }

    /*!
     * @brief **后序遍历(递归)**
     * @param visit 结点访问函数
     */
    void PostorderTraversalRecursive(void (*visit)(BinaryTreeNode<TData>*)) {
        this->PostorderTraversalOfSubtreeRecursive_(this->root_, visit);
    }

    /*!
     * @brief **后序遍历**
     * @param visit 结点访问函数
     */
    void PostorderTraversal(void (*visit)(BinaryTreeNode<TData>*)) {
        this->PostorderTraversalOfSubtree_(this->root_, visit);
    }

    /*!
     * @brief **层序遍历**
     * @param visit 结点访问函数
     */
    void LevelOrderTraversal(void (*visit)(BinaryTreeNode<TData>*)) {
        this->LevelOrderTraversalOfSubtree_(this->root_, visit);
    }

    /*!
     * @brief **建树(by前序遍历和中序遍历)**
     * @param preorder_list 前序遍历列表
     * @param inorder_list 中序遍历列表
     * @param length 字符串长度
     * @return 执行结果
     */
    bool CreateByPreorderAndInorderList(TData* preorder_list, TData* inorder_list, int length) {
        bool res = this->CreateSubtreeByPreorderAndInorderList_(preorder_list, inorder_list, length, this->root_);
        return res;
    }

    /*!
     * @brief **打印**
     * @note
     * 打印
     * ---
     * ---
     * 
     * ---
     * 对root_调用PrintSubTreeRecursive_
     */
    void Print() { this->PrintSubTreeRecursive_(this->root_); };

    // 判断两颗二叉树是否相同(递归)
    static bool Equal(BinaryTreeNode<TData>* root1, BinaryTreeNode<TData>* root2);

protected:
    BinaryTreeNode<TData>* root_; //!< 根结点

    // 子树插入数据
    bool InsertInSubtreeRecursive_(BinaryTreeNode<TData>*& subtree_root, const TData& data);
    // 删除子树
    void RemoveSubtreeRecursive_(BinaryTreeNode<TData>*& subtree_root);
    // 查找数据是否在(子)树中(递归)
    bool ExistInSubTree_(BinaryTreeNode<TData>* subtree_root, TData data) const;
    // 复制二叉树
    bool DuplicateSubTreeRecursive_(BinaryTreeNode<TData>* src_subtree_root, BinaryTreeNode<TData>*& target_subtree_root);
    // 求子树的高度(递归)
    int HeightOfSubtreeRecursive_(BinaryTreeNode<TData>* subtree_root) const;
    // 求子树的Size(递归)
    int SizeOfSubTreeRecursive_(BinaryTreeNode<TData>* subtree_root) const;
    // 子树获取节点的父节点
    BinaryTreeNode<TData>* ParentInSubtree_(BinaryTreeNode<TData>* subtree_root, BinaryTreeNode<TData>* node) const;

    // 子树前序遍历(递归)
    void PreorderTraversalOfSubtreeRecursive_(BinaryTreeNode<TData>* subtree_root, void (*visit)(BinaryTreeNode<TData>*));
    // 子树前序遍历(非递归)
    void PreorderTraversalOfSubtree_(BinaryTreeNode<TData>* subtree_root, void (*visit)(BinaryTreeNode<TData>*));
    // 子树中序遍历(递归)
    void InorderTraversalOfSubtreeRecursive_(BinaryTreeNode<TData>* subtree_root, void (*visit)(BinaryTreeNode<TData>*));
    // 子树中序遍历(非递归)
    void InorderTraversalOfSubtree_(BinaryTreeNode<TData>* subtree_root, void (*visit)(BinaryTreeNode<TData>*));
    // 子树后序遍历(递归)
    void PostorderTraversalOfSubtreeRecursive_(BinaryTreeNode<TData>* subtree_root, void (*visit)(BinaryTreeNode<TData>*));
    // 子树后序遍历(非递归)
    void PostorderTraversalOfSubtree_(BinaryTreeNode<TData>* subtree_root, void (*visit)(BinaryTreeNode<TData>*));
    // 子树层序遍历
    void LevelOrderTraversalOfSubtree_(BinaryTreeNode<TData>* subtree_root, void (*visit)(BinaryTreeNode<TData>*));
    // 子树打印
    void PrintSubTreeRecursive_(BinaryTreeNode<TData>* subtree_root);

    // 使用前序遍历和中序遍历结果, 创建二叉子树(递归)
    bool CreateSubtreeByPreorderAndInorderList_(TData* preorder_sub_list,
                                                TData* inorder_sub_list,
                                                int length,
                                                BinaryTreeNode<TData>*& subtree_root);

    // 判断两颗树相同
    friend bool operator== <>(const BinaryTree<TData>& binary_tree_1, const BinaryTree<TData>& binary_tree_2);
    // 输出二叉树
    friend ostream& operator<< <>(ostream& out, BinaryTree<TData>& binary_tree);
};


/*!
 * @brief **复制构造函数**
 * @tparam TData 数据项类型模板参数
 * @param src_binary_tree 源二叉树
 * @note
 * 复制构造函数
 * ----------
 * ----------
 *
 * ----------
 * 对src_binary_tree.Root()和root_, 调用DuplicateSubTreeRecursive_\n
 * **if** 调用失败 :\n
 * &emsp; 抛出logic_error\n
 */
template<typename TData>
BinaryTree<TData>::BinaryTree(const BinaryTree<TData>& src_binary_tree) {
    bool res = this->DuplicateSubTreeRecursive_(src_binary_tree.Root(), this->root_);
    if (!res) {
        throw logic_error("DuplicateSubTreeRecursive_ error");
    }
}


/*!
 * @brief **子树插入结点(递归)**
 * @tparam TData 数据项类型模板参数
 * @param subtree_root 子树根结点
 * @param data 结点数据项
 * @return 执行结果
 * @note
 * 子树插入结点
 * ----------
 * ----------
 *
 * ----------
 * + **1 空子树处理**\n
 * **if** 空子树 :\n
 * &emsp; subtree_root分配内存并初始化\n
 * &emsp; **if** 分配内存失败 :\n
 * &emsp;&emsp; 抛出bad_alloc()\n
 * &emsp; 返回true\n\n
 * + **2 分治递归**\n
 * 计算left_subtree_height(左子树高度)\n
 * 计算right_subtree_height(右子树高度)\n\n
 * **if** left_subtree_height > right_subtree_height :\n
 * &emsp; 左子树递归调用InsertInSubtreeRecursive_\n
 * &emsp; **if** 调用失败 :\n
 * &emsp;&emsp; 返回false\n
 * **else** \n
 * &emsp; 右子树递归调用InsertInSubtreeRecursive_\n
 * &emsp; **if** 调用失败 :\n
 * &emsp;&emsp; 返回false\n\n
 * + **3 退出函数**\n
 * 返回true\n
 */
template<typename TData>
bool BinaryTree<TData>::InsertInSubtreeRecursive_(BinaryTreeNode<TData>*& subtree_root, const TData& data) {

    if (subtree_root == NULL) {
        subtree_root = new BinaryTreeNode<TData>(data);
        if (subtree_root == NULL) {
            throw bad_alloc();
        }

        return true;
    }

    int left_subtree_height = HeightOfSubtreeRecursive_(subtree_root->left_child);
    int right_subtree_height = HeightOfSubtreeRecursive_(subtree_root->right_child);

    if (left_subtree_height > right_subtree_height) {
        bool res = InsertInSubtreeRecursive_(subtree_root->right_child, data);
        if (!res) {
            return false;
        }
    } else {
        bool res = InsertInSubtreeRecursive_(subtree_root->left_child, data);
        if (!res) {
            return false;
        }
    }

    return true;
}


/*!
 * @brief **删除子树**
 * @param subtree_root 子树根节点
 * @note
 * 删除子树
 * -------
 * -------
 *
 * -------
 * + **1 空子树处理**\n
 * **if** subtree_root为NULL :\n
 * &emsp; 退出函数\n\n
 * + **2 分治递归**\n
 * 对左子树调用RemoveSubtreeRecursive_\n
 * 对右子树调用RemoveSubtreeRecursive_\n\n
 * + **3 删除子树根结点**\n
 * 释放subtree_root\n
 * subtree_root置NULL\n
 */
template <class TData>
void BinaryTree<TData>::RemoveSubtreeRecursive_(BinaryTreeNode<TData>*& subtree_root) {
    if (subtree_root == NULL) {
        return;
    }

    this->RemoveSubtreeRecursive_(subtree_root->left_child);
    this->RemoveSubtreeRecursive_(subtree_root->right_child);

    delete subtree_root;
    subtree_root = NULL;
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
 * @brief 求子树高度(递归)
 * @tparam TData 数据项类型模板参数
 * @param subtree_root 子树根结点
 * @return 子树高度
 * @note
 * 求子树高度(递归)
 * --------------
 * --------------
 * 
 * --------------
 * + **1 空子树处理**\n
 * **if** 空子树 :\n
 * &emsp; 返回0\n\n
 * + **2 分治递归**\n
 * 对subtree_root->left_child递归调用HeightOfSubtreeRecursive_, 得到left_subtree_height(左子树高度)\n
 * 对subtree_root->right_child递归调用HeightOfSubtreeRecursive_, 得到left_subtree_height(右子树高度)\n\n
 * 计算subtree_height, 等于1 + 最高子树的高度\n\n
 * + **3 返回结果**\n
 * 返回subtree_height\n
 */
template<typename TData>
int BinaryTree<TData>::HeightOfSubtreeRecursive_(BinaryTreeNode<TData>* subtree_root) const {
    // ---------- 1 空子树处理 ----------

    if (subtree_root == NULL) {         // if 空子树
        return 0;                       // 返回0
    }

    // ---------- 2 分治递归 ----------

    // 对subtree_root->left_child递归调用HeightOfSubtreeRecursive_, 得到left_subtree_height(左子树高度)
    int left_subtree_height = HeightOfSubtreeRecursive_(subtree_root->left_child);
    // 对subtree_root->right_child递归调用HeightOfSubtreeRecursive_, 得到left_subtree_height(右子树高度)
    int right_subtree_height = HeightOfSubtreeRecursive_(subtree_root->right_child);

    // 计算subtree_height, 等于1 + 最高子树的高度
    int subtree_height = left_subtree_height < right_subtree_height ? (right_subtree_height + 1) : (left_subtree_height + 1);

    // ---------- 3 返回结果 ----------

    return subtree_height;              // 返回subtree_height
}


/*!
 * @brief **子树size(递归)**
 * @tparam TData 数据项类型模板参数
 * @param subtree_root 子树根结点
 * @return 子树size
 * @note
 * 子树size(递归)
 * -------------
 * -------------
 * 
 * -------------
 * + **1 空子树处理**\n
 * **if** 空子树 :\n
 * &emsp; 返回0\n\n
 * + **2 分治递归**\n
 * 对subtree_root->left_child递归调用SizeOfSubTreeRecursive_, 得到left_subtree_size(左子树size)\n
 * 对subtree_root->right_child递归调用SizeOfSubTreeRecursive_, 得到right_subtree_size(右子树size)\n\n
 * 计算subtree_size, 等于1 + left_subtree_size + right_subtree_size\n\n
 * + **3 返回结果**\n
 * 返回subtree_size\n
 */
template<class TData>
int BinaryTree<TData>::SizeOfSubTreeRecursive_(BinaryTreeNode<TData>* subtree_root) const {
    if (subtree_root == NULL) {
        return 0;
    }

    int left_subtree_size = SizeOfSubTreeRecursive_(subtree_root->left_child); // 递归求左子树size
    int right_subtree_size = SizeOfSubTreeRecursive_(subtree_root->right_child); // 递归求右子树size

    int subtree_size = 1 + left_subtree_size + right_subtree_size;

    return subtree_size;
}


/*!
 * @brief **在子树内获取父结点**
 * @tparam TData 数据项类型模板参数
 * @param subtree_root 子树根结点
 * @param node 结点
 * @return 父结点
 * @note
 * 在子树内获取父结点
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 空子树处理**\n
 * **if** 空子树 :\n
 * &emsp; 返回NULL\n\n
 * + **2 找到父节点情况处理**\n
 * **if** node是subtree_root的左孩子或者右孩子 :\n
 * &emsp; 返回subtree_root\n\n
 * + **3 分治递归**\n
 * 对subtree_root->left_child递归调用ParentInSubtree_\n
 * **if** 未找到父节点 :\n
 * &emsp; 对subtree_root->right_child递归调用ParentInSubtree_\n
 * 返回调用结果\n
 */
template<typename TData>
BinaryTreeNode<TData>* BinaryTree<TData>::ParentInSubtree_(BinaryTreeNode<TData>* subtree_root,
                                                           BinaryTreeNode<TData>* node) const
{
    if (subtree_root == NULL) {
        return NULL;
    }

    if (subtree_root->left_child == node || subtree_root->right_child == node) {
        return subtree_root;
    }

    BinaryTreeNode<TData>* parent = ParentInSubtree_(subtree_root->left_child, node);

    if (parent == NULL) {
        parent = ParentInSubtree_(subtree_root->right_child, node);
    }

    return parent;
}


 /*!
  * @brief **子树前序遍历(递归)**
  * @tparam TData 数据项类型模板参数
  * @param subtree_root 子树根结点
  * @param visit 访问函数
  * @note
  * 子树前序遍历(递归)
  * ---------------
  * ---------------
  *
  * ---------------
  * + **1 空子树处理**\n
  * **if** 空子树 :\n
  * &emsp; 返回\n\n
  * + **2 分治递归**\n
  * 访问subtree_root\n\n
  * 对subtree_root->left_child递归调用PreorderTraversalOfSubtreeRecursive_\n
  * 对subtree_root->right_child递归调用PreorderTraversalOfSubtreeRecursive_\n
  */
template<class TData>
void BinaryTree<TData>::PreorderTraversalOfSubtreeRecursive_(BinaryTreeNode<TData>* subtree_root,
                                                             void (*visit)(BinaryTreeNode<TData>*))
{
    if (subtree_root == NULL) {
        return;
    }

    visit(subtree_root);

    PreorderTraversalOfSubtreeRecursive_(subtree_root->left_child, visit);
    PreorderTraversalOfSubtreeRecursive_(subtree_root->right_child, visit);
}


/**
 * @brief **子树前序遍历(非递归)**
 * @tparam TData 数据项类型模板参数
 * @param subtree_root 子树根结点
 * @param visit 访问函数
 * @note
 * 子树前序遍历(非递归)
 * -----------------
 * -----------------
 * 
 * -----------------
 * 声明backtrack_stack(回溯栈)\n
 * subtree_root(子树根结点)入栈\n\n
 * **while loop** 回溯栈不为空 :\n
 * &emsp; 取栈顶, 赋给cur\n
 * &emsp; 栈顶出栈\n\n
 * &emsp; 访问cur\n\n
 * &emsp; **if** cur存在右孩子 :\n
 * &emsp;&emsp; cur右孩子入栈\n
 * &emsp; **if** cur存在左孩子 :\n
 * &emsp;&emsp; cur左孩子入栈\n
 */
template<class TData>
void BinaryTree<TData>::PreorderTraversalOfSubtree_(BinaryTreeNode<TData>* subtree_root,
                                                    void (*visit)(BinaryTreeNode<TData>*))
{
    stack<BinaryTreeNode<TData>*> backtrack_stack;
    backtrack_stack.push(subtree_root);

    while (!backtrack_stack.empty()) {

        BinaryTreeNode<TData>* cur = backtrack_stack.top();
        backtrack_stack.pop();

        visit(cur);

        if (cur->right_child != NULL) {
            backtrack_stack.push(cur->right_child);
        }

        if (cur->left_child != NULL) {
            backtrack_stack.push(cur->left_child);
        }
    }
}


/*!
 * @brief **子树中序遍历(递归)**
 * @tparam TData 数据项类型模板参数
 * @param subtree_root 子树根结点
 * @param visit 访问函数
 * @note
 * 子树中序遍历(递归)
 * ---------------
 * ---------------
 * 
 * ---------------
 * + **1 空子树处理**\n
 * **if** 空子树 :\n
 * &emsp; 返回\n\n
 * + **2 分治递归**\n
 * 对subtree_root->left_child递归调用PreorderTraversalOfSubtreeRecursive_\n
 * 访问subtree_root\n
 * 对subtree_root->right_child递归调用PreorderTraversalOfSubtreeRecursive_\n
 */
template<class TData>
void BinaryTree<TData>::InorderTraversalOfSubtreeRecursive_(BinaryTreeNode<TData>* subtree_root,
                                                            void (*visit)(BinaryTreeNode<TData>*))
{
    if (subtree_root == NULL) {
        return;
    }

    InorderTraversalOfSubtreeRecursive_(subtree_root->left_child, visit);

    visit(subtree_root);

    InorderTraversalOfSubtreeRecursive_(subtree_root->right_child, visit);
}


/**
 * @brief 子树中序遍历(非递归)
 * @tparam TData 节点数据模板类型
 * @param subtree_root 子树根节点指针
 * @param visit 访问函数
 */
template<class TData>
void BinaryTree<TData>::InorderTraversalOfSubtree_(BinaryTreeNode<TData>* subtree_root,
                                                   void (*visit)(BinaryTreeNode<TData>*))
{
    stack<BinaryTreeNode<TData>*> backtrack_stack;
    BinaryTreeNode<TData>* cur_tree_node = subtree_root;

    while (cur_tree_node != NULL || !backtrack_stack.empty()) {

        // 一直向左子树方向搜索(等于在做深度优先搜索DFS)
        while (cur_tree_node != NULL) {
            backtrack_stack.push(cur_tree_node);
            cur_tree_node = cur_tree_node->left_child;
        }

        if (!backtrack_stack.empty()) {

            cur_tree_node = backtrack_stack.top();
            backtrack_stack.pop();

            visit(cur_tree_node);

            cur_tree_node = cur_tree_node->right_child;
        }
    }
}


/*!
 * @brief **子树后序遍历(递归)**
 * @tparam TData 数据项类型模板参数
 * @param subtree_root 子树根结点
 * @param visit 访问函数
 * @note
 * 子树后序遍历(递归)
 * ---------------
 * ---------------
 * 
 * ---------------
 * + **1 空子树处理**\n
 * **if** 空子树 :\n
 * &emsp; 返回\n\n
 * + **2 分治递归**\n
 * 对subtree_root->left_child递归调用PreorderTraversalOfSubtreeRecursive_\n
 * 对subtree_root->right_child递归调用PreorderTraversalOfSubtreeRecursive_\n
 * 访问subtree_root\n
 */
template<typename TData>
void BinaryTree<TData>::PostorderTraversalOfSubtreeRecursive_(BinaryTreeNode<TData>* subtree_root,
                                                              void (*visit)(BinaryTreeNode<TData>*))
{
    if (subtree_root == NULL) {
        return;
    }

    PostorderTraversalOfSubtreeRecursive_(subtree_root->left_child, visit);
    PostorderTraversalOfSubtreeRecursive_(subtree_root->right_child, visit);

    visit(subtree_root);
}


/**
 * @brief 子树后序遍历(非递归)
 * @tparam TData 节点数据模板类型
 * @param subtree_root 子树根节点指针
 * @param visit 访问函数
 */
template <class TData>
void BinaryTree<TData>::PostorderTraversalOfSubtree_(BinaryTreeNode<TData>* subtree_root,
                                                                 void (*visit)(BinaryTreeNode<TData>*))
{
    stack<PostorderBacktrackStackNode<TData> > backtrack_stack;

    BinaryTreeNode<TData>* cur_tree_node = subtree_root;

    do {
        // 一直向左子树方向搜索(等于在做深度优先搜索DFS)
        while (cur_tree_node != NULL) {
            PostorderBacktrackStackNode<TData> node(cur_tree_node);
            backtrack_stack.push(node);
            cur_tree_node = cur_tree_node->left_child;
        }

        bool cur_tree_node_left_backtrack_unfinished = true;
        while (cur_tree_node_left_backtrack_unfinished && !backtrack_stack.empty()) {

            PostorderBacktrackStackNode<TData> cur_backtrack_node = backtrack_stack.top();
            backtrack_stack.pop();

            cur_tree_node = cur_backtrack_node.node;

            if (cur_backtrack_node.tag == PostorderBacktrackStackNode<TData>::LEFT_BACK_TRACKING) {
                cur_backtrack_node.tag = PostorderBacktrackStackNode<TData>::RIGHT_BACK_TRACKING;
                backtrack_stack.push(cur_backtrack_node);
                cur_tree_node = cur_tree_node->right_child;

                cur_tree_node_left_backtrack_unfinished = false;

            } else if (cur_backtrack_node.tag == PostorderBacktrackStackNode<TData>::RIGHT_BACK_TRACKING) {
                visit(cur_tree_node);
            }
        }
    } while (!backtrack_stack.empty());
}


/**
 * @brief **子树层序遍历**
 * @tparam TData 数据项类型模板参数
 * @param subtree_root 子树根结点
 * @param visit 访问函数
 * @note
 * 子树层序遍历
 * ----------
 * ----------
 * 
 * ----------
 * + **1 初始化遍历队列**\n
 * 声明traversal_queue\n
 * subtree_root入队\n\n
 * + **2 遍历**\n
 * **while loop** traversal_queue不为空 :\n
 * &emsp; 取队头, 赋给cur\n
 * &emsp; 队头出队\n\n
 * &emsp; 访问cur\n\n
 * &emsp; **if** cur的左孩子不为NULL :\n
 * &emsp;&emsp; cur->left_child入队\n
 * &emsp; **if** cur的右孩子不为NULL :\n
 * &emsp;&emsp; cur->right_child入队\n
 */
template<class TData>
void BinaryTree<TData>::LevelOrderTraversalOfSubtree_(BinaryTreeNode<TData>* subtree_root,
                                                      void (*visit)(BinaryTreeNode<TData>*))
{
    queue<BinaryTreeNode<TData>*> traversal_queue;
    traversal_queue.push(subtree_root);

    while (!traversal_queue.empty()) {
        BinaryTreeNode<TData>* cur = traversal_queue.front();
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
 * @brief **子树打印(递归)**
 * @tparam TData 数据项类型模板参数
 * @param subtree_root 子树根结点
 * @note
 * 子树打印
 * -------
 * -------
 * 
 * -------
 * + **1 空子树处理**\n
 * **if** 空子树 :\n
 * &emsp; 退出函数\n\n
 * + **2 打印子树根结点**\n
 * 打印subtree_root->data\n\n
 * + **3 递归处理左右子树**\n
 * **if** 存在left_child || 存在right_child :\n
 * &emsp; 打印'('\n
 * &emsp; 对subtree_root->left_child递归调用PrintSubTreeRecursive_\n
 * &emsp; 打印','\n
 * &emsp; 对subtree_root->right_child递归调用PrintSubTreeRecursive_\n
 * &emsp; 打印','\n
 */
template<typename TData>
void BinaryTree<TData>::PrintSubTreeRecursive_(BinaryTreeNode<TData>* subtree_root) {

    if (subtree_root == NULL) {
        return;
    }

    cout << subtree_root->data;

    if (subtree_root->left_child != NULL || subtree_root->right_child != NULL) {

        cout << '(';

        this->PrintSubTreeRecursive_(subtree_root->left_child);

        cout << ',';

        this->PrintSubTreeRecursive_(subtree_root->right_child);

        cout << ')';
    }
}


/*!
 * @brief **创建二叉子树by前序遍历子序列和中序遍历子序列(递归)**
 * @tparam TData 数据项类型模板参数
 * @param preorder_sub_list 前序遍历子序列
 * @param inorder_sub_list 后序遍历子序列
 * @param length 子序列长度
 * @param subtree_root 子树根结点
 * @return 执行结果
 * @note
 * 创建二叉子树by前序遍历子序列和中序遍历子序列(递归)
 * -----------------------------------------
 * -----------------------------------------
 *
 * -----------------------------------------
 * + **1 空子序列处理**\n
 * **if** length == 0 :\n
 * &emsp; 返回true\n\n
 * + **2 中序序列找到轴, 并生成子树根结点**\n
 * 初始化inorder_sub_list_pivot(中序遍历子序列轴)为0\n
 * 初始化cur_subtree_root_data, 指向前序遍历序列首元素\n\n
 * **while loop** cur_subtree_root_data != inorder_sub_list[inorder_sub_list_pivot] :\n
 * &emsp; inorder_sub_list_pivot向后移动1个位置\n\n
 * <span style="color:#DF5A00">
 * 此时:\n
 * &emsp; (preorder_sub_list[1, inorder_sub_list_pivot] / inorder_sub_list[0, inorder_sub_list_pivot - 1])为左子树;\n
 * &emsp; inorder_sub_list[inorder_sub_list_pivot]为子树根结点;\n
 * &emsp; (preorder_sub_list[inorder_sub_list_pivot + 1, length - 1]/inorder_sub_list[inorder_sub_list_pivot + 1, length - 1])为右子树;\n\n
 * </span>
 * 使用cur_subtree_root_data, 分配内存并初始化subtree_root\n
 * **if** 内存分配失败 :\n
 * &emsp; 返回false\n\n
 * + **3 递归构造左子树和右子树**\n
 * 调用CreateSubtreeByPreorderAndInorderList_, 使用preorder_sub_list[1, inorder_sub_list_pivot] 和 inorder_sub_list[0, inorder_sub_list_pivot - 1], 构造sub_tree的左子树\n
 * **if** 构造失败 :\n
 * &emsp; 返回false\n\n
 * 调用CreateSubtreeByPreorderAndInorderList_, 使用preorder_sub_list[inorder_sub_list_pivot + 1, length - 1] 和 inorder_sub_list[inorder_sub_list_pivot + 1, length - 1], 构造sub_tree的右子树\n
 * 返回调用结果\n
 */
template<typename TData>
bool BinaryTree<TData>::CreateSubtreeByPreorderAndInorderList_(TData* preorder_sub_list,
                                                               TData* inorder_sub_list,
                                                               int length,
                                                               BinaryTreeNode<TData>*& subtree_root)
{
    // ---------- 1 空子序列处理 ----------

    if (length == 0) {                                                              // if length == 0
        return true;                                                                // 返回true
    }

    // ---------- 2 中序序列找到轴, 并生成子树根结点 ----------

    int inorder_sub_list_pivot = 0;                                                 // 初始化inorder_sub_list_pivot(中序遍历子序列轴)为0
    TData cur_subtree_root_data = *preorder_sub_list;                               // 初始化cur_subtree_root_data, 指向前序遍历序列首元素

    while (cur_subtree_root_data != inorder_sub_list[inorder_sub_list_pivot]) {     // while loop cur_subtree_root_data != inorder_sub_list[inorder_sub_list_pivot]
        inorder_sub_list_pivot++;                                                   // inorder_sub_list_pivot向后移动1个位置
    }

    // 此时:
    // (preorder_sub_list[1, inorder_sub_list_pivot] / inorder_sub_list[0, inorder_sub_list_pivot - 1])为左子树
    // inorder_sub_list[inorder_sub_list_pivot]为子树根结点
    // (preorder_sub_list[inorder_sub_list_pivot + 1, length - 1]/inorder_sub_list[inorder_sub_list_pivot + 1, length - 1])为右子树

    subtree_root = new BinaryTreeNode<TData>(cur_subtree_root_data);                // 使用cur_subtree_root_data, 分配内存并初始化subtree_root
    if (subtree_root == NULL) {                                                     // if 内存分配失败
        return false;                                                               // 返回false
    }

    // ---------- 3 递归构造左子树和右子树 ----------

    // 调用CreateSubtreeByPreorderAndInorderList_,
    // 使用preorder_sub_list[1, inorder_sub_list_pivot] 和 inorder_sub_list[0, inorder_sub_list_pivot - 1],
    // 构造sub_tree的左子树
    bool res = CreateSubtreeByPreorderAndInorderList_(preorder_sub_list + 1,
                                                      inorder_sub_list,
                                                      inorder_sub_list_pivot,
                                                      subtree_root->left_child);
    if (!res) {                                                                     // if 构造失败
        return false;                                                               // 返回false
    }

    // 调用CreateSubtreeByPreorderAndInorderList_,
    // 使用preorder_sub_list[inorder_sub_list_pivot + 1, length - 1]/inorder_sub_list[inorder_sub_list_pivot + 1, length - 1],
    // 构造sub_tree的右子树
    res = CreateSubtreeByPreorderAndInorderList_(preorder_sub_list + inorder_sub_list_pivot + 1,
                                                 inorder_sub_list + inorder_sub_list_pivot + 1,
                                                 length - inorder_sub_list_pivot - 1,
                                                 subtree_root->right_child);

    return res;                                                                     // 返回调用结果
}


/*!
 * @brief **判断两颗二叉树是否相同(递归)**
 * @tparam TData 数据项类型模板参数
 * @param root1 根节点1
 * @param root2 根节点2
 * @return 是否相同
 * @note
 * 判断两颗二叉树是否相同(递归)
 * -----------------------
 * -----------------------
 *
 * -----------------------
 * + **1 两个空树比较**\n
 * **if** root1和root2都为NULL :\n
 * &emsp; 返回 true\n\n
 * + **2 递归**\n
 * **if** root1不为NULL && root2不为NULL && root1->data == root2->data &&
 *  Equal(root1->left_child, root2->left_child)和Equal(root1->right_child, root2->right_child)都返回true :\n
 * &emsp; 返回true\n\n
 * + **3 退出函数**\n
 * 返回false\n
 */
template<typename TData>
bool BinaryTree<TData>::Equal(BinaryTreeNode<TData>* root1, BinaryTreeNode<TData>* root2) {
    // ---------- 1 两个空树比较 ----------

    if (root1 == NULL && root2 == NULL) {                                       // if root1和root2都为NULL
        return true;                                                            // 返回 true
    }

    // ---------- 2 递归 ----------

    if (root1 != NULL && root2 != NULL && root1->data == root2->data            // if root1不为NULL && root2不为NULL && root1->data == root2->data &&
        && BinaryTree<TData>::Equal(root1->left_child, root2->left_child)       // Equal(root1->left_child, root2->left_child)返回true
        && BinaryTree<TData>::Equal(root1->right_child, root2->right_child))    // Equal(root1->right_child, root2->right_child)返回true
    {
        return true;                                                            // 返回true
    }

    // ---------- 3 退出函数 ----------

    return false;                                                               // 返回false
}


 /*!
  * @brief **重载==**
  * @tparam TData 数据项类型模板参数
  * @param binary_tree_1 二叉树1
  * @param binary_tree_2 二叉树2
  * @return 结果
  * @note
  * 重载==
  * -----
  * -----
  *
  * -----
  * 调用BinaryTree<TData>::Equal(binary_tree_1.Root(), binary_tree_2.Root()), 返回结果\n
  */
template<typename TData>
bool operator==(const BinaryTree<TData>& binary_tree_1, const BinaryTree<TData>& binary_tree_2) {
    return (BinaryTree<TData>::Equal(binary_tree_1.Root(), binary_tree_2.Root()));
}


/*!
 * @brief **重载&lt;&lt;**
 * @tparam TData 数据项类型模板参数
 * @param out 输出流
 * @param binary_tree 二叉树
 * @return 输出流
 * @note
 * 重载<<
 * -----
 * -----
 *
 * -----
 * 调用binary_tree.Print()\n
 */
template<typename TData>
ostream& operator<<(ostream& out, BinaryTree<TData>& binary_tree) {
    binary_tree.Print();
    return out;
}


#endif //CYBER_DASH_BINARY_TREE_H
