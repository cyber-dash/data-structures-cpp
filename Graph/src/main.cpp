/*!
 * @file main.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 图代码演示
 * @version 0.2.1
 * @date 2021-07-14
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#include "graph_algorithm.cpp"
#include "test.h"


using namespace std;


int main(int argc, char** argv) {

  TestMinPriorityQueue();

    /*
  // 测试矩阵图打印矩阵
  TestMatrixGraphPrintMatrix();

  // 测试由结点索引获取结点
  TestGetVertexByIndex();

  // 测试深度优先遍历
  TestDFS();

  // 测试广度优先遍历
  TestBFS();

  // 测试连通图
  TestComponents();
     */

  // 测试普利姆(Prim)最小生成树
  TestPrim();

  // 测试克努斯卡尔(Kruskal)最小生成树
  TestKruskal();

  // 测试迪杰斯特拉(Dijkstra)最短路径
  TestDijkstra();

  // 测试贝尔曼福特(BellmanFord)最短路径
  TestBellmanFord();

  // 测试弗洛伊德(Floyd-Warshall)最短路径
  TestFloyd();

  // 我们是CyberDash团队
  TestCyberDashShow();

  return 0;
}