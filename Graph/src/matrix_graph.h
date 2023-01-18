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
 * ---------------------------
 * ---------------------------
 *
 * <span style="color:#DF5A00">
 * 听过的风, 走过的路
 * </span>
 *
 * ---------------------------
 * + **1** 设置部分成员变量\n
 *  - type_(**图类型**)设为UNDIRECTED(**无向**)\n
 *  - max_vertex_count_(**结点数上限**)和max_weight_(**边权值上限**)使用参数赋值\n
 *  - vertex_count_(**结点数量**)和edge_count_(**边数量**)设为0\n
 * + **2** 设置邻接矩阵\n
 *  - **2.1** 分配邻接矩阵行内存\n
 *  **if** 内存分配失败 :\n
 *  &emsp; 抛出bad_alloc()错误\n
 *  - **2.2** 分配邻接矩阵每行的内存, 并初始化\n
 *  **for loop** 遍历adjacency_matrix_ :\n
 *  &emsp; 分配矩阵当前行的内存\n
 *  &emsp; **if** 内存分配失败 :\n
 *  &emsp;&emsp; 抛出bad_alloc()错误\n
 *  &emsp; **for loop** 遍历当前行 :\n
 *  &emsp;&emsp; 对当前矩阵元素adjacency_matrix_[row][col]初始化\n
 */
template<typename TVertex, typename TWeight>
MatrixGraph<TVertex, TWeight>::MatrixGraph(int max_vertex_count, TWeight max_weight) {

    // ---------- 1 设置部分成员变量 ----------

    // type_(**图类型**)设为UNDIRECTED(**无向**)
    this->type_ = Graph<TVertex, TWeight>::UNDIRECTED;

    // max_vertex_count_(**结点数上限**)和max_weight_(**边权值上限**)使用参数赋值
    this->max_weight_ = max_weight;
    this->max_vertex_count_ = max_vertex_count;

    // vertex_count_(**结点数量**)和edge_count_(**边数量**)设为0
    this->vertex_count_ = 0;
    this->edge_count_ = 0;

    // ---------- 2 设置邻接矩阵 ----------

    // 2.1 分配邻接矩阵行内存
    this->adjacency_matrix_ = new TWeight*[this->max_vertex_count_];
    if (!this->adjacency_matrix_) {     //if 内存分配失败
        throw bad_alloc();              // 抛出bad_alloc()错误
    }

    // 2.2 分配邻接矩阵每行的内存, 并初始化
    for (int row = 0; row < this->max_vertex_count_; row++) {   // for loop 遍历adjacency_matrix_
        this->adjacency_matrix_[row] = new TWeight[this->max_vertex_count_];    // 分配矩阵当前行的内存
        if (!this->adjacency_matrix_[row]) {                                    // if 内存分配失败
            throw bad_alloc();                                                  // 抛出bad_alloc()错误
        }

        for (int col = 0; col < this->max_vertex_count_; col++) {   // for loop 遍历当前行
            this->adjacency_matrix_[row][col] = TWeight();          // 对当前矩阵元素adjacency_matrix_[row][col]初始化
        }
    }
}


/*!
 * @brief **构造函数(图类型/结点数上限/边权值上限)**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param type 图类型
 * @param max_vertex_count 结点数上限
 * @param max_weight 边权值上限
 * @note
 * 构造函数(图类型/结点数上限/边权值上限)
 * ---------------------------------
 * ---------------------------------
 *
 * ---------------------------------
 * + **1** 设置部分成员变量\n
 *  - type_(**图类型**)和max_vertex_count_(**结点数上限**)和max_weight_(**边权值上限**)使用参数赋值\n
 *  - vertex_count_(**结点数量**)和edge_count_(**边数量**)设为0\n
 * + **2** 设置邻接矩阵\n
 *  - **2.1** 分配邻接矩阵行内存\n
 *  **if** 内存分配失败 :\n
 *  &emsp; 抛出bad_alloc()错误\n
 *  - **2.2** 分配邻接矩阵每行的内存, 并初始化\n
 *  **for loop** 遍历adjacency_matrix_ :\n
 *  &emsp; 分配矩阵当前行的内存\n
 *  &emsp; **if** 内存分配失败 :\n
 *  &emsp;&emsp; 抛出bad_alloc()错误\n
 *  &emsp; **for loop** 遍历当前行 :\n
 *  &emsp;&emsp; 对当前矩阵元素adjacency_matrix_[row][col]初始化\n
 */
template<typename TVertex, typename TWeight>
MatrixGraph<TVertex, TWeight>::MatrixGraph(int type, int max_vertex_count, TWeight max_weight) {

    // ---------- 1 设置部分成员变量 ----------

    // type_(**图类型**)和max_vertex_count_(**结点数上限**)和max_weight_(**边权值上限**)使用参数赋值
    this->type_ = type;
    this->max_weight_ = max_weight;
    this->max_vertex_count_ = max_vertex_count;

    this->vertex_count_ = 0;
    this->edge_count_ = 0;

    // ---------- 2 设置邻接矩阵 ----------

    // 2.1 分配邻接矩阵行内存
    this->adjacency_matrix_ = new TWeight*[this->max_vertex_count_];
    if (!this->adjacency_matrix_) {     //if 内存分配失败
        throw bad_alloc();              // 抛出bad_alloc()错误
    }

    // 2.2 分配邻接矩阵每行的内存, 并初始化
    for (int row = 0; row < this->max_vertex_count_; row++) {   // for loop 遍历adjacency_matrix_
        this->adjacency_matrix_[row] = new TWeight[this->max_vertex_count_];    // 分配矩阵当前行的内存
        if (!this->adjacency_matrix_[row]) {                                    // if 内存分配失败
            throw bad_alloc();                                                  // 抛出bad_alloc()错误
        }

        for (int col = 0; col < this->max_vertex_count_; col++) {   // for loop 遍历当前行
            this->adjacency_matrix_[row][col] = TWeight();          // 对当前矩阵元素adjacency_matrix_[row][col]初始化
        }
    }
}

/*!
 * @brief **构造函数(结点数上限/边权值上限/边/结点vector)**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param max_vertex_count 结点数上限
 * @param max_weight 边权值上限
 * @param edges 边vector
 * @param vertices 结点vector
 * @note
 * 构造函数(结点数上限/边权值上限/边/结点vector)
 * ----------------------------------------
 * ----------------------------------------
 *
 * ----------------------------------------
 * + **1** 设置部分成员变量\n
 *  - type_(**图类型**)和max_vertex_count_(**结点数上限**)和max_weight_(**边权值上限**)使用参数赋值\n
 *  - vertex_count_(**结点数量**)和edge_count_(**边数量**)设为0\n
 * + **2** 设置邻接矩阵\n
 *  - **2.1** 分配邻接矩阵行内存\n
 *  **if** 内存分配失败 :\n
 *  &emsp; 抛出bad_alloc()错误\n
 *  - **2.2** 分配邻接矩阵每行的内存, 并初始化\n
 *  **for loop** 遍历adjacency_matrix_ :\n
 *  &emsp; 分配矩阵当前行的内存\n
 *  &emsp; **if** 内存分配失败 :\n
 *  &emsp;&emsp; 抛出bad_alloc()错误\n
 *  &emsp; **for loop** 遍历当前行 :\n
 *  &emsp;&emsp; 对当前矩阵元素adjacency_matrix_[row][col]初始化\n
 * + **3** 插入结点和边\n
 *  - **3.1** 使用vertices插入结点\n
 *  **for loop** 遍历vertices :\n
 *  &emsp; 调用InsertVertex, 插入当前节点vertices[i]\n
 *  - **3.2** 使用edges插入边\n
 *  **for loop** 遍历vertices :\n
 *  &emsp; 调用InsertEdge, 插入当前边edges[i]\n
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
    // 2.1 分配邻接矩阵行内存
    this->adjacency_matrix_ = new TWeight*[this->max_vertex_count_];
    if (!this->adjacency_matrix_) {
        throw bad_alloc();
    }

    // 2.2 分配邻接矩阵每行的内存, 并初始化
    for (int row = 0; row < this->max_vertex_count_; row++) {
        this->adjacency_matrix_[row] = new TWeight[this->max_vertex_count_]; // 节点i对应的所有边
        if (!this->adjacency_matrix_) {
            throw bad_alloc();
        }

        for (int col = 0; col < this->max_vertex_count_; col++) {
            this->adjacency_matrix_[row][col] = TWeight();
        }
    }

    // ---------- 3 插入结点和边----------
    // 3.1 将vertices插入
    for (unsigned int i = 0; i < vertices.size(); i++) {
        this->InsertVertex(vertices[i]);
    }

    // 3.1 将edges插入
    for (unsigned int i = 0; i < edges.size(); i++) {
        this->InsertEdge(edges[i].starting_vertex, edges[i].ending_vertex, edges[i].weight);
    }
}


/*!
 * @brief **构造函数(图类型/结点数上限/边权值上限/边/结点vector)**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param type 图类型
 * @param max_vertex_count 结点数上限
 * @param max_weight 边权值上限
 * @param edges 边vector
 * @param vertices 结点vector
 * @note
 * 构造函数(图类型/结点数上限/边权值上限/边/结点vector)
 * ----------------------------------------------
 * ----------------------------------------------
 *
 * <span style="color:#DF5A00">
 * 听过的风, 走过的路\n
 * 爱过的人, 闯过的祸
 * </span>
 *
 * ----------------------------------------------
 * + **1** 设置部分成员变量\n
 *  - type_(**图类型**)设为UNDIRECTED(**无向**)\n
 *  - max_vertex_count_(**结点数上限**)和max_weight_(**边权值上限**)使用参数赋值\n
 *  - vertex_count_(**结点数量**)和edge_count_(**边数量**)设为0\n
 * + **2** 设置邻接矩阵\n
 *  - **2.1** 分配邻接矩阵行内存\n
 *  **if** 内存分配失败 :\n
 *  &emsp; 抛出bad_alloc()错误\n
 *  - **2.2** 分配邻接矩阵每行的内存, 并初始化\n
 *  **for loop** 遍历adjacency_matrix_ :\n
 *  &emsp; 分配矩阵当前行的内存\n
 *  &emsp; **if** 内存分配失败 :\n
 *  &emsp;&emsp; 抛出bad_alloc()错误\n
 *  &emsp; **for loop** 遍历当前行 :\n
 *  &emsp;&emsp; 对当前矩阵元素adjacency_matrix_[row][col]初始化\n
 * + **3** 插入结点和边\n
 *  - **3.1** 使用vertices插入结点\n
 *  **for loop** 遍历vertices :\n
 *  &emsp; 调用InsertVertex, 插入当前节点vertices[i]\n
 *  - **3.2** 使用edges插入边\n
 *  **for loop** 遍历vertices :\n
 *  &emsp; 调用InsertEdge, 插入当前边edges[i]\n
 */
template<typename TVertex, typename TWeight>
MatrixGraph<TVertex, TWeight>::MatrixGraph(int type,
                                           int max_vertex_count,
                                           TWeight max_weight,
                                           const vector<Edge<TVertex, TWeight> >& edges,
                                           const vector<TVertex>& vertices)
{
    // ---------- 1 设置部分成员变量 ----------
    this->type_ = type;
    this->max_weight_ = max_weight;
    this->max_vertex_count_ = max_vertex_count;

    this->vertex_count_ = 0;
    this->edge_count_ = 0;


    // ---------- 2 设置邻接矩阵 ----------
    // 2.1 分配邻接矩阵行内存
    this->adjacency_matrix_ = new TWeight*[this->max_vertex_count_];
    if (!this->adjacency_matrix_) {
        throw bad_alloc();
    }

    // 2.2 分配邻接矩阵每行的内存, 并初始化
    for (int row = 0; row < this->max_vertex_count_; row++) {
        this->adjacency_matrix_[row] = new TWeight[this->max_vertex_count_]; // 节点i对应的所有边
        if (!this->adjacency_matrix_) {
            throw bad_alloc();
        }

        for (int col = 0; col < this->max_vertex_count_; col++) {
            this->adjacency_matrix_[row][col] = TWeight();
        }
    }

    // ---------- 3 插入结点和边----------
    // 3.1 将vertices插入
    for (unsigned int i = 0; i < vertices.size(); i++) {
        this->InsertVertex(vertices[i]);
    }

    // 3.1 将edges插入
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
 * - **1** 释放邻接矩阵的每行的内存\n
 * **for loop** 遍历adjacency_matrix_各行 :\n
 * &emsp; delete[]当前行\n
 * - **2** 释放邻接矩阵行内存\n
 * delete[] adjacency_matrix_\n
 */
template<typename TVertex, typename TWeight>
MatrixGraph<TVertex, TWeight>::~MatrixGraph() {
    // ---------- 1 释放邻接矩阵的每行的内存 ----------
    for (int row = 0; row < this->vertex_count_; row++) {
        delete[] this->adjacency_matrix_[row];
    }

    // ---------- 2 释放邻接矩阵行内存 ----------
    delete[] this->adjacency_matrix_;
}


/*!
 * @brief **获取结点(by结点索引)**
 * @param vertex_index 结点索引
 * @param vertex 结点保存变量
 * @return 执行结果
 * @note
 * 获取结点(by结点索引)
 * -----------------
 * -----------------
 *
 * -----------------
 * - **1** 判断合法性\n
 * **if** 结点索引 < 0 或者 结点索引 >= 图结点数 :\n
 * &emsp; 返回false\n
 * - **2** 获取结点\n
 * vertices_[vertex_index]赋给参数vertex\n
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
 * 对于无向图, 起点/终点只是为了表达需要, 并不表示方向
 *
 * ----------------
 * - **1** 判断合法性\n
 * 获取起点索引starting_vertex_index\n
 * 获取终点索引starting_vertex_index\n
 * **if** 起点索引 < 0 || 终点索引 < 0 || 起点索引等于终点索引 || 邻接矩阵内对应元素为初始值 :\n
 * &emsp; 返回false\n
 * - **2** 获取边权值\n
 * 调用GetWeightByVertexIndex\n
 * **if** 执行结果为false :\n
 * &emsp; 返回false\n
 */
template<typename TVertex, typename TWeight>
bool MatrixGraph<TVertex, TWeight>::GetWeight(const TVertex& starting_vertex,
                                              const TVertex& ending_vertex,
                                              TWeight& weight) const
{
    int starting_vertex_index = GetVertexIndex(starting_vertex);
    int ending_vertex_index = GetVertexIndex(ending_vertex);
    if (starting_vertex_index < 0 || ending_vertex_index < 0 || starting_vertex_index == ending_vertex_index ||
        adjacency_matrix_[starting_vertex_index][ending_vertex_index] == TWeight())
    {
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
 * @param starting_vertex_index 起点索引
 * @param ending_vertex_index 终点索引
 * @param weight 边权值保存遍历
 * @return 执行结果
 * @note
 * 获取边权值(by结点索引)
 * -------------------
 * -------------------
 *
 * -------------------
 * - **1** 判断合法性\n
 * **if** 起点索引 < 0 || 终点索引 < 0 || 起点索引等于终点索引 || 邻接矩阵内对应元素为初始值 :\n
 * - **2** 获取边权值\n
 * adjacency_matrix_[starting_vertex_index][ending_vertex_index]赋给参数weight\n
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
 * @brief **获取结点的第一个相邻结点**
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
 * - **1** 判断合法性\n
 * 获取结点的索引\n
 * **if** 结点索引 < 0 :\n
 * &emsp; 返回false\n
 * - **2** 遍历结点找到第一个相邻结点\n
 * **for loop** 遍历结点 :\n
 * &emsp; 获取当前索引(i)对应的结点\n
 * &emsp; **if** 当前索引无对应结点 :\n
 * &emsp;&emsp; continue\n
 * &emsp; 获取 结点--->当前结点 的边权值\n
 * &emsp; **if** 边权值存在(边存在) :\n
 * &emsp;&emsp; 当前结点赋给参数first_neighbor\n
 * &emsp;&emsp; 返回true
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
 * @brief **获取结点相对于某一相邻结点的下一个相邻结点**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param vertex 结点
 * @param neighbor_vertex 某相邻结点
 * @param next_neighbor_vertex 下一相邻结点保存变量
 * @return 执行结果
 * @note
 * 获取结点相对于某一相邻结点的下一个相邻结点
 * -----------------------------------
 * -----------------------------------
 *
 * -----------------------------------
 * - **1** 判断合法性\n
 * 获取结点的索引\n
 * 获取相邻某结点的索引\n
 * **if** 结点索引 < 0 || 某相邻结点索引 < 0 :\n
 * &emsp; 返回false\n
 * - **2** 遍历结点找到下一个相邻结点\n
 * **for loop** 遍历结点索引, 从neighbor_vertex_index到vertex_count_(不包含) :\n
 * &emsp; 获取当前索引(i)对应的结点\n
 * &emsp; **if** 当前索引无对应结点 :\n
 * &emsp;&emsp; continue\n
 * &emsp; 获取 结点--->当前结点 的边权值\n
 * &emsp; **if** 边权值存在(边存在) :\n
 * &emsp;&emsp; 当前结点赋给参数next_neighbor_vertex\n
 * &emsp;&emsp; 返回true\n
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
 * @brief **插入结点**
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
 * - **1** 判断合法性\n
 * **if** 结点数 >= 结点数上限 :\n
 * &emsp; 返回false\n
 * - **2** 执行插入\n
 * &emsp; vertices_插入结点\n
 * &emsp; vertex_count_加1\n
 */
template<typename TVertex, typename TWeight>
bool MatrixGraph<TVertex, TWeight>::InsertVertex(const TVertex& vertex) {

    // ---------- 1 判断合法性 ----------

    if (this->vertex_count_ >= this->max_vertex_count_) {   // if 结点数 >= 结点数上限
        return false;                                       // 返回false
    }

    // ---------- 2 执行插入 ----------

    this->vertices_.push_back(vertex);  // vertices_插入结点
    this->vertex_count_++;              // vertex_count_加1

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
 * + **1** 检查插入合法性\n
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
 *  - **1.2** 边检查\n
 *  &emsp; **for loop** 遍历edges_ :\n
 *  &emsp;&emsp; **if** 无向图 :\n
 *  &emsp;&emsp;&emsp; **if** 边(起点--->终点) or 反向边(终点--->起点) 存在 :\n
 *  &emsp;&emsp;&emsp;&emsp; 返回false\n
 *  &emsp;&emsp; **if** 有向图 :\n
 *  &emsp;&emsp;&emsp; **if** 边(起点--->终点) 存在 :\n
 *  &emsp;&emsp;&emsp;&emsp; 返回false\n
 *  - **1.3** 邻接矩阵检查\n
 *  &emsp; **if** 无向图 :\n
 *  &emsp;&emsp; **if** 邻接矩阵内存在该边or反向边 :\n
 *  &emsp;&emsp;&emsp; 返回false;\n
 *  &emsp; **else if** 有向图 :\n
 *  &emsp;&emsp; **if** 邻接矩阵内存在该边 :\n
 *  &emsp;&emsp;&emsp; 返回false;\n
 * + **2** 执行插入\n
 *  - **2.1** 该边插入\n
 *   * 插入邻接矩阵\n
 *   * 插入edges_\n
 *  - **2.2** 无向图处理\n
 *  &emsp; **if** 无向图 :\n
 *  &emsp;&emsp; 反向边插入邻接矩阵\n
 *  - **2.3** edge_count_(边数)加1\n
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

    // 2.3 edge_count_加1
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
 * 除了删除结点, 还要删除该结点作为起点/终点的每条边
 * </span>
 *
 * -------
 * + **1 判断删除合理性**\n
 * &emsp; 获取待删除结点的索引\n
 * &emsp; **if** 结点索引 < 0 or 结点索引 >= vertex_count_ :\n
 * &emsp;&emsp; 返回false\n
 * + **2 邻接矩阵执行删除**\n
 * &emsp; (用索引vertex_count_ - 1结点, 替换待删除结点)\n
 * &emsp; **for loop** 遍历结点索引 :\n
 * &emsp;&emsp; 将邻接矩阵位置[i][vertex_index]的元素, 替换为位置[i][vertex_count_ - 1]的元素\n
 * &emsp;&emsp; 将邻接矩阵位置[vertex_index][i]的元素, 替换为位置[vertex_count_ - 1][i]的元素\n
 * + **3 edges_执行删除**\n
 * &emsp; **for loop** 遍历edges_ :\n
 * &emsp;&emsp; **if** 当前边起点or当前边终点 为待删除节点 :\n
 * &emsp;&emsp;&emsp; 删除当前边\n
 * &emsp;&emsp;&emsp; edge_count_(边数)减1\n
 * + **4 vertices_执行删除**\n
 * &emsp; vertices_的索引vertex_index位置元素, 替换为索引vertex_count_ - 1位置元素\n
 * &emsp; vertices_删除索引vertex_count - 1位置元素\n
 * + **5 vertex_count_(结点数)减1**\n
 * &emsp; **注意**: 通过此操作, 缩小了邻接矩阵的访问范围, 等于对邻接矩阵做了删除相关的操作\n
 */
template<typename TVertex, typename TWeight>
bool MatrixGraph<TVertex, TWeight>::RemoveVertex(const TVertex& vertex) {

    // ---------- 1 判断删除合理性 ----------
    int vertex_index = GetVertexIndex(vertex);                      // 获取待删除结点的索引
    if (vertex_index < 0 || vertex_index >= this->vertex_count_) {  // if 结点索引 < 0 or 结点索引 >= vertex_count_
        return false;                                               // 返回false
    }

    // ---------- 2 邻接矩阵执行删除 ----------
    // (用索引vertex_count_ - 1结点, 替换待删除结点)
    for (int i = 0; i < this->vertex_count_; i++) {     // for loop 遍历结点索引
        // 将邻接矩阵位置[i][vertex_index]的元素, 替换为位置[i][vertex_count_ - 1]的元素
        this->adjacency_matrix_[i][vertex_index] = this->adjacency_matrix_[i][this->vertex_count_ - 1];
        // 将邻接矩阵位置[vertex_index][i]的元素, 替换为位置[vertex_count_ - 1][i]的元素
        this->adjacency_matrix_[vertex_index][i] = this->adjacency_matrix_[this->vertex_count_ - 1][i];
    }

    // ---------- 3 edges_执行删除 ----------
    // for loop 遍历edges_
    for (typename vector<Edge<TVertex, TWeight> >::iterator iter = this->edges_.begin(); iter != this->edges_.end();) {
        if (iter->ending_vertex == vertex || iter->starting_vertex == vertex) { // if 当前边起点or当前边终点 为待删除节点
            iter = this->edges_.erase(iter);                                    // 删除当前边
            this->edge_count_--;                                                // edge_count_(边数)减1
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
    // 注意: 通过此操作, 缩小了邻接矩阵的访问范围, 等于对邻接矩阵做了删除相关的操作
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
 * + **1 检查合法性**\n
 *  - **1.1 检查结点**\n
 *  &emsp; 获取起点索引and终点索引\n
 *  &emsp; **if** 起点索引 < 0 || 终点索引 < 0 :\n
 *  &emsp;&emsp; 返回false\n
 *  - **1.2 检查边**\n
 *  &emsp; 待删除边索引变量remove_edge_index, 初始化为-1\n
 *  &emsp; **if** 有向图 :\n
 *  &emsp;&emsp; **for loop** 遍历edges_ :\n
 *  &emsp;&emsp;&emsp; **if** this->edges_[i](当前边)的起点和结点, 与参数起点和结点相同 :\n
 *  &emsp;&emsp;&emsp;&emsp; 将i(当前边索引)赋给remove_edge_index\n
 *  &emsp;&emsp;&emsp;&emsp; break(找到待删除边, 结束循环);\n
 *  &emsp; **else if** 无向图 :\n
 *  &emsp;&emsp; **for loop** 遍历edges_ :\n
 *  &emsp;&emsp;&emsp; **if** this->edges_[i](当前边)或者反向边的起点和结点, 与参数起点和结点相同 :\n
 *  &emsp;&emsp;&emsp;&emsp; 将i(当前边索引)赋给remove_edge_index\n
 *  &emsp;&emsp;&emsp;&emsp; break(找到待删除边, 结束循环);\n
 *  &emsp; **if** remove_edge_index为-1(说明没有找到待删除边) :\n
 *  &emsp;&emsp; 返回false\n
 *  - **1.3 检查邻接矩阵**\n
 *   * 检查 边(starting_vertex ---> ending_vertex) :\n
 *   &emsp; 调用GetWeight读取临界数组中的边信息\n
 *   &emsp; **if** GetWeight返回false :\n
 *   &emsp;&emsp; 返回false\n
 *   * 如果无向图, 检查 边(starting_vertex ---> ending_vertex) :\n
 *   &emsp;**if** 无向图: \n
 *   &emsp;&emsp; 调用GetWeight读取临界数组中的边信息\n
 *   &emsp;&emsp; **if** GetWeight返回false :\n
 *   &emsp;&emsp;&emsp; 返回false\n
 * + **2 edges_和邻接矩阵执行删除**\n
 *  - 2.1 (起点 ---> 终点)方向删除\n
 *   * 邻接矩阵内删除\n
 *   * edges_内删除\n
 *  - 2.2 无向图 (终点 ---> 起点)方向删除\n
 *  &emsp; **if** 无向图 :\n
 *  &emsp;&emsp; 邻接矩阵内删除反向边\n
 * + **3 edge_count_(边数)减1**\n
 */
template<typename TVertex, typename TWeight>
bool MatrixGraph<TVertex, TWeight>::RemoveEdge(const TVertex& starting_vertex, const TVertex& ending_vertex) {

    // ---------- 1 检查合法性 ----------

    // 1.1 检查结点
    // 获取起点索引and终点索引
    int starting_vertex_index = GetVertexIndex(starting_vertex);
    int ending_vertex_index = GetVertexIndex(ending_vertex);
    if (starting_vertex_index < 0 || ending_vertex_index < 0) {     // if 起点索引 < 0 || 终点索引 < 0
        return false;                                               // 返回false
    }

    // 1.2 检查边
    int remove_edge_index = -1;     // 待删除边索引变量remove_edge_index, 初始化为-1
    if (this->type_ == Graph<TVertex, TWeight>::DIRECTED) {             // if 有向图
        for (unsigned int i = 0; i < this->edges_.size(); i++) {                 // for loop 遍历edges_
            // if this->edges_[i](当前边)的起点和结点, 与参数起点和结点相同
            if (this->edges_[i].starting_vertex == starting_vertex && this->edges_[i].ending_vertex == ending_vertex) {
                remove_edge_index = i;      // 将i(当前边索引)赋给remove_edge_index
                break;                      // break(找到待删除边, 结束循环)
            }
        }
    } else if (this->type_ == Graph<TVertex, TWeight>::UNDIRECTED) {    // else if 无向图
        for (unsigned int i = 0; i < this->edges_.size(); i++) {                 // for loop 遍历edges_
            // if this->edges_[i](当前边)或者反向边的起点和结点, 与参数起点和结点相同
            if ((this->edges_[i].starting_vertex == starting_vertex && this->edges_[i].ending_vertex == ending_vertex) ||
                (this->edges_[i].starting_vertex == ending_vertex && this->edges_[i].ending_vertex == starting_vertex))
            {
                remove_edge_index = i;      // 将i(当前边索引)赋给remove_edge_index
                break;                      // break(找到待删除边, 结束循环)
            }
        }
    }

    if (remove_edge_index == -1) {  // if remove_edge_index为-1(说明没有找到待删除边)
        return false;               // 返回false
    }

    // 1.3 检查邻接矩阵
    // 检查 边(starting_vertex ---> ending_vertex)
    TWeight weight;
    bool res = GetWeight(starting_vertex, ending_vertex, weight);   // 调用GetWeight读取临界数组中的边信息
    if (!res) {                                                     // if GetWeight返回false
        return false;                                               // 返回false
    }

    // 如果无向图, 检查 边(starting_vertex ---> ending_vertex)
    if (this->type_ == Graph<TVertex, TWeight>::UNDIRECTED) {       // if 无向图
        res = GetWeight(ending_vertex, starting_vertex, weight);    // 调用GetWeight读取临界数组中的边信息
        if (!res) {                                                 // if GetWeight返回false
            return false;                                           // 返回false
        }
    }

    // ------ 2 在edges和邻接矩阵做删除 ------

    // 2.1 (起点 ---> 终点)方向删除
    this->adjacency_matrix_[starting_vertex_index][ending_vertex_index] = TWeight();        // 邻接矩阵内删除
    this->edges_.erase(this->edges_.begin() + remove_edge_index);                           // edges_内删除

    // 2.2 无向图 (终点 ---> 起点)方向删除
    if (this->type_ == Graph<TVertex, TWeight>::UNDIRECTED) {                               // if 无向图
        this->adjacency_matrix_[ending_vertex_index][starting_vertex_index] = TWeight();    // 邻接矩阵内删除反向边
    }

    // ----------- 3 edge_count_(边数)减1 ----------

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
    //  根据自己的想法, 自行实现
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
 * + **1 打印图的各种信息**\n
 *  - **1.1 打印结点信息**\n
 *  - **1.2 打印边信息**\n
 * + **2 打印邻接矩阵信息**\n
 */
template<typename TVertex, typename TWeight>
ostream& operator<<(ostream& out, MatrixGraph<TVertex, TWeight>& graph) {

    // ---------- 1 打印图的各种信息 ----------
    out << "--- 基本信息 ---" << endl;

    // 1.1 打印结点信息
    out << "结点数量: " << graph.VertexCount() << endl;
    for (unsigned int i = 0; i < graph.VertexCount(); i++) {
        TVertex vertex;
        graph.GetVertexByIndex(i, vertex);
        out << vertex << " ";
    }
    cout << endl << endl;

    // 1.2 打印边信息
    out << "边数量: " << graph.EdgeCount() << endl;
    for (unsigned int i = 0; i < graph.EdgeCount(); i++) {
        Edge<TVertex, TWeight> edge = graph.GetEdge(i);
        out << "(" << edge.starting_vertex << ", " << edge.ending_vertex << "), 权重: " << edge.weight << endl;
    }
    cout << endl;

    // ---------- 2 打印邻接矩阵信息 ----------
    out << "--- 邻接矩阵信息 ---" << endl;
    for (unsigned int row = 0; row < graph.VertexCount(); row++) {
        for (unsigned int col = 0; col < graph.VertexCount(); col++) {

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
 * **for loop** 遍历结点索引: \n
 * &emsp; **if** i(当前索引)对应的结点等于vertex :\n
 * &emsp;&emsp; 返回i\n
 * 返回-1(如果没有找到对应索引)\n
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
 * **for loop** 遍历行索引: \n
 * &emsp; **for loop** 遍历列索引:\n
 * &emsp;&emsp; 打印adjacency_matrix_[row][col](当前矩阵元素)\n
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
