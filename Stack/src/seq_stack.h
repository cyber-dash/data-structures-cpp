/*!
 * @file seq_stack.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 顺序栈头文件
 * @version 0.2.1
 * @date 2023-06-03
 */

#ifndef CYBER_DASH_SEQ_STACK_H
#define CYBER_DASH_SEQ_STACK_H


#include <iostream>
#include "stack.h"


using namespace std;


// 顺序栈模板类
template <typename TData> class SeqStack;
// 重载<<
template <typename TData> ostream& operator<<(ostream& os, const SeqStack<TData>& seq_stack);


/*!
 * @brief **顺序栈模板类**
 * @tparam TData 数据项类型模板参数
 */
template <typename TData>
class SeqStack: public Stack<TData> {

public:
    /*!
     * @brief **构造函数**
     * @param capacity 容量
     * @note
     * 构造函数
     * -------
     * -------
     *
     * -------
     * capacity_使用参数capacity, top_初始化为-1\n\n
     * mem_data_分配内存\n
     * **if** 内存分配失败 :\n
     * &emsp; 抛出bad_alloc()\n
     */
    SeqStack(int capacity = 20): capacity_(capacity), top_(-1) {
        this->mem_data_ = new TData[this->capacity_];                                       // mem_data_分配内存
        if (!this->mem_data_) {                                                             // if 内存分配失败
            throw bad_alloc();                                                              // 抛出bad_alloc()
        }
    }

    // 析构函数
    ~SeqStack();
    // 入栈
    bool Push(const TData& data);
    // 出栈(保存数据)
    bool Pop(TData& data);
    // 出栈(不保存数据)
    bool Pop();
    // 获取栈顶数据
    bool Top(TData& data) const;
    // 判断栈是否为空
    bool IsEmpty() const;
    // 判断栈是否满
    bool IsFull() const;
    // 获取栈大小
    int Length() const;
    // 清空
    void Clear();

    // 重载<<
    friend ostream& operator<< <>(ostream& os, const SeqStack<TData>& seq_stack);

private:
    TData* mem_data_;    //!< **元素数组**
    int capacity_;       //!< **容量**
    int top_;            //!< **栈顶索引**
};


/*!
 * @brief **析构函数**
 * @tparam TData 数据项类型模板参数
 * @note
 * 析构函数
 * -------
 * -------
 *
 * -------
 * 释放mem_data_
 *
 *
 * -------
 */
template <typename TData>
SeqStack<TData>::~SeqStack() {
    delete[] this->mem_data_;
}


/*!
 * @brief **入栈**
 * @tparam TData 数据项类型模板参数
 * @param data 数据项值
 * @return 执行结果
 * @note
 * 入栈
 * ---
 * ---
 *
 * ---
 * + **1 非法情况处理**\n\n
 * **if** 栈满 :\n
 * &emsp; 返回false\n\n
 * + **2 入栈操作**\n\n
 * top_加1\n
 * mem_data_[top_]的值设为data\n\n
 * + **3 退出函数**\n\n
 * 返回true\n
 *
 *
 * ---
 */
template <typename TData>
bool SeqStack<TData>::Push(const TData& data) {

    // ---------- 1 非法情况处理 ----------

    if (this->IsFull()) {                                                                   // if 栈满
        return false;                                                                       // 返回false
    }

    // ---------- 2 入栈操作 ----------

    this->top_++;                                                                           // top_加1
    this->mem_data_[this->top_] = data;                                                     // mem_data_[top_]的值设为data

    // ---------- 3 退出函数 ----------

    return true;                                                                            // 返回true
}


/*!
 * @brief **出栈(保存数据)**
 * @tparam TData 数据项类型模板参数
 * @param data 栈顶保存变量
 * @return 执行结果
 * @note
 * 出栈(保存数据)
 * ------------
 * ------------
 *
 * ------------
 * + **1 非法情况处理**\n\n
 * **if** 空栈 :\n
 * &emsp; 返回false\n\n
 * + **2 出栈处理**\n\n
 * mem_data_[top_]的值赋给参数data\n
 * top_减1\n\n
 * + **3 退出函数**\n\n
 * 返回true\n
 *
 *
 * ------------
 */
template <typename TData>
bool SeqStack<TData>::Pop(TData& data) {

    // ---------- 1 非法情况处理 ----------

    if (this->Length() == 0) {                                                              // if 空栈
        return false;                                                                       // 返回false
    }

    // ---------- 2 出栈处理 ----------

    data = this->mem_data_[this->top_];                                                     // mem_data_[top_]的值赋给参数data
    this->top_--;                                                                           // top_减1

    // ----------3 退出函数 ----------

    return true;                                                                            // 返回true
}


/*!
 * @brief **出栈(保存数据)**
 * @tparam TData 数据项类型模板参数
 * @param data 栈顶保存变量
 * @return 执行结果
 * @note
 * 出栈(保存数据)
 * ------------
 * ------------
 *
 * ------------
 * + **1 非法情况处理**\n\n
 * **if** 空栈 :\n
 * &emsp; 返回false\n\n
 * + **2 出栈处理**\n\n
 * top_减1\n\n
 * + **3 退出函数**\n\n
 * 返回true\n
 *
 *
 * ------------
 */
template <typename TData>
bool SeqStack<TData>::Pop() {
    if (this->Length() == 0) {
        return false;
    }

    this->top_--;

    return true;
}


/*!
 * @brief **取栈顶数据**
 * @tparam TData 数据项类型模板参数
 * @param data 栈顶保存变量
 * @return 执行结果
 * @note
 * 取栈顶数据
 * --------
 * --------
 *
 * --------
 * + **1 非法情况处理**\n\n
 * **if** 空栈 :\n
 * &emsp; 返回false\n\n
 * + **2 取栈顶**\n\n
 * mem_data_[top_]的值赋给参数data\n
 * + **3 退出函数**\n\n
 * 返回true\n
 *
 *
 * --------
 */
template <typename TData>
bool SeqStack<TData>::Top(TData& data) const {

    // ---------- 1 非法情况处理 ----------

    if (this->Length() == 0) {                                                              // if 空栈
        return false;                                                                       // 返回false
    }

    // ---------- 2 取栈顶 ----------

    data = this->mem_data_[this->top_];                                                     // mem_data_[top_]的值赋给参数data

    // ---------- 3 退出函数 ----------

    return true;                                                                            // 返回true
}


/*!
 * @brief **判断栈是否为空**
 * @tparam TData 数据项类型模板参数
 * @return 是否为空
 * @note
 * 判断栈是否为空
 * ------------
 * ------------
 *
 * ------------
 * 返回top_ == -1
 *
 *
 * ------------
 */
template <typename TData>
bool SeqStack<TData>::IsEmpty() const {
    return this->top_ == -1;
}


/*!
 * @brief **判断栈是否满**
 * @tparam TData 数据项类型模板参数
 * @return 是否满
 * @note
 * 判断栈是否满
 * ----------
 * ----------
 *
 * ----------
 * 返回top_ == capacity_ - 1
 *
 *
 * ----------
 */
template <typename TData>
bool SeqStack<TData>::IsFull() const {
    return this->top_ == this->capacity_ - 1;
}


/*!
 * @brief **获取栈长度**
 * @tparam TData 数据项类型模板参数
 * @return 长度
 * @note
 * 获取栈长度
 * --------
 * --------
 *
 * --------
 * 返回top_ + 1
 *
 *
 * --------
 */
template <typename TData>
int SeqStack<TData>::Length() const {
    return this->top_ + 1;
}


/*!
 * @brief **清空**
 * @tparam TData 数据项类型模板参数
 * @note
 * 清空
 * ---
 * ---
 *
 * ---
 * + **1 空栈处理**\n\n
 * **获取栈长度**\n
 * **if** 空栈 :\n
 * &emsp; 退出函数\n\n
 * + **2 循环出栈**\n\n
 * **for loop** 遍历length次 :\n
 * &emsp; 调用Pop()\n\n
 *
 *
 * ---
 */
template <typename TData>
void SeqStack<TData>::Clear() {

    // ---------- 1 空栈处理 ----------

    int length = this->Length();                                                            // 获取栈长度
    if (length == 0) {                                                                      // if 空栈
        return;                                                                             // 退出函数
    }

    // ---------- 2 循环出栈 ----------

    for (int i = 0; i < length; i++) {                                                      // for loop 遍历length次
        this->Pop();                                                                        // 调用Pop()
    }
}


/*!
 * @brief **重载<&lt;**
 * @tparam TData 数据项类型模板参数
 * @param os 输出流
 * @param seq_stack 顺序栈
 * @return 输出流
 * @note
 * 重载<<
 * ------
 * ------
 *
 * ------
 * 打印栈长度\n\n
 * **for loop** 从栈顶向下遍历 :\n
 * &emsp; 打印当前元素\n\n
 * 返回os\n
 *
 *
 * ------
 */
template<typename TData>
ostream& operator<<(ostream& os, const SeqStack<TData>& seq_stack) {

    os << "栈中元素个数: " << seq_stack.Length() << endl;                                     // 打印栈长度

    for (int i = seq_stack.top_; i >= 0; i--) {                                             // for loop 从栈顶向下遍历
        os << seq_stack.mem_data_[i] << endl;                                               // 打印当前元素
    }

    return os;                                                                              // 返回os
}


#endif // CYBER_DASH_SEQ_STACK_H
