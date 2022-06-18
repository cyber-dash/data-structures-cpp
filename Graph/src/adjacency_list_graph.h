/*!
 * @file adjacency_list_graph.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 邻接表图模板类
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
 * @tparam Vertex 结点
 * @tparam Weight 边权值
 */
template <class Vertex, class Weight>
struct AdjListEdge {
  /*! @brief 构造函数(无参数) */
  AdjListEdge() {}

  /*! @brief 构造函数(边终点的结点索引and边权重) */
  AdjListEdge(int ending_vertex_index, Weight weight): ending_vertex_index(ending_vertex_index), weight(weight), next(NULL) {}

  /*! @brief 重载!= */
  bool operator != (AdjListEdge<Vertex, Weight>& edge) const {
    return (ending_vertex_index != edge.ending_vertex_index);
  }

  int ending_vertex_index; //!< 边终点的结点索引
  Weight weight; //!< 边权重
  AdjListEdge<Vertex, Weight>* next; //!< 下一邻接表图边的指针
};


/*!
 * @brief 邻接表图节点结构体
 * @tparam Vertex 结点参数模板类型
 * @tparam Weight 边权值参数模板类型
 */
template<class Vertex, class Weight>
struct AdjListVertex {
  Vertex starting_vertex; //!< 起始结点
  AdjListEdge<Vertex, Weight>* adjacency_list; //!< 邻接表
};


/*!
 * @brief 邻接表图模板类
 * @tparam Vertex 结点类型模板参数
 * @tparam Weight 边权值类型模板参数
 */
template<class Vertex, class Weight>
class AdjacencyListGraph: public Graph<Vertex, Weight> {
public:

  // 构造函数
  AdjacencyListGraph(int size = DEFAULT_VERTICES);

  // 析构函数
  ~AdjacencyListGraph();

  // 使用结点索引获取结点
  bool GetVertexByIndex(Vertex& vertex, int vertex_index);

  // (由边的两个结点)获取边权值
  bool GetWeight(Weight& weight, Vertex v1, Vertex v2);

  // (由边的两个结点索引)获取边权值
  bool GetWeightByVertexIndex(Weight& weight, int v1_index, int v2_index);

  // 插入结点
  bool InsertVertex(const Vertex& vertex);

  // 删除结点
  bool RemoveVertex(Vertex vertex);

  // 插入边
  bool InsertEdge(Vertex vertex1, Vertex vertex2, Weight weight);

  // 删除边
  bool RemoveEdge(Vertex vertex1, Vertex vertex2);

  // 获取第一个相邻结点
  bool GetFirstNeighborVertex(Vertex& first_neighbor, const Vertex& vertex);

  // 获取下一个相邻结点
  bool GetNextNeighborVertex(Vertex& next_neighbor, const Vertex& vertex, const Vertex& neighbor_vertex);

  // 获取结点索引
  int GetVertexIndex(Vertex vertex);

  // 输入图(重载标准输入)
  template<class U>
  friend istream& operator>>(istream& in, AdjacencyListGraph<Vertex, Weight>& graph_adjacency_list);
  // 打印图(重载标准输出)
  template<class U>
  friend ostream& operator<<(ostream& out, AdjacencyListGraph<Vertex, Weight>& graph_adjacency_list);

  /*! @brief 我们是CyberDash :-) */
  void CyberDashShow();
private:
  AdjListVertex<Vertex, Weight>* vertex_table_; //!< 邻接点数组
};


/*!
 * @brief 构造函数
 * @tparam Vertex 结点类型模板参数
 * @tparam Weight 边权值类型模板参数
 * @param size 结点数量
 */
template<class Vertex, class Weight>
AdjacencyListGraph<Vertex, Weight>::AdjacencyListGraph(int size) {

  this->max_vertex_cnt_ = size;
  this->vertex_cnt_ = 0;
  this->edge_cnt_ = 0;

  this->vertex_table_ = new AdjListVertex<Vertex, Weight>[this->max_vertex_cnt_];

  for (int i = 0; i < this->max_vertex_cnt_; i++) {
    this->vertex_table_[i].adjacency_list = NULL;
  }
}


template<class Vertex, class Weight>
AdjacencyListGraph<Vertex, Weight>::~AdjacencyListGraph() {

  for (int i = 0; i < this->vertex_cnt_; i++) {

    AdjListEdge<Vertex, Weight>* cur_edge = this->vertex_table_[i].adjacency_list;

    while (cur_edge != NULL) {
      this->vertex_table_[i].adjacency_list = cur_edge->next;
      delete cur_edge;
      cur_edge = this->vertex_table_[i].adjacency_list;
    }
  }

  delete[] this->vertex_table_;
}


/*!
 * @brief 使用结点索引获取结点
 * @param vertex 结点(保存结果的节点)
 * @param vertex_index 结点索引
 * @return 是否获取成功
 */
template<class Vertex, class Weight>
bool AdjacencyListGraph<Vertex, Weight>::GetVertexByIndex(Vertex& vertex, int vertex_index) {
  if (vertex_index >= 0 && vertex_index < this->vertex_cnt_) {
    vertex = this->vertex_table_[vertex_index].starting_vertex;

    return true;
  } else {
    return false;
  }
}


/*!
 * @brief (由边的两个结点)获取边权值
 * @tparam Vertex 结点类型模板参数
 * @tparam Weight 边权值类型模板参数
 * @param weight 边权值(用于保存结果)
 * @param v1 结点1
 * @param v2 结点2
 * @return 是否获取成功
 */
template<class Vertex, class Weight>
bool AdjacencyListGraph<Vertex, Weight>::GetWeight(Weight& weight, Vertex v1, Vertex v2) {

  int v1_index = this->GetVertexIndex(v1);
  int v2_index = this->GetVertexIndex(v2);
  if (v1_index < 0 || v2_index < 0) {
    return false;
  }

  bool res = GetWeightByVertexIndex(weight, v1_index, v2_index);

  return res;
}


/*!
 * (由边的两个结点索引)获取边权值
 * @tparam Vertex
 * @tparam Weight
 */
template<class Vertex, class Weight>
bool AdjacencyListGraph<Vertex, Weight>::GetWeightByVertexIndex(Weight& weight, int v1_index, int v2_index) {

    if (v1_index < 0 || v2_index < 0) {
        return false;
    }

    AdjListEdge<Vertex, Weight>* edge = this->vertex_table_[v1_index].adjacency_list;

    while (edge != NULL && edge->ending_vertex_index != v2_index) {
        edge = edge->next;
    }

    if (edge != NULL) {
        weight = edge->weight;
        return true;
    }

    return false;
}


/*!
 * @brief 插入结点
 * @param vertex 节点
 * @return 是否插入成功
 */
template<class V, class W>
bool AdjacencyListGraph<V, W>::InsertVertex(const V& vertex) {

  // 如果已有节点数大于限制, 则不执行插入, 返回失败
  if (this->vertex_cnt_ == this->max_vertex_cnt_) {
    return false;
  }

  this->vertex_table_[this->vertex_cnt_].starting_vertex = vertex; // vertex_table_增加结点数据
  this->vertex_cnt_++; // 结点数增加

  return true;
}


/*!
 * @brief 删除结点
 * @param vertex 节点
 * @return 是否删除成功
 */
template<class Vertex, class Weight>
bool AdjacencyListGraph<Vertex, Weight>::RemoveVertex(Vertex vertex) {

  int vertex_index = this->GetVertexIndex(vertex);

  if (this->vertex_cnt_ == 1 || vertex_index < 0 || vertex_index >= this->vertex_cnt_) {
    return false;
  }

  while (this->vertex_table_[vertex_index].adjacency_list != NULL) {

    AdjListEdge<Vertex, Weight>* prior = NULL;
    AdjListEdge<Vertex, Weight>* cur = this->vertex_table_[vertex_index].adjacency_list;
    int cur_vertex_index = cur->ending_vertex_index;

    AdjListEdge<Vertex, Weight>* delete_edge = this->vertex_table_[cur_vertex_index].adjacency_list;

    while (delete_edge != NULL && delete_edge->ending_vertex_index != vertex_index) {
      prior = delete_edge;
      delete_edge = delete_edge->next;
    }

    if (delete_edge != NULL) {
      if (prior == NULL) {
        this->vertex_table_[cur_vertex_index].adjacency_list = delete_edge->next;
      } else {
        prior->next = delete_edge->next;
      }

      delete delete_edge;
    }

    this->vertex_table_[vertex_index].adjacency_list = cur->next;

    delete cur;

    this->edge_cnt_--;
  }

  this->vertex_cnt_--;

  this->vertex_table_[vertex_index].starting_vertex = this->vertex_table_[this->vertex_cnt_].starting_vertex;
  this->vertex_table_[vertex_index].adjacency_list = this->vertex_table_[this->vertex_cnt_].adjacency_list;

  AdjListEdge<Vertex, Weight>* cur = this->vertex_table_[this->vertex_cnt_].adjacency_list;
  while (cur != NULL) {

    AdjListEdge<Vertex, Weight>* modify_edge = this->vertex_table_[cur->ending_vertex_index].adjacency_list;

    while (modify_edge != NULL) {
      if (modify_edge->ending_vertex_index == this->vertex_cnt_) {
        modify_edge->ending_vertex_index = vertex_index;
        break;
      } else {
        modify_edge = modify_edge->next;
      }
    }

    cur = cur->next;
  }

  this->vertex_table_[this->vertex_cnt_].adjacency_list = NULL;

  return true;
}


/*!
 * @brief 插入边
 * @param vertex1 边节点1
 * @param vertex2 边节点2
 * @param weight 边权值
 * @return 是否插入成功
 */
template<class V, class W>
bool AdjacencyListGraph<V, W>::InsertEdge(V vertex1, V vertex2, W weight) {

  int vertex1_index = this->GetVertexIndex(vertex1);
  int vertex2_index = this->GetVertexIndex(vertex2);

  // 检查vertex1和vertex2合法性, 是否在图中
  if (vertex1_index < 0 || vertex1_index >= this->vertex_cnt_ || vertex2_index < 0 || vertex2_index >= this->vertex_cnt_) {
    return false;
  }

  // 在邻接表中找 vertex1_index --> vertex2_index 是否存在, 如果存在说明边已经存在, 不能插入
  AdjListEdge<V, W>* cur_edge = this->vertex_table_[vertex1_index].adjacency_list;
  while (cur_edge != NULL && cur_edge->ending_vertex_index != vertex2_index) {
    cur_edge = cur_edge->next;
  }

  if (cur_edge != NULL) {
    return false;
  }

  AdjListEdge<V, W>* v2_dest_edge = new AdjListEdge<V, W>(); // vertex1 --> vertex2
  AdjListEdge<V, W>* v1_dest_edge = new AdjListEdge<V, W>(); // vertex2 --> vertex1
  /* error handler */

  // 更新邻接表内对应的数据
  v2_dest_edge->ending_vertex_index = vertex2_index;
  v2_dest_edge->weight = weight;
  v2_dest_edge->next = this->vertex_table_[vertex1_index].adjacency_list;
  this->vertex_table_[vertex1_index].adjacency_list = v2_dest_edge;

  v1_dest_edge->ending_vertex_index = vertex1_index;
  v1_dest_edge->weight = weight;
  v1_dest_edge->next = this->vertex_table_[vertex2_index].adjacency_list;
  this->vertex_table_[vertex2_index].adjacency_list = v1_dest_edge;

  this->edge_cnt_++; // 边的数量+1

  return true;
}


/*!
 * @brief 删除边
 * @param vertex1 边结点1
 * @param vertex2 边结点2
 * @return 是否删除成功
 */
template<class V, class W>
bool AdjacencyListGraph<V, W>::RemoveEdge(V vertex1, V vertex2) {

  // 获取两个结点在vertex_table_的数组索引, 如果有一个不存在, 则返回false
  int vertex1_index = this->GetVertexIndex(vertex1);
  int vertex2_index = this->GetVertexIndex(vertex2);

  if (vertex1_index < 0 && vertex2_index < 0) {
    return false;
  }

  AdjListEdge<V, W>* delete_edge; // 待删除结点
  AdjListEdge<V, W>* prior_edge; // 待删除结点的前一节点
  AdjListEdge<V, W>* first_edge; // 第一个邻接结点就是待删除结点

  // vertex1 --> vertex2做删除
  delete_edge = this->vertex_table_[vertex1_index].adjacency_list;
  prior_edge = NULL;
  first_edge = this->vertex_table_[vertex1_index].adjacency_list;

  // 定位delete_edge_ptr和prior_edge_ptr
  while (delete_edge != NULL && delete_edge->ending_vertex_index != vertex2_index) {
    prior_edge = delete_edge;
    delete_edge = delete_edge->next;
  }

  if (delete_edge != NULL) {
    if (first_edge == delete_edge) { // 如果第一个邻接结点就是待删除结点
      this->vertex_table_[vertex1_index].adjacency_list = delete_edge->next;
    } else { // 第一个结点不是待删除结点
      prior_edge->next = delete_edge->next;

      delete delete_edge;
    }
  } else {
    return false; // 如果没有待删除结点, 则返回false
  }

  // vertex2 --> vertex1做删除
  delete_edge = this->vertex_table_[vertex2_index].adjacency_list;
  prior_edge = NULL;
  first_edge = this->vertex_table_[vertex2_index].adjacency_list;

  while (delete_edge != NULL && delete_edge->ending_vertex_index != vertex1_index) {
    prior_edge = delete_edge;
    delete_edge = delete_edge->next;
  }

  if (delete_edge != NULL) {
    if (first_edge == delete_edge) {
      this->vertex_table_[vertex2_index].adjacency_list = delete_edge->next;
    } else {
      prior_edge->next = delete_edge->next;

      delete delete_edge;
    }
  } else {
    return false;
  }

  // 边的总数减1
  this->edge_cnt_--;

  return true;
}


/*!
 * @brief 获取第一个相邻结点
 * @param first_neighbor 第一个相邻结点(用于保存节点)
 * @param vertex 节点
 * @return 是否获取成功
 */
template<class V, class W>
bool AdjacencyListGraph<V, W>::GetFirstNeighborVertex(V& first_neighbor, const V& vertex) {

  int vertex_index = this->GetVertexIndex(vertex); // 获取结点在vertex_table_的数组索引

  if (vertex_index >= 0) {
    AdjListEdge<V, W>* edge = this->vertex_table_[vertex_index].adjacency_list;
    if (edge != NULL) {

      int neighbor_index = edge->ending_vertex_index; // 第一个邻接结点的dest_index_

      bool has_vertex = this->GetVertexByIndex(first_neighbor, neighbor_index); // 取dest_index对应的结点

      return has_vertex;
    }
  }

  return false;
}


/*!
 * @brief 获取下一个相邻结点
 * @param next_neighbor 下一个相邻结点(用于保存结点)
 * @param vertex 结点
 * @param neighbor_vertex 当前相邻结点
 * @return 是否获取成功
 */
template<class V, class W>
bool AdjacencyListGraph<V, W>::GetNextNeighborVertex(V& next_neighbor, const V& vertex, const V& neighbor_vertex) {

  // 拿到vertex和neighbor_vertex对应的vertex_table_的数组索引
  int vertex_index = GetVertexIndex(vertex);
  int neighbor_index = GetVertexIndex(neighbor_vertex);

  if (vertex_index >= 0) {

    // 邻接表中, 找到neighbor_vertex的位置
    AdjListEdge<V, W>* edge_ptr = this->vertex_table_[vertex_index].adjacency_list;

    while (edge_ptr->next != NULL && edge_ptr->ending_vertex_index != neighbor_index) {
      edge_ptr = edge_ptr->next;
    }

    // 将下一个位置的结点赋给next_neighbor
    if (edge_ptr != NULL && edge_ptr->next != NULL) {
      int next_neighbor_index = edge_ptr->next->ending_vertex_index;

      bool has_next_neighbor = this->GetVertexByIndex(next_neighbor, next_neighbor_index);

      return has_next_neighbor;
    }
  }

  return false;
}


/*!
 * @brief 输入图
 * @tparam V 结点类型模板参数
 * @tparam W 边权值类型模板参数
 * @param in 输入流(引用)
 * @param graph_adjacency_list 邻接表图
 * @return 输入流(引用)
 */
template<class V, class W>
istream& operator>>(istream& in, AdjacencyListGraph<V, W>& graph_adjacency_list) {

  int vertex_num;
  int edge_num;

  cout<<"Input the vertex_num and edge_num"<<endl;
  in >> vertex_num >> edge_num;

  for (int i = 0; i < vertex_num; i++) {

    V vertex;

    cout<<"Input starting_vertex "<<i<<":"<<endl;
    in >> vertex;

    bool insert_done = graph_adjacency_list.InsertVertex(vertex);
    if (insert_done) {
      cout<<"Insert starting_vertex "<<i<<" done."<<endl;
    } else {
      cout<<"Insert starting_vertex "<<i<<" failed."<<endl;
      exit(1);
    }
  }

  for (int i = 0; i < edge_num; i++) {

    V src_vertex;
    V dest_vertex;
    W weight;

    cout<<"AdjListEdge "<<i<<":"<<endl;
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


/*!
 * @brief 输出(打印)图
 * @tparam V 结点类型模板参数
 * @tparam W 边权值类型模板参数
 * @param out 输出流(引用)
 * @param graph_adjacency_list 邻接表图
 * @return 输出流(引用)
 */
template<class V, class W>
ostream& operator<<(ostream& out, AdjacencyListGraph<V, W>& graph_adjacency_list) {

  int vertex_num = graph_adjacency_list.VertexCount();
  int edge_num = graph_adjacency_list.EdgeCount();

  cout<<"vertex_num: "<<vertex_num<<", edge_num: "<<edge_num<<endl;

  if (edge_num == 0) {
    cout<<"No edge"<<endl;
    return out;
  }

  for (int src_vertex_index = 0; src_vertex_index < vertex_num; src_vertex_index++) {
    for (int dest_vertex_index = 0; dest_vertex_index < vertex_num; dest_vertex_index++) {

      V src_vertex;
      V dest_vertex;

      bool get_src_value_done = graph_adjacency_list.GetVertexByIndex(src_vertex, src_vertex_index);
      bool get_dest_value_done = graph_adjacency_list.GetVertexByIndex(dest_vertex, dest_vertex_index);

      if (get_src_value_done && get_dest_value_done) {

        W weight;
        bool hasWeight = graph_adjacency_list.GetWeight(weight, src_vertex, dest_vertex);

        if (hasWeight) {
          out << "(" << src_vertex << "," << dest_vertex << "," << weight << ")" << endl;
        }
      }
    }
  }

  return out;
}


/*!
 * @brief 获取结点索引
 * @param vertex 结点
 * @return 结点索引
 */
template<class V, class W>
int AdjacencyListGraph<V, W>::GetVertexIndex(V vertex) {

  int vertex_index = -1; // 如果图中没有该结点, 则返回-1

  // 在vertex_table_中查哪个的value_为vertex
  for (int i = 0; i < this->vertex_cnt_; i++) {
    if (this->vertex_table_[i].starting_vertex == vertex) {
      vertex_index = i;
      break;
    }
  }

  return vertex_index;
}


template<class V, class W>
void AdjacencyListGraph<V, W>::CyberDashShow() {
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
