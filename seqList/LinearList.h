//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/7/14.
//

#ifndef CYBER_DASH_LINEAR_LIST_H
#define CYBER_DASH_LINEAR_LIST_H


template <class T>
class LinearList {
public:
  virtual int Size() const = 0;
  virtual int Length() const = 0;
  virtual int Search(T& x) const = 0;
  virtual int Locate(int i) const = 0;
  virtual bool GetData(int i, T& data) const = 0;
  virtual bool SetData(int i, const T& data) const = 0;
  virtual bool Insert(int i, const T& data) = 0;
  virtual bool Remove(int i, T& data) = 0;
  virtual bool IsEmpty() = 0;
  virtual bool IsFull() = 0;
  virtual void Output() = 0;
  // todo:
  // virtual void Sort() = 0;
  // virtual void Input() = 0;
  // virtual LinearList<T>& operator= (const LinearList<T>& L) = 0;
};


#endif //CYBER_DASH_LINEAR_LIST_H
