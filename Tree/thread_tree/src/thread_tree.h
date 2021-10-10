/*!
 * @file thread_tree.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 线索树
 * @version 0.2.1
 * @date 2021-05-13
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#ifndef CYBER_DASH_THREAD_TREE_H
#define CYBER_DASH_THREAD_TREE_H


#include <iostream>
#include <cstdlib>


using namespace std;


const int IS_CHILD = 0;
const int IS_THREAD_NODE = 1;


/*!
 * @brief 线索树结点模板结构体
 * @tparam T 类型模板参数
 */
template <class T>
struct ThreadNode {

  int left_tag;
  int right_tag;

  ThreadNode<T>* left_child; //!< 左孩子
  ThreadNode<T>* right_child; //!< 右孩子
  T data; //!< 数据项

  ThreadNode(const T& data):
      data(data),
      left_child(NULL), right_child(NULL),
      left_tag(IS_CHILD), right_tag(IS_CHILD) {}
};


/*!
 * @brief 线索树模板类
 * @tparam T 类型模板参数
 */
template <class T>
class ThreadTree {
public:
  ThreadTree(): root_(NULL) {}

  /*!
   * @brief 获取根节点指针
   * @return 根结点指针
   */
  ThreadNode<T>* Root() { return root_; }

  /*!
   * @brief 插入结点
   * @param data 数据
   * @return 是否插入成功
   */
  bool Insert(const T& data) { return Insert_(root_, data);}

  // 我们是CyberDash
  void CyberDashShow();

  /* 中序线索树 */

  // 创建中序线索
  void CreateInOrderThread();
  // 中序线索第一个线索结点
  ThreadNode<T>* First(ThreadNode<T>* node);
  // 求(node为根的)当前二叉树的最后一个线索节点的节点指针
  ThreadNode<T>* Last(ThreadNode<T>* node);
  // 中序线索下一个线索结点
  ThreadNode<T>* Next(ThreadNode<T>* node);
  // 中序线索前一个线索结点
  ThreadNode<T>* Prior(ThreadNode<T>* node);
  // 中序线索父结点
  ThreadNode<T>* Parent(ThreadNode<T>* node_ptr) { return Parent_(node_ptr); }
  // 中序线索二叉树中序遍历
  void InOrderTraverse(void (*visit)(ThreadNode<T>* node_ptr));
  // 中序线索二叉树前序遍历
  void PreOrderTraverse(void (*visit)(ThreadNode<T>* node_ptr));
  // 中序线索二叉树后序遍历
  void PostOrderTraverse(void (*visit)(ThreadNode<T> *p));
  // 中序线索二叉子树, 找到后续遍历第一个结点(书中未实现)
  ThreadNode<T>* FindFirstNodeForPostOrderTraverse(ThreadNode<T>* node_ptr);
  //
  void InsertRight(ThreadNode<T>* s, ThreadNode<T> *r);
  //
  void InsertLeft(ThreadNode<T>* s, ThreadNode<T> *r);
  //
  void DeleteRight(ThreadNode<T>* s);
  //
  void DeleteLeft(ThreadNode<T>* s);

  /* 前序线索树 */

  // 创建前序线索
  void CreatePreOrderThread();
  // 前序线索二叉树下一个结点
  ThreadNode<T>* PreOrderNext(ThreadNode<T>* node_ptr);
  // 前序线索二叉树前一个结点
  ThreadNode<T>* PreOrderPrior(ThreadNode<T> *current);

  /* 后序线索树 */
  // 创建后序线索
  void CreatePostThread();
  // 后序线索二叉树下一个结点
  ThreadNode<T>* PostOrderNext(ThreadNode<T> *current);
  // 后序线索二叉树前一个结点
  ThreadNode<T>* PostOrderPrior(ThreadNode<T> *current);

protected:
  ThreadNode<T>* root_;
  // 子树创建中序线索
  void CreateSubInOrderThread_(ThreadNode<T>*& node, ThreadNode<T>*& pre_node);
  // 子树创建前序线索
  void CreateSubPreOrderThread_(ThreadNode<T>*& node, ThreadNode<T>*& pre_node);
  // 子树创建后序线索
  void CreatePostOrderThread_(ThreadNode<T>*& node, ThreadNode<T>*& pre_node);
  // 父节点指针
  ThreadNode<T>* Parent_(ThreadNode<T>* node);
  // 子树插入
  bool Insert_(ThreadNode<T>*& node, const T& data);
};


/*!
 * @brief 求(node_ptr为根的)当前中序线索树的第一个节点指针
 * @tparam T 树节点数据类型
 * @param node 当前选中的节点
 * @return 结点指针
 * @note
 * 左子树遍历至最深的节点
 */
template <class T>
ThreadNode<T>* ThreadTree<T>::First(ThreadNode<T>* node) {
  ThreadNode<T>* cur = node;

  while (cur != NULL &&
         cur->left_child != NULL &&
         cur->left_tag == IS_CHILD)
  {
    cur = cur->left_child;
  }

  return cur;
}


/*!
 * @brief 中序线索树的下一节点
 * @tparam T 类型模板参数
 * @param node 当前选中节点
 * @return Next节点指针
 * @note
 * 最右子节点的First()
 */
template <class T>
ThreadNode<T>* ThreadTree<T>::Next(ThreadNode<T>* node) {
  if (node == NULL) {
    exit(1); // error handler
  }

  ThreadNode<T>* right_child = node->right_child;

  if (right_child != NULL && node->right_tag == IS_CHILD) {
    return First(right_child);
  }

  return right_child;
}


/*!
 * @brief 求(node_ptr为根的)当前二叉树的最后一个线索节点的节点指针
 * @tparam T 类型模板参数
 * @param node 当前节点
 * @return 最后一个线索节点的指针
 * @note
 * 最右子节点(可能非叶子)
 */
template <class T>
ThreadNode<T>* ThreadTree<T>::Last(ThreadNode<T> *node) {
  ThreadNode<T>* cur = node;

  while (cur != NULL &&
         cur->right_child != NULL &&
         cur->right_tag == IS_CHILD)
  {
    cur = cur->right_child;
  }

  return cur;
}


/*!
 * @brief 中序线索前一个线索结点
 * @tparam T 类型模板参数
 * @param node
 * @return
 */
template <class T>
ThreadNode<T>* ThreadTree<T>::Prior(ThreadNode<T>* node) {
  ThreadNode<T>* left_child = node->left_child;

  if (node->left_tag == IS_CHILD) {
    return Last(left_child);
  }

  return left_child;
}


/*!
 * @brief 中序线索二叉树中序遍历
 * @tparam T 类型模板参数
 * @param visit 遍历函数
 */
template <class T>
void ThreadTree<T>::InOrderTraverse(void (*visit)(ThreadNode<T>* node)) {
  for (ThreadNode<T>* cur = First(root_); cur != NULL; cur = Next(cur)) {
    visit(cur);
  }
}


/*!
 * @brief 创建中序线索
 * @tparam T 树节点数据类型
 * @note
 * 调用CreateInOrderSubThread_
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
    pre_node_ptr->right_child = NULL;
    pre_node_ptr->right_tag = IS_THREAD_NODE;
  }
}


/*!
 * @brief 子树创建中序线索(递归)
 * @tparam T 树节点数据类型
 * @param node 当前节点
 * @param pre_node 当前节点的前驱节点
 * @note
 * 递归终止条件:
 *    当前节点为null
 * 分治递归:
 *    左子树执行
 *    调整线索
 *    右子树执行
 */
template <class T>
void ThreadTree<T>::CreateSubInOrderThread_(ThreadNode<T>*& node, ThreadNode<T>*& pre_node) {

  if (node == NULL) {
    return;
  }

  // 左子树分治
  CreateSubInOrderThread_(node->left_child, pre_node);

  // (利用left_child_)
  // 如果left_child_指针为NULL,
  // 则将node_ptr->left_child_指向pre_node_ptr, 加入线索树
  if (node->left_child == NULL) {
    node->left_child = pre_node;
    node->left_tag = IS_THREAD_NODE;
  }

  // (利用right_child_)
  // 如果前一节点pre_node_ptr不为NULL, 并且它的right_child_不为NULL,
  // 则前一节点的right_child_指向node_ptr, 加入线索树
  if (pre_node != NULL && pre_node->right_child == NULL) {
    pre_node->right_child = node;
    pre_node->right_tag = IS_THREAD_NODE;
  }

  pre_node = node; // pre_node_ptr节点后移

  // 右子树分治
  CreateSubInOrderThread_(node->right_child, pre_node);
}


template <class T>
void ThreadTree<T>::CreatePreOrderThread() {
  ThreadNode<T> *node_ptr = NULL;

  if (root_ != NULL) {
    CreateSubPreOrderThread_(root_, node_ptr);
    node_ptr->right_child = NULL;
    node_ptr->right_tag = 1;
  }
}


/**
 *
 * @tparam T
 * @param node
 * @param pre_node
 */
template <class T>
void ThreadTree<T>::CreateSubPreOrderThread_(ThreadNode<T>*& node, ThreadNode<T>*& pre_node) {

  if (node == NULL) {
    return;
  }

  // (利用left_child_)
  // 如果left_child_指针为NULL,
  // 则将node_ptr->left_child_指向pre_node_ptr, 加入线索树
  if (node->left_child == NULL) {
    node->left_child = pre_node;
    node->left_tag = IS_THREAD_NODE;
  }

  // (利用right_child_)
  // 如果前一节点pre_node_ptr不为NULL, 并且它的right_child_不为NULL,
  // 则前一节点的right_child_指向node_ptr, 加入线索树
  if (pre_node != NULL && pre_node->right_child == NULL) {
    pre_node->right_child = node;
    pre_node->right_tag = IS_THREAD_NODE;
  }

  pre_node = node; // pre_node_ptr节点后移

  // 左子树分治
  // CreateSubPreOrderThread_(node_ptr->left_child_, pre_node_ptr); // 左子树遍历
  if (node->left_tag == IS_CHILD) {
    CreateSubPreOrderThread_(node->left_child, pre_node); // 左子树遍历
  }

  // 右子树分治
  CreateSubPreOrderThread_(node->right_child, pre_node); // 右子树遍历
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

  pre_node_ptr->right_child = NULL;
  pre_node_ptr->right_tag = 1;
}


/**
 * @brief
 * @tparam T
 * @param node
 * @param pre_node
 */
template <class T>
void ThreadTree<T>::CreatePostOrderThread_(ThreadNode<T>*& node, ThreadNode<T>*& pre_node) {
  if (node == NULL) {
    return;
  }

  CreatePostOrderThread_(node->left_child, pre_node);

  CreatePostOrderThread_(node->right_child, pre_node);

  if (node->left_child == NULL) {
    node->left_child = pre_node;
    node->left_tag = IS_THREAD_NODE;
  }

  if (pre_node != NULL && pre_node->right_child == NULL) {
    pre_node->right_child = node;
    pre_node->right_tag = IS_THREAD_NODE;
  }

  pre_node = node;
}


template <class T>
ThreadNode<T> *ThreadTree<T>::PreOrderNext(ThreadNode<T>* node_ptr) {

  if (node_ptr->left_tag != IS_THREAD_NODE) {
    return node_ptr->left_child;
  }

  return node_ptr->right_child;
}


template <class T>
ThreadNode<T> *ThreadTree<T>::PreOrderPrior(ThreadNode<T> *current) {

  if (current->left_tag == IS_THREAD_NODE) {
    return current->left_child;
  }

  ThreadNode<T> *parent = Parent_(current);

  if (parent == NULL) {
    return NULL;
  }

  if (parent->left_tag == 1 || parent->left_child == current) {
    return parent;
  }

  return Last(parent->left_child);
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

    if (cur->left_tag == IS_CHILD) { // 若有左子女, 则为前序后继
      cur = cur->left_child;
    } else if (cur->right_tag == IS_CHILD) { // 否则若有右子女, 则为前序后继
      cur = cur->right_child;
    } else { // 对于叶子结点, 沿着中序后继线索, 走到一个有右子女结点的结点, 这个右子女结点就是当前结点的前序后继结点
      while (cur != NULL && cur->right_tag == IS_THREAD_NODE) {
        cur = cur->right_child;
      }

      if (cur != NULL) {
        cur = cur->right_child;
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
    if (cur_parent->right_child == cur ||  // 当前结点是父节点的右孩子
        cur_parent->right_tag == IS_THREAD_NODE) // 当前结点是父节点左孩子, 并且父节点没有右孩子
    {
      cur = cur_parent;
    } else {
      cur = FindFirstNodeForPostOrderTraverse(cur_parent->right_child);
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

  while (cur->left_tag == IS_CHILD || cur->right_tag == IS_CHILD) {
    if (cur->left_tag == IS_CHILD) {
      cur = cur->left_child;
    } else if (cur->right_tag == IS_CHILD) {
      cur = cur->right_child;
    }
  }

  return cur;
}


/*!
 * @brief 中序线索二叉树求父节点
 * @tparam T 类型模板参数
 * @param node 结点指针
 * @return 父结点知真假
 * @note
 * 两条路径:
 *   1: 从当前结点走到树上层的一个中序前驱(不一定是直接前驱), 然后向右下找父节点
 *   2: 从当前结点走到书上层的一个中序后继(不一定是直接后继), 然后向左下找父节点
 */
template <class T>
ThreadNode<T>* ThreadTree<T>::Parent_(ThreadNode<T>* node) {

  if (node == root_) {
    return NULL;
  }

  /* 尝试路径1 */
  // 遍历至最左子节点
  ThreadNode<T>* left_side_child = node;
  while (left_side_child->left_tag == IS_CHILD) {
    left_side_child = left_side_child->left_child;
  }

  if (left_side_child->left_child != NULL) { // 如果等于NULL, 则寻找树上层的中序前驱失败, 路径1失败
    ThreadNode<T>* upper_level_pre_node = left_side_child->left_child; // 树上层的中序前驱

    // 向右下找父节点
    while (upper_level_pre_node != NULL &&
           upper_level_pre_node->left_child != node &&
           upper_level_pre_node->right_child != node) {
      upper_level_pre_node = upper_level_pre_node->right_child;
    }

    if (upper_level_pre_node != NULL) { // 如果不等于NULL, 则找到父节点, 否则路径1失败
      return upper_level_pre_node;
    }
  }

  /* 尝试路径2 */
  // 遍历至最右子节点
  ThreadNode<T>* right_side_child = node;
  while (right_side_child->right_tag == IS_CHILD) {
    right_side_child = right_side_child->right_child;
  }

  ThreadNode<T>* upper_level_post_node = right_side_child->right_child; // 树上层的中序后继

  // 向左下找父节点
  while (upper_level_post_node != NULL &&
         upper_level_post_node->left_child != node &&
         upper_level_post_node->right_child != node) {
    upper_level_post_node = upper_level_post_node->left_child;
  }

  return upper_level_post_node;
}


/*!
 * @brief 二叉树插入(建立线索之前)
 * @tparam T 类型模板参数
 * @param node 被插入的子树的根结点
 * @param data 数据项
 * @return 是否插入成功
 */
template<class T>
bool ThreadTree<T>::Insert_(ThreadNode<T>*& node, const T& data) {

  if (node == NULL) {
    node = new ThreadNode<T>(data);
    /* new error handler*/
    return true;
  }

  int left_sub_tree_height = Height(node->left_child);
  int right_sub_tree_height = Height(node->right_child);

  if (left_sub_tree_height > right_sub_tree_height) {
    return Insert_(node->right_child, data);
  } else {
    return Insert_(node->left_child, data);
  }
}


/*!
 * @brief 二叉子树的深度
 * @tparam T 类型模板参数
 * @param node 二叉子树的根
 * @return 深度
 */
template<class T>
int Height(ThreadNode<T>* node) {
  if (node == NULL) {
    return 0;
  }

  int left_sub_tree_height = Height(node->left_child);
  int right_sub_tree_height = Height(node->right_child);

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
  r->right_child = s->right_child;
  r->right_tag = s->right_tag;

  r->left_child = s;
  r->left_tag = IS_THREAD_NODE;

  s->right_child = r;
  s->right_tag = IS_CHILD;

  if (r->right_tag == IS_CHILD) {
    ThreadNode<T> *temp;
    temp = First(r->right_child);
    temp->left_child = r;
  }
}


template<class T>
void ThreadTree<T>::InsertLeft(ThreadNode<T> *s, ThreadNode<T> *l) {
  l->left_child = s->left_child;
  l->left_tag = s->left_tag;
  l->right_child = s;
  l->right_tag = 1;

  s->left_child = l;
  s->left_tag = 0;

  if (l->right_tag == 0) {
    ThreadNode<T> *temp;

    temp = Last(l->left_child);
    temp->right_child = l;
  }
}


template<class T>
void ThreadTree<T>::DeleteRight(ThreadNode<T> *s) {
  ThreadNode<T> *r = s->right_child;

  if (r->right_tag == 1) {
    if (r->left_tag == 1) {
      /* r has neither right child nor left child */
      s->right_child = r->right_child;
      s->right_tag = 1;
    } else {
      /* r has no right child but has left child */
      ThreadNode<T> *la = Last(r->left_child);
      la->right_child = r->right_child;
      s->right_child = r->left_child;
    }
  } else {
    if (r->left_tag == 1) {
      /* r has right child but has no left child */
      ThreadNode<T> *fr = First(r->right_child);
      fr->left_child = s;
      s->right_child = r->right_child;
    } else {
      /* r has both right child and left child */
      ThreadNode<T> *fr = First(r->right_child);
      ThreadNode<T> *la = Last(r->left_child);

      la->right_child = r->left_child;
      la->right_tag = r->right_tag;

      s->right_child = r->left_child;
      fr->left_child = la;
    }
  }

  delete r;
}


template<class T>
void ThreadTree<T>::DeleteLeft(ThreadNode<T> *s) {
  ThreadNode<T> *l = s->left_child;

  if (l->right_tag == 1) {
    if (l->left_tag == 1) {
      /* l has neither right child nor left child */
      s->left_child = l->left_child;
      s->left_tag = 1;
    } else {
      /* l has no right child but has left child */
      ThreadNode<T> *la = Last(l->left_child);
      la->right_child = s;
      s->left_child = l->left_child;
    }
  } else {
    if (l->left_tag == 1) {
      /* l has right child but has no left child */
      ThreadNode<T> *fr = First(l->right_child);
      fr->left_child = l->left_child;
      s->left_child = l->right_child;
    } else {
      /* l has both right child and left child */
      ThreadNode<T> *fr = First(l->right_child);
      ThreadNode<T> *la = Last(l->left_child);

      la->right_child = l->right_child;
      la->right_tag = l->right_tag;

      s->left_child = l->left_child;
      fr->left_child = la;
    }
  }

  delete l;
}


template <class T>
ThreadNode<T> *ThreadTree<T>::PostOrderNext(ThreadNode<T> *current) {
  if (current->right_tag == 1) {
    return current->right_child;
  }

  ThreadNode<T>* parent = Parent_(current);
  if (parent == NULL) {
    return NULL;
  }

  if (parent->right_tag == 1 || parent->right_child == current) {
    return parent;
  }

  return First(parent->right_child);
}


template <class T>
ThreadNode<T> *ThreadTree<T>::PostOrderPrior(ThreadNode<T> *current) {
  if (current->left_tag == 1) {
    return current->left_child;
  }

  if (current->right_tag == 1) {
    return current->left_child;
  }

  return current->right_child;
}


template<class T>
void ThreadTree<T>::CyberDashShow() {
  cout<<endl
      <<"*************************************** CyberDash ***************************************"<<endl<<endl
      <<"抖音号\"CyberDash计算机考研\", id: cyberdash_yuan"<<endl<<endl
      <<"CyberDash成员:"<<endl
      <<"元哥(cyberdash@163.com), "<<"北京邮电大学(通信工程本科)/北京邮电大学(信息与通信系统研究生)"<<endl
      <<"磊哥(alei_go@163.com), "<<"山东理工大学(数学本科)/北京邮电大学(计算机研究生)"<<endl<<endl
      <<"L_Dash(lyu2586@163.com), "<<"北京邮电大学(计算机在读研究生)"<<endl<<endl
      <<"数据结构开源代码(C++清华大学殷人昆)魔改升级版本: https://gitee.com/cyberdash/data_-structure-cpp"<<endl
      <<endl<<"*************************************** CyberDash ***************************************"<<endl<<endl;
}


#endif //CYBER_DASH_THREAD_TREE_H
