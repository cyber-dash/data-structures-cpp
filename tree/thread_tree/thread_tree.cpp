//
// Created by alei_go@163.com(抖音: cyberdash_yuan) on 2020/11/1.
//

#include <iostream>
#include <stdlib.h>
#include "thread_node.h"
#include "thread_tree.h"


using namespace std;


template <class T>
ThreadNode<T> *ThreadTree<T>::First(ThreadNode<T> *current) {
  ThreadNode<T> *p = current;

  while (p->ltag == 0) {
    p = p->leftChild;
  }

  return p;
}

template <class T>
ThreadNode<T> *ThreadTree<T>::Next(ThreadNode<T> *current) {
  ThreadNode<T> *p = current->rightChild;

  if (current->rtag == 0) {
    return First(p);
  }

  return p;
}

template <class T>
ThreadNode<T> *ThreadTree<T>::Last(ThreadNode<T> *current) {
  ThreadNode<T> *p = current;

  while (p->rtag == 0) {
    p = p->rightChild;
  }

  return p;
}

template <class T>
ThreadNode<T> *ThreadTree<T>::Prior(ThreadNode<T> *current) {
  ThreadNode<T> *p = current->leftChild;

  if (current->ltag == 0) {
    return Last(p);
  }

  return p;
}

template <class T>
void ThreadTree<T>::InOrder(void (*visit)(ThreadNode<T> *p)) {
  ThreadNode<T> *p;

  for (p = First(root); p != NULL; p = Next(p)) {
    visit(p);
  }
}

template <class T>
void ThreadTree<T>::createInThread(void) {
  ThreadNode<T> *pre = NULL;
  
  if (root != NULL) {
    createInThread(root, pre);
    pre->rightChild = NULL;
    pre->rtag = 1;
  }
}

template <class T>
void ThreadTree<T>::createInThread(ThreadNode<T> *current, ThreadNode<T> *& pre) {
  if (current == NULL) {
    return;
  }

  createInThread(current->leftChild, pre);

  if (current->leftChild == NULL) {
    current->leftChild = pre;
    current->ltag = 1;
  }

  if (pre != NULL && pre->rightChild == NULL) {
    pre->rightChild = current;
    pre->rtag = 1;
  }

  pre = current;

  createInThread(current->rightChild, pre);
}

template <class T>
void ThreadTree<T>::createPreThread(void) {
  ThreadNode<T> *pre = NULL;
  
  if (root != NULL) {
    createPreThread(root, pre);
    pre->rightChild = NULL;
    pre->rtag = 1;
  }
}

template <class T>
void ThreadTree<T>::createPreThread(ThreadNode<T> *current, ThreadNode<T> *& pre) {
  if (current == NULL) {
    return;
  }

  if (current->leftChild == NULL) {
    current->leftChild = pre;
    current->ltag = 1;
  }

  if (pre != NULL && pre->rightChild == NULL) {
    pre->rightChild = current;
    pre->rtag = 1;
  }

  pre = current;

  createPreThread(current->leftChild, pre);

  createPreThread(current->rightChild, pre);
}

template <class T>
void ThreadTree<T>::createPostThread(void) {
  ThreadNode<T> *pre = NULL;
  
  if (root != NULL) {
    createPostThread(root, pre);
    pre->rightChild = NULL;
    pre->rtag = 1;
  }
}

template <class T>
void ThreadTree<T>::createPostThread(ThreadNode<T> *current, ThreadNode<T> *& pre) {
  if (current == NULL) {
    return;
  }

  createPostThread(current->leftChild, pre);

  createPostThread(current->rightChild, pre);

  if (current->leftChild == NULL) {
    current->leftChild = pre;
    current->ltag = 1;
  }

  if (pre != NULL && pre->rightChild == NULL) {
    pre->rightChild = current;
    pre->rtag = 1;
  }

  pre = current;
}

template <class T>
void ThreadTree<T>::PreOrder(void (*visit)(ThreadNode<T> *p)) {
  ThreadNode<T> *p = root;

  while (p != NULL) {
    visit(p);

    if (p->ltag == 0) {
      p = p->leftChild;
    } else if (p->rtag == 0) {
      p = p->rightChild;
    } else {
      while (p != NULL && p->rtag == 1) {
        p = p->rightChild;
      }

      if (p != NULL) {
        p = p->rightChild;
      }
    }
  }
}

template <class T>
void ThreadTree<T>::PostOrder(void (*visit)(ThreadNode<T> *p)) {
  ThreadNode<T> *t = root;

  while (t->ltag == 0 || t->rtag == 0) {
    if (t->ltag == 0) {
      t = t->leftChild;
    } else if (t->rtag == 0) {
      t = t->rightChild;
    }
  }

  visit(t);

  ThreadNode<T> *p;

  while ((p = Parent(t)) != NULL) {
    if (p->rightChild == t || p->rtag == 1) {
      t = p;
    } else {
      t = p->rightChild;
      while (t->ltag == 0 || t->rtag == 0) {
        if (t->ltag == 0) {
          t = t->leftChild;
        } else if (t->rtag == 0) {
          t = t->rightChild;
        }
      }
    }

    visit(t);
  }
}

template <class T>
ThreadNode<T> *ThreadTree<T>::Parent(ThreadNode<T> *t) {
  ThreadNode<T> *p;

  if (t == root) {
    return NULL;
  }

  for (p = t; p->ltag == 0; p = p->leftChild);

  if (p->leftChild != NULL) {
    for (p = p->leftChild; 
      p != NULL && p->leftChild != t && p->rightChild != t;
      p = p->rightChild);
  }

  if (p == NULL || p->leftChild == NULL) {
    for (p = t; p->rtag == 0; p = p->rightChild);
    for (p = p->rightChild;
      p != NULL && p->leftChild != t && p->rightChild != t;
      p = p->leftChild);
    
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
    int i = Height(subTree->leftChild);
    int j = Height(subTree->rightChild);

    return (i > j) ? Insert(subTree->rightChild, x) : Insert(subTree->leftChild, x);
  }
}

template<class T>
int Height(ThreadNode<T> *subTree) {
  if (subTree == NULL) {
    return 0;
  } else {
    int i = Height(subTree->leftChild);
    int j = Height(subTree->rightChild);
    return (i < j) ? j + 1 : i + 1;
  }
}

template<class T>
void ThreadTree<T>::InsertRight(ThreadNode<T> *s, ThreadNode<T> *r) {
  r->rightChild = s->rightChild;
  r->rtag = s->rtag;

  r->leftChild = s;
  r->ltag = 1;

  s->rightChild = r;
  s->rtag = 0;

  if (r->rtag == 0) {
    ThreadNode<T> *temp;
    temp = First(r->rightChild);
    temp->leftChild = r;
  }
}

template<class T>
void ThreadTree<T>::InsertLeft(ThreadNode<T> *s, ThreadNode<T> *l) {
  l->leftChild = s->leftChild;
  l->ltag = s->ltag;
  l->rightChild = s;
  l->rtag = 1;

  s->leftChild = l;
  s->ltag = 0;

  if (l->rtag == 0) {
    ThreadNode<T> *temp;

    temp = Last(l->leftChild);
    temp->rightChild = l;
  }
}

template<class T>
void ThreadTree<T>::DeleteRight(ThreadNode<T> *s) {
  ThreadNode<T> *r = s->rightChild;

  if (r->rtag ==1) {
    if (r->ltag == 1) {
      /* r has neither right child nor left child */
      s->rightChild = r->rightChild;
      s->rtag = 1;
    } else {
      /* r has no right child but has left child */
      ThreadNode<T> *la = Last(r->leftChild);
      la->rightChild = r->rightChild;
      s->rightChild = r->leftChild;
    }
  } else {
    if (r->ltag == 1) {
      /* r has right child but has no left child */
      ThreadNode<T> *fr = First(r->rightChild);
      fr->leftChild = s;
      s->rightChild = r->rightChild;
    } else {
      /* r has both right child and left child */
      ThreadNode<T> *fr = First(r->rightChild);
      ThreadNode<T> *la = Last(r->leftChild);

      la->rightChild = r->leftChild;
      la->rtag = r->rtag;

      s->rightChild = r->leftChild;
      fr->leftChild = la;

    }
  }

  delete r;
}

template<class T>
void ThreadTree<T>::DeleteLeft(ThreadNode<T> *s) {
  ThreadNode<T> *l = s->leftChild;

  if (l->rtag == 1) {
    if (l->ltag == 1) {
      /* l has neither right child nor left child */
      s->leftChild = l->leftChild;
      s->ltag = 1;
    } else {
      /* l has no right child but has left child */
      ThreadNode<T> *la = Last(l->leftChild);
      la->rightChild = s;
      s->leftChild = l->leftChild;
    }
  } else {
    if (l->ltag == 1) {
      /* l has right child but has no left child */
      ThreadNode<T> *fr = First(l->rightChild);
      fr->leftChild = l->leftChild;
      s->leftChild = l->rightChild;
    } else {
      /* l has both right child and left child */
      ThreadNode<T> *fr = First(l->rightChild);
      ThreadNode<T> *la = Last(l->leftChild);

      la->rightChild = l->rightChild;
      la->rtag = l->rtag;

      s->leftChild = l->leftChild;
      fr->leftChild = la;
    }
  }

  delete l;
}

template <class T>
ThreadNode<T> *ThreadTree<T>::PreOrderNext(ThreadNode<T> *current) {
  if (current->ltag != 1) {
    return current->leftChild;
  }

  return current->rightChild;
}

template <class T>
ThreadNode<T> *ThreadTree<T>::PreOrderPrior(ThreadNode<T> *current) {
  if (current->ltag == 1) {
    return current->leftChild;
  }

  ThreadNode<T> *parent = Parent(current);

  if (parent == NULL) {
    return NULL;
  }

  if (parent->ltag == 1 || parent->leftChild == current) {
    return parent;
  }

  return Last(parent->leftChild);
}

template <class T>
ThreadNode<T> *ThreadTree<T>::PostOrderNext(ThreadNode<T> *current) {
  if (current->rtag == 1) {
    return current->rightChild;
  }

  ThreadNode<T> *parent = Parent(current);
  if (parent == NULL) {
    return NULL;
  }

  if (parent->rtag == 1 || parent->rightChild == current) {
    return parent;
  }

  return First(parent->rightChild);
}

template <class T>
ThreadNode<T> *ThreadTree<T>::PostOrderPrior(ThreadNode<T> *current) {
  if (current->ltag == 1) {
    return current->leftChild;
  }

  if (current->rtag == 1) {
    return current->leftChild;
  }

  return current->rightChild;
}


template<class T>
void ThreadTree<T>::CyberDashShow() {
  cout<<endl
      <<"*************************************** CyberDash ***************************************"<<endl<<endl
      <<"抖音号\"CyberDash计算机考研\", id: cyberdash_yuan"<<endl<<endl
      <<"CyberDash成员:"<<endl
      <<"元哥(cyberdash@163.com), "<<"北京邮电大学(通信工程本科)/北京邮电大学(信息与通信系统研究生)"<<endl
      <<"磊哥(alei_go@163.com), "<<"山东理工大学(数学本科)/北京邮电大学(计算机研究生)"<<endl<<endl
      <<"数据结构开源代码(C++清华大学殷人昆)魔改升级版本: https://gitee.com/cyberdash/data-structure-cpp"<<endl
      <<endl<<"*************************************** CyberDash ***************************************"<<endl<<endl;
}
