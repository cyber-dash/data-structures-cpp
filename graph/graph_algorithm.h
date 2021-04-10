//
// Created by cyberdash@163.com(抖音id:cyberdash_yuan) on 2021/2/4.
//

#ifndef CYBER_DASH_GRAPH_ALGORITHM_H
#define CYBER_DASH_GRAPH_ALGORITHM_H


#include <iostream>
#include "graph.h"
#include <set>
#include <queue>

#include "min_heap.h"
#include "disjoint_set.h"

using namespace std;


template<class T, class E>
void DFS(Graph<T, E>& graph, const T& vertex);


template<class T, class E>
void DFSOnVertex(Graph<T, E>& graph, T vertex, set<T>& visited_vertex_set);


template<class T, class E>
void BFS(Graph<T, E>& graph, const T& vertex);


template<class T, class E>
void Components(Graph<T, E>& graph);


const float MAX_VALUE = 10000000;

template<class T, class E>
struct MSTEdgeNode {
  T tail;
  T head;
  E weight_;
  MSTEdgeNode() {}
  MSTEdgeNode(E value): weight_(value) {}
  bool operator<=(MSTEdgeNode<T, E>& node) { return weight_ <= node.weight_; }
  bool operator>(MSTEdgeNode<T, E>& node) { return weight_ > node.weight_; }
};


template<class T, class E>
class MinSpanTree {
protected:
  MSTEdgeNode<T, E>* edge_node_ptr_;
  int max_size_;
  int current_count_;
public:
  MinSpanTree(int size): max_size_(size), current_count_(0) {
    edge_node_ptr_ = new MSTEdgeNode<T, E>[size];
  }

  int Insert(MSTEdgeNode<T, E>& edge_node) {
    if (current_count_ >= max_size_) {
      return -1;
    }

    edge_node_ptr_[current_count_] = edge_node;
    current_count_++;

    return current_count_ - 1;
  }

  void Show() {
    for (int i = 0; i < current_count_; i++) {
      cout<<"head: "<<edge_node_ptr_[i].head<<", tail: "<<edge_node_ptr_[i].tail<<", weight: "
        <<edge_node_ptr_[i].weight_<<endl;
    }
  }
};


template<class T, class E>
void Kruskal(Graph<T, E>& graph, MinSpanTree<T, E>& min_span_tree);


template<class T, class E>
void Prim(Graph<T, E>& graph, T vertex, MinSpanTree<T, E>& min_span_tree);


template<class T, class E>
void ShortestPath(Graph<T, E>& graph, T vertex, E dist[], int path[]);


template<class T, class E>
void PrintShortestPath(Graph<T, E>& graph, T vertex, E dist[], int path[]);



#endif //CYBER_DASH_GRAPH_ALGORITHM_H
