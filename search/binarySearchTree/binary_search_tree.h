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
  BST(): root_node_ptr_(NULL) {}
  BST(Key key, Elem elem);
  virtual ~BST() { delete this->root_node_ptr_; };
  BSTNode<Elem, Key>* Search (const Key& key) { return SearchInSubTree_(key, this->root_node_ptr_); }
  BST<Elem, Key>& operator=(const BST<Elem, Key>& R);
  void MakeEmpty() { MakeEmptySubTree_(root_node_ptr_); root_node_ptr_ = NULL; }
  void PrintTree(void (*visit)(BSTNode<Elem, Key>*)) const { this->PrintSubTree_(this->root_node_ptr_, visit); }
  Elem Min() { return MinInSubTree_(root_node_ptr_)->GetData(); }
  Elem Max() { return MaxInSubTree_(root_node_ptr_)->GetData(); }

  virtual bool Insert(Elem elem, Key key);
  virtual bool Remove(const Key& key) { return RemoveInSubTree_(key, root_node_ptr_); }

protected:
  BSTNode<Elem, Key>* root_node_ptr_;
  // 在子树中, 使用关键码进行搜索
  BSTNode<Elem, Key>* SearchInSubTree_(Key key, BSTNode<Elem, Key>* sub_tree_root_ptr);

  void MakeEmptySubTree_(BSTNode<Elem, Key>*& sub_tree_root_ptr);

  // 打印子树(递归/中序)
  void PrintSubTree_(BSTNode<Elem, Key>* sub_tree_root_ptr, void (*visit)(BSTNode<Elem, Key>* p)) const;

  BSTNode<Elem, Key>* Copy(const BSTNode<Elem, Key>* origin_sub_tree_root_ptr);

  // 子树中关键码最小项
  BSTNode<Elem, Key>* MinInSubTree_(BSTNode<Elem, Key>* sub_tree_root_ptr) const;

  // 子树中关键码最大项
  BSTNode<Elem, Key>* MaxInSubTree_(BSTNode<Elem, Key>* sub_tree_root_ptr) const;

  // 子树中插入节点(递归)
  bool InsertIntoSubTree_(Elem elem, Key key, BSTNode<Elem, Key>*& sub_tree_root_ptr);

  // 子树中删除节点(递归)
  bool RemoveInSubTree_(Key key, BSTNode<Elem, Key>*& sub_tree_root_ptr);
};


/**
 * @brief 在子树中, 使用关键码进行搜索
 * @tparam Elem 数据项模板类型
 * @tparam Key 关键码模板类型
 * @param key 关键码
 * @param sub_tree_root_ptr 子树根节点
 * @return 搜索结果
 * @note
 * 1. 如果子树根节点为NULL, 返回NULL
 * 2. 使用当前遍历节点的key, 与参数key作比较, 分别进行递归和返回搜索结果(终止递归)
 */
template <class Elem, class Key>
BSTNode<Elem, Key>* BST<Elem, Key>::SearchInSubTree_(Key key, BSTNode<Elem, Key>* sub_tree_root_ptr) {
  if (sub_tree_root_ptr == NULL) {
    return NULL;
  }

  Key cur_key = sub_tree_root_ptr->GetKey();

  if (key < cur_key) {
    return SearchInSubTree_(key, sub_tree_root_ptr->LeftChildPtr());
  } else if (key > cur_key) {
    return SearchInSubTree_(key, sub_tree_root_ptr->RightChildPtr());
  } else {
    return sub_tree_root_ptr;
  }
}


template<class Elem, class Key>
bool BST<Elem, Key>::Insert(Elem elem, Key key) {
  if (this->Search(key) != NULL) {
    return true;
  }

  return this->InsertIntoSubTree_(elem, key, this->root_node_ptr_);
}


/**
 * @brief 子树中插入节点(递归)
 * @tparam Elem 数据项模板类型
 * @tparam Key 关键码模板类型
 * @param elem 数据项
 * @param key 关键码
 * @param sub_tree_root_ptr 子树根节点指针
 * @return 是否插入成功
 * @note
 * 如果根节点指针为NULL, 则创建节点
 * 判断插入关键码与子树根节点关键码的大小关系, 在左子树or右子树做插入操作(递归)
 * 如果关键码相同, 则返回false
 */
template <class Elem, class Key>
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


template <class Elem, class Key>
BST<Elem, Key>::BST(Key key, Elem elem) {
  this->Insert(elem, key);
}


/**
 * @brief 子树中删除节点(递归)
 * @tparam Elem 数据项模板类型
 * @tparam Key 关键码模板类型
 * @param key 待删除节点的数据码
 * @param sub_tree_root_ptr 子树根节点
 * @return 是否删除成功
 * @note
 * 1. 如果子树根节点指针为NULL, 则返回false
 * 2. 递归分治, 找到删除节点的位置
 * 3. 如果有两个孩子节点, 使用中序前驱or后继, 替换掉待删除节点
 * 4. 如果只有一个孩子节点, 则将该孩子提升至待删除节点
 */
template <class Elem, class Key>
bool BST<Elem, Key>::RemoveInSubTree_(Key key, BSTNode<Elem, Key>*& sub_tree_root_ptr) {

  if (sub_tree_root_ptr == NULL) {
    return false;
  }

  if (key < sub_tree_root_ptr->GetKey()) {
    return RemoveInSubTree_(key, sub_tree_root_ptr->LeftChildPtr());
  } else if (key > sub_tree_root_ptr->GetKey()) {
    return RemoveInSubTree_(key, sub_tree_root_ptr->RightChildPtr());
  }

  // 删除sub_tree_root_ptr, 使用中序前驱or后继替换掉该节点, 此处使用后继
  if (sub_tree_root_ptr->LeftChildPtr() != NULL && sub_tree_root_ptr->RightChildPtr() != NULL) { // 存在左右孩子

    BSTNode<Elem, Key>* cur_node_ptr = sub_tree_root_ptr->RightChildPtr();
    while (cur_node_ptr->LeftChildPtr()!= NULL) {
      cur_node_ptr = cur_node_ptr->LeftChildPtr();
    }

    // 拿到后继节点的数据, 作为替换数据
    Elem replace_data = cur_node_ptr->GetData();
    Key replace_key = cur_node_ptr->GetKey();

    sub_tree_root_ptr->SetData(replace_data);
    sub_tree_root_ptr->SetKey(replace_key);

    // 删除替换数据原先所在的节点
    return RemoveInSubTree_(replace_key, sub_tree_root_ptr->RightChildPtr());
  } else {
    BSTNode<Elem, Key>* delete_node_ptr = sub_tree_root_ptr;

    if (sub_tree_root_ptr->LeftChildPtr() == NULL) {
      sub_tree_root_ptr = sub_tree_root_ptr->RightChildPtr();
    } else {
      sub_tree_root_ptr = sub_tree_root_ptr->LeftChildPtr();
    }

    delete delete_node_ptr;
    delete_node_ptr = NULL;

    return true;
  }
}


/**
 * @brief 清除子树(递归)
 * @tparam Elem 数据项类型模板
 * @tparam Key 关键码类型模板
 * @param sub_tree_root_ptr 子树根节点指针
 * @note
 * 如果sub_tree_root_ptr为NULL, 则递归结束
 * 对左右子树, 递归执行函数
 * 对子树节点执行delete和置NULL操作
 */
template <class Elem, class Key>
void BST<Elem, Key>::MakeEmptySubTree_(BSTNode<Elem, Key>*& sub_tree_root_ptr) {

  if (sub_tree_root_ptr == NULL) {
    return;
  }

  MakeEmptySubTree_(sub_tree_root_ptr->LeftChildPtr());
  MakeEmptySubTree_(sub_tree_root_ptr->RightChildPtr());

  delete sub_tree_root_ptr;
  sub_tree_root_ptr = NULL;
}


/**
 * @brief 打印子树(递归/中序)
 * @tparam Elem 数据项类型模板
 * @tparam Key 关键码类型模板
 * @param sub_tree_root_ptr 子树根节点指针
 * @param visit 访问函数
 * @note
 * 打印格式: "[子树根节点]([子树根节点左子树], [子树根节点右子树])"
 *
 * 1. 访问/打印子树根节点
 * 2. 打印“(”
 * 3. 访问/打印子树根节点的左子树
 * 4. 打印“,”
 * 5. 访问/打印子树根节点的右子树
 * 6. 打印“)”
 */
template <class Elem, class Key>
void BST<Elem, Key>::PrintSubTree_(BSTNode<Elem, Key>* sub_tree_root_ptr, void (*visit)(BSTNode<Elem, Key>*)) const {

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


/**
 * @brief 子树中关键码最小项
 * @tparam Elem 数据项模板类型
 * @tparam Key 关键码模板类型
 * @param sub_tree_root_ptr 子树根节点
 * @return 关键码最小项
 * @note
 * 左孩子节点迭代
 */
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


/**
 * @brief 子树中关键码最大项
 * @tparam Elem 数据项模板类型
 * @tparam Key 关键码模板类型
 * @param sub_tree_root_ptr 子树根节点
 * @return 关键码最大项
 * @note
 * 右孩子节点迭代
 */
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


template<class Elem, class Key>
BST<Elem, Key> &BST<Elem, Key>::operator=(const BST<Elem, Key> &R) {
  return *this;
}


#endif // CYBER_DASH_BINARY_SEARCH_TREE_H
