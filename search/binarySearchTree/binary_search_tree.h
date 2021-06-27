#ifndef CYBER_DASH_BINARY_SEARCH_TREE_H
#define CYBER_DASH_BINARY_SEARCH_TREE_H


#include <iostream>
#include <cstdlib>


using namespace std;


template <class Elem, class Key>
class BSTNode {
public:
  BSTNode(): left_child_ptr_(NULL), right_child_ptr_(NULL) {}
  BSTNode(const Elem& elem, const Key& key,
          BSTNode<Elem, Key>* left_child_ptr = NULL,
          BSTNode<Elem, Key>* right_child_ptr = NULL):
      elem_(elem), key_(key), left_child_ptr_(left_child_ptr), right_child_ptr_(right_child_ptr) {}
  // ~BSTNode() { }

  void SetData(const Elem& elem) { elem_ = elem;}
  Elem GetData() { return elem_; }

  void SetKey(const Key& key) { key_ = key; }
  Key GetKey() { return key_; }

  BSTNode<Elem, Key>* left_child_ptr_;
  BSTNode<Elem, Key>* right_child_ptr_;

private:
  Key key_;
  Elem elem_;
};


template <class Elem, class Key>
class BST {
public:
  BST(): root_(NULL) {}
  BST(Key key);
  BST(const Key& key, const Elem& elem);
  ~BST() {};
  BSTNode<Elem, Key>* Search (const Key key) { return Search_(key, root_); }
  BST<Elem, Key>& operator=(const BST<Elem, Key>& R);
  void makeEmpty(void) { MakeEmpty(root_); root_ = NULL; }
  void PrintTree(void (*visit)(BSTNode<Elem, Key> *p)) const { PrintTree(root_, visit); }
  Elem Min() { return Min(root_)->elem_; }
  Elem Max() { return Max(root_)->elem_; }

  bool Insert(const Elem& elem, const Key& key) {
    if (Search(key) != NULL)
      return true;
    return InsertSubTree_(elem, key, root_);
  }

  bool Remove(const Key key) { return Remove(key, root_); }

protected:
  BSTNode<Elem, Key>* root_;
  // Key RefValue;
  BSTNode<Elem, Key>* Search_(const Key& key, BSTNode<Elem, Key>* node_ptr);
  void MakeEmpty(BSTNode<Elem, Key>*& ptr);
  void PrintTree(BSTNode<Elem, Key>* ptr, void (*visit)(BSTNode<Elem, Key>* p)) const;
  BSTNode<Elem, Key>* Copy(const BSTNode<Elem, Key>* ptr);
  BSTNode<Elem, Key>* Min(BSTNode<Elem, Key>* ptr) const;
  BSTNode<Elem, Key>* Max(BSTNode<Elem, Key>* ptr) const;
  bool InsertSubTree_(const Elem& elem, const Key& key, BSTNode<Elem, Key>*& sub_tree_root_ptr);
  bool Remove(const Key& key, BSTNode<Elem, Key>*& node_ptr);
};


template <class Elem, class Key>
BSTNode<Elem, Key>* BST<Elem, Key>::Search_(const Key& key, BSTNode<Elem, Key>* node_ptr) {
  if (node_ptr == NULL) {
    return NULL;
  }

  Key cur_key = node_ptr->GetKey();

  if (key < cur_key) {
    return Search_(key, node_ptr->left_child_ptr_);
  } else if (key > cur_key) {
    return Search_(key, node_ptr->right_child_ptr_);
  } else {
    return node_ptr;
  }
};


template <class Elem, class Key>
bool BST<Elem, Key>::InsertSubTree_(const Elem& elem, const Key& key, BSTNode<Elem, Key>*& sub_tree_root_ptr) {
  if (sub_tree_root_ptr == NULL) {
    sub_tree_root_ptr = new BSTNode<Elem, Key>(elem, key);
    /* error handler */

    return true;
  }

  if (key< sub_tree_root_ptr->GetKey()) {
    return InsertSubTree_(elem, key, sub_tree_root_ptr->left_child_ptr_);
  } else if (key > sub_tree_root_ptr->GetKey()) {
    return InsertSubTree_(elem, key, sub_tree_root_ptr->right_child_ptr_);
  } else {
    return false;
  }
};


/*
template <class Elem, class Key>
BST<Elem, Key>::BST(Key value) {
  Elem x;
  root_ = NULL;
  RefValue = value;
  cin >> x;
  while (x.key != RefValue) {
    InsertSubTree_(x, root_);
    cin >> x;
  }
};
 */


template <class Elem, class Key>
BST<Elem, Key>::BST(const Key& key, const Elem& elem) {
  // root_ = new BSTNode<Elem, Key>(elem, key);
  Insert(elem, key);
}


template <class Elem, class Key>
bool BST<Elem, Key>::Remove(const Key& key, BSTNode<Elem, Key>*& node_ptr) {
  BSTNode<Elem, Key> *temp;

  if (node_ptr == NULL) {
    return false;
  }

  if (key < node_ptr->GetKey()) {
    return Remove(key, node_ptr->left_child_ptr_);
  } else if (key > node_ptr->GetKey()) {
    return Remove(key, node_ptr->right_child_ptr_);
  }

  if (node_ptr->left_child_ptr_ != NULL && node_ptr->right_child_ptr_ != NULL) {
    temp = node_ptr->right_child_ptr_;
    while (temp->left_child_ptr_ != NULL) {
      temp = temp->left_child_ptr_;
    }
    node_ptr->elem_ = temp->elem_;
    return Remove(node_ptr->elem_.getKey(), node_ptr->right_child_ptr_);
  } else {
    temp = node_ptr;
    if (node_ptr->left_child_ptr_ == NULL) {
      node_ptr = node_ptr->right_child_ptr_;
    } else {
      node_ptr = node_ptr->left_child_ptr_;
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

  MakeEmpty(ptr->left_child_ptr_);
  MakeEmpty(ptr->right_child_ptr_);

  delete ptr;
};

template <class E, class K>
void BST<E, K>::PrintTree(BSTNode<E, K> *ptr, void (*visit)(BSTNode<E, K> *p)) const {
  if (ptr == NULL) {
    return;
  }

  visit(ptr);
  cout << "(";
  PrintTree(ptr->left_child_ptr_, visit);
  cout << ",";
  PrintTree(ptr->right_child_ptr_, visit);
  cout << ")";
};

template <class E, class K>
BSTNode<E, K> *BST<E, K>::Copy(const BSTNode<E, K> *ptr) {
  if (ptr == NULL) {
    return NULL;
  }

  BSTNode<E, K> *pnode = new BSTNode<E, K>(ptr->elem_);
  pnode->left_child_ptr_ = Copy(ptr->left_child_ptr_);
  pnode->right_child_ptr_ = Copy(ptr->right_child_ptr_);

  return pnode;
};

template <class E, class K>
BSTNode<E, K> *BST<E, K>::Min(BSTNode<E, K> *ptr) const {
  if (ptr == NULL) {
    return NULL;
  }
  BSTNode<E, K> *ans = ptr;
  while (ans->left_child_ptr_ != NULL) {
    ans = ans->left_child_ptr_;
  }

  return ans;
};

template <class E, class K>
BSTNode<E, K> *BST<E, K>::Max(BSTNode<E, K> *ptr) const {
  if (ptr == NULL) {
    return NULL;
  }
  BSTNode<E, K> *ans = ptr;
  while (ans->right_child_ptr_ != NULL) {
    ans = ans->right_child_ptr_;
  }

  return ans;
};


#endif // CYBER_DASH_BINARY_SEARCH_TREE_H
