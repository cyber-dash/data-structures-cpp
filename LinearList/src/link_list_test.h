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


#endif // CYBER_DASH_LINK_LIST_TEST_H
