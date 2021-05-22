//
// Created by fenixlee@163.com(抖音: cyberdash_yuan) on 2021/2/15.
//

#include "test.h"
#include "graph_algorithm.h"
#include "graph_algorithm.cpp"


using namespace std;


// 测试使用结点索引获取结点
void TestGetVertexByIndex() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                   Test GetVertexByIndex                   |"<<endl;
  cout<<"|                   测试使用结点索引获取结点                    |"<<endl;

  cout<<"邻接表图:"<<endl;
  GraphAdjacencyList<string, double> graph_adjacency_list;

  graph_adjacency_list.InsertVertex("北京");
  graph_adjacency_list.InsertVertex("上海");
  graph_adjacency_list.InsertVertex("广州");
  graph_adjacency_list.InsertVertex("深圳");

  graph_adjacency_list.InsertEdge("北京", "上海", 0.8);
  graph_adjacency_list.InsertEdge("上海", "广州", 3.9);
  graph_adjacency_list.InsertEdge("广州", "深圳", 7.3);
  graph_adjacency_list.InsertEdge("北京", "广州", 11.3);
  graph_adjacency_list.InsertEdge("上海", "深圳", 0.3);

  string BJ;
  string SH;
  string GZ;
  string SZ;

  bool done;

  done = graph_adjacency_list.GetVertexByIndex(BJ, 0);
  done = graph_adjacency_list.GetVertexByIndex(SH, 1);
  done = graph_adjacency_list.GetVertexByIndex(GZ, 2);
  done = graph_adjacency_list.GetVertexByIndex(SZ, 3);

  cout<<"结点0: "<<BJ<<endl;
  cout<<"结点1: "<<SH<<endl;
  cout<<"结点2: "<<GZ<<endl;
  cout<<"结点3: "<<SZ<<endl;

  cout<<endl<<"矩阵图:"<<endl;
  GraphMatrix<string, double> matrix_graph(10);
  matrix_graph.InsertVertex("地球");
  matrix_graph.InsertVertex("火星");
  matrix_graph.InsertVertex("木星");
  matrix_graph.InsertVertex("水星");

  matrix_graph.InsertEdge("地球", "火星", 0.8);
  matrix_graph.InsertEdge("火星", "木星", 3.9);
  matrix_graph.InsertEdge("木星", "水星", 7.3);
  matrix_graph.InsertEdge("地球", "木星", 11.3);
  matrix_graph.InsertEdge("火星", "水星", 0.3);

  done = matrix_graph.GetVertexByIndex(BJ, 0);
  done = matrix_graph.GetVertexByIndex(SH, 1);
  done = matrix_graph.GetVertexByIndex(GZ, 2);
  done = matrix_graph.GetVertexByIndex(SZ, 3);

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

  GraphAdjacencyList<int, int> graph_adjacency_list;

  int v0 = 0;
  int v1 = 1;
  int v2 = 2;
  int v3 = 3;
  int v4 = 4;

  graph_adjacency_list.InsertVertex(v0);
  graph_adjacency_list.InsertVertex(v1);
  graph_adjacency_list.InsertVertex(v2);
  graph_adjacency_list.InsertVertex(v3);
  graph_adjacency_list.InsertVertex(v4);

  graph_adjacency_list.InsertEdge(v0, v1, 100);
  graph_adjacency_list.InsertEdge(v1, v2, 50);
  graph_adjacency_list.InsertEdge(v2, v3, 20);
  graph_adjacency_list.InsertEdge(v3, v4, 60);
  graph_adjacency_list.InsertEdge(v0, v3, 30);
  graph_adjacency_list.InsertEdge(v0, v4, 100);
  graph_adjacency_list.InsertEdge(v2, v4, 10);

  DFS(graph_adjacency_list, v0);

  cout<<"-------------------------------------------------------------"<<endl;
}


// 测试BFS
void TestBFS() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                          Test BFS                         |"<<endl;
  cout<<"|                       测试广度优先遍历                      |"<<endl;

  GraphAdjacencyList<int, int> graph_adjacency_list;

  int v0 = 0;
  int v1 = 1;
  int v2 = 2;
  int v3 = 3;
  int v4 = 4;

  graph_adjacency_list.InsertVertex(v0);
  graph_adjacency_list.InsertVertex(v1);
  graph_adjacency_list.InsertVertex(v2);
  graph_adjacency_list.InsertVertex(v3);
  graph_adjacency_list.InsertVertex(v4);

  graph_adjacency_list.InsertEdge(v0, v1, 100);
  graph_adjacency_list.InsertEdge(v1, v2, 50);
  graph_adjacency_list.InsertEdge(v2, v3, 20);
  graph_adjacency_list.InsertEdge(v3, v4, 60);
  graph_adjacency_list.InsertEdge(v0, v3, 30);
  graph_adjacency_list.InsertEdge(v0, v4, 100);
  graph_adjacency_list.InsertEdge(v2, v4, 10);

  BFS(graph_adjacency_list, v0);

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

  GraphAdjacencyList<int, double> graph_adjacency_list;

  graph_adjacency_list.InsertVertex(0);
  graph_adjacency_list.InsertVertex(1);
  graph_adjacency_list.InsertVertex(2);
  graph_adjacency_list.InsertVertex(3);

  graph_adjacency_list.InsertEdge(0, 1, 0.8);
  graph_adjacency_list.InsertEdge(2, 3, 7.3);

  Components(graph_adjacency_list);

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

  GraphAdjacencyList<string, double> graph_adjacency_list;

  string BJ = "北京";
  string SH = "上海";
  string GZ = "广州";
  string SZ = "深圳";

  graph_adjacency_list.InsertVertex(BJ);
  graph_adjacency_list.InsertVertex(SH);
  graph_adjacency_list.InsertVertex(GZ);
  graph_adjacency_list.InsertVertex(SZ);

  graph_adjacency_list.InsertEdge(BJ, SH, 0.8);
  graph_adjacency_list.InsertEdge(SH, GZ, 3.9);
  graph_adjacency_list.InsertEdge(GZ, SZ, 7.3);
  graph_adjacency_list.InsertEdge(BJ, GZ, 11.3);
  graph_adjacency_list.InsertEdge(SH, SZ, 0.3);

  MinSpanTree<string, double> min_span_tree(100);
  Kruskal(graph_adjacency_list, min_span_tree);

  min_span_tree.Show();

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

  GraphAdjacencyList<string, double> graph_adjacency_list;

  string BJ = "北京";
  string SH = "上海";
  string GZ = "广州";
  string SZ = "深圳";

  graph_adjacency_list.InsertVertex(BJ);
  graph_adjacency_list.InsertVertex(SH);
  graph_adjacency_list.InsertVertex(GZ);
  graph_adjacency_list.InsertVertex(SZ);

  graph_adjacency_list.InsertEdge(BJ, SH, 0.8);
  graph_adjacency_list.InsertEdge(SH, GZ, 3.9);
  graph_adjacency_list.InsertEdge(GZ, SZ, 7.3);
  graph_adjacency_list.InsertEdge(BJ, GZ, 11.3);
  graph_adjacency_list.InsertEdge(SH, SZ, 0.3);

  MinSpanTree<string, double> min_span_tree(100);
  // Prim(graph_adjacency_list, BJ, min_span_tree); // 殷书原版实现
  Prim(graph_adjacency_list, BJ, min_span_tree); // 朴素版Prim

  min_span_tree.Show();

  cout<<"-------------------------------------------------------------"<<endl;
}


void TestShortestPath() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                 Test DijkstraShortestPath                 |"<<endl;
  cout<<"|                     测试Dijkstra最短路径                    |"<<endl;

  GraphAdjacencyList<int, int> graph_adjacency_list;

  int v0 = 0;
  int v1 = 1;
  int v2 = 2;
  int v3 = 3;
  int v4 = 4;

  graph_adjacency_list.InsertVertex(v0);
  graph_adjacency_list.InsertVertex(v1);
  graph_adjacency_list.InsertVertex(v2);
  graph_adjacency_list.InsertVertex(v3);
  graph_adjacency_list.InsertVertex(v4);

  graph_adjacency_list.InsertEdge(v0, v1, 100);
  graph_adjacency_list.InsertEdge(v1, v2, 50);
  graph_adjacency_list.InsertEdge(v2, v3, 20);
  graph_adjacency_list.InsertEdge(v3, v4, 60);
  graph_adjacency_list.InsertEdge(v0, v3, 30);
  graph_adjacency_list.InsertEdge(v0, v4, 100);
  graph_adjacency_list.InsertEdge(v2, v4, 10);

  int dist[5];
  for (int i = 0; i < 5; i++) {
    dist[i] = (int)MAX_WEIGHT;
  }

  int path[5];

  DijkstraShortestPath(graph_adjacency_list, v0, dist, path);

  PrintShortestPath(graph_adjacency_list, v0, dist, path);

  cout<<"-------------------------------------------------------------"<<endl;
}
