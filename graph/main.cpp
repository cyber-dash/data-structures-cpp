//
// Created by cyberdash@163.com(抖音id:cyberdash_yuan) on 2021/1/23.
//

#include <iostream>
#include "graph_adjacency_list.h"
#include "graph_algorithm.cpp"
#include "test.h"


using namespace std;


int main(int argc, char** argv) {

  GraphAdjacencyList<int, double> graph_adjacency_list;

  /*
  cin>>graph_adjacency_list;
  cout<<graph_adjacency_list;
   */

  graph_adjacency_list.InsertVertex(0);
  graph_adjacency_list.InsertVertex(1);
  graph_adjacency_list.InsertVertex(2);

  /*
  graph_adjacency_list.InsertEdge(0, 1, 0.9);
  graph_adjacency_list.InsertEdge(0, 2, 0.6);
  graph_adjacency_list.InsertEdge(2, 1, 0.3);
   */

  graph_adjacency_list.InsertEdge(0, 1, 0);
  graph_adjacency_list.InsertEdge(0, 2, 0);
  graph_adjacency_list.InsertEdge(2, 1, 0);

  cout<<graph_adjacency_list;

  graph_adjacency_list.CyberDashShow();

  // graph_adjacency_list.RemoveEdge(0, 1);
  // graph_adjacency_list.RemoveEdge(2, 1);

  // graph_adjacency_list.RemoveVertex(0);
  // graph_adjacency_list.RemoveVertex(2);
  // graph_adjacency_list.RemoveVertex(1);

  // cout<<graph_adjacency_list;

  // DFS(graph_adjacency_list, 0);
  // BFS(graph_adjacency_list, 0);

  TestComponents();

  TestPrim();

  TestKruskal();

  TestShortestPath();

  return 0;
}