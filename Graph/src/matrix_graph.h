/*!
 * @file matrix_graph.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 矩阵图模板类
 * @version 0.2.1
 * @date 2021-07-14
 */

#ifndef CYBER_DASH_MATRIX_GRAPH_H
#define CYBER_DASH_MATRIX_GRAPH_H


#include <iostream>
#include <iomanip>
#include <map>
#include "graph.h"


using namespace std;


template<typename TVertex, typename TWeight> class MatrixGraph;
// 重载>>
template<typename TVertex, typename TWeight>
istream& operator>>(istream& in, MatrixGraph<TVertex, TWeight>& graph);
// 重载<<
template<typename TVertex, typename TWeight>
ostream& operator<<(ostream& out, MatrixGraph<TVertex, TWeight>& graph);


/*!
 * @brief **矩阵图模板类**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 */
template<typename TVertex, typename TWeight>
class MatrixGraph: public Graph<TVertex, TWeight> {
public:
    // 构造函数(结点数上限/边权值上限)
    MatrixGraph(int max_vertex_count, TWeight max_weight);

    // 构造函数(图类型/结点数上线/边权值上线)
    MatrixGraph(int type, int max_vertex_count, TWeight max_weight);

    // 构造函数(结点数上限/边权值上限/边/结点vector)
    MatrixGraph(int max_vertex_count,
                TWeight max_weight,
                const vector<Edge<TVertex, TWeight> >& edges,
                const vector<TVertex>& vertices);

    // 构造函数(图类型/结点数上线/边权值上线/边/节点vector)
    MatrixGraph(int type,
                int max_vertex_count,
                TWeight max_weight,
                const vector<Edge<TVertex, TWeight> >& edges,
                const vector<TVertex>& vertices);

    // 析构函数
    ~MatrixGraph();

    // 获取结点(by结点索引)
    bool GetVertexByIndex(int vertex_index, TVertex& vertex) const;

    // 获取边权值(by结点)
    bool GetWeight(const TVertex& starting_vertex, const TVertex& ending_vertex, TWeight& weight) const;

    // 获取边权值(by结点索引)
    bool GetWeightByVertexIndex(int starting_vertex_index, int ending_vertex_index, TWeight& weight) const;

    // 获取结点的第一个相邻结点
    bool GetFirstNeighborVertex(const TVertex& vertex, TVertex& first_neighbor) const;

    // 获取结点的下一个相邻结点
    bool GetNextNeighborVertex(const TVertex& vertex,
                               const TVertex& neighbor_vertex,
                               TVertex& next_neighbor_vertex) const;

    // 插入结点
    bool InsertVertex(const TVertex& vertex);

    // 插入边
    bool InsertEdge(const TVertex& starting_vertex, const TVertex& ending_vertex, const TWeight& weight);

    // 删除结点
    bool RemoveVertex(const TVertex& vertex);

    // 删除边
    bool RemoveEdge(const TVertex& starting_vertex, const TVertex& ending_vertex);

    // 获取结点索引
    int GetVertexIndex(const TVertex& vertex) const;

    // 重载>>
    friend istream& operator>> <>(istream& in, MatrixGraph<TVertex, TWeight>& graph);
    // 重载<<
    friend ostream& operator<< <>(ostream& out, MatrixGraph<TVertex, TWeight>& graph);

    // 打印邻接数组
    void PrintMatrix();
private:
    TWeight** adjacency_matrix_; //!< 邻接矩阵
};


/*!
 * @brief **构造函数(结点数上限/边权值上限)**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param max_vertex_count 结点数上限
 * @param max_weight 边权值上限
 * @note
 * 构造函数(结点数上限/边权值上限)
 * -------
 * -------
 *
 * <span style="color:#DF5A00">
 * 听过的风, 走过的路
 * </span>
 *
 * -------
 * ###1 设置部分成员变量###
 * ###2 设置邻接矩阵###
 *
 */
template<typename TVertex, typename TWeight>
MatrixGraph<TVertex, TWeight>::MatrixGraph(int max_vertex_count, TWeight max_weight) {

    // ---------- 1 设置部分成员变量 ----------
    this->type_ = Graph<TVertex, TWeight>::UNDIRECTED;
    this->max_weight_ = max_weight;
    this->max_vertex_count_ = max_vertex_count;

    this->vertex_count_ = 0;
    this->edge_count_ = 0;

    // ---------- 2 设置邻接矩阵 ----------
    this->adjacency_matrix_ = new TWeight*[this->max_vertex_count_];
    if (!this->adjacency_matrix_) {
        throw bad_alloc();
    }

    for (int row = 0; row < this->max_vertex_count_; row++) {
        this->adjacency_matrix_[row] = new TWeight[this->max_vertex_count_]; // 节点i对应的所有边
        if (!this->adjacency_matrix_[row]) {
            throw bad_alloc();
        }

        for (int col = 0; col < this->max_vertex_count_; col++) {
            this->adjacency_matrix_[row][col] = TWeight();
        }
    }
}


/*!
<<<<<<< HEAD
 * @brief **构造函数(结点数上限/边权值上限/边/结点vector)**
=======
 * @brief **构造函数**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param type 图类型
 * @param max_vertex_count 结点数上限
 * @param max_weight 边权值上限
 * @note
 * 构造函数
 * -------
 * -------
 *
 * -------
 */
template<typename TVertex, typename TWeight>
MatrixGraph<TVertex, TWeight>::MatrixGraph(int type, int max_vertex_count, TWeight max_weight) {
    this->type_ = type;
    this->max_weight_ = max_weight;
    this->max_vertex_count_ = max_vertex_count;

    this->vertex_count_ = 0;
    this->edge_count_ = 0;

    this->adjacency_matrix_ = new TWeight*[this->max_vertex_count_];
    if (!this->adjacency_matrix_) {
        throw bad_alloc();
    }

    for (int row = 0; row < this->max_vertex_count_; row++) {
        this->adjacency_matrix_[row] = new TWeight[this->max_vertex_count_]; // 节点i对应的所有边
        if (!this->adjacency_matrix_[row]) {
            throw bad_alloc();
        }

        for (int col = 0; col < this->max_vertex_count_; col++) {
            this->adjacency_matrix_[row][col] = TWeight();
        }
    }
}

/*!
 * @brief **构造函数(边/结点vector)**
>>>>>>> 矩阵图增加有向/无向(图/网)类型的支持, Floyd函数支持有向(图/网)的支持
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param max_vertex_count 结点数上限
 * @param max_weight 边权值上限
 * @param edges 边vector
 * @param vertices 结点vector
 * @note
 * 构造函数(结点数上限/边权值上限/边/结点vector)
 * ---------------------
 * ---------------------
 *
 * <span style="color:#DF5A00">
 * 听过的风, 走过的路\n
 * 爱过的人, 闯过的祸
 * </span>
 *
 * ---------------------
 * ###1 设置部分成员变量###
 * ###2 设置邻接矩阵###
 */
template<typename TVertex, typename TWeight>
MatrixGraph<TVertex, TWeight>::MatrixGraph(int max_vertex_count,
                                           TWeight max_weight,
                                           const vector<Edge<TVertex, TWeight> >& edges,
                                           const vector<TVertex>& vertices)
{
    // ---------- 1 设置部分成员变量 ----------
    this->type_ = Graph<TVertex, TWeight>::UNDIRECTED;
    this->max_weight_ = max_weight;
    this->max_vertex_count_ = max_vertex_count;

    this->vertex_count_ = 0;
    this->edge_count_ = 0;

    // ---------- 2 设置邻接矩阵 ----------
    this->adjacency_matrix_ = new TWeight*[this->max_vertex_count_];
    if (!this->adjacency_matrix_) {
        throw bad_alloc();
    }

    for (int row = 0; row < this->max_vertex_count_; row++) {
        this->adjacency_matrix_[row] = new TWeight[this->max_vertex_count_]; // 节点i对应的所有边
        if (!this->adjacency_matrix_) {
            throw bad_alloc();
        }

        for (int col = 0; col < this->max_vertex_count_; col++) {
            this->adjacency_matrix_[row][col] = TWeight();
        }
    }

    for (unsigned int i = 0; i < vertices.size(); i++) {
        this->InsertVertex(vertices[i]);
    }

    for (unsigned int i = 0; i < edges.size(); i++) {
        this->InsertEdge(edges[i].starting_vertex, edges[i].ending_vertex, edges[i].weight);
    }
}


/*!
 * @brief **构造函数(边/结点vector)**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param max_vertex_count 结点数上限
 * @param max_weight 边权值上限
 * @param edges 边vector
 * @param vertices 结点vector
 * @note
 * 构造函数(边/结点vector)
 * ---------------------
 * ---------------------
 *
 * ---------------------
 */
template<typename TVertex, typename TWeight>
MatrixGraph<TVertex, TWeight>::MatrixGraph(int type,
                                           int max_vertex_count,
                                           TWeight max_weight,
                                           const vector<Edge<TVertex, TWeight> >& edges,
                                           const vector<TVertex>& vertices)
{
    this->type_ = type;
    this->max_weight_ = max_weight;
    this->max_vertex_count_ = max_vertex_count;

    this->vertex_count_ = 0;
    this->edge_count_ = 0;

    this->adjacency_matrix_ = new TWeight*[this->max_vertex_count_];
    if (!this->adjacency_matrix_) {
        throw bad_alloc();
    }

    for (int row = 0; row < this->max_vertex_count_; row++) {
        this->adjacency_matrix_[row] = new TWeight[this->max_vertex_count_]; // 节点i对应的所有边
        if (!this->adjacency_matrix_) {
            throw bad_alloc();
        }

        for (int col = 0; col < this->max_vertex_count_; col++) {
            this->adjacency_matrix_[row][col] = TWeight();
        }
    }

    for (unsigned int i = 0; i < vertices.size(); i++) {
        this->InsertVertex(vertices[i]);
    }

    for (unsigned int i = 0; i < edges.size(); i++) {
        this->InsertEdge(edges[i].starting_vertex, edges[i].ending_vertex, edges[i].weight);
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
 * <span style="color:#DF5A00">
 * 所谓痛苦不算什么
 * </span>
 *
 * -------
 * ###1 释放邻接矩阵的每行###
 * ###2 释放邻接矩阵###
 */
template<typename TVertex, typename TWeight>
MatrixGraph<TVertex, TWeight>::~MatrixGraph() {
    // ---------- 1 释放邻接矩阵的每行 ----------
    for (int row = 0; row < this->vertex_count_; row++) {
        delete[] this->adjacency_matrix_[row];
    }

    // ---------- 2 释放邻接矩阵 ----------
    delete[] this->adjacency_matrix_;
}


/*!
 * @brief **获取结点(by结点索引)**
 * @param vertex_index 结点索引
 * @param vertex 结点保存遍历
 * @return 执行结果
 * @note
 * 获取结点(by结点索引)
 * -----------------
 * -----------------
 *
 * -----------------
 */
template<typename TVertex, typename TWeight>
bool MatrixGraph<TVertex, TWeight>::GetVertexByIndex(int vertex_index, TVertex& vertex) const {
    if (vertex_index < 0 && vertex_index >= this->vertex_count_) {
        return false;
    }

    vertex = this->vertices_[vertex_index];

    return true;
}


/*!
 * @brief 获取边权值(by结点)
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
template<typename Vertex, typename Weight>
bool MatrixGraph<Vertex, Weight>::GetWeight(const Vertex& starting_vertex,
                                            const Vertex& ending_vertex,
                                            Weight& weight) const
{
    int starting_vertex_index = GetVertexIndex(starting_vertex);
    int ending_vertex_index = GetVertexIndex(ending_vertex);
    if (starting_vertex_index < 0 || ending_vertex_index < 0) {
        return false;
    }

    bool res = GetWeightByVertexIndex(starting_vertex_index, ending_vertex_index, weight);
    if (!res) {
        return false;
    }

    return true;
}


/*!
 * @brief 获取边权值(by结点索引)
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param starting_vertex_index 起点结点索引
 * @param ending_vertex_index 终点结点索引
 * @param weight 边权值
 * @return 执行结果
 * @note
 * 获取边权值(by结点索引)
 * -------------------
 * -------------------
 *
 * -------------------
 */
template<typename TVertex, typename TWeight>
bool MatrixGraph<TVertex, TWeight>::GetWeightByVertexIndex(int starting_vertex_index,
                                                           int ending_vertex_index,
                                                           TWeight& weight) const
{
    if (starting_vertex_index < 0 || ending_vertex_index < 0 || starting_vertex_index == ending_vertex_index ||
        adjacency_matrix_[starting_vertex_index][ending_vertex_index] == TWeight())
    {
        return false;
    }

    weight = adjacency_matrix_[starting_vertex_index][ending_vertex_index];

    return true;
}


/*!
 * @brief 获取结点的第一个相邻结点
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param vertex 结点
 * @param first_neighbor 第一个相邻结点保存变量
 * @return 执行结果
 * @note
 * 获取结点的第一个相邻结点
 * --------------------
 * --------------------
 *
 * --------------------
 */
template<typename TVertex, typename TWeight>
bool MatrixGraph<TVertex, TWeight>::GetFirstNeighborVertex(const TVertex& vertex, TVertex& first_neighbor) const {
    int vertex_index = GetVertexIndex(vertex);
    if (vertex_index < 0) {
        return false;
    }

    for (int i = 0; i < this->vertex_count_; i++) {
        TWeight weight;
        TVertex cur_vertex;

        bool res = GetVertexByIndex(i, cur_vertex);
        if (!res) {
            continue;
        }

        res = GetWeight(vertex, cur_vertex, weight);
        if (res) {
            first_neighbor = cur_vertex;
            return true;
        }
    }

    return false;
}


/*!
 * @brief 获取结点的下一个相邻结点
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param vertex 结点
 * @param neighbor_vertex 某相邻结点
 * @param next_neighbor_vertex 下一相邻结点保存变量
 * @return 执行结果
 * @note
 * 获取结点的下一个相邻结点
 * --------------------
 * --------------------
 *
 * --------------------
 */
template<typename TVertex, typename TWeight>
bool MatrixGraph<TVertex, TWeight>::GetNextNeighborVertex(const TVertex& vertex,
                                                          const TVertex& neighbor_vertex,
                                                          TVertex& next_neighbor_vertex) const
{
    int vertex_index = GetVertexIndex(vertex);
    int neighbor_vertex_index = GetVertexIndex(neighbor_vertex);

    if (vertex_index < 0 || neighbor_vertex_index < 0) {
        return false;
    }

    for (int i = neighbor_vertex_index + 1; i < this->vertex_count_; i++) {
        TWeight weight;
        TVertex cur_vertex;

        bool res = GetVertexByIndex(i, cur_vertex);
        if (!res) {
            continue;
        }

        res = GetWeight(vertex, cur_vertex, weight);
        if (res) {
            next_neighbor_vertex = cur_vertex;
            return true;
        }
    }

    return false;
}


/*!
 * @brief 插入结点
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
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
bool MatrixGraph<TVertex, TWeight>::InsertVertex(const TVertex& vertex) {
    if (this->vertex_count_ >= this->max_vertex_count_) {
        return false;
    }

    this->vertices_.push_back(vertex);
    this->vertex_count_++;

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
 * 需要起点和终点都已经在图内, 否则无法插入(先插入结点, 再插入边)
 * -----
 */
template<typename TVertex, typename TWeight>
bool MatrixGraph<TVertex, TWeight>::InsertEdge(const TVertex& starting_vertex,
                                               const TVertex& ending_vertex,
                                               const TWeight& weight)
{
    // ---------- 1 检查插入合法性 ---------

    // 1.1 结点检查
    int starting_vertex_index = GetVertexIndex(starting_vertex);
    int ending_vertex_index = GetVertexIndex(ending_vertex);

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

    if (starting_vertex_index < 0 || ending_vertex_index < 0 || starting_vertex_index == ending_vertex_index) {
        return false;
    }

    // 遍历edges_, 检查是否能找到待插入边
    for (int i = 0; i < this->edges_.size(); i++) {
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

    // 1.3 邻接矩阵检查
    if (this->type_ == Graph<TVertex, TWeight>::UNDIRECTED) {
        // 邻接矩阵存在该边
        if (this->adjacency_matrix_[starting_vertex_index][ending_vertex_index] != TWeight() ||
            this->adjacency_matrix_[ending_vertex_index][starting_vertex_index] != TWeight())
        {
            return false;
        }
    } else if (this->type_ == Graph<TVertex, TWeight>::DIRECTED) {
        // 邻接矩阵存在该边
        if (this->adjacency_matrix_[starting_vertex_index][ending_vertex_index] != TWeight()) {
            return false;
        }
    }

    // ---------- 2 执行插入 ----------
    // 2.1 边(starting_vertex ---> ending_vertex) 插入
    // 插入邻接矩阵
    this->adjacency_matrix_[starting_vertex_index][ending_vertex_index] = weight;

    // 插入edges_
    Edge<TVertex, TWeight> edge(starting_vertex, ending_vertex, weight);
    this->edges_.push_back(edge);

    // 2.2 无向图, 反向边(ending_vertex ---> starting_vertex) 插入
    if (this->type_ == Graph<TVertex, TWeight>::UNDIRECTED) {
        // 反向边插入邻接矩阵
        this->adjacency_matrix_[ending_vertex_index][starting_vertex_index] = weight;
    }

    // ---------- 3 调edge_count_ ----------
    this->edge_count_++;

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
 * <span style="color:#DF5A00">
 * 除了删除结点, 还要删除该结点所对应的每条边
 * </span>
 *
 * -------
 * ### 1 判断删除合理性 ###
 * ### 2 邻接矩阵调整 ###
 * ### 3 边/结点vector执行删除 ###
 * - 边vector执行删除\n
 * &emsp; **for loop** 遍历edges_ :\n
 * &emsp;&emsp; **if** 当前边起点or当前边终点 为待删除节点 :\n
 * &emsp;&emsp;&emsp; 删除当前边\n
 * &emsp;&emsp;&emsp; edge_count_减1\n
 * - 结点vector执行删除\n
 * &emsp; 删除vertices_的this->vertex_count_ - 1\n
 */
template<typename TVertex, typename TWeight>
bool MatrixGraph<TVertex, TWeight>::RemoveVertex(const TVertex& vertex) {

    // ---------- 1 判断删除合理性 ----------
    int vertex_index = GetVertexIndex(vertex);
    if (vertex_index < 0 || vertex_index >= this->vertex_count_) {
        return false;
    }

    // ---------- 2 邻接矩阵调整 ----------

    for (int i = 0; i < this->vertex_count_; i++) {
        this->adjacency_matrix_[i][vertex_index] = this->adjacency_matrix_[i][this->vertex_count_ - 1];
        this->adjacency_matrix_[vertex_index][i] = this->adjacency_matrix_[this->vertex_count_ - 1][i];
    }

    // ---------- 3 边/结点vector执行删除 ----------
    // 边vector执行删除
    for (typename vector<Edge<TVertex, TWeight> >::iterator iter = this->edges_.begin(); iter != this->edges_.end();) {
        if (iter->ending_vertex == vertex || iter->starting_vertex == vertex) {
            iter = this->edges_.erase(iter);
            this->edge_count_--;
        } else {
            iter++;
        }
    }

    // 结点vector执行删除
    this->vertices_[vertex_index] = this->vertices_[this->vertex_count_ - 1];
    this->vertices_.erase(this->vertices_.begin() + this->vertex_count_ - 1);
    this->vertex_count_--;

    return true;
}


/*!
 * @brief **删除边**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
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
template<typename TVertex, typename TWeight>
bool MatrixGraph<TVertex, TWeight>::RemoveEdge(const TVertex& starting_vertex, const TVertex& ending_vertex) {

    /// ----- 1 检查合法性 -----
    // 1.1 检查结点
    // 起点/结点, 如果有一个不存在, 则返回false
    int starting_vertex_index = GetVertexIndex(starting_vertex);
    int ending_vertex_index = GetVertexIndex(ending_vertex);
    if (starting_vertex_index < 0 || ending_vertex_index < 0) {
        return false;
    }

    // 1.2 检查边
    // 遍历edges_, 检查是否能找到待删除边
    int remove_edge_index = -1;
    if (this->type_ == Graph<TVertex, TWeight>::DIRECTED) {
        for (int i = 0; i < this->edges_.size(); i++) {
            if (this->edges_[i].starting_vertex == starting_vertex && this->edges_[i].ending_vertex == ending_vertex) {
                remove_edge_index = i;
                break;
            }
        }
    } else if (this->type_ == Graph<TVertex, TWeight>::UNDIRECTED) {
        for (int i = 0; i < this->edges_.size(); i++) {
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

    // 1.3 检查邻接矩阵
    // 如果没有此边, 则不能删除
    TWeight weight;
    bool res = GetWeight(starting_vertex, ending_vertex, weight);
    if (!res) {
        return false;
    }

    if (this->type_ == Graph<TVertex, TWeight>::UNDIRECTED) {
        res = GetWeight(ending_vertex, starting_vertex, weight);
        if (!res) {
            return false;
        }
    }

    /// ------ 2 在edges和邻接表做删除 ------\n
    /// 2.1 starting_vertex --> ending_vertex 做删除
    // 邻接矩阵内删除
    this->adjacency_matrix_[starting_vertex_index][ending_vertex_index] = TWeight();
    // edges_内删除
    this->edges_.erase(this->edges_.begin() + remove_edge_index);

    // 2.1 无向(图/网), 增加 ending_vertex --> starting_vertex 做删除
    if (this->type_ == Graph<TVertex, TWeight>::UNDIRECTED) {
        // 邻接矩阵内删除
        this->adjacency_matrix_[ending_vertex_index][starting_vertex_index] = TWeight();
    }

    /// ------ 3 edge_count_调整 ------\n
    this->edge_count_--;

    return true;
}


/*!
 * @brief **重载>>**
 * @tparam TVertex 结点模板参数
 * @tparam TWeight 边权值模板参数
 * @param out 输入流
 * @param graph 图
 * @return 输入流
 * @note
 * 重载>>
 * -----
 * -----
 *
 * <span style="color:#DF5A00">
 * 请各位根据自己的设计, 自行实现:-)
 * </span>
 *
 * -----
 */
template<typename TVertex, typename TWeight>
istream& operator>>(istream& in, MatrixGraph<TVertex, TWeight>& graph) {
    // todo: 根据自己的想法, 自行实现
    return in;
}


/*!
 * @brief **重载&lt;&lt;**
 * @tparam TVertex 结点模板参数
 * @tparam TWeight 边权值模板参数
 * @param out 输出流
 * @param graph 图
 * @return 输出流
 * @note
 * 重载<<
 * -----
 * -----
 *
 * <span style="color:#DF5A00">
 * 电子文档并没有节省纸, 反而增加了纸张的消耗\n
 * 因为人们习惯于把文档打印在纸上:-(
 * </span>
 *
 * -----
 * ###1 打印图的各种信息###
 * ###2 打印邻接矩阵信息###
 */
template<typename TVertex, typename TWeight>
ostream& operator<<(ostream& out, MatrixGraph<TVertex, TWeight>& graph) {

    // ---------- 1 打印图的各种信息 ----------
    out << "--- 基本信息 ---" << endl;
    out << "结点数量: " << graph.VertexCount() << endl;

    for (int i = 0; i < graph.VertexCount(); i++) {
        TVertex vertex;
        graph.GetVertexByIndex(i, vertex);
        out << vertex << " ";
    }
    cout << endl << endl;
    out << "边数量: " << graph.EdgeCount() << endl;

    for (int i = 0; i < graph.EdgeCount(); i++) {
        Edge<TVertex, TWeight> edge = graph.GetEdge(i);
        out << "(" << edge.starting_vertex << ", " << edge.ending_vertex << "), 权重: " << edge.weight << endl;
    }
    cout << endl;

    // ---------- 2 打印邻接矩阵信息 ----------
    out << "--- 邻接矩阵信息 ---" << endl;
    for (int row = 0; row < graph.VertexCount(); row++) {
        for (int col = 0; col < graph.VertexCount(); col++) {

            TWeight weight;
            bool res = graph.GetWeightByVertexIndex(row, col, weight);
            if (!res) {
                continue;
            }

            out << "[" << row << "][" << col << "]: " << weight << endl;
        }
    }

    return out;
}


/*!
 * @brief **获取结点索引**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param vertex 结点
 * @return 索引值
 * @note
 * 获取结点索引
 * ----------
 * ----------
 *
 * ----------
 */
template<typename TVertex, typename TWeight>
int MatrixGraph<TVertex, TWeight>::GetVertexIndex(const TVertex& vertex) const {
    for (int i = 0; i < this->vertex_count_; i++) {
        if (this->vertices_[i] == vertex) {
            return i;
        }
    }

    return -1;
}


/*!
 * @brief **打印图邻接矩阵**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @note
 * 打印图邻接矩阵
 * ------------
 * ------------
 *
 * ------------
 */
template<typename TVertex, typename TWeight>
void MatrixGraph<TVertex, TWeight>::PrintMatrix() {
    for (int row = 0; row < this->vertex_count_; row++) {
        for (int col = 0; col < this->vertex_count_; col++) {
            cout << setw(5) << this->adjacency_matrix_[row][col] << "  ";
        }
        cout<<endl;
    }
}


#endif // CYBER_DASH_MATRIX_GRAPH_H
