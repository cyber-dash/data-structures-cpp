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
     * @brief **构造函数(无左右孩子)**
     * @param key 关键码
     * @param value 数据项
     * @note
     * 构造函数(无左右孩子)
     * ------------
     * ------------
     * 设置key/value, 左右孩子为NULL, 高度设为1, 平衡因子设为0
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
        this->height_ = (left_height > right_height ? left_height : right_height) + 1;  // 注意使用括号
        // this->height_ = max(left_height, right_height) + 1;
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
    TKey key_;              //!< **关键码(用于比较)**
    TValue value_;          //!< **数据项**
    int height_;            //!< **高度(作为子树根节点时具有意义)**
    int balance_factor_;    //!< **平衡因子**

    AvlNode<TKey, TValue>* left_child_;     //!< **左孩子**
    AvlNode<TKey, TValue>* right_child_;    //!< **右孩子**
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
    int HeightRecursive() { return this->SubTreeHeight_(this->root_); }

    TValue Max();
    TValue Min();

    AvlNode<TKey, TValue>* Search(TKey key) { return this->SearchInSubTree_(key, this->root_); }

    void Print(void (*visit)(AvlNode<TKey, TValue>*));

protected:
    bool InsertInSubTree_(TKey key, TValue value, AvlNode<TKey, TValue>*& sub_tree_root);   // 平衡树子树插入
    bool InsertInSubTreeRecursive_(AvlNode<TKey, TValue>*& sub_tree_root, TKey key, TValue value);

    bool RemoveInSubTree_(AvlNode<TKey, TValue>*& sub_tree_root, TKey key);                // 平衡树子树删除
    bool RemoveInSubTreeRecursive_(AvlNode<TKey, TValue>*& sub_tree_root, TKey key);

    AvlNode<TKey, TValue>* InsertBalanceByStack_(stack<AvlNode<TKey, TValue>*>& AVL_node_stack);
    AvlNode<TKey, TValue>* RemoveBalanceByStack_(stack<AvlNode<TKey, TValue>*>& AVL_node_stack);
    void Balance_(AvlNode<TKey, TValue>*& node);

    // 左单旋转(Rotation Left)
    int LeftRotate_(AvlNode<TKey, TValue>*& node);
    // 右单旋转(Rotation Right)
    int RightRotate_(AvlNode<TKey, TValue>*& node);
    // 先左后右双旋转(Rotation Left Right)
    int LeftRightRotate_(AvlNode<TKey, TValue>*& node);
    // 先右后左双旋转(Rotation Right Left)
    int RightLeftRotate_(AvlNode<TKey, TValue>*& node);

    AvlNode<TKey, TValue>* SearchInSubTree_(TKey key, AvlNode<TKey, TValue>* sub_tree_root);

    // 子树中关键码最小项
    AvlNode<TKey, TValue>* MinInSubTree_(AvlNode<TKey, TValue>* sub_tree_root) const;
    // 子树中关键码最大项
    AvlNode<TKey, TValue>* MaxInSubTreeRecursive_(AvlNode<TKey, TValue>* sub_tree_root) const;

    // 前一结点
    AvlNode<TKey, TValue>* PreviousNode(AvlNode<TKey, TValue>* node);

    // AVL子树的高度
    int SubTreeHeight_(AvlNode<TKey, TValue>* sub_tree_root);

    void PrintSubTreeRecursive_(AvlNode<TKey, TValue>* sub_tree_root, void (*visit)(AvlNode<TKey, TValue>*));

    bool LocateInsertPositionAndInitStack_(
            TKey key,
            AvlNode<TKey, TValue>* sub_tree_root,
            stack<AvlNode<TKey, TValue>*>& AVL_node_stack);

    AvlNode<TKey, TValue>* LocateDeleteNodeAndInitStack_(
            TKey key,
            AvlNode<TKey, TValue>* sub_tree_root,
            stack<AvlNode<TKey, TValue>*>& AVL_node_stack);

    AvlNode<TKey, TValue>* root_; // 根节点
};


/*!
 * @brief 左单旋转(Rotation Left)
 * @tparam TValue 搜索结果(数据)模板类型
 * @tparam TKey 关键码模板类型
 * @param node AVL树节点指针的引用
 * @note
 * ```
 *     Sub_Tree_Root                          pivot
 *            \                                / \
 *             \                              /   \
 *           pivot                 Sub_Tree_Root  node3
 *            / \                             \
 *           /   \                             \
 *       node2  node3                         node2
 *
 *     Sub_Tree_Root                          pivot
 *            \                                / \
 *             \                              /   \
 *           pivot                 Sub_Tree_Root  node3
 *              \
 *               \
 *             node3
 * ```
 */
template<class TKey, class TValue>
int AvlTree<TKey, TValue>::LeftRotate_(AvlNode<TKey, TValue>*& node) {

    AvlNode<TKey, TValue>* pivot = node->RightChild();

    //! 执行左旋
    node->SetRightChild(pivot->LeftChild());
    pivot->SetLeftChild(node);

    // 更新height
    node->UpdateHeight();
    pivot->UpdateHeight();

    node->UpdateBalanceFactor();
    pivot->UpdateBalanceFactor();

    node = pivot;   // --- 子树根节点指向pivot指向的结点 ---

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
 *          sub_tree_root                         sub_tree_root                                   pivot
 *               / \                                   / \                                         / \
 *              /   \                                 /   \                                       /   \
 *             /     \                               /     \                                     /     \
 *            /       \                             /       \                                   /       \
 *           /         \                           /         \                                 /         \
 *  left_rotate_pivot  node2                     pivot       node2                 left_rotate_pivot   sub_tree_root
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
template<class TKey, class TValue>
int AvlTree<TKey, TValue>::LeftRightRotate_(AvlNode<TKey, TValue>*& node) {
    AvlNode<TKey, TValue>* left_rotate_pivot = node->LeftChild();
    AvlNode<TKey, TValue>* right_rotate_pivot = left_rotate_pivot->RightChild();

    // 执行左旋
    left_rotate_pivot->SetRightChild(right_rotate_pivot->LeftChild());
    right_rotate_pivot->SetLeftChild(left_rotate_pivot);

    // 执行右旋
    node->SetLeftChild(right_rotate_pivot->RightChild());
    right_rotate_pivot->SetRightChild(node);

    left_rotate_pivot->UpdateHeight();
    left_rotate_pivot->UpdateBalanceFactor();

    node->UpdateHeight();
    node->UpdateBalanceFactor();

    right_rotate_pivot->UpdateHeight();
    right_rotate_pivot->UpdateBalanceFactor();

    node = right_rotate_pivot;  // --- 子树根节点指向pivot指向的结点 ---

    return node->BalanceFactor();
}


/*!
 * @brief **右左旋**
 * @tparam TValue 数据项模板参数
 * @tparam TKey 键值模板参数
 * @param sub_tree_root 旋转前的子树根结点
 * 右左旋
 * -----
 * -----
 *
 * -----
 */
template<class TKey, class TValue>
int AvlTree<TKey, TValue>::RightLeftRotate_(AvlNode<TKey, TValue>*& node) {

    AvlNode<TKey, TValue>* right_rotate_pivot = node->RightChild();
    AvlNode<TKey, TValue>* left_rotate_pivot = right_rotate_pivot->LeftChild();

    // cur_root/pivot 执行右旋
    right_rotate_pivot->SetLeftChild(left_rotate_pivot->RightChild());
    left_rotate_pivot->SetRightChild(right_rotate_pivot);

    // new_left_child/pivot 执行左旋
    node->SetRightChild(left_rotate_pivot->LeftChild());
    left_rotate_pivot->SetLeftChild(node);

    // 更新height
    right_rotate_pivot->UpdateHeight();
    right_rotate_pivot->UpdateBalanceFactor();

    node->UpdateHeight();
    node->UpdateBalanceFactor();

    left_rotate_pivot->UpdateHeight();
    left_rotate_pivot->UpdateBalanceFactor();

    node = left_rotate_pivot;   // --- 子树根节点指向pivot指向的结点 ---

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
AvlNode<TKey, TValue>* AvlTree<TKey, TValue>::InsertBalanceByStack_(stack<AvlNode<TKey, TValue>*>& AVL_node_stack) {
    AvlNode<TKey, TValue>* cur_parent_node = NULL;

    while (AVL_node_stack.empty() == false) {

        // 获取双亲结点
        cur_parent_node = AVL_node_stack.top();
        AVL_node_stack.pop();

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
AvlNode<TKey, TValue>* AvlTree<TKey, TValue>::RemoveBalanceByStack_(stack<AvlNode<TKey, TValue>*>& AVL_node_stack) {

    AvlNode<TKey, TValue>* cur_parent_node = NULL;

    while (!AVL_node_stack.empty()) {

        // 获取双亲结点
        cur_parent_node = AVL_node_stack.top();
        AVL_node_stack.pop();

        int grand_parent_direction;
        if (!AVL_node_stack.empty()) {
            AvlNode<TKey, TValue>* cur_grand_node = AVL_node_stack.top();
            if (cur_grand_node->LeftChild() == cur_parent_node) {
                grand_parent_direction = -1; // 左
            } else if (cur_grand_node->RightChild() == cur_parent_node) {
                grand_parent_direction = 1;  // 右
            }
        }

        cur_parent_node->UpdateHeight();
        cur_parent_node->UpdateBalanceFactor();

        this->Balance_(cur_parent_node);

        if (!AVL_node_stack.empty()) {
            AvlNode<TKey, TValue>* cur_grand_parent_node = AVL_node_stack.top();  // grand结点需要更新孩子结点
            if (grand_parent_direction == -1) {
                cur_grand_parent_node->SetLeftChild(cur_parent_node);
            } else {
                cur_grand_parent_node->SetRightChild(cur_parent_node);
            }
        }
    }

    return cur_parent_node;
}


template<class TKey, class TValue>
void AvlTree<TKey, TValue>::Balance_(AvlNode<TKey, TValue>*& node) {
    if (node->BalanceFactor() == AvlNode<TKey, TValue>::RIGHT_HIGHER_2) {
        if (node->RightChild()->BalanceFactor() != AvlNode<TKey, TValue>::LEFT_HIGHER_1) {
            this->LeftRotate_(node);        // 左单旋转
        } else {
            this->RightLeftRotate_(node);   // 右左旋转
        }
    } else if (node->BalanceFactor() == AvlNode<TKey, TValue>::LEFT_HIGHER_2) {
        if (node->LeftChild()->BalanceFactor() != AvlNode<TKey, TValue>::RIGHT_HIGHER_1) {
            this->RightRotate_(node);       // 右单旋转
        } else {
            this->LeftRightRotate_(node);   // 左右旋转
        }
    }
}


/*!
 * @brief **红黑树(子树)插入结点(递归)**
 * @tparam TKey 结点关键码类型模板参数
 * @tparam TValue 结点数据项类型模板参数
 * @param sub_tree_root 子树根节点
 * @param key 结点关键码
 * @param value 结点数据项
 * @return 执行结果
 * @note
 * 红黑树(子树)插入结点(递归)
 * -----------------------
 * -----------------------
 *
 * -----------------------
 */
template<class TKey, class TValue>
bool AvlTree<TKey, TValue>::InsertInSubTreeRecursive_(AvlNode<TKey, TValue>*& sub_tree_root, TKey key, TValue value) {
    if (!sub_tree_root) {
        sub_tree_root = new AvlNode<TKey, TValue>(key, value);
        if (!sub_tree_root) {
            return false;
        }

        return true;
    }

    if (key < sub_tree_root->Key()) {
        bool res = InsertInSubTreeRecursive_(sub_tree_root->LeftChild(), key, value);
        if (!res) {
            return res;
        }
    } else if (key > sub_tree_root->Key()) {
        bool res = InsertInSubTreeRecursive_(sub_tree_root->RightChild(), key, value);
        if (!res) {
            return res;
        }
    } else {
        return true;
    }

    sub_tree_root->UpdateHeight();
    sub_tree_root->UpdateBalanceFactor();

    Balance_(sub_tree_root);

    return true;
}


template<class TKey, class TValue>
bool AvlTree<TKey, TValue>::RemoveInSubTreeRecursive_(AvlNode<TKey, TValue>*& sub_tree_root, TKey key) {
    if (!sub_tree_root) {
        return false;
    }

    if (key < sub_tree_root->Key()) {
        bool res = RemoveInSubTreeRecursive_(sub_tree_root->LeftChild(), key);
        if (!res) {
            return res;
        }
    } else if (key > sub_tree_root->Key()) {
        bool res = RemoveInSubTreeRecursive_(sub_tree_root->RightChild(), key);
        if (!res) {
            return res;
        }
    } else {
        if (!sub_tree_root->LeftChild() && !sub_tree_root->RightChild()) {
            delete sub_tree_root;
            sub_tree_root = NULL;
        } else if (!sub_tree_root->LeftChild()) {
            AvlNode<TKey, TValue>* temp = sub_tree_root;
            sub_tree_root = sub_tree_root->RightChild();
            delete temp;
        } else if (!sub_tree_root->RightChild()) {
            AvlNode<TKey, TValue>* temp = sub_tree_root;
            sub_tree_root = sub_tree_root->LeftChild();
            delete temp;
        } else {
            AvlNode<TKey, TValue>* prev_node = this->PreviousNode(sub_tree_root);

            sub_tree_root->SetKey(prev_node->Key());
            sub_tree_root->SetValue(prev_node->Value());

            bool res = RemoveInSubTreeRecursive_(sub_tree_root->LeftChild(), prev_node->Key());
            if (!res) {
                return res;
            }
        }
    }

    if (!sub_tree_root) {
        return true;
    }

    sub_tree_root->UpdateHeight();
    sub_tree_root->UpdateBalanceFactor();

    Balance_(sub_tree_root);

    return true;
}


/**
 * @brief 平衡树子树插入(CyberDash实现版本)
 * @tparam TValue 数据项模板类型
 * @tparam TKey 关键码模板类型
 * @param value 数据项
 * @param key 关键码
 * @param sub_tree_root 子树根节点
 * @return 是否插入成功
 * @note
 * 1. 首先找到插入位置, 并且使用栈保存
 * 2. 分3种情况, 进行平衡化
 * 3. 平衡化结束后的收尾工作
 */
template<class TKey, class TValue>
bool AvlTree<TKey, TValue>::InsertInSubTree_(TKey key, TValue value, AvlNode<TKey, TValue>*& sub_tree_root) {

    stack<AvlNode<TKey, TValue>*> AVL_node_stack;

    //! 获取插入位置, 调整栈
    bool res = LocateInsertPositionAndInitStack_(key, sub_tree_root, AVL_node_stack);
    if (!res) {
        return res;
    }

    AvlNode<TKey, TValue>* insert_node = new AvlNode<TKey, TValue>(key, value);
    /* error handler */

    // 空树, 新结点成为根节点, 并返回
    if (AVL_node_stack.empty()) {
        sub_tree_root = insert_node;
        return true;
    }

    AvlNode<TKey, TValue>* cur_parent_node = AVL_node_stack.top();

    if (key < cur_parent_node->Key()) {
        cur_parent_node->SetLeftChild(insert_node);
    } else {
        cur_parent_node->SetRightChild(insert_node);
    }

    AvlNode<TKey, TValue>* balanced_node = this->InsertBalanceByStack_(AVL_node_stack);

    // 已经完成平衡化的树, 完成最后处理
    if (AVL_node_stack.empty() == true) {
        sub_tree_root = balanced_node;
    } else {
        AvlNode<TKey, TValue>* stack_top_node = AVL_node_stack.top();
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
 * @param sub_tree_root 子树根节点
 * @param AVL_node_stack AVL结点栈
 * @return 待删除结点的指针
 * @note
 * 函数执行完后:
 *     1. 返回待删除结点的指针, 如果没有找到则返回NULL
 *     2. 待删除结点的祖先节点进入队列
 */
template<class TKey, class TValue>
AvlNode<TKey, TValue>* AvlTree<TKey, TValue>::LocateDeleteNodeAndInitStack_(TKey key,
                                                                            AvlNode<TKey, TValue>* sub_tree_root,
                                                                            stack<AvlNode<TKey, TValue>*>& AVL_node_stack)
{
    AvlNode<TKey, TValue>* cur_node = sub_tree_root;  // 遍历结点

    // 使用key寻找删除结点的位置,
    // 并将该结点的所有祖先结点插入队列
    while (cur_node != NULL) {

        // 找到等于key的结点, 跳出循环
        if (key == cur_node->Key()) {
            break;
        }

        // cur_node入栈
        AVL_node_stack.push(cur_node);

        if (key < cur_node->Key()) {
            cur_node = cur_node->LeftChild();
        } else {
            cur_node = cur_node->RightChild();
        }
    }

    return cur_node;
}


template<class TKey, class TValue>
bool AvlTree<TKey, TValue>::LocateInsertPositionAndInitStack_(
        TKey key,
        AvlNode<TKey, TValue>* sub_tree_root,
        stack<AvlNode<TKey, TValue>*>& AVL_node_stack)
{
    AvlNode<TKey, TValue>* cur_node = sub_tree_root;

    // 寻找插入位置
    while (cur_node != NULL) {
        // 找到等于key的结点, 无法插入
        if (key == cur_node->Key()) {
            // return NULL;
            return false;
        }

        AVL_node_stack.push(cur_node);

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
 * @param sub_tree_root 子树根节点
 * @return 搜索结果
 * @note
 * 1. 如果子树根节点为NULL, 返回NULL
 * 2. 使用当前遍历节点的key, 与参数key作比较, 分别进行递归和返回搜索结果(终止递归)
 */
template <class TKey, class TValue>
AvlNode<TKey, TValue>* AvlTree<TKey, TValue>::SearchInSubTree_(TKey key, AvlNode<TKey, TValue>* sub_tree_root) {
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


/**
 * @brief 平衡树子树删除节点(CyberDash实现版本)
 * @tparam TValue 数据项模板类型
 * @tparam TKey 关键码模板类型
 * @param sub_tree_root 子树根节点
 * @param key 待删除关键码
 * @return
 */
template<class TKey, class TValue>
bool AvlTree<TKey, TValue>::RemoveInSubTree_(AvlNode<TKey, TValue>*& sub_tree_root, TKey key) {

    stack < AvlNode<TKey, TValue> * > AVL_node_stack;

    AvlNode<TKey, TValue>* delete_node = LocateDeleteNodeAndInitStack_(key, sub_tree_root, AVL_node_stack);
    if (delete_node == NULL) {
        return false; // 未找到删除结点
    }

    // 此时定位到delete_node, delete_node之前的所有祖先结点, 都已经入栈

    AvlNode<TKey, TValue>* delete_node_predecessor = NULL;
    // 结点有两个子女, 在左子树找到delete_node的直接前驱
    if (delete_node->LeftChild() != NULL  && delete_node->RightChild() != NULL ) {
        AVL_node_stack.push(delete_node); // 将待删除节点入stack

        delete_node_predecessor = delete_node->LeftChild();
        while (delete_node_predecessor->RightChild() != NULL) {
            AVL_node_stack.push(delete_node_predecessor);
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
        AVL_node_stack.push(delete_node); // 将待删除节点入stack

        // 将前驱结点作为待删除结点
        delete_node = delete_node_predecessor;
    }
    else if (delete_node->RightChild() != NULL) {  // 结点只有右孩子结点(由于平衡特性, 此时此右孩子必为叶子), 则右孩子结点为删除结点
        delete_node_predecessor = delete_node->RightChild();

        // 将被删除结点的前驱结点的值赋给被删除结点
        delete_node->SetKey(delete_node_predecessor->Key());
        delete_node->SetValue(delete_node_predecessor->Value());
        AVL_node_stack.push(delete_node); // 将待删除节点入stack

        // 将前驱结点作为待删除结点
        delete_node = delete_node_predecessor;
    }
    else {    // 结点为叶子结点
    }

    if (AVL_node_stack.empty()) {   // 删除根结点
        sub_tree_root = delete_node->RightChild();

        delete delete_node;
        delete_node = NULL;

        return true;
    } else {

        // 被删除结点的父节点与被删除结点的左孩子相连, 甩掉delete_node
        AvlNode<TKey, TValue>* delete_node_parent = AVL_node_stack.top();

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

        AvlNode<TKey, TValue>* balance_node = RemoveBalanceByStack_(AVL_node_stack);

        // 已经完成平衡化的树, 完成最后处理
        if (AVL_node_stack.empty() == true) {
            sub_tree_root = balance_node;
        } else {
            AvlNode<TKey, TValue>* stack_top_node = AVL_node_stack.top();
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
 * @param sub_tree_root
 * @param visit
 */
template <class TKey, class TValue>
void AvlTree<TKey, TValue>::PrintSubTreeRecursive_(
        AvlNode<TKey, TValue>* sub_tree_root,
        void (*visit)(AvlNode<TKey, TValue>*))
{
    if (sub_tree_root == NULL) {
        return;
    }

    visit(sub_tree_root);

    if (sub_tree_root->LeftChild() != NULL || sub_tree_root->RightChild() != NULL) {

        cout << "(";

        PrintSubTreeRecursive_(sub_tree_root->LeftChild(), visit);

        cout << ",";

        PrintSubTreeRecursive_(sub_tree_root->RightChild(), visit);

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
AvlNode<TKey, TValue>* AvlTree<TKey, TValue>::MinInSubTree_(AvlNode<TKey, TValue>* sub_tree_root) const {

    if (sub_tree_root == NULL) {
        return NULL;
    }

    AvlNode<TKey, TValue>* cur_node = sub_tree_root;

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
 * @param sub_tree_root 子树根节点
 * @return 关键码最大项
 * @note
 * 右孩子节点迭代
 */
template <class TKey, class TValue>
AvlNode<TKey, TValue>* AvlTree<TKey, TValue>::MaxInSubTreeRecursive_(AvlNode<TKey, TValue>* sub_tree_root) const {

    if (sub_tree_root == NULL) {
        return NULL;
    }

    AvlNode<TKey, TValue>* cur_node = sub_tree_root;
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
int AvlTree<TKey, TValue>::SubTreeHeight_(AvlNode<TKey, TValue>* sub_tree_root) {
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

#endif // CYBER_DASH_AVL_TREE_H
