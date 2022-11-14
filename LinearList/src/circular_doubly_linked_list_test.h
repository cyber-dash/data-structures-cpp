/*!
 * @file circular_doubly_linked_list_test.h
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
class CircularDoublyLinkedListTest {
public:
    /*! @brief 测试按方向插入 */
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
    static void TestGetNode();
    /*! @brief 测试获取设置数据 */
    static void TestGetDataAndSetData();
};


void CircularDoublyLinkedListTest::TestInsert() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|              Test CircularDoublyLinkedList InsertByDirection            |" << endl;
    cout << "|                     测试双向链表按方向插入                    |" << endl << endl << endl;

    CircularDoublyLinkedList<string>* band_list = new CircularDoublyLinkedList<string>();

    string band1("The Script");
    string band2("Linkin Park");
    string band3("Starship");
    string band4("Coldplay");
    string band5("黑豹");

    band_list->InsertByDirection(0, band1, CircularDoublyLinkedList<string>::FORWARD_DIRECTION);
    band_list->InsertByDirection(1, band2, CircularDoublyLinkedList<string>::FORWARD_DIRECTION);
    band_list->InsertByDirection(2, band3, CircularDoublyLinkedList<string>::FORWARD_DIRECTION);
    band_list->InsertByDirection(3, band4, CircularDoublyLinkedList<string>::FORWARD_DIRECTION);
    band_list->InsertByDirection(4, band5, CircularDoublyLinkedList<string>::FORWARD_DIRECTION);

    band_list->Print();

    cout << "-------------------------------------------------------------" << endl << endl;
}


void CircularDoublyLinkedListTest::TestRemove() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|              Test CircularDoublyLinkedList RemoveByDirection            |" << endl;
    cout << "|                     测试双向链表按方向删除                   |" << endl << endl << endl;

    CircularDoublyLinkedList<string>* city_list = new CircularDoublyLinkedList<string>();

    city_list->Insert(0, "北京");
    city_list->Insert(1, "上海");
    city_list->Insert(2, "广州");
    city_list->Insert(3, "深圳");
    city_list->Insert(4, "成都");
    city_list->Insert(5, "珠海");

    city_list->Print();

    string delete_item;

    int delete_pos = 3;
    city_list->RemoveByDirection(delete_pos, delete_item, CircularDoublyLinkedList<int>::FORWARD_DIRECTION);

    cout << "向后删除城市" << delete_pos << "之后: " << endl;
    city_list->Print();

    delete_pos = 1;
    city_list->RemoveByDirection(delete_pos, delete_item, CircularDoublyLinkedList<int>::FORWARD_DIRECTION);

    cout << "向后删除城市" << delete_pos << "之后: " << endl;
    city_list->Print();

    cout << "-------------------------------------------------------------" << endl << endl;
}


void CircularDoublyLinkedListTest::TestLength() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                   Test CircularDoublyLinkedList Length                  |" << endl;
    cout << "|                       测试双向链表长度                      |" << endl << endl << endl;

    CircularDoublyLinkedList<int>* double_list;
    double_list = new CircularDoublyLinkedList<int>();

    double_list->Insert(0, 1);
    double_list->Insert(1, 2);
    double_list->Insert(2, 3);

    cout << "双向链表长度: " << double_list->Length() << endl;

    cout << "-------------------------------------------------------------" << endl << endl;
}


void CircularDoublyLinkedListTest::TestEmpty() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                 Test CircularDoublyLinkedList Empty               |" << endl;
    cout << "|                      测试双向链表是否为空                   |" << endl << endl << endl;

    CircularDoublyLinkedList<string>* double_link;
    double_link = new CircularDoublyLinkedList<string>();

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


void CircularDoublyLinkedListTest::TestSearch() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                Test CircularDoublyLinkedList Search               |" << endl;
    cout << "|                       测试双向链表查找                      |" << endl << endl << endl;

    CircularDoublyLinkedList<int>* double_list;
    double_list = new CircularDoublyLinkedList<int>();

    double_list->Insert(0, 1);
    double_list->Insert(1, 2);
    double_list->Insert(2, 3);

    CircularDoublyLinkedNode<int>* node_1 = double_list->Search(1);
    CircularDoublyLinkedNode<int>* node_3 = double_list->Search(3);

    cout << "The address of node with data 1: " << 1 << " is " << node_1 << endl;
    cout << "The address of node with data 3: " << 1 << " is " << node_3 << endl;

    cout << "-------------------------------------------------------------" << endl << endl;
}


void CircularDoublyLinkedListTest::TestGetNode() {

    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|               Test CircularDoublyLinkedList GetNode               |"<<endl;
    cout<<"|              测试双向循环链表获取结点(向next方向)              |"<<endl<<endl<<endl;

    CircularDoublyLinkedList<int>* circular_doubly_linked_list = new CircularDoublyLinkedList<int>();

    circular_doubly_linked_list->Insert(0, 1);
    circular_doubly_linked_list->Insert(1, 2);
    circular_doubly_linked_list->Insert(2, 3);
    circular_doubly_linked_list->Insert(3, 4);
    circular_doubly_linked_list->Insert(4, 5);
    circular_doubly_linked_list->Insert(5, 5);
    circular_doubly_linked_list->Insert(6, 7);

    CircularDoublyLinkedNode<int>* node1 = circular_doubly_linked_list->GetNode(1);
    CircularDoublyLinkedNode<int>* node2 = circular_doubly_linked_list->GetNode(4);
    CircularDoublyLinkedNode<int>* node3 = circular_doubly_linked_list->GetNode(7);

    cout<<"node->data: "<<node1->data<<endl;
    cout<<"node->data: "<<node2->data<<endl;
    cout<<"node->data: "<<node3->data<<endl;

    cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void CircularDoublyLinkedListTest::TestGetDataAndSetData() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|          Test CircularDoublyLinkedList GetNode And SetData        |" << endl;
    cout << "|                 测试双向循环链表获取/设置数据项                |" << endl << endl << endl;

    CircularDoublyLinkedList<string>* city_list = new CircularDoublyLinkedList<string>();

    city_list->Insert(0, "Beijing");        // 位置0后边, 插入"Beijing"
    city_list->Insert(1, "Shanghai");       // 位置1后边, 插入"Shanghai"
    city_list->Insert(2, "Guangzhou");      // 位置2后边, 插入"Guangzhou"
    city_list->Insert(3, "Shenzhen");       // 位置3后边, 插入"Shenzhen"
    city_list->Insert(4, "Suzhou");         // 位置4后边, 插入"Suzhou"
    city_list->Insert(5, "Hangzhou");       // 位置5后边, 插入"Hangzhou"
    city_list->Insert(6, "Chengdu");        // 位置6后边, 插入"Chengdu"

    string city_name;
    city_list->GetData(3, city_name);
    cout << "The city_name: " << city_name;

    cout << endl << "-------------------------------------------------------------" << endl << endl;
}


#endif // CYBER_DASH_DOUBLE_LINK_LIST_TEST_H
