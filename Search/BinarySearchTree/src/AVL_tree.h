//
// Created by cyberdash@163.com on 2021/7/5.
//

#ifndef CYBER_DASH_AVL_TREE_H
#define CYBER_DASH_AVL_TREE_H


#include "binary_search_tree.h"
#include "stack"


template<class Value, class Key>
class AVLNode : public BSTNode<Value, Key> {
public:
    AVLNode(): left_child_(NULL), right_child_(NULL), balance_factor_(0) {}
    AVLNode(const Value& value, const Key& key) :
        value_(value), key_(key), left_child_(NULL), right_child_(NULL), balance_factor_(0) {}
    AVLNode(Value value, Key key, AVLNode<Value, Key>* left_child, AVLNode<Value, Key>* right_child) :
        value_(value), key_(key), left_child_(left_child), right_child_(right_child), balance_factor_(0) {}

    void SetLeftChild(AVLNode<Value, Key>* node) { this->left_child_ = node; }
    AVLNode<Value, Key>*& LeftChild() { return this->left_child_; };

    void SetRightChild(AVLNode<Value, Key>* node) { this->right_child_ = node; }
    AVLNode<Value, Key>*& RightChild() { return this->right_child_; };

    void SetValue(const Value& value) { this->value_ = value; }
    Value GetValue() { return this->value_; }

    void SetKey(const Key& key) { this->key_ = key; }
    Key GetKey() { return this->key_; }

    void SetBalanceFactor(int balance_factor) { this->balance_factor_ = balance_factor; }
    int GetBalanceFactor() { return this->balance_factor_; }

    static const int RIGHT_HIGHER_2 = 2;    //!< 左子树比右子树矮2
    static const int RIGHT_HIGHER_1 = 1;    //!< 左子树比右子树矮1
    static const int BALANCED = 0;          //!< 左右相等
    static const int LEFT_HIGHER_1 = -1;    //!< 左子树比右子树高1
    static const int LEFT_HIGHER_2 = -2;    //!< 左子树比右子树高2

protected:
    AVLNode<Value, Key>* left_child_;
    AVLNode<Value, Key>* right_child_;

    Value value_;
    Key key_;

    int balance_factor_;
};


template<class Value, class Key>
class AVLTree : public BST<Value, Key> {
public:
    AVLTree() : root_node_(NULL) {}
    AVLNode<Value, Key>*& RootRef() { return (AVLNode<Value, Key>*&)this->root_node_; }
    AVLNode<Value, Key>* Root() { return (AVLNode<Value, Key>*)this->root_node_; }

    bool Insert(Value data, Key key);
    bool InsertByCyberDash(Value data, Key key);
    bool Remove(Key key);
    AVLNode<Value, Key>* Search(Key key) { return this->SearchInSubTreeRecursive_(key, this->root_node_); }
    int Height() { return this->SubTreeHeight_(this->root_node_); }
    //
    Value Max();
    Value Min();
    void Print(void (*visit)(AVLNode<Value, Key>*));

    static AVLNode<Value, Key>* GetInsertNodePtrAndInitStack(
        Key key,
        AVLNode<Value, Key>* node,
        stack<AVLNode<Value, Key>*>& AVL_node_stack);

    static AVLNode<Value, Key>* GetDeleteNodePtrAndInitStack(
        Key key,
        AVLNode<Value, Key>* node,
        stack<AVLNode<Value, Key>*>& AVL_node_stack);

protected:
    AVLNode<Value, Key>* SearchInSubTreeRecursive_(Key key, AVLNode<Value, Key>* sub_tree_root);
    bool InsertInSubTree_(Value value, Key key, AVLNode<Value, Key>*& sub_tree_root);
    // 平衡树子树插入(CyberDash实现版本)
    bool InsertInSubTreeByCyberDash_(Value value, Key key, AVLNode<Value, Key>*& sub_tree_root);
    bool RemoveInSubTreeRecursive_(AVLNode<Value, Key>*& sub_tree_root, Key key);

    // 左单旋转(Rotation Left), 图7.15(a)的情形
    void RotateLeft_(AVLNode<Value, Key>*& node);
    // 右单旋转(Rotation Right), 图7.16(a)的情形
    void RotateRight_(AVLNode<Value, Key>*& node);
    // 先左后右双旋转(Rotation Left Right), 图7.17(a)的情形
    void RotateLeftRight_(AVLNode<Value, Key>*& node);
    // 先右后左双旋转(Rotation Right Left), 图7.18(a)的情形
    void RotateRightLeft_(AVLNode<Value, Key>*& node);

    // 子树中关键码最小项
    AVLNode<Value, Key>* MinInSubTree_(AVLNode<Value, Key>* sub_tree_root) const;

    // 子树中关键码最大项
    AVLNode<Value, Key>* MaxInSubTreeRecursive_(AVLNode<Value, Key>* sub_tree_root) const;
    // AVL子树的高度
    int SubTreeHeight_(AVLNode<Value, Key>* sub_tree_root);

    void PrintSubTreeRecursive_(AVLNode<Value, Key>* sub_tree_root, void (*visit)(AVLNode<Value, Key>*));

    AVLNode<Value, Key>* root_node_; // 根节点
};


/**
 * 左单旋转(Rotation Left), 图7.15(a)的情形
 * @tparam Value 搜索结果(数据)模板类型
 * @tparam Key 关键码模板类型
 * @param node AVL树节点指针的引用
 */
template<class Value, class Key>
void AVLTree<Value, Key>::RotateLeft_(AVLNode<Value, Key>*& node) {

    // 图7.15(b)
    AVLNode<Value, Key>* sub_left_node = node;
    node = sub_left_node->RightChild();

    // 图7.15(c)
    sub_left_node->SetRightChild(node->LeftChild());
    node->SetLeftChild(sub_left_node);

    // 调整平衡因子
    node->SetBalanceFactor(0);
    sub_left_node->SetBalanceFactor(0);
}


/**
 * 右单旋转(Rotation Right), 图7.16(a)的情形
 * @tparam Value 搜索结果(数据)模板类型
 * @tparam Key 关键码模板类型
 * @param node AVL树节点指针的引用
 */
template<class Value, class Key>
void AVLTree<Value, Key>::RotateRight_(AVLNode<Value, Key>*& node) {

    // 图7.16(b)
    AVLNode<Value, Key>* sub_right_node = node;
    node = sub_right_node->LeftChild();

    // 图7.16(c)
    sub_right_node->SetLeftChild(node->RightChild());
    node->SetRightChild(sub_right_node);

    // 调整平衡因子
    node->SetBalanceFactor(0);
    sub_right_node->SetBalanceFactor(0);
}


template<class Value, class Key>
void AVLTree<Value, Key>::RotateLeftRight_(AVLNode<Value, Key>*& node) {

    // 图7.17(b)
    AVLNode<Value, Key>* sub_right_node = node;
    AVLNode<Value, Key>* sub_left_node = sub_right_node->LeftChild();
    node = sub_left_node->RightChild();

    // 图7.17(c)
    sub_left_node->SetRightChild(node->LeftChild()); // node成为新根前, 甩掉它的左子树
    node->SetLeftChild(sub_left_node); // 左单旋转, node成为新根

    if (node->GetBalanceFactor() <= AVLNode<Value, Key>::BALANCED) {
        sub_left_node->SetBalanceFactor(AVLNode<Value, Key>::BALANCED);
    } else {
        sub_left_node->SetBalanceFactor(AVLNode<Value, Key>::LEFT_HIGHER_1);
    }

    sub_right_node->SetLeftChild(node->RightChild()); // node成为新根之前, 甩掉它的右子树
    node->SetRightChild(sub_right_node); // 右单旋转, node成为新根

    if (node->GetBalanceFactor() == AVLNode<Value, Key>::LEFT_HIGHER_1) {
        sub_right_node->SetBalanceFactor(AVLNode<Value, Key>::RIGHT_HIGHER_1);
    } else {
        sub_right_node->SetBalanceFactor(AVLNode<Value, Key>::BALANCED);
    }

    node->SetBalanceFactor(AVLNode<Value, Key>::BALANCED);
}


template<class Value, class Key>
void AVLTree<Value, Key>::RotateRightLeft_(AVLNode<Value, Key>*& node) {

    // 图7.18(b)
    AVLNode<Value, Key>* sub_left_node = node;
    AVLNode<Value, Key>* sub_right_node = sub_left_node->RightChild();
    node = sub_right_node->LeftChild();

    // 图7.18(c)
    sub_right_node->SetLeftChild(node->RightChild()); // node成为新根之前, 甩掉它的右子树
    node->SetRightChild(sub_right_node); // 右单旋转, node成为新根

    if (node->GetBalanceFactor() >= AVLNode<Value, Key>::BALANCED) {
        sub_right_node->SetBalanceFactor(AVLNode<Value, Key>::BALANCED);
    } else {
        sub_right_node->SetBalanceFactor(AVLNode<Value, Key>::RIGHT_HIGHER_1);
    }

    sub_left_node->SetRightChild(node->LeftChild()); // node成为新根前, 甩掉它的左子树
    node->SetLeftChild(sub_left_node); // 左单旋转, node成为新根

    if (node->GetBalanceFactor() == AVLNode<Value, Key>::RIGHT_HIGHER_1) {
        sub_left_node->SetBalanceFactor(AVLNode<Value, Key>::LEFT_HIGHER_1);
    } else {
        sub_left_node->SetBalanceFactor(AVLNode<Value, Key>::BALANCED);
    }

    node->SetBalanceFactor(AVLNode<Value, Key>::BALANCED);
}


template<class Value, class Key>
bool AVLTree<Value, Key>::Insert(Value data, Key key) {
    return this->InsertInSubTree_(data, key, this->RootRef());
}


template<class Value, class Key>
bool AVLTree<Value, Key>::InsertByCyberDash(Value data, Key key) {
    return this->InsertInSubTreeByCyberDash_(data, key, this->RootRef());
}


/**
 * @brief 子树中插入节点
 * @tparam Value 数据项模板类型
 * @tparam Key 关键码模板类型
 * @param value 数据项
 * @param key 关键码
 * @param sub_tree_root 子树根节点指针
 * @return 是否插入成功
 * @note
 * 如果根节点指针为NULL, 则创建节点
 * 判断插入关键码与子树根节点关键码的大小关系, 在左子树or右子树做插入操作(递归)
 * 如果关键码相同, 则返回false
 */
template<class Value, class Key>
bool AVLTree<Value, Key>::InsertInSubTree_(Value value, Key key, AVLNode<Value, Key>*& sub_tree_root) {

    AVLNode<Value, Key>* cur_stack_node = NULL;
    AVLNode<Value, Key>* cur_node = sub_tree_root;

    stack<AVLNode<Value, Key>*> AVL_node_stack;

    // 寻找插入位置
    while (cur_node != NULL) {
        // 找到等于key的结点, 无法插入, (原书使用value)
        if (key == cur_node->GetKey()) {
            return false;
        }

        cur_stack_node = cur_node;
        AVL_node_stack.push(cur_stack_node);

        if (key < cur_node->GetKey()) {
            cur_node = cur_node->LeftChild();
        } else {
            cur_node = cur_node->RightChild();
        }
    }

    cur_node = new AVLNode<Value, Key>(value, key);
    /* error handler */

    // 空树, 新结点成为根节点
    if (cur_stack_node == NULL) {
        sub_tree_root = cur_node;
        return true;
    }

    if (key < cur_stack_node->GetKey()) {
        cur_stack_node->SetLeftChild(cur_node);
    } else {
        cur_stack_node->SetRightChild(cur_node);
    }

    // 重新平衡化
    while (AVL_node_stack.empty() == false) {
        cur_stack_node = AVL_node_stack.top();
        AVL_node_stack.pop();

        if (cur_node == cur_stack_node->LeftChild()) {
            cur_stack_node->SetBalanceFactor(cur_stack_node->GetBalanceFactor() - 1);
        } else {
            cur_stack_node->SetBalanceFactor(cur_stack_node->GetBalanceFactor() + 1);
        }

        // 第1种情况, 平衡退出
        if (cur_stack_node->GetBalanceFactor() == 0) {
            break;
        }

        // 第2种情况, |平衡因子| = 1
        if (cur_stack_node->GetBalanceFactor() == AVLNode<Value, Key>::RIGHT_HIGHER_1 ||
            cur_stack_node->GetBalanceFactor() == AVLNode<Value, Key>::LEFT_HIGHER_1)
        {
            cur_node = cur_stack_node;
        } else { // 第3种情况, |bf| = 2
            int stack_node_rotate_flag = (cur_stack_node->GetBalanceFactor() < AVLNode<Value, Key>::BALANCED) ?
                                            AVLNode<Value, Key>::LEFT_HIGHER_1 : AVLNode<Value, Key>::RIGHT_HIGHER_1;
            if (cur_node->GetBalanceFactor() == stack_node_rotate_flag) { // 两个结点的平衡因子同号, 单旋转
                if (stack_node_rotate_flag == AVLNode<Value, Key>::LEFT_HIGHER_1) {
                    this->RotateRight_(cur_stack_node); // 右单旋转
                } else {
                    this->RotateLeft_(cur_stack_node); // 左单旋转
                }
            } else { // 两个结点的平衡因子反号, 双旋转
                if (stack_node_rotate_flag == AVLNode<Value, Key>::LEFT_HIGHER_1) {
                    this->RotateLeftRight_(cur_stack_node);
                } else {
                    this->RotateRightLeft_(cur_stack_node);
                }
            }

            break; // 不再向上调整
        }
    }

    if (AVL_node_stack.empty() == true) {
        sub_tree_root = cur_stack_node;
    } else {
        AVLNode<Value, Key>* stack_top_node = AVL_node_stack.top();
        if (stack_top_node->GetKey() > cur_stack_node->GetKey()) {
            stack_top_node->SetLeftChild(cur_stack_node);
        } else {
            stack_top_node->SetRightChild(cur_stack_node);
        }
    }

    return true;
}


template<class Value, class Key>
AVLNode<Value, Key>* AVLTree<Value, Key>::GetInsertNodePtrAndInitStack(
    Key key,
    AVLNode<Value, Key>* node,
    stack<AVLNode<Value, Key>*>& AVL_node_stack)
{

    AVLNode<Value, Key>* cur_node = node;

    // 寻找插入位置
    while (cur_node != NULL) {
        // 找到等于key的结点, 无法插入
        if (key == cur_node->GetKey()) {
            return NULL;
        }

        AVL_node_stack.push(cur_node);

        if (key < cur_node->GetKey()) {
            cur_node = cur_node->LeftChild();
        } else {
            cur_node = cur_node->RightChild();
        }
    }

    return cur_node;
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
template<class Value, class Key>
bool AVLTree<Value, Key>::InsertInSubTreeByCyberDash_(Value value, Key key, AVLNode<Value, Key>*& sub_tree_root) {

    stack<AVLNode<Value, Key>* > AVL_node_stack;

    //! 获取插入位置, 调整栈
    AVLNode<Value, Key>* insert_node = GetInsertNodePtrAndInitStack(key, sub_tree_root, AVL_node_stack);

    insert_node = new AVLNode<Value, Key>(value, key);
    /* error handler */

    // 空树, 新结点成为根节点, 并返回
    if (AVL_node_stack.empty()) {
        sub_tree_root = insert_node;
        return true;
    }

    AVLNode<Value, Key>* stack_node = AVL_node_stack.top();

    if (key < stack_node->GetKey()) {
        stack_node->SetLeftChild(insert_node);
    } else {
        stack_node->SetRightChild(insert_node);
    }

    AVLNode<Value, Key>* stack_node_child = insert_node;

    // 重新平衡化
    while (AVL_node_stack.empty() == false) {

        // 栈顶出栈
        stack_node = AVL_node_stack.top();
        AVL_node_stack.pop();

        // 调整平衡因子
        if (stack_node_child == stack_node->LeftChild()) {
            stack_node->SetBalanceFactor(stack_node->GetBalanceFactor() - 1);
        } else {
            stack_node->SetBalanceFactor(stack_node->GetBalanceFactor() + 1);
        }

        // 第1种情况, 平衡退出
        if (stack_node->GetBalanceFactor() == AVLNode<Value, Key>::BALANCED) {
            break;
        }

        // 第2种情况, |平衡因子| = 1
        if (stack_node->GetBalanceFactor() == AVLNode<Value, Key>::RIGHT_HIGHER_1 ||
            stack_node->GetBalanceFactor() == AVLNode<Value, Key>::LEFT_HIGHER_1) {
            stack_node_child = stack_node;
        } else { // 第3种情况, |bf| = 2
            int stack_node_rotate_flag = (stack_node->GetBalanceFactor() < 0) ?
                AVLNode<Value, Key>::LEFT_HIGHER_1 : AVLNode<Value, Key>::RIGHT_HIGHER_1;

            if (stack_node_child->GetBalanceFactor() == stack_node_rotate_flag) { // 两个结点的平衡因子同号, 单旋转
                if (stack_node_rotate_flag == AVLNode<Value, Key>::LEFT_HIGHER_1) {
                    this->RotateRight_(stack_node); // 右单旋转
                } else {
                    this->RotateLeft_(stack_node); // 左单旋转
                }
            } else { // 两个结点的平衡因子反号, 双旋转
                if (stack_node_rotate_flag == AVLNode<Value, Key>::LEFT_HIGHER_1) {
                    this->RotateLeftRight_(stack_node);
                } else {
                    this->RotateRightLeft_(stack_node);
                }
            }

            break; // 不再向上调整
        }
    }

    // 已经完成平衡化的树, 完成最后处理
    if (AVL_node_stack.empty() == true) {
        sub_tree_root = stack_node;
    } else {
        AVLNode<Value, Key>* stack_top_node = AVL_node_stack.top();
        if (stack_top_node->GetKey() > stack_node->GetKey()) {
            stack_top_node->SetLeftChild(stack_node);
        } else {
            stack_top_node->SetRightChild(stack_node);
        }
    }

    return true;
}


template<class Value, class Key>
AVLNode<Value, Key>* AVLTree<Value, Key>::GetDeleteNodePtrAndInitStack(Key key,
    AVLNode<Value, Key>* node,
    stack<AVLNode<Value, Key>*>& AVL_node_stack)
{
    AVLNode<Value, Key>* cur_node = node;

    // 寻找删除位置
    while (cur_node != NULL) {
        // 找到等于key的结点, 无法插入
        if (key == cur_node->GetKey()) {
            break;
        }

        AVL_node_stack.push(cur_node);

        if (key < cur_node->GetKey()) {
            cur_node = cur_node->LeftChild();
        } else {
            cur_node = cur_node->RightChild();
        }
    }

    return cur_node;
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
template <class Value, class Key>
AVLNode<Value, Key>* AVLTree<Value, Key>::SearchInSubTreeRecursive_(Key key, AVLNode<Value, Key>* sub_tree_root) {
    if (sub_tree_root == NULL) {
        return NULL;
    }

    Key cur_key = sub_tree_root->GetKey();

    if (key < cur_key) {
        return SearchInSubTreeRecursive_(key, sub_tree_root->LeftChild());
    } else if (key > cur_key) {
        return SearchInSubTreeRecursive_(key, sub_tree_root->RightChild());
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
template<class Value, class Key>
bool AVLTree<Value, Key>::RemoveInSubTreeRecursive_(AVLNode<Value, Key>*& sub_tree_root, Key key) {
    AVLNode<Value, Key>* cur_node_pre = NULL;

    stack<AVLNode<Value, Key>*> AVL_node_stack;

    AVLNode<Value, Key>* delete_node = GetDeleteNodePtrAndInitStack(key, sub_tree_root, AVL_node_stack);
    if (delete_node == NULL) {
        return false; // 未找到删除结点
    }

    if (delete_node->LeftChild() != NULL && delete_node->RightChild() != NULL) {
        AVL_node_stack.push(delete_node); // 将待删除节点入stack

        cur_node_pre = delete_node->LeftChild();
        while (cur_node_pre->RightChild() != NULL) {
            AVL_node_stack.push(cur_node_pre);
            cur_node_pre = cur_node_pre->RightChild();
        }

        delete_node->SetKey(cur_node_pre->GetKey());
        delete_node->SetValue(cur_node_pre->GetValue());

        delete_node = cur_node_pre;
    }

    AVLNode<Value, Key>* child_of_delete_node = NULL; // 被删除节点的孩子节点

    // 找到此时的待删除节点的一个孩子节点, 用作连接
    if (delete_node->LeftChild() != NULL) {
        child_of_delete_node = delete_node->LeftChild();
    } else {
        child_of_delete_node = delete_node->RightChild();
    }

    if (AVL_node_stack.empty() == true) { // 删除的是根节点
        sub_tree_root = child_of_delete_node;
    } else {
        AVLNode<Value, Key>* cur_stack_node = AVL_node_stack.top();

        if (cur_stack_node->LeftChild() == delete_node) { // 被删除节点是cur_stack_node的左孩子
            cur_stack_node->SetLeftChild(child_of_delete_node); // 连接
        } else { // 被删除节点是cur_stack_node的右孩子
            cur_stack_node->SetRightChild(child_of_delete_node); // 连接
        }

        AVLNode<Value, Key>* parent_node;

        // 重新平衡化
        while (AVL_node_stack.empty() == false) {

            AVLNode<Value, Key>* grand_parent_node = NULL;
            parent_node = AVL_node_stack.top();
            AVL_node_stack.pop();

            int grand_parent_direction;
            int parent_direction;

            if (parent_node->RightChild() == child_of_delete_node) {
                parent_node->SetBalanceFactor(parent_node->GetBalanceFactor() - 1);
            } else {
                parent_node->SetBalanceFactor(parent_node->GetBalanceFactor() + 1);
            }

            if (AVL_node_stack.empty() == false) {
                grand_parent_node = AVL_node_stack.top();
                AVL_node_stack.pop();

                grand_parent_direction = (grand_parent_node->LeftChild() == parent_node)
                    ? AVLNode<Value, Key>::LEFT_HIGHER_1 : AVLNode<Value, Key>::RIGHT_HIGHER_1;
            } else {
                grand_parent_direction = AVLNode<Value, Key>::LEFT_HIGHER_1;
            }

            // 图7.20
            if (parent_node->GetBalanceFactor() == AVLNode<Value, Key>::RIGHT_HIGHER_1 ||
                parent_node->GetBalanceFactor() == AVLNode<Value, Key>::LEFT_HIGHER_1)
            {
                break;
            }

            if (parent_node->GetBalanceFactor() != AVLNode<Value, Key>::BALANCED) { // |bf| = 2
                if (parent_node->GetBalanceFactor() < AVLNode<Value, Key>::BALANCED) {
                    parent_direction = AVLNode<Value, Key>::LEFT_HIGHER_1;
                    child_of_delete_node = parent_node->LeftChild();
                } else {
                    parent_direction = AVLNode<Value, Key>::RIGHT_HIGHER_1;
                    child_of_delete_node = parent_node->RightChild();
                }

                if (child_of_delete_node && child_of_delete_node->GetBalanceFactor() == AVLNode<Value, Key>::BALANCED) {
                    if (parent_direction == AVLNode<Value, Key>::LEFT_HIGHER_1) {
                        this->RotateRight_(parent_node);
                        parent_node->SetBalanceFactor(1);
                        parent_node->LeftChild()->SetBalanceFactor(AVLNode<Value, Key>::LEFT_HIGHER_1);
                    } else {
                        this->RotateLeft_(parent_node);
                        parent_node->SetBalanceFactor(AVLNode<Value, Key>::LEFT_HIGHER_1 );
                        parent_node->RightChild()->SetBalanceFactor(1);
                    }

                    break;
                }

                if (child_of_delete_node && child_of_delete_node->GetBalanceFactor() == parent_direction) { // 图7.23, 两节点平衡因子同号
                    if (parent_direction == AVLNode<Value, Key>::LEFT_HIGHER_1) {
                        this->RotateRight_(parent_node);
                    } else {
                        this->RotateLeft_(parent_node);
                    }
                } else { // 图7.24, 两节点平衡因子反号
                    if (parent_direction == AVLNode<Value, Key>::LEFT_HIGHER_1) {
                        this->RotateLeftRight_(parent_node);
                    } else {
                        this->RotateRightLeft_(parent_node);
                    }
                }


                if (grand_parent_node != NULL) { // todo: 新加, 不完全对


                // 旋转后, 新根与上层连接
                if (grand_parent_direction == AVLNode<Value, Key>::LEFT_HIGHER_1) {
                    grand_parent_node->SetLeftChild(parent_node);
                } else {
                    grand_parent_node->SetRightChild(parent_node);
                }


                }
            }

            child_of_delete_node = parent_node; // 图7.21, |bf| = 0
        }

        if (AVL_node_stack.empty() == true) {
            sub_tree_root = parent_node;
        }
    }

    delete delete_node;
    delete_node = NULL;

    return true;
}


/**
 * @brief 打印子树(递归)
 * @tparam Value
 * @tparam Key
 * @param sub_tree_root
 * @param visit
 */
template <class Value, class Key>
void AVLTree<Value, Key>::PrintSubTreeRecursive_(
    AVLNode<Value, Key>* sub_tree_root,
    void (*visit)(AVLNode<Value, Key>*))
{
    if (sub_tree_root == NULL) {
        return;
    }

    visit(sub_tree_root);

    cout << "(";

    PrintSubTreeRecursive_(sub_tree_root->LeftChild(), visit);

    cout << ",";

    PrintSubTreeRecursive_(sub_tree_root->RightChild(), visit);

    cout << ")";
}


template<class Value, class Key>
void AVLTree<Value, Key>::Print(void (*visit)(AVLNode<Value, Key>*)) {
    this->PrintSubTreeRecursive_((AVLNode<Value, Key> *) this->root_node_, visit); cout << endl;
    cout << endl;
}


template<class Value, class Key>
bool AVLTree<Value, Key>::Remove(Key key) {
    return this->RemoveInSubTreeRecursive_(this->RootRef(), key);
}


template <class Value, class Key>
AVLNode<Value, Key>* AVLTree<Value, Key>::MinInSubTree_(AVLNode<Value, Key>* sub_tree_root) const {

    if (sub_tree_root == NULL) {
        return NULL;
    }

    AVLNode<Value, Key>* cur_node = sub_tree_root;

    while (cur_node->LeftChild() != NULL) {
        cur_node = cur_node->LeftChild();
    }

    return cur_node;
}


template<class Value, class Key>
Value AVLTree<Value, Key>::Max() {
    AVLNode<Value, Key>* root_node = this->root_node_;
    AVLNode<Value, Key>* max_node = this->MaxInSubTreeRecursive_(this->Root());
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
template <class Value, class Key>
AVLNode<Value, Key>* AVLTree<Value, Key>::MaxInSubTreeRecursive_(AVLNode<Value, Key>* sub_tree_root) const {

    if (sub_tree_root == NULL) {
        return NULL;
    }

    AVLNode<Value, Key>* cur_node = sub_tree_root;
    while (cur_node->RightChild() != NULL) {
        cur_node = cur_node->RightChild();
    }

    return cur_node;
}


template<class Value, class Key>
Value AVLTree<Value, Key>::Min() {
    AVLNode<Value, Key>* max_node = this->MinInSubTree_(this->Root());
    return max_node->GetValue();
}


template<class Value, class Key>
int AVLTree<Value, Key>::SubTreeHeight_(AVLNode<Value, Key>* sub_tree_root) {
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
