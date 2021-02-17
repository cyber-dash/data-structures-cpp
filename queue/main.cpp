//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/7/28.
//

#include <iostream>
#include "link_queue.h"
#include "link_queue.cpp"


using namespace std;


int main() {

  LinkQueue<int> test_queue;

  // test EnQueue
  test_queue.EnQueue(1);
  test_queue.EnQueue(2);
  test_queue.EnQueue(3);
  test_queue.EnQueue(4);

  // test operator<<
  cout<<test_queue<<endl;

  // test DeQueue
  int curFrontData;
  test_queue.DeQueue(curFrontData);
  cout<<"Get DeQueue data: "<<curFrontData<<endl;
  cout<<test_queue<<endl;

  // test GetFront
  test_queue.GetFront(curFrontData);
  cout<<"Get DeQueue data: "<<curFrontData<<endl;
  cout<<test_queue<<endl;

  // test IsEmpty
  cout<<"IsEmpty: "<<test_queue.IsEmpty()<<endl<<endl;

  // test GetSize
  cout<<"The size is "<<test_queue.GetSize()<<endl;

  test_queue.CyberDashShow();

  return 0;
}