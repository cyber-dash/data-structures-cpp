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
 * @brief **邻接元素结构体模板**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @note
 * 邻接元素结构体模板
 * ---------------
 * ---------------
 *
 * 邻接元素包含: 邻结点, 邻接边和下一邻接元素
 *
 * ---------------
 */
template <typename TVertex, typename TWeight>
struct Adjacency {

  /*!
   * @brief 默认构造函数
   * @note
   * 默认构造函数
   * ----------
   * ----------
   *
   * ----------
   * 终点索引设置为-1\n
   * 终点初始化为TVertex()\n
   * 下一邻接元素地址设为NULL\n
   */
  Adjacency(): ending_vertex_index(-1), ending_vertex(TVertex()), weight(TWeight()), next(NULL) {};

  /*!
   * @brief 构造函数(邻接边终点/邻接边终点索引/边权重/下一邻接边)
   * @note
   * 构造函数(邻接边终点/邻接边终点索引/边权重/下一邻接边)
   * ----------------------------------------------
   * ----------------------------------------------
   *
   * ----------------------------------------------
   */
  Adjacency(const TVertex& ending_vertex,
            int ending_vertex_index,
            const TWeight& weight,
            Adjacency<TVertex, TWeight>* next = NULL):
    ending_vertex(ending_vertex), ending_vertex_index(ending_vertex_index), weight(weight), next(next) {}

  /*!
   * @brief 重载!=
   * @return 执行结果
   * @note
   * 重载!=
   * -----
   * -----
   *
   * -----
   */
  bool operator != (const Adjacency<TVertex, TWeight>& adjacency) const {
    return (this->ending_vertex_index != adjacency.ending_vertex_index);
  }

  /*!
   * @brief 重载!=
   * @param adjacency 邻接边
   * @return 执行结果
   * @note
   * 重载!=
   * -----
   * -----
   *
   * -----
   */
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
 * @brief **邻接表表元素模板类**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 */
template<typename TVertex, typename TWeight>
class VertexAdjacencies {
public:
    /*!
     * @brief 默认构造函数
     * @note
     * 默认构造函数
     * ----------
     * ----------
     *
     * ----------
     */
    VertexAdjacencies(): starting_vertex(TVertex()), first_adjacency(NULL) {}


    /*!
     * @brief 查找邻接结点和它的前驱结点
     * @param vertex 结点
     * @param adjacency
     * @param prior
     * @return
     */
    bool FindAdjacencyAndPrior(const TVertex& vertex,
                               Adjacency<TVertex, TWeight>*& adjacency,
                               Adjacency<TVertex, TWeight>*& prior)
    {
        prior = NULL;    // 待删除结点的前驱, 初始化为NULL
        Adjacency<TVertex, TWeight>* cur = this->first_adjacency;
        // 找到前驱结点和待删除结点
        while (cur != NULL && cur->ending_vertex != vertex) {
            prior = cur;
            cur = cur->next;
        }

        if (cur) {
            adjacency = cur;
            return true;
        }

        return false;
    }

    bool FindAdjacency(const TVertex& vertex, Adjacency<TVertex, TWeight>*& adjacency) {
        Adjacency<TVertex, TWeight> *cur = this->first_adjacency;
        // 找到前驱结点和待删除结点
        while (cur != NULL && cur->ending_vertex != vertex) {
            cur = cur->next;
        }

        if (cur) {
            adjacency = cur;
            return true;
        }

        return false;
    }

    void Clear() {
        Adjacency<TVertex, TWeight>* temp = this->first_adjacency;
        while (temp) {
            this->first_adjacency = temp->next;
            delete temp;
            temp = this->first_adjacency;
        }

        first_adjacency = NULL;
        starting_vertex = TVertex();
    }

    TVertex starting_vertex;                   //!< 起始结点
    Adjacency<TVertex, TWeight>* first_adjacency;    //!< 邻接边数组首地址
};


template<typename TVertex, typename TWeight> class AdjacencyListGraph;
// 输入图(重载标准输入)
template<typename TVertex, typename TWeight>
istream& operator>>(istream& in, AdjacencyListGraph<TVertex, TWeight>& graph);
// 打印图(重载标准输出)
template<typename TVertex, typename TWeight>
ostream& operator<<(ostream& out, AdjacencyListGraph<TVertex, TWeight>& graph);


/*!
 * @brief **邻接表图模板类**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 */
template<typename TVertex, typename TWeight>
class AdjacencyListGraph: public Graph<TVertex, TWeight> {
public:

    // 构造函数
    AdjacencyListGraph(unsigned int max_vertex_count, TWeight max_weight);

    AdjacencyListGraph(int type, unsigned int max_vertex_count, TWeight max_weight);

    AdjacencyListGraph(unsigned int max_vertex_count,
                       TWeight max_weight,
                       const vector<Edge<TVertex, TWeight> >& edges,
                       const vector<TVertex>& vertices);

    AdjacencyListGraph(int type,
                       unsigned int max_vertex_count,
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
    int GetVertexIndex(const TVertex& vertex) const;

    // 输入图(重载标准输入)
    friend istream& operator>> <>(istream& in, AdjacencyListGraph<TVertex, TWeight>& graph_adjacency_list);
    // 打印图(重载标准输出)
    friend ostream& operator<< <>(ostream& out, AdjacencyListGraph<TVertex, TWeight>& graph_adjacency_list);

private:
    VertexAdjacencies<TVertex, TWeight>* adjacency_list_; //!< 邻接表
};


/*!
 * @brief 构造函数(结点数上限/边权值上限)
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param max_vertex_count 结点数上限
 * @param max_weight 边权值上限
 * @note
 * 构造函数(结点数上限/边权值上限)
 * --------------------------
 * --------------------------
 *
 * --------------------------
 * + **1** 设置部分成员变量\n
 *  - type_(**图类型**)设为UNDIRECTED(**无向**)\n
 *  - max_vertex_count_(**结点数上限**)和max_weight_(**边权值上限**)使用参数赋值\n
 *  - vertex_count_(**结点数量**)和edge_count_(**边数量**)设为0\n
 * + **2** 设置邻接表\n
 *  - **2.1** 分配邻接矩阵行内存\n
 *  **if** 内存分配失败 :\n
 *  &emsp; 抛出bad_alloc()错误\n
 */
template<typename TVertex, typename TWeight>
AdjacencyListGraph<TVertex, TWeight>::AdjacencyListGraph(unsigned int max_vertex_count, TWeight max_weight) {

    // ----------- 1 设置部分成员变量 -----------

    // type_(图类型)设为UNDIRECTED(无向)
    this->type_ = Graph<TVertex, TWeight>::UNDIRECTED;

    // max_vertex_count_(结点数上限)和max_weight_(边权值上限)使用参数赋值
    this->max_vertex_count_ = max_vertex_count;
    this->max_weight_ = max_weight;

    // vertex_count_(结点数量)和edge_count_(边数量)设为0
    this->vertex_count_ = 0;
    this->edge_count_ = 0;

    this->adjacency_list_ = new VertexAdjacencies<TVertex, TWeight>[this->max_vertex_count_];
    if (!this->adjacency_list_) {
        throw bad_alloc();
    }

    for (int i = 0; i < this->max_vertex_count_; i++) {
        this->adjacency_list_[i].first_adjacency = NULL;
    }
}


template<typename TVertex, typename TWeight>
AdjacencyListGraph<TVertex, TWeight>::AdjacencyListGraph(int type, unsigned int max_vertex_count, TWeight max_weight) {
    this->type_ = type;
    this->max_vertex_count_ = max_vertex_count;
    this->max_weight_ = max_weight;
    this->vertex_count_ = 0;
    this->edge_count_ = 0;

    this->adjacency_list_ = new VertexAdjacencies<TVertex, TWeight>[this->max_vertex_count_];

    for (int i = 0; i < this->max_vertex_count_; i++) {
        this->adjacency_list_[i].first_adjacency = NULL;
    }
}


template<typename TVertex, typename TWeight>
AdjacencyListGraph<TVertex, TWeight>::AdjacencyListGraph(unsigned int max_vertex_count,
                                                         TWeight max_weight,
                                                         const vector<Edge<TVertex, TWeight> >& edges,
                                                         const vector<TVertex>& vertices)
{
    if (max_vertex_count < vertices.size()) {
        throw length_error("vertices size wrong");
    }

    this->type_ = Graph<TVertex, TWeight>::UNDIRECTED;
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


template<typename TVertex, typename TWeight>
AdjacencyListGraph<TVertex, TWeight>::AdjacencyListGraph(int type,
                                                         unsigned int max_vertex_count,
                                                         TWeight max_weight,
                                                         const vector<Edge<TVertex, TWeight> >& edges,
                                                         const vector<TVertex>& vertices)
{
    if (max_vertex_count < vertices.size()) {
        throw length_error("vertices size wrong");
    }

    this->type_ = type;
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
        Adjacency<TVertex, TWeight>* temp = this->adjacency_list_[starting_vertex_index].first_adjacency; // temp指向待删除邻接元素

        while (temp != NULL) {
            this->adjacency_list_[starting_vertex_index].first_adjacency = temp->next;
            delete temp;
            temp = this->adjacency_list_[starting_vertex_index].first_adjacency;
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
        // vertex = this->adjacency_list_[vertex_index].StartingVertex();
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

    Adjacency<TVertex, TWeight>* cur = this->adjacency_list_[starting_vertex_index].first_adjacency;

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

    Adjacency<TVertex, TWeight>* cur = this->adjacency_list_[starting_vertex_index].first_adjacency;

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
    if (this->vertex_count_ >= this->max_vertex_count_) {
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
 * -------
 */
template<typename TVertex, typename TWeight>
bool AdjacencyListGraph<TVertex, TWeight>::RemoveVertex(const TVertex& vertex) {

    // ---------- 1 合法性检查 ----------
    int vertex_index = this->GetVertexIndex(vertex);
    if (vertex_index < 0 || vertex_index >= this->vertex_count_) {
        return false;
    }

    // ---------- 2 邻接表调整 ----------
    // vertex的所有邻接结点, 在adjacency_list_各自所在的链表, 执行删除
    Adjacency<TVertex, TWeight>* cur_adjacency = this->adjacency_list_[vertex_index].first_adjacency;
    while (cur_adjacency) {
        Adjacency<TVertex, TWeight>* temp;
        Adjacency<TVertex, TWeight>* prior = NULL;    // 待删除结点的前驱, 初始化为NULL

        VertexAdjacencies<TVertex, TWeight> cur_vertex_adjacencies = this->adjacency_list_[cur_adjacency->ending_vertex_index];
        bool res = cur_vertex_adjacencies.FindAdjacencyAndPrior(vertex, temp, prior);
        if (res) {
            if (prior == NULL) {
                this->adjacency_list_[cur_adjacency->ending_vertex_index].first_adjacency = temp->next;
            } else {
                prior->next = temp->next;
            }

            delete temp;
            temp = NULL;
        }

        cur_adjacency = cur_adjacency->next;

        this->edge_count_--;
    }

    this->adjacency_list_[vertex_index].Clear();

    this->vertex_count_--;

    // 将当前最后一个结点索引(this->vertex_count_)的链表, 挪至vertex_index对应的位置
    this->adjacency_list_[vertex_index].starting_vertex = this->adjacency_list_[this->vertex_count_].starting_vertex;
    this->adjacency_list_[vertex_index].first_adjacency = this->adjacency_list_[this->vertex_count_].first_adjacency;

    TVertex modify_vertex = this->adjacency_list_[vertex_index].starting_vertex;

    // 将该链表的每个结点在其他链表中对应的adjacency进行ending_vertex_index调整
    Adjacency<TVertex, TWeight>* cur_modify_adjacency = this->adjacency_list_[this->vertex_count_].first_adjacency;

    while (cur_modify_adjacency) {

        Adjacency<TVertex, TWeight>* adjacency = NULL;
        VertexAdjacencies<TVertex, TWeight> cur_vertex_adjacencies =
            this->adjacency_list_[cur_modify_adjacency->ending_vertex_index];

        bool res = cur_vertex_adjacencies.FindAdjacency(modify_vertex, adjacency);
        if (res && adjacency != NULL) {
            adjacency->ending_vertex_index = vertex_index;
        }

        cur_modify_adjacency = cur_modify_adjacency->next;
    }

    this->adjacency_list_[this->vertex_count_].first_adjacency = NULL;
    this->adjacency_list_[this->vertex_count_].starting_vertex = TVertex();

    // ---------- 3 处理vertices_和edges_ ----------
    // vertices_删除结点
    this->vertices_.erase(this->vertices_.begin() + vertex_index);

    // edges_删除边
    for (typename vector<Edge<TVertex, TWeight> >::iterator iter = this->edges_.begin(); iter != this->edges_.end();) {
        if (iter->ending_vertex == vertex || iter->starting_vertex == vertex) {
            iter = this->edges_.erase(iter);
        } else {
            iter++;
        }
    }

    return true;
}


/*!
 * @brief **插入边**
 * @param starting_vertex 起点
 * @param ending_vertex 终点
 * @param weight 边权值
 * @return 执行结果
 * @note
 * 插入边
 * -----
 * -----
 *
 * -----
 */
template<typename TVertex, typename TWeight>
bool AdjacencyListGraph<TVertex, TWeight>::InsertEdge(const TVertex& starting_vertex,
                                                      const TVertex& ending_vertex,
                                                      const TWeight& weight)
{
    // ---------- 1 合法性判断和相关操作 ----------

    // 1.1 结点检查
    int starting_vertex_index = this->GetVertexIndex(starting_vertex);
    int ending_vertex_index = this->GetVertexIndex(ending_vertex);

    // 如果starting_vertex不在图中, 将结点starting_vertex插入
    if (starting_vertex_index < 0) {
        bool res = this->InsertVertex(starting_vertex);
        if (!res) {
            return false;
        }

        starting_vertex_index = this->GetVertexIndex(starting_vertex);
    }

    // 如果ending_vertex不在图中, 将结点ending_vertex插入
    if (ending_vertex_index < 0) {
        bool res = this->InsertVertex(ending_vertex);
        if (!res) {
            return false;
        }

        ending_vertex_index = this->GetVertexIndex(ending_vertex);
    }

    // 1.2 边检查
    // 遍历edges_, 检查是否能找到待插入边
    for (unsigned int i = 0; i < this->edges_.size(); i++) {
        if (this->type_ == Graph<TVertex, TWeight>::UNDIRECTED) {   // 无向
            // 无向图/网已存在该边, 不能插入
            if ((this->edges_[i].starting_vertex == starting_vertex && this->edges_[i].ending_vertex == ending_vertex) ||
                (this->edges_[i].starting_vertex == ending_vertex && this->edges_[i].ending_vertex == starting_vertex)) {
                return false;
            }
        } else if (this->type_ == Graph<TVertex, TWeight>::DIRECTED) {    // 有向
            // 有向图/网已存在该边, 不能插入
            if (this->edges_[i].starting_vertex == starting_vertex && this->edges_[i].ending_vertex == ending_vertex) {
                return false;
            }
        }
    }

    // 1.3 邻接表检查
    // 在邻接表中找 starting_vertex_index --> ending_vertex_index 是否存在(保存于cur指针)
    Adjacency<TVertex, TWeight>* cur = this->adjacency_list_[starting_vertex_index].first_adjacency;
    while (cur != NULL && cur->ending_vertex_index != ending_vertex_index) {
        cur = cur->next;
    }

    // 如果存在, 不能插入
    if (cur != NULL) {
        return true;
    }

    // ---------- 2 执行插入 ----------
    // 2.1 starting_vertex --> ending_vertex, 插入edges_和邻接表
    // 生成一个Adjacency结点(指针变量)ending_adjacency, next指向this->adjacency_list_[starting_vertex_index].adjacency指向的地址
    Adjacency<TVertex, TWeight>* ending_adjacency =
        new Adjacency<TVertex, TWeight>(ending_vertex,
                                        ending_vertex_index,
                                        weight,
                                        this->adjacency_list_[starting_vertex_index].first_adjacency);
    if (!ending_adjacency) {
        return false;
    }

    // 更新邻接表内对应的数据
    this->adjacency_list_[starting_vertex_index].first_adjacency = ending_adjacency;

    Edge<TVertex, TWeight> edge(starting_vertex, ending_vertex, weight);
    this->edges_.push_back(edge);

    // 2.2 ----- 无向图/网, 对ending_vertex --> starting_vertex, 插入edges_和邻接表 -----
    if (this->type_ == Graph<TVertex, TWeight>::UNDIRECTED) {
        Adjacency<TVertex, TWeight>* starting_adjacency =
            new Adjacency<TVertex, TWeight>(starting_vertex,
                                            starting_vertex_index,
                                            weight,
                                            this->adjacency_list_[ending_vertex_index].first_adjacency);
        if (!starting_adjacency) {
            return false;
        }

        // 更新邻接表内对应的数据
        this->adjacency_list_[ending_vertex_index].first_adjacency = starting_adjacency;
    }

    // ---------- 3 调edge_count_ ----------
    this->edge_count_++; // 边的数量+1

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
template<typename TVertex, typename TWeight>
bool AdjacencyListGraph<TVertex, TWeight>::RemoveEdge(const TVertex& starting_vertex, const TVertex& ending_vertex) {

    /// ---------- 1 合法性检查 ----------
    // 1.1 检查结点
    // 起点/结点, 如果有一个不存在, 则返回false
    int starting_vertex_index = this->GetVertexIndex(starting_vertex);
    int ending_vertex_index = this->GetVertexIndex(ending_vertex);

    if (starting_vertex_index < 0 && ending_vertex_index < 0) {
        return false;
    }

    // 1.2 检查边
    // 遍历edges_, 检查是否能找到待删除边
    int remove_edge_index = -1;
    if (this->type_ == Graph<TVertex, TWeight>::DIRECTED) {
        for (unsigned int i = 0; i < this->edges_.size(); i++) {
            if (this->edges_[i].starting_vertex == starting_vertex && this->edges_[i].ending_vertex == ending_vertex) {
                remove_edge_index = i;
                break;
            }
        }
    } else if (this->type_ == Graph<TVertex, TWeight>::UNDIRECTED) {
        for (unsigned int i = 0; i < this->edges_.size(); i++) {
            if ((this->edges_[i].starting_vertex == starting_vertex && this->edges_[i].ending_vertex == ending_vertex) ||
                (this->edges_[i].starting_vertex == ending_vertex && this->edges_[i].ending_vertex == starting_vertex))
            {
                remove_edge_index = i;
                break;
            }
        }
    }

    if (remove_edge_index == -1) {    // edges_无此边,
        return false;
    }

    // 1.3 检查邻接表
    // 待删除邻接元素, 初始化指向starting_vertex的第一个邻接元素
    Adjacency<TVertex, TWeight>* temp = this->adjacency_list_[starting_vertex_index].first_adjacency;
    // 待删除邻接元素的前一元素
    Adjacency<TVertex, TWeight>* prior = NULL;
    Adjacency<TVertex, TWeight>* reverse_temp = NULL;
    Adjacency<TVertex, TWeight>* reverse_prior = NULL;

    // 如果邻接表没有待删除边(starting_vertex ---> ending_vertex), 返回false
    // 定位temp和prior
    while (temp != NULL && temp->ending_vertex_index != ending_vertex_index) {
        prior = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return false;
    }

    // 有向图/网, 如果邻接表没有待删除边(ending_vertex ---> starting_vertex), 返回false
    if (this->type_ == Graph<TVertex, TWeight>::UNDIRECTED) {
        reverse_temp = this->adjacency_list_[ending_vertex_index].first_adjacency;
        reverse_prior = NULL;

        while (reverse_temp != NULL && reverse_temp->ending_vertex_index != starting_vertex_index) {
            reverse_prior = reverse_temp;
            reverse_temp = reverse_temp->next;
        }

        if (reverse_temp == NULL) {
            return false;
        }
    }

    /// ------ 2 在edges和邻接表做删除 ------\n
    /// 2.1 starting_vertex --> ending_vertex 做删除
    if (this->adjacency_list_[starting_vertex_index].first_adjacency == temp) { // 如果第一个邻接结点所对应的边就是待删除边
        this->adjacency_list_[starting_vertex_index].first_adjacency = temp->next;
    } else { // 第一个邻接结点对应的边不是待删除边
        prior->next = temp->next;

        delete temp;
        temp = NULL;
    }

    this->edges_.erase(this->edges_.begin() + remove_edge_index);

    // ----- 2.2 如果是无向图, ending_vertex --> starting_vertex做删除 -----
    if (this->type_ == Graph<TVertex, TWeight>::UNDIRECTED) { // 无向图
        if (this->adjacency_list_[ending_vertex_index].first_adjacency == reverse_temp) {
            this->adjacency_list_[ending_vertex_index].first_adjacency = reverse_temp->next;
        } else {
            reverse_prior->next = reverse_temp->next;

            delete reverse_temp;
            reverse_temp = NULL;
        }
    }

    /// ------ 3 edge_count_调整 ------\n
    // 边的总数减1
    this->edge_count_--;

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
        Adjacency<TVertex, TWeight>* adjacency = this->adjacency_list_[vertex_index].first_adjacency;
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
template<typename TVertex, typename TWeight>
bool AdjacencyListGraph<TVertex, TWeight>::GetNextNeighborVertex(const TVertex& vertex,
                                                                 const TVertex& neighbor_vertex,
                                                                 TVertex& next_neighbor) const
{
    // 拿到vertex和neighbor_vertex对应的adjacency_list_数组索引
    int vertex_index = GetVertexIndex(vertex);
    int neighbor_index = GetVertexIndex(neighbor_vertex);

    if (vertex_index >= 0) {

        // 邻接表中, 找到neighbor_vertex的位置
        Adjacency<TVertex, TWeight>* cur = this->adjacency_list_[vertex_index].first_adjacency;

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
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param in 输入流(引用)
 * @param adjacency_list_graph 邻接表图
 * @return 输入流(引用)
 */
template<typename TVertex, typename TWeight>
istream& operator>>(istream& in, AdjacencyListGraph<TVertex, TWeight>& adjacency_list_graph) {
    // todo: 自行实现
    return in;
}


/*!
 * @brief **输出(打印)图**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param out 输出流
 * @param graph 邻接表图
 * @return 输出流
 * @note
 * 输出(打印)图
 */
template<typename TVertex, typename TWeight>
ostream& operator<<(ostream& out, AdjacencyListGraph<TVertex, TWeight>& graph) {

    out << "--- 基本信息 ---" << endl;
    out << "结点数量: " << graph.VertexCount() << endl;

    for (unsigned int i = 0; i < graph.VertexCount(); i++) {
        TVertex vertex;
        graph.GetVertexByIndex(i, vertex);
        out << vertex << " ";
    }
    cout << endl << endl;
    out << "边数量: " << graph.EdgeCount() << endl;

    for (unsigned int i = 0; i < graph.EdgeCount(); i++) {
        Edge<TVertex, TWeight> cur_edge = graph.GetEdge(i);
        out << "(" << cur_edge.starting_vertex <<
               ", " << cur_edge.ending_vertex <<
               "), 权重: " << cur_edge.weight << endl;
    }
    cout << endl;

    out << "--- 邻接表信息 ---" << endl;
    for (unsigned int i = 0; i < graph.VertexCount(); i++) {
        TVertex vertex;
        graph.GetVertexByIndex(i, vertex);

        out << vertex << "的邻接结点: ";

        Adjacency<TVertex, TWeight>* cur_adjacency = graph.adjacency_list_[i].first_adjacency;
        while (cur_adjacency) {
            out << cur_adjacency->ending_vertex;
            if (cur_adjacency->next) {
                out << "-->";
            }
            cur_adjacency = cur_adjacency->next;
        }

        out << endl;
    }

    return out;
}


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
template<typename TVertex, typename TWeight>
int AdjacencyListGraph<TVertex, TWeight>::GetVertexIndex(const TVertex& vertex) const {
    for (int i = 0; i < this->vertex_count_; i++) {
        if (this->adjacency_list_[i].starting_vertex == vertex) {
            return i;
        }
    }

    return -1;
}


#endif // CYBER_DASH_ADJACENCY_LIST_GRAPH_H
