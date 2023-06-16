/*!
 * @file graph.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 图抽象模板类与边模板类
 * @version 0.2.1
 * @date 2021-01-23
 */

#ifndef CYBER_DASH_GRAPH_H
#define CYBER_DASH_GRAPH_H


#include <vector>


using namespace std;


/*!
 * @brief **边模板类**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @note
 * 边模板类
 * -------
 * -------
 *
 * <span style="color:#DF5A00">
 * 注:\n
 * 此模板类只表示存在边, 并不表达边的方向\n
 * 边的方向在邻接表图中, 由邻接表表示, 在邻接矩阵图中, 由邻接矩阵表示\n
 * </span>
 *
 * -------
 *
 */
template<typename TVertex, typename TWeight>
class Edge {
public:
    /*!
     * @brief **默认构造函数**
     * @note
     * 默认构造函数
     * ----------
     * ----------
     *
     * ----------
     */
    Edge(): starting_vertex(TVertex()), ending_vertex(TVertex()), weight(TWeight()) {}

    /*!
     * @brief **构造函数(边权值/起点/终点)**
     * @param weight 边权值
     * @param starting_vertex 起点
     * @param ending_vertex 终点
     * @note
     * 构造函数(边权值/起点/终点)
     * -----------------------
     * -----------------------
     *
     * -----------------------
     */
    Edge(const TVertex& starting_vertex, const TVertex& ending_vertex, const TWeight& weight):
        weight(weight), starting_vertex(starting_vertex), ending_vertex(ending_vertex) {}

    /*!
     * @brief **重载<=**
     * @param edge 边
     * @return 执行结果
     * @note
     * 重载<=
     * -----
     * -----
     *
     * -----
     */
    bool operator<=(const Edge<TVertex, TWeight>& edge) { return weight <= edge.weight; }

    /*!
     * @brief **重载>=**
     * @param edge 边
     * @return 执行结果
     * @note
     * 重载>=
     * -----
     * -----
     *
     * -----
     */
    bool operator>=(const Edge<TVertex, TWeight>& edge) { return weight >= edge.weight; }

    /*!
     * @brief **重载>**
     * @param edge 边
     * @return 执行结果
     * @note
     * 重载>
     * ----
     * ----
     *
     * ----
     */
    bool operator>(const Edge<TVertex, TWeight>& edge) { return weight > edge.weight; }

    /*!
     * @brief **重载&lt;**
     * @param edge 最小生成树边
     * @return 执行结果
     * @note
     * 重载<
     * ----
     * ----
     *
     * <span style="color:#DF5A00">
     * doxygen处理less-than符号(&lt;)不是很友好, 所以注释中使用"\&lt;"来表达&lt;
     * </span>
     *
     * ----
     */
    bool operator<(const Edge<TVertex, TWeight>& edge) { return weight < edge.weight; }

    TVertex starting_vertex;  //!< **起点**
    TVertex ending_vertex;    //!< **终点**
    TWeight weight;           //!< **边权重**
};


/*!
 * @brief **路径模板类**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 */
template<typename TVertex, typename TWeight>
class Path: public Edge<TVertex, TWeight> {
public:
    Path(): starting_vertex(TVertex()), ending_vertex(TVertex()), weight(TWeight()) {};
    Path(TVertex starting_vertex, TVertex ending_vertex, TWeight weight):
      starting_vertex(starting_vertex), ending_vertex(ending_vertex), weight(weight) {}

    TWeight weight;             //!< **路径权值**
    TVertex starting_vertex;    //!< **起点**
    TVertex ending_vertex;      //!< **终点**
};


/*!
 * @brief **图抽象模板类**
 * @tparam TVertex 节点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @note
 * 图抽象模板类
 * ----------
 * ----------
 *
 * ----------
 */
template<typename TVertex, typename TWeight>
class Graph {
public:
    /*!
     * @brief **获取图类型**
     * @return 图类型
     * @note
     * 1: 有向, 2: 无向
     */
    int Type() const { return this->type_; }

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
     * @brief **获取结点vector**
     * @return 结点vector
     */
    virtual const vector<TVertex>& Vertices() const { return this->vertices_; }

    /*!
     * @brief **获取边(by边索引)**
     * @param index 边索引
     * @return 边
     * @note
     * 获取边(by边索引)
     * --------------
     * --------------
     *
     * todo: 应该改为返回bool类型
     *
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
     * @brief **获取边权值(by结点索引)**
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


    /**!
     * @brief **获取结点的度**
     * @param vertex 结点
     * @return 度
     * @note
     * 获取结点的度
     * ----------
     * ----------
     *
     * ----------
     * **if** 有向图 :\n
     * &emsp; 返回-1(有向图应获取出度入度)\n\n
     * 获取vertex_index(结点索引)\n\n
     * 返回this->degrees_[vertex_index]\n
     *
     *
     * ----------
     */
    int GetVertexDegree(TVertex vertex) {
       if (this->type_ == DIRECTED) {                                           // if 有向图
           return -1;                                                           // 返回-1(有向图应获取出度入度)
       }

       int vertex_index = GetVertexIndex(vertex);                               // 获取vertex_index(结点索引)

       return this->degrees_[vertex_index];                                     // 返回this->degrees_[vertex_index]
    }


    /**!
     * @brief **获取结点的入度**
     * @param vertex 结点
     * @return 入度
     * @note
     * 获取结点的入度
     * ------------
     * ------------
     *
     * ------------
     * **if** 无向图 :\n
     * &emsp; 返回-1(无向图应获取度)\n\n
     * 获取vertex_index(结点索引)\n\n
     * 返回this->in_degrees_[vertex_index]\n
     *
     *
     * ----------
     */
    int GetVertexInDegree(const TVertex& vertex) const {
        if (this->type_ == UNDIRECTED) {                                        // if 无向图
            return -1;                                                          // 返回-1(无向图应获取度)
        }

        int vertex_index = GetVertexIndex(vertex);                              // 获取vertex_index(结点索引)

        return this->in_degrees_[vertex_index];                                 // 返回this->in_degrees_[vertex_index]
    }


    /**!
     * @brief **获取结点的出度**
     * @param vertex 结点
     * @return 出度
     * @note
     * 获取结点的出度
     * ------------
     * ------------
     *
     * ------------
     * **if** 无向图 :\n
     * &emsp; 返回-1(无向图应获取度)\n\n
     * 获取vertex_index(结点索引)\n\n
     * 返回this->out_degrees_[vertex_index]\n
     *
     *
     * ----------
     */
    int GetVertexOutDegree(TVertex vertex) {
        if (this->type_ == UNDIRECTED) {                                        // if 无向图
            return -1;                                                          // 返回-1(无向图应获取度)
        }

        int vertex_index = GetVertexIndex(vertex);                              // 获取vertex_index(结点索引)

        return this->out_degrees_[vertex_index];                                // 返回this->out_degrees_[vertex_index]
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
    virtual int GetVertexIndex(const TVertex& vertex) const = 0;

    static const int DIRECTED = 1;            //!< **有向**
    static const int UNDIRECTED = 2;          //!< **无向**
protected:
    int max_vertex_count_;                    //!< **图结点数量上限**
    TWeight max_weight_;                      //!< **边权值上限**
    int edge_count_;                          //!< **边数量**
    int vertex_count_;                        //!< **结点数量**
    int type_;                                //!< **类型(1:有向, 2:无向)**

    vector<TVertex> vertices_;                //!< **结点vector**
    vector<Edge<TVertex, TWeight> > edges_;   //!< **边vector**
    vector<int> degrees_;                     //!< **度vector(无向图使用)**
    vector<int> in_degrees_;                  //!< **入度vector(有向图使用)**
    vector<int> out_degrees_;                 //!< **出度vector(有向图使用)**
};


#endif //CYBER_DASH_GRAPH_H
