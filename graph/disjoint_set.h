//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2021/2/21.
//

#ifndef CYBER_DASH_DISJOINT_SET_H
#define CYBER_DASH_DISJOINT_SET_H


class DisjointSet {

public:
  DisjointSet(int size);
  ~DisjointSet() { delete[] parent_; }

  void Union(int root1, int root2);
  DisjointSet& operator=(const DisjointSet& disjoint_set);
  int Find(int value);
  XZ
};


#endif //CYBER_DASH_DISJOINT_SET_H
