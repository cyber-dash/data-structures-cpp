//
// Created by cyberdash@163.com(抖音id:cyberdash_yuan) on 2021/5/16.
//

#ifndef CYBER_DASH_TRI_TUPLE_H
#define CYBER_DASH_TRI_TUPLE_H


template<class T>
struct TriTuple {

};


template<class T>
class SparseMatrix {
public:
  SparseMatrix(int max_size);
  SparseMatrix(SparseMatrix<T>& sparse_matrix);

private:
  int rows_;
  int cols_;
  int terms_;
  int max_terms_;
  TriTuple<T>* sparse_matrix_array_;
};


#endif // CYBER_DASH_TRI_TUPLE_H
