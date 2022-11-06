/*!
 * @file child_sibling_tree.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 子女兄弟树模板类
 * @version 0.2.1
 * @date 2020-11-01
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
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
     * @brief **结构体构造函数**
     * @param data 数据项
     * @param first_child 长子结点
     * @param next_sibling 下一兄弟结点
     * @note
     * 结构体构造函数
     * ------------
     * ------------
     *
     * ------------
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
template <class TData>
class ChildSiblingTree {
public:
    /*! @brief 构造函数 */
    ChildSiblingTree() : root_(NULL) {}

    /*!
     * @brief **使用前序遍历字符串创建子女兄弟树**
     * @param str 前根遍历字符串
     * @note
     * 使用前序遍历字符串创建子女兄弟树
     * ---------------------------
     * ---------------------------
     *
     * ---------------------------
     */
    void CreateByPreOrderStr(char*& str) { this->CreateTreeByStrRecursive_(this->root_, str); }

    ChildSiblingNode<TData>* FirstChild();
    ChildSiblingNode<TData>* NextSibling();

    /*!
     * @brief **是否为空树**
     * @return 是/否
     */
    bool IsEmpty() { return this->root_ == NULL; }
    int NodeCount() { return this->SubTreeNodeCountRecursive_(this->root_); }
    int Depth() { return this->SubTreeDepthRecursive_(this->root_); }
    // bool FindParentAndSetCurrent();
    // bool FindAndSetCurrent(TData data);
    // void Insert(TData& item) { return this->InsertInSubTree_(this->root_, item); }
    // ChildSiblingNode<TData>* AddSibling(ChildSiblingNode<TData>* node, TData data);
    ChildSiblingNode<TData>* Root() { return this->root_; }
    void PreOrder(ostream& out) { PreOrderByOstream(out, this->root_); }
    void PostOrder(ostream& out) { PostOrderByOstream(out, this->root_); }
    void PreOrder(void (*visit)(ChildSiblingNode<TData>*)) { PreOrderInSubTreeRecursive_(root_, visit); }
    void PostOrder(void (*visit)(ChildSiblingNode<TData>*)) { PostOrderInSubTreeRecursive_(root_, visit); }
    void LevelOrder(void (*visit)(ChildSiblingNode<TData>*)) { LevelOrderInSubTree_(root_, visit); }
    void ShowTree() { this->ShowSubTreeRecursive_(this->root_); }
    void CyberDashShow();
private:
    ChildSiblingNode<TData>* root_; //!< 根结点
    // ChildSiblingNode<TData>* current_; //!< 当前指针, 为了方便链表操作

    // 在子树中使用数据项查找, 并将节点赋给current_
    // bool FindAndSetCurrentInSubTree_(ChildSiblingNode<TData>* sub_tree_root, TData data);
    // 删除子树
    void RemoveSubTree_(ChildSiblingNode<TData>* sub_tree_root);
    // 在子树中寻找父结点, 并设置当前结点current_
    // bool FindParentAndSetCurrentInSubTree_(ChildSiblingNode<TData>* sub_tree_root, ChildSiblingNode<TData>* node);

    // void InsertInSubTree_(ChildSiblingNode<TData>*& sub_tree_root, TData& data);
    void PreOrderByOstream(ostream& out, ChildSiblingNode<TData>* sub_tree_root);
    void PostOrderByOstream(ostream& out, ChildSiblingNode<TData>* sub_tree_root);
    // 在子树中进行先根遍历(递归)
    void PreOrderInSubTreeRecursive_(ChildSiblingNode<TData>* sub_tree_root, void (*visit)(ChildSiblingNode<TData>*));
    // 在子树中进行后根遍历(递归)
    void PostOrderInSubTreeRecursive_(ChildSiblingNode<TData>* sub_tree_root, void (*visit)(ChildSiblingNode<TData>*));
    // 在子树中层序遍历
    void LevelOrderInSubTree_(ChildSiblingNode<TData>* sub_tree_root, void (*visit)(ChildSiblingNode<TData>*));
    // 使用字符串创建子女兄弟树
    void CreateTreeByStrRecursive_(ChildSiblingNode<TData>*&, char*& str);
    // 子树节点数量(递归)
    int SubTreeNodeCountRecursive_(ChildSiblingNode<TData>* sub_tree_root);
    // 子树深度(递归)
    int SubTreeDepthRecursive_(ChildSiblingNode<TData>* sub_tree_root);
    // 打印子树(递归)
    void ShowSubTreeRecursive_(ChildSiblingNode<TData>* sub_tree_root);
};


/*
 * @brief 让树的根结点成为树的当前结点
 * @tparam T 类型模板参数
 * @return 是否设置成功
template <class T>
bool ChildSiblingTree<T>::SetRootToCurrent() {
    if (this->root_ == NULL) {
        this->current_ = NULL;
        return false;
    }

    this->current_ = this->root_;

    return true;
}
 */


/*!
 * @brief 删除子树
 * @tparam TData 类型模板参数
 * @param sub_tree_root 子树根结点
 */
template<class TData>
void ChildSiblingTree<TData>::RemoveSubTree_(ChildSiblingNode<TData>* sub_tree_root) {
    if (sub_tree_root != NULL) {
        this->RemoveSubTree_(sub_tree_root->first_child);
        this->RemoveSubTree_(sub_tree_root->next_sibling);
        delete sub_tree_root;
    }
}


/*
 * @brief 寻找父结点, 并设置当前结点current_
 * @tparam T 类型模板参数
 * @return 是否成功
template <class T>
bool ChildSiblingTree<T>::FindParentAndSetCurrent() {
    ChildSiblingNode<T>* node = this->current_;

    if (this->current_ == NULL || this->current_ == this->root_) {
        this->current_ = NULL;
        return false;
    }

    return FindParentAndSetCurrentInSubTree_(this->root_, node);
}
 */


/*
 * @brief 在子树中寻找父结点, 并设置当前结点current_
 * @tparam T 类型模板参数
 * @param sub_tree_root 子树根结点
 * @param node 待寻找父结点的结点
 * @return 是否成功
template <class T>
bool ChildSiblingTree<T>::FindParentAndSetCurrentInSubTree_(ChildSiblingNode<T>* sub_tree_root, ChildSiblingNode<T>* node) {

    ChildSiblingNode<T>* cur = sub_tree_root->first_child;

    while (cur != NULL && cur != node) {
        bool isFound = FindParentAndSetCurrentInSubTree_(cur, node);
        if (isFound == true) {
            return true;
        }
        cur = cur->next_sibling;
    }

    // node是根节点的孩子
    if (cur != NULL && cur == node) {
        this->current_ = sub_tree_root;
        return true;
    }

    this->current_ = NULL;
    return false;
}
 */


template <class TData>
ChildSiblingNode<TData>* ChildSiblingTree<TData>::FirstChild() {
    return this->root_->first_child;
}


template <class TData>
ChildSiblingNode<TData>* ChildSiblingTree<TData>::NextSibling() {
    return this->root_->next_sibling;
}


/*
template <class T>
bool ChildSiblingTree<T>::FindAndSetCurrent(T data) {
    if (this->IsEmpty()) {
        return false;
    }

    return FindAndSetCurrentInSubTree_(this->root_, data);
}
 */


/*
template <class T>
ChildSiblingNode<T>* AddSibling(ChildSiblingNode<T>* node, T data) {
    if (node == NULL) {
        return NULL;
    }

    while (node->next_sibling != NULL) {

    }
}
 */


/*
 * @brief 在子树中使用数据项查找, 并将节点赋给current_
 * @tparam T 类型模板参数
 * @param sub_tree_root 子树根结点
 * @param data 数据项
 * @return 是否成功
template <class T>
bool ChildSiblingTree<T>::FindAndSetCurrentInSubTree_(ChildSiblingNode<T>* sub_tree_root, T data) {
    bool isFound = false;

    if (sub_tree_root->data == data) {
        isFound = true;
        this->current_ = sub_tree_root;
    }
    else {
        ChildSiblingNode<T>* cur = sub_tree_root->first_child;
        while (cur != NULL) {
            isFound = FindAndSetCurrentInSubTree_(cur, data);
            if (isFound) {
                break;
            }

            cur = cur->next_sibling;
        }
    }

    return isFound;
}
 */


/*
template <class TData>
void ChildSiblingTree<TData>::InsertInSubTree_(ChildSiblingNode<TData>*& sub_tree_root, TData& data) {

    if (sub_tree_root == NULL) {
        sub_tree_root = new ChildSiblingNode<TData>(data);
        // error handling
    } else {
        InsertInSubTree_(sub_tree_root->first_child, data);
        if (sub_tree_root == Root()) {
            return;
        }
        InsertInSubTree_(sub_tree_root->next_sibling, data);
    }
}
 */


template <class TData>
void ChildSiblingTree<TData>::PreOrderByOstream(ostream& out, ChildSiblingNode<TData>* sub_tree_root) {
    if (sub_tree_root != NULL) {
        out << sub_tree_root->data;

        for (sub_tree_root = sub_tree_root->first_child; sub_tree_root != NULL; sub_tree_root = sub_tree_root->next_sibling) {
            PreOrderByOstream(out, sub_tree_root);
        }
    }
}

template <class TData>
void ChildSiblingTree<TData>::PostOrderByOstream(ostream& out, ChildSiblingNode<TData>* p) {
    if (p != NULL) {
        ChildSiblingNode<TData>* q;

        for (q = p->first_child; q != NULL; q = q->next_sibling) {
            PostOrderByOstream(out, q);
        }
        out << p->data;
    }
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
int ChildSiblingTree<TData>::SubTreeNodeCountRecursive_(ChildSiblingNode<TData>* sub_tree_root) {
    if (sub_tree_root == NULL) {
        return 0;
    }

    int count = 1;

    count += SubTreeNodeCountRecursive_(sub_tree_root->first_child);
    count += SubTreeNodeCountRecursive_(sub_tree_root->next_sibling);

    return count;
}


/*!
 * @brief 子树深度(递归)
 * @tparam TData 类型模板参数
 * @param sub_tree_root 子树根结点
 * @return 深度
 */
template <class TData>
int ChildSiblingTree<TData>::SubTreeDepthRecursive_(ChildSiblingNode<TData>* sub_tree_root) {
    if (sub_tree_root == NULL) {
        return 0;
    }

    // 长子结点对应的深度
    int first_child_depth = SubTreeDepthRecursive_(sub_tree_root->first_child) + 1;
    // 下一兄弟结点对应的深度
    int next_sibling_depth = SubTreeDepthRecursive_(sub_tree_root->next_sibling);

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


template<class TData>
void ChildSiblingTree<TData>::CyberDashShow() {
    cout << endl
        << "*************************************** CyberDash ***************************************" << endl << endl
        << "抖音号\"CyberDash计算机考研\", id: cyberdash_yuan" << endl << endl
        << "CyberDash成员:" << endl
        << "元哥(cyberdash@163.com), " << "北京邮电大学(通信工程本科)/北京邮电大学(信息与通信系统研究生)" << endl
        << "磊哥(alei_go@163.com), " << "山东理工大学(数学本科)/北京邮电大学(计算机研究生)" << endl << endl
        << "L_Dash(lyu2586@163.com), " << "北京邮电大学(计算机在读研究生)" << endl << endl
        << "数据结构开源代码(C++清华大学殷人昆)魔改升级版本: https://gitee.com/cyberdash/data-structure-cpp" << endl
        << endl << "*************************************** CyberDash ***************************************" << endl << endl;
}

#endif // CYBER_DASH_CHILD_SIBLING_TREE_H
