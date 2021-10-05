/*!
 * @file adjacency_list_graph.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 邻接表图类
 * @version 0.2.1
 * @date 2021-01-16
 *
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#ifndef CYBER_DASH_ADJACENCY_LIST_GRAPH_H
#define CYBER_DASH_ADJACENCY_LIST_GRAPH_H


#include <iostream>
#include <cstdlib>
#include "graph.h"


using namespace std;


/*!
 * @brief 邻接表图边结构体模板
 * @tparam V
 * @tparam W
 */
template <class V, class W>
struct Edge {
  /*! @brief 构造函数(无参数) */
  Edge() {}

  /*! @brief 构造函数(边终点的结点索引and边权重) */
  Edge(int num, W weight): dest_index(num), weight(weight), next(NULL) {}

  /*! @brief 重载!= */
  bool operator != (Edge<V, W>& edge) const {
    return (dest_index != edge.dest_index);
  }

  int dest_index; //!< 边终点的结点索引
  W weight; //!< 边权重
  Edge<V, W>* next; //!< 下一邻接表图边的指针
};


/*!
 * @brief 邻接表图节点结构体
 * @tparam V 结点参数模板类型
 * @tparam W 边权值参数模板类型
 */
template<class V, class W>
struct Vertex {
  V vertex; //!< 结点
  Edge<V, W>* adjacency_list; //!< 邻接表
};


/*!
 * @brief 邻接表图模板类
 * @tparam V 结点参数模板类型
 * @tparam W 边权值参数模板类型
 */
template<class V, class W>
class AdjacencyListGraph: public Graph<V, W> {
public:

  // 构造函数
  AdjacencyListGraph(int size = DEFAULT_VERTICES);

  // 析构函数
  ~AdjacencyListGraph();

  /**
   * @brief 使用结点索引获取结点
   * @param vertex 结点(保存结果的节点)
   * @param vertex_index 结点索引
   * @return 是否获取成功
   */
  bool GetVertexByIndex(V& vertex, int vertex_index);

  /**
   * @brief 获取边权值
   * @param weight 边权值(用于保存结果)
   * @param vertex1 边的节点1
   * @param vertex2 边的节点2
   * @return 是否获取成功
   */
  bool GetWeight(W& weight, V vertex1, V vertex2);

  // 插入结点
  bool InsertVertex(const V& vertex);

  // 删除结点
  bool RemoveVertex(V vertex);

  // 插入边
  bool InsertEdge(V vertex1, V vertex2, W weight);

  // 删除边
  bool RemoveEdge(V vertex1, V vertex2);

  // 获取第一个相邻结点
  bool GetFirstNeighborVertex(V& first_neighbor, const V& vertex);

  // 获取下一个相邻结点
  bool GetNextNeighborVertex(V& next_neighbor, const V& vertex, const V& neighbor_vertex);

  // 获取结点索引
  int GetVertexIndex(V vertex);

  // 输入图(重载标准输入)
  template<class U>
  friend istream& operator>>(istream& in, AdjacencyListGraph<V, W>& graph_adjacency_list);
  // 打印图(重载标准输出)
  template<class U>
  friend ostream& operator<<(ostream& out, AdjacencyListGraph<V, W>& graph_adjacency_list);

  /*! @brief 我们是CyberDash :-) */
  void CyberDashShow();
private:
  Vertex<V, W>* vertex_table_; //!< 邻接点数组
};


/*!
 * @brief 构造函数
 * @tparam V 结点类型模板参数
 * @tparam W 边权值类型模板参数
 * @param size 结点数量
 */
template<class V, class W>
AdjacencyListGraph<V, W>::AdjacencyListGraph(int size) {

  this->max_vertices_num_ = size;
  this->vertices_num_ = 0;
  this->edge_count_ = 0;

  this->vertex_table_ = new Vertex<V, W>[this->max_vertices_num_];

  for (int i = 0; i < this->max_vertices_num_; i++) {
    this->vertex_table_[i].adjacency_list = NULL;
  }
}


template<class T, class E>
AdjacencyListGraph<T, E>::~AdjacencyListGraph() {

  for (int i = 0; i < this->vertices_num_; i++) {

    Edge<T, E>* cur_edge = this->vertex_table_[i].adjacency_list;

    while (cur_edge != NULL) {
      this->vertex_table_[i].adjacency_list = cur_edge->next;
      delete cur_edge;
      cur_edge = this->vertex_table_[i].adjacency_list;
    }
  }

  delete[] this->vertex_table_;
}


/**
 * @brief 使用结点索引获取结点
 * @param vertex 结点(保存结果的节点)
 * @param vertex_index 结点索引
 * @return 是否获取成功
 */
template<class T, class E>
bool AdjacencyListGraph<T, E>::GetVertexByIndex(T& vertex, int vertex_index) {
  if (vertex_index >= 0 && vertex_index < this->vertices_num_) {
    vertex = this->vertex_table_[vertex_index].vertex;

    return true;
  } else {
    return false;
  }
}


template<class T, class E>
bool AdjacencyListGraph<T, E>::GetWeight(E& weight, T vertex1, T vertex2) {

  int vertex1_index = this->GetVertexIndex(vertex1);
  int vertex2_index = this->GetVertexIndex(vertex2);

  if (vertex1_index < 0 || vertex2_index < 0) {
    return false;
  }

  Edge<T, E>* edge_ptr = this->vertex_table_[vertex1_index].adjacency_list;

  while (edge_ptr != NULL && edge_ptr->dest_index != vertex2_index) {
    edge_ptr = edge_ptr->next;
  }

  if (edge_ptr != NULL) {
    weight = edge_ptr->weight;
    return true;
  }

  return false;
}


/**
 * @brief 插入结点
 * @param vertex 节点
 * @return 是否插入成功
 */
template<class T, class E>
bool AdjacencyListGraph<T, E>::InsertVertex(const T& vertex) {

  // 如果已有节点数大于限制, 则不执行插入, 返回失败
  if (this->vertices_num_ == this->max_vertices_num_) {
    return false;
  }

  this->vertex_table_[this->vertices_num_].vertex = vertex; // vertex_table_增加结点数据
  this->vertices_num_++; // 结点数增加

  return true;
}


/**
 * @brief 删除结点
 * @param vertex 节点
 * @return 是否删除成功
 */
template<class T, class E>
bool AdjacencyListGraph<T, E>::RemoveVertex(T vertex) {

  int vertex_index = this->GetVertexIndex(vertex);

  if (this->vertices_num_ == 1 || vertex_index < 0 || vertex_index >= this->vertices_num_) {
    return false;
  }

  while (this->vertex_table_[vertex_index].adjacency_list != NULL) {

    Edge<T, E>* prior_ptr = NULL;
    Edge<T, E>* cur_ptr = this->vertex_table_[vertex_index].adjacency_list;
    int cur_vertex_index = cur_ptr->dest_index;

    Edge<T, E>* delete_ptr = this->vertex_table_[cur_vertex_index].adjacency_list;

    while (delete_ptr != NULL && delete_ptr->dest_index != vertex_index) {
      prior_ptr = delete_ptr;
      delete_ptr = delete_ptr->next;
    }

    if (delete_ptr != NULL) {
      if (prior_ptr == NULL) {
        this->vertex_table_[cur_vertex_index].adjacency_list = delete_ptr->next;
      } else {
        prior_ptr->next = delete_ptr->next;
      }

      delete delete_ptr;
    }

    this->vertex_table_[vertex_index].adjacency_list = cur_ptr->next;

    delete cur_ptr;

    this->edge_count_--;
  }

  this->vertices_num_--;

  this->vertex_table_[vertex_index].vertex = this->vertex_table_[this->vertices_num_].vertex;
  this->vertex_table_[vertex_index].adjacency_list = this->vertex_table_[this->vertices_num_].adjacency_list;

  Edge<T, E>* cur_ptr = this->vertex_table_[this->vertices_num_].adjacency_list;
  while (cur_ptr != NULL) {

    Edge<T, E>* modify_edge_ptr = this->vertex_table_[cur_ptr->dest_index].adjacency_list;

    while (modify_edge_ptr != NULL) {
      if (modify_edge_ptr->dest_index == this->vertices_num_) {
        modify_edge_ptr->dest_index = vertex_index;
        break;
      } else {
        modify_edge_ptr = modify_edge_ptr->next;
      }
    }

    cur_ptr = cur_ptr->next;
  }

  this->vertex_table_[this->vertices_num_].adjacency_list = NULL;

  return true;
}


/**
 * @brief 插入边
 * @param vertex1 边节点1
 * @param vertex2 边节点2
 * @param weight 边权值
 * @return 是否插入成功
 */
template<class T, class E>
bool AdjacencyListGraph<T, E>::InsertEdge(T vertex1, T vertex2, E weight) {

  int vertex1_index = this->GetVertexIndex(vertex1);
  int vertex2_index = this->GetVertexIndex(vertex2);

  // 检查vertex1和vertex2合法性, 是否在图中
  if (vertex1_index < 0 || vertex1_index >= this->vertices_num_ || vertex2_index < 0 || vertex2_index >= this->vertices_num_) {
    return false;
  }

  // 在邻接表中找 vertex1_index --> vertex2_index 是否存在, 如果存在说明边已经存在, 不能插入
  Edge<T, E>* cur_edge_ptr = this->vertex_table_[vertex1_index].adjacency_list;
  while (cur_edge_ptr != NULL && cur_edge_ptr->dest_index != vertex2_index) {
    cur_edge_ptr = cur_edge_ptr->next;
  }

  if (cur_edge_ptr != NULL) {
    return false;
  }

  Edge<T, E>* v2_dest_edge_ptr = new Edge<T, E>(); // vertex1 --> vertex2
  Edge<T, E>* v1_dest_edge_ptr = new Edge<T, E>(); // vertex2 --> vertex1
  /* error handler */

  // 更新邻接表内对应的数据
  v2_dest_edge_ptr->dest_index = vertex2_index;
  v2_dest_edge_ptr->weight = weight;
  v2_dest_edge_ptr->next = this->vertex_table_[vertex1_index].adjacency_list;
  this->vertex_table_[vertex1_index].adjacency_list = v2_dest_edge_ptr;

  v1_dest_edge_ptr->dest_index = vertex1_index;
  v1_dest_edge_ptr->weight = weight;
  v1_dest_edge_ptr->next = this->vertex_table_[vertex2_index].adjacency_list;
  this->vertex_table_[vertex2_index].adjacency_list = v1_dest_edge_ptr;

  this->edge_count_++; // 边的数量+1

  return true;
}


/**
 * @brief 删除边
 * @param vertex1 边结点1
 * @param vertex2 边结点2
 * @return 是否删除成功
 */
template<class T, class E>
bool AdjacencyListGraph<T, E>::RemoveEdge(T vertex1, T vertex2) {

  // 获取两个结点在vertex_table_的数组索引, 如果有一个不存在, 则返回false
  int vertex1_index = this->GetVertexIndex(vertex1);
  int vertex2_index = this->GetVertexIndex(vertex2);

  if (vertex1_index < 0 && vertex2_index < 0) {
    return false;
  }

  Edge<T, E>* delete_edge_ptr; // 待删除结点
  Edge<T, E>* prior_edge_ptr; // 待删除结点的前一节点
  Edge<T, E>* first_edge_ptr; // 第一个邻接结点就是待删除结点

  // vertex1 --> vertex2做删除
  delete_edge_ptr = this->vertex_table_[vertex1_index].adjacency_list;
  prior_edge_ptr = NULL;
  first_edge_ptr = this->vertex_table_[vertex1_index].adjacency_list;

  // 定位delete_edge_ptr和prior_edge_ptr
  while (delete_edge_ptr != NULL && delete_edge_ptr->dest_index != vertex2_index) {
    prior_edge_ptr = delete_edge_ptr;
    delete_edge_ptr = delete_edge_ptr->next;
  }

  if (delete_edge_ptr != NULL) {
    if (first_edge_ptr == delete_edge_ptr) { // 如果第一个邻接结点就是待删除结点
      this->vertex_table_[vertex1_index].adjacency_list = delete_edge_ptr->next;
    } else { // 第一个结点不是待删除结点
      prior_edge_ptr->next = delete_edge_ptr->next;

      delete delete_edge_ptr;
    }
  } else {
    return false; // 如果没有待删除结点, 则返回false
  }

  // vertex2 --> vertex1做删除
  delete_edge_ptr = this->vertex_table_[vertex2_index].adjacency_list;
  prior_edge_ptr = NULL;
  first_edge_ptr = this->vertex_table_[vertex2_index].adjacency_list;

  while (delete_edge_ptr != NULL && delete_edge_ptr->dest_index != vertex1_index) {
    prior_edge_ptr = delete_edge_ptr;
    delete_edge_ptr = delete_edge_ptr->next;
  }

  if (delete_edge_ptr != NULL) {
    if (first_edge_ptr == delete_edge_ptr) {
      this->vertex_table_[vertex2_index].adjacency_list = delete_edge_ptr->next;
    } else {
      prior_edge_ptr->next = delete_edge_ptr->next;

      delete delete_edge_ptr;
    }
  } else {
    return false;
  }

  // 边的总数减1
  this->edge_count_--;

  return true;
}


/**
 * 获取第一个相邻结点
 * @param first_neighbor 第一个相邻结点(用于保存节点)
 * @param vertex 节点
 * @return 是否获取成功
 */
template<class T, class E>
bool AdjacencyListGraph<T, E>::GetFirstNeighborVertex(T& first_neighbor, const T& vertex) {

  int vertex_index = this->GetVertexIndex(vertex); // 获取结点在vertex_table_的数组索引

  if (vertex_index >= 0) {
    Edge<T, E>* edge_ptr = this->vertex_table_[vertex_index].adjacency_list;
    if (edge_ptr != NULL) {

      int neighbor_index = edge_ptr->dest_index; // 第一个邻接结点的dest_index_

      bool has_vertex = this->GetVertexByIndex(first_neighbor, neighbor_index); // 取dest_index对应的结点

      return has_vertex;
    }
  }

  return false;
}


/**
 * @brief 获取下一个相邻结点
 * @param next_neighbor 下一个相邻结点(用于保存结点)
 * @param vertex 结点
 * @param neighbor_vertex 当前相邻结点
 * @return 是否获取成功
 */
template<class T, class E>
bool AdjacencyListGraph<T, E>::GetNextNeighborVertex(T& next_neighbor, const T& vertex, const T& neighbor_vertex) {

  // 拿到vertex和neighbor_vertex对应的vertex_table_的数组索引
  int vertex_index = GetVertexIndex(vertex);
  int neighbor_index = GetVertexIndex(neighbor_vertex);

  if (vertex_index >= 0) {

    // 邻接表中, 找到neighbor_vertex的位置
    Edge<T, E>* edge_ptr = this->vertex_table_[vertex_index].adjacency_list;

    while (edge_ptr->next != NULL && edge_ptr->dest_index != neighbor_index) {
      edge_ptr = edge_ptr->next;
    }

    // 将下一个位置的结点赋给next_neighbor
    if (edge_ptr != NULL && edge_ptr->next != NULL) {
      int next_neighbor_index = edge_ptr->next->dest_index;

      bool has_next_neighbor = this->GetVertexByIndex(next_neighbor, next_neighbor_index);

      return has_next_neighbor;
    }
  }

  return false;
}


template<class T, class E>
istream& operator>>(istream& in, AdjacencyListGraph<T, E>& graph_adjacency_list) {

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
ostream& operator<<(ostream& out, AdjacencyListGraph<T, E>& graph_adjacency_list) {

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

      bool get_src_value_done = graph_adjacency_list.GetVertexByIndex(src_vertex, src_vertex_index);
      bool get_dest_value_done = graph_adjacency_list.GetVertexByIndex(dest_vertex, dest_vertex_index);

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


/**
 * @brief 获取结点索引
 * @param vertex 结点
 * @return 结点索引
 */
template<class T, class E>
int AdjacencyListGraph<T, E>::GetVertexIndex(T vertex) {

  int vertex_index = -1; // 如果图中没有该结点, 则返回-1

  // 在vertex_table_中查哪个的value_为vertex
  for (int i = 0; i < this->vertices_num_; i++) {
    if (this->vertex_table_[i].vertex == vertex) {
      vertex_index = i;
      break;
    }
  }

  return vertex_index;
}


template<class T, class E>
void AdjacencyListGraph<T, E>::CyberDashShow() {
  cout<<endl
      <<"*************************************** CyberDash ***************************************"<<endl<<endl
      <<"抖音号\"CyberDash计算机考研\", id: cyberdash_yuan"<<endl<<endl
      <<"CyberDash成员:"<<endl
      <<"元哥(cyberdash@163.com), "<<"北京邮电大学(通信工程本科)/北京邮电大学(信息与通信系统研究生)"<<endl
      <<"磊哥(alei_go@163.com), "<<"山东理工大学(数学本科)/北京邮电大学(计算机研究生)"<<endl<<endl
      <<"数据结构开源代码(C++清华大学殷人昆)魔改升级版本: https://gitee.com/cyberdash/data-structure-cpp"<<endl
      <<endl<<"*************************************** CyberDash ***************************************"<<endl<<endl;
}


#endif // CYBER_DASH_ADJACENCY_LIST_GRAPH_H
