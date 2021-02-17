
#include <iostream>
#include <string>

#include "BSTNode.h"

using namespace std;

template <class E, class K>
BSTNode<E, K> *BST<E, K>::Search(const K x, BSTNode<E, K> *ptr) {
  if (ptr == NULL) {
    return NULL;
  }

  if (x < ptr->data) {
    return Search(x, ptr->left);
  } else if (x > ptr->data) {
    return Search(x, ptr->right);
  } else {
    return ptr;
  }
};

template <class E, class K>
bool BST<E, K>::Insert(E& el, BSTNode<E, K> *&ptr) {
  if (ptr == NULL) {
    ptr = new BSTNode<E, K>(el);
    if (ptr == NULL) {
      cerr << "Out of space" << endl;
      exit(-1);
    }

    return true;
  }

  if (el < ptr->data) {
    return Insert(el, ptr->left);
  } else if (el > ptr->data) {
    return Insert(el, ptr->right);
  } else {
    return false;
  }
};

template <class E, class K>
BST<E, K>::BST(K value) {
  E x;
  root = NULL;
  RefValue = value;
  cin >> x;
  while (x.key != RefValue) {
    Insert(x, root);
    cin >> x;
  }
};

template <class E, class K>
bool BST<E, K>::Remove(const K x, BSTNode<E, K> *& ptr) {
  BSTNode<E, K> *temp;

  if (ptr == NULL) {
    return false;
  }

  if (x < ptr->data) {
    return Remove(x, ptr->left);
  } else if (x > ptr->data) {
    return Remove(x, ptr->right);
  }

  if (ptr->left != NULL && ptr->right != NULL) {
    temp = ptr->right;
    while (temp->left != NULL) {
      temp = temp->left;
    }
    ptr->data = temp->data;
    return Remove(ptr->data.getKey(), ptr->right);
  } else {
    temp = ptr;
    if (ptr->left == NULL) {
      ptr = ptr->right;
    } else {
      ptr = ptr->left;
    }

    delete temp; 
    return true;
  }
};

template <class E, class K>
void BST<E, K>::makeEmpty(BSTNode<E, K> *&ptr) {
  if (ptr == NULL) {
    return;
  }

  makeEmpty(ptr->left);
  makeEmpty(ptr->right);

  delete ptr;
};

template <class E, class K>
void BST<E, K>::PrintTree(BSTNode<E, K> *ptr, void (*visit)(BSTNode<E, K> *p)) const {
  if (ptr == NULL) {
    return;
  }

  visit(ptr);
  cout << "(";
  PrintTree(ptr->left, visit);
  cout << ",";
  PrintTree(ptr->right, visit);
  cout << ")";
};

template <class E, class K>
BSTNode<E, K> *BST<E, K>::Copy(const BSTNode<E, K> *ptr) {
  if (ptr == NULL) {
    return NULL;
  }

  BSTNode<E, K> *pnode = new BSTNode<E, K>(ptr->data);
  pnode->left = Copy(ptr->left);
  pnode->right = Copy(ptr->right);

  return pnode;
};

template <class E, class K>
BSTNode<E, K> *BST<E, K>::Min(BSTNode<E, K> *ptr) const {
  if (ptr == NULL) {
    return NULL;
  }
  BSTNode<E, K> *ans = ptr;
  while (ans->left != NULL) {
    ans = ans->left;
  }

  return ans;
};

template <class E, class K>
BSTNode<E, K> *BST<E, K>::Max(BSTNode<E, K> *ptr) const {
  if (ptr == NULL) {
    return NULL;
  }
  BSTNode<E, K> *ans = ptr;
  while (ans->right != NULL) {
    ans = ans->right;
  }

  return ans;
};

