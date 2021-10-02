/*!
 * @file link_list_test.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 单链表测试类
 * @version 0.2.1
 * @date 2021-09-28
 * @copyright Copyright (c) 2021
 * **CyberDash计算机考研**
 */

#ifndef CYBER_DASH_LINK_LIST_TEST_H
#define CYBER_DASH_LINK_LIST_TEST_H


#include "link_list.h"


/*!
 * @brief 单链表测试类
 */
class LinkListTest {
public:
  /*! @brief 测试插入 */
  static void TestInsert();

  /*! @brief 测试长度 */
  static void TestLength();

  /*! @brief 测试删除 */
  static void TestRemove();

  /*! @brief 测试清除链表 */
  static void TestMakeEmpty();

  /*! @brief 测试查找 */
  static void TestSearch();

  /*! @brief 测试定位 */
  static void TestLocate();
};


void LinkListTest::TestInsert() {
  cout << endl;
  cout << "|------------------------ CyberDash ------------------------|" << endl;
  cout << "|                    Test LinkList Insert                   |" << endl;
  cout << "|                         测试链表插入                        |" << endl << endl << endl;

  LinkList<int>* link_list = new LinkList<int>();

  link_list->Insert(0, 1);
  link_list->Insert(1, 2);
  link_list->Insert(2, 3);

  link_list->Output();

  cout << "-------------------------------------------------------------" << endl << endl;
}


void LinkListTest::TestLength() {
  cout << endl;
  cout << "|------------------------ CyberDash ------------------------|" << endl;
  cout << "|                    Test LinkList Length                   |" << endl;
  cout << "|                         测试链表长度                        |" << endl << endl << endl;

  LinkList<int> *link_list = new LinkList<int>();

  link_list->Insert(0, 1);
  link_list->Insert(1, 2);
  link_list->Insert(2, 3);

  cout << "链表长度: " << link_list->Length() << endl;

  cout << "-------------------------------------------------------------" << endl << endl;
}


void LinkListTest::TestRemove() {
  cout << endl;
  cout << "|------------------------ CyberDash ------------------------|" << endl;
  cout << "|                    Test LinkList Remove                   |" << endl;
  cout << "|                         测试链表删除                        |" << endl << endl << endl;

  LinkList<string>* link_list = new LinkList<string>();

  link_list->Insert(0, "Beijing");
  link_list->Insert(1, "Shanghai");
  link_list->Insert(2, "Guangzhou");
  link_list->Insert(3, "Shenzhen");
  link_list->Insert(4, "Caoxian");

  cout << "删除前的链表:" << endl;
  link_list->Output();

  cout << "测试删除功能:" << endl;

  string delete_str;
  link_list->Remove(1, delete_str);
  link_list->Output();
  link_list->Remove(4, delete_str);
  link_list->Output();
  link_list->Remove(2, delete_str);
  link_list->Output();

  cout << "-------------------------------------------------------------" << endl << endl;
}


void LinkListTest::TestMakeEmpty() {
  cout << endl;
  cout << "|------------------------ CyberDash ------------------------|" << endl;
  cout << "|                  Test LinkList MakeEmpty                  |" << endl;
  cout << "|                         测试清除链表                        |" << endl << endl << endl;

  LinkList<double>* link_list = new LinkList<double>();

  link_list->Insert(0, 135.34);
  link_list->Insert(1, 305.43);
  link_list->Insert(2, 304.83);
  link_list->Insert(3, 405.31);
  link_list->Insert(4, 804.54);

  link_list->Output();

  link_list->MakeEmpty();

  link_list->Output();

  cout << "-------------------------------------------------------------" << endl << endl;
}


void LinkListTest::TestSearch() {

  cout << endl;
  cout << "|------------------------ CyberDash ------------------------|" << endl;
  cout << "|                   Test LinkList Search                    |" << endl;
  cout << "|                         测试链表搜索                        |" << endl << endl << endl;

  LinkList<string>* link_list = new LinkList<string>();

  link_list->Insert(0, "Beijing");
  link_list->Insert(1, "Shanghai");
  link_list->Insert(2, "Guangzhou");
  link_list->Insert(3, "Shenzhen");
  link_list->Insert(4, "Caoxian");

  LinkNode<string>* bj_node_ptr = link_list->Search("Beijing");
  LinkNode<string>* cx_node_ptr = link_list->Search("Caoxian");

  cout << "bj_node_ptr->data_: " << bj_node_ptr->data_ << endl;
  cout << "cx_node_ptr->data_: " << cx_node_ptr->data_ << endl;

  cout << "-------------------------------------------------------------" << endl << endl;
}


void LinkListTest::TestLocate() {

  cout << endl;
  cout << "|------------------------ CyberDash ------------------------|" << endl;
  cout << "|                   Test LinkList LocateByDirection                    |" << endl;
  cout << "|                         测试链表定位                        |" << endl << endl << endl;

  LinkList<string>* link_list = new LinkList<string>();

  link_list->Insert(0, "Beijing");
  link_list->Insert(1, "Shanghai");
  link_list->Insert(2, "Guangzhou");
  link_list->Insert(3, "Shenzhen");
  link_list->Insert(4, "Caoxian");

  LinkNode<string>* pos_1_node_ptr = link_list->Locate(1);
  LinkNode<string>* pos_2_node_ptr = link_list->Locate(2);

  cout << "pos_1_node_ptr->data_: " << pos_1_node_ptr->data_ << endl;
  cout << "pos_2_node_ptr->data_: " << pos_2_node_ptr->data_ << endl;

  cout << "-------------------------------------------------------------" << endl << endl;
}


#endif // CYBER_DASH_LINK_LIST_TEST_H
