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
template<class TKey, class TValue>
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


template<class TKey, class TValue>
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

    TValue Max();
    TValue Min();

    AvlNode<TKey, TValue>* Search(TKey key) { return this->SearchInSubTree_(key, this->root_); }

    void Print(void (*visit)(AvlNode<TKey, TValue>*));

protected:
    bool InsertInSubTree_(TKey key, TValue value, AvlNode<TKey, TValue>*& subtree_root);   // 平衡树子树插入
    bool InsertInSubTreeRecursive_(AvlNode<TKey, TValue>*& subtree_root, TKey key, TValue value);

    bool RemoveInSubTree_(AvlNode<TKey, TValue>*& subtree_root, TKey key);                // 平衡树子树删除
    bool RemoveInSubTreeRecursive_(AvlNode<TKey, TValue>*& subtree_root, TKey key);

    AvlNode<TKey, TValue>* InsertBalanceByStack_(stack<AvlNode<TKey, TValue>*>& backtrack_stack);
    AvlNode<TKey, TValue>* RemoveBalanceByStack_(stack<AvlNode<TKey, TValue>*>& backtrack_stack);
    void Balance_(AvlNode<TKey, TValue>*& node);

    // 左单旋转(Rotation Left)
    int LeftRotate_(AvlNode<TKey, TValue>*& node);
    // 右单旋转(Rotation Right)
    int RightRotate_(AvlNode<TKey, TValue>*& node);
    // 先左后右双旋转(Rotation Left Right)
    int LeftRightRotate_(AvlNode<TKey, TValue>*& node);
    // 先右后左双旋转(Rotation Right Left)
    int RightLeftRotate_(AvlNode<TKey, TValue>*& node);

    AvlNode<TKey, TValue>* SearchInSubTree_(TKey key, AvlNode<TKey, TValue>* subtree_root);

    // 子树中关键码最小项
    AvlNode<TKey, TValue>* MinInSubTree_(AvlNode<TKey, TValue>* subtree_root) const;
    // 子树中关键码最大项
    AvlNode<TKey, TValue>* MaxInSubTreeRecursive_(AvlNode<TKey, TValue>* subtree_root) const;

    // 前一结点
    AvlNode<TKey, TValue>* PreviousNode(AvlNode<TKey, TValue>* node);

    // AVL子树的高度
    int HeightOfSubtreeRecursive_(AvlNode<TKey, TValue>* subtree_root);

    void PrintSubTreeRecursive_(AvlNode<TKey, TValue>* subtree_root, void (*visit)(AvlNode<TKey, TValue>*));

    bool FindInsertPositionAndInitStack_(
            TKey key,
            AvlNode<TKey, TValue>* subtree_root,
            stack<AvlNode<TKey, TValue>*>& backtrack_stack);

    AvlNode<TKey, TValue>* FindDeleteNodeAndInitStack_(
            TKey key,
            AvlNode<TKey, TValue>* subtree_root,
            stack<AvlNode<TKey, TValue>*>& backtrack_stack);

    AvlNode<TKey, TValue>* root_; // 根节点
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
    return this->InsertInSubTree_(key, value, this->Root());
}


template<class TKey, class TValue>
bool AvlTree<TKey, TValue>::InsertRecursive(TKey key, TValue value) {
    return this->InsertInSubTreeRecursive_(this->Root(), key, value);
}

template<class TKey, class TValue>
bool AvlTree<TKey, TValue>::RemoveRecursive(TKey key) {
    return this->RemoveInSubTreeRecursive_(this->Root(), key);
}


template<class TKey, class TValue>
AvlNode<TKey, TValue>* AvlTree<TKey, TValue>::InsertBalanceByStack_(stack<AvlNode<TKey, TValue>*>& backtrack_stack) {
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
AvlNode<TKey, TValue>* AvlTree<TKey, TValue>::RemoveBalanceByStack_(stack<AvlNode<TKey, TValue>*>& backtrack_stack) {

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
 * @brief **(子树)插入结点(递归)**
 * @tparam TKey 关键字类型模板参数
 * @tparam TValue 值类型模板参数
 * @param subtree_root 子树根结点
 * @param key 关键字
 * @param value 值
 * @return 执行结果
 * @note
 * (子树)插入结点(递归)
 * ------------------
 * ------------------
 *
 * ------------------
 */
template<typename TKey, typename TValue>
bool AvlTree<TKey, TValue>::InsertInSubTreeRecursive_(AvlNode<TKey, TValue>*& subtree_root, TKey key, TValue value) {
    if (!subtree_root) {
        subtree_root = new AvlNode<TKey, TValue>(key, value);
        if (!subtree_root) {
            return false;
        }

        return true;
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
    } else {
        return true;
    }

    subtree_root->UpdateHeight();
    subtree_root->UpdateBalanceFactor();

    Balance_(subtree_root);

    return true;
}


template<class TKey, class TValue>
bool AvlTree<TKey, TValue>::RemoveInSubTreeRecursive_(AvlNode<TKey, TValue>*& subtree_root, TKey key) {
    if (!subtree_root) {
        return false;
    }

    if (key < subtree_root->Key()) {
        bool res = RemoveInSubTreeRecursive_(subtree_root->LeftChild(), key);
        if (!res) {
            return res;
        }
    } else if (key > subtree_root->Key()) {
        bool res = RemoveInSubTreeRecursive_(subtree_root->RightChild(), key);
        if (!res) {
            return res;
        }
    } else {
        if (!subtree_root->LeftChild() && !subtree_root->RightChild()) {
            delete subtree_root;
            subtree_root = NULL;
        } else if (!subtree_root->LeftChild()) {
            AvlNode<TKey, TValue>* temp = subtree_root;
            subtree_root = subtree_root->RightChild();
            delete temp;
        } else if (!subtree_root->RightChild()) {
            AvlNode<TKey, TValue>* temp = subtree_root;
            subtree_root = subtree_root->LeftChild();
            delete temp;
        } else {
            AvlNode<TKey, TValue>* prev_node = this->PreviousNode(subtree_root);

            subtree_root->SetKey(prev_node->Key());
            subtree_root->SetValue(prev_node->Value());

            bool res = RemoveInSubTreeRecursive_(subtree_root->LeftChild(), prev_node->Key());
            if (!res) {
                return res;
            }
        }
    }

    if (!subtree_root) {
        return true;
    }

    subtree_root->UpdateHeight();
    subtree_root->UpdateBalanceFactor();

    Balance_(subtree_root);

    return true;
}


/**
 * @brief 平衡树子树插入(CyberDash实现版本)
 * @tparam TValue 数据项模板类型
 * @tparam TKey 关键码模板类型
 * @param value 数据项
 * @param key 关键码
 * @param subtree_root 子树根节点
 * @return 是否插入成功
 * @note
 * 1. 首先找到插入位置, 并且使用栈保存
 * 2. 分3种情况, 进行平衡化
 * 3. 平衡化结束后的收尾工作
 */
template<class TKey, class TValue>
bool AvlTree<TKey, TValue>::InsertInSubTree_(TKey key, TValue value, AvlNode<TKey, TValue>*& subtree_root) {

    stack<AvlNode<TKey, TValue>*> backtrack_stack;

    //! 获取插入位置, 调整栈
    bool res = FindInsertPositionAndInitStack_(key, subtree_root, backtrack_stack);
    if (!res) {
        return res;
    }

    AvlNode<TKey, TValue>* insert_node = new AvlNode<TKey, TValue>(key, value);
    /* error handler */

    // 空树, 新结点成为根节点, 并返回
    if (backtrack_stack.empty()) {
        subtree_root = insert_node;
        return true;
    }

    AvlNode<TKey, TValue>* cur_parent_node = backtrack_stack.top();

    if (key < cur_parent_node->Key()) {
        cur_parent_node->SetLeftChild(insert_node);
    } else {
        cur_parent_node->SetRightChild(insert_node);
    }

    AvlNode<TKey, TValue>* balanced_node = this->InsertBalanceByStack_(backtrack_stack);

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
 * 定位删除结点位置并初始化队列
 * @tparam TValue 数据项模板参数
 * @tparam TKey 键模板参数
 * @param key 键值
 * @param subtree_root 子树根节点
 * @param backtrack_stack AVL结点栈
 * @return 待删除结点的指针
 * @note
 * 函数执行完后:
 *     1. 返回待删除结点的指针, 如果没有找到则返回NULL
 *     2. 待删除结点的祖先节点进入队列
 */
template<class TKey, class TValue>
AvlNode<TKey, TValue>* AvlTree<TKey, TValue>::FindDeleteNodeAndInitStack_(TKey key,
                                                                          AvlNode<TKey, TValue>* subtree_root,
                                                                          stack<AvlNode<TKey, TValue>*>& backtrack_stack)
{
    AvlNode<TKey, TValue>* cur_node = subtree_root;  // 遍历结点

    // 使用key寻找删除结点的位置,
    // 并将该结点的所有祖先结点插入队列
    while (cur_node != NULL) {

        // 找到等于key的结点, 跳出循环
        if (key == cur_node->Key()) {
            break;
        }

        // cur_node入栈
        backtrack_stack.push(cur_node);

        if (key < cur_node->Key()) {
            cur_node = cur_node->LeftChild();
        } else {
            cur_node = cur_node->RightChild();
        }
    }

    return cur_node;
}


template<class TKey, class TValue>
bool AvlTree<TKey, TValue>::FindInsertPositionAndInitStack_(
        TKey key,
        AvlNode<TKey, TValue>* subtree_root,
        stack<AvlNode<TKey, TValue>*>& backtrack_stack)
{
    AvlNode<TKey, TValue>* cur_node = subtree_root;

    // 寻找插入位置
    while (cur_node != NULL) {
        // 找到等于key的结点, 无法插入
        if (key == cur_node->Key()) {
            return false;
        }

        backtrack_stack.push(cur_node);

        if (key < cur_node->Key()) {
            cur_node = cur_node->LeftChild();
        } else {
            cur_node = cur_node->RightChild();
        }
    }

    return true;
}


/**
 * @brief 在子树中, 使用关键码进行搜索
 * @tparam TValue 数据项模板类型
 * @tparam TKey 关键码模板类型
 * @param key 关键码
 * @param subtree_root 子树根节点
 * @return 搜索结果
 * @note
 * 1. 如果子树根节点为NULL, 返回NULL
 * 2. 使用当前遍历节点的key, 与参数key作比较, 分别进行递归和返回搜索结果(终止递归)
 */
template <class TKey, class TValue>
AvlNode<TKey, TValue>* AvlTree<TKey, TValue>::SearchInSubTree_(TKey key, AvlNode<TKey, TValue>* subtree_root) {
    if (subtree_root == NULL) {
        return NULL;
    }

    TKey cur_key = subtree_root->Key();

    if (key < cur_key) {
        return SearchInSubTree_(key, subtree_root->LeftChild());
    } else if (key > cur_key) {
        return SearchInSubTree_(key, subtree_root->RightChild());
    }

    return subtree_root;
}


/**
 * @brief 平衡树子树删除节点(CyberDash实现版本)
 * @tparam TValue 数据项模板类型
 * @tparam TKey 关键码模板类型
 * @param subtree_root 子树根节点
 * @param key 待删除关键码
 * @return
 */
template<class TKey, class TValue>
bool AvlTree<TKey, TValue>::RemoveInSubTree_(AvlNode<TKey, TValue>*& subtree_root, TKey key) {

    stack < AvlNode<TKey, TValue> * > backtrack_stack;

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
    } else {

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

        AvlNode<TKey, TValue>* balance_node = RemoveBalanceByStack_(backtrack_stack);

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
    }

    return true;
}


/**
 * @brief 打印子树(递归)
 * @tparam TValue
 * @tparam TKey
 * @param subtree_root
 * @param visit
 */
template <class TKey, class TValue>
void AvlTree<TKey, TValue>::PrintSubTreeRecursive_(
        AvlNode<TKey, TValue>* subtree_root,
        void (*visit)(AvlNode<TKey, TValue>*))
{
    if (subtree_root == NULL) {
        return;
    }

    visit(subtree_root);

    if (subtree_root->LeftChild() != NULL || subtree_root->RightChild() != NULL) {

        cout << "(";

        PrintSubTreeRecursive_(subtree_root->LeftChild(), visit);

        cout << ",";

        PrintSubTreeRecursive_(subtree_root->RightChild(), visit);

        cout << ")";

    }
}


template<class TKey, class TValue>
void AvlTree<TKey, TValue>::Print(void (*visit)(AvlNode<TKey, TValue>*)) {
    this->PrintSubTreeRecursive_((AvlNode<TKey, TValue> *) this->root_, visit); cout << endl;
}


template<class TKey, class TValue>
bool AvlTree<TKey, TValue>::Remove(TKey key) {
    return this->RemoveInSubTree_(this->Root(), key);
}


template <class TKey, class TValue>
AvlNode<TKey, TValue>* AvlTree<TKey, TValue>::MinInSubTree_(AvlNode<TKey, TValue>* subtree_root) const {

    if (subtree_root == NULL) {
        return NULL;
    }

    AvlNode<TKey, TValue>* cur_node = subtree_root;

    while (cur_node->LeftChild() != NULL) {
        cur_node = cur_node->LeftChild();
    }

    return cur_node;
}


template<class TKey, class TValue>
TValue AvlTree<TKey, TValue>::Max() {
    AvlNode<TKey, TValue>* max_node = this->MaxInSubTreeRecursive_(this->Root());
    return max_node->Value();
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
AvlNode<TKey, TValue>* AvlTree<TKey, TValue>::MaxInSubTreeRecursive_(AvlNode<TKey, TValue>* subtree_root) const {

    if (subtree_root == NULL) {
        return NULL;
    }

    AvlNode<TKey, TValue>* cur_node = subtree_root;
    while (cur_node->RightChild() != NULL) {
        cur_node = cur_node->RightChild();
    }

    return cur_node;
}


template<class TKey, class TValue>
TValue AvlTree<TKey, TValue>::Min() {
    AvlNode<TKey, TValue>* max_node = this->MinInSubTree_(this->Root());
    return max_node->Value();
}


template<class TKey, class TValue>
AvlNode<TKey, TValue>* AvlTree<TKey, TValue>::PreviousNode(AvlNode<TKey, TValue>* node) {
    AvlNode<TKey, TValue>* cur = node->LeftChild();
    while (cur->RightChild()) {
        cur = cur->RightChild();
    }

    return cur;
}


template<class TKey, class TValue>
int AvlTree<TKey, TValue>::HeightOfSubtreeRecursive_(AvlNode<TKey, TValue>* subtree_root) {
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


#endif // CYBER_DASH_AVL_TREE_H
