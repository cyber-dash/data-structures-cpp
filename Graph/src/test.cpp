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


/*!
 * @brief **测试-图-基础函数**
 * @note
 * 测试-图-基础函数
 * --------------
 * --------------
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
 *
 *
 * --------------
 */
void TestBaseFunctions() {
    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|                  Test Graph BaseFunctions                 |"<<endl;
    cout<<"|                     测试-图-基础函数                      |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                           北京                            |"<<endl;
    cout<<"|                           / \\                             |"<<endl;
    cout<<"|                          /   \\                            |"<<endl;
    cout<<"|                        0.1   0.12                         |"<<endl;
    cout<<"|                        /       \\                          |"<<endl;
    cout<<"|                       /         \\                         |"<<endl;
    cout<<"|                    上海---0.01---广州                     |"<<endl;
    cout<<"|                     / \\         / \\                       |"<<endl;
    cout<<"|                    /   \\       /   \\                      |"<<endl;
    cout<<"|                 0.13  0.14   0.05  0.17                   |"<<endl;
    cout<<"|                  /       \\   /       \\                    |"<<endl;
    cout<<"|                 /         \\ /         \\                   |"<<endl;
    cout<<"|             杭州--0.09-- 深圳 --0.11--成都                |"<<endl;
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
    cout << "---------- 1 邻接表有向图删除结点 ----------" << endl << endl;
    adjacency_list_directed_graph.RemoveVertex("北京");
    adjacency_list_directed_graph.RemoveVertex("上海");
    adjacency_list_directed_graph.RemoveVertex("深圳");
    cout << adjacency_list_directed_graph << endl << endl;

    // 构造adjacency_list_undirected_graph(邻接表无向图)
    AdjacencyListGraph<string, double> adjacency_list_undirected_graph(Graph<string, double>::UNDIRECTED, 10, 1000, edges, vertices);

    // 依次删除1个城市, 然后打印图
    cout << "---------- 2 邻接表无向图删除结点 ----------" << endl << endl;
    adjacency_list_undirected_graph.RemoveVertex("北京");
    adjacency_list_undirected_graph.RemoveVertex("上海");
    adjacency_list_undirected_graph.RemoveVertex("深圳");
    cout << adjacency_list_undirected_graph << endl << endl;

    // 构造matrix_directed_graph(矩阵有向图)
    MatrixGraph<string, double> matrix_directed_graph(Graph<string, double>::DIRECTED, 10, 1000, edges, vertices);

    // 依次删除1个城市, 然后打印图
    cout << "---------- 3 矩阵有向图删除结点 ----------" << endl << endl;
    matrix_directed_graph.RemoveVertex("北京");
    matrix_directed_graph.RemoveVertex("上海");
    matrix_directed_graph.RemoveVertex("深圳");
    cout << matrix_directed_graph << endl << endl;

    // 构造matrix_undirected_graph(矩阵无向图)
    MatrixGraph<string, double> matrix_undirected_graph(Graph<string, double>::UNDIRECTED, 10, 1000, edges, vertices);

    // 依次删除1个城市, 然后打印图
    cout << "---------- 4 矩阵无向图删除结点 ----------" << endl << endl;
    matrix_undirected_graph.RemoveVertex("北京");
    matrix_undirected_graph.RemoveVertex("上海");
    matrix_undirected_graph.RemoveVertex("深圳");
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
    cout<<"|                Test MatrixGraph PrintMatrix               |"<<endl;
    cout<<"|                    测试-矩阵图-打印矩阵                   |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                           北京                            |"<<endl;
    cout<<"|                           / \\                             |"<<endl;
    cout<<"|                          /   \\                            |"<<endl;
    cout<<"|                        0.1   0.12                         |"<<endl;
    cout<<"|                        /       \\                          |"<<endl;
    cout<<"|                       /         \\                         |"<<endl;
    cout<<"|                    上海---0.01---广州                     |"<<endl;
    cout<<"|                     / \\         / \\                       |"<<endl;
    cout<<"|                    /   \\       /   \\                      |"<<endl;
    cout<<"|                 0.13  0.14   0.05  0.17                   |"<<endl;
    cout<<"|                  /       \\   /       \\                    |"<<endl;
    cout<<"|                 /         \\ /         \\                   |"<<endl;
    cout<<"|             杭州--0.09-- 深圳 --0.11--成都                |"<<endl;
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

    cout << "打印矩阵:" << endl << endl;
    matrix_graph.PrintMatrix();

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
 * + **2 测试邻接表图深度优先遍历**\n\n
 * 构造adjacency_list_graph(邻接表无向图)\n
 * 以"北京"为起点进行深度优先遍历\n\n
 * + **3 测试矩阵图深度优先遍历**\n\n
 * 构造matrix_graph(矩阵无向图)\n
 * 以"北京"为起点进行深度优先遍历\n
 *
 *
 * -----------------------
 */
void TestDfsRecursive() {
    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|                  Test Graph Dfs                  |"<<endl;
    cout<<"|                 测试-图-深度优先遍历(递归)                |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                           北京                            |"<<endl;
    cout<<"|                           / \\                             |"<<endl;
    cout<<"|                          /   \\                            |"<<endl;
    cout<<"|                        0.1   0.12                         |"<<endl;
    cout<<"|                        /       \\                          |"<<endl;
    cout<<"|                       /         \\                         |"<<endl;
    cout<<"|                    上海---0.01---广州                     |"<<endl;
    cout<<"|                     / \\         / \\                       |"<<endl;
    cout<<"|                    /   \\       /   \\                      |"<<endl;
    cout<<"|                 0.13  0.14   0.05  0.17                   |"<<endl;
    cout<<"|                  /       \\   /       \\                    |"<<endl;
    cout<<"|                 /         \\ /         \\                   |"<<endl;
    cout<<"|             杭州--0.09-- 深圳 --0.11--成都                |"<<endl;
    cout<<endl;

    // ---------- 1 初始化图的基本信息 ----------

    // 初始化结点信息(北京, 上海, 广州, 深圳, 杭州, 成都 6座城市)
    unsigned int edge_count = 9;

    vector<string> vertices{ "北京", "上海", "广州", "深圳", "杭州", "成都" };

    vector<string> starting_vertices{ "北京",  "北京", "上海", "上海", "上海", "广州", "广州", "深圳", "深圳" };
    vector<string> ending_vertices{ "上海", "广州", "广州", "深圳", "杭州", "深圳", "成都", "杭州", "成都" };
    vector<double> weights{ 0.1, 0.12, 0.01, 0.14, 0.13, 0.05, 0.17, 0.09, 0.11 };

    // 初始化边信息
    vector<Edge<string, double> > edges;
    for (unsigned int i = 0; i < edge_count; i++) {
        Edge<string, double> edge(starting_vertices[i], ending_vertices[i], weights[i]);
        edges.push_back(edge);
    }

    // ---------- 2 测试邻接表图深度优先遍历 ----------

    cout<<"---------- 邻接表图 ----------"<<endl;
    AdjacencyListGraph<string, double> adjacency_list_graph(10, 1000, edges, vertices); // 构造adjacency_list_graph(邻接表无向图)
    Dfs(adjacency_list_graph, vertices[0]);                                    // "北京"为起点进行深度优先遍历

    // ---------- 3 测试矩阵图深度优先遍历 ----------

    cout<<endl<<"---------- 矩阵图 ----------"<<endl;
    MatrixGraph<string, double> matrix_graph(10, 1000, edges, vertices);                // 构造matrix_graph(矩阵无向图)
    Dfs(matrix_graph, vertices[0]);                                            // 以"北京"为起点进行深度优先遍历

    cout<<"-------------------------------------------------------------"<<endl;
}


/*!
 * @brief **测试-图-广度优先遍历**
 * @note
 * 测试-图-广度优先遍历
 * -----------------
 * -----------------
 *
 * -----------------
 *
 *
 * -----------------
 * + **1 初始化图的基本信息**\n\n
 * 初始化结点信息(北京, 上海, 广州, 深圳, 杭州, 成都 6座城市)\n
 * 初始化边信息\n\n
 * + **2 测试邻接表图广度优先遍历**\n\n
 * 构造adjacency_list_undirected_graph(邻接表无向图)\n
 * 以"北京"为起点进行bfs遍历\n\n
 * + **3 测试矩阵图广度优先遍历**\n\n
 * 构造matrix_undirected_graph(矩阵无向图)\n
 * 以"北京"为起点进行bfs遍历\n
 */
void TestBFS() {
    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|                       Test Graph Bfs                      |"<<endl;
    cout<<"|                    测试-图-广度优先遍历                   |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                           北京                            |"<<endl;
    cout<<"|                           / \\                             |"<<endl;
    cout<<"|                          /   \\                            |"<<endl;
    cout<<"|                        0.1   0.12                         |"<<endl;
    cout<<"|                        /       \\                          |"<<endl;
    cout<<"|                       /         \\                         |"<<endl;
    cout<<"|                    上海---0.01---广州                     |"<<endl;
    cout<<"|                     / \\         / \\                       |"<<endl;
    cout<<"|                    /   \\       /   \\                      |"<<endl;
    cout<<"|                 0.13  0.14   0.05  0.17                   |"<<endl;
    cout<<"|                  /       \\   /       \\                    |"<<endl;
    cout<<"|                 /         \\ /         \\                   |"<<endl;
    cout<<"|             杭州--0.09-- 深圳 --0.11--成都                |"<<endl;
    cout<<endl;

    // ---------- 1 初始化图的基本信息 ----------

    unsigned int edge_count = 9;

    // 初始化结点信息(北京, 上海, 广州, 深圳, 杭州, 成都 6座城市)
    vector<string> vertices{ "北京", "上海", "广州", "深圳", "杭州", "成都" };

    // 初始化边信息
    vector<string> starting_vertices{ "北京",  "北京", "上海", "上海", "上海", "广州", "广州", "深圳", "深圳" };
    vector<string> ending_vertices{ "上海", "广州", "广州", "深圳", "杭州", "深圳", "成都", "杭州", "成都" };
    vector<double> weights{ 0.1, 0.12, 0.01, 0.14, 0.13, 0.05, 0.17, 0.09, 0.11 };

    vector<Edge<string, double> > edges;
    for (unsigned int i = 0; i < edge_count; i++) {
        Edge<string, double> edge(starting_vertices[i], ending_vertices[i], weights[i]);
        edges.push_back(edge);
    }

    // ---------- 2 测试邻接表图广度优先遍历 ----------

    cout<<"---------- 邻接表图 ----------"<<endl;
    AdjacencyListGraph<string, double> adjacency_list_undirected_graph(10, 1000, edges, vertices);  // 构造adjacency_list_undirected_graph(邻接表无向图)
    Bfs(adjacency_list_undirected_graph, vertices[0]);                                              // 以"北京"为起点进行bfs遍历

    // ---------- 3 测试矩阵图广度优先遍历 ----------

    cout<<endl<<"---------- 矩阵图 ----------"<<endl;
    MatrixGraph<string, double> matrix_undirected_graph(10, 1000, edges, vertices);                 // 构造matrix_undirected_graph(矩阵无向图)
    Bfs(matrix_undirected_graph, vertices[0]);                                                      // 以"北京"为起点进行bfs遍历

    cout<<"-------------------------------------------------------------"<<endl;
}


/*!
 * @brief **测试-图-连通分量**
 * @note
 * 测试-图-连通分量
 * --------------
 * --------------
 *
 * --------------
 *
 *
 * --------------
 * + **1 构造邻接表图**\n\n
 * 声明adjacency_list_graph(邻接表图)\n
 * 插入结点0, 1, 2, 3\n
 * 插入边(0 , 1)和边(2, 3)\n\n
 * + **2 构造矩阵图**\n\n
 * 声明matrix_graph(矩阵图)\n
 * 插入结点0, 1, 2, 3\n
 * 插入边(0 , 1)和边(2, 3)\n\n
 * + **3 邻接表图求连通分量**\n\n
 * 调用Components\n\n
 * + **4 矩阵图求连通分量**\n\n
 * 调用Components\n\n
 *
 *
 * --------------
 */
void TestComponents() {

    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|                   Test Graph Components                   |"<<endl;
    cout<<"|                      测试-图-连通分量                     |"<<endl;
    cout<<"|  节点:                                                    |"<<endl;
    cout<<"|    0, 1, 2, 3                                             |"<<endl;
    cout<<"|  边:                                                      |"<<endl;
    cout<<"|    0-1权值: 0.8                                           |"<<endl;
    cout<<"|    2-3权值: 7.3                                           |"<<endl<<endl;

    // ---------- 1 构造邻接表图 ----------

    // 声明adjacency_list_graph(邻接表图)
    AdjacencyListGraph<int, double> adjacency_list_graph(10, 10000);

    // 插入结点0, 1, 2, 3
    adjacency_list_graph.InsertVertex(0);
    adjacency_list_graph.InsertVertex(1);
    adjacency_list_graph.InsertVertex(2);
    adjacency_list_graph.InsertVertex(3);

    // 插入边(0 , 1)和边(2, 3)
    adjacency_list_graph.InsertEdge(0, 1, 0.8);
    adjacency_list_graph.InsertEdge(2, 3, 7.3);

    // ---------- 2 构造矩阵图 ----------

    // 声明matrix_graph(矩阵图)
    MatrixGraph<int, double> matrix_graph(10, 10000);

    // 插入结点0, 1, 2, 3
    matrix_graph.InsertVertex(0);
    matrix_graph.InsertVertex(1);
    matrix_graph.InsertVertex(2);
    matrix_graph.InsertVertex(3);

    // 插入边(0 , 1)和边(2, 3)
    matrix_graph.InsertEdge(0, 1, 0.8);
    matrix_graph.InsertEdge(2, 3, 7.3);

    // ---------- 3 邻接表图求连通分量 ----------
    cout<<"---------- 邻接表图 ----------"<<endl;
    Components(adjacency_list_graph);                           // 调用Components

    // ---------- 4 矩阵图求连通分量 ----------
    cout<<"---------- 矩阵图 ----------"<<endl;
    Components(matrix_graph);                                   // 调用Components

    cout<<"-------------------------------------------------------------"<<endl;
}


/*!
 * @brief **测试-图-最小生成树Kruskal**
 * @note
 * 测试-图-最小生成树Kruskal
 * ----------------------
 * ----------------------
 *
 * ----------------------
 * + **1 初始化图的基本信息**\n\n
 * 初始化结点信息(北京, 上海, 广州, 深圳, 杭州, 成都 6座城市)\n
 * 初始化边信息\n\n
 * + **2 测试邻接表图Kruskal**\n\n
 * 构造adjacency_list_undirected_graph(邻接表无向图)\n
 * 初始化adj_min_span_tree(邻接表图的最小生成树)\n\n
 * 调用Kruskal求最小生成树\n
 * 打印最小生成树\n\n
 * + **3 测试矩阵图Kruskal**\n\n
 * 构造matrix_undirected_graph(矩阵无向图)\n
 * 初始化matrix_min_span_tree(矩阵图的最小生成树)\n\n
 * 调用Kruskal求最小生成树\n
 * 打印最小生成树\n\n
 *
 *
 * -------------------
 */
void TestKruskal() {
    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|                     Test Graph Kruskal                    |"<<endl;
    cout<<"|                  测试-图-最小生成树Kruskal                |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                           北京                            |"<<endl;
    cout<<"|                           / \\                             |"<<endl;
    cout<<"|                          /   \\                            |"<<endl;
    cout<<"|                        0.1   0.12                         |"<<endl;
    cout<<"|                        /       \\                          |"<<endl;
    cout<<"|                       /         \\                         |"<<endl;
    cout<<"|                    上海---0.01---广州                     |"<<endl;
    cout<<"|                     / \\         / \\                       |"<<endl;
    cout<<"|                    /   \\       /   \\                      |"<<endl;
    cout<<"|                 0.13  0.14   0.05  0.17                   |"<<endl;
    cout<<"|                  /       \\   /       \\                    |"<<endl;
    cout<<"|                 /         \\ /         \\                   |"<<endl;
    cout<<"|             杭州--0.09-- 深圳 --0.11--成都                |"<<endl;
    cout<<endl;

    // ---------- 1 初始化图的基本信息 ----------

    unsigned int edge_count = 9;

    // 初始化结点信息(北京, 上海, 广州, 深圳, 杭州, 成都 6座城市)
    vector<string> vertices{ "北京", "上海", "广州", "深圳", "杭州", "成都" };

    // 初始化边信息
    vector<string> starting_vertices{ "北京",  "北京", "上海", "上海", "上海", "广州", "广州", "深圳", "深圳" };
    vector<string> ending_vertices{ "上海", "广州", "广州", "深圳", "杭州", "深圳", "成都", "杭州", "成都" };
    vector<double> weights{ 0.1, 0.12, 0.01, 0.14, 0.13, 0.05, 0.17, 0.09, 0.11 };

    vector<Edge<string, double> > edges;
    for (unsigned int i = 0; i < edge_count; i++) {
        Edge<string, double> edge(starting_vertices[i], ending_vertices[i], weights[i]);
        edges.push_back(edge);
    }

    // ---------- 2 测试邻接表图Kruskal ----------

    cout<<"---------- 邻接表图 ----------"<<endl;
    AdjacencyListGraph<string, double> adjacency_list_graph(10, 1000, edges, vertices);     // 构造adjacency_list_undirected_graph(邻接表无向图)
    MinimumSpanTree<string, double> adj_min_span_tree(100);                                 // 初始化adj_min_span_tree(邻接表图的最小生成树)
    Kruskal(adjacency_list_graph, adj_min_span_tree);                                       // 调用Kruskal求最小生成树
    adj_min_span_tree.Print();                                                              // 打印最小生成树

    // ---------- 3 测试矩阵图Kruskal ----------

    cout<<endl<<"---------- 矩阵图 ----------"<<endl;
    MatrixGraph<string, double> matrix_graph(10, 1000, edges, vertices);                    // 构造matrix_undirected_graph(矩阵无向图)
    MinimumSpanTree<string, double> matrix_min_span_tree(100);                              // 初始化matrix_min_span_tree(邻接表图的最小生成树)

    Kruskal(matrix_graph, matrix_min_span_tree);                                            // 调用Kruskal求最小生成树
    matrix_min_span_tree.Print();                                                           // 打印最小生成树

    cout << "-------------------------------------------------------------" << endl;
}


/*!
 * @brief **测试-图-最小生成树Prim**
 * @note
 * 测试-图-最小生成树Prim
 * -------------------
 * -------------------
 *
 * -------------------
 * + **1 初始化图的基本信息**\n\n
 * 初始化结点信息(北京, 上海, 广州, 深圳, 杭州, 成都 6座城市)\n
 * 初始化边信息\n\n
 * + **2 测试邻接表图Prim**\n\n
 * 构造adjacency_list_undirected_graph(邻接表无向图)\n
 * 初始化adj_min_span_tree(邻接表图的最小生成树)\n\n
 * 调用Prim求最小生成树\n
 * 打印最小生成树\n\n
 * + **3 测试矩阵图Prim**\n\n
 * 构造matrix_undirected_graph(矩阵无向图)\n
 * 初始化matrix_min_span_tree(矩阵图的最小生成树)\n\n
 * 调用Prim求最小生成树\n
 * 打印最小生成树\n\n
 *
 *
 * -------------------
 */
void TestPrim() {
    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|                      Test Graph Prim                      |"<<endl;
    cout<<"|                   测试-图-最小生成树Prim                  |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                           北京                            |"<<endl;
    cout<<"|                           / \\                             |"<<endl;
    cout<<"|                          /   \\                            |"<<endl;
    cout<<"|                        0.1   0.12                         |"<<endl;
    cout<<"|                        /       \\                          |"<<endl;
    cout<<"|                       /         \\                         |"<<endl;
    cout<<"|                    上海---0.01---广州                     |"<<endl;
    cout<<"|                     / \\         / \\                       |"<<endl;
    cout<<"|                    /   \\       /   \\                      |"<<endl;
    cout<<"|                 0.13  0.14   0.05  0.17                   |"<<endl;
    cout<<"|                  /       \\   /       \\                    |"<<endl;
    cout<<"|                 /         \\ /         \\                   |"<<endl;
    cout<<"|             杭州--0.09-- 深圳 --0.11--成都                |"<<endl;
    cout<<endl;

    // ---------- 1 初始化图的基本信息 ----------

    unsigned int edge_count = 9;

    // 初始化结点信息(北京, 上海, 广州, 深圳, 杭州, 成都 6座城市)
    vector<string> vertices{ "北京", "上海", "广州", "深圳", "杭州", "成都" };

    // 初始化边信息
    vector<string> starting_vertices{ "北京",  "北京", "上海", "上海", "上海", "广州", "广州", "深圳", "深圳" };
    vector<string> ending_vertices{ "上海", "广州", "广州", "深圳", "杭州", "深圳", "成都", "杭州", "成都" };
    vector<double> weights{ 0.1, 0.12, 0.01, 0.14, 0.13, 0.05, 0.17, 0.09, 0.11 };

    vector<Edge<string, double> > edges;
    for (unsigned int i = 0; i < edge_count; i++) {
        Edge<string, double> edge(starting_vertices[i], ending_vertices[i], weights[i]);
        edges.push_back(edge);
    }

    // ---------- 2 测试邻接表图Prim ----------

    cout<<"---------- 邻接表图 ----------"<<endl;

    AdjacencyListGraph<string, double> adjacency_list_undirected_graph(10, 1000, edges, vertices);  // 构造adjacency_list_undirected_graph(邻接表无向图)
    MinimumSpanTree<string, double> adj_min_span_tree(100);                                         // 初始化adj_min_span_tree(邻接表图的最小生成树)
    Prim(adjacency_list_undirected_graph, adj_min_span_tree);                                       // 调用Prim求最小生成树
    adj_min_span_tree.Print();                                                                      // 打印最小生成树

    // ---------- 3 测试矩阵图Prim ----------

    cout<<endl<<"---------- 矩阵图 ----------"<<endl;

    MatrixGraph<string, double> matrix_undirected_graph(10, 1000, edges, vertices);                 // 构造matrix_undirected_graph(矩阵无向图)
    MinimumSpanTree<string, double> matrix_min_span_tree(100);                                      // 初始化matrix_min_span_tree(邻接表图的最小生成树)

    Prim(matrix_undirected_graph, matrix_min_span_tree);                                            // 调用Prim求最小生成树
    matrix_min_span_tree.Print();                                                                   // 打印最小生成树

    cout<<endl<<"-------------------------------------------------------------"<<endl<<endl;
}


/*!
 * @brief **测试-图-最短路径Dijkstra**
 * @note
 * 测试-图-最短路径Dijkstra
 * ----------------------
 * ----------------------
 *
 * ----------------------
 * + **1 初始化图的基本信息**\n\n
 * 初始化结点信息(北京, 上海, 广州, 深圳, 杭州, 成都 6座城市)\n
 * 初始化边信息\n\n
 * + **2 测试邻接表图Dijkstra**\n\n
 * 构造adjacency_list_undirected_graph(邻接表无向图)\n
 * 声明adjacency_list_graph_min_distances(邻接表图最短路径数组)\n
 * 声明adjacency_list_graph_predecessors(最短路径前驱结点数组)\n\n
 * 调用Dijkstra函数, 求"北京"到其他各点的最短路径\n
 * 调用PrintSingleSourceShortestPath打印"北京"到各城市的最短路径\n\n
 * + **3 测试矩阵图Dijkstra**\n\n
 * 构造matrix_undirected_graph(矩阵无向图)\n
 * 声明matrix_graph_min_distances(邻接表图最短路径数组)\n
 * 声明matrix_graph_predecessors(最短路径前驱结点数组)\n\n
 * 调用Dijkstra函数, 求"北京"到其他各点的最短路径\n
 * 调用PrintSingleSourceShortestPath打印"北京"到各城市的最短路径\n\n
 *
 *
 * ----------------------
 */
void TestDijkstra() {
    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|                       Test Dijkstra                       |"<<endl;
    cout<<"|                  测试-图-最短路径Dijkstra                 |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                           北京                            |"<<endl;
    cout<<"|                           / \\                             |"<<endl;
    cout<<"|                          /   \\                            |"<<endl;
    cout<<"|                        0.1   0.12                         |"<<endl;
    cout<<"|                        /       \\                          |"<<endl;
    cout<<"|                       /         \\                         |"<<endl;
    cout<<"|                    上海---0.01---广州                     |"<<endl;
    cout<<"|                     / \\         / \\                       |"<<endl;
    cout<<"|                    /   \\       /   \\                      |"<<endl;
    cout<<"|                 0.13  0.14   0.05  0.17                   |"<<endl;
    cout<<"|                  /       \\   /       \\                    |"<<endl;
    cout<<"|                 /         \\ /         \\                   |"<<endl;
    cout<<"|             杭州--0.09-- 深圳 --0.11--成都                |"<<endl;
    cout<<endl;

    // ---------- 1 初始化图的基本信息 ----------

    unsigned int edge_count = 9;

    // 初始化结点信息(北京, 上海, 广州, 深圳, 杭州, 成都 6座城市)
    vector<string> vertices{ "北京", "上海", "广州", "深圳", "杭州", "成都" };

    // 初始化边信息
    vector<string> starting_vertices{ "北京", "北京", "上海", "上海", "上海", "广州", "广州", "深圳", "深圳" };
    vector<string> ending_vertices{   "上海", "广州", "广州", "深圳", "杭州", "深圳", "成都", "杭州", "成都" };
    vector<double> weights{ 0.1, 0.12, 0.01, 0.14, 0.13, 0.05, 0.17, 0.09, 0.11 };

    vector<Edge<string, double> > edges;
    for (unsigned int i = 0; i < edge_count; i++) {
        Edge<string, double> edge(starting_vertices[i], ending_vertices[i], weights[i]);
        edges.push_back(edge);
    }

    // ---------- 2 测试邻接表图Dijkstra ----------

    cout << "---------- 邻接表图 ----------" << endl;

    AdjacencyListGraph<string, double> adjacency_list_undirected_graph(10, 1000, edges, vertices);      // 构造adjacency_list_undirected_graph(邻接表无向图)
    double adjacency_list_graph_min_distances[10];                                                      // 声明adjacency_list_graph_min_distances(邻接表图最短路径数组)
    int adjacency_list_graph_predecessors[10];                                                          // 声明adjacency_list_graph_predecessors(最短路径前驱结点数组)

    // 调用Dijkstra函数, 求"北京"到其他各点的最短路径
    Dijkstra(adjacency_list_undirected_graph, vertices[0], adjacency_list_graph_min_distances, adjacency_list_graph_predecessors);
    // 调用PrintSingleSourceShortestPath打印"北京"到各城市的最短路径
    PrintSingleSourceShortestPath(adjacency_list_undirected_graph, vertices[0], adjacency_list_graph_min_distances, adjacency_list_graph_predecessors);

    // ---------- 3 测试矩阵图Dijkstra ----------

    cout << endl << endl << "---------- 矩阵图 ----------" << endl;

    MatrixGraph<string, double> matrix_undirected_graph(1, 10, 1000, edges, vertices);                  // 构造matrix_undirected_graph(矩阵无向图)
    double matrix_graph_min_distances[10];                                                              // 声明matrix_graph_min_distances(邻接表图最短路径数组)
    int matrix_graph_predecessors[10];                                                                  // 声明matrix_graph_predecessors(最短路径前驱结点数组)

    // 调用Dijkstra函数, 求"北京"到其他各点的最短路径
    Dijkstra(matrix_undirected_graph, vertices[0], matrix_graph_min_distances, matrix_graph_predecessors);
    // 调用PrintSingleSourceShortestPath打印"北京"到各城市的最短路径
    PrintSingleSourceShortestPath(matrix_undirected_graph, vertices[0], matrix_graph_min_distances, matrix_graph_predecessors);

    cout<<"-------------------------------------------------------------"<<endl<<endl;
}


/*!
 * @brief **测试-图-最短路径BellmanFord**
 * @note
 * 测试-图-最短路径BellmanFord
 * ------------------------
 * ------------------------
 *
 * ------------------------
 * + **1 初始化图的基本信息**\n\n
 * 初始化结点信息(北京, 上海, 广州, 深圳, 杭州, 成都 6座城市)\n
 * 初始化边信息\n\n
 * + **2 测试邻接表图BellmanFord**\n\n
 * 构造adjacency_list_undirected_graph(邻接表无向图)\n
 * 声明adjacency_list_graph_min_distances(邻接表图最短路径数组)\n
 * 声明adjacency_list_graph_predecessors(最短路径前驱结点数组)\n\n
 * 调用BellmanFord函数, 求"北京"到其他各点的最短路径\n
 * 调用PrintSingleSourceShortestPath打印"北京"到各城市的最短路径\n\n
 * + **3 测试矩阵图BellmanFord**\n\n
 * 构造matrix_undirected_graph(矩阵无向图)\n
 * 声明matrix_graph_min_distances(邻接表图最短路径数组)\n
 * 声明matrix_graph_predecessors(最短路径前驱结点数组)\n\n
 * 调用BellmanFord函数, 求"北京"到其他各点的最短路径\n
 * 调用PrintSingleSourceShortestPath打印"北京"到各城市的最短路径\n\n
 *
 *
 * ------------------------
 */
void TestBellmanFord() {
    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|                  Test Graph BellmanFord                   |"<<endl;
    cout<<"|                测试-图-最短路径BellmanFord                  |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                           北京                            |"<<endl;
    cout<<"|                           / \\                             |"<<endl;
    cout<<"|                          /   \\                            |"<<endl;
    cout<<"|                        0.1   0.12                         |"<<endl;
    cout<<"|                        /       \\                          |"<<endl;
    cout<<"|                       /         \\                         |"<<endl;
    cout<<"|                    上海---0.01---广州                     |"<<endl;
    cout<<"|                     / \\         / \\                       |"<<endl;
    cout<<"|                    /   \\       /   \\                      |"<<endl;
    cout<<"|                 0.13  0.14   0.05  0.17                   |"<<endl;
    cout<<"|                  /       \\   /       \\                    |"<<endl;
    cout<<"|                 /         \\ /         \\                   |"<<endl;
    cout<<"|             杭州--0.09-- 深圳 --0.11--成都                |"<<endl;
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

    // ---------- 2 测试邻接表图BellmanFord ----------

    cout << "---------- 邻接表图 ----------" << endl;

    AdjacencyListGraph<string, double> adjacency_list_graph(10, 1000, edges, vertices);     // 构造adjacency_list_undirected_graph(邻接表无向图)

    double adjacency_list_graph_min_distances[10];                                          // 声明adjacency_list_graph_min_distances(邻接表图最短路径数组)
    int adjacency_list_graph_predecessors[10];                                              // 声明adjacency_list_graph_predecessors(最短路径前驱结点数组)

    // 调用BellmanFord函数, 求"北京"到其他各点的最短路径
    BellmanFord(adjacency_list_graph, vertices[0], adjacency_list_graph_min_distances, adjacency_list_graph_predecessors);
    // 调用PrintSingleSourceShortestPath打印"北京"到各城市的最短路径
    PrintSingleSourceShortestPath(adjacency_list_graph, vertices[0], adjacency_list_graph_min_distances, adjacency_list_graph_predecessors);

    // ---------- 3 测试矩阵图BellmanFord ----------

    cout << endl << endl << "---------- 矩阵图 ----------" << endl;

    MatrixGraph<string, double> matrix_graph(10, 1000, edges, vertices);                    // 构造matrix_undirected_graph(矩阵无向图)

    double matrix_graph_min_dists[10];                                                      // 声明matrix_graph_min_distances(邻接表图最短路径数组)
    int matrix_graph_predecessors[10];                                                      // 声明matrix_graph_predecessors(最短路径前驱结点数组)

    // 调用BellmanFord函数, 求"北京"到其他各点的最短路径
    BellmanFord(matrix_graph, vertices[0], matrix_graph_min_dists, matrix_graph_predecessors);
    // 调用PrintSingleSourceShortestPath打印"北京"到各城市的最短路径
    PrintSingleSourceShortestPath(matrix_graph, vertices[0], matrix_graph_min_dists, matrix_graph_predecessors);

    cout<<"-------------------------------------------------------------"<<endl<<endl;
}


/*!
 * @brief **测试-图-最短路径Floyd**
 * @note
 * 测试-图-最短路径Floyd
 * ------------------
 * ------------------
 *
 * ------------------
 * + **1 初始化图的基本信息**\n\n
 * 初始化结点信息(北京, 上海, 广州, 深圳, 杭州, 成都 6座城市)\n
 * 初始化边信息\n\n
 * + **2 测试邻接表有向图Floyd**\n\n
 * 构造adjacency_list_directed_graph(邻接表有向图)\n\n
 * 初始化adj_list_min_distances(邻接表最短路径二维向量)\n
 * 初始化adj_list_predecessors(最短路径前驱结点二维向量)\n\n
 * 调用Floyd执行弗洛伊德算法\n
 * 打印多源最短路径\n\n
 * + **3 测试矩阵有向图Floyd**\n\n
 * 构造matrix_directed_graph(矩阵有向图)\n\n
 * 初始化matrix_min_distances(矩阵最短路径二维向量)\n
 * 初始化matrix_predecessors(最短路径前驱结点二维向量)\n\n
 * 调用Floyd执行弗洛伊德算法\n
 * 打印多源最短路径\n\n
 *
 *
 * ------------------
 */
void TestFloyd() {
    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|                    Test Floyd-Warshall                    |"<<endl;
    cout<<"|                   测试-图-最短路径Floyd                   |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                           北京                            |"<<endl;
    cout<<"|                           / \\                             |"<<endl;
    cout<<"|                          /   \\                            |"<<endl;
    cout<<"|                        0.1   0.12                         |"<<endl;
    cout<<"|                        /       \\                          |"<<endl;
    cout<<"|                       /         \\                         |"<<endl;
    cout<<"|                    上海---0.01---广州                     |"<<endl;
    cout<<"|                     / \\         / \\                       |"<<endl;
    cout<<"|                    /   \\       /   \\                      |"<<endl;
    cout<<"|                 0.13  0.14   0.05  0.17                   |"<<endl;
    cout<<"|                  /       \\   /       \\                    |"<<endl;
    cout<<"|                 /         \\ /         \\                   |"<<endl;
    cout<<"|             杭州--0.09-- 深圳 --0.11--成都                |"<<endl;
    cout<<endl;

    // ---------- 1 初始化图的基本信息 ----------

    // 初始化结点信息(北京, 上海, 广州, 深圳, 杭州, 成都 6座城市)
    vector<string> vertices{ "北京", "上海", "广州", "深圳", "杭州", "成都" };

    // 初始化边信息
    unsigned int edge_count = 9;

    vector<string> starting_vertices{ "北京", "北京", "上海", "上海", "上海", "广州", "广州", "深圳", "深圳" };
    vector<string> ending_vertices  { "上海", "广州", "广州", "深圳", "杭州", "深圳", "成都", "杭州", "成都" };
    vector<double> weights          {  0.1,   0.12,   0.01,  0.14,   0.13,  0.05,  0.17,   0.09,  0.11  };

    vector<Edge<string, double> > edges;
    for (unsigned int i = 0; i < edge_count; i++) {
        Edge<string, double> edge(starting_vertices[i], ending_vertices[i], weights[i]);
        edges.push_back(edge);
    }

    // ---------- 2 测试邻接表有向图Floyd ----------

    cout << "---------- 邻接表图 ----------" << endl;

    // 构造adjacency_list_directed_graph(邻接表有向图)
    AdjacencyListGraph<string, double> adjacency_list_directed_graph(Graph<string, double>::DIRECTED, 10, 1000, edges, vertices);

    // 初始化adj_list_min_distances(邻接表最短路径二维向量)
    vector<vector<double> > adj_list_min_distances(adjacency_list_directed_graph.VertexCount(),
                                                   vector<double>(adjacency_list_directed_graph.VertexCount()));
    // 初始化adj_list_predecessors(最短路径前驱结点二维向量)
    vector<vector<int> > adj_list_predecessors(adjacency_list_directed_graph.VertexCount(),
                                               vector<int>(adjacency_list_directed_graph.VertexCount()));

    // 调用Floyd执行弗洛伊德算法
    Floyd(adjacency_list_directed_graph, adj_list_min_distances, adj_list_predecessors);

    // 打印多源最短路径
    PrintMultipleSourceShortestPath(adjacency_list_directed_graph,
                                    adj_list_min_distances,
                                    adj_list_predecessors);

    // ---------- 3 测试矩阵有向图Floyd ----------

    cout << endl << endl << "---------- 矩阵图 ----------" << endl;

    // 构造matrix_directed_graph(矩阵有向图)
    MatrixGraph<string, double> matrix_directed_graph(Graph<string, double>::DIRECTED, 10, 1000, edges, vertices);                // 构造矩阵图

    // 初始化matrix_min_distances(矩阵最短路径二维向量)
    vector<vector<double> > matrix_min_distances(matrix_directed_graph.VertexCount(),
                                                 vector<double>(matrix_directed_graph.VertexCount()));
    // 初始化matrix_predecessors(最短路径前驱结点二维向量)
    vector<vector<int> > matrix_predecessors(matrix_directed_graph.VertexCount(),
                                             vector<int>(matrix_directed_graph.VertexCount()));

    // 调用Floyd执行弗洛伊德算法
    Floyd(matrix_directed_graph, matrix_min_distances, matrix_predecessors);

    // 打印多源最短路径
    PrintMultipleSourceShortestPath(matrix_directed_graph,
                                    matrix_min_distances,
                                    matrix_predecessors);

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-图-拓扑排序**
 * @note
 * 测试-图-拓扑排序
 * --------------
 * --------------
 *
 * --------------
 * + **1 初始化图的基本信息**\n\n
 * 初始化结点信息(北京, 上海, 广州, 深圳, 杭州, 成都 6座城市)\n
 * 初始化边信息\n\n
 * + **2 测试邻接表有向图拓扑排序**\n\n
 * 初始化adj_list_directed_graph(邻接表有向图)\n
 * 打印拓扑排序结果\n\n
 * + **3 测试矩阵无向图拓扑排序**\n\n
 * 初始化matrix_undirected_graph(矩阵无向图)\n
 * 打印拓扑排序结果\n
 *
 *
 * --------------
 */
void TestTopologicalSort() {
    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|                  Test Graph TopologySort                  |"<<endl;
    cout<<"|                      测试-图-拓扑排序                     |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                           北京                            |"<<endl;
    cout<<"|                           / \\                             |"<<endl;
    cout<<"|                          /   \\                            |"<<endl;
    cout<<"|                        0.1   0.12                         |"<<endl;
    cout<<"|                        /       \\                          |"<<endl;
    cout<<"|                       /         \\                         |"<<endl;
    cout<<"|                    上海---0.01---广州                     |"<<endl;
    cout<<"|                     / \\         / \\                       |"<<endl;
    cout<<"|                    /   \\       /   \\                      |"<<endl;
    cout<<"|                 0.13  0.14   0.05  0.17                   |"<<endl;
    cout<<"|                  /       \\   /       \\                    |"<<endl;
    cout<<"|                 /         \\ /         \\                   |"<<endl;
    cout<<"|             杭州--0.09-- 深圳 --0.11--成都                |"<<endl;
    cout<<endl;

    // ---------- 1 初始化图的基本信息 ----------

    // 初始化结点信息(北京, 上海, 广州, 深圳, 杭州, 成都 6座城市)
    vector<string> vertices{ "北京", "上海", "广州", "深圳", "杭州", "成都" };

    // 初始化边信息
    unsigned int edge_count = 9;

    vector<string> starting_vertices{ "北京", "北京", "上海", "上海", "上海", "广州", "广州", "深圳", "深圳" };
    vector<string> ending_vertices  { "上海", "广州", "广州", "深圳", "杭州", "深圳", "成都", "杭州", "成都" };
    vector<double> weights          {  0.1,   0.12,   0.01,  0.14,   0.13,  0.05,  0.17,   0.09,  0.11  };

    vector<Edge<string, double> > edges;
    for (unsigned int i = 0; i < edge_count; i++) {
        Edge<string, double> edge(starting_vertices[i], ending_vertices[i], weights[i]);
        edges.push_back(edge);
    }

    vector<string> topology_sorted_list;

    // ---------- 2 测试邻接表有向图拓扑排序 ----------

    cout << "---------- 邻接表图 ----------" << endl;

    // 初始化adj_list_directed_graph(邻接表有向图)
    AdjacencyListGraph<string, double> adj_list_directed_graph(Graph<string, double>::DIRECTED, 10, 1000, edges, vertices);
    bool res = TopologicalSort(adj_list_directed_graph, vertices[0], topology_sorted_list);
    if (!res) {
        cout<<"拓扑排序失败"<<endl;
        return;
    }

    // 打印拓扑排序结果
    for (auto iter = topology_sorted_list.begin(); iter != topology_sorted_list.end(); iter++) {
        cout<<*iter<<' ';
    }
    cout<<endl;

    topology_sorted_list.clear();   // 清空topology_sorted_list

    // ---------- 3 测试矩阵无向图拓扑排序 ----------

    cout << endl << endl << "---------- 矩阵图 ----------" << endl;

    // 初始化matrix_undirected_graph(矩阵无向图)
    MatrixGraph<string, double> matrix_undirected_graph(Graph<string, double>::UNDIRECTED, 10, 1000, edges, vertices);
    res = TopologicalSort(matrix_undirected_graph, vertices[0], topology_sorted_list);
    if (!res) {
        cout<<"拓扑排序失败"<<endl;
    }

    // 打印拓扑排序结果
    for (auto iter = topology_sorted_list.begin(); iter != topology_sorted_list.end(); iter++) {
        cout<<*iter<<' ';
    }
    cout<<endl;

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-图-关键路径**
 * @note
 * 测试-图-关键路径
 * --------------
 * --------------
 *
 * --------------
 * + **1 初始化图的基本信息**\n\n
 * 初始化结点信息(北京, 上海, 广州, 深圳, 杭州, 成都 6座城市)\n
 * 初始化边信息\n\n
 * + **2 测试邻接表有向图关键路径**\n\n
 * 初始化adj_list_directed_graph(邻接表有向图)\n
 * 调用GetCriticalPath, 求"北京"到各城市的关键路径\n
 * 打印各关键路径\n\n
 * + **3 测试矩阵有向图关键路径**\n\n
 * 初始化matrix_directed_graph(矩阵有向图)\n
 * 调用GetCriticalPath, 求"北京"到各城市的关键路径\n
 * 打印各关键路径\n
 *
 *
 * --------------
 */
void TestCriticalPaths() {
    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|                  Test Graph CriticalPaths                 |"<<endl;
    cout<<"|                      测试-图-关键路径                     |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                           北京                            |"<<endl;
    cout<<"|                           / \\                             |"<<endl;
    cout<<"|                          /   \\                            |"<<endl;
    cout<<"|                        0.1   0.12                         |"<<endl;
    cout<<"|                        /       \\                          |"<<endl;
    cout<<"|                       /         \\                         |"<<endl;
    cout<<"|                    上海---0.01---广州                     |"<<endl;
    cout<<"|                     / \\         / \\                       |"<<endl;
    cout<<"|                    /   \\       /   \\                      |"<<endl;
    cout<<"|                 0.13  0.14   0.05  0.17                   |"<<endl;
    cout<<"|                  /       \\   /       \\                    |"<<endl;
    cout<<"|                 /         \\ /         \\                   |"<<endl;
    cout<<"|             杭州--0.09-- 深圳 --0.11--成都                |"<<endl;
    cout<<endl;

    // ---------- 1 初始化图的基本信息 ----------

    // 初始化结点信息(北京, 上海, 广州, 深圳, 杭州, 成都 6座城市)
    vector<string> vertices{ "北京", "上海", "广州", "深圳", "杭州", "成都" };

    // 初始化边信息
    unsigned int edge_count = 9;
    vector<string> starting_vertices{ "北京", "北京", "上海", "上海", "上海", "广州", "广州", "深圳", "深圳" };
    vector<string> ending_vertices  { "上海", "广州", "广州", "深圳", "杭州", "深圳", "成都", "杭州", "成都" };
    vector<double> weights          {  0.1,   0.12,   0.01,  0.14,   0.13,  0.05,  0.17,   0.09,  0.11  };

    vector<Edge<string, double> > edges;
    for (unsigned int i = 0; i < edge_count; i++) {
        Edge<string, double> edge(starting_vertices[i], ending_vertices[i], weights[i]);
        edges.push_back(edge);
    }

    string starting_vertex = vertices[0];

    // ---------- 2 测试邻接表有向图关键路径 ----------

    cout << "---------- 邻接表图 ----------" << endl;
    // 初始化adj_list_directed_graph(邻接表有向图)
    AdjacencyListGraph<string, double> adj_list_directed_graph(Graph<string, double>::DIRECTED, 10, 1000, edges, vertices);

    // 调用GetCriticalPath, 求"北京"到各城市的关键路径
    vector<double> critical_paths = GetCriticalPath(adj_list_directed_graph, starting_vertex);
    // 打印各关键路径
    for (unsigned int i = 0; i < critical_paths.size(); i++) {
        cout<<"北京 ---> "<<vertices[i]<<" 关键路径长度: "<<critical_paths[i]<<endl;
    }

    // ---------- 3 测试矩阵有向图关键路径 ----------

    cout << endl << endl << "---------- 矩阵图 ----------" << endl;
    // 初始化matrix_directed_graph(矩阵有向图)
    MatrixGraph<string, double> matrix_directed_graph(Graph<string, double>::DIRECTED, 10, 1000, edges, vertices);

    // 调用GetCriticalPath, 求"北京"到各城市的关键路径
    critical_paths = GetCriticalPath(matrix_directed_graph, starting_vertex);
    // 打印各关键路径
    for (unsigned int i = 0; i < critical_paths.size(); i++) {
        cout<<"北京 ---> "<<vertices[i]<<" 关键路径长度: "<<critical_paths[i]<<endl;
    }

    cout << "-------------------------------------------------------------" << endl << endl;
}
