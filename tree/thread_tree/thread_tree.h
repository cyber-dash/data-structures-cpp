//
// Created by alei_go@163.com(抖音: cyberdash_yuan) on 2020/11/1.
//

#ifndef CYBER_DASH_THREAD_TREE_H
#define CYBER_DASH_THREAD_TREE_H


#include "thread_node.h"
#include <iostream>
#include <cstdlib>


using namespace std;


template <class T>
class ThreadTree {
public:
  ThreadTree(): root_() {}

  ThreadNode<T>* GetRoot() { return root_; }

  void CreateInOrderThread();
  void CreatePreOrderThread();
  void CreatePostThread();

  ThreadNode<T>* First(ThreadNode<T>* node_ptr);
  ThreadNode<T>* Last(ThreadNode<T>* node_ptr);

  ThreadNode<T>* Next(ThreadNode<T>* node_ptr);
  ThreadNode<T>* Prior(ThreadNode<T>* node_ptr);

  ThreadNode<T>* Parent(ThreadNode<T>* node_ptr) { return Parent_(node_ptr); }

  ThreadNode<T>* PreOrderNext(ThreadNode<T> *node_ptr);
  ThreadNode<T>* PreOrderPrior(ThreadNode<T> *current);

  ThreadNode<T>* PostOrderNext(ThreadNode<T> *current);
  ThreadNode<T>* PostOrderPrior(ThreadNode<T> *current);

  // 中序线索二叉树中序遍历
  void InOrderTraverse(void (*visit)(ThreadNode<T>* node_ptr));
  // 中序线索二叉树前序遍历
  void PreOrderTraverse(void (*visit)(ThreadNode<T>* node_ptr));
  // 中序线索二叉树后序遍历
  void PostOrderTraverse(void (*visit)(ThreadNode<T> *p));
  ThreadNode<T>* FindFirstNodeForPostOrderTraverse(ThreadNode<T>* node_ptr);

  bool Insert(T& data) { return Insert_(root_, data);}
  void InsertRight(ThreadNode<T>* s, ThreadNode<T> *r);
  void InsertLeft(ThreadNode<T>* s, ThreadNode<T> *r);
  void DeleteRight(ThreadNode<T>* s);
  void DeleteLeft(ThreadNode<T>* s);

  void CyberDashShow();

protected:
  ThreadNode<T>* root_;
  // void CreateSubInOrderThread_(ThreadNode<T>* node_ptr, ThreadNode<T>*& pre_node_ptr);
  void CreateSubInOrderThread_(ThreadNode<T>*& node_ptr, ThreadNode<T>*& pre_node_ptr);
  // void CreateSubPreOrderThread_(ThreadNode<T>*& node_ptr, ThreadNode<T>*& pre_node_ptr);
  void CreateSubPreOrderThread_(ThreadNode<T>* node_ptr, ThreadNode<T>*& pre_node_ptr);
  void CreatePostOrderThread_(ThreadNode<T>*& node_ptr, ThreadNode<T>*& pre_node_ptr);
  ThreadNode<T>* Parent_(ThreadNode<T>* node_ptr);

  bool Insert_(ThreadNode<T>*& node_ptr, T& data);
};


/**
 * @brief 求(node_ptr为根的)当前中序线索树的第一个节点指针
 * 左子树遍历至最深的节点
 * @tparam T 树节点数据类型
 * @param node_ptr 当前选中的节点
 * @return
 */
template <class T>
ThreadNode<T>* ThreadTree<T>::First(ThreadNode<T>* node_ptr) {
  ThreadNode<T>* cur_node_ptr = node_ptr;

  while (cur_node_ptr != NULL &&
      cur_node_ptr->left_child_ != NULL &&
      cur_node_ptr->left_tag_ == IS_CHILD)
  {
    cur_node_ptr = cur_node_ptr->left_child_;
  }

  return cur_node_ptr;
}


/**
 * @brief 中序线索树的下一节点
 * 最右子节点的First()
 * @tparam T 树节点数据类型
 * @param node_ptr 当前选中节点
 * @return Next节点指针
 */
template <class T>
ThreadNode<T>* ThreadTree<T>::Next(ThreadNode<T> *node_ptr) {
  if (node_ptr == NULL) {
    exit(1); // error handler
  }

  ThreadNode<T>* right_child_ptr = node_ptr->right_child_;

  if (right_child_ptr != NULL && node_ptr->right_tag_ == IS_CHILD)
  {
    return First(right_child_ptr);
  }

  return right_child_ptr;
}


/**
 * @brief 求(node_ptr为根的)当前二叉树的最后一个线索节点的节点指针
 * 最右子节点(可能非叶子)
 * @tparam T 树节点数据类型
 * @param node_ptr 当前节点
 * @return 最后一个线索节点的指针
 */
template <class T>
ThreadNode<T>* ThreadTree<T>::Last(ThreadNode<T> *node_ptr) {
  ThreadNode<T>* cur_node_ptr = node_ptr;

  while (cur_node_ptr != NULL &&
      cur_node_ptr->right_child_ != NULL &&
      cur_node_ptr->right_tag_ == IS_CHILD)
  {
    cur_node_ptr = cur_node_ptr->right_child_;
  }

  return cur_node_ptr;
}


/**
 * @brief
 * @tparam T
 * @param node_ptr
 * @return
 */
template <class T>
ThreadNode<T>* ThreadTree<T>::Prior(ThreadNode<T> *node_ptr) {
  ThreadNode<T>* left_node_ptr = node_ptr->left_child_;

  if (node_ptr->left_tag_ == IS_CHILD) {
    return Last(left_node_ptr);
  }

  return left_node_ptr;
}


/**
 * @brief
 * @tparam T
 * @param visit
 */
template <class T>
void ThreadTree<T>::InOrderTraverse(void (*visit)(ThreadNode<T>*)) {
  for (ThreadNode<T>* node_ptr = First(root_); node_ptr != NULL; node_ptr = Next(node_ptr)) {
    visit(node_ptr);
  }
}


/**
 * @brief 调用CreateInOrderSubThread_创建中序线索
 * @tparam T 树节点数据类型
 */
template <class T>
void ThreadTree<T>::CreateInOrderThread() {
  if (root_ == NULL) {
    return;
  }

  ThreadNode<T>* pre_node_ptr = NULL;

  CreateSubInOrderThread_(root_, pre_node_ptr);

  // 最后一个线索节点, 收尾工作
  if (pre_node_ptr != NULL) {
    pre_node_ptr->right_child_ = NULL;
    pre_node_ptr->right_tag_ = IS_THREAD_NODE;
  }
}


/**
 * @brief 子树创建中序线索(递归)
 * 递归终止条件:
 *    当前节点为null
 * 分治递归:
 *    左子树执行
 *    调整线索
 *    右子树执行
 * @tparam T 树节点数据类型
 * @param node_ptr 当前节点
 * @param pre_node_ptr 当前节点的前驱节点
 */
template <class T>
void ThreadTree<T>::CreateSubInOrderThread_(ThreadNode<T>*& node_ptr, ThreadNode<T>*& pre_node_ptr) {

  if (node_ptr == NULL) {
    return;
  }

  // 左子树分治
  CreateSubInOrderThread_(node_ptr->left_child_, pre_node_ptr);

  // (利用left_child_)
  // 如果left_child_指针为NULL,
  // 则将node_ptr->left_child_指向pre_node_ptr, 加入线索树
  if (node_ptr->left_child_ == NULL) {
    node_ptr->left_child_ = pre_node_ptr;
    node_ptr->left_tag_ = IS_THREAD_NODE;
  }

  // (利用right_child_)
  // 如果前一节点pre_node_ptr不为NULL, 并且它的right_child_不为NULL,
  // 则前一节点的right_child_指向node_ptr, 加入线索树
  if (pre_node_ptr != NULL && pre_node_ptr->right_child_ == NULL) {
    pre_node_ptr->right_child_ = node_ptr;
    pre_node_ptr->right_tag_ = IS_THREAD_NODE;
  }

  pre_node_ptr = node_ptr; // pre_node_ptr节点后移

  // 右子树分治
  CreateSubInOrderThread_(node_ptr->right_child_, pre_node_ptr);
}


template <class T>
void ThreadTree<T>::CreatePreOrderThread() {
  ThreadNode<T> *node_ptr = NULL;

  if (root_ != NULL) {
    CreateSubPreOrderThread_(root_, node_ptr);
    node_ptr->right_child_ = NULL;
    node_ptr->right_tag_ = 1;
  }
}


/**
 *
 * @tparam T
 * @param node_ptr
 * @param pre_node_ptr
 */
template <class T>
void ThreadTree<T>::CreateSubPreOrderThread_(ThreadNode<T>* node_ptr, ThreadNode<T>*& pre_node_ptr) {

  if (node_ptr == NULL) {
    return;
  }

  // (利用left_child_)
  // 如果left_child_指针为NULL,
  // 则将node_ptr->left_child_指向pre_node_ptr, 加入线索树
  if (node_ptr->left_child_ == NULL) {
    node_ptr->left_child_ = pre_node_ptr;
    node_ptr->left_tag_ = IS_THREAD_NODE;
  }

  // (利用right_child_)
  // 如果前一节点pre_node_ptr不为NULL, 并且它的right_child_不为NULL,
  // 则前一节点的right_child_指向node_ptr, 加入线索树
  if (pre_node_ptr != NULL && pre_node_ptr->right_child_ == NULL) {
    pre_node_ptr->right_child_ = node_ptr;
    pre_node_ptr->right_tag_ = IS_THREAD_NODE;
  }

  pre_node_ptr = node_ptr; // pre_node_ptr节点后移

  // 左子树分治
  // CreateSubPreOrderThread_(node_ptr->left_child_, pre_node_ptr); // 左子树遍历
  if (node_ptr->left_tag_ == IS_CHILD) {
    CreateSubPreOrderThread_(node_ptr->left_child_, pre_node_ptr); // 左子树遍历
  }

  // 右子树分治
  CreateSubPreOrderThread_(node_ptr->right_child_, pre_node_ptr); // 右子树遍历
}


/**
 *
 * @tparam T
 */
template <class T>
void ThreadTree<T>::CreatePostThread() {
  if (root_ == NULL) {
    return;
  }

  ThreadNode<T>* pre_node_ptr = NULL;

  CreatePostOrderThread_(root_, pre_node_ptr);

  pre_node_ptr->right_child_ = NULL;
  pre_node_ptr->right_tag_ = 1;
}


/**
 * @brief
 * @tparam T
 * @param node_ptr
 * @param pre_node_ptr
 */
template <class T>
void ThreadTree<T>::CreatePostOrderThread_(ThreadNode<T>*& node_ptr, ThreadNode<T>*& pre_node_ptr) {
  if (node_ptr == NULL) {
    return;
  }

  CreatePostOrderThread_(node_ptr->left_child_, pre_node_ptr);

  CreatePostOrderThread_(node_ptr->right_child_, pre_node_ptr);

  if (node_ptr->left_child_ == NULL) {
    node_ptr->left_child_ = pre_node_ptr;
    node_ptr->left_tag_ = IS_THREAD_NODE;
  }

  if (pre_node_ptr != NULL && pre_node_ptr->right_child_ == NULL) {
    pre_node_ptr->right_child_ = node_ptr;
    pre_node_ptr->right_tag_ = IS_THREAD_NODE;
  }

  pre_node_ptr = node_ptr;
}


template <class T>
ThreadNode<T> *ThreadTree<T>::PreOrderNext(ThreadNode<T>* node_ptr) {

  if (node_ptr->left_tag_ != IS_THREAD_NODE) {
    return node_ptr->left_child_;
  }

  return node_ptr->right_child_;
}


template <class T>
ThreadNode<T> *ThreadTree<T>::PreOrderPrior(ThreadNode<T> *current) {

  if (current->left_tag_ == IS_THREAD_NODE) {
    return current->left_child_;
  }

  ThreadNode<T> *parent = Parent_(current);

  if (parent == NULL) {
    return NULL;
  }

  if (parent->left_tag_ == 1 || parent->left_child_ == current) {
    return parent;
  }

  return Last(parent->left_child_);
}


/**
 * @brief 中序线索二叉树前序遍历
 * 若当前结点有左子女, 则前序的后继结点为左孩子节点
 * 否则, 若当前结点有右子女, 则前序的后继结点为右孩子节点
 * 对于叶子结点, 沿着中序后继线索, 走到一个有右子女结点的结点, 这个右子女结点就是当前结点的前序后继结点
 * @tparam T
 * @param visit
 */
template <class T>
void ThreadTree<T>::PreOrderTraverse(void (*visit)(ThreadNode<T>* node_ptr)) {
  ThreadNode<T> *cur = root_;

  while (cur != NULL) {
    visit(cur);

    if (cur->left_tag_ == IS_CHILD) { // 若有左子女, 则为前序后继
      cur = cur->left_child_;
    } else if (cur->right_tag_ == IS_CHILD) { // 否则若有右子女, 则为前序后继
      cur = cur->right_child_;
    } else { // 对于叶子结点, 沿着中序后继线索, 走到一个有右子女结点的结点, 这个右子女结点就是当前结点的前序后继结点
      while (cur != NULL && cur->right_tag_ == IS_THREAD_NODE) {
        cur = cur->right_child_;
      }

      if (cur != NULL) {
        cur = cur->right_child_;
      }
    }
  }
}


/**
 * @brief 中序线索二叉树, 后续遍历
 * 重复下述过程, 直到叶结点为止:
 *    从根出发, 沿着左子树链一直找下去, 找到左孩子不再是做孩子指针的结点
 *    再找到该结点的右孩子, 以此结点为根的子树上,
 * 接着, 从此结点开始后序遍历, 每次先找到当前节点的父节点
 *    如果当前结点是父节点的右孩子or虽然是这个父节点的左孩子, 但这个父节点没有右孩子
 *       则后序下的后继为该父节点
 *    否则, 在当前结点的右子树(如果存在)上重复执行上面的操作
 * @tparam T
 * @param visit
 */
template <class T>
void ThreadTree<T>::PostOrderTraverse(void (*visit)(ThreadNode<T>*)) {

  ThreadNode<T>* cur = FindFirstNodeForPostOrderTraverse(root_);
  ThreadNode<T> *cur_parent;

  visit(cur); // 访问第一个结点

  while ((cur_parent = Parent_(cur)) != NULL) {
    if (cur_parent->right_child_ == cur ||  // 当前结点是父节点的右孩子
        cur_parent->right_tag_ == IS_THREAD_NODE) // 当前结点是父节点左孩子, 并且父节点没有右孩子
    {
      cur = cur_parent;
    } else {
      cur = FindFirstNodeForPostOrderTraverse(cur_parent->right_child_);
    }

    visit(cur);
  }
}


/**
 * @brief 中序线索树后续遍历, 找到第一个遍历结点(以node_ptr为根)
 * 重复下述过程, 直到叶结点为止:
 *    沿着左子树链一直找下去, 找到左孩子不再是做孩子指针的结点
 *    再找到该结点的右孩子, 以此结点为根的子树上,
 * @tparam T
 * @param node_ptr
 * @return
 */
template<class T>
ThreadNode<T>* ThreadTree<T>::FindFirstNodeForPostOrderTraverse(ThreadNode<T>* node_ptr) {

  ThreadNode<T>* cur = node_ptr;

  while (cur->left_tag_ == IS_CHILD || cur->right_tag_ == IS_CHILD) {
    if (cur->left_tag_ == IS_CHILD) {
      cur = cur->left_child_;
    } else if (cur->right_tag_ == IS_CHILD) {
      cur = cur->right_child_;
    }
  }

  return cur;
}


/**
 * @brief 中序线索二叉树求父节点
 * 两条路径:
 *   1: 从当前结点走到树上层的一个中序前驱(不一定是直接前驱), 然后向右下找父节点
 *   2: 从当前结点走到书上层的一个中序后继(不一定是直接后继), 然后向左下找父节点
 * @tparam T
 * @param node_ptr
 * @return
 */
template <class T>
ThreadNode<T> *ThreadTree<T>::Parent_(ThreadNode<T>* node_ptr) {

  if (node_ptr == root_) {
    return NULL;
  }

  /*
   * 尝试路径1
   */
  // 遍历至最左子节点
  ThreadNode<T>* left_side_child_ptr = node_ptr;
  while (left_side_child_ptr->left_tag_ == IS_CHILD) {
    left_side_child_ptr = left_side_child_ptr->left_child_;
  }

  if (left_side_child_ptr->left_child_ != NULL) { // 如果等于NULL, 则寻找树上层的中序前驱失败, 路径1失败
    ThreadNode<T>* upper_level_pre_node = left_side_child_ptr->left_child_; // 树上层的中序前驱

    // 向右下找父节点
    while (upper_level_pre_node != NULL &&
           upper_level_pre_node->left_child_ != node_ptr &&
           upper_level_pre_node->right_child_ != node_ptr) {
      upper_level_pre_node = upper_level_pre_node->right_child_;
    }

    if (upper_level_pre_node != NULL) { // 如果不等于NULL, 则找到父节点, 否则路径1失败
      return upper_level_pre_node;
    }
  }

  /*
   * 尝试路径2
   */
  // 遍历至最右子节点
  ThreadNode<T>* right_side_child_ptr = node_ptr;
  while (right_side_child_ptr->right_tag_ == IS_CHILD) {
    right_side_child_ptr = right_side_child_ptr->right_child_;
  }

  ThreadNode<T>* upper_level_post_node = right_side_child_ptr->right_child_; // 树上层的中序后继

  // 向左下找父节点
  while (upper_level_post_node != NULL &&
         upper_level_post_node->left_child_ != node_ptr &&
         upper_level_post_node->right_child_ != node_ptr) {
    upper_level_post_node = upper_level_post_node->left_child_;
  }

  return upper_level_post_node;
}


/**
 * @brief 二叉树插入(建立线索之前)
 * @tparam T
 * @param node_ptr 被插入的子树的根结点
 * @param data
 * @return
 */
template<class T>
bool ThreadTree<T>::Insert_(ThreadNode<T>*& node_ptr, T& data) {

  if (node_ptr == NULL) {
    node_ptr = new ThreadNode<T>(data);
    /* new error handler*/
    return true;
  }

  int left_sub_tree_height = Height(node_ptr->left_child_);
  int right_sub_tree_height = Height(node_ptr->right_child_);

  if (left_sub_tree_height > right_sub_tree_height) {
    return Insert_(node_ptr->right_child_, data);
  } else {
    return Insert_(node_ptr->left_child_, data);
  }
}


/**
 * @brief 二叉子树的深度
 * @tparam T
 * @param node_ptr 二叉子树的根
 * @return 深度
 */
template<class T>
int Height(ThreadNode<T>* node_ptr) {
  if (node_ptr == NULL) {
    return 0;
  }

  int left_sub_tree_height = Height(node_ptr->left_child_);
  int right_sub_tree_height = Height(node_ptr->right_child_);
  return (left_sub_tree_height < right_sub_tree_height) ?
    right_sub_tree_height + 1 : left_sub_tree_height + 1;
}


/**
 * @breif
 * @tparam T
 * @param s
 * @param r
 */
template<class T>
void ThreadTree<T>::InsertRight(ThreadNode<T>* s, ThreadNode<T>* r) {
  r->right_child_ = s->right_child_;
  r->right_tag_ = s->right_tag_;

  r->left_child_ = s;
  r->left_tag_ = IS_THREAD_NODE;

  s->right_child_ = r;
  s->right_tag_ = IS_CHILD;

  if (r->right_tag_ == IS_CHILD) {
    ThreadNode<T> *temp;
    temp = First(r->right_child_);
    temp->left_child_ = r;
  }
}


template<class T>
void ThreadTree<T>::InsertLeft(ThreadNode<T> *s, ThreadNode<T> *l) {
  l->left_child_ = s->left_child_;
  l->left_tag_ = s->left_tag_;
  l->right_child_ = s;
  l->right_tag_ = 1;

  s->left_child_ = l;
  s->left_tag_ = 0;

  if (l->right_tag_ == 0) {
    ThreadNode<T> *temp;

    temp = Last(l->left_child_);
    temp->right_child_ = l;
  }
}


template<class T>
void ThreadTree<T>::DeleteRight(ThreadNode<T> *s) {
  ThreadNode<T> *r = s->right_child_;

  if (r->right_tag_ == 1) {
    if (r->left_tag_ == 1) {
      /* r has neither right child nor left child */
      s->right_child_ = r->right_child_;
      s->right_tag_ = 1;
    } else {
      /* r has no right child but has left child */
      ThreadNode<T> *la = Last(r->left_child_);
      la->right_child_ = r->right_child_;
      s->right_child_ = r->left_child_;
    }
  } else {
    if (r->left_tag_ == 1) {
      /* r has right child but has no left child */
      ThreadNode<T> *fr = First(r->right_child_);
      fr->left_child_ = s;
      s->right_child_ = r->right_child_;
    } else {
      /* r has both right child and left child */
      ThreadNode<T> *fr = First(r->right_child_);
      ThreadNode<T> *la = Last(r->left_child_);

      la->right_child_ = r->left_child_;
      la->right_tag_ = r->right_tag_;

      s->right_child_ = r->left_child_;
      fr->left_child_ = la;

    }
  }

  delete r;
}


template<class T>
void ThreadTree<T>::DeleteLeft(ThreadNode<T> *s) {
  ThreadNode<T> *l = s->left_child_;

  if (l->right_tag_ == 1) {
    if (l->left_tag_ == 1) {
      /* l has neither right child nor left child */
      s->left_child_ = l->left_child_;
      s->left_tag_ = 1;
    } else {
      /* l has no right child but has left child */
      ThreadNode<T> *la = Last(l->left_child_);
      la->right_child_ = s;
      s->left_child_ = l->left_child_;
    }
  } else {
    if (l->left_tag_ == 1) {
      /* l has right child but has no left child */
      ThreadNode<T> *fr = First(l->right_child_);
      fr->left_child_ = l->left_child_;
      s->left_child_ = l->right_child_;
    } else {
      /* l has both right child and left child */
      ThreadNode<T> *fr = First(l->right_child_);
      ThreadNode<T> *la = Last(l->left_child_);

      la->right_child_ = l->right_child_;
      la->right_tag_ = l->right_tag_;

      s->left_child_ = l->left_child_;
      fr->left_child_ = la;
    }
  }

  delete l;
}


template <class T>
ThreadNode<T> *ThreadTree<T>::PostOrderNext(ThreadNode<T> *current) {
  if (current->right_tag_ == 1) {
    return current->right_child_;
  }

  ThreadNode<T> *parent = Parent_(current);
  if (parent == NULL) {
    return NULL;
  }

  if (parent->right_tag_ == 1 || parent->right_child_ == current) {
    return parent;
  }

  return First(parent->right_child_);
}


template <class T>
ThreadNode<T> *ThreadTree<T>::PostOrderPrior(ThreadNode<T> *current) {
  if (current->left_tag_ == 1) {
    return current->left_child_;
  }

  if (current->right_tag_ == 1) {
    return current->left_child_;
  }

  return current->right_child_;
}


template<class T>
void ThreadTree<T>::CyberDashShow() {
  cout<<endl
      <<"*************************************** CyberDash ***************************************"<<endl<<endl
      <<"抖音号\"CyberDash计算机考研\", id: cyberdash_yuan"<<endl<<endl
      <<"CyberDash成员:"<<endl
      <<"元哥(cyberdash@163.com), "<<"北京邮电大学(通信工程本科)/北京邮电大学(信息与通信系统研究生)"<<endl
      <<"磊哥(alei_go@163.com), "<<"山东理工大学(数学本科)/北京邮电大学(计算机研究生)"<<endl<<endl
      <<"数据结构开源代码(C++清华大学殷人昆)魔改升级版本: https://gitee.com/cyberdash/data_-structure-cpp"<<endl
      <<endl<<"*************************************** CyberDash ***************************************"<<endl<<endl;
}

#endif //CYBER_DASH_THREAD_TREE_H
