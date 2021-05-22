//
// Created by cyberdash@163.com(抖音id:cyberdash_yuan) on 2021/1/23.
//

#ifndef CYBER_DASH_MATRIX_GRAPH_H
#define CYBER_DASH_MATRIX_GRAPH_H


#include "graph.h"
#include <iostream>


using namespace std;


template<class T, class E>
class MatrixGraph: public Graph<T, E> {

public:
  explicit MatrixGraph(int size = DEFAULT_VERTICES);
  ~MatrixGraph();

  bool GetVertexByIndex(T& vertex, int vertex_index);

  /**
   * @brief 获取边权值
   * @param weight 边权值(用于保存结果)
   * @param vertex1 边的节点1
   * @param vertex2 边的节点2
   * @return 是否获取成功
   */
  bool GetWeight(E& weight, T vertex1, T vertex2);

  /**
   * @brief 插入结点
   * @param vertex 节点
   * @return 是否插入成功
   */
  bool InsertVertex(const T& vertex);

  /**
   * @brief 删除结点
   * @param vertex 节点
   * @return 是否删除成功
   */
  bool RemoveVertex(T vertex);

  /**
   * @brief 插入边
   * @param vertex1 边节点1
   * @param vertex2 边节点2
   * @param weight 边权值
   * @return 是否插入成功
   */
  bool InsertEdge(T vertex1, T vertex2, E weight);

  /**
   * @brief 删除边
   * @param vertex1 边结点1
   * @param vertex2 边结点2
   * @return 是否删除成功
   */
  bool RemoveEdge(T vertex1, T vertex2);

  /**
   * 获取第一个相邻结点
   * @param first_neighbor 第一个相邻结点(用于保存节点)
   * @param vertex 节点
   * @return 是否获取成功
   */
  bool GetFirstNeighborVertex(T& first_neighbor, const T& vertex);

  /**
   * @brief 获取下一个相邻结点
   * @param next_neighbor_vertex 下一个相邻结点(用于保存结点)
   * @param vertex 结点
   * @param neighbor_vertex 当前相邻结点
   * @return 是否获取成功
   */
  bool GetNextNeighborVertex(T& next_neighbor_vertex, const T& vertex, const T& neighbor_vertex);

  /**
   * @brief 获取结点索引
   * @param vertex 结点
   * @return 结点索引
   */
  int GetVertexIndex(T vertex);

  template<class U>
  friend istream& operator>>(istream& in, MatrixGraph<T, E>& graph_matrix);
  template<class U>
  friend ostream& operator<<(ostream& out, MatrixGraph<T, E>& graph_matrix);

  void PrintMatrix();

private:
  T* vertices_list_;
  E** edge_matrix_;
};


template<class T, class E>
MatrixGraph<T, E>::MatrixGraph(int size) {

  this->max_vertices_num_ = size;
  this->vertices_num_ = 0;
  this->edge_count_ = 0;

  // 所有节点
  this->vertices_list_ = new T[this->max_vertices_num_];
  /* error handler */

  this->edge_matrix_ = (E**)new E*[this->max_vertices_num_];
  /* error handler */

  for (int i = 0; i < this->max_vertices_num_; i++) {
    this->edge_matrix_[i] = new E[this->max_vertices_num_]; // 节点i对应的所有边
    for (int j = 0; j < this->max_vertices_num_; j++) {
      this->edge_matrix_[i][j] = (i == j) ? 0 : MAX_WEIGHT;
    }
  }
}


template<class T, class E>
MatrixGraph<T, E>::~MatrixGraph() {
  delete[] this->vertices_list_;
  delete[] this->edge_matrix_;
}


/**
 * @brief 使用结点索引获取结点
 * @param vertex 结点(保存结果的节点)
 * @param vertex_index 结点索引
 * @return 是否获取成功
 */
template<class T, class E>
bool MatrixGraph<T, E>::GetVertexByIndex(T& vertex, int vertex_index) {
  if (vertex_index >= 0 && vertex_index <= this->vertices_num_) {
    vertex = this->vertices_list_[vertex_index];
    return true;
  } else {
    return false;
  }
}


template<class T, class E>
bool MatrixGraph<T, E>::GetWeight(E& weight, T vertex1, T vertex2) {

  int v1_index = GetVertexIndex(vertex1);
  int v2_index = GetVertexIndex(vertex2);

  if (v1_index >= 0 && v2_index >= 0 &&
    v1_index != v2_index &&
    this->edge_matrix_[v1_index][v2_index] != MAX_WEIGHT &&
    this->edge_matrix_[v1_index][v2_index] > 0)
  {
    weight = this->edge_matrix_[v1_index][v2_index];

    return true;
  }

  return false;
}


template<class T, class E>
bool MatrixGraph<T, E>::GetFirstNeighborVertex(T& first_neighbor, const T& vertex) {

  int vertex_index = GetVertexIndex(vertex);

  if (vertex_index < 0) {
    return false;
  }

  for (int cur_index = 0; cur_index < this->vertices_num_; cur_index++) {
    E weight;
    T cur_vertex;

    bool done = GetVertexByIndex(cur_vertex, cur_index);
    if (!done) {
      continue;
    }

    bool has_weight = GetWeight(weight, vertex, cur_vertex);
    if (has_weight) {
      first_neighbor = cur_vertex;
      return true;
    }
  }

  return false;
}


template<class T, class E>
bool MatrixGraph<T, E>::GetNextNeighborVertex(T& next_neighbor_vertex, const T& vertex, const T& neighbor_vertex) {

  int vertex_index = GetVertexIndex(vertex);
  int neighbor_vertex_index = GetVertexIndex(neighbor_vertex);

  if (vertex_index < 0 && neighbor_vertex_index < 0) {
    return false;
  }

  for (int cur_index = neighbor_vertex_index + 1; cur_index < this->vertices_num_; cur_index ++) {
    E weight;
    T cur_vertex;

    bool done = GetVertexByIndex(cur_vertex, cur_index);
    if (!done) {
      continue;
    }

    bool has_weight = GetWeight(weight, vertex, cur_vertex);
    if (has_weight) {
      next_neighbor_vertex = cur_vertex;
      return true;
    }
  }

  return false;
}


template<class T, class E>
bool MatrixGraph<T, E>::InsertVertex(const T& vertex) {
  if (this->vertices_num_ >= this->max_vertices_num_) {
    return false;
  }

  this->vertices_list_[this->vertices_num_] = vertex;
  this->vertices_num_++;

  return true;
}


template<class T, class E>
bool MatrixGraph<T, E>::InsertEdge(T vertex1, T vertex2, E weight) {

  int v1_index = GetVertexIndex(vertex1);
  int v2_index = GetVertexIndex(vertex2);

  if (v1_index < 0 || v2_index < 0 || v1_index == v2_index)
  {
    return false;
  }

  this->edge_matrix_[v1_index][v2_index] = weight;
  this->edge_matrix_[v2_index][v1_index] = weight;

  this->edge_count_++;

  return true;
}


template<class T, class E>
bool MatrixGraph<T, E>::RemoveVertex(T vertex) {

  int vertex_index = GetVertexIndex(vertex);

  if (vertex_index < 0 || vertex_index >= this->vertices_num_) {
    return false;
  }

  // 只剩1个顶点 todo: 书上的逻辑, 实际上可以删除
  if (this->vertices_num_ == 1) {
    return false;
  }

  this->vertices_list_[vertex_index] = this->vertices_list_[this->vertices_num_ - 1];

  for (int i = 0; i < this->vertices_num_; i++) {
    if (this->edge_matrix_[i][vertex_index] > 0 && this->edge_matrix_[i][vertex_index] < MAX_WEIGHT) {
      this->edge_count_--;
    }
  }

  for (int row = 0; row < this->vertices_num_; row++) {
    this->edge_matrix_[row][vertex_index] = this->edge_matrix_[row][this->vertices_num_ - 1];
  }

  for (int col = 0; col < this->vertices_num_; col++) {
    this->edge_matrix_[vertex_index][col] = this->edge_matrix_[this->vertices_num_ - 1][col];
  }

  this->vertices_num_--;

  return true;
}


template<class T, class E>
bool MatrixGraph<T, E>::RemoveEdge(T vertex1, T vertex2) {

  int v1_index = GetVertexIndex(vertex1);
  int v2_index = GetVertexIndex(vertex2);

  E weight;
  bool has_weight = GetWeight(weight, vertex1, vertex2);
  if (has_weight) {
    this->edge_matrix_[v1_index][v2_index] = MAX_WEIGHT;
    this->edge_matrix_[v2_index][v1_index] = MAX_WEIGHT;

    this->edge_count_--;

    return true;
  }

  return false;
}


template<class T, class E>
istream& operator>>(istream& in, MatrixGraph<T, E>& graph_matrix) {

  int vertex_num;
  int edge_num;
  T src_vertex;
  T dest_vertex;
  E weight;

  cout<<"Input the vertex_num and edge_num"<<endl;
  in >> vertex_num >> edge_num;

  for (int i = 0; i < vertex_num; i++) {

    cout<<"Vertex "<<i<<":"<<endl;
    in >> src_vertex;

    graph_matrix.InsertVertex(src_vertex);
  }

  for (int i = 0; i < edge_num; i++) {

    cout<<"Edge "<<i<<":"<<endl;
    in >> src_vertex >> dest_vertex >> weight;

    int src_vertex_index = graph_matrix.GetVertexPos(src_vertex); // todo: pos
    int dest_vertex_index = graph_matrix.GetVertexPos(dest_vertex);

    if (src_vertex_index < 0 || dest_vertex_index < 0) {
      cout<<"Error input"<<endl;
      continue;
    }

    graph_matrix.InsertEdge(src_vertex_index, dest_vertex_index, weight);
  }
}


template<class T, class E>
ostream& operator<<(ostream& out, MatrixGraph<T, E>& graph_matrix) {

  int vertex_num = graph_matrix.NumberOfVertices();
  int edge_num = graph_matrix.NumberOfEdges();

  cout<<"vertex_num: "<<vertex_num<<", edge_num: "<<edge_num<<endl;

  for (int src_vertex_index = 0; src_vertex_index < vertex_num; src_vertex_index++) {
    for (int dest_vertex_index = 0; dest_vertex_index < vertex_num; dest_vertex_index++) {

      E weight = graph_matrix.GetWeight(src_vertex_index, dest_vertex_index);

      if (weight > 0 && weight < MAX_WEIGHT) {

        T e1 = graph_matrix.GetValue(src_vertex_index);
        T e2 = graph_matrix.GetValue(dest_vertex_index);

        out << "(" << e1 << "," << e2 << "," << weight << ")" << endl;
      }
    }
  }
}


template<class T, class E>
int MatrixGraph<T, E>::GetVertexIndex(T vertex) {

  int vertex_index = -1;

  for (int i = 0; i < this->vertices_num_; i++) {
    if (this->vertices_list_[i] == vertex) {
      vertex_index = i;
      break;
    }
  }

  return vertex_index;
}


template<class T, class E>
void MatrixGraph<T, E>::PrintMatrix() {
  for (int i = 0; i < this->vertices_num_; i++) {
    for (int j = 0; j < this->vertices_num_; j++) {
      cout<<this->edge_matrix_[i][j]<<"  ";
    }
    cout<<endl;
  }
}

#endif //CYBER_DASH_MATRIX_GRAPH_H
