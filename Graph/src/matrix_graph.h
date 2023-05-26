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

    // 构造函数(图类型/结点数上限/边权值上限)
    MatrixGraph(int type, int max_vertex_count, TWeight max_weight);

    // 构造函数(结点数上限/边权值上限/边vector/结点vector)
    MatrixGraph(int max_vertex_count,
                TWeight max_weight,
                const vector<Edge<TVertex, TWeight> >& edges,
                const vector<TVertex>& vertices);

    // 构造函数(图类型/结点数上限/边权值上限/边vector/结点vector)
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
 * @brief **构造函数(结点数上限, 边权值上限)**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param max_vertex_count 结点数上限
 * @param max_weight 边权值上限
 * @note
 * 构造函数(结点数上限, 边权值上限)
 * ---------------------------
 * ---------------------------
 *
 * <span style="color:#DF5A00">
 * 听过的风, 走过的路
 * </span>
 *
 * ---------------------------
 * + **1** 设置部分成员变量\n\n
 * type_(**图类型**)设为UNDIRECTED(**无向**)\n\n
 * max_vertex_count_(**结点数上限**)使用参数赋值\n
 * max_weight_(**边权值上限**)使用参数赋值\n\n
 * vertex_count_(**结点数量**)设为0\n
 * edge_count_(**边数量**)设为0\n\n
 * + **2** 设置邻接矩阵\n\n
 * <span style="color:#E76600;font-weight:bold">( 2.1 分配邻接矩阵内存 )</span>\n
 * adjacency_matrix_分配内存并初始化\n
 * **if** 内存分配失败 :\n
 * &emsp; 抛出bad_alloc()错误\n\n
 * <span style="color:#E76600;font-weight:bold">( 2.2 分配邻接矩阵每行的内存, 并初始化 )</span>\n
 * **for loop** 遍历adjacency_matrix_ :\n
 * &emsp; 分配矩阵当前行的内存\n
 * &emsp; **if** 内存分配失败 :\n
 * &emsp;&emsp; 抛出bad_alloc()错误\n
 * &emsp; **for loop** 遍历当前行 :\n
 * &emsp;&emsp; 对当前矩阵元素adjacency_matrix_[row][col]初始化\n
 */
template<typename TVertex, typename TWeight>
MatrixGraph<TVertex, TWeight>::MatrixGraph(int max_vertex_count, TWeight max_weight) {

    // ---------- 1 设置部分成员变量 ----------

    this->type_ = Graph<TVertex, TWeight>::UNDIRECTED;                                          // type_(图类型)设为UNDIRECTED(无向)

    this->max_weight_ = max_weight;                                                             // max_vertex_count_(结点数上限)使用参数赋值
    this->max_vertex_count_ = max_vertex_count;                                                 // max_weight_(边权值上限)使用参数赋值

    this->vertex_count_ = 0;                                                                    // vertex_count_(结点数量)设为0
    this->edge_count_ = 0;                                                                      // edge_count_(边数量)设为0

    // ---------- 2 设置邻接矩阵 ----------

    // ( 2.1 分配邻接矩阵内存 )
    this->adjacency_matrix_ = new TWeight*[this->max_vertex_count_];                            // adjacency_matrix_分配内存并初始化
    if (!this->adjacency_matrix_) {                                                             //if 内存分配失败
        throw bad_alloc();                                                                      // 抛出bad_alloc()错误
    }

    // ( 2.2 分配邻接矩阵每行的内存, 并初始化 )
    for (int row = 0; row < this->max_vertex_count_; row++) {                                   // for loop 遍历adjacency_matrix_
        this->adjacency_matrix_[row] = new TWeight[this->max_vertex_count_];                    // 分配矩阵当前行的内存
        if (!this->adjacency_matrix_[row]) {                                                    // if 内存分配失败
            throw bad_alloc();                                                                  // 抛出bad_alloc()错误
        }

        for (int col = 0; col < this->max_vertex_count_; col++) {                               // for loop 遍历当前行
            this->adjacency_matrix_[row][col] = TWeight();                                      // 对当前矩阵元素adjacency_matrix_[row][col]初始化
        }
    }
}


/*!
 * @brief **构造函数(图类型, 结点数上限, 边权值上限)**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param type 图类型
 * @param max_vertex_count 结点数上限
 * @param max_weight 边权值上限
 * @note
 * 构造函数(图类型, 结点数上限, 边权值上限)
 * ---------------------------------
 * ---------------------------------
 *
 * ---------------------------------
 * + **1** 设置部分成员变量\n\n
 * type_(**图类型**)使用参数赋值\n\n
 * max_vertex_count_(**结点数上限**)使用参数赋值\n
 * max_weight_(**边权值上限**)使用参数赋值\n\n
 * vertex_count_(**结点数量**)设为0\n
 * edge_count_(**边数量**)设为0\n\n
 * + **2** 设置邻接矩阵\n\n
 * <span style="color:#E76600;font-weight:bold">( 2.1 分配邻接矩阵内存 )</span>\n
 * adjacency_matrix_分配内存并初始化\n
 * **if** 内存分配失败 :\n
 * &emsp; 抛出bad_alloc()错误\n\n
 * <span style="color:#E76600;font-weight:bold">( 2.2 分配邻接矩阵每行的内存, 并初始化 )</span>\n
 * **for loop** 遍历adjacency_matrix_ :\n
 * &emsp; 分配矩阵当前行的内存\n
 * &emsp; **if** 内存分配失败 :\n
 * &emsp;&emsp; 抛出bad_alloc()错误\n
 * &emsp; **for loop** 遍历当前行 :\n
 * &emsp;&emsp; 对当前矩阵元素adjacency_matrix_[row][col]初始化\n
 */
template<typename TVertex, typename TWeight>
MatrixGraph<TVertex, TWeight>::MatrixGraph(int type, int max_vertex_count, TWeight max_weight) {

    // ---------- 1 设置部分成员变量 ----------

    this->type_ = type;                                                                         // type_(图类型)使用参数赋值

    this->max_weight_ = max_weight;                                                             // max_vertex_count_(结点数上限)使用参数赋值
    this->max_vertex_count_ = max_vertex_count;                                                 // max_weight_(边权值上限)使用参数赋值

    this->vertex_count_ = 0;                                                                    // vertex_count_(结点数量)设为0
    this->edge_count_ = 0;                                                                      // edge_count_(边数量)设为0

    // ---------- 2 设置邻接矩阵 ----------

    // ( 2.1 分配邻接矩阵内存 )
    this->adjacency_matrix_ = new TWeight*[this->max_vertex_count_];                            // adjacency_matrix_分配内存并初始化
    if (!this->adjacency_matrix_) {                                                             //if 内存分配失败
        throw bad_alloc();                                                                      // 抛出bad_alloc()错误
    }

    // ( 2.2 分配邻接矩阵每行的内存, 并初始化 )
    for (int row = 0; row < this->max_vertex_count_; row++) {                                   // for loop 遍历adjacency_matrix_
        this->adjacency_matrix_[row] = new TWeight[this->max_vertex_count_];                    // 分配矩阵当前行的内存
        if (!this->adjacency_matrix_[row]) {                                                    // if 内存分配失败
            throw bad_alloc();                                                                  // 抛出bad_alloc()错误
        }

        for (int col = 0; col < this->max_vertex_count_; col++) {                               // for loop 遍历当前行
            this->adjacency_matrix_[row][col] = TWeight();                                      // 对当前矩阵元素adjacency_matrix_[row][col]初始化
        }
    }
}


/*!
 * @brief **构造函数(结点数上限, 边权值上限, 边vector, 结点vector)**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param max_vertex_count 结点数上限
 * @param max_weight 边权值上限
 * @param edges 边vector
 * @param vertices 结点vector
 * @note
 * 构造函数(结点数上限, 边权值上限, 边vector, 结点vector)
 * ------------------------------------------------
 * ------------------------------------------------
 *
 * ------------------------------------------------
 * + **1** 设置部分成员变量\n
 * type_(**图类型**)设为UNDIRECTED(**无向**)\n\n
 * max_vertex_count_(**结点数上限**)使用参数赋值\n
 * max_weight_(**边权值上限**)使用参数赋值\n\n
 * vertex_count_(**结点数量**)设为0\n
 * edge_count_(**边数量**)设为0\n\n
 * + **2** 设置邻接矩阵\n\n
 * <span style="color:#E76600;font-weight:bold">( 2.1 分配邻接矩阵内存 )</span>\n
 * adjacency_matrix_分配内存并初始化\n
 * **if** 内存分配失败 :\n
 * &emsp; 抛出bad_alloc()错误\n\n
 * <span style="color:#E76600;font-weight:bold">( 2.2 分配邻接矩阵每行的内存, 并初始化 )</span>\n
 * **for loop** 遍历adjacency_matrix_ :\n
 * &emsp; 分配矩阵当前行的内存\n
 * &emsp; **if** 内存分配失败 :\n
 * &emsp;&emsp; 抛出bad_alloc()错误\n
 * &emsp; **for loop** 遍历当前行 :\n
 * &emsp;&emsp; 对当前矩阵元素adjacency_matrix_[row][col]初始化\n\n
 * + **3** 插入结点和边\n\n
 * ( 3.1 使用vertices插入结点 )\n
 * **for loop** 遍历vertices :\n
 * &emsp; 调用InsertVertex, 插入当前节点vertices[i]\n\n
 * ( 3.2 使用edges插入边 )\n
 * **for loop** 遍历vertices :\n
 * &emsp; 调用InsertEdge, 插入当前边edges[i]\n
 */
template<typename TVertex, typename TWeight>
MatrixGraph<TVertex, TWeight>::MatrixGraph(int max_vertex_count,
                                           TWeight max_weight,
                                           const vector<Edge<TVertex, TWeight> >& edges,
                                           const vector<TVertex>& vertices)
{
    // ---------- 1 设置部分成员变量 ----------

    this->type_ = Graph<TVertex, TWeight>::UNDIRECTED;                                          // type_(图类型)设为UNDIRECTED(无向)

    this->max_weight_ = max_weight;                                                             // max_vertex_count_(结点数上限)使用参数赋值
    this->max_vertex_count_ = max_vertex_count;                                                 // max_weight_(边权值上限)使用参数赋值

    this->vertex_count_ = 0;                                                                    // vertex_count_(结点数量)设为0
    this->edge_count_ = 0;                                                                      // edge_count_(边数量)设为0

    // ---------- 2 设置邻接矩阵 ----------

    // ( 2.1 分配邻接矩阵内存 )
    this->adjacency_matrix_ = new TWeight*[this->max_vertex_count_];                            // adjacency_matrix_分配内存并初始化
    if (!this->adjacency_matrix_) {                                                             //if 内存分配失败
        throw bad_alloc();                                                                      // 抛出bad_alloc()错误
    }

    // ( 2.2 分配邻接矩阵每行的内存, 并初始化 )
    for (int row = 0; row < this->max_vertex_count_; row++) {                                   // for loop 遍历adjacency_matrix_
        this->adjacency_matrix_[row] = new TWeight[this->max_vertex_count_];                    // 分配矩阵当前行的内存
        if (!this->adjacency_matrix_[row]) {                                                    // if 内存分配失败
            throw bad_alloc();                                                                  // 抛出bad_alloc()错误
        }

        for (int col = 0; col < this->max_vertex_count_; col++) {                               // for loop 遍历当前行
            this->adjacency_matrix_[row][col] = TWeight();                                      // 对当前矩阵元素adjacency_matrix_[row][col]初始化
        }
    }

    // ---------- 3 插入结点和边----------

    // ( 3.1 将vertices插入 )
    for (unsigned int i = 0; i < vertices.size(); i++) {                                        // for loop 遍历vertices
        this->InsertVertex(vertices[i]);                                                        // 调用InsertVertex, 插入当前节点vertices[i]
    }

    // ( 3.1 将edges插入 )
    for (unsigned int i = 0; i < edges.size(); i++) {                                           // for loop 遍历vertices
        this->InsertEdge(edges[i].starting_vertex, edges[i].ending_vertex, edges[i].weight);    // 调用InsertEdge, 插入当前边edges[i]
    }
}


/*!
 * @brief **构造函数(图类型, 结点数上限, 边权值上限, 边vector, 结点vector)**
 * @tparam TVertex 结点类型模板参数
 * @tparam TWeight 边权值类型模板参数
 * @param type 图类型
 * @param max_vertex_count 结点数上限
 * @param max_weight 边权值上限
 * @param edges 边vector
 * @param vertices 结点vector
 * @note
 * 构造函数(图类型/结点数上限/边权值上限/边vector/结点vector)
 * ----------------------------------------------
 * ----------------------------------------------
 *
 * <span style="color:#DF5A00">
 * 听过的风, 走过的路\n
 * 爱过的人, 闯过的祸\n
 * </span>
 *
 * ----------------------------------------------
 * + **1** 设置部分成员变量\n\n
 * type_(**图类型**)使用参数赋值\n\n
 * max_vertex_count_(**结点数上限**)使用参数赋值\n
 * max_weight_(**边权值上限**)使用参数赋值\n\n
 * vertex_count_(**结点数量**)设为0\n
 * edge_count_(**边数量**)设为0\n\n
 * + **2** 设置邻接矩阵\n\n
 * <span style="color:#E76600;font-weight:bold">( 2.1 分配邻接矩阵内存 )</span>\n
 * adjacency_matrix_分配内存并初始化\n
 * **if** 内存分配失败 :\n
 * &emsp; 抛出bad_alloc()错误\n\n
 * <span style="color:#E76600;font-weight:bold">( 2.2 分配邻接矩阵每行的内存, 并初始化 )</span>\n
 * **for loop** 遍历adjacency_matrix_ :\n
 * &emsp; 分配矩阵当前行的内存\n
 * &emsp; **if** 内存分配失败 :\n
 * &emsp;&emsp; 抛出bad_alloc()错误\n
 * &emsp; **for loop** 遍历当前行 :\n
 * &emsp;&emsp; 对当前矩阵元素adjacency_matrix_[row][col]初始化\n\n
 * + **3** 插入结点和边\n\n
 * ( 3.1 使用vertices插入结点 )\n
 * **for loop** 遍历vertices :\n
 * &emsp; 调用InsertVertex, 插入当前节点vertices[i]\n\n
 * ( 3.2 使用edges插入边 )\n
 * **for loop** 遍历vertices :\n
 * &emsp; 调用InsertEdge, 插入当前边edges[i]\n
 */
template<typename TVertex, typename TWeight>
MatrixGraph<TVertex, TWeight>::MatrixGraph(int type,
                                           int max_vertex_count,
                                           TWeight max_weight,
                                           const vector<Edge<TVertex, TWeight> >& edges,
                                           const vector<TVertex>& vertices)
{
    // ---------- 1 设置部分成员变量 ----------

    this->type_ = type;                                                                         // type_(图类型)使用参数赋值

    this->max_weight_ = max_weight;                                                             // max_vertex_count_(结点数上限)使用参数赋值
    this->max_vertex_count_ = max_vertex_count;                                                 // max_weight_(边权值上限)使用参数赋值

    this->vertex_count_ = 0;                                                                    // vertex_count_(结点数量)设为0
    this->edge_count_ = 0;                                                                      // edge_count_(边数量)设为0

    // ---------- 2 设置邻接矩阵 ----------

    // ( 2.1 分配邻接矩阵内存 )
    this->adjacency_matrix_ = new TWeight*[this->max_vertex_count_];                            // adjacency_matrix_分配内存并初始化
    if (!this->adjacency_matrix_) {                                                             //if 内存分配失败
        throw bad_alloc();                                                                      // 抛出bad_alloc()错误
    }

    // ( 2.2 分配邻接矩阵每行的内存, 并初始化 )
    for (int row = 0; row < this->max_vertex_count_; row++) {                                   // for loop 遍历adjacency_matrix_
        this->adjacency_matrix_[row] = new TWeight[this->max_vertex_count_];                    // 分配矩阵当前行的内存
        if (!this->adjacency_matrix_[row]) {                                                    // if 内存分配失败
            throw bad_alloc();                                                                  // 抛出bad_alloc()错误
        }

        for (int col = 0; col < this->max_vertex_count_; col++) {                               // for loop 遍历当前行
            this->adjacency_matrix_[row][col] = TWeight();                                      // 对当前矩阵元素adjacency_matrix_[row][col]初始化
        }
    }

    // ---------- 3 插入结点和边----------

    // ( 3.1 将vertices插入 )
    for (unsigned int i = 0; i < vertices.size(); i++) {                                        // for loop 遍历vertices
        this->InsertVertex(vertices[i]);                                                        // 调用InsertVertex, 插入当前节点vertices[i]
    }

    // ( 3.1 将edges插入 )
    for (unsigned int i = 0; i < edges.size(); i++) {                                           // for loop 遍历vertices
        this->InsertEdge(edges[i].starting_vertex, edges[i].ending_vertex, edges[i].weight);    // 调用InsertEdge, 插入当前边edges[i]
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
 * **for loop** 遍历adjacency_matrix_各行 :\n
 * &emsp; delete[]当前行\n
 * delete[] adjacency_matrix_\n
 */
template<typename TVertex, typename TWeight>
MatrixGraph<TVertex, TWeight>::~MatrixGraph() {
    for (int row = 0; row < this->vertex_count_; row++) {                                       // for loop 遍历adjacency_matrix_各行
        delete[] this->adjacency_matrix_[row];                                                  // delete[]当前行
    }

    delete[] this->adjacency_matrix_;                                                           // delete[] adjacency_matrix_
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

    // ---------- 1 判断合法性 ----------

    if (vertex_index < 0 && vertex_index >= this->vertex_count_) {  // if 结点索引 < 0 或者 结点索引 >= 图结点数
        return false;                                               // 返回false
    }

    // ---------- 2 获取结点 ----------

    vertex = this->vertices_[vertex_index];                         // vertices_[vertex_index]赋给参数vertex

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
 * 获取终点索引ending_vertex_index\n
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
    // ---------- 1 判断合法性 ----------

    int starting_vertex_index = GetVertexIndex(starting_vertex);    // 获取起点索引starting_vertex_index
    int ending_vertex_index = GetVertexIndex(ending_vertex);        // 获取终点索引ending_vertex_index

    // if 起点索引 < 0 || 终点索引 < 0 || 起点索引等于终点索引 || 邻接矩阵内对应元素为初始值 :
    if (starting_vertex_index < 0 || ending_vertex_index < 0 || starting_vertex_index == ending_vertex_index ||
        adjacency_matrix_[starting_vertex_index][ending_vertex_index] == TWeight())
    {
        return false;   // 返回false
    }

    // ---------- 2 获取边权值 ----------

    // 调用GetWeightByVertexIndex
    bool res = GetWeightByVertexIndex(starting_vertex_index, ending_vertex_index, weight);
    if (!res) {             // if 执行结果为false
        return false;       // 返回false
    }

    return true;
}


/*!
 * @brief **获取边权值(by结点索引)**
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
 * **if** 起点索引 < 0 <b>||</b> 终点索引 < 0 <b>||</b> 起点索引等于终点索引 <b>||</b> 起点索引 >= 结点数
 * <b>||</b> 终点索引 >= 结点数 <b>||</b> 邻接矩阵内对应元素为初始值 :\n
 * &emsp; 返回false\n
 * - **2** 获取边权值\n
 * adjacency_matrix_<b>[</b>starting_vertex_index<b>][</b>ending_vertex_index<b>]</b>赋给参数weight\n
 */
template<typename TVertex, typename TWeight>
bool MatrixGraph<TVertex, TWeight>::GetWeightByVertexIndex(int starting_vertex_index,
                                                           int ending_vertex_index,
                                                           TWeight& weight) const
{
    // ---------- 1 判断合法性 ----------

    // if 起点索引 < 0 || 终点索引 < 0 || 起点索引等于终点索引 || 起点索引 >= 结点数 || 终点索引 >= 结点数 || 邻接矩阵内对应元素为初始值
    if (starting_vertex_index < 0 || ending_vertex_index < 0 || starting_vertex_index == ending_vertex_index ||
        starting_vertex_index >= this->vertex_count_ || ending_vertex_index >= this->vertex_count_ ||
        adjacency_matrix_[starting_vertex_index][ending_vertex_index] == TWeight())
    {
        return false;   // 返回false
    }

    // ---------- 2 获取边权值 ----------

    // adjacency_matrix_[starting_vertex_index][ending_vertex_index]赋给参数weight
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
 * + **1 判断合法性**\n\n
 * 获取结点索引\n
 * **if** 结点索引 < 0 :\n
 * &emsp; 返回false\n\n
 * + **2 遍历找到第一个相邻结点**\n\n
 * **for loop** 遍历结点索引 :\n
 * &emsp; 声明weight(边权值)\n
 * &emsp; 声明cur_vertex(当前结点)\n\n
 * &emsp; 获取i(当前结点索引)对应的结点\n
 * &emsp; **if** 当前索引无对应结点 :\n
 * &emsp;&emsp; continue\n\n
 * &emsp; 获取邻接边(vertex ---> cur_vertex)的权值\n\n
 * &emsp; **if** weight存在(即边存在) :\n
 * &emsp;&emsp; cur_vertex赋给参数first_neighbor\n
 * &emsp;&emsp; 返回true\n\n
 * + **3 退出函数**\n\n
 * 返回false\n
 */
template<typename TVertex, typename TWeight>
bool MatrixGraph<TVertex, TWeight>::GetFirstNeighborVertex(const TVertex& vertex, TVertex& first_neighbor) const {

    // ---------- 1 判断合法性 ----------

    int vertex_index = GetVertexIndex(vertex);                                                  // 获取结点索引
    if (vertex_index < 0) {                                                                     // if 结点索引 < 0
        return false;                                                                           // 返回false
    }

    // ---------- 2 遍历结点找到第一个相邻结点 ----------

    for (int i = 0; i < this->vertex_count_; i++) {                                             // for loop 遍历结点索引
        TWeight weight;                                                                         // 声明weight(边权值)
        TVertex cur_vertex;                                                                     // 声明cur_vertex(当前结点)

        bool res = GetVertexByIndex(i, cur_vertex);                                             // 获取当前索引(i)对应的结点
        if (!res) {                                                                             // if 当前索引无对应结点
            continue;                                                                           // continue
        }

        res = GetWeight(vertex, cur_vertex, weight);                                            // 获取邻接边(vertex ---> cur_vertex)的权值
        if (res) {                                                                              // if 边权值存在(边存在)
            first_neighbor = cur_vertex;                                                        // 当前结点赋给参数first_neighbor
            return true;                                                                        // 返回true
        }
    }

    // ---------- 3 退出函数 ----------

    return false;                                                                               // 返回false
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
 * + **1 判断合法性**\n\n
 * 获取vertex_index(结点索引)\n
 * 获取neighbor_vertex_index(相邻某结点的结点索引)\n
 * **if** 结点索引 < 0 || 某相邻结点索引 < 0 :\n
 * &emsp; 返回false\n\n
 * + **2 遍历结点找到下一个相邻结点**\n
 * **for loop** 遍历结点索引, 从(neighbor_vertex_index + 1)到(vertex_count_ - 1) :\n
 * &emsp; 声明weight(边权值)\n
 * &emsp; 声明cur_vertex(当前结点)\n\n
 * &emsp; 获取i(当前索引)对应的结点\n
 * &emsp; **if** 当前索引无对应结点 :\n
 * &emsp;&emsp; continue\n\n
 * &emsp; 获取边(vertex ---> cur_vertex)的权值\n
 * &emsp; **if** 边权值存在(边存在) :\n
 * &emsp;&emsp; cur_vertex赋给参数next_neighbor_vertex\n
 * &emsp;&emsp; 返回true\n\n
 * + **3 退出函数**\n
 * 返回false\n
 */
template<typename TVertex, typename TWeight>
bool MatrixGraph<TVertex, TWeight>::GetNextNeighborVertex(const TVertex& vertex,
                                                          const TVertex& neighbor_vertex,
                                                          TVertex& next_neighbor_vertex) const
{
    // ---------- 1 判断合法性 -----------

    int vertex_index = GetVertexIndex(vertex);                                                      // 获取vertex_index(结点索引)
    int neighbor_vertex_index = GetVertexIndex(neighbor_vertex);                                    // 获取neighbor_vertex_index(相邻某结点的结点索引)

    if (vertex_index < 0 || neighbor_vertex_index < 0) {                                            // if 结点索引 < 0 || 某相邻结点索引 < 0
        return false;                                                                               // 返回false
    }

    // ---------- 2 遍历结点找到下一个相邻结点 ----------

    for (int i = neighbor_vertex_index + 1; i < this->vertex_count_; i++) {                         // for loop 遍历结点索引, 从(neighbor_vertex_index + 1)到(vertex_count_ - 1)
        TWeight weight;                                                                             // 声明weight(边权值)
        TVertex cur_vertex;                                                                         // 声明cur_vertex(当前结点)

        bool res = GetVertexByIndex(i, cur_vertex);                                                 // 获取i(当前索引)对应的结点
        if (!res) {                                                                                 // if 当前索引无对应结点
            continue;                                                                               // continue
        }

        res = GetWeight(vertex, cur_vertex, weight);                                                // 获取边(vertex ---> cur_vertex)的权值
        if (res) {                                                                                  // if 边权值存在(边存在)
            next_neighbor_vertex = cur_vertex;                                                      // cur_vertex赋给参数next_neighbor_vertex
            return true;                                                                            // 返回true
        }
    }

    // ---------- 3 退出函数 ----------

    return false;                                                                                   // 返回false
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
 * - **1** 判断合法性\n\n
 * **if** 结点数 >= 结点数上限 :\n
 * &emsp; 返回false\n\n
 * - **2** 执行插入\n\n
 * vertices_插入结点\n\n
 * **if** 无向图 :\n
 * &emsp; degrees_插入0(vertex的度初始化为0)\n
 * **else** (无向图)\n
 * &emsp; in_degrees_插入0(vertex的入度初始化为0)\n
 * &emsp; out_degrees_插入0(vertex的出度初始化为0)\n\n
 * vertex_count_加1\n\n
 * - **3** 退出函数\n\n
 * 返回true\n
 */
template<typename TVertex, typename TWeight>
bool MatrixGraph<TVertex, TWeight>::InsertVertex(const TVertex& vertex) {

    // ---------- 1 判断合法性 ----------

    if (this->vertex_count_ >= this->max_vertex_count_) {                                           // if 结点数 >= 结点数上限
        return false;                                                                               // 返回false
    }

    // ---------- 2 执行插入 ----------

    this->vertices_.push_back(vertex);                                                              // vertices_插入结点

    if (this->type_ == Graph<TVertex, TWeight>::UNDIRECTED) {                                       // if 无向图
        this->degrees_.push_back(0);                                                                // degrees_插入0(vertex的度初始化为0)
    } else {                                                                                        // else (无向图)
        this->in_degrees_.push_back(0);                                                             // in_degrees_插入0(vertex的入度初始化为0)
        this->out_degrees_.push_back(0);                                                            // out_degrees_插入0(vertex的出度初始化为0)
    }

    this->vertex_count_++;                                                                          // vertex_count_加1

    // ---------- 3 退出函数 ----------

    return true;                                                                                    // 返回true
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
 * + **1** 检查插入合法性\n\n
 * <span style="color:#FF9900;font-weight:bold">( 1.1 结点检查和相关处理 )</span>\n
 * 获取starting_vertex_index(起点的结点索引)\n
 * 获取ending_vertex_index(终点的结点索引)\n\n
 * **if** starting_vertex_index < 0 :\n
 * &emsp; 插入起点\n
 * &emsp; **if** 插入失败 :\n
 * &emsp;&emsp; 返回false\n
 * &emsp; 重新获取starting_vertex_index\n\n
 * **if** ending_vertex_index < 0 :\n
 * &emsp; 插入终点\n
 * &emsp; **if** 插入失败 :\n
 * &emsp;&emsp; 返回false\n
 * &emsp; 重新获取ending_vertex_index\n\n
 * **if** starting_vertex_index < 0 || ending_vertex_index < 0 || starting_vertex_index == ending_vertex_index :\n
 * &emsp; 返回false\n\n
 * <span style="color:#FF9900;font-weight:bold">( 1.2 边检查 )</span>\n
 * **for loop** 遍历edges_ :\n
 * &emsp; **if** 无向图 :\n
 * &emsp;&emsp;&emsp; **if** 边(起点 ---> 终点) or 反向边(终点 ---> 起点) 存在 :\n
 * &emsp;&emsp;&emsp;&emsp; 返回false\n
 * &emsp; **else** (有向图) \n
 * &emsp;&emsp;&emsp; **if** 边(起点 ---> 终点) 存在 :\n
 * &emsp;&emsp;&emsp;&emsp; 返回false\n\n
 * <span style="color:#FF9900;font-weight:bold">( 1.3 邻接矩阵检查 )</span>\n
 * **if** 无向图 :\n
 * &emsp; **if** 邻接矩阵内存在该边or反向边 :\n
 * &emsp;&emsp; 返回false;\n
 * **else** (有向图) \n
 * &emsp; **if** 邻接矩阵内存在该边 :\n
 * &emsp;&emsp; 返回false;\n\n
 * + **2 执行插入**\n\n
 * <span style="color:#E76600;font-weight:bold">( 2.1 该边(starting_vertex ---> ending_vertex)插入 )</span>\n
 * 插入邻接矩阵\n\n
 * 生成边(starting_vertex ---> ending_vertex)\n
 * 插入edges_\n\n
 * <span style="color:#E76600;font-weight:bold">( 2.2 如果无向图/网, 边(ending_vertex --> starting_vertex)插入edges_和邻接表 )</span>\n
 * **if** 无向图 :\n
 * &emsp; 反向边(ending_vertex ---> starting_vertex)插入邻接矩阵\n\n
 * <span style="color:#E76600;font-weight:bold">( 2.3 边数加1 )</span>\n
 * edge_count_加1\n\n
 * + **3 度处理**\n\n
 * **if** 无向图 :\n
 * &emsp; 边起点的度加1\n
 * &emsp; 边终点的度加1\n
 * **else**\n
 * &emsp; 边起点的出度加1\n
 * &emsp; 边终点的入度加1\n\n
 * + **4 退出函数**\n\n
 * 返回true\n
 */
template<typename TVertex, typename TWeight>
bool MatrixGraph<TVertex, TWeight>::InsertEdge(const TVertex& starting_vertex,
                                               const TVertex& ending_vertex,
                                               const TWeight& weight)
{
    // ---------- 1 合法性检查和相关处理 ---------

    // ( 1.1 结点检查和相关处理 )
    int starting_vertex_index = GetVertexIndex(starting_vertex);                                        // 获取起点索引
    int ending_vertex_index = GetVertexIndex(ending_vertex);                                            // 获取终点索引

    if (starting_vertex_index < 0) {                                                                    // if 起点索引 < 0
        bool res = this->InsertVertex(starting_vertex);                                                 // 插入起点
        if (!res) {                                                                                     // if 插入失败
            return false;                                                                               // 返回false
        }

        starting_vertex_index = this->GetVertexIndex(starting_vertex);                                  // 使用新插入的起点获取起点索引
    }

    if (ending_vertex_index < 0) {                                                                      // if 终点索引 < 0
        bool res = this->InsertVertex(ending_vertex);                                                   // 插入终点
        if (!res) {                                                                                     // if 插入失败
            return false;                                                                               // 返回false
        }

        ending_vertex_index = this->GetVertexIndex(ending_vertex);                                      // 使用新插入的终点获取终点索引
    }

    if (starting_vertex_index < 0 || ending_vertex_index < 0 ||                                         // if 起点索引 < 0 || 终点索引 < 0 || 起点索引 等于 终点索引
        starting_vertex_index == ending_vertex_index)
    {
        return false;                                                                                   // 返回false
    }

    // ( 1.2 边检查 )
    for (unsigned int i = 0; i < this->edges_.size(); i++) {                                            // for loop 遍历edges_
        if (this->type_ == Graph<TVertex, TWeight>::UNDIRECTED) {                                       // if 无向图
            if ((this->edges_[i].starting_vertex == starting_vertex &&                                  // if 边(起点--->终点) or 反向边(终点--->起点) 存在
                 this->edges_[i].ending_vertex == ending_vertex) ||
                (this->edges_[i].starting_vertex == ending_vertex &&
                 this->edges_[i].ending_vertex == starting_vertex)) {
                return false;                                                                           // 返回false
            }
        } else {                                                                                        // else 有向图
            if (this->edges_[i].starting_vertex == starting_vertex &&                                   // if 边(起点--->终点) 存在
                this->edges_[i].ending_vertex == ending_vertex)
            {
                return false;                                                                           // 返回false
            }
        }
    }

    // ( 1.3 邻接矩阵检查 )
    if (this->type_ == Graph<TVertex, TWeight>::UNDIRECTED) {                                           // if 无向图
        if (this->adjacency_matrix_[starting_vertex_index][ending_vertex_index] != TWeight() ||         // if 邻接矩阵内存在该边or反向边
            this->adjacency_matrix_[ending_vertex_index][starting_vertex_index] != TWeight())
        {
            return false;                                                                               // 返回false
        }
    } else if (this->type_ == Graph<TVertex, TWeight>::DIRECTED) {                                      // else if 有向图
        if (this->adjacency_matrix_[starting_vertex_index][ending_vertex_index] != TWeight()) {         // is 邻接矩阵内存在该边
            return false;                                                                               // 返回false
        }
    }

    // ---------- 2 执行插入 ----------

    // ( 2.1 边(starting_vertex ---> ending_vertex) 插入 )
    this->adjacency_matrix_[starting_vertex_index][ending_vertex_index] = weight;                       // 插入邻接矩阵

    Edge<TVertex, TWeight> edge(starting_vertex, ending_vertex, weight);                                // 生成边(starting_vertex ---> ending_vertex)
    this->edges_.push_back(edge);                                                                       // 插入edges_

    // ( 2.2 如果无向图/网, 边(ending_vertex --> starting_vertex)插入edges_和邻接表 )
    if (this->type_ == Graph<TVertex, TWeight>::UNDIRECTED) {                                           // if 无向图
        this->adjacency_matrix_[ending_vertex_index][starting_vertex_index] = weight;                   // 反向边(ending_vertex ---> starting_vertex)插入邻接矩阵
    }

    // ( 2.3 边数加1 )
    this->edge_count_++;                                                                                // edge_count_加1

    // ---------- 3 度处理 ----------

    if (this->type_ == Graph<TVertex, TWeight>::UNDIRECTED) {                                           // if 无向图
        this->degrees_[starting_vertex_index]++;                                                        // 边起点的度加1
        this->degrees_[ending_vertex_index]++;                                                          // 边终点的度加1
    } else {                                                                                            // else (有向图)
        this->in_degrees_[ending_vertex_index]++;                                                       // 边终点的入度加1
        this->out_degrees_[starting_vertex_index]++;                                                    // 边起点的出度加1
    }

    // ---------- 4 更新edge_count_ ----------

    return true;                                                                                        // 返回true
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
 * + **1 合法性判断**\n\n
 * &emsp; 获取vertex_index(待删除结点的索引)\n
 * &emsp; **if** vertex_index < 0 or vertex_index >= vertex_count_ :\n
 * &emsp;&emsp; 返回false\n\n
 * + **2 邻接矩阵执行删除**\n\n
 * (用索引vertex_count_ - 1结点, 替换待删除结点)\n
 * **for loop** 遍历结点索引 :\n
 * &emsp; **if** i(当前结点索引) == vertex_index :\n
 * &emsp;&emsp; continue\n\n
 * &emsp; 声明weight(边权值)\n\n
 * &emsp; 获取边(vertex ---> 当前遍历结点)的weight\n
 * &emsp; **if** 边(vertex ---> 当前遍历结点)存在 :\n
 * &emsp;&emsp; **if** 无向图 :\n
 * &emsp;&emsp;&emsp; 当前结点的度减1\n
 * &emsp;&emsp; **else** (有向图)\n
 * &emsp;&emsp;&emsp; 当前结点的入度减1\n\n
 * &emsp; 获取边(当前遍历结点 ---> vertex)的weight\n
 * &emsp; **if** 边(当前遍历结点 ---> vertex)存在 :\n
 * &emsp;&emsp; **if** 无向图 :\n
 * &emsp;&emsp;&emsp; do nothing (无向图的情况, 2.1已经执行过, 因此此处不做任何操作)\n
 * &emsp;&emsp; **else** (有向图)\n
 * &emsp;&emsp;&emsp; 当前结点的出度减1\n\n
 * &emsp; 将邻接矩阵位置[i][vertex_index]的元素, 替换为位置[i][vertex_count_ - 1]的元素\n
 * &emsp; 将邻接矩阵位置[vertex_index][i]的元素, 替换为位置[vertex_count_ - 1][i]的元素\n\n
 * + **3 度调整**\n\n
 * **if** 无向图 :\n
 * &emsp; degrees_[vertex_index], 替换为索引(vertex_count_ - 1)结点的度\n
 * &emsp; 删除索引(vertex_count_ - 1)结点的度\n
 * **else** (有向图)\n
 * &emsp; in_degrees_[vertex_index], 替换为索引(vertex_count_ - 1)结点的入度\n
 * &emsp; 删除索引(vertex_count_ - 1)结点的入度\n\n
 * &emsp; out_degrees_[vertex_index], 替换为索引(vertex_count_ - 1)结点的出度\n
 * &emsp; 删除索引(vertex_count_ - 1)结点的出度\n\n
 * + **4 edges_执行删除**\n\n
 * **for loop** 遍历edges_ :\n
 * &emsp; **if** 当前边起点or当前边终点 为待删除节点 :\n
 * &emsp;&emsp; 删除当前边\n
 * &emsp;&emsp; 边数减1\n
 * &emsp; **else**\n
 * &emsp;&emsp; 遍历指针向后移动1位\n
 * + **5 vertices_执行删除**\n\n
 * vertices_的索引vertex_index位置元素, 替换为索引vertex_count_ - 1位置元素\n
 * vertices_删除索引vertex_count - 1位置元素\n
 * vertex_count_(结点数)减1**\n
 * + **6 退出函数**\n\n
 * 返回true\n
 */
template<typename TVertex, typename TWeight>
bool MatrixGraph<TVertex, TWeight>::RemoveVertex(const TVertex& vertex) {

    // ---------- 1 判断删除合理性 ----------

    int vertex_index = GetVertexIndex(vertex);                                                                  // 获取vertex_index(待删除结点的索引)
    if (vertex_index < 0 || vertex_index >= this->vertex_count_) {                                              // if vertex_index < 0 or vertex_index >= vertex_count_
        return false;                                                                                           // 返回false
    }

    // ---------- 2 邻接矩阵执行删除 ----------

    // (用索引vertex_count_ - 1结点, 替换待删除结点)
    for (int i = 0; i < this->vertex_count_; i++) {                                                             // for loop 遍历结点索引
        if (i == vertex_index) {                                                                                //if i(当前结点索引) == vertex_index
            continue;                                                                                           // continue
        }

        TWeight weight;                                                                                         // 声明weight(边权值)

        bool res = this->GetWeightByVertexIndex(vertex_index, i, weight);                                       // 获取边(vertex ---> 当前遍历结点)的weight
        if (res) {                                                                                              // if 边(vertex ---> 当前遍历结点)存在
            if (this->type_ == Graph<TVertex, TWeight>::UNDIRECTED) {                                           // if 无向图
                this->degrees_[i]--;                                                                            // 当前结点的度减1
            } else {                                                                                            // else (有向图)
                this->in_degrees_[i]--;                                                                         // 当前结点的入度减1
            }
        }

        res = this->GetWeightByVertexIndex(i, vertex_index, weight);                                            // 获取边(当前遍历结点 ---> vertex)的weight
        if (res) {                                                                                              // if 边(当前遍历结点 ---> vertex)存在
            if (this->type_ == Graph<TVertex, TWeight>::UNDIRECTED) {                                           // if 无向图
                // do nothing                                                                                   // 无向图的情况, 由于上面已经执行过, 因此此处不做任何操作
            } else {                                                                                            // else (有向图)
                this->out_degrees_[i]--;                                                                        // 当前结点的出度减1
            }
        }

        this->adjacency_matrix_[vertex_index][i] = this->adjacency_matrix_[this->vertex_count_ - 1][i];         // 将邻接矩阵位置[vertex_index][i]的元素, 替换为位置[vertex_count_ - 1][i]的元素
        this->adjacency_matrix_[i][vertex_index] = this->adjacency_matrix_[i][this->vertex_count_ - 1];         // 将邻接矩阵位置[i][vertex_index]的元素, 替换为位置[i][vertex_count_ - 1]的元素
    }

    // ---------- 3 度调整 ----------

    if (this->type_ == Graph<TVertex, TWeight>::UNDIRECTED) {                                                   // if 无向图
        this->degrees_[vertex_index] = this->degrees_[this->vertex_count_ - 1];                                 // degrees_[vertex_index], 替换为索引(vertex_count_ - 1)结点的度
        this->degrees_.erase(this->degrees_.begin() + this->vertex_count_ - 1);                                 // 删除索引(vertex_count_ - 1)结点的度
    } else {                                                                                                    // else (有向图)
        this->in_degrees_[vertex_index] = this->in_degrees_[this->vertex_count_ - 1];                           // in_degrees_[vertex_index], 替换为索引(vertex_count_ - 1)结点的入度
        this->in_degrees_.erase(this->in_degrees_.begin() + this->vertex_count_ - 1);                           // 删除索引(vertex_count_ - 1)结点的入度

        this->out_degrees_[vertex_index] = this->out_degrees_[this->vertex_count_ - 1];                         // out_degrees_[vertex_index], 替换为索引(vertex_count_ - 1)结点的出度
        this->out_degrees_.erase(this->out_degrees_.begin() + this->vertex_count_ - 1);                         // 删除索引(vertex_count_ - 1)结点的出度
    }

    // ---------- 4 edges_执行删除 ----------

    for (auto iter = this->edges_.begin(); iter != this->edges_.end();) {                                       // for loop 遍历edges_
        if (iter->ending_vertex == vertex || iter->starting_vertex == vertex) {                                 // if 当前边起点or当前边终点 为待删除节点
            iter = this->edges_.erase(iter);                                                                    // 删除当前边
            this->edge_count_--;                                                                                // 边数减1
        } else {                                                                                                // else
            iter++;                                                                                             // 遍历指针向后移动1位
        }
    }

    // ---------- 5 vertices_执行删除 ----------

    this->vertices_[vertex_index] = this->vertices_[this->vertex_count_ - 1];                                   // vertices_的索引vertex_index位置元素, 替换为索引vertex_count_ - 1位置元素
    this->vertices_.erase(this->vertices_.begin() + this->vertex_count_ - 1);                                   // vertices_删除索引vertex_count - 1位置元素

    this->vertex_count_--;                                                                                      // vertex_count_减1

    // ---------- 6 退出函数 ----------

    return true;                                                                                                // 返回true
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
 * + **1 合法性检查**\n\n
 * <span style="color:#FF9900;font-weight:bold">( 1.1 检查待删除边的起点和终点 )</span>\n
 * 获取起点索引和终点索引\n
 * **if** 起点索引 < 0 <b>||</b> 终点索引 < 0 :\n
 * &emsp; 返回false\n\n
 * <span style="color:#FF9900;font-weight:bold">( 1.2 检查vertices_ )</span>\n
 * 初始化target_edge_index(待删除边索引)为-1\n
 * **if** 有向图 :\n
 * &emsp; **for** 遍历edges_ :\n
 * &emsp;&emsp; **if** 当前边的起点等于参数起点 <b>&&</b> 当前边的终点等于参数终点 :\n
 * &emsp;&emsp;&emsp; i<b>(当前边索引)</b>赋给target_edge_index\n
 * &emsp;&emsp;&emsp; 退出循环(找到待删除边索引)\n
 * **else** (无向图) :\n
 * &emsp; **for loop** 遍历edges_ :\n
 * &emsp;&emsp; **if** <b>(</b>当前边的起点等于参数起点 <b>&&</b> 当前边的终点等于参数终点<b>)</b> <b>||</b>
 * <b>(</b>当前边的起点等于参数终点 <b>&&</b> 当前边的终点等于参数起点<b>)</b> :\n
 * &emsp;&emsp;&emsp; i<b>(当前边索引)</b>赋给target_edge_index\n
 * &emsp;&emsp;&emsp; 退出循环(找到待删除边索引)\n\n
 * **if** target_edge_index等于-1(edges_内无此边) :\n
 * &emsp; 返回false\n\n
 * <span style="color:#FF9900;font-weight:bold">( 1.3 检查邻接矩阵 )</span>\n
 * 获取边(starting_vertex ---> ending_vertex)的权值\n
 * **if** 权值不存在(即边不存在) :\n
 * &emsp; 返回false\n\n
 * **if** 无向图: \n
 * &emsp; 获取边(ending_vertex ---> starting_vertex)的权值\n
 * &emsp; **if** 权值不存在(即边不存在) :\n
 * &emsp;&emsp; 返回false\n\n
 * + **2 edges_和邻接矩阵执行删除**\n\n
 * <span style="color:#E76600;font-weight:bold">( 2.1 (起点 ---> 终点)方向删除 )</span>\n
 * 邻接矩阵内删除\n
 * edges_内删除\n\n
 * <span style="color:#E76600;font-weight:bold">( 2.2 无向图 (终点 ---> 起点)方向删除 )</span>\n
 * **if** 无向图 :\n
 * &emsp; 邻接矩阵内删除反向边\n\n
 * <span style="color:#E76600;font-weight:bold">( 2.3 边总数减1 )</span>\n
 * edge_count_减1\n\n
 * + **3 度调整**\n\n
 * **if** 无向图 :\n
 * &emsp; 边起点的度减1\n
 * &emsp; 边终点的度减1\n
 * **else** (有向图) :\n
 * &emsp; 边终点的入度减1\n
 * &emsp; 边起点的出度减1\n\n
 * + **4 退出函数**\n\n
 * 返回true\n
 */
template<typename TVertex, typename TWeight>
bool MatrixGraph<TVertex, TWeight>::RemoveEdge(const TVertex& starting_vertex, const TVertex& ending_vertex) {

    // ---------- 1 合法性检查 ----------

    // (1.1 检查待删除边的起点和终点)
    int starting_vertex_index = this->GetVertexIndex(starting_vertex);                                          // 获取起点索引和终点索引
    int ending_vertex_index = this->GetVertexIndex(ending_vertex);
    if (starting_vertex_index < 0 || ending_vertex_index < 0) {                                                 // if 起点索引 < 0 || 终点索引 < 0
        return false;                                                                                           // 返回false
    }

    // (1.2 检查vertices_)
    int target_edge_index = -1;                                                                                 // 初始化target_edge_index(待删除边索引)为-1
    if (this->type_ == Graph<TVertex, TWeight>::DIRECTED) {                                                     // if 有向图
        for (unsigned int i = 0; i < this->edges_.size(); i++) {                                                // for 遍历边vector
            if (this->edges_[i].starting_vertex == starting_vertex &&                                           // if 当前边的起点等于参数起点 && 当前边的终点等于参数终点
                this->edges_[i].ending_vertex == ending_vertex)
            {
                target_edge_index = (int)i;                                                                     // i(当前边索引)赋给target_edge_index
                break;                                                                                          // 退出循环(找到待删除边索引)
            }
        }
    } else {                                                                                                    // else (无向图)
        for (unsigned int i = 0; i < this->edges_.size(); i++) {                                                // for loop 遍历边vector

            // if (当前边的起点等于参数起点 && 当前边的终点等于参数终点) || (当前边的起点等于参数终点 && 当前边的终点等于参数起点)
            if ((this->edges_[i].starting_vertex == starting_vertex && this->edges_[i].ending_vertex == ending_vertex) ||
                (this->edges_[i].starting_vertex == ending_vertex && this->edges_[i].ending_vertex == starting_vertex))
            {
                target_edge_index = (int)i;                                                                     // i(当前边索引)赋给target_edge_index
                break;                                                                                          // 退出循环
            }
        }
    }

    if (target_edge_index == -1) {                                                                              // if target_edge_index等于-1(edges_内无此边)
        return false;                                                                                           // 返回false
    }

    // ( 1.3 检查邻接矩阵 )
    TWeight weight;                                                                                             // 声明weight(边权值)
    bool res = GetWeight(starting_vertex, ending_vertex, weight);                                               // 获取边(starting_vertex ---> ending_vertex)的权值
    if (!res) {                                                                                                 // if 权值不存在(即边不存在)
        return false;                                                                                           // 返回false
    }

    if (this->type_ == Graph<TVertex, TWeight>::UNDIRECTED) {                                                   // if 无向图
        res = GetWeight(ending_vertex, starting_vertex, weight);                                                // 获取边(ending_vertex ---> starting_vertex)的权值
        if (!res) {                                                                                             // if 权值不存在(即边不存在)
            return false;                                                                                       // 返回false
        }
    }

    // ------ 2 在edges和邻接矩阵做删除 ------

    // 2.1 (起点 ---> 终点)方向删除
    this->adjacency_matrix_[starting_vertex_index][ending_vertex_index] = TWeight();                            // 邻接矩阵内删除
    this->edges_.erase(this->edges_.begin() + target_edge_index);                                               // edges_内删除

    // 2.2 无向图 (终点 ---> 起点)方向删除
    if (this->type_ == Graph<TVertex, TWeight>::UNDIRECTED) {                                                   // if 无向图
        this->adjacency_matrix_[ending_vertex_index][starting_vertex_index] = TWeight();                        // 邻接矩阵内删除反向边
    }

    // (2.3 边总数减1)
    this->edge_count_--;                                                                                        // edge_count_减1

    // ----------- 3 度调整 ----------

    if (this->type_ == Graph<TVertex, TWeight>::UNDIRECTED) {                                                   // if 无向图
        this->degrees_[starting_vertex_index]--;                                                                // 边起点的度减1
        this->degrees_[ending_vertex_index]--;                                                                  // 边终点的度减1
    } else {                                                                                                    // else (有向图)
        this->in_degrees_[ending_vertex_index]--;                                                               // 边终点的入度减1
        this->out_degrees_[starting_vertex_index]--;                                                            // 边起点的出度减1
    }

    // ---------- 4 退出函数 ----------

    return true;                                                                                                // 返回true
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
    for (int i = 0; i < this->vertex_count_; i++) {     // for loop 遍历结点索引
        if (this->vertices_[i] == vertex) {             // if i(当前索引)对应的结点等于vertex
            return i;                                   // 返回i
        }
    }

    return -1;  // 返回-1(如果没有找到对应索引)
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
    for (int row = 0; row < this->vertex_count_; row++) {                   // for loop 遍历行索引
        for (int col = 0; col < this->vertex_count_; col++) {               // for loop 遍历列索引
            cout << setw(5) << this->adjacency_matrix_[row][col] << "  ";   // 打印adjacency_matrix_[row][col](当前矩阵元素)
        }
        cout<<endl;
    }
}


#endif // CYBER_DASH_MATRIX_GRAPH_H
