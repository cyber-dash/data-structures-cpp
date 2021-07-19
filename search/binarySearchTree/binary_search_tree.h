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

  virtual void SetData(const Elem& elem) { elem_ = elem;}
  virtual Elem GetData() { return elem_; }

  virtual void SetKey(const Key& key) { key_ = key; }
  virtual Key GetKey() { return key_; }

  void SetLeftChildPtr(BSTNode<Elem, Key>* node_ptr) { this->left_child_ptr_ = node_ptr; }
  void SetRightChildPtr(BSTNode<Elem, Key>* node_ptr) { this->right_child_ptr_ = node_ptr; }

  BSTNode<Elem, Key>*& LeftChildPtr() { return this->left_child_ptr_; };
  BSTNode<Elem, Key>*& RightChildPtr() { return this->right_child_ptr_; };

protected:
  BSTNode<Elem, Key>* left_child_ptr_;
  BSTNode<Elem, Key>* right_child_ptr_;

  Key key_;
  Elem elem_;
};


template <class Elem, class Key>
class BST {
public:
  BST(): root_(NULL) {}
  // BST(Key key);
  BST(const Key& key, const Elem& elem);
  ~BST() {};
  BSTNode<Elem, Key>* Search (const Key& key) {
    return SearchInSubTree_(key, this->root_);
  }
  BST<Elem, Key>& operator=(const BST<Elem, Key>& R);
  void makeEmpty(void) { MakeEmpty(root_); root_ = NULL; }
  void PrintTree(void (*visit)(BSTNode<Elem, Key>*)) const { this->PrintSubTree_(this->root_, visit); }
  Elem Min() { return MinInSubTree_(root_)->GetData(); }
  Elem Max() { return MaxInSubTree_(root_)->GetData(); }

  virtual bool Insert(Elem elem, Key key);
  virtual bool Remove(const Key& key) { return RemoveInSubTree_(key, root_); }

protected:
  BSTNode<Elem, Key>* root_;
  // Key RefValue;
  BSTNode<Elem, Key>* SearchInSubTree_(const Key& key, BSTNode<Elem, Key>* node_ptr);
  void MakeEmpty(BSTNode<Elem, Key>*& sub_tree_root_ptr);
  void PrintSubTree_(BSTNode<Elem, Key>* sub_tree_root_ptr, void (*visit)(BSTNode<Elem, Key>* p)) const;
  BSTNode<Elem, Key>* Copy(const BSTNode<Elem, Key>* origin_sub_tree_root_ptr);
  BSTNode<Elem, Key>* MinInSubTree_(BSTNode<Elem, Key>* sub_tree_root_ptr) const;
  BSTNode<Elem, Key>* MaxInSubTree_(BSTNode<Elem, Key>* sub_tree_root_ptr) const;
  // bool InsertIntoSubTree_(const Elem& elem, const Key& key, BSTNode<Elem, Key>*& sub_tree_root_ptr);
  bool InsertIntoSubTree_(Elem elem, Key key, BSTNode<Elem, Key>*& sub_tree_root_ptr);
  bool RemoveInSubTree_(const Key& key, BSTNode<Elem, Key>*& sub_tree_root_ptr);
};


template <class Elem, class Key>
BSTNode<Elem, Key>* BST<Elem, Key>::SearchInSubTree_(const Key& key, BSTNode<Elem, Key>* node_ptr) {
  if (node_ptr == NULL) {
    return NULL;
  }

  Key cur_key = node_ptr->GetKey();

  if (key < cur_key) {
    return SearchInSubTree_(key, node_ptr->LeftChildPtr());
  } else if (key > cur_key) {
    return SearchInSubTree_(key, node_ptr->RightChildPtr());
  } else {
    return node_ptr;
  }
}


template<class Elem, class Key>
bool BST<Elem, Key>::Insert(Elem elem, Key key) {
  if (this->Search(key) != NULL) {
    return true;
  }

  return this->InsertIntoSubTree_(elem, key, this->root_);
}


template <class Elem, class Key>
// bool BST<Elem, Key>::InsertIntoSubTree_(const Elem& elem, const Key& key, BSTNode<Elem, Key>*& sub_tree_root_ptr) {
bool BST<Elem, Key>::InsertIntoSubTree_(Elem elem, Key key, BSTNode<Elem, Key>*& sub_tree_root_ptr) {
  if (sub_tree_root_ptr == NULL) {
    sub_tree_root_ptr = new BSTNode<Elem, Key>(elem, key);
    /* error handler */

    return true;
  }

  if (key < sub_tree_root_ptr->GetKey()) {
    return InsertIntoSubTree_(elem, key, sub_tree_root_ptr->LeftChildPtr());
  } else if (key > sub_tree_root_ptr->GetKey()) {
    return InsertIntoSubTree_(elem, key, sub_tree_root_ptr->RightChildPtr());
  } else {
    return false;
  }
}


/*
template <class Elem, class Key>
BST<Elem, Key>::BST(Key value) {
  Elem x;
  root_ = NULL;
  RefValue = value;
  cin >> x;
  while (x.key != RefValue) {
    InsertIntoSubTree_(x, root_);
    cin >> x;
  }
};
 */


template <class Elem, class Key>
BST<Elem, Key>::BST(const Key& key, const Elem& elem) {
  Insert(elem, key);
}


template <class Elem, class Key>
bool BST<Elem, Key>::RemoveInSubTree_(const Key& key, BSTNode<Elem, Key>*& sub_tree_root_ptr) {


  if (sub_tree_root_ptr == NULL) {
    return false;
  }

  if (key < sub_tree_root_ptr->GetKey()) {
    return RemoveInSubTree_(key, sub_tree_root_ptr->LeftChildPtr());
  } else if (key > sub_tree_root_ptr->GetKey()) {
    return RemoveInSubTree_(key, sub_tree_root_ptr->RightChildPtr());
  }

  if (sub_tree_root_ptr->LeftChildPtr() != NULL && sub_tree_root_ptr->RightChildPtr() != NULL) {

    BSTNode<Elem, Key>* cur_node_ptr = sub_tree_root_ptr->RightChildPtr();
    while (cur_node_ptr->LeftChildPtr()!= NULL) {
      cur_node_ptr = cur_node_ptr->LeftChildPtr();
    }

    sub_tree_root_ptr->SetData(cur_node_ptr->GetData());
    sub_tree_root_ptr->SetKey(cur_node_ptr->GetKey());

    return RemoveInSubTree_(sub_tree_root_ptr->GetKey(), sub_tree_root_ptr->RightChildPtr());
  } else {
    BSTNode<Elem, Key>* cur_node_ptr = sub_tree_root_ptr;
    if (sub_tree_root_ptr->LeftChildPtr() == NULL) {
      sub_tree_root_ptr = sub_tree_root_ptr->RightChildPtr();
    } else {
      sub_tree_root_ptr = sub_tree_root_ptr->LeftChildPtr();
    }

    delete cur_node_ptr;
    cur_node_ptr = NULL;

    return true;
  }
}


template <class Elem, class K>
void BST<Elem, K>::MakeEmpty(BSTNode<Elem, K>*& sub_tree_root_ptr) {

  if (sub_tree_root_ptr == NULL) {
    return;
  }

  MakeEmpty(sub_tree_root_ptr->LeftChildPtr());
  MakeEmpty(sub_tree_root_ptr->RightChildPtr());

  delete sub_tree_root_ptr;
  sub_tree_root_ptr = NULL;
}


template <class Elem, class Key>
void BST<Elem, Key>::PrintSubTree_(BSTNode<Elem, Key>* sub_tree_root_ptr, void (*visit)(BSTNode<Elem, Key> *p)) const {

  if (sub_tree_root_ptr == NULL) {
    return;
  }

  visit(sub_tree_root_ptr);

  cout << "(";

  PrintSubTree_(sub_tree_root_ptr->LeftChildPtr(), visit);

  cout << ",";

  PrintSubTree_(sub_tree_root_ptr->RightChildPtr(), visit);

  cout << ")";
}


template <class Elem, class Key>
BSTNode<Elem, Key>* BST<Elem, Key>::Copy(const BSTNode<Elem, Key>* origin_sub_tree_root_ptr) {

  if (origin_sub_tree_root_ptr == NULL) {
    return NULL;
  }

  BSTNode<Elem, Key>* new_sub_tree_root_ptr = new BSTNode<Elem, Key>(
      origin_sub_tree_root_ptr->GetData(),
      origin_sub_tree_root_ptr->GetKey());

  new_sub_tree_root_ptr->left_child_ptr_ = Copy(origin_sub_tree_root_ptr->left_child_ptr_);
  new_sub_tree_root_ptr->right_child_ptr_ = Copy(origin_sub_tree_root_ptr->right_child_ptr_);

  return new_sub_tree_root_ptr;
}


template <class Elem, class Key>
BSTNode<Elem, Key>* BST<Elem, Key>::MinInSubTree_(BSTNode<Elem, Key>* sub_tree_root_ptr) const {

  if (sub_tree_root_ptr == NULL) {
    return NULL;
  }

  BSTNode<Elem, Key>* cur_node_ptr = sub_tree_root_ptr;

  while (cur_node_ptr->LeftChildPtr() != NULL) {
    cur_node_ptr = cur_node_ptr->LeftChildPtr();
  }

  return cur_node_ptr;
}


template <class Elem, class Key>
BSTNode<Elem, Key>* BST<Elem, Key>::MaxInSubTree_(BSTNode<Elem, Key>* sub_tree_root_ptr) const {

  if (sub_tree_root_ptr == NULL) {
    return NULL;
  }

  BSTNode<Elem, Key>* cur_node_ptr = sub_tree_root_ptr;
  while (cur_node_ptr->RightChildPtr() != NULL) {
    cur_node_ptr = cur_node_ptr->RightChildPtr();
  }

  return cur_node_ptr;
}


#endif // CYBER_DASH_BINARY_SEARCH_TREE_H
