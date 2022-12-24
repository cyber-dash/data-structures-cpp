/*!
 * @file graph.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 图抽象模板类
 * @version 0.2.1
 * @date 2021-01-23
 */

#ifndef CYBER_DASH_GRAPH_H
#define CYBER_DASH_GRAPH_H


#include <vector>


using namespace std;


template<typename TVertex, typename TWeight>
class Edge {
public:
    Edge(TVertex starting_vertex, TVertex ending_vertex, TWeight weight):
        starting_vertex(starting_vertex), ending_vertex(ending_vertex), weight(weight) {};

    // int starting_vertex_index;       //!< 起点索引
    // int ending_vertex_index;         //!< 终点索引
    TVertex starting_vertex;        //!< 起点
    TVertex ending_vertex;          //!< 终点
    TWeight weight;                 //!< 边权值
};


/*!
 * @brief **路径模板类**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 */
template<typename TVertex, typename TWeight>
class Path {
public:
    Path(): starting_vertex(TVertex()), ending_vertex(TVertex()), weight(TWeight()) {};
    Path(TVertex starting_vertex, TVertex ending_vertex, TWeight weight):
      starting_vertex(starting_vertex), ending_vertex(ending_vertex), weight(weight) {}

    /*!
     * 重载 <=
     * @param path 边
     * @return 比较结果
     */
    bool operator<=(const Path<TVertex, TWeight>& path) const { return weight <= path.weight; }

    /*!
     * 重载 >=
     * @param path 边
     * @return 比较结果
     */
    bool operator>=(const Path<TVertex, TWeight>& path) const { return weight >= path.weight; }

    /*!
     * 重载 >
     * @param path 边
     * @return 比较结果
     */
    bool operator>(const Path<TVertex, TWeight>& path) const { return weight > path.weight; }

    /*!
     * 重载 <
     * @param path 边
     * @return 比较结果
     */
    bool operator<(const Path<TVertex, TWeight>& path) const { return weight < path.weight; }

    TWeight weight;             //!< 路径权值
    TVertex starting_vertex;    //!< 起点
    TVertex ending_vertex;      //!< 终点
};


/*!
 * @brief **图抽象模板类**
 * @tparam TVertex 节点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 */
template<typename TVertex, typename TWeight>
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
    unsigned int VertexCount() const { return this->vertex_count_; }

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
    unsigned int EdgeCount() const { return this->edge_count_; }

    /*!
     * @brief **获取边权值上限**
     * @return 边权值上限
     */
    virtual TWeight MaxWeight() const { return this->max_weight_; }

    /*!
     * @brief **获取边vector**
     * @return 边vector
     */
    virtual const vector<Edge<TVertex, TWeight> >& Edges() const { return this->edges_; }

    /*!
     * @brief **获取边(by边索引)**
     * @param index 边索引
     * @return 边
     * @note
     * 获取边(by边索引)
     * --------------
     * --------------
     * todo: 改为返回bool类型
     * --------------
     */
    virtual const Edge<TVertex, TWeight>& GetEdge(int index) const { return this->edges_[index]; }

    /*!
     * @brief **获取结点(by结点索引)(纯虚函数)**
     * @param vertex 结点保存变量
     * @param vertex_index 结点索引
     * @return 执行结果
     * @note
     * 获取结点(by结点索引)(纯虚函数)
     * ---------------
     * ---------------
     *
     * ---------------
     */
    virtual bool GetVertexByIndex(int vertex_index, TVertex& vertex) const = 0;

    /*!
     * @brief **获取边权值(by结点)(纯虚函数)**
     * @param weight 边权值保存变量
     * @param starting_vertex 起点
     * @param ending_vertex 终点
     * @return 执行结果
     * @note
     * 获取边权值(by结点)(纯虚函数)
     * -----------------
     * -----------------
     *
     * -----------------
     */
    virtual bool GetWeight(const TVertex& starting_vertex, const TVertex& ending_vertex, TWeight& weight) const = 0;

    /*!
     * @brief 获取边权值(by结点索引)
     * @param weight 边权值保存变量
     * @param starting_vertex_index 起点索引
     * @param ending_vertex_index 终点索引
     * @return 执行结果
     * @note
     * 获取边权值(by结点索引)
     * ---------------------
     * ---------------------
     *
     * ---------------------
     */
    virtual bool GetWeightByVertexIndex(int starting_vertex_index, int ending_vertex_index, TWeight& weight) const = 0;


    /*!
     * @brief **获取结点的第一个相邻结点**
     * @param first_neighbor 第一个相邻结点保存变量
     * @param vertex 当前结点
     * @return 执行结果
     * @note
     * 获取结点的第一个相邻结点
     * --------------------
     * --------------------
     *
     * --------------------
     */
    virtual bool GetFirstNeighborVertex(const TVertex& vertex, TVertex& first_neighbor) const = 0;


    /*!
     * @brief **获取结点的下一个相邻结点**
     * @param next_neighbor 下一个相邻结点保存变量
     * @param vertex 当前结点
     * @param neighbor_vertex 相邻节点
     * @return 执行结果
     * @note
     * 获取结点的下一个相邻结点
     * --------------------
     * --------------------
     *
     * --------------------
     */
    virtual bool GetNextNeighborVertex(const TVertex& vertex,
                                       const TVertex& neighbor_vertex,
                                       TVertex& next_neighbor) const = 0;

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
    virtual bool InsertEdge(const TVertex& starting_vertex, const TVertex& ending_vertex, const TWeight& weight) = 0;

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
    virtual bool RemoveVertex(const TVertex& vertex) = 0;


    /*!
     * @brief **删除边**
     * @param starting_vertex 起点
     * @param ending_vertex 终点
     * @return 执行结果
     * @note
     * 删除边
     * -----
     * -----
     *
     * -----
     */
    virtual bool RemoveEdge(const TVertex& starting_vertex, const TVertex& ending_vertex) = 0;

    /*!
     * @brief **获取结点索引**
     * @param vertex 结点
     * @return 结点索引
     * @note
     * 获取结点索引
     * --------------
     * --------------
     *
     * --------------
     */
    virtual int GetVertexIndex(TVertex vertex) const = 0;

protected:
    int max_vertex_count_{};    //!< 图结点数量上限
    TWeight max_weight_;      //!< 边权值上限
    int edge_count_{};          //!< 边数量
    int vertex_count_{};        //!< 结点数量

    vector<TVertex> vertices_;              //!< 结点vector
    vector<Edge<TVertex, TWeight> > edges_; //!< 边vector
};


#endif //CYBER_DASH_GRAPH_H
