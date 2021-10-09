/*!
 * @file queue.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 队列基类
 * @version 0.2.1
 * @date 2021-07-14
 *
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#ifndef CYBER_DASH_QUEUE_H
#define CYBER_DASH_QUEUE_H


template<class T>
class Queue {
public:
  virtual ~Queue() {};
   /*!
   * @brief 队列入队
   * @param data 入队节点的值
   * @return 是否获取成功
   */
  virtual bool EnQueue(const T& data) = 0;
   /*!
   * @brief 队列出队
   * @param data 出队节点的值
   * @return 是否获取成功
   */
  virtual bool DeQueue(T& data) = 0;
   /*!
   * @brief 获取头节点
   * @param data 头节点的值
   * @return 是否获取成功
   */
  virtual bool GetFront(T& data) const = 0;
   /*!
   * @brief 队列是否为空
   * @return 是否为空
   */
  virtual bool IsEmpty() const = 0;
   /*!
   * @brief 获取队列长度
   * @return 队列长度
   */
  virtual int GetSize() const = 0;
};


#endif //CYBER_DASH_QUEUE_H