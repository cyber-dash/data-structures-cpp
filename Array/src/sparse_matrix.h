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
    int row;         //!< **行索引**
    int col;         //!< **列索引**
    TValue value;    //!< **值**

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
     *
     *
     * -----
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
  explicit SparseMatrix(int capacity = 100);

  // 复制构造函数
  SparseMatrix(const SparseMatrix<TValue>& sparse_matrix);

  /*! @brief **析构函数** */
  virtual ~SparseMatrix() { delete[] elements_; }

  /*! @brief **获取行数** */
  int Rows() const { return this->rows_; }
  /*! @brief **设置行数** */
  void SetRows(int rows) { this->rows_ = rows; }

  /*! @brief **获取列数** */
  int Cols() const { return this->cols_; };
  /*! @brief **设置行数** */
  void SetCols(int cols) { this->cols_ = cols; };

  /*! @brief **获取元素数** */
  int Size() const { return this->size_; }
  /*! @brief **设置元素数** */
  void SetSize(int size) { this->size_ = size; }

  /*! @brief **获取容量** */
  int Capacity() const { return this->capacity_; }
  /*! @brief **设置最大元素数** */
  void SetCapacity(int capacity) { this->capacity_ = capacity; }

  // 获取元素
  bool Element(int row, int col, TValue& value);
  // 添加(替换)元素
  bool SetElement(int row, int col, TValue value);

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
  int rows_;                     //!< **行数**
  int cols_;                     //!< **列数**
  int size_;                     //!< **当前元素数**
  int capacity_;                 //!< **最大元素数**
  TriTuple<TValue>* elements_;   //!< **元素数组**
};


/*!
 * @brief **构造函数(最大元素数)**
 * @tparam TData 值类型模板参数
 * @param capacity 最大元素个数
 * @note
 * 构造函数(最大元素数)
 * -----------------
 * -----------------
 *
 * -----------------
 * **if** 最大元素数 <= 0 :\n
 * &emsp; 抛出length_error()异常\n\n
 * elements_分配内存并初始化\n
 * **if** 内存分配失败 :\n
 * &emsp; 抛出bad_alloc()异常\n
 *
 *
 * -----------------
 */
template<typename TData>
SparseMatrix<TData>::SparseMatrix(int capacity): rows_(0), cols_(0), size_(0), capacity_(capacity) {

    if (capacity <= 0) {                                                                    // if 最大元素数 <= 0
        throw length_error("wrong max size");                                               // 抛出length_error()异常
    }

    this->elements_ = new TriTuple<TData>[capacity];                                        // elements_分配内存并初始化
    if (!this->elements_) {                                                                 // if 内存分配失败
        throw bad_alloc();                                                                  // 抛出bad_alloc()异常
    }
}


/*!
 * @brief **复制构造函数**
 * @tparam TData 值类型模板参数
 * @param sparse_matrix 源稀疏矩阵
 * @note
 * 复制构造函数
 * ----------
 * ----------
 *
 * ----------
 * elements_分配内存并初始化\n
 * **if** 内存分配失败 :\n
 * &emsp; 抛出bad_alloc()\n\n
 * **for loop** 遍历非0元素个数 :\n
 * &emsp; elements_[i]赋值\n
 *
 *
 * ----------
 */
template<typename TData>
SparseMatrix<TData>::SparseMatrix(const SparseMatrix<TData>& sparse_matrix) :
  rows_(sparse_matrix.Rows()), cols_(sparse_matrix.Cols()),
  size_(sparse_matrix.Size()), capacity_(sparse_matrix.Capacity())
{
    this->elements_ = new TriTuple<TData>[this->Capacity()];                            // elements_分配内存并初始化
    if (!this->elements_) {                                                             // if 内存分配失败
        throw bad_alloc();                                                              // 抛出bad_alloc()
    }

    for (int i = 0; i < this->size_; i++) {                                             // for loop 遍历非0元素个数
        this->elements_[i] = sparse_matrix.elements_[i];                                // elements_[i]赋值
    }
}


/*!
 * @brief **获取元素**
 * @tparam TValue 值类型模板参数
 * @param row 行索引
 * @param col 列索引
 * @param value 值保存变量
 * @return 执行结果
 * @note
 * 获取元素
 * -------
 * -------
 *
 * -------
 * **for loop** 遍历elements_数组 :\n
 * &emsp; **if** 当前元素行号和列号等于参数row和col :\n
 * &emsp; 当前元素的value赋给参数value\n
 * &emsp; 返回true\n
 * 返回false\n
 *
 *
 * -------
 */
template<typename TValue>
bool SparseMatrix<TValue>::Element(int row, int col, TValue& value) {
    for (int i = 0; i < this->Size(); i++) {                                        // for loop 遍历elements_数组
        if (this->elements_[i].row == row && this->elements_[i].col == col) {       // if 当前元素行号和列号等于参数row和col
            value = this->elements_[i].value;                                       // 当前元素的value赋给参数value
            return true;                                                            // 返回true
        }
    }

    return false;                                                                   // 返回false
}


/*!
 * @brief **设置元素**
 * @tparam TValue 值类型模板参数
 * @param row 行号
 * @param col 列号
 * @param value 值
 * @return 执行结果
 * @note
 * 设置元素
 * -------
 * -------
 *
 * 设置某位置(如果该位置有元素, 则替换)
 *
 * -------
 * + **1 非法位置处理**\n\n
 * **if** row >= 当前矩阵行数 || col >= 单签矩阵列数 : \n
 * &emsp; 返回false\n\n
 * **if** 当前非0元素个数 == 容量 || 当前非0元素个数 == 行数 * 列数 :\n
 * &emsp; 返回false\n\n
 * + **2 获取该位置在elements_数组中对应的索引**\n\n
 * 初始化index(位置在elements_数组的索引)为-1\n
 * **for loop** 遍历elements_数组 :\n
 * &emsp; **if** elements_[i](当前元素)的行号 == 参数行号 :\n
 * &emsp;&emsp; **if** 当前元素的列号 >= 参数列号 :\n
 * &emsp;&emsp;&emsp; index = i\n
 * &emsp;&emsp;&emsp; 退出循环(找到索引值)\n
 * &emsp; **else if** 当前元素的行号 > 参数行号\n
 * &emsp;&emsp; index = i\n
 * &emsp;&emsp; 退出循环(找到索引值)\n\n
 * + **3 更新非0元素的情况处理**\n\n
 * **if** index != -1 && 当前elements_元素的行号列号等于参数行号列号 :\n
 * &emsp; 当前elements_元素更新value\n
 * &emsp; 返回true\n\n
 * + **4 插入新元素的情况处理**\n\n
 * **if** index为-1(elements_尾部做扩展) :\n
 * &emsp; index值改为this->Size()\n\n
 * elements[this->size]的行号更新\n
 * elements[this->size]的列号更新\n
 * elements[this->size]的值更新\n\n
 * **for loop** elements数组索引 this->Size() 到 index :\n
 * &emsp; 相邻元素交换\n\n
 * + **5 更新size**\n\n
 * size_加1\n\n
 * + **6 退出函数**\n\n
 * 返回true\n
 *
 *
 * -------
 */
template<typename TValue>
bool SparseMatrix<TValue>::SetElement(int row, int col, TValue value) {

    // ---------- 1 非法位置处理 ----------

    if (row >= this->Rows() || col >= this->Cols()) {                   // if** row >= 当前矩阵行数 || col >= 单签矩阵列数 :
        return false;                                                   // 返回false
    }

    if (this->Size() == this->Capacity() ||                             // if 当前非0元素个数 == 容量 || 当前非0元素个数 == 行数 * 列数 :
        this->Size() == this->Rows() * this->Cols())
    {
        return false;                                                   // 返回false
    }

    // ---------- 2 获取该位置在elements_数组中对应的索引 ----------

    int index = -1;                                                     // 初始化index(位置在elements_数组的索引)为-1
    for (int i = 0; i < this->Size(); i++) {                            // for loop 遍历elements_数组 :
        if (this->elements_[i].row == row) {                            // if elements_[i](当前元素)的行号 == 参数行号 :
            if (this->elements_[i].col >= col) {                        // if 当前元素的列号 >= 参数列号 :
                index = i;                                              // index = i
                break;                                                  // 退出循环(找到索引值)
            }
        } else if (this->elements_[i].row > row) {                      // else if 当前元素的行号 > 参数行号
            index = i;                                                  // index = i
            break;                                                      // 退出循环(找到索引值)
        }
    }

    // ---------- 3 更新非0元素的情况处理 ----------

    if (index != -1 &&                                                  // if index != -1 && 当前elements_元素的行号列号等于参数行号列号 :
        this->elements_[index].row == row &&
        this->elements_[index].col == col)
    {
        this->elements_[index].value = value;                           // 当前elements_元素更新value
        return true;                                                    // 返回true
    }

    // ---------- 4 插入新元素的情况处理 ----------

    if (index == -1) {                                                  // if index为-1(elements_尾部做扩展) :
        index = this->Size();                                           // index值改为this->Size()
    }

    this->elements_[this->size_].row =  row;                            // elements[this->size]的行号更新
    this->elements_[this->size_].col =  col;                            // elements[this->size]的列号更新
    this->elements_[this->size_].value = value;                         // elements[this->size]的值更新

    for (int i = this->Size(); i > index; i--) {                        // for loop elements数组索引 this->Size() 到 index :
        Swap(&this->elements_[i], &this->elements_[i - 1]);             // 相邻元素交换
    }

    // ---------- 5 更新size ----------

    this->size_++;                                                      // size_加1

    // ---------- 6 退出函数 ----------

    return true;                                                        // 返回true
}


/*!
 * @brief **交换函数**
 * @tparam TValue 值类型模板参数
 * @param a 元素a
 * @param b 元素b
 */
template<typename TValue>
void Swap(TriTuple<TValue>* a, TriTuple<TValue>* b) {
    TriTuple<TValue> tmp = *a;
    *a = *b;
    *b = tmp;
}


/*!
 * @brief **重载<<**
 * @tparam TData 值类型模板参数
 * @param out 输出流
 * @param sparse_matrix 稀疏矩阵
 * @return 输出流
 * @note
 * 重载<<
 * ------
 * ------
 *
 * 代码示例
 * ```
 * cout << sparse_matrix;
 * ```
 *
 * ------
 * + **1 打印基本项**\n\n
 * 打印行数\n
 * 打印列数\n\n
 * + **2 打印非零元素**\n\n
 * 打印非零元素个数\n\n
 * **for loop** 遍历elements_数组 :\n
 * &emsp; 打印当前非零元素的信息\n\n
 * + **3 退出函数**\n\n
 * 返回out\n
 *
 *
 * ------
 */
template<typename TData>
ostream& operator<<(ostream& out, SparseMatrix<TData>& sparse_matrix) {

    // ---------- 1 打印基本项 ----------

    out << "rows = " << sparse_matrix.Rows() << endl;                           // 打印行数
    out << "cols = " << sparse_matrix.Cols() << endl;                           // 打印列数

    // ---------- 2 打印非零元素 ----------

    out << "NonZero element count: " << sparse_matrix.Size() << endl;           // 打印非零元素个数

    for (int i = 0; i < sparse_matrix.Size(); i++) {                            // for loop 遍历elements_数组
        out << "sparse_matrix[" << sparse_matrix.elements_[i].row << "][" <<    // 打印当前非零元素的信息
          sparse_matrix.elements_[i].col << "] = " <<
          sparse_matrix.elements_[i].value << endl;
    }

    // ---------- 3 退出函数 ----------

    return out;                                                                 // 返回out
}


/*!
 * @brief **重载>>**
 * @tparam TValue 值类型模板参数
 * @param in 输入流
 * @param sparse_matrix 稀疏矩阵
 * @return 输入流
 * @note
 * 重载>>
 * -----
 * -----
 *
 * 代码示例
 * ```
 * cin >> sparse_matrix;
 * ```
 *
 * -----
 */
template<typename TValue>
istream& operator>>(istream& in, SparseMatrix<TValue>& sparse_matrix) {
    cout << "输入rows, cols和size" << endl;

    int rows = 0;
    int cols = 0;
    int size = 0;

    in >> rows >> cols >> size;

    if (size > sparse_matrix.Capacity()) {
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
 * &emsp;&emsp;&emsp; 设置转置矩阵当前elements_元素的行号\n
 * &emsp;&emsp;&emsp; 设置转置矩阵当前elements_元素的列号\n
 * &emsp;&emsp;&emsp; 设置转置矩阵当前elements_元素的value\n
 * &emsp;&emsp;&emsp; 转置矩阵当前elements_元素指向下一个\n\n
 * + **4 退出函数**\n
 * 返回返回trans_sparse_matrix\n
 *
 *
 * -------------------
 */
template<typename TData>
SparseMatrix<TData>* SparseMatrix<TData>::Transpose() {

    // ---------- 1 初始化稀疏矩阵 ----------

    SparseMatrix<TData>* trans_sparse_matrix = new SparseMatrix<TData>(this->Capacity());               // trans_sparse_matrix分配内存并初始化

    trans_sparse_matrix->SetRows(this->Cols());                                                         // 使用原矩阵cols_设置转置矩阵rows_
    trans_sparse_matrix->SetCols(this->Rows());                                                         // 使用原矩阵rows_设置转置矩阵cols_
    trans_sparse_matrix->SetSize(this->Size());                                                         // 使用原矩阵size_设置转置矩阵size_

    // ---------- 2 size为0情况处理 ----------

    if (this->Size() == 0) {                                                                            // if size_为0
        return trans_sparse_matrix;                                                                     // 返回trans_sparse_matrix
    }

    // ---------- 3 转置 ----------

    int cur_elements_index = 0;                                                                         // 初始化cur_elements_index(转置矩阵elements数组遍历变量)为0
    for (int row = 0; row < this->Cols(); row++) {                                                      // for loop 遍历本数组cols_(列), 作为转置数组行(row)
        for (int i = 0; i < this->Size(); i++) {                                                        // for loop 遍历本数组elements_
            if (this->elements_[i].col == row) {                                                        // if elements_[i](本数组当前elements_元素)的列号 == row
                trans_sparse_matrix->elements_[cur_elements_index].row = row;                           // 设置转置矩阵当前elements_元素的行号
                trans_sparse_matrix->elements_[cur_elements_index].col = this->elements_[i].row;        // 设置转置矩阵当前elements_元素的列号
                trans_sparse_matrix->elements_[cur_elements_index].value = this->elements_[i].value;    // 设置转置矩阵当前elements_元素的value

                cur_elements_index++;                                                                   // 转置矩阵当前elements_元素指向下一个
            }
        }
    }

    // ---------- 4 退出函数 ----------

    return trans_sparse_matrix;                                                                         // 返回trans_sparse_matrix
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
 * 空间换时间的思想\n\n
 *
 * **row_sizes**: 转置矩阵各行元素数量, 即 原矩阵各列元素数量\n
 * **iterator_positions**: 执行转置时, 原矩阵各列(转置矩阵各行)的每一列(转置矩阵每一行)的任务执行数组\n
 * \n
 * <span style="color:#D40000;font-size:larger">
 * iterator_positions[i] = iterator_positions[i - 1] + row_sizes[i - 1]\n
 * </span>
 *
 * -------------------
 *
 * + **1 初始化辅助数组**\n\n
 * row_sizes(转置矩阵各行元素数量)分配内存并初始化\n
 * iterator_positions(转置矩阵各行在elements_数组的遍历位置)分配内存并初始化\n\n
 * + **2 转置矩阵分配内存**\n\n
 * **if** 内存分配失败 :\n
 * &emsp; 抛出bad_alloc()\n\n
 * 本矩阵的cols_, 赋值给转置矩阵的rows_\n
 * 本矩阵的rows_, 赋值给转置矩阵的cols_\n
 * 本矩阵的size_, 赋值给转置矩阵的size_\n\n
 * + **3 size为0情况处理**\n\n
 * **if** size_为0 :\n
 * &emsp; 返回trans_sparse_matrix\n\n
 * + **4 构造row_sizes**\n\n
 * **for loop** 遍历原矩阵列 (对应转置矩阵行) :\n
 * &emsp; row_sizes[i] (转置矩阵当前行元素个数) 设为0\n\n
 * **for loop** 遍历本矩阵elements_ :\n
 * &emsp; cur_row(元素对应的转置矩阵行号)取elements_[i].col\n
 * &emsp; row_sizes[cur_row]加1\n\n
 * + **5 构造iterator_positions**\n\n
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
 * + **6 快速转置**\n\n
 * **for loop** 遍历本矩阵elements_ :\n
 * &emsp; 声明row(当前元素在转置矩阵的行号), 取this->elements_[i].col\n
 * &emsp; 声明cur_elements_index(转置矩阵当前遍历元素的索引), 取iterator_positions[row]\n\n
 * &emsp; 设置转置矩阵当前elements_元素的行号\n
 * &emsp; 设置转置矩阵当前elements_元素的列号\n
 * &emsp; 设置转置矩阵当前elements_元素的value\n\n
 * &emsp; iterator_positions[row]加1(表示向后挪1位)\n\n
 * + **7 删除辅助数组**\n\n
 * 释放iterator_positions\n
 * 释放row_sizes\n\n
 * + **8 退出函数**\n\n
 * 返回trans_sparse_matrix\n
 *
 *
 * -------------------
 */
template<typename TValue>
SparseMatrix<TValue>* SparseMatrix<TValue>::FastTranspose() {

    // ---------- 1 初始化辅助数组 ----------

    int* row_sizes = new int[this->Cols()];                                                     // row_sizes(转置矩阵各行元素数量)分配内存并初始化
    int* iterator_positions = new int[this->Cols()];                                            // iterator_positions(转置矩阵各行在elements_数组的遍历位置)分配内存并初始化

    // ---------- 2 转置矩阵分配内存 ----------

    SparseMatrix<TValue>* trans_sparse_matrix = new SparseMatrix<TValue>(this->Capacity());
    if (!trans_sparse_matrix) {                                                                 // if 内存分配失败
        throw bad_alloc();                                                                      // 抛出bad_alloc()
    }

    trans_sparse_matrix->SetRows(this->Cols());                                                 // 本矩阵的cols_, 赋值给转置矩阵的rows_
    trans_sparse_matrix->SetCols(this->Rows());                                                 // 本矩阵的rows_, 赋值给转置矩阵的cols_
    trans_sparse_matrix->SetSize(this->Size());                                                 // 本矩阵的size_, 赋值给转置矩阵的size_

    // ---------- 3 size为0情况处理 ----------

    if (this->Size() == 0) {                                                                    // if size_为0
        return trans_sparse_matrix;                                                             // 返回trans_sparse_matrix
    }

    // ---------- 4 构造row_sizes ----------

    for (int i = 0; i < this->Cols(); i++) {                                                    // for loop 遍历原矩阵列 (对应转置矩阵行)
        row_sizes[i] = 0;                                                                       // row_sizes[i] (转置矩阵当前行元素个数) 设为0
    }

    for (int i = 0; i < this->Size(); i++) {                                                    // for loop 遍历本矩阵elements_
        int cur_row = this->elements_[i].col;                                                   // cur_row(元素对应的转置矩阵行号)取elements_[i].col
        row_sizes[cur_row]++;                                                                   // row_sizes[cur_row]加1
    }

    // ---------- 5 构造iterator_positions ----------

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

    iterator_positions[0] = 0;                                                                  // iterator_positions[0]初始化为0
    for (int row = 1; row < this->Cols(); row++) {                                              // for loop 遍历本数组cols_(列), 作为转置数组行(row)
        iterator_positions[row] = iterator_positions[row - 1] + row_sizes[row - 1];             // 构造iterator_positions[row]
    }

    // ----------6 快速转置 ----------

    for (int i = 0; i < this->Size(); i++) {                                                    // for loop 遍历本矩阵elements_
        int row = this->elements_[i].col;                                                       // row(当前元素在转置矩阵的行号), 取this->elements_[i].col
        int cur_elements_index = iterator_positions[row];                                       // cur_elements_index(转置矩阵当前遍历元素的索引), 取iterator_positions[row]

        trans_sparse_matrix->elements_[cur_elements_index].row = this->elements_[i].col;        // 设置转置矩阵当前elements_元素的行号
        trans_sparse_matrix->elements_[cur_elements_index].col = this->elements_[i].row;        // 设置转置矩阵当前elements_元素的列号
        trans_sparse_matrix->elements_[cur_elements_index].value = this->elements_[i].value;    // 设置转置矩阵当前elements_元素的value

        iterator_positions[row]++;                                                              // iterator_positions[row]加1(表示向后挪1位)
    }

    // ---------- 7 删除辅助数组 ----------

    delete[] iterator_positions;                                                                // 释放iterator_positions
    delete[] row_sizes;                                                                         // 释放row_sizes

    // ---------- 8 退出函数 ----------

    return trans_sparse_matrix;                                                                 // 返回trans_sparse_matrix
}


#endif
