//
// Created by cyberdash@163.com(抖音id:cyberdash_yuan) on 2021/1/23.
//

#include "graph_algorithm.cpp"
#include "test.h"


using namespace std;


int main(int argc, char** argv) {

  TestGetVertexByIndex();

  TestDFS();

  // TestBFS();

  TestComponents();

  TestPrim();

  TestKruskal();

  TestShortestPath();

  return 0;
}