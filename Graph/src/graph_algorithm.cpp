/*!
 * @file graph_algorithm.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 图算法.cpp文件
 * @version 0.2.1
 * @date 2021-02-04
 */

#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include "graph_algorithm.h"
#include "priority_queue.h"
#include "disjoint_set.h"


/*!
 * @brief **图深度优先遍历**
 * @tparam TVertex 结点类型模版参数
 * @tparam TWeight 边权值类型模板参数
 * @param graph 图
 * @param vertex 遍历起点
 * @note
 * 图深度优先遍历
 * ------------
 * ------------
 *
 * ------------
 * - **1 声明已访问结点集合visited_vertex_set**\n
 * - **2 对vertex(遍历起点)调用DfsOnVertexRecursive**\n
 */
template<typename TVertex, typename TWeight>
void DfsRecursive(const Graph<TVertex, TWeight>& graph, const TVertex& vertex) {

    // 1 声明已访问结点集合visited_vertex_set
    set<TVertex> visited_vertex_set;

    // 2 对vertex(遍历起点)调用DfsOnVertexRecursive
    DfsOnVertexRecursive(graph, vertex, visited_vertex_set);
}


/*!
 * @brief **图结点深度优先遍历(递归)**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param graph 图
 * @param vertex 遍历起点
 * @param visited_vertex_set 已访问结点集合
 * @note
 * 图结点深度优先遍历(递归)
 * --------------------
 * --------------------
 *
 * 利用函数的调用关系来模拟栈
 *
 * --------------------
 * + **1 起点插入已遍历结点集合**\n
 * + **2 遍历起点的邻接点, 执行递归**\n
 *  - **2.1 初始化neighbor_vertex(新邻接点)和new_neighbor_exists(是否存在新邻接点)**\n
 *  &emsp; 调用GetFirstNeighborVertex,初始化neighbor_vertex和new_neighbor_exists\n
 *  - **2.2 遍历执行递归**\n
 *  &emsp;**while loop** 存在新邻接点 :\n
 *  &emsp;&emsp; **if** 新邻接点不在visit_vertex_set(已访问结点集合)中 :\n
 *  &emsp;&emsp;&emsp; 对新邻接点调用DfsOnVertexRecursive(递归)\n
 *  &emsp;&emsp; 获取下一新邻接点, 并将执行结果(是否存在下一新邻接点)赋给new_neighbor_exists\n
 *  &emsp;&emsp; **if** 下一新邻接点存在 :\n
 *  &emsp;&emsp;&emsp; 更新neighbor_vertex\n
 */
template<typename TVertex, typename TWeight>
void DfsOnVertexRecursive(const Graph<TVertex, TWeight>& graph, const TVertex& vertex, set<TVertex>& visited_vertex_set) {

    cout << "访问结点: " << vertex << endl;

    // ---------- 1 起点插入已遍历结点集合 ----------
    visited_vertex_set.insert(vertex);

    // ---------- 2 遍历起点的邻接点, 执行递归 ----------

    // 2.1 初始化neighbor_vertex(新邻接点)和new_neighbor_exists(是否存在新邻接点)
    TVertex neighbor_vertex;
    // 调用GetFirstNeighborVertex,初始化neighbor_vertex和new_neighbor_exists
    bool new_neighbor_exists = graph.GetFirstNeighborVertex(vertex, neighbor_vertex);

    // 2.2 遍历执行递归
    while (new_neighbor_exists) {                   // while loop 存在新邻接点
        // if 新邻接点不在visit_vertex_set(已访问结点集合)中
        if (visited_vertex_set.find(neighbor_vertex) == visited_vertex_set.end()) {
            // 对新邻接点调用DfsOnVertexRecursive(递归)
            DfsOnVertexRecursive(graph, neighbor_vertex, visited_vertex_set);
        }

        // 获取下一新邻接点, 并将执行结果(是否存在下一新邻接点)赋给new_neighbor_exists
        TVertex next_neighbor_vertex;
        new_neighbor_exists = graph.GetNextNeighborVertex(vertex, neighbor_vertex, next_neighbor_vertex);

        if (new_neighbor_exists) {                  // if 下一新邻接点存在
            neighbor_vertex = next_neighbor_vertex; // 更新neighbor_vertex
        }
    }
}


/*!
 * @brief **图广度优先遍历**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param graph 图
 * @param vertex 遍历起点
 * @note
 * 图广度优先遍历
 * ------------
 * ------------
 *
 * ------------
 * + **1 起点插入已遍历结点集合**\n
 * &emsp; 声明已遍历结点集合\n
 * &emsp; 插入起点\n
 * + **2 起点入队**\n
 * &emsp; 声明结点队列\n
 * &emsp; 起点入队\n
 * + **3 使用队列进行遍历结点**\n
 * &emsp; **while loop** 队列不为空 :\n
 * &emsp;&emsp; 取队头\n
 * &emsp;&emsp; 队头出队\n
 * &emsp;&emsp; 对队头结点调用GetFirstNeighborVertex, 初始化neighbor_vertex(新邻接点)和new_neighbor_exists(是否存在新邻接点)\n
 * &emsp;&emsp; **while loop** 存在新邻接点 :\n
 * &emsp;&emsp;&emsp; **if** 该新邻接点未被访问 :\n
 * &emsp;&emsp;&emsp;&emsp; 访问新邻接点\n
 * &emsp;&emsp;&emsp;&emsp; 该结点插入visited_vertex_set(已访问结点集合)\n
 * &emsp;&emsp;&emsp;&emsp; 该结点入队\n
 * &emsp;&emsp;&emsp; 获取下一新邻接点, 并将执行结果(是否存在下一新邻接点)赋给new_neighbor_exists\n
 * &emsp;&emsp;&emsp; **if** 下一新邻接点存在 :\n
 * &emsp;&emsp;&emsp;&emsp; 更新neighbor_vertex\n
 */
template<typename TVertex, typename TWeight>
void Bfs(const Graph<TVertex, TWeight>& graph, const TVertex& vertex) {

    cout<<"访问结点: "<<vertex<<endl;

    // ---------- 1 起点插入已遍历结点集合 ----------

    set<TVertex> visited_vertex_set;    // 声明已遍历结点集合
    visited_vertex_set.insert(vertex);  // 插入起点

    // ---------- 2 起点入队 ----------

    queue<TVertex> vertex_queue;        // 声明结点队列
    vertex_queue.push(vertex);          // 起点入队

    // ---------- 3 使用队列进行遍历结点 ----------
    while (!vertex_queue.empty()) {                     // while loop 队列不为空
        TVertex front_vertex = vertex_queue.front();    // 取队头
        vertex_queue.pop();                             // 队头出队

        // 对队头结点调用GetFirstNeighborVertex, 初始化neighbor_vertex(新邻接点)和new_neighbor_exists(是否存在新邻接点)
        TVertex neighbor_vertex;
        bool new_neighbor_exists = graph.GetFirstNeighborVertex(front_vertex, neighbor_vertex);
        while (new_neighbor_exists) {                                                   // while loop 存在新邻接点

            if (visited_vertex_set.find(neighbor_vertex) == visited_vertex_set.end()) { // if 该新邻接点未被访问
                cout<<"访问结点: "<<neighbor_vertex<<endl;           // 访问新邻接点
                visited_vertex_set.insert(neighbor_vertex);         // 该结点插入visited_vertex_set(已访问结点集合)
                vertex_queue.push(neighbor_vertex);                 // 该结点入队
            }

            // 获取下一新邻接点, 并将执行结果(是否存在下一新邻接点)赋给new_neighbor_exists
            TVertex next_neighbor_vertex;
            new_neighbor_exists = graph.GetNextNeighborVertex(front_vertex, neighbor_vertex, next_neighbor_vertex);
            if (new_neighbor_exists) {                  // if 下一新邻接点存在
                neighbor_vertex = next_neighbor_vertex; // 更新neighbor_vertex
            }
        }
    }
}


/*!
 * @brief **图的连通分量**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param graph 图
 * @return 连通分量个数
 * @note
 * 图的连通分量
 * ----------
 * ----------
 *
 * <span style="color:#DF5A00">
 * 打印连通分量与算法耦合太重, 有兴趣的朋友自行解耦:-)
 * </span>
 *
 * ----------
 * - **1 边界条件处理**\n
 * &emsp; **if** 结点数为0 :\n
 * &emsp;&emsp; 返回0\n
 * - **2 声明visited_vertex_set(已访问结点集合)**\n
 * - **3 遍历结点, 使用DFS划分联通分量**\n
 * &emsp; 初始化连通分量数量为1
 * &emsp; **for loop** 遍历结点索引 :\n
 * &emsp;&emsp; 获取i(当前索引)对应的结点vertex\n
 * &emsp;&emsp; **if** 在visited_vertex_set中(则已经在某连通分量中) :\n
 * &emsp;&emsp;&emsp; continue(不再处理)\n
 * &emsp;&emsp; 使用DfsOnVertexRecursive对vertex进行遍历\n
 * &emsp;&emsp; 连通分量数量+1\n
 */
template<typename TVertex, typename TWeight>
int Components(const Graph<TVertex, TWeight>& graph) {

    // ---------- 1 边界条件处理 ----------

    if (graph.VertexCount() == 0) {     // if 结点数为0
        return 0;                       // 返回0
    }

    // 2 ---------- 声明visited_vertex_set(已访问结点集合) ----------

    set<TVertex> visited_vertex_set;

    int count = 1; // 初始连通分量数量为1

    for (unsigned int i = 0; i < graph.VertexCount(); i++) {    // for loop 遍历结点索引

        TVertex vertex;
        bool res = graph.GetVertexByIndex(i, vertex);   // 获取i(当前索引)对应的结点vertex
        if (!res) {
            continue;
        }

        // if 在visited_vertex_set中(则已经在某连通分量中)
        if (visited_vertex_set.find(vertex) != visited_vertex_set.end()) {
            continue;   // continue(不再处理)
        }

        cout << "连通分量" << count << ":" << endl;

        // 使用DfsOnVertexRecursive对vertex进行遍历
        DfsOnVertexRecursive(graph, vertex, visited_vertex_set);

        count++; // 连通分量数量+1
        cout<<endl;
    }

    return count;
}


/*!
 * @brief **Kruskal最小生成树算法**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param graph 图
 * @param min_span_tree 最小生成树保存变量
 * @note
 * Kruskal最小生成树算法
 * -------------------
 * -------------------
 *
 * <span style="color:#DF5A00">
 * 图 { Vertices(结点集合), { Edges(边集合) } }\n
 * \n
 * 最小生成树的初始状态: 只有n个顶点, 没有边, MST = { Vertices, { } }\n
 * \n
 * while MST未完成:\n
 * &emsp;&emsp; 在Edges中选择权值最小的边\n
 * &emsp;&emsp; if 此边的两个结点, 分别落在不同的连通分量:\n
 * &emsp;&emsp;&emsp;&emsp; 将此边加入到MST\n
 * &emsp;&emsp;&emsp;&emsp; Edges舍去这条边\n
 * </span>
 *
 * -------------------
 * + **1 初始化min_priority_queue(最小优先队列)和disjoint_set(并查集)**\n
 *  - 声明并初始化最小优先队列\n
 *  - 初始化并查集, size为图结点数\n
 * + **2 将所有边入队到最小优先队列**\n
 * &emsp; **for loop** 遍历边索引 :\n
 * &emsp;&emsp; 获取i(当前边索引)对应的starting_vertex(起点)和ending_vertex(终点)\n
 * &emsp;&emsp; 对起点和终点调用GetWeight\n
 * &emsp;&emsp; **if** 边存在 :\n
 * &emsp;&emsp;&emsp; 声明并初始化mst_edge(最小生成树边)\n
 * &emsp;&emsp;&emsp; 入队到最小优先队列\n
 * + **3 贪心**\n
 * &emsp; **for loop** 循环"图结点数 - 1"次 :\n
 * &emsp;&emsp; 最小优先队列队头出队, 赋给cur_edge(**当前边**)\n
 * &emsp;&emsp; 取当前边的cur_starting_vertex_index(**起点索引**)和cur_ending_vertex_index(**终点索引**)\n
 * &emsp;&emsp; 取起点的cur_starting_vertex_root_index(**并查集根节点索引**)和
 * 终点的cur_ending_vertex_root_index(**并查集根节点索引**)\n
 * &emsp;&emsp; **if** 起点和终点不在一个并查集 :\n
 * &emsp;&emsp;&emsp; 将起点所在的并查集与终点所在的并查集合并\n
 * &emsp;&emsp;&emsp; cur_edge(**当前边**)插入到min_span_tree\n
 * &emsp;&emsp;&emsp; 循环计数加1\n
 */
template<typename TVertex, typename TWeight>
void Kruskal(const Graph<TVertex, TWeight>& graph, MinimumSpanTree<TVertex, TWeight>& min_span_tree) {

    // ---------- 1 初始化min_priority_queue(最小优先队列)和disjoint_set(并查集) ----------

    MinPriorityQueue<Edge<TVertex, TWeight> > min_priority_queue;    // 声明并初始化最小优先队列
    DisjointSet disjoint_set(graph.VertexCount());                   // 初始化并查集, size为图结点数

    // ---------- 2 将所有边入队到最小优先队列 ----------

    for (unsigned int i = 0; i < graph.EdgeCount(); i++) {   // for loop 遍历边索引
        // 获取i(当前边索引)对应的starting_vertex(起点)和ending_vertex(终点)
        TVertex cur_starting_vertex = graph.GetEdge(i).starting_vertex;
        TVertex cur_ending_vertex = graph.GetEdge(i).ending_vertex;

        TWeight weight;
        bool res = graph.GetWeight(cur_starting_vertex, cur_ending_vertex, weight); // 对起点和终点调用GetWeight
        if (res) {  // if 边存在
            // 声明并初始化mst_edge(最小生成树边)
            Edge<TVertex, TWeight> mst_edge(cur_starting_vertex, cur_ending_vertex, weight);
            // 入队到最小优先队列
            min_priority_queue.Enqueue(mst_edge);
        }
    }

    // ---------- 3 贪心 ----------
    for (unsigned int i = 0; i < graph.VertexCount() - 1;) {
        Edge<TVertex, TWeight> cur_edge;
        min_priority_queue.Dequeue(cur_edge);

        // 当前边的cur_starting_vertex_index(起点索引)
        int cur_starting_vertex_index = graph.GetVertexIndex(cur_edge.starting_vertex);
        // 当前边的cur_ending_vertex_index(终点索引)
        int cur_ending_vertex_index = graph.GetVertexIndex(cur_edge.ending_vertex);

        // 当前边的起点对应的cur_starting_vertex_root_index(起点所在并查集的根节点索引)
        int cur_starting_vertex_root_index = disjoint_set.Find(cur_ending_vertex_index);
        // 当前边的终点对应的cur_ending_vertex_root_index(终点所在并查集的根节点索引)
        int cur_ending_vertex_root_index = disjoint_set.Find(cur_starting_vertex_index);

        if (cur_starting_vertex_root_index != cur_ending_vertex_root_index) {   // if 起点和终点不在一个并查集
            // 将起点所在的并查集与终点所在的并查集合并
            disjoint_set.Union(cur_starting_vertex_root_index, cur_ending_vertex_root_index);

            min_span_tree.Insert(cur_edge); // cur_edge(当前边)插入到min_span_tree
            i++;                            // 循环计数加1
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
template<typename TVertex, typename TWeight>
bool Prim(const Graph<TVertex, TWeight>& graph, MinimumSpanTree<TVertex, TWeight>& min_span_tree) {

    // 索引0对应的结点, 作为Prim算法的起始结点starting_vertex
    TVertex starting_vertex;
    bool res = graph.GetVertexByIndex(0, starting_vertex);
    if (!res) {
        return false;
    }

    // 最小生成树中的结点集合, 进行初始化, 插入结点starting_vertex
    set<TVertex> mst_vertex_set;
    mst_vertex_set.insert(starting_vertex);

    MinPriorityQueue<Edge<TVertex, TWeight> > min_priority_queue;   // 最小优先队列

    TVertex cur_neighbor_vertex;
    TVertex next_neighbor_vertex;

    bool new_neighbor_exists = graph.GetFirstNeighborVertex(starting_vertex, cur_neighbor_vertex);
    while (new_neighbor_exists) {

        TWeight cur_edge_weight;
        graph.GetWeight(starting_vertex, cur_neighbor_vertex, cur_edge_weight);

        Edge<TVertex, TWeight> cur_mst_edge(starting_vertex, cur_neighbor_vertex, cur_edge_weight);
        min_priority_queue.Enqueue(cur_mst_edge);

        // 遍历至下一个邻接结点
        new_neighbor_exists = graph.GetNextNeighborVertex(starting_vertex, cur_neighbor_vertex, next_neighbor_vertex);
        if (new_neighbor_exists) {
            cur_neighbor_vertex = next_neighbor_vertex;
        }
    }


    while (mst_vertex_set.size() < graph.VertexCount()) {

        // 最小优先队列Dequeue出最短边, 赋给mst_edge_node
        Edge<TVertex, TWeight> mst_edge_node;
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
            new_neighbor_exists = graph.GetFirstNeighborVertex(cur_mst_vertex, cur_neighbor_vertex);
            while (new_neighbor_exists) {
                if (mst_vertex_set.find(cur_neighbor_vertex) == mst_vertex_set.end()) { // 如果cur_neighbor_vertex不在mst_vertex_set:
                    TWeight cur_weight;
                    graph.GetWeight(cur_mst_vertex, cur_neighbor_vertex, cur_weight);

                    // 用 边(cur_mst_vertex, cur_neighbor_vertex) 的信息, 构造MSTNode结点
                    Edge<TVertex, TWeight> cur_mst_edge(cur_mst_vertex, cur_neighbor_vertex, cur_weight);

                    // 将其入队到最小优先队列min_priority_queue
                    min_priority_queue.Enqueue(cur_mst_edge);
                }

                // 遍历至下一个邻接结点
                new_neighbor_exists = graph.GetNextNeighborVertex(cur_mst_vertex, cur_neighbor_vertex, next_neighbor_vertex);
                if (new_neighbor_exists) {
                    cur_neighbor_vertex = next_neighbor_vertex;
                }
            }
        }
    }

    return true;
}


/*!
 * @brief **Dijkstra迪杰斯特拉最短路径**
 * @tparam TVertex 结点类型模板类型
 * @tparam TWeight 边权值类型模板类型
 * @param graph 图
 * @param starting_vertex 起点
 * @param distance 最短路径数组, distance[i]表示: 起始结点到索引i结点的最短路径
 * @param predecessor 前一结点数组, predecessor[i]表示: 最短路径中, 索引i结点的前一结点的索引
 * @note
 * Dijkstra迪杰斯特拉最短路径
 * ------------------------
 * ------------------------
 *
 * <span style="color:#E76600">
 * Dijkstra算法伪代码\n
 * \n
 * vertex_set: 保存所有已知实际(起始点 --> 该结点)最短路径值的结点的集合\n
 * min_priority_queue: 结点的一个优先队列，以结点的最短路径估计(起始点 --> 该节点的路径值), 进行排序\n
 * \n
 * 迪杰斯特拉算法:\n
 * \n
 * &emsp; --- 初始化 ---\n
 * \n
 * &emsp; // 初始化起点到每个(以外的)结点的distance, 到自身的距离为0, 到其他结点为无穷大\n
 * &emsp; INITIALIZE-SINGLE-SOURCE(graph(图), starting_vertex(起点))\n
 * \n
 * &emsp; // vertex_set初始化为空\n
 * &emsp; vertex_set(结点集合) <-- 空\n
 * \n
 * &emsp; // 起点进入优先队列\n
 * &emsp; priority_queue(优先队列) <-- 路径(起始点, 起始点, 路径长度)\n
 * \n
 * &emsp; --- 贪心 ---\n
 * \n
 * &emsp; while (min_priority_queue中有元素) :\n
 * &emsp;&emsp; do u <-- EXTRACT_MIN(priority_queue)  // 选取u为priority_queue中, 最短路径估计最小(起始点到该节点的路径最短)的结点\n
 * \n
 * &emsp;&emsp; vertex_set <-- vertex_set and u       // u加入集合vertex_set\n
 * &emsp;&emsp; for u的每个邻接结点v:\n
 * &emsp;&emsp;&emsp; 松弛(u, v, 边集合)               // 松弛成功的结点, 会被加入到vertex_set, u进入priority_queue
 * </span>
 *
 * ------------------------
 * + **1 **
 */
template<typename TVertex, typename TWeight>
void Dijkstra(const Graph<TVertex, TWeight>& graph,
               const TVertex& starting_vertex,
               TWeight distance[],
               int predecessor[])
{
  /// --- 初始化 ---

  // vertex_set初始化为空
  set<TVertex> vertex_set;

  // 起始点到自身的最短路径值为0, 到其他结点的最短路径值为graph.MaxWeight()
  int starting_vertex_idx = graph.GetVertexIndex(starting_vertex); // starting_vertex结点的索引
  for (unsigned int i = 0; i < graph.VertexCount(); i++) {
    distance[i] = graph.MaxWeight();
  }
  distance[starting_vertex_idx] = 0;

  // 路径的最小优先队列, 路径起始点-->起始点入优先队列
  MinPriorityQueue<Path<TVertex, TWeight> > min_priority_queue;
  Path<TVertex, TWeight> cur_path(starting_vertex, starting_vertex, 0);
  min_priority_queue.Enqueue(cur_path);

  // 起始点的前驱结点索引设为-1
  predecessor[starting_vertex_idx] = -1;

  /// --- 贪心 ---

  while (min_priority_queue.Size() != 0) {   // 当所有结点插入到vertex_set时, 由于内层循环continue所有结点, 优先队列将为空

    // 优先队列出队元素到min_distance_path, 得到:
    //   起始点到(vertex_set的)各结点中的最短路径cur_min_distance_path
    //   该路径对应的终点cur_min_dist_endking_vertex

    //   终点索引cur_min_dist_ending_vertex_idx
    Path<TVertex, TWeight> cur_min_distance_path;
    min_priority_queue.Dequeue(cur_min_distance_path);

    TVertex cur_min_distance_ending_vertex;
    cur_min_distance_ending_vertex = cur_min_distance_path.ending_vertex;

    int cur_min_distance_ending_vertex_idx = graph.GetVertexIndex(cur_min_distance_ending_vertex);

    // 将cur_min_dist_ending_vertex插入到vertex_set
    vertex_set.insert(cur_min_distance_ending_vertex);

    // 对cur_min_dist_ending_vertex的每个(未进入vertex_set的)相邻节点执行松弛
    for (unsigned int j = 0; j < graph.VertexCount(); j++) {

      // 索引j对应的结点vertex_j
      TVertex vertex_j;
      // graph.GetVertexByIndex(vertex_j, j);
        graph.GetVertexByIndex(j, vertex_j);

      // 如果vertex_j已经在vertex_set中, continue
      if (vertex_set.find(vertex_j) != vertex_set.end()) {
        continue;
      }

      // 边(cur_min_distance_ending_vertex --> vertex_j)的值, 赋给weight
      TWeight weight;
      // bool get_weight_done = graph.GetWeight(weight, cur_min_distance_ending_vertex, vertex_j);
        bool get_weight_done = graph.GetWeight(cur_min_distance_ending_vertex, vertex_j, weight);
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

        Path<TVertex, TWeight> new_min_distance_path(starting_vertex, vertex_j, distance[j]);
        min_priority_queue.Enqueue(new_min_distance_path);
      }
    }
  }
}


/*!
 * Bellman-Ford贝尔曼福特最短路径
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
template<typename TVertex, typename TWeight>
bool BellmanFord(const Graph<TVertex, TWeight>& graph,
                 const TVertex& starting_vertex,
                 TWeight distance[],
                 int predecessor[])
{
    // --- 初始化 ---

    // 起始点到自身的最短路径值为0, 到其他结点的最短路径值为graph.MaxWeight()
    int starting_vertex_index = graph.GetVertexIndex(starting_vertex); // starting_vertex结点的索引
    for (unsigned int i = 0; i < graph.VertexCount(); i++) {
        distance[i] = graph.MaxWeight();
    }
    distance[starting_vertex_index] = 0;

    // 起始点的前驱结点索引设为-1
    predecessor[starting_vertex_index] = -1;

    // --- 动态规划 ---

    // BellmanFord执行|V| - 1次"松弛所有边"
    for (unsigned int vertex_index = 0; vertex_index < graph.VertexCount() - 1; vertex_index++) {
        for (unsigned int edge_index = 0; edge_index < graph.EdgeCount(); edge_index++) {
            TVertex cur_starting_vertex = graph.GetEdge(edge_index).starting_vertex;
            TVertex cur_ending_vertex = graph.GetEdge(edge_index).ending_vertex;

            int cur_starting_vertex_index = graph.GetVertexIndex(cur_starting_vertex);
            int cur_ending_vertex_index = graph.GetVertexIndex(cur_ending_vertex);

            TWeight cur_edge_weight;
            bool res = graph.GetWeight(cur_starting_vertex, cur_ending_vertex, cur_edge_weight);
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
    for (unsigned int i = 0; i < graph.EdgeCount(); i++) {
        TVertex cur_starting_vertex = graph.GetEdge(i).starting_vertex;
        TVertex cur_ending_vertex = graph.GetEdge(i).ending_vertex;

        int cur_starting_vertex_index = graph.GetVertexIndex(cur_starting_vertex);
        int cur_ending_vertex_index = graph.GetVertexIndex(cur_ending_vertex);

        TWeight cur_weight;
        bool get_weight_done = graph.GetWeight(cur_starting_vertex, cur_ending_vertex, cur_weight);
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
 * @brief **弗洛伊德(Floyd-Warshall)最短路径**
 * @tparam TVertex 图结点类型模板参数
 * @tparam TWeight 图边权值类型模板参数
 * @param graph 图
 * @param distance 最短路径数组, distance[i][j]表示: 索引i结点到索引j结点的最短路径
 * @param predecessor 前一结点数组, predecessor[i][j]表示: 索引i结点到索引j结点最短路径中, j的前一结点
 * @note
 * Floyd-Warshall弗洛伊德最短路径算法
 * --------------------------------
 * --------------------------------
 *
 * Floyd:
 *     distance[][] is a distance matrix for n vertices.
 *     distance[i][j] is the distance to move directly from i to j.
 *         if no direct link from i to j
 *             then initialize distance[i][j] = INFINITY
 *         the distance from a node to itself is 0.(Initialize distance[i][i] = 0 for all i)
 *     predecessor[][] is a predecessor matrix. it enables you to reconstruct the shortest paths.
 *         predecessor[i][j] should be initialized to i.
 *
 * 算法执行结果:
 *     distance[i][j] contains the total cost along the shortest path from i to j.
 *     predecessor[i][j] contains the predecessor of j on the shortest path from i to j.
 * --------------------------------
 */
template<typename TVertex, typename TWeight>
void Floyd(const Graph<TVertex, TWeight>& graph, vector<vector<TWeight> >& distance, vector<vector<int> >& predecessor) {
    for (unsigned int start = 0; start < graph.VertexCount(); start++) {
        for (unsigned int end = 0; end < graph.VertexCount(); end++) {

            if (start == end) {
                distance[start][end] = TWeight();
                predecessor[start][end] = start;
            } else {
                TWeight weight;
                bool res = graph.GetWeightByVertexIndex(start, end, weight);
                if (res) {
                    distance[start][end] = weight;
                    predecessor[start][end] = start;
                } else {
                    distance[start][end] = graph.MaxWeight();
                }
            }
        }
    }

    // --- 动态规划 ---

    for (unsigned int intermediate = 0; intermediate < graph.VertexCount(); intermediate++) {
        for (unsigned int start = 0; start < graph.VertexCount(); start++) {
            for (unsigned int end = 0; end < graph.VertexCount(); end++) {

                // --- 松弛操作 ---

                // 如果
                //     边 (start  -->  intermediate)          的weight
                //      +
                //     边             (intermediate -->  end) 的weight
                //      <
                //     边 (start  -------------------->  end) 的weight
                // 则
                //     更新distance[start][end] 和 predecessor[start][end]
                if (distance[start][intermediate] + distance[intermediate][end] < distance[start][end]) {
                    distance[start][end] = distance[start][intermediate] + distance[intermediate][end];
                    predecessor[start][end] = predecessor[intermediate][end];
                }
            }
        }
    }
}


/*!
 * @brief 打印单源最短路径(SSSP)
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param graph 图
 * @param starting_vertex 起点
 * @param distance 最短路径数组, distance[i]表示: 起始结点到索引i结点的最短路径
 * @param predecessor 前一结点数组, predecessor[i]表示: 最短路径中, 索引i结点的前一结点
 */
template<typename TVertex, typename TWeight>
void PrintSingleSourceShortestPath(const Graph<TVertex, TWeight>& graph,
                                   const TVertex& starting_vertex,
                                   TWeight distance[],
                                   const int predecessor[])
{
    cout << "--- 从起始点(" << starting_vertex << ")到其他各顶点的最短路径 ---" << endl;

    int starting_vertex_index = graph.GetVertexIndex(starting_vertex);

    // 用于存放以某个结点为终点的最短路径经过的结点
    int* inverted_predecessors = new int[graph.VertexCount()];

    // 分别显示starting_vertex到各个结点的最短路径
    for (unsigned int ending_vertex_index = 0; ending_vertex_index < graph.VertexCount(); ending_vertex_index++) {
        if (ending_vertex_index == starting_vertex_index) {
            continue;
        }

        // 构造"以索引starting_vertex_idx结点(staring_vertex)为起点, 索引cur_ending_vertex_idx结点为终点"的最短路径
        int predecessor_vertex_index = ending_vertex_index;
        int inverted_predecessor_vertex_index = 0; // 最短路径结点倒序索引

        while (predecessor_vertex_index != starting_vertex_index) {
            inverted_predecessors[inverted_predecessor_vertex_index] = predecessor_vertex_index;
            predecessor_vertex_index = predecessor[predecessor_vertex_index];
            inverted_predecessor_vertex_index++;
        }

        TVertex ending_vertex;
        graph.GetVertexByIndex(ending_vertex_index, ending_vertex);

        cout << "起始点(" << starting_vertex << ")到结点(" << ending_vertex << ")的最短路径为:";
        cout << starting_vertex << " ";

        // 使用inverted_predecessor数组打印出路径, 对inverted_predecessor数组从后向前, 依次打印
        while (inverted_predecessor_vertex_index > 0) {
            inverted_predecessor_vertex_index--;
            graph.GetVertexByIndex(inverted_predecessors[inverted_predecessor_vertex_index], ending_vertex);
            cout << ending_vertex << " ";
        }

        cout << ", ";
        cout << "最短路径长度为:" << distance[ending_vertex_index] << endl;
    }

    delete[] inverted_predecessors;
}


/*!
 * 递归打印某一个起始点的最短路径(在多源最短路径中)
 * @tparam TVertex 结点模板类型
 * @tparam TWeight 边权值模板类型
 * @param graph 图(引用)
 * @param predecessor 前一结点数组, predecessor[starting_vertex_index][ending_vertex_index]表示: 索引i结点到索引j结点最短路径中, j的前一结点
 * @param starting_vertex_index
 * @param ending_vertex_index
 */
template<typename TVertex, typename TWeight>
// void PrintOneSourceShortestPathRecursive(const Graph<TVertex, TWeight>& graph,
bool PrintOneSourceShortestPathRecursive(const Graph<TVertex, TWeight>& graph,
                                         vector<vector<int> > predecessor,
                                         int starting_vertex_index,
                                         int ending_vertex_index)
{
    if (predecessor[starting_vertex_index][ending_vertex_index] == -1) {
        cout << "没有路径" << endl;
        return false;
    }

    if (starting_vertex_index != ending_vertex_index) {
        bool res = PrintOneSourceShortestPathRecursive(graph,
                                            predecessor,
                                            starting_vertex_index,
                                            predecessor[starting_vertex_index][ending_vertex_index]);
        if (!res) {
            return false;
        }
    }

    TVertex ending_vertex;
    graph.GetVertexByIndex(ending_vertex_index, ending_vertex);

    cout << ending_vertex << " ";

    return true;
}


/*!
 * @brief **打印多源最短路径(弗洛伊德Floyd等MSSP)**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param graph 图
 * @param distance 最短路径数组, distance[i][j]表示: 索引i结点到索引j结点的最短路径
 * @param predecessor 前一结点数组, predecessor[i][j]表示: 索引i结点到索引j结点最短路径中, j的前一结点
 * @note
 * 打印多源最短路径(弗洛伊德Floyd等MSSP)
 * ---------------------------------
 * ---------------------------------
 * 按照不同起始点, 分类打印
 * ---------------------------------
 */
template<typename TVertex, typename TWeight>
void PrintMultipleSourceShortestPath(const Graph<TVertex, TWeight>& graph,
                                     const vector<vector<TWeight> >& distance,
                                     const vector<vector<int> >& predecessor)
{
    for (unsigned int starting_vertex_index = 0; starting_vertex_index < graph.VertexCount(); starting_vertex_index++) {

        TVertex starting_vertex;
        graph.GetVertexByIndex(starting_vertex_index, starting_vertex);

        cout << "--- 从起始点(" << starting_vertex << ")到其他各顶点的最短路径 ---" << endl;

        for (unsigned int ending_vertex_index = 0; ending_vertex_index < graph.VertexCount(); ending_vertex_index++) {
            if (starting_vertex_index == ending_vertex_index) {
                continue;
            }

            TVertex ending_vertex;
            graph.GetVertexByIndex(ending_vertex_index, ending_vertex);

            cout << "起始点(" << starting_vertex << ")到结点(" << ending_vertex << ")的最短路径为: ";

            bool res = PrintOneSourceShortestPathRecursive(graph, predecessor, starting_vertex_index, ending_vertex_index);
            if (res) {
                cout << ", 最短路径长度为: " << distance[starting_vertex_index][ending_vertex_index] << endl;
            }

        }

        cout<<endl;
    }
}

