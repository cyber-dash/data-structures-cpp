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
 * @brief **图深度优先遍历(递归)**
 * @tparam TVertex 结点类型模版参数
 * @tparam TWeight 边权值类型模板参数
 * @param graph 图
 * @param vertex 遍历起点
 * @note
 * 图深度优先遍历(递归)
 * -----------------
 * -----------------
 *
 * -----------------
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
 * &emsp;&emsp; 取当前边的cur_starting_vertex_index(**当前边起点索引**)和cur_ending_vertex_index(**当前边终点索引**)\n
 * &emsp;&emsp; 取当前边起点的cur_starting_vertex_root_index(**起点所在并查集的根节点索引**)和
 * 当前边终点的cur_ending_vertex_root_index(**终点所在并查集的根节点索引**)\n
 * &emsp;&emsp; **if** 当前边起点和当前边终点不在一个并查集 :\n
 * &emsp;&emsp;&emsp; 将当前边起点所在的并查集, 与当前边终点所在的并查集合并\n
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
 * @brief **Prim最小生成树算法**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param graph 图
 * @param min_span_tree 最小生成树
 * @note
 * Prim最小生成树算法
 * ----------------
 * ----------------
 *
 * 此算法针对无向图\n
 * \n
 * <span style="color:#FB1927">
 * 图 { Vertices(结点集合), { Edges(边集合) } }\n
 * min_span_tree: 最小生成树\n
 * mst_vertex_set: min_span_tree的结点集合\n
 * \n
 * 算法从mst_vertex_set = { starting_vertex }开始(只包含起始结点)\n
 * 循环:\n
 * &emsp;&emsp; 在所有u ∈ mst_vertex_set, v ∈ (Vertices - mst_vertex_set)的边(u, v) ∈ E中\n
 * </span>
 * ```
 *             mst_vertex_set    Vertices - mst_vertex_set
 *                   ------          ------
 *                 /       \       /       \
 *                |   u ---|------|-- v    |
 *                \       /       \       /
 *                 -------         ------
 * ```
 * <span style="color:#FB1927">
 * &emsp;&emsp; 找一条权值最小的边(starting_vertex, ending_vertex), 权值weight\n
 * &emsp;&emsp;&emsp;&emsp; 加入min_span_tree\n
 * &emsp;&emsp;&emsp;&emsp; 结点u加入mst_vertex_set\n
 * &emsp;&emsp; 直到mst_vertex_set = Vertices为止\n
 * \n
 * 此时min_span_tree为最小生成树, 有vertex_count - 1条边\n
 * </span>
 *
 * ----------------
 * + **1 设置起点**\n
 * &emsp; 获取索引0结点, 作为起点\n
 * &emsp; **if** 获取失败 :\n
 * &emsp;&emsp; 返回false\n
 * + **2 初始化最小生成树结点集合和边的最小优先队列**\n
 * &emsp; 声明mst_vertex_set(**最小生成树结点集合**)\n
 * &emsp; 起点插入集合\n
 * &emsp; 声明min_priority_queue(**边的最小优先队列**)\n
 * + **3 贪心**\n
 * &emsp; **while loop** 最小生成树结点集合的结点数 < 图结点数(**最小生成树未完成**) :\n
 * &emsp;&emsp; **if** 最小优先队列不为空 :\n
 * &emsp;&emsp;&emsp; 队头出队, 赋值给cur_min_edge(**当前最小边**)\n
 * &emsp;&emsp;&emsp; cur_min_edge插入min_span_tree(**最小生成树**)\n
 * &emsp;&emsp;&emsp; cur_min_edge的终点, 插入mst_vertex_set(**最小生成树结点集合**)\n
 * &emsp;&emsp; **for loop** 遍历mst_vertex_set :\n
 * &emsp;&emsp;&emsp; 取cur_mst_vertex(**当前最小生成树结点**)\n
 * &emsp;&emsp;&emsp; 取cur_mst_vertex(**当前最小生成树结点**)的首个邻接结点, 赋给cur_neighbor_vertex(**当前邻接结点**),
 * 执行结果赋值给new_neighbor_exists(**存在新的邻接结点**)\n
 * &emsp;&emsp;&emsp; **while loop** 存在新的邻接结点 :\n
 * &emsp;&emsp;&emsp;&emsp; **if** cur_neighbor_vertex(**当前新的邻接结点**)不在最小生成树结点集合中 :\n
 * &emsp;&emsp;&emsp;&emsp;&emsp; 获取 边(cur_mst_vertex --- cur_neighbor_vertex)\n
 * &emsp;&emsp;&emsp;&emsp;&emsp; 将其入队到min_priority_queue(**最小优先队列**)\n
 * &emsp;&emsp;&emsp;&emsp; 获取next_neighbor_vertex(**下一邻接结点**), 并将执行结果赋给new_neighbor_exists\n
 * &emsp;&emsp;&emsp;&emsp; **if** 下一邻接结点存在 :\n
 * &emsp;&emsp;&emsp;&emsp;&emsp; 下一邻接结点赋给cur_neighbor_vertex\n
 */
template<typename TVertex, typename TWeight>
bool Prim(const Graph<TVertex, TWeight>& graph, MinimumSpanTree<TVertex, TWeight>& min_span_tree) {

    // ---------- 1 设置起点 ----------
    TVertex starting_vertex;
    bool res = graph.GetVertexByIndex(0, starting_vertex);  // 获取索引0结点, 作为起点
    if (!res) {         // if 获取失败
        return false;   // 返回false
    }

    // ---------- 2 初始化最小生成树结点集合和边的最小优先队列 ----------
    set<TVertex> mst_vertex_set;                                    // 声明mst_vertex_set(最小生成树结点集合)
    mst_vertex_set.insert(starting_vertex);                         // 起点插入集合

    MinPriorityQueue<Edge<TVertex, TWeight> > min_priority_queue;   // 声明min_priority_queue(边的最小优先队列)

    // ---------- 3 贪心 ----------
    while (mst_vertex_set.size() < graph.VertexCount()) {       // while loop 最小生成树结点集合的结点数 < 图结点数(最小生成树未完成)

        if (min_priority_queue.Size() != 0) {                   // if 最小优先队列不为空
            Edge<TVertex, TWeight> cur_min_edge;
            min_priority_queue.Dequeue(cur_min_edge);           // 队头出队, 赋值给cur_min_edge(当前最小边)

            min_span_tree.Insert(cur_min_edge);                 // cur_min_edge插入min_span_tree(最小生成树)

            mst_vertex_set.insert(cur_min_edge.ending_vertex);  // cur_min_edge的终点, 插入mst_vertex_set(最小生成树结点集合)
        }

        // for loop 遍历mst_vertex_set
        for (typename set<TVertex>::iterator iter = mst_vertex_set.begin(); iter != mst_vertex_set.end(); iter++) {
            TVertex cur_mst_vertex = *iter; // 取cur_mst_vertex(当前最小生成树结点)

            // 取cur_mst_vertex(当前最小生成树结点)的首个邻接结点, 赋给cur_neighbor_vertex(当前邻接结点), 执行结果赋值给new_neighbor_exists(存在新的邻接结点)
            TVertex cur_neighbor_vertex;
            bool new_neighbor_exists = graph.GetFirstNeighborVertex(cur_mst_vertex, cur_neighbor_vertex);

            while (new_neighbor_exists) {   // while loop 存在新的邻接结点

                // if cur_neighbor_vertex(当前新的邻接结点)不在最小生成树结点集合中
                if (mst_vertex_set.find(cur_neighbor_vertex) == mst_vertex_set.end()) {

                    TWeight cur_weight;
                    graph.GetWeight(cur_mst_vertex, cur_neighbor_vertex, cur_weight);

                    // 获取 边(cur_mst_vertex --- cur_neighbor_vertex)
                    Edge<TVertex, TWeight> cur_edge(cur_mst_vertex, cur_neighbor_vertex, cur_weight);

                    // 将其入队到min_priority_queue(最小优先队列)
                    min_priority_queue.Enqueue(cur_edge);
                }

                // 获取next_neighbor_vertex(下一邻接结点), 并将执行结果赋给new_neighbor_exists
                TVertex next_neighbor_vertex;
                new_neighbor_exists = graph.GetNextNeighborVertex(cur_mst_vertex, cur_neighbor_vertex, next_neighbor_vertex);
                if (new_neighbor_exists) {                      // if 下一邻接结点存在
                    cur_neighbor_vertex = next_neighbor_vertex; // 下一邻接结点赋给cur_neighbor_vertex
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
 * + **1 初始化**\n
 *  - **1.1 distance数组(起点到各点的最短路径长度)初始化**\n
 *  &emsp; 获取starting_vertex_index(起点索引)\n
 *  &emsp; **for loop** 遍历结点 :\n
 *  &emsp;&emsp; 路径(起点 ---> 当前结点)的最短路径, 长度设为上限值(不存在最短路径)\n
 *  &emsp; 路径(起点 ---> 起点)的最短路径, 长度设为0\n
 *  - **1.2 min_priority_queue(最短路径的最小优先队列)初始化**\n
 *  &emsp; 路径(起点 ---> 起点)入队\n
 *  - **1.3 predecessor数组(最短路径终点的前驱结点索引)初始化**\n
 *  路径(起点 ---> 起点)的最短路径, 起点的前驱结点索引为-1\n
 * + **2 贪心** &emsp;&emsp;&emsp;<span style="color:#d40000">两层对结点的循环, 故时间复杂度: O(V^2)</span>\n
 * **while loop** 最短路径的最小优先队列不为空 :\n
 * &emsp; min_priority_queue队头出队, 赋给cur_min_path(从起点开始到各个结点, 当前最短的路径)\n
 * &emsp; 获取cur_min_path的终点索引, 赋给cur_min_path_ending_vertex_index\n
 * &emsp; **for loop** 遍历结点 :\n
 * &emsp;&emsp; 获取当前结点cur_vertex\n
 * &emsp;&emsp; 获取 边(cur_min_path.ending_vertex ---> cur_vertex) (即: 当前最短的路径的终点 ---> 当前遍历结点)\n
 * &emsp;&emsp; **if** 边(cur_min_path.ending_vertex ---> cur_vertex)不存在 :\n
 * &emsp;&emsp;&emsp; continue(不做处理)\n
 * &emsp;&emsp; **if** 路径(起点 ---> 当前最短路径的终点) + 边(当前最短路径的终点, 当前遍历结点)权值 < 路径(起点 ---> 当前遍历结点) :\n
 * &emsp;&emsp;&emsp; 路径(起点 ---> 当前遍历结点) = 路径(起点 ---> 当前最短路径的终点) + 边(当前最短路径的终点, 当前遍历结点)权值\n
 * &emsp;&emsp;&emsp; 路径(起点 ---> 当前遍历结点), 当前遍历结点的前一结点索引设为cur_min_path_ending_vertex_index\n
 * &emsp;&emsp;&emsp; 生成路径new_min_distance_path(起点 ---> 当前遍历结点)\n
 * &emsp;&emsp;&emsp; 将new_min_distance_path插入min_priority_queue(路径的最小优先队列)\n
 */
template<typename TVertex, typename TWeight>
void Dijkstra(const Graph<TVertex, TWeight>& graph,
               const TVertex& starting_vertex,
               TWeight distance[],
               int predecessor[])
{
    // ---------- 1 初始化 ----------

    // 1.1 distance数组(起点到各点的最短路径长度)初始化
    int starting_vertex_index = graph.GetVertexIndex(starting_vertex);  // 获取starting_vertex_index(起点索引)
    for (unsigned int i = 0; i < graph.VertexCount(); i++) {    // for loop 遍历结点
        distance[i] = graph.MaxWeight();                        // 路径(起点 ---> 当前结点)的最短路径, 长度设为上限值(不存在最短路径)
    }
    distance[starting_vertex_index] = 0;                        // 路径(起点 ---> 起点)的最短路径, 长度设为0

    // 1.2 min_priority_queue(最短路径的最小优先队列)初始化
    MinPriorityQueue<Path<TVertex, TWeight> > min_priority_queue;
    Path<TVertex, TWeight> cur_path(starting_vertex, starting_vertex, 0);
    min_priority_queue.Enqueue(cur_path);       // 路径(起点 ---> 起点)入队

    // 1.3 predecessor数组(最短路径终点的前驱结点索引)初始化
    predecessor[starting_vertex_index] = -1;    // 路径(起点 ---> 起点)的最短路径, 起点的前驱结点索引为-1

    // ---------- 2 贪心 ----------

    while (min_priority_queue.Size() != 0) {    // while loop 最短路径的最小优先队列不为空

        // min_priority_queue队头出队, 赋给cur_min_path(从起点开始到各个结点, 当前最短的路径)
        Path<TVertex, TWeight> cur_min_path;
        min_priority_queue.Dequeue(cur_min_path);

        // 获取cur_min_path的终点索引, 赋给cur_min_path_ending_vertex_index
        int cur_min_path_ending_vertex_index = graph.GetVertexIndex(cur_min_path.ending_vertex);

        for (unsigned int i = 0; i < graph.VertexCount(); i++) {    // for loop 遍历结点

            // 获取当前结点cur_vertex
            TVertex cur_vertex;
            graph.GetVertexByIndex(i, cur_vertex);

            // 获取 边(cur_min_path.ending_vertex ---> cur_vertex) (即: 当前最短的路径的终点 ---> 当前遍历结点)
            TWeight weight;
            bool get_weight_done = graph.GetWeight(cur_min_path.ending_vertex, cur_vertex, weight);
            if (!get_weight_done) {     // if 边(cur_min_path.ending_vertex ---> cur_vertex)不存在
                continue;               // continue(不做处理)
            }

            // --- 松弛操作 ---

            // 如果
            //   路径 (starting_vertex  --> cur_min_path_ending_vertex)                的weight
            //    +
            //   边                      (cur_min_path_ending_vertex  -->  cur_vertex) 的weight
            //    <
            //   路径 (starting_vertex  ---------------------------------->  cur_vertex) 的weight
            // 则
            //   更新distance[i]和predecessor[i]
            //   生成new_min_distance_path, 进入最小优先队列

            // if 路径(起点 ---> 当前最短路径的终点) + 边(当前最短路径的终点, 当前遍历结点)权值 < 路径(起点 ---> 当前遍历结点)
            if (distance[cur_min_path_ending_vertex_index] + weight < distance[i]) {
                // 路径(起点 ---> 当前遍历结点) = 路径(起点 ---> 当前最短路径的终点) + 边(当前最短路径的终点, 当前遍历结点)权值
                distance[i] = distance[cur_min_path_ending_vertex_index] + weight;
                // 路径(起点 ---> 当前遍历结点), 当前遍历结点的前一结点索引设为cur_min_path_ending_vertex_index
                predecessor[i] = cur_min_path_ending_vertex_index;

                // 生成路径new_min_distance_path(起点 ---> 当前遍历结点)
                Path<TVertex, TWeight> new_min_distance_path(starting_vertex, cur_vertex, distance[i]);
                // 将new_min_distance_path插入min_priority_queue(路径的最小优先队列)
                min_priority_queue.Enqueue(new_min_distance_path);
            }
        }
    }
}


/*!
 * @brief **Bellman-Ford贝尔曼福特最短路径**
 * @tparam TVertex 图结点模板类型
 * @tparam TWeight 图边权值模板类型
 * @param graph 图的引用
 * @param starting_vertex 起始结点
 * @param distance 最短路径数组, distance[i]表示: 起始结点到索引i结点的最短路径
 * @param predecessor 前一结点数组, predecessor[i]表示: 最短路径中, 索引i结点的前一结点
 * @return 是否有负环
 * @note
 * Bellman-Ford贝尔曼福特最短路径
 * ---------------------------
 * ---------------------------
 *
 * <span style="color:#FB1927">
 * BellmanFord算法:\n
 * \n
 * --- 初始化 ---\n
 * \n
 * &emsp;&emsp; for 图中的每个结点v:\n
 * &emsp;&emsp;&emsp;&emsp; 如果(starting_vertex, v)没有边:\n
 * &emsp;&emsp;&emsp;&emsp;&emsp;&emsp; distance[v] <-- MAX(不存在路径)\n
 * &emsp;&emsp;&emsp;&emsp; 否则:\n
 * &emsp;&emsp;&emsp;&emsp;&emsp;&emsp; 如果 v 是starting_vertex(起始点):\n
 * &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp; distance[v] = 0\n
 * &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp; predecessor[v] <-- -1(没有前一结点)\n
 * &emsp;&emsp;&emsp;&emsp;&emsp;&emsp; 否则:\n
 * &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp; distance[v] = 边(starting_vertex, v)的长度(权值)\n
 * &emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp; predecessor[v] <-- starting_vertex_index(结点starting_vertex的索引) // v的前一结点是starting_vertex
 * \n
 * \n
 * --- 动态规划 ---\n
 * \n
 * &emsp;&emsp; for循环(图结点总数 - 1)次:\n
 * &emsp;&emsp;&emsp;&emsp; for 图的每一条边edge (u, v):\n
 * &emsp;&emsp;&emsp;&emsp;&emsp;&emsp; // 松弛\n
 * &emsp;&emsp;&emsp;&emsp; 如果 distance[u] + 边(u, v)权重 < distance[v]:\n
 * &emsp;&emsp;&emsp;&emsp;&emsp;&emsp; distance[v] <-- distance[u] + 边(u, v)权重\n
 * &emsp;&emsp;&emsp;&emsp;&emsp;&emsp; predecessor[v] <-- u\n
 * \n
 * \n
 * --- 检查是否有负权重的回路 ---\n
 * \n
 * &emsp;&emsp; for 每一条边edge (u, v):\n
 * &emsp;&emsp;&emsp;&emsp; 如果 distance[u] + 边(u, v)权重 < distance[v]:\n
 * &emsp;&emsp;&emsp;&emsp;&emsp;&emsp; error "图包含负回路"\n
 * </span>
 *
 * ---------------------------
 * + **1 初始化**\n
 * 初始化starting_vertex_index(起点索引)\n
 * **while loop** 遍历结点索引 :\n
 * &emsp; (起点 ---> 索引i结点)的最短路径, 权值(长度)初始化为MaxWeight(), 即初始化为不存在最短路径\n
 * (起点 ---> 起点)的最短路径, 权值(长度)初始化为0\n
 * (起点 ---> 起点)的最短路径, 起点的前一结点索引设为-1\n
 * + **2 动态规划**  &emsp;&emsp;&emsp;<span style="color:#d40000">1层对结点的循环, 1层对边的循环, 故时间复杂度: O(V*E)</span>\n
 * **while loop** 循环VertexCount() - 1次 :\n
 * &emsp; **while loop** 循环每条边 :\n
 * &emsp;&emsp; 取当前边起点, 取当前边终点\n
 * &emsp;&emsp; 取当前边起点索引, 取当前边终点索引\n
 * &emsp;&emsp; 取当前边(cur_starting_vertex ---> cur_ending_vertex)的权重cur_edge_weight\n
 * &emsp;&emsp; **if** 不存在边(cur_starting_vertex ---> cur_ending_vertex) :\n
 * &emsp;&emsp;&emsp; continue\n
 * &emsp;&emsp; (松弛)\n
 * &emsp;&emsp; **if** (起点 ---> 当前边起点)的最短路径 + 当前边权值 < (起点 ---> 当前边终点)的最短路径 :\n
 * &emsp;&emsp;&emsp; (起点 ---> 当前边终点)的最短路径 = (起点 ---> 当前边起点)的最短路径 + 当前边权值\n
 * &emsp;&emsp;&emsp; (起点 ---> 当前边终点)的最短路径, 当前边终点的前一结点, 被赋值为当前边起点\n
 * + **3 检查是否有负权重的回路**\n
 * 初始化negative_weight_cycle_exists为false(初始化为没有负权环)\n
 * **for loop** 遍历每条边 :\n
 * &emsp; 取当前边起点, 当前边终点 :\n
 * &emsp; 取当前边起点索引, 当前边终点索引 :\n
 * &emsp;&emsp; 取当前边(cur_starting_vertex ---> cur_ending_vertex)的权重cur_edge_weight\n
 * &emsp;&emsp; **if** 不存在边(cur_starting_vertex ---> cur_ending_vertex) :\n
 * &emsp;&emsp;&emsp; continue\n
 * &emsp;&emsp; **if** (起点 ---> 当前边起点)的最短路径 + 当前边权值 < (起点 ---> 当前边终点)的最短路径 :\n
 * &emsp;&emsp;&emsp; negative_weight_cycle_exists设为true\n
 * &emsp;&emsp;&emsp; 跳出循环(发现负权回路)\n
 * 返回negative_weight_cycle_exists\n
 */
template<typename TVertex, typename TWeight>
bool BellmanFord(const Graph<TVertex, TWeight>& graph,
                 const TVertex& starting_vertex,
                 TWeight distance[],
                 int predecessor[])
{
    // ---------- 1 初始化 ----------

    int starting_vertex_index = graph.GetVertexIndex(starting_vertex);  // 初始化starting_vertex_index(起点索引)
    for (unsigned int i = 0; i < graph.VertexCount(); i++) {    // while loop 遍历结点索引
        distance[i] = graph.MaxWeight();                        // (起点 ---> 索引i结点)的最短路径, 权值(长度)初始化为MaxWeight(), 即初始化为不存在最短路径
    }
    distance[starting_vertex_index] = starting_vertex_index;    // (起点 ---> 起点)的最短路径, 权值(长度)初始化为0

    predecessor[starting_vertex_index] = -1;                    // (起点 ---> 起点)的最短路径, 起点的前一结点索引设为-1

    // ---------- 2 动态规划 ----------

    for (unsigned int vertex_index = 0; vertex_index < graph.VertexCount() - 1; vertex_index++) {   // while loop 循环VertexCount() - 1次
        for (unsigned int edge_index = 0; edge_index < graph.EdgeCount(); edge_index++) {           // while loop 循环每条边
            // 取当前边起点, 取当前边终点
            TVertex cur_starting_vertex = graph.GetEdge(edge_index).starting_vertex;
            TVertex cur_ending_vertex = graph.GetEdge(edge_index).ending_vertex;

            // 取当前边起点索引, 取当前边终点索引
            int cur_starting_vertex_index = graph.GetVertexIndex(cur_starting_vertex);
            int cur_ending_vertex_index = graph.GetVertexIndex(cur_ending_vertex);

            TWeight cur_edge_weight;
            // 取当前边(cur_starting_vertex ---> cur_ending_vertex)的权重cur_edge_weight
            bool res = graph.GetWeight(cur_starting_vertex, cur_ending_vertex, cur_edge_weight);
            if (!res) {     // if 不存在边(cur_starting_vertex ---> cur_ending_vertex)
                continue;
            }

            // --- 松弛 ---
            // 如果
            //   边 (starting_vertex  --> cur_starting_vertex)                         的weight
            //    +
            //   边                      (cur_starting_vertex  -->  cur_ending_vertex) 的weight
            //    <
            //   边 (starting_vertex  --------------------------->  cur_ending_vertex) 的weight
            // 则
            //   更新distance[cur_ending_vertex_index]和predecessor[cur_ending_vertex_index]

            // if (起点 ---> 当前边起点)的最短路径 + 当前边权值 < (起点 ---> 当前边终点)的最短路径
            if (distance[cur_starting_vertex_index] + cur_edge_weight < distance[cur_ending_vertex_index]) {
                // (起点 ---> 当前边终点)的最短路径 = (起点 ---> 当前边起点)的最短路径 + 当前边权值
                distance[cur_ending_vertex_index] = distance[cur_starting_vertex_index] + cur_edge_weight;
                // (起点 ---> 当前边终点)的最短路径, 当前边终点的前一结点, 被赋值为当前边起点
                predecessor[cur_ending_vertex_index] = cur_starting_vertex_index;
            }
        }
    }

    // ---------- 3 检查是否有负权重的回路 ----------

    bool negative_weight_cycle_exists = false;  // 初始化negative_weight_cycle_exists为false(初始化为没有负权环)

    for (unsigned int i = 0; i < graph.EdgeCount(); i++) {  // for loop 遍历每条边
        // 取当前边起点, 当前边终点
        TVertex cur_starting_vertex = graph.GetEdge(i).starting_vertex;
        TVertex cur_ending_vertex = graph.GetEdge(i).ending_vertex;

        // 取当前边起点索引, 当前边终点索引
        int cur_starting_vertex_index = graph.GetVertexIndex(cur_starting_vertex);
        int cur_ending_vertex_index = graph.GetVertexIndex(cur_ending_vertex);

        TWeight cur_weight;
        // 取当前边(cur_starting_vertex ---> cur_ending_vertex)的权重cur_edge_weight
        bool get_weight_done = graph.GetWeight(cur_starting_vertex, cur_ending_vertex, cur_weight);
        if (!get_weight_done) { // if 不存在边(cur_starting_vertex ---> cur_ending_vertex)
            continue;
        }

        // if (起点 ---> 当前边起点)的最短路径 + 当前边权值 < (起点 ---> 当前边终点)的最短路径
        if (distance[cur_starting_vertex_index] + cur_weight < distance[cur_ending_vertex_index]) {
            negative_weight_cycle_exists = true;    // negative_weight_cycle_exists设为true
            break;                                  // 跳出循环(发现负权回路)
        }
    }

    return negative_weight_cycle_exists;    // 返回negative_weight_cycle_exists
}


/*!
 * @brief **Floyd-Warshall弗洛伊德最短路径算法**
 * @tparam TVertex 图结点类型模板参数
 * @tparam TWeight 图边权值类型模板参数
 * @param graph 图
 * @param distance 最短路径数组
 * @param predecessor 前一结点数组
 * @note
 * Floyd-Warshall弗洛伊德最短路径算法
 * --------------------------------
 * --------------------------------
 *
 * <span style="color:#DF5A00">
 * distance[i][j]表示: 索引i结点到索引j结点的最短路径\n
 * predecessor[i][j]表示: 索引i结点到索引j结点的最短路径中, j的前一结点\n
 * <span style="color:#DF5A00">
 *
 * <span style="color:#65000b">
 * Floyd:\n
 * &emsp; distance[][] is a distance matrix for n vertices.\n
 * &emsp; distance[i][j] is the distance to move directly from i to j.\n
 * &emsp; if no direct link from i to j\n
 * &emsp;&emsp; then initialize distance[i][j] = INFINITY\n
 * &emsp; the distance from a node to itself is 0.(Initialize distance[i][i] = 0 for all i)\n
 * \n
 * &emsp; predecessor[][] is a predecessor matrix. it enables you to reconstruct the shortest paths.\n
 * &emsp; predecessor[i][j] should be initialized to i.\n
 * \n
 * 算法执行结果:\n
 * &emsp; distance[i][j] contains the total cost along the shortest path from i to j.\n
 * &emsp; predecessor[i][j] contains the predecessor of j on the shortest path from i to j.\n
 * </span>
 *
 * --------------------------------
 *
 * - **1 使用图的信息填充distance和predecessor数组**\n
 * **for loop** 遍历start(起点) :\n
 * &emsp; **for loop** 遍历end(终点) :\n
 * &emsp;&emsp; **if** start等于end :\n
 * &emsp;&emsp;&emsp; 路径(start ---> start)长度初始化\n
 * &emsp;&emsp;&emsp; 路径(start ---> start), start的前一结点为start\n
 * &emsp;&emsp; **else** (start不等于end):\n
 * &emsp;&emsp;&emsp; 获取边(start ---> end)的权值(长度)\n
 * &emsp;&emsp;&emsp; **if** 存在边 :\n
 * &emsp;&emsp;&emsp;&emsp; 路径(start ---> end)的长度为边权值\n
 * &emsp;&emsp;&emsp;&emsp; 路径(start ---> end), end的前一结点为start\n
 * &emsp;&emsp;&emsp; **else** (不存在边) :\n
 * &emsp;&emsp;&emsp;&emsp; 路径(start ---> end)的长度为边权值上限\n
 * &emsp;&emsp;&emsp;&emsp; 路径(start ---> end), end的前一结点不存在(predecessor[start][end]设为-1)\n
 * - **2 动态规划**\n
 * **for loop** 遍历intermediate(中间点) :\n
 * &emsp; **for loop** 遍历起点 :\n
 * &emsp;&emsp; **for loop** 遍历终点 :\n
 * &emsp;&emsp;&emsp; (松弛)\n
 * &emsp;&emsp;&emsp; **if** 路径(start ---> intermediate) + 路径(intermediate ---> end) < 路径(start ---> end) :\n
 * &emsp;&emsp;&emsp;&emsp; 路径(start ---> end) <= 路径(start ---> intermediate) + 路径(intermediate ---> end)\n
 * &emsp;&emsp;&emsp;&emsp; 路径(start ---> end)终点的前一结点 <= 路径(intermediate ---> end)终点的前一结点\n
 */
template<typename TVertex, typename TWeight>
void Floyd(const Graph<TVertex, TWeight>& graph, vector<vector<TWeight> >& distance, vector<vector<int> >& predecessor) {

    // ---------- 1 使用图的信息填充distance和predecessor数组 ----------
    for (unsigned int start = 0; start < graph.VertexCount(); start++) {
        for (unsigned int end = 0; end < graph.VertexCount(); end++) {

            if (start == end) {
                distance[start][end] = TWeight();
                predecessor[start][end] = (int)start;
            } else {
                TWeight weight;
                bool res = graph.GetWeightByVertexIndex(start, end, weight);
                if (res) {
                    distance[start][end] = weight;
                    predecessor[start][end] = (int)start;
                } else {
                    distance[start][end] = graph.MaxWeight();
                    predecessor[start][end] = -1;
                }
            }
        }
    }

    // ---------- 2 动态规划 ----------

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
 * @brief **打印单源最短路径(SSSP)**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param graph 图
 * @param starting_vertex 起点
 * @param distance 最短路径数组, distance[i]表示: 起始结点到索引i结点的最短路径
 * @param predecessor 前一结点数组, predecessor[i]表示: 最短路径中, 索引i结点的前一结点
 * @note
 * 打印单源最短路径(SSSP)
 * --------------------
 * --------------------
 *
 * distance[i]表示: 起始结点到索引i结点的最短路径\n
 * predecessor[i]表示: 最短路径中, 索引i结点的前一结点\n
 *
 * --------------------
 * 打印一段文本\n
 * 获取起点索引\n
 * 声明inverted_predecessors(反向前驱数组), 并分配内存\n
 * **for loop** 遍历结点索引(当前索引作为路径终点索引) :\n
 * &emsp; **if** 起点索引 等于 终点索引 :\n
 * &emsp;&emsp; continue\n
 * &emsp; 初始化cur_predecessor_index(最短路径当前结点的前驱结点索引)为ending_vertex_index(终点索引)\n
 * &emsp; 初始化i(inverted_predecessors的数组索引)为0\n
 * &emsp; **while loop** 当前结点的前驱结点 不等于 起点 :\n
 * &emsp;&emsp; inverted_predecessors[i]被赋值为当前结点的前驱结点\n
 * &emsp;&emsp; cur_predecessor_index更新为predecessor[cur_predecessor_index](向前驱方向进行)\n
 * &emsp;&emsp; i++(填充inverted_predecessors的下一个位置的内容)\n
 * &emsp;&emsp; 获取当前终点的索引\n
 * &emsp;&emsp; 打印一段文本\n
 * &emsp;&emsp; (使用inverted_predecessors数组打印出路径, 对inverted_predecessor数组从后向前, 依次打印)\n
 * &emsp;&emsp; **while loop** i > 0 :\n
 * &emsp;&emsp;&emsp; i--\n
 * &emsp;&emsp;&emsp; 获取inverted_predecessors[i]对应的结点, 赋给cur_vertex\n
 * &emsp;&emsp;&emsp; 打印cur_vertex\n
 * &emsp; 打印一段文本\n
 * 释放inverted_predecessors\n
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
        int cur_predecessor_index = (int)ending_vertex_index;
        int i = 0; // 最短路径结点倒序索引

        while (cur_predecessor_index != starting_vertex_index) {
            inverted_predecessors[i] = cur_predecessor_index;
            cur_predecessor_index = predecessor[cur_predecessor_index];
            i++;
        }

        TVertex ending_vertex;
        graph.GetVertexByIndex(ending_vertex_index, ending_vertex);

        cout << "起始点(" << starting_vertex << ")到结点(" << ending_vertex << ")的最短路径为:";
        cout << starting_vertex << " ";

        // 使用inverted_predecessor数组打印出路径, 对inverted_predecessor数组从后向前, 依次打印
        while (i > 0) {
            i--;
            TVertex cur_vertex;
            graph.GetVertexByIndex(inverted_predecessors[i], cur_vertex);
            cout << cur_vertex << " ";
        }

        cout << ", ";
        cout << "最短路径长度为:" << distance[ending_vertex_index] << endl;
    }

    delete[] inverted_predecessors;
}


/*!
 * @brief **打印单源最短路径(在多源最短路径中)(递归)**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param graph 图
 * @param predecessor 前一结点数组
 * @param starting_vertex_index 起点索引
 * @param ending_vertex_index 终点索引
 * @note
 * 打印单源最短路径(在多源最短路径中)(递归)
 * -----------------------------------
 * -----------------------------------
 *
 * <span style="color:#893834">
 * **Sssp**: Single source shortest path, 单源最短路径\n
 * **Mssp**: Multiple source shortest path, 单源最短路径\n
 * **predecessor[i][j]**: 路径(索引i结点 ----> 索引j结点)的最短路径中, 索引j结点的前一结点\n
 * </span>
 *
 * -----------------------------------
 * + **1 合法性校验**\n
 * &emsp; **if** predecessor[starting_vertex_index][ending_vertex_index]为-1, 即起点到结点不存在最短路径 :\n
 * &emsp;&emsp; 打印"没有路径"\n
 * &emsp;&emsp; 返回false\n
 * + **2 递归执行**\n
 * &emsp; **if** 起点索引 不等于 终点索引 :\n
 * &emsp;&emsp; 对最短路径中的(**起点索引**)starting_vertex_index和
 * (**终点的前一结点索引**)predecessor[starting_vertex_index][ending_vertex_index], 调用PrintSsspInMsspRecursive\n
 * &emsp;&emsp; **if** 执行结果失败 :\n
 * &emsp;&emsp;&emsp; 返回false\n
 * + **3 打印结点**\n
 * &emsp; 获取终点\n
 * &emsp; 打印终点\n
 */
template<typename TVertex, typename TWeight>
bool PrintSsspInMsspRecursive(const Graph<TVertex, TWeight>& graph,
                              vector<vector<int> > predecessor,
                              int starting_vertex_index,
                              int ending_vertex_index)
{
    // ---------- 1 合法性校验 ----------

    // if predecessor[starting_vertex_index][ending_vertex_index]为-1, 即起点到结点不存在最短路径
    if (predecessor[starting_vertex_index][ending_vertex_index] == -1) {
        cout << "没有路径" << endl;                                         // 打印"没有路径"
        return false;                                                      // 返回false
    }

    // ---------- 2 递归执行 ----------

    if (starting_vertex_index != ending_vertex_index) {     // if 起点索引 不等于 终点索引
        // 对最短路径中的(起点索引)starting_vertex_index和(终点的前一结点索引)predecessor[starting_vertex_index][ending_vertex_index], 调用PrintSsspInMsspRecursive
        bool res = PrintSsspInMsspRecursive(graph,
                                            predecessor,
                                            starting_vertex_index,
                                            predecessor[starting_vertex_index][ending_vertex_index]);
        if (!res) {         // if 执行结果失败
            return false;   // 返回false
        }
    }

    // ---------- 3 打印结点 ----------

    TVertex ending_vertex;
    graph.GetVertexByIndex(ending_vertex_index, ending_vertex);     // 获取终点

    cout << ending_vertex << " ";                                   // 打印终点

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
 *
 * 按照不同起始点, 分类打印
 *
 * ---------------------------------
 * **for loop** 遍历结点索引i :\n
 * &emsp; 获取i对应的结点, 作为当前路径起点\n
 * &emsp; 打印一段文字\n
 * &emsp; **for loop** 遍历结点索引j :\n
 * &emsp;&emsp; **if** i等于j(代表起点与终点重合) :\n
 * &emsp;&emsp;&emsp; continue\n
 * &emsp;&emsp; 获取j对应的结点, 作为当前路径终点\n
 * &emsp;&emsp; 打印一段文字\n
 * &emsp;&emsp; 对i(当前路径起点索引)和j(当前路径终点索引)调用PrintSsspInMsspRecursive\n
 * &emsp;&emsp; **if** 存在最短路径 :\n
 * &emsp;&emsp;&emsp; 打印最短路径长度\n
 */
template<typename TVertex, typename TWeight>
void PrintMultipleSourceShortestPath(const Graph<TVertex, TWeight>& graph,
                                     const vector<vector<TWeight> >& distance,
                                     const vector<vector<int> >& predecessor)
{
    for (unsigned int i = 0; i < graph.VertexCount(); i++) {        // for loop 遍历结点索引i

        TVertex cur_starting_vertex;
        graph.GetVertexByIndex(i, cur_starting_vertex);             // 获取i对应的结点, 作为当前路径起点

        cout << "--- 从起始点(" << cur_starting_vertex << ")到其他各顶点的最短路径 ---" << endl;   // 打印一段文字

        for (unsigned int j = 0; j < graph.VertexCount(); j++) {    // for loop 遍历结点索引j
            if (i == j) {   // if i等于j(代表起点与终点重合)
                continue;
            }

            TVertex ending_vertex;
            graph.GetVertexByIndex(j, ending_vertex);   // 获取j对应的结点, 作为当前路径终点

            cout << "起始点(" << cur_starting_vertex << ")到结点(" << ending_vertex << ")的最短路径为: ";   // 打印一段文字

            bool res = PrintSsspInMsspRecursive(graph, predecessor, i, j); // 对i(当前路径起点索引)和j(当前路径终点索引)调用PrintSsspInMsspRecursive
            if (res) {                                                     // if 存在最短路径
                cout << ", 最短路径长度为: " << distance[i][j] << endl;      // 打印最短路径长度
            }
        }

        cout<<endl;
    }
}

