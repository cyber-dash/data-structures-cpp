//
// Created by alei_go@163.com(抖音: cyberdash_yuan) on 2020/11/1.
//

#ifndef CYBER_DASH_LEI_TREE_H
#define CYBER_DASH_LEI_TREE_H

#include "tree_node.h"

template <class T>
class Tree {
  private:
    TreeNode<T> *root, *current;
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
  public:
    Tree(void) { root = current = NULL; }
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
};

#endif //CYBER_DASH_LEI_TREE_H
