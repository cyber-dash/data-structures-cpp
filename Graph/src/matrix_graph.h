/*!
 * @file matrix_graph.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 矩阵图模板类
 * @version 0.2.1
 * @date 2021-07-14
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#ifndef CYBER_DASH_MATRIX_GRAPH_H
#define CYBER_DASH_MATRIX_GRAPH_H


#include "graph.h"
#include <iostream>
#include <map>


using namespace std;


/*!
 * @brief 矩阵图模板类
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 */
template<class TVertex, class TWeight>
class MatrixGraph: public Graph<TVertex, TWeight> {

public:
  // 构造函数
    MatrixGraph(int max_vertex_count, TWeight max_weight);

    MatrixGraph(int max_vertex_count,
                TWeight max_weight,
                const vector<Edge<TVertex, TWeight> >& edges,
                const vector<TVertex>& vertices);

    // 析构函数
    ~MatrixGraph();

    /*!
     * @brief 获取节点(由结点索引)
     * @param vertex 结点(用于保存结果)
     * @param vertex_index 结点索引
     * @return 是否获取成功
     */
  // bool GetVertexByIndex(TVertex& vertex, int vertex_index);
    bool GetVertexByIndex(int vertex_index, TVertex& vertex);

    // (由边的两个结点)获取边权值
  // bool GetWeight(TWeight& weight, TVertex v1, TVertex v2);
    bool GetWeight(TVertex v1, TVertex v2, TWeight& weight);

    // (由边的两个结点索引)获取边权值
  // bool GetWeightByVertexIndex(TWeight& weight, int v1_index, int v2_index);
    bool GetWeightByVertexIndex(int v1_index, int v2_index, TWeight& weight);

  /*!
   * @brief 插入结点
   * @param vertex 节点
   * @return 是否插入成功
   */
  bool InsertVertex(const TVertex& vertex);

  /*!
   * @brief 删除结点
   * @param vertex 节点
   * @return 是否删除成功
   */
  bool RemoveVertex(const TVertex& vertex);

  /*!
   * @brief 插入边
   * @param starting_vertex 边节点1
   * @param ending_vertex 边节点2
   * @param weight 边权值
   * @return 是否插入成功
   */
  bool InsertEdge(const TVertex& starting_vertex, const TVertex& ending_vertex, const TWeight& weight);

  /*!
   * @brief 删除边
   * @param vertex1 边结点1
   * @param vertex2 边结点2
   * @return 是否删除成功
   */
  bool RemoveEdge(TVertex vertex1, TVertex vertex2);

  /*!
   * 获取第一个相邻结点
   * @param first_neighbor 第一个相邻结点(用于保存节点)
   * @param vertex 节点
   * @return 是否获取成功
   */
  // bool GetFirstNeighborVertex(TVertex& first_neighbor, const TVertex& vertex);
    bool GetFirstNeighborVertex(const TVertex& vertex, TVertex& first_neighbor);

    /*!
     * @brief 获取下一个相邻结点
     * @param next_neighbor_vertex 下一个相邻结点(用于保存结点)
     * @param vertex 结点
     * @param neighbor_vertex 当前相邻结点
     * @return 是否获取成功
     */
    // bool GetNextNeighborVertex(TVertex& next_neighbor_vertex, const TVertex& vertex, const TVertex& neighbor_vertex);
    bool GetNextNeighborVertex(const TVertex& vertex, const TVertex& neighbor_vertex, TVertex& next_neighbor_vertex);

  /*!
   * @brief 获取结点索引
   * @param vertex 结点
   * @return 结点索引
   */
  int GetVertexIndex(TVertex vertex);

  template<class U>
  friend istream& operator>>(istream& in, MatrixGraph<TVertex, TWeight>& graph_matrix);
  template<class U>
  friend ostream& operator<<(ostream& out, MatrixGraph<TVertex, TWeight>& graph_matrix);

  void PrintMatrix();
  // void CyberDashShow();

  // map<pair<TVertex, TVertex>, TWeight> edge_map; // todo: 用于保存边集合, 未实现
private:
  TWeight** adjacency_matrix_; //!< 边矩阵
};


/*!
 * @brief 构造函数
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param max_vertex_count 最大结点数
 */
template<class TVertex, class TWeight>
MatrixGraph<TVertex, TWeight>::MatrixGraph(int max_vertex_count, TWeight max_weight) {
    this->max_weight_ = max_weight;
    this->max_vertex_count_ = max_vertex_count;

    this->vertex_count_ = 0;
    this->edge_count_ = 0;

    // 所有节点
    /*
    this->vertices_ = new TVertex[this->max_vertex_count_];
    if (!this->vertices_) {
        throw bad_alloc();
    }
     */

    this->adjacency_matrix_ = (TWeight**)new TWeight*[this->max_vertex_count_];
    if (!this->adjacency_matrix_) {
        throw bad_alloc();
    }

    for (int i = 0; i < this->max_vertex_count_; i++) {
        this->adjacency_matrix_[i] = new TWeight[this->max_vertex_count_]; // 节点i对应的所有边
        for (int j = 0; j < this->max_vertex_count_; j++) {
            this->adjacency_matrix_[i][j] = 0;
        }
    }
}


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

    this->adjacency_matrix_ = (TWeight**)new TWeight*[this->max_vertex_count_];
    if (!this->adjacency_matrix_) {
        throw bad_alloc();
    }

    for (int starting_vertex_index = 0; starting_vertex_index < this->max_vertex_count_; starting_vertex_index++) {
        this->adjacency_matrix_[starting_vertex_index] = new TWeight[this->max_vertex_count_]; // 节点i对应的所有边
        for (int ending_vertex_index = 0; ending_vertex_index < this->max_vertex_count_; ending_vertex_index++) {
            this->adjacency_matrix_[starting_vertex_index][ending_vertex_index] = (TWeight)0;
        }
    }

    for (unsigned int i = 0; i < vertices.size(); i++) {
        TVertex vertex = vertices[i];
        this->InsertVertex(vertex);
    }

    for (unsigned int i = 0; i < edges.size(); i++) {
        TVertex starting_vertex = edges[i].starting_vertex;
        TVertex ending_vertex = edges[i].ending_vertex;
        TWeight weight = edges[i].weight;

        this->InsertEdge(starting_vertex, ending_vertex, weight);
    }
}

/*!
 * @brief 析构函数
 * @tparam Vertex 结点类型模板参数
 * @tparam Weight 边权值类型模板参数
 */
template<class Vertex, class Weight>
MatrixGraph<Vertex, Weight>::~MatrixGraph() {
  for (int i = 0; i < this->vertex_count_; i++) {
      delete[] this->adjacency_matrix_[i];
  }
  delete[] this->adjacency_matrix_;
}


/*!
 * @brief 使用结点索引获取结点
 * @param vertex 结点(保存结果的节点)
 * @param vertex_index 结点索引
 * @return 是否获取成功
 */
template<class TVertex, class TWeight>
bool MatrixGraph<TVertex, TWeight>::GetVertexByIndex(int vertex_index, TVertex& vertex) {
  if (vertex_index >= 0 && vertex_index <= this->vertex_count_) {
    vertex = this->vertices_[vertex_index];
    return true;
  } else {
    return false;
  }
}


/*!
 * @brief 获取边权值
 * @tparam Vertex
 * @tparam Weight
 * @param weight
 * @param v1
 * @param v2
 * @return
 */
template<class Vertex, class Weight>
// bool MatrixGraph<TVertex, TWeight>::GetWeight(TWeight& weight, TVertex v1, TVertex v2) {
bool MatrixGraph<Vertex, Weight>::GetWeight(Vertex v1, Vertex v2, Weight& weight) {

  int v1_index = GetVertexIndex(v1);
  int v2_index = GetVertexIndex(v2);
  if (v1_index < 0 || v2_index < 0) {
      return false;
  }

  // bool res = GetWeightByVertexIndex(weight, v1_index, v2_index);
    bool res = GetWeightByVertexIndex(v1_index, v2_index, weight);

  return res;
}


template<class Vertex, class Weight>
// bool MatrixGraph<TVertex, TWeight>::GetWeightByVertexIndex(TWeight& weight, int v1_index, int v2_index) {
bool MatrixGraph<Vertex, Weight>::GetWeightByVertexIndex(int v1_index, int v2_index, Weight& weight) {

    if (v1_index >= 0 && v2_index >= 0 && v1_index != v2_index &&
        adjacency_matrix_[v1_index][v2_index] != 0)
    {
        weight = adjacency_matrix_[v1_index][v2_index];

        return true;
    }

    return false;
}


template<typename TVertex, typename TWeight>
bool MatrixGraph<TVertex, TWeight>::GetFirstNeighborVertex(const TVertex& vertex, TVertex& first_neighbor) {

  int vertex_index = GetVertexIndex(vertex);
  if (vertex_index < 0) {
    return false;
  }

  for (int i = 0; i < this->vertex_count_; i++) {
    TWeight weight;
    TVertex cur_vertex;

    // bool done = GetVertexByIndex(cur_vertex, i);
      bool done = GetVertexByIndex(i, cur_vertex);
    if (!done) {
      continue;
    }

    // bool has_weight = GetWeight(weight, vertex, cur_vertex);
      bool has_weight = GetWeight(vertex, cur_vertex, weight);
    if (has_weight) {
      first_neighbor = cur_vertex;
      return true;
    }
  }

  return false;
}


template<class TVertex, class TWeight>
// bool MatrixGraph<TVertex, TWeight>::GetNextNeighborVertex(TVertex& next_neighbor_vertex, const TVertex& vertex, const TVertex& neighbor_vertex) {
bool MatrixGraph<TVertex, TWeight>::GetNextNeighborVertex(const TVertex& vertex, const TVertex& neighbor_vertex, TVertex& next_neighbor_vertex) {

  int vertex_index = GetVertexIndex(vertex);
  int neighbor_vertex_index = GetVertexIndex(neighbor_vertex);

  if (vertex_index < 0 && neighbor_vertex_index < 0) {
    return false;
  }

  for (int cur_index = neighbor_vertex_index + 1; cur_index < this->vertex_count_; cur_index ++) {
    TWeight weight;
    TVertex cur_vertex;

    // bool done = GetVertexByIndex(cur_vertex, cur_index);
      bool done = GetVertexByIndex(cur_index, cur_vertex);
    if (!done) {
      continue;
    }

    // bool has_weight = GetWeight(weight, vertex, cur_vertex);
      bool has_weight = GetWeight(vertex, cur_vertex, weight);
    if (has_weight) {
      next_neighbor_vertex = cur_vertex;
      return true;
    }
  }

  return false;
}


template<class Vertex, class Weight>
bool MatrixGraph<Vertex, Weight>::InsertVertex(const Vertex& vertex) {
    if (this->vertex_count_ >= this->max_vertex_count_) {
        return false;
    }

    this->vertices_.push_back(vertex);
    this->vertex_count_++;

    return true;
}


template<class TVertex, class TWeight>
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
    this->adjacency_matrix_[ending_vertex_index][starting_vertex_index] = weight;

    this->edge_count_++;

    Edge<TVertex, TWeight> edge(starting_vertex, ending_vertex, weight);
    this->edges_.push_back(edge);

    return true;
}


template<class Vertex, class Weight>
bool MatrixGraph<Vertex, Weight>::RemoveVertex(const Vertex& vertex) {

  int vertex_index = GetVertexIndex(vertex);

  if (vertex_index < 0 || vertex_index >= this->vertex_count_) {
    return false;
  }

  // 只剩1个顶点 todo: 实际上可以删除
  if (this->vertex_count_ == 1) {
    return false;
  }

  this->vertices_[vertex_index] = this->vertices_[this->vertex_count_ - 1];

  for (int i = 0; i < this->vertex_count_; i++) {
    if (this->adjacency_matrix_[i][vertex_index] > 0) {
      this->edge_count_--;
    }
  }

  for (int row = 0; row < this->vertex_count_; row++) {
    this->adjacency_matrix_[row][vertex_index] = this->adjacency_matrix_[row][this->vertex_count_ - 1];
  }

  for (int col = 0; col < this->vertex_count_; col++) {
    this->adjacency_matrix_[vertex_index][col] = this->adjacency_matrix_[this->vertex_count_ - 1][col];
  }

  this->vertex_count_--;

  return true;
}


template<class Vertex, class Weight>
bool MatrixGraph<Vertex, Weight>::RemoveEdge(Vertex vertex1, Vertex vertex2) {

  int v1_index = GetVertexIndex(vertex1);
  int v2_index = GetVertexIndex(vertex2);

  Weight weight;
  // bool has_weight = GetWeight(weight, vertex1, vertex2);
    bool has_weight = GetWeight(vertex1, vertex2, weight);
  if (has_weight) {
    this->adjacency_matrix_[v1_index][v2_index] = 0;
    this->adjacency_matrix_[v2_index][v1_index] = 0;

    this->edge_count_--;

    return true;
  }

  return false;
}


// todo: 需要测试, 但这个方法太笨重了, 懒得动 :-(
template<class Vertex, class Weight>
istream& operator>>(istream& in, MatrixGraph<Vertex, Weight>& graph_matrix) {

  int vertex_num;
  int edge_num;
  Vertex src_vertex;
  Vertex dest_vertex;
  Weight weight;

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
int MatrixGraph<Vertex, Weight>::GetVertexIndex(Vertex vertex) {
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
