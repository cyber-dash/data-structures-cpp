//
// Created by cyberdash@163.com on 2021/7/5.
//

#ifndef CYBER_DASH_AVL_TREE_H
#define CYBER_DASH_AVL_TREE_H


#include "binary_search_tree.h"
#include "stack"


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
  bool Insert(Elem data, Key key);
  bool Remove(Key key, Elem& data) { return this->RemoveInSubTree_(this->root_, key, data); }
  int Height() const;
protected:
  AVLNode<Elem, Key>* SearchInSubTree_(const Key& key, const AVLNode<Elem, Key>*& sub_tree_root_ptr) const;
  bool InsertInSubTree_(AVLNode<Elem, Key>*& sub_tree_root_ptr, Elem elem, Key key);
  // bool RemoveInSubTree_(AVLNode<Elem, Key>*& sub_tree_root_ptr, Key key, Elem& elem);
  bool RemoveInSubTree_(AVLNode<Elem, Key>*& sub_tree_root_ptr, Key key);

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
  node_ptr = sub_right_node_ptr->LeftChildPtr();

  // 图7.16(c)
  sub_right_node_ptr->SetLeftChildPtr(node_ptr->RightChildPtr());
  node_ptr->SetRightChildPtr(sub_right_node_ptr);

  // 调整平衡因子
  node_ptr->balance_factor = 0;
  sub_right_node_ptr->balance_factor = 0;
}


template<class Elem, class Key>
void RotateLeftRight_(AVLNode<Elem, Key>*& node_ptr) {

  // 图7.17(b)
  AVLNode<Elem, Key>* sub_right_node_ptr = node_ptr;
  AVLNode<Elem, Key>* sub_left_node_ptr = sub_right_node_ptr->LeftChildPtr();
  node_ptr = sub_left_node_ptr->RightChildPtr();

  // 图7.17(c)
  sub_left_node_ptr->SetRightChildPtr(node_ptr->LeftChildPtr()); // node_ptr成为新根前, 甩掉它的左子树
  node_ptr->SetLeftChildPtr(sub_left_node_ptr); // 左单旋转, node_ptr成为新根

  if (node_ptr->balance_factor <= 0) {
    sub_left_node_ptr->balance_factor = 0;
  } else {
    sub_left_node_ptr->balance_factor = -1;
  }

  sub_right_node_ptr->SetLeftChildPtr(node_ptr->RightChildPtr()); // node_ptr成为新根之前, 甩掉它的右子树
  node_ptr->SetRightChildPtr(sub_right_node_ptr); // 右单旋转, node_ptr成为新根

  if (node_ptr->balance_factor == -1) {
    sub_right_node_ptr->balance_factor = 1;
  } else {
    sub_right_node_ptr->balance_factor = 0;
  }

  node_ptr->balance_factor = 0;
}


template<class Elem, class Key>
void RotateRightLeft_(AVLNode<Elem, Key>*& node_ptr) {

  // 图7.18(b)
  AVLNode<Elem, Key>* sub_left_node_ptr = node_ptr;
  AVLNode<Elem, Key>* sub_right_node_ptr= sub_left_node_ptr->LeftChildPtr();
  node_ptr = sub_right_node_ptr->LeftChildPtr();

  // 图7.18(c)
  sub_right_node_ptr->SetLeftChildPtr(node_ptr->RightChildPtr()); // node_ptr成为新根之前, 甩掉它的右子树
  node_ptr->SetRightChildPtr(sub_right_node_ptr); // 右单旋转, node_ptr成为新根

  if (node_ptr->balance_factor >= 0) {
    sub_right_node_ptr->balance_factor = 0;
  } else {
    sub_right_node_ptr->balance_factor = 1;
  }

  sub_left_node_ptr->SetRightChildPtr(node_ptr->LeftChildPtr()); // node_ptr成为新根前, 甩掉它的左子树
  node_ptr->SetLeftChildPtr(sub_left_node_ptr); // 左单旋转, node_ptr成为新根

  if (node_ptr->balance_factor == 1) {
    sub_left_node_ptr->balance_factor = -1;
  } else {
    sub_left_node_ptr->balance_factor = 0;
  }

  node_ptr->balance_factor = 0;
}


template<class Elem, class Key>
bool AVLTree<Elem, Key>::InsertInSubTree_(AVLNode<Elem, Key>*& sub_tree_root_ptr, Elem elem, Key key) {
  AVLNode<Elem, Key>* cur_stack_node_ptr = NULL; // todo: parent_node_of_insert
  AVLNode<Elem, Key>* cur_node_ptr = sub_tree_root_ptr;

  stack<AVLNode<Elem, Key>*> AVL_node_stack;

  // 寻找插入位置
  while (cur_node_ptr != NULL) {
    // 找到等于key的结点, 无法插入, todo: 原书使用elem
    if (key == cur_node_ptr->GetKey()) {
      return false;
    }

    cur_stack_node_ptr = cur_node_ptr;
    AVL_node_stack.push(cur_stack_node_ptr);

    // todo: 原书使用elem
    if (key < cur_node_ptr->GetKey()) {
      cur_node_ptr = cur_node_ptr->LeftChildPtr();
    } else {
      cur_node_ptr = cur_node_ptr->RightChildPtr();
    }
  }

  cur_node_ptr = new AVLNode<Elem, Key>(elem, key);
  /* error handler */

  // 空树, 新结点成为根节点
  if (cur_stack_node_ptr == NULL) {
    sub_tree_root_ptr = cur_node_ptr;
    return true;
  }

  // todo: 原书使用elem做比较, 应该是错了
  if (key < cur_stack_node_ptr->GetKey()) {
    cur_stack_node_ptr->SetLeftChildPtr(cur_node_ptr);
  } else {
    cur_stack_node_ptr->SetRightChildPtr(cur_node_ptr);
  }

  // 重新平衡化
  while (AVL_node_stack.empty() == false) {
    cur_stack_node_ptr = AVL_node_stack.top();
    AVL_node_stack.pop();

    if (cur_node_ptr == cur_stack_node_ptr->LeftChildPtr()) {
      cur_stack_node_ptr->balance_factor--;
    } else {
      cur_stack_node_ptr->balance_factor++;
    }

    // 第1种情况, 平衡退出
    if (cur_stack_node_ptr->balance_factor == 0) {
      break;
    }

    // 第2种情况, |平衡因子| = 1
    if (cur_stack_node_ptr->balance_factor == 1 || cur_stack_node_ptr->balance_factor == -1) {
      cur_node_ptr = cur_stack_node_ptr;
    } else { // 第3种情况, |bf| = 2
      int stack_node_rotate_flag = (cur_stack_node_ptr->balance_factor < 0) ? -1 : 1;
      if (cur_node_ptr->balance_factor == stack_node_rotate_flag) { // 两个结点的平衡因子同号, 单旋转
        if (stack_node_rotate_flag == -1) {
          this->RotateRight_(cur_stack_node_ptr); // 右单旋转
        } else {
          this->RotateLeft_(cur_stack_node_ptr); // 左单旋转
        }
      } else { // 两个结点的平衡因子反号, 双旋转
        if (stack_node_rotate_flag == -1) {
          this->RotateLeftRight_(cur_stack_node_ptr);
        } else {
          this->RotateRightLeft_(cur_stack_node_ptr);
        }
      }

      break; // 不再向上调整
    }
  }

  if (AVL_node_stack.empty() == true) {
    sub_tree_root_ptr = cur_stack_node_ptr;
  } else {
    AVLNode<Elem, Key>* stack_top_node_ptr = AVL_node_stack.top();
    if (stack_top_node_ptr->GetKey() > cur_stack_node_ptr->GetKey()) {
      stack_top_node_ptr->SetLeftChildPtr(cur_stack_node_ptr);
    } else {
      stack_top_node_ptr->SetRightChildPtr(cur_stack_node_ptr);
    }
  }

  return true;
}


template<class Elem, class Key>
bool AVLTree<Elem, Key>::RemoveInSubTree_(AVLNode<Elem, Key>*& sub_tree_root_ptr, Key key) {

}

#endif // CYBER_DASH_AVL_TREE_H
