/*!
 * @file queue.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 队列纯抽象模板类
 * @version 0.2.1
 * @date 2021-07-14
 */

#ifndef CYBER_DASH_QUEUE_H
#define CYBER_DASH_QUEUE_H


 /*!
  * @brief **队列纯抽象模板类**
  * @tparam TData 数据项类型模板参数
  * @note
  * 队列纯抽象模板类
  * --------------
  * --------------
  *
  * --------------
  */
template<class TData>
class Queue {
public:
	/*!
	 * @brief **入队(纯虚函数)**
	 * @param data 数据项
	 * @return 执行结果
	 * @note
	 * 入队(纯虚函数)
	 * ---------
	 * ---------
	 *
	 * 入队(纯虚函数)
	 *
	 * ---------
	 */
	virtual bool EnQueue(const TData& data) = 0;

	/*!
	 * @brief **出队(纯虚函数)**
	 * @param data 数据项保存变量
	 * @return 执行结果
	 * @note
	 * 出队(纯虚函数)
	 * ---------
	 * ---------
	 *
	 * 出队(纯虚函数)
	 *
	 * ---------
	 */
	virtual bool DeQueue(TData& data) = 0;

	/*!
	 * @brief **获取队头数据(纯虚函数)**
	 * @param data 数据项保存变量
	 * @return 执行结果
	 * @note
	 * 获取队头数据(纯虚函数)
	 * ---------
	 * ---------
	 *
	 * 获取队头数据(纯虚函数)
	 *
	 * ---------
	 */
	virtual bool Front(TData& data) const = 0;

	/*!
	 * @brief **队列是否为空(纯虚函数)**
	 * @return 结果
	 * @note
	 * 队列是否为空(纯虚函数)
	 * ---------
	 * ---------
	 *
	 * 队列是否为空(纯虚函数)
	 *
	 * ---------
	 */
	virtual bool IsEmpty() const = 0;

	/*!
	 * @brief **队列长度(纯虚函数)**
	 * @return 长度
	 * @note
	 * 队列长度(纯虚函数)
	 * ---------
	 * ---------
	 *
	 * 队列长度(纯虚函数)
	 *
	 * ---------
	 */
	virtual int Length() const = 0;
};


#endif //CYBER_DASH_QUEUE_H
