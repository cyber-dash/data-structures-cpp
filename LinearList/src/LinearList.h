//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/7/14.
//

#ifndef CYBER_DASH_LINEAR_LIST_H
#define CYBER_DASH_LINEAR_LIST_H


/*!
 * @brief 线性表抽象基类
 * @tparam T 类型模板参数
 */
template <class T>
class LinearList {
public:
  /*!
   * @brief 获取长度
   * @return 线性表长度
   */
  virtual int Length() const = 0;

  /*!
   * @brief 获取第pos个结点的数据项
   * @param pos 第pos个
   * @param data 数据项(用于保存结果)
   * @return 是否获取成功
   */
  virtual bool GetData(int pos, T& data) const = 0;

  /*!
   * @brief 设置第pos个结点的数据项
   * @param pos 第pos个
   * @param data 数据项
   * @return
   */
  virtual bool SetData(int pos, const T& data) const = 0;

  /*!
   * @brief 在第pos个元素之后, 插入数据
   * @param pos 位置pos
   * @param data 数据项值
   * @return 是否成功
   */
  virtual bool Insert(int pos, const T& data) = 0;

  /*!
   * @brief 删除第pos个元素
   * @param pos 位置pos
   * @param data 数据项值(保存被删除的元素数据项)
   * @return 是否成功
   */
  virtual bool Remove(int pos, T& data) = 0;

  /*!
   * @brief 判断是否为空
   * @return 是否为空
   */
  virtual bool IsEmpty() = 0;

  /*!
   * @brief 打印线性表
   */
  virtual void Output() = 0;

  virtual void CyberDashShow() = 0;

  // virtual int Locate(int pos) const = 0;
  // virtual int Search(T& data) const = 0;
  // virtual int Size() const = 0;
  // virtual bool IsFull() = 0;
  // virtual void Sort() = 0;
  // virtual void Input() = 0;
};


#endif //CYBER_DASH_LINEAR_LIST_H
