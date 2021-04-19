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
  ThreadTree(): root_(NULL) {}
  void CreateInOrderThread(void);
  void CreatePreOrderThread(void);
  void CreatePostThread(void);
  ThreadNode<T> *GetRoot(void) {return root_;}
  ThreadNode<T> *First(ThreadNode<T> *current);
  ThreadNode<T> *Last(ThreadNode<T> *node_ptr);
  ThreadNode<T> *Next(ThreadNode<T> *node_ptr);
  ThreadNode<T> *Prior(ThreadNode<T> *current);
  ThreadNode<T> *PreOrderNext(ThreadNode<T> *current);
  ThreadNode<T> *PreOrderPrior(ThreadNode<T> *current);
  ThreadNode<T> *PostOrderNext(ThreadNode<T> *current);
  ThreadNode<T> *PostOrderPrior(ThreadNode<T> *current);
  void InOrderTraverse(void (*visit)(ThreadNode<T>* node_ptr));
  void PreOrderTraverse(void (*visit)(ThreadNode<T>* node_ptr));
  void PostOrder(void (*visit)(ThreadNode<T> *p));

  bool Insert(T& item) { return Insert(root_, item);}
  void InsertRight(ThreadNode<T> *s, ThreadNode<T> *r);
  void InsertLeft(ThreadNode<T> *s, ThreadNode<T> *r);
  void DeleteRight(ThreadNode<T> *s);
  void DeleteLeft(ThreadNode<T> *s);

  void CyberDashShow();

protected:
  ThreadNode<T> *root_;
  void CreateInOrderSubThread_(ThreadNode<T>* node_ptr, ThreadNode<T>*& pre_node_ptr);
  void CreatePreOrderSubThread_(ThreadNode<T>* node_ptr, ThreadNode<T>*& pre_node_ptr);
  void createPostOrderThread_(ThreadNode<T>* node_ptr, ThreadNode<T>*& pre_node_ptr);
  ThreadNode<T>* Parent(ThreadNode<T>* node_ptr);

  bool Insert(ThreadNode<T>*& subTree, T& x);
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

  while (cur_node_ptr->left_tag_ == IS_CHILD) {
    cur_node_ptr = cur_node_ptr->left_child_;
  }

  return cur_node_ptr;
}


/**
 * @brief 线索树下一节点
 * 原书未做空指针处理, 已做补充
 *
 * @tparam T 树节点数据类型
 * @param node_ptr 当前选中节点
 * @return
 */
template <class T>
ThreadNode<T>* ThreadTree<T>::Next(ThreadNode<T> *node_ptr) {
  if (node_ptr == NULL) {
    exit(1); // error handler
  }

  ThreadNode<T>* right_child_ptr = node_ptr->right_child_;

  if (node_ptr->right_tag_ == IS_CHILD) {
    return First(right_child_ptr);
  }

  return right_child_ptr;
}


/**
 * @brief 求(node_ptr为根的)当前中序线索树的最后一个节点指针
 * 右子树遍历至最右的节点
 * @tparam T 树节点数据类型
 * @param node_ptr 当前节点
 * @return 最后一个线索节点的指针
 */
template <class T>
ThreadNode<T>* ThreadTree<T>::Last(ThreadNode<T> *node_ptr) {
  ThreadNode<T>* cur_node_ptr = node_ptr;

  while (cur_node_ptr->right_tag_ == 0) {
    cur_node_ptr = cur_node_ptr->right_child_;
  }

  return cur_node_ptr;
}


/**
 * @brief
 * @tparam T
 * @param current
 * @return
 */
template <class T>
ThreadNode<T>* ThreadTree<T>::Prior(ThreadNode<T> *current) {
  ThreadNode<T> *p = current->left_child_;

  if (current->left_tag_ == 0) {
    return Last(p);
  }

  return p;
}


/**
 * @brief
 * @tparam T
 * @param visit
 */
template <class T>
void ThreadTree<T>::InOrderTraverse(void (*visit)(ThreadNode<T> *p)) {
  ThreadNode<T> *p;

  for (p = First(root_); p != NULL; p = Next(p)) {
    visit(p);
  }
}


/**
 * @brief 调用CreateInOrderSubThread_创建线索树
 * @tparam T 树节点数据类型
 */
template <class T>
void ThreadTree<T>::CreateInOrderThread() {
  if (root_ == NULL) {
    return;
  }

  ThreadNode<T>* pre_node_ptr = NULL;

  CreateInOrderSubThread_(root_, pre_node_ptr);

  if (pre_node_ptr != NULL) {
    pre_node_ptr->right_child_ = NULL;
    pre_node_ptr->right_tag_ = 1;
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
void ThreadTree<T>::CreateInOrderSubThread_(ThreadNode<T>* node_ptr, ThreadNode<T>*& pre_node_ptr) {
  if (node_ptr == NULL) {
    return;
  }

  CreateInOrderSubThread_(node_ptr->left_child_, pre_node_ptr);

  // 如果left_child_指针为NULL, 则将node_ptr->left_child_指向pre_node_ptr, 加入线索树
  if (node_ptr->left_child_ == NULL) {
    node_ptr->left_child_ = pre_node_ptr;
    node_ptr->left_tag_ = IS_THREAD_NODE;
  }

  // 如果前一节点pre_node_ptr不为NULL, 并且它的right_child_不为NULL, 则前一节点的right_child_指向node_ptr
  if (pre_node_ptr != NULL && pre_node_ptr->right_child_ == NULL) {
    pre_node_ptr->right_child_ = node_ptr;
    pre_node_ptr->right_tag_ = IS_THREAD_NODE;
  }

  pre_node_ptr = node_ptr;

  CreateInOrderSubThread_(node_ptr->right_child_, pre_node_ptr);
}



template <class T>
void ThreadTree<T>::CreatePreOrderThread() {
  ThreadNode<T> *pre = NULL;

  if (root_ != NULL) {
    CreatePreOrderSubThread_(root_, pre);
    pre->right_child_ = NULL;
    pre->right_tag_ = 1;
  }
}


/**
 *
 * @tparam T
 * @param node_ptr
 * @param pre_node_ptr
 */
template <class T>
void ThreadTree<T>::CreatePreOrderSubThread_(ThreadNode<T>* node_ptr, ThreadNode<T>*& pre_node_ptr) {
  if (node_ptr == NULL) {
    return;
  }

  if (node_ptr->left_child_ == NULL) {
    node_ptr->left_child_ = pre_node_ptr;
    node_ptr->left_tag_ = IS_THREAD_NODE;
  }

  if (pre_node_ptr != NULL && pre_node_ptr->right_child_ == NULL) {
    pre_node_ptr->right_child_ = node_ptr;
    pre_node_ptr->right_tag_ = IS_THREAD_NODE;
  }

  pre_node_ptr = node_ptr;

  CreatePreOrderSubThread_(node_ptr->left_child_, pre_node_ptr);

  CreatePreOrderSubThread_(node_ptr->right_child_, pre_node_ptr);
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

  createPostOrderThread_(root_, pre_node_ptr);

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
void ThreadTree<T>::createPostOrderThread_(ThreadNode<T>* node_ptr, ThreadNode<T>*& pre_node_ptr) {
  if (node_ptr == NULL) {
    return;
  }

  createPostOrderThread_(node_ptr->left_child_, pre_node_ptr);

  createPostOrderThread_(node_ptr->right_child_, pre_node_ptr);

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


/**
 * @brief
 * @tparam T
 * @param visit
 */
template <class T>
void ThreadTree<T>::PreOrderTraverse(void (*visit)(ThreadNode<T>* node_ptr)) {
  ThreadNode<T> *cur_node_ptr = root_;

  while (cur_node_ptr != NULL) {
    visit(cur_node_ptr);

    if (cur_node_ptr->left_tag_ == IS_CHILD) {
      cur_node_ptr = cur_node_ptr->left_child_;
    } else if (cur_node_ptr->right_tag_ == IS_CHILD) {
      cur_node_ptr = cur_node_ptr->right_child_;
    } else {
      while (cur_node_ptr != NULL && cur_node_ptr->right_tag_ == IS_THREAD_NODE) {
        cur_node_ptr = cur_node_ptr->right_child_;
      }

      if (cur_node_ptr != NULL) {
        cur_node_ptr = cur_node_ptr->right_child_;
      }
    }
  }
}


/**
 * @brief
 * @tparam T
 * @param visit
 */
template <class T>
void ThreadTree<T>::PostOrder(void (*visit)(ThreadNode<T> *p)) {
  ThreadNode<T> *t = root_;

  while (t->left_tag_ == 0 || t->right_tag_ == 0) {
    if (t->left_tag_ == 0) {
      t = t->left_child_;
    } else if (t->right_tag_ == 0) {
      t = t->right_child_;
    }
  }

  visit(t);

  ThreadNode<T> *p;

  while ((p = Parent(t)) != NULL) {
    if (p->right_child_ == t || p->right_tag_ == 1) {
      t = p;
    } else {
      t = p->right_child_;
      while (t->left_tag_ == 0 || t->right_tag_ == 0) {
        if (t->left_tag_ == 0) {
          t = t->left_child_;
        } else if (t->right_tag_ == 0) {
          t = t->right_child_;
        }
      }
    }

    visit(t);
  }
}

template <class T>
ThreadNode<T> *ThreadTree<T>::Parent(ThreadNode<T> *t) {
  ThreadNode<T> *p;

  if (t == root_) {
    return NULL;
  }

  for (p = t; p->left_tag_ == 0; p = p->left_child_);

  if (p->left_child_ != NULL) {
    for (p = p->left_child_;
         p != NULL && p->left_child_ != t && p->right_child_ != t;
         p = p->right_child_);
  }

  if (p == NULL || p->left_child_ == NULL) {
    for (p = t; p->right_tag_ == 0; p = p->right_child_);
    for (p = p->right_child_;
         p != NULL && p->left_child_ != t && p->right_child_ != t;
         p = p->left_child_);

  }

  return p;
}

template<class T>
bool ThreadTree<T>::Insert(ThreadNode<T> *& subTree, T& x) {
  if (subTree == NULL) {
    subTree = new ThreadNode<T>(x);
    if (subTree == NULL) {
      cerr << "存储分配错误!" << endl;
      exit(1);
    }
    return true;
  } else {
    int i = Height(subTree->left_child_);
    int j = Height(subTree->right_child_);

    return (i > j) ? Insert(subTree->right_child_, x) : Insert(subTree->left_child_, x);
  }
}


/**
 *
 * @tparam T
 * @param node_ptr
 * @return
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
void ThreadTree<T>::InsertRight(ThreadNode<T> *s, ThreadNode<T> *r) {
  r->right_child_ = s->right_child_;
  r->right_tag_ = s->right_tag_;

  r->left_child_ = s;
  r->left_tag_ = 1;

  s->right_child_ = r;
  s->right_tag_ = 0;

  if (r->right_tag_ == 0) {
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
ThreadNode<T> *ThreadTree<T>::PreOrderNext(ThreadNode<T> *current) {
  if (current->left_tag_ != 1) {
    return current->left_child_;
  }

  return current->right_child_;
}

template <class T>
ThreadNode<T> *ThreadTree<T>::PreOrderPrior(ThreadNode<T> *current) {
  if (current->left_tag_ == 1) {
    return current->left_child_;
  }

  ThreadNode<T> *parent = Parent(current);

  if (parent == NULL) {
    return NULL;
  }

  if (parent->left_tag_ == 1 || parent->left_child_ == current) {
    return parent;
  }

  return Last(parent->left_child_);
}

template <class T>
ThreadNode<T> *ThreadTree<T>::PostOrderNext(ThreadNode<T> *current) {
  if (current->right_tag_ == 1) {
    return current->right_child_;
  }

  ThreadNode<T> *parent = Parent(current);
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
