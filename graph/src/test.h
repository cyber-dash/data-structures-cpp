//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2021/2/15.
//

#ifndef CYBER_DASH_GRAPH_TEST_H
#define CYBER_DASH_GRAPH_TEST_H


#include "adjacency_list_graph.h"
#include "matrix_graph.h"
#include <iostream>


// 测试矩阵图的矩阵
void TestMatrixGraphMatrix();

// 测试使用结点索引获取结点
void TestGetVertexByIndex();

// 测试DFS
void TestDFS();

// 测试BFS
void TestBFS();

// 测试连通分量
void TestComponents();

// 测试KrusKal
void TestKruskal();

// 测试Prim算法
void TestPrim();

// 测试Dijkstra最小生成树
void TestShortestPath();

// 关于CyberDash
void TestCyberDashShow();


#endif //CYBER_DASH_GRAPH_TEST_H
