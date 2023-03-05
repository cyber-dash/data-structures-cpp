/*!
 * @file child_sibling_tree.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 子女兄弟树模板类
 * @version 0.2.1
 * @date 2020-11-01
 */

#ifndef CYBER_DASH_CHILD_SIBLING_TREE_H
#define CYBER_DASH_CHILD_SIBLING_TREE_H


#include <cstdlib>
#include <iostream>
#include <queue>


using namespace std;


/*!
 * @brief **子女兄弟树结点模板结构体**
 * @tparam TData 类型模板参数
 */
template <class TData>
struct ChildSiblingNode {
    /*!
     * @brief **构造函数(数据项/长子结点/下一兄弟结点)**
     * @param data 数据项
     * @param first_child 长子结点
     * @param next_sibling 下一兄弟结点
     * @note
     * 构造函数(数据项/长子结点/下一兄弟结点)
     * ---------------------------------
     * ---------------------------------
     *
     * ---------------------------------
     * 设置data, first_child和next_sibling
     */
    explicit ChildSiblingNode(TData data,
                              ChildSiblingNode<TData>* first_child = NULL,
                              ChildSiblingNode<TData>* next_sibling = NULL) :
        data(data), first_child(first_child), next_sibling(next_sibling) {}

    TData data;                             //!< 数据项
    ChildSiblingNode<TData>* first_child;    //!< 长子结点
    ChildSiblingNode<TData>* next_sibling;  //!< 下一兄弟结点
};


/*!
 * @brief **子女兄弟树模板类**
 * @tparam TData 数据项类型模板参数
 */
template <typename TData>
class ChildSiblingTree {
public:
    /*!
     * @brief **默认构造函数**
     * @note
     * 默认构造函数
     * ----------
     * ----------
     *
     * ----------
     * root_设为NULL
     */
    ChildSiblingTree() : root_(NULL) {}

    /*!
     * @brief **使用带"()"的先根遍历字符串创建子女兄弟树**
     * @param str 带"()"的先根遍历字符串
     * @note
     * 使用带"()"的先根遍历字符串创建子女兄弟树
     * ----------------------------------
     * ----------------------------------
     *
     * ----------------------------------
     */
    void CreateByPreorderStr(char*& str) { this->CreateTreeByStrRecursive_(this->root_, str); }

    /*!
     * @brief 获取长子结点
     * @return 长子结点
     */
    ChildSiblingNode<TData>*& FirstChild();

    /*!
     * @brief 获取下一个兄弟
     * @return 下一兄弟结点
     */
    ChildSiblingNode<TData>*& NextSibling();

    /*!
     * @brief **判断是否空树**
     * @return 是否空树
     */
    bool Empty() { return this->root_ == NULL; }

    /*!
     * @brief **获取结点数(递归)**
     * @return 结点数
     * 获取结点数(递归)
     * --------------
     * --------------
     *
     * --------------
     * 对根结点调用NodeCountOfSubTreeRecursive_, 返回结果
     */
    int NodeCountRecursive() { return this->NodeCountOfSubTreeRecursive_(this->root_); }

    /*!
     * @brief **获取高度(递归)**
     * @return 高度
     * @note
     * 获取高度(递归)
     * ------------
     * ------------
     *
     * ------------
     * 对根结点调用HeightOfSubTreeRecursive_, 返回结果
     */
    int Height() { return this->MaxHeightWithYoungerSiblingTreesRecursive_(this->root_); }

    /*!
     * @brief **获取根结点**
     * @return 根结点
     */
    ChildSiblingNode<TData>* Root() { return this->root_; }

    /*!
     * @brief **前序遍历**
     * @param visit 结点访问函数
     * @note
     * 前序遍历
     * -------
     * -------
     *
     * -------
     * 对root_调用PreOrderInSubTreeRecursive_
     */
    void PreOrderRecursive(void (*visit)(ChildSiblingNode<TData>*)) { PreOrderOfSubTreeRecursive_(root_, visit); }

    /*!
     * @brief **后序遍历**
     * @param visit 结点访问函数
     * @note
     * 后序遍历
     * -------
     * -------
     *
     * -------
     * 对root_调用PostOrderInSubTreeRecursive_
     */
    void PostOrder(void (*visit)(ChildSiblingNode<TData>*)) { PostOrderOfSubTreeRecursive_(root_, visit); }

    /*!
     * @brief **层序遍历**
     * @param visit 结点访问函数
     * @note
     * 层序遍历
     * -------
     * -------
     *
     * -------
     * 对root_调用LevelOrderInSubTreeRecursive_
     */
    void LevelOrder(void (*visit)(ChildSiblingNode<TData>*)) { LevelOrderOfSubTree_(root_, visit); }

    /*!
     * @brief **打印(递归)**
     * @note
     * 打印(递归)
     * ---------
     * ---------
     *
     * ---------
     * 对root_调用PrintSubTreeRecursive_
     */
    void PrintRecursive() { this->PrintSubTreeRecursive_(this->root_); }
private:
    ChildSiblingNode<TData>* root_; //!< 根结点

    // 子树删除(递归)
    void RemoveSubTreeRecursive_(ChildSiblingNode<TData>* subtree_root);

    // 子树先根遍历(递归)
    void PreOrderOfSubTreeRecursive_(ChildSiblingNode<TData>* subtree_root, void (*visit)(ChildSiblingNode<TData>*));
    // 子树后根遍历(递归)
    void PostOrderOfSubTreeRecursive_(ChildSiblingNode<TData>* subtree_root, void (*visit)(ChildSiblingNode<TData>*));
    // 子树层序遍历
    void LevelOrderOfSubTree_(ChildSiblingNode<TData>* sub_tree_root, void (*visit)(ChildSiblingNode<TData>*));
    // 使用字符串创建子女兄弟树
    void CreateTreeByStrRecursive_(ChildSiblingNode<TData>*&, char*& str);
    // 子树节点数量(递归)
    int NodeCountOfSubTreeRecursive_(ChildSiblingNode<TData>* subtree_root);
    // 子树深度(递归)
    int MaxHeightWithYoungerSiblingTreesRecursive_(ChildSiblingNode<TData>* subtree_root);
    // 子树打印(递归)
    void PrintSubTreeRecursive_(ChildSiblingNode<TData>* subtree_root);
};


/*!
 * @brief **子树删除(递归)**
 * @tparam TData 数据项类型模板参数
 * @param subtree_root 子树根结点
 * @note
 * 子树删除(递归)
 * ------------
 * ------------
 *
 * 删除整个子树
 *
 * ------------
 * + **1 空树处理**\n
 * **if** 空子树 :\n
 * &emsp; 返回\n
 * + **2 递归**\n
 * 对长子结点, 递归调用RemoveSubTreeRecursive_\n
 * 对下一兄弟结点, 递归调用RemoveSubTreeRecursive_\n
 * + **3 删除根结点**\n
 * 释放subtree_root\n
 */
template<typename TData>
void ChildSiblingTree<TData>::RemoveSubTreeRecursive_(ChildSiblingNode<TData>* subtree_root) {

    // ---------- 1 空树处理 ----------

    if (subtree_root == NULL) {     // if 空子树
        return;                     // 返回
    }

    // ---------- 2 递归 ----------

    // 对长子结点, 递归调用RemoveSubTreeRecursive_
    this->RemoveSubTreeRecursive_(subtree_root->first_child);
    // 对下一兄弟结点, 递归调用RemoveSubTreeRecursive_
    this->RemoveSubTreeRecursive_(subtree_root->next_sibling);

    // ---------- 3 删除根结点 ----------

    delete subtree_root;            // 释放subtree_root
}


template <typename TData>
ChildSiblingNode<TData>*& ChildSiblingTree<TData>::FirstChild() {
    return this->root_->first_child;
}


template <class TData>
ChildSiblingNode<TData>*& ChildSiblingTree<TData>::NextSibling() {
    return this->root_->next_sibling;
}


/*!
 * @brief 子树先根遍历
 * @tparam TData 数据项类型模板参数
 * @param subtree_root 子树根结点
 * @param visit 遍历函数
 */
template <typename TData>
void ChildSiblingTree<TData>::PreOrderOfSubTreeRecursive_(ChildSiblingNode<TData>* subtree_root,
                                                          void (*visit)(ChildSiblingNode<TData>*))
{
    if (subtree_root == NULL) {
        return;
    }

    visit(subtree_root);

    PreOrderOfSubTreeRecursive_(subtree_root->first_child, visit); // 对长子结点进行递归
    PreOrderOfSubTreeRecursive_(subtree_root->next_sibling, visit); // 对兄弟结点进行递归
}


/*!
 * @brief **子树后根遍历(递归)**
 * @tparam TData 数据项类型模板参数
 * @param subtree_root 子树根结点
 * @param visit 访问函数
 * @note
 * 子树后根遍历(递归)
 * ----------------
 * ----------------
 *
 * ----------------
 */
template <typename TData>
void ChildSiblingTree<TData>::PostOrderOfSubTreeRecursive_(ChildSiblingNode<TData>* subtree_root,
                                                           void (*visit)(ChildSiblingNode<TData>*))
{
    if (subtree_root == NULL) {
        return;
    }

    PostOrderOfSubTreeRecursive_(subtree_root->first_child, visit);
    visit(subtree_root);
    PostOrderOfSubTreeRecursive_(subtree_root->next_sibling, visit);
}


/*!
 * @brief 在子树中层序遍历
 * @tparam TData 类型模板参数
 * @param out 输出流
 * @param sub_tree_root 子树根节点
 */
template <class TData>
void ChildSiblingTree<TData>::LevelOrderOfSubTree_(ChildSiblingNode<TData>* sub_tree_root, void (*visit)(ChildSiblingNode<TData>*)) {
    queue<ChildSiblingNode<TData>*> node_queue;

    if (sub_tree_root == NULL) {
        return;
    }

    // 初始化队列node_queue
    node_queue.push(sub_tree_root);

    while (!node_queue.empty()) {
        // 取队头
        ChildSiblingNode<TData>* front_node = node_queue.front();
        node_queue.pop();

        // 输出流输出
        visit(front_node);

        // 队头节点的所有孩子节点入队
        for (ChildSiblingNode<TData>* cur = front_node->first_child; cur != NULL; cur = cur->next_sibling) {
            node_queue.push(cur);
        }
    }
}


/*!
 * @brief **子树节点数量(递归)**
 * @tparam TData 数据项类型模板参数
 * @param subtree_root 子树根结点
 * @return 节点数量
 * @note
 * 子树节点数量(递归)
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 空树处理**\n
 * **if** 空树 :\n
 * &emsp; 返回0\n
 * + **2 递归**\n
 * 初始化node_count为1(1个子树根结点)\n
 * 递归获取first_child(长子结点)对应的子树的结点数, 加到node_count\n
 * 递归获取next_sibling(下一兄弟结点)对应的子树的结点数, 加到node_count\n
 * + **3 返回结果**\n
 * 返回count\n
 */
template <typename TData>
int ChildSiblingTree<TData>::NodeCountOfSubTreeRecursive_(ChildSiblingNode<TData>* subtree_root) {

    // ---------- 1 空树处理 ----------

    if (subtree_root == NULL) {     // if 空树
        return 0;                   // 返回0
    }

    // ---------- 2 递归 ----------

    int node_count = 1;             // 初始化node_count为1(1个子树根结点)

    // 递归获取first_child(长子结点)对应的子树的结点数, 加到node_count
    node_count += NodeCountOfSubTreeRecursive_(subtree_root->first_child);
    // 递归获取next_sibling(下一兄弟结点)对应的子树的结点数, 加到node_count
    node_count += NodeCountOfSubTreeRecursive_(subtree_root->next_sibling);

    // ---------- 3 返回结果 ----------

    return node_count;              // 返回count\n
}


/*!
 * @brief **自身和所有弟弟子树的最大高度(递归)**
 * @tparam TData 数据项类型模板参数
 * @param subtree_root 子树根结点
 * @return 高度
 * 自身和所有弟弟子树的最大高度(递归)
 * -----------------------------
 * -----------------------------
 *
 * -----------------------------
 * + **1 空树处理**\n
 * **if** 空树 :\n
 * &emsp; 返回0\n
 * + **2 递归**\n
 * 求self_height, 自身(以node为根结点的子树)的高度
 * 求max_younger_sibling_height, 所有弟弟子树的最大的高度
 * 取max_height, 为MAX(self_height, max_younger_sibling_height)
 * + **3 返回结果**\n
 * 返回max_height\n
 */
template <typename TData>
int ChildSiblingTree<TData>::MaxHeightWithYoungerSiblingTreesRecursive_(ChildSiblingNode<TData>* subtree_root) {
    // ---------- 1 空树处理 ----------

    if (subtree_root == NULL) {     // if 空树
        return 0;                   // 返回0
    }

    // ---------- 2 递归 ----------

    // 求self_height, 自身(以node为根结点的子树)的高度
    int self_height = MaxHeightWithYoungerSiblingTreesRecursive_(subtree_root->first_child) + 1;
    // 求max_younger_sibling_height, 所有弟弟子树的最大的高度
    int max_younger_sibling_height = MaxHeightWithYoungerSiblingTreesRecursive_(subtree_root->next_sibling);

    // 取max_height, 为MAX(self_height, max_younger_sibling_height)
    int max_height = (self_height > max_younger_sibling_height) ? self_height : max_younger_sibling_height;

    // ---------- 3 返回结果 ----------
    return max_height;              // 返回max_height
}


/*!
 * @brief **创建子女兄弟树(使用字符串)(递归)**
 * @tparam TData 类型模板参数
 * @param sub_tree_root 子树根节点
 * @param str 字符串
 * @note
 * 创建子女兄弟树(使用字符串)(递归)
 * ---------------------------
 * ---------------------------
 *
 * ---------------------------
 */
template <class TData>
void ChildSiblingTree<TData>::CreateTreeByStrRecursive_(ChildSiblingNode<TData>*& sub_tree_root, char*& str) {
    /// ### 1 字符串遍历结束处理 ###
    if (*str == '\0') {
        return;
    }

    /// ### 2 节点结束处理 ###
    if (*str == ')') {
        str++; // 下一个兄弟节点
        return;
    }

    /// ### 3 节点开始处理 ###
    while (*str == '(') {
        str++;
    }

    /// ### 4 数据项赋值 ###
    TData cur_data;
    if (is_same<TData, int>::value) {
        cur_data = (TData)(*str - '0');
    } else if (is_same<TData, char>::value) {
        cur_data = *str;
    }
    str++;

    sub_tree_root = new ChildSiblingNode<TData>(cur_data);
    /* error handler */

    /// ### 5 递归 ###
    CreateTreeByStrRecursive_(sub_tree_root->first_child, str);
    CreateTreeByStrRecursive_(sub_tree_root->next_sibling, str);
}


/*!
 * @brief 子树打印(递归)
 * @tparam TData 数据项类型模板参数
 * @param subtree_root 子树根结点
 * @note
 * 子树打印(递归)
 * ------------
 * ------------
 *
 * ------------
 */
template <typename TData>
void ChildSiblingTree<TData>::PrintSubTreeRecursive_(ChildSiblingNode<TData>* subtree_root) {
    if (subtree_root == NULL) {
        return;
    }

    cout << '(';

    cout << subtree_root->data;

    for (ChildSiblingNode<TData>* cur = subtree_root->first_child; cur != NULL; cur = cur->next_sibling) {
        PrintSubTreeRecursive_(cur);
    }

    cout << ')';
}


#endif // CYBER_DASH_CHILD_SIBLING_TREE_H
