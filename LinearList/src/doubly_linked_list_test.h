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
    // 测试双向链表插入结点
    static void TestInsert();

    // 测试双向链表删除结点
    static void TestRemove();

    // 测试双向链表搜索
    static void TestSearch();

    // 测试双向链表长度
    static void TestLength();

    // 测试双向链表清空链表
    static void TestClear();
};


void DoublyLinkedListTest::TestInsert() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                Test DoublyLinkedList Insert               |" << endl;
    cout << "|                        测试双链表插入                       |" << endl << endl << endl;

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

    cout << "-------------------------------------------------------------" << endl << endl;
}


void DoublyLinkedListTest::TestRemove() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                Test DoublyLinkedList Remove               |" << endl;
    cout << "|                      测试双链表删除结点                     |" << endl << endl << endl;

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

    cout << "-------------------------------------------------------------" << endl << endl;
}


// 测试双向链表搜索
void DoublyLinkedListTest::TestSearch() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                Test DoublyLinkedList Search               |" << endl;
    cout << "|                        测试双链表搜索                       |" << endl << endl << endl;

    DoublyLinkedList<int>* number_list = new DoublyLinkedList<int>();

    for (int i = 1; i <= 5; i++) {
        int pos = i - 1;
        int data = i;
        number_list->Insert(pos, data);
    }

    DoublyLinkedNode<int>* addr = number_list->Search(3);

    cout << "-------------------------------------------------------------" << endl << endl;
}


// 测试双向链表长度
void DoublyLinkedListTest::TestLength() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                Test DoublyLinkedList Length               |" << endl;
    cout << "|                        测试双链表长度                       |" << endl << endl << endl;


    cout << "-------------------------------------------------------------" << endl << endl;
}


// 测试双向链表清空链表
void DoublyLinkedListTest::TestClear() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                 Test DoublyLinkedList Clear               |" << endl;
    cout << "|                      测试双链表清空链表                      |" << endl << endl << endl;


    cout << "-------------------------------------------------------------" << endl << endl;
}


#endif // CYBER_DASH_DOUBLY_LINKED_LIST_TEST_H
