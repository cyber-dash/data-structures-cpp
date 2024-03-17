/*!
 * @file seq_list.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 顺序表模板类
 * @version 0.2.1
 * @date 2021-09-28
 */

#ifndef CYBER_DASH_SEQ_LIST_H
#define CYBER_DASH_SEQ_LIST_H


#include <iostream>
#include <cstdlib>
#include <exception>
#include "linear_list.h"


using namespace std;


/*!
 * @brief **顺序表模板类**
 * @tparam TData 数据项类型模板参数
 * @note
 * 顺序表模板类
 * ----------
 * ----------
 *
 * 使用数组mem_data_实现各函数
 *
 * ----------
 */
template<typename TData>
class SeqList: public LinearList<TData> {

public:
    /*!
     * @brief **默认构造函数**
     */
    SeqList(): mem_data_(NULL), capacity_(0), last_index_(-1) {}

    // 构造函数(容量)
    explicit SeqList(int capacity = 100);

    // 复制构造函数
    SeqList(const SeqList<TData>& seq_list);

    // 析构函数
    ~SeqList() { delete[] mem_data_; }

    /*!
     * @brief **获取容量**
     * @return 容量
     */
    int Capacity() const { return capacity_; }

    // 获取当前长度
    int Length() const { return last_index_ + 1; }

    // 搜索
    int Search(const TData& data) const;

    // 获取结点数据
    bool GetData(int pos, TData& data) const;

    // 设置结点数据
    bool SetData(int pos, const TData& data);

    // 插入结点
    bool Insert(int prev_pos, const TData& data);

    // 删除结点
    bool Remove(int target_pos, TData& data);

    // 是否为空
    bool IsEmpty() const;

    // 是否满
    bool IsFull() const;

    // 重制容量
    bool ResetCapacity(int capacity);

    // 排序
    void Sort();

    // 打印顺序表
    void Print();

    // 赋值运算符重载函数
    SeqList<TData>& operator= (const SeqList<TData>& seq_list);

    // 我们是CyberDash
    void CyberDashShow();

private:
    TData* mem_data_;        //!< **数据项数组**
    int capacity_;           //!< **容量**
    int last_index_;         //!< **最后一项的数组索引**
};


/*!
 * @brief **构造函数(容量) **
 * @tparam TData 数据项类型模板参数
 * @param capacity 顺序表size
 */
template<class TData>
SeqList<TData>::SeqList(int capacity) : capacity_(capacity), last_index_(-1) {
    if (capacity < 0) {
        throw out_of_range("capacity < 0");
    }

    this->mem_data_ = new TData[capacity];
    if (!this->mem_data_) {
        throw bad_alloc();
    }
}


/*!
 * @brief **复制构造函数**
 * @tparam TData 数据项类型模板参数
 * @param seq_list 顺序表
 * @note
 * 复制构造函数
 * ----------
 * ----------
 *
 * ----------
 * + **1 初始化**
 * capacity_初始化为seq_list的容量\n
 * last_index_初始化为seq_list.Length() - 1\n
 * **if** 容量为0 :\n
 * &emsp; 退出函数\n\n
 * + **2 mem_data_分配内存**
 * mem_data_分配内存并初始化\n
 * **if** 内存分配失败 :\n
 * &emsp; 抛出bad_alloc()\n\n
 * + **3 mem_data_内存赋值**
 * **for loop** 位置1到seq_list.Length() :\n
 * &emsp; 声明变量cur_data\n
 * seq_list位置pos的变量赋给cur_data\n\n
 * cur_data赋给this->mem_data_[pos - 1]\n
 *
 *
 * ----------
 */
template<typename TData>
SeqList<TData>::SeqList(const SeqList<TData>& seq_list) {

    // ---------- 1 初始化 ----------

    this->capacity_ = seq_list.Capacity();                  // capacity_初始化为seq_list的容量
    this->last_index_ = seq_list.Length() - 1;              // last_index_初始化为seq_list.Length() - 1

    if (this->capacity_ == 0) {                             // if 容量为0
        return;                                             // 退出函数
    }

    // ---------- 2 mem_data_分配内存 ----------

    this->mem_data_ = new TData[this->Capacity()];          // mem_data_分配内存并初始化
    if (!this->mem_data_) {                                 // if 内存分配失败
        throw bad_alloc();                                  // 抛出bad_alloc()
    }

    // ---------- 3 mem_data_内存赋值 ----------

    for (int pos = 1; pos <= seq_list.Length(); pos++) {    // for loop 位置1到seq_list.Length()
        TData cur_data;                                     // 声明变量cur_data
        seq_list.GetData(pos, cur_data);                    // seq_list位置pos的变量赋给cur_data

        this->mem_data_[pos - 1] = cur_data;                // cur_data赋给this->mem_data_[pos - 1]
    }
}


/*!
 * @brief **重制容量**
 * @tparam TData 数据项类型模板参数
 * @param capacity 新的容量
 * @return 容量
 * @note
 * 重制容量
 * -------
 * -------
 *
 * -------
 * + **1 非法容量处理**\n
 * **if** 新容量 < 原有容量 :\n
 * &emsp; 返回-1\n\n
 * + **2 分配新内存**\n
 * new_mem_data分配内存并初始化\n
 * **if** 内存分配失败 :\n
 * &emsp; 抛出bad_alloc()\n\n
 * + **3 将已有的数据赋值到新内存**\n
 * **for loop** 遍历原数据 :\n
 * &emsp; mem_data[i]赋给new_mem_data[i]\n\n
 * + **4 释放旧内存使用新内存**\n
 * 释放mem_data_\n
 * mem_data_指向new_mem_data\n\n
 * + **5 容量调整**\n
 * capacity_调整\n
 * + **6 退出函数**\n
 * 返回true\n
 *
 *
 * -------
 */
template<typename TData>
bool SeqList<TData>::ResetCapacity(int capacity) {

    // ----------- 1 非法容量处理 -----------

    if (capacity < Length()) {                              // if 新容量 < 原有容量
        return false;                                       // 返回-1
    }

    // ----------- 2 分配新内存 -----------

    TData* new_mem_data = new TData[capacity];              // new_mem_data分配内存并初始化
    if (new_mem_data == NULL) {                             // if 内存分配失败
        throw bad_alloc();                                  // 抛出bad_alloc()
    }

    // ----------- 3 将已有的数据赋值到新内存 -----------

    for (int i = 0; i < this->Length(); i++) {              // for loop 遍历原数据
        new_mem_data[i] = mem_data_[i];                     // mem_data[i]赋给new_mem_data[i]
    }

    // ----------- 4 释放旧内存使用新内存 -----------

    delete[] this->mem_data_;                                     // 释放mem_data_
    this->mem_data_ = new_mem_data;                               // mem_data_指向new_mem_data

    // ----------- 5 容量调整 -----------

    capacity_ = capacity;                                   // capacity_调整

    // ----------- 6 退出函数 -----------

    return true;                                            // 返回true
}


/*!
 * @brief **搜索**
 * @tparam TData 数据项类型模板参数
 * @param data 待搜索数据项
 * @return 位置
 * 搜索
 * ---
 * ---
 *
 * ---
 * **for loop** 遍历mem_data_ :\n
 * &emsp; **if** 当前元素等于参数data :\n
 * &emsp;&emsp; 返回i + 1\n
 * 返回0\n
 *
 *
 * ---
 */
template<typename TData>
int SeqList<TData>::Search(const TData& data) const {

    for (int i = 0; i <= last_index_; i++) {                // for loop 遍历mem_data_
        if (mem_data_[i] == data) {                         // if 当前元素等于参数data
            return i + 1;                                   // 返回i + 1
        }
    }

    return 0;                                               // 返回0
}


/*!
 * @brief **获取结点数据**
 * @tparam TData 数据项类型模板参数
 * @param pos 位置
 * @param data 数据项保存变量
 * @return 执行结果
 * @note
 * 获取结点数据
 * ----------
 * ----------
 *
 * ----------
 * + **1 非法位置判断**\n
 * **if** pos <= 0 <b>||</b> pos > last_index_ + 1 :\n
 * &emsp; 返回false\n\n
 * + **2 赋值**\n
 * mem_data_[pos - 1]赋给data\n\n
 * + **3 退出函数**\n
 * 返回true\n
 *
 *
 * ----------
 */
template<typename TData>
bool SeqList<TData>::GetData(int pos, TData& data) const {

    // ---------- 1 非法位置判断 ----------

    if (pos <= 0 || pos > last_index_ + 1) {                    // if pos <= 0 || pos > last_index_ + 1
        return false;                                           // 返回false
    }

    // ---------- 2 赋值 ----------

    data = mem_data_[pos - 1];                                  // mem_data_[pos - 1]赋给data

    // ---------- 3 退出函数 ----------

    return true;                                                // 返回true
}


/*!
 * @brief **设置结点数据**
 * @tparam TData 数据项类型模板参数
 * @param pos 位置
 * @param data 数据项
 * @return 执行结果
 * @note
 * 设置结点数据
 * ----------
 * ----------
 *
 * ----------
 * + **1 非法位置判断**\n
 * **if** pos <= 0 <b>||</b> pos > last_index_ + 1 :\n
 * &emsp; 返回false\n\n
 * + **2 赋值**\n
 * data赋给mem_data_[pos - 1]\n\n
 * + **3 退出函数**\n
 * 返回true\n
 *
 *
 * ----------
 */
template<typename TData>
bool SeqList<TData>::SetData(int pos, const TData& data) {

    // ---------- 1 非法位置判断 ----------

    if (pos <= 0 || pos > last_index_ + 1) {                    // if pos <= 0 <b>||</b> pos > last_index_ + 1
        return false;                                           // 返回false
    }

    // ---------- 2 赋值 ----------

    mem_data_[pos - 1] = data;                                  // data赋给mem_data_[pos - 1]

    // ---------- 3 退出函数 ----------

    return true;                                                // 返回true
}


/*!
 * @brief **插入结点**
 * @param prev_pos 插入位置的前一位置
 * @param data 数据项值
 * @return 执行结果
 * @note
 * 插入结点
 * -------
 * -------
 *
 * 区别于数组, 以1开始\n
 * 当pos为0时, 表示插入位置1
 *
 * -------
 * + **1 非法情况判断**\n\n
 * **if** last_index_等于size_ - 1 :\n
 * &emsp; 返回false\n
 * **if** prev_pos < 0 或者 prev_pos > last_index_ + 1 :\n
 * &emsp; 返回false\n\n
 * + **2 插入**\n\n
 * **for loop** 遍历mem_data_数组索引, 从last_index_到prev_pos :\n
 * &emsp; mem_data_[i + 1]等于mem_data_[i](前一位置元素)\n
 * 参数data赋值给mem_data_[prev_pos]\n
 * last_index_加1\n\n
 * + **3 退出函数**\n\n
 * 返回true\n
 *
 *
 * -------
 */
template<typename TData>
bool SeqList<TData>::Insert(int prev_pos, const TData& data) {

    // ---------- 1 非法情况判断 ----------

    if (last_index_ == capacity_ - 1) {                                 // if last_index_等于size_ - 1
        return false;                                                   // 返回false
    }

    if (prev_pos < 0 || prev_pos > last_index_ + 1) {                   // if prev_pos < 0 或者 prev_pos > last_index_ + 1
        return false;                                                   // 返回false
    }

    // ---------- 2 插入 ----------

    for (int i = last_index_; i >= prev_pos; i--) {                     // for loop 遍历mem_data_数组索引, 从last_index_到prev_pos
        mem_data_[i + 1] = mem_data_[i];                                // mem_data_[i + 1]等于mem_data_[i](前一位置元素)
    }

    mem_data_[prev_pos] = data;                                         // 参数data赋值给mem_data_[prev_pos]

    last_index_++;                                                      // last_index_加1

    // ---------- 3 退出函数 ----------

    return true;                                                        // 返回true
}


/*!
 * @brief **删除结点**
 * @tparam TData 数据项类型模板参数
 * @param target_pos 位置
 * @param data 数据项保存变量
 * @return 执行结果
 * @note
 * 删除结点
 * ------
 * ------
 *
 * ------
 * + **1 非法情况判断**\n
 * **if** last_index_等于-1 :\n
 * &emsp; 返回false\n
 * **if** target_pos < 1 或者 target_pos > Length() :\n
 * &emsp; 返回false\n
 * + **2 保存被删除元素的数据项**\n
 * mem_data_[target_pos - 1]赋给参数data\n
 * + **3 删除**\n
 * **for loop** 遍历mem_data_索引target_pos到last_index_ :\n
 * &emsp; mem_data_[i - 1] <--- mem_data_[i]\n
 * last_index_减1\n
 * + **4 退出函数**\n
 * 返回true\n
 *
 *
 * ------
 */
template<typename TData>
bool SeqList<TData>::Remove(int target_pos, TData& data) {

    // ---------- 1 非法情况判断 ----------

    if (last_index_ == -1) {                                            // if last_index_等于-1
        return false;                                                   // 返回false
    }

    if (target_pos < 1 || target_pos > this->Length()) {                // if target_pos < 1 或者 target_pos > Length()
        return false;                                                   // 返回false
    }

    // ---------- 2 保存被删除元素的数据项 ----------

    data = mem_data_[target_pos - 1];                                   // mem_data_[target_pos - 1]赋给参数data

    // ---------- 3 删除 ----------

    for (int i = target_pos; i <= last_index_; i++) {                   // for loop 遍历mem_data_索引target_pos到last_index_
        mem_data_[i - 1] = mem_data_[i];                                // mem_data_[i - 1] <--- mem_data_[i]
    }

    last_index_--;                                                      // last_index_减1

    // ---------- 4 退出函数 ----------

    return true;                                                        // 返回true
}


/*!
 * @brief **判断是否为空表**
 * @tparam TData 数据项类型模板参数
 * @return 是否为空表
 * @note
 * 判断是否为空表
 * -------------
 * -------------
 * 
 * -------------
 * **if** last_index_为-1 :\n
 * &emsp; 返回true\n
 * 返回false\n
 *
 *
 * -------------
 */
template<typename TData>
bool SeqList<TData>::IsEmpty() const {
    if (last_index_ == -1) {                                            // if last_index_为-1
        return true;                                                    // 返回true
    }

    return false;                                                       // 返回false
}


/*!
 * @brief **判断是否满表**
 * @tparam TData 数据项类型模板参数
 * @return 是否满表
 * @note
 * 判断是否满表
 * -----------
 * -----------
 * 
 * -----------
 * **if** last_index_为size_ - 1 :\n
 * &emsp; 返回true\n
 * 返回false\n
 *
 *
 * -----------
 */
template<typename TData>
bool SeqList<TData>::IsFull() const {
    if (last_index_ == capacity_ - 1) {                                 // if last_index_为size_ - 1
        return true;                                                    // 返回true
    }

    return false;                                                       // 返回false
}


/*!
 * @brief **重载=**
 * @tparam TData 数据项类型模板参数
 * @param seq_list 顺序表
 * @return 顺序表引用
 * @note
 * 重载=
 * ----
 * ----
 * 
 * ----
 * + **1 自身赋值处理**\n
 * **if** 自身赋值 :\n
 * &emsp; 返回*this\n\n
 * + **2 内存重新分配**\n
 * 使用seq_list的容量重新分配内存\n\n
 * + **3 复制**\n
 * size_复制\n
 * 变量length, 取seq_list.Length()\n
 * **for loop** 遍历seq_list :\n
 * &emsp; 取seq_list当前元素数据项, 赋给curData\n
 * &emsp; curData赋给this的当前位置元素\n\n
 * + **4 退出函数**\n
 * 返回*this\n
 *
 *
 * ----
 */
template<typename TData>
SeqList<TData>& SeqList<TData>::operator=(const SeqList<TData>& seq_list) {

    // ---------- 1 自身赋值处理 ----------

    if (&seq_list == this) {                                            // if 自身赋值
        return *this;                                                   // 返回*this
    }

    // ---------- 2 内存重新分配 ----------

    bool res = this->ResetCapacity(seq_list.Capacity());                // 使用seq_list的容量重新分配内存
    if (!res) {
        throw length_error("seq_list length wrong");
    }

    // ---------- 3 复制 ----------

    int length = seq_list.Length();                                     // 变量length, 取seq_list.Length()

    for (int i = 1; i <= length; i++) {                                 // for loop 遍历seq_list
        TData cur_data;
        seq_list.GetData(i, cur_data);                                  // 取seq_list当前元素数据项, 赋给cur_data

        this->mem_data_[i - 1] = cur_data;                              // data赋给mem_data_[pos - 1]

        this->last_index_++;                                            // last_index_调整
    }

    // ---------- 4 退出函数 ----------

    return *this;                                                       // 返回*this
}


/*!
 * @brief **打印**
 * @tparam TData 数据项类型模板参数
 * @note
 * 打印
 * ---
 * ---
 *
 * ---
 * + **1 空表处理**\n
 * **if** 空表 :\n
 * &emsp; 打印"顺序表为空表"\n
 * &emsp; 推出函数\n\n
 * + **2 按顺序打印**\n
 * **for loop** 遍历mem_data_的数据项部分 :\n
 * &emsp; 打印当前元素\n
 *
 *
 * ---
 */
template<typename TData>
void SeqList<TData>::Print() {

    // ---------- 1 空表处理 ----------

    if (last_index_ == -1) {                                    // if 空表
        cout << "顺序表为空表" << endl;                           // 打印"顺序表为空表"
        return;                                                 // 退出函数
    }

    // ---------- 2 按顺序打印 ----------

    for (int i = 0; i <= last_index_; i++) {                    // for loop 遍历mem_data_的数据项部分
        cout << "位置(非数组索引)" << i + 1 << ": " << mem_data_[i] << endl;    // 打印当前元素
    }
}


/*!
 * @brief **排序**
 * @tparam TData 数据项类型模板参数
 * @note
 * 排序
 * ---
 * ---
 *
 * <span style="color:#FF8100">
 * 冒泡排序
 * </span>
 *
 * ---
 */
template<typename TData>
void SeqList<TData>::Sort() {

    int length = this->Length();
    for (int i = 1; i < length; i++) {
        for (int j = 1; j <= length - i; j++) {

            TData j_data;
            this->GetData(j, j_data);

            TData j_next_data;
            this->GetData(j + 1, j_next_data);

            if (j_data > j_next_data) {
                this->SetData(j, j_next_data);
                this->SetData(j + 1, j_data);
            }
        }
    }
}


#endif // CYBER_DASH_SEQ_LIST_H
