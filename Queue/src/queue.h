/*!
 * @file queue.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 队列虚基类
 * @version 0.2.1
 * @date 2021-07-14
 */

#ifndef CYBER_DASH_QUEUE_H
#define CYBER_DASH_QUEUE_H


 /*!
  * @brief 队列虚基类
  * @tparam TData 类型模板参数
  */
template<class TData>
class Queue {
public:
	/*!
	* @brief 入队
	* @param data 入队节点的值
	* @return 是否获取成功
	*/
	virtual bool EnQueue(const TData& data) = 0;

	/*!
	* @brief 出队
	* @param data 出队节点的值
	* @return 是否获取成功
	*/
	virtual bool DeQueue(TData& data) = 0;

	/*!
	* @brief 获取队头数据
	* @param data 头节点的值
	* @return 是否获取成功
	*/
	virtual bool Front(TData& data) const = 0;

	/*!
	* @brief 队列是否为空
	* @return 是否为空
	*/
	virtual bool IsEmpty() const = 0;

	/*!
	* @brief 获取队列长度
	* @return 队列长度
	*/
	virtual int Length() const = 0;
};


#endif //CYBER_DASH_QUEUE_H
