//
// Created by alei_go@163.com(抖音: cyberdash_yuan) on 2020/11/1.
//
/*!
 * @file tree.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 树模板类
 * @version 0.2.1
 * @date 2020-11-01
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#ifndef CYBER_DASH_TREE_H
#define CYBER_DASH_TREE_H

#include "tree_node.h"

template <class T>
class Tree {
public:
  Tree() { root = current = NULL; }
  bool IsRoot(void);
  bool IsEmpty(void) { return root == NULL; }
  bool FirstChild(void);
  bool NextSibling(void);
  bool Parent(void);
  bool Find(T value);
  void Insert(T& item) { return Insert(root, item);}
  TreeNode<T> *GetRoot(void) { return root; }
  void PreOrder(ostream& out) { PreOrder(out, root); }
  void PostOrder(ostream& out) { PostOrder(out, root); }
  void preorder(void (*visit)(TreeNode<T> *p)) { preorder(root, visit); }
  void postorder(void (*visit)(TreeNode<T> *p)) { postorder(root, visit); }
  void LevelOrder(ostream& out) { LevelOrder(out, root); }
  int count_node(void) { return count_node(root); }
  int find_depth(void) { return find_depth(root); }
  void create_tree(char *&GL) { create_tree(root, GL); }
  void show_tree(void) { show_tree(root); }
  void CyberDashShow();
private:
  TreeNode<T>* root;
  TreeNode<T>* current;
  bool Find(TreeNode<T> *p, T value);
  void RemoveSubTree(TreeNode<T> *p);
  bool FindParent(TreeNode<T> *t, TreeNode<T> *p);
  void Insert(TreeNode<T> *& subTree, T& x);
  void PreOrder(ostream& out, TreeNode<T> *p);
  void PostOrder(ostream& out, TreeNode<T> *p);
  void preorder(TreeNode<T> *t, void (*visit)(TreeNode<T> *p));
  void postorder(TreeNode<T> *t, void (*visit)(TreeNode<T> *p));
  void LevelOrder(ostream& out, TreeNode<T> *p);
  void create_tree(TreeNode<T> *&, char *&GL);
  int count_node(TreeNode<T> *t);
  int find_depth(TreeNode<T> *t);
  void show_tree(TreeNode<T> *t);
};

#endif // CYBER_DASH_TREE_H
