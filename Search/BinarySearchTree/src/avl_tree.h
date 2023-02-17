//
// Created by cyberdash@163.com on 2021/7/5.
//

#ifndef CYBER_DASH_AVL_TREE_H
#define CYBER_DASH_AVL_TREE_H


#include <stack>
#include "binary_search_tree.h"


/*!
 * @brief **AVL树结点模板类**
 * @tparam TKey 关键码类型模板参数
 * @tparam TValue 数据项类型模板参数
 */
template<typename TKey, typename TValue>
class AvlNode: public BinarySearchTreeNode<TKey, TValue> {
public:

    /*!
     * @brief **构造函数(默认)**
     * @note
     * 构造函数(默认)
     * ------------
     * ------------
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
     * 设置key_/value_, 左右孩子为NULL, 高度设为1, 平衡因子设为0
     */
    AvlNode(const TKey& key, const TValue& value) :
        value_(value), key_(key), left_child_(NULL), right_child_(NULL), height_(1), balance_factor_(BALANCED) {}

    /*!
     * @brief **构造函数(有左右孩子)**
     * @param key 关键码
     * @param value 数据项
     * @param left_child 左孩子
     * @param right_child 右孩子
     * @note
     * 构造函数(有左右孩子)
     * ------------
     * ------------
     * 设置key/value/左右孩子, 高度设为1, 平衡因子设为0
     */
    AvlNode(TKey key, TValue value, AvlNode<TKey, TValue>* left_child, AvlNode<TKey, TValue>* right_child) :
        value_(value), key_(key), left_child_(left_child), right_child_(right_child),
        height_(1), balance_factor_(BALANCED) {}

    /*!
     * @brief **获取左孩子结点**
     * @return 左孩子结点
     */
    AvlNode<TKey, TValue>*& LeftChild() { return this->left_child_; };
    /*!
     * @brief **设置左孩子结点**
     * @param node avl树结点
     */
    void SetLeftChild(AvlNode<TKey, TValue>* node) { this->left_child_ = node; }

    /*!
     * @brief **获取右孩子结点**
     * @return 右孩子结点
     */
    AvlNode<TKey, TValue>*& RightChild() { return this->right_child_; };
    /*!
     * @brief **设置右孩子结点**
     * @param node avl树结点
     */
    void SetRightChild(AvlNode<TKey, TValue>* node) { this->right_child_ = node; }

    TKey Key() { return this->key_; }
    void SetKey(const TKey& key) { this->key_ = key; }

    TValue Value() { return this->value_; }
    void SetValue(const TValue& value) { this->value_ = value; }

    int Height() { return this->height_; }
    void SetHeight(int height) { this->height_ = height; }

    int BalanceFactor() { return this->balance_factor_; }
    void SetBalanceFactor(int balance_factor) { this->balance_factor_ = balance_factor; }

    /*!
     * @brief **更新高度**
     * @note
     * 作为子树根节点时具有意义
     */
    void UpdateHeight() {
        int left_height = LeftChild() ? LeftChild()->Height() : 0;
        int right_height = RightChild() ? RightChild()->Height() : 0;
        this->height_ = (left_height > right_height ? left_height : right_height) + 1;
    }
    /*!
     * @brief **更新平衡因子**
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


template<typename TKey, typename TValue>
class AvlTree : public BinarySearchTree<TKey, TValue> {
public:
    AvlTree() : root_(NULL) {}
    AvlNode<TKey, TValue>*& Root() { return this->root_; }
    void SetRoot(AvlNode<TKey, TValue>* node) { this->root_ = node; }

    bool Insert(TKey key, TValue value);
    bool InsertRecursive(TKey key, TValue value);

    bool Remove(TKey key);
    bool RemoveRecursive(TKey key);

    int Height() { return this->root_->Height(); }
    int HeightRecursive() { return this->HeightOfSubtreeRecursive_(this->root_); }

    bool Max(TValue& value);
    bool Min(TValue& min_value);

    AvlNode<TKey, TValue>* Search(TKey key) { return this->SearchInSubTree_(this->root_, key); }

    void Print(void (*visit)(AvlNode<TKey, TValue>*));

protected:
    // 子树插入结点(递归)
    bool InsertInSubTreeRecursive_(AvlNode<TKey, TValue>*& subtree_root, TKey key, TValue value);
    // 子树插入结点
    bool InsertInSubTree_(AvlNode<TKey, TValue>*& subtree_root, TKey key, TValue value);   // 平衡树子树插入

    bool RemoveInSubTree_(AvlNode<TKey, TValue>*& subtree_root, TKey key);                // 平衡树子树删除
    bool DeletionInSubTreeRecursive_(AvlNode<TKey, TValue>*& subtree_root, TKey key);

    AvlNode<TKey, TValue>* InsertionBalanceByStack_(stack<AvlNode<TKey, TValue>*>& backtrack_stack);
    AvlNode<TKey, TValue>* DeletionBalanceByStack_(stack<AvlNode<TKey, TValue>*>& backtrack_stack);
    void Balance_(AvlNode<TKey, TValue>*& node);

    // 左单旋转(Rotation Left)
    int LeftRotate_(AvlNode<TKey, TValue>*& node);
    // 右单旋转(Rotation Right)
    int RightRotate_(AvlNode<TKey, TValue>*& node);
    // 先左后右双旋转(Rotation Left Right)
    int LeftRightRotate_(AvlNode<TKey, TValue>*& node);
    // 先右后左双旋转(Rotation Right Left)
    int RightLeftRotate_(AvlNode<TKey, TValue>*& node);

    AvlNode<TKey, TValue>* SearchInSubTree_(AvlNode<TKey, TValue>* subtree_root, TKey key);

    // 子树中关键码最小项
    AvlNode<TKey, TValue>* MinInSubTree_(AvlNode<TKey, TValue>* subtree_root) const;
    // 子树中关键码最大项
    AvlNode<TKey, TValue>* MaxInSubTree_(AvlNode<TKey, TValue>* subtree_root) const;

    // 获取结点的(中序)前一结点
    AvlNode<TKey, TValue>* PreviousNode_(AvlNode<TKey, TValue>* node);

    // AVL子树的高度
    int HeightOfSubtreeRecursive_(AvlNode<TKey, TValue>* subtree_root);

    void PrintSubTreeRecursive_(AvlNode<TKey, TValue>* subtree_root, void (*Print)(AvlNode<TKey, TValue>*));

    bool CheckInsertLegalAndInitStack_(
            TKey key,
            AvlNode<TKey, TValue>* subtree_root,
            stack<AvlNode<TKey, TValue>*>& backtrack_stack);

    AvlNode<TKey, TValue>* FindDeleteNodeAndInitStack_(
            TKey key,
            AvlNode<TKey, TValue>* subtree_root,
            stack<AvlNode<TKey, TValue>*>& backtrack_stack);

    AvlNode<TKey, TValue>* root_; //!< 根结点
};


/*!
 * @brief **左单旋转(Left Rotation)**
 * @tparam TValue 搜索结果(数据)模板类型
 * @tparam TKey 关键码模板类型
 * @param node AVL树节点指针的引用
 * @return 平衡因子
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

    return node->BalanceFactor();
}


/**
 * 右单旋转(Rotation Right), 图7.16(a)的情形
 * @tparam TValue 搜索结果(数据)模板类型
 * @tparam TKey 关键码模板类型
 * @param node 旋转前的子树根节点
 * @note
 * ```
 *          Sub_Tree_Root      pivot
 *               /              / \
 *              /              /   \
 *          pivot          node2  Sub_Tree_Root
 *            / \                  /
 *           /   \                /
 *       node2  node3          node3
 *
 *          Sub_Tree_Root      pivot
 *               /              / \
 *              /              /   \
 *          pivot          node2  Sub_Tree_Root
 *            /
 *           /
 *       node2
 * ```
 */
template<class TKey, class TValue>
int AvlTree<TKey, TValue>::RightRotate_(AvlNode<TKey, TValue>*& node) {

    //! pivot指向调整后的(子树根)结点
    AvlNode<TKey, TValue>* pivot = node->LeftChild();

    //! node以pivot为轴, 执行右旋
    node->SetLeftChild(pivot->RightChild());
    pivot->SetRightChild(node);

    // 更新height
    node->UpdateHeight();
    pivot->UpdateHeight();

    // 更新平衡因子
    node->UpdateBalanceFactor();
    pivot->UpdateBalanceFactor();

    // --- 子树根节点指向pivot指向的结点 ---

    node = pivot;

    return node->BalanceFactor();
}


/*!
 * 左右旋
 * @tparam TValue 数据项模板参数
 * @tparam TKey 键值模板参数
 * @param node 旋转前的子树根结点
 * @note
 * ```
 *          subtree_root                         subtree_root                                   pivot
 *               / \                                   / \                                         / \
 *              /   \                                 /   \                                       /   \
 *             /     \                               /     \                                     /     \
 *            /       \                             /       \                                   /       \
 *           /         \                           /         \                                 /         \
 *  left_rotate_pivot  node2                     pivot       node2                 left_rotate_pivot   subtree_root
 *         / \                                   / \                                         / \         / \
 *        /   \                                 /   \                                       /   \       /   \
 *       /     \                               /     \                                     /     \     /     \
 *    node3  pivot                left_rotate_pivot  node5                              node3  node4 node5  node2
 *            / \                            / \
 *           /   \                          /   \
 *          /     \                        /     \
 *        node4  node5                  node3   node4
 *
 *
 *
 *
 * ```
 */
template<typename TKey, typename TValue>
int AvlTree<TKey, TValue>::LeftRightRotate_(AvlNode<TKey, TValue>*& node) {
    this->LeftRotate_(node->LeftChild());
    this->RightRotate_(node);
    return node->BalanceFactor();
}


/*!
 * @brief **右左旋**
 * @tparam TValue 数据项模板参数
 * @tparam TKey 键值模板参数
 * @param subtree_root 旋转前的子树根结点
 * 右左旋
 * -----
 * -----
 *
 * -----
 */
template<class TKey, class TValue>
int AvlTree<TKey, TValue>::RightLeftRotate_(AvlNode<TKey, TValue>*& node) {
    this->RightRotate_(node->RightChild());
    this->LeftRotate_(node);
    return node->BalanceFactor();
}


template<class TKey, class TValue>
bool AvlTree<TKey, TValue>::Insert(TKey key, TValue value) {
    return this->InsertInSubTree_(this->Root(), key, value);
}


template<class TKey, class TValue>
bool AvlTree<TKey, TValue>::InsertRecursive(TKey key, TValue value) {
    return this->InsertInSubTreeRecursive_(this->Root(), key, value);
}

template<class TKey, class TValue>
bool AvlTree<TKey, TValue>::RemoveRecursive(TKey key) {
    return this->DeletionInSubTreeRecursive_(this->Root(), key);
}


template<class TKey, class TValue>
AvlNode<TKey, TValue>* AvlTree<TKey, TValue>::InsertionBalanceByStack_(stack<AvlNode<TKey, TValue>*>& backtrack_stack) {
    AvlNode<TKey, TValue>* cur_parent_node = NULL;

    while (backtrack_stack.empty() == false) {

        // 获取双亲结点
        cur_parent_node = backtrack_stack.top();
        backtrack_stack.pop();

        cur_parent_node->UpdateBalanceFactor();

        // 第1种情况, 平衡退出
        if (cur_parent_node->BalanceFactor() == AvlNode<TKey, TValue>::BALANCED) {
            break;
        }

        // 第2种情况, |平衡因子| = 1
        if (cur_parent_node->BalanceFactor() == AvlNode<TKey, TValue>::RIGHT_HIGHER_1 ||
            cur_parent_node->BalanceFactor() == AvlNode<TKey, TValue>::LEFT_HIGHER_1) {
            // 不做操作, 继续遍历
        } else { // 第3种情况, |平衡因子| = 2
            this->Balance_(cur_parent_node);

            break; // cur_parent_node调整后height没有变化, 因此无需再向上遍历执行操作
        }

        cur_parent_node->UpdateHeight();
    }

    return cur_parent_node;
}


template<class TKey, class TValue>
AvlNode<TKey, TValue>* AvlTree<TKey, TValue>::DeletionBalanceByStack_(stack<AvlNode<TKey, TValue>*>& backtrack_stack) {

    AvlNode<TKey, TValue>* cur_parent_node = NULL;

    while (!backtrack_stack.empty()) {

        // 获取双亲结点
        cur_parent_node = backtrack_stack.top();
        backtrack_stack.pop();

        int grand_parent_direction;
        if (!backtrack_stack.empty()) {
            AvlNode<TKey, TValue>* cur_grand_node = backtrack_stack.top();
            if (cur_grand_node->LeftChild() == cur_parent_node) {
                grand_parent_direction = -1; // 左
            } else if (cur_grand_node->RightChild() == cur_parent_node) {
                grand_parent_direction = 1;  // 右
            }
        }

        cur_parent_node->UpdateHeight();
        cur_parent_node->UpdateBalanceFactor();

        this->Balance_(cur_parent_node);

        if (!backtrack_stack.empty()) {
            AvlNode<TKey, TValue>* cur_grand_parent_node = backtrack_stack.top();  // grand结点需要更新孩子结点
            if (grand_parent_direction == -1) {
                cur_grand_parent_node->SetLeftChild(cur_parent_node);
            } else {
                cur_grand_parent_node->SetRightChild(cur_parent_node);
            }
        }
    }

    return cur_parent_node;
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
    if (node->BalanceFactor() == AvlNode<TKey, TValue>::RIGHT_HIGHER_2) {       // if 右子树高度 > 左子树高度 2个结点
        // if 右子树侧, (左子树高度 == 右子树高度) or (左子树高度 < 右子树高度 1个结点)
        if (node->RightChild()->BalanceFactor() != AvlNode<TKey, TValue>::LEFT_HIGHER_1) {
            this->LeftRotate_(node);        // 执行LeftRotate_(左单旋转)
        } else {                            // else (右子树侧, 左子树高度 > 右子树高度 1个结点)
            this->RightLeftRotate_(node);   // 执行RightLeftRotate_(右左旋转)
        }
    } else if (node->BalanceFactor() == AvlNode<TKey, TValue>::LEFT_HIGHER_2) { // else if 左子树高度 > 右子树高度 2个结点
        // if 左子树侧, (左子树高度 == 右子树高度) or (左子树高度 > 右子树高度 1个结点)
        if (node->LeftChild()->BalanceFactor() != AvlNode<TKey, TValue>::RIGHT_HIGHER_1) {
            this->RightRotate_(node);       // 执行RightRotate_(右单旋转)
        } else {                            // else (左子树侧, 左子树高度 < 右子树高度 1个结点)
            this->LeftRightRotate_(node);   // 执行LeftRightRotate_(左右旋转)
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
 * &emsp;&emsp; 返回false\n
 * &emsp; 返回true\n
 * + **2 重复插入处理**\n
 * **if** 插入关键字 == 子树根结点关键字 :\n
 * &emsp; 返回false(重复插入)\n
 * + **3 分治递归**\n
 * **if** 插入关键字 < 子树根结点关键字 :\n
 * &emsp; 对子树根结点的左孩子结点执行递归插入\n
 * &emsp; **if** 插入失败 :\n
 * &emsp;&emsp; 返回false\n
 * **else if** 插入关键字 > 子树根结点关键字 :\n
 * &emsp; 对子树根结点的右孩子结点执行递归插入\n
 * &emsp; **if** 插入失败 :\n
 * &emsp;&emsp; 返回false\n
 * + **4 调整平衡**\n
 * 更新子树根结点的高度\n
 * 更新子树根结点的平衡因子\n
 * 对子树根结点进行平衡\n
 * + **5 函数返回**\n
 * 返回true(结束递归)\n
 */
template<typename TKey, typename TValue>
bool AvlTree<TKey, TValue>::InsertInSubTreeRecursive_(AvlNode<TKey, TValue>*& subtree_root, TKey key, TValue value) {
    if (!subtree_root) {
        subtree_root = new AvlNode<TKey, TValue>(key, value);
        if (!subtree_root) {
            throw bad_alloc();
        }

        return true;
    }

    if (key == subtree_root->Key()) {
        return false;
    }

    if (key < subtree_root->Key()) {
        bool res = InsertInSubTreeRecursive_(subtree_root->LeftChild(), key, value);
        if (!res) {
            return res;
        }
    } else if (key > subtree_root->Key()) {
        bool res = InsertInSubTreeRecursive_(subtree_root->RightChild(), key, value);
        if (!res) {
            return res;
        }
    }

    subtree_root->UpdateHeight();
    subtree_root->UpdateBalanceFactor();

    Balance_(subtree_root);

    return true;
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
 * 调用CheckInsertLegalAndInitStack_, 检查是否重复插入, 并将沿途检查的各点入栈\n
 * **if** 重复插入 :\n
 * &emsp; 返回false\n
 * + **2 插入结点**\n
 *  - **2.1 初始化插入结点**\n
 *  初始化new_node(待插入结点)\n
 *  **if** new失败 :\n
 *  &emsp; 抛出bad_alloc()异常\n
 *  - **2.2 空子树插入结点**\n
 *  new_node成为根节点\n
 *  返回true\n
 *  - **2.3 非空子树插入结点**\n
 *  取栈顶, 作为插入结点的父结点(parent_node)\n
 *  **if** 插入结点key < 父结点key :\n
 *  &emsp;&emsp; 插入结点为父结点的左孩子\n
 *  **else** (插入结点key > 父结点key) :\n
 *  &emsp;&emsp; 插入结点为父结点的右孩子\n
 *  调用InsertionBalanceByStack_, 对回溯栈内的结点做平衡, 返回最终的平衡结点balance_node\n
 * + **3 回溯栈处理结束后的补充处理**\n
 * **if** 回溯栈为空 :\n
 * &emsp; balance_node为最新的子树根结点\n
 * **else** (回溯栈不为空) :\n
 * &emsp; 取回溯栈栈顶\n
 * &emsp; **if** 栈顶结点key > 平衡点key :\n
 * &emsp;&emsp; 平衡点为栈顶结点的左孩子\n
 * &emsp; **else** (栈顶结点key < 平衡点key) :\n
 * &emsp;&emsp; 平衡点为栈顶结点的右孩子\n
 * + **4 函数返回**\n
 * 返回true\n
 */
template<typename TKey, typename TValue>
bool AvlTree<TKey, TValue>::InsertInSubTree_(AvlNode<TKey, TValue>*& subtree_root, TKey key, TValue value) {

    stack<AvlNode<TKey, TValue>*> backtrack_stack;

    bool res = CheckInsertLegalAndInitStack_(key, subtree_root, backtrack_stack);
    if (!res) {
        return res;
    }

    AvlNode<TKey, TValue>* new_node = new AvlNode<TKey, TValue>(key, value);
    if (!new_node) {
        throw bad_alloc();
    }

    // 空树, 新结点成为根节点, 并返回
    if (backtrack_stack.empty()) {
        subtree_root = new_node;
        return true;
    }

    AvlNode<TKey, TValue>* parent_node = backtrack_stack.top();

    if (key < parent_node->Key()) {
        parent_node->SetLeftChild(new_node);
    } else {
        parent_node->SetRightChild(new_node);
    }

    AvlNode<TKey, TValue>* balanced_node = this->InsertionBalanceByStack_(backtrack_stack);

    // 已经完成平衡化的树, 完成最后处理
    if (backtrack_stack.empty() == true) {
        subtree_root = balanced_node;
    } else {
        AvlNode<TKey, TValue>* stack_top_node = backtrack_stack.top();
        if (stack_top_node->Key() > balanced_node->Key()) {
            stack_top_node->SetLeftChild(balanced_node);
        } else {
            stack_top_node->SetRightChild(balanced_node);
        }
    }

    return true;
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
 * &emsp; 返回false\n
 * + **2 执行递归**\n
 * **if** 待删除key < 子树根结点key :\n
 * &emsp; 子树根结点左孩子, 递归执行DeletionInSubTreeRecursive_\n
 * &emsp; **if** 递归失败 :\n
 * &emsp;&emsp; 返回false\n
 * **else if** 待删除key > 子树根结点key :\n
 * &emsp; 子树根结点右孩子, 递归执行DeletionInSubTreeRecursive_\n
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
 * &emsp;&emsp; 子树根结点左孩子, 递归执行DeletionInSubTreeRecursive_\n
 * &emsp;&emsp; **if** 递归失败 :\n
 * &emsp;&emsp;&emsp; 返回false\n
 * + **3 平衡**\n
 * 调整子树根结点高度\n
 * 调整子树根结点平衡因子\n
 * 对子树根结点执行Balance_, 进行平衡\n
 * + **4 返回true**\n
 */
template<typename TKey, typename TValue>
bool AvlTree<TKey, TValue>::DeletionInSubTreeRecursive_(AvlNode<TKey, TValue>*& subtree_root, TKey key) {
    if (!subtree_root) {
        return false;
    }

    if (key < subtree_root->Key()) {
        bool res = DeletionInSubTreeRecursive_(subtree_root->LeftChild(), key);
        if (!res) {
            return res;
        }
    } else if (key > subtree_root->Key()) {
        bool res = DeletionInSubTreeRecursive_(subtree_root->RightChild(), key);
        if (!res) {
            return res;
        }
    } else {
        if (!subtree_root->LeftChild() && !subtree_root->RightChild()) {
            delete subtree_root;
            subtree_root = NULL;

            return true;
        } else if (!subtree_root->LeftChild()) {
            AvlNode<TKey, TValue>* temp = subtree_root;
            subtree_root = subtree_root->RightChild();

            delete temp;
        } else if (!subtree_root->RightChild()) {
            AvlNode<TKey, TValue>* temp = subtree_root;
            subtree_root = subtree_root->LeftChild();

            delete temp;
        } else {
            AvlNode<TKey, TValue>* prev_node = this->PreviousNode_(subtree_root);

            subtree_root->SetKey(prev_node->Key());
            subtree_root->SetValue(prev_node->Value());

            bool res = DeletionInSubTreeRecursive_(subtree_root->LeftChild(), prev_node->Key());
            if (!res) {
                return res;
            }
        }
    }

    subtree_root->UpdateHeight();
    subtree_root->UpdateBalanceFactor();

    Balance_(subtree_root);

    return true;
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
 * &emsp; **else if** 待删除key > 当前结点key_ :\n
 * &emsp;&emsp; cur指向自身右孩子\n
 * 返回cur\n
 */
template<typename TKey, typename TValue>
AvlNode<TKey, TValue>* AvlTree<TKey, TValue>::FindDeleteNodeAndInitStack_(TKey key,
                                                                          AvlNode<TKey, TValue>* subtree_root,
                                                                          stack<AvlNode<TKey, TValue>*>& backtrack_stack)
{
    AvlNode<TKey, TValue>* cur = subtree_root;

    while (cur != NULL) {

        if (key == cur->Key()) {
            break;
        }

        backtrack_stack.push(cur);

        if (key < cur->Key()) {
            cur = cur->LeftChild();
        } else {
            cur = cur->RightChild();
        }
    }

    return cur;
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
 * &emsp; **else if** 待删除key > 当前结点key_ :\n
 * &emsp;&emsp; cur指向自身右孩子\n
 * 返回true\n
 */
template<typename TKey, typename TValue>
bool AvlTree<TKey, TValue>::CheckInsertLegalAndInitStack_(TKey key,
                                                          AvlNode<TKey, TValue>* subtree_root,
                                                          stack<AvlNode<TKey, TValue>*>& backtrack_stack)
{
    AvlNode<TKey, TValue>* cur = subtree_root;

    while (cur != NULL) {
        if (key == cur->Key()) {
            return false;
        }

        backtrack_stack.push(cur);

        if (key < cur->Key()) {
            cur = cur->LeftChild();
        } else {
            cur = cur->RightChild();
        }
    }

    return true;
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
 * + **3 返回结果**\n
 */
template <typename TKey, typename TValue>
AvlNode<TKey, TValue>* AvlTree<TKey, TValue>::SearchInSubTree_(AvlNode<TKey, TValue>* subtree_root, TKey key) {
    if (subtree_root == NULL) {
        return NULL;
    }

    if (key < subtree_root->Key()) {
        return SearchInSubTree_(subtree_root->LeftChild(), key);
    } else if (key > subtree_root->Key()) {
        return SearchInSubTree_(subtree_root->RightChild(), key);
    }

    return subtree_root;
}


/**
 * @brief **子树删除节点**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 * @param subtree_root 子树根节点
 * @param key 待删除关键字
 * @return 执行结果
 * @note
 * 子树删除节点
 * ----------
 * ----------
 *
 * ----------
 */
template<typename TKey, typename TValue>
bool AvlTree<TKey, TValue>::RemoveInSubTree_(AvlNode<TKey, TValue>*& subtree_root, TKey key) {

    stack <AvlNode<TKey, TValue>* > backtrack_stack;

    AvlNode<TKey, TValue>* delete_node = FindDeleteNodeAndInitStack_(key, subtree_root, backtrack_stack);
    if (delete_node == NULL) {
        return false; // 未找到删除结点
    }

    // 此时定位到delete_node, delete_node之前的所有祖先结点, 都已经入栈

    AvlNode<TKey, TValue>* delete_node_predecessor = NULL;
    // 结点有两个子女, 在左子树找到delete_node的直接前驱
    if (delete_node->LeftChild() != NULL  && delete_node->RightChild() != NULL ) {
        backtrack_stack.push(delete_node); // 将待删除节点入stack

        delete_node_predecessor = delete_node->LeftChild();
        while (delete_node_predecessor->RightChild() != NULL) {
            backtrack_stack.push(delete_node_predecessor);
            delete_node_predecessor = delete_node_predecessor->RightChild();
        }

        // 将被删除结点的前驱结点的值赋给被删除结点
        delete_node->SetKey(delete_node_predecessor->Key());
        delete_node->SetValue(delete_node_predecessor->Value());

        // 将前驱结点作为待删除结点
        delete_node = delete_node_predecessor;

    } else if (delete_node->LeftChild() != NULL) {  // 结点只有左孩子结点(由于平衡特性, 此时此左孩子必为叶子), 则左孩子结点为删除结点
        delete_node_predecessor = delete_node->LeftChild();

        // 将被删除结点的前驱结点的值赋给被删除结点
        delete_node->SetKey(delete_node_predecessor->Key());
        delete_node->SetValue(delete_node_predecessor->Value());
        backtrack_stack.push(delete_node); // 将待删除节点入stack

        // 将前驱结点作为待删除结点
        delete_node = delete_node_predecessor;
    } else if (delete_node->RightChild() != NULL) {  // 结点只有右孩子结点(由于平衡特性, 此时此右孩子必为叶子), 则右孩子结点为删除结点
        delete_node_predecessor = delete_node->RightChild();

        // 将被删除结点的前驱结点的值赋给被删除结点
        delete_node->SetKey(delete_node_predecessor->Key());
        delete_node->SetValue(delete_node_predecessor->Value());
        backtrack_stack.push(delete_node); // 将待删除节点入stack

        // 将前驱结点作为待删除结点
        delete_node = delete_node_predecessor;
    } else {    // 结点为叶子结点
    }

    if (backtrack_stack.empty()) {   // 删除根结点
        subtree_root = delete_node->RightChild();

        delete delete_node;
        delete_node = NULL;

        return true;
    }

    // 被删除结点的父节点与被删除结点的左孩子相连, 甩掉delete_node
    AvlNode<TKey, TValue>* delete_node_parent = backtrack_stack.top();

    if (delete_node_parent->LeftChild() == delete_node) {             // 左孩子删除
        if (delete_node->RightChild() != NULL) {
            delete_node_parent->SetLeftChild(delete_node->RightChild());
        } else {
            delete_node_parent->SetLeftChild(delete_node->LeftChild());
        }
    } else if (delete_node_parent->RightChild() == delete_node) {      // 右孩子删除
        if (delete_node->RightChild() != NULL) {
            delete_node_parent->SetRightChild(delete_node->RightChild());
        } else {
            delete_node_parent->SetRightChild(delete_node->LeftChild());
        }
    }

    delete delete_node;
    delete_node = NULL;

    AvlNode<TKey, TValue>* balance_node = DeletionBalanceByStack_(backtrack_stack);

    // 已经完成平衡化的树, 完成最后处理
    if (backtrack_stack.empty() == true) {
        subtree_root = balance_node;
    } else {
        AvlNode<TKey, TValue>* stack_top_node = backtrack_stack.top();
        if (stack_top_node->Key() > balance_node->Key()) {
            stack_top_node->SetLeftChild(balance_node);
        } else {
            stack_top_node->SetRightChild(balance_node);
        }
    }

    return true;
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
 * &emsp; 返回\n
 * + **2 分治递归**\n
 * 访问结点\n
 * **if** 子树为叶子类型(没有左右孩子): \n
 * &emsp; 返回\n
 * 打印'('\n
 * 递归调用PrintSubTreeRecursive_, 对左子树进行打印\n
 * 打印','\n
 * 递归调用PrintSubTreeRecursive_, 对右子树进行打印\n
 * 打印')'\n
 */
template <typename TKey, typename TValue>
void AvlTree<TKey, TValue>::PrintSubTreeRecursive_(
        AvlNode<TKey, TValue>* subtree_root,
        void (*Print)(AvlNode<TKey, TValue>*))
{
    // ---------- 1 空树处理 ----------

    if (subtree_root == NULL) {                                 // if 子树根结点为NULL
        return;                                                 // 返回
    }

    // ---------- 2 分治递归 ----------

    Print(subtree_root);                                        // 访问结点

    // if 子树为叶子类型(没有左右孩子)
    if (subtree_root->LeftChild() == NULL && subtree_root->RightChild() == NULL) {
        return;                                                 // 返回
    }

    cout << "(";                                                // 打印'('

    PrintSubTreeRecursive_(subtree_root->LeftChild(), Print);   // 递归调用PrintSubTreeRecursive_, 对左子树进行打印

    cout << ",";                                                // 打印','

    PrintSubTreeRecursive_(subtree_root->RightChild(), Print);  // 递归调用PrintSubTreeRecursive_, 对右子树进行打印

    cout << ")";                                                // 打印')'
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


template<typename TKey, typename TValue>
bool AvlTree<TKey, TValue>::Remove(TKey key) {
    return this->RemoveInSubTree_(this->Root(), key);
}


/*!
 * @note **获取最小关键字对应的值**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 * @param min_value 值保存变量
 * @return 执行结果
 * 获取最小关键字对应的值
 * -------------------
 * -------------------
 *
 * -------------------
 */
template<typename TKey, typename TValue>
bool AvlTree<TKey, TValue>::Min(TValue& min_value) {
    AvlNode<TKey, TValue>* node = this->MinInSubTree_(this->Root());
    if (!node) {
        return false;
    }

    min_value = node->Value();

    return true;
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

    if (subtree_root == NULL) {
        return NULL;
    }

    AvlNode<TKey, TValue>* cur = subtree_root;

    while (cur && cur->LeftChild() != NULL) {
        cur = cur->LeftChild();
    }

    return cur;
}


template<class TKey, class TValue>
bool AvlTree<TKey, TValue>::Max(TValue& value) {
    AvlNode<TKey, TValue>* node = this->MaxInSubTree_(this->Root());
    if (!node) {
        return false;
    }

    value = node->Value();

    return true;
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

    if (subtree_root == NULL) {
        return NULL;
    }

    AvlNode<TKey, TValue>* cur = subtree_root;
    while (cur && cur->RightChild() != NULL) {
        cur = cur->RightChild();
    }

    return cur;
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
 * &emsp;&emsp; 返回NULL\n
 * + **2 查找结点**\n
 * &emsp; 初始化遍历指针cur, 指向结点的左孩子\n
 * &emsp; **while loop** cur不为NULL <b>&&</b> cur存在右孩子 :\n
 * &emsp;&emsp; cur指向右孩子\n
 * &emsp; 返回cur\n
 */
template<typename TKey, typename TValue>
AvlNode<TKey, TValue>* AvlTree<TKey, TValue>::PreviousNode_(AvlNode<TKey, TValue>* node) {

    // ---------- 1 合法性判断 ----------

    if (!node) {        // if node为NULL :
        return NULL;    // 返回NULL
    }

    // ---------- 2 查找结点 ----------

    AvlNode<TKey, TValue>* cur = node->LeftChild(); // 初始化遍历指针cur, 指向结点的左孩子
    while (cur && cur->RightChild()) {              // while loop cur不为NULL && cur存在右孩子 :
        cur = cur->RightChild();                    // cur指向右孩子
    }

    return cur;                                     // 返回cur
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


#endif // CYBER_DASH_AVL_TREE_H
