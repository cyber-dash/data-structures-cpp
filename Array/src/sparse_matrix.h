/*!
 * @file sparse_matrix.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 稀疏矩阵 
 * @version 0.2.1
 * @date 2021-05-13
 */

#ifndef CYBER_DASH_SPARSE_MATRIX_H
#define CYBER_DASH_SPARSE_MATRIX_H


#include <stdexcept>
#include <iostream>
#include <cstdlib>


using namespace std;


/*!
 * @brief **稀疏矩阵三元组模板结构体**
 */
template<typename TValue>
struct TriTuple {
    int row;         //!< 行索引
    int col;         //!< 列索引
    TValue value;    //!< 值

    /*!
     * @brief **重载=**
     * @param tri_tuple 稀疏矩阵三元组元素
     * @return 当前对象的引用
     * @note
     * 重载=
     * -----
     * -----
     *
     * -----
     * + **1 赋值自身处理**\n
     * **if** 赋值自身 :\n
     * &emsp; 返回*this\n\n
     * + **2 赋值**\n
     * row赋值\n
     * col赋值\n
     * value赋值\n\n
     * 返回*this\n
     */
    TriTuple<TValue>& operator=(const TriTuple<TValue>& tri_tuple) {

        // ---------- 1 赋值自身处理 ----------

        if (&tri_tuple == this) {                           // if 赋值自身
            return *this;                                   // 返回*this
        }

        // ---------- 2 赋值 ----------

        row = tri_tuple.row;                                // row赋值
        col = tri_tuple.col;                                // col赋值
        value = tri_tuple.value;                            // value赋值

        return *this;                                       // 返回*this
    }
};


template<typename TValue> class SparseMatrix;
template<typename TValue> ostream& operator<< (ostream& out, SparseMatrix<TValue>& sparse_matrix); // 运算符<<
template<typename TValue> istream& operator>> (istream& in, SparseMatrix<TValue>& sparse_matrix);  // 运算符>>


/*!
 * @brief **稀疏矩阵模板类**
 */
template<typename TValue>
class SparseMatrix {
public:

  // 构造函数(参数为稀疏矩阵最大元素个数)
  explicit SparseMatrix(int max_size = 100);

  // 复制构造函数
  SparseMatrix(const SparseMatrix<TValue>& sparse_matrix);

  /*! @brief 析构函数 */
  virtual ~SparseMatrix() { delete[] elements_; }

  /*! @brief 获取行数 */
  int Rows() const { return this->rows_; }
  /*! @brief 设置行数 */
  void SetRows(int rows) { this->rows_ = rows; }

  /*! @brief 获取列数 */
  int Cols() const { return this->cols_; };
  /*! @brief 设置行数 */
  void SetCols(int cols) { this->cols_ = cols; };

  /*! @brief 获取元素数 */
  int Size() const { return this->size_; }
  /*! @brief 设置元素数 */
  void SetSize(int size) { this->size_ = size; }

  /*! @brief 获取最大元素数 */
  int MaxSize() const { return this->max_size_; }
  /*! @brief 设置最大元素数 */
  void SetMaxSize(int max_size) { this->max_size_ = max_size; }

  // 获取元素
  bool Element(int row, int col, TValue& value);
  // 添加(替换)元素
  bool SetElement(int row, int col, TValue value);

  // 赋值运算符重载函数
  SparseMatrix<TValue>& operator=(const SparseMatrix<TValue>& sparse_matrix);

  // 转置运算
  SparseMatrix<TValue>* Transpose();

  // 快速转置运算
  SparseMatrix<TValue>* FastTranspose();

  // 当前矩阵与sparse_matrix相加 todo: 未实现
  SparseMatrix<TValue> Add(SparseMatrix<TValue>& sparse_matrix);

  // 当前矩阵与矩阵sparse_matrix相乘 todo: 未实现
  SparseMatrix<TValue> Multiply(SparseMatrix<TValue>& sparse_matrix);

  // 打印稀疏矩阵
  friend ostream& operator<< <>(ostream& out, SparseMatrix<TValue>& sparse_matrix);
  // 输入稀疏矩阵
  friend istream& operator>> <>(istream& in, SparseMatrix<TValue>& sparse_matrix);

private:
  int rows_; //!< 行数
  int cols_; //!< 列数
  int size_; //!< 当前元素数
  int max_size_; //!< 最大元素数
  TriTuple<TValue>* elements_; //!< 元素数组
};


/*!
 * @brief 构造函数(参数为稀疏矩阵最大元素个数)
 * @tparam TData 类型模板参数
 * @param max_size 最大元素个数
 */
template<class TData>
SparseMatrix<TData>::SparseMatrix(int max_size): rows_(0), cols_(0), size_(0), max_size_(max_size) {
    if (max_size < 0) {
        throw length_error("wrong max size");
    }

    this->elements_ = new TriTuple<TData>[max_size];
    if (!this->elements_) {
        throw bad_alloc();
    }
}


/*!
 * @brief 复制构造函数
 * @tparam TData 类型模板参数
 * @param sparse_matrix 稀疏矩阵(的引用)
 */
template<class TData>
SparseMatrix<TData>::SparseMatrix(const SparseMatrix<TData>& sparse_matrix) :
  rows_(sparse_matrix.Rows()), cols_(sparse_matrix.Cols()),
  size_(sparse_matrix.Size()), max_size_(sparse_matrix.MaxSize())
{
    this->elements_ = new TriTuple<TData>[this->MaxSize()];
    if (!this->elements_) {
        throw bad_alloc();
    }

    for (int i = 0; i < this->size_; i++) {
        this->elements_[i] = sparse_matrix.elements_[i];
    }
}


/*!
 * @brief 获取数组元素
 * @tparam TValue 类型模板参数
 * @param row 行索引
 * @param col 列索引
 * @param value 值引用(用于保存结果)
 * @return 是否获取成功
 */
template<class TValue>
bool SparseMatrix<TValue>::Element(int row, int col, TValue& value) {
    for (int i = 0; i < this->Size(); i++) {
        if (this->elements_[i].row == row && this->elements_[i].col == col) {
            value = this->elements_[i].value;
            return true;
        }
    }

    return false;
}


/*!
 * **设置元素**
 * @tparam TValue 类型模板参数
 * @param row 行索引
 * @param col 列索引
 * @param value 元素值
 * @return 执行结果
 * @note
 * 设置某位置(如果该位置有元素, 则替换),
 */
template<class TValue>
bool SparseMatrix<TValue>::SetElement(int row, int col, TValue value) {

    if (row >= this->Rows() || col >= this->Cols()) {
        return false;
    }

    int pos = -1;
    for (int i = 0; i < this->Size(); i++) {
        // 如果索引i的元素的row与插入位置相同
        if (this->elements_[i].row == row) {
            // 若果索引i的元素的col大于等于插入位置
            if (this->elements_[i].col >= col) {
                pos = i;
                break;
            }
        } else if (this->elements_[i].row > row) {
            pos = i;
            break;
        }
    }

    // 此数组位置已经有值, 直接赋值
    if (pos != -1 && this->elements_[pos].row == row && this->elements_[pos].col == col) {
        this->elements_[pos].value = value;
        return true;
    }

    if (this->Size() == this->MaxSize() || this->Size() == this->Rows() * this->Cols()) { // 不能再插入
        return false;
    }

    // elements_有效位后面做扩展, 而不是在有效位中做插入
    if (pos == -1) {
        pos = this->Size();
    }

    // 先插入到最后一个位置
    this->elements_[this->size_].row =  row;
    this->elements_[this->size_].col =  col;
    this->elements_[this->size_].value = value;

    // 从后向前, 依次相邻交换, 完成插入
    for (int i = this->Size(); i > pos; i--) {
        swap(&this->elements_[i], &this->elements_[i - 1]);
    }

    this->size_++; // 插入后, 数量+1

    return true;
}


template<class TValue>
void swap(TriTuple<TValue>* a, TriTuple<TValue>* b) {
    TriTuple<TValue> tmp = *a;
    *a = *b;
    *b = tmp;
}


/*!
 * @brief 赋值运算符重载函数
 * @tparam TValue 类型模板参数
 * @param sparse_matrix 稀疏矩阵(的引用)
 * @return 当前数组本身
 */
template<class TValue>
SparseMatrix<TValue>& SparseMatrix<TValue>::operator=(const SparseMatrix<TValue>& sparse_matrix) {
    if (&sparse_matrix == this) {
        return *this;
    }

    this->SetRows(sparse_matrix.Rows());
    this->SetCols(sparse_matrix.Cols());
    this->SetSize(sparse_matrix.Size());
    this->SetMaxSize(sparse_matrix.MaxSize());

    this->elements_ = new TriTuple<TValue>[this->MaxSize()];
    if (!this->elements_) {
        throw bad_alloc();
    }

    for (int i = 0; i < this->size_; i++) {
        this->elements_[i] = sparse_matrix.elements_[i];
    }

    return *this;
}


/*!
 * @brief 打印稀疏矩阵
 * @tparam TData 类型模板参数
 * @param out 输出流(的引用)
 * @param sparse_matrix 稀疏矩阵(的引用)
 * @return 输出流(的引用)
 * 代码示例
 * ```
 * cout << sparse_matrix;
 * ```
 */
template<class TData>
ostream& operator<<(ostream& out, SparseMatrix<TData>& sparse_matrix) {
    out << "rows = " << sparse_matrix.Rows() << endl;
    out << "cols = " << sparse_matrix.Cols() << endl;
    out << "NonZero terms: " << sparse_matrix.Size() << endl;

    for (int i = 0; i < sparse_matrix.Size(); i++) {
        out << "M[" << sparse_matrix.elements_[i].row << "][" <<
          sparse_matrix.elements_[i].col << "] = " <<
          sparse_matrix.elements_[i].value << endl;
    }

    return out;
}


/*!
 * @brief 输入稀疏矩阵
 * @tparam TValue 类型模板参数
 * @param out 输入流(的引用)
 * @param sparse_matrix 稀疏矩阵(的引用)
 * @return 输入流(的引用)
 * @note
 * 代码示例
 * ```
 * cin >> sparse_matrix;
 * ```
 */
template<class TValue>
istream& operator>>(istream& in, SparseMatrix<TValue>& sparse_matrix) {
    cout << "输入rows, cols和size" << endl;

    int rows = 0;
    int cols = 0;
    int size = 0;

    in >> rows >> cols >> size;

    if (size > sparse_matrix.MaxSize()) {
        throw length_error("size wrong");
    }

    sparse_matrix.SetRows(rows);
    sparse_matrix.SetCols(cols);
    sparse_matrix.SetSize(size);

    for (int i = 0; i < sparse_matrix.Size(); i++) {
        cout << "输入第" << i << "个row, column和term的值" << endl;
        in >> sparse_matrix.elements_[i].row
          >> sparse_matrix.elements_[i].col
          >> sparse_matrix.elements_[i].value;
    }

    cout << sparse_matrix << endl;

    return in;
}


/*!
 * @brief **生成转置稀疏矩阵**
 * @tparam TData 类型模板参数
 * @return 转置矩阵的地址
 * @note
 * 生成转置稀疏矩阵
 * -------------
 * -------------
 *
 *   两个for循环 \n
 *   时间复杂度O(col^2*row)
 *
 * -------------
 * + **1 初始化稀疏矩阵**\n
 * trans_sparse_matrix分配内存并初始化\n
 * 使用原矩阵cols_设置转置矩阵rows_\n
 * 使用原矩阵rows_设置转置矩阵cols_\n
 * 使用原矩阵size_设置转置矩阵size_\n\n
 * + **2 size为0情况处理**\n
 * **if** size_为0 :\n
 * &emsp; 返回trans_sparse_matrix\n\n
 * + **3 转置**\n
 * 初始化cur_elements_index(转置矩阵elements数组遍历变量)为0\n
 * **for loop** 遍历本数组cols_(列), 作为转置数组行(row) :\n
 * &emsp; **for loop** 遍历本数组elements_ :\n
 * &emsp;&emsp; **if** elements_[i](本数组当前elements_元素)的列号 == row :\n
 * &emsp;&emsp;&emsp; trans_sparse_matrix->elements_[cur_elements_index](转置矩阵当前elements_元素)的行号 = row\n
 * &emsp;&emsp;&emsp; 转置矩阵当前elements_元素的列号 = 本矩阵当前elements_元素的行号\n
 * &emsp;&emsp;&emsp; 转置矩阵当前elements_元素的value = 本矩阵当前elements_元素的value\n
 * &emsp;&emsp;&emsp; 转置矩阵当前elements_元素指向下一个\n\n
 * + **4 退出函数**\n
 * 返回返回trans_sparse_matrix\n
 */
template<typename TData>
SparseMatrix<TData>* SparseMatrix<TData>::Transpose() {

    // ---------- 1 初始化稀疏矩阵 ----------

    // trans_sparse_matrix分配内存并初始化
    SparseMatrix<TData>* trans_sparse_matrix = new SparseMatrix<TData>(this->MaxSize());

    trans_sparse_matrix->SetRows(this->Cols());         // 使用原矩阵cols_设置转置矩阵rows_
    trans_sparse_matrix->SetCols(this->Rows());         // 使用原矩阵rows_设置转置矩阵cols_
    trans_sparse_matrix->SetSize(this->Size());         // 使用原矩阵size_设置转置矩阵size_

    // ---------- 2 size为0情况处理 ----------

    if (this->Size() == 0) {                            // if size_为0
        return trans_sparse_matrix;                     // 返回trans_sparse_matrix
    }

    // ---------- 3 转置 ----------

    int cur_elements_index = 0;                         // 初始化cur_elements_index(转置矩阵elements数组遍历变量)为0
    for (int row = 0; row < this->Cols(); row++) {      // for loop 遍历本数组cols_(列), 作为转置数组行(row)
        for (int i = 0; i < this->Size(); i++) {        // for loop 遍历本数组elements_
            if (this->elements_[i].col == row) {        // if elements_[i](本数组当前elements_元素)的列号 == row
                // trans_sparse_matrix->elements_[cur_elements_index](转置矩阵当前elements_元素)的行号 = row
                trans_sparse_matrix->elements_[cur_elements_index].row = row;

                // 转置矩阵当前elements_元素的列号 = 本矩阵当前elements_元素的行号
                trans_sparse_matrix->elements_[cur_elements_index].col = this->elements_[i].row;

                // 转置矩阵当前elements_元素的value = 本矩阵当前elements_元素的value
                trans_sparse_matrix->elements_[cur_elements_index].value = this->elements_[i].value;

                cur_elements_index++;                   // 转置矩阵当前elements_元素指向下一个
            }
        }
    }

    // ---------- 4 退出函数 ----------

    return trans_sparse_matrix;                         // 返回返回trans_sparse_matrix
}


/*!
 * @brief **生成转置矩阵(快速转置)**
 * @tparam TValue 值类型模板参数
 * @return 转置矩阵
 * @note
 * 生成转置矩阵(快速转置)
 * -------------------
 * -------------------
 *
 *  空间换时间的思想\n\n
 *
 *  **row_sizes**: 转置矩阵各行元素数量, 即 原矩阵各列元素数量\n
 *  **iterator_positions**: 执行转置时, 原矩阵各列(转置矩阵各行)的每一列(转置矩阵每一行)的任务执行数组 \n
 *
 *  \n先初始化以上两个数组 \n\n
 *  遍历sparse_matrix_array_ \n
 *  对原矩阵三元组第i个元素, 进行转置矩阵三元组对应位置的赋值 \n
 *  赋值结束后, 更新iterator_positions[this->elements_[i].col]的值(下一次转置矩阵数组执行的位置, 向后挪一位) \n
 *
 * -------------------
 * + **1 初始化辅助数组**\n
 * row_sizes(转置矩阵各行元素数量)分配内存并初始化\n
 * iterator_positions(转置矩阵各行在elements_数组的遍历位置)分配内存并初始化\n\n
 * + **2 转置矩阵分配内存**\n
 * **if** 内存分配失败 :\n
 * &emsp; 抛出bad_alloc()\n\n
 * 本矩阵的cols_, 赋值给转置矩阵的rows_\n
 * 本矩阵的rows_, 赋值给转置矩阵的cols_\n
 * 本矩阵的size_, 赋值给转置矩阵的size_\n\n
 * + **3 size为0情况处理**\n
 * **if** size_为0 :\n
 * &emsp; 返回trans_sparse_matrix\n\n
 * + **4 构造row_sizes**\n
 * **for loop** 遍历本矩阵elements_ :\n
 * &emsp; cur_row(元素对应的转置矩阵行号)取elements_[i].col\n
 * &emsp; row_sizes[cur_row]加1\n\n
 * + **5 构造iterator_positions**\n
 * \n
 * ```
 * 初始化转置数组的三元组数组elements_的分布
 *
 *
 *                 elements_[ 0 ... 第1行的首元素的位置 ... 第i行的首个元素的位置 ... ]
 *                            ^             ^                       ^
 *                            |             |                       |
 *            iterator_positions[0]   iterator_positions[1]   iterator_positions[i] ...
 *
 *
 * 核心算法:
 *
 *    iterator_positions[i] = iterator_positions[i - 1] + row_sizes[i - 1];
 *
 * 即在三元组数组elements_上, 每行首个元素所在的位置, 等于上一行首个元素的位置 + 该行的所有元素数
 *
 * ```
 * \n
 * iterator_positions[0]初始化为0\n
 * **for loop** 遍历本数组cols_(列), 作为转置数组行(row) :\n
 * &emsp; iterator_positions[row] = iterator_positions[row - 1] + row_sizes[row - 1]\n\n
 * + **6 快速转置**\n
 * **for loop** 遍历本矩阵elements_ :\n
 * &emsp; 声明row(当前元素在转置矩阵的行号), 取this->elements_[i].col\n
 * &emsp; 声明cur_elements_index(转置矩阵当前遍历元素的索引), 取iterator_positions[row]\n\n
 * &emsp; trans_sparse_matrix->elements_[cur_elements_index](转置矩阵当前遍历元素)的row(行号), 取当前矩阵元素的col(列号)\n
 * &emsp; 转置矩阵当前遍历元素的col(列号), 取当前矩阵元素的row(行号)\n
 * &emsp; 转置矩阵当前遍历元素的value, 取当前矩阵元素的value\n\n
 * &emsp; iterator_positions[row\加1\n\n
 * + **7 删除辅助数组**\n
 * 释放iterator_positions\n
 * 释放row_sizes\n\n
 * + **8 退出函数**\n
 * 返回trans_sparse_matrix\n
 */
template<typename TValue>
SparseMatrix<TValue>* SparseMatrix<TValue>::FastTranspose() {
    int* row_sizes = new int[this->Cols()];
    int* iterator_positions = new int[this->Cols()];

    SparseMatrix<TValue>* trans_sparse_matrix = new SparseMatrix<TValue>(this->MaxSize());
    if (!trans_sparse_matrix) {
        throw bad_alloc();
    }

    trans_sparse_matrix->SetRows(this->Cols());
    trans_sparse_matrix->SetCols(this->Rows());
    trans_sparse_matrix->SetSize(this->Size());

    if (this->Size() == 0) {
        return trans_sparse_matrix;
    }

    for (int i = 0; i < this->Size(); i++) {
        int cur_row = this->elements_[i].col;
        row_sizes[cur_row]++;
    }

    // 初始化转置数组的三元组数组elements_的分布
    //
    //                 elements_[ 0 ... 第1行的首元素的位置 ... 第i行的首个元素的位置 ... ]
    //                            ^             ^                       ^
    //                            |             |                       |
    //                iterator_positions[0]   iterator_positions[1]   iterator_positions[i] ...
    //
    // 核心算法:
    //    iterator_positions[i] = iterator_positions[i - 1] + row_sizes[i - 1];
    // 即在三元组数组elements_上, 每行首个元素所在的位置, 等于上一行首个元素的位置 + 该行的所有元素数
    iterator_positions[0] = 0;
    for (int row = 1; row < this->Cols(); row++) {
        iterator_positions[row] = iterator_positions[row - 1] + row_sizes[row - 1];
    }

    for (int i = 0; i < this->Size(); i++) {
        int row = this->elements_[i].col;
        int cur_elements_index = iterator_positions[row];

        trans_sparse_matrix->elements_[cur_elements_index].row = this->elements_[i].col;
        trans_sparse_matrix->elements_[cur_elements_index].col = this->elements_[i].row;
        trans_sparse_matrix->elements_[cur_elements_index].value = this->elements_[i].value;

        // iterator_positions[row]加1, 表示向后挪一位
        iterator_positions[row]++;
    }

    delete[] iterator_positions;
    delete[] row_sizes;

    return trans_sparse_matrix;
}


#endif
