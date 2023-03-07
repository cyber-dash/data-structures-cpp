/*!
 * @file static_linked_list.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 静态链表模板类
 * @version 0.2.1
 * @date 2022-11-18
 */

#ifndef CYBER_DASH_STATIC_LINKED_LIST_H
#define CYBER_DASH_STATIC_LINKED_LIST_H


#include <iostream>


using namespace std;


/*!
 * @brief **静态链表结点模板结构体
 * @note
 * 静态链表结点模板结构体
 * --------------------
 * --------------------
 * 
 * <span style="color:#FF8100">
 * 注意:\n
 *     当next值为HEAD(0)时, 表示该数组元素是链表最后一个结点\n
 *     当next值为NONE(-1)时, 表示该数组元素未使用\n
 * 
 * 这个设定节省内存, 但如果不清楚则会困惑\n
 * </span>
 * 
 * --------------------
 */
template <typename TData>
struct StaticLinkedListNode {
    /*!
     * @brief **默认构造函数**
     */
    StaticLinkedListNode<TData>() : next(0) {}
    explicit StaticLinkedListNode<TData>(TData data) : data(data), next(-1) {}
    StaticLinkedListNode<TData>(TData data, int next) : data(data), next(next) {}

    TData data;    //!< 数据项
    int next;      //!< 下一结点的索引
};


/*!
 * @brief **静态链表模板类**
 * @note
 * 静态链表模板类
 * ------------
 * ------------
 *
 * ------------
 */
template <typename TData>
class StaticLinkedList {
public:
    explicit StaticLinkedList(int capacity = 100);

    int Length() const { return length_; }

    int Capacity() const { return capacity_; }

    bool IsEmpty() const { return length_ == 0; }

    bool Search(const TData& data, int& pos) const;

    bool Insert(int pos, const TData& data);

    bool Remove(int pos, TData& data);

    void Print() const;

    StaticLinkedListNode<TData>& operator[] (size_t index);

    static const int NONE = -1;
    static const int HEAD = 0;

private:
    bool GetInsertionIndex_(int& index) const;
    bool Extend_(int increased_capacity);
    bool GetIndexByPos_(int pos, int& index) const;

    StaticLinkedListNode<TData>* mem_data_;    //!< 静态链表, mem_data_[0]为头结点(不保存元素)
    int length_;                               //!< 静态链表长度
    int capacity_;                             //!< 静态链表容量
};


/*!
 * @brief **构造函数(容量)**
 * @tparam TData 数据项类型模板参数
 * @param capacity 容量
 * @note
 * 构造函数(容量)
 * ------------
 * ------------
 *
 * ------------
 * + **1 初始化成员变量**\n
 * capacity_(容量)使用参数进行初始化\n
 * length_(当前长度)初始化为0\n
 * \n
 * mem_data_分配内存并初始化, capacity_ + 1个元素, 首元素为头结点\n
 * **if** mem_data_内存分配失败 :\n
 * &emsp; 抛出bad_alloc()异常\n
 * \n
 * + **2 初始化结点**\n
 * HEAD结点的next指向HEAD<b>(0, 自身)</b>\n
 * **for loop** 数组索引从1到capacity :\n
 * &emsp; 当前数组元素的next值为NONE<b>(-1, 表示该数组元素不在静态链表中使用)</b>\n
 */
template <typename TData>
StaticLinkedList<TData>::StaticLinkedList(int capacity) {

    // ---------- 1 初始化成员变量 ----------

    capacity_ = capacity;                                       // capacity_(容量)使用参数进行初始化
    length_ = 0;                                                // length_(当前长度)初始化为0

    mem_data_ = new StaticLinkedListNode<TData>[capacity_ + 1]; // mem_data_分配内存并初始化, capacity_ + 1个元素, 首元素为头结点
    if (!mem_data_) {                                           // if mem_data_内存分配失败
        throw bad_alloc();                                      // 抛出bad_alloc()异常
    }

    // ---------- 2 初始化结点 ----------

    mem_data_[HEAD].next = HEAD;                                // HEAD结点的next指向HEAD(0, 自身)

    for (int i = 1; i <= capacity; i++) {                       // for loop 数组索引从1到capacity
        // 当前数组元素的next值为NONE(-1, 表示该数组元素不在静态链表中使用)
        mem_data_[i].next = StaticLinkedList<TData>::NONE;
    }
}


/*!
 * @brief **根据pos获取结点的数组索引**
 * @tparam TData 数据项类型模板参数
 * @param pos 位置
 * @param index 数组索引保存变量
 * @return 执行结果
 * @note
 * 根据pos获取结点的数组索引
 * ----------------------
 * ----------------------
 *
 * <span style="color:#FF8100">
 * pos为0时, 取静态链表head结点(数组索引0元素)\n
 * </span>
 * <span style="color:#038575">
 * (pos < 0)或者(pos > 链表长度)时, 非法位置, 返回false\n
 * </span>
 * <span style="color:#65000b">
 * pos为1时, 取链表第一个元素结点, 与数组的方式有区别\n
 * </span>
 *
 * ----------------------
 * + **1 pos非法情况处理**\n
 * **if** pos < 0 或者 pos > 静态链表长度 :\n
 * &emsp; 返回false\n
 * + **2 pos为0情况处理**\n
 * **if** pos等于0 :\n
 * &emsp; index赋值为HEAD(0)\n
 * &emsp; 返回true\n
 * + **3 遍历链表至相应位置并取索引**\n
 * 声明并初始化cur_index(遍历变量), 等于HEAD结点的next\n
 * **for loop** 从1遍历到pos - 1 :\n
 * &emsp; cur_index指向cur_index结点的next\n
 * cur_index的值赋给index\n
 * + **4 退出函数**\n
 * 返回true\n
 */
template<typename TData>
bool StaticLinkedList<TData>::GetIndexByPos_(int pos, int& index) const {

    // ---------- 1 pos非法情况处理 ----------

    if (pos < 0|| pos > this->length_) {                // if pos < 0 或者 pos > 静态链表长度
        return false;                                   // 返回false
    }

    // ---------- 2 pos为0情况处理 ----------

    if (pos == 0) {                                     // if pos等于0
        index = HEAD;                                   // index赋值为HEAD(0)
        return true;                                    // 返回true
    }

    // ---------- 3 遍历链表至相应位置并取索引 ----------

    int cur_index = this->mem_data_[HEAD].next;         // 声明并初始化cur_index(遍历变量), 等于HEAD结点的next
    for (int i = 1; i < pos; i++) {                     // for loop 从1遍历到pos - 1
        cur_index = this->mem_data_[cur_index].next;    // cur_index指向cur_index结点的next
    }

    index = cur_index;                                  // cur_index的值赋给index

    // ---------- 4 退出函数 ----------

    return true;                                        // 返回true
}


/*!
 * @brief **搜索**
 * @tparam TData 数据项类型模板参数
 * @param data 搜索数据
 * @param pos 位置
 * @return 执行结果
 * @note
 * 搜索
 * ---
 * ---
 *
 * ---
 * + **1 空链表处理**\n
 * **if** 空链表 :\n
 * &emsp; 返回false\n
 * + **2 遍历链表搜索**\n
 * **for loop** 遍历链表的每个结点 :\n
 * &emsp; **if** 当前结点的data等于参数data :\n
 * &emsp;&emsp; cur_pos(当前位置)赋给pos\n
 * &emsp;&emsp; 返回true\n
 * &emsp; cur_pos加1\n
 * + **3 返回false**\n
 */
template<typename TData>
bool StaticLinkedList<TData>::Search(const TData& data, int& pos) const {

    // ---------- 1 空链表处理 ----------

    if (length_ == 0) {                     // if 空链表
        return false;                       // 返回false
    }

    // ---------- 2 遍历链表搜索 ----------

    // for loop 遍历链表的每个结点
    for (int cur_pos = 1, i = mem_data_[HEAD].next; i != HEAD; i = mem_data_[i].next) {

        if (mem_data_[i].data == data) {    // if 当前结点的data等于参数data
            pos = cur_pos;                  // cur_pos(当前位置)赋给pos
            return true;                    // 返回true
        }

        cur_pos++;                          // cur_pos加1
    }

    // ---------- 3 返回false ----------

    return false;
}


/*!
 * @brief **插入**
 * @tparam TData 数据项类型模板参数
 * @param data 待插入数据项
 * @param pos 插入位置的前一位置
 * @return 执行结果
 * @note
 * 插入
 * ---
 * ---
 * 
 * <span style="color:#038575">
 * pos等于0为头结点, 从1开始是数据元素结点 \n
 * </span>
 * <span style="color:#FF8100">
 * 在数组pos位置的后面, 执行插入 \n
 * </span>
 * 
 * ---
 * + **1 非法位置处理**\n
 * **if** pos < 0 <b>||</b> pos大于链表长度 :\n
 * &emsp; 返回false\n
 * \n
 * + **2 扩容处理**\n
 * **if** 链表长度等于容量 :\n
 * &emsp; 扩容1倍\n
 * \n
 * + **3 获取插入位置前一位置的数组索引**\n
 * 对pos调用GetIndexByPos_, 获取prev_index<b>(插入位置前一位置的数组索引)</b>\n
 * **if** 获取失败 :\n
 * &emsp; 返回false\n
 * \n
 * + **4 获取插入位置的数组索引**\n
 * 调用GetInsertionIndex_, 获取insertion_index<b>(执行插入的索引)</b>\n
 * **if** 获取失败: \n
 * &emsp; 返回false\n
 * \n
 * + **5 执行插入**\n
 * 插入位置数组元素的next, 指向pos位置数组元素的next\n
 * pos位置数组元素的next, 指向插入位置\n
 * 插入位置的data, 等于参数data\n
 * \n
 * 链表长度+1\n
 * + **6 返回结果**\n
 * 返回true\n
 */
template <typename TData>
bool StaticLinkedList<TData>::Insert(int pos, const TData& data) {
    if (pos < 0 || pos > length_) {
        return false;
    }

    if (length_ == capacity_) {
        this->Extend_(capacity_);
    }

    int prev_index;
    bool res = GetIndexByPos_(pos, prev_index);
    if (!res) {
        return false;
    }

    int insertion_index;
    res = GetInsertionIndex_(insertion_index);
    if (!res) {
        return false;
    }

    mem_data_[insertion_index].next = mem_data_[prev_index].next;
    mem_data_[prev_index].next = insertion_index;
    mem_data_[insertion_index].data = data;

    length_++;

    return true;
}


/*!
 * @brief **删除结点**
 * @tparam TData 数据项类型模板参数
 * @param pos 删除结点位置
 * @param data 数据项保存变量
 * @return 执行结果
 * @note
 * 删除结点
 * -------
 * -------
 *
 * -------
 * + **1 非法情况处理**\n
 * **if** 空链表 :\n
 * &emsp; 返回false\n
 * **if** pos < 1 <b>||</b> pos > 链表长度 :\n
 * &emsp; 返回false\n
 * + **2 找到删除结点前一结点**\n
 * 初始化prev_index(待删除结点前一结点的数组索引)\n
 * **for loop** 从位置1遍历到位置pos - 1 :\n
 * &emsp; prev_index值改为mem_data_[prev_index].next\n
 * + **3 删除**\n
 * 初始化deletion_index(待删除结点的数组索引), 等于mem_data_[prev_index].next\n
 * 前一结点的next, 指向待删除结点的next\n
 * 待删除结点的next设置为NONE(此数组元素不再在链表中)\n
 * 被删除结点的data赋给参数data\n
 * 链表长度减1\n
 * + **4 退出函数**\n
 * 返回true\n
 */
template<typename TData>
bool StaticLinkedList<TData>::Remove(int pos, TData& data) {

    if (length_ == 0) {
        return false;
    }

    if (pos < 1 || pos > length_) {
        return false;
    }

    int prev_index = HEAD;
    for (int i = 1; i < pos; i++) {
        prev_index = mem_data_[prev_index].next;
    }

    int deletion_index = mem_data_[prev_index].next;
    mem_data_[prev_index].next = mem_data_[deletion_index].next;

    mem_data_[deletion_index].next = NONE;

    data = mem_data_[deletion_index].data;

    length_--;

    return true;
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
 * + **1 空链表处理**\n
 * + **2 循环打印数据**\n
 * **for loop** 遍历链表中的每个结点 :\n
 * &emsp; 打印当前结点的data\n
 * &emsp; **if** 不是最后一个结点 :\n
 * &emsp;&emsp; 打印"-->"(表示next指向)\n
 */
template<typename TData>
void StaticLinkedList<TData>::Print() const {
    if (length_ == 0) {
        cout << "Empty list" << endl;
    }

    for (int cur = mem_data_[HEAD].next; cur != HEAD; cur = mem_data_[cur].next) {
        cout << mem_data_[cur].data;
        if (mem_data_[cur].next != HEAD) {
            cout << "-->";
        }
    }

    cout << endl;
}


/*!
 * @brief **扩容**
 * @tparam TData 数据项类型模板参数
 * @param increased_capacity 增加的容量
 * @return 执行结果
 * @note
 * 扩容
 * ---
 * ---
 *
 * ---
 * + **1 容量数值增加**\n
 * 使用old_capacity保存旧链表的容量\n
 * capacity_增加数值\n
 * + **2 开辟新内存**\n
 * 使用新容量, 初始化并分配内存\n
 * **if** 新内存分配失败 :\n
 * &emsp; 返回false\n
 * + **3 新内存赋值**\n
 * **for loop** 遍历原链表容量内的数组元素\n
 * &emsp; new_mem_data[i] = mem_data_[i]\n
 * **for loop** 遍历新链表新增容量的数组元素\n
 * &emsp; 每个元素的next设置为NONE(-1, 不在链表中)\n
 * + **4 使用新内存并释放旧内存**\n
 * 释放旧内存\n
 * 指向新内存\n
 * + **5 退出函数**\n
 * 返回true\n
 */
template <typename TData>
bool StaticLinkedList<TData>::Extend_(int increased_capacity) {
    int old_capacity = capacity_;
    capacity_ += increased_capacity;
    StaticLinkedListNode<TData>* new_mem_data = new StaticLinkedListNode<TData>[capacity_ + 1];
    if (!new_mem_data) {
        return false;
    }

    for (int i = HEAD; i <= old_capacity; i++) {
        new_mem_data[i] = mem_data_[i];
    }

    for (int i = old_capacity + 1; i <= capacity_; i++) {
        new_mem_data[i].next = NONE;
    }

    delete[] mem_data_;
    mem_data_ = new_mem_data;

    return true;
}


/*!
 * @brief **获取插入位置的数组索引**
 * @tparam TData 数据项类型模板参数
 * @param index 索引保存变量
 * @return 执行结果
 * @note
 * 获取插入位置的数组索引
 * ------------------
 * ------------------
 *
 * ------------------
 * + **1 非法情况处理**\n
 * **if** 链表长度等于容量 :\n
 * &emsp; 返回false\n
 * + **2 查找到插入位置并赋值**\n
 * **for loop** 从位置1遍历到位置length_ + 1 :\n
 * &emsp; **if** 当前位置的next等于NONE(-1, 未被链表使用) :\n
 * &emsp;&emsp; 当前位置的索引i, 赋给参数index\n
 * &emsp;&emsp; 返回true\n
 * + **3 退出函数**\n
 * 返回false(失败情况处理)\n
 */
template <typename TData>
bool StaticLinkedList<TData>::GetInsertionIndex_(int& index) const {

    // ---------- 1 非法情况处理 ----------

    if (length_ == capacity_) {                                     // if 链表长度等于容量
        return false;                                               // 返回false
    }

    // ---------- 2 查找到插入位置并赋值 ----------

    for (int i = 1; i <= length_ + 1; i++) {                        // for loop 从位置1遍历到位置length_ + 1
        if (mem_data_[i].next == StaticLinkedList<TData>::NONE) {   // if 当前位置的next等于NONE(-1, 未被链表使用)
            index = i;                                              // 当前位置的索引i, 赋给参数index
            return true;                                            // 返回true
        }
    }

    // ---------- 3 退出函数 -----------

    return false;                                                   //返回false(失败情况处理)
}


template <typename TData>
StaticLinkedListNode<TData>& StaticLinkedList<TData>::operator[] (size_t index) {
    if ((int)index > length_) {
        throw exception("Out of Range");
    }

    return this->mem_data_[index];
}


#endif // CYBER_DASH_STATIC_LINKED_LIST_H
