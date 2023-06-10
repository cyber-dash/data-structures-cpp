/*!
 * @file test.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 图测试.cpp文件
 * @version 0.2.1
 * @date 2021-10-9
 */

#include "test.h"
#include "min_priority_queue.h"
#include "graph_algorithm.h"
#include "graph_algorithm.cpp"


using namespace std;


void TestDirectedGraph() {
    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|                    Test Directed Graph                    |"<<endl;
    cout<<"|                         测试有向图                          |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                         北京                               |"<<endl;
    cout<<"|                         / \\                               |"<<endl;
    cout<<"|                        /   \\                              |"<<endl;
    cout<<"|                      0.1   0.12                           |"<<endl;
    cout<<"|                      /       \\                            |"<<endl;
    cout<<"|                     /         \\                           |"<<endl;
    cout<<"|                  上海---0.01---广州                        |"<<endl;
    cout<<"|                   / \\         / \\                         |"<<endl;
    cout<<"|                  /   \\       /   \\                        |"<<endl;
    cout<<"|               0.13  0.14   0.05   0.17                    |"<<endl;
    cout<<"|                /       \\   /       \\                      |"<<endl;
    cout<<"|               /         \\ /         \\                     |"<<endl;
    cout<<"|            杭州 --0.09-- 深圳 --0.11-- 成都                 |"<<endl;
    cout<<endl;

    unsigned int edge_count = 18;

    // 结点信息
    vector<string> vertices{ "北京", "上海", "广州", "深圳", "杭州", "成都" };

    // 边信息
    vector<string> starting_vertices{
        "北京", "北京", "上海", "上海", "上海", "广州", "广州", "深圳", "深圳",
        "上海", "广州", "广州", "深圳", "杭州", "深圳", "成都", "杭州", "成都",
    };
    vector<string> ending_vertices{
        "上海", "广州", "广州", "深圳", "杭州", "深圳", "成都", "杭州", "成都",
        "北京", "北京", "上海", "上海", "上海", "广州", "广州", "深圳", "深圳",
    };
    vector<double> weights{
        0.1, 0.12, 0.01, 0.14, 0.13, 0.05, 0.17, 0.09, 0.11,
        0.1, 0.12, 0.01, 0.14, 0.13, 0.05, 0.17, 0.09, 0.11,
    };    // 边权重数组

    vector<Edge<string, double> > edges;
    for (unsigned int i = 0; i < edge_count; i++) {
        Edge<string, double> edge(starting_vertices[i], ending_vertices[i], weights[i]);
        edges.push_back(edge);
    }

    int graph_type = 1; // 有向
    // 构造邻接表图
    AdjacencyListGraph<string, double> adj_list_graph(graph_type, 10, 1000, edges, vertices);

    // 构造矩阵图
    MatrixGraph<string, double> matrix_graph(graph_type, 10, 1000, edges, vertices);

    cout << "##### 2 删除边(\"上海\", \"北京\") #####" << endl << endl;
    adj_list_graph.RemoveEdge("北京", "上海");
    matrix_graph.RemoveEdge("北京", "上海");

    cout << adj_list_graph << endl;
    cout << matrix_graph << endl;
}


/*!
 * @brief **测试-图-基础函数**
 * @note
 * 测试-图-基础函数
 * --------------
 * --------------
 *
 *
 * --------------
 * + **1 初始化图的基本信息**\n\n
 * 初始化结点信息(北京, 上海, 广州, 深圳, 杭州, 成都 6座城市)\n
 * 初始化边信息\n\n
 * + **2 测试基础函数**\n\n
 * 构造adjacency_list_directed_graph(邻接表有向图)\n
 * 依次删除1个城市, 然后打印图\n\n
 * 构造adjacency_list_undirected_graph(邻接表无向图)\n
 * 依次删除1个城市, 然后打印图\n\n
 * 构造matrix_directed_graph(矩阵有向图)\n
 * 依次删除1个城市, 然后打印图\n\n
 * 构造matrix_undirected_graph(矩阵无向图)\n
 * 依次删除1个城市, 然后打印图\n\n
 */
void TestBaseFunctions() {
    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|                  Test Graph BaseFunctions                 |"<<endl;
    cout<<"|                       测试-图-基础函数                   |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                         北京                               |"<<endl;
    cout<<"|                         / \\                               |"<<endl;
    cout<<"|                        /   \\                              |"<<endl;
    cout<<"|                      0.1   0.12                           |"<<endl;
    cout<<"|                      /       \\                            |"<<endl;
    cout<<"|                     /         \\                           |"<<endl;
    cout<<"|                  上海---0.01---广州                        |"<<endl;
    cout<<"|                   / \\         / \\                         |"<<endl;
    cout<<"|                  /   \\       /   \\                        |"<<endl;
    cout<<"|               0.13  0.14   0.05   0.17                    |"<<endl;
    cout<<"|                /       \\   /       \\                      |"<<endl;
    cout<<"|               /         \\ /         \\                     |"<<endl;
    cout<<"|            杭州 --0.09-- 深圳 --0.11-- 成都                 |"<<endl;
    cout<<endl;

    // ---------- 1 初始化图的基本信息 ----------

    // 初始化结点信息(北京, 上海, 广州, 深圳, 杭州, 成都 6座城市)
    vector<string> vertices{ "北京", "上海", "广州", "深圳", "杭州", "成都" };

    // 初始化边信息
    unsigned int edge_count = 9;

    vector<string> starting_vertices{ "北京",  "北京", "上海", "上海", "上海", "广州", "广州", "深圳", "深圳" };  // 初始化起点数组
    vector<string> ending_vertices{ "上海", "广州", "广州", "深圳", "杭州", "深圳", "成都", "杭州", "成都" };     // 初始化终点数组
    vector<double> weights{ 0.1, 0.12, 0.01, 0.14, 0.13, 0.05, 0.17, 0.09, 0.11 };                           // 初始化边权值数组

    vector<Edge<string, double> > edges;                                                                     // 声明边vector
    // 构造边vector
    for (unsigned int i = 0; i < edge_count; i++) {
        Edge<string, double> edge(starting_vertices[i], ending_vertices[i], weights[i]);
        edges.push_back(edge);
    }

    // ---------- 2 测试基础函数 ----------

    // 构造adjacency_list_directed_graph(邻接表有向图)
    AdjacencyListGraph<string, double> adjacency_list_directed_graph(Graph<string, double>::DIRECTED, 10, 1000, edges, vertices);

    // 依次删除1个城市, 然后打印图
    cout << "##### 1 邻接表有向图删除结点 #####" << endl << endl;
    adjacency_list_directed_graph.RemoveVertex("北京");
    cout << adjacency_list_directed_graph << endl << endl << endl << endl;
    adjacency_list_directed_graph.RemoveVertex("上海");
    cout << adjacency_list_directed_graph << endl << endl << endl << endl;
    adjacency_list_directed_graph.RemoveVertex("深圳");
    cout << adjacency_list_directed_graph << endl << endl << endl << endl;
    adjacency_list_directed_graph.RemoveVertex("广州");
    cout << adjacency_list_directed_graph << endl << endl << endl << endl;
    adjacency_list_directed_graph.RemoveVertex("成都");
    cout << adjacency_list_directed_graph << endl << endl << endl << endl;
    adjacency_list_directed_graph.RemoveVertex("杭州");
    cout << adjacency_list_directed_graph << endl << endl << endl << endl;

    // 构造adjacency_list_undirected_graph(邻接表无向图)
    AdjacencyListGraph<string, double> adjacency_list_undirected_graph(Graph<string, double>::UNDIRECTED, 10, 1000, edges, vertices);

    // 依次删除1个城市, 然后打印图
    cout << "##### 2 邻接表无向图删除结点 #####" << endl << endl;
    adjacency_list_undirected_graph.RemoveVertex("北京");
    cout << adjacency_list_undirected_graph << endl << endl << endl << endl;
    adjacency_list_undirected_graph.RemoveVertex("上海");
    cout << adjacency_list_undirected_graph << endl << endl << endl << endl;
    adjacency_list_undirected_graph.RemoveVertex("深圳");
    cout << adjacency_list_undirected_graph << endl << endl << endl << endl;
    adjacency_list_undirected_graph.RemoveVertex("广州");
    cout << adjacency_list_undirected_graph << endl << endl << endl << endl;
    adjacency_list_undirected_graph.RemoveVertex("成都");
    cout << adjacency_list_undirected_graph << endl << endl << endl << endl;
    adjacency_list_undirected_graph.RemoveVertex("杭州");
    cout << adjacency_list_undirected_graph << endl << endl << endl << endl;

    // 构造matrix_directed_graph(矩阵有向图)
    MatrixGraph<string, double> matrix_directed_graph(Graph<string, double>::DIRECTED, 10, 1000, edges, vertices);

    // 依次删除1个城市, 然后打印图
    cout << "##### 3 矩阵有向图删除结点 #####" << endl << endl;
    matrix_directed_graph.RemoveVertex("北京");
    cout << matrix_directed_graph << endl << endl;
    matrix_directed_graph.RemoveVertex("上海");
    cout << matrix_directed_graph << endl << endl;
    matrix_directed_graph.RemoveVertex("深圳");
    cout << matrix_directed_graph << endl << endl;
    matrix_directed_graph.RemoveVertex("广州");
    cout << matrix_directed_graph << endl << endl;
    matrix_directed_graph.RemoveVertex("成都");
    cout << matrix_directed_graph << endl << endl;
    matrix_directed_graph.RemoveVertex("杭州");
    cout << matrix_directed_graph << endl << endl;

    // 构造matrix_undirected_graph(矩阵无向图)
    MatrixGraph<string, double> matrix_undirected_graph(Graph<string, double>::UNDIRECTED, 10, 1000, edges, vertices);

    // 依次删除1个城市, 然后打印图
    cout << "##### 4 矩阵无向图删除结点 #####" << endl << endl;
    matrix_undirected_graph.RemoveVertex("北京");
    cout << matrix_undirected_graph << endl << endl;
    matrix_undirected_graph.RemoveVertex("上海");
    cout << matrix_undirected_graph << endl << endl;
    matrix_undirected_graph.RemoveVertex("深圳");
    cout << matrix_undirected_graph << endl << endl;
    matrix_undirected_graph.RemoveVertex("广州");
    cout << matrix_undirected_graph << endl << endl;
    matrix_undirected_graph.RemoveVertex("成都");
    cout << matrix_undirected_graph << endl << endl;
    matrix_undirected_graph.RemoveVertex("杭州");
    cout << matrix_undirected_graph << endl << endl;

    cout << "-------------------------------------------------------------" << endl;
}


/*!
 * @brief **测试-矩阵图-打印矩阵**
 * @note
 * 测试-矩阵图-打印矩阵
 * -----------------
 * -----------------
 *
 * -----------------
 * + **1 初始化图的基本信息**\n\n
 * 初始化结点信息(北京, 上海, 广州, 深圳, 杭州, 成都 6座城市)\n
 * 初始化边信息\n\n
 * 构造无向矩阵图\n\n
 * + **2 打印矩阵**\n\n
 *
 *
 * -----------------
 */
void TestMatrixGraphPrintMatrix() {
    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|                      Test PrintMatrix                     |"<<endl;
    cout<<"|                       测试矩阵图的矩阵                      |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                         北京                               |"<<endl;
    cout<<"|                         / \\                               |"<<endl;
    cout<<"|                        /   \\                              |"<<endl;
    cout<<"|                      0.1   0.12                           |"<<endl;
    cout<<"|                      /       \\                            |"<<endl;
    cout<<"|                     /         \\                           |"<<endl;
    cout<<"|                  上海---0.01---广州                        |"<<endl;
    cout<<"|                   / \\         / \\                         |"<<endl;
    cout<<"|                  /   \\       /   \\                        |"<<endl;
    cout<<"|               0.13  0.14   0.05   0.17                    |"<<endl;
    cout<<"|                /       \\   /       \\                      |"<<endl;
    cout<<"|               /         \\ /         \\                     |"<<endl;
    cout<<"|            杭州 --0.09-- 深圳 --0.11-- 成都                 |"<<endl;
    cout<<endl;

    // ---------- 1 初始化图的基本信息 ----------
    unsigned int edge_count = 9;

    // 初始化结点信息(北京, 上海, 广州, 深圳, 杭州, 成都 6座城市)
    vector<string> vertices{ "北京", "上海", "广州", "深圳", "杭州", "成都" };

    // 初始化边信息
    vector<string> starting_vertices{ "北京",  "北京", "上海", "上海", "上海", "广州", "广州", "深圳", "深圳" };
    vector<string> ending_vertices{ "上海", "广州", "广州", "深圳", "杭州", "深圳", "成都", "杭州", "成都" };
    vector<double> weights{ 0.1, 0.12, 0.01, 0.14, 0.13, 0.05, 0.17, 0.09, 0.11 };    // 边权重数组

    vector<Edge<string, double> > edges;
    for (unsigned int i = 0; i < edge_count; i++) {
        Edge<string, double> edge(starting_vertices[i], ending_vertices[i], weights[i]);
        edges.push_back(edge);
    }

    // 构造无向矩阵图
    MatrixGraph<string, double> matrix_graph(10, 1000, edges, vertices);

    // ---------- 2 打印矩阵 ----------

    matrix_graph.PrintMatrix();

    cout<<"-------------------------------------------------------------"<<endl;
}


/*!
 * @brief **测试-图-使用结点索引获取结点**
 * @note
 * 测试-图-使用结点索引获取结点
 * ------------------------
 * ------------------------
 *
 * ------------------------
 * + **1 初始化图的基本信息**\n\n
 * 初始化结点信息(北京, 上海, 广州, 深圳, 杭州, 成都 6座城市)\n
 * 初始化边信息\n\n
 * 构造无向矩阵图\n\n
 * + **2 测试邻接表图**\n\n
 * + **3 测试矩阵图**\n\n
 *
 *
 * ------------------------
 */
void TestGetVertexByIndex() {
    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|                Test Graph GetVertexByIndex                |"<<endl;
    cout<<"|                 测试-图-使用结点索引获取结点              |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                         北京                               |"<<endl;
    cout<<"|                         / \\                               |"<<endl;
    cout<<"|                        /   \\                              |"<<endl;
    cout<<"|                      0.1   0.12                           |"<<endl;
    cout<<"|                      /       \\                            |"<<endl;
    cout<<"|                     /         \\                           |"<<endl;
    cout<<"|                  上海---0.01---广州                        |"<<endl;
    cout<<"|                   / \\         / \\                         |"<<endl;
    cout<<"|                  /   \\       /   \\                        |"<<endl;
    cout<<"|               0.13  0.14   0.05   0.17                    |"<<endl;
    cout<<"|                /       \\   /       \\                      |"<<endl;
    cout<<"|               /         \\ /         \\                     |"<<endl;
    cout<<"|            杭州 --0.09-- 深圳 --0.11-- 成都                 |"<<endl;
    cout<<endl;
    // ---------- 1 初始化图的基本信息 ----------

    unsigned int edge_count = 9;

    // 初始化结点信息(北京, 上海, 广州, 深圳, 杭州, 成都 6座城市)
    vector<string> vertices{ "北京", "上海", "广州", "深圳", "杭州", "成都" };

    vector<string> starting_vertices{ "北京",  "北京", "上海", "上海", "上海", "广州", "广州", "深圳", "深圳" };
    vector<string> ending_vertices{ "上海", "广州", "广州", "深圳", "杭州", "深圳", "成都", "杭州", "成都" };
    vector<double> weights{ 0.1, 0.12, 0.01, 0.14, 0.13, 0.05, 0.17, 0.09, 0.11 };    // 边权重数组

    // 初始化边信息
    vector<Edge<string, double> > edges;
    for (unsigned int i = 0; i < edge_count; i++) {
        Edge<string, double> edge(starting_vertices[i], ending_vertices[i], weights[i]);
        edges.push_back(edge);
    }

    // 构造无向矩阵图
    vector<string> graph_vertices(vertices.size());

    // ---------- 2 测试邻接表图 ----------

    // 构造邻接表图
    AdjacencyListGraph<string, double> adjacency_list_graph(10, 1000, edges, vertices);

    // 按照索引值读取邻接表图各结点
    for (unsigned int i = 0; i < adjacency_list_graph.VertexCount(); i++) {
        adjacency_list_graph.GetVertexByIndex(i, graph_vertices[i]);
    }

    adjacency_list_graph.RemoveEdge("上海", "北京");
    adjacency_list_graph.RemoveEdge("北京", "广州");
    adjacency_list_graph.RemoveVertex("北京");
    adjacency_list_graph.RemoveVertex("上海");
    adjacency_list_graph.RemoveVertex("广州");
    adjacency_list_graph.RemoveVertex("深圳");
    adjacency_list_graph.RemoveVertex("杭州");

    cout << adjacency_list_graph << endl;

    // ---------- 3 测试矩阵图 ----------

    // 构造矩阵图
    MatrixGraph<string, double> matrix_graph(10, 10000, edges, vertices);
    matrix_graph.RemoveVertex("北京");

    // 按照索引值读取矩阵图各结点
    for (unsigned int i = 0; i < matrix_graph.VertexCount(); i++) {
        matrix_graph.GetVertexByIndex(i, graph_vertices[i]);
    }

    // 打印结点
    cout<<endl<<"**矩阵图**"<<endl;
    for (unsigned int i = 0; i < matrix_graph.VertexCount(); i++) {
        cout << "索引" << i << "结点: " << graph_vertices[i] << endl;
    }

    cout<<"-------------------------------------------------------------"<<endl;
}


/*!
 * @brief **测试-图-深度优先遍历(递归)**
 * @note
 * 测试-图-深度优先遍历(递归)
 * -----------------------
 * -----------------------
 *
 * -----------------------
 * + **1 初始化图的基本信息**\n\n
 * 初始化结点信息(北京, 上海, 广州, 深圳, 杭州, 成都 6座城市)\n
 * 初始化边信息\n\n
 * 构造无向矩阵图\n\n
 * + **2 测试邻接表图深度优先遍历**\n\n
 * + **3 测试矩阵图深度优先遍历**\n\n
 *
 *
 * -----------------------
 */
void TestDfsRecursive() {
    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|                  Test Graph DfsRecursive                  |"<<endl;
    cout<<"|                   测试-图-深度优先遍历(递归)             |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                           北京                               |"<<endl;
    cout<<"|                           / \\                               |"<<endl;
    cout<<"|                          /   \\                              |"<<endl;
    cout<<"|                        0.1   0.12                           |"<<endl;
    cout<<"|                        /       \\                            |"<<endl;
    cout<<"|                       /         \\                           |"<<endl;
    cout<<"|                    上海---0.01---广州                       |"<<endl;
    cout<<"|                     / \\         / \\                         |"<<endl;
    cout<<"|                    /   \\       /   \\                        |"<<endl;
    cout<<"|                 0.13  0.14   0.05   0.17                    |"<<endl;
    cout<<"|                  /       \\   /       \\                      |"<<endl;
    cout<<"|                 /         \\ /         \\                     |"<<endl;
    cout<<"|              杭州 --0.09-- 深圳 --0.11-- 成都                 |"<<endl;
    cout<<endl;

    // ---------- 1 初始化图的基本信息 ----------

    // 初始化结点信息(北京, 上海, 广州, 深圳, 杭州, 成都 6座城市)
    unsigned int edge_count = 9;

    vector<string> vertices{ "北京", "上海", "广州", "深圳", "杭州", "成都" };

    vector<string> starting_vertices{ "北京",  "北京", "上海", "上海", "上海", "广州", "广州", "深圳", "深圳" };
    vector<string> ending_vertices{ "上海", "广州", "广州", "深圳", "杭州", "深圳", "成都", "杭州", "成都" };
    vector<double> weights{ 0.1, 0.12, 0.01, 0.14, 0.13, 0.05, 0.17, 0.09, 0.11 };    // 边权重数组

    // 初始化边信息
    vector<Edge<string, double> > edges;
    for (unsigned int i = 0; i < edge_count; i++) {
        Edge<string, double> edge(starting_vertices[i], ending_vertices[i], weights[i]);
        edges.push_back(edge);
    }

    // ---------- 2 测试邻接表图深度优先遍历 ----------

    cout<<"**邻接表图**"<<endl;
    AdjacencyListGraph<string, double> adjacency_list_graph(10, 1000, edges, vertices);

    DfsRecursive(adjacency_list_graph, vertices[0]);

    // ---------- 3 测试矩阵图深度优先遍历 ----------

    cout<<endl<<"**矩阵图**"<<endl;
    MatrixGraph<string, double> matrix_graph(10, 1000, edges, vertices);

    DfsRecursive(matrix_graph, vertices[0]);

    cout<<"-------------------------------------------------------------"<<endl;
}


// 测试BFS
void TestBFS() {
    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|                          Test Bfs                         |"<<endl;
    cout<<"|                       测试广度优先遍历                      |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                           北京                               |"<<endl;
    cout<<"|                           / \\                               |"<<endl;
    cout<<"|                          /   \\                              |"<<endl;
    cout<<"|                        0.1   0.12                           |"<<endl;
    cout<<"|                        /       \\                            |"<<endl;
    cout<<"|                       /         \\                           |"<<endl;
    cout<<"|                    上海---0.01---广州                       |"<<endl;
    cout<<"|                     / \\         / \\                         |"<<endl;
    cout<<"|                    /   \\       /   \\                        |"<<endl;
    cout<<"|                 0.13  0.14   0.05   0.17                    |"<<endl;
    cout<<"|                  /       \\   /       \\                      |"<<endl;
    cout<<"|                 /         \\ /         \\                     |"<<endl;
    cout<<"|              杭州 --0.09-- 深圳 --0.11-- 成都                 |"<<endl;
    cout<<endl;

    unsigned int edge_count = 9;

    // 结点信息
    vector<string> vertices{ "北京", "上海", "广州", "深圳", "杭州", "成都" };

    // 边信息
    vector<string> starting_vertices{ "北京",  "北京", "上海", "上海", "上海", "广州", "广州", "深圳", "深圳" };
    vector<string> ending_vertices{ "上海", "广州", "广州", "深圳", "杭州", "深圳", "成都", "杭州", "成都" };
    vector<double> weights{ 0.1, 0.12, 0.01, 0.14, 0.13, 0.05, 0.17, 0.09, 0.11 };    // 边权重数组

    vector<Edge<string, double> > edges;
    for (unsigned int i = 0; i < edge_count; i++) {
        Edge<string, double> edge(starting_vertices[i], ending_vertices[i], weights[i]);
        edges.push_back(edge);
    }

    // 构造邻接表图
    AdjacencyListGraph<string, double> adjacency_list_graph(10, 1000, edges, vertices);
    // 构造矩阵图
    MatrixGraph<string, double> matrix_graph(10, 1000, edges, vertices);

    cout<<"**邻接表图**"<<endl;
    Bfs(adjacency_list_graph, vertices[0]);

    cout<<endl<<"**矩阵图**"<<endl;
    Bfs(matrix_graph, vertices[0]);

    cout<<"-------------------------------------------------------------"<<endl;
}


void TestComponents() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                      Test Components                      |"<<endl;
  cout<<"|                        测试连通分量                         |"<<endl;
  cout<<"|  节点:                                                     |"<<endl;
  cout<<"|    0, 1, 2, 3                                             |"<<endl;
  cout<<"|  边:                                                      |"<<endl;
  cout<<"|    0-1权值: 0.8                                            |"<<endl<<endl;
  cout<<"|    2-3权值: 7.3                                            |"<<endl<<endl;

  AdjacencyListGraph<int, double> adjacency_list_graph(10, 10000);

  adjacency_list_graph.InsertVertex(0);
  adjacency_list_graph.InsertVertex(1);
  adjacency_list_graph.InsertVertex(2);
  adjacency_list_graph.InsertVertex(3);

  adjacency_list_graph.InsertEdge(0, 1, 0.8);
  adjacency_list_graph.InsertEdge(2, 3, 7.3);

  MatrixGraph<int, double> matrix_graph(10, 10000);

  matrix_graph.InsertVertex(0);
  matrix_graph.InsertVertex(1);
  matrix_graph.InsertVertex(2);
  matrix_graph.InsertVertex(3);

  matrix_graph.InsertEdge(0, 1, 0.8);
  matrix_graph.InsertEdge(2, 3, 7.3);

  cout<<"**邻接表图测试**"<<endl;
  Components(adjacency_list_graph);

  cout<<endl<<"**矩阵图测试**"<<endl;
  Components(matrix_graph);

  cout<<"-------------------------------------------------------------"<<endl;
}


void TestKruskal() {
    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|                        Test Kruskal                       |"<<endl;
    cout<<"|                       测试Kruskal算法                      |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                           北京                               |"<<endl;
    cout<<"|                           / \\                               |"<<endl;
    cout<<"|                          /   \\                              |"<<endl;
    cout<<"|                        0.1   0.12                           |"<<endl;
    cout<<"|                        /       \\                            |"<<endl;
    cout<<"|                       /         \\                           |"<<endl;
    cout<<"|                    上海---0.01---广州                       |"<<endl;
    cout<<"|                     / \\         / \\                         |"<<endl;
    cout<<"|                    /   \\       /   \\                        |"<<endl;
    cout<<"|                 0.13  0.14   0.05  0.17                    |"<<endl;
    cout<<"|                  /       \\   /       \\                      |"<<endl;
    cout<<"|                 /         \\ /         \\                     |"<<endl;
    cout<<"|              杭州-- 0.09 --深圳-- 0.11 --成都                 |"<<endl;
    cout<<endl;

    unsigned int edge_count = 9;

    // 结点信息
    vector<string> vertices{ "北京", "上海", "广州", "深圳", "杭州", "成都" };

    // 边信息
    vector<string> starting_vertices{ "北京",  "北京", "上海", "上海", "上海", "广州", "广州", "深圳", "深圳" };
    vector<string> ending_vertices{ "上海", "广州", "广州", "深圳", "杭州", "深圳", "成都", "杭州", "成都" };
    vector<double> weights{ 0.1, 0.12, 0.01, 0.14, 0.13, 0.05, 0.17, 0.09, 0.11 };    // 边权重数组

    vector<Edge<string, double> > edges;
    for (unsigned int i = 0; i < edge_count; i++) {
        Edge<string, double> edge(starting_vertices[i], ending_vertices[i], weights[i]);
        edges.push_back(edge);
    }

    AdjacencyListGraph<string, double> adjacency_list_graph(10, 1000, edges, vertices); // 构造邻接表图
    MatrixGraph<string, double> matrix_graph(10, 1000, edges, vertices);                // 构造矩阵图

    MinimumSpanTree<string, double> min_span_tree_adj(100);
    MinimumSpanTree<string, double> min_span_tree_matrix(100);

    cout << "**邻接表图测试**" << endl;
    Kruskal(adjacency_list_graph, min_span_tree_adj);
    min_span_tree_adj.Print();

    cout << endl << "**矩阵图测试**" << endl;
    Kruskal(matrix_graph, min_span_tree_matrix);

    min_span_tree_matrix.Print();
    cout << "-------------------------------------------------------------" << endl;
}


void TestPrim() {
    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|                         Test Prim                         |"<<endl;
    cout<<"|                        测试Prim算法                        |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                           北京                             |"<<endl;
    cout<<"|                           / \\                               |"<<endl;
    cout<<"|                          /   \\                              |"<<endl;
    cout<<"|                        0.1   0.12                          |"<<endl;
    cout<<"|                        /       \\                            |"<<endl;
    cout<<"|                       /         \\                           |"<<endl;
    cout<<"|                    上海---0.01---广州                       |"<<endl;
    cout<<"|                     / \\         / \\                         |"<<endl;
    cout<<"|                    /   \\       /   \\                        |"<<endl;
    cout<<"|                 0.13  0.14   0.05  0.17                    |"<<endl;
    cout<<"|                  /       \\   /       \\                      |"<<endl;
    cout<<"|                 /         \\ /         \\                     |"<<endl;
    cout<<"|              杭州-- 0.09 --深圳-- 0.11 --成都                 |"<<endl;
    cout<<endl;

    unsigned int edge_count = 9;

    // 结点信息
    vector<string> vertices{ "北京", "上海", "广州", "深圳", "杭州", "成都" };

    // 边信息
    vector<string> starting_vertices{ "北京",  "北京", "上海", "上海", "上海", "广州", "广州", "深圳", "深圳" };
    vector<string> ending_vertices{ "上海", "广州", "广州", "深圳", "杭州", "深圳", "成都", "杭州", "成都" };
    vector<double> weights{ 0.1, 0.12, 0.01, 0.14, 0.13, 0.05, 0.17, 0.09, 0.11 };    // 边权重数组

    vector<Edge<string, double> > edges;
    for (unsigned int i = 0; i < edge_count; i++) {
        Edge<string, double> edge(starting_vertices[i], ending_vertices[i], weights[i]);
        edges.push_back(edge);
    }

    AdjacencyListGraph<string, double> adjacency_list_graph(10, 1000, edges, vertices); // 构造邻接表图
    MatrixGraph<string, double> matrix_graph(10, 1000, edges, vertices);                // 构造矩阵图

    cout<<endl<<"**邻接表图测试**"<<endl;
    MinimumSpanTree<string, double> min_span_tree_adj(100);
    Prim(adjacency_list_graph, min_span_tree_adj);
    min_span_tree_adj.Print();

    cout<<endl<<"**矩阵图测试**"<<endl;
    MinimumSpanTree<string, double> min_span_tree_matrix(100);
    Prim(matrix_graph, min_span_tree_matrix);
    min_span_tree_matrix.Print();

    cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void TestDijkstra() {
    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|                       Test Dijkstra                       |"<<endl;
    cout<<"|                     测试Dijkstra最短路径                    |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                           北京                             |"<<endl;
    cout<<"|                           / \\                               |"<<endl;
    cout<<"|                          /   \\                              |"<<endl;
    cout<<"|                        0.1   0.12                          |"<<endl;
    cout<<"|                        /       \\                            |"<<endl;
    cout<<"|                       /         \\                           |"<<endl;
    cout<<"|                    上海---0.01---广州                       |"<<endl;
    cout<<"|                     / \\         / \\                         |"<<endl;
    cout<<"|                    /   \\       /   \\                        |"<<endl;
    cout<<"|                 0.13  0.14   0.05  0.17                    |"<<endl;
    cout<<"|                  /       \\   /       \\                      |"<<endl;
    cout<<"|                 /         \\ /         \\                     |"<<endl;
    cout<<"|              杭州-- 0.09 --深圳-- 0.11 --成都                 |"<<endl;
    cout<<endl;

    unsigned int edge_count = 9;

    // 结点信息
    vector<string> vertices{ "北京", "上海", "广州", "深圳", "杭州", "成都" };

    // 边信息
    vector<string> starting_vertices{ "北京", "北京", "上海", "上海", "上海", "广州", "广州", "深圳", "深圳" };
    vector<string> ending_vertices{   "上海", "广州", "广州", "深圳", "杭州", "深圳", "成都", "杭州", "成都" };
    vector<double> weights{ 0.1, 0.12, 0.01, 0.14, 0.13, 0.05, 0.17, 0.09, 0.11 };    // 边权重数组

    vector<Edge<string, double> > edges;
    for (unsigned int i = 0; i < edge_count; i++) {
        Edge<string, double> edge(starting_vertices[i], ending_vertices[i], weights[i]);
        edges.push_back(edge);
    }

    cout<<endl<<"**邻接表图Dijkstra测试**"<<endl<<endl;
    AdjacencyListGraph<string, double> adjacency_list_graph(10, 1000, edges, vertices); // 构造邻接表图
    double adjacency_list_graph_min_distances[10];
    int adjacency_list_graph_predecessors[10];

    Dijkstra(adjacency_list_graph, vertices[0], adjacency_list_graph_min_distances, adjacency_list_graph_predecessors);
    PrintSingleSourceShortestPath(adjacency_list_graph, vertices[0], adjacency_list_graph_min_distances, adjacency_list_graph_predecessors);

    cout<<endl<<"**矩阵图测试**"<<endl<<endl;
    MatrixGraph<string, double> matrix_graph(1, 10, 1000, edges, vertices);                // 构造矩阵图
    double matrix_graph_min_distances[10];
    int matrix_graph_predecessors[10];

    Dijkstra(matrix_graph, vertices[0], matrix_graph_min_distances, matrix_graph_predecessors);
    PrintSingleSourceShortestPath(matrix_graph, vertices[0], matrix_graph_min_distances, matrix_graph_predecessors);

    cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void TestBellmanFord() {
    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|                      Test BellmanFord                     |"<<endl;
    cout<<"|                    测试BellmanFord最短路径                  |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                           北京                             |"<<endl;
    cout<<"|                           / \\                               |"<<endl;
    cout<<"|                          /   \\                              |"<<endl;
    cout<<"|                        0.1   0.12                          |"<<endl;
    cout<<"|                        /       \\                            |"<<endl;
    cout<<"|                       /         \\                           |"<<endl;
    cout<<"|                    上海---0.01---广州                       |"<<endl;
    cout<<"|                     / \\         / \\                         |"<<endl;
    cout<<"|                    /   \\       /   \\                        |"<<endl;
    cout<<"|                 0.13  0.14   0.05  0.17                    |"<<endl;
    cout<<"|                  /       \\   /       \\                      |"<<endl;
    cout<<"|                 /         \\ /         \\                     |"<<endl;
    cout<<"|              杭州-- 0.09 --深圳-- 0.11 --成都                 |"<<endl;
    cout<<endl;

    unsigned int edge_count = 9;

    // 结点信息
    vector<string> vertices{ "北京", "上海", "广州", "深圳", "杭州", "成都" };

    // 边信息
    vector<string> starting_vertices{ "北京",  "北京", "上海", "上海", "上海", "广州", "广州", "深圳", "深圳" };
    vector<string> ending_vertices{ "上海", "广州", "广州", "深圳", "杭州", "深圳", "成都", "杭州", "成都" };
    vector<double> weights{ 0.1, 0.12, 0.01, 0.14, 0.13, 0.05, 0.17, 0.09, 0.11 };    // 边权重数组

    vector<Edge<string, double> > edges;
    for (unsigned int i = 0; i < edge_count; i++) {
        Edge<string, double> edge(starting_vertices[i], ending_vertices[i], weights[i]);
        edges.push_back(edge);
    }

    AdjacencyListGraph<string, double> adjacency_list_graph(10, 1000, edges, vertices); // 构造邻接表图
    MatrixGraph<string, double> matrix_graph(10, 1000, edges, vertices);                // 构造矩阵图

    double adjacency_list_graph_min_distances[10];
    int adjacency_list_graph_predecessors[10];

    BellmanFord(adjacency_list_graph, vertices[0], adjacency_list_graph_min_distances, adjacency_list_graph_predecessors);
    PrintSingleSourceShortestPath(adjacency_list_graph, vertices[0], adjacency_list_graph_min_distances, adjacency_list_graph_predecessors);

    cout<<endl<<"**矩阵图测试**"<<endl<<endl;
    double matrix_graph_min_dists[10];
    int matrix_graph_predecessors[10];

    BellmanFord(matrix_graph, vertices[0], matrix_graph_min_dists, matrix_graph_predecessors);
    PrintSingleSourceShortestPath(matrix_graph, vertices[0], matrix_graph_min_dists, matrix_graph_predecessors);

    cout<<"-------------------------------------------------------------"<<endl<<endl;
}


/*! 测试Floyd最短路径 */
void TestFloyd() {
    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|                    Test Floyd-Warshall                    |"<<endl;
    cout<<"|                     测试弗洛伊德最短路径                     |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                           北京                             |"<<endl;
    cout<<"|                           / \\                               |"<<endl;
    cout<<"|                          /   \\                              |"<<endl;
    cout<<"|                        0.1   0.12                          |"<<endl;
    cout<<"|                        /       \\                            |"<<endl;
    cout<<"|                       /         \\                           |"<<endl;
    cout<<"|                    上海---0.01---广州                       |"<<endl;
    cout<<"|                     / \\         / \\                         |"<<endl;
    cout<<"|                    /   \\       /   \\                        |"<<endl;
    cout<<"|                 0.13  0.14   0.05  0.17                    |"<<endl;
    cout<<"|                  /       \\   /       \\                      |"<<endl;
    cout<<"|                 /         \\ /         \\                     |"<<endl;
    cout<<"|              杭州-- 0.09 --深圳-- 0.11 --成都                 |"<<endl;
    cout<<endl;

    unsigned int edge_count = 9;

    // 结点信息
    vector<string> vertices{ "北京", "上海", "广州", "深圳", "杭州", "成都" };

    // 边信息
    vector<string> starting_vertices{ "北京", "北京", "上海", "上海", "上海", "广州", "广州", "深圳", "深圳" };
    vector<string> ending_vertices  { "上海", "广州", "广州", "深圳", "杭州", "深圳", "成都", "杭州", "成都" };
    vector<double> weights          {  0.1,   0.12,   0.01,  0.14,   0.13,  0.05,  0.17,   0.09,  0.11  };

    vector<Edge<string, double> > edges;
    for (unsigned int i = 0; i < edge_count; i++) {
        Edge<string, double> edge(starting_vertices[i], ending_vertices[i], weights[i]);
        edges.push_back(edge);
    }

    AdjacencyListGraph<string, double> adjacency_list_graph(1, 10, 1000, edges, vertices); // 构造邻接表图
    MatrixGraph<string, double> matrix_graph(1, 10, 1000, edges, vertices);                // 构造矩阵图

    cout<<endl<<"**邻接表图测试**"<<endl<<endl;

    // 邻接表图distance
    vector<vector<double> > adjacency_list_graph_distances(adjacency_list_graph.VertexCount(),
                                                           vector<double>(adjacency_list_graph.VertexCount()));
    // 邻接表图predecessor
    vector<vector<int> > adjacency_list_graph_predecessors(adjacency_list_graph.VertexCount(),
                                                           vector<int>(adjacency_list_graph.VertexCount()));

    // 执行弗洛伊德算法
    Floyd(adjacency_list_graph, adjacency_list_graph_distances, adjacency_list_graph_predecessors);

    // 打印多源(MSSP)最短路径
    PrintMultipleSourceShortestPath(adjacency_list_graph,
                                    adjacency_list_graph_distances,
                                    adjacency_list_graph_predecessors);

    cout<<endl<<"**矩阵图测试**"<<endl<<endl;

    // matrix_graph_min_distances
    vector<vector<double> > matrix_graph_min_distances(matrix_graph.VertexCount(),
                                                       vector<double>(matrix_graph.VertexCount()));
    // matrix_graph_predecessors
    vector<vector<int> > matrix_graph_predecessors(matrix_graph.VertexCount(),
                                                   vector<int>(matrix_graph.VertexCount()));

    for (unsigned int i = 0; i < matrix_graph.VertexCount(); i++) {
        for (unsigned int j = 0; j < matrix_graph.VertexCount(); j++) {
            matrix_graph_predecessors[i][j] = -1;
        }
    }

    // 执行弗洛伊德算法
    Floyd(matrix_graph, matrix_graph_min_distances, matrix_graph_predecessors);

    // 打印多源最短路径
    PrintMultipleSourceShortestPath(matrix_graph,
                                    matrix_graph_min_distances,
                                    matrix_graph_predecessors);

    cout << "-------------------------------------------------------------" << endl << endl;
}


void TestTopologicalSort() {
    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|                       Test TopologySort                       |"<<endl;
    cout<<"|                         测试拓扑排序                    |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                           北京                             |"<<endl;
    cout<<"|                           / \\                               |"<<endl;
    cout<<"|                          /   \\                              |"<<endl;
    cout<<"|                        0.1   0.12                          |"<<endl;
    cout<<"|                        /       \\                            |"<<endl;
    cout<<"|                       /         \\                           |"<<endl;
    cout<<"|                    上海---0.01---广州                       |"<<endl;
    cout<<"|                     / \\         / \\                         |"<<endl;
    cout<<"|                    /   \\       /   \\                        |"<<endl;
    cout<<"|                 0.13  0.14   0.05  0.17                    |"<<endl;
    cout<<"|                  /       \\   /       \\                      |"<<endl;
    cout<<"|                 /         \\ /         \\                     |"<<endl;
    cout<<"|              杭州-- 0.09 --深圳-- 0.11 --成都                 |"<<endl;
    cout<<endl;


    unsigned int edge_count = 9;

    // 结点信息
    vector<string> vertices{ "北京", "上海", "广州", "深圳", "杭州", "成都" };

    // 边信息
    vector<string> starting_vertices{ "北京", "北京", "上海", "上海", "上海", "广州", "广州", "深圳", "深圳" };
    vector<string> ending_vertices  { "上海", "广州", "广州", "深圳", "杭州", "深圳", "成都", "杭州", "成都" };
    vector<double> weights          {  0.1,   0.12,   0.01,  0.14,   0.13,  0.05,  0.17,   0.09,  0.11  };

    vector<Edge<string, double> > edges;
    for (unsigned int i = 0; i < edge_count; i++) {
        Edge<string, double> edge(starting_vertices[i], ending_vertices[i], weights[i]);
        edges.push_back(edge);
    }

    AdjacencyListGraph<string, double> adjacency_list_graph(1, 10, 1000, edges, vertices); // 构造邻接表图
    MatrixGraph<string, double> matrix_graph(1, 10, 1000, edges, vertices);                // 构造矩阵图

    cout<<endl<<"**邻接表图测试**"<<endl<<endl;

    vector<string> topology_sorted_list;
    bool res = TopologicalSort(adjacency_list_graph, vertices[0], topology_sorted_list);

    if (res) {
        for (auto iter = topology_sorted_list.begin(); iter != topology_sorted_list.end(); iter++) {
            cout<<*iter<<' ';
        }
        cout<<endl;
    } else {
        cout<<"拓扑排序失败"<<endl;
    }

    cout<<endl<<"**矩阵图测试**"<<endl<<endl;

    topology_sorted_list.clear();
    res = TopologicalSort(matrix_graph, vertices[0], topology_sorted_list);

    if (res) {
        for (auto iter = topology_sorted_list.begin(); iter != topology_sorted_list.end(); iter++) {
            cout<<*iter<<' ';
        }
        cout<<endl;
    } else {
        cout<<"拓扑排序失败"<<endl;
    }

    cout << "-------------------------------------------------------------" << endl << endl;
}


void TestCriticalPaths() {
    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|                     Test CriticalPaths                       |"<<endl;
    cout<<"|                         测试关键路径                    |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                           北京                             |"<<endl;
    cout<<"|                           / \\                               |"<<endl;
    cout<<"|                          /   \\                              |"<<endl;
    cout<<"|                        0.1   0.12                          |"<<endl;
    cout<<"|                        /       \\                            |"<<endl;
    cout<<"|                       /         \\                           |"<<endl;
    cout<<"|                    上海---0.01---广州                       |"<<endl;
    cout<<"|                     / \\         / \\                         |"<<endl;
    cout<<"|                    /   \\       /   \\                        |"<<endl;
    cout<<"|                 0.13  0.14   0.05  0.17                    |"<<endl;
    cout<<"|                  /       \\   /       \\                      |"<<endl;
    cout<<"|                 /         \\ /         \\                     |"<<endl;
    cout<<"|              杭州-- 0.09 --深圳-- 0.11 --成都                 |"<<endl;
    cout<<endl;


    unsigned int edge_count = 9;

    // 结点信息
    vector<string> vertices{ "北京", "上海", "广州", "深圳", "杭州", "成都" };

    // 边信息
    vector<string> starting_vertices{ "北京", "北京", "上海", "上海", "上海", "广州", "广州", "深圳", "深圳" };
    vector<string> ending_vertices  { "上海", "广州", "广州", "深圳", "杭州", "深圳", "成都", "杭州", "成都" };
    vector<double> weights          {  0.1,   0.12,   0.01,  0.14,   0.13,  0.05,  0.17,   0.09,  0.11  };

    vector<Edge<string, double> > edges;
    for (unsigned int i = 0; i < edge_count; i++) {
        Edge<string, double> edge(starting_vertices[i], ending_vertices[i], weights[i]);
        edges.push_back(edge);
    }

    AdjacencyListGraph<string, double> adjacency_list_graph(Graph<string, double>::DIRECTED, 10, 1000, edges, vertices); // 构造邻接表图
    MatrixGraph<string, double> matrix_graph(Graph<string, double>::DIRECTED, 10, 1000, edges, vertices);                // 构造矩阵图

    string starting_vertex = vertices[0];

    cout<<endl<<"**邻接表图测试**"<<endl<<endl;
    vector<double> critical_paths = GetCriticalPath(adjacency_list_graph, starting_vertex);
    for (unsigned int i = 0; i < critical_paths.size(); i++) {
        cout<<"北京 ---> "<<vertices[i]<<" 关键路径长度: "<<critical_paths[i]<<endl;
    }

    cout<<endl<<"**矩阵图测试**"<<endl<<endl;
    critical_paths = GetCriticalPath(matrix_graph, starting_vertex);
    for (unsigned int i = 0; i < critical_paths.size(); i++) {
        cout<<"北京 ---> "<<vertices[i]<<" 关键路径长度: "<<critical_paths[i]<<endl;
    }

    cout << "-------------------------------------------------------------" << endl << endl;
}
