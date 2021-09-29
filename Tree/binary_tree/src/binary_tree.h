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
  BinTreeNode(): left_child_ptr_(NULL), right_child_ptr_(NULL) {}
  BinTreeNode(T data, BinTreeNode<T>* left_child_ptr = NULL, BinTreeNode<T>* right_child_ptr = NULL):
      data_(data), left_child_ptr_(left_child_ptr), right_child_ptr_(right_child_ptr) {}

  T data_;
  BinTreeNode<T>* left_child_ptr_;
  BinTreeNode<T>* right_child_ptr_;
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

  /* 基础函数 */
  // 是否为空树
  bool IsEmpty() { return root_ptr_ == NULL; }
  // 获取根节点
  BinTreeNode<T>* GetRoot() const { return root_ptr_; }
  // 获取父节点
  BinTreeNode<T>* Parent(BinTreeNode<T> *current) { return (root_ptr_ == NULL || root_ptr_ == current) ? NULL :
    Parent_(root_ptr_, current); }
  // 左孩子
  BinTreeNode<T>* LeftChild(BinTreeNode<T> *current) { return (current != NULL) ? current->left_child_ptr_ : NULL; }
  // 右孩子
  BinTreeNode<T>* RightChild(BinTreeNode<T> *current) { return (current != NULL) ? current->right_child_ptr_ : NULL; }
  // 高度
  int Height() { return SubTreeHeight_(root_ptr_); }
  // Size
  int Size() { return SubTreeSize_(root_ptr_); }
  // 插入结点
  bool Insert(T& item) { return SubTreeInsert_(root_ptr_, item); }
  // 查询结点(是否在树中)
  bool Find(T item) { return SubTreeFind_(root_ptr_, item); }

  /* 遍历系列 */
  // 前序遍历(使用递归)
  void PreOrder(void (*visit)(BinTreeNode<T>*)) { SubTreePreOrder_(root_ptr_, visit); }
  // 前序遍历(使用非递归)
  void PreOrderNonRecursive(void (*visit)(BinTreeNode<T>*)) { SubTreePreOrderNonRecursive_(root_ptr_, visit); }
  // 中序遍历(使用递归)
  void InOrder(void (*visit)(BinTreeNode<T>*)) { SubTreeInOrder_(root_ptr_, visit); }
  // 中序遍历(使用非递归)
  void InOrderNonRecursive(void (*visit)(BinTreeNode<T>*)) { SubTreeInOrderNonRecursive_(root_ptr_, visit); }
  // 后序遍历(使用递归)
  void PostOrder(void (*visit)(BinTreeNode<T>*)) { SubTreePostOrder_(root_ptr_, visit); }
  // 后序遍历(使用非递归)
  void PostOrderNonRecursive(void (*visit)(BinTreeNode<T>*)) { SubTreePostOrderNonRecursive_(root_ptr_, visit); }
  // 层序遍历
  void LevelOrder(void (*visit)(BinTreeNode<T>*)) { SubTreeLevelOrder_(root_ptr_, visit); }

  // 使用前序遍历和中序遍历结果, 创建二叉树
  void CreateBinTreeByPreAndInOrderString(T *pre_order_str_ptr, T *in_order_str_ptr, int str_length) {
    CreateSubBinTreeByPreAndInOrderString_(pre_order_str_ptr, in_order_str_ptr, str_length, root_ptr_);
  }

  /* 打印输出系列 */
  // 打印二叉树(使用'(', ',',')')
  void Print() { SubTreePrint_(root_ptr_); };
  // 使用输入流创建二叉树
  void CreateBinTree(istream &in) { CreateBinTree_(in, root_ptr_); }
  // 使用输出流打印二叉树(前序)
  void Traverse(BinTreeNode<T>* subTree, ostream& out);

  // 我们是CyberDash :-)
  void CyberDashShow();

protected:
  BinTreeNode<T>* root_ptr_;
  T value_;

  void CreateBinTree_(istream& in, BinTreeNode<T> *& subTree);
  // 使用前序遍历和中序遍历结果, 创建二叉子树(递归)
  void CreateSubBinTreeByPreAndInOrderString_(T* pre_order_str_ptr, T* in_order_str_ptr,
                                              int str_length, BinTreeNode<T>*& sub_tree_root_ptr);
  // 子树插入数据
  bool SubTreeInsert_(BinTreeNode<T> *& node_ptr, T& value);
  // 删除子树
  void Destroy(BinTreeNode<T> *& subTree);
  // 查找数据是否在(子)树中
  bool SubTreeFind_(BinTreeNode<T>* sub_tree_root_ptr, T value) const;
  // 复制二叉树
  BinTreeNode<T>* Copy(BinTreeNode<T> *src_tree_root_ptr);
  // 求子树的高度(递归)
  int SubTreeHeight_(BinTreeNode<T> *sub_tree_root_ptr) const;
  // 求子树的Size(递归)
  int SubTreeSize_(BinTreeNode<T>* sub_tree_root_ptr) const;
  // 子树获取节点的父节点
  BinTreeNode<T>* Parent_(BinTreeNode<T>* sub_tree_root_ptr, BinTreeNode<T>* node_ptr);

  // 子树前序遍历(递归)
  void SubTreePreOrder_(BinTreeNode<T>* sub_tree_root_ptr, void (*visit)(BinTreeNode<T>* p));
  // 子树前序遍历(非递归)
  void SubTreePreOrderNonRecursive_(BinTreeNode<T>* sub_tree_root_ptr, void (*visit)(BinTreeNode<T> *p));
  // 子树中序遍历(递归)
  void SubTreeInOrder_(BinTreeNode<T>* sub_tree_root_ptr, void (*visit)(BinTreeNode<T>* p));
  // 子树中序遍历(非递归)
  void SubTreeInOrderNonRecursive_(BinTreeNode<T>* sub_tree_root_ptr, void (*visit)(BinTreeNode<T> *p));
  // 子树后序遍历(递归)
  void SubTreePostOrder_(BinTreeNode<T>* sub_tree_root_ptr, void (*visit)(BinTreeNode<T>* p));
  // 子树后序遍历(非递归)
  void SubTreePostOrderNonRecursive_(BinTreeNode<T> *sub_tree_root_ptr, void (*visit)(BinTreeNode<T>*));

  // 子树层序遍历
  void SubTreeLevelOrder_(BinTreeNode<T> *sub_tree_root_ptr, void (*visit)(BinTreeNode<T> *p));
  // 子树打印
  void SubTreePrint_(BinTreeNode<T> *sub_tree_root_ptr);

  // 判断两颗树相同
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
    Destroy(subTree->left_child_ptr_);
    Destroy(subTree->right_child_ptr_);
    delete subTree;
  }
}


/**
 * @brief 子树获取节点的父节点
 * @tparam T 节点数据模板类型
 * @param sub_tree_root_ptr 子树根节点指针
 * @param node_ptr 节点指针
 * @return 节点的, 位于子树内的, 父节点指针
 */
template<class T>
BinTreeNode<T>* BinaryTree<T>::Parent_(BinTreeNode<T>* sub_tree_root_ptr, BinTreeNode<T>* node_ptr) {

  // 如果子树根为NULL, 则返回NULL
  if (sub_tree_root_ptr == NULL) {
    return NULL;
  }

  // 如果子树根的左孩子or右孩子, 就是node_ptr的父节点, 则返回子树根结点
  if (sub_tree_root_ptr->left_child_ptr_ == node_ptr || sub_tree_root_ptr->right_child_ptr_ == node_ptr) {
    return sub_tree_root_ptr;
  }

  BinTreeNode<T>* parent_ptr = Parent_(sub_tree_root_ptr->left_child_ptr_, node_ptr);

  if (parent_ptr == NULL) {
    parent_ptr = Parent_(sub_tree_root_ptr->right_child_ptr_, node_ptr);
  }

  return parent_ptr;
}


template<class T>
void BinaryTree<T>::Traverse(BinTreeNode<T> *subTree, ostream& out) {
  if (subTree != NULL) {
    out << subTree->data_ << ' ';
    Traverse(subTree->left_child_ptr_, out);
    Traverse(subTree->right_child_ptr_, out);
  }
}


/**
 * 子树前序遍历(递归)
 * @tparam T 节点数据模板类型
 * @param sub_tree_root_ptr 子树根节点指针
 * @param visit 访问函数
 */
template<class T>
void BinaryTree<T>::SubTreePreOrder_(BinTreeNode<T>* sub_tree_root_ptr, void (*visit)(BinTreeNode<T>*)) {
  if (sub_tree_root_ptr == NULL) {
    return;
  }

  visit(sub_tree_root_ptr);

  SubTreePreOrder_(sub_tree_root_ptr->left_child_ptr_, visit);
  SubTreePreOrder_(sub_tree_root_ptr->right_child_ptr_, visit);
}


/**
 * 子树中序遍历(递归)
 * @tparam T 节点数据模板类型
 * @param sub_tree_root_ptr 子树根节点指针
 * @param visit 访问函数
 */
template<class T>
void BinaryTree<T>::SubTreeInOrder_(BinTreeNode<T>* sub_tree_root_ptr,
                                    void (*visit)(BinTreeNode<T>*))
{
  if (sub_tree_root_ptr == NULL) {
    return;
  }

  SubTreeInOrder_(sub_tree_root_ptr->left_child_ptr_, visit);

  visit(sub_tree_root_ptr);

  SubTreeInOrder_(sub_tree_root_ptr->right_child_ptr_, visit);
}


/**
 * 子树后序遍历(递归)
 * @tparam T 节点数据模板类型
 * @param sub_tree_root_ptr 子树根节点指针
 * @param visit 访问函数
 */
template<class T>
void BinaryTree<T>::SubTreePostOrder_(BinTreeNode<T>* sub_tree_root_ptr,
                                      void (*visit)(BinTreeNode<T>*))
{
  if (sub_tree_root_ptr == NULL) {
    return;
  }

  SubTreePostOrder_(sub_tree_root_ptr->left_child_ptr_, visit);
  SubTreePostOrder_(sub_tree_root_ptr->right_child_ptr_, visit);

  visit(sub_tree_root_ptr);
}


/**
 * @brief 求子树的size(递归)
 * @tparam T 节点数据模板类型
 * @param sub_tree_root_ptr 子树根节点指针
 * @return 子树size
 */
template<class T>
int BinaryTree<T>::SubTreeSize_(BinTreeNode<T>* sub_tree_root_ptr) const {
  if (sub_tree_root_ptr == NULL) {
    return 0;
  }

  int left_sub_tree_size = SubTreeSize_(sub_tree_root_ptr->left_child_ptr_); // 递归求左子树size
  int right_sub_tree_size = SubTreeSize_(sub_tree_root_ptr->right_child_ptr_); // 递归求右子树size

  int sub_tree_size = 1 + left_sub_tree_size + right_sub_tree_size;

  return sub_tree_size;
}


/**
 * @brief 求子树的高度(递归)
 * @tparam T 节点数据模板类型
 * @param sub_tree_root_ptr 子树根节点指针
 * @return 子树高度
 */
template<class T>
int BinaryTree<T>::SubTreeHeight_(BinTreeNode<T>* sub_tree_root_ptr) const {
  // 如果子树根节点为空, 则返回0
  if (sub_tree_root_ptr == NULL) {
    return 0;
  }

  int left_sub_tree_height = SubTreeHeight_(sub_tree_root_ptr->left_child_ptr_); // 递归求左子树高度
  int right_sub_tree_height = SubTreeHeight_(sub_tree_root_ptr->right_child_ptr_); // 递归求右子树高度

  // 树高度 = 最高的左右子树高度 + 1
  if (left_sub_tree_height < right_sub_tree_height) {
    return right_sub_tree_height + 1;
  } else {
    return left_sub_tree_height + 1;
  }
}


/**
 * @brief 复制二叉树
 * @tparam T 结点数据模板类型
 * @param src_tree_root_ptr 源树根节点
 * @return 新树根节点
 */
template<class T>
BinTreeNode<T>* BinaryTree<T>::Copy(BinTreeNode<T>* src_tree_root_ptr) {
  if (src_tree_root_ptr == NULL) {
    return NULL;
  }

  BinTreeNode<T>* new_node_ptr = new BinTreeNode<T>();
  /* Null handler */

  new_node_ptr->data_ = src_tree_root_ptr->data_;
  new_node_ptr->left_child_ptr_ = Copy(src_tree_root_ptr->left_child_ptr_);
  new_node_ptr->right_child_ptr_ = Copy(src_tree_root_ptr->right_child_ptr_);

  return new_node_ptr;
}


/**
 * @brief 判断两颗二叉树是否相同
 * @tparam T 结点数据模板类型
 * @param root_ptr_a 根节点a
 * @param root_ptr_b 根节点2
 * @return 是否相同
 */
template<class T>
bool Equal(BinTreeNode<T>* root_ptr_a, BinTreeNode<T>* root_ptr_b) {
  if (root_ptr_a == NULL && root_ptr_b == NULL) {
    return true;
  }

  if (root_ptr_a != NULL && root_ptr_b != NULL && root_ptr_a->data_ == root_ptr_b->data_
      && Equal(root_ptr_a->left_child_ptr_, root_ptr_b->left_child_ptr_)
      && Equal(root_ptr_a->right_child_ptr_, root_ptr_b->right_child_ptr_))
  {
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
      CreateBinTree_(in, subTree->left_child_ptr_);
      CreateBinTree_(in, subTree->right_child_ptr_);
    } else {
      subTree = NULL;
    }
  }
}


template<class T>
int operator == (const BinaryTree<T>& bin_tree_a, const BinaryTree<T>& bin_tree_b) {
  return (Equal(bin_tree_a.GetRoot(), bin_tree_b.GetRoot()));
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


/**
 * @brief 子树插入数据
 * @tparam T 结点数据模板类型
 * @param node_ptr
 * @param value
 * @return
 */
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

  int left_sub_tree_height = SubTreeHeight_(node_ptr->left_child_ptr_);
  int right_sub_tree_height = SubTreeHeight_(node_ptr->right_child_ptr_);

  if (left_sub_tree_height > right_sub_tree_height) {
    insert_res = SubTreeInsert_(node_ptr->right_child_ptr_, value);
  } else {
    insert_res = SubTreeInsert_(node_ptr->left_child_ptr_, value);
  }

  return insert_res;
}


/**
 * @brief 查找数据是否在(子)树中
 * @tparam T 结点数据模板类型
 * @param sub_tree_root_ptr 子树根节点指针
 * @param value 被查找数据
 * @return 是否存在
 */
template<class T>
bool BinaryTree<T>::SubTreeFind_(BinTreeNode<T>* sub_tree_root_ptr, T value) const {

  if (sub_tree_root_ptr == NULL) {
    return false;
  }

  if (sub_tree_root_ptr->data_ == value) {
    return true;
  }

  if (SubTreeFind_(sub_tree_root_ptr->left_child_ptr_, value)) {
    return true;
  }

  return SubTreeFind_(sub_tree_root_ptr->right_child_ptr_, value);
}


/**
 * @brief 子树打印
 * @tparam T 结点数据模板类型
 * @param sub_tree_root_ptr 子树根节点
 */
template<class T>
void BinaryTree<T>::SubTreePrint_(BinTreeNode<T>* sub_tree_root_ptr) {

  if (sub_tree_root_ptr == NULL) {
    return;
  }

  cout << sub_tree_root_ptr->data_;

  if (sub_tree_root_ptr->left_child_ptr_ != NULL || sub_tree_root_ptr->right_child_ptr_ != NULL) {

    cout << '(';

    SubTreePrint_(sub_tree_root_ptr->left_child_ptr_);

    cout << ',';

    if (sub_tree_root_ptr->right_child_ptr_ != NULL) {
      SubTreePrint_(sub_tree_root_ptr->right_child_ptr_);
    }

    cout << ')';
  }
}


/**
 * @brief 子树前序遍历(非递归)
 * @tparam T 节点数据模板类型
 * @param sub_tree_root_ptr 子树根节点指针
 * @param visit 访问函数
 */
template<class T>
void BinaryTree<T>::SubTreePreOrderNonRecursive_(BinTreeNode<T>* sub_tree_root_ptr, void (*visit)(BinTreeNode<T>*)) {

  // (栈初始化)声明前序遍历栈, 子树根节点指针入栈
  stack<BinTreeNode<T>*> pre_traverse_stack;
  pre_traverse_stack.push(sub_tree_root_ptr);

  while (!pre_traverse_stack.empty()) {

    // 出栈
    BinTreeNode<T>* cur_node_ptr = pre_traverse_stack.top();
    pre_traverse_stack.pop();

    // 访问
    visit(cur_node_ptr);

    // 孩子节点入栈
    if (cur_node_ptr->right_child_ptr_ != NULL) {
      pre_traverse_stack.push(cur_node_ptr->right_child_ptr_);
    }

    if (cur_node_ptr->left_child_ptr_ != NULL) {
      pre_traverse_stack.push(cur_node_ptr->left_child_ptr_);
    }
  }
}


/**
 * @brief 子树层序遍历
 * @tparam T 节点数据模板类型
 * @param sub_tree_root_ptr 子树根节点指针
 * @param visit 访问函数
 */
template<class T>
void BinaryTree<T>::SubTreeLevelOrder_(BinTreeNode<T>* sub_tree_root_ptr, void (*visit)(BinTreeNode<T>* node_ptr)) {

  queue<BinTreeNode<T>*> level_traverse_queue;

  BinTreeNode<T>* cur_node_ptr = sub_tree_root_ptr;
  level_traverse_queue.push(cur_node_ptr);

  while (!level_traverse_queue.empty()) {
    cur_node_ptr = level_traverse_queue.front();
    level_traverse_queue.pop();

    visit(cur_node_ptr);

    if (cur_node_ptr->left_child_ptr_ != NULL) {
      level_traverse_queue.push(cur_node_ptr->left_child_ptr_);
    }

    if (cur_node_ptr->right_child_ptr_ != NULL) {
      level_traverse_queue.push(cur_node_ptr->right_child_ptr_);
    }
  }
}


/**
 * @brief 子树中序遍历(非递归)
 * @tparam T 节点数据模板类型
 * @param sub_tree_root_ptr 子树根节点指针
 * @param visit 访问函数
 */
template<class T>
void BinaryTree<T>::SubTreeInOrderNonRecursive_(BinTreeNode<T>* sub_tree_root_ptr, void (*visit)(BinTreeNode<T>*)) {

  stack<BinTreeNode<T>*> in_traverse_stack;
  BinTreeNode<T>* cur_node_ptr = sub_tree_root_ptr;

  while (cur_node_ptr != NULL || !in_traverse_stack.empty()) {

    while (cur_node_ptr != NULL) {
      in_traverse_stack.push(cur_node_ptr);
      cur_node_ptr = cur_node_ptr->left_child_ptr_;
    }

    if (!in_traverse_stack.empty()) {

      cur_node_ptr = in_traverse_stack.top();
      in_traverse_stack.pop();

      visit(cur_node_ptr);

      cur_node_ptr = cur_node_ptr->right_child_ptr_;
    }
  }
}


/**
 * @brief 子树后序遍历(非递归)
 * @tparam T 节点数据模板类型
 * @param sub_tree_root_ptr 子树根节点指针
 * @param visit 访问函数
 */
template <class T>
void BinaryTree<T>::SubTreePostOrderNonRecursive_(BinTreeNode<T>* sub_tree_root_ptr, void (*visit)(BinTreeNode<T>*)) {

  stack<PostOrderStackNode<T> > post_traverse_stack;

  BinTreeNode<T>* cur_node_ptr = sub_tree_root_ptr;

  do {
    while (cur_node_ptr != NULL) {
      PostOrderStackNode<T> traverse_node(cur_node_ptr);
      post_traverse_stack.push(traverse_node);
      cur_node_ptr = cur_node_ptr->left_child_ptr_;
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
          cur_node_ptr = cur_node_ptr->right_child_ptr_;

          left_unfinished = false;

          break;
        case PostOrderStackNode<T>::RIGHT:
          visit(cur_node_ptr);

          break;
      }
    }
  } while (!post_traverse_stack.empty());
}


/**
 * 使用前序遍历和中序遍历结果, 创建二叉子树(递归)
 * @tparam T 节点数据模板类型
 * @param pre_order_str_ptr 前序遍历输出字符串
 * @param in_order_str_ptr 中序遍历输出字符串
 * @param str_length 字符串长度
 * @param sub_tree_root_ptr 二叉树根节点指针
 */
template<class T>
void BinaryTree<T>::CreateSubBinTreeByPreAndInOrderString_(T* pre_order_str_ptr, T* in_order_str_ptr,
                                                           int str_length, BinTreeNode<T>*& sub_tree_root_ptr)
{
  if (str_length == 0) {
    return;
  }

  int pivot = 0;
  T cur_root_value = pre_order_str_ptr[0];

  while (cur_root_value != in_order_str_ptr[pivot]) {
    pivot++;
  }

  sub_tree_root_ptr = new BinTreeNode<T>(cur_root_value);
  if (sub_tree_root_ptr == NULL) {
    cerr << "存储分配错误!" << endl;
    exit(1);
  }

  CreateSubBinTreeByPreAndInOrderString_(pre_order_str_ptr + 1,
                                         in_order_str_ptr,
                                         pivot,
                                         sub_tree_root_ptr->left_child_ptr_);

  CreateSubBinTreeByPreAndInOrderString_(pre_order_str_ptr + pivot + 1,
                                         in_order_str_ptr + pivot + 1,
                                         str_length - pivot - 1,
                                         sub_tree_root_ptr->right_child_ptr_);
}


/**
 * 我们是CyberDash :-)
 */
template<class T>
void BinaryTree<T>::CyberDashShow() {
  cout<<endl
      <<"*************************************** CyberDash ***************************************"<<endl<<endl
      <<"抖音号\"CyberDash计算机考研\", id: cyberdash_yuan"<<endl<<endl
      <<"CyberDash成员:"<<endl
      <<"元哥(cyberdash@163.com), "<<"北京邮电大学(通信工程本科)/北京邮电大学(信息与通信系统研究生)"<<endl
      <<"磊哥(alei_go@163.com), "<<"山东理工大学(数学本科)/北京邮电大学(计算机研究生)"<<endl<<endl
      <<"L_Dash(yuleen_@outlook.com), "<<"北京邮电大学(计算机研究生在读)"<<endl<<endl
      <<"数据结构开源代码(C++清华大学殷人昆)魔改升级版本: https://gitee.com/cyberdash/data-structure-cpp"<<endl
      <<endl<<"*************************************** CyberDash ***************************************"<<endl<<endl;
}


#endif //CYBER_DASH_BINARY_TREE_H
