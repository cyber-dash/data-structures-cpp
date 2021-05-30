//
// Created by cyberdash@163.com on 2021/5/29.
//

#include "test.h"
#include "string"


using namespace std;


void TestSearchListSeqSearch() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                  Test SearchListSeqSearch                 |"<<endl;
  cout<<"|                    测试有序顺序表的顺序搜索                   |"<<endl;

  int size = 100;
  SearchList<string, string> search_list(size);

  search_list.Insert("我的家乡", "北京");
  search_list.Insert("我的高中", "北京汇文中学");
  search_list.Insert("我的大学", "北京邮电大学");

  int pos1 = search_list.SeqSearch("我的家乡");
  int pos2 = search_list.SeqSearch("我的高中");
  int pos3 = search_list.SeqSearch("我的大学");

  cout<<"\"我的家乡\"搜索位置: "<<pos1<<endl;
  cout<<"\"我的高中\"搜索位置: "<<pos2<<endl;
  cout<<"\"我的大学\"搜索位置: "<<pos3<<endl;

  cout<<"-------------------------------------------------------------"<<endl;
}
