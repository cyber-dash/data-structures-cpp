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
#include "min_priority_queue.h"
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
 * 声明已访问结点集合visited_vertex_set\n\n
 * 对vertex(遍历起点)调用DfsOnVertexRecursive\n
 *
 *
 * -----------------
 */
template<typename TVertex, typename TWeight>
void DfsRecursive(const Graph<TVertex, TWeight>& graph, const TVertex& vertex) {

    set<TVertex> visited_vertex_set;                                            // 声明已访问结点集合visited_vertex_set

    DfsOnVertexRecursive(graph, vertex, visited_vertex_set);                    // 对vertex(遍历起点)调用DfsOnVertexRecursive
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
 * + **1 初始化visited_vertex_set(已访问结点集合)**\n\n
 * vertex插入到visited_vertex_set\n\n
 * + **2 遍历vertex(起点)的邻接点, 执行递归**\n\n
 * <span style="color:#E76600;font-weight:bold">( 2.1 初始化neighbor_vertex(新邻接点)和new_neighbor_exists(是否存在新邻接点) )</span>\n
 * 声明neighbor_vertex(新邻结点)\n
 * 调用GetFirstNeighborVertex,初始化neighbor_vertex和new_neighbor_exists\n\n
 * <span style="color:#E76600;font-weight:bold">( 2.2 遍历执行递归 )</span>\n
 * **while loop** 存在新邻接点 :\n\n
 * &emsp; **if** 新邻接点不在visit_vertex_set中 :\n
 * &emsp;&emsp; 对新邻接点调用DfsOnVertexRecursive<span style="color:#008040;font-weight:bold">(递归)</span>\n\n
 * &emsp; 获取下一新邻接点, 并将执行结果(是否存在下一新邻接点)赋给new_neighbor_exists\n
 * &emsp; **if** 下一新邻接点存在 :\n
 * &emsp;&emsp; 更新neighbor_vertex\n\n
 *
 *
 * --------------------
 */
template<typename TVertex, typename TWeight>
void DfsOnVertexRecursive(const Graph<TVertex, TWeight>& graph, const TVertex& vertex, set<TVertex>& visited_vertex_set) {

    cout << "访问结点: " << vertex << endl;

    // ---------- 1 起点插入已遍历结点集合 ----------

    visited_vertex_set.insert(vertex);                                                                      // vertex插入到visited_vertex_set

    // ---------- 2 遍历起点的邻接点, 执行递归 ----------

    // ( 2.1 初始化neighbor_vertex(新邻接点)和new_neighbor_exists(是否存在新邻接点) )
    TVertex neighbor_vertex;                                                                                // 声明neighbor_vertex(新邻结点)
    bool new_neighbor_exists = graph.GetFirstNeighborVertex(vertex, neighbor_vertex);                       // 调用GetFirstNeighborVertex, 初始化neighbor_vertex和new_neighbor_exists

    // ( 2.2 遍历执行递归 )
    while (new_neighbor_exists) {                                                                           // while loop 存在新邻接点
        if (visited_vertex_set.find(neighbor_vertex) == visited_vertex_set.end()) {                         // if 新邻接点不在visit_vertex_set(已访问结点集合)中
            DfsOnVertexRecursive(graph, neighbor_vertex, visited_vertex_set);                               // 对新邻接点调用DfsOnVertexRecursive(递归)
        }

        TVertex next_neighbor_vertex;                                                                       // 声明next_neighbor_vertex(下一新邻结点)
        new_neighbor_exists = graph.GetNextNeighborVertex(vertex, neighbor_vertex, next_neighbor_vertex);   // 获取下一新邻接点, 并将执行结果(是否存在下一新邻接点)赋给new_neighbor_exists

        if (new_neighbor_exists) {                                                                          // if 下一新邻接点存在
            neighbor_vertex = next_neighbor_vertex;                                                         // 更新neighbor_vertex
        }
    }
}


/*!
 * @brief **拓扑排序**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param graph 图
 * @param starting_vertex 起点
 * @param topology_sorted_list 拓扑排序列表
 * @return 执行结果
 * @note
 * 拓扑排序
 * ------
 * ------
 *
 * DFS的方式
 *
 * ------
 * <p>
 * 声明visited_vertex_set(已访问结点集合)\n\n
 * **if** 有向图 :\n
 * &emsp; 获取起点入度\n
 * &emsp; **if** 入度 > 0 :\n
 * &emsp;&emsp; 返回false\n\n
 * 对起点调用TopologicalSortRecursive_\n\n
 * 返回true\n
 * </p>
 * <hr>
 */
template<typename TVertex, typename TWeight>
bool TopologicalSort(const Graph<TVertex, TWeight>& graph,
                     const TVertex& starting_vertex,
                     vector<TVertex>& topology_sorted_list)
{
    set<TVertex> visited_vertex_set;                                                                // 声明visited_vertex_set(已访问结点集合)

    if (graph.Type() == Graph<TVertex, TWeight>::DIRECTED) {                                        // if 有向图
        int in_degree = graph.GetVertexInDegree(starting_vertex);                                   // 获取起点入度
        if (in_degree > 0) {                                                                        // if 入度 > 0
            return false;                                                                           // 返回false
        }
    }

    TopologicalSortRecursive_(graph, starting_vertex, visited_vertex_set, topology_sorted_list);    // 对起点调用TopologicalSortRecursive_

    return true;                                                                                    // 返回true
}


/*!
 * @brief **拓扑排序(递归)**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param graph 图
 * @param starting_vertex 起点
 * @param visited_vertex_set 已访问结点集合
 * @param topology_sorted_list 拓扑排序列表
 * @note
 * 拓扑排序(递归)
 * ------------
 * ------------
 *
 * DFS的方式
 *
 * ------------
 * <p>
 * + **1 起点插入已遍历结点集合**\n\n
 * 将starting_vertex插入到visited_vertex_set\n
 * 将starting_vertex插入到topology_sorted_list\n\n
 * + **2 遍历起点的邻接点, 执行递归**\n\n
 * ( 2.1 初始化neighbor_vertex(新邻接点)和new_neighbor_exists(是否存在新邻接点) )\n
 * 声明neighbor_vertex(新邻结点)\n
 * 调用GetFirstNeighborVertex,初始化neighbor_vertex和new_neighbor_exists(是否存在新邻结点)\n\n
 * ( 2.2 遍历执行递归 )\n
 * **while loop** 存在新邻接点 :\n
 * &emsp; **if** 新邻接点不在visit_vertex_set(已访问结点集合)中 :\n
 * &emsp;&emsp; 对新邻接点调用DfsOnVertexRecursive(递归)\n\n
 * &emsp; 声明next_neighbor_vertex(下一邻接点)\n
 * &emsp; 获取next_neighbor_vertex, 并将执行结果(是否存在下一新邻接点)赋给new_neighbor_exists\n\n
 * &emsp; **if** 下一新邻接点存在 :\n
 * &emsp;&emsp; 更新neighbor_vertex\n
 * </p>
 * <hr>
 */
template<typename TVertex, typename TWeight>
void TopologicalSortRecursive_(const Graph<TVertex, TWeight>& graph,
                               TVertex starting_vertex,
                               set<TVertex>& visited_vertex_set,
                               vector<TVertex>& topology_sorted_list)
{

    // ---------- 1 起点插入已遍历结点集合 ----------

    visited_vertex_set.insert(starting_vertex);                                                             // 将starting_vertex插入到visited_vertex_set
    topology_sorted_list.push_back(starting_vertex);                                                        // 将starting_vertex插入到topology_sorted_list

    // ---------- 2 遍历起点的邻接点, 执行递归 ----------

    // 2.1 初始化neighbor_vertex(新邻接点)和new_neighbor_exists(是否存在新邻接点)
    TVertex neighbor_vertex;                                                                                // 声明neighbor_vertex(新邻结点)
    bool new_neighbor_exists = graph.GetFirstNeighborVertex(starting_vertex, neighbor_vertex);              // 调用GetFirstNeighborVertex,初始化neighbor_vertex和new_neighbor_exists

    // 2.2 遍历执行递归
    while (new_neighbor_exists) {                                                                           // while loop 存在新邻接点
        if (visited_vertex_set.find(neighbor_vertex) == visited_vertex_set.end()) {                         // if 新邻接点不在visit_vertex_set(已访问结点集合)中
            TopologicalSortRecursive_(graph, neighbor_vertex, visited_vertex_set, topology_sorted_list);    // 对新邻接点调用DfsOnVertexRecursive(递归)
        }

        TVertex next_neighbor_vertex;                                                                       // 声明next_neighbor_vertex(下一邻结点)
        new_neighbor_exists = graph.GetNextNeighborVertex(starting_vertex,                                  // 获取next_neighbor_vertex, 并将执行结果(是否存在下一新邻接点)赋给new_neighbor_exists
                                                          neighbor_vertex,
                                                          next_neighbor_vertex);

        if (new_neighbor_exists) {                                                                          // if 下一新邻接点存在
            neighbor_vertex = next_neighbor_vertex;                                                         // 更新neighbor_vertex
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
 * + **1 初始化visited_vertex_set(已访问结点集合)**\n\n
 * &emsp; 声明visited_vertex_set\n
 * &emsp; 插入vertex(起点)\n\n
 * + **2 初始化visited_queue(结点队列)**\n\n
 * &emsp; 声明vertex_queue\n
 * &emsp; 起点入队\n\n
 * + **3 使用队列进行遍历**\n\n
 * &emsp; **while loop** 队列不为空 :\n
 * &emsp;&emsp; 取front_vertex(队头)\n
 * &emsp;&emsp; 队头出队\n\n
 * &emsp;&emsp; 获取neighbor_vertex(新邻接点)和new_neighbor_exists(是否存在新邻接点)\n\n
 * &emsp;&emsp; **while loop** 存在neighbor_vertex :\n\n
 * &emsp;&emsp;&emsp; **if** neighbor_vertex未被访问 :\n
 * &emsp;&emsp;&emsp;&emsp; 访问neighbor_vertex\n
 * &emsp;&emsp;&emsp;&emsp; neighbor_vertex插入visited_vertex_set\n\n
 * &emsp;&emsp;&emsp;&emsp; neighbor_vertex入队\n\n
 * &emsp;&emsp;&emsp; 获取下一邻接点\n
 * &emsp;&emsp;&emsp; **if** 下一邻接点存在 :\n
 * &emsp;&emsp;&emsp;&emsp; 用下一邻接点更新neighbor_vertex\n
 *
 *
 * ------------
 */
template<typename TVertex, typename TWeight>
void Bfs(const Graph<TVertex, TWeight>& graph, const TVertex& vertex) {

    cout<<"访问结点: "<<vertex<<endl;

    // ---------- 1 初始化visited_vertex_set(已遍历结点集合) ----------

    set<TVertex> visited_vertex_set;                                                                // 声明visited_vertex_set
    visited_vertex_set.insert(vertex);                                                              // 插入vertex(起点)

    // ---------- 2 初始化visited_queue(结点队列) ----------

    queue<TVertex> vertex_queue;                                                                    // 声明vertex_queue
    vertex_queue.push(vertex);                                                                      // 起点入队

    // ---------- 3 使用队列进行遍历结点 ----------

    while (!vertex_queue.empty()) {                                                                 // while loop 队列不为空
        TVertex front_vertex = vertex_queue.front();                                                // 取front_vertex(队头)
        vertex_queue.pop();                                                                         // 队头出队

        TVertex neighbor_vertex;
        bool new_neighbor_exists = graph.GetFirstNeighborVertex(front_vertex, neighbor_vertex);     // 获取neighbor_vertex(新邻接点)和new_neighbor_exists(是否存在新邻接点)
        while (new_neighbor_exists) {                                                               // while loop 存在新邻接点

            if (visited_vertex_set.find(neighbor_vertex) == visited_vertex_set.end()) {             // if 该新邻接点未被访问
                cout<<"访问结点: "<<neighbor_vertex<<endl;                                           // 访问新邻接点
                visited_vertex_set.insert(neighbor_vertex);                                         // 该结点插入visited_vertex_set(已访问结点集合)
                vertex_queue.push(neighbor_vertex);                                                 // 该结点入队
            }

            TVertex next_neighbor_vertex;
            new_neighbor_exists = graph.GetNextNeighborVertex(front_vertex,                         // 获取下一新邻接点, 并将执行结果(是否存在下一新邻接点)赋给new_neighbor_exists
                                                              neighbor_vertex,
                                                              next_neighbor_vertex);
            if (new_neighbor_exists) {                                                              // if 下一新邻接点存在
                neighbor_vertex = next_neighbor_vertex;                                             // 更新neighbor_vertex
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
 * + **1 边界条件处理**\n\n
 * **if** 结点数为0 :\n
 * &emsp; 返回0\n\n
 * + **2 遍历结点, 使用DFS划分联通分量**\n\n
 * 声明visited_vertex_set(已访问结点集合)\n
 * 初始化连通分量数量为1\n\n
 * **for loop** 遍历结点索引 :\n
 * &emsp; 声明vertex(当前结点)\n
 * &emsp; 获取i(当前索引)对应的结点vertex\n\n
 * &emsp; **if** 在visited_vertex_set中(则已经在某连通分量中) :\n
 * &emsp;&emsp; continue(不再处理)\n\n
 * &emsp; 使用DfsOnVertexRecursive对vertex进行遍历\n\n
 * &emsp; 连通分量数量+1\n\n
 * + **退出函数**\n\n
 * 返回连通分量数量\n
 *
 *
 * ----------
 */
template<typename TVertex, typename TWeight>
int Components(const Graph<TVertex, TWeight>& graph) {

    // ---------- 1 边界条件处理 ----------

    if (graph.VertexCount() == 0) {                                                         // if 结点数为0
        return 0;                                                                           // 返回0
    }

    // 2 ---------- 声明visited_vertex_set(已访问结点集合) ----------

    set<TVertex> visited_vertex_set;                                                        // 声明visited_vertex_set(已访问结点集合)
    int count = 1;                                                                          // 初始连通分量数量为1

    for (unsigned int i = 0; i < graph.VertexCount(); i++) {                                // for loop 遍历结点索引

        TVertex vertex;                                                                     // 声明vertex(当前结点)
        bool res = graph.GetVertexByIndex(i, vertex);                                       // 获取i(当前索引)对应的结点vertex
        if (!res) {
            continue;
        }

        if (visited_vertex_set.find(vertex) != visited_vertex_set.end()) {                  // if 在visited_vertex_set中(则已经在某连通分量中)
            continue;                                                                       // continue(不再处理)
        }

        cout << "连通分量" << count << ":" << endl;

        DfsOnVertexRecursive(graph, vertex, visited_vertex_set);                            // 使用DfsOnVertexRecursive对vertex进行遍历

        count++;                                                                            // 连通分量数量+1
        cout<<endl;
    }

    // ---------- 3 退出函数 ----------

    return count;                                                                           // 返回连通分量数量
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
 * + **1 初始化min_priority_queue(最小优先队列)和disjoint_set(并查集)**\n\n
 * 声明min_priority_queue<span style="color:#283593;font-weight:bold">(最小优先队列)</span>\n
 * 初始化disjoint_set<span style="color:#283593;font-weight:bold">(并查集)</span>, size为图结点数\n\n
 * + **2 将所有边入队到最小优先队列**\n\n
 * **for loop** 遍历边索引 :\n
 * &emsp; 获取cur_starting_vertex<span style="color:#283593;font-weight:bold">(当前边起点)</span>\n
 * &emsp; 获取cur_ending_vertex<span style="color:#283593;font-weight:bold">(当前边终点)</span>\n\n
 * &emsp; 声明weight<span style="color:#283593;font-weight:bold">(当前边权重)</span>\n
 * &emsp; 获取weight\n
 * &emsp; **if** weight存在(即边存在) :\n
 * &emsp;&emsp; 声明并初始化mst_edge<span style="color:#283593;font-weight:bold">(最小生成树边)</span>\n
 * &emsp;&emsp; 入队到min_priority_queue\n\n
 * + **3 贪心**\n\n
 * **for loop** 循环(图结点数 - 1)次 :\n
 * &emsp; 声明cur_edge<span style="color:#283593;font-weight:bold">(当前边)</span>\n
 * &emsp; min_priority_queue队头出队, 赋给cur_edge\n\n
 * &emsp; 取cur_starting_vertex_index<span style="color:#283593;font-weight:bold">(当前边的起点索引)</span>\n
 * &emsp; 取cur_ending_vertex_index<span style="color:#283593;font-weight:bold">(当前边终点索引)</span>\n\n
 * &emsp; 取cur_starting_vertex_root_index<span style="color:#283593;font-weight:bold">(当前边的起点所在并查集的根结点索引)</span>\n
 * &emsp; 取cur_ending_vertex_root_index<span style="color:#283593;font-weight:bold">(当前边的终点所在并查集的根结点索引)</span>\n\n
 * &emsp; **if** 当前边起点和当前边终点, 不在一个并查集 :\n
 * &emsp;&emsp; 将cur_edge的起点所在的并查集, 与cur_edge终点所在的并查集合并\n
 * &emsp;&emsp; cur_edge插入到min_span_tree<span style="color:#008040;font-weight:bold">(最小生成树增加1条边)</span>\n\n
 * &emsp;&emsp; 循环计数加1\n
 *
 *
 * -------------------
 */
template<typename TVertex, typename TWeight>
void Kruskal(const Graph<TVertex, TWeight>& graph, MinimumSpanTree<TVertex, TWeight>& min_span_tree) {

    // ---------- 1 初始化min_priority_queue(最小优先队列)和disjoint_set(并查集) ----------

    MinPriorityQueue<Edge<TVertex, TWeight> > min_priority_queue;                                   // 声明min_priority_queue(最小优先队列)
    DisjointSet disjoint_set(graph.VertexCount());                                                  // 初始化disjoint_set(并查集), size为图结点数

    // ---------- 2 将所有边入队到最小优先队列 ----------

    for (unsigned int i = 0; i < graph.EdgeCount(); i++) {                                          // for loop 遍历边索引
        TVertex cur_starting_vertex = graph.GetEdge(i).starting_vertex;                             // 获取cur_starting_vertex(当前边起点)
        TVertex cur_ending_vertex = graph.GetEdge(i).ending_vertex;                                 // 获取cur_ending_vertex(当前边起点)

        TWeight weight;                                                                             // 声明weight(当前边权重)
        bool res = graph.GetWeight(cur_starting_vertex, cur_ending_vertex, weight);                 // 获取weight
        if (res) {                                                                                  // if weight存在(即当前边存在)
            Edge<TVertex, TWeight> mst_edge(cur_starting_vertex, cur_ending_vertex, weight);        // 声明并初始化mst_edge(最小生成树边)
            min_priority_queue.Enqueue(mst_edge);                                                   // 入队到min_priority_queue
        }
    }

    // ---------- 3 贪心 ----------

    for (unsigned int i = 0; i < graph.VertexCount() - 1;) {                                        // for loop 循环(图结点数 - 1)次
        Edge<TVertex, TWeight> cur_edge;                                                            // 声明cur_edge(当前边)
        min_priority_queue.Dequeue(cur_edge);                                                       // min_priority_queue队头出队, 赋给cur_edge

        int cur_starting_vertex_index = graph.GetVertexIndex(cur_edge.starting_vertex);             // 取cur_starting_vertex_index(当前边的起点索引)
        int cur_ending_vertex_index = graph.GetVertexIndex(cur_edge.ending_vertex);                 // 取cur_ending_vertex_index(当前边终点索引)

        int cur_starting_vertex_root_index = disjoint_set.Find(cur_ending_vertex_index);            // 取cur_starting_vertex_root_index(当前边的起点所在并查集的根结点索引)
        int cur_ending_vertex_root_index = disjoint_set.Find(cur_starting_vertex_index);            // 取cur_ending_vertex_root_index(当前边的终点所在并查集的根结点索引)

        if (cur_starting_vertex_root_index != cur_ending_vertex_root_index) {                       // if 当前边起点和当前边终点, 不在一个并查集
            disjoint_set.Union(cur_starting_vertex_root_index, cur_ending_vertex_root_index);       // 将cur_edge的起点所在的并查集, 与cur_edge终点所在的并查集合并
            min_span_tree.Insert(cur_edge);                                                         // cur_edge插入到min_span_tree(最小生成树增加1条边)

            i++;                                                                                    // 循环计数加1
        }
    }
}


/*!
 * @brief **Prim最小生成树算法**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param graph 图
 * @param min_span_tree 最小生成树
 * @return 执行结果
 * @note
 * Prim最小生成树算法
 * ----------------
 * ----------------
 *
 * 此算法针对无向图\n\n
 * <span style="color:#FB1927">
 * 图 { Vertices(结点集合), { Edges(边集合) } }\n
 * min_span_tree: 最小生成树\n
 * mst_vertex_set: min_span_tree的结点集合\n\n
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
 * &emsp;&emsp; 直到mst_vertex_set = Vertices为止\n\n
 * 此时min_span_tree为最小生成树, 有vertex_count - 1条边\n
 * </span>
 *
 * ----------------
 * + **1 设置起点**\n\n
 * 声明starting_vertex<span style="color:#283593;font-weight:bold">(起点)</span>\n
 * 获取索引0结点, 作为起点\n
 * **if** 获取失败 :\n
 * &emsp; 返回false\n\n
 * + **2 初始化最小生成树结点集合和边的最小优先队列**\n\n
 * 声明mst_vertex_set<span style="color:#283593;font-weight:bold">(最小生成树结点集合)</span>\n
 * starting_vertex插入集合\n\n
 * 声明min_priority_queue<span style="color:#283593;font-weight:bold">(边的最小优先队列)</span>\n\n
 * + **3 贪心**\n\n
 * **while loop** 最小生成树结点集合的结点数 < 图结点数<span style="color:#008040;font-weight:bold">(即最小生成树未完成)</span> :\n\n
 * <span style="color:#E76600;font-weight:bold">( 3.1 最小优先队列队头出队, 进入最小生成树 )</span>\n
 * &emsp; **if** min_priority_queue不为空 :\n
 * &emsp;&emsp; 声明cur_min_edge<span style="color:#283593;font-weight:bold">(当前最小边)</span>\n
 * &emsp;&emsp; 队头出队, 赋值给cur_min_edge\n\n
 * &emsp;&emsp; cur_min_edge插入min_span_tree<span style="color:#283593;font-weight:bold">(最小生成树)</span>\n
 * &emsp;&emsp; cur_min_edge的终点, 插入mst_vertex_set\n\n
 * <span style="color:#E76600;font-weight:bold">( 3.2 最小优先队列队头出队, 进入最小生成树 )</span>\n
 * &emsp; **for loop** 遍历mst_vertex_set :\n
 * &emsp;&emsp; 取cur_mst_vertex<span style="color:#283593;font-weight:bold">(当前最小生成树结点)</span>\n\n
 * &emsp;&emsp; 声明cur_neighbor_vertex<span style="color:#283593;font-weight:bold">(当前邻接结点)</span>\n
 * &emsp;&emsp; 取cur_mst_vertex的首个邻接结点, 赋给cur_neighbor_vertex, 执行结果赋值给new_neighbor_exists<span style="color:#283593;font-weight:bold">(存在新的邻接结点)</span>\n\n
 * &emsp;&emsp; **while loop** 存在新的邻接结点 :\n
 * &emsp;&emsp;&emsp; **if** cur_neighbor_vertex不在最小生成树结点集合中 :\n
 * &emsp;&emsp;&emsp;&emsp; 声明cur_weight(当前边权重)\n
 * &emsp;&emsp;&emsp;&emsp; 获取 边(cur_mst_vertex ---> cur_neighbor_vertex) 的权重, 赋给cur_weight\n\n
 * &emsp;&emsp;&emsp;&emsp; 使用 边(cur_mst_vertex --- cur_neighbor_vertex) 生成cur_edge\n
 * &emsp;&emsp;&emsp;&emsp; cur_edge入队到min_priority_queue\n\n
 * &emsp;&emsp;&emsp; 获取next_neighbor_vertex<span style="color:#283593;font-weight:bold">(下一邻接结点)</span>, 并将执行结果赋给new_neighbor_exists\n\n
 * &emsp;&emsp;&emsp; **if** 下一邻接结点存在 :\n
 * &emsp;&emsp;&emsp;&emsp; 下一邻接结点赋给cur_neighbor_vertex\n
 *
 *
 * ----------------
 */
template<typename TVertex, typename TWeight>
bool Prim(const Graph<TVertex, TWeight>& graph, MinimumSpanTree<TVertex, TWeight>& min_span_tree) {

    // ---------- 1 设置起点 ----------

    TVertex starting_vertex;                                                                                // 声明starting_vertex(起点)
    bool res = graph.GetVertexByIndex(0, starting_vertex);                                                  // 获取索引0结点, 作为起点
    if (!res) {                                                                                             // if 获取失败
        return false;                                                                                       // 返回false
    }

    // ---------- 2 初始化最小生成树结点集合和边的最小优先队列 ----------

    set<TVertex> mst_vertex_set;                                                                            // 声明mst_vertex_set(最小生成树结点集合)
    mst_vertex_set.insert(starting_vertex);                                                                 // starting_vertex插入集合

    MinPriorityQueue<Edge<TVertex, TWeight> > min_priority_queue;                                           // 声明min_priority_queue(边的最小优先队列)

    // ---------- 3 贪心 ----------

    while (mst_vertex_set.size() < graph.VertexCount()) {                                                   // while loop 最小生成树结点集合的结点数 < 图结点数(最小生成树未完成)

        if (min_priority_queue.Size() != 0) {                                                               // if min_priority_queue不为空
            Edge<TVertex, TWeight> cur_min_edge;                                                            // 声明cur_min_edge(当前最小边)
            min_priority_queue.Dequeue(cur_min_edge);                                                       // 队头出队, 赋值给cur_min_edge

            min_span_tree.Insert(cur_min_edge);                                                             // cur_min_edge插入min_span_tree(最小生成树)

            mst_vertex_set.insert(cur_min_edge.ending_vertex);                                              // cur_min_edge的终点, 插入mst_vertex_set
        }

        for (typename set<TVertex>::iterator iter = mst_vertex_set.begin(); iter != mst_vertex_set.end(); iter++) {     // for loop 遍历mst_vertex_set
            TVertex cur_mst_vertex = *iter;                                                                 // 取cur_mst_vertex(当前最小生成树结点)

            TVertex cur_neighbor_vertex;                                                                    // 声明cur_neighbor_vertex(当前邻接结点)
            bool new_neighbor_exists = graph.GetFirstNeighborVertex(cur_mst_vertex, cur_neighbor_vertex);   // 取cur_mst_vertex的首个邻接结点, 赋给cur_neighbor_vertex, 执行结果赋值给new_neighbor_exists(存在新的邻接结点)

            while (new_neighbor_exists) {                                                                   // while loop 存在新的邻接结点

                if (mst_vertex_set.find(cur_neighbor_vertex) == mst_vertex_set.end()) {                     // if cur_neighbor_vertex(当前新的邻接结点)不在最小生成树结点集合中

                    TWeight cur_weight;                                                                     // 声明cur_weight(当前边权重)
                    graph.GetWeight(cur_mst_vertex, cur_neighbor_vertex, cur_weight);                       // 获取 边(cur_mst_vertex ---> cur_neighbor_vertex) 的权重, 赋给cur_weight

                    Edge<TVertex, TWeight> cur_edge(cur_mst_vertex, cur_neighbor_vertex, cur_weight);       // 使用 边(cur_mst_vertex --- cur_neighbor_vertex) 生成cur_edge

                    min_priority_queue.Enqueue(cur_edge);                                                   // 将其入队到min_priority_queue(最小优先队列)
                }

                TVertex next_neighbor_vertex;
                new_neighbor_exists = graph.GetNextNeighborVertex(cur_mst_vertex,                           // 获取next_neighbor_vertex(下一邻接结点), 并将执行结果赋给new_neighbor_exists
                                                                  cur_neighbor_vertex,
                                                                  next_neighbor_vertex);
                if (new_neighbor_exists) {                                                                  // if 下一邻接结点存在
                    cur_neighbor_vertex = next_neighbor_vertex;                                             // 下一邻接结点赋给cur_neighbor_vertex
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
 * + **1 初始化**\n\n
 * <span style="color:#FF9900;font-weight:bold">( 1.1 distance数组(起点到各点的最短路径长度)初始化 )</span>\n
 * 获取starting_vertex_index(起点索引)\n
 * **for loop** 遍历结点 :\n
 * &emsp; 路径(起点 ---> 当前结点)的最短路径, 长度设为上限值(不存在最短路径)\n\n
 * 路径(起点 ---> 起点)的最短路径, 长度设为0\n\n
 * <span style="color:#FF9900;font-weight:bold">( 1.2 min_priority_queue(最短路径的最小优先队列)初始化 )</span>\n
 * 路径(起点 ---> 起点)入队\n\n
 * <span style="color:#FF9900;font-weight:bold">( 1.3 predecessor数组(最短路径终点的前驱结点索引)初始化 )</span>\n
 * 路径(起点 ---> 起点)的最短路径, 起点的前驱结点索引为-1(即起点不存在前驱结点)\n\n
 * + **2 贪心** &emsp;&emsp;&emsp;<span style="color:#d40000">两层对结点的循环, 故时间复杂度: O(V^2)</span>\n\n
 * **while loop** 最短路径的最小优先队列不为空 :\n\n
 * &emsp; min_priority_queue队头出队, 赋给cur_min_path(从起点开始到各个结点, 当前最短的路径)\n
 * &emsp; 获取cur_min_path的终点索引, 赋给cur_min_path_ending_vertex_index\n\n
 * &emsp; **for loop** 遍历结点 :\n
 * &emsp;&emsp; 声明cur_vertex(当前结点)\n
 * &emsp;&emsp; 获取cur_vertex\n
 * &emsp;&emsp; 声明weight(边(cur_min_path的终点 ---> 当前结点)的权值)\n
 * &emsp;&emsp; 获取 边(cur_min_path.ending_vertex ---> cur_vertex) (即: 当前最短的路径的终点 ---> 当前遍历结点)\n\n
 * &emsp;&emsp; **if** 边(cur_min_path.ending_vertex ---> cur_vertex)不存在 :\n
 * &emsp;&emsp;&emsp; continue(不做处理)\n\n
 * &emsp;&emsp; **if** 路径(起点 ---> 当前最短路径的终点) + 边(当前最短路径的终点, 当前遍历结点)权值 < 路径(起点 ---> 当前遍历结点) :\n
 * &emsp;&emsp;&emsp; 路径(起点 ---> 当前遍历结点) = 路径(起点 ---> 当前最短路径的终点) + 边(当前最短路径的终点, 当前遍历结点)权值\n
 * &emsp;&emsp;&emsp; 路径(起点 ---> 当前遍历结点)中  , 当前遍历结点的前一结点的索引, 设为cur_min_path_ending_vertex_index\n\n
 * &emsp;&emsp;&emsp; 生成路径new_min_distance_path(起点 ---> 当前遍历结点)\n
 * &emsp;&emsp;&emsp; 将new_min_distance_path插入min_priority_queue(路径的最小优先队列)\n
 *
 *
 * ------------------------
 */
template<typename TVertex, typename TWeight>
void Dijkstra(const Graph<TVertex, TWeight>& graph,
               const TVertex& starting_vertex,
               TWeight distance[],
               int predecessor[])
{
    // ---------- 1 初始化 ----------

    // ( 1.1 distance数组(起点到各点的最短路径长度)初始化 )
    int starting_vertex_index = graph.GetVertexIndex(starting_vertex);                                  // 获取starting_vertex_index(起点索引)
    for (unsigned int i = 0; i < graph.VertexCount(); i++) {                                            // for loop 遍历结点
        distance[i] = graph.MaxWeight();                                                                // 路径(起点 ---> 当前结点)的最短路径, 长度设为上限值(不存在最短路径)
    }
    distance[starting_vertex_index] = 0;                                                                // 路径(起点 ---> 起点)的最短路径, 长度设为0

    // ( 1.2 min_priority_queue(最短路径的最小优先队列)初始化 )
    MinPriorityQueue<Path<TVertex, TWeight> > min_priority_queue;
    Path<TVertex, TWeight> cur_path(starting_vertex, starting_vertex, 0);
    min_priority_queue.Enqueue(cur_path);                                                               // 路径(起点 ---> 起点)入队

    // ( 1.3 predecessor数组(最短路径终点的前驱结点索引)初始化 )
    predecessor[starting_vertex_index] = -1;                                                            // 路径(起点 ---> 起点)的最短路径, 起点的前驱结点索引为-1(即起点不存在前驱结点)

    // ---------- 2 贪心 ----------

    while (min_priority_queue.Size() != 0) {                                                            // while loop 最短路径的最小优先队列不为空

        Path<TVertex, TWeight> cur_min_path;
        min_priority_queue.Dequeue(cur_min_path);                                                       // min_priority_queue队头出队, 赋给cur_min_path(从起点开始到各个结点, 当前最短的路径)

        int cur_min_path_ending_vertex_index = graph.GetVertexIndex(cur_min_path.ending_vertex);        // 获取cur_min_path的终点索引, 赋给cur_min_path_ending_vertex_index

        for (unsigned int i = 0; i < graph.VertexCount(); i++) {                                        // for loop 遍历结点

            TVertex cur_vertex;                                                                         // 声明cur_vertex(当前结点)
            graph.GetVertexByIndex(i, cur_vertex);                                                      // 获取cur_vertex

            TWeight weight;                                                                             // 声明weight(边(cur_min_path的终点 ---> 当前结点)的权值)
            bool get_weight_done = graph.GetWeight(cur_min_path.ending_vertex, cur_vertex, weight);     // 获取 边(cur_min_path.ending_vertex ---> cur_vertex) (即: 当前最短的路径的终点 ---> 当前遍历结点)
            if (!get_weight_done) {                                                                     // if 边(cur_min_path.ending_vertex ---> cur_vertex)不存在
                continue;                                                                               // continue(不做处理)
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

            if (distance[cur_min_path_ending_vertex_index] + weight < distance[i]) {                    // if 路径(起点 ---> 当前最短路径的终点) + 边(当前最短路径的终点, 当前遍历结点)权值 < 路径(起点 ---> 当前遍历结点)
                distance[i] = distance[cur_min_path_ending_vertex_index] + weight;                      // 路径(起点 ---> 当前遍历结点) = 路径(起点 ---> 当前最短路径的终点) + 边(当前最短路径的终点, 当前遍历结点)权值
                predecessor[i] = cur_min_path_ending_vertex_index;                                      // 路径(起点 ---> 当前遍历结点)中, 当前遍历结点的前一结点的索引, 设为cur_min_path_ending_vertex_index

                Path<TVertex, TWeight> new_min_distance_path(starting_vertex, cur_vertex, distance[i]); // 生成路径new_min_distance_path(起点 ---> 当前遍历结点)
                min_priority_queue.Enqueue(new_min_distance_path);                                      // 将new_min_distance_path插入min_priority_queue(路径的最小优先队列)
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
 * + **1 初始化**\n\n
 * 初始化starting_vertex_index(起点索引)\n
 * **while loop** 遍历结点索引 :\n
 * &emsp; 路径(起点 ---> 索引i结点)的最短路径, 权值(长度)初始化为MaxWeight()<span style="color:#008040;font-weight:bold">(即初始化为不存在最短路径)</span>\n\n
 * 路径(起点 ---> 起点)的最短路径, 权值(长度)初始化为0\n
 * 路径(起点 ---> 起点)的最短路径, 起点的前一结点索引设为-1<span style="color:#008040;font-weight:bold">(不存在)</span>\n\n
 * + **2 动态规划**  &emsp;&emsp;&emsp;<span style="color:#d40000">1层对结点的循环, 1层对边的循环, 故时间复杂度: O(V*E)</span>\n\n
 * **while loop** 循环(结点数 - 1)次<span style="color:#008040;font-weight:bold">(最小生成树边的数量)</span> :\n
 * &emsp; **while loop** 循环每条边 :\n\n
 * &emsp;&emsp; 取cur_starting_vertex(当前边起点)\n
 * &emsp;&emsp; 取cur_ending_vertex(当前边终点)\n\n
 * &emsp;&emsp; 取cur_starting_vertex_index(当前边起点索引)\n
 * &emsp;&emsp; 取cur_ending_vertex_index(当前边终点索引)\n\n
 * &emsp;&emsp; 声明cur_edge_weight(当前边权值)\n
 * &emsp;&emsp; 取cur_edge_weight\n
 * &emsp;&emsp; **if** 获取失败<span style="color:#008040;font-weight:bold">(即边(cur_starting_vertex ---> cur_ending_vertex)不存在)</span> :\n
 * &emsp;&emsp;&emsp; continue\n\n
 * &emsp;&emsp; <span style="color:#008040;font-weight:bold">(松弛)</span>\n
 * &emsp;&emsp; **if** (起点 ---> 当前边起点)的最短路径 + 当前边权值 < (起点 ---> 当前边终点)的最短路径 :\n
 * &emsp;&emsp;&emsp; (起点 ---> 当前边终点)的最短路径 = (起点 ---> 当前边起点)的最短路径 + 当前边权值\n
 * &emsp;&emsp;&emsp; 在(起点 ---> 当前边终点)的最短路径中, 当前边终点的前一结点, 被赋值为当前边起点\n\n
 * + **3 检查是否有负权重的回路**\n\n
 * 初始化negative_weight_cycle_exists(存在负环)为false<span style="color:#008040;font-weight:bold">(初始化为没有负权环)</span>\n\n
 * **for loop** 遍历每条边 :\n\n
 * &emsp; 取cur_starting_vertex(当前边起点)\n
 * &emsp; 取cur_ending_vertex(当前边终点)\n\n
 * &emsp; 取cur_starting_vertex_index(当前边起点索引)\n
 * &emsp; 取cur_ending_vertex_index(当前边终点索引)\n\n
 * &emsp; 声明cur_weight(当前边权值)\n
 * &emsp; 取cur_weight\n
 * &emsp; **if** 获取失败<span style="color:#008040;font-weight:bold">(即边(cur_starting_vertex ---> cur_ending_vertex)不存在)</span> :\n
 * &emsp;&emsp; continue\n\n
 * &emsp; **if** (起点 ---> 当前边起点)的最短路径 + 当前边权值 < (起点 ---> 当前边终点)的最短路径 :\n
 * &emsp;&emsp; negative_weight_cycle_exists设为true\n
 * &emsp;&emsp; 跳出循环<span style="color:#008040;font-weight:bold">(发现负权回路)</span>\n\n
 * + **4 退出函数**\n\n
 * 返回negative_weight_cycle_exists\n
 *
 *
 * ---------------------------
 */
template<typename TVertex, typename TWeight>
bool BellmanFord(const Graph<TVertex, TWeight>& graph,
                 const TVertex& starting_vertex,
                 TWeight distance[],
                 int predecessor[])
{
    // ---------- 1 初始化 ----------

    int starting_vertex_index = graph.GetVertexIndex(starting_vertex);                                          // 初始化starting_vertex_index(起点索引)
    for (unsigned int i = 0; i < graph.VertexCount(); i++) {                                                    // while loop 遍历结点索引
        distance[i] = graph.MaxWeight();                                                                        // 路径(起点 ---> 索引i结点)的最短路径, 权值(长度)初始化为MaxWeight()(即初始化为不存在最短路径)
    }
    distance[starting_vertex_index] = starting_vertex_index;                                                    // (起点 ---> 起点)的最短路径, 权值(长度)初始化为0

    predecessor[starting_vertex_index] = -1;                                                                    // (起点 ---> 起点)的最短路径, 起点的前一结点索引设为-1(不存在)

    // ---------- 2 动态规划 ----------

    for (unsigned int vertex_index = 0; vertex_index < graph.VertexCount() - 1; vertex_index++) {               // while loop 循环(结点数 - 1)次(最小生成树边的数量)
        for (unsigned int edge_index = 0; edge_index < graph.EdgeCount(); edge_index++) {                       // while loop 循环每条边

            TVertex cur_starting_vertex = graph.GetEdge(edge_index).starting_vertex;                            // 取cur_starting_vertex(当前边起点)
            TVertex cur_ending_vertex = graph.GetEdge(edge_index).ending_vertex;                                // 取cur_ending_vertex(当前边终点)

            int cur_starting_vertex_index = graph.GetVertexIndex(cur_starting_vertex);                          // 取cur_starting_vertex_index(当前边起点索引)
            int cur_ending_vertex_index = graph.GetVertexIndex(cur_ending_vertex);                              // 取cur_ending_vertex_index(当前边终点索引)

            TWeight cur_edge_weight;                                                                            // 声明cur_edge_weight(当前边权重)
            bool res = graph.GetWeight(cur_starting_vertex, cur_ending_vertex, cur_edge_weight);                // 获取cur_edge_weight
            if (!res) {                                                                                         // if 获取失败(即边(cur_starting_vertex ---> cur_ending_vertex)不存在)
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

            if (distance[cur_starting_vertex_index] + cur_edge_weight < distance[cur_ending_vertex_index]) {    // if (起点 ---> 当前边起点)的最短路径 + 当前边权值 < (起点 ---> 当前边终点)的最短路径
                distance[cur_ending_vertex_index] = distance[cur_starting_vertex_index] + cur_edge_weight;      // (起点 ---> 当前边终点)的最短路径 = (起点 ---> 当前边起点)的最短路径 + 当前边权值
                predecessor[cur_ending_vertex_index] = cur_starting_vertex_index;                               // (起点 ---> 当前边终点)的最短路径, 当前边终点的前一结点, 被赋值为当前边起点
            }
        }
    }

    // ---------- 3 检查是否有负权重的回路 ----------

    bool negative_weight_cycle_exists = false;                                                                  // 初始化negative_weight_cycle_exists为false(初始化为没有负权环)

    for (unsigned int i = 0; i < graph.EdgeCount(); i++) {                                                      // for loop 遍历每条边
        TVertex cur_starting_vertex = graph.GetEdge(i).starting_vertex;                                         // 取cur_starting_vertex(当前边起点)
        TVertex cur_ending_vertex = graph.GetEdge(i).ending_vertex;                                             // 取cur_ending_vertex(当前边终点)

        int cur_starting_vertex_index = graph.GetVertexIndex(cur_starting_vertex);                              // 取cur_starting_vertex_index(当前边起点索引)
        int cur_ending_vertex_index = graph.GetVertexIndex(cur_ending_vertex);                                  // 取cur_ending_vertex_index(当前边终点索引)

        TWeight cur_weight;                                                                                     // 声明cur_weight(当前边权值)
        bool get_weight_done = graph.GetWeight(cur_starting_vertex, cur_ending_vertex, cur_weight);             // 取cur_weight
        if (!get_weight_done) {                                                                                 // if 获取失败(即边(cur_starting_vertex ---> cur_ending_vertex)不存在)
            continue;
        }

        if (distance[cur_starting_vertex_index] + cur_weight < distance[cur_ending_vertex_index]) {             // if (起点 ---> 当前边起点)的最短路径 + 当前边权值 < (起点 ---> 当前边终点)的最短路径
            negative_weight_cycle_exists = true;                                                                // negative_weight_cycle_exists设为true
            break;                                                                                              // 跳出循环(发现负权回路)
        }
    }

    // ---------- 4 退出函数 ----------

    return negative_weight_cycle_exists;                                                                        // 返回negative_weight_cycle_exists
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
 * - **1 使用图的信息填充distance和predecessor数组**\n\n
 * **for loop** 遍历start(起点) :\n
 * &emsp; **for loop** 遍历end(终点) :\n
 * &emsp;&emsp; **if** start等于end :\n
 * &emsp;&emsp;&emsp; 路径(start ---> end)长度初始化\n
 * &emsp;&emsp;&emsp; 路径(start ---> end), start的前一结点为start\n
 * &emsp;&emsp; **else** (start不等于end):\n
 * &emsp;&emsp;&emsp; 获取边(start ---> end)的权值(长度)\n
 * &emsp;&emsp;&emsp; **if** 存在边 :\n
 * &emsp;&emsp;&emsp;&emsp; 路径(start ---> end)的长度为边权值\n
 * &emsp;&emsp;&emsp;&emsp; 路径(start ---> end), end的前一结点为start\n
 * &emsp;&emsp;&emsp; **else** (不存在边) :\n
 * &emsp;&emsp;&emsp;&emsp; 路径(start ---> end)的长度为边权值上限\n
 * &emsp;&emsp;&emsp;&emsp; 路径(start ---> end), end的前一结点不存在(predecessor[start][end]设为-1)\n\n
 * - **2 动态规划**\n\n
 * **for loop** 遍历intermediate(中间点) :\n
 * &emsp; **for loop** 遍历起点 :\n
 * &emsp;&emsp; **for loop** 遍历终点 :\n
 * &emsp;&emsp;&emsp; (松弛)\n
 * &emsp;&emsp;&emsp; **if** 路径(start ---> intermediate) + 路径(intermediate ---> end) < 路径(start ---> end) :\n
 * &emsp;&emsp;&emsp;&emsp; 路径(start ---> end) <= 路径(start ---> intermediate) + 路径(intermediate ---> end)\n
 * &emsp;&emsp;&emsp;&emsp; 路径(start ---> end)终点的前一结点, 修改为路径(intermediate ---> end)终点的前一结点\n
 *
 *
 * --------------------------------
 */
template<typename TVertex, typename TWeight>
void Floyd(const Graph<TVertex, TWeight>& graph, vector<vector<TWeight> >& distance, vector<vector<int> >& predecessor) {

    // ---------- 1 使用图的信息填充distance和predecessor数组 ----------

    for (unsigned int start = 0; start < graph.VertexCount(); start++) {                                    // for loop 遍历start(起点)
        for (unsigned int end = 0; end < graph.VertexCount(); end++) {                                      // for loop 遍历end(终点)

            if (start == end) {                                                                             // if start等于end
                distance[start][end] = TWeight();                                                           // 路径(start ---> start)长度初始化
                predecessor[start][end] = (int)start;                                                       // 路径(start ---> end), start的前一结点为start
            } else {                                                                                        // else (start不等于end)
                TWeight weight;
                bool res = graph.GetWeightByVertexIndex(start, end, weight);                                // 获取边(start ---> end)的权值(长度)
                if (res) {                                                                                  // if 存在边
                    distance[start][end] = weight;                                                          // 路径(start ---> end)的长度为边权值
                    predecessor[start][end] = (int)start;                                                   // 路径(start ---> end), end的前一结点为start
                } else {                                                                                    // else (不存在边)
                    distance[start][end] = graph.MaxWeight();                                               // 路径(start ---> end)的长度为边权值上限
                    predecessor[start][end] = -1;                                                           // 路径(start ---> end), end的前一结点不存在(predecessor[start][end]设为-1)
                }
            }
        }
    }

    // ---------- 2 动态规划 ----------

    for (unsigned int intermediate = 0; intermediate < graph.VertexCount(); intermediate++) {               // for loop 遍历intermediate(中间点)
        for (unsigned int start = 0; start < graph.VertexCount(); start++) {                                // for loop 遍历起点
            for (unsigned int end = 0; end < graph.VertexCount(); end++) {                                  // for loop 遍历终点

                // --- 松弛操作 ---

                // 如果
                //     边 (start  -->  intermediate)          的weight
                //      +
                //     边             (intermediate -->  end) 的weight
                //      <
                //     边 (start  -------------------->  end) 的weight
                // 则
                //     更新distance[start][end] 和 predecessor[start][end]

                // (松弛)
                if (distance[start][intermediate] + distance[intermediate][end] < distance[start][end]) {   // if 路径(start ---> intermediate) + 路径(intermediate ---> end) < 路径(start ---> end)
                    distance[start][end] = distance[start][intermediate] + distance[intermediate][end];     // 路径(start ---> end) <= 路径(start ---> intermediate) + 路径(intermediate ---> end)
                    predecessor[start][end] = predecessor[intermediate][end];                               // 路径(start ---> end)终点的前一结点, 修改为路径(intermediate ---> end)终点的前一结点
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
 * 打印一段文本\n\n
 * 获取起点索引\n
 * 声明inverted_predecessors(反向前驱数组), 并分配内存\n\n
 * **for loop** 遍历结点索引(当前索引作为路径终点索引) :\n\n
 * &emsp; **if** 起点索引 == 终点索引 :\n
 * &emsp;&emsp; continue\n\n
 * &emsp; 初始化cur_predecessor_index(最短路径当前结点的前驱结点索引)为ending_vertex_index(终点索引)\n
 * &emsp; 初始化i(inverted_predecessors的数组索引)为0\n\n
 * &emsp; **while loop** 当前结点的前驱结点 不等于 起点 :\n
 * &emsp;&emsp; inverted_predecessors[i]被赋值为当前结点的前驱结点\n
 * &emsp;&emsp; cur_predecessor_index更新为predecessor[cur_predecessor_index](向前驱方向进行)\n
 * &emsp;&emsp; i++(填充inverted_predecessors的下一个位置的内容)\n\n
 * &emsp; 获取当前终点的索引\n
 * &emsp; 打印一段文本\n\n
 * &emsp; (使用inverted_predecessors数组打印出路径, 对inverted_predecessor数组从后向前, 依次打印)\n
 * &emsp; **while loop** i > 0 :\n
 * &emsp;&emsp; i--\n
 * &emsp;&emsp; 获取inverted_predecessors[i]对应的结点, 赋给cur_vertex\n
 * &emsp;&emsp; 打印cur_vertex\n\n
 * &emsp; 打印一段文本\n\n
 * 释放inverted_predecessors\n
 *
 *
 * --------------------
 */
template<typename TVertex, typename TWeight>
void PrintSingleSourceShortestPath(const Graph<TVertex, TWeight>& graph,
                                   const TVertex& starting_vertex,
                                   TWeight distance[],
                                   const int predecessor[])
{
    cout << "--- 从起始点(" << starting_vertex << ")到其他各顶点的最短路径 ---" << endl;                // 打印一段文本

    int starting_vertex_index = graph.GetVertexIndex(starting_vertex);                              // 获取起点索引

    int* inverted_predecessors = new int[graph.VertexCount()];                                      // 声明inverted_predecessors(反向前驱数组), 并分配内存

    for (unsigned int ending_vertex_index = 0;                                                      // for loop 遍历结点索引(当前索引作为路径终点索引)
         ending_vertex_index < graph.VertexCount();
         ending_vertex_index++)
    {
        if (ending_vertex_index == starting_vertex_index) {                                         // if 起点索引 == 终点索引
            continue;                                                                               // continue
        }

        int cur_predecessor_index = (int)ending_vertex_index;                                       // 初始化cur_predecessor_index(最短路径当前结点的前驱结点索引)为ending_vertex_index(终点索引)
        int i = 0;                                                                                  // 初始化i(inverted_predecessors的数组索引)为0

        while (cur_predecessor_index != starting_vertex_index) {                                    // while loop 当前结点的前驱结点 不等于 起点
            inverted_predecessors[i] = cur_predecessor_index;                                       // inverted_predecessors[i]被赋值为当前结点的前驱结点
            cur_predecessor_index = predecessor[cur_predecessor_index];                             // cur_predecessor_index更新为predecessor[cur_predecessor_index](向前驱方向进行)
            i++;                                                                                    // i++(填充inverted_predecessors的下一个位置的内容)
        }

        TVertex ending_vertex;
        graph.GetVertexByIndex(ending_vertex_index, ending_vertex);                                 // 获取当前终点的索引

        cout << "起始点(" << starting_vertex << ")到结点(" << ending_vertex << ")的最短路径为:";        // 打印一段文本
        cout << starting_vertex << " ";

        // (使用inverted_predecessors数组打印出路径, 对inverted_predecessor数组从后向前, 依次打印)
        while (i > 0) {                                                                             // while loop i > 0
            i--;                                                                                    // i减1
            TVertex cur_vertex;
            graph.GetVertexByIndex(inverted_predecessors[i], cur_vertex);                           // 获取inverted_predecessors[i]对应的结点, 赋给cur_vertex
            cout << cur_vertex << " ";                                                              // 打印cur_vertex
        }

        cout << ", ";
        cout << "最短路径长度为:" << distance[ending_vertex_index] << endl;                           // 打印一段文本
    }

    delete[] inverted_predecessors;                                                                 // 释放inverted_predecessors
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
 * + **1 合法性校验**\n\n
 * **if** predecessor[starting_vertex_index][ending_vertex_index]为-1, 即起点到结点不存在最短路径 :\n
 * &emsp; 打印"没有路径"\n
 * &emsp; 返回false\n\n
 * + **2 递归执行**\n\n
 * **if** 起点索引 不等于 终点索引 :\n
 * &emsp; 对最短路径中的(**起点索引**)starting_vertex_index和
 * (**终点的前一结点索引**)predecessor[starting_vertex_index][ending_vertex_index], 调用PrintSsspInMsspRecursive\n\n
 * &emsp; **if** 执行结果失败 :\n
 * &emsp;&emsp; 返回false\n\n
 * + **3 打印结点**\n\n
 * 声明ending_vertex(终点)\n
 * 获取ending_vertex\n
 * 打印终点\n\n
 * + **4 退出函数**\n\n
 * 返回true\n
 *
 *
 * -----------------------------------
 */
template<typename TVertex, typename TWeight>
bool PrintSsspInMsspRecursive(const Graph<TVertex, TWeight>& graph,
                              vector<vector<int> > predecessor,
                              int starting_vertex_index,
                              int ending_vertex_index)
{
    // ---------- 1 合法性校验 ----------

    if (predecessor[starting_vertex_index][ending_vertex_index] == -1) {                                // if 终点的前一结点索引为-1, 即起点到结点不存在最短路径
        cout << "没有路径" << endl;                                                                      // 打印"没有路径"
        return false;                                                                                   // 返回false
    }

    // ---------- 2 递归执行 ----------

    if (starting_vertex_index != ending_vertex_index) {                                                 // if 起点索引 不等于 终点索引
        bool res = PrintSsspInMsspRecursive(graph,                                                      // 对最短路径中的起点索引和终点的前一结点索引, 调用PrintSsspInMsspRecursive
                                            predecessor,
                                            starting_vertex_index,
                                            predecessor[starting_vertex_index][ending_vertex_index]);
        if (!res) {                                                                                     // if 执行结果失败
            return false;                                                                               // 返回false
        }
    }

    // ---------- 3 打印结点 ----------

    TVertex ending_vertex;                                                                              // 声明ending_vertex(终点)
    graph.GetVertexByIndex(ending_vertex_index, ending_vertex);                                         // 获取ending_vertex

    cout << ending_vertex << " ";                                                                       // 打印ending_vertex

    // ---------- 4 退出函数 ----------

    return true;                                                                                        // 返回true
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
 *
 *
 * ---------------------------------
 */
template<typename TVertex, typename TWeight>
void PrintMultipleSourceShortestPath(const Graph<TVertex, TWeight>& graph,
                                     const vector<vector<TWeight> >& distance,
                                     const vector<vector<int> >& predecessor)
{
    for (unsigned int i = 0; i < graph.VertexCount(); i++) {                                            // for loop 遍历结点索引i

        TVertex cur_starting_vertex;
        graph.GetVertexByIndex(i, cur_starting_vertex);                                                 // 获取i对应的结点, 作为当前路径起点

        cout << "--- 从起始点(" << cur_starting_vertex << ")到其他各顶点的最短路径 ---" << endl;             // 打印一段文字

        for (unsigned int j = 0; j < graph.VertexCount(); j++) {                                        // for loop 遍历结点索引j
            if (i == j) {                                                                               // if i等于j(代表起点与终点重合)
                continue;
            }

            TVertex ending_vertex;
            graph.GetVertexByIndex(j, ending_vertex);                                                   // 获取j对应的结点, 作为当前路径终点

            cout << "起始点(" << cur_starting_vertex << ")到结点(" << ending_vertex << ")的最短路径为: ";   // 打印一段文字

            bool res = PrintSsspInMsspRecursive(graph, predecessor, i, j);                              // 对i(当前路径起点索引)和j(当前路径终点索引)调用PrintSsspInMsspRecursive
            if (res) {                                                                                  // if 存在最短路径
                cout << ", 最短路径长度为: " << distance[i][j] << endl;                                   // 打印最短路径长度
            }
        }

        cout<<endl;
    }
}


/*!
 * @brief **关键路径**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param graph 图
 * @param starting_vertex 起点
 * @return 起点索引到各结点索引的关键路径数组
 * @note
 * 关键路径
 * -------
 * -------
 * <p>
 * + **1 初始化**\n\n
 * 声明critical_paths(起点索引到各结点索引的关键路径数组)\n
 * 声明visited_vertex_index_set(已访问结点索引的集合)\n
 * 声明vertex_index_queue(结点索引队列)\n\n
 * 初始化starting_vertex_index(起点的结点索引)\n\n
 * 将starting_vertex_index插入visited_vertex_index_set\n
 * 将starting_vertex_index插入vertex_index_queue\n\n
 * **for loop** 遍历图的结点索引 :\n
 * &emsp; critical_paths各元素值初始化\n\n
 * + **2 BFS**\n\n
 * **while loop** vertex_index_queue不为空 :\n
 * &emsp; 获取队头, 作为cur_start_index(当前起点)\n
 * &emsp; 队头出队\n\n
 * &emsp;&emsp; **for loop** 遍历图结点索引, 作为cur_end_index(当前终点) :\n
 * &emsp;&emsp;&emsp; 声明cur_weight(当前边权重)\n
 * &emsp;&emsp;&emsp; 获取边(cur_start_index ---> cur_end_index)的权重, 赋给cur_weight\n
 * &emsp;&emsp;&emsp; **if** 存在边 && 参数起点到当前边起点的关键路径距离 + 当前边权重(边长) > 参数起点到当前边终点的关键路径距离 :\n
 * &emsp;&emsp;&emsp;&emsp; 当前边终点入队\n\n
 * &emsp;&emsp;&emsp; cur_end_index插入到visited_vertex_index_set\n\n
 * + **3 退出函数**\n\n
 * 返回critical_paths\n
 * </p>
 * <hr>
 */
template<typename TVertex, typename TWeight>
vector<TWeight> GetCriticalPath(const Graph<TVertex, TWeight>& graph, const TVertex& starting_vertex) {
    // ---------- 1 初始化 ----------

    vector<TWeight> critical_paths;                                                                     // 声明critical_paths(起点索引到各结点索引的关键路径数组)
    set<int> visited_vertex_index_set;                                                                  // 声明visited_vertex_index_set(已访问结点索引的集合)
    queue<int> vertex_index_queue;                                                                      // 声明vertex_index_queue(结点索引队列)

    int starting_vertex_index = graph.GetVertexIndex(starting_vertex);                                  // 初始化starting_vertex_index(起点的结点索引)
    visited_vertex_index_set.insert(starting_vertex_index);                                             // 将starting_vertex_index插入visited_vertex_index_set
    vertex_index_queue.push(starting_vertex_index);                                                     // 将starting_vertex_index插入vertex_index_queue

    for (unsigned int i = 0; i < graph.VertexCount(); i++) {                                            // for loop 遍历图的结点索引 :
        critical_paths.push_back(TWeight());                                                            // critical_paths各元素值初始化
    }

    // ---------- 2 BFS ----------
    while (!vertex_index_queue.empty()) {                                                               // while loop vertex_index_queue不为空 :
        int cur_start_index = vertex_index_queue.front();                                               // 获取队头, 作为cur_start_index(当前起点)
        vertex_index_queue.pop();                                                                       // 队头出队

        for (int cur_end_index = 0; cur_end_index < int(graph.VertexCount()); cur_end_index++) {        // for loop 遍历图结点索引, 作为cur_end_index(当前终点)
            TWeight cur_weight;                                                                         // 声明cur_weight(当前边权重)
            bool res = graph.GetWeightByVertexIndex(cur_start_index, cur_end_index, cur_weight);        // 获取边(cur_start_index ---> cur_end_index)的权重, 赋给cur_weight
            if (res && critical_paths[cur_start_index] + cur_weight > critical_paths[cur_end_index]) {
                critical_paths[cur_end_index] = critical_paths[cur_start_index] + cur_weight;
                if (visited_vertex_index_set.find(cur_end_index) == visited_vertex_index_set.end()) {   // if 存在边 && 参数起点到当前边起点的关键路径距离 + 当前边权重(边长) > 参数起点到当前边终点的关键路径距离
                    vertex_index_queue.push(cur_end_index);                                             // 当前边终点入队
                }

                visited_vertex_index_set.insert(cur_end_index);                                         // cur_end_index插入到visited_vertex_index_set
            }
        }
    }

    // ---------- 3 退出函数 ----------

    return critical_paths;                                                                              // 返回critical_paths
}
