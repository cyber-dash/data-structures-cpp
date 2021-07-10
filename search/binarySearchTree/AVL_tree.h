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

  // 左单旋转(Rotation Left), 图7.15(a)的情形
  void RotateLeft_(AVLNode<Elem, Key>*& node_ptr);
  // 右单旋转(Rotation Right), 图7.16(a)的情形
  void RotateRight_(AVLNode<Elem, Key>*& node_ptr);
  // 先左后右双旋转(Rotation Left Right), 图7.17(a)的情形
  void RotateLeftRight_(AVLNode<Elem, Key>*& node_ptr);
  // 先右后左双旋转(Rotation Right Left), 图7.18(a)的情形
  void RotateRightLeft_(AVLNode<Elem, Key>*& node_ptr);
  // AVL子树的高度
  int HeightOfSubTree_(AVLNode<Elem, Key>* sub_tree_root_ptr) const;
};


/**
 * 左单旋转(Rotation Left), 图7.15(a)的情形
 * @tparam Elem 搜索结果(数据)模板类型
 * @tparam Key 关键码模板类型
 * @param node_ptr AVL树节点指针的引用
 */
template<class Elem, class Key>
void AVLTree<Elem, Key>::RotateLeft_(AVLNode<Elem, Key>*& node_ptr) {

  // 图7.15(b)
  AVLNode<Elem, Key>* sub_left_node_ptr = node_ptr;
  node_ptr = sub_left_node_ptr->right_child_ptr_;

  // 图7.15(c)
  sub_left_node_ptr->right_child_ptr_ = node_ptr->left_child_ptr_;
  node_ptr->left_child_ptr_ = sub_left_node_ptr;

  // 调整平衡因子
  node_ptr->balance_factor = 0;
  sub_left_node_ptr->balance_factor = 0;
}


/**
 * 右单旋转(Rotation Right), 图7.16(a)的情形
 * @tparam Elem 搜索结果(数据)模板类型
 * @tparam Key 关键码模板类型
 * @param node_ptr AVL树节点指针的引用
 */
template<class Elem, class Key>
void AVLTree<Elem, Key>::RotateRight_(AVLNode<Elem, Key>*& node_ptr) {

  // 图7.16(b)
  AVLNode<Elem, Key>* sub_right_node_ptr = node_ptr;
  node_ptr = sub_right_node_ptr->left_child_ptr_;

  // 图7.16(c)
  sub_right_node_ptr->left_child_ptr_ = node_ptr->right_child_ptr_;
  node_ptr->right_child_ptr_ = sub_right_node_ptr;

  // 调整平衡因子
  node_ptr->balance_factor = 0;
  sub_right_node_ptr->balance_factor = 0;
}


template<class Elem, class Key>
void RotateLeftRight_(AVLNode<Elem, Key>*& node_ptr) {

  // 图7.17(b)
  AVLNode<Elem, Key>* sub_right_node_ptr = node_ptr;
  // AVLNode<Elem, Key>* sub_left_node_ptr = sub_right_node_ptr->left_child_ptr_;
  AVLNode<Elem, Key>* sub_left_node_ptr = sub_right_node_ptr->LeftChildPtr();
  node_ptr = sub_left_node_ptr->RightChildPtr();

  // 图7.17(c)
  sub_left_node_ptr->right_child_ptr_ = sub_left_node_ptr; // node_ptr成为新根前, 甩掉它的左子树

  node_ptr->left_child_ptr_ = sub_left_node_ptr;

  if (node_ptr->balance_factor <= 0) {
    sub_left_node_ptr->balance_factor = 0;
  } else {
    sub_left_node_ptr->balance_factor = -1;
  }

  sub_right_node_ptr->left_child_ptr_ = node_ptr->right_child_ptr_;
  node_ptr->right_child_ptr_ = sub_right_node_ptr;

  if (node_ptr->balance_factor == -1) {
    sub_right_node_ptr->balance_factor = 1;
  } else {
    sub_right_node_ptr->balance_factor = 0;
  }

  node_ptr->balance_factor = 0;
}


template<class Elem, class Key>
void RotateRightLeft_(AVLNode<Elem, Key>*& node_ptr) {

  // 图7.17(b) --> 图7.17(c)
  AVLNode<Elem, Key>* sub_left_node_ptr = node_ptr;
  AVLNode<Elem, Key>* sub_right_node_ptr= sub_left_node_ptr->left_child_ptr_;

  node_ptr->left_child_ptr_ = sub_right_node_ptr;

  if (node_ptr->balance_factor <= 0) {
    sub_right_node_ptr->balance_factor = 0;
  } else {
    sub_right_node_ptr->balance_factor = 1;
  }

  sub_left_node_ptr->left_child_ptr_ = node_ptr->right_child_ptr_;
  node_ptr->right_child_ptr_ = sub_left_node_ptr;

  if (node_ptr->balance_factor == -1) {
    sub_left_node_ptr->balance_factor = -1;
  } else {
    sub_left_node_ptr->balance_factor = 0;
  }

  node_ptr->balance_factor = 0;
}


#endif // CYBER_DASH_AVL_TREE_H
