/*!
 * @file seq_list.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 顺序表模板类
 * @version 0.2.1
 * @date 2021-09-28
 * @copyright Copyright (c) 2021
 * **CyberDash计算机考研**
 */

#ifndef CYBER_DASH_SEQ_LIST_H
#define CYBER_DASH_SEQ_LIST_H


#include <iostream>
#include <cstdlib>
#include <exception>
#include "linear_list.h"


using namespace std;


/*!
 * @brief 顺序表模板类
 * @tparam TData 类型模板参数
 */
template<class TData>
class SeqList : public LinearList<TData> {

public:
    // 构造函数(无参数)
    SeqList() : mem_data_(NULL), size_(0), last_index_(-1) {}

    // 构造函数(参数:顺序表总长度)
    explicit SeqList(int size = 100);

    // 复制构造函数(参数:顺序表)
    SeqList(SeqList<TData>& seq_list);

    // 析构函数
    ~SeqList() { delete[] mem_data_; }

    // 获取总长度
    int Size() const;

    // 获取当前长度
    int Length() const;

    // 搜索
    int Search(TData& data) const;

    // 定位
    int Locate(int pos) const;

    // 获取位置pos的数据
    bool GetData(int pos, TData& data) const;

    // 设置位置pos的数据
    bool SetData(int pos, const TData& data);

    // 位置pos插入数据data
    bool Insert(int pos, const TData& data);

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
SeqList<TData>::SeqList(SeqList<TData>& seq_list) {

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
 * @brief 定位
 * @tparam TData 类型模板参数
 * @param pos 第pos个
 * @return 位置pos
 * @note
 * pos是以1为起始, 不同于数组以0开始
 */
template<class TData>
int SeqList<TData>::Locate(int pos) const {
    if (pos >= 1 && pos <= last_index_ + 1) {
        return pos;
    }
    else {
        return 0;
    }
};


/*!
 * @brief 获取位置pos的数据
 * @tparam TData 类型模板参数
 * @param pos 位置pos
 * @param data 数据(用于保存数据项)
 * @return 是否获取成功
 */
template<class TData>
bool SeqList<TData>::GetData(int pos, TData& data) const {
    if (pos > 0 && pos <= last_index_ + 1) {
        data = mem_data_[pos - 1];
        return true;
    }
    else {
        return false;
    }
}


/*!
 * @brief 设置位置pos的数据
 * @tparam TData 类型模板参数
 * @param pos 位置pos
 * @param data 数据
 * @return 是否设置成功
 */
template<class TData>
bool SeqList<TData>::SetData(int pos, const TData& data) {
    if (pos > 0 && pos <= last_index_ + 1) {
        mem_data_[pos - 1] = data;
        return true;
    }
    else {
        return false;
    }
}


/*!
 * @brief 在第pos个元素之后, 插入数据
 * @param pos 位置pos
 * @param data 数据项值
 * @return 是否成功
 * @note
 * 区别于数组, 以1开始\n
 * 当pos为0时, 表示插入位置1
 */
template<class TData>
bool SeqList<TData>::Insert(int pos, const TData& data) {

    if (last_index_ == size_ - 1) {
        return false;
    }

    if (pos < 0 || pos > last_index_ + 1) {
        return false;
    }

    for (int i = last_index_; i >= pos; i--) {
        mem_data_[i + 1] = mem_data_[i];
    }

    mem_data_[pos] = data;

    last_index_++;

    return true;
}


/*!
 * @brief 删除位置pos的数据
 * @tparam TData 类型模板参数
 * @param pos 位置pos
 * @param remove_data 被删除的数据项
 * @return 是否删除成功
 */
template<class TData>
bool SeqList<TData>::Remove(int pos, TData& remove_data) {

    if (last_index_ == -1) {
        return false;
    }

    if (pos < 1 || pos > last_index_ + 1) {
        return false;
    }

    remove_data = mem_data_[pos - 1];

    for (int i = pos; i <= last_index_; i++) {
        mem_data_[i - 1] = mem_data_[i];
    }

    last_index_--;

    return true;
}


/*!
 * @brief 是否为空表
 * @tparam TData 类型模板参数
 * @return 是否为空
 */
template<class TData>
bool SeqList<TData>::IsEmpty() const {
    if (last_index_ == -1) {
        return true;
    }
    else {
        return false;
    }
}


/*!
 * @brief 顺序表是否满
 * @tparam TData 类型模板参数
 * @return 是否满
 */
template<class TData>
bool SeqList<TData>::IsFull() const {
    if (last_index_ == size_ - 1) {
        return true;
    }
    else {
        return false;
    }
}


/*!
 * @brief 赋值运算符重载函数
 * @tparam TData 类型模板参数
 * @param seq_list 顺序表
 * @return 顺序表引用
 */
template<class TData>
SeqList<TData>& SeqList<TData>::operator=(const SeqList<TData>& seq_list) {

    this->size_ = seq_list.Size();
    int p_length = seq_list.Length();

    for (int i = 0; i < p_length; i++) {
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
        cout << "顺序表为空表:" << endl;
    }
    else {
        for (int i = 0; i <= last_index_; i++) {
            cout << "#" << i + 1 << ":" << mem_data_[i] << endl;
        }
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
