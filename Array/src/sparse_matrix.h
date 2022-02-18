/*!
 * @file sparse_matrix.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 稀疏矩阵 
 * @version 0.2.1
 * @date 2021-05-13
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#ifndef CYBER_DASH_SPARSE_MATRIX_H
#define CYBER_DASH_SPARSE_MATRIX_H


#include <iostream>
#include <cstdlib>


using namespace std;


//! 稀疏矩阵三元组结构体
template<class T>
struct TriTuple {
  int row; //!< 行索引
  int col; //!< 列索引
  T value; //!< 值

  /*!
   * @brief 赋值运算符重载函数
   * @param tri_tuple 稀疏函数三元组数据
   * @return 当前对象本身
   */
  TriTuple<T>& operator=(TriTuple<T>& tri_tuple) {
    row = tri_tuple.row;
    col = tri_tuple.col;
    value = tri_tuple.value;

    return *this;
  }
};


//! 稀疏矩阵模板类
template<class T>
class SparseMatrix {
public:

  // 构造函数(参数为稀疏矩阵最大元素个数)
  SparseMatrix(int max_size = 100);

  // 复制构造函数(参数为稀疏矩阵)
  SparseMatrix(SparseMatrix<T>& sparse_matrix);

  /*! @brief 析构函数 */
  virtual ~SparseMatrix() { delete[] sparse_matrix_array_; }

  /*! @brief 获取行数 */
  int Rows() { return this->rows_; }
  /*! @brief 设置行数 */
  void SetRows(int rows) { this->rows_ = rows; }

  /*! @brief 获取列数 */
  int Cols() { return this->cols_; };
  /*! @brief 设置行数 */
  void SetCols(int cols) { this->cols_ = cols; };

  /*! @brief 获取元素数 */
  int Terms() { return this->terms_; }
  /*! @brief 设置元素数 */
  void SetTerms(int terms) { this->terms_ = terms; }

  /*! @brief 获取最大元素数 */
  int MaxTerms() { return this->max_terms_; }
  /*! @brief 设置最大元素数 */
  int SetMaxTerms(int max_terms) { this->max_terms_ = max_terms; }

  // 获取元素
  bool GetElement(int row, int col, T& value);
  // 添加元素(如果此位置元素存在, 则覆盖)
  bool AddElement(int row, int col, T value);

  /*! @brief 获取元素数组起始地址 */
  TriTuple<T>* SparseMatrixArray() { return this->sparse_matrix_array_; }

  // 赋值运算符重载函数
  SparseMatrix<T>& operator = (SparseMatrix<T>& sparse_matrix);

  // 转置运算
  SparseMatrix<T>* Transpose();

  // 快速转置运算
  SparseMatrix<T>* FastTranspose();

  // 当前矩阵与sparse_matrix相加 todo: 未实现
  SparseMatrix<T> Add(SparseMatrix<T>& sparse_matrix);

  // 当前矩阵与矩阵sparse_matrix相乘 todo: 未实现
  SparseMatrix<T> Multiply(SparseMatrix<T>& sparse_matrix);

  // 打印稀疏矩阵
  template <class U>
  friend ostream& operator << (ostream& out, SparseMatrix<T>& sparse_matrix);
  // 输入稀疏矩阵
  template <class U>
  friend istream& operator >> (istream& in, SparseMatrix<T>& sparse_matrix);

private:
  int rows_; //!< 行数
  int cols_; //!< 列数
  int terms_; //!< 当前元素数
  int max_terms_; //!< 最大元素数
  TriTuple<T>* sparse_matrix_array_; //!< 元素数组
};


/*!
 * @brief 构造函数(参数为稀疏矩阵最大元素个数)
 * @tparam T 类型模板参数
 * @param max_size 最大元素个数
 */
template<class T>
SparseMatrix<T>::SparseMatrix(int max_size): max_terms_(max_size) {
  if (max_size < 1) {
    cerr<<"初始化max_size错误"<<endl;
    return;
  }

  this->sparse_matrix_array_ = new TriTuple<T>[max_size];
  /* error handler */

  this->max_terms_ = max_size;
  this->rows_ = 0;
  this->cols_ = 0;
  this->terms_ = 0;
}


/*!
 * @brief 复制构造函数(参数为稀疏矩阵)
 * @tparam T 类型模板参数
 * @param sparse_matrix 稀疏矩阵(的引用)
 */
template<class T>
SparseMatrix<T>::SparseMatrix(SparseMatrix<T>& sparse_matrix) :
  rows_(sparse_matrix.Rows()), cols_(sparse_matrix.Cols()),
  terms_(sparse_matrix.Terms()), max_terms_(sparse_matrix.MaxTerms())
{
  this->sparse_matrix_array_ = new TriTuple<T>[this->MaxTerms()];
  /* error handler */

  for (int i = 0; i < this->terms_; i++) {
    this->sparse_matrix_array_[i] = sparse_matrix.SparseMatrixArray()[i];
  }
}


/*!
 * @brief 获取数组元素
 * @tparam T 类型模板参数
 * @param row 行索引
 * @param col 列索引
 * @param value 值引用(用于保存结果)
 * @return 是否获取成功
 */
template<class T>
bool SparseMatrix<T>::GetElement(int row, int col, T& value) {
  for (int i = 0; i < this->Terms(); i++) {
    if (this->sparse_matrix_array_[i].row == row && this->sparse_matrix_array_[i].col == col) {
      value = this->sparse_matrix_array_[i].value;
      return true;
    }
  }

  return false;
}


/*!
 * @brief 添加元素
 * @tparam T 类型模板参数
 * @param row 行索引
 * @param col 列索引
 * @param value 值
 * @return 是否添加成功
 * @note
 * 如果row/col对应的位置已经有数组元素, 则更新数组元素的值
 */
template<class T>
bool SparseMatrix<T>::AddElement(int row, int col, T value) {

  if (row >= this->Rows() || col >= this->Cols()) {
    return false;
  }

  for (int i = 0; i < this->Terms(); i++) {
    if (this->sparse_matrix_array_[i].row == row && this->sparse_matrix_array_[i].col == col) {
      this->sparse_matrix_array_[i].value = value;
      return true;
    }
  }

  if (this->Terms() == this->MaxTerms()) { // 不能再插入
    return false;
  }

  this->sparse_matrix_array_[this->terms_].row =  row;
  this->sparse_matrix_array_[this->terms_].col =  col;
  this->sparse_matrix_array_[this->terms_].value = value;

  this->terms_++;

  return true;
}


/*!
 * @brief 赋值运算符重载函数
 * @tparam T 类型模板参数
 * @param sparse_matrix 稀疏矩阵(的引用)
 * @return 当前数组本身
 */
template<class T>
SparseMatrix<T>& SparseMatrix<T>::operator = (SparseMatrix<T>& sparse_matrix) {

  this->SetRows(sparse_matrix.Rows());
  this->SetCols(sparse_matrix.Cols());
  this->SetTerms(sparse_matrix.Terms());
  this->SetMaxTerms(sparse_matrix.MaxTerms());

  this->sparse_matrix_array_ = new TriTuple<T>[this->MaxTerms()];
  /* error handler */

  for (int i = 0; i < this->terms_; i++) {
    this->sparse_matrix_array_[i] = sparse_matrix.SparseMatrixArray()[i];
  }

  return *this;
}


/*!
 * @brief 打印稀疏矩阵
 * @tparam T 类型模板参数
 * @param out 输出流(的引用)
 * @param sparse_matrix 稀疏矩阵(的引用)
 * @return 输出流(的引用)
 * 代码示例
 * ```
 * cout << sparse_matrix;
 * ```
 */
template<class T>
ostream& operator<<(ostream& out, SparseMatrix<T>& sparse_matrix) {
  out<<"rows = "<<sparse_matrix.Rows()<<endl;
  out<<"cols = "<<sparse_matrix.Cols()<<endl;
  out<<"NonZero terms: "<<sparse_matrix.Terms()<<endl;

  for (int i = 0; i < sparse_matrix.Terms(); i++) {
    out<<"M["<<sparse_matrix.SparseMatrixArray()[i].row<<"]["<<
      sparse_matrix.SparseMatrixArray()[i].col<<"] = "<<
      sparse_matrix.SparseMatrixArray()[i].value<<endl;
  }

  return out;
}


/*!
 * @brief 输入稀疏矩阵
 * @tparam T 类型模板参数
 * @param out 输入流(的引用)
 * @param sparse_matrix 稀疏矩阵(的引用)
 * @return 输入流(的引用)
 * @note
 * 代码示例
 * ```
 * cin >> sparse_matrix;
 * ```
 */
template<class T>
istream& operator>>(istream& in, SparseMatrix<T>& sparse_matrix) {
  cout << "输入rows, cols和terms" << endl;

  int rows = 0;
  int cols = 0;
  int terms = 0;

  in >> rows >> cols >> terms;

  if (terms > sparse_matrix.MaxTerms()) {
    /* error handler */
    exit(1);
  }

  sparse_matrix.SetRows(rows);
  sparse_matrix.SetCols(cols);
  sparse_matrix.SetTerms(terms);

  for (int i = 0; i < sparse_matrix.Terms(); i++) {
    cout << "输入第" << i << "个row, column和term的值" << endl;
    in >> sparse_matrix.SparseMatrixArray()[i].row
      >> sparse_matrix.SparseMatrixArray()[i].col
      >> sparse_matrix.SparseMatrixArray()[i].value;
  }

  cout << sparse_matrix << endl;

  return in;
}


/*!
 * @brief 稀疏矩阵转置
 * @tparam T 类型模板参数
 * @return 转置矩阵的地址
 * @note
 *   两个for循环 \n
 *   时间复杂度O(col^2*row)
 */
template<class T>
SparseMatrix<T>* SparseMatrix<T>::Transpose() {
  SparseMatrix<T>* trans_sparse_matrix_ptr = new SparseMatrix<T>(this->MaxTerms());

  trans_sparse_matrix_ptr->SetRows(this->Cols());
  trans_sparse_matrix_ptr->SetCols(this->Rows());
  trans_sparse_matrix_ptr->SetTerms(this->Terms());

  if (this->Terms() == 0) {
    return trans_sparse_matrix_ptr;
  }

  int cur = 0;
  for (int i = 0; i < this->Cols(); i++) { // 用列号做扫描, 做Cols趟
    for (int j = 0; j < this->Terms(); j++) { // 在数组sparse_matrix_array_中找到列号为i的三元组
      if (this->SparseMatrixArray()[j].col == i) {
        trans_sparse_matrix_ptr->SparseMatrixArray()[cur].row = i; // row等于col
        trans_sparse_matrix_ptr->SparseMatrixArray()[cur].col = this->SparseMatrixArray()[j].row; // col等于row
        trans_sparse_matrix_ptr->SparseMatrixArray()[cur].value = this->SparseMatrixArray()[j].value; // value
        cur++;
      }
    }
  }

  return trans_sparse_matrix_ptr;
}


/*!
 * @brief 稀疏矩阵快速转置
 * @tparam T 类型模板参数
 * @return 转置矩阵的指针
 * @note
 *  空间换时间的思想\n\n
 *
 *  **row_size_arr**: 保存原矩阵各列分别有多少个元素, 对应转置矩阵的各行有多少个元素 \n
 *  **trans_pos_at_each_row_arr**: 执行转置时, 原矩阵各列(转置矩阵各行)的每一列(转置矩阵每一行)的任务执行数组 \n
 *
 *  \n先初始化以上两个数组 \n\n
 *  遍历sparse_matrix_array_ \n
 *  对第i个元素进行转置矩阵对应的赋值 \n
 *  赋值结束后, 更新trans_pos_at_each_row_arr[this->SparseMatrixArray()[i].col]的值(下一次转置矩阵数组执行保存的位置向后挪一位) \n
 */
template<class T>
SparseMatrix<T>* SparseMatrix<T>::FastTranspose() {
  int* row_item_count_arr = new int[this->Cols()];
  int* iter_pos_arr = new int[this->Cols()];

  SparseMatrix<T>* trans_sparse_matrix = new SparseMatrix<T>(this->MaxTerms());

  trans_sparse_matrix->SetRows(this->Cols());
  trans_sparse_matrix->SetCols(this->Rows());
  trans_sparse_matrix->SetTerms(this->Terms());

  if (this->Terms() == 0) {
    return trans_sparse_matrix;
  }

  for (int i = 0; i < this->Cols(); i++) {
    row_item_count_arr[i] = 0;
  }

  // 将转置数组每行有多少个元素, 保存到row_item_count_arr
  for (int i = 0; i < this->Terms(); i++) {
    row_item_count_arr[this->SparseMatrixArray()[i].col]++;
  }

  // 初始化转置数组的三元组数组sparse_matrix_array的分布
  //
  // this->sparse_matrix_array[ 0 ... 第1行的首元素的位置 ... 第i行的首个元素的位置 ... ]
  //                            ^             ^                       ^
  //                            |             |                       |
  //                iter_pos_arr[0]   iter_pos_arr[1]           iter_pos_arr[i] ...
  //
  // 核心算法:
  //    iter_pos_arr[i] = iter_pos_arr[i - 1] + row_item_count_arr[i - 1];
  // 即在三元组数组sparse_matrix_array上, 每行首个元素所在的位置, 等于上一行首个元素的位置 + 该行的所有元素数
  iter_pos_arr[0] = 0;
  for (int i = 1; i < this->Cols(); i++) {
    iter_pos_arr[i] = iter_pos_arr[i - 1] + row_item_count_arr[i - 1];
  }

  for (int i = 0; i < this->Terms(); i++) {
    // 转制后矩阵的当前行索引(等于原数组的列索引)
    int cur_row = this->SparseMatrixArray()[i].col;
    // 当前稀疏矩阵的三元组数组的数组索引, 取iter_pos_arr[cur_row];
    int cur_sparse_matrix_index = iter_pos_arr[cur_row];

    // 转置矩阵的三元组数组
    TriTuple<T>* trans_sparse_matrix_array = trans_sparse_matrix->SparseMatrixArray();
    // 原矩阵的三元组数组
    TriTuple<T>* src_spase_matrix_array = this->SparseMatrixArray();

    // 转置矩阵元素的row/col于原数组互换, value相同
    trans_sparse_matrix_array[cur_sparse_matrix_index].row = src_spase_matrix_array[i].col;
    trans_sparse_matrix_array[cur_sparse_matrix_index].col = src_spase_matrix_array[i].row;
    trans_sparse_matrix_array[cur_sparse_matrix_index].value = src_spase_matrix_array[i].value;

    // 由于trans_sparse_matrix_array[ iter_pos_arr[cur_row] ]处理已经结束, cur_row的下一次处理应在下一个位置
    // iter_pos_arr[cur_row]加1, 表示向后挪一位
    iter_pos_arr[cur_row]++;
  }

  delete[] iter_pos_arr;
  delete[] row_item_count_arr;

  return trans_sparse_matrix;
}


#endif
