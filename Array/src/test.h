/*!
 * @file test.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 稀疏矩阵测试头文件
 * @version 0.2.1
 * @date 2021-05-13
 */

#ifndef CYBER_DASH_SPARSE_MATRIX_TEST_H
#define CYBER_DASH_SPARSE_MATRIX_TEST_H


#include "sparse_matrix.h"


// 测试-稀疏矩阵-构造函数
void TestSparseMatrixConstructor();

// 测试-稀疏矩阵-复制构造函数
void TestSparseMatrixCopyConstructor();

// 测试-稀疏矩阵-转置
void TestSparseMatrixTranspose();

// 测试-稀疏矩阵-快速转置
void TestSparseMatrixFastTranspose();


#endif // CYBER_DASH_SPARSE_MATRIX_TEST_H
