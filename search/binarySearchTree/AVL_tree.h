//
// Created by cyberdash@163.com on 2021/7/5.
//

#ifndef CYBER_DASH_AVL_TREE_H
#define CYBER_DASH_AVL_TREE_H


#include "binary_search_tree.h"


template<class Elem, class Key>
class AVLNode: public BSTNode<Elem, Key> {

  AVLNode() {
    this->left_child_ptr_ = NULL;
    this->right_child_ptr_ = NULL;
    this->balance_factor = 0;
  }

  AVLNode(const Elem& elem, const Key& key,
          AVLNode<Elem, Key>* left_child_ptr = NULL,
          AVLNode<Elem, Key>* right_child_ptr = NULL) {
    this->elem_ = elem;
    this->key_ = key;
    this->left_child_ptr_ = left_child_ptr;
    this->right_child_ptr_ = right_child_ptr;
    this->balance_factor = 0;
  }

  int balance_factor;
};


template<class Elem, class Key>
class AVLTree: public BST<Elem, Key> {
public:
  AVLTree() { this->root_ = NULL; }
  bool Insert(const Elem& data, const Key& key);
  bool Remove(Key key, Elem& data) { return this->RemoveInSubTree_(this->root_, key, data); }
  int Height() const;
protected:
  AVLNode<Elem, Key>* SearchInSubTree_(const Key& key, const AVLNode<Elem, Key>*& sub_tree_root_ptr) const;
  bool InsertInSubTree_(AVLNode<Elem, Key>*& sub_tree_root_ptr);
  bool RemoveInSubTree_(AVLNode<Elem, Key>*& sub_tree_root_ptr, Key key, Elem& elem);
  void RotateLeft_(AVLNode<Elem, Key>*& node_ptr);
  void RotateRight_(AVLNode<Elem, Key>*& node_ptr);
  void RotateLeftRight_(AVLNode<Elem, Key>*& node_ptr);
  void RotateRightLeft_(AVLNode<Elem, Key>*& node_ptr);
  int HeightOfSubTree_(AVLNode<Elem, Key>* sub_tree_root_ptr) const;
};


template<class Elem, class Key>
void AVLTree<Elem, Key>::RotateLeft_(AVLNode<Elem, Key>*& node_ptr) {

  AVLNode<Elem, Key>* sub_left_node_ptr = node_ptr;

  node_ptr = sub_left_node_ptr->right_child_ptr_;
  sub_left_node_ptr->right_child_ptr_ = node_ptr->left_child_ptr_;
  node_ptr->left_child_ptr_ = sub_left_node_ptr;

  node_ptr->balance_factor = 0;
  sub_left_node_ptr->balance_factor = 0;
}


#endif // CYBER_DASH_AVL_TREE_H
