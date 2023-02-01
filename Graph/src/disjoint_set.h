/*!
 * @file disjoint_set.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 并查集.h文件
 * @version 0.2.1
 * @date 2021-02-21
 *
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#ifndef CYBER_DASH_DISJOINT_SET_H
#define CYBER_DASH_DISJOINT_SET_H


/*!
 * @brief 并查集类
 */
class DisjointSet {

public:
    // 构造函数
    explicit DisjointSet(int size);

    /*!
     * @brief **析构函数**
     * @note
     * 析构函数
     * -------
     * -------
     *
     * -------
     * 释放parent_
     */
    ~DisjointSet() { delete[] parent_; }

    // 合并
    void Union(int node1, int node2);

    // 查找
    int Find(int index);

    // 合并集合(Weighted)
    void WeightedUnion(int node1, int node2);

    // 查找(非递归)
    int FindNonRecursive(int index);
private:
    int size_;     //!< 大小
    int* parent_;  //!< 父节点数组
};


#endif //CYBER_DASH_DISJOINT_SET_H
