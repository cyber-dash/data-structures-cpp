/*!
 * @file test.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 图测试.cpp文件
 * @version 0.2.1
 * @date 2021-10-9
 */

#include "test.h"
#include "priority_queue.h"
#include "algorithm.h"
#include "algorithm.cpp"


using namespace std;


void TestDn() {
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

    int edge_count = 9;

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

    // 构造矩阵图
    int graph_type = 1; // 有向
    MatrixGraph<string, double> matrix_graph(graph_type, 10, 1000, edges, vertices);
    cout << matrix_graph << endl << endl;

    cout << "##### 2 矩阵图删除边(\"上海\", \"北京\") #####" << endl << endl;
    matrix_graph.RemoveEdge("北京", "上海");

    cout << matrix_graph << endl;
}


void TestBaseFunctions() {
    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|                  Test Graph BaseFunctions                 |"<<endl;
    cout<<"|                        测试图基础函数                       |"<<endl;
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

    int edge_count = 9;

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

    cout << "##### 1 邻接表图删除结点\"北京\" #####" << endl << endl;
    adjacency_list_graph.RemoveVertex("北京");

    cout << adjacency_list_graph << endl << endl << endl << endl;

    // 构造矩阵图
    MatrixGraph<string, double> matrix_graph(10, 1000, edges, vertices);
    cout << "##### 2 矩阵图删除结点\"上海\" #####" << endl << endl;
    matrix_graph.RemoveVertex("上海");

    cout << matrix_graph << endl;

    cout<<"-------------------------------------------------------------"<<endl;
}


void TestMinPriorityQueue() {
    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|                   Test MinPriorityQueue                   |"<<endl;
    cout<<"|                       测试最小优先队列                      |"<<endl;

    int arr[5] = { 3, 1, 4, 1, 5 };

    MinPriorityQueue<int> min_priority_queue(arr, 5);

    int item;

    min_priority_queue.Dequeue(item);
    cout<<item<<endl;
    min_priority_queue.Dequeue(item);
    cout<<item<<endl;

    min_priority_queue.Enqueue(9);
    min_priority_queue.Enqueue(2);
    min_priority_queue.Enqueue(6);

    min_priority_queue.Dequeue(item);
    cout<<item<<endl;
    min_priority_queue.Dequeue(item);
    cout<<item<<endl;
    min_priority_queue.Dequeue(item);
    cout<<item<<endl;
    min_priority_queue.Dequeue(item);
    cout<<item<<endl;
    min_priority_queue.Dequeue(item);
    cout<<item<<endl;
    min_priority_queue.Dequeue(item);
    cout<<item<<endl;

    cout<<"-------------------------------------------------------------"<<endl;
}


// 测试矩阵图的矩阵
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

    int edge_count = 9;

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

    MatrixGraph<string, double> matrix_graph(10, 1000, edges, vertices);

    matrix_graph.PrintMatrix();

    cout<<"-------------------------------------------------------------"<<endl;
}


// 测试使用结点索引获取结点
void TestGetVertexByIndex() {
    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|                Test Graph GetVertexByIndex                |"<<endl;
    cout<<"|                    测试使用结点索引获取结点                   |"<<endl;
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

    int edge_count = 9;

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

    vector<string> graph_vertices(vertices.size());

    // 构造邻接表图
    AdjacencyListGraph<string, double> adjacency_list_graph(10, 1000, edges, vertices);

    // 按照索引值读取邻接表图各结点
    for (int i = 0; i < adjacency_list_graph.VertexCount(); i++) {
        adjacency_list_graph.GetVertexByIndex(i, graph_vertices[i]);
    }

    // adjacency_list_graph.RemoveEdge("北京", "上海");
    adjacency_list_graph.RemoveEdge("上海", "北京");
    adjacency_list_graph.RemoveEdge("北京", "广州");
    adjacency_list_graph.RemoveVertex("北京");
    adjacency_list_graph.RemoveVertex("上海");
    adjacency_list_graph.RemoveVertex("广州");
    adjacency_list_graph.RemoveVertex("深圳");
    adjacency_list_graph.RemoveVertex("杭州");
    // adjacency_list_graph.RemoveVertex("成都");

    cout << adjacency_list_graph << endl;
    // 打印结点
    /*
    cout<<"**邻接表图**"<<endl;
    for (int i = 0; i < adjacency_list_graph.VertexCount(); i++) {
        string cur_vertex;
        adjacency_list_graph.GetVertexByIndex(i, cur_vertex);
        cout << "索引" << i << "结点: " << cur_vertex << endl;
    }
     */

    // 构造矩阵图
    MatrixGraph<string, double> matrix_graph(10, 10000, edges, vertices);
    matrix_graph.RemoveVertex("北京");

    // 按照索引值读取矩阵图各结点
    for (int i = 0; i < matrix_graph.VertexCount(); i++) {
        matrix_graph.GetVertexByIndex(i, graph_vertices[i]);
    }

    // 打印结点
    cout<<endl<<"**矩阵图**"<<endl;
    for (int i = 0; i < matrix_graph.VertexCount(); i++) {
        cout << "索引" << i << "结点: " << graph_vertices[i] << endl;
    }

    cout<<"-------------------------------------------------------------"<<endl;
}


// 测试DFS
void TestDFS() {
    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|                       Test Graph DfsRecursive                      |"<<endl;
    cout<<"|                      测试图深度优先遍历                      |"<<endl;
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

    int edge_count = 9;

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
    MatrixGraph<string, double> matrix_graph(10, 1000, edges, vertices);

    cout<<"**邻接表图**"<<endl;
    DfsRecursive(adjacency_list_graph, vertices[0]);

    cout<<endl<<"**矩阵图**"<<endl;
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

    int edge_count = 9;

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

    int edge_count = 9;

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

    int edge_count = 9;

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

    int edge_count = 9;

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

    cout<<endl<<"**邻接表图Dijkstra测试**"<<endl<<endl;
    AdjacencyListGraph<string, double> adjacency_list_graph(10, 1000, edges, vertices); // 构造邻接表图
    double adjacency_list_graph_min_distances[10];
    int adjacency_list_graph_predecessors[10];

    DijkstraByPriorityQueue(adjacency_list_graph, vertices[0], adjacency_list_graph_min_distances, adjacency_list_graph_predecessors);
    PrintSingleSourceShortestPath(adjacency_list_graph, vertices[0], adjacency_list_graph_min_distances, adjacency_list_graph_predecessors);

    cout<<endl<<"**矩阵图测试**"<<endl<<endl;
    MatrixGraph<string, double> matrix_graph(1, 10, 1000, edges, vertices);                // 构造矩阵图
    double matrix_graph_min_distances[10];
    int matrix_graph_predecessors[10];

    DijkstraByPriorityQueue(matrix_graph, vertices[0], matrix_graph_min_distances, matrix_graph_predecessors);
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

    int edge_count = 9;

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

    int edge_count = 9;

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

    AdjacencyListGraph<string, double> adjacency_list_graph(1, 10, 1000, edges, vertices); // 构造邻接表图
    MatrixGraph<string, double> matrix_graph(1, 10, 1000, edges, vertices);                // 构造矩阵图


    cout<<endl<<"**邻接表图测试**"<<endl<<endl;
    // 邻接表图结点数量
    int adj_list_graph_vertices_num = adjacency_list_graph.VertexCount();
    // 邻接表图distance
    vector<vector<double> > adj_list_graph_distances(adj_list_graph_vertices_num,
                                                     vector<double>(adj_list_graph_vertices_num));
    // 邻接表图predecessor
    vector<vector<int> > adj_list_graph_predecessors(adj_list_graph_vertices_num,
                                                     vector<int>(adj_list_graph_vertices_num));
    for (int i = 0; i < adj_list_graph_vertices_num; i++) {
        for (int j = 0; j < adj_list_graph_vertices_num; j++) {
            adj_list_graph_predecessors[i][j] = -1;
        }
    }

    // 执行弗洛伊德算法
    Floyd(adjacency_list_graph, adj_list_graph_distances, adj_list_graph_predecessors);

    // 打印多源(MSSP)最短路径
    PrintMultipleSourceShortestPath(adjacency_list_graph,
                                    adj_list_graph_distances,
                                    adj_list_graph_predecessors);

    cout<<endl<<"**矩阵图测试**"<<endl<<endl;
    // 矩阵图结点数量
    int matrix_graph_vertices_num = matrix_graph.VertexCount();
    // matrix_graph_min_distances
    vector<vector<double> > matrix_graph_min_distances(matrix_graph_vertices_num,
                                                       vector<double>(matrix_graph_vertices_num));
    // matrix_graph_predecessors
    vector<vector<int> > matrix_graph_predecessors(matrix_graph_vertices_num,
                                                   vector<int>(matrix_graph_vertices_num));

    for (int i = 0; i < matrix_graph_vertices_num; i++) {
        for (int j = 0; j < matrix_graph_vertices_num; j++) {
            matrix_graph_predecessors[i][j] = -1;
        }
    }
    // 执行弗洛伊德算法
    Floyd(matrix_graph, matrix_graph_min_distances, matrix_graph_predecessors);

    // 打印多源最短路径
    PrintMultipleSourceShortestPath(matrix_graph,
                                    matrix_graph_min_distances,
                                    matrix_graph_predecessors);

    cout<<"-------------------------------------------------------------"<<endl<<endl;
}
