//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/7/28.
//

#ifndef CYBER_DASH_QUEUE_H
#define CYBER_DASH_QUEUE_H


template<class T>
class Queue {
public:
  virtual ~Queue() {};
  virtual bool EnQueue(const T& data) = 0;
  virtual bool DeQueue(T& data) = 0;
  virtual bool GetFront(T& data) const = 0;
  virtual bool IsEmpty() const = 0;
  virtual int GetSize() const = 0;
};


#endif //CYBER_DASH_QUEUE_H