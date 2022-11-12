/*!
 * @file doubly_linked_list_test.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 双向循环单链表测试类
 * @version 0.2.1
 * @date 2022-11-10
 * @copyright Copyright (c) 2021
 * **CyberDash计算机考研**
 */

#ifndef CYBER_DASH_DOUBLE_LINK_LIST_TEST_H
#define CYBER_DASH_DOUBLE_LINK_LIST_TEST_H

#include "circular_doubly_linked_list.h"


using namespace std;


/*!
 * @brief 双向链表测试类
 */
class DoublyLinkedListTest {
public:
    /*! @brief 测试按方向插入 */
    static void TestInsertByDirection();
    /*! @brief 测试删除 */
    static void TestRemoveByDirection();
    /*! @brief 测试长度 */
    static void TestLength();
    /*! @brief 测试链表是否为空 */
    static void TestEmpty();
    /*! @brief 测试链表查找 */
    static void TestSearch();
    /*! @brief 测试链表定位 */
    static void TestGetNode();
    /*! @brief 测试获取设置数据 */
    static void TestGetDataAndSetData();
};


void DoublyLinkedListTest::TestInsertByDirection() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|              Test DoublyLinkedList InsertByDirection            |" << endl;
    cout << "|                     测试双向链表按方向插入                    |" << endl << endl << endl;

    DoublyLinkedList<string>* band_list = new DoublyLinkedList<string>();

    string band1("The Script");
    string band2("Linkin Park");
    string band3("Starship");

    band_list->InsertByDirection(0, band1, DoublyLinkedList<string>::FORWARD_DIRECTION);
    band_list->InsertByDirection(1, band2, DoublyLinkedList<string>::FORWARD_DIRECTION);
    band_list->InsertByDirection(2, band3, DoublyLinkedList<string>::FORWARD_DIRECTION);

    band_list->Print();

    cout << "-------------------------------------------------------------" << endl << endl;
}


void DoublyLinkedListTest::TestRemoveByDirection() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|              Test DoublyLinkedList RemoveByDirection            |" << endl;
    cout << "|                     测试双向链表按方向删除                   |" << endl << endl << endl;

    DoublyLinkedList<string>* city_list = new DoublyLinkedList<string>();

    city_list->Insert(0, "北京");
    city_list->Insert(1, "上海");
    city_list->Insert(2, "广州");
    city_list->Insert(3, "深圳");
    city_list->Insert(4, "成都");
    city_list->Insert(5, "珠海");

    city_list->Print();

    string delete_item;

    int delete_pos = 3;
    city_list->RemoveByDirection(delete_pos, delete_item, DoublyLinkedList<int>::FORWARD_DIRECTION);

    cout << "向后删除城市" << delete_pos << "之后: " << endl;
    city_list->Print();

    delete_pos = 1;
    city_list->RemoveByDirection(delete_pos, delete_item, DoublyLinkedList<int>::FORWARD_DIRECTION);

    cout << "向后删除城市" << delete_pos << "之后: " << endl;
    city_list->Print();

    cout << "-------------------------------------------------------------" << endl << endl;
}


void DoublyLinkedListTest::TestLength() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                   Test DoublyLinkedList Length                  |" << endl;
    cout << "|                       测试双向链表长度                      |" << endl << endl << endl;

    DoublyLinkedList<int>* double_list;
    double_list = new DoublyLinkedList<int>();

    double_list->Insert(0, 1);
    double_list->Insert(1, 2);
    double_list->Insert(2, 3);

    cout << "双向链表长度: " << double_list->Length() << endl;

    cout << "-------------------------------------------------------------" << endl << endl;
}


void DoublyLinkedListTest::TestEmpty() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                 Test DoublyLinkedList Empty               |" << endl;
    cout << "|                      测试双向链表是否为空                   |" << endl << endl << endl;

    DoublyLinkedList<string>* double_link;
    double_link = new DoublyLinkedList<string>();

    cout << "Before insert any string:" << endl;

    bool isEmpty = double_link->IsEmpty();
    if (isEmpty) {
        cout << "The seq_list is empty." << endl;
    }
    else {
        cout << "The seq_list isn't empty." << endl;
    }

    string BJ = "Beijing";
    double_link->Insert(0, BJ);

    cout << "After insert the string \"Beijing\":" << endl;

    isEmpty = double_link->IsEmpty();
    if (isEmpty) {
        cout << "The seq_list is empty." << endl;
    }
    else {
        cout << "The seq_list isn't empty." << endl;
    }

    cout << "-------------------------------------------------------------" << endl << endl;
}


void DoublyLinkedListTest::TestSearch() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                   Test DoublyLinkedList Search                  |" << endl;
    cout << "|                       测试双向链表查找                      |" << endl << endl << endl;

    DoublyLinkedList<int>* double_list;
    double_list = new DoublyLinkedList<int>();

    double_list->Insert(0, 1);
    double_list->Insert(1, 2);
    double_list->Insert(2, 3);

    DoublyLinkedNode<int>* node_1 = double_list->Search(1);
    DoublyLinkedNode<int>* node_3 = double_list->Search(3);

    cout << "The pos of " << 1 << " is " << node_1 << endl;
    cout << "The pos of " << 3 << " is " << node_3 << endl;

    cout << "-------------------------------------------------------------" << endl << endl;
}


void DoublyLinkedListTest::TestGetNode() {

    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|               Test DoublyLinkedList GetNode               |"<<endl;
    cout<<"|              测试双向循环链表获取结点(向next方向)              |"<<endl<<endl<<endl;

    DoublyLinkedList<int>* doubly_linked_list = new DoublyLinkedList<int>();

    doubly_linked_list->Insert(0, 1);
    doubly_linked_list->Insert(1, 2);
    doubly_linked_list->Insert(2, 3);

    DoublyLinkedNode<int>* node = doubly_linked_list->GetNode(3);

    cout<<"node->data: "<<node->data<<endl;

    cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void DoublyLinkedListTest::TestGetDataAndSetData() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|          Test DoublyLinkedList GetNode And SetData        |" << endl;
    cout << "|                 测试双向循环链表获取/设置数据项                |" << endl << endl << endl;

    DoublyLinkedList<string>* city_list = new DoublyLinkedList<string>();

    city_list->Insert(0, "Beijing");
    city_list->Insert(1, "Shanghai");
    city_list->Insert(2, "Shenzhen");

    string city_name;
    city_list->GetData(1, city_name);
    cout << "The city_name: " << city_name;

    cout << endl << "-------------------------------------------------------------" << endl << endl;
}


#endif // CYBER_DASH_DOUBLE_LINK_LIST_TEST_H
