//
// Created by fenixlee@163.com(抖音: cyberdash_yuan) on 2021/2/15.
//

#include "test.h"
#include "graph_algorithm.h"
#include "graph_algorithm.cpp"


using namespace std;


void TestComponents() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                      Test Components                      |"<<endl;
  cout<<"|                        测试连通分量                         |"<<endl;
  cout<<"|  节点:                                                    |"<<endl;
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


/*
void TestPrim() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                         Test Prim                         |"<<endl;
  cout<<"|                        测试Prim算法                        |"<<endl;
  cout<<"|  节点:                                                    |"<<endl;
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
  Prim(graph_adjacency_list, BJ, min_span_tree);

  min_span_tree.Show();

  cout<<"-------------------------------------------------------------"<<endl;
}
 */


void TestPrim() {

  GraphAdjacencyList<string, double> graph_adjacency_list;

  string D = "D";

  graph_adjacency_list.InsertVertex("A");
  graph_adjacency_list.InsertVertex("B");
  graph_adjacency_list.InsertVertex("C");
  graph_adjacency_list.InsertVertex("D");
  graph_adjacency_list.InsertVertex("E");
  graph_adjacency_list.InsertVertex("F");
  graph_adjacency_list.InsertVertex("G");

  graph_adjacency_list.InsertEdge("A", "B", 7);
  graph_adjacency_list.InsertEdge("B", "C", 8);
  graph_adjacency_list.InsertEdge("A", "D", 5);
  graph_adjacency_list.InsertEdge("B", "D", 9);
  graph_adjacency_list.InsertEdge("B", "E", 7);
  graph_adjacency_list.InsertEdge("D", "E", 15);
  graph_adjacency_list.InsertEdge("E", "F", 8);
  graph_adjacency_list.InsertEdge("G", "F", 11);
  graph_adjacency_list.InsertEdge("G", "E", 9);

  MinSpanTree<string, double> min_span_tree(100);
  Prim(graph_adjacency_list, D, min_span_tree);

  min_span_tree.Show();
}


void TestShortestPath() {
  cout<<endl;
  cout<<"************************* CyberDash *************************"<<endl;
  cout<<"*                       Test Dijkstra                       *"<<endl;
  cout<<"*                   测试Dijkstra最小生成树算法                 *"<<endl;
  cout<<"************************* CyberDash *************************"<<endl<<endl;

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

  ShortestPath(graph_adjacency_list, v0, dist, path);
  PrintShortestPath(graph_adjacency_list, v0, dist, path);
}
