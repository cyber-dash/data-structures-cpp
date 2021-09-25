//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2021/2/21.
//

#ifndef CYBER_DASH_DISJOINT_SET_H
#define CYBER_DASH_DISJOINT_SET_H


const int DEFAULT_SIZE = 10;


class DisjointSet {

public:
  DisjointSet(int size = DEFAULT_SIZE);
  ~DisjointSet() { delete[] parent_; }

  void Union(int root1, int root2);
  DisjointSet& operator=(const DisjointSet& disjoint_set);
  int Find(int value);
  int FindNonRecursive(int value);
  void WeightedUnion(int node1, int node2);

private:
  int* parent_;
  int size_;
};


#endif //CYBER_DASH_DISJOINT_SET_H
