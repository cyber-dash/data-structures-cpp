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
 * 测试广度优先遍历\n
 * 测试-图-广度优先遍历\n
 * 测试-图-连通分量\n
 * 测试-图-最小生成树Prim\n
 * 测试-图-最小生成树Kruskal\n
 * 测试-图-最短路径Dijkstra\n
 * 测试-图-最短路径BellmanFord\n
 * 测试-图-最短路径Floyd\n
 * 测试-图-拓扑排序\n
 * 测试-图-关键路径\n
 *
 *
 * -------
 */
int main(int argc, char** argv) {

    // 测试-图-基础函数
    TestBaseFunctions();

    // 测试-矩阵图-打印矩阵
    TestMatrixGraphPrintMatrix();

    // 测试-图-深度优先遍历(递归)
    TestDfsRecursive();

    // 测试-图-广度优先遍历
    TestBFS();

    // 测试-图-连通分量
    TestComponents();

    // 测试-图-最小生成树Prim
    TestPrim();

    // 测试-图-最小生成树Kruskal
    TestKruskal();

    // 测试-图-最短路径Dijkstra
    TestDijkstra();

    // 测试-图-最短路径BellmanFord
    TestBellmanFord();

    // 测试-图-最短路径Floyd
    TestFloyd();

    // 测试-图-拓扑排序
    TestTopologicalSort();

    // 测试-图-关键路径
    TestCriticalPaths();

    return 0;
}