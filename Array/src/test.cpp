/*!
 * @file test.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 稀疏矩阵测试.cpp文件
 * @version 0.2.1
 * @date 2021-05-16
 */


#include "test.h"


/*!
 * @brief **测试-稀疏矩阵-构造函数**
 * @note
 * 测试-稀疏矩阵-构造函数
 * -------------------
 * -------------------
 *
 * -------------------
 * 初始化sparse_matrix(稀疏矩阵, 100个元素)\n
 * 打印sparse_matrix\n
 *
 *
 * -------------------
 */
void TestSparseMatrixConstructor() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                Test SparseMatrixConstructor               |" << endl;
    cout << "|                    测试-稀疏矩阵-构造函数                  |" << endl << endl << endl;

    // 初始化sparse_matrix(稀疏矩阵, 100个元素)
    SparseMatrix<int> sparse_matrix(100);

    // 打印sparse_matrix
    cout << sparse_matrix;

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-稀疏矩阵-复制构造函数**
 * @note
 * 测试-稀疏矩阵-复制构造函数
 * ----------------------
 * ----------------------
 *
 * ----------------------
 * + **1 构造稀疏矩阵**\n\n
 * 声明sparse_matrix_1\n
 * 设置行数\n
 * 设置列数\n
 * 设置[3][9]\n
 * 设置[4][17]\n\n
 * 打印sparse_matrix_1\n\n
 * + **2 复制稀疏矩阵**\n\n
 * 使用sparse_matrix_1复制sparse_matrix_2\n
 * 打印sparse_matrix_2\n
 *
 *
 * ----------------------
 */
void TestSparseMatrixCopyConstructor() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|              Test SparseMatrix CopyConstructor            |" << endl;
    cout << "|                  测试-稀疏矩阵-复制构造函数               |" << endl << endl << endl;

    // ---------- 1 构造稀疏矩阵 ----------

    SparseMatrix<int> sparse_matrix_1(200);                                 // 声明sparse_matrix_1
    sparse_matrix_1.SetRows(10);                                            // 设置行数
    sparse_matrix_1.SetCols(20);                                            // 设置列数
    sparse_matrix_1.SetElement(3, 9, 100);                                  // 设置[3][9]
    sparse_matrix_1.SetElement(4, 17, 83);                                  // 设置[4][17]

    cout << "打印sparse_matrix_1:" << endl;
    cout << sparse_matrix_1 << endl << endl;                                // 打印sparse_matrix_1

    // ---------- 2 复制稀疏矩阵 ----------

    SparseMatrix<int> sparse_matrix_2(sparse_matrix_1);                     // 使用sparse_matrix_1复制sparse_matrix_2
    cout << "打印sparse_matrix_2:" << endl;
    cout << sparse_matrix_2;                                                // 打印sparse_matrix_2

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-稀疏矩阵-转置**
 * @note
 * 测试-稀疏矩阵-转置
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 构造稀疏矩阵**\n\n
 * 声明sparse_matrix\n
 * 设置行数\n
 * 设置列数\n
 * 设置[0][1]\n
 * 设置[1][0]\n
 * 设置[6][7]\n
 * 设置[9][19]\n
 * 打印sparse_matrix\n\n
 * + **2 转置**\n\n
 * 调用Transpose, 获取trans_sparse_matrix(转置矩阵)\n
 * 打印trans_sparse_matrix\n
 *
 *
 * ---------------
 */
void TestSparseMatrixTranspose() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                Test SparseMatrix Transpose                |" << endl;
    cout << "|                      测试-稀疏矩阵-转置                   |" << endl << endl << endl;

    // ---------- 1 构造稀疏矩阵 ----------

    SparseMatrix<double> sparse_matrix(100);                                                    // 声明sparse_matrix

    sparse_matrix.SetRows(10);                                                                  // 设置行数
    sparse_matrix.SetCols(20);                                                                  // 设置列数

    sparse_matrix.SetElement(0, 1, 11.345);                                                     // 设置[0][1]
    sparse_matrix.SetElement(1, 0, 4.2);                                                        // 设置[1][0]
    sparse_matrix.SetElement(6, 7, 432.569);                                                    // 设置[6][7]
    sparse_matrix.SetElement(9, 19, 54.8);                                                      // 设置[9][19]

    cout << "sparse_matrix矩阵:" << endl;
    cout << sparse_matrix << endl;                                                              // 打印sparse_matrix

    // ---------- 2 转置 ----------

    SparseMatrix<double>* trans_sparse_matrix = sparse_matrix.Transpose();                      // 调用Transpose, 获取trans_sparse_matrix(转置矩阵)

    cout << "转置后的矩阵:" << endl;
    cout << *trans_sparse_matrix << endl;                                                       // 打印trans_sparse_matrix

    cout <<"-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-稀疏矩阵-快速转置**
 * @note
 * 测试-稀疏矩阵-快速转置
 * -------------------
 * -------------------
 *
 * -------------------
 * + **1 构造稀疏矩阵**\n\n
 * 声明sparse_matrix\n
 * 设置行数\n
 * 设置列数\n
 * 设置[0][0]\n
 * 设置[49][38]\n
 * 设置[0][1]\n
 * 设置[6][7]\n
 * 设置[6][22]\n
 * 设置[1][0]\n
 * 设置[49][39]\n
 * 打印sparse_matrix\n\n
 * + **2 转置**\n\n
 * 调用Transpose, 获取trans_sparse_matrix(转置矩阵)\n
 * 打印trans_sparse_matrix\n
 *
 *
 * -------------------
 */
void TestSparseMatrixFastTranspose() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|               Test SparseMatrix FastTranspose             |" << endl;
    cout << "|                   测试-稀疏矩阵-快速转置                  |" << endl << endl << endl;

    // ---------- 1 构造稀疏矩阵 ----------

    SparseMatrix<double> sparse_matrix(100);                                        // 声明sparse_matrix

    sparse_matrix.SetRows(50);                                                      // 设置行数
    sparse_matrix.SetCols(40);                                                      // 设置列数

    sparse_matrix.SetElement(0, 0, 9);                                              // 设置[0][0]
    sparse_matrix.SetElement(49, 38, 19.7989);                                      // 设置[49][38]
    sparse_matrix.SetElement(0, 1, 11.345);                                         // 设置[0][1]
    sparse_matrix.SetElement(6, 7, 432.569);                                        // 设置[6][7]
    sparse_matrix.SetElement(6, 22, 5490.989);                                      // 设置[6][22]
    sparse_matrix.SetElement(1, 0, 4.2);                                            // 设置[1][0]
    sparse_matrix.SetElement(49, 39, 64);                                           // 设置[49][39]

    cout << "sparse_matrix矩阵:" << endl;
    cout << sparse_matrix << endl;                                                  // 打印sparse_matrix

    // ---------- 2 转置 ----------

    SparseMatrix<double>* trans_sparse_matrix = sparse_matrix.Transpose();          // 调用Transpose, 获取trans_sparse_matrix(转置矩阵)

    cout << "转置后的矩阵:" << endl;
    cout << *trans_sparse_matrix << endl;                                           // 打印trans_sparse_matrix

    cout << "-------------------------------------------------------------" << endl << endl;
}
