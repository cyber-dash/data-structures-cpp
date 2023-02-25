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
    ChildSiblingNode<TData>* next_sibling;  //!< 兄弟结点
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

    ChildSiblingNode<TData>* FirstChild();
    ChildSiblingNode<TData>* NextSibling();

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
    int Height() { return this->HeightOfSubTreeRecursive_(this->root_); }

    /*!
     * @brief **获取根结点**
     * @return 根结点
     */
    ChildSiblingNode<TData>* Root() { return this->root_; }
    void PreOrder(void (*visit)(ChildSiblingNode<TData>*)) { PreOrderInSubTreeRecursive_(root_, visit); }
    void PostOrder(void (*visit)(ChildSiblingNode<TData>*)) { PostOrderInSubTreeRecursive_(root_, visit); }
    void LevelOrder(void (*visit)(ChildSiblingNode<TData>*)) { LevelOrderInSubTree_(root_, visit); }
    void ShowTree() { this->ShowSubTreeRecursive_(this->root_); }
private:
    ChildSiblingNode<TData>* root_; //!< 根结点

    void RemoveSubTree_(ChildSiblingNode<TData>* sub_tree_root);

    // 在子树中进行先根遍历(递归)
    void PreOrderInSubTreeRecursive_(ChildSiblingNode<TData>* sub_tree_root, void (*visit)(ChildSiblingNode<TData>*));
    // 在子树中进行后根遍历(递归)
    void PostOrderInSubTreeRecursive_(ChildSiblingNode<TData>* sub_tree_root, void (*visit)(ChildSiblingNode<TData>*));
    // 在子树中层序遍历
    void LevelOrderInSubTree_(ChildSiblingNode<TData>* sub_tree_root, void (*visit)(ChildSiblingNode<TData>*));
    // 使用字符串创建子女兄弟树
    void CreateTreeByStrRecursive_(ChildSiblingNode<TData>*&, char*& str);
    // 子树节点数量(递归)
    int NodeCountOfSubTreeRecursive_(ChildSiblingNode<TData>* sub_tree_root);
    // 子树深度(递归)
    int HeightOfSubTreeRecursive_(ChildSiblingNode<TData>* sub_tree_root);
    // 打印子树(递归)
    void ShowSubTreeRecursive_(ChildSiblingNode<TData>* sub_tree_root);
};


/*!
 * @brief 删除子树
 * @tparam TData 类型模板参数
 * @param sub_tree_root 子树根结点
 */
template<class TData>
void ChildSiblingTree<TData>::RemoveSubTree_(ChildSiblingNode<TData>* sub_tree_root) {
    if (sub_tree_root == NULL) {
        return;
    }

    this->RemoveSubTree_(sub_tree_root->first_child);
    this->RemoveSubTree_(sub_tree_root->next_sibling);

    delete sub_tree_root;
}


template <class TData>
ChildSiblingNode<TData>* ChildSiblingTree<TData>::FirstChild() {
    return this->root_->first_child;
}


template <class TData>
ChildSiblingNode<TData>* ChildSiblingTree<TData>::NextSibling() {
    return this->root_->next_sibling;
}


/*!
 * @brief 在子树中先根遍历
 * @tparam TData 类型模板参数
 * @param sub_tree_root 子树根结点
 * @param visit 遍历函数
 */
template <class TData>
void ChildSiblingTree<TData>::PreOrderInSubTreeRecursive_(ChildSiblingNode<TData>* sub_tree_root,
                                                          void (*visit)(ChildSiblingNode<TData>*))
{
    if (sub_tree_root == NULL) {
        return;
    }

    visit(sub_tree_root);

    PreOrderInSubTreeRecursive_(sub_tree_root->first_child, visit); // 对长子结点进行递归
    PreOrderInSubTreeRecursive_(sub_tree_root->next_sibling, visit); // 对兄弟结点进行递归
}


/*!
 * @brief 在子树中后根遍历
 * @tparam TData 类型模板参数
 * @param sub_tree_root 子树根结点
 * @param visit 遍历函数
 */
template <class TData>
void ChildSiblingTree<TData>::PostOrderInSubTreeRecursive_(ChildSiblingNode<TData>* sub_tree_root,
                                                           void (*visit)(ChildSiblingNode<TData>*))
{
    if (sub_tree_root == NULL) {
        return;
    }

    PostOrderInSubTreeRecursive_(sub_tree_root->first_child, visit);
    visit(sub_tree_root);
    PostOrderInSubTreeRecursive_(sub_tree_root->next_sibling, visit);
}


/*!
 * @brief 在子树中层序遍历
 * @tparam TData 类型模板参数
 * @param out 输出流
 * @param sub_tree_root 子树根节点
 */
template <class TData>
// void ChildSiblingTree<TData>::LevelOrderInSubTree_(ostream& out, ChildSiblingNode<TData>* sub_tree_root) {
void ChildSiblingTree<TData>::LevelOrderInSubTree_(ChildSiblingNode<TData>* sub_tree_root, void (*visit)(ChildSiblingNode<TData>*)) {
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
 * @brief 子树节点数量(递归)
 * @tparam TData 类型模板参数
 * @param sub_tree_root
 * @return 节点数量
 */
template <class TData>
int ChildSiblingTree<TData>::NodeCountOfSubTreeRecursive_(ChildSiblingNode<TData>* sub_tree_root) {
    if (sub_tree_root == NULL) {
        return 0;
    }

    int count = 1;

    count += NodeCountOfSubTreeRecursive_(sub_tree_root->first_child);
    count += NodeCountOfSubTreeRecursive_(sub_tree_root->next_sibling);

    return count;
}


/*!
 * @brief 子树深度(递归)
 * @tparam TData 类型模板参数
 * @param sub_tree_root 子树根结点
 * @return 深度
 */
template <class TData>
int ChildSiblingTree<TData>::HeightOfSubTreeRecursive_(ChildSiblingNode<TData>* sub_tree_root) {
    if (sub_tree_root == NULL) {
        return 0;
    }

    // 长子结点对应的深度
    int first_child_depth = HeightOfSubTreeRecursive_(sub_tree_root->first_child) + 1;
    // 下一兄弟结点对应的深度
    int next_sibling_depth = HeightOfSubTreeRecursive_(sub_tree_root->next_sibling);

    return (first_child_depth > next_sibling_depth) ? first_child_depth : next_sibling_depth;
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
 * @brief 打印子树(递归)
 * @tparam TData 类型模板参数
 * @param sub_tree_root 子树根结点
 */
template <class TData>
void ChildSiblingTree<TData>::ShowSubTreeRecursive_(ChildSiblingNode<TData>* sub_tree_root) {
    if (sub_tree_root == NULL) {
        return;
    }

    cout << '(';
    cout << sub_tree_root->data;

    for (ChildSiblingNode<TData>* cur = sub_tree_root->first_child; cur != NULL; cur = cur->next_sibling) {
        ShowSubTreeRecursive_(cur);
    }

    cout << ')';
}


#endif // CYBER_DASH_CHILD_SIBLING_TREE_H
