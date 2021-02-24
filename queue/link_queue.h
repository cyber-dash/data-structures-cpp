//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/7/28.
//

#ifndef CYBER_DASH_LINK_QUEUE_H
#define CYBER_DASH_LINK_QUEUE_H


#include <cstdlib>
#include "link_node.h"
#include "queue.h"
#include <iostream>


using namespace std;


template<class T>
class LinkQueue: public Queue<T> {

public:
  LinkQueue(): front_ptr_(NULL), rear_ptr_(NULL)  {}
  ~LinkQueue();
  bool EnQueue(const T& data);
  bool DeQueue(T& x);
  bool GetFront(T& data) const;
  bool IsEmpty() const;
  int GetSize() const;
  void MakeEmpty();

  LinkNode<T>* GetFrontPtr() { return front_ptr_; }
  LinkNode<T>* GetRearPtr() { return rear_ptr_; }

  template<class U>
  friend ostream& operator<<(ostream& os, LinkQueue<T>& link_queue);

  void CyberDashShow();

private:
  LinkNode<T>* front_ptr_;
  LinkNode<T>* rear_ptr_;

};


#endif //CYBER_DASH_LINK_QUEUE_H
