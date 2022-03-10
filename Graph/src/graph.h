/*!
 * @file graph.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 图虚基模板类
 * @version 0.2.1
 * @date 2021-01-23
 *
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#ifndef CYBER_DASH_GRAPH_H
#define CYBER_DASH_GRAPH_H


const int DEFAULT_VERTICES = 20; //<! 默认图结点个数
const int MAX_WEIGHT = 1000; //<! 最大权值, todo: 矩阵图剔除这个逻辑


/*!
 * @brief 图基类(模板类)
 * @tparam Vertex 节点类型模板参数
 * @tparam Weight 边权值类型模板参数
 */
template<class Vertex, class Weight>
class Graph {
public:

  /*!
   * @brief 获取图结点数量
   * @return 图结点数量
   */
  int NumberOfVertices() { return this->vertices_num_; }

  /*!
   * @brief 获取边数量
   * @return 边数量
   */
  int NumberOfEdges() { return this->edge_count_; }

  /*!
   * @brief 获取结点(由结点索引)
   * @param vertex 结点(用于保存结果)
   * @param vertex_index 结点索引
   * @return 是否获取成功
   */
  virtual bool GetVertexByIndex(Vertex& vertex, int vertex_index) = 0;

  /*!
   * @brief 获取边权值
   * @param weight 边权值(用于保存结果)
   * @param v1 边的一个节点
   * @param v2 边的另一个节点
   * @return 是否获取成功
   */
  virtual bool GetWeight(Weight& weight, Vertex v1, Vertex v2) = 0;

  /*!
   * @brief 获取结点的第一个相邻结点
   * @param first_neighbor 结点(用于保存第一个相邻结点)
   * @param vertex 结点
   * @return 是否获取成功
   */
  virtual bool GetFirstNeighborVertex(Vertex& first_neighbor, const Vertex& vertex) = 0;

  /*!
   * @brief 获取结点的下一个相邻结点
   * @param next_neighbor 结点(用于保存下一个相邻结点)
   * @param vertex 结点
   * @param neighbor_vertex 结点的一个相邻节点
   * @return 是否获取成功
   */
  virtual bool GetNextNeighborVertex(Vertex& next_neighbor, const Vertex& vertex, const Vertex& neighbor_vertex) = 0;

  /*!
   * @brief 插入结点
   * @param vertex 结点
   * @return 是否插入成功
   */
  virtual bool InsertVertex(const Vertex& vertex) = 0;

  /*!
   * @brief 插入边
   * @param vertex1 边的一个结点
   * @param vertex2 边的另一个结点
   * @param weight 边的权值
   * @return 是否插入成功
   */
  virtual bool InsertEdge(Vertex vertex1, Vertex vertex2, Weight weight) = 0;

  /*!
   * @brief 删除结点
   * @param v 节点
   * @return 是否删除成功
   */
  virtual bool RemoveVertex(Vertex v) = 0;

  /*!
   * @brief 删除边
   * @param v1 边的一个节点
   * @param v2 边的另一个节点
   * @return 是否删除成功
   */
  virtual bool RemoveEdge(Vertex v1, Vertex v2) = 0;

  /*!
   * @brief 获取结点的索引值
   * @param vertex 节点
   * @return 是否获取成功
   */
  virtual int GetVertexIndex(Vertex vertex) = 0;

protected:
  int max_vertices_num_; //!< 图节点数量最大限制
  int edge_count_; //!< 边数量
  int vertices_num_; //!< 节点数量
};


#endif //CYBER_DASH_GRAPH_H
