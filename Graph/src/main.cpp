/*!
 * @file main.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 图demo演示
 * @version 0.2.1
 * @date 2021-07-14
 *
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */
#include "graph_algorithm.cpp"
#include "test.h"


using namespace std;


int main(int argc, char** argv) {

  TestMatrixGraphMatrix();

  TestGetVertexByIndex();

  TestDFS();

  TestBFS();

  TestComponents();

  TestPrim();

  TestKruskal();

  TestDijkstraShortestPath();

  TestCyberDashShow();

  return 0;
}