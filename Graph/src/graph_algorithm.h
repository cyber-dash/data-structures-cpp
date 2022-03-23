/*!
 * @file graph_algorithm.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 图算法.h文件
 * @version 0.2.1
 * @date 2021-02-04
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#ifndef CYBER_DASH_GRAPH_ALGORITHM_H
#define CYBER_DASH_GRAPH_ALGORITHM_H


#include <iostream>
#include "graph.h"
#include <set>
#include <queue>

#include "min_heap.h"
#include "disjoint_set.h"


using namespace std;


// 图深度优先遍历
template<class Vertex, class Weight>
void DFS(Graph<Vertex, Weight>& graph, const Vertex& vertex);


// 图深度优先遍历(递归)
template<class Vertex, class Weight>
void DFSOnVertex(Graph<Vertex, Weight>& graph, Vertex vertex, set<Vertex>& visited_vertex_set);


// 图广度优先遍历
template<class Vertex, class Weight>
void BFS(Graph<Vertex, Weight>& graph, const Vertex& vertex);


// 求图的连通分量
template<class Vertex, class Weight>
void Components(Graph<Vertex, Weight>& graph);


/*!
 * @brief 最小生成树结点结构体
 */
template<class V, class W>
struct MSTEdgeNode {
  /*! @brief 构造函数(空参数) */
  MSTEdgeNode() {}
  /*! @brief 构造函数() */
  MSTEdgeNode(W value): weight(value) {}
  /*! @brief 重载<= */
  bool operator<=(MSTEdgeNode<V, W>& node) { return weight <= node.weight; }
  /*! @brief 重载> */
  bool operator>(MSTEdgeNode<V, W>& node) { return weight > node.weight; }

  V tail; //!< 尾结点
  V head; //!< 头结点
  W weight; //!< 边权重
};


/*!
 * @brief 最小生成树模板类
 * @tparam Vertex 结点类型模板参数
 * @tparam Weight 边权值类型模板参数
 */
template<class Vertex, class Weight>
class MinSpanTree {
protected:
  MSTEdgeNode<Vertex, Weight>* edge_node_array_; //!< 最小生成树结点数组
  int max_size_; //!< 最大结点数
  int cur_size_; //!< 当前生成树的节点数量
public:
  // 构造函数
  MinSpanTree(int size): max_size_(size), cur_size_(0) {
    edge_node_array_ = new MSTEdgeNode<Vertex, Weight>[size];
  }

  // 向edge_node_array_插入结点
  int Insert(MSTEdgeNode<Vertex, Weight>& edge_node) {
    if (cur_size_ >= max_size_) {
      return -1;
    }

    edge_node_array_[cur_size_] = edge_node;
    cur_size_++;

    return cur_size_ - 1;
  }

  /*! @brief 显示最小生成树 */
  void Show() {
    Weight sum = 0;
    for (int i = 0; i < cur_size_; i++) {
      sum += edge_node_array_[i].weight;
      cout << "head: " << edge_node_array_[i].head << ", tail: " << edge_node_array_[i].tail << ", weight: "
           << edge_node_array_[i].weight << endl;
    }

    cout<<"最小生成树边, 总权值: "<<sum<<endl;
  }
};


// Kruskal最小生成树
template<class Vertex, class Weight>
void Kruskal(Graph<Vertex, Weight>& graph, MinSpanTree<Vertex, Weight>& min_span_tree);


// Prim(使用堆实现的优先队列)
template<class Vertex, class Weight>
void PrimByHeap(Graph<Vertex, Weight>& graph, Vertex vertex, MinSpanTree<Vertex, Weight>& min_span_tree);


// Prim算法朴素实现
template<class Vertex, class Weight>
void Prim(Graph<Vertex, Weight>& graph, Vertex vertex, MinSpanTree<Vertex, Weight>& min_span_tree);


// 迪杰斯特拉(Dijkstra)最短路径
template<class Vertex, class Weight>
void Dijkstra(Graph<Vertex, Weight>& graph, Vertex starting_vertex, Weight distance[], int predecessor[]);


// 显示迪杰斯特拉(Dijkstra)最短路径
template<class Vertex, class Weight>
void PrintShortestPath(Graph<Vertex, Weight>& graph, Vertex starting_vertex, Weight distance[], int predecessor[]);


// 贝尔曼福特(Bellman-Ford)最短路径
template<class Vertex, class Weight>
bool BellmanFord(Graph<Vertex, Weight>& graph, Vertex starting_vertex, Weight distance[], int predecessor[]);


#endif // CYBER_DASH_GRAPH_ALGORITHM_H
