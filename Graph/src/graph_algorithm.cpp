/*!
 * @file graph_algorithm.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 图算法.cpp文件
 * @version 0.2.1
 * @date 2021-02-04
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include "graph_algorithm.h"
#include "priority_queue.h"
#include "disjoint_set.h"


/*!
 * @brief 图深度优先遍历
 * @tparam Vertex 结点模版参数
 * @tparam Weight 边权值模板参数
 * @param graph 图的引用
 * @param vertex 遍历起始结点
 */
template<class Vertex, class Weight>
void DFS(Graph<Vertex, Weight>& graph, const Vertex& vertex) {

  set<Vertex> visited_vertex_set;

  DFSOnVertex(graph, vertex, visited_vertex_set);
}


/*!
 * @brief 图深度优先遍历(递归)
 * @tparam Vertex 结点模板参数
 * @tparam Weight 边权值模板参数
 * @param graph 图
 * @param vertex 遍历起始结点
 * @param visited_vertex_set 已访问结点集合
 * @note 利用函数的调用关系来模拟栈
 */
template<class Vertex, class Weight>
void DFSOnVertex(Graph<Vertex, Weight>& graph, Vertex vertex, set<Vertex>& visited_vertex_set) {

  cout<<"访问结点: "<<vertex<<endl;

  visited_vertex_set.insert(vertex);

  Vertex neighbor_vertex;
  bool has_neighbor = graph.GetFirstNeighborVertex(neighbor_vertex, vertex);

  while (has_neighbor) {
    if (visited_vertex_set.find(neighbor_vertex) == visited_vertex_set.end()) {
      DFSOnVertex(graph, neighbor_vertex, visited_vertex_set);
    }

    Vertex next_neighbor_vertex;
    has_neighbor = graph.GetNextNeighborVertex(next_neighbor_vertex, vertex, neighbor_vertex);

    if (has_neighbor) {
      neighbor_vertex = next_neighbor_vertex;
    }
  }
}


/*!
 * @brief 图广度优先遍历
 * @tparam Vertex 结点模板参数
 * @tparam Weight 边权值模板参数
 * @param graph 图的引用
 * @param vertex 遍历起始结点
 * @note
 * 使用队列进行广度优先遍历
 */
template<class Vertex, class Weight>
void BFS(Graph<Vertex, Weight>& graph, const Vertex& vertex) {

  cout<<"访问结点: "<<vertex<<endl;

  set<Vertex> visited_vertex_set;       // 已访问结点集合
  visited_vertex_set.insert(vertex);    // 插入已访问的起始结点vertex

  queue<Vertex> vertex_queue;           // 结点队列
  vertex_queue.push(vertex);            // 已访问的起始结点vertex入队

  while (!vertex_queue.empty()) {
    Vertex front_vertex = vertex_queue.front(); // 每次取队头
    vertex_queue.pop();

    // 遍历:已取出的队头结点的相邻结点
    //     如果未访问该结点:
    //         入队
    Vertex neighbor_vertex;
    bool has_neighbor = graph.GetFirstNeighborVertex(neighbor_vertex, front_vertex);
    while (has_neighbor) {
      if (visited_vertex_set.find(neighbor_vertex) == visited_vertex_set.end()) {   // 如果未访问
        cout<<"访问结点: "<<neighbor_vertex<<endl;

        visited_vertex_set.insert(neighbor_vertex);

        vertex_queue.push(neighbor_vertex);
      }

      Vertex next_neighbor_vertex;
      has_neighbor = graph.GetNextNeighborVertex(next_neighbor_vertex, front_vertex, neighbor_vertex);
      if (has_neighbor) {
        neighbor_vertex = next_neighbor_vertex;
      }
    }
  }
}


/*!
 * @brief 求图的连通分量
 * @tparam Vertex 结点模板参数
 * @tparam Weight 边权值模板参数
 * @param graph 图(引用)
 * @note
 * 1. 使用visited_vertex_set保存已经遍历过的结点
 * 2. 每遍历一个结点vertex
 *   如果在visited_vertex_set中(则已经在某连通分量中)
 *       不再处理;
 *   如果不在visited_vertex_set中:
 *       使用DFS对vertex进行遍历
 *       连通分量数量+1
 */
template<class Vertex, class Weight>
void Components(Graph<Vertex, Weight>& graph) {

  int vertex_cnt = graph.VertexCount(); // 图内结点的数量
  set<Vertex> visited_vertex_set; // 使用set保存已经遍历过的结点

  int component_idx = 1; // 初始连通分量为1

  for (int i = 0; i < graph.VertexCount(); i++) {

    Vertex vertex;
    bool done = graph.GetVertexByIndex(vertex, i); // 获取索引i对应的结点vertex

    if (done) {
      // 如果visited_vertex_set中, 没有查到vertex(说明vertex在一个新的联通分量中):
      //     对vertex执行DFS遍历(书中的算法, 使用BFS也可以)
      if (visited_vertex_set.find(vertex) == visited_vertex_set.end()) {
        cout << "连通分量" << component_idx << ":" << endl;
        DFSOnVertex(graph, vertex, visited_vertex_set);

        component_idx++; // 连通分量数量+1
        cout<<endl;
      }
    }
  }
}


/*!
 * @brief Kruskal算法
 * @tparam TVertex 结点模板参数
 * @tparam TWeight 边权值模板参数
 * @param graph 图(引用)
 * @param min_span_tree 最小生成树(引用)
 * @note
 * 
 * 参数graph对应图{ TVertex(结点集合), { E(边集合) } }
 * 最小生成树的初始状态只有n个顶点, 没有边, MST = { TVertex, { } }
 * 
 * while MST未完成:
 *     在E中选择代价最小的边
 *     如果 此边的两个结点, 分别落在不同的连通分量:
 *         将此边加入到MST
 *         E舍去这条边
 */
template<class TVertex, class TWeight>
void Kruskal(Graph<TVertex, TWeight>& graph, MinSpanTree<TVertex, TWeight>& min_span_tree) {

    MinPriorityQueue<MSTNode<TVertex, TWeight> > min_priority_queue;    // 最小优先队列
    DisjointSet disjoint_set(graph.VertexCount());                             // 使用并查集来判断连通分量

    for (int i = 0; i < graph.EdgeCount(); i++) {
        TVertex cur_starting_vertex = graph.GetEdge(i).starting_vertex;
        TVertex cur_ending_vertex = graph.GetEdge(i).ending_vertex;

        // 如果边(cur_starting_vertex, cur_ending_vertex)存在, 即拿到权重:
        //     则插入最小优先队列min_priority_queue
        TWeight weight;
        bool get_weight_done = graph.GetWeight(weight, cur_starting_vertex, cur_ending_vertex);
        if (get_weight_done) {
            MSTNode<TVertex, TWeight> cur_MST_node(weight, cur_starting_vertex, cur_ending_vertex);
            min_priority_queue.Enqueue(cur_MST_node);
        }
    }

    // 执行Kruskal算法核心流程
    for (int i = 0; i < graph.VertexCount() - 1;) {
        MSTNode<TVertex, TWeight> cur_MST_node;
        min_priority_queue.Dequeue(cur_MST_node);

        int cur_ending_vertex_index = graph.GetVertexIndex(cur_MST_node.ending_vertex);       // 当前边的起点索引
        int cur_starting_vertex_index = graph.GetVertexIndex(cur_MST_node.starting_vertex);   // 当前边的终点索引

        int cur_starting_vertex_root_index = disjoint_set.Find(cur_ending_vertex_index);    // 当前边的起点对应的并查集根结点索引
        int cur_ending_vertex_root_index = disjoint_set.Find(cur_starting_vertex_index);    // 当前边的终点对应的并查集根节点索引

        // if 两个根节点不在一个并查集内:
        //     合并两个并查集
        //     当前最小生成树结点cur_MST_node, 插入最小生成树min_span_tree
        //     i++
        if (cur_starting_vertex_root_index != cur_ending_vertex_root_index) {
            disjoint_set.Union(cur_starting_vertex_root_index, cur_ending_vertex_root_index); // 合并
            min_span_tree.Insert(cur_MST_node);   // 插入到最小生成树
            i++;
        }
    }
}


/*!
 * @brief Prim算法
 * @tparam TVertex 结点模板参数
 * @tparam TWeight 边权值模板参数
 * @param graph 图(引用)
 * @param min_span_tree 最小生成树
 * @note
 *
 * # CyberDash批注
 * 参数graph对应图{ TVertex(结点集合), { E(边集合) } }.
 * min_span_tree为最小生成树,
 * min_span_tree中的结点对应结点集合mst_vertex_set
 *
 * 算法从mst_vertex_set = { starting_vertex }开始(只包含起始结点),
 * ```
 * 循环以下操作:
 *     在所有u ∈ mst_vertex_set, v ∈ (TVertex - mst_vertex_set)的边(u, v) ∈ E中,
 * 
 *    mst_vertex_set    TVertex - mst_vertex_set
 *         ------          ------
 *       /       \       /       \
 *      |   u----|------|---v    |
 *      \       /       \       /
 *       -------         ------
 * 
 *     找一条权值最小的边(starting_vertex, ending_vertex), 权值weight,
 *         加入min_span_tree(以MSTEdgeNode的方式)
 *         结点u加入mst_vertex_set,
 *     直到mst_vertex_set = V为止
 * ```
 * 此时min_span_tree为最小生成树, 有** n-1条边
 */
template<class TVertex, class TWeight>
bool Prim(Graph<TVertex, TWeight>& graph, MinSpanTree<TVertex, TWeight>& min_span_tree) {

    // 索引0对应的结点, 作为Prim算法的起始结点starting_vertex
    TVertex starting_vertex;
    bool res = graph.GetVertexByIndex(starting_vertex, 0);
    if (!res) {
        return false;
    }

    // 最小生成树中的结点集合, 进行初始化, 插入结点starting_vertex
    set<TVertex> mst_vertex_set;
    mst_vertex_set.insert(starting_vertex);

    MinPriorityQueue<MSTNode<TVertex, TWeight> > min_priority_queue;   // 最小优先队列

    TVertex cur_neighbor_vertex;
    TVertex next_neighbor_vertex;

    bool new_neighbor_exists = graph.GetFirstNeighborVertex(cur_neighbor_vertex, starting_vertex);
    while (new_neighbor_exists) {

        TWeight cur_edge_weight;
        graph.GetWeight(cur_edge_weight, starting_vertex, cur_neighbor_vertex);

        MSTNode<TVertex, TWeight> cur_mst_edge_node(cur_edge_weight, starting_vertex, cur_neighbor_vertex);
        min_priority_queue.Enqueue(cur_mst_edge_node);

        // 遍历至下一个邻接结点
        new_neighbor_exists = graph.GetNextNeighborVertex(next_neighbor_vertex, starting_vertex, cur_neighbor_vertex);
        if (new_neighbor_exists) {
            cur_neighbor_vertex = next_neighbor_vertex;
        }
    }


    while (mst_vertex_set.size() < graph.VertexCount()) {

        // 最小优先队列Dequeue出最短边, 赋给mst_edge_node
        MSTNode<TVertex, TWeight> mst_edge_node;
        min_priority_queue.Dequeue(mst_edge_node);

        // 最短边进入min_span_tree
        min_span_tree.Insert(mst_edge_node);

        // mst_edge_node.tail进入最小生成树结点集合mst_vertex_set
        mst_vertex_set.insert(mst_edge_node.ending_vertex);

        // 将所有u ∈ mst_vertex_set, v ∈ TVertex - mst_vertex_set对应的边(u, v),
        // 入队到最小优先队列min_priority_queue
        for (typename set<TVertex>::iterator iter = mst_vertex_set.begin(); iter != mst_vertex_set.end(); iter++) {
            TVertex cur_mst_vertex = *iter;

            // 结点cur_mst_vertex, 与它的所有不在mst_vertex_set的邻接结点, 所构成的边, 入队到min_priority_queue
            new_neighbor_exists = graph.GetFirstNeighborVertex(cur_neighbor_vertex, cur_mst_vertex);
            while (new_neighbor_exists) {
                if (mst_vertex_set.find(cur_neighbor_vertex) == mst_vertex_set.end()) { // 如果cur_neighbor_vertex不在mst_vertex_set:
                    TWeight cur_weight;
                    graph.GetWeight(cur_weight, cur_mst_vertex, cur_neighbor_vertex);

                    // 用 边(cur_mst_vertex, cur_neighbor_vertex) 的信息, 构造MSTNode结点
                    MSTNode<TVertex, TWeight> cur_mst_edge_node(cur_weight, cur_mst_vertex, cur_neighbor_vertex);

                    // 将其入队到最小优先队列min_priority_queue
                    min_priority_queue.Enqueue(cur_mst_edge_node);
                }

                // 遍历至下一个邻接结点
                new_neighbor_exists = graph.GetNextNeighborVertex(next_neighbor_vertex, cur_mst_vertex, cur_neighbor_vertex);
                if (new_neighbor_exists) {
                    cur_neighbor_vertex = next_neighbor_vertex;
                }
            }
        }
    }

    return true;
}


/*!
 * @brief 迪杰斯特拉(Dijkstra)最短路径
 * @tparam Vertex 图结点模板类型
 * @tparam Weight 图边权值模板类型
 * @param graph 图的引用
 * @param starting_vertex 起始结点
 * @param distance 最短路径数组, distance[i]表示: 起始结点到索引i结点的最短路径
 * @param predecessor 前一结点数组, predecessor[i]表示: 最短路径中, 索引i结点的前一结点的索引
 * @note
 * Dijkstra算法伪代码
 *
 * vertex_set: 保存所有已知实际(起始点 --> 该结点)最短路径值的结点的集合
 * MinPriorityQueue: 结点的一个优先队列，以结点的最短路径估计(起始点 --> 该节点的路径值), 进行排序
 *
 *
 * 迪杰斯特拉算法:
 *
 *     --- 初始化 ---
 *
 *     // 起始点到每个(原点以外的)结点的distance为无穷大，distance[起始点索引] = 0
 *     INITIALIZE-SINGLE-SOURCE(graph(图), starting_vertex(起始点))
 *
 *     // vertex_set初始化为空
 *     vertex_set(结点集合) <-- 空
 *
 *     --- 贪心 ---
 *
 *     while (PriorityQueue中有元素)
 *         do u <-- EXTRACT_MIN()  // 选取最短路径估计最小(起始点到该节点的路径最短)的结点u
 *         vertex_set <-- vertex_set and u      // u加入集合vertex_set
 *         for u的每个邻接结点v:
 *             松弛(u, v, 边集合)                 // 松弛成功的结点, 会被加入到vertex_set
 */
template<class Vertex, class Weight>
void Dijkstra(Graph<Vertex, Weight>& graph, Vertex starting_vertex, Weight distance[], int predecessor[]) {

  /// --- 初始化 ---

  // vertex_set初始化为空
  set<Vertex> vertex_set;

  // 起始点到自身的最短路径值为0, 到其他结点的最短路径值为graph.MaxWeight()
  int starting_vertex_index = graph.GetVertexIndex(starting_vertex); // starting_vertex结点的索引
  for (unsigned int i = 0; i < graph.VertexCount(); i++) {
    distance[i] = graph.MaxWeight();
  }
  distance[starting_vertex_index] = 0;

  // 起始点的前驱结点索引设为-1
  predecessor[starting_vertex_index] = -1;

  /// --- 贪心 ---

  for (unsigned int i = 0; i < graph.VertexCount(); i++) {
    Weight cur_min_distance = graph.MaxWeight();   // 以starting_vertex为起点, 某个结点为终点的最短路径(当前最短路径)
    Vertex cur_min_distance_ending_vertex;          // 当前最短路径对应的的终点结点

    // Loop遍历结点(使用优先队列见DijkstraByPriorityQueue), 得到:
    //   起始点到(vertex_set的)各结点中的最短路径cur_min_distance_path
    //   该路径对应的终点cur_min_dist_ending_vertex
    //   终点索引cur_min_dist_ending_vertex_idx

    for (unsigned int j = 0; j < graph.VertexCount(); j++) {

      // 拿到索引j对应的结点vertex_j
      Vertex vertex_j;
      graph.GetVertexByIndex(vertex_j, j);

      // 如果vertex_j已经在vertex_set中, continue
      if (vertex_set.find(vertex_j) != vertex_set.end()) {
        continue;
      }

      Weight cur_distance;
      if (graph.GetWeightByVertexIndex(cur_distance, i, j) && distance[j] < cur_min_distance) {
          cur_min_distance_ending_vertex = vertex_j;
          cur_min_distance = distance[j];
      }
    }

    int cur_min_dist_ending_vertex_index = graph.GetVertexIndex(cur_min_distance_ending_vertex);

    // 将cur_min_dist_ending_vertex插入到vertex_set
    vertex_set.insert(cur_min_distance_ending_vertex);

    // 对cur_min_dist_ending_vertex的每个(未进入vertex_set的)相邻节点执行松弛
    for (unsigned int j = 0; j < graph.VertexCount(); j++) {

      // 拿到索引j对应的结点vertex_j
      Vertex vertex_j;
      graph.GetVertexByIndex(vertex_j, j);
      /* error handler */

      // 如果vertex_j已经在vertex_set中, continue
      if (vertex_set.find(vertex_j) != vertex_set.end()) {
        continue;
      }

      // 边(cur_min_distance_ending_vertex --> vertex_j)的值, 赋给weight
      Weight weight;
      bool get_weight_done = graph.GetWeight(weight, cur_min_distance_ending_vertex, vertex_j);
      if (!get_weight_done) { // 如果没有边, continue
        continue;
      }

      // 松弛操作:
      // 如果
      //   边 (starting_vertex  --> cur_min_distance_ending_vertex)                的weight
      //    +
      //   边                      (cur_min_distance_ending_vertex  -->  vertex_j) 的weight
      //    <
      //   边 (starting_vertex  ---------------------------------->  vertex_j) 的weight
      // 则
      //   更新distance[j]和predecessor[j]
      if (distance[cur_min_dist_ending_vertex_index] + weight < distance[j])
      {
        distance[j] = distance[cur_min_dist_ending_vertex_index] + weight;
        predecessor[j] = cur_min_dist_ending_vertex_index;
      }
    }
  }
}


/*!
 * @brief 迪杰斯特拉(Dijkstra)最短路径(优先队列)
 * @tparam TVertex 图结点模板类型
 * @tparam TWeight 图边权值模板类型
 * @param graph 图的引用
 * @param starting_vertex 起始结点
 * @param distance 最短路径数组, distance[i]表示: 起始结点到索引i结点的最短路径
 * @param predecessor 前一结点数组, predecessor[i]表示: 最短路径中, 索引i结点的前一结点的索引
 * @note
 * Dijkstra算法伪代码
 *
 * vertex_set: 保存所有已知实际(起始点 --> 该结点)最短路径值的结点的集合
 * MinPriorityQueue: 结点的一个优先队列，以结点的最短路径估计(起始点 --> 该节点的路径值), 进行排序
 *
 * 迪杰斯特拉算法:
 *
 *     --- 初始化 ---
 *
 *     // 起始点到每个(原点以外的)结点的distance为无穷大，distance[起始点索引] = 0
 *     INITIALIZE-SINGLE-SOURCE(graph(图), starting_vertex(起始点))
 *
 *     // vertex_set初始化为空
 *     vertex_set(结点集合) <-- 空
 *
 *     // 起始点进入优先队列
 *     MinPriorityQueue(优先队列) <-- 路径(起始点, 起始点, 路径长度)
 *
 *     --- 贪心 ---
 *
 *     while (PriorityQueue中有元素)
 *         do u <-- EXTRACT_MIN(MinPriorityQueue)  // 选取u为PriorityQueue中, 最短路径估计最小(起始点到该节点的路径最短)的结点
 *
 *         vertex_set <-- vertex_set and u      // u加入集合vertex_set
 *         for u的每个邻接结点v:
 *             松弛(u, v, 边集合)                 // 松弛成功的结点, 会被加入到vertex_set, u进入MinPriorityQueue
 */
template<class TVertex, class TWeight>
void DijkstraByPriorityQueue(Graph<TVertex, TWeight>& graph,
                             TVertex starting_vertex,
                             TWeight distance[],
                             int predecessor[])
{
  /// --- 初始化 ---

  // vertex_set初始化为空
  set<TVertex> vertex_set;

  // 起始点到自身的最短路径值为0, 到其他结点的最短路径值为graph.MaxWeight()
  int starting_vertex_idx = graph.GetVertexIndex(starting_vertex); // starting_vertex结点的索引
  for (int i = 0; i < graph.VertexCount(); i++) {
    distance[i] = graph.MaxWeight();
  }
  distance[starting_vertex_idx] = 0;

  // 路径的最小优先队列, 路径起始点-->起始点入优先队列
  MinPriorityQueue<AdjacencyListPath<TVertex, TWeight> > min_priority_queue;
  AdjacencyListPath<TVertex, TWeight> cur_path(starting_vertex, starting_vertex, 0);
  min_priority_queue.Enqueue(cur_path);

  // 起始点的前驱结点索引设为-1
  predecessor[starting_vertex_idx] = -1;

  /// --- 贪心 ---

  while (min_priority_queue.Size() != 0) {   // 当所有结点插入到vertex_set时, 由于内层循环continue所有结点, 优先队列将为空

    // 优先队列出队元素到min_distance_path, 得到:
    //   起始点到(vertex_set的)各结点中的最短路径cur_min_distance_path
    //   该路径对应的终点cur_min_dist_ending_vertex
    //   终点索引cur_min_dist_ending_vertex_idx
    AdjacencyListPath<TVertex, TWeight> cur_min_distance_path;
    min_priority_queue.Dequeue(cur_min_distance_path);

    TVertex cur_min_distance_ending_vertex;
    cur_min_distance_ending_vertex = cur_min_distance_path.ending_vertex;

    int cur_min_distance_ending_vertex_idx = graph.GetVertexIndex(cur_min_distance_ending_vertex);

    // 将cur_min_dist_ending_vertex插入到vertex_set
    vertex_set.insert(cur_min_distance_ending_vertex);

    // 对cur_min_dist_ending_vertex的每个(未进入vertex_set的)相邻节点执行松弛
    for (int j = 0; j < graph.VertexCount(); j++) {

      // 索引j对应的结点vertex_j
      TVertex vertex_j;
      graph.GetVertexByIndex(vertex_j, j);

      // 如果vertex_j已经在vertex_set中, continue
      if (vertex_set.find(vertex_j) != vertex_set.end()) {
        continue;
      }

      // 边(cur_min_distance_ending_vertex --> vertex_j)的值, 赋给weight
      TWeight weight;
      bool get_weight_done = graph.GetWeight(weight, cur_min_distance_ending_vertex, vertex_j);
      if (!get_weight_done) { // 如果没有边, continue
        continue;
      }

      /// --- 松弛操作 ---

      // 如果
      //   边 (starting_vertex  --> cur_min_distance_ending_vertex)                的weight
      //    +
      //   边                      (cur_min_distance_ending_vertex  -->  vertex_j) 的weight
      //    <
      //   边 (starting_vertex  ---------------------------------->  vertex_j) 的weight
      // 则
      //   更新distance[j]和predecessor[j]
      //   生成new_min_distance_path, 进入最小优先队列
      if (distance[cur_min_distance_ending_vertex_idx] + weight < distance[j]) {
        distance[j] = distance[cur_min_distance_ending_vertex_idx] + weight;
        predecessor[j] = cur_min_distance_ending_vertex_idx;

        AdjacencyListPath<TVertex, TWeight> new_min_distance_path(starting_vertex, vertex_j, distance[j]);
        min_priority_queue.Enqueue(new_min_distance_path);
      }
    }
  }
}


/*!
 * 贝尔曼福特(Bellman-Ford)最短路径
 * @tparam TVertex 图结点模板类型
 * @tparam TWeight 图边权值模板类型
 * @param graph 图的引用
 * @param starting_vertex 起始结点
 * @param distance 最短路径数组, distance[i]表示: 起始结点到索引i结点的最短路径
 * @param predecessor 前一结点数组, predecessor[i]表示: 最短路径中, 索引i结点的前一结点
 * @return 是否有负环
 * @note
 *
 * BellmanFord算法:
 *
 *     --- 初始化 ---
 *
 *     for 图中的每个结点v:
 *         如果(starting_vertex, v)没有边:
 *             distance[v] <-- MAX(不存在路径)
 *         否则:
 *             如果 v 是starting_vertex(起始点):
 *                 distance[v] = 0
 *                 predecessor[v] <-- -1(没有前一结点)
 *             否则:
 *                 distance[v] = 边(starting_vertex, v)的长度(权值)
 *                 predecessor[v] <-- starting_vertex_index(结点starting_vertex的索引) // v的前一结点是starting_vertex
 *
 *
 *     --- 动态规划 ---
 *
 *     for循环(图结点总数 - 1)次:
 *         for 图的每一条边edge (u, v):
 *             // 松弛
 *             如果 distance[u] + 边(u, v)权重 < distance[v]:
 *                 distance[v] <-- distance[u] + 边(u, v)权重
 *                 predecessor[v] <-- u
 *
 *
 *     --- 检查是否有负权重的回路 ---
 *
 *     for 每一条边edge (u, v):
 *         如果 distance[u] + 边(u, v)权重 < distance[v]:
 *             error "图包含负回路"
 */
template<class TVertex, class TWeight>
bool BellmanFord(Graph<TVertex, TWeight>& graph, TVertex starting_vertex, TWeight distance[], int predecessor[]) {
    int vertex_cnt = graph.VertexCount();

    // --- 初始化 ---

    // 起始点到自身的最短路径值为0, 到其他结点的最短路径值为graph.MaxWeight()
    int starting_vertex_index = graph.GetVertexIndex(starting_vertex); // starting_vertex结点的索引
    for (int i = 0; i < graph.VertexCount(); i++) {
        distance[i] = graph.MaxWeight();
    }
    distance[starting_vertex_index] = 0;

    // 起始点的前驱结点索引设为-1
    predecessor[starting_vertex_index] = -1;

    // --- 动态规划 ---

    // BellmanFord执行|V| - 1次"松弛所有边"
    for (int vertex_index = 0; vertex_index < graph.VertexCount() - 1; vertex_index++) {
        for (int edge_index = 0; edge_index < graph.EdgeCount(); edge_index++) {
            TVertex cur_starting_vertex = graph.GetEdge(edge_index).starting_vertex;
            TVertex cur_ending_vertex = graph.GetEdge(edge_index).ending_vertex;

            int cur_starting_vertex_index = graph.GetVertexIndex(cur_starting_vertex);
            int cur_ending_vertex_index = graph.GetVertexIndex(cur_ending_vertex);

            TWeight cur_edge_weight;
            bool res = graph.GetWeight(cur_edge_weight, cur_starting_vertex, cur_ending_vertex);
            if (!res) {
                continue;
            }

            /// --- 松弛 ---
            // 如果
            //   边 (starting_vertex  --> cur_starting_vertex)                         的weight
            //    +
            //   边                      (cur_starting_vertex  -->  cur_ending_vertex) 的weight
            //    <
            //   边 (starting_vertex  --------------------------->  cur_ending_vertex) 的weight
            // 则
            //   更新distance[cur_ending_vertex_index]和predecessor[cur_ending_vertex_index]
            if (distance[cur_starting_vertex_index] + cur_edge_weight < distance[cur_ending_vertex_index]) {
                distance[cur_ending_vertex_index] = distance[cur_starting_vertex_index] + cur_edge_weight;
                predecessor[cur_ending_vertex_index] = cur_starting_vertex_index;
            }
        }
    }

    // --- 检查是否有负权重的回路 ---
    bool has_negative_weight_cycle = false; // 默认没有负权环
    for (int i = 0; i < graph.EdgeCount(); i++) {
        TVertex cur_starting_vertex = graph.GetEdge(i).starting_vertex;
        TVertex cur_ending_vertex = graph.GetEdge(i).ending_vertex;

        int cur_starting_vertex_index = graph.GetVertexIndex(cur_starting_vertex);
        int cur_ending_vertex_index = graph.GetVertexIndex(cur_ending_vertex);

        TWeight cur_weight;
        bool get_weight_done = graph.GetWeight(cur_weight, cur_starting_vertex, cur_ending_vertex);
        if (!get_weight_done) {
            continue;
        }

        if (distance[cur_starting_vertex_index] + cur_weight < distance[cur_ending_vertex_index]) {
            has_negative_weight_cycle = true;
            break;
        }
    }

    return has_negative_weight_cycle;
}


/*!
 * 弗洛伊德(Floyd-Warshall)最短路径
 * @tparam Vertex 图结点模板类型
 * @tparam Weight 图边权值模板类型
 * @param graph 图的引用
 * @param distance 最短路径数组, distance[i][j]表示: 索引i结点到索引j结点的最短路径
 * @param predecessor 前一结点数组, predecessor[i][j]表示: 索引i结点到索引j结点最短路径中, j的前一结点
 * @note
 *
 * 弗洛伊德算法:
 *     distance[][] is a distance matrix for n vertices.
 *         distance[i][j] is the distance to move directly from i to j.
 *         if no direct link from i to j
 *             then initialize distance[i][j] = INFINITY
 *         the distance from a node to itself is 0.(Initialize distance[i][i] = 0 for all i)
 *     predecessor[][] is a predecessor matrix. it enables you to reconstruct the shortest paths.
 *         predecessor[i][j] should be initialized to i.
 *
 * 算法执行结果:
 *     distance[i][j] contains the total cost along the shortest path from i to j.
 *     predecessor[i][j] contains the predecessor of j on the shortest path from i to j.
 */
template<class Vertex, class Weight>
void Floyd(Graph<Vertex, Weight>& graph, vector<vector<Weight> >& distance, vector<vector<int> >& predecessor) {
  int vertex_cnt = graph.VertexCount();    // 结点数量

  for (int cur_starting_vertex_index = 0; cur_starting_vertex_index < graph.VertexCount(); cur_starting_vertex_index++) {
    for (int cur_ending_vertex_index = 0; cur_ending_vertex_index < graph.VertexCount(); cur_ending_vertex_index++) {

      if (cur_starting_vertex_index == cur_ending_vertex_index) {
        distance[cur_starting_vertex_index][cur_ending_vertex_index] = (Weight)0;
      } else {
        Weight weight;
        bool done = graph.GetWeightByVertexIndex(weight, cur_starting_vertex_index, cur_ending_vertex_index);
        if (done) {
          distance[cur_starting_vertex_index][cur_ending_vertex_index] = weight;
        } else {
            distance[cur_starting_vertex_index][cur_ending_vertex_index] = graph.MaxWeight();
        }
      }

      predecessor[cur_starting_vertex_index][cur_ending_vertex_index] = cur_starting_vertex_index;
    }
  }

  // --- 动态规划 ---

  for (int cur_vertex_idx = 0; cur_vertex_idx < graph.VertexCount(); cur_vertex_idx++) {
    for (int cur_starting_vertex_idx = 0; cur_starting_vertex_idx < graph.VertexCount(); cur_starting_vertex_idx++) {
      for (int cur_ending_vertex_idx = 0; cur_ending_vertex_idx < graph.VertexCount(); cur_ending_vertex_idx++) {

        // --- 松弛操作 ---

        // 如果
        //   边 (cur_starting_vertex  --> cur_vertex)                         的weight
        //    +
        //   边                          (cur_vertex  -->  cur_ending_vertex) 的weight
        //    <
        //   边 (starting_vertex  ---------------------->  cur_ending_vertex) 的weight
        // 则
        //   更新distance[cur_starting_vertex_idx][cur_ending_vertex_idx] 和
        //      predecessor[cur_starting_vertex_idx][cur_ending_vertex_idx]
        if (distance[cur_starting_vertex_idx][cur_vertex_idx] + distance[cur_vertex_idx][cur_ending_vertex_idx]
              < distance[cur_starting_vertex_idx][cur_ending_vertex_idx])
        {
          distance[cur_starting_vertex_idx][cur_ending_vertex_idx] =
            distance[cur_starting_vertex_idx][cur_vertex_idx] + distance[cur_vertex_idx][cur_ending_vertex_idx];

          predecessor[cur_starting_vertex_idx][cur_ending_vertex_idx] =
            predecessor[cur_vertex_idx][cur_ending_vertex_idx];
        }
      }
    }
  }
}


/*!
 * @brief 打印单源最短路径(SSSP)
 * @tparam Vertex 结点类型模板参数
 * @tparam Weight 边权值类型模板参数
 * @param graph 图的引用
 * @param starting_vertex 起始结点
 * @param distance 最短路径数组, distance[i]表示: 起始结点到索引i结点的最短路径
 * @param predecessor 前一结点数组, predecessor[i]表示: 最短路径中, 索引i结点的前一结点
 */
template<class Vertex, class Weight>
void PrintSingleSourceShortestPath(Graph<Vertex, Weight>& graph,
                                   Vertex starting_vertex,
                                   Weight distance[],
                                   const int predecessor[])
{
  cout << "--- 从起始点(" << starting_vertex << ")到其他各顶点的最短路径 ---" << endl;

  int vertex_cnt = graph.VertexCount();
  int starting_vertex_idx = graph.GetVertexIndex(starting_vertex);

  // 用于存放以某个结点为终点的最短路径经过的结点
  int* inverted_predecessor = new int[graph.VertexCount()];

  // 分别显示starting_vertex到各个结点的最短路径
  for (int cur_ending_vertex_idx = 0; cur_ending_vertex_idx < graph.VertexCount(); cur_ending_vertex_idx++) {
    if (cur_ending_vertex_idx == starting_vertex_idx) {
      continue;
    }

    // 构造"以索引starting_vertex_idx结点(staring_vertex)为起点, 索引cur_ending_vertex_idx结点为终点"的最短路径
    int predecessor_vertex_idx = cur_ending_vertex_idx;
    int inverted_predecessor_vertex_idx = 0; // 最短路径结点倒序索引

    while (predecessor_vertex_idx != starting_vertex_idx) {
      inverted_predecessor[inverted_predecessor_vertex_idx] = predecessor_vertex_idx;
      predecessor_vertex_idx = predecessor[predecessor_vertex_idx];
      inverted_predecessor_vertex_idx++;
    }

    // 获取索引i对应的结点
    Vertex vertex_ending_vertex;
    graph.GetVertexByIndex(vertex_ending_vertex, cur_ending_vertex_idx);

    cout << "起始点(" << starting_vertex << ")到结点(" << vertex_ending_vertex << ")的最短路径为:";
    cout << starting_vertex << " ";

    // 使用inverted_predecessor数组打印出路径, 对inverted_predecessor数组从后向前, 依次打印
    while (inverted_predecessor_vertex_idx > 0) {
      inverted_predecessor_vertex_idx--;
      graph.GetVertexByIndex(vertex_ending_vertex, inverted_predecessor[inverted_predecessor_vertex_idx]);
      cout << vertex_ending_vertex << " ";
    }

    cout << ", ";
    cout << "最短路径长度为:" << distance[cur_ending_vertex_idx] << endl;
  }

  delete[] inverted_predecessor;
}


/*!
 * 递归打印某一个起始点的最短路径(在多源最短路径中)
 * @tparam Vertex 结点模板类型
 * @tparam Weight 边权值模板类型
 * @param graph 图(引用)
 * @param predecessor 前一结点数组, predecessor[starting_vertex_idx][ending_vertex_idx]表示: 索引i结点到索引j结点最短路径中, j的前一结点
 * @param starting_vertex_idx
 * @param ending_vertex_idx
 */
template<class Vertex, class Weight>
void PrintOneSourceShortestPathRecursive(Graph<Vertex, Weight>& graph,
                                         vector<vector<int> > predecessor,
                                         int starting_vertex_idx,
                                         int ending_vertex_idx)
{
  if (starting_vertex_idx != ending_vertex_idx) {
    PrintOneSourceShortestPathRecursive(graph,
                                        predecessor,
                                        starting_vertex_idx,
                                        predecessor[starting_vertex_idx][ending_vertex_idx]);
  }

  Vertex ending_vertex;
  graph.GetVertexByIndex(ending_vertex, ending_vertex_idx);

  cout << ending_vertex << " ";
}


/*!
 * 打印多源最短路径(弗洛伊德Floyd等MSSP)
 * @tparam Vertex 结点模板类型
 * @tparam Weight 边权值模板类型
 * @param graph 图(引用)
 * @param distance 最短路径数组, distance[i][j]表示: 索引i结点到索引j结点的最短路径
 * @param predecessor 前一结点数组, predecessor[i][j]表示: 索引i结点到索引j结点最短路径中, j的前一结点
 * @note
 *
 * 按照不同起始点, 分类打印
 */
template<class Vertex, class Weight>
void PrintMultipleSourceShortestPath(Graph<Vertex,
                                     Weight>& graph,
                                     vector<vector<Weight> > distance,
                                     vector<vector<int> > predecessor)
{
  int vertex_cnt = graph.VertexCount();    // 结点数量

  for (int cur_starting_vertex_idx = 0; cur_starting_vertex_idx < graph.VertexCount(); cur_starting_vertex_idx++) {
    Vertex cur_starting_vertex;
    graph.GetVertexByIndex(cur_starting_vertex, cur_starting_vertex_idx);

    cout << "--- 从起始点(" << cur_starting_vertex << ")到其他各顶点的最短路径 ---" << endl;

    for (int cur_ending_vertex_idx = 0; cur_ending_vertex_idx < graph.VertexCount(); cur_ending_vertex_idx++) {
      if (cur_starting_vertex_idx == cur_ending_vertex_idx) {
        continue;
      }

      Vertex cur_ending_vertex;
      graph.GetVertexByIndex(cur_ending_vertex, cur_ending_vertex_idx);

      cout << "起始点(" << cur_starting_vertex << ")到结点(" << cur_ending_vertex << ")的最短路径为: ";

      PrintOneSourceShortestPathRecursive(graph, predecessor, cur_starting_vertex_idx, cur_ending_vertex_idx);

      cout << ", 最短路径长度为: " << distance[cur_starting_vertex_idx][cur_ending_vertex_idx] << endl;
    }

    cout<<endl;
  }
}

