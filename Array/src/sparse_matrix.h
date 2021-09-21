/**
 * @file sparse_matrix.h
 * @author cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 稀疏矩阵 
 * @version 0.1
 * @date 2021-05-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef CYBER_DASH_TRI_TUPLE_H
#define CYBER_DASH_TRI_TUPLE_H


#include <iostream>
// #include <ostream>


using namespace std;


template<class T>
struct TriTuple {
  int row;
  int col;
  T value;
  TriTuple<T>& operator=(TriTuple<T>& trituple) {
    row = trituple.row;
    col = trituple.col;
    value = trituple.value;
  }
};


/**
 * @brief 构造稀疏矩阵
 * 
 * @tparam T 存储的值
 */
template<class T>
class SparseMatrix {
public:
/**
 * @brief 构建一个新的稀疏矩阵
 * 
 * @param max_size 矩阵最大容量
 */
  SparseMatrix(int max_size);
  SparseMatrix(SparseMatrix<T>& sparse_matrix);
  ~SparseMatrix() { delete[] sparse_matrix_array_; }

  SparseMatrix<T>& operator=(SparseMatrix<T>& sparse_matrix);

  // 转置运算
  SparseMatrix<T> Transpose();

  // 快速转置运算
  SparseMatrix<T> FastTranspose();

  // 当前矩阵与sparse_matrix相加
  SparseMatrix<T> Add(SparseMatrix<T>& sparse_matrix);

  // 当前矩阵与矩阵sparse_matrix相乘
  SparseMatrix<T> Multiply(SparseMatrix<T>& sparse_matrix);

  friend ostream& operator<<(ostream& out, SparseMatrix<T>& sparse_matrix);
  friend istream& operator>>(istream& in, SparseMatrix<T>& sparse_matrix);

private:
  int rows_;
  int cols_;
  int terms_;
  int max_terms_;
  TriTuple<T>* sparse_matrix_array_;
};


/**
 * @brief 构造函数
 * @tparam T 数据模板类型
 * @param max_size 矩阵的最大维度
 */
template<class T>
SparseMatrix<T>::SparseMatrix(int max_size): max_terms_(max_size) {
  if (max_size < 1) {
    cerr<<"初始化max_size错误"<<endl;
    return;
  }

  this->sparse_matrix_array_ = new TriTuple<T>[max_size];
  /* error handler */

  this->rows_ = 0;
  this->cols_ = 0;
  this->terms_ = 0;
}


template<class T>
SparseMatrix<T>::SparseMatrix(SparseMatrix<T>& sparse_matrix) {
  this->rows_ = sparse_matrix.rows_;
  this->cols_ = sparse_matrix.cols_;
  this->terms_ = sparse_matrix.terms_;
  this->max_terms_ = sparse_matrix.max_terms_;

  this->sparse_matrix_array_ = new TriTuple<T>[this->max_terms_];
  /* error handler */

  for (int i = 0; i < this->terms_; i++) {
    this->sparse_matrix_array_[i] = sparse_matrix.sparse_matrix_array_[i];
  }
}


template<class T>
ostream& operator<<(ostream &out, SparseMatrix<T> &sparse_matrix) {
  return out;
}


template<class T>
istream &operator>>(istream &in, SparseMatrix<T> &sparse_matrix) {
  return in;
}


template<class T>
SparseMatrix<T> SparseMatrix<T>::Transpose() {
  return SparseMatrix<T>(0);
}


template<class T>
SparseMatrix<T> SparseMatrix<T>::FastTranspose() {
  return SparseMatrix<T>(0);
}


#endif
/**
 * @brief  CYBER_DASH_TRI_TUPLE_H
 * 
 */