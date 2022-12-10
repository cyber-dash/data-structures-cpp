/*!
 * @file graph.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 图抽象模板类
 * @version 0.2.1
 * @date 2021-01-23
 */

#ifndef CYBER_DASH_GRAPH_H
#define CYBER_DASH_GRAPH_H


// const int DEFAULT_VERTICES = 20;


template<class TVertex, class TWeight>
class AdjacencyListPath {
public:
  AdjacencyListPath() = default;
  AdjacencyListPath(TVertex starting_vertex, TVertex ending_vertex, TWeight weight):
    starting_vertex(starting_vertex), ending_vertex(ending_vertex), weight(weight) {}
  TWeight weight;
  TVertex starting_vertex;
  TVertex ending_vertex;

  /*!
   * 重载 <=
   * @param edge 边
   * @return 比较结果
   */
  bool operator<=(const AdjacencyListPath<TVertex, TWeight>& edge) const { return weight <= edge.weight; }

  /*!
   * 重载 >=
   * @param edge 边
   * @return 比较结果
   */
  bool operator>=(const AdjacencyListPath<TVertex, TWeight>& edge) const { return weight >= edge.weight; }

  /*!
   * 重载 >
   * @param edge 边
   * @return 比较结果
   */
  bool operator>(const AdjacencyListPath<TVertex, TWeight>& edge) const { return weight > edge.weight; }

  /*!
   * 重载 <
   * @param edge 边
   * @return 比较结果
   */
  bool operator<(const AdjacencyListPath<TVertex, TWeight>& edge) const { return weight < edge.weight; }
};


/*!
 * @brief **图抽象模板类**
 * @tparam TVertex 节点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 */
template<class TVertex, class TWeight>
class Graph {
public:

  /*!
   * @brief **获取结点数量**
   * @return 结点数量
   * @note
   * 获取结点数量
   * ----------
   * ----------
   *
   * ----------
   */
  unsigned int VertexCount() { return this->vertex_count_; }

  /*!
   * @brief **获取边数量**
   * @return 边数量
   * @note
   * 获取边数量
   * ---------
   * ---------
   *
   * ---------
   */
  unsigned int EdgeCount() { return this->edge_count_; }

  virtual TWeight MaxWeight() const { return this->max_weight_; }

  /*!
   * @brief **由结点索引获取结点(纯虚函数)**
   * @param vertex 结点保存变量
   * @param vertex_index 结点索引
   * @return 执行结果
   * @note
   * 由结点索引获取结点
   * ---------------
   * ---------------
   *
   * ---------------
   */
  virtual bool GetVertexByIndex(TVertex& vertex, int vertex_index) = 0;

  /*!
   * @brief **获取边权值(使用结点)**
   * @param weight 边权值保存变量
   * @param v1 边的一个节点
   * @param v2 边的另一个节点
   * @return 执行结果
   * @note
   * 获取边权值(使用结点)
   * -----------------
   * -----------------
   *
   * -----------------
   */
  virtual bool GetWeight(TWeight& weight, TVertex v1, TVertex v2) = 0;

  /*!
   * @brief 获取边权值(使用结点索引)
   * @param weight 边权值保存变量
   * @param v1_index 边的一个结点索引
   * @param v2_index 边的另一个结点索引
   * @return 执行结果
   * @note
   * 获取边权值(使用结点索引)
   * ---------------------
   * ---------------------
   *
   * ---------------------
   */
  virtual bool GetWeightByVertexIndex(TWeight& weight, int v1_index, int v2_index) = 0;

  /*!
   * @brief **获取结点的第一个相邻结点**
   * @param first_neighbor 第一个相邻结点的保存变量
   * @param vertex 结点
   * @return 执行结果
   * @note
   * 获取结点的第一个相邻结点
   * --------------------
   * --------------------
   *
   * --------------------
   */
  virtual bool GetFirstNeighborVertex(TVertex& first_neighbor, const TVertex& vertex) = 0;


  /*!
   * @brief **获取结点的下一个相邻结点**
   * @param next_neighbor 下一相邻结点的保存变量
   * @param vertex 结点
   * @param neighbor_vertex 相邻节点
   * @return 执行结果
   * @note
   * 获取结点的下一个相邻结点
   * --------------------
   * --------------------
   *
   * --------------------
   */
  virtual bool GetNextNeighborVertex(TVertex& next_neighbor, const TVertex& vertex, const TVertex& neighbor_vertex) = 0;


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
  virtual bool InsertVertex(const TVertex& vertex) = 0;

  /*!
   * @brief **插入边**
   * @param vertex1 边的一个结点
   * @param vertex2 边的另一个结点
   * @param weight 边的权值
   * @return 执行结果
   * @note
   * 插入边
   * -----
   * -----
   *
   * -----
   */
  virtual bool InsertEdge(TVertex vertex1, TVertex vertex2, TWeight weight) = 0;


  /*!
   * @brief **删除结点**
   * @param vector 结点
   * @return 执行结果
   * @note
   * 删除结点
   * -------
   * -------
   *
   * -------
   */
  virtual bool RemoveVertex(TVertex vector) = 0;


  /*!
   * @brief **删除边**
   * @param vertex1 边的一个节点
   * @param vertex2 边的另一个节点
   * @return 执行结果
   * @note
   * 删除边
   * -----
   * -----
   *
   * -----
   */
  virtual bool RemoveEdge(TVertex vertex1, TVertex vertex2) = 0;

  /*!
   * @brief **获取结点的索引值**
   * @param vertex 结点
   * @return 索引值
   * @note
   * 获取结点的索引值
   * --------------
   * --------------
   *
   * --------------
   */
  virtual int GetVertexIndex(TVertex vertex) = 0;

protected:
  int max_vertex_count_;    //!< 图节点数量最大限制
  int edge_count_;          //!< 边数量
  int vertex_count_;        //!< 节点数量
  TWeight max_weight_;
};


#endif //CYBER_DASH_GRAPH_H
