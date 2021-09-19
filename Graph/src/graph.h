//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2021/1/23.
//

#ifndef CYBER_DASH_GRAPH_H
#define CYBER_DASH_GRAPH_H


const int DEFAULT_VERTICES = 20;
const int MAX_WEIGHT = 1000;


template<class T, class E>
class Graph {
public:
  Graph(int size = DEFAULT_VERTICES);
  ~Graph();
  bool GraphEmpty() const;
  bool GraphFull() const;
  int NumberOfVertices();
  int NumberOfEdges();

  virtual bool GetVertexByIndex(T& vertex, int vertex_index) = 0;

  virtual bool GetWeight(E& weight, T v1, T v2) = 0;

  virtual bool GetFirstNeighborVertex(T& first_neighbor, const T& vertex) = 0;

  virtual bool GetNextNeighborVertex(T& next_neighbor, const T& vertex, const T& neighbor_vertex) = 0;

  virtual bool InsertVertex(const T& vertex) = 0;

  virtual bool InsertEdge(T vertex1, T vertex2, E weight) = 0;

  virtual bool RemoveVertex(T v) = 0;

  virtual bool RemoveEdge(T v1, T v2) = 0;

  virtual int GetVertexIndex(T vertex) = 0;

protected:
  int max_vertices_num_; // 图节点数量最大限制
  int edge_count_; // 边数量
  int vertices_num_; // 节点数量
};


template<class T, class E>
Graph<T, E>::Graph(int size) {
}


template<class T, class E>
Graph<T, E>::~Graph() {
}


template<class T, class E>
int Graph<T, E>::NumberOfVertices() {
  return vertices_num_;
}


template<class T, class E>
int Graph<T, E>::NumberOfEdges() {
  return edge_count_;
}

#endif //CYBER_DASH_GRAPH_H
