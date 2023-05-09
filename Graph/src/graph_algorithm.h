/*!
 * @file graph_algorithm.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 图算法h文件
 * @version 0.2.1
 * @date 2021-02-04
 */

#ifndef CYBER_DASH_GRAPH_ALGORITHM_H
#define CYBER_DASH_GRAPH_ALGORITHM_H


#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include "graph.h"


using namespace std;


/*!
 * @brief 最小生成树模板类
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 */
template<typename TVertex, typename TWeight>
class MinimumSpanTree {
public:

    /*!
     * @brief **构造函数(边数上限)**
     * @param max_size 边数上限
     * @note
     * 构造函数
     * -------
     * -------
     *
     * -------
     * mst_edges_分配内存\n
     * **if** 内存分配失败 :\n
     * &emsp; 抛出bad_alloc()\n
     */
    explicit MinimumSpanTree(int max_size): max_size_(max_size), size_(0) {
        this->mst_edges_ = new Edge<TVertex, TWeight>[max_size];    // mst_edges_分配内存
        if (!this->mst_edges_) {                                    // if 内存分配失败
            throw bad_alloc();                                      // 抛出bad_alloc()
        }
    }

    /*!
     * @brief **插入边**
     * @param edge 边
     * @return 当前最小生成树边的数量
     * @note
     * 插入边
     * -----
     * -----
     *
     * -----
     * + **1 合法性判断**\n
     * **if** 当前边数量 >= 最大边数量 :\n
     * &emsp; 返回-1\n
     * + **2 执行插入**\n
     * &emsp; 插入到最后一项\n
     * &emsp; size_加1\n
     */
    int Insert(Edge<TVertex, TWeight>& edge) {
        // ---------- 1 合法性判断 ----------

        if (size_ >= max_size_) {   // if 当前边数量 >= 最大边数量 :
            return -1;              // 返回-1
        }

        // ---------- 2 执行插入 ----------

        mst_edges_[size_] = edge;   // 插入到最后一项
        size_++;                    // size_加1

        return size_ - 1;
    }

    /*!@brief 显示最小生成树
     * @note
     * 显示最小生成树
     * -------------
     * -------------
     *
     * -------------
     * 初始化total_weight(总权值)
     * **for loop** 遍历最小生成树 :\n
     * &emsp; 获取当前边权值\n
     * &emsp; 打印当前边信息\n
     * 打一段文本\n
     * */
    void Print() {
        // 初始化total_weight(总权值)
        TWeight total_weight = 0; // 总权值
        for (int i = 0; i < this->size_; i++) {             // for loop 遍历最小生成树
            total_weight += this->mst_edges_[i].weight;
            cout << "starting_vertex: " << this->mst_edges_[i].starting_vertex  // 获取当前边权值\n
                                        // 打一段文本\n
                 << ", ending_vertex: " << mst_edges_[i].ending_vertex          // 打印当前边信息\n
                 << ", weight: " << mst_edges_[i].weight << endl;
        }

        cout << "最小生成树边, 总权值: " << total_weight << endl;
    }

protected:
    Edge<TVertex, TWeight>* mst_edges_; //!< 最小生成树边数组
    int max_size_;                      //!< 边数上限
    int size_;                          //!< 当前边数量
};


// 图深度优先遍历
template<typename TVertex, typename TWeight>
void DfsRecursive(const Graph<TVertex, TWeight>& graph, const TVertex& vertex);


// 图深度优先遍历(递归)
template<typename TVertex, typename TWeight>
void DfsOnVertexRecursive(const Graph<TVertex, TWeight>& graph, const TVertex& vertex, set<TVertex>& visited_vertex_set);

template<typename TVertex, typename TWeight>
bool TopologicalSort(const Graph<TVertex, TWeight>& graph,
                     const TVertex& vertex,
                     vector<TVertex>& topology_sorted_list);


// 图广度优先遍历
template<typename TVertex, typename TWeight>
void Bfs(const Graph<TVertex, TWeight>& graph, const TVertex& vertex);


// 求图的连通分量
template<typename TVertex, typename TWeight>
int Components(const Graph<TVertex, TWeight>& graph);


// Prim算法
template<typename TVertex, typename TWeight>
bool Prim(const Graph<TVertex, TWeight>& graph, MinimumSpanTree<TVertex, TWeight>& min_span_tree);


// Kruskal最小生成树(优先队列)
template<typename TVertex, typename TWeight>
void Kruskal(const Graph<TVertex, TWeight>& graph, MinimumSpanTree<TVertex, TWeight>& min_span_tree);


// 迪杰斯特拉(Dijkstra)最短路径(优先队列)
template<class Vertex, class Weight>
void Dijkstra(const Graph<Vertex, Weight>& graph,
              const Vertex& starting_vertex,
              Weight distance[],
              int predecessor[]);


// 贝尔曼福特(Bellman-Ford)最短路径
template<typename Vertex, typename Weight>
bool BellmanFord(const Graph<Vertex, Weight>& graph,
                 const Vertex& starting_vertex,
                 Weight distance[],
                 int predecessor[]);


// 弗洛伊德(Floyd-Warshall)最短路径
template<class Vertex, class Weight>
void Floyd(const Graph<Vertex, Weight>& graph, vector<vector<Weight> >& distance, vector<vector<int> >& predecessor);


// 打印单源最短路径(迪杰斯特拉Dijkstra, 贝尔曼福特BellmanFord等)
template<typename TVertex, typename TWeight>
void PrintSingleSourceShortestPath(const Graph<TVertex, TWeight>& graph,
                                   const TVertex& starting_vertex,
                                   TWeight distance[],
                                   const int predecessor[]);


// 打印多源最短路径(弗洛伊德Floyd等)
template<typename TVertex, typename TWeight>
void PrintMultipleSourceShortestPath(const Graph<TVertex, TWeight>& graph,
                                     const vector<vector<TWeight> >& distance,
                                     const vector<vector<int> >& predecessor);


#endif // CYBER_DASH_GRAPH_ALGORITHM_H
