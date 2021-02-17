//
// Created by cyberdash@163.com(抖音id:cyberdash_yuan) on 2021/1/26.
//

#ifndef CYBER_DASH_GRAPH_ADJACENCY_LIST_H
#define CYBER_DASH_GRAPH_ADJACENCY_LIST_H


#include "graph.h"
#include "iostream"
#include "cstdlib"


using namespace std;


template <class T, class E>
struct Edge {
  Edge() {}
  Edge(int num, E weight): dest_index_(num), weight_(weight), next_(NULL) {}
  bool operator != (Edge<T, E>& edge) const {
    return (dest_index_ != edge.dest_index_);
  }

  int dest_index_;
  E weight_;
  Edge<T, E>* next_;
};


template<class T, class E>
struct Vertex {
  T value_;
  Edge<T, E>* adjacency_list_ptr_;
};


template<class T, class E>
class GraphAdjacencyList: public Graph<T, E> {

public:

  GraphAdjacencyList(int size = DEFAULT_VERTICES);

  ~GraphAdjacencyList();

  bool GetVertexValue(T& value, int vertex_index);

  bool GetWeight(E& weight, T vertex1, T vertex2);

  bool InsertVertex(const T& vertex);

  bool RemoveVertex(T vertex);

  bool InsertEdge(T vertex1, T vertex2, E weight);

  bool RemoveEdge(T v1, T v2);

  bool GetFirstNeighbor(T& first_neighbor, const T& vertex);

  bool GetNextNeighbor(T& next_neighbor, const T& vertex, const T& neighbor_vertex);

  int GetVertexIndex(T vertex);

  template<class U>
  friend istream& operator>>(istream& in, GraphAdjacencyList<T, E>& graph_adjacency_list);
  template<class U>
  friend ostream& operator<<(ostream& out, GraphAdjacencyList<T, E>& graph_adjacency_list);

  void CyberDashShow();
private:
  Vertex<T, E>* vertex_table_;
};


template<class T, class E>
GraphAdjacencyList<T, E>::GraphAdjacencyList(int size) {

  this->max_vertices_num_ = size;
  this->vertices_num_ = 0;
  this->edges_num_ = 0;

  this->vertex_table_ = new Vertex<T, E>[this->max_vertices_num_];

  for (int i = 0; i < this->max_vertices_num_; i++) {
    this->vertex_table_[i].adjacency_list_ptr_ = NULL;
  }
}


template<class T, class E>
GraphAdjacencyList<T, E>::~GraphAdjacencyList() {

  for (int i = 0; i < this->vertices_num_; i++) {

    Edge<T, E>* cur_edge_ptr = this->vertex_table_[i].adjacency_list_ptr_;

    while (cur_edge_ptr != NULL) {
      this->vertex_table_[i].adjacency_list_ptr_ = cur_edge_ptr->next_;
      delete cur_edge_ptr;
      cur_edge_ptr = this->vertex_table_[i].adjacency_list_ptr_;
    }
  }

  delete[] this->vertex_table_;
}


template<class T, class E>
bool GraphAdjacencyList<T, E>::GetVertexValue(T& vertex, int index) {
  if (index >= 0 && index < this->vertices_num_) {
    vertex = this->vertex_table_[index].value_;

    return true;
  } else {
    return false;
  }
}


template<class T, class E>
bool GraphAdjacencyList<T, E>::GetWeight(E& weight, T vertex1, T vertex2) {

  int vertex1_index = this->GetVertexIndex(vertex1);
  int vertex2_index = this->GetVertexIndex(vertex2);

  if (vertex1_index < 0 || vertex2_index < 0) {
    return false;
  }

  Edge<T, E>* edge_ptr = this->vertex_table_[vertex1_index].adjacency_list_ptr_;

  while (edge_ptr != NULL && edge_ptr->dest_index_ != vertex2_index) {
    edge_ptr = edge_ptr->next_;
  }

  if (edge_ptr != NULL) {
    weight = edge_ptr->weight_;
    return true;
  }

  return false;
}


template<class T, class E>
bool GraphAdjacencyList<T, E>::InsertVertex(const T& vertex) {

  if (this->vertices_num_ == this->max_vertices_num_) {
    return false;
  }

  this->vertex_table_[this->vertices_num_].value_ = vertex;
  this->vertices_num_++;

  return true;
}


template<class T, class E>
bool GraphAdjacencyList<T, E>::RemoveVertex(T vertex) {

  int vertex_index = this->GetVertexIndex(vertex);

  if (this->vertices_num_ == 1 || vertex_index < 0 || vertex_index >= this->vertices_num_) {
    return false;
  }

  while (this->vertex_table_[vertex_index].adjacency_list_ptr_ != NULL) {

    Edge<T, E>* prior_ptr = NULL;
    Edge<T, E>* cur_ptr = this->vertex_table_[vertex_index].adjacency_list_ptr_;
    int cur_vertex_index = cur_ptr->dest_index_;

    Edge<T, E>* delete_ptr = this->vertex_table_[cur_vertex_index].adjacency_list_ptr_;

    while (delete_ptr != NULL && delete_ptr->dest_index_ != vertex_index) {
      prior_ptr = delete_ptr;
      delete_ptr = delete_ptr->next_;
    }

    if (delete_ptr != NULL) {
      if (prior_ptr == NULL) {
        this->vertex_table_[cur_vertex_index].adjacency_list_ptr_ = delete_ptr->next_;
      } else {
        prior_ptr->next_ = delete_ptr->next_;
      }

      delete delete_ptr;
    }

    this->vertex_table_[vertex_index].adjacency_list_ptr_ = cur_ptr->next_;

    delete cur_ptr;

    this->edges_num_--;
  }

  this->vertices_num_--;

  this->vertex_table_[vertex_index].value_ = this->vertex_table_[this->vertices_num_].value_;
  this->vertex_table_[vertex_index].adjacency_list_ptr_ = this->vertex_table_[this->vertices_num_].adjacency_list_ptr_;

  Edge<T, E>* cur_ptr = this->vertex_table_[this->vertices_num_].adjacency_list_ptr_;
  while (cur_ptr != NULL) {

    Edge<T, E>* modify_edge_ptr = this->vertex_table_[cur_ptr->dest_index_].adjacency_list_ptr_;

    while (modify_edge_ptr != NULL) {
      if (modify_edge_ptr->dest_index_ == this->vertices_num_) {
        modify_edge_ptr->dest_index_ = vertex_index;
        break;
      } else {
        modify_edge_ptr = modify_edge_ptr->next_;
      }
    }

    cur_ptr = cur_ptr->next_;
  }

  this->vertex_table_[this->vertices_num_].adjacency_list_ptr_ = NULL;

  return true;
}


// if weight == 0, no weight graph
template<class T, class E>
bool GraphAdjacencyList<T, E>::InsertEdge(T vertex1, T vertex2, E weight) {

  int vertex1_index = this->GetVertexIndex(vertex1);
  int vertex2_index = this->GetVertexIndex(vertex2);

  if (vertex1_index < 0 || vertex1_index >= this->vertices_num_ || vertex2_index < 0 || vertex2_index >= this->vertices_num_) {
    return false;
  }

  Edge<T, E>* cur_edge_ptr = this->vertex_table_[vertex1_index].adjacency_list_ptr_;
  while (cur_edge_ptr != NULL && cur_edge_ptr->dest_index_ != vertex2_index) {
    cur_edge_ptr = cur_edge_ptr->next_;
  }

  // 已经存在
  if (cur_edge_ptr != NULL) {
    return false;
  }

  Edge<T, E>* v2_dest_edge_ptr = new Edge<T, E>();
  Edge<T, E>* v1_dest_edge_ptr = new Edge<T, E>();
  /* error handler */

  v2_dest_edge_ptr->dest_index_ = vertex2_index;
  v2_dest_edge_ptr->weight_ = weight;
  v2_dest_edge_ptr->next_ = this->vertex_table_[vertex1_index].adjacency_list_ptr_;
  this->vertex_table_[vertex1_index].adjacency_list_ptr_ = v2_dest_edge_ptr;

  v1_dest_edge_ptr->dest_index_ = vertex1_index;
  v1_dest_edge_ptr->weight_ = weight;
  v1_dest_edge_ptr->next_ = this->vertex_table_[vertex2_index].adjacency_list_ptr_;
  this->vertex_table_[vertex2_index].adjacency_list_ptr_ = v1_dest_edge_ptr;

  this->edges_num_++;

  return true;
}


template<class T, class E>
bool GraphAdjacencyList<T, E>::RemoveEdge(T vertex1, T vertex2) {

  int vertex1_index = this->GetVertexIndex(vertex1);
  int vertex2_index = this->GetVertexIndex(vertex2);

  if (vertex1_index < 0 && vertex2_index < 0) {
    return false;
  }

  Edge<T, E>* delete_edge_ptr = this->vertex_table_[vertex1_index].adjacency_list_ptr_;
  Edge<T, E>* prior_edge_ptr = NULL;
  Edge<T, E>* first_edge_ptr = this->vertex_table_[vertex1_index].adjacency_list_ptr_;

  while (delete_edge_ptr != NULL && delete_edge_ptr->dest_index_ != vertex2_index) {
    prior_edge_ptr = delete_edge_ptr;
    delete_edge_ptr = delete_edge_ptr->next_;
  }

  if (delete_edge_ptr != NULL) {
    if (first_edge_ptr == delete_edge_ptr) {
      this->vertex_table_[vertex1_index].adjacency_list_ptr_ = delete_edge_ptr->next_;
    } else {
      prior_edge_ptr->next_ = delete_edge_ptr->next_;

      delete delete_edge_ptr;
    }
  } else {
    return false;
  }

  delete_edge_ptr = this->vertex_table_[vertex2_index].adjacency_list_ptr_;
  prior_edge_ptr = NULL;
  first_edge_ptr = this->vertex_table_[vertex2_index].adjacency_list_ptr_;

  while (delete_edge_ptr != NULL && delete_edge_ptr->dest_index_ != vertex1_index) {
    prior_edge_ptr = delete_edge_ptr;
    delete_edge_ptr = delete_edge_ptr->next_;
  }

  if (delete_edge_ptr != NULL) {
    if (first_edge_ptr == delete_edge_ptr) {
      this->vertex_table_[vertex2_index].adjacency_list_ptr_ = delete_edge_ptr->next_;
    } else {
      prior_edge_ptr->next_ = delete_edge_ptr->next_;

      delete delete_edge_ptr;
    }
  } else {
    return false;
  }

  this->edges_num_--;

  return true;
}


template<class T, class E>
bool GraphAdjacencyList<T, E>::GetFirstNeighbor(T& first_neighbor, const T& vertex) {

  int vertex_index = this->GetVertexIndex(vertex);

  if (vertex_index >= 0) {
    Edge<T, E>* edge_ptr = this->vertex_table_[vertex_index].adjacency_list_ptr_;
    if (edge_ptr != NULL) {

      int neighbor_index = edge_ptr->dest_index_;

      bool get_first_neighbor_done = false;
      get_first_neighbor_done = this->GetVertexValue(first_neighbor, neighbor_index);

      return get_first_neighbor_done;
    }
  }

  return false;
}


template<class T, class E>
bool GraphAdjacencyList<T, E>::GetNextNeighbor(T& next_neighbor, const T& vertex, const T& neighbor_vertex) {

  int vertex_index = GetVertexIndex(vertex);
  int neighbor_index = GetVertexIndex(neighbor_vertex);

  if (vertex_index >= 0) {

    Edge<T, E>* edge_ptr = this->vertex_table_[vertex_index].adjacency_list_ptr_;

    while (edge_ptr->next_ != NULL && edge_ptr->dest_index_ != neighbor_index) {
      edge_ptr = edge_ptr->next_;
    }

    // on the neighbor vertex
    if (edge_ptr != NULL && edge_ptr->next_ != NULL) {
      int next_neighbor_index = edge_ptr->next_->dest_index_;

      bool get_next_neighbor_done = false;
      get_next_neighbor_done = this->GetVertexValue(next_neighbor, next_neighbor_index);

      return get_next_neighbor_done;
    }
  }

  return false;
}


template<class T, class E>
istream& operator>>(istream& in, GraphAdjacencyList<T, E>& graph_adjacency_list) {

  int vertex_num;
  int edge_num;

  cout<<"Input the vertex_num and edge_num"<<endl;
  in >> vertex_num >> edge_num;

  for (int i = 0; i < vertex_num; i++) {

    T vertex;

    cout<<"Input vertex "<<i<<":"<<endl;
    in >> vertex;

    bool insert_done = graph_adjacency_list.InsertVertex(vertex);
    if (insert_done) {
      cout<<"Insert vertex "<<i<<" done."<<endl;
    } else {
      cout<<"Insert vertex "<<i<<" failed."<<endl;
      exit(1);
    }
  }

  for (int i = 0; i < edge_num; i++) {

    T src_vertex;
    T dest_vertex;
    E weight;

    cout<<"Edge "<<i<<":"<<endl;
    in >> src_vertex >> dest_vertex >> weight;

    int src_vertex_index = graph_adjacency_list.GetVertexIndex(src_vertex);
    int dest_vertex_index = graph_adjacency_list.GetVertexIndex(dest_vertex);
    if (src_vertex_index < 0 || dest_vertex_index < 0) {
      cout<<"Error input"<<endl;
      continue;
    }

    graph_adjacency_list.InsertEdge(src_vertex, dest_vertex, weight);
  }

  return in;
}


template<class T, class E>
ostream& operator<<(ostream& out, GraphAdjacencyList<T, E>& graph_adjacency_list) {

  int vertex_num = graph_adjacency_list.NumberOfVertices();
  int edge_num = graph_adjacency_list.NumberOfEdges();

  cout<<"vertex_num: "<<vertex_num<<", edge_num: "<<edge_num<<endl;

  if (edge_num == 0) {
    cout<<"No edge"<<endl;
    return out;
  }

  for (int src_vertex_index = 0; src_vertex_index < vertex_num; src_vertex_index++) {
    for (int dest_vertex_index = 0; dest_vertex_index < vertex_num; dest_vertex_index++) {

      T src_vertex;
      T dest_vertex;

      bool get_src_value_done = graph_adjacency_list.GetVertexValue(src_vertex, src_vertex_index);
      bool get_dest_value_done = graph_adjacency_list.GetVertexValue(dest_vertex, dest_vertex_index);

      if (get_src_value_done && get_dest_value_done) {

        E weight;
        bool hasWeight = graph_adjacency_list.GetWeight(weight, src_vertex, dest_vertex);

        if (hasWeight) {
          out << "(" << src_vertex << "," << dest_vertex << "," << weight << ")" << endl;
        }
      }
    }
  }

  return out;
}


template<class T, class E>
int GraphAdjacencyList<T, E>::GetVertexIndex(T vertex) {

  int vertex_index = -1;

  for (int i = 0; i < this->vertices_num_; i++) {
    if (this->vertex_table_[i].value_ == vertex) {
      vertex_index = i;
      break;
    }
  }

  return vertex_index;
}


template<class T, class E>
void GraphAdjacencyList<T, E>::CyberDashShow() {
  cout<<endl
      <<"*************************************** CyberDash ***************************************"<<endl<<endl
      <<"抖音号\"CyberDash计算机考研\", id: cyberdash_yuan"<<endl<<endl
      <<"CyberDash成员:"<<endl
      <<"元哥(cyberdash@163.com), "<<"北京邮电大学(通信工程本科)/北京邮电大学(信息与通信系统研究生)"<<endl
      <<"磊哥(alei_go@163.com), "<<"山东理工大学(数学本科)/北京邮电大学(计算机研究生)"<<endl<<endl
      <<"数据结构开源代码(C++清华大学殷人昆)魔改升级版本: https://gitee.com/cyberdash/data-structure-cpp"<<endl
      <<endl<<"*************************************** CyberDash ***************************************"<<endl<<endl;
}


#endif //CYBER_DASH_GRAPH_ADJACENCY_LIST_H
