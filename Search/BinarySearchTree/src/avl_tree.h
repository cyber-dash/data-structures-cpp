/*!
 * @file avl_tree.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief AVL树结点模板类与AVL树模板类
 * @version 0.2.1
 * @date 2023-02-22
 */

#ifndef CYBER_DASH_AVL_TREE_H
#define CYBER_DASH_AVL_TREE_H


#include <stack>
#include "binary_search_tree.h"


/*!
 * @brief **AVL树结点模板类**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 */
template<typename TKey, typename TValue>
class AvlNode: public BstNode<TKey, TValue> {
public:

    /*!
     * @brief **默认构造函数**
     * @note
     * 默认构造函数
     * ----------
     * ----------
     * 左右孩子为NULL, 高度设为1, 平衡因子设为0
     */
    AvlNode(): left_child_(NULL), right_child_(NULL), height_(1), balance_factor_(BALANCED) {}

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
     * 设置key_/value_, 左右孩子为NULL, 高度设为1, 平衡因子设为0
     */
    AvlNode(const TKey& key, const TValue& value) :
        value_(value), key_(key), left_child_(NULL), right_child_(NULL), height_(1), balance_factor_(BALANCED) {}

    /*!
     * @brief **构造函数(关键字/值/左右孩子)**
     * @param key 关键字
     * @param value 值
     * @param left_child 左孩子
     * @param right_child 右孩子
     * @note
     * 构造函数(关键字/值/左右孩子)
     * ------------------------
     * ------------------------
     *
     * ------------------------
     * 设置key_/value_/左右孩子, 高度设为1, 平衡因子设为0
     */
    AvlNode(TKey key, TValue value, AvlNode<TKey, TValue>* left_child, AvlNode<TKey, TValue>* right_child) :
        value_(value), key_(key), left_child_(left_child), right_child_(right_child),
        height_(1), balance_factor_(BALANCED) {}

    /*!
     * @brief **获取左孩子结点**
     * @return 左孩子结点(指针引用)
     */
    AvlNode<TKey, TValue>*& LeftChild() { return this->left_child_; };

    /*!
     * @brief **设置左孩子结点**
     * @param node 结点(指针)
     */
    void SetLeftChild(AvlNode<TKey, TValue>* node) { this->left_child_ = node; }

    /*!
     * @brief **获取右孩子结点**
     * @return 右孩子结点(指针引用)
     */
    AvlNode<TKey, TValue>*& RightChild() { return this->right_child_; };

    /*!
     * @brief **设置右孩子结点**
     * @param node 结点(指针)
     */
    void SetRightChild(AvlNode<TKey, TValue>* node) { this->right_child_ = node; }

    /*!
     * @brief **获取关键字**
     * @return 关键字
     */
    TKey Key() { return this->key_; }
    /*!
     * @brief **设置关键字**
     * @param key 关键字
     */
    void SetKey(const TKey& key) { this->key_ = key; }

    /*!
     * @brief **获取值**
     * @return 值
     */
    TValue Value() { return this->value_; }
    /*!
     * @brief **设置值**
     * @param value 值
     */
    void SetValue(const TValue& value) { this->value_ = value; }

    /*!
     * @brief **获取高度**
     * @return 高度
     */
    int Height() { return this->height_; }
    /*!
     * @brief **设置高度**
     * @param height 高度
     */
    void SetHeight(int height) { this->height_ = height; }

    /*!
     * @brief **获取平衡因子**
     * @return 平衡因子
     */
    int BalanceFactor() { return this->balance_factor_; }
    /*!
     * @brief **设置平衡因子**
     * @param balance_factor 平衡因子
     */
    void SetBalanceFactor(int balance_factor) { this->balance_factor_ = balance_factor; }

    /*!
     * @brief **更新高度**
     * @note
     * 更新高度
     * -------
     * -------
     *
     * 以该结点为根结点的子树, 更新高度
     *
     * -------
     * 获取left_height(左子树高度)\n
     * 获取right_height(右子树高度)\n
     * 取left_height最大值, 加1赋给height_\n
     */
    void UpdateHeight() {
        int left_height = LeftChild() ? LeftChild()->Height() : 0;
        int right_height = RightChild() ? RightChild()->Height() : 0;
        this->height_ = (left_height > right_height ? left_height : right_height) + 1;
    }

    /*!
     * @brief **更新平衡因子**
     * @note
     * 更新平衡因子
     * -----------
     * -----------
     *
     * 以该结点为根结点的子树, 更新平衡因子
     *
     * -----------
     * 获取left_height(左子树高度)\n
     * 获取right_height(右子树高度)\n
     * 取right_height - left_height赋给balance_factor_\n
     */
    void UpdateBalanceFactor() {
        int left_height = LeftChild() ? LeftChild()->Height() : 0;
        int right_height = RightChild() ? RightChild()->Height() : 0;
        this->balance_factor_ = right_height - left_height;
    }

    static const int RIGHT_HIGHER_2 = 2;    //!< **左子树比右子树矮2**
    static const int RIGHT_HIGHER_1 = 1;    //!< **左子树比右子树矮1**
    static const int BALANCED = 0;          //!< **左右平衡**
    static const int LEFT_HIGHER_1 = -1;    //!< **左子树比右子树高1**
    static const int LEFT_HIGHER_2 = -2;    //!< **左子树比右子树高2**

protected:
    TKey key_;                              //!< 关键字
    TValue value_;                          //!< 值

    AvlNode<TKey, TValue>* left_child_;     //!< 左孩子
    AvlNode<TKey, TValue>* right_child_;    //!< 右孩子

    int height_;                            //!< 高度
    int balance_factor_;                    //!< 平衡因子
};


/*!
 * @brief **AVL树模板类**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 */
template<typename TKey, typename TValue>
class AvlTree : public BinarySearchTree<TKey, TValue> {
public:
    /*!
     * @brief **默认构造函数**
     * @note
     * 默认构造函数
     * ----------
     * ----------
     *
     * ----------
     * root_设置为NULL
     */
    AvlTree() : root_(NULL) {}

    /*!
     * @brief **获取根结点**
     * @return 根结点
     * @note
     * 获取根结点
     * --------
     * --------
     *
     * --------
     * 返回root_
     */
    AvlNode<TKey, TValue>*& Root() { return this->root_; }

    // 设置根结点
    void SetRoot(AvlNode<TKey, TValue>* node) { this->root_ = node; }

    // 插入结点
    bool Insert(TKey key, TValue value);
    // 插入结点(递归)
    bool InsertRecursive(TKey key, TValue value);

    // 删除结点
    bool Remove(TKey key);
    // 删除结点(递归)
    bool RemoveRecursive(TKey key);

    /*!
     * @brief **获取高度**
     * @return 高度
     * @note
     * 获取高度
     * ------
     * ------
     *
     * ------
     * 调用root_->Height(), 返回高度
     */
    int Height() { return this->root_->Height(); }

    /*!
     * @brief **获取高度(递归)**
     * @return 高度
     * @note
     * 获取高度(递归)
     * ------------
     * ------------
     *
     * ------------
     * 对根结点调用HeightOfSubtreeRecursive_, 返回高度
     */
    int HeightRecursive() { return this->HeightOfSubtreeRecursive_(this->root_); }

    // 获取最大关键字对应的值
    bool Max(TValue& max_value);
    // 获取最小关键字对应的值
    bool Min(TValue& min_value);

    /*!
     * @brief **搜索**
     * @param key 关键字
     * @return 搜索结果
     * @note
     * 搜索
     * ---
     * ---
     *
     * ---
     * 调用SearchInSubTree_, 返回结果
     */
    AvlNode<TKey, TValue>* Search(TKey key) { return this->SearchInSubTree_(this->root_, key); }

    // 打印
    void Print(void (*visit)(AvlNode<TKey, TValue>*));

protected:
    // 子树插入结点(递归)
    bool InsertInSubTreeRecursive_(AvlNode<TKey, TValue>*& subtree_root, TKey key, TValue value);
    // 子树插入结点
    bool InsertInSubTree_(AvlNode<TKey, TValue>*& subtree_root, TKey key, TValue value);

    // 子树删除结点
    bool RemoveInSubTree_(AvlNode<TKey, TValue>*& subtree_root, TKey key);
    // 子树删除结点(递归)
    bool RemoveInSubTreeRecursive_(AvlNode<TKey, TValue>*& subtree_root, TKey key);

    // 插入动作平衡(by回溯栈)
    AvlNode<TKey, TValue>* InsertionBalanceByStack_(stack<AvlNode<TKey, TValue>*>& backtrack_stack);
    // 删除动作平衡(by回溯栈)
    AvlNode<TKey, TValue>* RemovalBalanceByStack_(stack<AvlNode<TKey, TValue>*>& backtrack_stack);
    // 平衡
    void Balance_(AvlNode<TKey, TValue>*& node);

    // 左单旋转(Left Rotation)
    int LeftRotate_(AvlNode<TKey, TValue>*& node);
    // 右单旋转(Right Rotation)
    int RightRotate_(AvlNode<TKey, TValue>*& node);
    // 先左后右双旋转(Left Right Rotation)
    int LeftRightRotate_(AvlNode<TKey, TValue>*& node);
    // 先右后左双旋转(Right Left Rotation)
    int RightLeftRotate_(AvlNode<TKey, TValue>*& node);

    // 子树搜索(递归)
    AvlNode<TKey, TValue>* SearchInSubTree_(AvlNode<TKey, TValue>* subtree_root, TKey key);

    // 获取(子树中)关键字最小结点
    AvlNode<TKey, TValue>* MinInSubTree_(AvlNode<TKey, TValue>* subtree_root) const;
    // 获取(子树中)关键字最大结点
    AvlNode<TKey, TValue>* MaxInSubTree_(AvlNode<TKey, TValue>* subtree_root) const;

    // 获取结点的(中序)前一结点
    AvlNode<TKey, TValue>* PreviousNode_(AvlNode<TKey, TValue>* node);

    // 子树高度
    int HeightOfSubtreeRecursive_(AvlNode<TKey, TValue>* subtree_root);

    // 子树打印(递归)
    void PrintSubTreeRecursive_(AvlNode<TKey, TValue>* subtree_root, void (*Print)(AvlNode<TKey, TValue>*));

    // 检查插入合法性并初始化回溯栈
    bool CheckInsertLegalAndInitStack_(TKey key,
                                       AvlNode<TKey, TValue>* subtree_root,
                                       stack<AvlNode<TKey, TValue>*>& backtrack_stack);

    // 定位删除结点并初始化回溯栈
    AvlNode<TKey, TValue>* FindRemoveNodeAndInitStack_(AvlNode<TKey, TValue>* subtree_root,
                                                       TKey key,
                                                       stack<AvlNode<TKey, TValue>*>& backtrack_stack);

    AvlNode<TKey, TValue>* root_; //!< 根结点
};


/*!
 * @brief **左单旋转(Left Rotation)**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 * @param node 待旋转结点
 * @return 旋转后的平衡因子
 * @note
 * 左单旋转(Left Rotation)
 * ----------------------
 * ----------------------
 * <span style="color:#FF9900">
 * **情景1:**\n
 * </span>
 * ```
 *          node                             pivot
 *            \                               / \
 *             \                             /   \
 *            pivot        ---->          node  node3
 *             / \                           \
 *            /   \                           \
 *        node2  node3                       node2
 * ```
 *
 * <span style="color:#E76600">
 * **情景2:**\n
 * </span>
 * ```
 *          node                              pivot
 *            \                                / \
 *             \                              /   \
 *            pivot         ---->           node  node3
 *               \
 *                \
 *              node3
 * ```
 * ----------------------
 * + **1 指定pivot(旋转轴)**\n
 * &emsp; 取结点右孩子为pivot<b>(旋转轴)</b>\n
 * + **2 旋转**\n
 * &emsp; pivot的左孩子, 改为node的右孩子\n
 * &emsp; node改为pivot的左孩子\n
 * + **3 调整高度和平衡因子**\n
 *  - **3.1 调整高度**\n
 *  &emsp; node更新高度\n
 *  &emsp; pivot更新高度\n
 *  - **3.2 调整平衡因子**\n
 *  &emsp; node更新平衡因子\n
 *  &emsp; pivot更新平衡因子\n
 * + **4 修改node**\n
 * &emsp; node的<b>(引用)</b>值改为pivot\n
 * + **5 返回旋转后的平衡因子**\n
 * 返回node的平衡因子\n
 */
template<class TKey, class TValue>
int AvlTree<TKey, TValue>::LeftRotate_(AvlNode<TKey, TValue>*& node) {

    // ---------- 1 指定pivot(旋转轴) ----------

    AvlNode<TKey, TValue>* pivot = node->RightChild();  // 取结点右孩子为pivot(旋转轴)

    // ---------- 2 旋转 ----------

    node->SetRightChild(pivot->LeftChild());            // pivot的左孩子, 改为node的右孩子
    pivot->SetLeftChild(node);                          // node改为pivot的左孩子

    // ---------- 3 调整高度和平衡因子 ----------

    // ----- 3.1 调整高度 -----
    node->UpdateHeight();                               // node更新高度
    pivot->UpdateHeight();                              // pivot更新高度

    // ----- 3.2 调整平衡因子 -----
    node->UpdateBalanceFactor();                        // node更新平衡因子
    pivot->UpdateBalanceFactor();                       // pivot更新平衡因子

    // ---------- 4 修改node ----------

    node = pivot;                                       // node的(引用)值改为pivot

    // ---------- 5 返回旋转后的平衡因子 ----------

    return node->BalanceFactor();                       // 返回node的平衡因子
}


/**
 * @brief **右单旋转(Right Rotation)**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 * @param node 待旋转结点
 * @return 旋转后的平衡因子
 * @note
 * -----------------
 * -----------------
 *
 * <span style="color:#FF9900">
 * **情景1:**\n
 * </span>
 * ```
 *                node                       pivot
 *                /                           / \
 *               /                           /   \
 *            pivot          ----->          node2  node
 *             / \                               /
 *            /   \                             /
 *        node2  node3                       node3
 * ```
 *
 * <span style="color:#E76600">
 * **情景2:**\n
 * </span>
 * ```
 *               node                         pivot
 *                /                            / \
 *               /                            /   \
 *            pivot          ----->          node2  node
 *             /
 *            /
 *         node2
 * ```
 * <span style="color:#E76600">
 * **情景3:**\n
 * </span>
 * ```
 *               node                                  pivot
 *               / \                                   / \
 *              /   \                                 /   \
 *          pivot  node2                           node3  node
 *            / \              ----->               /     / \
 *           /   \                                 /     /   \
 *       node3  node4                          node5  node4  node2
 *         /
 *        /
 *     node5
 * ```
 *
 * -----------------
 * + **1 指定pivot(旋转轴)**\n
 * &emsp; 取结点左孩子为pivot<b>(旋转轴)</b>\n
 * + **2 旋转**\n
 * &emsp; pivot的右孩子, 改为node的左孩子\n
 * &emsp; node改为pivot的右孩子\n
 * + **3 调整高度和平衡因子**\n
 *  - **3.1 调整高度**\n
 *  &emsp; node更新高度\n
 *  &emsp; pivot更新高度\n
 *  - **3.2 调整平衡因子**\n
 *  &emsp; node更新平衡因子\n
 *  &emsp; pivot更新平衡因子\n
 * + **4 修改node**\n
 * &emsp; node的<b>(引用)</b>值改为pivot\n
 * + **5 返回旋转后的平衡因子**\n
 * 返回node的平衡因子\n
 */
template<typename TKey, typename TValue>
int AvlTree<TKey, TValue>::RightRotate_(AvlNode<TKey, TValue>*& node) {

    // ---------- 1 指定pivot(旋转轴) ----------

    AvlNode<TKey, TValue>* pivot = node->LeftChild();       // 取结点左孩子为pivot(旋转轴)

    // ---------- 2 旋转 ----------

    node->SetLeftChild(pivot->RightChild());                // pivot的右孩子, 改为node的左孩子
    pivot->SetRightChild(node);                             // node改为pivot的右孩子

    // ---------- 3 调整高度和平衡因子 ----------

    // ----- 3.1 调整高度 -----
    node->UpdateHeight();                                   // node更新高度
    pivot->UpdateHeight();                                  // pivot更新高度

    // ----- 3.2 调整平衡因子 -----
    node->UpdateBalanceFactor();                            // node更新平衡因子
    pivot->UpdateBalanceFactor();                           // pivot更新平衡因子

    // ---------- 4 修改node ----------

    node = pivot;                                           // node的(引用)值改为pivot

    // ---------- 5 返回旋转后的平衡因子 ----------

    return node->BalanceFactor();                           // 返回node的平衡因子
}


/*!
 * @brief **左右旋(Left-Right Rotation)**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 * @param node 待旋转结点
 * @return 旋转后的平衡因子
 * @note
 * 左右旋(Left-Right Rotation)
 * --------------------------
 * --------------------------
 *
 * 场景示例(仅示例, 未完全覆盖所有场景)
 *
 * <span style="color:#FF9900">
 * **情景1:**\n
 * </span>
 * ```
 *                node                        node                        pivot
 *                /                           /                            / \
 *               /                           /                            /   \
 *            node2     ----左旋1次---->   pivot   ----右旋1次---->     node2  node
 *               \                         /
 *                \                       /
 *               pivot                 node2
 * ```
 *
 * <span style="color:#FF9900">
 * **情景2:**\n
 * </span>
 * ```
 *               node                                    node                                      pivot
 *               / \                                      / \                                       / \
 *              /   \                                    /   \                                     /   \
 *          node2  node3                             pivot  node3                               node2  node
 *             / \                                     /                                         / \     \
 *            /   \             ----左旋1次---->      /               ----右旋1次---->          /   \     \
 *        node4  pivot                              node2                                   node4 node5  node3
 *                /                                 / \
 *               /                                 /   \
 *            node5                             node4 node5
 * ```
 *
 * --------------------------
 * 1. 对node的左孩子执行Left Rotate(左旋)\n
 * 2. 对node执行Right Rotate(右旋)\n
 * 3. 返回最新的平衡因子\n
 */
template<typename TKey, typename TValue>
int AvlTree<TKey, TValue>::LeftRightRotate_(AvlNode<TKey, TValue>*& node) {

    this->LeftRotate_(node->LeftChild());   // 1. 对node的左孩子执行Left Rotate(左旋)

    this->RightRotate_(node);               // 2. 对node执行Right Rotate(右旋)

    return node->BalanceFactor();           // 3. 返回最新的平衡因子
}


/*!
 * @brief **右左旋**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 * @param node 带旋转结点
 * @return 旋转后的平衡因子
 * 右左旋
 * -----
 * -----
 *
 * 场景示例(仅示例, 未完全覆盖所有场景)
 *
 * <span style="color:#FF9900">
 * **情景1:**\n
 * </span>
 * ```
 *         node                         node                              pivot
 *            \                           \                                / \
 *             \                           \                              /   \
 *            node2     ----右旋1次---->   pivot   ----左旋1次---->      node  node2
 *             /                             \
 *            /                               \
 *         pivot                             node2
 * ```
 *
 * <span style="color:#FF9900">
 * **情景2:**\n
 * </span>
 * ```
 *          node                                         node                                          pivot
 *          / \                                           / \                                           / \
 *         /   \                                         /   \                                         /   \
 *      node2 node3                                  node2  pivot                                   node   node3
 *             / \                                             \                                     /     / \
 *            /   \             ----右旋1次---->                \         ----左旋1次---->          /     /   \
 *        pivot  node4                                         node3                             node2  node5 node4
 *           \                                                  / \
 *            \                                                /   \
 *           node5                                          node5 node4
 * ```
 *
 * -----
 * 1. 对node的右孩子执行Right Rotate(右旋)\n
 * 2. 对node执行Left Rotate(左旋)\n
 * 3. 返回最新的平衡因子\n
 */
template<typename TKey, typename TValue>
int AvlTree<TKey, TValue>::RightLeftRotate_(AvlNode<TKey, TValue>*& node) {

    this->RightRotate_(node->RightChild());  // 1. 对node的右孩子执行Right Rotate(右旋)

    this->LeftRotate_(node);                 // 2. 对node执行Left Rotate(左旋)

    return node->BalanceFactor();            // 3. 返回最新的平衡因子
}


/*!
 * @brief **插入结点**
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
 * 对根结点调用InsertInSubTree_, 返回结果
 */
template<typename TKey, typename TValue>
bool AvlTree<TKey, TValue>::Insert(TKey key, TValue value) {
    return this->InsertInSubTree_(this->Root(), key, value);    // 对根结点调用InsertInSubTree_, 返回结果
}


/*!
 * @brief **插入结点(递归)**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 * @param key 关键字
 * @param value 值
 * @return 执行结果
 * @note
 * 插入结点(递归)
 * ------------
 * ------------
 *
 * ------------
 * 对根结点调用InsertInSubTreeRecursive_
 */
template<typename TKey, typename TValue>
bool AvlTree<TKey, TValue>::InsertRecursive(TKey key, TValue value) {
    return this->InsertInSubTreeRecursive_(this->Root(), key, value);   // 对根结点调用InsertInSubTreeRecursive_
}


/*!
 * @brief **删除结点(递归)**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 * @param key 关键字
 * @return 执行结果
 * @note
 * 删除结点(递归)
 * ------------
 * ------------
 *
 * ------------
 * 对根结点调用RemoveInSubTreeRecursive_
 */
template<typename TKey, typename TValue>
bool AvlTree<TKey, TValue>::RemoveRecursive(TKey key) {
    return this->RemoveInSubTreeRecursive_(this->Root(), key);  // 对根结点调用RemoveInSubTreeRecursive_
}


/*!
 * @brief **插入后平衡(by回溯栈)**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 * @param backtrack_stack 回溯栈
 * @return 平衡后的子树根结点
 * @note
 * 插入后平衡(by回溯栈)
 * -----------------
 * -----------------
 *
 * -----------------
 * 声明并初始化cur_parent_node<b>(当前父节点)</b>为NULL\n\n
 * **while loop** 回溯栈不为空 :\n\n
 * &emsp; 取栈顶, 赋给cur_parent_node\n
 * &emsp; 栈顶出栈\n\n
 * &emsp; cur_parent_node更新平衡因子\n
 * &emsp; **if** cur_parent_node平衡 :\n
 * &emsp;&emsp; break <span style="color:#FF9900">(平衡结束, 跳出循环)</span>\n\n
 * &emsp; **if** 平衡因子为1或者-1(右子树高1或者左子树高1) :\n
 * &emsp;&emsp; (不做任何操作)\n
 * &emsp; **else** ( 平衡因子为2或者-2(右子树高2或者左子树高2) ) :\n
 * &emsp;&emsp; 对cur_parent_node执行平衡\n
 * &emsp;&emsp; break <span style="color:#FF9900">(回溯栈内的结点, 都已经平衡, 可以自行证明验证)</span>\n\n
 * &emsp; cur_parent_node更新高度\n\n
 * 返回cur_parent_node\n
 */
template<typename TKey, typename TValue>
AvlNode<TKey, TValue>* AvlTree<TKey, TValue>::InsertionBalanceByStack_(stack<AvlNode<TKey, TValue>*>& backtrack_stack) {

    AvlNode<TKey, TValue>* cur_parent_node = NULL;                                          // 声明并初始化cur_parent_node(当前父节点)为NULL

    while (!backtrack_stack.empty()) {                                                      // while loop 回溯栈不为空

        cur_parent_node = backtrack_stack.top();                                            // 取栈顶, 赋给cur_parent_node
        backtrack_stack.pop();                                                              // 栈顶出栈

        cur_parent_node->UpdateBalanceFactor();                                             // cur_parent_node更新平衡因子
        if (cur_parent_node->BalanceFactor() == AvlNode<TKey, TValue>::BALANCED) {          // if cur_parent_node平衡
            break;                                                                          // break(平衡结束, 跳出循环)
        }

        if (cur_parent_node->BalanceFactor() == AvlNode<TKey, TValue>::RIGHT_HIGHER_1 ||    // if 平衡因子为1或者-1, 右子树高1或者左子树高1
            cur_parent_node->BalanceFactor() == AvlNode<TKey, TValue>::LEFT_HIGHER_1)
        {
                                                                                            // (不做任何操作)
        } else {                                                                            // else (平衡因子为2或者-2, 右子树高2或者左子树高2)
            this->Balance_(cur_parent_node);                                                // 对cur_parent_node执行平衡
            break;                                                                          // break(回溯栈内的结点, 都已经平衡, 可以自行证明验证)
        }

        cur_parent_node->UpdateHeight();                                                    // cur_parent_node更新高度
    }

    return cur_parent_node;                                                                 // 返回cur_parent_node
}


/*!
 * @brief **删除动作平衡(by回溯栈)**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 * @param backtrack_stack 回溯栈
 * @return 平衡后的子树根结点
 * @note
 * 删除动作平衡(by回溯栈)
 * -------------------
 * -------------------
 *
 * -------------------
 * 声明并初始化cur_parent_node(当前父节点)为NULL\n\n
 * **while loop** 回溯栈不为空 :\n\n
 * &emsp; 取栈顶, 赋给cur_parent_node(当前父节点)\n
 * &emsp; 栈顶出栈\n\n
 * &emsp; 声明grand_parent_direction(祖父结点与父节点的关系)\n\n
 * &emsp; **if** 回溯栈为不为空 :\n
 * &emsp;&emsp; 取栈顶, 赋给cur_grand_node(祖父结点)\n\n
 * &emsp;&emsp; **if** 父节点是祖父结点的左孩子 :\n
 * &emsp;&emsp;&emsp; grand_parent_direction设置成-1(左)\n
 * &emsp;&emsp; **else if** 父节点是祖父结点的左孩子 :\n
 * &emsp;&emsp;&emsp; grand_parent_direction设置成1(右)\n\n
 * &emsp; cur_parent_node更新高度\n
 * &emsp; cur_parent_node更新平衡因子\n
 * &emsp; cur_parent_node进行平衡\n\n
 * &emsp; **if** 回溯栈不为空 :\n
 * &emsp;&emsp; 取栈顶, 赋给cur_grand_node(祖父结点)\n\n
 * &emsp;&emsp; **if** grand_parent_direction为-1(父节点是祖父结点的左孩子) :\n
 * &emsp;&emsp;&emsp; cur_parent_node设置成cur_grand_node的左孩子\n
 * &emsp;&emsp; **else** (grand_parent_direction为-1(父节点是祖父结点的左孩子)) :\n
 * &emsp;&emsp;&emsp; cur_parent_node设置成cur_grand_node的右孩子\n\n
 * 返回cur_parent_node\n
 */
template<typename TKey, typename TValue>
AvlNode<TKey, TValue>* AvlTree<TKey, TValue>::RemovalBalanceByStack_(stack<AvlNode<TKey, TValue>*>& backtrack_stack) {

    AvlNode<TKey, TValue>* cur_parent_node = NULL;                              // 声明并初始化cur_parent_node(当前父节点)为NULL

    while (!backtrack_stack.empty()) {                                          // while loop 回溯栈不为空

        cur_parent_node = backtrack_stack.top();                                // 取栈顶, 赋给cur_parent_node(当前父节点)
        backtrack_stack.pop();                                                  // 栈顶出栈

        int grand_parent_direction;                                             // 声明grand_parent_direction(祖父结点与父节点的关系)

        if (!backtrack_stack.empty()) {                                         // if 回溯栈为不为空
            AvlNode<TKey, TValue>* cur_grand_node = backtrack_stack.top();      // 取栈顶, 赋给cur_grand_node(祖父结点)

            if (cur_grand_node->LeftChild() == cur_parent_node) {               // if 父节点是祖父结点的左孩子
                grand_parent_direction = -1;                                    // grand_parent_direction设置成-1(左)
            } else if (cur_grand_node->RightChild() == cur_parent_node) {       // else if 父节点是祖父结点的左孩子
                grand_parent_direction = 1;                                     // grand_parent_direction设置成1(右)
            }
        }

        cur_parent_node->UpdateHeight();                                        // cur_parent_node更新高度
        cur_parent_node->UpdateBalanceFactor();                                 // cur_parent_node更新平衡因子

        this->Balance_(cur_parent_node);                                        // cur_parent_node进行平衡

        if (!backtrack_stack.empty()) {                                         // if 回溯栈不为空
            AvlNode<TKey, TValue>* cur_grand_node = backtrack_stack.top();      // 取栈顶, 赋给cur_grand_node(祖父结点)

            if (grand_parent_direction == -1) {                                 // if grand_parent_direction为-1(父节点是祖父结点的左孩子)
                cur_grand_node->SetLeftChild(cur_parent_node);                  // cur_parent_node设置成cur_grand_node的左孩子
            } else {                                                            // else (grand_parent_direction为-1(父节点是祖父结点的左孩子))
                cur_grand_node->SetRightChild(cur_parent_node);                 // cur_parent_node设置成cur_grand_node的右孩子
            }
        }
    }

    return cur_parent_node;                                                     // 返回cur_parent_node
}


/*!
 * @brief **平衡**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 * @param node 结点
 * @note
 * 平衡
 * ---
 * ---
 *
 * ---
 * **if** 右子树高度 > 左子树高度 2个结点 :\n
 * &emsp; **if** 右子树侧, (左子树高度 == 右子树高度) or (左子树高度 < 右子树高度 1个结点) :\n
 * &emsp;&emsp; 执行LeftRotate_(左单旋转)\n
 * &emsp; **else** (右子树侧, 左子树高度 > 右子树高度 1个结点) :\n
 * &emsp;&emsp; 执行RightLeftRotate_(右左旋转)\n
 * **else if** 左子树高度 > 右子树高度 2个结点 :\n
 * &emsp; **if** 左子树侧, (左子树高度 == 右子树高度) or (左子树高度 > 右子树高度 1个结点) :\n
 * &emsp;&emsp; 执行RightRotate_(右单旋转)\n
 * &emsp; **else** (左子树侧, 左子树高度 < 右子树高度 1个结点) :\n
 * &emsp;&emsp; 执行LeftRightRotate_(左右旋转)\n
 */
template<typename TKey, typename TValue>
void AvlTree<TKey, TValue>::Balance_(AvlNode<TKey, TValue>*& node) {
    if (node->BalanceFactor() == AvlNode<TKey, TValue>::RIGHT_HIGHER_2) {                   // if 右子树高度 > 左子树高度 2个结点
        if (node->RightChild()->BalanceFactor() != AvlNode<TKey, TValue>::LEFT_HIGHER_1) {  // if 右子树侧, (左子树高度 == 右子树高度) or (左子树高度 < 右子树高度 1个结点)
            this->LeftRotate_(node);                                                        // 执行LeftRotate_(左单旋转)
        } else {                                                                            // else (右子树侧, 左子树高度 > 右子树高度 1个结点)
            this->RightLeftRotate_(node);                                                   // 执行RightLeftRotate_(右左旋转)
        }
    } else if (node->BalanceFactor() == AvlNode<TKey, TValue>::LEFT_HIGHER_2) {             // else if 左子树高度 > 右子树高度 2个结点
        if (node->LeftChild()->BalanceFactor() != AvlNode<TKey, TValue>::RIGHT_HIGHER_1) {  // if 左子树侧, (左子树高度 == 右子树高度) or (左子树高度 > 右子树高度 1个结点)
            this->RightRotate_(node);                                                       // 执行RightRotate_(右单旋转)
        } else {                                                                            // else (左子树侧, 左子树高度 < 右子树高度 1个结点)
            this->LeftRightRotate_(node);                                                   // 执行LeftRightRotate_(左右旋转)
        }
    }
}


/*!
 * @brief **子树插入结点(递归)**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 * @param subtree_root 子树根结点
 * @param key 关键字
 * @param value 值
 * @return 执行结果
 * @note
 * 子树插入结点(递归)
 * ------------------
 * ------------------
 *
 * ------------------
 * + **1 空子树插入结点**\n
 * **if** 子树根结点为NULL :\n
 * &emsp; 子树根结点分配内存并初始化\n
 * &emsp; **if** 内存分配失败 :\n
 * &emsp;&emsp; 抛出bad_alloc\n
 * &emsp; 返回true\n\n
 * + **2 重复插入处理**\n
 * **if** 插入关键字 == 子树根结点关键字 :\n
 * &emsp; 返回false(重复插入)\n\n
 * + **3 分治递归**\n
 * **if** 插入关键字 < 子树根结点关键字 :\n
 * &emsp; 对子树根结点的左孩子结点执行递归插入\n
 * &emsp; **if** 插入失败 :\n
 * &emsp;&emsp; 返回false\n
 * **else if** 插入关键字 > 子树根结点关键字 :\n
 * &emsp; 对子树根结点的右孩子结点执行递归插入\n
 * &emsp; **if** 插入失败 :\n
 * &emsp;&emsp; 返回false\n\n
 * + **4 调整平衡**\n
 * 更新子树根结点的高度\n
 * 更新子树根结点的平衡因子\n
 * 对子树根结点进行平衡\n\n
 * + **5 函数返回**\n
 * 返回true(结束递归)\n
 */
template<typename TKey, typename TValue>
bool AvlTree<TKey, TValue>::InsertInSubTreeRecursive_(AvlNode<TKey, TValue>*& subtree_root, TKey key, TValue value) {

    // ---------- 1 空子树插入结点 ----------

    if (!subtree_root) {                                                                // if 子树根结点为NULL
        subtree_root = new AvlNode<TKey, TValue>(key, value);                           // 子树根结点分配内存并初始化
        if (!subtree_root) {                                                            // if 内存分配失败
            throw bad_alloc();                                                          // 抛出bad_alloc
        }

        return true;                                                                    // 返回true
    }

    // ---------- 2 重复插入处理 ----------

    if (key == subtree_root->Key()) {                                                   // if 插入关键字 == 子树根结点关键字
        return false;                                                                   // 返回false(重复插入)
    }
    // ---------- 3 分治递归 ----------

    if (key < subtree_root->Key()) {                                                    // if 插入关键字 < 子树根结点关键字
        bool res = InsertInSubTreeRecursive_(subtree_root->LeftChild(), key, value);    // 对子树根结点的左孩子结点执行递归插入
        if (!res) {                                                                     // if 插入失败
            return res;                                                                 // 返回false
        }
    } else if (key > subtree_root->Key()) {                                             // else if 插入关键字 > 子树根结点关键字
        bool res = InsertInSubTreeRecursive_(subtree_root->RightChild(), key, value);   // 对子树根结点的右孩子结点执行递归插入
        if (!res) {                                                                     // if 插入失败
            return res;                                                                 // 返回false
        }
    }

    // ---------- 4 调整平衡 ----------

    subtree_root->UpdateHeight();                                                       // 更新子树根结点的高度
    subtree_root->UpdateBalanceFactor();                                                // 更新子树根结点的平衡因子

    Balance_(subtree_root);                                                             // 对子树根结点进行平衡

    // ---------- 5 函数返回 ----------

    return true;                                                                        // 返回true(结束递归)
}


/*!
 * @brief **子树插入结点**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 * @param subtree_root 子树根结点
 * @param key 关键字
 * @param value 值
 * @return 执行结果
 * @note
 * 子树插入结点
 * ----------
 * ----------
 *
 * <span style="color:#FF9900">
 * **非递归**\n
 * </span>
 *
 * ----------
 * + **1 重复插入检查与回溯栈初始化**\n
 * 声明backtrack_stack(回溯栈)\n
 * 检查是否重复插入, 并将沿途检查的各点入栈\n
 * **if** 重复插入 :\n
 * &emsp; 返回false\n\n
 * + **2 插入结点**\n
 * (2.1 初始化插入结点)\n
 * 初始化new_node(待插入结点)\n
 * **if** new失败 :\n
 * &emsp; 抛出bad_alloc()异常\n\n
 * (2.2 空子树插入结点)\n
 * **if** 回溯栈为空栈 :\n
 * &emsp; new_node成为根节点\n
 * &emsp; 返回true\n\n
 * (2.3 非空子树插入结点)\n
 * 取栈顶, 作为插入结点的父结点(parent_node)\n
 * **if** 插入结点key < 父结点key :\n
 * &emsp;&emsp; 插入结点为父结点的左孩子\n
 * **else** (插入结点key > 父结点key) :\n
 * &emsp;&emsp; 插入结点为父结点的右孩子\n
 * 对回溯栈内的结点做平衡, 返回最终的平衡结点balance_node\n\n
 * + **3 回溯栈处理结束后的补充处理**\n
 * **if** 回溯栈为空 :\n
 * &emsp; balance_node为最新的子树根结点\n
 * **else** (回溯栈不为空) :\n
 * &emsp; 取回溯栈栈顶\n
 * &emsp; **if** 栈顶结点key > 平衡点key :\n
 * &emsp;&emsp; 平衡点为栈顶结点的左孩子\n
 * &emsp; **else** (栈顶结点key < 平衡点key) :\n
 * &emsp;&emsp; 平衡点为栈顶结点的右孩子\n\n
 * + **4 函数返回**\n
 * 返回true\n
 */
template<typename TKey, typename TValue>
bool AvlTree<TKey, TValue>::InsertInSubTree_(AvlNode<TKey, TValue>*& subtree_root, TKey key, TValue value) {

    // ---------- 1 重复插入检查与回溯栈初始化 ----------

    stack<AvlNode<TKey, TValue>*> backtrack_stack;                                              // 声明backtrack_stack(回溯栈)

    bool res = CheckInsertLegalAndInitStack_(key, subtree_root, backtrack_stack);               // 检查是否重复插入, 并将沿途检查的各点入栈
    if (!res) {                                                                                 // if 重复插入
        return res;                                                                             // 返回false
    }

    // ---------- 2 插入结点 ----------

    // ----- 2.1 初始化插入结点 -----
    AvlNode<TKey, TValue>* new_node = new AvlNode<TKey, TValue>(key, value);                    // 初始化new_node(待插入结点)
    if (!new_node) {                                                                            // if new失败
        throw bad_alloc();                                                                      // 抛出bad_alloc()异常
    }

    // ----- 2.2 空子树插入结点 -----
    if (backtrack_stack.empty()) {                                                              // if 回溯栈为空栈
        subtree_root = new_node;                                                                // new_node成为根节点
        return true;                                                                            // 返回true
    }

    // ----- 2.3 非空子树插入结点 -----
    AvlNode<TKey, TValue>* parent_node = backtrack_stack.top();                                 // 取栈顶, 作为插入结点的父结点(parent_node)

    if (key < parent_node->Key()) {                                                             // if 插入结点key < 父结点key
        parent_node->SetLeftChild(new_node);                                                    // 插入结点为父结点的左孩子
    } else {                                                                                    // else (插入结点key > 父结点key)
        parent_node->SetRightChild(new_node);                                                   // 插入结点为父结点的右孩子
    }

    AvlNode<TKey, TValue>* balanced_node = this->InsertionBalanceByStack_(backtrack_stack);     // 对回溯栈内的结点做平衡, 返回最终的平衡结点balance_node

    // ---------- 3 回溯栈处理结束后的补充处理 ----------

    if (backtrack_stack.empty() == true) {                                                      // if 回溯栈为空
        subtree_root = balanced_node;                                                           // balance_node为最新的子树根结点
    } else {                                                                                    // else (回溯栈不为空)
        AvlNode<TKey, TValue>* stack_top_node = backtrack_stack.top();                          // 取回溯栈栈顶
        if (stack_top_node->Key() > balanced_node->Key()) {                                     // if 栈顶结点key > 平衡点key
            stack_top_node->SetLeftChild(balanced_node);                                        // 平衡点为栈顶结点的左孩子
        } else {                                                                                // else (栈顶结点key < 平衡点key)
            stack_top_node->SetRightChild(balanced_node);                                       // 平衡点为栈顶结点的右孩子
        }
    }

    // ---------- 4 函数返回 ----------

    return true;                                                                                // 返回true
}


/*!
 * @brief **子树删除结点(递归)**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 * @param subtree_root 子树根结点
 * @param key 待删除关键字
 * @return 执行结果
 * @note
 * 子树删除结点(递归)
 * ----------------
 * ----------------
 *
 * ----------------
 * + **1 空子树处理**\n
 * **if** 空子树 :\n
 * &emsp; 返回false\n\n
 * + **2 执行递归**\n
 * **if** 待删除key < 子树根结点key :\n
 * &emsp; 子树根结点左孩子, 递归执行RemovalInSubTreeRecursive_\n
 * &emsp; **if** 递归失败 :\n
 * &emsp;&emsp; 返回false\n
 * **else if** 待删除key > 子树根结点key :\n
 * &emsp; 子树根结点右孩子, 递归执行RemovalInSubTreeRecursive_\n
 * &emsp; **if** 递归失败 :\n
 * &emsp;&emsp; 返回false\n
 * **else** (待删除key 等于 子树根结点key) :\n
 * &emsp; **if** 子树为叶子(根结点没有左右孩子) :\n
 * &emsp;&emsp; 释放子树根结点\n
 * &emsp;&emsp; 返回true\n
 * &emsp; **else if** 子树左孩子为NULL :\n
 * &emsp;&emsp; 根结点指向右孩子\n
 * &emsp;&emsp; 原根结点释放\n
 * &emsp; **else if** 子树右孩子为NULL :\n
 * &emsp;&emsp; 根结点指向左孩子\n
 * &emsp;&emsp; 原根结点释放\n
 * &emsp; **else** (根结点同时存在左右孩子) \n
 * &emsp;&emsp; prev_node指向根结点中序的前一个结点(在左子树内)\n
 * &emsp;&emsp; prev_node的数据赋给子树根结点\n
 * &emsp;&emsp; 子树根结点左孩子, 递归执行RemovalInSubTreeRecursive_\n
 * &emsp;&emsp; **if** 递归失败 :\n
 * &emsp;&emsp;&emsp; 返回false\n\n
 * + **3 平衡**\n
 * 调整子树根结点高度\n
 * 调整子树根结点平衡因子\n
 * 对子树根结点执行Balance_, 进行平衡\n\n
 * + **4 退出函数**\n
 * 返回true\n
 */
template<typename TKey, typename TValue>
bool AvlTree<TKey, TValue>::RemoveInSubTreeRecursive_(AvlNode<TKey, TValue>*& subtree_root, TKey key) {

    // ---------- 1 空子树处理 ----------

    if (!subtree_root) {                                                                        // if 空子树
        return false;                                                                           // 返回false
    }

    // ---------- 2 执行递归 ----------

    if (key < subtree_root->Key()) {                                                            // if 待删除key < 子树根结点key
        bool res = RemoveInSubTreeRecursive_(subtree_root->LeftChild(), key);                   // 子树根结点左孩子, 递归执行RemovalInSubTreeRecursive_
        if (!res) {                                                                             // if 递归失败
            return false;                                                                       // 返回false
        }
    } else if (key > subtree_root->Key()) {                                                     // else if 待删除key > 子树根结点key
        bool res = RemoveInSubTreeRecursive_(subtree_root->RightChild(), key);                  // 子树根结点右孩子, 递归执行RemovalInSubTreeRecursive_
        if (!res) {                                                                             // if 递归失败
            return res;                                                                         // 返回false
        }
    } else {                                                                                    // else (待删除key 等于 子树根结点key)
        if (!subtree_root->LeftChild() && !subtree_root->RightChild()) {                        // if 子树为叶子(根结点没有左右孩子)
            delete subtree_root;                                                                // 释放子树根结点
            subtree_root = NULL;

            return true;                                                                        // 返回true
        } else if (!subtree_root->LeftChild()) {                                                // else if 子树左孩子为NULL
            AvlNode<TKey, TValue>* temp = subtree_root;
            subtree_root = subtree_root->RightChild();                                          // 根结点指向右孩子

            delete temp;                                                                        // 原根结点释放
        } else if (!subtree_root->RightChild()) {                                               // else if 子树右孩子为NULL
            AvlNode<TKey, TValue>* temp = subtree_root;
            subtree_root = subtree_root->LeftChild();                                           // 根结点指向左孩子

            delete temp;                                                                        // 原根结点释放
        } else {                                                                                // else (根结点同时存在左右孩子)
            AvlNode<TKey, TValue>* prev_node = this->PreviousNode_(subtree_root);               // prev_node指向根结点中序的前一个结点(在左子树内)

            subtree_root->SetKey(prev_node->Key());                                             // prev_node的数据赋给子树根结点
            subtree_root->SetValue(prev_node->Value());

            bool res = RemoveInSubTreeRecursive_(subtree_root->LeftChild(), prev_node->Key());  // 子树根结点左孩子, 递归执行RemovalInSubTreeRecursive_
            if (!res) {                                                                         // if 递归失败
                return res;                                                                     // 返回false
            }
        }
    }

    // ---------- 3 平衡 ----------

    subtree_root->UpdateHeight();                                                               // 调整子树根结点高度
    subtree_root->UpdateBalanceFactor();                                                        // 调整子树根结点平衡因子

    Balance_(subtree_root);                                                                     // 对子树根结点执行Balance_, 进行平衡

    // ---------- 4 退出函数 ----------

    return true;                                                                                // 返回true
}


/*!
 * @brief **定位删除结点并初始化回溯栈**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 * @param key 关键字
 * @param subtree_root 子树根结点
 * @param backtrack_stack 回溯栈
 * @return 指向待删除结点的指针
 * @note
 * 定位删除结点并初始化回溯栈
 * ----------------------
 * ----------------------
 *
 * ----------------------
 * 初始化遍历指针cur, 指向子树根结点\n
 * **while loop** cur不为NULL :\n
 * &emsp; **if** 待删除key等于当前结点key_ :\n
 * &emsp;&emsp; 跳出循环(找到待删除结点)\n
 * &emsp; cur入回溯栈backtrack_stack\n
 * &emsp; **if** 待删除key < 当前结点key_ :\n
 * &emsp;&emsp; cur指向自身左孩子\n
 * &emsp; **else** (待删除key > 当前结点key_) :\n
 * &emsp;&emsp; cur指向自身右孩子\n
 * 返回cur\n
 */
template<typename TKey, typename TValue>
AvlNode<TKey, TValue>* AvlTree<TKey, TValue>::FindRemoveNodeAndInitStack_(AvlNode<TKey, TValue>* subtree_root,
                                                                          TKey key,
                                                                          stack<AvlNode<TKey, TValue>*>& backtrack_stack)
{

    AvlNode<TKey, TValue>* cur = subtree_root;      // 初始化遍历指针cur, 指向子树根结点

    while (cur != NULL) {                           // while loop cur不为NULL

        if (key == cur->Key()) {                    // if 待删除key等于当前结点key_
            break;                                  // 跳出循环(找到待删除结点)
        }

        backtrack_stack.push(cur);                  // cur入回溯栈backtrack_stack

        if (key < cur->Key()) {                     // if 待删除key < 当前结点key_
            cur = cur->LeftChild();                 // cur指向自身左孩子
        } else {                                    // else (待删除key > 当前结点key_)
            cur = cur->RightChild();                // cur指向自身右孩子
        }
    }

    return cur;                                     // 返回cur
}


/*!
 * @brief **检查插入合法性并初始化回溯栈**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 * @param key 关键字
 * @param subtree_root 子树根结点
 * @param backtrack_stack 回溯栈
 * @return 执行结果
 * @note
 * 检查插入合法性并初始化回溯栈
 * ------------------------
 * ------------------------
 *
 * ------------------------
 * 初始化遍历指针cur, 指向子树根结点\n
 * **while loop** cur不为NULL :\n
 * &emsp; **if** 待删除key等于当前结点key_ :\n
 * &emsp;&emsp; 返回false(重复插入)\n
 * &emsp; cur入回溯栈backtrack_stack\n
 * &emsp; **if** 待删除key < 当前结点key_ :\n
 * &emsp;&emsp; cur指向自身左孩子\n
 * &emsp; **else** (待删除key > 当前结点key_) :\n
 * &emsp;&emsp; cur指向自身右孩子\n
 * 返回true\n
 */
template<typename TKey, typename TValue>
bool AvlTree<TKey, TValue>::CheckInsertLegalAndInitStack_(TKey key,
                                                          AvlNode<TKey, TValue>* subtree_root,
                                                          stack<AvlNode<TKey, TValue>*>& backtrack_stack)
{
    AvlNode<TKey, TValue>* cur = subtree_root;  // 初始化遍历指针cur, 指向子树根结点

    while (cur != NULL) {                       // while loop cur不为NULL
        if (key == cur->Key()) {                // if 待删除key等于当前结点key_
            return false;                       // 返回false(重复插入)
        }

        backtrack_stack.push(cur);              // cur入回溯栈backtrack_stack

        if (key < cur->Key()) {                 // if 待删除key < 当前结点key_
            cur = cur->LeftChild();             // cur指向自身左孩子
        } else {                                // else (待删除key > 当前结点key_)
            cur = cur->RightChild();            // cur指向自身右孩子
        }
    }

    return true;                                // 返回true
}


/**
 * @brief **子树搜索(递归)**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 * @param key 关键字
 * @param subtree_root 子树根结点
 * @return 结点指针
 * @note
 * 子树搜索(递归)
 * -------------
 * -------------
 *
 * -------------
 * + **1 空树处理**\n
 * **if** 子树根结点为NULL :\n
 * &emsp; 返回NULL\n
 * + **2 分治递归**\n
 * **if** 被查找key < 子树结点key :\n
 * &emsp; 调用SearchInSubTree左孩子结点进行递归\n
 * **if** 被查找key > 子树结点key :\n
 * &emsp; 调用SearchInSubTree左孩子结点进行递归\n
 * + **3 返回根结点**\n
 */
template <typename TKey, typename TValue>
AvlNode<TKey, TValue>* AvlTree<TKey, TValue>::SearchInSubTree_(AvlNode<TKey, TValue>* subtree_root, TKey key) {

    // ---------- 1 空树处理 ----------

    if (subtree_root == NULL) {                                     // if 子树根结点为NULL
        return NULL;                                                // 返回NULL
    }

    // ---------- 2 分治递归 ----------

    if (key < subtree_root->Key()) {                                // if 被查找key < 子树结点key
        return SearchInSubTree_(subtree_root->LeftChild(), key);    // 调用SearchInSubTree左孩子结点进行递归
    } else if (key > subtree_root->Key()) {                         // if 被查找key > 子树结点key
        return SearchInSubTree_(subtree_root->RightChild(), key);   // 调用SearchInSubTree左孩子结点进行递归
    }

    // ---------- 3 返回根结点 ----------

    return subtree_root;
}


/**
 * @brief **子树删除结点**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 * @param subtree_root 子树根结点
 * @param key 待删除关键字
 * @return 执行结果
 * @note
 * 子树删除节点
 * ----------
 * ----------
 *
 * ----------
 * + **1 找到待删除结点并初始化回溯栈**\n
 * 声明backtrack_stack(回溯栈)\n
 * 调用FindRemoveNodeAndInitStack_取得remove_node(待删除结点指针), 并将remove_node的所有祖先结点进入回溯栈\n
 * **if** remove_node为NULL(未找到待删除结点) :\n
 * &emsp; 返回false\n
 * + **2 替换待删除结点并将沿途结点入栈**\n
 * **if** 待删除结点同时存在左右孩子 :\n
 * &emsp; 待删除结点入栈\n
 * &emsp; 初始化遍历指针cur, 指向待删除结点左孩子\n
 * &emsp; **while loop** cur指向的结点存在右孩子 :\n
 * &emsp;&emsp; cur指向的结点入栈\n
 * &emsp;&emsp; cur指向自身右孩子\n
 * &emsp;&emsp; (此时cur指向了替换结点)\n
 * &emsp;&emsp; 将cur指向结点的key_和value_赋给待删除结点\n
 * &emsp;&emsp; remove_node指向cur\n
 * **else if** 待删除结点存在左孩子, 不存在右孩子 :\n
 * &emsp; 待删除结点入栈\n
 * &emsp; 声明并初始化replace_node(替换结点), 指向左孩子\n
 * &emsp; 将replace_node指向结点的key_和value_赋给待删除结点\n
 * &emsp; remove_node指向replace_node\n
 * **else if** 待删除结点不存在左孩子, 存在右孩子 :\n
 * &emsp; 待删除结点入栈\n
 * &emsp; 声明并初始化replace_node(替换结点), 指向右孩子\n
 * &emsp; 将replace_node指向结点的key_和value_赋给待删除结点\n
 * &emsp; remove_node指向replace_node\n
 * **else** (叶子结点) :\n
 * &emsp; (不做任何操作)\n
 * + **3 子树为叶子情况的处理**\n
 * **if** 回溯栈为空栈(子树只有一个结点, 删除该唯一结点) :\n
 * &emsp; subtree_root为NULL\n
 * &emsp; 释放remove_node\n
 * &emsp; 返回true\n
 * + **4 删除替换后的remove_node**\n
 * 声明并初始化指针remove_node_parent, 指向remove_node的父节点(回溯栈栈顶)\n
 * **if** 待删除结点是remove_node_parent的左孩子 :\n
 * &emsp; **if** 待删除结点存在右孩子 :\n
 * &emsp;&emsp; remove_node_parent的左孩子结点, 设为remove_node的右孩子\n
 * &emsp; **else** (待删除结点不存在右孩子) :\n
 * &emsp;&emsp; remove_node_parent的左孩子结点, 设为remove_node的左孩子\n
 * **else if** 待删除结点是remove_node_parent的右孩子 :\n
 * &emsp; **if** 待删除结点存在右孩子 :\n
 * &emsp;&emsp; remove_node_parent的右孩子结点, 设为remove_node的右孩子\n
 * &emsp; **else** (待删除结点不存在右孩子) :\n
 * &emsp;&emsp; remove_node_parent的右孩子结点, 设为remove_node的左孩子\n
 * 释放remove_node\n
 * + **5 平衡**\n
 * 调用RemovalBalanceByStack_, 对backtrack_stack(回溯栈)中的各结点进行平衡, 返回balance_node(最终的平衡点)\n
 * **if** 回溯栈空栈(balance_node没有祖先结点) :\n
 * &emsp; 将balance_node设置为子树根结点\n
 * **else** (balance_node存在祖先结点) :\n
 * &emsp; 回溯栈栈顶元素出栈, 赋给balance_node_parent(平衡结点的父结点)\n
 * &emsp; **if** balance_node_parent的Key() > balance_node的Key() :\n
 * &emsp;&emsp; 将balance_node设为balance_node_parent的左孩子\n
 * &emsp; **else** (balance_node_parent的Key() < balance_node的Key()) :\n
 * &emsp;&emsp; 将balance_node设为balance_node_parent的右孩子\n
 * + **6 退出函数**\n
 * 返回true\n
 */
template<typename TKey, typename TValue>
bool AvlTree<TKey, TValue>::RemoveInSubTree_(AvlNode<TKey, TValue>*& subtree_root, TKey key) {

    // ---------- 1 找到待删除结点并初始化回溯栈 ----------

    stack<AvlNode<TKey, TValue>*> backtrack_stack;                                      // 声明backtrack_stack(回溯栈)

    // 调用FindRemoveNodeAndInitStack_取得remove_node(待删除结点指针), 并将remove_node的所有祖先结点进入回溯栈
    AvlNode<TKey, TValue>* remove_node = FindRemoveNodeAndInitStack_(subtree_root, key, backtrack_stack);
    if (remove_node == NULL) {                                                          // if remove_node为NULL(未找到待删除结点)
        return false;                                                                   // 返回false
    }

    // ---------- 2 替换待删除结点并将沿途结点入栈 ----------

    if (remove_node->LeftChild() != NULL && remove_node->RightChild() != NULL ) {       // if 待删除结点同时存在左右孩子
        backtrack_stack.push(remove_node);                                              // 待删除结点入栈

        AvlNode<TKey, TValue>* cur = remove_node->LeftChild();                          // 初始化遍历指针cur, 指向待删除结点左孩子
        while (cur->RightChild() != NULL) {                                             // while loop cur指向的结点存在右孩子
            backtrack_stack.push(cur);                                                  // cur指向的结点入栈
            cur = cur->RightChild();                                                    // cur指向自身右孩子
        }

        remove_node->SetKey(cur->Key());                                                // (此时cur指向了替换结点)
        remove_node->SetValue(cur->Value());                                            // 将cur指向结点的key_和value_赋给待删除结点

        remove_node = cur;                                                              // remove_node指向cur

    } else if (remove_node->LeftChild() != NULL && remove_node->RightChild() == NULL) { // else if 待删除结点存在左孩子, 不存在右孩子
        backtrack_stack.push(remove_node);                                              // 待删除结点入栈

        AvlNode<TKey, TValue>* replace_node = remove_node->LeftChild();                 // 声明并初始化replace_node(替换结点), 指向左孩子

        remove_node->SetKey(replace_node->Key());                                       // 将replace_node指向结点的key_和value_赋给待删除结点
        remove_node->SetValue(replace_node->Value());

        remove_node = replace_node;                                                     // remove_node指向replace_node
    } else if (remove_node->LeftChild() == NULL && remove_node->RightChild() != NULL) { // else if 待删除结点不存在左孩子, 存在右孩子
        backtrack_stack.push(remove_node);                                              // 待删除结点入栈

        AvlNode<TKey, TValue>* replace_node = remove_node->RightChild();                // 声明并初始化replace_node(替换结点), 指向右孩子

        remove_node->SetKey(replace_node->Key());                                       // 将replace_node指向结点的key_和value_赋给待删除结点
        remove_node->SetValue(replace_node->Value());

        remove_node = replace_node;                                                     // remove_node指向replace_node
    } else {                                                                            // else (叶子结点)
        // (不做任何操作)
    }

    // ---------- 3 子树为叶子情况的处理 ----------

    if (backtrack_stack.empty()) {                                                      // if 回溯栈为空栈(子树只有一个结点, 删除该唯一结点)
        subtree_root = NULL;                                                            // subtree_root为NULL

        delete remove_node;                                                             // 释放remove_node
        remove_node = NULL;

        return true;                                                                    // 返回true
    }

    // ---------- 4 删除替换后的remove_node ----------

    AvlNode<TKey, TValue>* remove_node_parent = backtrack_stack.top();                  // 声明并初始化指针remove_node_parent, 指向remove_node的父节点(回溯栈栈顶)

    if (remove_node_parent->LeftChild() == remove_node) {                               // if 待删除结点是remove_node_parent的左孩子
        if (remove_node->RightChild() != NULL) {                                        // if 待删除结点存在右孩子
            remove_node_parent->SetLeftChild(remove_node->RightChild());                // remove_node_parent的左孩子结点, 设为remove_node的右孩子
        } else {                                                                        // else (待删除结点不存在右孩子)
            remove_node_parent->SetLeftChild(remove_node->LeftChild());                 // remove_node_parent的左孩子结点, 设为remove_node的左孩子
        }
    } else if (remove_node_parent->RightChild() == remove_node) {                       // else if 待删除结点是remove_node_parent的右孩子
        if (remove_node->RightChild() != NULL) {                                        // if 待删除结点存在右孩子
            remove_node_parent->SetRightChild(remove_node->RightChild());               // remove_node_parent的右孩子结点, 设为remove_node的右孩子
        } else {                                                                        // else (待删除结点不存在右孩子)
            remove_node_parent->SetRightChild(remove_node->LeftChild());                // remove_node_parent的右孩子结点, 设为remove_node的左孩子
        }
    }

    delete remove_node;                                                                 // 释放remove_node
    remove_node = NULL;

    // ---------- 5 平衡 ----------

    AvlNode<TKey, TValue>* balance_node = RemovalBalanceByStack_(backtrack_stack);      // 对backtrack_stack(回溯栈)中的各结点进行平衡, 返回balance_node(最终的平衡点)

    if (backtrack_stack.empty() == true) {                                              // if 回溯栈空栈(balance_node没有祖先结点)
        subtree_root = balance_node;                                                    // 将balance_node设置为子树根结点
    } else {                                                                            // else (balance_node存在祖先结点)
        AvlNode<TKey, TValue>* balance_node_parent = backtrack_stack.top();             // 回溯栈栈顶元素出栈, 赋给balance_node_parent(平衡结点的父结点)
        if (balance_node_parent->Key() > balance_node->Key()) {                         // if balance_node_parent的Key() > balance_node的Key()
            balance_node_parent->SetLeftChild(balance_node);                            // 将balance_node设为balance_node_parent的左孩子
        } else {                                                                        // else (balance_node_parent的Key() < balance_node的Key())
            balance_node_parent->SetRightChild(balance_node);                           // 将balance_node设为balance_node_parent的右孩子
        }
    }

    // ---------- 6 退出函数 ----------

    return true;                                                                        // 返回true
}


/**
 * @brief **子树打印(递归)**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值字类型模板参数
 * @param subtree_root 子树根结点
 * @param Print 结点打印函数
 * @note
 * 子树打印(递归)
 * ------------
 * ------------
 *
 * ------------
 * + **1 空树处理**\n
 * **if** 子树根结点为NULL :\n
 * &emsp; 退出函数\n\n
 * + **2 分治递归**\n
 * 访问结点\n\n
 * **if** 子树为叶子类型(没有左右孩子): \n
 * &emsp; 退出函数\n\n
 * 打印'('\n
 * 递归调用PrintSubTreeRecursive_, 对左子树进行打印\n
 * 打印','\n
 * 递归调用PrintSubTreeRecursive_, 对右子树进行打印\n
 * 打印')'\n
 */
template <typename TKey, typename TValue>
void AvlTree<TKey, TValue>::PrintSubTreeRecursive_(AvlNode<TKey, TValue>* subtree_root,
                                                   void (*Print)(AvlNode<TKey, TValue>*))
{
    // ---------- 1 空树处理 ----------

    if (subtree_root == NULL) {                                                     // if 子树根结点为NULL
        return;                                                                     // 返回
    }

    // ---------- 2 分治递归 ----------

    Print(subtree_root);                                                            // 访问结点

    if (subtree_root->LeftChild() == NULL && subtree_root->RightChild() == NULL) {  // if 子树为叶子类型(没有左右孩子)
        return;                                                                     // 返回
    }

    cout << "(";                                                                    // 打印'('

    PrintSubTreeRecursive_(subtree_root->LeftChild(), Print);                       // 递归, 对左子树进行打印

    cout << ",";                                                                    // 打印','

    PrintSubTreeRecursive_(subtree_root->RightChild(), Print);                      // 递归, 对右子树进行打印

    cout << ")";                                                                    // 打印')'
}


/*!
 * @brief **打印**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 * @param visit 访问函数
 * @note
 * 打印
 * ---
 * ---
 *
 * ---
 * 对root_(根结点)调用PrintSubTreeRecursive_
 */
template<typename TKey, typename TValue>
void AvlTree<TKey, TValue>::Print(void (*visit)(AvlNode<TKey, TValue>*)) {
    this->PrintSubTreeRecursive_(this->root_, visit);
    cout << endl;
}


/*!
 * @brief **删除结点**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 * @param key 关键字
 * @return 执行结果
 * @note
 * 删除结点
 * ------
 * ------
 *
 * ------
 * 对根结点调用RemoveInSubTree_, 返回结果
 */
template<typename TKey, typename TValue>
bool AvlTree<TKey, TValue>::Remove(TKey key) {
    return this->RemoveInSubTree_(this->Root(), key);
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
bool AvlTree<TKey, TValue>::Min(TValue& min_value) {
    AvlNode<TKey, TValue>* node = this->MinInSubTree_(this->Root());            // 对根结点调用MinInSubTree_, 获取key最小的结点
    if (!node) {                                                                // if node为NULL
        return false;                                                           // 返回false
    }

    min_value = node->Value();                                                  // node的value_赋给min_value

    return true;                                                                // 返回true
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
AvlNode<TKey, TValue>* AvlTree<TKey, TValue>::MinInSubTree_(AvlNode<TKey, TValue>* subtree_root) const {

    // ---------- 1 空子树处理 ----------

    if (subtree_root == NULL) {                                             // if 子树根结点为NULL
        return NULL;                                                        // 返回NULL
    }

    // ---------- 2 向左遍历 ----------

    AvlNode<TKey, TValue>* cur = subtree_root;                              // 声明并初始化cur指向子树根结点

    while (cur && cur->LeftChild() != NULL) {                               // while loop cur不为NULL && cur的左孩子不为NULL
        cur = cur->LeftChild();                                             // cur指向自身左孩子
    }

    // ---------- 3 返回结果 ----------

    return cur;                                                             // 返回cur
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
bool AvlTree<TKey, TValue>::Max(TValue& max_value) {
    AvlNode<TKey, TValue>* node = this->MaxInSubTree_(this->Root());    // 对根结点调用MaxInSubTree_, 获取key最大的结点
    if (!node) {                                                        // if node为NULL
        return false;                                                   // 返回false
    }

    max_value = node->Value();                                          // node的value_赋给max_value

    return true;                                                        // 返回true
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
AvlNode<TKey, TValue>* AvlTree<TKey, TValue>::MaxInSubTree_(AvlNode<TKey, TValue>* subtree_root) const {

    // ---------- 1 空子树处理 ----------

    if (subtree_root == NULL) {                     // if 子树根结点为NULL
        return NULL;                                // 返回NULL
    }

    // ---------- 2 向右遍历 ----------

    AvlNode<TKey, TValue>* cur = subtree_root;      // 声明并初始化cur指向子树根结点
    while (cur && cur->RightChild() != NULL) {      // while loop cur不为NULL && cur的右孩子不为NULL
        cur = cur->RightChild();                    // cur指向自身右孩子
    }

    // ---------- 3 返回结果 ----------

    return cur;                                     // 返回cur
}


/*!
 * @brief **获取结点的(中序)前一结点**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 * @param node 结点
 * @return 前一结点指针
 * @note
 * 获取结点的(中序)前一结点
 * ---------------------
 * ---------------------
 *
 *
 *
 * ---------------------
 * + **1 合法性判断**\n
 * &emsp; **if** node为NULL :\n
 * &emsp;&emsp; 返回NULL\n\n
 * + **2 查找结点**\n
 * &emsp; 初始化遍历指针cur, 指向结点的左孩子\n\n
 * &emsp; **while loop** cur不为NULL <b>&&</b> cur存在右孩子 :\n
 * &emsp;&emsp; cur指向右孩子\n\n
 * &emsp; 返回cur\n
 */
template<typename TKey, typename TValue>
AvlNode<TKey, TValue>* AvlTree<TKey, TValue>::PreviousNode_(AvlNode<TKey, TValue>* node) {

    // ---------- 1 合法性判断 ----------

    if (!node) {                                            // if node为NULL
        return NULL;                                        // 返回NULL
    }

    // ---------- 2 查找结点 ----------

    AvlNode<TKey, TValue>* cur = node->LeftChild();         // 初始化遍历指针cur, 指向结点的左孩子
    while (cur && cur->RightChild()) {                      // while loop cur不为NULL && cur存在右孩子 :
        cur = cur->RightChild();                            // cur指向右孩子
    }

    return cur;                                             // 返回cur
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
int AvlTree<TKey, TValue>::HeightOfSubtreeRecursive_(AvlNode<TKey, TValue>* subtree_root) {

    // ---------- 1 空树处理 ----------

    if (!subtree_root) {                                                                // if 空子树
        return 0;                                                                       // 返回0
    }

    // ---------- 2 分治递归 ----------

    int left_subtree_height = HeightOfSubtreeRecursive_(subtree_root->LeftChild());     // 取left_subtree_height(左子树高度)
    int right_subtree_height = HeightOfSubtreeRecursive_(subtree_root->RightChild());   // 取right_subtree_height(右子树高度)

    if (left_subtree_height < right_subtree_height) {                                   // if 左子树高度 < 右子树高度
        return right_subtree_height + 1;                                                // 返回 右子树高度 + 1
    } else {                                                                            // else (左子树高度 >= 右子树高度)
        return left_subtree_height + 1;                                                 // 返回 左子树高度 + 1
    }
}


#endif // CYBER_DASH_AVL_TREE_H
