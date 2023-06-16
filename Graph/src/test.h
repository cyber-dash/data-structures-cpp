/*!
 * @file test.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 图测试头文件
 * @version 0.2.1
 * @date 2021-10-9
 */

#ifndef CYBER_DASH_GRAPH_TEST_H
#define CYBER_DASH_GRAPH_TEST_H


#include "adjacency_list_graph.h"
#include "matrix_graph.h"


// 测试-图-基础函数
void TestBaseFunctions();

// 测试-矩阵图-打印矩阵
void TestMatrixGraphPrintMatrix();

// 测试-图-深度优先遍历(递归)
void TestDfsRecursive();

// 测试-图-广度优先遍历
void TestBFS();

// 测试-图-连通分量
void TestComponents();

// 测试-图-最小生成树Kruskal
void TestKruskal();

// 测试-图-最小生成树Prim
void TestPrim();

// 测试-图-最短路径Dijkstra
void TestDijkstra();

// 测试-图-最短路径BellmanFord
void TestBellmanFord();

// 测试-图-最短路径Floyd
void TestFloyd();

// 测试拓扑排序
void TestTopologicalSort();

// 测试关键路径
void TestCriticalPaths();


#endif //CYBER_DASH_GRAPH_TEST_H
