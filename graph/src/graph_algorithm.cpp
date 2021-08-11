//
// Created by cyberdash@163.com(抖音id:cyberdash_yuan) on 2021/2/4.
//

#include "graph_algorithm.h"
#include <iostream>


/**
 * @brief 图深度优先遍历
 * @tparam T 结点模板类型
 * @tparam E 边模板类型
 * @param graph 图
 * @param vertex 遍历起始结点
 */
template<class T, class E>
void DFS(Graph<T, E>& graph, const T& vertex) {

  set<T> visited_vertex_set;

  DFSOnVertex(graph, vertex, visited_vertex_set);
}


/**
 * @brief 图节点深度优先遍历(递归)
 * @tparam T 节点模板类型
 * @tparam E 边模板类型
 * @param graph 图
 * @param vertex 图节点
 * @param visited_vertex_set 已访问节点集合
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


/**
 * @brief 图广度优先遍历
 * @tparam T 结点模板类型
 * @tparam E 边模板类型
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


/**
 * @brief 求图的连通分量
 * @tparam T 结点模板类型
 * @tparam E 边模板类型
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


/**
 * @brief 殷人昆版教材的实现, 此为经过优化的版本, 优化点在堆的操作
 * @tparam T 图节点数据模板类型
 * @tparam E 边模板类型
 * @param graph 图
 * @param vertex 起始节点(起始可以不用这个参数, 参考教科书, 此处保留)
 * @param min_span_tree 最小生成树
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


/**
 * @brief Prim算法朴素实现
 * @tparam T 图节点数据模板类型
 * @tparam E 边模板类型
 * @param graph 图
 * @param vertex 起始节点(其实可以不用这个参数, 参照教科书, 此处保留)
 * @param min_span_tree 最小生成树
 */
template<class T, class E>
void Prim(Graph<T, E>& graph, T vertex, MinSpanTree<T, E>& min_span_tree) {

  MSTEdgeNode<T, E> mst_edge_node;

  int count = 1; // 起始vertex进入mst节点集合, count=1
  int vertex_num = graph.NumberOfVertices();
  int edge_num = graph.NumberOfEdges();

  set<T> mst_vertex_set; // 原书中的Vmst
  mst_vertex_set.insert(vertex);

  do {

    MinHeap<MSTEdgeNode<T, E> > min_heap(edge_num);

    for (typename set<T>::iterator set_iter = mst_vertex_set.begin(); set_iter != mst_vertex_set.end(); set_iter++) {
      vertex = *set_iter;

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
    }

    min_heap.RemoveMin(mst_edge_node);

    min_span_tree.Insert(mst_edge_node);

    vertex = mst_edge_node.head;
    mst_vertex_set.insert(vertex);
    count++;

  } while (count < vertex_num);
}


/**
 * @brief
 * @tparam T
 * @tparam E
 * @param graph
 * @param origin_vertex
 * @param min_dist_arr 数组, dist[i]表示源点v0到vi的距离长度
 * @param from_path_arr
 * @note
 */
template<class T, class E>
void DijkstraShortestPath(Graph<T, E>& graph, T origin_vertex, E* min_dist_arr, int* from_path_arr) {

  int vertex_num = graph.NumberOfVertices();
  set<T> vertex_set;
  int origin_vertex_idx = graph.GetVertexIndex(origin_vertex); // origin_vertex节点的索引

  // 初始化
  for (int i = 0; i < vertex_num; i++) {

    // 获取索引i对应的节点idx_i_vertex
    T idx_i_vertex;
    bool get_vertex_done = graph.GetVertexByIndex(idx_i_vertex, i);
    /* error handler */

    // 将边(origin_vertex --> idx_i_vertex)的值, 保存到min_dist_arr[i]
    // 如果边(origin_vertex --> idx_i_vertex)不存在, 则min_dist_arr[i]为MAX_WEIGHT
    bool get_weight_done = graph.GetWeight(min_dist_arr[i], origin_vertex, idx_i_vertex);
    if (!get_weight_done) {
      min_dist_arr[i] = (E)MAX_WEIGHT;
    }

    // 如果边(origin_vertex --> idx_i_vertex)存在,
    // 则from_path_arr[i]的值, 为索引origin_vertex_idx; 否则为-1
    if (idx_i_vertex != origin_vertex && get_weight_done && get_vertex_done) {
      from_path_arr[i] = origin_vertex_idx;
    } else {
      from_path_arr[i] = -1;
    }
  }

  // 节点vertex加入到集合vertex_set
  vertex_set.insert(origin_vertex);
  min_dist_arr[origin_vertex_idx] = 0;

  // 将图中其他节点, 按照算法, 依次加入到集合vertex_set, 并且按照最短路径状态方程, 执行算法
  for (int i = 0; i < vertex_num - 1; i++) {
    E cur_min_dist = (E)MAX_WEIGHT; // 以origin_vertex为起点, 某个节点为终点的边中, 的最短路径(当前最短路径)
    T cur_min_dist_dest_vertex = origin_vertex; // 当前最短路径的终点

    // 找到当前到各个节点中的最短路径, 保存到cur_min_dist
    // 并更新cur_min_dist_dest_vertex
    for (int j = 0; j < vertex_num; j++) {

      // 拿到索引j对应的节点idx_j_vertex
      T idx_j_vertex;
      bool get_vertex_done = graph.GetVertexByIndex(idx_j_vertex, j);
      /* error handler */

      // 如果idx_j_vertex已经在vertex_set中, continue
      if (vertex_set.find(idx_j_vertex) != vertex_set.end()) {
        continue;
      }

      if (min_dist_arr[j] < cur_min_dist)
      {
        cur_min_dist_dest_vertex = idx_j_vertex;
        cur_min_dist = min_dist_arr[j];
      }
    }

    vertex_set.insert(cur_min_dist_dest_vertex); // 将cur_min_dist_dest_vertex插入到vertex_set

    int cur_min_dist_dest_vertex_idx = graph.GetVertexIndex(cur_min_dist_dest_vertex);

    // Dijkstra核心算法
    for (int j = 0; j < vertex_num; j++) {
      T idx_j_vertex;
      bool get_vertex_done = graph.GetVertexByIndex(idx_j_vertex, j);
      /* error handler */

      // 如果idx_j_vertex已经在vertex_set中, continue
      if (vertex_set.find(idx_j_vertex) != vertex_set.end()) {
        continue;
      }

      // 边(cur_min_dist_dest_vertex --> idx_j_vertex)的值, 赋给weight
      E weight;
      bool get_weight_done = graph.GetWeight(weight, cur_min_dist_dest_vertex, idx_j_vertex);
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


template<class T, class E>
void PrintShortestPath(Graph<T, E>& graph, T vertex, E* dist, int* from_path) {
  cout<<"从顶点"<<vertex<<"到其他各顶点的最短路径为: "<<endl;

  int vertex_num = graph.NumberOfVertices();
  int vertex_index = graph.GetVertexIndex(vertex);

  int* vertex_idx_arr = new int[vertex_num];

  for (int i = 0; i < vertex_num; i++) {
    if (i != vertex_index) {
      int j = i;
      int vertex_idx = 0;

      while (j != vertex_index) {
        vertex_idx_arr[vertex_idx++] = j;
        j = from_path[j];
      }

      T cur_vertex;
      graph.GetVertexByIndex(cur_vertex, i);
      cout<<"顶点"<<cur_vertex<<"的最短路径为:"<<vertex<<" ";
      while (vertex_idx > 0) {
        graph.GetVertexByIndex(cur_vertex, vertex_idx_arr[--vertex_idx]);
        cout<<cur_vertex<<" ";
      }

      cout<<"最短路径长度为:"<<dist[i]<<endl;
    }
  }

  delete[] vertex_idx_arr;
}


