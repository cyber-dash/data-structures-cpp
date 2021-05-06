//
// Created by alei_go@163.com(抖音: cyberdash_yuan) on 2020/11/1.
//

#ifndef CYBER_DASH_BINARY_TREE_H
#define CYBER_DASH_BINARY_TREE_H

#include <iostream>
#include <stdlib.h>
#include <stack>
#include <queue>
#include "binary_tree.h"


using namespace std;


template <class T>
struct BinTreeNode {
  BinTreeNode(): left_child_(NULL), right_child_(NULL) {}
  BinTreeNode(T data, BinTreeNode<T>* left_child_ptr = NULL, BinTreeNode<T>* right_child_ptr = NULL):
    data_(data), left_child_(left_child_ptr), right_child_(right_child_ptr) {}

  T data_;
  BinTreeNode<T>* left_child_;
  BinTreeNode<T>* right_child_;
};


template <class T>
struct PostOrderStackNode {
  BinTreeNode<T> *bin_node_ptr;
  enum { LEFT, RIGHT } tag;
  explicit PostOrderStackNode(BinTreeNode<T> *node_ptr = NULL) {
    bin_node_ptr = node_ptr;
    tag = LEFT;
  }
};


template <class T>
class BinaryTree {
public:
  BinaryTree(): root_ptr_(NULL) {}
  BinaryTree(T value): value_(value), root_ptr_(NULL) {}
  BinaryTree(BinaryTree<T>& binary_tree) { root_ptr_ = Copy(binary_tree.root_ptr_); }
  ~BinaryTree() { Destroy(root_ptr_); }

  // 是否为空树
  bool IsEmpty() { return (root_ptr_ == NULL) ? true : false; }
  // 获取根节点
  BinTreeNode<T>* GetRoot() const { return root_ptr_; }
  // 父节点
  BinTreeNode<T>* Parent(BinTreeNode<T> *current) { return (root_ptr_ == NULL || root_ptr_ == current) ? NULL :
    Parent_(root_ptr_, current); }
  // 左孩子
  BinTreeNode<T>* LeftChild(BinTreeNode<T> *current) { return (current != NULL) ? current->left_child_ : NULL; }
  // 右孩子
  BinTreeNode<T>* RightChild(BinTreeNode<T> *current) { return (current != NULL) ? current->right_child_ : NULL; }
  // 深度
  int Height() { return SubTreeHeight_(root_ptr_); }
  // Size
  int Size() { return SubTreeSize_(root_ptr_); }
  // 插入结点
  bool Insert(T& item) { return SubTreeInsert_(root_ptr_, item); }
  // 查询结点(是否在树中)
  bool Find(T item) { return SubTreeFind_(root_ptr_, item); }

  /* 遍历系列 */
  // 前序遍历(递归)
  void PreOrder(void (*visit)(BinTreeNode<T>*)) { PreOrder_(root_ptr_, visit); }
  // 前序遍历(非递归)
  void PreOrderNonRecursive(void (*visit)(BinTreeNode<T>*)) { SubTreePreOrderNonRecursive_(root_ptr_, visit); }
  // 中序遍历(递归)
  void InOrder(void (*visit)(BinTreeNode<T>*)) { InOrder(root_ptr_, visit); }
  // 中序遍历(非递归)
  void InOrderNonRecursive(void (*visit)(BinTreeNode<T>*)) { SubTreeInOrderNonRecursive_(root_ptr_, visit); }
  // 后序遍历(递归)
  void PostOrder(void (*visit)(BinTreeNode<T>*)) { PostOrder_(root_ptr_, visit); }
  // 后序遍历(非递归)
  void PostOrderNonRecursive(void (*visit)(BinTreeNode<T>*)) { SubTreePostOrderNonRecursive_(root_ptr_, visit); }
  // 层序遍历
  void LevelOrder(void (*visit)(BinTreeNode<T> *p)) { SubTreeLevelOrder_(root_ptr_, visit); }

  // 使用前序遍历和中序遍历结果,创建二叉树
  void CreateBinTreeByPreAndInOrderString(T *pre_order_str_ptr, T *in_order_str_ptr, int str_length) {
    CreateSubBinTreeByPreAndInOrderString_(pre_order_str_ptr, in_order_str_ptr, str_length, root_ptr_);
  }

  // 打印二叉树(使用'(', ',',')')
  void Print(void) { SubTreePrint_(root_ptr_); };
  // 使用输入流创建二叉树
  void CreateBinTree(istream &in) { CreateBinTree_(in, root_ptr_); }
  // 使用输出流打印二叉树(前序)
  void Traverse(BinTreeNode<T>* subTree, ostream& out);

  void CyberDashShow();

protected:
  BinTreeNode<T>* root_ptr_;
  T value_;

  void CreateBinTree_(istream& in, BinTreeNode<T> *& subTree);
  BinTreeNode<T>* CreateSubBinTreeByPreAndInOrderString_(T* pre_order_str_ptr, T* in_order_str_ptr, int str_length, BinTreeNode<T> *& node_ptr);
  bool SubTreeInsert_(BinTreeNode<T> *& node_ptr, T& value);
  void Destroy(BinTreeNode<T> *& subTree);
  bool SubTreeFind_(BinTreeNode<T> *node_ptr, T value) const;
  BinTreeNode<T>* Copy(BinTreeNode<T> *orignode);
  int SubTreeHeight_(BinTreeNode<T> *subTree) const;
  int SubTreeSize_(BinTreeNode<T> *subTree) const;
  BinTreeNode<T>* Parent_(BinTreeNode<T> *sub_tree_root_ptr, BinTreeNode<T> *node_ptr);

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


template<class T>
void BinaryTree<T>::Destroy(BinTreeNode<T> *& subTree) {
  if (subTree != NULL) {
    Destroy(subTree->left_child_);
    Destroy(subTree->right_child_);
    delete subTree;
  }
}


/**
 * @brief 二叉子树查找父节点
 *
 * @tparam T
 * @param sub_tree_root_ptr
 * @param node_ptr
 * @return
 */
template<class T>
BinTreeNode<T>* BinaryTree<T>::Parent_(BinTreeNode<T>* sub_tree_root_ptr, BinTreeNode<T>* node_ptr) {

  // 如果子树根为NULL, 则返回NULL
  if (sub_tree_root_ptr == NULL) {
    return NULL;
  }

  // 如果子树根的左孩子or右孩子, 就是node_ptr的父节点, 则返回子树根结点
  if (sub_tree_root_ptr->left_child_ == node_ptr || sub_tree_root_ptr->right_child_ == node_ptr) {
    return sub_tree_root_ptr;
  }

  BinTreeNode<T>* parent_ptr = Parent_(sub_tree_root_ptr->left_child_, node_ptr);

  if (parent_ptr == NULL) {
    parent_ptr = Parent_(sub_tree_root_ptr->right_child_, node_ptr);
  }

  return parent_ptr;

  /*
  // 左右子树递归调用Parent_
  if ((parent_ptr = Parent_(sub_tree_root_ptr->left_child_, node_ptr)) != NULL) {
    return parent_ptr;
  } else {
    return Parent_(sub_tree_root_ptr->right_child_, node_ptr);
  }
   */
}


template<class T>
void BinaryTree<T>::Traverse(BinTreeNode<T> *subTree, ostream& out) {
  if (subTree != NULL) {
    out << subTree->data_ << ' ';
    Traverse(subTree->left_child_, out);
    Traverse(subTree->right_child_, out);
  }
}


template<class T>
void BinaryTree<T>::PreOrder_(BinTreeNode<T> *subTree, void (*visit)(BinTreeNode<T>*)) {
  if (subTree != NULL) {
    visit(subTree);
    PreOrder_(subTree->left_child_, visit);
    PreOrder_(subTree->right_child_, visit);
  }
}


template<class T>
void BinaryTree<T>::InOrder(BinTreeNode<T> *node_ptr, void (*visit)(BinTreeNode<T>*))
{
  if (node_ptr!= NULL) {
    InOrder(node_ptr->left_child_, visit);
    visit(node_ptr);
    InOrder(node_ptr->right_child_, visit);
  }
}


template<class T>
void BinaryTree<T>::PostOrder_(BinTreeNode<T> *subTree,
                               void (*visit)(BinTreeNode<T> *p)) {
  if (subTree != NULL) {
    PostOrder_(subTree->left_child_, visit);
    PostOrder_(subTree->right_child_, visit);
    visit(subTree);
  }
}


template<class T>
int BinaryTree<T>::SubTreeSize_(BinTreeNode<T> *sub_tree) const {
  if (sub_tree == NULL) {
    return 0;
  }

  int left_sub_tree_size = SubTreeSize_(sub_tree->left_child_);
  int right_sub_tree_size = SubTreeSize_(sub_tree->right_child_);

  int sub_tree_size = 1 + left_sub_tree_size + right_sub_tree_size;

  return sub_tree_size;
}


template<class T>
int BinaryTree<T>::SubTreeHeight_(BinTreeNode<T> *subTree) const {
  if (subTree == NULL) {
    return 0;
  } else {
    int i = SubTreeHeight_(subTree->left_child_);
    int j = SubTreeHeight_(subTree->right_child_);
    return (i < j) ? j + 1 : i + 1;
  }
}


template<class T>
BinTreeNode<T> *BinaryTree<T>::Copy(BinTreeNode<T> *orignode) {
  if (orignode == NULL) return NULL;

  BinTreeNode<T> *temp = new BinTreeNode<T>;
  temp->data_ = orignode->data_;
  temp->left_child_ = Copy(orignode->left_child_);
  temp->right_child_ = Copy(orignode->right_child_);

  return temp;
}


template<class T>
bool equal(BinTreeNode<T> *a, BinTreeNode<T> *b) {
  if (a == NULL && b == NULL) return true;

  if (a != NULL && b != NULL && a->data_ == b->data_
      && equal(a->left_child_, b->left_child_)
      && equal(a->right_child_, b->right_child_)) {
    return true;
  } else {
    return false;
  }
}


template<class T>
void BinaryTree<T>::CreateBinTree_(istream& in, BinTreeNode<T>*& subTree) {
  T item;

  if (!in.eof()) {
    in >> item;
    if (item != value_) {
      subTree = new BinTreeNode<T>(item);
      if(subTree == NULL) {
        cerr << "存储分配错误!" << endl;
        exit(1);
      }
      CreateBinTree_(in, subTree->left_child_);
      CreateBinTree_(in, subTree->right_child_);
    } else {
      subTree = NULL;
    }
  }
}


template<class T>
int operator == (const BinaryTree<T>& s, const BinaryTree<T>& t) {
  return (equal(s.GetRoot(), t.GetRoot())) ? true : false;
}


template<class T>
istream& operator >> (istream& in, BinaryTree<T>& Tree) {
  Tree.CreateBinTree(in);
  return in;
}


template<class T>
ostream& operator << (ostream& out, BinaryTree<T>& Tree) {
  out << "二叉树的前序遍历\n";
  Tree.Traverse(Tree.GetRoot(), out);
  out << endl;
  return out;
}


template<class T>
bool BinaryTree<T>::SubTreeInsert_(BinTreeNode<T>*& node_ptr, T& value) {

  if (node_ptr == NULL) {
    node_ptr = new BinTreeNode<T>(value);
    if (node_ptr == NULL) {
      cerr << "存储分配错误!" << endl;
      return false;
    }

    return true;
  }

  bool insert_res = false;

  int left_sub_tree_height = SubTreeHeight_(node_ptr->left_child_);
  int right_sub_tree_height = SubTreeHeight_(node_ptr->right_child_);

  if (left_sub_tree_height > right_sub_tree_height) {
    insert_res = SubTreeInsert_(node_ptr->right_child_, value);
  } else {
    insert_res = SubTreeInsert_(node_ptr->left_child_, value);
  }

  return insert_res;
}


template<class T>
bool BinaryTree<T>::SubTreeFind_(BinTreeNode<T> *node_ptr, T value) const {

  if (node_ptr == NULL) {
    return false;
  }

  if (node_ptr->data_ == value) {
    return true;
  }

  if (SubTreeFind_(node_ptr->left_child_, value)) {
    return true;
  }

  return SubTreeFind_(node_ptr->right_child_, value);
}


template<class T>
void BinaryTree<T>::SubTreePrint_(BinTreeNode<T> *node_ptr) {

  if (node_ptr == NULL) {
    return;
  }

  cout<<node_ptr->data_;

  if (node_ptr->left_child_ != NULL || node_ptr->right_child_ != NULL) {

    cout << '(';

    SubTreePrint_(node_ptr->left_child_);

    cout << ',';

    if (node_ptr->right_child_ != NULL) {
      SubTreePrint_(node_ptr->right_child_);
    }

    cout << ')';
  }
}


/**
 * @brief 二叉子树前序遍历(非递归)
 *
 * @tparam T
 * @param node_ptr
 * @param visit
 */
template<class T>
void BinaryTree<T>::SubTreePreOrderNonRecursive_(BinTreeNode<T> *node_ptr, void (*visit)(BinTreeNode<T>*)) {

  stack<BinTreeNode<T> *> pre_traverse_stack;

  pre_traverse_stack.push(node_ptr);

  while (! pre_traverse_stack.empty()) {

    BinTreeNode<T>* cur_node_ptr = pre_traverse_stack.top();
    pre_traverse_stack.pop();

    visit(cur_node_ptr);

    if (cur_node_ptr->right_child_ != NULL) {
      pre_traverse_stack.push(cur_node_ptr->right_child_);
    }

    if (cur_node_ptr->left_child_ != NULL) {
      pre_traverse_stack.push(cur_node_ptr->left_child_);
    }
  }
}


template<class T>
void BinaryTree<T>::SubTreeLevelOrder_(BinTreeNode<T> *root, void (*visit)(BinTreeNode<T>* node_ptr)) {

  queue<BinTreeNode<T>*> level_traverse_queue;

  BinTreeNode<T>* cur_node_ptr = root;
  level_traverse_queue.push(cur_node_ptr);

  while (!level_traverse_queue.empty()) {
    cur_node_ptr = level_traverse_queue.front();
    level_traverse_queue.pop();

    visit(cur_node_ptr);

    if (cur_node_ptr->left_child_ != NULL) {
      level_traverse_queue.push(cur_node_ptr->left_child_);
    }

    if (cur_node_ptr->right_child_ != NULL) {
      level_traverse_queue.push(cur_node_ptr->right_child_);
    }
  }
}


template<class T>
void BinaryTree<T>::SubTreeInOrderNonRecursive_(BinTreeNode<T> *node_ptr, void (*visit)(BinTreeNode<T>*)) {

  stack<BinTreeNode<T> *> in_traverse_stack;
  BinTreeNode<T> *cur_node_ptr = node_ptr;

  while (cur_node_ptr != NULL || !in_traverse_stack.empty()) {

    while (cur_node_ptr != NULL) {
      in_traverse_stack.push(cur_node_ptr);
      cur_node_ptr = cur_node_ptr->left_child_;
    }

    if (!in_traverse_stack.empty()) {

      cur_node_ptr = in_traverse_stack.top();
      in_traverse_stack.pop();

      visit(cur_node_ptr);

      cur_node_ptr = cur_node_ptr->right_child_;
    }
  }
}


template <class T>
void BinaryTree<T>::SubTreePostOrderNonRecursive_(BinTreeNode<T> *node_ptr, void (*visit)(BinTreeNode<T>*)) {

  stack<PostOrderStackNode<T> > post_traverse_stack;

  BinTreeNode<T>* cur_node_ptr = node_ptr;

  do {
    while (cur_node_ptr != NULL) {
      PostOrderStackNode<T> traverse_node(cur_node_ptr);
      post_traverse_stack.push(traverse_node);
      cur_node_ptr = cur_node_ptr->left_child_;
    }

    bool left_unfinished = true;
    while (left_unfinished && !post_traverse_stack.empty()) {

      PostOrderStackNode<T> cur_traverse_node = post_traverse_stack.top();
      post_traverse_stack.pop();

      cur_node_ptr = cur_traverse_node.bin_node_ptr;

      switch (cur_traverse_node.tag) {
        case PostOrderStackNode<T>::LEFT:
          cur_traverse_node.tag = PostOrderStackNode<T>::RIGHT;
          post_traverse_stack.push(cur_traverse_node);
          cur_node_ptr = cur_node_ptr->right_child_;

          left_unfinished = false;

          break;
        case PostOrderStackNode<T>::RIGHT:
          visit(cur_node_ptr);

          break;
      }
    }
  } while (!post_traverse_stack.empty());
}


template<class T>
BinTreeNode<T>* BinaryTree<T>::CreateSubBinTreeByPreAndInOrderString_(
  T *pre_order_str_ptr, T *in_order_str_ptr, int str_length, BinTreeNode<T>*& node_ptr)
{
  if (str_length == 0) {
    return NULL;
  }

  int pivot = 0;
  T cur_root_value = pre_order_str_ptr[0];

  while (cur_root_value != in_order_str_ptr[pivot]) {
    pivot++;
  }

  node_ptr = new BinTreeNode<T>(cur_root_value);
  if (node_ptr == NULL) {
    cerr << "存储分配错误!" << endl;
    exit(1);
  }

  CreateSubBinTreeByPreAndInOrderString_(pre_order_str_ptr + 1,
                                         in_order_str_ptr,
                                         pivot,
                                         node_ptr->left_child_);

  CreateSubBinTreeByPreAndInOrderString_(pre_order_str_ptr + pivot + 1,
                                         in_order_str_ptr + pivot + 1,
                                         str_length - pivot - 1,
                                         node_ptr->right_child_);

  return node_ptr;
}


template<class T>
void BinaryTree<T>::CyberDashShow() {
  cout<<endl
      <<"*************************************** CyberDash ***************************************"<<endl<<endl
      <<"抖音号\"CyberDash计算机考研\", id: cyberdash_yuan"<<endl<<endl
      <<"CyberDash成员:"<<endl
      <<"元哥(cyberdash@163.com), "<<"北京邮电大学(通信工程本科)/北京邮电大学(信息与通信系统研究生)"<<endl
      <<"磊哥(alei_go@163.com), "<<"山东理工大学(数学本科)/北京邮电大学(计算机研究生)"<<endl<<endl
      <<"数据结构开源代码(C++清华大学殷人昆)魔改升级版本: https://gitee.com/cyberdash/data-structure-cpp"<<endl
      <<endl<<"*************************************** CyberDash ***************************************"<<endl<<endl;
}


#endif //CYBER_DASH_BINARY_TREE_H
