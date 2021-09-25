//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/7/28.
//

#ifndef CYBER_DASH_STACK_H
#define CYBER_DASH_STACK_H


template<class T>
class Stack {
public:
  Stack() {};
  virtual ~Stack() {};
  virtual void Push(const T& data) = 0;
  virtual bool Pop(T& x) = 0;
  virtual bool GetTop(T& data) const = 0;
  virtual bool IsEmpty() const = 0;
  // virtual bool IsFull() const = 0;
  virtual int GetSize() const = 0;
};


#endif //CYBER_DASH_STACK_H
