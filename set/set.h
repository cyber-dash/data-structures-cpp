//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2021/5/16.
//

#ifndef CYBER_DASH_SET_H
#define CYBER_DASH_SET_H

template<class T>
class Set {
public:
  virtual Set() = 0;
  virtual MakeEmpty() = 0;
  virtual bool addMember(const T x)=0;
  virtual bool delMember(const T x)=0;
  virtual Set<T> intersectWith(const Set<T>& R)=0;
  virtual Set<T> unionWith(const Set<T>& R)=0;
  virtual Set<T> differenceFrom(const Set<T>& R)=0;
  virtual bool Contains(const T x)=0;
  virtual bool subSet(const Set<T>& R)=0;
  virtual bool operator == (const Set<T>& R)=0;
};

#endif // CYBER_DASH_SET_H
