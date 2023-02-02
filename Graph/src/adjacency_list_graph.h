﻿/*!
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
 * @brief **邻接项结构体模板**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @note
 * 邻接项结构体模板
 * --------------
 * --------------
 *
 * <span style="color:#DF5A00">
 * 邻接项包含: 邻结点, 邻接边和下一邻接项\n
 * 其中:\n
 * &emsp; 邻接点, 作为有向/无向边的终点存在, 因此命名为ending_vertex\n
 * &emsp; 邻接点索引, 与邻接点对应, 命名为ending_vertex_index\n
 * </span>
 *
 * --------------
 */
template <typename TVertex, typename TWeight>
struct Adjacency {

  /*!
   * @brief **默认构造函数**
   * @note
   * 默认构造函数
   * ----------
   * ----------
   *
   * ----------
   * 邻接点索引设置为-1\n
   * 邻接点初始化为TVertex()\n
   * 下一邻接项地址设为NULL\n
   */
  Adjacency(): ending_vertex_index(-1), ending_vertex(TVertex()), weight(TWeight()), next(NULL) {};

  /*!
   * @brief **构造函数(邻接点/邻接点索引/邻接边权重/下一邻接项)**
   * @note
   * 构造函数(邻接点/邻接点索引/邻接边权重/下一邻接项)
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
   * @brief **重载!=**
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
   * @brief **重载=**
   * @param adjacency 邻接边
   * @return 执行结果
   * @note
   * 重载=
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

  int ending_vertex_index;            //!< 邻接点索引
  TVertex ending_vertex;              //!< 邻结点
  TWeight weight;                     //!< 邻接边权重
  Adjacency<TVertex, TWeight>* next;  //!< 下一邻接项
};


/*!
 * @brief **结点邻接项模板类**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @note
 * 结点邻接项模板类
 * ---------------
 * ---------------
 *
 * <span style="color:#DF5A00">
 * 成员变量包括:\n
 * &emsp; 1个图结点, 作为边起点\n
 * &emsp; 1个邻接项指针(作为第1个邻接项)\n
 * </span>
 *
 * ---------------
 */
template<typename TVertex, typename TWeight>
class VertexAdjacencies {
public:

    /*!
     * @brief **默认构造函数**
     * @note
     * 默认构造函数
     * ----------
     * ----------
     *
     * ----------
     * 起点初始化\n
     * 第1邻接项指针设为NULL\n
     */
    VertexAdjacencies(): starting_vertex(TVertex()), first_adjacency(NULL) {}

    /*!
     * @brief **查找邻接项和它的前驱**
     * @param vertex 结点
     * @param adjacency 邻接项保存变量
     * @param prior 前驱保存变量
     * @return 执行结果
     * @note
     * 查找邻接项和它的前驱
     * -----------------
     * -----------------
     *
     * -----------------
     * + **1 初始化前驱为NULL**\n
     * + **2 查找对应的邻接项**\n
     *  - 初始化遍历指针cur, 指向first_adjacency(第1个邻接项)\n
     *  - 遍历查找\n
     *  &emsp; **while** cur不为NULL and cur对应的邻接点不等于vertex :\n
     *  &emsp;&emsp; prior(前驱)指向cur\n
     *  &emsp;&emsp; cur指向cur->next(cur向后移动)\n
     * + **3 查找结果处理**\n
     * &emsp; **if** cur不为NULL(找到对应的邻接项) :\n
     * &emsp;&emsp; cur的值赋给adjacency\n
     * &emsp;&emsp; 返回true\n
     */
    bool FindAdjacencyAndPrior(const TVertex& vertex,
                               Adjacency<TVertex, TWeight>*& adjacency,
                               Adjacency<TVertex, TWeight>*& prior)
    {
        // ---------- 1 初始化前驱为NULL ----------

        prior = NULL;

        // ---------- 2 查找对应的邻接项 ----------

        // 初始化遍历指针cur, 指向first_adjacency(第1个邻接项)
        Adjacency<TVertex, TWeight>* cur = this->first_adjacency;

        // 遍历查找
        while (cur != NULL && cur->ending_vertex != vertex) {   // while cur不为NULL and cur对应的邻接点不等于vertex
            prior = cur;        // prior(前驱)指向cur
            cur = cur->next;    // cur指向cur->next(cur向后移动)
        }

        // ---------- 3 查找结果处理 ----------

        if (cur) {              // if cur不为NULL(找到对应的邻接项)
            adjacency = cur;    // cur的值赋给adjacency
            return true;        // 返回true
        }

        return false;
    }

    /*!
     * @brief **查找邻接项**
     * @param vertex 结点
     * @param adjacency 邻接项保存变量
     * @return 执行结果
     * @note
     * 查找邻接项
     * ---------
     * ---------
     *
     * ---------
     * + **1 查找对应的邻接项**\n
     *  - 初始化遍历指针cur, 指向first_adjacency(第1个邻接项)\n
     *  - 遍历查找\n
     *  &emsp; **while** cur不为NULL and cur对应的邻接点不等于vertex :\n
     *  &emsp;&emsp; cur指向cur->next(cur向后移动)\n
     * + **2 查找结果处理**\n
     * &emsp; **if** cur不为NULL(找到对应的邻接项) :\n
     * &emsp;&emsp; cur的值赋给adjacency\n
     * &emsp;&emsp; 返回true\n
     */
    bool FindAdjacency(const TVertex& vertex, Adjacency<TVertex, TWeight>*& adjacency) {

        // ---------- 1 查找对应的邻接项 ----------

        // 初始化遍历指针cur, 指向first_adjacency(第1个邻接项)
        Adjacency<TVertex, TWeight> *cur = this->first_adjacency;

        // 遍历查找
        while (cur != NULL && cur->ending_vertex != vertex) {   // while cur不为NULL and cur对应的邻接点不等于vertex
            cur = cur->next;                                    // cur指向cur->next(cur向后移动)
        }

        // ---------- 2 查找结果处理 ----------

        if (cur) {              // if cur不为NULL(找到对应的邻接项)
            adjacency = cur;    // cur的值赋给adjacency
            return true;        // 返回true
        }

        return false;
    }

    /*!
     * @brief **清除**
     * @note
     * 清除
     * ---
     * ---
     *
     * ---
     * + **1 释放所有邻接项**\n
     *  - 初始化指针temp, 指向first_adjacency(第1个邻接项)\n
     *  - 循环执行释放\n
     *  &emsp; **while** temp指针不为NULL :\n
     *  &emsp;&emsp; 第1邻接项指向temp->next\n
     *  &emsp;&emsp; 释放temp\n
     *  &emsp;&emsp; temp指向第1邻接项\n
     * + **2 处理成员变量**\n
     *  - first_adjacency设为NULL\n
     *  - starting_vertex设为TVertex()\n
     */
    void Clear() {

        // ---------- 1 释放所有邻接项 ----------

        // 初始化指针temp, 指向first_adjacency(第1个邻接项)
        Adjacency<TVertex, TWeight>* temp = this->first_adjacency;

        // 循环执行释放
        while (temp) {                             // while temp指针不为NULL
            this->first_adjacency = temp->next;     // 第1邻接项指向temp->next
            delete temp;                           // 释放temp
            temp = this->first_adjacency;           // temp指向第1邻接项
        }

        // ---------- 2 处理成员变量 ----------

        this->first_adjacency = NULL;        // first_adjacency设为NULL
        this->starting_vertex = TVertex();  // starting_vertex设为TVertex()
    }

    TVertex starting_vertex;                        //!< 起始结点
    Adjacency<TVertex, TWeight>* first_adjacency;    //!< 第1个邻接项
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

    // 构造函数(结点数上限/边权值上限)
    AdjacencyListGraph(unsigned int max_vertex_count, TWeight max_weight);

    // 构造函数(图类型/结点数上限/边权值上限)
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
 * @brief **构造函数(结点数上限/边权值上限)**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param max_vertex_count 结点数上限
 * @param max_weight 边权值上限
 * @note
 * 构造函数(结点数上限/边权值上限)
 * --------------------------
 * --------------------------
 *
 * 默认无向图
 *
 * --------------------------
 * + **1 设置部分成员变量**\n
 *  - type_(**图类型**)设为UNDIRECTED(**无向**)\n
 *  - max_vertex_count_(**结点数上限**)和max_weight_(**边权值上限**)使用参数赋值\n
 *  - vertex_count_(**结点数量**)和edge_count_(**边数量**)设为0\n
 * + **2 设置邻接表**\n
 *  分配邻接矩阵行内存**\n
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

    // ---------- 2 设置邻接表 ----------

    // 分配邻接矩阵行内存
    this->adjacency_list_ = new VertexAdjacencies<TVertex, TWeight>[this->max_vertex_count_];
    if (!this->adjacency_list_) {   // if 内存分配失败
        throw bad_alloc();          // 抛出bad_alloc()错误
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
    if (!this->adjacency_list_) {   // if 内存分配失败
        throw bad_alloc();          // 抛出bad_alloc()错误
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
 * @brief **析构函数**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @note
 * 析构函数
 * -------
 * -------
 *
 * -------
 * + **1 释放邻接表各元素**\n
 * **for loop** 遍历邻接表各元素 :\n
 * &emsp; 取当前元素cur_vertex_adjacencies(当前结点邻接项)\n
 * &emsp; 调用Clear(), 释放该结点邻接项\n
 * + **2 释放邻接表**\n
 * 释放adjacency_list_(邻接表)\n
 */
template<typename TVertex, typename TWeight>
AdjacencyListGraph<TVertex, TWeight>::~AdjacencyListGraph() {

    // ---------- 1 释放邻接表各元素 ----------

    for (int i = 0; i < this->vertex_count_; i++) { // for loop 遍历邻接表各元素
        // 取当前元素cur_vertex_adjacencies(当前结点邻接项)
        VertexAdjacencies<TVertex, TWeight> cur_vertex_adjacencies = this->adjacency_list_[i];
        cur_vertex_adjacencies.Clear(); // 调用Clear(), 释放该结点邻接项
    }

    // ----------- 2 释放邻接表 ----------

    delete[] this->adjacency_list_; // 释放adjacency_list_(邻接表)
}


/*!
 * @brief **获取结点(by结点索引)**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param vertex_index 结点索引
 * @param vertex 结点保存变量
 * @return 执行结果
 * @note
 * 获取结点(by结点索引)
 * -----------------
 * -----------------
 *
 * -----------------
 * + **1 合法性判断**\n
 * **if** 结点索引 < 0 or 结点索引 >= 结点数 :\n
 * &emsp; 返回false\n
 * + **2 获取结点**\n
 * 将adjacency_list_[vertex_index].starting_vertex赋给vertex\n
 */
template<typename TVertex, typename TWeight>
bool AdjacencyListGraph<TVertex, TWeight>::GetVertexByIndex(int vertex_index, TVertex& vertex) const {

    // ---------- 1 合法性判断 ----------

    if (vertex_index < 0 || vertex_index >= this->vertex_count_) {  // if 结点索引 < 0 or 结点索引 >= 结点数
        return false;   // 返回false
    }

    // ---------- 2 获取结点 ----------

    // 将adjacency_list_[vertex_index].starting_vertex赋给vertex
    vertex = this->adjacency_list_[vertex_index].starting_vertex;

    return true;
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
 * + **1 合法性检查**\n
 * 获取起点和终点的索引\n
 * **if** 起点索引 < 0 or 终点索引 < 0 :\n
 * &emsp; 返回false\n
 * + **2 在邻接表中查找边**\n
 * 初始化cur指向adjacency_list_[starting_vertex_index].first_adjacency(起点的首个邻接项)\n
 * **while loop** cur不为NULL and cur->ending_vertex不等于ending_vertex\n
 * &emsp; cur指向cur->next\n
 * + **3 结果处理**\n
 * **if** cur为NULL(没有对应的边) :\n
 * &emsp; 返回false\n
 * cur->weight赋给weight\n
 */
template<typename TVertex, typename TWeight>
bool AdjacencyListGraph<TVertex, TWeight>::GetWeight(const TVertex& starting_vertex,
                                                     const TVertex& ending_vertex,
                                                     TWeight& weight) const
{
    // ---------- 1 合法性检查 ----------

    // 获取起点和终点的索引
    int starting_vertex_index = this->GetVertexIndex(starting_vertex);
    int ending_vertex_index = this->GetVertexIndex(ending_vertex);
    if (starting_vertex_index < 0 || ending_vertex_index < 0) { // if 起点索引 < 0 or 终点索引 < 0
        return false;                                           // 返回false
    }

    // ---------- 2 在邻接表中查找边 ----------

    // 初始化cur指向adjacency_list_[starting_vertex_index].first_adjacency(起点的首个邻接项)
    Adjacency<TVertex, TWeight>* cur = this->adjacency_list_[starting_vertex_index].first_adjacency;

    while (cur && cur->ending_vertex != ending_vertex) { // while loop cur不为NULL and cur->ending_vertex不等于ending_vertex
        cur = cur->next;    // cur指向cur->next
    }

    // ---------- 3 结果处理 ----------

    if (!cur) {             // if cur为NULL(没有对应的边)
        return false;       // 返回false
    }

    weight = cur->weight;   // cur->weight赋给weight

    return true;
}


/*!
 * @brief **获取边权值(by结点索引)**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param starting_vertex_index 起点索引
 * @param ending_vertex_index 终点索引
 * @param weight 边权值保存变量
 * @return 执行结果
 * @note
 * 获取边权值(by结点索引)
 * --------------------
 * --------------------
 *
 * --------------------
 * - **1** 判断合法性\n
 * **if** 起点索引 < 0 <b>||</b> 终点索引 < 0 <b>||</b> 起点索引等于终点索引 <b>||</b> 起点索引 >= 结点数
 * <b>||</b> 终点索引 >= 结点数 :\n
 * &emsp; 返回false\n
 * - **2** 获取边权值\n
 * 初始化指针cur, 指向adjacency_list_<b>[</b>starting_vertex_index<b>]</b>.first_adjacency\n
 * **while loop** cur不为NULL <b>&&</b> cur的终点结点索引不等于终点索引 :\n
 * &emsp; cur指向cur->next\n
 * **if** cur不为NULL :\n
 * &emsp; cur->weight赋给weight(获取到对应边权值)\n
 * &emsp; 返回true\n
 */
template<typename TVertex, typename TWeight>
bool AdjacencyListGraph<TVertex, TWeight>::GetWeightByVertexIndex(int starting_vertex_index,
                                                                  int ending_vertex_index,
                                                                  TWeight& weight) const
{
    if (starting_vertex_index < 0 || ending_vertex_index < 0 || starting_vertex_index == ending_vertex_index ||
        starting_vertex_index >= this->vertex_count_ || ending_vertex_index >= this->vertex_count_)
    {
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
 * + **1 合法性检查**\n
 * &emsp; **if** 当前图结点数 >= 结点数上限 :\n
 * &emsp;&emsp; 返回false\n
 * + **2 执行插入**\n
 * &emsp; 邻接表索引vertex_count_元素的start_vertex设置为vertex\n
 * &emsp; vertex_count_加1\n
 * &emsp; vertices插入vertex\n
 */
template<typename TVertex, typename TWeight>
bool AdjacencyListGraph<TVertex, TWeight>::InsertVertex(const TVertex& vertex) {

    // ---------- 1 合法性检查 ----------

    if (this->vertex_count_ >= this->max_vertex_count_) {   // if 当前图结点数 >= 结点数上限
        return false;                                       // 返回false
    }

    // ---------- 2 执行插入 ----------

    this->adjacency_list_[this->vertex_count_].starting_vertex = vertex;    // 邻接表索引vertex_count_元素的start_vertex设置为vertex
    this->vertex_count_++;                                  // vertex_count_加1
    this->vertices_.push_back(vertex);                      // vertices插入vertex

    return true;
}


/*!
 * @brief **删除结点**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param vertex 结点
 * @return 执行结果
 * @note
 * 删除结点
 * -------
 * -------
 *
 * -------
 * + **1 合法性检查**\n
 * 获取结点的索引\n
 * **if** 结点索引 < 0 or 结点索引 >= 结点数 :\n
 * &emsp; 返回false\n
 * + **2 邻接表调整**\n
 *  - **2.1 其他结点邻接项的邻接项链表内, 删除涉及vertex的元素**\n
 *  - **2.2 vertex对应的结点邻接项, 执行删除**\n
 *  - **2.3 索引vertex_count_ - 1对应结点的结点代替已删除的结点**\n
 *   使用索引vertex_count_ - 1的结点邻接项, 替换索引vertex_index的结点邻接项\n
 *   索引vertex_count_ - 1的结点邻接项starting_vertex设为TVertex(), first_adjacency指向NULL\n
 *  - **2.4 调整后的索引vertex_index结点, 在其他结点邻接项的邻接项链表, 进行相应调整**\n
 *   初始化substitute_vertex(替换结点)\n
 *   初始化cur_substitute_adjacency(当前替换邻接项)\n
 *   **while loop** 当前替换项存在 :\n
 *   &emsp; 初始化update_vertex_adjacencies(待更新结点邻接项), 取当前替换项的终点所对应的结点邻接项\n
 *   &emsp; 初始化update_adjacency(待更新邻接项)为NULL\n
 *   &emsp; 在update_vertex_adjacencies中查找substitute_vertex, 将查找的结果赋给update_adjacency\n
 *   &emsp; **if** 执行成功 and 存在查找结果 :\n
 *   &emsp;&emsp; 将update_adjacency的ending_vertex_index更新为vertex_index\n
 *   &emsp;&emsp; cur_substitute_adjacency(当前替换邻接项)指向next(换下一替换邻接项执行流程)\n
 * + **3 edges_执行删除**\n
 * &emsp; **for loop** 遍历edges_ :\n
 * &emsp;&emsp; **if** 当前边起点or当前边终点 为待删除节点 :\n
 * &emsp;&emsp;&emsp; 删除当前边\n
 * + **4 vertices_执行删除**\n
 * &emsp; vertices_的索引vertex_index位置元素, 替换为索引vertex_count_ - 1位置元素\n
 * &emsp; vertices_删除索引vertex_count - 1位置元素\n
 * + **5 vertex_count_(结点数)减1**\n
 * vertices_删除结点
 */
template<typename TVertex, typename TWeight>
bool AdjacencyListGraph<TVertex, TWeight>::RemoveVertex(const TVertex& vertex) {

    // ---------- 1 合法性检查 ----------

    int vertex_index = this->GetVertexIndex(vertex);                // 获取结点的索引
    if (vertex_index < 0 || vertex_index >= this->vertex_count_) {  // if 结点索引 < 0 or 结点索引 >= 结点数
        return false;   // 返回false
    }

    // ---------- 2 邻接表调整 ----------

    // ----- 2.1 其他结点邻接项的邻接项链表内, 删除涉及vertex的元素 -----
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
    }

    // ----- 2.2 vertex对应的结点邻接项, 执行删除 -----
    this->adjacency_list_[vertex_index].Clear();

    // ----- 2.3 索引vertex_count_ - 1对应结点的结点代替已删除的结点 -----
    // 使用索引vertex_count_ - 1的结点邻接项, 替换索引vertex_index的结点邻接项
    this->adjacency_list_[vertex_index].starting_vertex = this->adjacency_list_[this->vertex_count_ - 1].starting_vertex;
    this->adjacency_list_[vertex_index].first_adjacency = this->adjacency_list_[this->vertex_count_ - 1].first_adjacency;

    // 索引vertex_count_ - 1的结点邻接项starting_vertex设为TVertex(), first_adjacency指向NULL
    this->adjacency_list_[this->vertex_count_ - 1].starting_vertex = TVertex();
    this->adjacency_list_[this->vertex_count_ - 1].first_adjacency = NULL;

    // 2.4 调整后的索引vertex_index结点, 在其他结点邻接项的邻接项链表, 进行相应调整
    // 初始化substitute_vertex(替换结点)
    TVertex substitute_vertex = this->adjacency_list_[vertex_index].starting_vertex;
    // 初始化cur_substitute_adjacency(当前替换邻接项)
    Adjacency<TVertex, TWeight>* cur_substitute_adjacency = this->adjacency_list_[vertex_index].first_adjacency;

    // while loop 当前替换项存在
    while (cur_substitute_adjacency) {

        // 初始化update_vertex_adjacencies(待更新结点邻接项), 取当前替换项的终点所对应的结点邻接项
        VertexAdjacencies<TVertex, TWeight> update_vertex_adjacencies =
            this->adjacency_list_[cur_substitute_adjacency->ending_vertex_index];
        // 初始化update_adjacency(待更新邻接项)为NULL
        Adjacency<TVertex, TWeight>* update_adjacency = NULL;

        // 在update_vertex_adjacencies中查找substitute_vertex, 将查找的结果赋给update_adjacency
        bool res = update_vertex_adjacencies.FindAdjacency(substitute_vertex, update_adjacency);
        if (res && update_adjacency != NULL) {                    // if 执行成功 and 存在查找结果
            update_adjacency->ending_vertex_index = vertex_index; // 将update_adjacency的ending_vertex_index更新为vertex_index
        }

        // cur_substitute_adjacency(当前替换邻接项)指向next(换下一替换邻接项执行流程)
        cur_substitute_adjacency = cur_substitute_adjacency->next;
    }

    // ---------- 3 edges_执行删除 ----------
    // for loop 遍历edges_
    for (typename vector<Edge<TVertex, TWeight> >::iterator iter = this->edges_.begin(); iter != this->edges_.end();) {
        if (iter->ending_vertex == vertex || iter->starting_vertex == vertex) { // if 当前边起点or当前边终点 为待删除节点
            iter = this->edges_.erase(iter);                                    // 删除当前边
            this->edge_count_--;
        } else {
            iter++;
        }
    }

    // ---------- 4 vertices_执行删除 ----------
    // vertices_的索引vertex_index位置元素, 替换为索引vertex_count_ - 1位置元素
    this->vertices_[vertex_index] = this->vertices_[this->vertex_count_ - 1];
    // vertices_删除索引vertex_count - 1位置元素
    this->vertices_.erase(this->vertices_.begin() + this->vertex_count_ - 1);

    // ---------- 5 vertex_count_(边数)减1 ----------
    this->vertex_count_--;

    return true;
}


/*!
 * @brief **插入边**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
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
 * + **1 检查插入合法性**\n
 *  - **1.1** 结点检查和相关处理\n
 *  &emsp; 获取起点索引\n
 *  &emsp; 获取终点索引\n
 *  &emsp; **if** 起点索引 < 0 :\n
 *  &emsp;&emsp; 插入起点\n
 *  &emsp;&emsp; **if** 插入失败 :\n
 *  &emsp;&emsp;&emsp; 返回false\n
 *  &emsp;&emsp; 使用新插入的起点获取起点索引\n
 *  &emsp; **if** 终点索引 < 0 :\n
 *  &emsp;&emsp; 插入终点\n
 *  &emsp;&emsp; **if** 插入失败 :\n
 *  &emsp;&emsp;&emsp; 返回false\n
 *  &emsp;&emsp; 使用新插入的终点获取终点索引\n
 *  &emsp; **if** 起点索引 < 0 || 终点索引 < 0 || 起点索引 等于 终点索引 :\n
 *  &emsp;&emsp; 返回false\n
 *  - **1.2 边检查**\n
 *  &emsp; **for loop** 遍历edges_ :\n
 *  &emsp;&emsp; **if** 无向图 :\n
 *  &emsp;&emsp;&emsp; **if** 边(起点--->终点) or 反向边(终点--->起点) 存在 :\n
 *  &emsp;&emsp;&emsp;&emsp; 返回false\n
 *  &emsp;&emsp; **if** 有向图 :\n
 *  &emsp;&emsp;&emsp; **if** 边(起点--->终点) 存在 :\n
 *  &emsp;&emsp;&emsp;&emsp; 返回false\n
 *  - **1.3 邻接表检查**\n
 *  &emsp; 初始化cur_adjacency(当前邻接项)指向起点对应的结点邻接项的第1个邻接项\n
 *  &emsp; **while loop** 当前邻接项存在 and 当前邻接项的终点索引不等于终点索引 :\n
 *  &emsp;&emsp; 当前邻接项指向next\n
 *  &emsp; **if** 当前邻接项存在非NULL值 :\n
 *  &emsp;&emsp; 返回false\n
 */
template<typename TVertex, typename TWeight>
bool AdjacencyListGraph<TVertex, TWeight>::InsertEdge(const TVertex& starting_vertex,
                                                      const TVertex& ending_vertex,
                                                      const TWeight& weight)
{

    // ---------- 1 检查插入合法性 ---------

    // 1.1 结点检查和相关处理
    int starting_vertex_index = GetVertexIndex(starting_vertex);        // 获取起点索引
    int ending_vertex_index = GetVertexIndex(ending_vertex);            // 获取终点索引

    if (starting_vertex_index < 0) {                                    // if 起点索引 < 0
        bool res = this->InsertVertex(starting_vertex);                 // 插入起点
        if (!res) {                                                     // if 插入失败
            return false;                                               // 返回false
        }

        starting_vertex_index = this->GetVertexIndex(starting_vertex);  // 使用新插入的起点获取起点索引
    }

    if (ending_vertex_index < 0) {                                      // if 终点索引 < 0
        bool res = this->InsertVertex(ending_vertex);                   // 插入终点
        if (!res) {                                                     // if 插入失败
            return false;                                               // 返回false
        }

        ending_vertex_index = this->GetVertexIndex(ending_vertex);      // 使用新插入的终点获取终点索引
    }

    // if 起点索引 < 0 || 终点索引 < 0 || 起点索引 等于 终点索引
    if (starting_vertex_index < 0 || ending_vertex_index < 0 || starting_vertex_index == ending_vertex_index) {
        return false;                                                   // 返回false
    }

    // ---------- 1.2 边检查 ----------
    for (unsigned int i = 0; i < this->edges_.size(); i++) {            // for loop 遍历edges_
        if (this->type_ == Graph<TVertex, TWeight>::UNDIRECTED) {       // if 无向图
            // if 边(起点--->终点) or 反向边(终点--->起点) 存在
            if ((this->edges_[i].starting_vertex == starting_vertex &&
                 this->edges_[i].ending_vertex == ending_vertex) ||
                (this->edges_[i].starting_vertex == ending_vertex &&
                 this->edges_[i].ending_vertex == starting_vertex)) {
                return false;   // 返回false
            }
        } else if (this->type_ == Graph<TVertex, TWeight>::DIRECTED) {  // if 有向图
            // if 边(起点--->终点) 存在
            if (this->edges_[i].starting_vertex == starting_vertex && this->edges_[i].ending_vertex == ending_vertex) {
                return false;   // 返回false
            }
        }
    }

    // 1.3 邻接表检查
    // 初始化cur_adjacency(当前邻接项)指向起点对应的结点邻接项的第1个邻接项
    Adjacency<TVertex, TWeight>* cur_adjacency = this->adjacency_list_[starting_vertex_index].first_adjacency;
    // while loop 当前邻接项存在 and 当前邻接项的终点索引不等于终点索引
    while (cur_adjacency != NULL && cur_adjacency->ending_vertex_index != ending_vertex_index) {
        cur_adjacency = cur_adjacency->next;    // 当前邻接项指向next
    }

    if (cur_adjacency != NULL) {    // if 当前邻接项存在非NULL值
        return false;               // 返回false
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

    // ---------- 1 合法性检查 ----------
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
                remove_edge_index = (int)i;
                break;
            }
        }
    } else if (this->type_ == Graph<TVertex, TWeight>::UNDIRECTED) {
        for (unsigned int i = 0; i < this->edges_.size(); i++) {
            if ((this->edges_[i].starting_vertex == starting_vertex && this->edges_[i].ending_vertex == ending_vertex) ||
                (this->edges_[i].starting_vertex == ending_vertex && this->edges_[i].ending_vertex == starting_vertex))
            {
                remove_edge_index = (int)i;
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

    if (vertex_index < 0) {
        return false;
    }

    Adjacency<TVertex, TWeight>* adjacency = this->adjacency_list_[vertex_index].first_adjacency;
    if (!adjacency) {
        return false;
    }

    int neighbor_index = adjacency->ending_vertex_index; // 第一个邻接结点的索引

    bool new_neighbor_exists = this->GetVertexByIndex(neighbor_index, first_neighbor);

    return new_neighbor_exists;
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
    int vertex_index = GetVertexIndex(vertex);
    int neighbor_index = GetVertexIndex(neighbor_vertex);

    if (vertex_index < 0) {
        return false;
    }

    // 邻接表中, 找到neighbor_vertex的位置
    Adjacency<TVertex, TWeight>* cur = this->adjacency_list_[vertex_index].first_adjacency;
    if (!cur) {
        return false;
    }

    while (cur->next != NULL && cur->ending_vertex_index != neighbor_index) {
        cur = cur->next;
    }

    if (!cur || !cur->next) {
        return false;
    }

    int next_neighbor_index = cur->next->ending_vertex_index;

    bool new_neighbor_exists = this->GetVertexByIndex(next_neighbor_index, next_neighbor);

    return new_neighbor_exists;
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
