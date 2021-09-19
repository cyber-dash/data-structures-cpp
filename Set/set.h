//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2021/5/16.
//

#ifndef CYBER_DASH_SET_H
#define CYBER_DASH_SET_H


template<class T>
class Set {
public:

  // 构造函数
  virtual Set() = 0;

  // 置空集合
  virtual MakeEmpty() = 0;

  // 加入新成员
  virtual bool AddMember(T x) = 0;

  // 删除成员
  virtual bool DelMember(T x) = 0;

  // 集合的交运算
  virtual Set<T> IntersectWith(const Set<T>& set) = 0;

  // 集合的并运算
  virtual Set<T> UnionWith(const Set<T>& set) = 0;

  // 集合的差运算
  virtual Set<T> DifferenceFrom(const Set<T>& set) = 0;

  // 判断是否是集合的成员
  virtual bool Contains(T x) = 0;

  // 判断是否是集合的子集
  virtual bool SubSet(const Set<T>& set) = 0;

  // 判断集合是否相等
  virtual bool operator == (const Set<T>& set) = 0;
};


#endif // CYBER_DASH_SET_H
