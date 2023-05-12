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
 */
void TestSparseMatrixConstructor() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                Test SparseMatrixConstructor               |" << endl;
    cout << "|                    测试-稀疏矩阵-构造函数                  |" << endl << endl << endl;

    SparseMatrix<int> sparse_matrix(100);

    cout << sparse_matrix;

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-稀疏矩阵-复制构造函数**
 */
void TestSparseMatrixCopyConstructor() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|              Test SparseMatrix CopyConstructor            |" << endl;
    cout << "|                  测试-稀疏矩阵-复制构造函数               |" << endl << endl << endl;

    SparseMatrix<int> sparse_matrix_1(100);
    sparse_matrix_1.SetRows(10);
    sparse_matrix_1.SetCols(20);
    sparse_matrix_1.SetElement(3, 9, 100);
    sparse_matrix_1.SetElement(4, 17, 83);

    cout << "打印sparse_matrix_1:" << endl;
    cout << sparse_matrix_1 << endl << endl;

    SparseMatrix<int> sparse_matrix_2(sparse_matrix_1);
    cout << "打印sparse_matrix_2:" << endl;
    cout << sparse_matrix_2;

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-稀疏矩阵-转置**
 */
void TestSparseMatrixTranspose() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                Test SparseMatrix Transpose                |" << endl;
    cout << "|                      测试-稀疏矩阵-转置                   |" << endl << endl << endl;

    SparseMatrix<double> sparse_matrix(100);

    sparse_matrix.SetRows(10);
    sparse_matrix.SetCols(20);

    sparse_matrix.SetElement(0, 1, 11.345);
    sparse_matrix.SetElement(1, 0, 4.2);
    sparse_matrix.SetElement(6, 7, 432.569);
    sparse_matrix.SetElement(9, 19, 54.8);

    cout << "sparse_matrix矩阵:" << endl;
    cout << sparse_matrix << endl;

    SparseMatrix<double>* trans_sparse_matrix = sparse_matrix.Transpose();

    cout << "转置后的矩阵:" << endl;
    cout << *trans_sparse_matrix << endl;

    cout <<"-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-稀疏矩阵-快速转置**
 */
void TestSparseMatrixFastTranspose() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|               Test SparseMatrix FastTranspose             |" << endl;
    cout << "|                   测试-稀疏矩阵-快速转置                  |" << endl << endl << endl;

    SparseMatrix<double> sparse_matrix(100);

    sparse_matrix.SetRows(50);
    sparse_matrix.SetCols(40);

    sparse_matrix.SetElement(0, 0, 9);
    sparse_matrix.SetElement(49, 38, 19.7989);
    sparse_matrix.SetElement(0, 1, 11.345);
    sparse_matrix.SetElement(6, 7, 432.569);
    sparse_matrix.SetElement(6, 22, 5490.989);
    sparse_matrix.SetElement(1, 0, 4.2);
    sparse_matrix.SetElement(49, 39, 64);

    cout << "sparse_matrix矩阵:" << endl;
    cout << sparse_matrix << endl;

    sparse_matrix = *(sparse_matrix.FastTranspose());

    cout << "转置后的矩阵:" << endl;
    cout << sparse_matrix << endl;

    cout << "-------------------------------------------------------------" << endl << endl;
}
