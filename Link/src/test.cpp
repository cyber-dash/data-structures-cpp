/*!
 * @file test.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 链表测试
 * @version 0.2.1
 * @date 2020-09-27
 * @copyright Copyright (c) 2021
 * **CyberDash计算机考研**
 */

#include <iostream>
#include "test.h"


using namespace std;


void TestLinkListInsert() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                    Test LinkList Insert                   |"<<endl;
  cout<<"|                         测试链表插入                        |"<<endl<<endl<<endl;

  LinkList<int>* link_list;
  link_list = new LinkList<int>();

  link_list->Insert(0, 1);
  link_list->Insert(1, 2);
  link_list->Insert(2, 3);

  link_list->Output();

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void TestLinkListLength() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                    Test LinkList Length                   |"<<endl;
  cout<<"|                         测试链表长度                        |"<<endl<<endl<<endl;

  LinkList<int> *link_list;
  link_list = new LinkList<int>();

  link_list->Insert(0, 1);
  link_list->Insert(1, 2);
  link_list->Insert(2, 3);

  cout<<"链表长度: "<<link_list->Length()<<endl;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}
