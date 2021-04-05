//
// Created by cyberdash@163.com(抖音id:cyberdash_yuan) on 2021/1/23.
//

#ifndef CYBER_DASH_GRAPH_MATRIX_H
#define CYBER_DASH_GRAPH_MATRIX_H


#include "graph.h"
#include <iostream>


using namespace std;


template<class T, class E>
class GraphMatrix: public Graph<T, E> {

public:
  explicit GraphMatrix(int size = DEFAULT_VERTICES, bool is_weighted = true);
  ~GraphMatrix();
  T GetValue(int i);
  E GetWeight(int v1, int v2);
  int GetFirstNeighbor(int v);
  int GetNextNeighbor(int v, int w);
  bool InsertVertex(const T& vertex);
  bool InsertEdge(int v1, int v2, E weight);
  bool RemoveVertex(int vertex_index);
  bool RemoveEdge(int v1, int v2);

  template<class U>
  friend istream& operator>>(istream& in, GraphMatrix<T, E>& graph_matrix);
  template<class U>
  friend ostream& operator<<(ostream& out, GraphMatrix<T, E>& graph_matrix);

  int GetVertexPos(T vertex);

private:
  T* vertices_list_;
  E** edge_matrix_;
  bool is_weighted_;
};


template<class T, class E>
GraphMatrix<T, E>::GraphMatrix(int size, bool is_weighted) {

  this->max_vertices_num_ = size;
  this->vertices_num_ = 0;
  this->edges_num_ = 0;

  this->vertices_list_ = new T[this->max_vertices_num_];
  /* error handler */

  this->edge_matrix_ = (E**)new E*[this->max_vertices_num_];
  /* error handler */

  for (int i = 0; i < this->max_vertices_num_; i++) {
    this->edge_matrix_[i] = new E[this->max_vertices_num_];
    for (int j = 0; j < this->max_vertices_num_; j++) {
      this->edge_matrix_[i][j] = (i == j) ? 0 : MAX_WEIGHT;
    }
  }
}


template<class T, class E>
GraphMatrix<T, E>::~GraphMatrix() {
  delete[] this->vertices_list_;
  delete[] this->edge_matrix_;
}


template<class T, class E>
T GraphMatrix<T, E>::GetValue(int vertex_index) {
  if (vertex_index >= 0 && vertex_index <= this->vertices_num_) {
    return this->vertices_list_[vertex_index];
  } else {
    return (T)NULL;
  }
}


template<class T, class E>
E GraphMatrix<T, E>::GetWeight(int v1, int v2) {
  if (v1 >= 0 && v2 >= 0) {
    return this->edge_matrix_[v1][v2];
  } else {
    return 0;
  }
}


template<class T, class E>
int GraphMatrix<T, E>::GetFirstNeighborVertex(int v) {

  int col = -1;

  if (v < 0) {
    return col;
  }

  for (col = 0; col < this->vertices_num_; col++) {
    if (this->edge_matrix_[v][col] > 0 && this->edge_matrix_[v][col] < MAX_WEIGHT) {
      break;
    }
  }

  return col;
}


template<class T, class E>
int GraphMatrix<T, E>::GetNextNeighborVertex(int v, int w) {

  int col = -1;

  if (v < 0 && w < 0) {
    return col;
  }

  for (col = w + 1; col < this->vertices_num_; col ++) {
    if (this->edge_matrix_[v][col] > 0 && this->edge_matrix_[v][col] < MAX_WEIGHT) {
      break;
    }
  }

  return col;
}


template<class T, class E>
bool GraphMatrix<T, E>::InsertVertex(const T& vertex) {
  if (this->vertices_num_ >= this->max_vertices_num_) {
    return false;
  } else {
    this->vertices_list_[this->vertices_num_] = vertex;
    this->vertices_num_++;

    return true;
  }
}


template<class T, class E>
bool GraphMatrix<T, E>::InsertEdge(int v1, int v2, E weight) {
  if (v1 >= 0 && v1 < this->vertices_num_ &&
      v2 >= 0 && v2 < this->vertices_num_ &&
      this->edge_matrix_[v1][v2] == MAX_WEIGHT)
  {
    this->edge_matrix_[v1][v2] = weight;
    this->edge_matrix_[v2][v1] = weight;

    this->edges_num_++;

    return true;
  } else {
    return false;
  }
}


template<class T, class E>
bool GraphMatrix<T, E>::RemoveVertex(int vertex_index) {

  if (vertex_index < 0 || vertex_index >= this->vertices_num_) {
    return false;
  }

  // 只剩1个顶点
  if (this->vertices_num_ == 1) {
    return false;
  }

  this->vertices_list_[vertex_index] = this->vertices_list_[this->vertices_num_ - 1];

  for (int i = 0; i < this->vertices_num_; i++) {
    if (this->edge_matrix_[i][vertex_index] > 0 && this->edge_matrix_[i][vertex_index] < MAX_WEIGHT) {
      this->edges_num_--;
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
bool GraphMatrix<T, E>::RemoveEdge(int v1, int v2) {

  if (v1 > -1 && v1 < this->vertices_num_ &&
      v2 > -1 && v2 < this->vertices_num_ &&
      this->edge_matrix_[v1][v2] > 0 && this->edge_matrix_[v1][v2] < MAX_WEIGHT)
  {
    this->edge_matrix_[v1][v2] = MAX_WEIGHT;
    this->edge_matrix_[v2][v1] = MAX_WEIGHT;

    this->edges_num_--;

    return true;
  } else {
    return false;
  }
}


template<class T, class E>
istream& operator>>(istream& in, GraphMatrix<T, E>& graph_matrix) {

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
ostream& operator<<(ostream& out, GraphMatrix<T, E>& graph_matrix) {

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
int GraphMatrix<T, E>::GetVertexPos(T vertex) {

  int vertex_pos = -1;

  for (int i = 0; i < this->vertices_num_; i++) {
    if (this->vertices_list_[i] == vertex) {
      vertex_pos = i;
      break;
    }
  }

  return vertex_pos;
}

#endif //CYBER_DASH_GRAPH_MATRIX_H
