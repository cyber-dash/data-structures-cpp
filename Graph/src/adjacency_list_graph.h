/*!
 * @file adjacency_list_graph.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 邻接表图模板类
 * @version 0.2.1
 * @date 2021-01-16
 */

#ifndef CYBER_DASH_ADJACENCY_LIST_GRAPH_H
#define CYBER_DASH_ADJACENCY_LIST_GRAPH_H


#include <iostream>
#include <cstdlib>
#include <vector>
#include "graph.h"


using namespace std;


/*!
 * @brief 邻接表图边结构体模板
 * @tparam TVertex 结点
 * @tparam TWeight 边权值
 */
template <class TVertex, class TWeight>
struct Adjacency {
  /*! @brief 构造函数(无参数) */
  Adjacency(): ending_vertex_index(-1), next(NULL) {};

  /*! @brief 构造函数(边终点的结点索引and边权重) */
  Adjacency(const TVertex& ending_vertex,
            int ending_vertex_index,
            const TWeight& weight,
            Adjacency<TVertex, TWeight>* next = NULL):
    ending_vertex(ending_vertex), ending_vertex_index(ending_vertex_index), weight(weight), next(next) {}

  /*! @brief 重载!= */
  bool operator != (const Adjacency<TVertex, TWeight>& adjacency) const {
    return (this->ending_vertex_index != adjacency.ending_vertex_index);
  }

  Adjacency<TVertex, TWeight>& operator=(const Adjacency<TVertex, TWeight>& adjacency) {
      if (&adjacency == this) {
          return *this;
      }

      this->ending_vertex_index = adjacency.ending_vertex_index;
      this->ending_vertex = adjacency.ending_vertex;
      this->weight = adjacency.weight;
      this->next = adjacency.next;
  }

  int ending_vertex_index;            //!< 边终点的结点索引
  TVertex ending_vertex;              //!< 边终点
  TWeight weight;                     //!< 边权重
  Adjacency<TVertex, TWeight>* next;  //!< 下一邻接边
};


/*!
 * @brief 结点邻接信息模板类
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 */
template<typename TVertex, typename TWeight>
struct VertexAdjacencies {
    VertexAdjacencies(): adjacency(NULL) {}
    TVertex starting_vertex;                         //!< 起始结点
    Adjacency<TVertex, TWeight>* adjacency;        //!< 邻接边数组
};


template<typename TVertex, typename TWeight> class AdjacencyListGraph;
// 输入图(重载标准输入)
template<typename TVertex, typename TWeight>
istream& operator>>(istream& in, AdjacencyListGraph<TVertex, TWeight>& adjacency_list_graph);
// 打印图(重载标准输出)
template<typename TVertex, typename TWeight>
ostream& operator<<(ostream& out, AdjacencyListGraph<TVertex, TWeight>& adjacency_list_graph);


/*!
 * @brief 邻接表图模板类
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 */
template<typename TVertex, typename TWeight>
class AdjacencyListGraph: public Graph<TVertex, TWeight> {
public:

    // 构造函数
    AdjacencyListGraph(int max_vertex_count, TWeight max_weight);

    AdjacencyListGraph(int max_vertex_count,
                       TWeight max_weight,
                       const vector<Edge<TVertex, TWeight> >& edges,
                       const vector<TVertex>& vertices);

    // 析构函数
    ~AdjacencyListGraph();

    // 使用结点索引获取结点
    bool GetVertexByIndex(int vertex_index, TVertex& vertex);

    // (由边的两个结点)获取边权值
    bool GetWeight(TVertex starting_vertex, TVertex ending_vertex, TWeight& weight);

    // (由边的两个结点索引)获取边权值
    bool GetWeightByVertexIndex(int starting_vertex_index, int ending_vertex_index, TWeight& weight);

    // 插入结点
    bool InsertVertex(const TVertex& vertex);

    // 删除结点
    bool RemoveVertex(const TVertex& vertex);

    // 插入边
    bool InsertEdge(const TVertex& starting_vertex, const TVertex& ending_vertex, const TWeight& weight);

    // 删除边
    bool RemoveEdge(TVertex vertex1, TVertex vertex2);

    // 获取第一个相邻结点
    bool GetFirstNeighborVertex(const TVertex& vertex, TVertex& first_neighbor);

    // 获取下一个相邻结点
    // bool GetNextNeighborVertex(TVertex& next_neighbor, const TVertex& vertex, const TVertex& neighbor_vertex);    // todo: 参数循序调整
    bool GetNextNeighborVertex(const TVertex& vertex, const TVertex& neighbor_vertex, TVertex& next_neighbor);    // todo: 参数循序调整

    // 获取结点索引
    int GetVertexIndex(TVertex vertex);

    // 输入图(重载标准输入)
    friend istream& operator>>(istream& in, AdjacencyListGraph<TVertex, TWeight>& graph_adjacency_list);
    // 打印图(重载标准输出)
    friend ostream& operator<<(ostream& out, AdjacencyListGraph<TVertex, TWeight>& graph_adjacency_list);

private:
    VertexAdjacencies<TVertex, TWeight>* adjacency_list_; //!< 邻接表
};


/*!
 * @brief 构造函数
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param max_vertex_count 结点数量
 */
template<class TVertex, class TWeight>
AdjacencyListGraph<TVertex, TWeight>::AdjacencyListGraph(int max_vertex_count, TWeight max_weight) {

  this->max_vertex_count_ = max_vertex_count;
  this->max_weight_ = max_weight;
  this->vertex_count_ = 0;
  this->edge_count_ = 0;

  this->adjacency_list_ = new VertexAdjacencies<TVertex, TWeight>[this->max_vertex_count_];

  for (int i = 0; i < this->max_vertex_count_; i++) {
    this->adjacency_list_[i].adjacency = NULL;
  }
}


template<typename TVertex, typename TWeight>
AdjacencyListGraph<TVertex, TWeight>::AdjacencyListGraph(int max_vertex_count,
                                                         TWeight max_weight,
                                                         const vector<Edge<TVertex, TWeight> >& edges,
                                                         const vector<TVertex>& vertices)
{
    if (max_vertex_count < vertices.size()) {
        throw length_error("vertices size wrong");
    }

    this->max_vertex_count_ = max_vertex_count;
    this->max_weight_ = max_weight;

    this->vertex_count_ = 0;
    this->edge_count_ = 0;

    this->adjacency_list_ = new VertexAdjacencies<TVertex, TWeight>[this->max_vertex_count_];
    if (!this->adjacency_list_) {
        throw bad_alloc();
    }

    for (unsigned int i = 0; i < this->vertices_.size(); i++) {
        this->InsertVertex(vertices[i]);
    }

    for (unsigned int i = 0; i < edges.size(); i++) {
        TVertex starting_vertex = edges[i].starting_vertex;
        TVertex ending_vertex = edges[i].ending_vertex;
        TWeight weight = edges[i].weight;

        this->InsertEdge(starting_vertex, ending_vertex, weight);
    }
}


/*!
 * @brief **邻接表图析构函数**
 * @tparam TVertex
 * @tparam TWeight
 */
template<typename TVertex, typename TWeight>
AdjacencyListGraph<TVertex, TWeight>::~AdjacencyListGraph() {
    for (int i = 0; i < this->vertex_count_; i++) {
        Adjacency<TVertex, TWeight>* temp = this->adjacency_list_[i].adjacency; // temp指向待删除邻接元素

        while (temp != NULL) {
            this->adjacency_list_[i].adjacency = temp->next;
            delete temp;
            temp = this->adjacency_list_[i].adjacency;
        }
    }

    delete[] this->adjacency_list_;
}


/*!
 * @brief **使用结点索引获取结点**
 * @param vertex 结点保存变量
 * @param vertex_index 结点索引
 * @return 执行结果
 */
template<typename TVertex, typename TWeight>
bool AdjacencyListGraph<TVertex, TWeight>::GetVertexByIndex(int vertex_index, TVertex& vertex) {
    if (vertex_index >= 0 && vertex_index < this->vertex_count_) {
        vertex = this->adjacency_list_[vertex_index].starting_vertex;

        return true;
    }

    return false;
}


/*!
 * @brief **获取边权值(by结点)**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param weight 边权值保存变量
 * @param starting_vertex 起点
 * @param ending_vertex 终点
 * @return 执行结果
 */
template<typename TVertex, typename TWeight>
bool AdjacencyListGraph<TVertex, TWeight>::GetWeight(TVertex starting_vertex, TVertex ending_vertex, TWeight& weight) {
    int starting_vertex_index = this->GetVertexIndex(starting_vertex);
    Adjacency<TVertex, TWeight>* cur = this->adjacency_list_[starting_vertex_index].adjacency;

    while (cur && cur->ending_vertex != ending_vertex) {
        cur = cur->next;
    }

    if (cur) {
        weight = cur->weight;
        return true;
    }

    return false;
}


/*!
 * @brief **获取边权值(by结点索引)**
 * @tparam TVertex
 * @tparam TWeight
 */
template<typename TVertex, typename TWeight>
bool AdjacencyListGraph<TVertex, TWeight>::GetWeightByVertexIndex(int starting_vertex_index,
                                                                  int ending_vertex_index,
                                                                  TWeight& weight)
{
    if (starting_vertex_index < 0 || ending_vertex_index < 0) {
        return false;
    }

    Adjacency<TVertex, TWeight>* cur = this->adjacency_list_[starting_vertex_index].adjacency;

    while (cur && cur->ending_vertex_index != ending_vertex_index) {
        cur = cur->next;
    }

    if (cur) {
        weight = cur->weight;
        return true;
    }

    return false;
}


/*!
 * @brief **插入结点**
 * @param vertex 结点
 * @return 执行结果
 */
template<typename TVertex, typename TWeight>
bool AdjacencyListGraph<TVertex, TWeight>::InsertVertex(const TVertex& vertex) {

  // 如果已有节点数大于限制, 则不执行插入, 返回失败
  if (this->vertex_count_ == this->max_vertex_count_) {
    return false;
  }

  this->adjacency_list_[this->vertex_count_].starting_vertex = vertex; // vertex_table_增加结点数据
  this->vertex_count_++; // 结点数增加

  this->vertices_.push_back(vertex);

  return true;
}


/*!
 * @brief 删除结点
 * @param vertex 节点
 * @return 是否删除成功
 */
template<class Vertex, class Weight>
bool AdjacencyListGraph<Vertex, Weight>::RemoveVertex(const Vertex& vertex) {

    int vertex_index = this->GetVertexIndex(vertex);

    if (this->vertex_count_ == 1 || vertex_index < 0 || vertex_index >= this->vertex_count_) {
        return false;
    }

    while (this->adjacency_list_[vertex_index].adjacency != NULL) {

        Adjacency<Vertex, Weight>* prior = NULL;
        Adjacency<Vertex, Weight>* cur_adjacency_edge = this->adjacency_list_[vertex_index].adjacency;

        Adjacency<Vertex, Weight>* delete_edge = NULL;
        Adjacency<Vertex, Weight>* cur = this->adjacency_list_[cur_adjacency_edge->ending_vertex_index].adjacency;

        while (cur != NULL && cur->ending_vertex_index != vertex_index) {
            prior = cur;
            cur = cur->next;
        }
        delete_edge = cur;

        if (delete_edge != NULL) {
            if (prior == NULL) {
                this->adjacency_list_[cur_adjacency_edge->ending_vertex_index].adjacency = delete_edge->next;
            } else {
                prior->next = delete_edge->next;
            }

            delete delete_edge;
            delete_edge = NULL;
        }

        this->adjacency_list_[vertex_index].adjacency = cur_adjacency_edge->next;

        delete cur_adjacency_edge;

        this->edge_count_--;
    }

    this->vertex_count_--;

    this->adjacency_list_[vertex_index].starting_vertex = this->adjacency_list_[this->vertex_count_].starting_vertex;
    this->adjacency_list_[vertex_index].adjacency = this->adjacency_list_[this->vertex_count_].adjacency;

    Adjacency<Vertex, Weight>* cur_adjacency_edge = this->adjacency_list_[this->vertex_count_].adjacency;
    while (cur_adjacency_edge) {

        Adjacency<Vertex, Weight>* modify_adjacency_edge = this->adjacency_list_[cur_adjacency_edge->ending_vertex_index].adjacency;

        while (modify_adjacency_edge != NULL) {
            if (modify_adjacency_edge->ending_vertex_index == this->vertex_count_) {
                modify_adjacency_edge->ending_vertex_index = vertex_index;
                break;
            } else {
                modify_adjacency_edge = modify_adjacency_edge->next;
            }
        }

        cur_adjacency_edge = cur_adjacency_edge->next;
    }

    this->adjacency_list_[this->vertex_count_].adjacency = NULL;

    // vertices_删除结点
    for (int i = 0; i < this->VertexCount(); i++) {
        if (this->vertices_[i] == vertex) {
            this->vertices_.erase(this->vertices_.begin() + i);
            break;
        }
    }

    // edges_删除边
    for (int i = 0; i < this->EdgeCount(); i++) {
        if (this->GetEdge(i).ending_vertex == vertex || this->GetEdge(i).starting_vertex == vertex) {
            this->edges_.erase(this->edges_.begin() + i);
        }
    }

    return true;
}


/*!
 * @brief 插入边
 * @param starting_vertex 边节点1
 * @param ending_vertex 边节点2
 * @param weight 边权值
 * @return 是否插入成功
 */
template<typename TVertex, typename TWeight>
bool AdjacencyListGraph<TVertex, TWeight>::InsertEdge(const TVertex& starting_vertex,
                                                      const TVertex& ending_vertex,
                                                      const TWeight& weight)
{

    int starting_vertex_index = this->GetVertexIndex(starting_vertex);
    int ending_vertex_index = this->GetVertexIndex(ending_vertex);

    // todo: 这里应有多个边界判断处理
    if (starting_vertex_index < 0) {
        this->InsertVertex(starting_vertex);
        starting_vertex_index = this->GetVertexIndex(starting_vertex);
    }

    if (ending_vertex_index < 0) {
        this->InsertVertex(ending_vertex);
        ending_vertex_index = this->GetVertexIndex(ending_vertex);
    }

    if (starting_vertex_index >= this->vertex_count_ || ending_vertex_index >= this->vertex_count_) {
        return false;
    }

    // 在邻接表中找 starting_vertex_index --> ending_vertex_index 是否存在, 如果存在说明边已经存在, 不能插入
    Adjacency<TVertex, TWeight>* cur = this->adjacency_list_[starting_vertex_index].adjacency;
    while (cur != NULL && cur->ending_vertex_index != ending_vertex_index) {
        cur = cur->next;
    }

    if (cur != NULL) {
        return true;
    }

    // starting_vertex --> ending_vertex
    Adjacency<TVertex, TWeight>* ending_adjacency =
        new Adjacency<TVertex, TWeight>(ending_vertex,
                                        ending_vertex_index,
                                        weight,
                                        this->adjacency_list_[starting_vertex_index].adjacency);
    if (!ending_adjacency) {
        return false;
    }

    // ending_vertex --> starting_vertex
    Adjacency<TVertex, TWeight>* starting_adjacency =
        new Adjacency<TVertex, TWeight>(starting_vertex,
                                        starting_vertex_index,
                                        weight,
                                        this->adjacency_list_[ending_vertex_index].adjacency);
    if (!starting_adjacency) {
        return false;
    }

    // 更新邻接表内对应的数据
    this->adjacency_list_[starting_vertex_index].adjacency = ending_adjacency;
    this->adjacency_list_[ending_vertex_index].adjacency = starting_adjacency;

    this->edge_count_++; // 边的数量+1

    Edge<TVertex, TWeight> edge(starting_vertex, ending_vertex, weight);
    this->edges_.push_back(edge);

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

  Adjacency<V, W>* cur_delete_adjacency_edge; // 待删除结点
  Adjacency<V, W>* prior_edge; // 待删除结点的前一节点
  Adjacency<V, W>* first_edge; // 第一个邻接结点就是待删除结点

  // vertex1 --> vertex2做删除
  cur_delete_adjacency_edge = this->adjacency_list_[vertex1_index].adjacency;
  prior_edge = NULL;
  first_edge = this->adjacency_list_[vertex1_index].adjacency;

  // 定位delete_edge_ptr和prior_edge_ptr
  while (cur_delete_adjacency_edge != NULL && cur_delete_adjacency_edge->ending_vertex_index != vertex2_index) {
    prior_edge = cur_delete_adjacency_edge;
      cur_delete_adjacency_edge = cur_delete_adjacency_edge->next;
  }

  if (cur_delete_adjacency_edge != NULL) {
    if (first_edge == cur_delete_adjacency_edge) { // 如果第一个邻接结点就是待删除结点
      this->adjacency_list_[vertex1_index].adjacency = cur_delete_adjacency_edge->next;
    } else { // 第一个结点不是待删除结点
      prior_edge->next = cur_delete_adjacency_edge->next;

      delete cur_delete_adjacency_edge;
    }
  } else {
    return false; // 如果没有待删除结点, 则返回false
  }

  // vertex2 --> vertex1做删除
  cur_delete_adjacency_edge = this->adjacency_list_[vertex2_index].adjacency;
  prior_edge = NULL;
  first_edge = this->adjacency_list_[vertex2_index].adjacency;

  while (cur_delete_adjacency_edge != NULL && cur_delete_adjacency_edge->ending_vertex_index != vertex1_index) {
    prior_edge = cur_delete_adjacency_edge;
      cur_delete_adjacency_edge = cur_delete_adjacency_edge->next;
  }

  if (cur_delete_adjacency_edge != NULL) {
    if (first_edge == cur_delete_adjacency_edge) {
      this->adjacency_list_[vertex2_index].adjacency = cur_delete_adjacency_edge->next;
    } else {
      prior_edge->next = cur_delete_adjacency_edge->next;

      delete cur_delete_adjacency_edge;
    }
  } else {
    return false;
  }

  // 边的总数减1
  this->edge_count_--;

    for (int i = 0; i < this->EdgeCount(); i++) {
        if ((this->GetEdge(i).ending_vertex == vertex1 && this->GetEdge(i).starting_vertex == vertex2) ||
            (this->GetEdge(i).ending_vertex == vertex2 && this->GetEdge(i).starting_vertex == vertex1))     // todo: 补充区分有向无向
        {
            this->edges_.erase(this->edges_.begin() + i);
        }
    }

    return true;
}


/*!
 * @brief 获取第一个相邻结点
 * @param first_neighbor 第一个相邻结点(用于保存节点)
 * @param vertex 节点
 * @return 是否获取成功
 */
template<typename TVertex, typename TWeight>
// bool AdjacencyListGraph<TVertex, TWeight>::GetFirstNeighborVertex(TVertex& first_neighbor, const TVertex& vertex) {
bool AdjacencyListGraph<TVertex, TWeight>::GetFirstNeighborVertex(const TVertex& vertex, TVertex& first_neighbor) {

  int vertex_index = this->GetVertexIndex(vertex); // 获取结点在vertex_table_的数组索引

  if (vertex_index >= 0) {
    Adjacency<TVertex, TWeight>* edge = this->adjacency_list_[vertex_index].adjacency;
    if (edge != NULL) {

      int neighbor_index = edge->ending_vertex_index; // 第一个邻接结点的dest_index_

      // bool has_vertex = this->GetVertexByIndex(first_neighbor, neighbor_index); // 取dest_index对应的结点
        bool has_vertex = this->GetVertexByIndex(neighbor_index, first_neighbor); // 取dest_index对应的结点

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
template<class TVertex, class TWeight>
bool AdjacencyListGraph<TVertex, TWeight>::GetNextNeighborVertex(const TVertex& vertex, const TVertex& neighbor_vertex, TVertex& next_neighbor) {

  // 拿到vertex和neighbor_vertex对应的vertex_table_的数组索引
  int vertex_index = GetVertexIndex(vertex);
  int neighbor_index = GetVertexIndex(neighbor_vertex);

  if (vertex_index >= 0) {

    // 邻接表中, 找到neighbor_vertex的位置
    Adjacency<TVertex, TWeight>* edge_ptr = this->adjacency_list_[vertex_index].adjacency;

    while (edge_ptr->next != NULL && edge_ptr->ending_vertex_index != neighbor_index) {
      edge_ptr = edge_ptr->next;
    }

    // 将下一个位置的结点赋给next_neighbor
    if (edge_ptr != NULL && edge_ptr->next != NULL) {
      int next_neighbor_index = edge_ptr->next->ending_vertex_index;

      // bool has_next_neighbor = this->GetVertexByIndex(next_neighbor, next_neighbor_index);
        bool has_next_neighbor = this->GetVertexByIndex(next_neighbor_index, next_neighbor);

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
 * @param adjacency_list_graph 邻接表图
 * @return 输入流(引用)
 */
template<class V, class W>
istream& operator>>(istream& in, AdjacencyListGraph<V, W>& adjacency_list_graph) {

  int vertex_num;
  int edge_num;

  cout<<"Input the vertex_num and edge_num"<<endl;
  in >> vertex_num >> edge_num;

  for (int i = 0; i < vertex_num; i++) {

    V vertex;

    cout<<"Input starting_vertex "<<i<<":"<<endl;
    in >> vertex;

    bool insert_done = adjacency_list_graph.InsertVertex(vertex);
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

    cout<<"Adjacency "<<i<<":"<<endl;
    in >> src_vertex >> dest_vertex >> weight;

    int src_vertex_index = adjacency_list_graph.GetVertexIndex(src_vertex);
    int dest_vertex_index = adjacency_list_graph.GetVertexIndex(dest_vertex);
    if (src_vertex_index < 0 || dest_vertex_index < 0) {
      cout<<"Error input"<<endl;
      continue;
    }

    adjacency_list_graph.InsertEdge(src_vertex, dest_vertex, weight);
  }

  return in;
}


/*!
 * @brief 输出(打印)图
 * @tparam V 结点类型模板参数
 * @tparam W 边权值类型模板参数
 * @param out 输出流(引用)
 * @param adjacency_list_graph 邻接表图
 * @return 输出流(引用)
 */
template<class V, class W>
ostream& operator<<(ostream& out, AdjacencyListGraph<V, W>& adjacency_list_graph) {

  int vertex_num = adjacency_list_graph.VertexCount();
  int edge_num = adjacency_list_graph.EdgeCount();

  cout<<"vertex_num: "<<vertex_num<<", edge_num: "<<edge_num<<endl;

  if (edge_num == 0) {
    cout<<"No edge"<<endl;
    return out;
  }

  for (int src_vertex_index = 0; src_vertex_index < vertex_num; src_vertex_index++) {
    for (int dest_vertex_index = 0; dest_vertex_index < vertex_num; dest_vertex_index++) {

      V src_vertex;
      V dest_vertex;

      // bool get_src_value_done = adjacency_list_graph.GetVertexByIndex(src_vertex, src_vertex_index);
        bool get_src_value_done = adjacency_list_graph.GetVertexByIndex(src_vertex_index, src_vertex);
      // bool get_dest_value_done = adjacency_list_graph.GetVertexByIndex(dest_vertex, dest_vertex_index);
        bool get_dest_value_done = adjacency_list_graph.GetVertexByIndex(dest_vertex_index, dest_vertex);

      if (get_src_value_done && get_dest_value_done) {

        W weight;
        // bool hasWeight = adjacency_list_graph.GetWeight(weight, src_vertex, dest_vertex);
          bool hasWeight = adjacency_list_graph.GetWeight(src_vertex, dest_vertex, weight);

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
template<class TVertex, class TWeight>
int AdjacencyListGraph<TVertex, TWeight>::GetVertexIndex(TVertex vertex) {

    int vertex_index = -1; // 如果图中没有该结点, 则返回-1

    // 在_中查哪个的value_为vertex
    for (int i = 0; i < this->vertex_count_; i++) {
        if (this->adjacency_list_[i].starting_vertex == vertex) {
            vertex_index = i;
            break;
        }
    }

    return vertex_index;
}


#endif // CYBER_DASH_ADJACENCY_LIST_GRAPH_H
