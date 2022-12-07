/*!
 * @file linear_list.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 线性表纯抽象模板类
 * @version 0.2.1
 * @date 2020-06-06
 */

#ifndef CYBER_DASH_LINEAR_LIST_H
#define CYBER_DASH_LINEAR_LIST_H


/*!
 * @brief 线性表纯抽象模板类
 * @tparam TData 数据项类型模板参数
 * @note
 * 线性表纯抽象模板类
 * ----------------
 * ----------------
 *
 * ----------------
 */
template <typename TData>
class LinearList {
public:
	/*!
	 * @brief **获取长度(纯虚函数)**
	 * @return 长度
	 * @note
	 * 获取长度(纯虚函数)
	 * ----------------
	 * ----------------
	 *
	 * ----------------
	 */
	virtual int Length() const = 0;

	/*!
	 * @brief **获取某位置元素的数据项(纯虚函数)**
     * @tparam TData 数据项类型模板参数
	 * @param pos 位置
	 * @param data 数据项保存变量
	 * @return 执行结果
	 * @note
	 * 获取某位置元素的数据项(纯虚函数)
	 * ----------------
	 * ----------------
	 *
	 * 起始位置为1, 区别于数组起始位置为0
	 *
	 * ----------------
	 */
	virtual bool GetData(int pos, TData& data) const = 0;

	/*!
	 * @brief **设置某位置元素的数据项(纯虚函数)**
     * @tparam TData 数据项类型模板参数
	 * @param pos 位置
	 * @param data 数据项
	 * @return 执行结果
	 * @note
	 * 设置某位置元素的数据项(纯虚函数)
	 * ----------------
	 * ----------------
	 *
	 * 起始位置为1, 区别于数组起始位置为0
	 *
	 * ----------------
	 */
	virtual bool SetData(int pos, const TData& data) = 0;

	/*!
	 * @brief **插入(纯虚函数)**
     * @tparam TData 数据项类型模板参数
	 * @param pos 插入位置的前一位置
	 * @param data 数据项
	 * @return 执行结果
	 * @note
	 * 插入(纯虚函数)
	 * ---------
	 * ---------
	 *
	 * 在pos后插入, 插入完成后, 新元素的位置为pos + 1
	 *
	 * ---------
	 */
	virtual bool Insert(int pos, const TData& data) = 0;

	/*!
	 * @brief **删除元素(纯虚函数)**
     * @tparam TData 数据项类型模板参数
	 * @param pos 位置
	 * @param data 数据项保存变量
	 * @return 执行结果
	 * @note
	 * 删除元素(纯虚函数)
	 * ---------
	 * ---------
	 *
	 * ---------
	 */
	virtual bool Remove(int pos, TData& data) = 0;

	/*!
	 * @brief **判断是否为空(纯虚函数)**
	 * @return 结果
	 * @note
	 * 判断是否为空
	 * ---------
	 * ---------
	 *
	 * ---------
	 */
	virtual bool IsEmpty() const = 0;

	/*!
	 * @brief **打印线性表(纯虚函数)**
	 * @note
	 * 打印线性表
	 * ---------
	 * ---------
	 *
	 * ---------
	 */
	virtual void Print() = 0;
};


#endif // CYBER_DASH_LINEAR_LIST_H
