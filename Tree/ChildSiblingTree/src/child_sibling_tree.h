/*!
 * @file ChildSiblingTree.h
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


/*!
 * @brief 子女兄弟树结点模板结构体
 * @tparam T 类型模板参数
 */
template <class T>
struct ChildSiblingNode {
  /*!
   * @brief 结构体构造函数
   * @param data 数据项
   * @param first_child 长子结点指针
   * @param next_sibling 下一兄弟结点指针
   */
  ChildSiblingNode(T data, ChildSiblingNode<T>* first_child = NULL, ChildSiblingNode<T>* next_sibling = NULL):
    data(data), first_child(first_child), next_sibling(next_sibling) {}

  T data; //!< 数据项
  ChildSiblingNode<T>* first_child; //!< 长子结点指针
  ChildSiblingNode<T>* next_sibling; //!< 兄弟结点指针
};


/*!
 * @brief 子女兄弟树模板类
 * @tparam T 类型模板参数
 */
template <class T>
class ChildSiblingTree {
public:
  /*! @brief 构造函数 */
  ChildSiblingTree(): root_(NULL), current_(NULL) {}
  bool SetRootToCurrent();
  bool IsEmpty() { return this->root_ == NULL; }
  bool FirstChild();
  bool NextSibling();
  bool FindParentAndSetCurrent();
  bool FindAndSetCurrent(T data);
  void Insert(T& item) { return InsertInSubTree_(this->root_, item);}
  ChildSiblingNode<T>* Root() { return this->root_; }
  void PreOrder(ostream& out) { PreOrder(out, this->root_); }
  void PostOrder(ostream& out) { PostOrder(out, this->root_); }
  void preorder(void (*visit)(ChildSiblingNode<T>*)) { PreOrderInSubTreeRecursive_(root_, visit); }
  void postorder(void (*visit)(ChildSiblingNode<T>*)) { PostOrderInSubTreeRecursive_(root_, visit); }
  void LevelOrder(ostream& out) { LevelOrderInSubTree_(out, root_); }
  int count_node() { return count_node(root_); }
  int find_depth() { return find_depth(root_); }
  void create_tree(char *&GL) { create_tree(root_, GL); }
  void show_tree() { show_tree(root_); }
  void CyberDashShow();
private:
  ChildSiblingNode<T>* root_; //!< 根结点
  ChildSiblingNode<T>* current_; //!< 当前指针, 为了方便链表操作

  // 在子树中使用数据项查找, 并将节点赋给current_
  bool FindAndSetCurrentInSubTree_(ChildSiblingNode<T>* sub_tree_root, T data);
  // 删除子树
  void RemoveSubTree_(ChildSiblingNode<T>* sub_tree_root);
  // 在子树中寻找父结点, 并设置当前结点current_
  bool FindParentAndSetCurrentInSubTree_(ChildSiblingNode<T>* sub_tree_root, ChildSiblingNode<T>* node);

  void InsertInSubTree_(ChildSiblingNode<T>*& sub_tree_root, T& data);
  void PreOrder(ostream& out, ChildSiblingNode<T> *p);
  void PostOrder(ostream& out, ChildSiblingNode<T> *p);
  // 在子树中进行先根遍历(递归)
  void PreOrderInSubTreeRecursive_(ChildSiblingNode<T>* sub_tree_root, void (*visit)(ChildSiblingNode<T>*));
  // 在子树中后根遍历
  void PostOrderInSubTreeRecursive_(ChildSiblingNode<T>* sub_tree_root, void (*visit)(ChildSiblingNode<T>*));
  void LevelOrderInSubTree_(ostream& out, ChildSiblingNode<T> *p);
  void create_tree(ChildSiblingNode<T> *&, char *&GL);
  int count_node(ChildSiblingNode<T> *t);
  int find_depth(ChildSiblingNode<T> *t);
  void show_tree(ChildSiblingNode<T> *t);
};


/*!
 * @brief 让树的根结点成为树的当前结点
 * @tparam T 类型模板参数
 * @return 是否设置成功
 */
template <class T>
bool ChildSiblingTree<T>::SetRootToCurrent() {
  if (this->root_ == NULL) {
    this->current_ = NULL;
    return false;
  }

  this->current_ = this->root_;

  return true;
}


/*!
 * @brief 删除子树
 * @tparam T 类型模板参数
 * @param sub_tree_root 子树根结点
 */
template<class T>
void ChildSiblingTree<T>::RemoveSubTree_(ChildSiblingNode<T>* sub_tree_root){
  if (sub_tree_root != NULL) {
    this->RemoveSubTree_(sub_tree_root->first_child);
    this->RemoveSubTree_(sub_tree_root->next_sibling);
    delete sub_tree_root;
  }
}


/*!
 * @brief 寻找父结点, 并设置当前结点current_
 * @tparam T 类型模板参数
 * @return 是否成功
 */
template <class T>
bool ChildSiblingTree<T>::FindParentAndSetCurrent() {
  ChildSiblingNode<T>* node = this->current_;

  if (this->current_ == NULL || this->current_ == this->root_) {
    this->current_ = NULL;
    return false;
  }

  return FindParentAndSetCurrentInSubTree_(this->root_, node);
}


/*!
 * @brief 在子树中寻找父结点, 并设置当前结点current_
 * @tparam T 类型模板参数
 * @param sub_tree_root 子树根结点
 * @param node 待寻找父结点的结点
 * @return 是否成功
 */
template <class T>
bool ChildSiblingTree<T>::FindParentAndSetCurrentInSubTree_(ChildSiblingNode<T>* sub_tree_root, ChildSiblingNode<T>* node) {

  /*
  ChildSiblingNode<T>* cur = sub_tree_root->first_child;
  bool succ;

  while (cur != NULL && cur != node) {
    if ((succ = FindParentInSubTree_(cur, node)) == true) {
      return succ;
    }
    cur = cur->next_sibling;
  }

  if (cur != NULL && cur == node) {
    current_ = sub_tree_root;
    return true;
  } else {
    current_ = NULL;
    return false;
  }
   */

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


template <class T>
bool ChildSiblingTree<T>::FirstChild() {
  if (this->current_ != NULL && this->current_->first_child != NULL) {
    current_ = current_->first_child;
    return true;
  }

  current_ = NULL;

  return false;
}


template <class T>
bool ChildSiblingTree<T>::NextSibling() {
  if (current_ != NULL && current_->next_sibling != NULL) {
    current_ = current_->next_sibling;
    return true;
  }

  current_ = NULL;

  return false;
}


template <class T>
bool ChildSiblingTree<T>::FindAndSetCurrent(T data) {
  if (this->IsEmpty()) {
    return false;
  }

  return FindAndSetCurrentInSubTree_(this->root_, data);
}


/*!
 * @brief 在子树中使用数据项查找, 并将节点赋给current_
 * @tparam T 类型模板参数
 * @param sub_tree_root 子树根结点
 * @param data 数据项
 * @return 是否成功
 */
template <class T>
bool ChildSiblingTree<T>::FindAndSetCurrentInSubTree_(ChildSiblingNode<T>* sub_tree_root, T data) {
  bool isFound = false;

  if (sub_tree_root->data == data) {
    isFound = true;
    this->current_ = sub_tree_root;
  } else {
    ChildSiblingNode<T>* cur = sub_tree_root->first_child;
    /*
    while (cur != NULL && !(isFound = FindAndSetCurrentInSubTree_(cur, data))) {
      cur = cur->next_sibling;
    }
     */
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


template <class T>
void ChildSiblingTree<T>::InsertInSubTree_(ChildSiblingNode<T>*& sub_tree_root, T& data) {

  if (sub_tree_root == NULL) {
    sub_tree_root = new ChildSiblingNode<T>(data);
    // error handling
  } else {
    InsertInSubTree_(sub_tree_root->first_child, data);
    if (sub_tree_root == Root()) {
      return;
    }
    InsertInSubTree_(sub_tree_root->next_sibling, data);
  }
}


template <class T>
void ChildSiblingTree<T>::PreOrder(ostream& out, ChildSiblingNode<T> *p) {
  if (p != NULL) {
    out << p->data;

    for (p = p->first_child; p != NULL; p = p->next_sibling) {
      PreOrder(out, p);
    }
  }
}

template <class T>
void ChildSiblingTree<T>::PostOrder(ostream& out, ChildSiblingNode<T> *p) {
  if (p != NULL) {
    ChildSiblingNode<T> *q;

    for (q = p->first_child; q != NULL; q = q->next_sibling) {
      PostOrder(out, q);
    }
    out << p->data;
  }
}


/*!
 * @brief 在子树中先根遍历
 * @tparam T 类型模板参数
 * @param sub_tree_root 子树根结点
 * @param visit 遍历函数
 */
template <class T>
void ChildSiblingTree<T>::PreOrderInSubTreeRecursive_(ChildSiblingNode<T>* sub_tree_root,
                                                      void (*visit)(ChildSiblingNode<T>*))
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
 * @tparam T 类型模板参数
 * @param sub_tree_root 子树根结点
 * @param visit 遍历函数
 */
template <class T>
void ChildSiblingTree<T>::PostOrderInSubTreeRecursive_(ChildSiblingNode<T>* sub_tree_root,
                                                       void (*visit)(ChildSiblingNode<T>*))
{
  if (sub_tree_root == NULL) {
    return;
  }

  PostOrderInSubTreeRecursive_(sub_tree_root->first_child, visit);
  visit(sub_tree_root);
  PostOrderInSubTreeRecursive_(sub_tree_root->next_sibling, visit);
}


template <class T>
void ChildSiblingTree<T>::LevelOrderInSubTree_(ostream& out, ChildSiblingNode<T> *p)
{
  queue < ChildSiblingNode<T> * > Q;

  if (p != NULL) {
    Q.push(p);

    while (!Q.empty()) {
      p = Q.front();
      Q.pop();
      out << p->data;
      for (p = p->first_child; p != NULL; p = p->next_sibling) {
        Q.push(p);
      }
    }
  }
}

template <class T>
int ChildSiblingTree<T>::count_node(ChildSiblingNode<T> *t) {
  if (t == NULL) {
    return 0;
  }

  int count = 1;

  count += count_node(t->first_child);
  count += count_node(t->next_sibling);

  return count;
}

template <class T>
int ChildSiblingTree<T>::find_depth(ChildSiblingNode<T> *t) {
  if (t == NULL) {
    return 0;
  }

  int fc_depth = find_depth(t->first_child) + 1;
  int ns_depth = find_depth(t->next_sibling);

  return (fc_depth > ns_depth) ? fc_depth : ns_depth;
}

template <class T>
void ChildSiblingTree<T>::create_tree(ChildSiblingNode<T> *& subTree, char *&GL) {
  if (*GL == '\0') {
    return;
  }

  if (*GL == ')') {
    GL++;
    return;
  }

  while (*GL == '(') {
    GL++;
  }

  subTree = new ChildSiblingNode<T>(*(GL++) - '0');
  if (subTree == NULL) {
    cerr << "存储分配错误!" << endl;
    exit(1);
  }
  create_tree(subTree->first_child, GL);
  create_tree(subTree->next_sibling, GL);
}

template <class T>
void ChildSiblingTree<T>::show_tree(ChildSiblingNode<T> *t) {
  if (t == NULL) {
    return;
  }

  cout << '(';
  cout << t->data;

  for (ChildSiblingNode<T> *p = t->first_child; p != NULL; p = p->next_sibling) {
    show_tree(p);
  }

  cout << ')';
}


template<class T>
void ChildSiblingTree<T>::CyberDashShow() {
  cout<<endl
      <<"*************************************** CyberDash ***************************************"<<endl<<endl
      <<"抖音号\"CyberDash计算机考研\", id: cyberdash_yuan"<<endl<<endl
      <<"CyberDash成员:"<<endl
      <<"元哥(cyberdash@163.com), "<<"北京邮电大学(通信工程本科)/北京邮电大学(信息与通信系统研究生)"<<endl
      <<"磊哥(alei_go@163.com), "<<"山东理工大学(数学本科)/北京邮电大学(计算机研究生)"<<endl<<endl
      <<"L_Dash(lyu2586@163.com), "<<"北京邮电大学(计算机在读研究生)"<<endl<<endl
      <<"数据结构开源代码(C++清华大学殷人昆)魔改升级版本: https://gitee.com/cyberdash/data-structure-cpp"<<endl
      <<endl<<"*************************************** CyberDash ***************************************"<<endl<<endl;
}

#endif // CYBER_DASH_CHILD_SIBLING_TREE_H
