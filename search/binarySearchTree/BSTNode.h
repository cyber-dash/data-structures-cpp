#ifndef CYBER_DASH_BINARY_SEARCH_TREE_H
#define CYBER_DASH_BINARY_SEARCH_TREE_H


#include <iostream>
#include <stdlib.h>


using namespace std;


template <class E, class K>
struct BSTNode {
  BSTNode(): left_child(NULL), right_child(NULL) {}
  BSTNode(const E data, BSTNode<E, K>* left_child_ptr = NULL, BSTNode<E, K>* right_child_ptr = NULL):
      data_(data), left_child(left_child_ptr), right_child(right_child_ptr) {}
  ~BSTNode() { }

  void SetData(E data) { data_ = data;}
  E GetData() {return data_;}

  BSTNode<E, K>* left_child;
  BSTNode<E, K>* right_child;

  E data_;
};


template <class E, class K>
class BST {
public:
  BST(): root_(NULL) {}
  BST(K key);
  ~BST() {};
  BSTNode<E, K> *Search (const K key) { return Search_(key, root_); }
  BST<E, K> & operator = (const BST<E, K> &R);
  void makeEmpty(void) { MakeEmpty(root_); root_ = NULL; }
  void PrintTree(void (*visit)(BSTNode<E, K> *p)) const { PrintTree(root_, visit); }
  E Min() { return Min(root_)->data_; }
  E Max() { return Max(root_)->data_; }
  bool Insert(E& el, const K key) { if (Search_(key) != NULL) return true; return Insert(el, root_); }
  bool Remove(const K key) { return Remove(key, root_); }

protected:
  BSTNode<E, K>* root_;
  K RefValue;
  BSTNode<E, K>* Search_(const K key, BSTNode<E, K>* node_ptr);
  void MakeEmpty(BSTNode<E, K>*& ptr);
  void PrintTree(BSTNode<E, K>* ptr, void (*visit)(BSTNode<E, K>* p)) const;
  BSTNode<E, K>* Copy(const BSTNode<E, K>* ptr);
  BSTNode<E, K>* Min(BSTNode<E, K>* ptr) const;
  BSTNode<E, K>* Max(BSTNode<E, K>* ptr) const;
  bool Insert(E& data, BSTNode<E, K>*& node_ptr);
  bool Remove(const K key, BSTNode<E, K>*& ptr);
};


template <class E, class K>
BSTNode<E, K>* BST<E, K>::Search_(const K key, BSTNode<E, K>* node_ptr) {
  if (node_ptr == NULL) {
    return NULL;
  }

  if (key < node_ptr->data_) {
    return Search_(key, node_ptr->left_child);
  } else if (key > node_ptr->data_) {
    return Search_(key, node_ptr->right_child);
  } else {
    return node_ptr;
  }
};


template <class E, class K>
bool BST<E, K>::Insert(E& data, BSTNode<E, K>*& node_ptr) {
  if (node_ptr == NULL) {
    node_ptr = new BSTNode<E, K>(data);
    if (node_ptr == NULL) {
      cerr << "Out of space" << endl;
      return false;
    }

    return true;
  }

  if (data < node_ptr->data_) {
    return Insert(data, node_ptr->left_child);
  } else if (data > node_ptr->data_) {
    return Insert(data, node_ptr->right_child);
  } else {
    return false;
  }
};


template <class E, class K>
BST<E, K>::BST(K value) {
  E x;
  root_ = NULL;
  RefValue = value;
  cin >> x;
  while (x.key != RefValue) {
    Insert(x, root_);
    cin >> x;
  }
};

template <class E, class K>
bool BST<E, K>::Remove(const K x, BSTNode<E, K> *& ptr) {
  BSTNode<E, K> *temp;

  if (ptr == NULL) {
    return false;
  }

  if (x < ptr->data_) {
    return Remove(x, ptr->left_child);
  } else if (x > ptr->data_) {
    return Remove(x, ptr->right_child);
  }

  if (ptr->left_child != NULL && ptr->right_child != NULL) {
    temp = ptr->right_child;
    while (temp->left_child != NULL) {
      temp = temp->left_child;
    }
    ptr->data_ = temp->data_;
    return Remove(ptr->data_.getKey(), ptr->right_child);
  } else {
    temp = ptr;
    if (ptr->left_child == NULL) {
      ptr = ptr->right_child;
    } else {
      ptr = ptr->left_child;
    }

    delete temp;
    return true;
  }
};

template <class E, class K>
void BST<E, K>::MakeEmpty(BSTNode<E, K> *&ptr) {
  if (ptr == NULL) {
    return;
  }

  MakeEmpty(ptr->left_child);
  MakeEmpty(ptr->right_child);

  delete ptr;
};

template <class E, class K>
void BST<E, K>::PrintTree(BSTNode<E, K> *ptr, void (*visit)(BSTNode<E, K> *p)) const {
  if (ptr == NULL) {
    return;
  }

  visit(ptr);
  cout << "(";
  PrintTree(ptr->left_child, visit);
  cout << ",";
  PrintTree(ptr->right_child, visit);
  cout << ")";
};

template <class E, class K>
BSTNode<E, K> *BST<E, K>::Copy(const BSTNode<E, K> *ptr) {
  if (ptr == NULL) {
    return NULL;
  }

  BSTNode<E, K> *pnode = new BSTNode<E, K>(ptr->data_);
  pnode->left_child = Copy(ptr->left_child);
  pnode->right_child = Copy(ptr->right_child);

  return pnode;
};

template <class E, class K>
BSTNode<E, K> *BST<E, K>::Min(BSTNode<E, K> *ptr) const {
  if (ptr == NULL) {
    return NULL;
  }
  BSTNode<E, K> *ans = ptr;
  while (ans->left_child != NULL) {
    ans = ans->left_child;
  }

  return ans;
};

template <class E, class K>
BSTNode<E, K> *BST<E, K>::Max(BSTNode<E, K> *ptr) const {
  if (ptr == NULL) {
    return NULL;
  }
  BSTNode<E, K> *ans = ptr;
  while (ans->right_child != NULL) {
    ans = ans->right_child;
  }

  return ans;
};


#endif // CYBER_DASH_BINARY_SEARCH_TREE_H
