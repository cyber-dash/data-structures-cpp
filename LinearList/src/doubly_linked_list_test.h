/*!
 * @file doubly_linked_list_test.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 双向链表测试类
 * @version 0.9.0
 * @date 2022-11-13
 */

#ifndef CYBER_DASH_DOUBLY_LINKED_LIST_TEST_H
#define CYBER_DASH_DOUBLY_LINKED_LIST_TEST_H


#include "doubly_linked_list.h"


using namespace std;


/*!
 * @brief 双向链表测试类
 */
class DoublyLinkedListTest {
public:
    /*! @brief 测试按方向插入 */
    static void TestInsert();

    /*! @brief 测试删除 */
    static void TestRemove();
};


void DoublyLinkedListTest::TestInsert() {

    DoublyLinkedList<string>* band_list = new DoublyLinkedList<string>();

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


void DoublyLinkedListTest::TestRemove() {

    DoublyLinkedList<string>* band_list = new DoublyLinkedList<string>();

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
    band_list->Remove(4, data);

    band_list->Print();
}


#endif // CYBER_DASH_DOUBLY_LINKED_LIST_TEST_H
