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
     * 调用CreateSubTreeByPreorderStrRecursive_\n
     */
    void CreateByPreorderStr(TData*& str) { this->CreateSubTreeByPreorderStrRecursive_(this->root_, str); }

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
    int HeightRecursive() { return this->MaxHeightWithYoungerSiblingTreesRecursive_(this->root_); }

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
    void LevelOrderOfSubTree_(ChildSiblingNode<TData>* subtree_root, void (*visit)(ChildSiblingNode<TData>*));
    // 使用字符串创建子女兄弟树
    void CreateSubTreeByPreorderStrRecursive_(ChildSiblingNode<TData>*&, TData*& str);
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


/*!
 * @brief **子树先根遍历(递归)**
 * @tparam TData 数据项类型模板参数
 * @param subtree_root 子树根结点
 * @param visit 结点访问函数
 * @note
 * 子树先根遍历(递归)
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 空树处理**\n
 * **if** 空树 :\n
 * &emsp; 返回\n
 * + **2 递归**\n
 * 访问当前子树根结点\n
 * 对长子结点递归后根遍历\n
 * 对下一兄弟结点递归后根遍历\n
 */
template <typename TData>
void ChildSiblingTree<TData>::PreOrderOfSubTreeRecursive_(ChildSiblingNode<TData>* subtree_root,
                                                          void (*visit)(ChildSiblingNode<TData>*))
{
    // ---------- 1 空树处理 ----------

    if (subtree_root == NULL) { // if 空树
        return;                 // 返回
    }

    // ---------- 2 递归 ----------

    // 访问当前子树根结点
    visit(subtree_root);
    // 对长子结点递归后根遍历
    PreOrderOfSubTreeRecursive_(subtree_root->first_child, visit); // 对长子结点进行递归
    // 对下一兄弟结点递归后根遍历
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
 * + **1 空树处理**\n
 * **if** 空树 :\n
 * &emsp; 返回\n
 * + **2 递归**\n
 * 对长子结点递归后根遍历\n
 * 访问当前子树根结点\n
 * 对下一兄弟结点递归后根遍历\n
 */
template <typename TData>
void ChildSiblingTree<TData>::PostOrderOfSubTreeRecursive_(ChildSiblingNode<TData>* subtree_root,
                                                           void (*visit)(ChildSiblingNode<TData>*))
{
    // ---------- 1 空树处理 ----------

    if (subtree_root == NULL) { // if 空树
        return;                 // 返回
    }

    // ---------- 2 递归 ----------

    // 对长子结点递归后根遍历
    PostOrderOfSubTreeRecursive_(subtree_root->first_child, visit);
    // 访问当前子树根结点
    visit(subtree_root);
    // 对下一兄弟结点递归后根遍历
    PostOrderOfSubTreeRecursive_(subtree_root->next_sibling, visit);
}


/*!
 * @brief **子树层序遍历**
 * @tparam TData 数据项类型模板参数
 * @param subtree_root 子树根节点
 * @param visit 结点访问函数
 * @note
 * 子树层序遍历
 * ----------
 * ----------
 *
 * ----------
 * + **1 空树处理**\n
 * **if** 空树 :\n
 * &emsp; 返回\n
 * + **2 队列初始化**\n
 * 声明node_queue(结点队列)\n
 * 子树根结点入队\n
 * + **3 使用队列进行遍历**\n
 * **while loop** 队列不为空 :\n
 * &emsp; 取队头结点front_node\n
 * &emsp; 队头出队\n
 * &emsp; 访问结点\n
 * &emsp; **while loop** 遍历front_node的所有孩子结点 :\n
 * &emsp;&emsp; 当前孩子结点入队\n
 */
template <typename TData>
void ChildSiblingTree<TData>::LevelOrderOfSubTree_(ChildSiblingNode<TData>* subtree_root,
                                                   void (*visit)(ChildSiblingNode<TData>*))
{
    // ---------- 1 空树处理 ----------

    if (subtree_root == NULL) {                                    // if 空树
        return;                                                    // 返回
    }

    // ---------- 2 队列初始化 ----------

    queue<ChildSiblingNode<TData>*> node_queue;                    // 声明node_queue(结点队列)
    node_queue.push(subtree_root);                                 // 子树根结点入队

    // ---------- 3 使用队列进行遍历 ----------

    while (!node_queue.empty()) {                                   // while loop 队列不为空
        ChildSiblingNode<TData>* front_node = node_queue.front();   // 取队头结点front_node
        node_queue.pop();                                           // 队头出队

        visit(front_node);                                          // 访问结点

        // while loop 遍历front_node的所有孩子结点
        for (ChildSiblingNode<TData>* cur = front_node->first_child; cur != NULL; cur = cur->next_sibling) {
            node_queue.push(cur);                                // 当前孩子结点入队
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
 * 求self_height, 自身(以node为根结点的子树)的高度\n
 * 求max_younger_sibling_height, 所有弟弟子树的最大的高度\n
 * 取max_height, 为MAX(self_height, max_younger_sibling_height)\n
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
 * @brief **创建子女兄弟树(使用先根遍历字符串)(递归)**
 * @tparam TData 数据项类型模板参数
 * @param subtree_root 子树根节点
 * @param str 先根遍历字符串
 * @note
 * 创建子女兄弟树(使用先根遍历字符串)(递归)
 * ----------------------------------
 * ----------------------------------
 *
 * ----------------------------------
 * + **1 建树结束处理**\n
 * **if** 当前字符为'\0' :\n
 * &emsp; 返回(建树完成)\n
 * \n
 * + **2 某子树结束处理**\n
 * **if** 当前字符为')' :\n
 * &emsp; str向后移动1位(处理下一个兄弟结点)\n
 * &emsp; 返回(当前子树建树完成)\n
 * \n
 * + **3 新子树根结点开始处理**\n
 * **if** 当前字符为'(' :\n
 * &emsp; str向后移动1位(处理下一个兄弟结点)\n
 * \n
 * + **4 创建新子树根结点**\n
 * **if** int类型 :\n
 * &emsp; 进行转换\n
 * **else if** char类型 :\n
 * &emsp; 用*转换进行赋值\n
 * str向后移动1位(处理下一个兄弟结点)\n
 * \n
 * 初始化subtree_root(子树根结点)并分配内存\n
 * **if** 内存分配失败 :\n
 * &emsp; 抛出bad_alloc()\n
 * \n
 * + **5 对长子结点和兄弟节点递归构造子树**\n
 * 对first_child递归创建子树\n
 * 对next_sibling递归创建子树\n
 */
template <typename TData>
void ChildSiblingTree<TData>::CreateSubTreeByPreorderStrRecursive_(ChildSiblingNode<TData>*& subtree_root, TData*& str) {

    // ---------- 1 建树结束处理 ----------

    if (*str == TData('\0')) {                              // if 当前字符为'\0'
        return;                                             // 返回(建树完成)
    }

    // ---------- 2 某子树结束处理 ----------

    if (*str == TData(')')) {                               // if 当前字符为')'
        str++;                                              // str向后移动1位(处理下一个兄弟结点)
        return;                                             // 返回(当前子树建树完成)
    }

    // ---------- 3 新子树根结点开始处理 ----------

    while (*str == TData('(')) {                            // if 当前字符为'('
        str++;                                              // str向后移动1位(处理下一个兄弟结点)
    }

    // ---------- 4 创建新子树根结点 ----------

    TData cur_data;
    if (is_same<TData, int>::value) {                       // if int类型
        cur_data = (TData)(*str - '0');                     // 进行转换
    } else if (is_same<TData, char>::value) {               // else if char类型
        cur_data = *str;                                    // 用*转换进行赋值
    }

    str++;                                                  // str向后移动1位(处理下一个兄弟结点)

    subtree_root = new ChildSiblingNode<TData>(cur_data);   // 初始化subtree_root(子树根结点)并分配内存
    if (!subtree_root) {                                    // if 内存分配失败
        throw bad_alloc();                                  // 抛出bad_alloc()
    }

    // ---------- 5 对长子结点和兄弟节点递归构造子树 ----------

    // 对first_child递归创建子树
    CreateSubTreeByPreorderStrRecursive_(subtree_root->first_child, str);
    // 对next_sibling递归创建子树
    CreateSubTreeByPreorderStrRecursive_(subtree_root->next_sibling, str);
}


/*!
 * @brief **子树打印(递归)**
 * @tparam TData 数据项类型模板参数
 * @param subtree_root 子树根结点
 * @note
 * 子树打印(递归)
 * ------------
 * ------------
 *
 * ------------
 * + **1 空树处理**\n
 * **if** 空树 :\n
 * &emsp; 返回\n
 * + **2 打印'('和子树根结点**\n
 * 打印'('\n
 * 打印子树根结点\n
 * + **3 递归打印所有孩子结点的子树**\n
 * **for loop** 子树根结点的所有孩子结点 :\n
 * &emsp; 递归打印以当前孩子结点为根结点的子树\n
 * + **4 打印')'**\n
 */
template <typename TData>
void ChildSiblingTree<TData>::PrintSubTreeRecursive_(ChildSiblingNode<TData>* subtree_root) {

    // ---------- 1 空树处理 ----------

    if (subtree_root == NULL) {                       // if 空树
        return;                                       // 返回
    }

    // ---------- 2 打印'('和子树根结点 ----------

    cout << '(';                                      // 打印'('
    cout << subtree_root->data;                       // 打印子树根结点

    // ---------- 3 递归打印所有孩子结点的子树 ----------

    // for loop 子树根结点的所有孩子结点
    for (ChildSiblingNode<TData>* cur = subtree_root->first_child; cur != NULL; cur = cur->next_sibling) {
        PrintSubTreeRecursive_(cur);    // 递归打印以当前孩子结点为根结点的子树
    }

    // ---------- 4 打印')' ----------

    cout << ')';
}


#endif // CYBER_DASH_CHILD_SIBLING_TREE_H
