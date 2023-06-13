/*!
 * @file main.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 图代码演示
 * @version 0.2.1
 * @date 2021-07-14
 */

#include "graph_algorithm.cpp"
#include "test.h"


using namespace std;


/*!
 * @brief **main函数**
 * @param argc
 * @param argv
 * @return 0
 * @note
 * main函数
 * -------
 * -------
 *
 * -------
 * 测试-图-基础函数\n
 * 测试-矩阵图-打印矩阵\n
 * 测试-图-深度优先遍历(递归)\n
 *
 *
 * -------
 */
int main(int argc, char** argv) {

    /*
    // 测试-图-基础函数
    TestBaseFunctions();

    // 测试-矩阵图-打印矩阵
    TestMatrixGraphPrintMatrix();

    // 测试-图-深度优先遍历(递归)
    TestDfsRecursive();

    // 测试广度优先遍历
    TestBFS();

    // 测试连通图
    TestComponents();

    // 测试普利姆(Prim)最小生成树
    TestPrim();

    // 测试克努斯卡尔(Kruskal)最小生成树
    TestKruskal();

    // 测试迪杰斯特拉(Dijkstra)最短路径
    TestDijkstra();

    // 测试贝尔曼福特(BellmanFord)最短路径
    TestBellmanFord();
     */

    // 测试弗洛伊德(Floyd-Warshall)最短路径
    TestFloyd();

    /*
    // 测试拓扑排序
    TestTopologicalSort();

    // 关键路径
    TestCriticalPaths();
     */

    return 0;
}