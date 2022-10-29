//
// Created by cyberdash@163.com on 2021/7/5.
//

#ifndef CYBER_DASH_AVL_TREE_H
#define CYBER_DASH_AVL_TREE_H


#include "binary_search_tree.h"
#include "stack"


/*
int max(int a, int b) {
    if (a > b) {
        return a;
    }

    return b;
}
 */

template<class Key, class Value>
class AVLNode : public BSTNode<Key, Value> {
public:
    AVLNode(): left_child_(NULL), right_child_(NULL), height_(1), balance_factor_(0) {}
    AVLNode(const Key& key, const Value& value) :
        value_(value), key_(key), left_child_(NULL), right_child_(NULL), height_(1), balance_factor_(0) {}
    AVLNode(Key key, Value value, AVLNode<Key, Value>* left_child, AVLNode<Key, Value>* right_child) :
        value_(value), key_(key), left_child_(left_child), right_child_(right_child), height_(1), balance_factor_(0) {}

    void SetLeftChild(AVLNode<Key, Value>* node) { this->left_child_ = node; }
    AVLNode<Key, Value>*& LeftChild() { return this->left_child_; };

    void SetRightChild(AVLNode<Key, Value>* node) { this->right_child_ = node; }
    AVLNode<Key, Value>*& RightChild() { return this->right_child_; };

    void SetValue(const Value& value) { this->value_ = value; }
    Value GetValue() { return this->value_; }

    void SetKey(const Key& key) { this->key_ = key; }
    Key GetKey() { return this->key_; }

    void SetHeight(int height) { this->height_ = height; }
    int GetHeight() { return this->height_; }

    void SetBalanceFactor(int balance_factor) { this->balance_factor_ = balance_factor; }
    int GetBalanceFactor() { return this->balance_factor_; }

    void UpdateHeight() {
        int left_height = this->left_child_ ? this->left_child_->GetHeight() : 0;
        int right_height = this->right_child_ ? this->right_child_->GetHeight() : 0;
        this->height_ = max(left_height, right_height) + 1;
    }
    void UpdateBalanceFactor() {
        int left_height = this->left_child_ ? this->left_child_->GetHeight() : 0;
        int right_height = this->right_child_ ? this->right_child_->GetHeight() : 0;
        this->balance_factor_ = right_height - left_height;
    }

    static int max(int a, int b) {
        if (a > b) {
            return a;
        }

        return b;
    }

    static const int RIGHT_HIGHER_2 = 2;    //!< 左子树比右子树矮2
    static const int RIGHT_HIGHER_1 = 1;    //!< 左子树比右子树矮1
    static const int BALANCED = 0;          //!< 左右相等
    static const int LEFT_HIGHER_1 = -1;    //!< 左子树比右子树高1
    static const int LEFT_HIGHER_2 = -2;    //!< 左子树比右子树高2

protected:
    AVLNode<Key, Value>* left_child_;
    AVLNode<Key, Value>* right_child_;

    Value value_;
    Key key_;
    int height_;

    int balance_factor_;
};


template<class Key, class Value>
class AVLTree : public BST<Key, Value> {
public:
    AVLTree() : root_node_(NULL) {}
    AVLNode<Key, Value>*& RootRef() { return (AVLNode<Key, Value>*&)this->root_node_; }
    AVLNode<Key, Value>* Root() { return this->root_node_; }

    bool Insert(Key key, Value data);
    bool Remove(Key key);
    AVLNode<Key, Value>* Search(Key key) { return this->SearchInSubTree_(key, this->root_node_); }
    int Height() { return this->SubTreeHeight_(this->root_node_); }
    int Height2() { return this->root_node_->GetHeight(); }
    //
    Value Max();
    Value Min();
    void Print(void (*visit)(AVLNode<Key, Value>*));

    static bool LocateInsertPositionAndInitStack(
        Key key,
        AVLNode<Key, Value>* sub_tree_root,
        stack<AVLNode<Key, Value>*>& AVL_node_stack);

    static AVLNode<Key, Value>* LocateDeleteNodeAndInitStack(
        Key key,
        AVLNode<Key, Value>* sub_tree_root,
        stack<AVLNode<Key, Value>*>& AVL_node_stack);

protected:

    AVLNode<Key, Value>* InsertBalance_(stack<AVLNode<Key, Value>*>& AVL_node_stack);
    AVLNode<Key, Value>* RemoveBalance_(stack<AVLNode<Key, Value>*>& AVL_node_stack);
    void Balance_(AVLNode<Key, Value>*& node);

    AVLNode<Key, Value>* SearchInSubTree_(Key key, AVLNode<Key, Value>* sub_tree_root);
    bool InsertInSubTree_(Key key, Value value, AVLNode<Key, Value>*& sub_tree_root);   // 平衡树子树插入
    bool RemoveInSubTree_(AVLNode<Key, Value>*& sub_tree_root, Key key);                // 平衡树子树删除

    // 左单旋转(Rotation Left)
    int LeftRotate_(AVLNode<Key, Value>*& node);
    // 右单旋转(Rotation Right)
    int RightRotate_(AVLNode<Key, Value>*& node);
    // 先左后右双旋转(Rotation Left Right)
    int LeftRightRotate_(AVLNode<Key, Value>*& node);
    // 先右后左双旋转(Rotation Right Left)
    int RightLeftRotate_(AVLNode<Key, Value>*& node);

    // 子树中关键码最小项
    AVLNode<Key, Value>* MinInSubTree_(AVLNode<Key, Value>* sub_tree_root) const;

    // 子树中关键码最大项
    AVLNode<Key, Value>* MaxInSubTreeRecursive_(AVLNode<Key, Value>* sub_tree_root) const;
    // AVL子树的高度
    int SubTreeHeight_(AVLNode<Key, Value>* sub_tree_root);

    void PrintSubTreeRecursive_(AVLNode<Key, Value>* sub_tree_root, void (*visit)(AVLNode<Key, Value>*));

    AVLNode<Key, Value>* root_node_; // 根节点
    // int height_;    // 高度
};


/**
 * 左单旋转(Rotation Left), 图7.15(a)的情形
 * @tparam Value 搜索结果(数据)模板类型
 * @tparam Key 关键码模板类型
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
template<class Key, class Value>
int AVLTree<Key, Value>::LeftRotate_(AVLNode<Key, Value>*& node) {

    AVLNode<Key, Value>* pivot = node->RightChild();

    //! 执行左旋
    node->SetRightChild(pivot->LeftChild());
    pivot->SetLeftChild(node);

    // 更新height
    node->UpdateHeight();
    pivot->UpdateHeight();

    node->UpdateBalanceFactor();
    pivot->UpdateBalanceFactor();

    node = pivot;   // --- 子树根节点指向pivot指向的结点 ---

    return node->GetBalanceFactor();
}


/**
 * 右单旋转(Rotation Right), 图7.16(a)的情形
 * @tparam Value 搜索结果(数据)模板类型
 * @tparam Key 关键码模板类型
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
template<class Key, class Value>
int AVLTree<Key, Value>::RightRotate_(AVLNode<Key, Value>*& node) {

    //! pivot指向调整后的(子树根)结点
    AVLNode<Key, Value>* pivot = node->LeftChild();

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

    return node->GetBalanceFactor();
}


/*!
 * 左右旋
 * @tparam Value 数据项模板参数
 * @tparam Key 键值模板参数
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
template<class Key, class Value>
int AVLTree<Key, Value>::LeftRightRotate_(AVLNode<Key, Value>*& node) {
    AVLNode<Key, Value>* left_rotate_pivot = node->LeftChild();
    AVLNode<Key, Value>* right_rotate_pivot = left_rotate_pivot->RightChild();

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

    return node->GetBalanceFactor();
}


/*!
 * @brief **右左旋**
 * @tparam Value 数据项模板参数
 * @tparam Key 键值模板参数
 * @param sub_tree_root 旋转前的子树根结点
 * 右左旋
 * -----
 * -----
 *
 * -----
 */
template<class Key, class Value>
int AVLTree<Key, Value>::RightLeftRotate_(AVLNode<Key, Value>*& node) {

    AVLNode<Key, Value>* right_rotate_pivot = node->RightChild();
    AVLNode<Key, Value>* left_rotate_pivot = right_rotate_pivot->LeftChild();

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

    return node->GetBalanceFactor();
}


// todo: Value和Key的参数位置应该互换
template<class Key, class Value>
bool AVLTree<Key, Value>::Insert(Key key, Value data) {
    return this->InsertInSubTree_(key, data, this->RootRef());
}


template<class Key, class Value>
AVLNode<Key, Value>* AVLTree<Key, Value>::InsertBalance_(stack<AVLNode<Key, Value>*>& AVL_node_stack) {
    AVLNode<Key, Value>* cur_parent_node = NULL;

    while (AVL_node_stack.empty() == false) {

        // 获取双亲结点
        cur_parent_node = AVL_node_stack.top();
        AVL_node_stack.pop();

        cur_parent_node->UpdateBalanceFactor();

        // 第1种情况, 平衡退出
        if (cur_parent_node->GetBalanceFactor() == AVLNode<Key, Value>::BALANCED) {
            break;
        }

        // 第2种情况, |平衡因子| = 1
        if (cur_parent_node->GetBalanceFactor() == AVLNode<Key, Value>::RIGHT_HIGHER_1 ||
            cur_parent_node->GetBalanceFactor() == AVLNode<Key, Value>::LEFT_HIGHER_1) {
            // 不做操作, 继续遍历
        } else { // 第3种情况, |平衡因子| = 2
            this->Balance_(cur_parent_node);

            break; // cur_parent_node调整后height没有变化, 因此无需再向上遍历执行操作
        }

        cur_parent_node->UpdateHeight();
    }

    return cur_parent_node;
}


template<class Key, class Value>
AVLNode<Key, Value>* AVLTree<Key, Value>::RemoveBalance_(stack<AVLNode<Key, Value>*>& AVL_node_stack) {

    AVLNode<Key, Value>* cur_parent_node = NULL;

    while (!AVL_node_stack.empty()) {

        // 获取双亲结点
        cur_parent_node = AVL_node_stack.top();
        AVL_node_stack.pop();

        int grand_parent_direction;
        if (!AVL_node_stack.empty()) {
            AVLNode<Key, Value>* cur_grand_node = AVL_node_stack.top();
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
            AVLNode<Key, Value>* cur_grand_parent_node = AVL_node_stack.top();  // grand结点需要更新孩子结点
            if (grand_parent_direction == -1) {
                cur_grand_parent_node->SetLeftChild(cur_parent_node);
            } else {
                cur_grand_parent_node->SetRightChild(cur_parent_node);
            }
        }
    }

    return cur_parent_node;
}


template<class Key, class Value>
void AVLTree<Key, Value>::Balance_(AVLNode<Key, Value>*& node) {
    if (node->GetBalanceFactor() == AVLNode<Key, Value>::RIGHT_HIGHER_2) { // 两个结点的平衡因子同号, 单旋转
        if (node->RightChild()->GetBalanceFactor() != AVLNode<Key, Value>::LEFT_HIGHER_1) {
            this->LeftRotate_(node); // 左单旋转
        } else {
            this->RightLeftRotate_(node); // 右左旋转
        }
    } else if (node->GetBalanceFactor() == AVLNode<Key, Value>::LEFT_HIGHER_2) {
        if (node->LeftChild()->GetBalanceFactor() != AVLNode<Key, Value>::RIGHT_HIGHER_1) {
            this->RightRotate_(node);
        } else {
            this->LeftRightRotate_(node);
        }
    }
}


/**
 * @brief 平衡树子树插入(CyberDash实现版本)
 * @tparam Value 数据项模板类型
 * @tparam Key 关键码模板类型
 * @param value 数据项
 * @param key 关键码
 * @param sub_tree_root 子树根节点
 * @return 是否插入成功
 * @note
 * 1. 首先找到插入位置, 并且使用栈保存
 * 2. 分3种情况, 进行平衡化
 * 3. 平衡化结束后的收尾工作
 */
template<class Key, class Value>
bool AVLTree<Key, Value>::InsertInSubTree_(Key key, Value value, AVLNode<Key, Value>*& sub_tree_root) {

    stack<AVLNode<Key, Value>*> AVL_node_stack;

    //! 获取插入位置, 调整栈
    bool res = LocateInsertPositionAndInitStack(key, sub_tree_root, AVL_node_stack);
    if (!res) {
        return res;
    }

    AVLNode<Key, Value>* insert_node = new AVLNode<Key, Value>(key, value);
    /* error handler */

    // 空树, 新结点成为根节点, 并返回
    if (AVL_node_stack.empty()) {
        sub_tree_root = insert_node;
        return true;
    }

    AVLNode<Key, Value>* cur_parent_node = AVL_node_stack.top();

    if (key < cur_parent_node->GetKey()) {
        cur_parent_node->SetLeftChild(insert_node);
    } else {
        cur_parent_node->SetRightChild(insert_node);
    }

    AVLNode<Key, Value>* balanced_node = this->InsertBalance_( AVL_node_stack);

    // 已经完成平衡化的树, 完成最后处理
    if (AVL_node_stack.empty() == true) {
        sub_tree_root = balanced_node;
    } else {
        AVLNode<Key, Value>* stack_top_node = AVL_node_stack.top();
        if (stack_top_node->GetKey() > balanced_node->GetKey()) {
            stack_top_node->SetLeftChild(balanced_node);
        } else {
            stack_top_node->SetRightChild(balanced_node);
        }
    }

    return true;
}


/*!
 * 定位删除结点位置并初始化队列
 * @tparam Value 数据项模板参数
 * @tparam Key 键模板参数
 * @param key 键值
 * @param sub_tree_root 子树根节点
 * @param AVL_node_stack AVL结点栈
 * @return 待删除结点的指针
 * @note
 * 函数执行完后:
 *     1. 返回待删除结点的指针, 如果没有找到则返回NULL
 *     2. 待删除结点的祖先节点进入队列
 */
template<class Key, class Value>
AVLNode<Key, Value>* AVLTree<Key, Value>::LocateDeleteNodeAndInitStack(Key key,
                                                                       AVLNode<Key, Value>* sub_tree_root,
                                                                       stack<AVLNode<Key, Value>*>& AVL_node_stack)
{
    AVLNode<Key, Value>* cur_node = sub_tree_root;  // 遍历结点

    // 使用key寻找删除结点的位置,
    // 并将该结点的所有祖先结点插入队列
    while (cur_node != NULL) {

        // 找到等于key的结点, 跳出循环
        if (key == cur_node->GetKey()) {
            break;
        }

        // cur_node入栈
        AVL_node_stack.push(cur_node);

        if (key < cur_node->GetKey()) {
            cur_node = cur_node->LeftChild();
        } else {
            cur_node = cur_node->RightChild();
        }
    }

    return cur_node;
}


template<class Key, class Value>
// AVLNode<Key, Value>* AVLTree<Key, Value>::LocateInsertPositionAndInitStack(
bool AVLTree<Key, Value>::LocateInsertPositionAndInitStack(
    Key key,
    AVLNode<Key, Value>* sub_tree_root,
    stack<AVLNode<Key, Value>*>& AVL_node_stack)
{
    AVLNode<Key, Value>* cur_node = sub_tree_root;

    // 寻找插入位置
    while (cur_node != NULL) {
        // 找到等于key的结点, 无法插入
        if (key == cur_node->GetKey()) {
            // return NULL;
            return false;
        }

        AVL_node_stack.push(cur_node);

        if (key < cur_node->GetKey()) {
            cur_node = cur_node->LeftChild();
        } else {
            cur_node = cur_node->RightChild();
        }
    }

    return true;
}


/**
 * @brief 在子树中, 使用关键码进行搜索
 * @tparam Value 数据项模板类型
 * @tparam Key 关键码模板类型
 * @param key 关键码
 * @param sub_tree_root 子树根节点
 * @return 搜索结果
 * @note
 * 1. 如果子树根节点为NULL, 返回NULL
 * 2. 使用当前遍历节点的key, 与参数key作比较, 分别进行递归和返回搜索结果(终止递归)
 */
template <class Key, class Value>
AVLNode<Key, Value>* AVLTree<Key, Value>::SearchInSubTree_(Key key, AVLNode<Key, Value>* sub_tree_root) {
    if (sub_tree_root == NULL) {
        return NULL;
    }

    Key cur_key = sub_tree_root->GetKey();

    if (key < cur_key) {
        return SearchInSubTree_(key, sub_tree_root->LeftChild());
    } else if (key > cur_key) {
        return SearchInSubTree_(key, sub_tree_root->RightChild());
    }

    return sub_tree_root;
}


/**
 * @brief 平衡树子树删除节点(CyberDash实现版本)
 * @tparam Value 数据项模板类型
 * @tparam Key 关键码模板类型
 * @param sub_tree_root 子树根节点
 * @param key 待删除关键码
 * @return
 */
template<class Key, class Value>
bool AVLTree<Key, Value>::RemoveInSubTree_(AVLNode<Key, Value>*& sub_tree_root, Key key) {

    stack<AVLNode<Key, Value>*> AVL_node_stack;

    AVLNode<Key, Value>* delete_node = LocateDeleteNodeAndInitStack(key, sub_tree_root, AVL_node_stack);
    if (delete_node == NULL) {
        return false; // 未找到删除结点
    }

    // 此时定位到delete_node, delete_node之前的所有祖先结点, 都已经入栈

    AVLNode<Key, Value>* delete_node_predecessor = NULL;
    // 结点有两个子女, 在左子树找到delete_node的直接前驱
    if (delete_node->LeftChild() != NULL  && delete_node->RightChild() != NULL ) {
        AVL_node_stack.push(delete_node); // 将待删除节点入stack

        delete_node_predecessor = delete_node->LeftChild();
        while (delete_node_predecessor->RightChild() != NULL) {
            AVL_node_stack.push(delete_node_predecessor);
            delete_node_predecessor = delete_node_predecessor->RightChild();
        }

        // 将被删除结点的前驱结点的值赋给被删除结点
        delete_node->SetKey(delete_node_predecessor->GetKey());
        delete_node->SetValue(delete_node_predecessor->GetValue());

        // 将前驱结点作为待删除结点
        delete_node = delete_node_predecessor;

    } else if (delete_node->LeftChild() != NULL) {  // 结点只有左孩子结点(由于平衡特性, 此时此左孩子必为叶子), 则左孩子结点为删除结点
        delete_node_predecessor = delete_node->LeftChild();

        // 将被删除结点的前驱结点的值赋给被删除结点
        delete_node->SetKey(delete_node_predecessor->GetKey());
        delete_node->SetValue(delete_node_predecessor->GetValue());
        AVL_node_stack.push(delete_node); // 将待删除节点入stack

        // 将前驱结点作为待删除结点
        delete_node = delete_node_predecessor;
    }
    else if (delete_node->RightChild() != NULL) {  // 结点只有右孩子结点(由于平衡特性, 此时此右孩子必为叶子), 则右孩子结点为删除结点
        delete_node_predecessor = delete_node->RightChild();

        // 将被删除结点的前驱结点的值赋给被删除结点
        delete_node->SetKey(delete_node_predecessor->GetKey());
        delete_node->SetValue(delete_node_predecessor->GetValue());
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
        AVLNode<Key, Value>* delete_node_parent = AVL_node_stack.top();

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

        AVLNode<Key, Value>* balance_node = RemoveBalance_(AVL_node_stack);

        // 已经完成平衡化的树, 完成最后处理
        if (AVL_node_stack.empty() == true) {
            sub_tree_root = balance_node;
        } else {
            AVLNode<Key, Value>* stack_top_node = AVL_node_stack.top();
            if (stack_top_node->GetKey() > balance_node->GetKey()) {
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
 * @tparam Value
 * @tparam Key
 * @param sub_tree_root
 * @param visit
 */
template <class Key, class Value>
void AVLTree<Key, Value>::PrintSubTreeRecursive_(
    AVLNode<Key, Value>* sub_tree_root,
    void (*visit)(AVLNode<Key, Value>*))
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


template<class Key, class Value>
void AVLTree<Key, Value>::Print(void (*visit)(AVLNode<Key, Value>*)) {
    this->PrintSubTreeRecursive_((AVLNode<Key, Value> *) this->root_node_, visit); cout << endl;
}


template<class Key, class Value>
bool AVLTree<Key, Value>::Remove(Key key) {
    return this->RemoveInSubTree_(this->RootRef(), key);
}


template <class Key, class Value>
AVLNode<Key, Value>* AVLTree<Key, Value>::MinInSubTree_(AVLNode<Key, Value>* sub_tree_root) const {

    if (sub_tree_root == NULL) {
        return NULL;
    }

    AVLNode<Key, Value>* cur_node = sub_tree_root;

    while (cur_node->LeftChild() != NULL) {
        cur_node = cur_node->LeftChild();
    }

    return cur_node;
}


template<class Key, class Value>
Value AVLTree<Key, Value>::Max() {
    AVLNode<Key, Value>* root_node = this->root_node_;
    AVLNode<Key, Value>* max_node = this->MaxInSubTreeRecursive_(this->Root());
    return max_node->GetValue();
}


/**
 * @brief 子树中关键码最大项
 * @tparam Value 数据项模板类型
 * @tparam Key 关键码模板类型
 * @param sub_tree_root 子树根节点
 * @return 关键码最大项
 * @note
 * 右孩子节点迭代
 */
template <class Key, class Value>
AVLNode<Key, Value>* AVLTree<Key, Value>::MaxInSubTreeRecursive_(AVLNode<Key, Value>* sub_tree_root) const {

    if (sub_tree_root == NULL) {
        return NULL;
    }

    AVLNode<Key, Value>* cur_node = sub_tree_root;
    while (cur_node->RightChild() != NULL) {
        cur_node = cur_node->RightChild();
    }

    return cur_node;
}


template<class Key, class Value>
Value AVLTree<Key, Value>::Min() {
    AVLNode<Key, Value>* max_node = this->MinInSubTree_(this->Root());
    return max_node->GetValue();
}


template<class Key, class Value>
int AVLTree<Key, Value>::SubTreeHeight_(AVLNode<Key, Value>* sub_tree_root) {
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
