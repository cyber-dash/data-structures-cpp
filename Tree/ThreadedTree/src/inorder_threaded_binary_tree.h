/*!
 * @file inorder_threaded_binary_tree.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 线索树
 * @version 0.2.1
 * @date 2021-05-13
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#ifndef CYBER_DASH_INORDER_THREADED_BINARY_TREE_H
#define CYBER_DASH_INORDER_THREADED_BINARY_TREE_H


#include <iostream>
#include <cstdlib>
#include "threaded_node.h"


using namespace std;




/*!
 * @brief 线索树模板类
 * @tparam TData 类型模板参数
 */
template <typename TData>
class InorderThreadedBinaryTree {
public:
    InorderThreadedBinaryTree(): root_(NULL) {}

    /*!
     * @brief 获取根节点指针
     * @return 根结点指针
     */
    ThreadedNode<TData>* Root() { return root_; }

    /*!
     * @brief 插入结点
     * @param data 数据
     * @return 是否插入成功
     */
    bool Insert(const TData& data) { return Insert_(root_, data);}

    /* 中序线索树 */

    // 创建中序线索
    void CreateInOrderThread();
    // 中序线索第一个线索结点
    ThreadedNode<TData>* First(ThreadedNode<TData>* node);
    // 求(node为根的)当前二叉树的最后一个线索节点的节点指针
    ThreadedNode<TData>* Last(ThreadedNode<TData>* node);
    // 中序线索下一个线索结点
    ThreadedNode<TData>* Next(ThreadedNode<TData>* node);
    // 中序线索前一个线索结点
    ThreadedNode<TData>* Prior(ThreadedNode<TData>* node);
    // 中序线索父结点
    ThreadedNode<TData>* Parent(ThreadedNode<TData>* node_ptr) { return Parent_(node_ptr); }
    // 中序线索二叉树中序遍历
    void InOrderTraverse(void (*visit)(ThreadedNode<TData>* node_ptr));
    // 中序线索二叉树前序遍历
    void PreOrderTraverse(void (*visit)(ThreadedNode<TData>* node_ptr));
    // 中序线索二叉树后序遍历
    void PostOrderTraverse(void (*visit)(ThreadedNode<TData> *p));
    // 中序线索二叉子树, 找到后续遍历第一个结点(书中未实现)
    ThreadedNode<TData>* FindFirstNodeForPostOrderTraverse(ThreadedNode<TData>* node_ptr);
    //
    void InsertRight(ThreadedNode<TData>* s, ThreadedNode<TData> *r);
    //
    void InsertLeft(ThreadedNode<TData>* s, ThreadedNode<TData> *r);
    //
    void DeleteRight(ThreadedNode<TData>* s);
    //
    void DeleteLeft(ThreadedNode<TData>* s);


protected:
    ThreadedNode<TData>* root_;
    // 子树创建中序线索
    void CreateSubInOrderThread_(ThreadedNode<TData>*& node, ThreadedNode<TData>*& pre_node);
    // 父节点指针
    ThreadedNode<TData>* Parent_(ThreadedNode<TData>* node);
    // 子树插入
    bool Insert_(ThreadedNode<TData>*& node, const TData& data);
};


/*!
 * @brief 求(node_ptr为根的)当前中序线索树的第一个节点指针
 * @tparam T 树节点数据类型
 * @param node 当前选中的节点
 * @return 结点指针
 * @note
 * 左子树遍历至最深的节点
 */
template <class T>
ThreadedNode<T>* InorderThreadedBinaryTree<T>::First(ThreadedNode<T>* node) {
    ThreadedNode<T>* cur = node;

    while (cur != NULL &&
           cur->left_child != NULL &&
           cur->left_tag == CHILD_POINTER)
    {
        cur = cur->left_child;
    }

    return cur;
}


/*!
 * @brief 中序线索树的下一节点
 * @tparam T 类型模板参数
 * @param node 当前选中节点
 * @return Next节点指针
 * @note
 * 最右子节点的First()
 */
template <class T>
ThreadedNode<T>* InorderThreadedBinaryTree<T>::Next(ThreadedNode<T>* node) {
    if (node == NULL) {
        exit(1); // error handler
    }

    ThreadedNode<T>* right_child = node->right_child;

    if (right_child != NULL && node->right_tag == CHILD_POINTER) {
        return First(right_child);
    }

    return right_child;
}


/*!
 * @brief 求(node_ptr为根的)当前二叉树的最后一个线索节点的节点指针
 * @tparam T 类型模板参数
 * @param node 当前节点
 * @return 最后一个线索节点的指针
 * @note
 * 最右子节点(可能非叶子)
 */
template <class T>
ThreadedNode<T>* InorderThreadedBinaryTree<T>::Last(ThreadedNode<T> *node) {
    ThreadedNode<T>* cur = node;

    while (cur != NULL &&
           cur->right_child != NULL &&
           cur->right_tag == CHILD_POINTER)
    {
        cur = cur->right_child;
    }

    return cur;
}


/*!
 * @brief 中序线索前一个线索结点
 * @tparam T 类型模板参数
 * @param node
 * @return
 */
template <class T>
ThreadedNode<T>* InorderThreadedBinaryTree<T>::Prior(ThreadedNode<T>* node) {
    ThreadedNode<T>* left_child = node->left_child;

    if (node->left_tag == CHILD_POINTER) {
        return Last(left_child);
    }

    return left_child;
}


/*!
 * @brief 中序线索二叉树中序遍历
 * @tparam T 类型模板参数
 * @param visit 遍历函数
 */
template <class T>
void InorderThreadedBinaryTree<T>::InOrderTraverse(void (*visit)(ThreadedNode<T>* node)) {
    for (ThreadedNode<T>* cur = First(root_); cur != NULL; cur = Next(cur)) {
        visit(cur);
    }
}


/*!
 * @brief 创建中序线索
 * @tparam T 树节点数据类型
 * @note
 * 调用CreateInOrderSubThread_
 */
template <class T>
void InorderThreadedBinaryTree<T>::CreateInOrderThread() {
    if (root_ == NULL) {
        return;
    }

    ThreadedNode<T>* pre_node_ptr = NULL;

    CreateSubInOrderThread_(root_, pre_node_ptr);

    // 最后一个线索节点, 收尾工作
    if (pre_node_ptr != NULL) {
        pre_node_ptr->right_child = NULL;
        pre_node_ptr->right_tag = THREADED_NODE_POINTER;
    }
}


/*!
 * @brief 子树创建中序线索(递归)
 * @tparam T 树节点数据类型
 * @param node 当前节点
 * @param pre_node 当前节点的前驱节点
 * @note
 * 递归终止条件:
 *    当前节点为null
 * 分治递归:
 *    左子树执行
 *    调整线索
 *    右子树执行
 */
template <class T>
void InorderThreadedBinaryTree<T>::CreateSubInOrderThread_(ThreadedNode<T>*& node, ThreadedNode<T>*& pre_node) {

    if (node == NULL) {
        return;
    }

    // 左子树分治
    CreateSubInOrderThread_(node->left_child, pre_node);

    // (利用left_child_)
    // 如果left_child_指针为NULL,
    // 则将node_ptr->left_child_指向pre_node_ptr, 加入线索树
    if (node->left_child == NULL) {
        node->left_child = pre_node;
        node->left_tag = THREADED_NODE_POINTER;
    }

    // (利用right_child_)
    // 如果前一节点pre_node_ptr不为NULL, 并且它的right_child_不为NULL,
    // 则前一节点的right_child_指向node_ptr, 加入线索树
    if (pre_node != NULL && pre_node->right_child == NULL) {
        pre_node->right_child = node;
        pre_node->right_tag = THREADED_NODE_POINTER;
    }

    pre_node = node; // pre_node_ptr节点后移

    // 右子树分治
    CreateSubInOrderThread_(node->right_child, pre_node);
}



/**
 * @brief 中序线索二叉树前序遍历
 * 若当前结点有左子女, 则前序的后继结点为左孩子节点
 * 否则, 若当前结点有右子女, 则前序的后继结点为右孩子节点
 * 对于叶子结点, 沿着中序后继线索, 走到一个有右子女结点的结点, 这个右子女结点就是当前结点的前序后继结点
 * @tparam T
 * @param visit
 */
template <class T>
void InorderThreadedBinaryTree<T>::PreOrderTraverse(void (*visit)(ThreadedNode<T>* node_ptr)) {
    ThreadedNode<T> *cur = root_;

    while (cur != NULL) {
        visit(cur);

        if (cur->left_tag == CHILD_POINTER) { // 若有左子女, 则为前序后继
            cur = cur->left_child;
        } else if (cur->right_tag == CHILD_POINTER) { // 否则若有右子女, 则为前序后继
            cur = cur->right_child;
        } else { // 对于叶子结点, 沿着中序后继线索, 走到一个有右子女结点的结点, 这个右子女结点就是当前结点的前序后继结点
            while (cur != NULL && cur->right_tag == THREADED_NODE_POINTER) {
                cur = cur->right_child;
            }

            if (cur != NULL) {
                cur = cur->right_child;
            }
        }
    }
}


/**
 * @brief 中序线索二叉树, 后续遍历
 * 重复下述过程, 直到叶结点为止:
 *    从根出发, 沿着左子树链一直找下去, 找到左孩子不再是做孩子指针的结点
 *    再找到该结点的右孩子, 以此结点为根的子树上,
 * 接着, 从此结点开始后序遍历, 每次先找到当前节点的父节点
 *    如果当前结点是父节点的右孩子or虽然是这个父节点的左孩子, 但这个父节点没有右孩子
 *       则后序下的后继为该父节点
 *    否则, 在当前结点的右子树(如果存在)上重复执行上面的操作
 * @tparam T
 * @param visit
 */
template <class T>
void InorderThreadedBinaryTree<T>::PostOrderTraverse(void (*visit)(ThreadedNode<T>*)) {

    ThreadedNode<T>* cur = FindFirstNodeForPostOrderTraverse(root_);
    ThreadedNode<T> *cur_parent;

    visit(cur); // 访问第一个结点

    while ((cur_parent = Parent_(cur)) != NULL) {
        if (cur_parent->right_child == cur ||  // 当前结点是父节点的右孩子
            cur_parent->right_tag == THREADED_NODE_POINTER) // 当前结点是父节点左孩子, 并且父节点没有右孩子
        {
            cur = cur_parent;
        } else {
            cur = FindFirstNodeForPostOrderTraverse(cur_parent->right_child);
        }

        visit(cur);
    }
}


/**
 * @brief 中序线索树后续遍历, 找到第一个遍历结点(以node_ptr为根)
 * 重复下述过程, 直到叶结点为止:
 *    沿着左子树链一直找下去, 找到左孩子不再是做孩子指针的结点
 *    再找到该结点的右孩子, 以此结点为根的子树上,
 * @tparam T
 * @param node_ptr
 * @return
 */
template<class T>
ThreadedNode<T>* InorderThreadedBinaryTree<T>::FindFirstNodeForPostOrderTraverse(ThreadedNode<T>* node_ptr) {

    ThreadedNode<T>* cur = node_ptr;

    while (cur->left_tag == CHILD_POINTER || cur->right_tag == CHILD_POINTER) {
        if (cur->left_tag == CHILD_POINTER) {
            cur = cur->left_child;
        } else if (cur->right_tag == CHILD_POINTER) {
            cur = cur->right_child;
        }
    }

    return cur;
}


/*!
 * @brief 中序线索二叉树求父节点
 * @tparam T 类型模板参数
 * @param node 结点指针
 * @return 父结点知真假
 * @note
 * 两条路径:
 *   1: 从当前结点走到树上层的一个中序前驱(不一定是直接前驱), 然后向右下找父节点
 *   2: 从当前结点走到书上层的一个中序后继(不一定是直接后继), 然后向左下找父节点
 */
template <class T>
ThreadedNode<T>* InorderThreadedBinaryTree<T>::Parent_(ThreadedNode<T>* node) {

    if (node == root_) {
        return NULL;
    }

    /* 尝试路径1 */
    // 遍历至最左子节点
    ThreadedNode<T>* left_side_child = node;
    while (left_side_child->left_tag == CHILD_POINTER) {
        left_side_child = left_side_child->left_child;
    }

    if (left_side_child->left_child != NULL) { // 如果等于NULL, 则寻找树上层的中序前驱失败, 路径1失败
        ThreadedNode<T>* upper_level_pre_node = left_side_child->left_child; // 树上层的中序前驱

        // 向右下找父节点
        while (upper_level_pre_node != NULL &&
               upper_level_pre_node->left_child != node &&
               upper_level_pre_node->right_child != node) {
            upper_level_pre_node = upper_level_pre_node->right_child;
        }

        if (upper_level_pre_node != NULL) { // 如果不等于NULL, 则找到父节点, 否则路径1失败
            return upper_level_pre_node;
        }
    }

    /* 尝试路径2 */
    // 遍历至最右子节点
    ThreadedNode<T>* right_side_child = node;
    while (right_side_child->right_tag == CHILD_POINTER) {
        right_side_child = right_side_child->right_child;
    }

    ThreadedNode<T>* upper_level_post_node = right_side_child->right_child; // 树上层的中序后继

    // 向左下找父节点
    while (upper_level_post_node != NULL &&
           upper_level_post_node->left_child != node &&
           upper_level_post_node->right_child != node) {
        upper_level_post_node = upper_level_post_node->left_child;
    }

    return upper_level_post_node;
}


/*!
 * @brief 二叉树插入(建立线索之前)
 * @tparam T 类型模板参数
 * @param node 被插入的子树的根结点
 * @param data 数据项
 * @return 是否插入成功
 */
template<class T>
bool InorderThreadedBinaryTree<T>::Insert_(ThreadedNode<T>*& node, const T& data) {

    if (node == NULL) {
        node = new ThreadedNode<T>(data);
        /* new error handler*/
        return true;
    }

    int left_sub_tree_height = Height(node->left_child);
    int right_sub_tree_height = Height(node->right_child);

    if (left_sub_tree_height > right_sub_tree_height) {
        return Insert_(node->right_child, data);
    } else {
        return Insert_(node->left_child, data);
    }
}


/*!
 * @brief 二叉子树的深度
 * @tparam T 类型模板参数
 * @param node 二叉子树的根
 * @return 深度
 */
template<class T>
int Height(ThreadedNode<T>* node) {
    if (node == NULL) {
        return 0;
    }

    int left_sub_tree_height = Height(node->left_child);
    int right_sub_tree_height = Height(node->right_child);

    return (left_sub_tree_height < right_sub_tree_height) ?
           right_sub_tree_height + 1 : left_sub_tree_height + 1;
}


/**
 * @breif
 * @tparam T
 * @param s
 * @param r
 */
template<class T>
void InorderThreadedBinaryTree<T>::InsertRight(ThreadedNode<T>* s, ThreadedNode<T>* r) {
    r->right_child = s->right_child;
    r->right_tag = s->right_tag;

    r->left_child = s;
    r->left_tag = THREADED_NODE_POINTER;

    s->right_child = r;
    s->right_tag = CHILD_POINTER;

    if (r->right_tag == CHILD_POINTER) {
        ThreadedNode<T> *temp;
        temp = First(r->right_child);
        temp->left_child = r;
    }
}


template<class T>
void InorderThreadedBinaryTree<T>::InsertLeft(ThreadedNode<T> *s, ThreadedNode<T> *l) {
    l->left_child = s->left_child;
    l->left_tag = s->left_tag;
    l->right_child = s;
    l->right_tag = 1;

    s->left_child = l;
    s->left_tag = 0;

    if (l->right_tag == 0) {
        ThreadedNode<T> *temp;

        temp = Last(l->left_child);
        temp->right_child = l;
    }
}


template<class T>
void InorderThreadedBinaryTree<T>::DeleteRight(ThreadedNode<T> *s) {
    ThreadedNode<T> *r = s->right_child;

    if (r->right_tag == 1) {
        if (r->left_tag == 1) {
            /* r has neither right child nor left child */
            s->right_child = r->right_child;
            s->right_tag = 1;
        } else {
            /* r has no right child but has left child */
            ThreadedNode<T> *la = Last(r->left_child);
            la->right_child = r->right_child;
            s->right_child = r->left_child;
        }
    } else {
        if (r->left_tag == 1) {
            /* r has right child but has no left child */
            ThreadedNode<T> *fr = First(r->right_child);
            fr->left_child = s;
            s->right_child = r->right_child;
        } else {
            /* r has both right child and left child */
            ThreadedNode<T> *fr = First(r->right_child);
            ThreadedNode<T> *la = Last(r->left_child);

            la->right_child = r->left_child;
            la->right_tag = r->right_tag;

            s->right_child = r->left_child;
            fr->left_child = la;
        }
    }

    delete r;
}


template<class T>
void InorderThreadedBinaryTree<T>::DeleteLeft(ThreadedNode<T> *s) {
    ThreadedNode<T> *l = s->left_child;

    if (l->right_tag == 1) {
        if (l->left_tag == 1) {
            /* l has neither right child nor left child */
            s->left_child = l->left_child;
            s->left_tag = 1;
        } else {
            /* l has no right child but has left child */
            ThreadedNode<T> *la = Last(l->left_child);
            la->right_child = s;
            s->left_child = l->left_child;
        }
    } else {
        if (l->left_tag == 1) {
            /* l has right child but has no left child */
            ThreadedNode<T> *fr = First(l->right_child);
            fr->left_child = l->left_child;
            s->left_child = l->right_child;
        } else {
            /* l has both right child and left child */
            ThreadedNode<T> *fr = First(l->right_child);
            ThreadedNode<T> *la = Last(l->left_child);

            la->right_child = l->right_child;
            la->right_tag = l->right_tag;

            s->left_child = l->left_child;
            fr->left_child = la;
        }
    }

    delete l;
}



#endif // CYBER_DASH_INORDER_THREADED_BINARY_TREE_H
