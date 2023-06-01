/*!
 * @file main.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 稀疏矩阵测试Demo演示
 * @version 0.2.1
 * @date 2021-05-16
 */

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
 * aaa
 *
 * -------
 *
 * 测试-稀疏矩阵-构造函数\n
 * 测试-稀疏矩阵-复制构造函数\n
 * 测试-稀疏矩阵-转置\n
 * 测试-稀疏矩阵-快速转置\n
 *
 * -------
 */
int main(int argc, char** argv) {

    // 测试-稀疏矩阵-构造函数
    TestSparseMatrixConstructor();

    // 测试-稀疏矩阵-复制构造函数
    TestSparseMatrixCopyConstructor();

    // 测试-稀疏矩阵-转置
    TestSparseMatrixTranspose();

    // 测试-稀疏矩阵-快速转置
    TestSparseMatrixFastTranspose();

    return 0;
}