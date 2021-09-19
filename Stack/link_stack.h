//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/7/28.
//

#ifndef CYBER_DASH_LINK_STACK_H
#define CYBER_DASH_LINK_STACK_H


#include "stack.h"
#include "link_node.h"
#include <iostream>

using namespace std;

template <class T>
class LinkStack: public Stack<T>{

public:
  LinkStack(): top_ptr_(NULL) {}
  ~LinkStack();
  void Push(const T& data);
  bool Pop(T& data);
  bool GetTop(T& data) const;
  bool IsEmpty() const;
  int GetSize() const;
  void MakeEmpty();

  LinkNode<T>* GetTopPtr();

  template<class U>
  friend ostream& operator<<(ostream& os, LinkStack<T>& stack);

  void CyberDashShow();

private:
  LinkNode<T>* top_ptr_;     // 元素

};


#endif //CYBER_DASH_LINK_STACK_H
