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
istream& operator>>(istream& in, AdjacencyListGraph<TVertex, TWeight>& graph);
// 打印图(重载标准输出)
template<typename TVertex, typename TWeight>
ostream& operator<<(ostream& out, AdjacencyListGraph<TVertex, TWeight>& graph);


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
    bool GetVertexByIndex(int vertex_index, TVertex& vertex) const;

    // 获取边权值()
    bool GetWeight(const TVertex& starting_vertex, const TVertex& ending_vertex, TWeight& weight) const;

    // (由边的两个结点索引)获取边权值
    bool GetWeightByVertexIndex(int starting_vertex_index, int ending_vertex_index, TWeight& weight) const;

    // 插入结点
    bool InsertVertex(const TVertex& vertex);

    // 删除结点
    bool RemoveVertex(const TVertex& vertex);

    // 插入边
    bool InsertEdge(const TVertex& starting_vertex, const TVertex& ending_vertex, const TWeight& weight);

    // 删除边
    bool RemoveEdge(const TVertex& starting_vertex, const TVertex& ending_vertex);

    // 获取第一个相邻结点
    bool GetFirstNeighborVertex(const TVertex& vertex, TVertex& first_neighbor) const;

    // 获取下一个相邻结点
    bool GetNextNeighborVertex(const TVertex& vertex, const TVertex& neighbor_vertex, TVertex& next_neighbor) const;

    // 获取结点索引
    int GetVertexIndex(TVertex vertex) const;

    // 输入图(重载标准输入)
    friend istream& operator>> <>(istream& in, AdjacencyListGraph<TVertex, TWeight>& graph_adjacency_list);
    // 打印图(重载标准输出)
    friend ostream& operator<< <>(ostream& out, AdjacencyListGraph<TVertex, TWeight>& graph_adjacency_list);

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
 * @brief **邻接表图析构函数**
 * @tparam TVertex
 * @tparam TWeight
 */
template<typename TVertex, typename TWeight>
AdjacencyListGraph<TVertex, TWeight>::~AdjacencyListGraph() {
    for (int starting_vertex_index = 0; starting_vertex_index < this->vertex_count_; starting_vertex_index++) {
        Adjacency<TVertex, TWeight>* temp = this->adjacency_list_[starting_vertex_index].adjacency; // temp指向待删除邻接元素

        while (temp != NULL) {
            this->adjacency_list_[starting_vertex_index].adjacency = temp->next;
            delete temp;
            temp = this->adjacency_list_[starting_vertex_index].adjacency;
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
bool AdjacencyListGraph<TVertex, TWeight>::GetVertexByIndex(int vertex_index, TVertex& vertex) const {
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
 * @note
 * 获取边权值(by结点)
 * ----------------
 * ----------------
 *
 * ----------------
 */
template<typename TVertex, typename TWeight>
bool AdjacencyListGraph<TVertex, TWeight>::GetWeight(const TVertex& starting_vertex,
                                                     const TVertex& ending_vertex,
                                                     TWeight& weight) const
{
    int starting_vertex_index = this->GetVertexIndex(starting_vertex);
    if (starting_vertex_index < 0) {
        return false;
    }

    Adjacency<TVertex, TWeight>* cur = this->adjacency_list_[starting_vertex_index].adjacency;

    while (cur && cur->ending_vertex != ending_vertex) {
        cur = cur->next;
    }

    if (!cur) {
        return false;
    }

    weight = cur->weight;

    return true;
}


/*!
 * @brief **获取边权值(by结点索引)**
 * @tparam TVertex
 * @tparam TWeight
 */
template<typename TVertex, typename TWeight>
bool AdjacencyListGraph<TVertex, TWeight>::GetWeightByVertexIndex(int starting_vertex_index,
                                                                  int ending_vertex_index,
                                                                  TWeight& weight) const
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
 * @note
 * 插入结点
 * -------
 * -------
 *
 * -------
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
 * @brief **删除结点**
 * @param vertex 结点
 * @return 执行结果
 * @note
 * 删除结点
 * -------
 * -------
 *
 * todo: 丑陋:-(, 进行封装
 *
 * -------
 */
template<typename TVertex, typename TWeight>
bool AdjacencyListGraph<TVertex, TWeight>::RemoveVertex(const TVertex& vertex) {

    int vertex_index = this->GetVertexIndex(vertex);

    if (vertex_index < 0 || vertex_index >= this->vertex_count_) {
        return false;
    }

    // vertex的邻接结点, 在adjacency_list_各自所在的链表, 执行删除
    Adjacency<TVertex, TWeight>* cur_adjacency = this->adjacency_list_[vertex_index].adjacency;
    while (cur_adjacency) {

        // vertex的当前邻接结点, 在邻接表中的自身链表中的邻接结点元素指针
        Adjacency<TVertex, TWeight>* cur_adjacency_ending_vertex_adjacency =
            this->adjacency_list_[cur_adjacency->ending_vertex_index].adjacency;

        Adjacency<TVertex, TWeight>* prior = NULL;    // 待删除结点的前驱, 初始化为NULL
        // 找到前驱结点和待删除结点
        while (cur_adjacency_ending_vertex_adjacency != NULL &&
               cur_adjacency_ending_vertex_adjacency->ending_vertex_index != vertex_index)
        {
            prior = cur_adjacency_ending_vertex_adjacency;
            cur_adjacency_ending_vertex_adjacency = cur_adjacency_ending_vertex_adjacency->next;
        }

        Adjacency<TVertex, TWeight>* temp = cur_adjacency_ending_vertex_adjacency;
        if (temp != NULL) {
            if (prior == NULL) {
                this->adjacency_list_[cur_adjacency->ending_vertex_index].adjacency = temp->next;
            } else {
                prior->next = temp->next;
            }

            delete temp;
            temp = NULL;
        }

        cur_adjacency = cur_adjacency->next;

        this->edge_count_--;
    }

    Adjacency<TVertex, TWeight>* temp = this->adjacency_list_[vertex_index].adjacency;
    while (temp) {
        this->adjacency_list_[vertex_index].adjacency = temp->next;
        delete temp;
        temp = this->adjacency_list_[vertex_index].adjacency;
    }

    this->adjacency_list_[vertex_index].adjacency = NULL;
    this->adjacency_list_[vertex_index].starting_vertex = TVertex();

    this->vertex_count_--;

    // 将当前最后一个结点索引(this->vertex_count_)的链表, 挪至vertex_index对应的位置
    this->adjacency_list_[vertex_index].starting_vertex = this->adjacency_list_[this->vertex_count_].starting_vertex;
    this->adjacency_list_[vertex_index].adjacency = this->adjacency_list_[this->vertex_count_].adjacency;

    // 将该链表的每个结点在其他链表中对应的adjacency进行ending_vertex_index调整
    Adjacency<TVertex, TWeight>* cur_adjacency_ending_vertex_adjacency =
        this->adjacency_list_[this->vertex_count_].adjacency;
    while (cur_adjacency_ending_vertex_adjacency) {

        Adjacency<TVertex, TWeight>* cur =
            this->adjacency_list_[cur_adjacency_ending_vertex_adjacency->ending_vertex_index].adjacency;

        while (cur != NULL) {
            if (cur->ending_vertex_index == this->vertex_count_) {
                cur->ending_vertex_index = vertex_index;
                break;
            } else {
                cur = cur->next;
            }
        }

        cur_adjacency_ending_vertex_adjacency = cur_adjacency_ending_vertex_adjacency->next;
    }

    this->adjacency_list_[this->vertex_count_].adjacency = NULL;
    this->adjacency_list_[this->vertex_count_].starting_vertex = TVertex();

    // vertices_删除结点
    this->vertices_.erase(this->vertices_.begin() + vertex_index);

    // edges_删除边
    for (vector<Edge<TVertex, TWeight> >::iterator iter = this->edges_.begin(); iter != this->edges_.end(); iter++) {
        if (iter->ending_vertex == vertex || iter->starting_vertex == vertex) {
            iter = this->edges_.erase(iter);
        }
        this->edge_count_--;
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

    // ----- ending_vertex --> starting_vertex ----- todo: 无向图逻辑
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
    this->adjacency_list_[ending_vertex_index].adjacency = starting_adjacency;  // todo: 无向图逻辑

    this->edge_count_++; // 边的数量+1

    Edge<TVertex, TWeight> edge(starting_vertex, ending_vertex, weight);
    this->edges_.push_back(edge);

    return true;
}


/*!
 * @brief **删除边**
 * @param starting_vertex 起点
 * @param ending_vertex 终点
 * @return 执行结果
 * 删除边
 * -----
 * -----
 *
 * -----
 */
template<class TVertex, class TWeight>
bool AdjacencyListGraph<TVertex, TWeight>::RemoveEdge(const TVertex& starting_vertex, const TVertex& ending_vertex) {

    // 起点/结点, 如果有一个不存在, 则返回false
    int starting_vertex_index = this->GetVertexIndex(starting_vertex);
    int ending_vertex_index = this->GetVertexIndex(ending_vertex);

    if (starting_vertex_index < 0 && ending_vertex_index < 0) {
        return false;
    }

    /// ------ starting_vertex --> ending_vertex 做删除 ------
    // 待删除邻接元素, 初始化指向starting_vertex的第一个邻接元素
    Adjacency<TVertex, TWeight>* temp = this->adjacency_list_[starting_vertex_index].adjacency;
    // 待删除邻接元素的前一元素
    Adjacency<TVertex, TWeight>* prior = NULL;

    // 定位temp和prior
    while (temp != NULL && temp->ending_vertex_index != ending_vertex_index) {
        prior = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return false; // 如果没有找到待删除边, 返回false
    }

    if (this->adjacency_list_[starting_vertex_index].adjacency == temp) { // 如果第一个邻接结点所对应的边就是待删除边
        this->adjacency_list_[starting_vertex_index].adjacency = temp->next;
    } else { // 第一个邻接结点对应的边不是待删除边
        prior->next = temp->next;

        delete temp;
        temp = NULL;
    }

    // -----  ending_vertex --> starting_vertex 做删除 ----- todo: 无向图逻辑
    temp = this->adjacency_list_[ending_vertex_index].adjacency;
    prior = NULL;

    while (temp != NULL && temp->ending_vertex_index != starting_vertex_index) {
        prior = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return false;
    }

    if (this->adjacency_list_[ending_vertex_index].adjacency == temp) {
        this->adjacency_list_[ending_vertex_index].adjacency = temp->next;
    } else {
        prior->next = temp->next;

        delete temp;
        temp = NULL;
    }

    // 边的总数减1
    this->edge_count_--;

    for (int i = 0; i < this->EdgeCount(); i++) {
        if (this->GetEdge(i).ending_vertex == ending_vertex && this->GetEdge(i).starting_vertex == starting_vertex) {
            this->edges_.erase(this->edges_.begin() + i);
        }

        // todo: 此为无向图逻辑
        if (this->GetEdge(i).ending_vertex == starting_vertex && this->GetEdge(i).starting_vertex == ending_vertex) {
            this->edges_.erase(this->edges_.begin() + i);
        }
    }

    return true;
}


/*!
 * @brief **获取第一个相邻结点**
 * @param first_neighbor 第一个相邻结点保存变量
 * @param vertex 当前结点
 * @return 执行结果
 * 获取第一个相邻结点
 * ---------------
 * ---------------
 *
 * ---------------
 */
template<typename TVertex, typename TWeight>
bool AdjacencyListGraph<TVertex, TWeight>::GetFirstNeighborVertex(const TVertex& vertex,
                                                                  TVertex& first_neighbor) const
{

    int vertex_index = this->GetVertexIndex(vertex); // 获取结点在adjacency_list_的数组索引

    if (vertex_index >= 0) {
        Adjacency<TVertex, TWeight>* adjacency = this->adjacency_list_[vertex_index].adjacency;
        if (adjacency != NULL) {
            int neighbor_index = adjacency->ending_vertex_index; // 第一个邻接结点的索引

            bool new_neighbor_exists = this->GetVertexByIndex(neighbor_index, first_neighbor);

            return new_neighbor_exists;
        }
    }

    return false;
}


/*!
 * @brief **获取下一个相邻结点**
 * @param next_neighbor 下一个相邻结点保存变量
 * @param vertex 当前结点
 * @param neighbor_vertex 当前相邻结点
 * @return 执行结果
 * 获取下一个相邻结点
 * ---------------
 * ---------------
 *
 * ---------------
 */
template<class TVertex, class TWeight>
bool AdjacencyListGraph<TVertex, TWeight>::GetNextNeighborVertex(const TVertex& vertex,
                                                                 const TVertex& neighbor_vertex,
                                                                 TVertex& next_neighbor) const
{
    // 拿到vertex和neighbor_vertex对应的adjacency_list_数组索引
    int vertex_index = GetVertexIndex(vertex);
    int neighbor_index = GetVertexIndex(neighbor_vertex);

    if (vertex_index >= 0) {

        // 邻接表中, 找到neighbor_vertex的位置
        Adjacency<TVertex, TWeight>* cur = this->adjacency_list_[vertex_index].adjacency;

        while (cur->next != NULL && cur->ending_vertex_index != neighbor_index) {
            cur = cur->next;
        }

        // 将下一个位置的结点赋给next_neighbor
        if (cur != NULL && cur->next != NULL) {
            int next_neighbor_index = cur->next->ending_vertex_index;

            bool new_neighbor_exists = this->GetVertexByIndex(next_neighbor_index, next_neighbor);

            return new_neighbor_exists;
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
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param out 输出流(引用)
 * @param graph 邻接表图
 * @return 输出流(引用)
 */
template<class TVertex, class TWeight>
ostream& operator<<(ostream& out, AdjacencyListGraph<TVertex, TWeight>& graph) {

    out<<"结点数量: "<<graph.VertexCount()<<", 边数量: "<<graph.EdgeCount()<<endl<<endl;

    for (int i = 0; i < graph.VertexCount(); i++) {
        TVertex vertex;
        graph.GetVertexByIndex(i, vertex);
        out << vertex << " ";
    }
    cout << endl << endl;

    for (int i = 0; i < graph.EdgeCount(); i++) {
        Edge<TVertex, TWeight> cur_edge = graph.GetEdge(i);
        out << "(" << cur_edge.starting_vertex <<
               ", " << cur_edge.ending_vertex <<
               "), 权重: " << cur_edge.weight << endl;
    }
    cout << endl;

    out << "邻接表:" << endl;
    for (int i = 0; i < graph.VertexCount(); i++) {

        TVertex vertex;
        graph.GetVertexByIndex(i, vertex);

        out << vertex << "的邻接结点: ";

        Adjacency<TVertex, TWeight>* cur_adjacency = graph.adjacency_list_[i].adjacency;
        while (cur_adjacency) {
            out << cur_adjacency->ending_vertex;
            if (cur_adjacency->next) {
                out << ",";
            }
            cur_adjacency = cur_adjacency->next;
        }

        out << endl;
    }

    return out;
}


/*!
 * @brief 获取结点索引
 * @param vertex 结点
 * @return 结点索引
 */
template<class TVertex, class TWeight>
int AdjacencyListGraph<TVertex, TWeight>::GetVertexIndex(TVertex vertex) const {

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
