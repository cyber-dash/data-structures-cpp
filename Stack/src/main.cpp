/*!
 * @file main.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 栈demo演示
 * @version 0.2.1
 * @date 2020-07-15
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#include <iostream>
#include "link_stack.h"


using namespace std;


int main() {

  LinkStack<int> test_stack;

  // 操作 int 类型的栈
  test_stack.Push(1);
  test_stack.Push(2);
  test_stack.Push(3);
  test_stack.Push(4);

  // test GetTop
  int top_data;
  test_stack.GetTop(top_data);
  cout<<"top_data: "<<top_data<<endl;

  // test operator<<
  cout<<test_stack<<endl;

  // test Pop
  int pop_data;
  test_stack.Pop(pop_data);
  test_stack.Pop(pop_data);
  test_stack.Pop(pop_data);
  cout<<test_stack<<endl;

  test_stack.Pop(pop_data);
  cout<<test_stack<<endl;

  // test CyberDashShow
  test_stack.CyberDashShow();

  return 0;
}