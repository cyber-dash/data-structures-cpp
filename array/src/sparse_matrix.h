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


template<class T>
struct TriTuple {

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

private:
  int rows_;
  int cols_;
  int terms_;
  int max_terms_;
  TriTuple<T>* sparse_matrix_array_;
};


#endif
/**
 * @brief  CYBER_DASH_TRI_TUPLE_H
 * 
 */