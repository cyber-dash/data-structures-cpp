//
// Created by Zhongyuan.Li on 9/29/2021.
//

#ifndef CYBER_DASH_DOUBLE_LINK_LIST_TEST_H
#define CYBER_DASH_DOUBLE_LINK_LIST_TEST_H

#include "double_link_list.h"


using namespace std;


/*!
 * @brief 双向链表测试类
 */
class DoubleLinkListTest {
public:
  /*! @brief 测试插入 */
  static void TestInsert();
  /*! @brief 测试删除 */
  static void TestRemove();
  /*! @brief 测试长度 */
  static void TestLength();
  /*! @brief 测试链表是否为空 */
  static void TestEmpty();
  /*! @brief 测试链表查找 */
  static void TestSearch();
  /*! @brief 测试链表定位 */
  static void TestLocate();
};


void DoubleLinkListTest::TestInsert() {
  cout << endl;
  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<"                    Test DoubleList Insert                   "<<endl;
  cout<<"                         测试双向链表插入                        "<<endl<<endl<<endl;

  DoubleLinkList<int>* double_list = new DoubleLinkList<int>();

  double_list->Insert(0,1);
  double_list->Insert(1,2);
  double_list->Insert(2,3);

  double_list->Output();

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void DoubleLinkListTest::TestRemove() {

  cout<<endl;
  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<"               Test DoubleList Remove              "<<endl;
  cout<<"                         测试双向链表删除                        "<<endl<<endl<<endl;

  DoubleLinkList<int>* double_list;
  double_list = new DoubleLinkList<int>();

  double_list->Insert(0,1);
  double_list->Insert(1,2);
  double_list->Insert(2,3);

  int delete_item;
  double_list->Remove(3,delete_item);

  cout<<"remove item"<<delete_item<<endl;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void DoubleLinkListTest::TestLength(){

  cout<<endl;
  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<"               Test DoubleList Length              "<<endl;
  cout<<"                         测试双向链表长度                       "<<endl<<endl<<endl;

  DoubleLinkList<int>* double_list;
  double_list = new DoubleLinkList<int>();

  double_list->Insert(0,1);
  double_list->Insert(1,2);
  double_list->Insert(2,3);

  cout<<"double_list length"<<double_list->Length()<<endl;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void DoubleLinkListTest::TestEmpty(){

  cout<<endl;
  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<"               Test DoubleList Empty              "<<endl;
  cout<<"                         测试双向链表是否为空                        "<<endl<<endl<<endl;

  DoubleLinkList<string>* double_link;
  double_link = new DoubleLinkList<string>();

  cout<<"Before insert any string:"<<endl;

  bool isEmpty = double_link->IsEmpty();
  if (isEmpty) {
    cout<<"The seq_list is empty."<<endl;
  } else {
    cout<<"The seq_list isn't empty."<<endl;
  }

  string BJ = "Beijing";
  double_link->Insert(0,BJ);

  cout<<"After insert the string \"Beijing\":"<<endl;

  isEmpty = double_link->IsEmpty();
  if (isEmpty) {
    cout<<"The seq_list is empty."<<endl;
  } else {
    cout<<"The seq_list isn't empty."<<endl;
  }

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void DoubleLinkListTest::TestSearch(){

  cout<<endl;
  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<"               Test DoubleList Search              "<<endl;
  cout<<"                         测试双向链表查找                        "<<endl<<endl<<endl;

  DoubleLinkList<int>* double_list;
  double_list = new DoubleLinkList<int>();

  double_list->Insert(0,1);
  double_list->Insert(1,2);
  double_list->Insert(2,3);

  int pos = double_list->Search(3);

  cout<<"The pos of"<<3<<" is "<<pos<<endl;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}

/*
void DoubleLinkListTest::TestLocate(){

  cout<<endl;
  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<"               Test DoubleList Locate              "<<endl;
  cout<<"                         测试双向链表Locate                        "<<endl<<endl<<endl;

  DoubleLinkList<int>* double_list;
  double_list = new DoubleLinkList<int>();

  double_list->Insert(0,1);
  double_list->Insert(1,2);
  double_list->Insert(2,3);

  int pos = double_list->Locate(3);

  cout<<"The pos is: "<<pos<<endl;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}
 */


#endif // CYBER_DASH_DOUBLE_LINK_LIST_TEST_H
