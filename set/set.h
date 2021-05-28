//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2021/5/16.
//

#ifndef CYBER_DASH_SET_H
#define CYBER_DASH_SET_H

template <class T>
class Set
{
public:
  virtual Set() = 0;
  virtual MakeEmpty() = 0;
  virtual bool AddMember(const T x) = 0;
  virtual bool DelMember(const T x) = 0;
  virtual Set<T> IntersectWith(const Set<T> &R) = 0;
  virtual Set<T> UnionWith(const Set<T> &R) = 0;
  virtual Set<T> DifferenceFrom(const Set<T> &R) = 0;
  virtual bool Contains(const T x) = 0;
  virtual bool SubSet(const Set<T> &R) = 0;
  virtual bool Operator==(const Set<T> &R) = 0;
};

#endif // CYBER_DASH_SET_H
