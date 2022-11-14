/*!
 * @file circular_singly_linked_list_test.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 循环单链表测试类
 * @version 0.2.1
 * @date 2022-11-10
 */

#ifndef CYBER_DASH_CIRCULAR_SINGLY_LINKED_LIST_TEST_H
#define CYBER_DASH_CIRCULAR_SINGLY_LINKED_LIST_TEST_H


#include "circular_singly_linked_list.h"


class CircularSinglyLinkedListTest {
public:
    /*! @brief 测试插入 */
    static void TestInsert();
    /*! @brief 测试删除 */
    static void TestRemove();
};

void CircularSinglyLinkedListTest::TestInsert() {

    CircularSinglyLinkedList<string>* band_list = new CircularSinglyLinkedList<string>();

    string band1("The Script");
    string band2("Linkin Park");
    string band3("Starship");
    string band4("Coldplay");
    string band5("黑豹");

    band_list->Insert(0, band1);
    band_list->Insert(1, band2);
    band_list->Insert(2, band3);
    band_list->Insert(3, band4);
    band_list->Insert(4, band5);

    band_list->Print();
}


void CircularSinglyLinkedListTest::TestRemove() {

    CircularSinglyLinkedList<string>* band_list = new CircularSinglyLinkedList<string>();

    string band1("The Script");
    string band2("Linkin Park");
    string band3("Starship");
    string band4("Coldplay");
    string band5("黑豹");

    band_list->Insert(0, band1);
    band_list->Insert(1, band2);
    band_list->Insert(2, band3);
    band_list->Insert(3, band4);
    band_list->Insert(4, band5);

    string data;
    band_list->Remove(2, data);
    band_list->Print();
    band_list->Remove(4, data);
    band_list->Print();
    band_list->Remove(1, data);
    band_list->Print();
}


#endif // CYBER_DASH_CIRCULAR_SINGLY_LINKED_LIST_TEST_H
