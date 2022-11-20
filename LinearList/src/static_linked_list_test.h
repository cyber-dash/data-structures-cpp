//
// Created by svenlee on 2022/11/19.
//

#ifndef CYBER_DASH_STATIC_LINKED_LIST_TEST_H
#define CYBER_DASH_STATIC_LINKED_LIST_TEST_H


#include <iostream>
#include "static_linked_list.h"


using namespace std;


class StaticLinkedListTest {
public:
    /*! @brief 测试复制构造函数 */
    static void TestInsert();
};


void StaticLinkedListTest::TestInsert() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                Test StaticLinkedList Insert               |" << endl;
    cout << "|                       测试静态链表插入                       |" << endl << endl << endl;

    StaticLinkedList<int>* static_link_list = new StaticLinkedList<int>();

    static_link_list->Insert(0, 2);
    static_link_list->Insert(1, 8);
    static_link_list->Insert(2, 5);
    static_link_list->Insert(3, 7);
    static_link_list->Insert(0, 4);
    static_link_list->Insert(0, 1);

    static_link_list->Print();

    cout << "-------------------------------------------------------------" << endl << endl;
}


#endif // CYBER_DASH_STATIC_LINKED_LIST_TEST_H
