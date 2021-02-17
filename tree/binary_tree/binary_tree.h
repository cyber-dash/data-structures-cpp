//
// Created by alei_go@163.com(抖音: cyberdash_yuan) on 2020/11/1.
//

#ifndef CYBER_DASH_BINARY_TREE_H
#define CYBER_DASH_BINARY_TREE_H

#include <iostream>
#include "bin_tree_node.h"
#include "binary_tree.h"


using namespace std;


template <class T>
class BinaryTree {
public:
  BinaryTree(): root_ptr_(NULL) {}
  BinaryTree(T value): value_(value), root_ptr_(NULL) {}
  BinaryTree(BinaryTree<T>& binary_tree) { root_ptr_ = Copy(binary_tree.root_ptr_); }

  ~BinaryTree() { Destroy(root_ptr_); }

  bool IsEmpty() { return (root_ptr_ == NULL) ? true : false; }

  BinTreeNode<T>* getRoot() const { return root_ptr_; }
  BinTreeNode<T>* Parent(BinTreeNode<T> *current) { return (root_ptr_ == NULL || root_ptr_ == current) ? NULL : Parent(root_ptr_, current); }
  BinTreeNode<T>* LeftChild(BinTreeNode<T> *current) { return (current != NULL) ? current->left_child_ptr_ : NULL; }
  BinTreeNode<T>* RightChild(BinTreeNode<T> *current) { return (current != NULL) ? current->right_child_ptr_ : NULL; }

  int Height() { return SubTreeHeight_(root_ptr_); }
  int Size() { return SubTreeSize_(root_ptr_); }

  void PreOrder(void (*visit)(BinTreeNode<T>*)) { PreOrder_(root_ptr_, visit); }
  void InOrder(void (*visit)(BinTreeNode<T>*)) { InOrder(root_ptr_, visit); }
  void PostOrder(void (*visit)(BinTreeNode<T>*)) { PostOrder_(root_ptr_, visit); }
  // void PreOrder1(void (*visit)(BinTreeNode<T>*)) { SubTreePreOrder_(root_ptr_, visit); } // todo: repeated?
  void PreOrderNonRecursive(void (*visit)(BinTreeNode<T>*)) { SubTreePreOrderNonRecursive_(root_ptr_, visit); }
  bool Insert(T& item) { return SubTreeInsert_(root_ptr_, item); }
  bool Find(T item) { return SubTreeFind_(root_ptr_, item); }
  void CreateBinTree(istream &in) { CreateBinTree(in, root_ptr_); }
  void Traverse(BinTreeNode<T>* subTree, ostream& out);
  void Print(void) { SubTreePrint_(root_ptr_); };
  void createBinTreeByPreAndInOrderString(T *pre_order_str_ptr, T *in_order_str_ptr, int str_length) {
    CreateSubBinTreeByPreAndInOrderString_(pre_order_str_ptr, in_order_str_ptr, str_length, root_ptr_);
  }

  void LevelOrder(void (*visit)(BinTreeNode<T> *p)) { SubTreeLevelOrder_(root_ptr_, visit); }
  void InOrderNonRecursive(void (*visit)(BinTreeNode<T>*)) { SubTreeInOrderNonRecursive_(root_ptr_, visit); }
  void PostOrderNonRecursive(void (*visit)(BinTreeNode<T>*)) { SubTreePostOrderNonRecursive_(root_ptr_, visit); }

  void CyberDashShow();

protected:
  BinTreeNode<T>* root_ptr_;
  T value_;

  void CreateBinTree(istream& in, BinTreeNode<T> *& subTree);
  BinTreeNode<T>* CreateSubBinTreeByPreAndInOrderString_(T* pre_order_str_ptr, T* in_order_str_ptr, int str_length, BinTreeNode<T> *& node_ptr);
  bool SubTreeInsert_(BinTreeNode<T> *& node_ptr, T& value);
  void Destroy(BinTreeNode<T> *& subTree);
  bool SubTreeFind_(BinTreeNode<T> *node_ptr, T value) const;
  BinTreeNode<T> *Copy(BinTreeNode<T> *orignode);
  int SubTreeHeight_(BinTreeNode<T> *subTree) const;
  int SubTreeSize_(BinTreeNode<T> *subTree) const;
  BinTreeNode<T> *Parent(BinTreeNode<T> *subTree, BinTreeNode<T> *current);

  void PreOrder_(BinTreeNode<T> *subTree, void (*visit)(BinTreeNode<T> *p));
  void InOrder(BinTreeNode<T> *subTree, void (*visit)(BinTreeNode<T> *p));
  void PostOrder_(BinTreeNode<T> *subTree, void (*visit)(BinTreeNode<T> *p));
  void SubTreePrint_(BinTreeNode<T> *node_ptr);

  void SubTreePreOrder_(BinTreeNode<T> *node_ptr, void (*visit)(BinTreeNode<T> *p));
  void SubTreePreOrderNonRecursive_(BinTreeNode<T> *node_ptr, void (*visit)(BinTreeNode<T> *p));
  void SubTreeLevelOrder_(BinTreeNode<T> *root, void (*visit)(BinTreeNode<T> *p));
  void SubTreeInOrderNonRecursive_(BinTreeNode<T> *node_ptr, void (*visit)(BinTreeNode<T> *p));
  void SubTreePostOrderNonRecursive_(BinTreeNode<T> *node_ptr, void (*visit)(BinTreeNode<T>*));

  template<class U>
  friend int operator == (const BinaryTree<T>& s, const BinaryTree<T>& t);
  template<class U>
  friend istream& operator >> (istream& in, BinTreeNode<T>& Tree);
  template<class U>
  friend ostream& operator << (ostream& in, BinTreeNode<T>& Tree);

};



#endif //CYBER_DASH_BINARY_TREE_H
