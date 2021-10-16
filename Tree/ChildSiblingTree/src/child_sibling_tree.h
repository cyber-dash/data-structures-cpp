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


// #include <stdio>
#include <cstdlib>
#include <iostream>
#include <queue>


template <class T>
struct ChildSiblingNode {
  ChildSiblingNode(T data = 0, ChildSiblingNode<T>* first_child = NULL, ChildSiblingNode<T>* next_sibling = NULL):
    data(data), first_child(first_child), next_sibling(next_sibling) {}

  T data;
  ChildSiblingNode<T>* first_child; //!< 长子结点指针
  ChildSiblingNode<T>* next_sibling; //!< 兄弟结点指针
};


template <class T>
class Tree {
public:
  Tree(): root_(NULL), current_(NULL) {}
  bool Root();
  bool IsEmpty() { return this->root_ == NULL; }
  bool FirstChild();
  bool NextSibling();
  bool Parent();
  bool Find(T value);
  void Insert(T& item) { return Insert(root_, item);}
  ChildSiblingNode<T> *GetRoot(void) { return root_; }
  void PreOrder(ostream& out) { PreOrder(out, root_); }
  void PostOrder(ostream& out) { PostOrder(out, root_); }
  void preorder(void (*visit)(ChildSiblingNode<T> *p)) { preorder(root_, visit); }
  void postorder(void (*visit)(ChildSiblingNode<T> *p)) { postorder(root_, visit); }
  void LevelOrder(ostream& out) { LevelOrder(out, root_); }
  int count_node() { return count_node(root_); }
  int find_depth() { return find_depth(root_); }
  void create_tree(char *&GL) { create_tree(root_, GL); }
  void show_tree() { show_tree(root_); }
  void CyberDashShow();
private:
  ChildSiblingNode<T>* root_; //!< 根结点
  ChildSiblingNode<T>* current_; //!< 当前指针, 为了方便链表操作
  bool Find(ChildSiblingNode<T> *p, T value);
  void RemoveSubTree(ChildSiblingNode<T> *p);
  bool FindParent(ChildSiblingNode<T> *t, ChildSiblingNode<T> *p);
  void Insert(ChildSiblingNode<T> *& subTree, T& x);
  void PreOrder(ostream& out, ChildSiblingNode<T> *p);
  void PostOrder(ostream& out, ChildSiblingNode<T> *p);
  void preorder(ChildSiblingNode<T> *t, void (*visit)(ChildSiblingNode<T> *p));
  void postorder(ChildSiblingNode<T> *t, void (*visit)(ChildSiblingNode<T> *p));
  void LevelOrder(ostream& out, ChildSiblingNode<T> *p);
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
bool Tree<T>::Root() {
  if (this->root_ == NULL) {
    this->current_ = NULL;
    return false;
  }

  this->current_ = this->root_;

  return true;
}

template<class T>
void Tree<T>::RemoveSubTree(ChildSiblingNode<T> *p){
  if (p){
    RemoveSubTree(p->first_child);
    RemoveSubTree(p->next_sibling);
    delete p;
  }
}

template <class T>
bool Tree<T>::Parent(void) {
  ChildSiblingNode<T> *p = current_;

  if (current_ == NULL || current_ == root_) {
    current_ = NULL;
    return false;
  }

  return FindParent(root_, p);
}

template <class T>
bool Tree<T>::FindParent(ChildSiblingNode<T> *t, ChildSiblingNode<T> *p) {
  ChildSiblingNode<T> *q = t->first_child;
  bool succ;

  while (q != NULL && q != p) {
    if ((succ = FindParent(q, p)) == true) {
      return succ;
    }
    q = q->next_sibling;
  }

  if (q != NULL && q == p) {
    current_ = t;
    return true;
  } else {
    current_ = NULL;
    return false;
  }
}

template <class T>
bool Tree<T>::FirstChild() {
  if (this->current_ != NULL && this->current_->first_child != NULL) {
    current_ = current_->first_child;
    return true;
  }

  current_ = NULL;

  return false;
}

template <class T>
bool Tree<T>::NextSibling(void) {
  if (current_ != NULL && current_->next_sibling != NULL) {
    current_ = current_->next_sibling;
    return true;
  }

  current_ = NULL;

  return false;
}

template <class T>
bool Tree<T>::Find(T value) {
  if (IsEmpty()) {
    return false;
  }

  return Find(root_, value);
}

template <class T>
bool Tree<T>::Find(ChildSiblingNode<T> *p, T value) {
  bool result = false;

  if (p->data == value) {
    result = true;
    current_ = p;
  } else {
    ChildSiblingNode<T> *q = p->first_child;
    while (q != NULL && !(result = Find(q, value))) {
      q = q->next_sibling;
    }
  }

  return result;
}

template <class T>
void Tree<T>::Insert(ChildSiblingNode<T> *& subTree, T& x) {
  if (subTree == NULL) {
    subTree = new ChildSiblingNode<T>(x);
    if (subTree == NULL) {
      cerr << "存储分配错误!" << endl;
      exit(1);
    }
  } else {
    Insert(subTree->first_child, x);
    if (subTree == GetRoot()) {
      return;
    }
    Insert(subTree->next_sibling, x);
  }
}

template <class T>
void Tree<T>::PreOrder(ostream& out, ChildSiblingNode<T> *p) {
  if (p != NULL) {
    out << p->data;

    for (p = p->first_child; p != NULL; p = p->next_sibling) {
      PreOrder(out, p);
    }
  }
}

template <class T>
void Tree<T>::PostOrder(ostream& out, ChildSiblingNode<T> *p) {
  if (p != NULL) {
    ChildSiblingNode<T> *q;

    for (q = p->first_child; q != NULL; q = q->next_sibling) {
      PostOrder(out, q);
    }
    out << p->data;
  }
}

template <class T>
void Tree<T>::preorder(ChildSiblingNode<T> *t, void (*visit)(ChildSiblingNode<T> *p))
{
  if (t == NULL) {
    return;
  }

  visit(t);

  preorder(t->first_child, visit);
  preorder(t->next_sibling, visit);
}

template <class T>
void Tree<T>::postorder(ChildSiblingNode<T> *t, void (*visit)(ChildSiblingNode<T> *p))
{
  if (t == NULL) {
    return;
  }

  postorder(t->first_child, visit);
  visit(t);
  postorder(t->next_sibling, visit);
}

template <class T>
void Tree<T>::LevelOrder(ostream& out, ChildSiblingNode<T> *p)
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
int Tree<T>::count_node(ChildSiblingNode<T> *t) {
  if (t == NULL) {
    return 0;
  }

  int count = 1;

  count += count_node(t->first_child);
  count += count_node(t->next_sibling);

  return count;
}

template <class T>
int Tree<T>::find_depth(ChildSiblingNode<T> *t) {
  if (t == NULL) {
    return 0;
  }

  int fc_depth = find_depth(t->first_child) + 1;
  int ns_depth = find_depth(t->next_sibling);

  return (fc_depth > ns_depth) ? fc_depth : ns_depth;
}

template <class T>
void Tree<T>::create_tree(ChildSiblingNode<T> *& subTree, char *&GL) {
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
void Tree<T>::show_tree(ChildSiblingNode<T> *t) {
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
void Tree<T>::CyberDashShow() {
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
