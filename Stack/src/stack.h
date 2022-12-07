/*!
 * @file stack.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 栈纯抽象模板类
 * @version 0.2.1
 * @date 2020-07-28
 */


#ifndef CYBER_DASH_STACK_H
#define CYBER_DASH_STACK_H


/*!
 * @brief **栈纯虚模板类**
 * @tparam TData 类型模板参数
 * @note
 * 栈纯虚模板类
 * ----------
 * ----------
 *
 * ----------
 */
template<typename TData>
class Stack {
public:
	/*!
	 * @brief **入栈(纯虚函数)**
	 * @param data 数据项
	 * @return 执行结果
	 * @note
	 * 入栈(纯虚函数)
	 * -------------
	 * -------------
	 *
	 * -------------
	 */
	virtual bool Push(const TData& data) = 0;

	/*!
	 * @brief **出栈(纯虚函数)**
	 * @param data 数据项保存变量
	 * @return 执行结果
	 * @note
	 * 出栈(纯虚函数)
	 * -------------
	 * -------------
	 *
	 * -------------
	 */
	virtual bool Pop(TData& data) = 0;

	/*!
	 * @brief **获取栈顶数据(纯虚函数)**
	 * @param data 数据项保存变量
	 * @return 执行结果
	 * @note
	 * 获取栈顶数据(纯虚函数)
	 * -------------
	 * -------------
	 *
	 * -------------
	 */
	virtual bool Top(TData& data) const = 0;

	/*!
	 * @brief **判断是否为空(纯虚函数)**
	 * @return 结果
	 * @note
	 * 判断是否为空(纯虚函数)
	 * -------------
	 * -------------
	 *
	 * -------------
	 */
	virtual bool IsEmpty() const = 0;

	/*!
	 * @brief **获取长度(纯虚函数)**
	 * @return 长度
	 * @note
	 * 获取长度(纯虚函数)
	 * -------------
	 * -------------
	 *
	 * -------------
	 */
	virtual int Length() const = 0;
};


#endif //CYBER_DASH_STACK_H
