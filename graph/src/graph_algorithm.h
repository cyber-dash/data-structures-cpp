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


/**
 * @brief 图深度优先遍历
 * @tparam T 结点模板类型
 * @tparam E 边模板类型
 * @param graph 图
 * @param vertex 遍历起始结点
 */
template<class T, class E>
void DFS(Graph<T, E>& graph, const T& vertex);


/**
 * @brief 图节点深度优先遍历(递归)
 * @tparam T 节点模板类型
 * @tparam E 边模板类型
 * @param graph 图
 * @param vertex 图节点
 * @param visited_vertex_set 已访问节点集合
 */
template<class T, class E>
void DFSOnVertex(Graph<T, E>& graph, T vertex, set<T>& visited_vertex_set);


/**
 * @brief 图广度优先遍历
 * @tparam T 结点模板类型
 * @tparam E 边模板类型
 * @param graph 图
 * @param vertex 遍历起始结点
 */
template<class T, class E>
void BFS(Graph<T, E>& graph, const T& vertex);


/**
 * @brief 求图的连通分量
 * @tparam T 结点模板类型
 * @tparam E 边模板类型
 * @param graph 图
 */
template<class T, class E>
void Components(Graph<T, E>& graph);


// const float MAX_VALUE = 10000000;


/**
 * @brief 最小生成树结点
 * @tparam T 结点模板类型
 * @tparam E 边模板类型
 */
template<class T, class E>
struct MSTEdgeNode {
  T tail; // 尾结点
  T head; // 头结点
  E weight; // 权重
  MSTEdgeNode() {}
  MSTEdgeNode(E value): weight(value) {}
  bool operator<=(MSTEdgeNode<T, E>& node) { return weight <= node.weight; }
  bool operator>(MSTEdgeNode<T, E>& node) { return weight > node.weight; }
};


/**
 * @brief 最小生成树
 * @tparam T 结点模板类型
 * @tparam E 边模板类型
 */
template<class T, class E>
class MinSpanTree {
protected:
  MSTEdgeNode<T, E>* edge_node_array_; // 最小生成树结点数组
  int max_size_;
  int cur_node_count_; // 当前生成树的节点数量
public:
  // 构造函数
  MinSpanTree(int size): max_size_(size), cur_node_count_(0) {
    edge_node_array_ = new MSTEdgeNode<T, E>[size];
  }

  // 向edge_node_array_插入结点
  int Insert(MSTEdgeNode<T, E>& edge_node) {
    if (cur_node_count_ >= max_size_) {
      return -1;
    }

    edge_node_array_[cur_node_count_] = edge_node;
    cur_node_count_++;

    return cur_node_count_ - 1;
  }

  // 显示最小生成树
  void Show() {
    E sum = 0;
    for (int i = 0; i < cur_node_count_; i++) {
      sum += edge_node_array_[i].weight;
      cout << "head: " << edge_node_array_[i].head << ", tail: " << edge_node_array_[i].tail << ", weight: "
           << edge_node_array_[i].weight << endl;
    }

    cout<<"最小生成树边, 总权值: "<<sum<<endl;
  }
};


/**
 * @brief Kruskal最小生成树
 * @tparam T 节点模板类型
 * @tparam E 边模板类型
 * @param graph 图
 * @param min_span_tree 最小生成树
 */
template<class T, class E>
void Kruskal(Graph<T, E>& graph, MinSpanTree<T, E>& min_span_tree);


template<class T, class E>
void Prim(Graph<T, E>& graph, T vertex, MinSpanTree<T, E>& min_span_tree);


/**
 * @brief Prim最小生成树
 * @tparam T 节点模板类型
 * @tparam E 边模板类型
 * @param graph 图
 * @param min_span_tree 最小生成树
 */
template<class T, class E>
void Prim2(Graph<T, E>& graph, T vertex, MinSpanTree<T, E>& min_span_tree);


/**
 * @brief Dijkstra最短路径
 * @tparam T 结点模板类型
 * @tparam E 边模板类型
 * @param graph 图
 * @param vertex 起始结点
 * @param dist
 * @param path
 */
template<class T, class E>
void DijkstraShortestPath(Graph<T, E>& graph, T vertex, E* dist, int* path);


/**
 * @brief 打印最短路径
 * @tparam T
 * @tparam E
 * @param graph
 * @param vertex
 * @param dist
 * @param path
 */
template<class T, class E>
void PrintShortestPath(Graph<T, E>& graph, T vertex, E dist[], int path[]);


#endif //CYBER_DASH_GRAPH_ALGORITHM_H