/*!
 * @file disjoint_set.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 并查集.cpp文件
 * @version 0.2.1
 * @date 2021-02-21
 */

#include "disjoint_set.h"


/*!
 * @brief **构造函数(size)**
 * @note
 * 构造函数(size)
 * -------------
 * -------------
 *
 * -------------
 * size_赋值\n
 * parent_分配内存\n
 * **for loop** 遍历parents_ :\n
 * &emsp; parents_[i]初始化为-1(本身为1个并查集, 自己为自身并查集的根结点)\n
 */
DisjointSet::DisjointSet(int size) {
    size_ = size;                                                                       // size_赋值
    this->parents_ = new int[this->size_];                                              // parent_分配内存
    for (int i = 0; i < size; i++) {                                                    // for loop** 遍历parents_
        parents_[i] = -1;                                                               // parents_[i]初始化为-1(本身为1个并查集, 自己为自身并查集的根结点)
    }
}


/*!
 * @brief **查找**
 * @param index 数组索引
 * @return 根结点
 * @note
 * 查找
 * ---
 * ---
 *
 * ---
 * **while loop** index存在父结点 :\n
 * &emsp; index更新为父结点索引值\n\n
 * 返回index\n
 */
int DisjointSet::Find(int index) {

    while (parents_[index] >= 0) {                                                      // while loop index存在父结点
        index = parents_[index];                                                        // index更新为父结点索引值
    }

    return index;                                                                       // 返回index
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
 * **if** index结点没有父结点 :\n
 * &emsp; 返回index\n\n
 * 返回FindRecursive(parents_[index])\n
 */
int DisjointSet::FindRecursive(int index) {
  if (parents_[index] < 0) {                                                            // if index结点没有父结点
    return index;                                                                       // 返回index
  }

  return FindRecursive(parents_[index]);                                                // 返回FindRecursive(parents_[index])
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
 * + **1 获取各自的根结点**\n\n
 * 获取root1(node1的并查集根结点索引)\n
 * 获取root2(node2的并查集根结点索引)\n\n
 * + **2 判断是否已经合并**\n\n
 * **if** root1等于root2: \n
 * &emsp; 退出函数\n\n
 * + **3 合并**\n\n
 * 计算new_weight\n\n
 * **if** node2对应的并查集 比 node1对应的并查集 的结点数量多 :\n
 * &emsp; root1结点的父结点设为root2\n
 * &emsp; root2对应的并查集的weight更新为new_weight\n
 * **else**\n
 * &emsp; root2结点的父结点设为root1\n
 * &emsp; root1对应的并查集的weight更新为new_weight\n
 */
void DisjointSet::WeightedUnion(int node1, int node2) {
    // ---------- 1 获取各自的根结点 ----------

    int root1 = FindRecursive(node1);                                                   // 获取root1(node1的并查集根结点索引)
    int root2 = FindRecursive(node2);                                                   // 获取root2(node2的并查集根结点索引)

    // ---------- 2 判断是否已经合并 ----------

    if (root1 == root2) {                                                               // if root1等于root2
        return;                                                                         // 退出函数
    }

    // ---------- 3 合并 ----------

    int new_weight = parents_[root1] + parents_[root2];                                 // 计算new_weight

    if (parents_[root2] < parents_[root1]) {                                            // if node2对应的并查集 比 node1对应的并查集 的结点数量多
        parents_[root1] = root2;                                                        // root1结点的父结点设为root2
        parents_[root2] = new_weight;                                                   // root2对应的并查集的weight更新为new_weight
    } else {
        parents_[root2] = root1;                                                        // root2结点的父结点设为root1
        parents_[root1] = new_weight;                                                   // root1对应的并查集的weight更新为new_weight
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
 * + **2 判断是否已经合并**\n
 * **if** root1等于root2: \n
 * &emsp; 退出函数\n\n
 * + **3 合并**\n\n
 * parents_[root1]更新(root1作为合并后集合的根结点)\n
 * root1成为结点root2的父结点\n
 */
void DisjointSet::Union(int node1, int node2) {

    // ---------- 1 获取根结点 ----------

    int root1 = FindRecursive(node1);                                                   // 获取node1的根结点root1
    int root2 = FindRecursive(node2);                                                   // 获取node2的根结点root2

    // ---------- 2 判断是否已经合并 ----------

    if (root1 == root2) {                                                               // if root1等于root2
        return;                                                                         // 退出函数
    }

    // ---------- 3 合并 ----------

    parents_[root1] += parents_[root2];                                                 // parents_[root1]更新(root1作为合并后集合的根结点)
    parents_[root2] = root1;                                                            // root1成为结点root2的父结点
}

