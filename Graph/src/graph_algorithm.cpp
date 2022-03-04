/*!
 * @file graph_algorithm.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 图算法.cpp文件
 * @version 0.2.1
 * @date 2021-02-04
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#include "graph_algorithm.h"
#include <iostream>


/*!
 * @brief 图深度优先遍历
 * @tparam T 结点类型模版参数
 * @tparam E 边权值类型模板参数
 * @param graph 图
 * @param vertex 遍历起始结点
 */
template<class T, class E>
void DFS(Graph<T, E>& graph, const T& vertex) {

  set<T> visited_vertex_set;

  DFSOnVertex(graph, vertex, visited_vertex_set);
}


/*!
 * @brief 图深度优先遍历(递归)
 * @tparam T 节点类型模板参数
 * @tparam E 边权值类型模板参数
 * @param graph 图
 * @param vertex 遍历起始结点
 * @param visited_vertex_set 已访问节点集合
 * @note 利用函数的调用关系来模拟栈
 */
template<class T, class E>
void DFSOnVertex(Graph<T, E>& graph, T vertex, set<T>& visited_vertex_set) {

  cout<<"Vertex: "<<vertex<<endl;

  visited_vertex_set.insert(vertex);

  T neighbor_vertex;
  bool has_neighbor = graph.GetFirstNeighborVertex(neighbor_vertex, vertex);

  while (has_neighbor) {
    if (visited_vertex_set.find(neighbor_vertex) == visited_vertex_set.end()) {
      DFSOnVertex(graph, neighbor_vertex, visited_vertex_set);
    }

    T next_neighbor_vertex;
    has_neighbor = graph.GetNextNeighborVertex(next_neighbor_vertex, vertex, neighbor_vertex);

    if (has_neighbor) {
      neighbor_vertex = next_neighbor_vertex;
    }
  }
}


/*!
 * @brief 图广度优先遍历
 * @tparam T 结点类型模板参数
 * @tparam E 边权值类型模板参数
 * @param graph 图
 * @param vertex 遍历起始结点
 * @note
 * 使用队列进行广度优先遍历
 */
template<class T, class E>
void BFS(Graph<T, E>& graph, const T& vertex) {

  set<T> visited_vertex_set;
  visited_vertex_set.insert(vertex);

  queue<T> vertex_queue;
  vertex_queue.push(vertex); // 遍历起始结点入队列

  cout<<"Vertex "<<vertex<<endl;

  while (!vertex_queue.empty()) {
    T front_vertex = vertex_queue.front(); // 每次取队头
    vertex_queue.pop();

    // 已取出的队头结点的相邻结点入队
    T neighbor_vertex;
    bool has_neighbor = graph.GetFirstNeighborVertex(neighbor_vertex, front_vertex);

    while (has_neighbor) {
      if (visited_vertex_set.find(neighbor_vertex) == visited_vertex_set.end()) {
        cout<<"Vertex "<<neighbor_vertex<<endl;

        visited_vertex_set.insert(neighbor_vertex);

        vertex_queue.push(neighbor_vertex);
      }

      T next_neighbor_vertex;
      has_neighbor = graph.GetNextNeighborVertex(next_neighbor_vertex, front_vertex, neighbor_vertex);
      neighbor_vertex = next_neighbor_vertex;
    }
  }
}


/*!
 * @brief 求图的连通分量
 * @tparam T 结点类型模板参数
 * @tparam E 边权值类型模板参数
 * @param graph 图
 * @note
 * 1. 使用visited_vertex_set保存已经遍历过的节点
 * 2. 每遍历一个节点vertex
 *   如果在visited_vertex_set中, 则已经在某连通分量中, 不再处理;
 *   如果不在visited_vertex_set中, 使用DFS对vertex进行遍历, 连通分量数量+1
 */
template<class T, class E>
void Components(Graph<T, E>& graph) {

  int vertices_num = graph.NumberOfVertices(); // 图内节点的数量
  set<T> visited_vertex_set; // 使用set保存已经遍历过的节点

  int component_index = 1; // 初始连通分量为1

  for (int i = 0; i < vertices_num; i++) {

    T vertex;
    bool done = graph.GetVertexByIndex(vertex, i); // 获取索引i对应的节点vertex

    if (done) {
      // 如果visited_vertex_set中, 没有查到vertex, 说明vertex在一个新的联通分量中
      // 对vertex执行DFS遍历(书中的算法, 使用BFS也可以)
      if (visited_vertex_set.find(vertex) == visited_vertex_set.end()) {
        cout<<"连通分量"<<component_index<<":"<<endl;
        DFSOnVertex(graph, vertex, visited_vertex_set);

        component_index++; // 连通分量数量+1
        cout<<endl;
      }
    }
  }
}


/*!
 * @brief Kruskal算法
 * @tparam T 结点类型模板参数
 * @tparam E 边权值类型模板参数
 * @param graph 图
 * @param min_span_tree 最小生成树
 */
template<class T, class E>
void Kruskal(Graph<T, E>& graph, MinSpanTree<T, E>& min_span_tree) {

  MSTEdgeNode<T, E> edge_node;

  int vertex_num = graph.NumberOfVertices();
  int edge_num = graph.NumberOfEdges();

  MinHeap<MSTEdgeNode<T, E> > min_heap(edge_num);

  DisjointSet disjoint_set(vertex_num);

  for (int u = 0; u < vertex_num; ++u) {
    for (int v = u + 1; v < vertex_num; v++) {
      T vertex_u;
      T vertex_v;
      graph.GetVertexByIndex(vertex_u, u);
      graph.GetVertexByIndex(vertex_v, v);

      E weight;
      bool get_weight_done = graph.GetWeight(weight, vertex_u, vertex_v);
      if (get_weight_done) {
        edge_node.tail = vertex_u;
        edge_node.head = vertex_v;
        edge_node.weight = weight;

        min_heap.Insert(edge_node);
      }

    }
  }

  int count = 1;

  while (count < vertex_num) {
    min_heap.RemoveMin(edge_node);


    int tail_idx = graph.GetVertexIndex(edge_node.tail);
    int head_idx = graph.GetVertexIndex(edge_node.head);

    int tail_root_idx = disjoint_set.Find(tail_idx);
    int head_root_idx = disjoint_set.Find(head_idx);

    if (tail_root_idx != head_root_idx) {
      disjoint_set.Union(tail_root_idx, head_root_idx);

      min_span_tree.Insert(edge_node);
      count++;
    }
  }
}


/*!
 * @brief Prim算法(优化)
 * @tparam T 结点类型模板参数
 * @tparam E 边权值类型模板参数
 * @param graph 图
 * @param vertex 起始节点(起始可以不用这个参数, 参考教科书, 此处保留)
 * @param min_span_tree 最小生成树
 * @note
 * 殷人昆版教材的实现, 此为经过优化的版本, 优化点在堆的操作
 */
template<class T, class E>
void PrimPlus(Graph<T, E>& graph, T vertex, MinSpanTree<T, E>& min_span_tree) {

  MSTEdgeNode<T, E> mst_edge_node;

  int count = 1; // 起始vertex进入mst节点集合, count=1
  int vertex_num = graph.NumberOfVertices();
  int edge_num = graph.NumberOfEdges();

  MinHeap<MSTEdgeNode<T, E> > min_heap(edge_num);

  set<T> mst_vertex_set; // 原书中的Vmst
  mst_vertex_set.insert(vertex);

  do {
    T neighbor_vertex;
    bool has_neighbor = graph.GetFirstNeighborVertex(neighbor_vertex, vertex);

    while (has_neighbor) {
      if (mst_vertex_set.find(neighbor_vertex) == mst_vertex_set.end()) {

        mst_edge_node.tail = vertex;
        mst_edge_node.head = neighbor_vertex;

        graph.GetWeight(mst_edge_node.weight, vertex, neighbor_vertex);

        min_heap.Insert(mst_edge_node);
      }

      T next_neighbor_vertex;
      has_neighbor = graph.GetNextNeighborVertex(next_neighbor_vertex, vertex, neighbor_vertex);

      if (has_neighbor) {
        neighbor_vertex = next_neighbor_vertex;
      }
    }

    while (min_heap.IsEmpty() == false && count < vertex_num) {

      min_heap.RemoveMin(mst_edge_node);

      if (mst_vertex_set.find(mst_edge_node.head) == mst_vertex_set.end()) {
        min_span_tree.Insert(mst_edge_node);

        vertex = mst_edge_node.head;
        mst_vertex_set.insert(vertex);
        count++;

        break;
      }
    }
  } while (count < vertex_num);
}


/*!
 * @brief Prim算法实现
 * @tparam Vertex 结点类型模板参数
 * @tparam Weight 边权值类型模板参数
 * @param graph 图
 * @param vertex 起始节点(其实可以不用这个参数, 参照教科书, 此处保留)
 * @param min_span_tree 最小生成树
 */
template<class Vertex, class Weight>
void Prim(Graph<Vertex, Weight>& graph, Vertex vertex, MinSpanTree<Vertex, Weight>& min_span_tree) {

  MSTEdgeNode<Vertex, Weight> mst_edge_node;

  int count = 1; // 起始vertex进入mst节点集合, count=1
  int vertex_num = graph.NumberOfVertices();
  int edge_num = graph.NumberOfEdges();

  set<Vertex> mst_vertex_set; // 原书中的Vmst
  mst_vertex_set.insert(vertex);

  do {

    MinHeap<MSTEdgeNode<Vertex, Weight> > min_heap(edge_num);

    for (typename set<Vertex>::iterator set_iter = mst_vertex_set.begin(); set_iter != mst_vertex_set.end(); set_iter++) {
      vertex = *set_iter;

      Vertex neighbor_vertex;
      bool has_neighbor = graph.GetFirstNeighborVertex(neighbor_vertex, vertex);

      while (has_neighbor) {
        if (mst_vertex_set.find(neighbor_vertex) == mst_vertex_set.end()) {

          mst_edge_node.tail = vertex;
          mst_edge_node.head = neighbor_vertex;

          graph.GetWeight(mst_edge_node.weight, vertex, neighbor_vertex);

          min_heap.Insert(mst_edge_node);
        }

        Vertex next_neighbor_vertex;
        has_neighbor = graph.GetNextNeighborVertex(next_neighbor_vertex, vertex, neighbor_vertex);

        if (has_neighbor) {
          neighbor_vertex = next_neighbor_vertex;
        }
      }
    }

    min_heap.RemoveMin(mst_edge_node);

    min_span_tree.Insert(mst_edge_node);

    vertex = mst_edge_node.head;
    mst_vertex_set.insert(vertex);
    count++;

  } while (count < vertex_num);
}


/**
 * @brief 迪杰斯特拉(Dijkstra)最短路径
 * @tparam Vertex 图节点模板类型
 * @tparam Weight 图边权值模板类型
 * @param graph 图类型
 * @param origin_vertex 起始节点
 * @param min_dist_arr 最短路径数组, dist[i]表示: 路径起始节点到索引i节点的最短路径的权值
 * @param from_path_arr 路径数组, from_path_arr[i]表示: 以索引i节点为终点的边的起始节点
 * @note 贪心算法
 */
template<class Vertex, class Weight>
void DijkstraShortestPath(Graph<Vertex, Weight>& graph,
                          Vertex origin_vertex,
                          Weight min_dist_arr[],
                          int from_path_arr[])
{
  int vertex_num = graph.NumberOfVertices();
  set<Vertex> vertex_set;
  int origin_vertex_idx = graph.GetVertexIndex(origin_vertex); // origin_vertex节点的索引

  // 初始化
  for (int i = 0; i < vertex_num; i++) {

    // 获取索引i对应的节点vertex_i
    Vertex vertex_i;
    bool get_vertex_done = graph.GetVertexByIndex(vertex_i, i);
    /* error handler */

    // 将边(origin_vertex --> vertex_i)的值, 保存到min_dist_arr[i], 如果不存在, 则min_dist_arr[i]为MAX_WEIGHT
    bool get_weight_done = graph.GetWeight(min_dist_arr[i], origin_vertex, vertex_i);
    if (!get_weight_done) {
      min_dist_arr[i] = (Weight)MAX_WEIGHT;
    }

    // 如果边(origin_vertex --> vertex_i)存在, 则from_path_arr[i]的值, 为索引origin_vertex_idx; 否则为-1
    if (vertex_i != origin_vertex && get_weight_done && get_vertex_done) {
      from_path_arr[i] = origin_vertex_idx;
    } else {
      from_path_arr[i] = -1;
    }
  }

  // 节点origin_vertex加入到集合vertex_set
  vertex_set.insert(origin_vertex);
  min_dist_arr[origin_vertex_idx] = 0;

  // 将图中其他vertex_num - 1个节点, 按照贪心策略, 执行算法, 并加入到集合vertex_set
  for (int i = 0; i < vertex_num - 1; i++) {
    Weight cur_min_dist = (Weight)MAX_WEIGHT; // 以origin_vertex为起点, 某个节点为终点的最短路径(当前最短路径)
    Vertex cur_min_dist_dest_vertex; // 当前最短路径的终点

    // 原点到各节点中的最短路径, 保存到cur_min_dist(当前最短路径), 并更新cur_min_dist_dest_vertex(当前最短路径终点)
    for (int j = 0; j < vertex_num; j++) {

      // 拿到索引j对应的节点vertex_j
      Vertex vertex_j;
      graph.GetVertexByIndex(vertex_j, j);
      /* error handler */

      // 如果idx_j_vertex已经在vertex_set中, continue
      if (vertex_set.find(vertex_j) != vertex_set.end()) {
        continue;
      }

      if (min_dist_arr[j] < cur_min_dist)
      {
        cur_min_dist_dest_vertex = vertex_j;
        cur_min_dist = min_dist_arr[j];
      }
    }

    vertex_set.insert(cur_min_dist_dest_vertex); // 将cur_min_dist_dest_vertex插入到vertex_set

    int cur_min_dist_dest_vertex_idx = graph.GetVertexIndex(cur_min_dist_dest_vertex);

    // Dijkstra核心算法
    for (int j = 0; j < vertex_num; j++) {
      Vertex vertex_j;
      graph.GetVertexByIndex(vertex_j, j);
      /* error handler */

      // 如果idx_j_vertex已经在vertex_set中, continue
      if (vertex_set.find(vertex_j) != vertex_set.end()) {
        continue;
      }

      // 边(cur_min_dist_dest_vertex --> vertex_j)的值, 赋给weight
      Weight weight;
      bool get_weight_done = graph.GetWeight(weight, cur_min_dist_dest_vertex, vertex_j);
      if (!get_weight_done) {
        continue; // 如果没有边
      }

      // 如果
      // 边(origin_vertex --> cur_min_dist_dest_vertex)的weight
      //  +
      // 边(cur_min_dist_dest_vertex --> dix_j_vertex)的weight(也就是变量weight)
      //  <
      // 边(origin_vertex --> dix_j_vertex)的weight
      // 更新min_dist_arr[j]和from_path_arr[j]
      if (min_dist_arr[cur_min_dist_dest_vertex_idx] + weight < min_dist_arr[j])
      {
        min_dist_arr[j] = min_dist_arr[cur_min_dist_dest_vertex_idx] + weight;
        from_path_arr[j] = cur_min_dist_dest_vertex_idx;
      }
    }
  }
}


/*!
 * @brief 显示迪杰斯特拉(Dijkstra)最短路径
 * @tparam T 结点类型模板参数
 * @tparam E 边权值类型模板参数
 * @param graph 图类型
 * @param origin_vertex 路径起始节点
 * @param min_dist_arr 最短路径数组, dist[i]表示: 路径起始节点到索引i节点的最短路径的权值
 * @param from_path_arr 路径数组, from_path_arr[i]表示: 以索引i节点为终点的边的起始节点
 */
template<class T, class E>
void PrintDijkstraShortestPath(Graph<T, E>& graph, T origin_vertex, E min_dist_arr[], int from_path_arr[]) {
  cout << "从顶点" << origin_vertex << "到其他各顶点的最短路径为: " << endl;

  int vertex_count = graph.NumberOfVertices();
  int origin_vertex_idx = graph.GetVertexIndex(origin_vertex);

  // 用于存放以某个节点为终点的最短路径经过的节点
  int* cur_pre_path_arr = new int[vertex_count];
  /* error handler */

  // 分别显示origin_vertex到各个节点的最短路径
  for (int i = 0; i < vertex_count; i++) {
    if (i == origin_vertex_idx) {
      continue;
    }

    int pre_vertex_idx = i; // 以索引i节点为终点
    int idx = 0;

    while (pre_vertex_idx != origin_vertex_idx) {
      cur_pre_path_arr[idx] = pre_vertex_idx;
      idx++;
      pre_vertex_idx = from_path_arr[pre_vertex_idx];
    }

    // 获取索引i的节点
    T idx_i_vertex;
    graph.GetVertexByIndex(idx_i_vertex, i);

    cout << "顶点" << idx_i_vertex << "的最短路径为:" << origin_vertex << " ";

    while (idx > 0) {
      idx--;
      graph.GetVertexByIndex(idx_i_vertex, cur_pre_path_arr[idx]);
      cout << idx_i_vertex << " ";
    }

    cout << "最短路径长度为:" << min_dist_arr[i] << endl;
  }

  delete[] cur_pre_path_arr;
}


