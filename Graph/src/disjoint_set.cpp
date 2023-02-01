/*!
 * @file disjoint_set.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 并查集.cpp文件
 * @version 0.2.1
 * @date 2021-02-21
 */

#include "disjoint_set.h"


/*!
 * @brief **构造函数**
 * @note
 * 构造函数
 * -------
 * -------
 *
 * -------
 */
DisjointSet::DisjointSet(int size) {
    size_ = size;
    this->parent_ = new int[this->size_];
    for (int i = 0; i < size; i++) {
        parent_[i] = -1;
    }
}


/*!
 * @brief **查找(非递归)**
 * @param index 数组索引
 * @return 根节点
 * @note
 * 查找(非递归)
 * ----------
 * ----------
 *
 * ----------
 */
int DisjointSet::FindNonRecursive(int index) {

    while (parent_[index] >= 0) {
        index = parent_[index];
    }

    return index;
}


/*!
 * @brief **查找(递归)**
 * @param index 数组索引
 * @return 根节点
 * @note
 * 查找(递归)
 * ---------
 * ---------
 *
 * ---------
 */
int DisjointSet::Find(int index) {
  if (parent_[index] < 0) {
    return index;
  }

  return Find(parent_[index]);
}


/**
 * @brief 合并集合(Weighted)
 * @param node1 结点1
 * @param node2 结点2
 * @note
 * 合并集合(Weighted)
 * -----------------
 * -----------------
 *
 * -----------------
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
 * @brief **合并**
 * @param node1 结点1
 * @param node2 结点2
 * @note
 * 合并
 * ----
 * ----
 *
 * ----
 * + **1 获取根结点**\n
 * &emsp; 获取node1的根结点root1\n
 * &emsp; 获取node2的根结点root2\n
 * + **2 判断是否已在同一集合**\n
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

