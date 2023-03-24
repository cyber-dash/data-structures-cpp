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
 */
template<typename TData>
class SeqList : public LinearList<TData> {

public:
    // 默认构造函数
    SeqList() : mem_data_(NULL), size_(0), last_index_(-1) {}

    // 构造函数(参数:顺序表总长度)
    explicit SeqList(int size = 100);

    // 复制构造函数(参数:顺序表)
    SeqList(const SeqList<TData>& seq_list);

    // 析构函数
    ~SeqList() { delete[] mem_data_; }

    // 获取总长度
    int Size() const;

    // 获取当前长度
    int Length() const;

    // 搜索
    int Search(TData& data) const;

    // 获取位置pos的数据
    bool GetData(int pos, TData& data) const;

    // 设置位置pos的数据
    bool SetData(int pos, const TData& data);

    // 位置pos插入数据data
    bool Insert(int prev_pos, const TData& data);

    // 删除位置pos的数据
    bool Remove(int pos, TData& data);

    // 是否为空
    bool IsEmpty() const;

    // 是否满
    bool IsFull() const;

    // 调整顺序表的长度
    int Resize(int new_size);

    // 输入顺序表
    void Input();

    // 排序
    void Sort();

    // 打印顺序表
    void Print();

    // 赋值运算符重载函数
    SeqList<TData>& operator= (const SeqList<TData>& seq_list);

    // 我们是CyberDash
    void CyberDashShow();

private:
    TData* mem_data_; //!< 数据项数组
    int size_; //!< 顺序表总长度
    int last_index_; //!< 最后一项的数组索引
};


/*!
 * @brief **构造函数(参数size) **
 * @tparam TData 数据项类型模板参数
 * @param size 顺序表size
 */
template<class TData>
SeqList<TData>::SeqList(int size) {
    if (size < 0) {
        throw out_of_range("size < 0");
    }

    this->size_ = size;
    this->last_index_ = -1;
    this->mem_data_ = new TData[size];
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
 * ### 1. 初始化 ###
 * ### 2. mem_data_分配内存 ###
 * ### 3. mem_data_内存赋值 ###
 */
template<class TData>
SeqList<TData>::SeqList(const SeqList<TData>& seq_list) {

    // ----- 1. 初始化size_和last_index_
    this->size_ = seq_list.Size();
    this->last_index_ = seq_list.Length() - 1;

    if (this->size_ == 0) {
        return;
    }

    // ----- 2. this->mem_data_分配内存 -----
    this->mem_data_ = new TData[this->Size()];
    if (!this->mem_data_) {
        throw bad_alloc();
    }

    // ----- 3. this->mem_data_内存赋值 -----
    for (int i = 1; i <= this->last_index_ + 1; i++) {
        TData cur_data;
        seq_list.GetData(i, cur_data);

        this->mem_data_[i - 1] = cur_data;
    }
}


/*!
 * @brief **调整顺序表的长度**
 * @tparam TData 类型模板参数
 * @param new_size 新的总长度
 * @return 新的总长度
 * @note
 * **返回值说明**
 * -2: 分配内存失败
 * -1: 无效参数
 * 0: 新的总长度与原来的相同
 */
template<class TData>
int SeqList<TData>::Resize(int new_size) {

    if (new_size <= 0) {
        cerr << "无效的数组大小" << endl;
        return -1;
    }

    if (new_size == this->Size()) {
        cout << "重分配数组长度与原数组长度相同" << endl;
        return 0;
    }

    TData* new_data_array = new TData[this->Size()];
    if (new_data_array == NULL) {
        cerr << "存储分配错误" << endl;
        return -2;
    }

    TData* src_ptr = mem_data_;
    TData* dest_ptr = new_data_array;

    for (int i = 0; i < this->Length(); i++) {
        *(dest_ptr + i) = *(src_ptr + i);
    }

    delete[] mem_data_;
    mem_data_ = new_data_array;

    size_ = new_size;

    return new_size;
}


/*!
 * @brief 查找数据
 * @tparam TData 类型模板参数
 * @param data 数据
 * @return 在顺序表中的位置
 */
template<class TData>
int SeqList<TData>::Search(TData& data) const {

    int pos = 0; // 从1开始, 返回0表示没有查到

    for (int i = 0; i <= last_index_; i++) {
        if (mem_data_[i] == data) {
            pos = i + 1;
            break;
        }
    }

    return pos;
}


/*!
 * @brief 获取位置pos的数据
 * @tparam TData 类型模板参数
 * @param pos 位置pos
 * @param data 数据(用于保存数据项)
 * @return 执行结果
 */
template<class TData>
bool SeqList<TData>::GetData(int pos, TData& data) const {
    if (pos <= 0 || pos > last_index_ + 1) {
        return false;
    }

    data = mem_data_[pos - 1];

    return true;
}


/*!
 * @brief 设置位置pos的数据
 * @tparam TData 类型模板参数
 * @param pos 位置pos
 * @param data 数据
 * @return 是否设置成功
 */
template<typename TData>
bool SeqList<TData>::SetData(int pos, const TData& data) {
    if (pos <= 0 || pos > last_index_ + 1) {
        return false;
    }

    mem_data_[pos - 1] = data;

    return true;
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
 * + **1 非法情况判断**\n
 * **if** last_index_等于size_ - 1 :\n
 * &emsp; 返回false\n
 * **if** prev_pos < 0 或者 prev_pos > last_index_ + 1 :\n
 * &emsp; 返回false\n
 * + **2 插入**\n
 * **for loop** 遍历mem_data_数组索引, 从last_index_到prev_pos :\n
 * &emsp; mem_data_[i + 1]等于mem_data_[i](前一位置元素)\n
 * 参数data赋值给mem_data_[prev_pos]\n
 * last_index_加1\n
 * + **3 退出函数**\n
 * 返回true\n
 */
template<class TData>
bool SeqList<TData>::Insert(int prev_pos, const TData& data) {

    if (last_index_ == size_ - 1) {
        return false;
    }

    if (prev_pos < 0 || prev_pos > last_index_ + 1) {
        return false;
    }

    for (int i = last_index_; i >= prev_pos; i--) {
        mem_data_[i + 1] = mem_data_[i];
    }

    mem_data_[prev_pos] = data;

    last_index_++;

    return true;
}


/*!
 * @brief **删除结点**
 * @tparam TData 数据项类型模板参数
 * @param pos 位置
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
 * **if** deletion_pos < 1 或者 deletion_pos > Length() :\n
 * &emsp; 返回false\n
 * + **2 保存被删除元素的数据项**\n
 * mem_data_[deletion_pos - 1]赋给参数data\n
 * + **3 删除**\n
 * **for loop** 遍历mem_data_索引deletion_pos到last_index_ :\n
 * &emsp; mem_data_[i - 1] <--- mem_data_[i]\n
 * last_index_减1\n
 * + **4 退出函数**\n
 * 返回true\n
 */
template<typename TData>
bool SeqList<TData>::Remove(int deletion_pos, TData& data) {

    if (last_index_ == -1) {
        return false;
    }

    if (deletion_pos < 1 || deletion_pos > this->Length()) {
        return false;
    }

    data = mem_data_[deletion_pos - 1];

    for (int i = deletion_pos; i <= last_index_; i++) {
        mem_data_[i - 1] = mem_data_[i];
    }

    last_index_--;

    return true;
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
 */
template<typename TData>
bool SeqList<TData>::IsEmpty() const {
    if (last_index_ == -1) {
        return true;
    }

    return false;
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
 */
template<class TData>
bool SeqList<TData>::IsFull() const {
    if (last_index_ == size_ - 1) {
        return true;
    }

    return false;
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
 * + **2 复制**\n
 * size_复制\n
 * 变量length, 取seq_list.Length()\n
 * **for loop** 遍历seq_list :\n
 * &emsp; 取seq_list当前元素数据项, 赋给curData\n
 * &emsp; curData赋给this的当前位置元素\n
 * + **3 退出函数**\n
 * 返回*this\n
 */
template<class TData>
SeqList<TData>& SeqList<TData>::operator=(const SeqList<TData>& seq_list) {

    if (&seq_list == this) {
        return *this;
    }

    this->size_ = seq_list.Size();
    int length = seq_list.Length();

    for (int i = 0; i < length; i++) {
        int curData;
        seq_list.GetData(i, curData);

        this->SetData(i, curData);
    }

    return *this;
}


/*!
 * @brief 获取总长度
 * @tparam TData 类型模板参数
 * @return 总长度
 */
template<class TData>
int SeqList<TData>::Size() const {
    return size_;
}


/*!
 * @brief 获取当前长度
 * @tparam TData 类型模板参数
 * @return 当前长度
 */
template<class TData>
int SeqList<TData>::Length() const {
    return last_index_ + 1;
}


/*!
 * @brief 打印顺序表
 * @tparam TData 类型模板参数
 */
template<class TData>
void SeqList<TData>::Print() {

    if (last_index_ == -1) {
        cout << "顺序表为空表" << endl;
        return;
    }

    for (int i = 0; i <= last_index_; i++) {
        cout << "#" << i + 1 << ":" << mem_data_[i] << endl;
    }
}


/*!
 * @brief 排序
 * @tparam TData 类型模板参数
 */
template<class TData>
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
