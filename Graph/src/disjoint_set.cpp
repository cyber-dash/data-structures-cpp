/*!
 * @file disjoint_set.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 并查集.cpp文件
 * @version 0.2.1
 * @date 2021-02-21
 *
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#include "disjoint_set.h"


/*!
 * @brief 构造函数
 * @param size 大小
 */
DisjointSet::DisjointSet(int size) {
  size_ = size;
  this->parent_ = new int[this->size_];
  for (int i = 0; i < size; i++) {
    parent_[i] = -1;
  }
}


/*!
 * @brief 重载=
 * @param disjoint_set 源并查集
 * @return 赋值后的并查集
 * @note
 *  todo: 未实现
 */
DisjointSet& DisjointSet::operator=(const DisjointSet& disjoint_set) {

  return *this;
}


/*!
 * @brief 查找(非递归)
 * @param value 数组索引
 * @return 根节点
 */
int DisjointSet::FindNonRecursive(int value) {

  while (parent_[value] >= 0) {
    value = parent_[value];
  }

  return value;
}


/*!
 * @brief 查找
 * @param value 数组索引
 * @return 根节点
 */
int DisjointSet::Find(int value) {
  if (parent_[value] < 0) {
    return value;
  } else {
    return Find(parent_[value]);
  }
}


/**
 * @brief 合并集合(Weighted)
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


/*!
 * @brief 查找(对原书进行优化)
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

