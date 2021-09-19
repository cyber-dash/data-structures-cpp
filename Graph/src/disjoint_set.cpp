//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2021/2/21.
//

#include "disjoint_set.h"


DisjointSet::DisjointSet(int size) {
  size_ = size;
  this->parent_ = new int[this->size_];
  for (int i = 0; i < size; i++) {
    parent_[i] = -1;
  }
}


DisjointSet& DisjointSet::operator=(const DisjointSet& disjoint_set) {

  return *this;
}


int DisjointSet::FindNonRecursive(int value) {

  while (parent_[value] >= 0) {
    value = parent_[value];
  }

  return value;
}


int DisjointSet::Find(int value) {
  if (parent_[value] < 0) {
    return value;
  } else {
    return Find(parent_[value]);
  }
}


/**
 *
 * @param node1
 * @param node2
 */
void DisjointSet::WeightedUnion(int node1, int node2) {
  int root1 = Find(node1);
  int root2 = Find(node2);

  if (root1 == root2) {
    return;
  }

  int weighted_union_root = parent_[root1] + parent_[root2];

  if (parent_[root2] < parent_[root1]) {
    parent_[root1] = root2;
    parent_[root2] = weighted_union_root;
  } else {
    parent_[root2] = root1;
    parent_[root1] = weighted_union_root;
  }
}


/**
 * 对原书进行优化
 * @param node1
 * @param node2
 */
void DisjointSet::Union(int node1, int node2) {
  int root1 = Find(node1);
  int root2 = Find(node2);

  if (root1 == root2) {
    return;
  }

  parent_[root1] += parent_[root2];
  parent_[root2] = root1; // 将根root2连接到另一根root1下面
}

