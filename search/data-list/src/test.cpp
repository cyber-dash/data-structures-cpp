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
  cout<<"|                      测试顺序表的顺序搜索                    |"<<endl;

  int size = 100;
  SearchList<string, string> search_list(size);

  search_list.Insert("我的家乡", "北京");
  search_list.Insert("我的高中", "北京汇文中学");
  search_list.Insert("我的大学", "北京邮电大学");

  int pos1 = search_list.SeqSearch("我的家乡");
  int pos2 = search_list.SeqSearch("我的高中");
  int pos3 = search_list.SeqSearch("我的大学");

  cout<<"(从1开始)"<<endl;
  cout<<"\"我的家乡\"搜索位置: "<<pos1<<endl;
  cout<<"\"我的高中\"搜索位置: "<<pos2<<endl;
  cout<<"\"我的大学\"搜索位置: "<<pos3<<endl;

  cout<<"-------------------------------------------------------------"<<endl;
}


void TestSortedListSeqSearch() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                  Test SortedListSeqSearch                 |"<<endl;
  cout<<"|                    测试有序顺序表的顺序搜索                   |"<<endl;

  int size = 100;
  SortedList<string, string> sorted_list(size);

  sorted_list.Insert("My hometown", "北京");
  sorted_list.Insert("My senior high school", "北京汇文中学");
  sorted_list.Insert("My college", "北京邮电大学");

  int pos1 = sorted_list.SeqSearch("My hometown");
  int pos2 = sorted_list.SeqSearch("My senior high school");
  int pos3 = sorted_list.SeqSearch("My college");

  cout<<"(从1开始)"<<endl;
  cout<<"\"My hometown\"搜索位置: "<<pos1<<endl;
  cout<<"\"My senior high school\"搜索位置: "<<pos2<<endl;
  cout<<"\"My college\"搜索位置: "<<pos3<<endl;

  cout<<"-------------------------------------------------------------"<<endl;
}
