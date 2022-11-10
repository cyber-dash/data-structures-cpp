﻿/*!
 * @file linear_list.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 线性表抽象模板基类
 * @version 0.2.1
 * @date 2020-06-06
 * @copyright Copyright (c) 2021
 * **CyberDash计算机考研**
 */

#ifndef CYBER_DASH_LINEAR_LIST_H
#define CYBER_DASH_LINEAR_LIST_H


 /*!
  * @brief 线性表抽象基类
  * @tparam TData 数据项类型模板参数
  */
template <typename TData>
class LinearList {
public:
	/*!
	 * @brief 获取长度
	 * @return 线性表长度
	 */
	virtual int Length() const = 0;

	/*!
	 * @brief 获取元素数据
	 * @param pos 位置
	 * @param data 数据保存变量
	 * @return 执行结果
	 */
	virtual bool GetData(int pos, TData& data) const = 0;

	/*!
	 * @brief 设置第pos个结点的数据项
	 * @param pos 第pos个
	 * @param data 数据项
	 * @return
	 */
	virtual bool SetData(int pos, const TData& data) = 0;

	/*!
	 * @brief **插入(数据)**
     * @tparam TData 数据项类型模板参数
	 * @param pos 位置
	 * @param data 数据项值
	 * @return 执行结果
	 * @note
	 * 插入(数据)
	 * ---------
	 * ---------
	 *
	 * ---------
	 */
	virtual bool Insert(int pos, const TData& data) = 0;

	/*!
	 * @brief **删除元素**
     * @tparam TData 数据项类型模板参数
	 * @param pos 位置
	 * @param data 数据保存变量
	 * @return 执行结果
	 */
	virtual bool Remove(int pos, TData& data) = 0;

	/*!
	 * @brief 判断是否为空
	 * @return 是否为空
	 */
	virtual bool IsEmpty() const = 0;

	/*!
	 * @brief 打印线性表
	 */
	virtual void Print() = 0;
};


#endif // CYBER_DASH_LINEAR_LIST_H
