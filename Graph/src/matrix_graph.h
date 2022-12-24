/*!
 * @file matrix_graph.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 矩阵图模板类
 * @version 0.2.1
 * @date 2021-07-14
 */

#ifndef CYBER_DASH_MATRIX_GRAPH_H
#define CYBER_DASH_MATRIX_GRAPH_H


#include <iostream>
#include <map>
#include "graph.h"


using namespace std;


template<typename TVertex, typename TWeight> class MatrixGraph;
// 输入图(重载标准输入)
template<typename TVertex, typename TWeight>
istream& operator>>(istream& in, MatrixGraph<TVertex, TWeight>& graph);
// 打印图(重载标准输出)
template<typename TVertex, typename TWeight>
ostream& operator<<(ostream& out, MatrixGraph<TVertex, TWeight>& graph);


/*!
 * @brief **矩阵图模板类**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 */
template<typename TVertex, typename TWeight>
class MatrixGraph: public Graph<TVertex, TWeight> {

public:
    // 构造函数
    MatrixGraph(int max_vertex_count, TWeight max_weight);

    // 构造函数(边/结点vector)
    MatrixGraph(int max_vertex_count,
                TWeight max_weight,
                const vector<Edge<TVertex, TWeight> >& edges,
                const vector<TVertex>& vertices);

    // 析构函数
    ~MatrixGraph();

    // 获取结点(by结点索引)
    bool GetVertexByIndex(int vertex_index, TVertex& vertex) const;

    // 获取边权值(by结点)
    bool GetWeight(const TVertex& starting_vertex, const TVertex& ending_vertex, TWeight& weight) const;

    // 获取边权值(by结点索引)
    bool GetWeightByVertexIndex(int starting_vertex_index, int ending_vertex_index, TWeight& weight) const;

    // 获取结点的第一个相邻结点
    bool GetFirstNeighborVertex(const TVertex& vertex, TVertex& first_neighbor) const;

    // 获取结点的下一个相邻结点
    bool GetNextNeighborVertex(const TVertex& vertex,
                               const TVertex& neighbor_vertex,
                               TVertex& next_neighbor_vertex) const;

    // 插入结点
    bool InsertVertex(const TVertex& vertex);

    // 插入边
    bool InsertEdge(const TVertex& starting_vertex, const TVertex& ending_vertex, const TWeight& weight);

    // 删除结点
    bool RemoveVertex(const TVertex& vertex);

  /*!
   * @brief 删除边
   * @param starting_vertex 起点
   * @param ending_vertex 终点
   * @return 执行结果
   */
  bool RemoveEdge(const TVertex& starting_vertex, const TVertex& ending_vertex);

    /*!
     * @brief **获取结点索引**
     * @param vertex 结点
     * @return 结点索引
     * @note
     * 获取结点索引
     * ----------
     * ----------
     *
     * ----------
     */
    int GetVertexIndex(TVertex vertex) const;

    friend istream& operator>> <>(istream& in, MatrixGraph<TVertex, TWeight>& graph_matrix);
    friend ostream& operator<< <>(ostream& out, MatrixGraph<TVertex, TWeight>& graph_matrix);

    void PrintMatrix();
private:
    TWeight** adjacency_matrix_; //!< 邻接矩阵
};


/*!
 * @brief **构造函数**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param max_vertex_count 结点数上限
 * @param max_weight 边权值上限
 * @note
 * 构造函数
 * -------
 * -------
 *
 * -------
 */
template<typename TVertex, typename TWeight>
MatrixGraph<TVertex, TWeight>::MatrixGraph(int max_vertex_count, TWeight max_weight) {
    this->max_weight_ = max_weight;
    this->max_vertex_count_ = max_vertex_count;

    this->vertex_count_ = 0;
    this->edge_count_ = 0;

    this->adjacency_matrix_ = new TWeight*[this->max_vertex_count_];
    if (!this->adjacency_matrix_) {
        throw bad_alloc();
    }

    for (int row = 0; row < this->max_vertex_count_; row++) {
        this->adjacency_matrix_[row] = new TWeight[this->max_vertex_count_]; // 节点i对应的所有边
        if (!this->adjacency_matrix_[row]) {
            throw bad_alloc();
        }

        for (int col = 0; col < this->max_vertex_count_; col++) {
            this->adjacency_matrix_[row][col] = TWeight();
        }
    }
}


/*!
 * @brief **构造函数(边/结点vector)**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param max_vertex_count 结点数上限
 * @param max_weight 边权值上限
 * @param edges 边vector
 * @param vertices 结点vector
 * @note
 * 构造函数(边/结点vector)
 * ---------------------
 * ---------------------
 *
 * ---------------------
 */
template<typename TVertex, typename TWeight>
MatrixGraph<TVertex, TWeight>::MatrixGraph(int max_vertex_count,
                                           TWeight max_weight,
                                           const vector<Edge<TVertex, TWeight> >& edges,
                                           const vector<TVertex>& vertices)
{
    this->max_weight_ = max_weight;
    this->max_vertex_count_ = max_vertex_count;

    this->vertex_count_ = 0;
    this->edge_count_ = 0;

    this->adjacency_matrix_ = new TWeight*[this->max_vertex_count_];
    if (!this->adjacency_matrix_) {
        throw bad_alloc();
    }

    for (int row = 0; row < this->max_vertex_count_; row++) {
        this->adjacency_matrix_[row] = new TWeight[this->max_vertex_count_]; // 节点i对应的所有边
        if (!this->adjacency_matrix_) {
            throw bad_alloc();
        }

        for (int col = 0; col < this->max_vertex_count_; col++) {
            this->adjacency_matrix_[row][col] = TWeight();
        }
    }

    for (unsigned int i = 0; i < vertices.size(); i++) {
        this->InsertVertex(vertices[i]);
    }

    for (unsigned int i = 0; i < edges.size(); i++) {
        this->InsertEdge(edges[i].starting_vertex, edges[i].ending_vertex, edges[i].weight);
    }
}


/*!
 * @brief **析构函数**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @note
 * 析构函数
 * -------
 * -------
 *
 * -------
 */
template<typename TVertex, typename TWeight>
MatrixGraph<TVertex, TWeight>::~MatrixGraph() {
    for (int row = 0; row < this->vertex_count_; row++) {
        delete[] this->adjacency_matrix_[row];
    }

    delete[] this->adjacency_matrix_;
}


/*!
 * @brief **获取结点(by结点索引)**
 * @param vertex_index 结点索引
 * @param vertex 结点保存遍历
 * @return 执行结果
 * @note
 * 获取结点(by结点索引)
 * -----------------
 * -----------------
 *
 * -----------------
 */
template<typename TVertex, typename TWeight>
bool MatrixGraph<TVertex, TWeight>::GetVertexByIndex(int vertex_index, TVertex& vertex) const {
    if (vertex_index < 0 && vertex_index >= this->vertex_count_) {
        return false;
    }

    vertex = this->vertices_[vertex_index];

    return true;
}


/*!
 * @brief 获取边权值(by结点)
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param weight 边权值保存变量
 * @param starting_vertex 起点
 * @param ending_vertex 终点
 * @return 执行结果
 * @note
 * 获取边权值(by结点)
 * ----------------
 * ----------------
 *
 * ----------------
 */
template<typename Vertex, typename Weight>
bool MatrixGraph<Vertex, Weight>::GetWeight(const Vertex& starting_vertex,
                                            const Vertex& ending_vertex,
                                            Weight& weight) const
{
    int starting_vertex_index = GetVertexIndex(starting_vertex);
    int ending_vertex_index = GetVertexIndex(ending_vertex);
    if (starting_vertex_index < 0 || ending_vertex_index < 0) {
        return false;
    }

    bool res = GetWeightByVertexIndex(starting_vertex_index, ending_vertex_index, weight);
    if (!res) {
        return false;
    }

    return true;
}


/*!
 * @brief 获取边权值(by结点索引)
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param starting_vertex_index 起点结点索引
 * @param ending_vertex_index 终点结点索引
 * @param weight 边权值
 * @return 执行结果
 * @note
 * 获取边权值(by结点索引)
 * -------------------
 * -------------------
 *
 * -------------------
 */
template<typename TVertex, typename TWeight>
bool MatrixGraph<TVertex, TWeight>::GetWeightByVertexIndex(int starting_vertex_index,
                                                           int ending_vertex_index,
                                                           TWeight& weight) const
{
    if (starting_vertex_index < 0 || ending_vertex_index < 0 || starting_vertex_index == ending_vertex_index ||
        adjacency_matrix_[starting_vertex_index][ending_vertex_index] == 0)
    {
        return false;
    }

    weight = adjacency_matrix_[starting_vertex_index][ending_vertex_index];

    return true;
}


/*!
 * @brief 获取结点的第一个相邻结点
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param vertex 结点
 * @param first_neighbor 第一个相邻结点保存变量
 * @return 执行结果
 * @note
 * 获取结点的第一个相邻结点
 * --------------------
 * --------------------
 *
 * --------------------
 */
template<typename TVertex, typename TWeight>
bool MatrixGraph<TVertex, TWeight>::GetFirstNeighborVertex(const TVertex& vertex, TVertex& first_neighbor) const {
    int vertex_index = GetVertexIndex(vertex);
    if (vertex_index < 0) {
        return false;
    }

    for (int i = 0; i < this->vertex_count_; i++) {
        TWeight weight;
        TVertex cur_vertex;

        bool res = GetVertexByIndex(i, cur_vertex);
        if (!res) {
            continue;
        }

        res = GetWeight(vertex, cur_vertex, weight);
        if (res) {
            first_neighbor = cur_vertex;
            return true;
        }
    }

    return false;
}


/*!
 * @brief 获取结点的下一个相邻结点
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param vertex 结点
 * @param neighbor_vertex 某相邻结点
 * @param next_neighbor_vertex 下一相邻结点保存变量
 * @return 执行结果
 * @note
 * 获取结点的下一个相邻结点
 * --------------------
 * --------------------
 *
 * --------------------
 */
template<typename TVertex, typename TWeight>
bool MatrixGraph<TVertex, TWeight>::GetNextNeighborVertex(const TVertex& vertex,
                                                          const TVertex& neighbor_vertex,
                                                          TVertex& next_neighbor_vertex) const
{
    int vertex_index = GetVertexIndex(vertex);
    int neighbor_vertex_index = GetVertexIndex(neighbor_vertex);

    if (vertex_index < 0 || neighbor_vertex_index < 0) {
        return false;
    }

    for (int i = neighbor_vertex_index + 1; i < this->vertex_count_; i++) {
        TWeight weight;
        TVertex cur_vertex;

        bool res = GetVertexByIndex(i, cur_vertex);
        if (!res) {
            continue;
        }

        res = GetWeight(vertex, cur_vertex, weight);
        if (res) {
            next_neighbor_vertex = cur_vertex;
            return true;
        }
    }

    return false;
}


/*!
 * @brief 插入结点
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param vertex 结点
 * @return 执行结果
 * @note
 * 插入结点
 * -------
 * -------
 *
 * -------
 */
template<typename TVertex, typename TWeight>
bool MatrixGraph<TVertex, TWeight>::InsertVertex(const TVertex& vertex) {
    if (this->vertex_count_ >= this->max_vertex_count_) {
        return false;
    }

    this->vertices_.push_back(vertex);
    this->vertex_count_++;

    return true;
}


/*!
 * @brief **插入边**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param starting_vertex 起点
 * @param ending_vertex 终点
 * @param weight 边权值
 * @return 执行结果
 * @note
 * 插入边
 * -----
 * -----
 * 需要起点和终点都已经在图内, 否则无法插入(先插入结点, 再插入边)
 * -----
 */
template<typename TVertex, typename TWeight>
bool MatrixGraph<TVertex, TWeight>::InsertEdge(const TVertex& starting_vertex,
                                               const TVertex& ending_vertex,
                                               const TWeight& weight)
{
    int starting_vertex_index = GetVertexIndex(starting_vertex);
    int ending_vertex_index = GetVertexIndex(ending_vertex);

    if (starting_vertex_index < 0 || ending_vertex_index < 0 || starting_vertex_index == ending_vertex_index) {
        return false;
    }

    this->adjacency_matrix_[starting_vertex_index][ending_vertex_index] = weight;

    // todo: 无向图逻辑
    this->adjacency_matrix_[ending_vertex_index][starting_vertex_index] = weight;

    this->edge_count_++;

    Edge<TVertex, TWeight> edge(starting_vertex, ending_vertex, weight);
    this->edges_.push_back(edge);

    return true;
}


/*!
 * @brief **删除结点**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param vertex 结点
 * @return 执行结果
 * @note
 * 删除结点
 * -------
 * -------
 *
 * -------
 */
template<typename TVertex, typename TWeight>
bool MatrixGraph<TVertex, TWeight>::RemoveVertex(const TVertex& vertex) {

    int vertex_index = GetVertexIndex(vertex);

    if (vertex_index < 0 || vertex_index >= this->vertex_count_) {
        return false;
    }

    // edges_删除边
    for (vector<Edge<TVertex, TWeight> >::iterator iter = this->edges_.begin(); iter != this->edges_.end(); iter++) {
        if (iter->ending_vertex == vertex || iter->starting_vertex == vertex) {
            iter = this->edges_.erase(iter);
        }
        this->edge_count_--;
    }

    // 调整邻接矩阵
    this->vertices_[vertex_index] = this->vertices_[this->vertex_count_ - 1];

    for (int i = 0; i < this->vertex_count_; i++) {
        this->adjacency_matrix_[i][vertex_index] = this->adjacency_matrix_[i][this->vertex_count_ - 1];
        this->adjacency_matrix_[vertex_index][i] = this->adjacency_matrix_[this->vertex_count_ - 1][i];
    }

    // 调整vertex_count_和vertices_
    this->vertices_.erase(this->vertices_.begin() + this->vertex_count_ - 1);
    this->vertex_count_--;

    return true;
}


/*!
 * @brief 删除边
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param starting_vertex 起点
 * @param ending_vertex 终点
 * @return 执行结果
 */
template<typename TVertex, typename TWeight>
bool MatrixGraph<TVertex, TWeight>::RemoveEdge(const TVertex& starting_vertex, const TVertex& ending_vertex) {

    int starting_vertex_index = GetVertexIndex(starting_vertex);
    int ending_vertex_index = GetVertexIndex(ending_vertex);
    if (starting_vertex_index < 0 || ending_vertex_index < 0) {
        return false;
    }

    TWeight weight;
    bool res = GetWeight(starting_vertex, ending_vertex, weight);
    if (!res) {
        return false;
    }

    this->adjacency_matrix_[starting_vertex_index][ending_vertex_index] = TWeight();
    this->adjacency_matrix_[ending_vertex_index][starting_vertex_index] = TWeight();

    this->edge_count_--;

    return true;
}


// todo: 需要测试, 但这个方法太笨重了, 懒得动 :-(
template<typename TVertex, typename TWeight>
istream& operator>>(istream& in, MatrixGraph<TVertex, TWeight>& graph_matrix) {

  int vertex_num;
  int edge_num;
  TVertex src_vertex;
  TVertex dest_vertex;
  TWeight weight;

  cout<<"Input the vertex_num and edge_num"<<endl;
  in >> vertex_num >> edge_num;

  for (int i = 0; i < vertex_num; i++) {

    cout<<"src_vertex "<<i<<":"<<endl;
    in >> src_vertex;

    graph_matrix.InsertVertex(src_vertex);
  }

  for (int i = 0; i < edge_num; i++) {

    cout<<"Adjacency "<<i<<":"<<endl;
    in >> src_vertex >> dest_vertex >> weight;

    int src_vertex_index = graph_matrix.GetVertexIndex(src_vertex);
    int dest_vertex_index = graph_matrix.GetVertexIndex(dest_vertex);

    if (src_vertex_index < 0 || dest_vertex_index < 0) {
      cout<<"Error input"<<endl;
      continue;
    }

    graph_matrix.InsertEdge(src_vertex_index, dest_vertex_index, weight);
  }
}


/*
template<class TVertex, class TWeight>
ostream& operator<<(ostream& out, MatrixGraph<TVertex, TWeight>& graph_matrix) {

  int vertex_num = graph_matrix.VertexCount();
  int edge_num = graph_matrix.EdgeCount();

  cout<<"vertex_num: "<<vertex_num<<", edge_num: "<<edge_num<<endl;

  for (int vertex1_index = 0; vertex1_index < vertex_num; vertex1_index++) {
    for (int vertex2_index = 0; vertex2_index < vertex_num; vertex2_index++) {

        TWeight weight = graph_matrix.GetWeight(vertex1_index, vertex2_index);

      if (weight > 0) {

        TVertex vertex1 = graph_matrix.GetValue(vertex1_index);
        TVertex vertex2 = graph_matrix.GetValue(vertex2_index);

        out << "(" << vertex1 << "," << vertex2 << "," << weight << ")" << endl;
      }
    }
  }
}
 */


/*!
 * 获取结点索引
 * @tparam Vertex 结点类型模板参数
 * @tparam Weight 边权值类型模板参数
 * @param vertex 结点
 * @return
 */
template<class Vertex, class Weight>
int MatrixGraph<Vertex, Weight>::GetVertexIndex(Vertex vertex) const {
    for (int i = 0; i < this->vertex_count_; i++) {
        if (this->vertices_[i] == vertex) {
            return i;
        }
    }

    return -1;
}


/*!
 * 打印图邻接矩阵
 * @tparam Vertex 结点类型模板参数
 * @tparam Weight
 */
template<class Vertex, class Weight>
void MatrixGraph<Vertex, Weight>::PrintMatrix() {
  for (int i = 0; i < this->vertex_count_; i++) {
    for (int j = 0; j < this->vertex_count_; j++) {
      cout << this->adjacency_matrix_[i][j] << "  ";
    }
    cout<<endl;
  }
}


#endif // CYBER_DASH_MATRIX_GRAPH_H
