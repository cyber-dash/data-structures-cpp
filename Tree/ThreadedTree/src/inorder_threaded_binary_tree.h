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
    bool InsertRecursive(const TData& data) { return InsertInSubTreeRecursive_(root_, data);}

    // 创建中序线索
    void CreateThreadRecursive();
    // 中序线索第一个线索结点
    ThreadedNode<TData>* First(ThreadedNode<TData>* subtree_root);
    // 求(node为根的)当前二叉树的最后一个线索节点的节点指针
    ThreadedNode<TData>* Last(ThreadedNode<TData>* subtree_root);
    // 中序线索下一个线索结点
    ThreadedNode<TData>* Next(ThreadedNode<TData>* node);
    // 中序线索前一个线索结点
    ThreadedNode<TData>* Pre(ThreadedNode<TData>* node);
    // 中序线索父结点
    ThreadedNode<TData>* Parent(ThreadedNode<TData>* node_ptr) { return Parent_(node_ptr); }
    // 中序线索二叉树中序遍历
    void InorderTraverse(void (*visit)(ThreadedNode<TData>* node_ptr));
    // 中序线索二叉树前序遍历
    void PreorderTraverse(void (*visit)(ThreadedNode<TData>* node_ptr));
    // 中序线索二叉树后序遍历
    void PostOrderTraverse(void (*visit)(ThreadedNode<TData> *p));
    // 中序线索二叉子树, 找到后续遍历第一个结点(书中未实现)
    ThreadedNode<TData>* GetFirstNodeForPostorderTraverse(ThreadedNode<TData>* node);

protected:
    ThreadedNode<TData>* root_;
    // 子树创建中序线索
    void CreateThreadInSubtreeRecursive_(ThreadedNode<TData>*& subtree_root, ThreadedNode<TData>*& pre_node);
    // 父节点指针
    ThreadedNode<TData>* Parent_(ThreadedNode<TData>* node);
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
 * &emsp; 抛出invalid_argument("NULL pointer")\n
 * + **2 获取结点**\n
 * 初始化cur(遍历指针), 指向subtree_root\n\n
 * **while loop** cur存在左孩子 && cur->left_tag属性为CHILD_POINTER :\n
 * &emsp; cur指向cur->left_child\n\n
 * + **3 返回结果**\n
 * 返回cur\n
 */
template <typename TData>
ThreadedNode<TData>* InorderThreadedBinaryTree<TData>::First(ThreadedNode<TData>* subtree_root) {
    if (!subtree_root) {
        throw invalid_argument("NULL pointer");
    }

    ThreadedNode<TData>* cur = subtree_root;

    while (cur->left_child != NULL && cur->left_tag == CHILD_POINTER) {
        cur = cur->left_child;
    }

    return cur;
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
    if (node->right_tag == THREADED_NODE_POINTER) {
        return node->right_child;
    }

    return First(node->right_child);
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
    if (!subtree_root) {
        throw invalid_argument("NULL pointer");
    }

    ThreadedNode<TData>* cur = subtree_root;

    while (cur->right_child != NULL && cur->right_tag == CHILD_POINTER) {
        cur = cur->right_child;
    }

    return cur;
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
    if (node->left_tag == THREADED_NODE_POINTER) {  // if node的left_tag属性, 是THREADED_NODE_POINTER(线索结点指针)
        return node->left_child;                    // 返回node->left_child
    }

    return Last(node->left_child);                  // 返回Last(node->left_child)
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
 * &emsp; visit(cur)\n
 */
template <typename TData>
void InorderThreadedBinaryTree<TData>::InorderTraverse(void (*visit)(ThreadedNode<TData>* node)) {
    for (ThreadedNode<TData>* cur = First(root_); cur != NULL; cur = Next(cur)) {
        visit(cur);
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
 * @param visit 访问函数
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
void InorderThreadedBinaryTree<TData>::PreorderTraverse(void (*visit)(ThreadedNode<TData>*)) {
    ThreadedNode<TData>* cur = root_;

    while (cur != NULL) {
        visit(cur);

        if (cur->left_tag == CHILD_POINTER) {
            cur = cur->left_child;
        } else if (cur->right_tag == CHILD_POINTER) {
            cur = cur->right_child;
        } else {
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
 * @brief 后序遍历
 * @tparam TData 数据项类型模板参数
 * @param visit
 * @note
 * 重复下述过程, 直到叶结点为止:
 *    从根出发, 沿着左子树链一直找下去, 找到左孩子不再是做孩子指针的结点
 *    再找到该结点的右孩子, 以此结点为根的子树上,
 * 接着, 从此结点开始后序遍历, 每次先找到当前节点的父节点
 *    如果当前结点是父节点的右孩子or虽然是这个父节点的左孩子, 但这个父节点没有右孩子
 *       则后序下的后继为该父节点
 *    否则, 在当前结点的右子树(如果存在)上重复执行上面的操作
 */
template <typename TData>
void InorderThreadedBinaryTree<TData>::PostOrderTraverse(void (*visit)(ThreadedNode<TData>*)) {

    ThreadedNode<TData>* cur = GetFirstNodeForPostorderTraverse(root_);
    ThreadedNode<TData>* cur_parent;

    visit(cur); // 访问第一个结点

    while ((cur_parent = Parent_(cur)) != NULL) {
        if (cur_parent->right_child == cur ||  // 当前结点是父节点的右孩子
            cur_parent->right_tag == THREADED_NODE_POINTER) // 当前结点是父节点左孩子, 并且父节点没有右孩子
        {
            cur = cur_parent;
        } else {
            cur = GetFirstNodeForPostorderTraverse(cur_parent->right_child);
        }

        visit(cur);
    }
}


/**
 * @brief 中序线索树后续遍历, 找到第一个遍历结点(以node_ptr为根)
 * @tparam TData
 * @param node
 * @return
 * @note
 * 重复下述过程, 直到叶结点为止:
 *    沿着左子树链一直找下去, 找到左孩子不再是做孩子指针的结点
 *    再找到该结点的右孩子, 以此结点为根的子树上,
 */
template<class TData>
ThreadedNode<TData>* InorderThreadedBinaryTree<TData>::GetFirstNodeForPostorderTraverse(ThreadedNode<TData>* node) {

    ThreadedNode<TData>* cur = node;

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
 * @tparam TData 类型模板参数
 * @param node 结点指针
 * @return 父结点
 * @note
 * 两条路径:
 *   1: 从当前结点走到树上层的一个中序前驱(不一定是直接前驱), 然后向右下找父节点
 *   2: 从当前结点走到书上层的一个中序后继(不一定是直接后继), 然后向左下找父节点
 */
template <class TData>
ThreadedNode<TData>* InorderThreadedBinaryTree<TData>::Parent_(ThreadedNode<TData>* node) {

    if (node == root_) {
        return NULL;
    }

    /* 尝试路径1 */
    // 遍历至最左子节点
    ThreadedNode<TData>* left_side_child = node;
    while (left_side_child->left_tag == CHILD_POINTER) {
        left_side_child = left_side_child->left_child;
    }

    if (left_side_child->left_child != NULL) { // 如果等于NULL, 则寻找树上层的中序前驱失败, 路径1失败
        ThreadedNode<TData>* upper_level_pre_node = left_side_child->left_child; // 树上层的中序前驱

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
    ThreadedNode<TData>* right_side_child = node;
    while (right_side_child->right_tag == CHILD_POINTER) {
        right_side_child = right_side_child->right_child;
    }

    ThreadedNode<TData>* upper_level_post_node = right_side_child->right_child; // 树上层的中序后继

    // 向左下找父节点
    while (upper_level_post_node != NULL &&
           upper_level_post_node->left_child != node &&
           upper_level_post_node->right_child != node) {
        upper_level_post_node = upper_level_post_node->left_child;
    }

    return upper_level_post_node;
}


/*!
 * @brief **子树插入(建立线索之前)**
 * @tparam TData 数据项类型模板参数
 * @param subtree_root 子树根结点
 * @param data 数据项
 * @return 执行结果
 */
template<typename TData>
bool InorderThreadedBinaryTree<TData>::InsertInSubTreeRecursive_(ThreadedNode<TData>*& subtree_root,
                                                                 const TData& data)
{

    if (subtree_root == NULL) {
        subtree_root = new ThreadedNode<TData>(data);
        if (!subtree_root) {
            throw bad_alloc();
        }

        return true;
    }

    int left_subtree_height = Height(subtree_root->left_child);
    int right_subtree_height = Height(subtree_root->right_child);

    if (left_subtree_height > right_subtree_height) {
        return InsertInSubTreeRecursive_(subtree_root->right_child, data);
    } else {
        return InsertInSubTreeRecursive_(subtree_root->left_child, data);
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



#endif // CYBER_DASH_INORDER_THREADED_BINARY_TREE_H
