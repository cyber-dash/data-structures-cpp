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
 * @tparam Vertex 结点类型模版参数
 * @tparam Weight 边权值类型模板参数
 * @param graph 图
 * @param vertex 遍历起始结点
 */
template<class Vertex, class Weight>
void DFS(Graph<Vertex, Weight>& graph, const Vertex& vertex) {

  set<Vertex> visited_vertex_set;

  DFSOnVertex(graph, vertex, visited_vertex_set);
}


/*!
 * @brief 图深度优先遍历(递归)
 * @tparam Vertex 结点类型模板参数
 * @tparam Weight 边权值类型模板参数
 * @param graph 图
 * @param vertex 遍历起始结点
 * @param visited_vertex_set 已访问结点集合
 * @note 利用函数的调用关系来模拟栈
 */
template<class Vertex, class Weight>
void DFSOnVertex(Graph<Vertex, Weight>& graph, Vertex vertex, set<Vertex>& visited_vertex_set) {

  cout<<"Vertex: "<<vertex<<endl;

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
 * @tparam Vertex 结点类型模板参数
 * @tparam Weight 边权值类型模板参数
 * @param graph 图
 * @param vertex 遍历起始结点
 * @note
 * 使用队列进行广度优先遍历
 */
template<class Vertex, class Weight>
void BFS(Graph<Vertex, Weight>& graph, const Vertex& vertex) {

  set<Vertex> visited_vertex_set;
  visited_vertex_set.insert(vertex);

  queue<Vertex> vertex_queue;
  vertex_queue.push(vertex); // 遍历起始结点入队列

  cout<<"Vertex "<<vertex<<endl;

  while (!vertex_queue.empty()) {
    Vertex front_vertex = vertex_queue.front(); // 每次取队头
    vertex_queue.pop();

    // 已取出的队头结点的相邻结点入队
    Vertex neighbor_vertex;
    bool has_neighbor = graph.GetFirstNeighborVertex(neighbor_vertex, front_vertex);

    while (has_neighbor) {
      if (visited_vertex_set.find(neighbor_vertex) == visited_vertex_set.end()) {
        cout<<"Vertex "<<neighbor_vertex<<endl;

        visited_vertex_set.insert(neighbor_vertex);

        vertex_queue.push(neighbor_vertex);
      }

      Vertex next_neighbor_vertex;
      has_neighbor = graph.GetNextNeighborVertex(next_neighbor_vertex, front_vertex, neighbor_vertex);
      neighbor_vertex = next_neighbor_vertex;
    }
  }
}


/*!
 * @brief 求图的连通分量
 * @tparam Vertex 结点类型模板参数
 * @tparam Weight 边权值类型模板参数
 * @param graph 图
 * @note
 * 1. 使用visited_vertex_set保存已经遍历过的结点
 * 2. 每遍历一个结点vertex
 *   如果在visited_vertex_set中, 则已经在某连通分量中, 不再处理;
 *   如果不在visited_vertex_set中, 使用DFS对vertex进行遍历, 连通分量数量+1
 */
template<class Vertex, class Weight>
void Components(Graph<Vertex, Weight>& graph) {

  int vertices_num = graph.NumberOfVertices(); // 图内结点的数量
  set<Vertex> visited_vertex_set; // 使用set保存已经遍历过的结点

  int component_index = 1; // 初始连通分量为1

  for (int i = 0; i < vertices_num; i++) {

    Vertex vertex;
    bool done = graph.GetVertexByIndex(vertex, i); // 获取索引i对应的结点vertex

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
 * @tparam Vertex 结点类型模板参数
 * @tparam Weight 边权值类型模板参数
 * @param graph 图
 * @param min_span_tree 最小生成树
 */
template<class Vertex, class Weight>
void Kruskal(Graph<Vertex, Weight>& graph, MinSpanTree<Vertex, Weight>& min_span_tree) {

  MSTEdgeNode<Vertex, Weight> edge_node;

  int vertex_num = graph.NumberOfVertices();
  int edge_num = graph.NumberOfEdges();

  MinHeap<MSTEdgeNode<Vertex, Weight> > min_heap(edge_num);

  DisjointSet disjoint_set(vertex_num);

  for (int u_idx = 0; u_idx < vertex_num; ++u_idx) {
    for (int v_idx = u_idx + 1; v_idx < vertex_num; v_idx++) {
      Vertex vertex_u;
      Vertex vertex_v;
      graph.GetVertexByIndex(vertex_u, u_idx);
      graph.GetVertexByIndex(vertex_v, v_idx);

      Weight weight;
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
 * @brief Prim算法(使用堆实现的优先队列)
 * @tparam Vertex 结点类型模板参数
 * @tparam Weight 边权值类型模板参数
 * @param graph 图
 * @param vertex 起始结点(起始可以不用这个参数, 参考教科书, 此处保留)
 * @param min_span_tree 最小生成树
 * @note
 * 殷人昆版教材的实现, 此为经过优化的版本, 优化点在引入优先队列(堆优化)
 */
template<class Vertex, class Weight>
void PrimByHeap(Graph<Vertex, Weight>& graph, Vertex vertex, MinSpanTree<Vertex, Weight>& min_span_tree) {

  MSTEdgeNode<Vertex, Weight> mst_edge_node;

  int count = 1; // 起始vertex进入mst结点集合, count=1
  int vertex_num = graph.NumberOfVertices();
  int edge_num = graph.NumberOfEdges();

  MinHeap<MSTEdgeNode<Vertex, Weight> > min_heap(edge_num);

  set<Vertex> mst_vertex_set; // 原书中的Vmst
  mst_vertex_set.insert(vertex);

  do {
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
 * @param vertex 起始结点(其实可以不用这个参数, 参照教科书, 此处保留)
 * @param min_span_tree 最小生成树
 */
template<class Vertex, class Weight>
void Prim(Graph<Vertex, Weight>& graph, Vertex vertex, MinSpanTree<Vertex, Weight>& min_span_tree) {

  MSTEdgeNode<Vertex, Weight> mst_edge_node;

  int count = 1; // 起始vertex进入mst结点集合, count=1
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


/*!
 * @brief 迪杰斯特拉(Dijkstra)最短路径
 * @tparam Vertex 图结点模板类型
 * @tparam Weight 图边权值模板类型
 * @param graph 图的引用
 * @param starting_vertex 起始结点
 * @param distance 最短路径数组, distance[i]表示: 起始结点到索引i结点的最短路径
 * @param predecessor 前一结点数组, predecessor[i]表示: 最短路径中, 索引i结点的前一结点
 * @note 
 * S: 保存所有已知实际最短路径值的结点的集合
 * Q: Q是结点的一个优先队列，以结点的最短路径估计, 进行排序
 * function Dijkstra(图, 边集合, 起始点)
 *     INITIALIZE-SINGLE-SOURCE(图, 起始点)   // 初始化, 每个除原点外的顶点的置为无穷大，distance[起始点索引] = 0
 *     S <-- 空
 *     Q <-- 起始点
 *     while (Q中有元素)
 *         do u_idx <-- EXTRACT_MIN(Q)           // 选取u为Q中最短路径估计最小的结点
 *         S <-- S and u_idx
 *         for u的每个邻接结点
 *             松弛(u_idx, v_idx, 边集合)             // 松弛成功的结点会被加入到队列中
 */
template<class Vertex, class Weight>
void Dijkstra(Graph<Vertex, Weight>& graph,
                          Vertex starting_vertex,
                          Weight distance[],
                          int predecessor[])
{
  int vertex_num = graph.NumberOfVertices();
  set<Vertex> vertex_set;   // 这个set的本意, 是用来实现优先队列
  int starting_vertex_idx = graph.GetVertexIndex(starting_vertex); // starting_vertex结点的索引

  // 初始化
  for (int i = 0; i < vertex_num; i++) {

    // 获取索引i对应的结点vertex_i
    Vertex vertex_i;
    bool get_vertex_done = graph.GetVertexByIndex(vertex_i, i);
    /* error handler */

    // 将边(starting_vertex --> vertex_i)的值, 保存到distance[i], 如果不存在, 则distance[i]为MAX_WEIGHT
    bool get_weight_done = graph.GetWeight(distance[i], starting_vertex, vertex_i);
    if (!get_weight_done) {
      distance[i] = (Weight)MAX_WEIGHT; // todo: 其实可以用其他的方式表示没有边:-)
    }

    // 如果边(starting_vertex --> vertex_i)存在, 则predecessor[i]的值, 为索引starting_vertex_idx; 否则为-1
    if (vertex_i != starting_vertex && get_weight_done && get_vertex_done) {
      predecessor[i] = starting_vertex_idx;
    } else {
      predecessor[i] = -1;
    }
  }

  // 起始点starting_vertex加入到集合vertex_set
  vertex_set.insert(starting_vertex);
  distance[starting_vertex_idx] = 0;

  for (int i = 0; i < vertex_num - 1; i++) {
    Weight cur_min_dist = (Weight)MAX_WEIGHT; // 以starting_vertex为起点, 某个结点为终点的最短路径(当前最短路径)
    Vertex cur_min_dist_dest_vertex;          // 当前最短路径的终点

    // 找到起始点到(不在vertex_set的)各结点中的最短路径, 和
    // 该路径对应的结点cur_min_dist_dest_vertex和结点索引cur_min_dist_dest_vertex_idx
    // todo: 可以进行堆优化
    for (int j = 0; j < vertex_num; j++) {

      // 拿到索引j对应的结点vertex_j
      Vertex vertex_j;
      graph.GetVertexByIndex(vertex_j, j);
      /* error handler */

      // 如果vertex_j已经在vertex_set中, continue
      if (vertex_set.find(vertex_j) != vertex_set.end()) {
        continue;
      }

      if (distance[j] < cur_min_dist)
      {
        cur_min_dist_dest_vertex = vertex_j;
        cur_min_dist = distance[j];
      }
    }

    // cur_min_dist_dest_vertex结点对应的结点索引
    int cur_min_dist_dest_vertex_idx = graph.GetVertexIndex(cur_min_dist_dest_vertex);

    // 将cur_min_dist_dest_vertex插入到vertex_set
    vertex_set.insert(cur_min_dist_dest_vertex);

    for (int j = 0; j < vertex_num; j++) {

      // 拿到索引j对应的结点vertex_j
      Vertex vertex_j;
      graph.GetVertexByIndex(vertex_j, j);
      /* error handler */

      // 如果vertex_j已经在vertex_set中, continue
      if (vertex_set.find(vertex_j) != vertex_set.end()) {
        continue;
      }

      // 边(cur_min_dist_dest_vertex --> vertex_j)的值, 赋给weight
      Weight weight;
      bool get_weight_done = graph.GetWeight(weight, cur_min_dist_dest_vertex, vertex_j);
      if (!get_weight_done) { // 如果没有边, continue
        continue;
      }

      // 松弛操作:
      // 如果
      //   边 (starting_vertex --> cur_min_dist_dest_vertex)                的weight
      //    +
      //   边                     (cur_min_dist_dest_vertex  -->  vertex_j) 的weight
      //    <
      //   边 (starting_vertex                -->                 vertex_j) 的weight
      // 则
      //   更新distance[j]和predecessor[j]
      if (distance[cur_min_dist_dest_vertex_idx] + weight < distance[j])
      {
        distance[j] = distance[cur_min_dist_dest_vertex_idx] + weight;
        predecessor[j] = cur_min_dist_dest_vertex_idx;
      }
    }
  }
}


// 贝尔曼福特(Bellman-Ford)最短路径
template<class Vertex, class Weight>
bool BellmanFord(Graph<Vertex, Weight>& graph, Vertex starting_vertex, Weight distance[], int predecessor[]) {

  int vertex_num = graph.NumberOfVertices();
  int edge_num = graph.NumberOfEdges();
  set<Vertex> vertex_set;
  int starting_vertex_idx = graph.GetVertexIndex(starting_vertex); // starting_vertex结点的索引

  // 初始化
  for (int i = 0; i < vertex_num; i++) {

    // 获取索引i对应的结点vertex_i
    Vertex vertex_i;
    bool get_vertex_done = graph.GetVertexByIndex(vertex_i, i);
    /* error handler */

    // 将边(starting_vertex --> vertex_i)的值, 保存到distance[i], 如果不存在, 则distance[i]为MAX_WEIGHT
    bool get_weight_done = graph.GetWeight(distance[i], starting_vertex, vertex_i);
    if (!get_weight_done) {
      distance[i] = (Weight)MAX_WEIGHT; // todo: 其实可以用其他的方式表示没有边:-)
    }

    // 如果边(starting_vertex --> vertex_i)存在, 则predecessor[i]的值, 为索引starting_vertex_idx; 否则为-1
    if (vertex_i != starting_vertex && get_weight_done && get_vertex_done) {
      predecessor[i] = starting_vertex_idx;
    } else {
      predecessor[i] = -1;
    }
  }

  for (int i = 0; i < edge_num - 1; i++) {

      for (int u_idx = 0; u_idx < vertex_num; u_idx++) {
          // for (int v_idx = u_idx + 1; v_idx < vertex_num; v_idx++) {
          for (int v_idx = 0; v_idx < vertex_num; v_idx++) {
			  Vertex vertex_u;
			  Vertex vertex_v;
			  graph.GetVertexByIndex(vertex_u, u_idx);
			  graph.GetVertexByIndex(vertex_v, v_idx);

			  Weight weight_u_v;
			  bool get_weight_done = graph.GetWeight(weight_u_v, vertex_u, vertex_v);
			  if (!get_weight_done) {
                  continue;
              }

              // 边u-->v存在
			  if (distance[u_idx] + weight_u_v < distance[v_idx]) {
                  distance[v_idx] = distance[u_idx] + weight_u_v;
                  predecessor[v_idx] = u_idx;
			  }
          }
      }
  }

  bool has_negative_weight_cycle = false; // 默认没有负权环
  bool negative_cycle_triggered = false;  // 是否除法负环检测规则
  for (int u_idx = 0; u_idx < vertex_num; ++u_idx) {
      for (int v_idx = u_idx + 1; v_idx < vertex_num; v_idx++) {
		  Vertex vertex_u;
		  Vertex vertex_v;
		  graph.GetVertexByIndex(vertex_u, u_idx);
		  graph.GetVertexByIndex(vertex_v, v_idx);

		  Weight weight_u_v;
		  bool get_weight_done = graph.GetWeight(weight_u_v, vertex_u, vertex_v);
		  if (!get_weight_done) {
			  continue;
		  }
          if (distance[u_idx] + weight_u_v < distance[v_idx]) {
              negative_cycle_triggered = true;
              break;
          }
      }
      if (negative_cycle_triggered == true) {
          has_negative_weight_cycle = true;
          break;
      }
  }

  return has_negative_weight_cycle;
}


/*!
 * @brief 显示最短路径
 * @tparam Vertex 结点类型模板参数
 * @tparam Weight 边权值类型模板参数
 * @param graph 图类型
 * @param starting_vertex 路径起始结点
 * @param distance 最短路径数组, distance[i]表示: 路径起始结点到索引i结点的最短路径的权值
 * @param predecessor 前一结点数组, predecessor[i]表示: 最短路径中, 索引i结点的前一结点
 */
template<class Vertex, class Weight>
void PrintShortestPath(Graph<Vertex, Weight>& graph, Vertex starting_vertex, Weight distance[], int predecessor[]) {
  cout << "从起始点(" << starting_vertex << ")到其他各顶点的最短路径为: " << endl;

  int vertex_count = graph.NumberOfVertices();
  int starting_vertex_idx = graph.GetVertexIndex(starting_vertex);

  // 用于存放以某个结点为终点的最短路径经过的结点
  int* cur_predecessor = new int[vertex_count];
  /* error handler */

  // 分别显示origin_vertex到各个结点的最短路径
  for (int i = 0; i < vertex_count; i++) {
    if (i == starting_vertex_idx) {
      continue;
    }

    int pre_vertex_idx = i; // 以索引i结点为终点
    int idx = 0;

    while (pre_vertex_idx != starting_vertex_idx) {
      cur_predecessor[idx] = pre_vertex_idx;
      idx++;
      pre_vertex_idx = predecessor[pre_vertex_idx];
    }

    // 获取索引i的结点
    Vertex vertex_i;
    graph.GetVertexByIndex(vertex_i, i);

    cout << "起始点(" << starting_vertex << ")到结点(" << vertex_i << ")的最短路径为:";
    cout << starting_vertex << " ";

    // 使用cur_predecessor数组打印出路径
    while (idx > 0) {
      idx--;
      graph.GetVertexByIndex(vertex_i, cur_predecessor[idx]);
      cout << vertex_i << " ";
    }

    cout << ", ";
    cout << "最短路径长度为:" << distance[i] << endl;
  }

  delete[] cur_predecessor;
}


