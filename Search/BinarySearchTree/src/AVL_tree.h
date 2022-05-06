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
    AVLNode() :
        left_child_ptr_(NULL), right_child_ptr_(NULL), balance_factor(0) {}
    AVLNode(const Value& elem, const Key& key) :
        value_(elem), key_(key), left_child_ptr_(NULL), right_child_ptr_(NULL), balance_factor(0) {}
    AVLNode(Value elem, Key key, AVLNode<Value, Key>* left_child_ptr, AVLNode<Value, Key>* right_child_ptr) :
        value_(elem), key_(key), left_child_ptr_(left_child_ptr), right_child_ptr_(right_child_ptr), balance_factor(0) {}

    void SetLeftChildPtr(AVLNode<Value, Key>* node_ptr) { this->left_child_ptr_ = node_ptr; }
    void SetRightChildPtr(AVLNode<Value, Key>* node_ptr) { this->right_child_ptr_ = node_ptr; }

    void SetValue(const Value& elem) { this->value_ = elem; }
    Value GetValue() { return this->value_; }

    void SetKey(const Key& key) { this->key_ = key; }
    Key GetKey() { return this->key_; }

    AVLNode<Value, Key>*& LeftChildPtr() { return this->left_child_ptr_; };
    AVLNode<Value, Key>*& RightChildPtr() { return this->right_child_ptr_; };

    int balance_factor;

protected:

    AVLNode<Value, Key>* left_child_ptr_;
    AVLNode<Value, Key>* right_child_ptr_;

    Value value_;
    Key key_;
};


template<class Value, class Key>
class AVLTree : public BST<Value, Key> {
public:
    AVLTree() : root_node_ptr_(NULL) {}
    AVLNode<Value, Key>*& RootRef() { return (AVLNode<Value, Key>*&)this->root_node_ptr_; }
    AVLNode<Value, Key>* Root() { return (AVLNode<Value, Key>*)this->root_node_ptr_; }

    bool Insert(Value data, Key key);
    bool InsertByCyberDash(Value data, Key key);
    // bool Remove(Key key, Value& data) { return this->RemoveInSubTreeByCyberDash_(RootRef(), key); }
    bool RemoveByCyberDash(Key key);
    AVLNode<Value, Key>* Search(Key key) { return this->SearchInSubTree_(key, this->root_node_ptr_); }
    int Height() { return this->SubTreeHeight_(this->root_node_ptr_); }


    Value Max();
    Value Min();
    void PrintTree(void (*visit)(AVLNode<Value, Key>*));

    static AVLNode<Value, Key>* GetInsertNodePtrAndInitStack(Key key,
        AVLNode<Value, Key>* node_ptr,
        stack<AVLNode<Value, Key>*>& AVL_node_stack);

    static AVLNode<Value, Key>* GetDeleteNodePtrAndInitStack(Key key,
        AVLNode<Value, Key>* node_ptr,
        stack<AVLNode<Value, Key>*>& AVL_node_stack);

protected:
    AVLNode<Value, Key>* SearchInSubTree_(Key key, AVLNode<Value, Key>* sub_tree_root_ptr);
    bool InsertInSubTree_(Value elem, Key key, AVLNode<Value, Key>*& sub_tree_root_ptr);
    // 平衡树子树插入(CyberDash实现版本)
    bool InsertInSubTreeByCyberDash_(Value elem, Key key, AVLNode<Value, Key>*& sub_tree_root_ptr);
    bool RemoveInSubTreeByCyberDash_(AVLNode<Value, Key>*& sub_tree_root_ptr, Key key);

    // 左单旋转(Rotation Left), 图7.15(a)的情形
    void RotateLeft_(AVLNode<Value, Key>*& node_ptr);
    // 右单旋转(Rotation Right), 图7.16(a)的情形
    void RotateRight_(AVLNode<Value, Key>*& node_ptr);
    // 先左后右双旋转(Rotation Left Right), 图7.17(a)的情形
    void RotateLeftRight_(AVLNode<Value, Key>*& node_ptr);
    // 先右后左双旋转(Rotation Right Left), 图7.18(a)的情形
    void RotateRightLeft_(AVLNode<Value, Key>*& node_ptr);

    // 子树中关键码最小项
    AVLNode<Value, Key>* MinInSubTree_(AVLNode<Value, Key>* sub_tree_root_ptr) const;

    // 子树中关键码最大项
    AVLNode<Value, Key>* MaxInSubTree_(AVLNode<Value, Key>* sub_tree_root_ptr) const;
    // AVL子树的高度
    int SubTreeHeight_(AVLNode<Value, Key>* sub_tree_root_ptr);

    void PrintSubTree_(AVLNode<Value, Key>* sub_tree_root_ptr, void (*visit)(AVLNode<Value, Key>*));

    AVLNode<Value, Key>* root_node_ptr_; // 根节点
};


/**
 * 左单旋转(Rotation Left), 图7.15(a)的情形
 * @tparam Value 搜索结果(数据)模板类型
 * @tparam Key 关键码模板类型
 * @param node_ptr AVL树节点指针的引用
 */
template<class Value, class Key>
void AVLTree<Value, Key>::RotateLeft_(AVLNode<Value, Key>*& node_ptr) {

    // 图7.15(b)
    AVLNode<Value, Key>* sub_left_node_ptr = node_ptr;
    node_ptr = sub_left_node_ptr->RightChildPtr();

    // 图7.15(c)
    sub_left_node_ptr->SetRightChildPtr(node_ptr->LeftChildPtr());
    node_ptr->SetLeftChildPtr(sub_left_node_ptr);

    // 调整平衡因子
    node_ptr->balance_factor = 0;
    sub_left_node_ptr->balance_factor = 0;
}


/**
 * 右单旋转(Rotation Right), 图7.16(a)的情形
 * @tparam Value 搜索结果(数据)模板类型
 * @tparam Key 关键码模板类型
 * @param node_ptr AVL树节点指针的引用
 */
template<class Value, class Key>
void AVLTree<Value, Key>::RotateRight_(AVLNode<Value, Key>*& node_ptr) {

    // 图7.16(b)
    AVLNode<Value, Key>* sub_right_node_ptr = node_ptr;
    node_ptr = sub_right_node_ptr->LeftChildPtr();

    // 图7.16(c)
    sub_right_node_ptr->SetLeftChildPtr(node_ptr->RightChildPtr());
    node_ptr->SetRightChildPtr(sub_right_node_ptr);

    // 调整平衡因子
    node_ptr->balance_factor = 0;
    sub_right_node_ptr->balance_factor = 0;
}


template<class Value, class Key>
void AVLTree<Value, Key>::RotateLeftRight_(AVLNode<Value, Key>*& node_ptr) {

    // 图7.17(b)
    AVLNode<Value, Key>* sub_right_node_ptr = node_ptr;
    AVLNode<Value, Key>* sub_left_node_ptr = sub_right_node_ptr->LeftChildPtr();
    node_ptr = sub_left_node_ptr->RightChildPtr();

    // 图7.17(c)
    sub_left_node_ptr->SetRightChildPtr(node_ptr->LeftChildPtr()); // node_ptr成为新根前, 甩掉它的左子树
    node_ptr->SetLeftChildPtr(sub_left_node_ptr); // 左单旋转, node_ptr成为新根

    if (node_ptr->balance_factor <= 0) {
        sub_left_node_ptr->balance_factor = 0;
    }
    else {
        sub_left_node_ptr->balance_factor = -1;
    }

    sub_right_node_ptr->SetLeftChildPtr(node_ptr->RightChildPtr()); // node_ptr成为新根之前, 甩掉它的右子树
    node_ptr->SetRightChildPtr(sub_right_node_ptr); // 右单旋转, node_ptr成为新根

    if (node_ptr->balance_factor == -1) {
        sub_right_node_ptr->balance_factor = 1;
    }
    else {
        sub_right_node_ptr->balance_factor = 0;
    }

    node_ptr->balance_factor = 0;
}


template<class Value, class Key>
void AVLTree<Value, Key>::RotateRightLeft_(AVLNode<Value, Key>*& node_ptr) {

    // 图7.18(b)
    AVLNode<Value, Key>* sub_left_node_ptr = node_ptr;
    AVLNode<Value, Key>* sub_right_node_ptr = sub_left_node_ptr->RightChildPtr();
    node_ptr = sub_right_node_ptr->LeftChildPtr();

    // 图7.18(c)
    sub_right_node_ptr->SetLeftChildPtr(node_ptr->RightChildPtr()); // node_ptr成为新根之前, 甩掉它的右子树
    node_ptr->SetRightChildPtr(sub_right_node_ptr); // 右单旋转, node_ptr成为新根

    if (node_ptr->balance_factor >= 0) {
        sub_right_node_ptr->balance_factor = 0;
    }
    else {
        sub_right_node_ptr->balance_factor = 1;
    }

    sub_left_node_ptr->SetRightChildPtr(node_ptr->LeftChildPtr()); // node_ptr成为新根前, 甩掉它的左子树
    node_ptr->SetLeftChildPtr(sub_left_node_ptr); // 左单旋转, node_ptr成为新根

    if (node_ptr->balance_factor == 1) {
        sub_left_node_ptr->balance_factor = -1;
    }
    else {
        sub_left_node_ptr->balance_factor = 0;
    }

    node_ptr->balance_factor = 0;
}


template<class Value, class Key>
bool AVLTree<Value, Key>::Insert(Value data, Key key) {
    return this->InsertInSubTree_(data, key, (AVLNode<Value, Key>*&)this->root_node_ptr_);
}


template<class Value, class Key>
bool AVLTree<Value, Key>::InsertByCyberDash(Value data, Key key) {
    return this->InsertInSubTreeByCyberDash_(data, key, (AVLNode<Value, Key>*&)this->root_node_ptr_);
}


/**
 * @brief 子树中插入节点(递归)
 * @tparam Value 数据项模板类型
 * @tparam Key 关键码模板类型
 * @param elem 数据项
 * @param key 关键码
 * @param sub_tree_root_ptr 子树根节点指针
 * @return 是否插入成功
 * @note
 * 如果根节点指针为NULL, 则创建节点
 * 判断插入关键码与子树根节点关键码的大小关系, 在左子树or右子树做插入操作(递归)
 * 如果关键码相同, 则返回false
 */
template<class Value, class Key>
bool AVLTree<Value, Key>::InsertInSubTree_(Value elem, Key key, AVLNode<Value, Key>*& sub_tree_root_ptr) {

    AVLNode<Value, Key>* cur_stack_node_ptr = NULL;
    AVLNode<Value, Key>* cur_node_ptr = sub_tree_root_ptr;

    stack<AVLNode<Value, Key>*> AVL_node_stack;

    // 寻找插入位置
    while (cur_node_ptr != NULL) {
        // 找到等于key的结点, 无法插入, (原书使用elem)
        if (key == cur_node_ptr->GetKey()) {
            return false;
        }

        cur_stack_node_ptr = cur_node_ptr;
        AVL_node_stack.push(cur_stack_node_ptr);

        if (key < cur_node_ptr->GetKey()) {
            cur_node_ptr = cur_node_ptr->LeftChildPtr();
        }
        else {
            cur_node_ptr = cur_node_ptr->RightChildPtr();
        }
    }

    cur_node_ptr = new AVLNode<Value, Key>(elem, key);
    /* error handler */

    // 空树, 新结点成为根节点
    if (cur_stack_node_ptr == NULL) {
        sub_tree_root_ptr = cur_node_ptr;
        return true;
    }

    if (key < cur_stack_node_ptr->GetKey()) {
        cur_stack_node_ptr->SetLeftChildPtr(cur_node_ptr);
    }
    else {
        cur_stack_node_ptr->SetRightChildPtr(cur_node_ptr);
    }

    // 重新平衡化
    while (AVL_node_stack.empty() == false) {
        cur_stack_node_ptr = AVL_node_stack.top();
        AVL_node_stack.pop();

        if (cur_node_ptr == cur_stack_node_ptr->LeftChildPtr()) {
            cur_stack_node_ptr->balance_factor--;
        }
        else {
            cur_stack_node_ptr->balance_factor++;
        }

        // 第1种情况, 平衡退出
        if (cur_stack_node_ptr->balance_factor == 0) {
            break;
        }

        // 第2种情况, |平衡因子| = 1
        if (cur_stack_node_ptr->balance_factor == 1 || cur_stack_node_ptr->balance_factor == -1) {
            cur_node_ptr = cur_stack_node_ptr;
        }
        else { // 第3种情况, |bf| = 2
            int stack_node_rotate_flag = (cur_stack_node_ptr->balance_factor < 0) ? -1 : 1;
            if (cur_node_ptr->balance_factor == stack_node_rotate_flag) { // 两个结点的平衡因子同号, 单旋转
                if (stack_node_rotate_flag == -1) {
                    this->RotateRight_(cur_stack_node_ptr); // 右单旋转
                }
                else {
                    this->RotateLeft_(cur_stack_node_ptr); // 左单旋转
                }
            }
            else { // 两个结点的平衡因子反号, 双旋转
                if (stack_node_rotate_flag == -1) {
                    this->RotateLeftRight_(cur_stack_node_ptr);
                }
                else {
                    this->RotateRightLeft_(cur_stack_node_ptr);
                }
            }

            break; // 不再向上调整
        }
    }

    if (AVL_node_stack.empty() == true) {
        sub_tree_root_ptr = cur_stack_node_ptr;
    }
    else {
        AVLNode<Value, Key>* stack_top_node_ptr = AVL_node_stack.top();
        if (stack_top_node_ptr->GetKey() > cur_stack_node_ptr->GetKey()) {
            stack_top_node_ptr->SetLeftChildPtr(cur_stack_node_ptr);
        }
        else {
            stack_top_node_ptr->SetRightChildPtr(cur_stack_node_ptr);
        }
    }

    return true;
}


template<class Value, class Key>
AVLNode<Value, Key>* AVLTree<Value, Key>::GetInsertNodePtrAndInitStack(Key key,
    AVLNode<Value, Key>* node_ptr,
    stack<AVLNode<Value, Key>*>& AVL_node_stack) {

    AVLNode<Value, Key>* cur_node_ptr = node_ptr;

    // 寻找插入位置
    while (cur_node_ptr != NULL) {
        // 找到等于key的结点, 无法插入, todo: 原书使用elem
        if (key == cur_node_ptr->GetKey()) {
            return NULL;
        }

        AVL_node_stack.push(cur_node_ptr);

        // 原书使用elem, 此处使用关键码
        if (key < cur_node_ptr->GetKey()) {
            cur_node_ptr = cur_node_ptr->LeftChildPtr();
        }
        else {
            cur_node_ptr = cur_node_ptr->RightChildPtr();
        }
    }

    return cur_node_ptr;
}


template<class Value, class Key>
AVLNode<Value, Key>* AVLTree<Value, Key>::GetDeleteNodePtrAndInitStack(Key key,
    AVLNode<Value, Key>* node_ptr,
    stack<AVLNode<Value, Key>*>& AVL_node_stack) {

    AVLNode<Value, Key>* cur_node_ptr = node_ptr;

    // 寻找删除位置
    while (cur_node_ptr != NULL) {
        // 找到等于key的结点, 无法插入
        if (key == cur_node_ptr->GetKey()) {
            break;
        }

        AVL_node_stack.push(cur_node_ptr);

        if (key < cur_node_ptr->GetKey()) {
            cur_node_ptr = cur_node_ptr->LeftChildPtr();
        }
        else {
            cur_node_ptr = cur_node_ptr->RightChildPtr();
        }
    }

    return cur_node_ptr;
}


/**
 * @brief 在子树中, 使用关键码进行搜索
 * @tparam Value 数据项模板类型
 * @tparam Key 关键码模板类型
 * @param key 关键码
 * @param sub_tree_root_ptr 子树根节点
 * @return 搜索结果
 * @note
 * 1. 如果子树根节点为NULL, 返回NULL
 * 2. 使用当前遍历节点的key, 与参数key作比较, 分别进行递归和返回搜索结果(终止递归)
 */
template <class Value, class Key>
AVLNode<Value, Key>* AVLTree<Value, Key>::SearchInSubTree_(Key key, AVLNode<Value, Key>* sub_tree_root_ptr) {
    if (sub_tree_root_ptr == NULL) {
        return NULL;
    }

    Key cur_key = sub_tree_root_ptr->GetKey();

    if (key < cur_key) {
        return SearchInSubTree_(key, sub_tree_root_ptr->LeftChildPtr());
    }
    else if (key > cur_key) {
        return SearchInSubTree_(key, sub_tree_root_ptr->RightChildPtr());
    }
    else {
        return sub_tree_root_ptr;
    }
}


/**
 * @brief 平衡树子树插入(CyberDash实现版本)
 * @tparam Value 数据项模板类型
 * @tparam Key 关键码模板类型
 * @param elem 数据项
 * @param key 关键码
 * @param sub_tree_root_ptr 子树根节点
 * @return 是否插入成功
 * @note
 * 1. 首先找到插入位置, 并且使用栈保存
 * 2. 分3种情况, 进行平衡化
 * 3. 平衡化结束后的收尾工作
 */
template<class Value, class Key>
bool AVLTree<Value, Key>::InsertInSubTreeByCyberDash_(Value elem, Key key, AVLNode<Value, Key>*& sub_tree_root_ptr) {

    stack<AVLNode<Value, Key>* > AVL_node_stack;

    // 获取插入位置, 初始化栈
    AVLNode<Value, Key>* insert_node_ptr = GetInsertNodePtrAndInitStack(key, sub_tree_root_ptr, AVL_node_stack);

    insert_node_ptr = new AVLNode<Value, Key>(elem, key);
    /* error handler */

    // 空树, 新结点成为根节点, 并返回
    if (AVL_node_stack.empty()) {
        sub_tree_root_ptr = insert_node_ptr;
        return true;
    }

    AVLNode<Value, Key>* stack_node_ptr = AVL_node_stack.top();

    // 原书使用elem做比较, 应该是错了
    if (key < stack_node_ptr->GetKey()) {
        stack_node_ptr->SetLeftChildPtr(insert_node_ptr);
    }
    else {
        stack_node_ptr->SetRightChildPtr(insert_node_ptr);
    }

    AVLNode<Value, Key>* stack_node_child_ptr = insert_node_ptr;

    // 重新平衡化
    while (AVL_node_stack.empty() == false) {

        // 栈顶出栈
        stack_node_ptr = AVL_node_stack.top();
        AVL_node_stack.pop();

        // 调整平衡因子
        if (stack_node_child_ptr == stack_node_ptr->LeftChildPtr()) {
            stack_node_ptr->balance_factor--;
        }
        else {
            stack_node_ptr->balance_factor++;
        }

        // 第1种情况, 平衡退出
        if (stack_node_ptr->balance_factor == 0) {
            break;
        }

        // 第2种情况, |平衡因子| = 1
        if (stack_node_ptr->balance_factor == 1 || stack_node_ptr->balance_factor == -1) {
            stack_node_child_ptr = stack_node_ptr;
        }
        else { // 第3种情况, |bf| = 2
            int stack_node_rotate_flag = (stack_node_ptr->balance_factor < 0) ? -1 : 1;
            if (stack_node_child_ptr->balance_factor == stack_node_rotate_flag) { // 两个结点的平衡因子同号, 单旋转
                if (stack_node_rotate_flag == -1) {
                    this->RotateRight_(stack_node_ptr); // 右单旋转
                }
                else {
                    this->RotateLeft_(stack_node_ptr); // 左单旋转
                }
            }
            else { // 两个结点的平衡因子反号, 双旋转
                if (stack_node_rotate_flag == -1) {
                    this->RotateLeftRight_(stack_node_ptr);
                }
                else {
                    this->RotateRightLeft_(stack_node_ptr);
                }
            }

            break; // 不再向上调整
        }
    }

    // 已经完成平衡化的树, 完成最后处理
    if (AVL_node_stack.empty() == true) {
        sub_tree_root_ptr = stack_node_ptr;
    }
    else {
        AVLNode<Value, Key>* stack_top_node_ptr = AVL_node_stack.top();
        if (stack_top_node_ptr->GetKey() > stack_node_ptr->GetKey()) {
            stack_top_node_ptr->SetLeftChildPtr(stack_node_ptr);
        }
        else {
            stack_top_node_ptr->SetRightChildPtr(stack_node_ptr);
        }
    }

    return true;
}


/**
 * @brief 平衡树子树删除节点(CyberDash实现版本)
 * @tparam Value 数据项模板类型
 * @tparam Key 关键码模板类型
 * @param sub_tree_root_ptr 子树根节点
 * @param key 待删除关键码
 * @return
 */
template<class Value, class Key>
bool AVLTree<Value, Key>::RemoveInSubTreeByCyberDash_(AVLNode<Value, Key>*& sub_tree_root_ptr, Key key) {
    AVLNode<Value, Key>* cur_node_pre_ptr = NULL;

    stack<AVLNode<Value, Key>*> AVL_node_stack;

    AVLNode<Value, Key>* delete_node_ptr = GetDeleteNodePtrAndInitStack(key,
        sub_tree_root_ptr,
        AVL_node_stack);

    if (delete_node_ptr == NULL) {
        return false; // 未找到删除结点
    }

    if (delete_node_ptr->LeftChildPtr() != NULL && delete_node_ptr->RightChildPtr() != NULL) {
        AVL_node_stack.push(delete_node_ptr); // 将待删除节点入stack

        cur_node_pre_ptr = delete_node_ptr->LeftChildPtr();
        while (cur_node_pre_ptr->RightChildPtr() != NULL) {
            AVL_node_stack.push(cur_node_pre_ptr);
            cur_node_pre_ptr = cur_node_pre_ptr->RightChildPtr();
        }

        delete_node_ptr->SetKey(cur_node_pre_ptr->GetKey());
        delete_node_ptr->SetValue(cur_node_pre_ptr->GetValue());

        delete_node_ptr = cur_node_pre_ptr;
    }

    AVLNode<Value, Key>* child_of_delete_node_ptr = NULL; // 被删除节点的孩子节点

    // 找到此时的待删除节点的一个孩子节点, 用作连接
    if (delete_node_ptr->LeftChildPtr() != NULL) {
        child_of_delete_node_ptr = delete_node_ptr->LeftChildPtr();
    }
    else {
        child_of_delete_node_ptr = delete_node_ptr->RightChildPtr();
    }

    if (AVL_node_stack.empty() == true) { // 删除的是根节点
        sub_tree_root_ptr = child_of_delete_node_ptr;
    }
    else {

        AVLNode<Value, Key>* cur_stack_node_ptr = AVL_node_stack.top();

        if (cur_stack_node_ptr->LeftChildPtr() == delete_node_ptr) { // 被删除节点是cur_stack_node_ptr的左孩子
            cur_stack_node_ptr->SetLeftChildPtr(child_of_delete_node_ptr); // 连接
        }
        else { // 被删除节点是cur_stack_node_ptr的右孩子
            cur_stack_node_ptr->SetRightChildPtr(child_of_delete_node_ptr); // 连接
        }

        AVLNode<Value, Key>* parent_node_ptr;

        // 重新平衡化
        while (AVL_node_stack.empty() == false) {

            AVLNode<Value, Key>* grand_parent_node_ptr = NULL;
            parent_node_ptr = AVL_node_stack.top();
            AVL_node_stack.pop();

            int grand_parent_direction;
            int parent_direction;

            if (parent_node_ptr->RightChildPtr() == child_of_delete_node_ptr) {
                parent_node_ptr->balance_factor--;
            }
            else {
                parent_node_ptr->balance_factor++;
            }

            if (AVL_node_stack.empty() == false) {
                grand_parent_node_ptr = AVL_node_stack.top();
                AVL_node_stack.pop();

                grand_parent_direction = (grand_parent_node_ptr->LeftChildPtr() == parent_node_ptr) ? -1 : 1;
            }
            else {
                grand_parent_direction = 0;
            }

            if (parent_node_ptr->balance_factor == 1 || parent_node_ptr->balance_factor == -1) { // 图7.20
                break;
            }

            if (parent_node_ptr->balance_factor != 0) { // |bf| = 2
                if (parent_node_ptr->balance_factor < 0) {
                    parent_direction = -1;
                    child_of_delete_node_ptr = parent_node_ptr->LeftChildPtr();
                }
                else {
                    parent_direction = 1;
                    child_of_delete_node_ptr = parent_node_ptr->RightChildPtr();
                }

                if (child_of_delete_node_ptr && child_of_delete_node_ptr->balance_factor == 0) {
                    if (parent_direction == -1) {
                        this->RotateRight_(parent_node_ptr);
                        parent_node_ptr->balance_factor = 1;
                        parent_node_ptr->LeftChildPtr()->balance_factor = -1;
                    }
                    else {
                        this->RotateLeft_(parent_node_ptr);
                        parent_node_ptr->balance_factor = -1;
                        parent_node_ptr->RightChildPtr()->balance_factor = 1;
                    }

                    break;
                }

                if (child_of_delete_node_ptr && child_of_delete_node_ptr->balance_factor == parent_direction) { // 图7.23, 两节点平衡因子同号
                    if (parent_direction == -1) {
                        this->RotateRight_(parent_node_ptr);
                    }
                    else {
                        this->RotateLeft_(parent_node_ptr);
                    }
                }
                else { // 图7.24, 两节点平衡因子反号
                    if (parent_direction == -1) {
                        this->RotateLeftRight_(parent_node_ptr);
                    }
                    else {
                        this->RotateRightLeft_(parent_node_ptr);
                    }
                }

                // 旋转后, 新根与上层连接
                if (grand_parent_direction == -1) {
                    grand_parent_node_ptr->SetLeftChildPtr(parent_node_ptr);
                }
                else {
                    grand_parent_node_ptr->SetRightChildPtr(parent_node_ptr);
                }
            }

            child_of_delete_node_ptr = parent_node_ptr; // 图7.21, |bf| = 0
        }

        if (AVL_node_stack.empty() == true) {
            sub_tree_root_ptr = parent_node_ptr;
        }
    }

    delete delete_node_ptr;
    delete_node_ptr = NULL;

    return true;
}


/**
 * @brief 打印子树(递归)
 * @tparam Value
 * @tparam Key
 * @param sub_tree_root_ptr
 * @param visit
 */
template <class Value, class Key>
void AVLTree<Value, Key>::PrintSubTree_(AVLNode<Value, Key>* sub_tree_root_ptr, void (*visit)(AVLNode<Value, Key>*)) {

    if (sub_tree_root_ptr == NULL) {
        return;
    }

    visit(sub_tree_root_ptr);

    cout << "(";

    PrintSubTree_(sub_tree_root_ptr->LeftChildPtr(), visit);

    cout << ",";

    PrintSubTree_(sub_tree_root_ptr->RightChildPtr(), visit);

    cout << ")";
}


template<class Value, class Key>
void AVLTree<Value, Key>::PrintTree(void (*visit)(AVLNode<Value, Key>*)) {
    this->PrintSubTree_((AVLNode<Value, Key>*)this->root_node_ptr_, visit); cout << endl;
}


template<class Value, class Key>
bool AVLTree<Value, Key>::RemoveByCyberDash(Key key) {
    return this->RemoveInSubTreeByCyberDash_(this->RootRef(), key);
}


template <class Value, class Key>
AVLNode<Value, Key>* AVLTree<Value, Key>::MinInSubTree_(AVLNode<Value, Key>* sub_tree_root_ptr) const {

    if (sub_tree_root_ptr == NULL) {
        return NULL;
    }

    AVLNode<Value, Key>* cur_node_ptr = sub_tree_root_ptr;

    while (cur_node_ptr->LeftChildPtr() != NULL) {
        cur_node_ptr = cur_node_ptr->LeftChildPtr();
    }

    return cur_node_ptr;
}


template<class Value, class Key>
Value AVLTree<Value, Key>::Max() {
    AVLNode<Value, Key>* root_node_ptr = this->root_node_ptr_;
    AVLNode<Value, Key>* max_node = this->MaxInSubTree_(root_node_ptr);
    return max_node->GetValue();
}


/**
 * @brief 子树中关键码最大项
 * @tparam Value 数据项模板类型
 * @tparam Key 关键码模板类型
 * @param sub_tree_root_ptr 子树根节点
 * @return 关键码最大项
 * @note
 * 右孩子节点迭代
 */
template <class Value, class Key>
AVLNode<Value, Key>* AVLTree<Value, Key>::MaxInSubTree_(AVLNode<Value, Key>* sub_tree_root_ptr) const {

    if (sub_tree_root_ptr == NULL) {
        return NULL;
    }

    AVLNode<Value, Key>* cur_node_ptr = sub_tree_root_ptr;
    while (cur_node_ptr->RightChildPtr() != NULL) {
        cur_node_ptr = cur_node_ptr->RightChildPtr();
    }

    return cur_node_ptr;
}


template<class Value, class Key>
Value AVLTree<Value, Key>::Min() {
    AVLNode<Value, Key>* max_node = this->MinInSubTree_(this->Root());
    return max_node->GetValue();
}


template<class Value, class Key>
int AVLTree<Value, Key>::SubTreeHeight_(AVLNode<Value, Key>* sub_tree_root_ptr) {
    if (sub_tree_root_ptr == NULL) {
        return 0;
    }

    int left_sub_tree_height = SubTreeHeight_(sub_tree_root_ptr->LeftChildPtr());
    int right_sub_tree_height = SubTreeHeight_(sub_tree_root_ptr->RightChildPtr());

    if (left_sub_tree_height < right_sub_tree_height) {
        return right_sub_tree_height + 1;
    }
    else {
        return left_sub_tree_height + 1;
    }
}

#endif // CYBER_DASH_AVL_TREE_H
