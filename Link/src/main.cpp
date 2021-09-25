//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/6/6.
//

#include <iostream>
#include "node.h"
#include "link_list.h"
#include "link_list.cpp"


using namespace std;


int main(int argc, char** argv) {

  LinkList<int> *link_list;
  link_list = new LinkList<int>();

  int link_len = link_list->Length();
  cout<<"link_len:"<<link_len<<endl;

  // test Output
  link_list->Output();

  // test Insert
  int num1 = 1;
  int num2 = 2;
  link_list->Insert(0, num1);
  link_list->Insert(1, num2);

  // test Insert(int pos, T& data);
  int num3 = 3;
  link_list->Insert(2, num3);
  link_list->Output();

  // test constructor with LinkList
  LinkList<int>* link_list3 = new LinkList<int>(*link_list);
  link_list3->Output();

  // test GetData
  int test_data1;
  link_list->GetData(1, test_data1);
  cout<<"test_data1: "<<test_data1<<endl;

  // test SetData
  int test_data2 = 0;
  link_list->SetData(2, test_data2);
  link_list->Output();

  link_list->CyberDashShow();
}
