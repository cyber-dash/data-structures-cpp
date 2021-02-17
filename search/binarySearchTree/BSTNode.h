#ifndef CYBER_DASH_LEI_BSTNODE_H
#define CYBER_DASH_LEI_BSTNODE_H

#include <iostream>
#include <stdlib.h>

template <class E, class K>

struct BSTNode {
  E data;
  BSTNode<E, K> *left, *right;
  BSTNode(): left(NULL), right(NULL) {}
  BSTNode(const E d, BSTNode<E, K> *L = NULL, BSTNode<E, K> *R = NULL): data(d), left(L), right(R) {}
  ~BSTNode() { }
  void setData(E d) {data = d;}
  E getData() {return data;}
};

template <class E, class K>
class BST {
public:
  BST(): root(NULL) {}
  BST(K value);
  ~BST() {};
  BSTNode<E, K> *Search (const K x) { return Search(x, root); }
  BST<E, K> & operator = (const BST<E, K> &R);
  void makeEmpty(void) { makeEmpty(root); root = NULL; }
  void PrintTree(void (*visit)(BSTNode<E, K> *p)) const { PrintTree(root, visit); }
  E Min() { return Min(root)->data; }
  E Max() { return Max(root)->data; }
  bool Insert(E& el, const K x) { if (Search(x) != NULL) return true; return Insert(el, root); }
  bool Remove(const K x) { return Remove(x, root); }

private:
  BSTNode<E, K> *root;
  K RefValue;
  BSTNode<E, K> *Search(const K x, BSTNode<E, K> *ptr);
  void makeEmpty(BSTNode<E, K> *&ptr);
  void PrintTree(BSTNode<E, K> *ptr, void (*visit)(BSTNode<E, K> *p)) const;
  BSTNode<E, K> *Copy(const BSTNode<E, K> *ptr);
  BSTNode<E, K> *Min(BSTNode<E, K> *ptr) const;
  BSTNode<E, K> *Max(BSTNode<E, K> *ptr) const;
  bool Insert(E &el, BSTNode<E, K> *& ptr);
  bool Remove(const K x, BSTNode<E, K> *& ptr);
};
#endif //CYBER_DASH_LEI_BSTNODE_H
