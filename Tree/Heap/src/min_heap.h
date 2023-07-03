/*!
 * @file min_heap.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 小顶堆
 * @version 0.2.1
 * @date 2021-07-14
 */

#ifndef CYBER_DASH_MIN_HEAP_H
#define CYBER_DASH_MIN_HEAP_H

#include <iostream>
#include <cstdlib>


using namespace std;


#define DEFAULT_CAPACITY    200


/*!
 * @brief **最小堆模板类**
 * @tparam TElement 数据项类型模板参数
 */
template<typename TElement>
class MinHeap {
public:
  explicit MinHeap(int capacity = DEFAULT_CAPACITY);
  MinHeap(TElement* elements, int length, int capacity);
  ~MinHeap() { delete[] elements_; }

  // 插入
  bool Insert(const TElement& element);
  // 堆顶出堆
  bool Pop(TElement& element);
  // 获取堆顶
  bool Top(TElement& element);

  /*!
   * @brief **是否空堆**
   * @return 结果
   * @note
   * 是否空
   * -----
   * -----
   *
   * -----
   * 返回size_ == 0
   *
   *
   * -----
   */
  bool IsEmpty() const { return size_ == 0; }

  /*!
   * @brief **是否满堆**
   * @return 结果
   * @note
   * 是否满堆
   * -------
   * -------
   *
   * -------
   * 返回size_ == capacity_
   *
   *
   * -------
   */
  bool IsFull() const { return size_ == capacity_; }

  /*!
   * @brief **获取堆大小**
   * @return 堆大小
   * @note
   * 获取堆大小
   * --------
   * --------
   *
   * --------
   * 返回size_
   *
   *
   * --------
   */
  int Size() { return size_; }

  /*!
   * @brief **清空堆**
   * @note
   * 清空堆
   * -----
   * -----
   *
   * -----
   * size_调整为0
   *
   *
   * -----
   */
  void Clear() { size_ = 0; }

private:
  TElement* elements_;    //!< **堆元素数组**
  int size_;    //!< **当前堆size**
  int capacity_;     //!< **容量**
  void SiftDown_(int index);
  void SiftUp_(int index);
  void Swap_(TElement& element1, TElement& element2);
};


/*!
 * @brief **构造函数(容量)**
 * @tparam TElement 元素类型模板参数
 * @param capacity 容量
 * @note
 * 构造函数(容量)
 * ------------
 * ------------
 *
 * ------------
 * 设置capacity_(容量)\n\n
 * 设置size_(当前堆大小)为0\n\n
 * elements_分配内存\n
 * **if** 内存分配失败 :\n
 * &emsp; 抛出bad_alloc()错误\n
 *
 *
 * ------------
 */
template <typename TElement>
MinHeap<TElement>::MinHeap(int capacity) {
    capacity_ = (capacity > DEFAULT_CAPACITY) ? capacity : DEFAULT_CAPACITY;                // 设置capacity_(容量)
    size_ = 0;                                                                              // 设置size_(当前堆大小)为0
    elements_ = new TElement[capacity_];                                                    // elements_分配内存
    if (elements_ == NULL) {                                                                // if 内存分配失败
        throw bad_alloc();                                                                  // 抛出bad_alloc()错误
    }
}


/*!
 * @brief **构造函数(元素数组, 数组长度, 容量)**
 * @tparam TElement 元素类型模板参数
 * @param elements 元素数组首地址
 * @param length 元素数组长度
 * @param capacity 容量
 * @note
 * 构造函数(元素数组, 数组长度, 容量)
 * ------------------------------
 * ------------------------------
 *
 * ------------------------------
 * + **1 初始化**\n\n
 * 设置capacity_<span style="color:#283593;font-weight:bold">(容量)</span>\n
 * 设置size_<span style="color:#283593;font-weight:bold">(当前堆大小)</span>为length\n\n
 * elements_分配内存\n
 * **if** 内存分配失败 :\n
 * &emsp; 抛出bad_alloc()错误\n\n
 * **for loop** 遍历capacity :\n
 * &emsp; elements_[i]赋值\n\n
 * + **2 建堆**\n\n
 * **for loop** 从索引(size_ - 2) / 2 到 0 :\n
 * &emsp; 对i<span style="color:#283593;font-weight:bold">(当前索引)</span>执行SiftDown_;\n
 *
 *
 * ------------------------------
 */
template <typename TElement>
MinHeap<TElement>::MinHeap(TElement* elements, int length, int capacity) {

    // ---------- 1 初始化 ----------

    capacity_ = (capacity > DEFAULT_CAPACITY) ? capacity : DEFAULT_CAPACITY;                // 设置capacity_(容量)
    size_ = length;                                                                              // 设置size_(当前堆大小)为0

    elements_ = new TElement[capacity_];                                                    // elements_分配内存
    if (elements_ == NULL) {                                                                // if 内存分配失败
        throw bad_alloc();                                                                  // 抛出bad_alloc()错误
    }

    for (int i = 0; i < capacity; i++) {                                                    // for loop 遍历capacity
        elements_[i] = elements[i];                                                         // elements_[i]赋值
    }

    // ----------- 2 建堆 ----------

    for (int i = (size_ - 2) / 2; i >= 0; i--) {                                            // for loop 从索引(size_ - 2) / 2 到 0
        SiftDown_(i);                                                                       // 对i(当前索引)执行SiftDown_
    }
}


/*!
 * @brief **向下调整**
 * @tparam TElement 元素类型模板参数
 * @param index 索引
 * @note
 * 向下调整
 * -------
 * -------
 *
 * -------
 * **for loop** 遍历索引index的后代结点 :\n\n
 * &emsp; **if** child_index(当前左孩子结点索引) + 1 < 堆大小 && 左孩子节点元素 > 右孩子结点元素 :\n
 * &emsp;&emsp; child_index调整为右孩子结点索引(自加1), 此时child_index元素为孩子结点中最小孩子元素\n\n
 * &emsp; **if** index(当前结点索引)元素 <= 最小孩子元素 :\n
 * &emsp;&emsp; 跳出循环\n\n
 * &emsp; 交换(当前结点, 最小孩子结点)\n
 *
 *
 * -------
 */
template <typename TElement>
void MinHeap<TElement>::SiftDown_(int index) {
    for (int child_index = 2 * index + 1; child_index < size_; index = child_index, child_index = child_index * 2 + 1) {    // for loop 遍历索引index的后代结点
        if (child_index + 1 < size_ && elements_[child_index] > elements_[child_index + 1]) {                               // if 当前左孩子结点索引 + 1 < 堆大小 && 左孩子节点元素 > 右孩子结点元素
            child_index++;                                                                                                  // child_index调整为右孩子结点索引(自加1)( 此时child_index元素为孩子结点中最小孩子元素)
        }

        if (elements_[index] <= elements_[child_index]) {                                                                   // if index(当前结点索引)元素 <= 最小孩子元素
          break;                                                                                                            // 跳出循环
        }

        Swap_(elements_[index], elements_[child_index]);                                                                    // 交换(当前结点, 最小孩子结点)
    }
}


/*!
 * @brief **向上调整**
 * @tparam TElement 元素类型模板参数
 * @param index 索引
 * @note
 * 向上调整
 * -------
 * -------
 *
 * -------
 * **for loop** 遍历索引index的祖先结点 :\n\n
 * &emsp; **if** 当前父节点元素 <= 当前结点元素 :\n
 * &emsp;&emsp; 退出循环\n\n
 * &emsp; 交换(当前父节点, 当前结点)\n
 *
 *
 * -------
 */
template <typename TElement>
void MinHeap<TElement>::SiftUp_(int index) {
    for (int parent_index = (index - 1) / 2; parent_index >= 0; index = parent_index, parent_index = (index - 1) / 2) { // for loop 遍历索引index的祖先结点
        if (elements_[parent_index] <= elements_[index]) {                                                              // if 当前父节点元素 <= 当前结点元素
            break;                                                                                                      // 退出循环
        }

        Swap_(elements_[parent_index], elements_[index]);                                                               // 交换(当前父节点, 当前结点)
    }
}


/*!
 * @brief **交换**
 * @tparam TElement 元素类型模板参数
 * @param element1 元素1
 * @param element2 元素2
 * @note
 * 交换
 * ---
 * ---
 *
 * ---
 * 常规交换操作
 *
 *
 * ---
 */
template <typename TElement>
void MinHeap<TElement>::Swap_(TElement& element1, TElement& element2) {
  TElement tmp = element1;
  element1 = element2;
  element2 = tmp;
}


/*!
 * @brief **插入**
 * @tparam TElement 元素类型模板参数
 * @param element 元素
 * @return 执行结果
 * @note
 * 插入
 * ---
 * ---
 *
 * ---
 * + **1 合法性判断**\n\n
 * **if** 堆满 :\n
 * &emsp; 返回false(无法插入)\n\n
 * + **2 数组末尾插入元素**\n\n
 * elements_[size_]元素赋值element\n\n
 * + **3 调整堆**\n\n
 * 对索引size_位置元素(即element_[size_])执行SiftUp_\n
 * 堆size加1\n\n
 * + **4 退出函数**\n\n
 * 返回true\n
 *
 *
 * ---
 */
template <typename TElement>
bool MinHeap<TElement>::Insert(const TElement& element) {
    // ---------- 1 合法性判断 ----------

    if (size_ == capacity_) {                                                               // if 堆满
        return false;                                                                       //  返回false(无法插入)
    }

    // ---------- 2 数组末尾插入元素 ----------

    elements_[size_] = element;                                                             // elements_[size_]元素赋值element

    // ---------- 3 调整堆 ----------

    SiftUp_(size_);                                                                         // 对索引size_位置元素(即element_[size_])执行SiftUp_
    size_++;                                                                                // 堆size加1

    // ---------- 4 退出函数 ----------

    return true;                                                                            // 返回true
}


/*!
 * @brief **堆顶出堆**
 * @tparam TElement 元素类型模板参数
 * @param element 堆顶元素保存变量
 * @return 执行结果
 * @note
 * 堆顶出堆
 * -------
 * -------
 *
 * -------
 * + **1 合法性判断**\n
 * **if** 空堆 :\n
 * &emsp; 返回false\n
 * + **2 保存堆顶**\n
 * element保存堆顶值\n
 * + **3 替换堆顶**\n
 * elements_[size_ - 1](最后一个元素)替换elements_[0]\n
 * 堆size_减1\n
 * + **4 调整堆**\n
 * 对堆顶执行SiftDown_\n
 * + **5 退出函数**\n\n
 * 返回true\n
 *
 *
 * -------
 */
template <typename TElement>
bool MinHeap<TElement>::Pop(TElement& element) {
    // ---------- 1 合法性判断 ----------

    if (!size_) {                                                   // if 空堆
        return false;                                               //  返回false
    }

    // ---------- 2 保存堆顶 ----------

    element = elements_[0];                                         // element保存堆顶值

    // ---------- 3 替换堆顶 ----------

    elements_[0] = elements_[size_ - 1];                            // elements_[size_ - 1](最后一个元素)替换elements_[0]
    size_--;                                                        // 堆size_减1

    // ---------- 4 调整堆 ----------

    SiftDown_(0);                                                   // 对堆顶执行SiftDown_

    // ---------- 5 退出函数 ----------

    return true;                                                    // 返回true
}


/*!
 * @brief **获取堆顶**
 * @tparam TElement 元素类型模板参数
 * @param element 堆顶保存元素
 * @return 执行结果
 * @note
 * 获取堆顶
 * -------
 * -------
 *
 * -------
 * + **1 合法性判断**\n\n
 * **if** 空堆 :\n
 * &emsp; 返回false\n\n
 * + **2 堆顶赋值**\n\n
 * element保存堆顶值\n\n
 * + **3 退出函数**\n\n
 * 返回true\n
 *
 *
 * -------
 */
template <typename TElement>
bool MinHeap<TElement>::Top(TElement& element) {
    // ---------- 1 合法性判断 ----------

    if (!size_) {                                                   // if 空堆
        return false;                                               // 返回false
    }

    // ---------- 2 堆顶赋值 ----------

    element = elements_[0];                                         // element保存堆顶值

    // ---------- 3 退出函数 ----------

    return true;                                                    // 返回true
}


#endif // CYBER_DASH_MIN_HEAP_H
