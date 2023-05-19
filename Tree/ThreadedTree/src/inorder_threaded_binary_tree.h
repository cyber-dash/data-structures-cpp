/*!
 * @file inorder_threaded_binary_tree.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 中序线索树模板类
 * @version 0.2.1
 * @date 2021-05-13
 */

#ifndef CYBER_DASH_INORDER_THREADED_BINARY_TREE_H
#define CYBER_DASH_INORDER_THREADED_BINARY_TREE_H


#include <iostream>
#include <cstdlib>
#include "threaded_node.h"


using namespace std;


/*!
 * @brief **中序线索树模板类**
 * @tparam TData 数据项类型模板参数
 */
template <typename TData>
class InorderThreadedBinaryTree {
public:
    /*! @brief **默认构造函数** */
    InorderThreadedBinaryTree(): root_(NULL) {}

    /*!
     * @brief **获取根结点**
     * @return 根结点
     */
    ThreadedNode<TData>* Root() { return root_; }

    /*!
     * @brief **插入结点**
     * @param data 结点数据项
     * @return 执行结果
     * @note
     * 插入结点
     * ------
     * ------
     *
     * <span style="color:#DF5A00">
     * 注意: 本函数不涉及线索操作, 因此请在建立线索前调用此函数
     * </span>
     *
     * ------
     * 对root_调用InsertInSubTreeRecursive_
     */
    bool InsertRecursive(const TData& data) { return InsertInSubTreeRecursive_(root_, data); }

    // 创建中序线索
    void CreateThreadRecursive();
    // 中序线索第一个线索结点
    ThreadedNode<TData>* First(ThreadedNode<TData>* subtree_root);
    // 获取子树最后一个线索结点
    ThreadedNode<TData>* Last(ThreadedNode<TData>* subtree_root);
    // 获取下一个线索结点
    ThreadedNode<TData>* Next(ThreadedNode<TData>* node);
    // 获取前一个线索结点
    ThreadedNode<TData>* Pre(ThreadedNode<TData>* node);
    // 获取父结点
    ThreadedNode<TData>* Parent(ThreadedNode<TData>* node);
    // 中序线索二叉树中序遍历
    void InorderTraverse(void (*visit)(ThreadedNode<TData>*));
    // 中序线索二叉树前序遍历
    void PreorderTraverse(void (*Visit)(ThreadedNode<TData>*));
    // 中序线索二叉树后序遍历
    void PostorderTraverse(void (*visit)(ThreadedNode<TData>*));
    // 子树获取后序遍历首个遍历结点
    ThreadedNode<TData>* GetFirstNodeForPostorder(ThreadedNode<TData>* subtree_root);

protected:
    ThreadedNode<TData>* root_;     //!< 根结点
    // 子树创建中序线索
    void CreateThreadInSubtreeRecursive_(ThreadedNode<TData>*& subtree_root, ThreadedNode<TData>*& pre_node);
    // 子树插入
    bool InsertInSubTreeRecursive_(ThreadedNode<TData>*& subtree_root, const TData& data);
};


/*!
 * @brief **获取子树首个线索结点**
 * @tparam TData 数据项类型模板参数
 * @param subtree_root 子树根结点
 * @return 首个线索结点
 * @note
 * 获取子树首个线索结点
 * -----------------
 * -----------------
 *
 * -----------------
 * + **1 空子树处理**\n
 * **if** 空子树 :\n
 * &emsp; 抛出invalid_argument("NULL pointer")\n\n
 * + **2 获取结点**\n
 * 初始化cur(遍历指针), 指向subtree_root\n\n
 * **while loop** cur存在左孩子 && cur->left_tag属性为CHILD_POINTER :\n
 * &emsp; cur指向cur->left_child\n\n
 * + **3 返回结果**\n
 * 返回cur\n
 */
template <typename TData>
ThreadedNode<TData>* InorderThreadedBinaryTree<TData>::First(ThreadedNode<TData>* subtree_root) {
    // ---------- 1 空子树处理 ----------

    if (!subtree_root) {                                                            // if 空子树
        throw invalid_argument("NULL pointer");                                     // 抛出invalid_argument("NULL pointer")
    }

    // ---------- 2 获取结点 ----------

    ThreadedNode<TData>* cur = subtree_root;                                        // 初始化cur(遍历指针), 指向subtree_root

    while (cur->left_child != NULL && cur->left_tag == CHILD_POINTER) {             // while loop cur存在左孩子 && cur->left_tag属性为CHILD_POINTER
        cur = cur->left_child;                                                      // cur指向cur->left_child
    }

    // ---------- 3 返回结果 ----------

    return cur;                                                                     // 返回cur
}


/*!
 * @brief **获取下一线索结点**
 * @tparam TData 数据项类型模板参数
 * @param node 结点
 * @return 下一线索结点
 * @note
 * 获取下一线索结点
 * -------------
 * -------------
 *
 * -------------
 * **if** node的right_tag属性, 是THREADED_NODE_POINTER(线索结点指针) :\n
 * &emsp; 返回node->right_child\n\n
 * 返回First(node->right_child)\n
 */
template <typename TData>
ThreadedNode<TData>* InorderThreadedBinaryTree<TData>::Next(ThreadedNode<TData>* node) {
    if (node->right_tag == THREADED_NODE_POINTER) {                         // if node的right_tag属性, 是THREADED_NODE_POINTER(线索结点指针)
        return node->right_child;                                           // 返回node->right_child
    }

    return First(node->right_child);                                        // 返回First(node->right_child)
}


/*!
 * @brief 获取子树最后一个线索结点
 * @tparam TData 数据项类型模板参数
 * @param subtree_root 子树根结点
 * @return 最后一个线索节点的指针
 * @note
 * 获取子树最后一个线索结点
 * --------------------
 * --------------------
 *
 * --------------------
 * + **1 空子树处理**\n
 * **if** 空子树 :\n
 * &emsp; 抛出invalid_argument("NULL pointer")\n\n
 * + **2 获取结点**\n
 * 初始化cur(遍历指针), 指向subtree_root\n\n
 * **while loop** cur存在右孩子 && cur->right_tag属性为CHILD_POINTER :\n
 * &emsp; cur指向cur->right_child\n\n
 * + **3 返回结果**\n
 * 返回cur\n
 */
template <typename TData>
ThreadedNode<TData>* InorderThreadedBinaryTree<TData>::Last(ThreadedNode<TData>* subtree_root) {

    // ---------- 1 空子树处理 ----------

    if (!subtree_root) {                                                                // if 空子树
        throw invalid_argument("NULL pointer");                                         // 抛出invalid_argument("NULL pointer")
    }

    // ---------- 2 获取结点 ----------

    ThreadedNode<TData>* cur = subtree_root;                                            // 初始化cur(遍历指针), 指向subtree_root

    while (cur->right_child != NULL && cur->right_tag == CHILD_POINTER) {               // while loop cur存在右孩子 && cur->right_tag属性为CHILD_POINTER
        cur = cur->right_child;                                                         // cur指向cur->right_child
    }

    // ---------- 3 返回结果 ----------

    return cur;                                                                         // 返回cur
}


/*!
 * @brief **获取前一线索结点**
 * @tparam TData 数据项类型模板参数
 * @param node 结点
 * @return 前一线索结点
 * @note
 * 获取前一线索结点
 * -------------
 * -------------
 *
 * -------------
 * **if** node的left_tag属性, 是THREADED_NODE_POINTER(线索结点指针) :\n
 * &emsp; 返回node->left_child\n\n
 * 返回Last(node->left_child)\n
 */
template <typename TData>
ThreadedNode<TData>* InorderThreadedBinaryTree<TData>::Pre(ThreadedNode<TData>* node) {
    if (node->left_tag == THREADED_NODE_POINTER) {                  // if node的left_tag属性, 是THREADED_NODE_POINTER(线索结点指针)
        return node->left_child;                                    // 返回node->left_child
    }

    return Last(node->left_child);                                  // 返回Last(node->left_child)
}


/*!
 * @brief **中序遍历**
 * @tparam TData 数据项类型模板参数
 * @param visit 访问函数
 * @note
 * 中序遍历
 * -------
 * -------
 *
 * -------
 * **for loop** cur(遍历指针)指向First(root_); cur != NULL; cur指向下一线索结点 :\n
 * &emsp; 访问cur指向的结点\n
 */
template <typename TData>
void InorderThreadedBinaryTree<TData>::InorderTraverse(void (*visit)(ThreadedNode<TData>* node)) {
    for (ThreadedNode<TData>* cur = First(root_); cur != NULL; cur = Next(cur)) {       // for loop cur(遍历指针)指向First(root_); cur != NULL; cur指向下一线索结点
        visit(cur);                                                                     // 访问cur指向的结点
    }
}


/*!
 * @brief **创建中序线索(递归)**
 * @tparam TData 数据项类型模板参数
 * @note
 * 创建中序线索(递归)
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 空树处理**\n
 * **if** root_为NULL :\n
 * &emsp; 退出函数\n\n
 * + **2 执行递归**\n
 * 初始化pre_node为NULL\n
 * 调用CreateInOrderSubThread_\n\n
 * + **3 最后一个线索结点收尾工作**\n
 * pre_node->right_child设为NULL\n
 * pre_node->right_tag属性, 设为THREADED_NODE_POINTER(线索结点指针)\n
 */
template <typename TData>
void InorderThreadedBinaryTree<TData>::CreateThreadRecursive() {

    // ---------- 1 空树处理 ----------

    if (root_ == NULL) {                                // if root_为NULL :
        return;                                         // 退出函数
    }

    // ---------- 2 执行递归 ----------

    ThreadedNode<TData>* pre_node = NULL;               // 初始化pre_node为NULL

    CreateThreadInSubtreeRecursive_(root_, pre_node);   // 调用CreateInOrderSubThread_

    // ---------- 3 最后一个线索结点收尾工作 ----------

    pre_node->right_child = NULL;                       // pre_node->right_child设为NULL
    pre_node->right_tag = THREADED_NODE_POINTER;        // pre_node->right_tag属性, 设为THREADED_NODE_POINTER(线索结点指针)
}


/*!
 * @brief **子树创建中序线索(递归)**
 * @tparam TData 数据项类型模板参数
 * @param subtree_root 子树根结点
 * @param pre_node 子树根结点的前一结点(中序顺序)
 * @note
 * 子树创建中序线索(递归)
 * ------------------
 * ------------------
 *
 * 利用遍历, 中序遍历的结点顺序, 即是线索顺序
 *
 * ------------------
 * + **1 空子树处理**\n
 * **if** 空子树 :\n
 * &emsp; 返回\n\n
 * + **2 左子树递归**\n
 * 对左子树递归创建线索\n\n
 * + **3 创建线索**\n
 * **if** subtree_root->left_child为NULL :\n
 * &emsp; subtree_root->left_child指向pre_node\n
 * &emsp; subtree_root->left_tag属性, 设置为THREADED_NODE_POINTER(线索结点指针)\n\n
 * **if** pre_node存在 && pre_node->right_child为NULL :\n
 * &emsp; pre_node->right_child指向subtree_root\n
 * &emsp; pre_node->left_tag属性, 设置为THREADED_NODE_POINTER(线索结点指针)\n\n
 * + **4 更新pre_node**\n
 * pre_node = subtree_root;\n\n
 * + **5 右子树递归**\n
 * 对右子树递归创建线索\n
 */
template <typename TData>
void InorderThreadedBinaryTree<TData>::CreateThreadInSubtreeRecursive_(ThreadedNode<TData>*& subtree_root,
                                                                       ThreadedNode<TData>*& pre_node)
{
    // ---------- 1 空子树处理 ----------

    if (subtree_root == NULL) {                                             // if 空子树 :
        return;                                                             // 返回
    }

    // ---------- 2 左子树递归 ----------

    CreateThreadInSubtreeRecursive_(subtree_root->left_child, pre_node);    // 对左子树递归创建线索

    // ---------- 3 创建线索 ----------

    if (subtree_root->left_child == NULL) {                                 // if subtree_root->left_child为NULL :
        subtree_root->left_child = pre_node;                                // subtree_root->left_child指向pre_node
        subtree_root->left_tag = THREADED_NODE_POINTER;                     // subtree_root->left_tag属性, 设置为THREADED_NODE_POINTER(线索结点指针)
    }

    if (pre_node != NULL && pre_node->right_child == NULL) {                // if pre_node存在 && pre_node->right_child为NULL :
        pre_node->right_child = subtree_root;                               // pre_node->right_child指向subtree_root
        pre_node->right_tag = THREADED_NODE_POINTER;                        // pre_node->left_tag属性, 设置为THREADED_NODE_POINTER(线索结点指针)
    }

    // ---------- 4 更新pre_node ----------

    pre_node = subtree_root;                                                // pre_node = subtree_root;

    // ---------- 5 右子树递归 ----------

    CreateThreadInSubtreeRecursive_(subtree_root->right_child, pre_node);   // 对右子树递归创建线索
}


/**
 * @brief **前序遍历**
 * @tparam TData 数据项类型模板参数
 * @param Visit 访问函数
 * @note
 * 前序遍历
 * -------
 * -------
 *
 * IF: 当前结点有左孩子\n
 * &emsp; 下一访问结点为左孩子\n
 * ELSE IF: 当前结点有右孩子\n
 * &emsp; 下一访问结点为右孩子\n
 * ELSE(叶子结点):\n
 * &emsp; 沿着中序线索回溯, 到一个有右孩子的结点, 下一访问结点为该结点的右孩子\n
 *
 * -------
 * 初始化cur(遍历指针), 指向root_\n\n
 * **while loop** cur不为NULL :\n
 * &emsp; 访问cur\n\n
 * &emsp; **if** cur有左孩子 :\n
 * &emsp;&emsp; cur指向左孩子\n
 * &emsp; **else if** cur有右孩子 :\n
 * &emsp;&emsp; cur指向右孩子\n
 * &emsp; **else** (叶子结点) :\n
 * &emsp;&emsp; (使用中序线索回溯至第1个有右孩子的结点)\n
 * &emsp;&emsp; **while loop** cur不为NULL && cur->right_tag属性为THREADED_NODE_POINTER(线索结点指针) :\n
 * &emsp;&emsp;&emsp; cur指向右孩子\n
 * &emsp;&emsp; (cur移动)\n
 * &emsp;&emsp; **if** cur不为NULL :\n
 * &emsp;&emsp;&emsp; cur指向右孩子\n\n
 */
template <typename TData>
void InorderThreadedBinaryTree<TData>::PreorderTraverse(void (*Visit)(ThreadedNode<TData>*)) {
    ThreadedNode<TData>* cur = root_;                                           // 初始化cur(遍历指针), 指向root_

    while (cur != NULL) {                                                       // while loop cur不为NULL
        Visit(cur);                                                             // 访问cur

        if (cur->left_tag == CHILD_POINTER) {                                   // if cur有左孩子
            cur = cur->left_child;                                              // cur指向左孩子
        } else if (cur->right_tag == CHILD_POINTER) {                           // else if cur有右孩子
            cur = cur->right_child;                                             // cur指向右孩子
        } else {                                                                // else (叶子结点)
            // (使用中序线索回溯至第1个有右孩子的结点)
            while (cur != NULL && cur->right_tag == THREADED_NODE_POINTER) {    // while loop cur不为NULL && cur->right_tag属性为THREADED_NODE_POINTER(线索结点指针)
                cur = cur->right_child;                                         // cur指向右孩子
            }

            // (cur移动)
            if (cur != NULL) {                                                  // if cur不为NULL
                cur = cur->right_child;                                         // cur指向右孩子
            }
        }
    }
}


/**
 * @brief **后序遍历**
 * @tparam TData 数据项类型模板参数
 * @param visit 结点访问函数
 * @note
 * 后序遍历
 * ------
 * ------
 *
 * ------
 * + **1 空树处理**\n
 * **if** 空树 :\n
 * &emsp; 退出函数\n\n
 * + **2 访问后序遍历的第1个结点**\n
 * 初始化cur, 指向后序遍历的第1个节点\n
 * 初始化cur_parent, 指向cur的父节点\n\n
 * 访问cur\n\n
 * + **3 递归**\n
 * **while loop** cur_parent不为NULL :\n
 * &emsp; **if** cur是cur_parent的右孩子 <b>||</b> cur是cur_parent的左孩子, 并且cur_parent没有右孩子 :\n
 * &emsp;&emsp; cur指向cur_parent\n
 * &emsp; **else** (cur指向cur_parent的左孩子, 同时cur_parent存在右孩子)\n
 * &emsp;&emsp; cur指向cur_parent->right_child的后序遍历首结点\n\n
 * &emsp; 访问cur\n\n
 * &emsp; cur_parent指向cur的父节点\n
 */
template <typename TData>
void InorderThreadedBinaryTree<TData>::PostorderTraverse(void (*visit)(ThreadedNode<TData>*)) {

    // ---------- 1 空树处理 ----------

    if (!root_) {                                                                               // if 空树
        return;                                                                                 // 退出函数
    }

    // ---------- 2 访问后序遍历的第1个结点 ----------

    ThreadedNode<TData>* cur = GetFirstNodeForPostorder(root_);                                 // 初始化cur, 指向后序遍历的第1个节点
    ThreadedNode<TData>* cur_parent = Parent(cur);                                              // 初始化cur_parent, 指向cur的父节点

    visit(cur);                                                                                 // 访问cur

    // ---------- 3 递归 ----------

    while (cur_parent != NULL) {                                                                // while loop cur_parent不为NULL
        if (cur_parent->right_child == cur || cur_parent->right_tag == THREADED_NODE_POINTER) { // if cur是cur_parent的右孩子 || cur是cur_parent的左孩子, 并且cur_parent没有右孩子
            cur = cur_parent;                                                                   // cur指向cur_parent
        } else {                                                                                // else (cur指向cur_parent的左孩子, 同时cur_parent存在右孩子)
            cur = GetFirstNodeForPostorder(cur_parent->right_child);                            // cur指向cur_parent->right_child的后序遍历首结点
        }

        visit(cur);                                                                             // 访问cur

        cur_parent = Parent(cur);                                                               // cur_parent指向cur的父节点
    }
}


/**
 * @brief **子树获取后序遍历首个遍历结点**
 * @tparam TData 数据项类型模板参数
 * @param subtree_root 子树根结点
 * @return 首个遍历结点
 * @note
 * 子树获取后序遍历首个遍历结点
 * ------------------------
 * ------------------------
 *
 * 优先沿着左子树链找\n
 * 左子树链没有, 则沿着右子树链找\n
 * ```
 * 示例:
 *
 *     a
 *      \
 *       b
 *      /
 *     d
 *    / \
 *   e   g
 *    \
 *     h
 * ```
 *
 * <span style="color:#D40000;font-size:larger">
 * 对结点a调用函数, 返回h\n
 * </span>
 *
 * ------------------------
 * 初始化cur(遍历指针)指向subtree_root\n\n
 * **while loop** cur结点存在孩子结点 :\n
 * &emsp; **if** cur存在左孩子 :\n
 * &emsp;&emsp; cur指向cur->left_child\n
 * &emsp; **else if** cur存在右孩子 :\n
 * &emsp;&emsp; cur指向cur->right_child\n\n
 * 返回cur\n
 */
template<typename TData>
ThreadedNode<TData>* InorderThreadedBinaryTree<TData>::GetFirstNodeForPostorder(ThreadedNode<TData>* subtree_root) {

    ThreadedNode<TData>* cur = subtree_root;                                        // 初始化cur(遍历指针)指向subtree_root

    while (cur->left_tag == CHILD_POINTER || cur->right_tag == CHILD_POINTER) {     // while loop cur结点存在孩子结点
        if (cur->left_tag == CHILD_POINTER) {                                       // if cur存在左孩子
            cur = cur->left_child;                                                  // cur指向cur->left_child
        } else if (cur->right_tag == CHILD_POINTER) {                               // else if cur存在右孩子
            cur = cur->right_child;                                                 // cur指向cur->right_child
        }
    }

    return cur;                                                                     // 返回cur
}


/*!
 * @brief **求父节点**
 * @tparam TData 数据项类型模板参数
 * @param node 结点
 * @return 父结点
 * @note
 * 求父节点
 * -------
 * -------
 *
 * 两条路径:\n
 * &emsp; 1: 从当前结点走到树(以当前结点为根结点)上层的一个中序前驱, 然后向右下找父节点\n
 * &emsp; 2: 从当前结点走到树上层的一个中序后继, 然后向左下找父节点\n\n
 * ```
 * 示例:
 *
 *     a
 *      \
 *       b
 *      /
 *     d
 *    / \
 *   e   g
 *  / \
 * f   h
 * ```
 * <span style="color:#DF5A00;font-size:larger">
 * 求e的parent\n\n
 * </span>
 *
 * <span style="color:#D40000;font-size:larger">
 * 前驱路径:\n
 * &emsp; 先遍历到f, 找f的前驱a, a不是e的父结点, 找a->right_child结点b, b也不是e的父结点, 因此左侧路径未找到e的父结点\n\n
 * 后继路径:\n
 * &emsp; 先遍历到h, 找h的后继d, 返回d(d就是e的父结点)\n
 * </span>
 *
 * -------
 * + **1 空结点处理**\n
 * **if** 空节点 :\n
 * &emsp; 抛出invalid_argument错误\n\n
 * + **2 根结点处理**\n
 * **if** node为根结点 :\n
 * &emsp; 返回NULL\n\n
 * + **3 通过前驱寻找父节点**\n
 * 初始化cur<span style="color:#DF5A00">(遍历指针)</span>指向node\n
 * **while loop** cur->left_tag为孩子结点指针 :\n
 * &emsp;cur指向自身左孩子\n\n
 * 初始化upper_level_pre_node (上层前驱结点) 指向cur->left_child(指向上层前驱)\n\n
 * **if** left_side_child->left_child不为NULL(此时存在前驱) :\n
 * &emsp; **if** upper_level_pre_node->right_child不是node :\n
 * &emsp;&emsp; upper_level_pre_node指向自身右孩子\n\n
 * &emsp; **if** upper_level_pre_node不为NULL && upper_level_pre_node是node的父结点 :\n
 * &emsp;&emsp; 返回upper_level_pre_node\n\n
 * + **4 通过后继寻找父节点**\n
 * cur指向node\n
 * **while loop** cur->right_tag为孩子结点指针 :\n
 * &emsp; cur指向自身右孩子\n\n
 * upper_level_post_node (上层后继结点) 指向cur的右孩子(指向上层后继)\n\n
 * 返回upper_level_post_node\n
 */
template <typename TData>
ThreadedNode<TData>* InorderThreadedBinaryTree<TData>::Parent(ThreadedNode<TData>* node) {

    // ---------- 1 空结点处理 ----------

    if (!node) {                                                                    // if 空节点
        throw invalid_argument("NULL pointer");                                     // 抛出invalid_argument错误
    }

    // ---------- 2 根结点处理 ----------

    if (node == root_) {                                                            // if node为根结点
        return NULL;                                                                // 返回NULL
    }

    // ---------- 3 通过前驱寻找父节点 ----------

    ThreadedNode<TData>* cur = node;                                                // 初始化cur(遍历指针)指向node
    while (cur->left_tag == CHILD_POINTER) {                                        // while loop cur->left_tag为孩子结点指针
        cur = cur->left_child;                                                      // cur指向自身左孩子
    }

    ThreadedNode<TData>* upper_level_pre_node = cur->left_child;                    // 初始化upper_level_pre_node (上层前驱结点) 指向cur->left_child(指向上层前驱)

    if (upper_level_pre_node != NULL) {                                             // if left_side_child->left_child不为NULL(此时存在前驱)

        if (upper_level_pre_node->right_child != node) {                            // if upper_level_pre_node->right_child不是node
            upper_level_pre_node = upper_level_pre_node->right_child;               // upper_level_pre_node指向自身右孩子
        }

        if (upper_level_pre_node != NULL &&                                         // if upper_level_pre_node不为NULL && upper_level_pre_node是node的父结点
            (upper_level_pre_node->left_child == node ||
             upper_level_pre_node->right_child == node)
           )
        {
            return upper_level_pre_node;                                            // 返回upper_level_pre_node
        }
    }

    // ---------- 4 通过后继寻找父节点 ----------

    cur = node;                                                                     // cur指向node
    while (cur->right_tag == CHILD_POINTER) {                                       // while loop cur->right_tag为孩子结点指针
        cur = cur->right_child;                                                     // cur指向自身右孩子
    }

    ThreadedNode<TData>* upper_level_post_node = cur->right_child;                  // upper_level_post_node (上层后继结点) 指向cur的右孩子(指向上层后继)

    return upper_level_post_node;                                                   // 返回upper_level_post_node
}


/*!
 * @brief **子树插入(建立线索之前)**
 * @tparam TData 数据项类型模板参数
 * @param subtree_root 子树根结点
 * @param data 数据项
 * @return 执行结果
 * @note
 * 子树插入(建立线索之前)
 * ------------------
 * ------------------
 *
 * ------------------
 * + **1 空子树插入**\n
 * **if** 空子树 :\n
 * &emsp; 分配内存并初始化subtree_root(子树根结点)\n
 * &emsp; **if** 内存分配失败 :\n
 * &emsp;&emsp; 抛出bad_alloc()\n\n
 * &emsp; 返回true\n\n
 * + **2 非空子树插入**\n
 * 获取left_subtree_height(左子树高度)\n
 * 获取right_subtree_height(右子树高度)\n\n
 * **if** 获取left_subtree_height > right_subtree_height :\n
 * &emsp; 在右子树递归调用InsertInSubTreeRecursive_, 执行插入\n
 * **else**\n
 * &emsp; 在左子树递归调用InsertInSubTreeRecursive_, 执行插入\n
 */
template<typename TData>
bool InorderThreadedBinaryTree<TData>::InsertInSubTreeRecursive_(ThreadedNode<TData>*& subtree_root,
                                                                 const TData& data)
{

    // ---------- 1 空子树插入 ----------

    if (subtree_root == NULL) {                                                             // if 空子树
        subtree_root = new ThreadedNode<TData>(data);                                       // 分配内存并初始化subtree_root(子树根结点)
        if (!subtree_root) {                                                                // if 内存分配失败
            throw bad_alloc();                                                              // 抛出bad_alloc()
        }

        return true;                                                                        // 返回true
    }

    // ---------- 2 非空子树插入 ----------

    int left_subtree_height = HeightOfSubTree(subtree_root->left_child);                    // 获取left_subtree_height(左子树高度)
    int right_subtree_height = HeightOfSubTree(subtree_root->right_child);                  // 获取right_subtree_height(右子树高度)

    if (left_subtree_height > right_subtree_height) {                                       // if 获取left_subtree_height > right_subtree_height
        return InsertInSubTreeRecursive_(subtree_root->right_child, data);                  // 在右子树递归调用InsertInSubTreeRecursive_, 执行插入
    } else {                                                                                // else
        return InsertInSubTreeRecursive_(subtree_root->left_child, data);                   // 在左子树递归调用InsertInSubTreeRecursive_, 执行插入
    }
}


/*!
 * @brief **求子树高度**
 * @tparam TData 数据项类型模板参数
 * @param subtree_root 子树根结点
 * @return 高度
 * @note
 * 求子树高度
 * --------
 * --------
 *
 * --------
 * + **1 空树处理**\n
 * **if** 空子树 :\n
 * &emsp; 返回0\n
 * + **2 非空树处理**\n
 * 获取left_subtree_height(左子树高度)\n
 * 获取right_subtree_height(右子树高度)\n\n
 * 返回最高子树的高度加1\n
 */
template<typename TData>
int HeightOfSubTree(ThreadedNode<TData>* subtree_root) {

    // ---------- 1 空树处理 ----------

    if (subtree_root == NULL) {                                                                             // if 空子树
        return 0;                                                                                           // 返回0
    }

    // ---------- 2 非空树处理 ----------

    int left_subtree_height = HeightOfSubTree(subtree_root->left_child);                                    // 获取left_subtree_height(左子树高度)
    int right_subtree_height = HeightOfSubTree(subtree_root->right_child);                                  // 获取right_subtree_height(右子树高度)

    return (left_subtree_height < right_subtree_height ? right_subtree_height : left_subtree_height) + 1;   // 返回最高子树的高度加1
}


#endif // CYBER_DASH_INORDER_THREADED_BINARY_TREE_H
