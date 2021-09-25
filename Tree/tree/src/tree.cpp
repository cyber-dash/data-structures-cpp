//
// Created by alei_go@163.com(抖音: cyberdash_yuan) on 2020/11/1.
//

#include <iostream>
#include <queue>

#include <stdio.h>
#include <stdlib.h>

using namespace std;

#include "tree.h"
#include "tree_node.h"

template <class T>
bool Tree<T>::IsRoot(void) {
  if (root == NULL) {
    current = NULL;
    return false;
  }

  current = root;

  return true;
}

template<class T>
void Tree<T>::RemoveSubTree(TreeNode<T> *p){
  if (p){
    RemoveSubTree(p->firstChild);
    RemoveSubTree(p->nextSibling);
    delete p;
  }
}

template <class T>
bool Tree<T>::Parent(void) {
  TreeNode<T> *p = current;

  if (current == NULL || current == root) {
    current = NULL;
    return false;
  }

  return FindParent(root, p);
}

template <class T>
bool Tree<T>::FindParent(TreeNode<T> *t, TreeNode<T> *p) {
  TreeNode<T> *q = t->firstChild;
  bool succ;

  while (q != NULL && q != p) {
    if ((succ = FindParent(q, p)) == true) {
      return succ;
    }
    q = q->nextSibling;
  }

  if (q != NULL && q == p) {
    current = t;
    return true;
  } else {
    current = NULL;
    return false;
  }
}

template <class T>
bool Tree<T>::FirstChild(void) {
  if (current != NULL && current->firstChild != NULL) {
    current = current->firstChild;
    return true;
  }

  current = NULL;

  return false;
}

template <class T>
bool Tree<T>::NextSibling(void) {
  if (current != NULL && current->nextSibling != NULL) {
    current = current->nextSibling;
    return true;
  }

  current = NULL;

  return false;
}

template <class T>
bool Tree<T>::Find(T value) {
  if (IsEmpty()) {
    return false;
  }

  return Find(root, value);
}

template <class T>
bool Tree<T>::Find(TreeNode<T> *p, T value) {
  bool result = false;

  if (p->data == value) {
    result = true;
    current = p;
  } else {
    TreeNode<T> *q = p->firstChild;
    while (q != NULL && !(result = Find(q, value))) {
      q = q->nextSibling;
    }
  }

  return result;
}

template <class T>
void Tree<T>::Insert(TreeNode<T> *& subTree, T& x) {
  if (subTree == NULL) {
    subTree = new TreeNode<T>(x);
    if (subTree == NULL) {
      cerr << "存储分配错误!" << endl; 
      exit(1);
    }
  } else {
    Insert(subTree->firstChild, x);
    if (subTree == GetRoot()) {
      return;
    }
    Insert(subTree->nextSibling, x);
  }
}

template <class T>
void Tree<T>::PreOrder(ostream& out, TreeNode<T> *p) {
  if (p != NULL) {
    out << p->data;

    for (p = p->firstChild; p != NULL; p = p->nextSibling) {
      PreOrder(out, p);
    }
  }
}

template <class T>
void Tree<T>::PostOrder(ostream& out, TreeNode<T> *p) {
  if (p != NULL) {
    TreeNode<T> *q;

    for (q = p->firstChild; q != NULL; q = q->nextSibling) {
      PostOrder(out, q);
    }
    out << p->data;
  }
}

template <class T>
void Tree<T>::preorder(TreeNode<T> *t, void (*visit)(TreeNode<T> *p))
{
  if (t == NULL) {
    return;
  }

  visit(t);

  preorder(t->firstChild, visit);
  preorder(t->nextSibling, visit);
}

template <class T>
void Tree<T>::postorder(TreeNode<T> *t, void (*visit)(TreeNode<T> *p))
{
  if (t == NULL) {
    return;
  }

  postorder(t->firstChild, visit);
  visit(t);
  postorder(t->nextSibling, visit);
}

template <class T>
void Tree<T>::LevelOrder(ostream& out, TreeNode<T> *p)
{
  queue<TreeNode<T> *> Q;

  if (p != NULL) {
    Q.push(p);

    while (!Q.empty()) {
      p = Q.front();
      Q.pop();
      out << p->data;
      for (p = p->firstChild; p != NULL; p = p->nextSibling) {
        Q.push(p);
      }
    }
  }
}

template <class T>
int Tree<T>::count_node(TreeNode<T> *t) {
  if (t == NULL) {
    return 0;
  }

  int count = 1;

  count += count_node(t->firstChild);
  count += count_node(t->nextSibling);

  return count;
}

template <class T>
int Tree<T>::find_depth(TreeNode<T> *t) {
  if (t == NULL) {
    return 0;
  }

  int fc_depth = find_depth(t->firstChild) + 1;
  int ns_depth = find_depth(t->nextSibling);

  return (fc_depth > ns_depth) ? fc_depth : ns_depth;
}

template <class T>
void Tree<T>::create_tree(TreeNode<T> *& subTree, char *&GL) {
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

  subTree = new TreeNode<T>(*(GL++) - '0');
  if (subTree == NULL) {
    cerr << "存储分配错误!" << endl; 
    exit(1);
  }
  create_tree(subTree->firstChild, GL);
  create_tree(subTree->nextSibling, GL);
}

template <class T>
void Tree<T>::show_tree(TreeNode<T> *t) {
  if (t == NULL) {
    return;
  }

  cout << '(';
  cout << t->data;

  for (TreeNode<T> *p = t->firstChild; p != NULL; p = p->nextSibling) {
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
      <<"数据结构开源代码(C++清华大学殷人昆)魔改升级版本: https://gitee.com/cyberdash/data-structure-cpp"<<endl
      <<endl<<"*************************************** CyberDash ***************************************"<<endl<<endl;
}
