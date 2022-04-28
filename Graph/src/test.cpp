/*!
 * @file test.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 图测试.cpp文件
 * @version 0.2.1
 * @date 2021-10-9
 *
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#include "test.h"
#include "graph_algorithm.h"
#include "graph_algorithm.cpp"


using namespace std;


// 测试矩阵图的矩阵
void TestMatrixGraphPrintMatrix() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                      Test PrintMatrix                     |"<<endl;
  cout<<"|                       测试矩阵图的矩阵                      |"<<endl;

  MatrixGraph<string, double> matrix_graph(10);
  matrix_graph.InsertVertex("地球");
  matrix_graph.InsertVertex("火星");
  matrix_graph.InsertVertex("木星");
  matrix_graph.InsertVertex("水星");

  matrix_graph.InsertEdge("地球", "火星", 0.8);
  matrix_graph.InsertEdge("火星", "木星", 3.9);
  matrix_graph.InsertEdge("木星", "水星", 7.3);
  matrix_graph.InsertEdge("地球", "木星", 11.3);
  matrix_graph.InsertEdge("火星", "水星", 0.3);

  matrix_graph.PrintMatrix();

  cout<<"-------------------------------------------------------------"<<endl;
}


// 测试使用结点索引获取结点
void TestGetVertexByIndex() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                   Test GetVertexByIndex                   |"<<endl;
  cout<<"|                   测试使用结点索引获取结点                    |"<<endl;

  cout<<"**邻接表图**"<<endl;
  AdjacencyListGraph<string, double> adjacency_list_graph;

  adjacency_list_graph.InsertVertex("北京");
  adjacency_list_graph.InsertVertex("上海");
  adjacency_list_graph.InsertVertex("广州");
  adjacency_list_graph.InsertVertex("深圳");

  adjacency_list_graph.InsertEdge("北京", "上海", 0.8);
  adjacency_list_graph.InsertEdge("上海", "广州", 3.9);
  adjacency_list_graph.InsertEdge("广州", "深圳", 7.3);
  adjacency_list_graph.InsertEdge("北京", "广州", 11.3);
  adjacency_list_graph.InsertEdge("上海", "深圳", 0.3);

  string BJ;
  string SH;
  string GZ;
  string SZ;

  adjacency_list_graph.GetVertexByIndex(BJ, 0);
  adjacency_list_graph.GetVertexByIndex(SH, 1);
  adjacency_list_graph.GetVertexByIndex(GZ, 2);
  adjacency_list_graph.GetVertexByIndex(SZ, 3);

  cout<<"结点0: "<<BJ<<endl;
  cout<<"结点1: "<<SH<<endl;
  cout<<"结点2: "<<GZ<<endl;
  cout<<"结点3: "<<SZ<<endl;

  cout<<endl<<"**矩阵图**"<<endl;
  MatrixGraph<string, double> matrix_graph(10);
  matrix_graph.InsertVertex("地球");
  matrix_graph.InsertVertex("火星");
  matrix_graph.InsertVertex("木星");
  matrix_graph.InsertVertex("水星");

  matrix_graph.InsertEdge("地球", "火星", 0.8);
  matrix_graph.InsertEdge("火星", "木星", 3.9);
  matrix_graph.InsertEdge("木星", "水星", 7.3);
  matrix_graph.InsertEdge("地球", "木星", 11.3);
  matrix_graph.InsertEdge("火星", "水星", 0.3);

  matrix_graph.GetVertexByIndex(BJ, 0);
  matrix_graph.GetVertexByIndex(SH, 1);
  matrix_graph.GetVertexByIndex(GZ, 2);
  matrix_graph.GetVertexByIndex(SZ, 3);

  cout<<"结点0: "<<BJ<<endl;
  cout<<"结点1: "<<SH<<endl;
  cout<<"结点2: "<<GZ<<endl;
  cout<<"结点3: "<<SZ<<endl;

  cout<<"-------------------------------------------------------------"<<endl;
}


// 测试DFS
void TestDFS() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                          Test DFS                         |"<<endl;
  cout<<"|                       测试深度优先遍历                      |"<<endl;

  int v0 = 0;
  int v1 = 1;
  int v2 = 2;
  int v3 = 3;
  int v4 = 4;

  AdjacencyListGraph<int, int> adjacency_list_graph;

  adjacency_list_graph.InsertVertex(v0);
  adjacency_list_graph.InsertVertex(v1);
  adjacency_list_graph.InsertVertex(v2);
  adjacency_list_graph.InsertVertex(v3);
  adjacency_list_graph.InsertVertex(v4);

  adjacency_list_graph.InsertEdge(v0, v1, 100);
  adjacency_list_graph.InsertEdge(v1, v2, 50);
  adjacency_list_graph.InsertEdge(v2, v3, 20);
  adjacency_list_graph.InsertEdge(v3, v4, 60);
  adjacency_list_graph.InsertEdge(v0, v3, 30);
  adjacency_list_graph.InsertEdge(v0, v4, 100);
  adjacency_list_graph.InsertEdge(v2, v4, 10);

  MatrixGraph<int, int> matrix_graph;

  matrix_graph.InsertVertex(v0);
  matrix_graph.InsertVertex(v1);
  matrix_graph.InsertVertex(v2);
  matrix_graph.InsertVertex(v3);
  matrix_graph.InsertVertex(v4);

  matrix_graph.InsertEdge(v0, v1, 100);
  matrix_graph.InsertEdge(v1, v2, 50);
  matrix_graph.InsertEdge(v2, v3, 20);
  matrix_graph.InsertEdge(v3, v4, 60);
  matrix_graph.InsertEdge(v0, v3, 30);
  matrix_graph.InsertEdge(v0, v4, 100);
  matrix_graph.InsertEdge(v2, v4, 10);

  cout<<"**邻接表图**"<<endl;
  DFS(adjacency_list_graph, v0);

  cout<<endl<<"**矩阵图**"<<endl;
  DFS(matrix_graph, v0);

  cout<<"-------------------------------------------------------------"<<endl;
}


// 测试BFS
void TestBFS() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                          Test BFS                         |"<<endl;
  cout<<"|                       测试广度优先遍历                      |"<<endl;

  int v0 = 0;
  int v1 = 1;
  int v2 = 2;
  int v3 = 3;
  int v4 = 4;

  AdjacencyListGraph<int, int> adjacency_list_graph;
  MatrixGraph<int, int> matrix_graph;

  adjacency_list_graph.InsertVertex(v0);
  adjacency_list_graph.InsertVertex(v1);
  adjacency_list_graph.InsertVertex(v2);
  adjacency_list_graph.InsertVertex(v3);
  adjacency_list_graph.InsertVertex(v4);

  matrix_graph.InsertVertex(v0);
  matrix_graph.InsertVertex(v1);
  matrix_graph.InsertVertex(v2);
  matrix_graph.InsertVertex(v3);
  matrix_graph.InsertVertex(v4);

  adjacency_list_graph.InsertEdge(v0, v1, 100);
  adjacency_list_graph.InsertEdge(v1, v2, 50);
  adjacency_list_graph.InsertEdge(v2, v3, 20);
  adjacency_list_graph.InsertEdge(v3, v4, 60);
  adjacency_list_graph.InsertEdge(v0, v3, 30);
  adjacency_list_graph.InsertEdge(v0, v4, 100);
  adjacency_list_graph.InsertEdge(v2, v4, 10);

  matrix_graph.InsertEdge(v0, v1, 100);
  matrix_graph.InsertEdge(v1, v2, 50);
  matrix_graph.InsertEdge(v2, v3, 20);
  matrix_graph.InsertEdge(v3, v4, 60);
  matrix_graph.InsertEdge(v0, v3, 30);
  matrix_graph.InsertEdge(v0, v4, 100);
  matrix_graph.InsertEdge(v2, v4, 10);

  cout<<"**邻接表图**"<<endl;
  BFS(adjacency_list_graph, v0);

  cout<<endl<<"**矩阵图**"<<endl;
  BFS(matrix_graph, v0);

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

  AdjacencyListGraph<int, double> adjacency_list_graph;

  adjacency_list_graph.InsertVertex(0);
  adjacency_list_graph.InsertVertex(1);
  adjacency_list_graph.InsertVertex(2);
  adjacency_list_graph.InsertVertex(3);

  adjacency_list_graph.InsertEdge(0, 1, 0.8);
  adjacency_list_graph.InsertEdge(2, 3, 7.3);

  MatrixGraph<int, double> matrix_graph;

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
  cout<<"|  节点:                                                     |"<<endl;
  cout<<"|    \"北京\", \"上海\", \"广州\", \"深圳\"                           |"<<endl;
  cout<<"|  边:                                                      |"<<endl;
  cout<<"|    \"北京\"-\"上海\"权值: 0.8                                   |"<<endl<<endl;
  cout<<"|    \"上海\"-\"广州\"权值: 3.9                                   |"<<endl<<endl;
  cout<<"|    \"广州\"-\"深圳\"权值: 7.3                                   |"<<endl<<endl;
  cout<<"|    \"北京\"-\"广州\"权值: 11.3                                  |"<<endl<<endl;
  cout<<"|    \"上海\"-\"深圳\"权值: 0.3                                   |"<<endl<<endl;

  string BJ = "北京";
  string SH = "上海";
  string GZ = "广州";
  string SZ = "深圳";

  MinSpanTree<string, double> min_span_tree_adj(100);
  MinSpanTree<string, double> min_span_tree_matrix(100);

  AdjacencyListGraph<string, double> adjacency_list_graph;

  adjacency_list_graph.InsertVertex(BJ);
  adjacency_list_graph.InsertVertex(SH);
  adjacency_list_graph.InsertVertex(GZ);
  adjacency_list_graph.InsertVertex(SZ);

  adjacency_list_graph.InsertEdge(BJ, SH, 0.8);
  adjacency_list_graph.InsertEdge(SH, GZ, 3.9);
  adjacency_list_graph.InsertEdge(GZ, SZ, 7.3);
  adjacency_list_graph.InsertEdge(BJ, GZ, 11.3);
  adjacency_list_graph.InsertEdge(SH, SZ, 0.3);

  MatrixGraph<string, double> matrix_graph;
  matrix_graph.InsertVertex(BJ);
  matrix_graph.InsertVertex(SH);
  matrix_graph.InsertVertex(GZ);
  matrix_graph.InsertVertex(SZ);

  matrix_graph.InsertEdge(BJ, SH, 0.8);
  matrix_graph.InsertEdge(SH, GZ, 3.9);
  matrix_graph.InsertEdge(GZ, SZ, 7.3);
  matrix_graph.InsertEdge(BJ, GZ, 11.3);
  matrix_graph.InsertEdge(SH, SZ, 0.3);

  cout<<"**邻接表图测试**"<<endl;
  Kruskal(adjacency_list_graph, min_span_tree_adj);
  min_span_tree_adj.Show();

  cout<<endl<<"**矩阵图测试**"<<endl;
  Kruskal(matrix_graph, min_span_tree_matrix);

  min_span_tree_matrix.Show();
  cout<<"-------------------------------------------------------------"<<endl;
}


void TestPrim() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                         Test Prim                         |"<<endl;
  cout<<"|                        测试Prim算法                        |"<<endl;
  cout<<"|  节点:                                                     |"<<endl;
  cout<<"|    \"北京\", \"上海\", \"广州\", \"深圳\"                           |"<<endl;
  cout<<"|  边:                                                      |"<<endl;
  cout<<"|    \"北京\"-\"上海\"权值: 0.8                                   |"<<endl<<endl;
  cout<<"|    \"上海\"-\"广州\"权值: 3.9                                   |"<<endl<<endl;
  cout<<"|    \"广州\"-\"深圳\"权值: 7.3                                   |"<<endl<<endl;
  cout<<"|    \"北京\"-\"广州\"权值: 11.3                                  |"<<endl<<endl;
  cout<<"|    \"上海\"-\"深圳\"权值: 0.3                                   |"<<endl<<endl;

  string BJ = "北京";
  string SH = "上海";
  string GZ = "广州";
  string SZ = "深圳";

  AdjacencyListGraph<string, double> adjacency_list_graph;

  adjacency_list_graph.InsertVertex(BJ);
  adjacency_list_graph.InsertVertex(SH);
  adjacency_list_graph.InsertVertex(GZ);
  adjacency_list_graph.InsertVertex(SZ);

  adjacency_list_graph.InsertEdge(BJ, SH, 0.8);
  adjacency_list_graph.InsertEdge(SH, GZ, 3.9);
  adjacency_list_graph.InsertEdge(GZ, SZ, 7.3);
  adjacency_list_graph.InsertEdge(BJ, GZ, 11.3);
  adjacency_list_graph.InsertEdge(SH, SZ, 0.3);

  MatrixGraph<string, double> matrix_graph;

  matrix_graph.InsertVertex(BJ);
  matrix_graph.InsertVertex(SH);
  matrix_graph.InsertVertex(GZ);
  matrix_graph.InsertVertex(SZ);

  matrix_graph.InsertEdge(BJ, SH, 0.8);
  matrix_graph.InsertEdge(SH, GZ, 3.9);
  matrix_graph.InsertEdge(GZ, SZ, 7.3);
  matrix_graph.InsertEdge(BJ, GZ, 11.3);
  matrix_graph.InsertEdge(SH, SZ, 0.3);

  cout<<endl<<"**邻接表图测试**"<<endl;
  MinSpanTree<string, double> min_span_tree_adj(100);
  Prim(adjacency_list_graph, BJ, min_span_tree_adj); // 殷书原版堆优化
  min_span_tree_adj.Show();

  cout<<endl<<"**矩阵图测试**"<<endl;
  MinSpanTree<string, double> min_span_tree_matrix(100);
  Prim(matrix_graph, BJ, min_span_tree_matrix); // 朴素版Prim
  min_span_tree_matrix.Show();

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void TestDijkstra() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                       Test Dijkstra                       |"<<endl;
  cout<<"|                     测试Dijkstra最短路径                    |"<<endl;

  string city[5] = { "北京", "上海", "广州", "深圳", "杭州" };

  AdjacencyListGraph<string, double> adjacency_list_graph;	// 邻接表图
  MatrixGraph<string, double> matrix_graph;					// 矩阵图

  // 将5个城市都加入到两个图中
  for (int i = 0; i < 5; i++) {
	  adjacency_list_graph.InsertVertex(city[i]);
  }
  for (int i = 0; i < 5; i++) {
	  matrix_graph.InsertVertex(city[i]);
  }

  // 北京 --> 上海, 98.63
  // 上海 --> 广州, 51.52
  // 广州 --> 深圳, 17 
  // 深圳 --> 杭州, 58.98
  // 北京 --> 深圳, 29.3
  // 北京 --> 杭州, 100.003
  // 广州 --> 杭州, 9.34
  adjacency_list_graph.InsertEdge(city[0], city[1], 98.63);
  adjacency_list_graph.InsertEdge(city[1], city[2], 51.52);
  adjacency_list_graph.InsertEdge(city[2], city[3], 17);
  adjacency_list_graph.InsertEdge(city[3], city[4], 58.98);
  adjacency_list_graph.InsertEdge(city[0], city[3], 29.3);
  adjacency_list_graph.InsertEdge(city[0], city[4], 100.003);
  adjacency_list_graph.InsertEdge(city[2], city[4], 9.34);

  matrix_graph.InsertEdge(city[0], city[1], 98.63);
  matrix_graph.InsertEdge(city[1], city[2], 51.52);
  matrix_graph.InsertEdge(city[2], city[3], 17);
  matrix_graph.InsertEdge(city[2], city[4], 58.98);
  matrix_graph.InsertEdge(city[0], city[3], 29.3);
  matrix_graph.InsertEdge(city[0], city[4], 100.003);
  matrix_graph.InsertEdge(city[2], city[4], 9.34);

  cout<<endl<<"**邻接表图Dijkstra测试**"<<endl<<endl;
  double min_dist_arr_adj[5];
  int from_path_arr_adj[5];

  Dijkstra(adjacency_list_graph, city[0], min_dist_arr_adj, from_path_arr_adj);
  PrintSingleSourceShortestPath(adjacency_list_graph, city[0], min_dist_arr_adj, from_path_arr_adj);

  cout<<endl<<"**矩阵图测试**"<<endl<<endl;
  double min_dist_arr_matrix[5];
  int from_path_arr_matrix[5];

  Dijkstra(adjacency_list_graph, city[0], min_dist_arr_matrix, from_path_arr_matrix);
  PrintSingleSourceShortestPath(adjacency_list_graph, city[0], min_dist_arr_matrix, from_path_arr_matrix);

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void TestBellmanFord() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                      Test BellmanFord                     |"<<endl;
  cout<<"|                    测试BellmanFord最短路径                  |"<<endl;

  string city[5] = { "北京", "上海", "广州", "深圳", "杭州" };

  AdjacencyListGraph<string, double> adjacency_list_graph;	// 邻接表图
  MatrixGraph<string, double> matrix_graph;					// 矩阵图

  // 将5个城市都加入到两个图中
  for (int i = 0; i < 5; i++) {
	  adjacency_list_graph.InsertVertex(city[i]);
  }
  for (int i = 0; i < 5; i++) {
	  matrix_graph.InsertVertex(city[i]);
  }

  // 北京 --> 上海, 98.63
  // 上海 --> 广州, 51.52
  // 广州 --> 深圳, 17 
  // 深圳 --> 杭州, 58.98
  // 北京 --> 深圳, 29.3
  // 北京 --> 杭州, 100.003
  // 广州 --> 杭州, 9.34
  adjacency_list_graph.InsertEdge(city[0], city[1], 98.63);
  adjacency_list_graph.InsertEdge(city[1], city[2], 51.52);
  adjacency_list_graph.InsertEdge(city[2], city[3], 17);
  adjacency_list_graph.InsertEdge(city[3], city[4], 58.98);
  adjacency_list_graph.InsertEdge(city[0], city[3], 29.3);
  adjacency_list_graph.InsertEdge(city[0], city[4], 100.003);
  adjacency_list_graph.InsertEdge(city[2], city[4], 9.34);

  matrix_graph.InsertEdge(city[0], city[1], 98.63);
  matrix_graph.InsertEdge(city[1], city[2], 51.52);
  matrix_graph.InsertEdge(city[2], city[3], 17);
  matrix_graph.InsertEdge(city[2], city[4], 58.98);
  matrix_graph.InsertEdge(city[0], city[3], 29.3);
  matrix_graph.InsertEdge(city[0], city[4], 100.003);
  matrix_graph.InsertEdge(city[2], city[4], 9.34);

  cout<<endl<<"**邻接表图Dijkstra测试**"<<endl<<endl;
  double min_dist_arr1[5];
  int predecessor_arr1[5];

  BellmanFord(adjacency_list_graph, city[0], min_dist_arr1, predecessor_arr1);
  PrintSingleSourceShortestPath(adjacency_list_graph, city[0], min_dist_arr1, predecessor_arr1);

  cout<<endl<<"**矩阵图测试**"<<endl<<endl;
  double min_dist_arr2[5];
  int predecessor_arr2[5];

  BellmanFord(adjacency_list_graph, city[0], min_dist_arr2, predecessor_arr2);
  PrintSingleSourceShortestPath(adjacency_list_graph, city[0], min_dist_arr2, predecessor_arr2);

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}



/*! 测试Floyd最短路径 */
void TestFloyd() {
    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|                    Test Floyd-Warshall                    |"<<endl;
    cout<<"|                     测试弗洛伊德最短路径                     |"<<endl;

    string city[5] = { "北京", "上海", "广州", "深圳", "杭州" };

    AdjacencyListGraph<string, double> adjacency_list_graph;	// 邻接表图
    MatrixGraph<string, double> matrix_graph;					// 矩阵图

    // 将5个城市都加入到两个图中
    for (int i = 0; i < 5; i++) {
        adjacency_list_graph.InsertVertex(city[i]);
    }
    for (int i = 0; i < 5; i++) {
        matrix_graph.InsertVertex(city[i]);
    }

    // 北京 --> 上海, 98.63
    // 上海 --> 广州, 51.52
    // 广州 --> 深圳, 17
    // 深圳 --> 杭州, 58.98
    // 北京 --> 深圳, 29.3
    // 北京 --> 杭州, 100.003
    // 广州 --> 杭州, 9.34
    adjacency_list_graph.InsertEdge(city[0], city[1], 98.63);
    adjacency_list_graph.InsertEdge(city[1], city[2], 51.52);
    adjacency_list_graph.InsertEdge(city[2], city[3], 17);
    adjacency_list_graph.InsertEdge(city[3], city[4], 58.98);
    adjacency_list_graph.InsertEdge(city[0], city[3], 29.3);
    adjacency_list_graph.InsertEdge(city[0], city[4], 100.003);
    adjacency_list_graph.InsertEdge(city[2], city[4], 9.34);

    matrix_graph.InsertEdge(city[0], city[1], 98.63);
    matrix_graph.InsertEdge(city[1], city[2], 51.52);
    matrix_graph.InsertEdge(city[2], city[3], 17);
    matrix_graph.InsertEdge(city[2], city[4], 58.98);
    matrix_graph.InsertEdge(city[0], city[3], 29.3);
    matrix_graph.InsertEdge(city[0], city[4], 100.003);
    matrix_graph.InsertEdge(city[2], city[4], 9.34);

    int matrix_graph_vertices_num = matrix_graph.NumberOfVertices();
    vector<vector<double> > distance(matrix_graph_vertices_num,
                                     vector<double>(matrix_graph_vertices_num));
    vector<vector<int> > predecessor(matrix_graph_vertices_num,
                                     vector<int>(matrix_graph_vertices_num));

    Floyd(matrix_graph, distance, predecessor);

    PrintMultipleSourceShortestPath(matrix_graph, distance, predecessor);

    cout<<"-------------------------------------------------------------"<<endl<<endl;
}


// 关于CyberDash, :)
void TestCyberDashShow() {
  MatrixGraph<int, int> cyber_dash_graph;
  cyber_dash_graph.CyberDashShow();
}
