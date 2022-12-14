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
#include <vector>


using namespace std;


/*!
 * 最小生成树结点结构体
 * @tparam Vertex 结点类型模板参数
 * @tparam Weight 边权值类型模板参数
 */
template<class Vertex, class Weight>
struct MSTNode {
    /*! @brief 构造函数(空参数) */
    MSTNode() {};

    /*!
     * 构造函数(边权值)
     * @param weight 边权值
     */
    explicit MSTNode(Weight weight): weight(weight) {}

    /*!
     * 构造函数(边权值)
     * @param weight 边权值
     */
    MSTNode(Weight weight, Vertex starting_vertex, Vertex ending_vertex):
      weight(weight), starting_vertex(starting_vertex), ending_vertex(ending_vertex) {}

    /*!
     * 重载 <=
     * @param node MST结点
     * @return 比较结果
     */
    bool operator<=(MSTNode<Vertex, Weight>& node) { return weight <= node.weight; }

    /*!
     * 重载 >=
     * @param node MST结点
     * @return 比较结果
     */
    bool operator>=(MSTNode<Vertex, Weight>& node) { return weight >= node.weight; }

    /*!
     * 重载 >
     * @param node MST结点
     * @return 比较结果
     */
    bool operator>(MSTNode<Vertex, Weight>& node) { return weight > node.weight; }

    /*!
     * 重载 <
     * @param node MST结点
     * @return 比较结果
     */
    bool operator<(MSTNode<Vertex, Weight>& node) { return weight < node.weight; }

    Vertex ending_vertex;    //!< 尾结点
    Vertex starting_vertex;  //!< 头结点
    Weight weight;           //!< 边权重
};


/*!
 * @brief 最小生成树模板类
 * @tparam Vertex 结点类型模板参数
 * @tparam Weight 边权值类型模板参数
 * @note
 * 最小生成树的大多数算法, 利用了MST性质:
 *     假设N = { TVertex(结点), { E(边) } }是一个连通网, U是顶点集V的一个非空子集.
 *     若
 *         (u, v)是一条具有最小权值的边, 其中u ∈ U, v ∈ TVertex - U,
 *     则
 *         必存在一颗包含边(u, v)的最小生成树
 */
template<class Vertex, class Weight>
class MinSpanTree {
public:
    /*! 构造函数 */
    MinSpanTree(int size): max_size_(size), cur_size_(0) {
        array_ = new MSTNode<Vertex, Weight>[size];
    }

    /*!
     * 向MST插入结点
     * @param mst_edge_node MSTEdgeNode类型结点
     * @return 当前最小生成树边的数量
     */
    int Insert(MSTNode<Vertex, Weight>& mst_edge_node) {
        if (cur_size_ >= max_size_) {
            return -1;
        }

        array_[cur_size_] = mst_edge_node;
        cur_size_++;

        return cur_size_ - 1;
    }

    /*! @brief 显示最小生成树 */
    void Show() {
        Weight sum = 0; // 总权值
        for (int i = 0; i < cur_size_; i++) {
            sum += array_[i].weight;
            cout << "starting_vertex: " << array_[i].starting_vertex << ", ending_vertex: " << array_[i].ending_vertex << ", weight: "
                 << array_[i].weight << endl;
        }

        cout<<"最小生成树边, 总权值: "<<sum<<endl;
    }

protected:
    MSTNode<Vertex, Weight>* array_; //!< 最小生成树结点数组
    int max_size_; //!< 最大结点数
    int cur_size_; //!< 当前生成树的节点数量
};


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


// Prim算法
template<class Vertex, class Weight>
bool Prim(Graph<Vertex, Weight>& graph, MinSpanTree<Vertex, Weight>& min_span_tree);


// Kruskal最小生成树(优先队列)
template<class Vertex, class Weight>
void Kruskal(Graph<Vertex, Weight>& graph, MinSpanTree<Vertex, Weight>& min_span_tree);


// 迪杰斯特拉(Dijkstra)最短路径
template<class Vertex, class Weight>
void Dijkstra(Graph<Vertex, Weight>& graph, Vertex starting_vertex, Weight distance[], int predecessor[]);


// 迪杰斯特拉(Dijkstra)最短路径(优先队列)
template<class Vertex, class Weight>
void DijkstraByPriorityQueue(Graph<Vertex, Weight>& graph,
                             Vertex starting_vertex,
                             Weight distance[],
                             int predecessor[]);

// 迪杰斯特拉(Dijkstra)最短路径2(优先队列, 优先队列控制循环)
template<class Vertex, class Weight>
void DijkstraByPriorityQueue2(Graph<Vertex, Weight>& graph,
                             Vertex starting_vertex,
                             Weight distance[],
                             int predecessor[]);

// 迪杰斯特拉(Dijkstra)最短路径2(stl优先队列)
template<class Vertex, class Weight>
void DijkstraByStlPriorityQueue(Graph<Vertex, Weight>& graph,
                              Vertex starting_vertex,
                              Weight distance[],
                              int predecessor[]);


// 贝尔曼福特(Bellman-Ford)最短路径
template<class Vertex, class Weight>
bool BellmanFord(Graph<Vertex, Weight>& graph, Vertex starting_vertex, Weight distance[], int predecessor[]);


// 弗洛伊德(Floyd-Warshall)最短路径
template<class Vertex, class Weight>
void Floyd(Graph<Vertex, Weight>& graph, vector<vector<Weight> >& distance, vector<vector<int> >& predecessor);


// 打印单源最短路径(迪杰斯特拉Dijkstra, 贝尔曼福特BellmanFord等)
template<class Vertex, class Weight>
void PrintSingleSourceShortestPath(Graph<Vertex, Weight>& graph,
                                   Vertex starting_vertex,
                                   Weight distance[],
                                   const int predecessor[]);


// 打印多源最短路径(弗洛伊德Floyd等)
template<class Vertex, class Weight>
void PrintMultipleSourceShortestPath(Graph<Vertex, Weight>& graph,
                                     vector<vector<Weight> > distance,
                                     vector<vector<int> > predecessor);


#endif // CYBER_DASH_GRAPH_ALGORITHM_H
