/*!
 * @file linked_list_test.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 单链表测试类
 * @version 0.2.1
 * @date 2021-09-28
 * @copyright Copyright (c) 2021
 * **CyberDash计算机考研**
 */

#ifndef CYBER_DASH_LINK_LIST_TEST_H
#define CYBER_DASH_LINK_LIST_TEST_H


#include "singly_linked_list.h"


 /*!
  * @brief 单链表测试类
  */
class SinglyLinkListTest {
public:
	/*! @brief 测试复制构造函数 */
	static void TestCopyConstructor();

	/*! @brief 测试插入 */
	static void TestInsert();

	/*! @brief 测试长度 */
	static void TestLength();

	/*! @brief 测试删除 */
	static void TestRemove();

	/*! @brief 测试清除链表 */
	static void TestClear();

	/*! @brief 测试查找 */
	static void TestSearch();

	/*! @brief 测试定位 */
	static void TestLocate();

	/*! @brief 测试设置和获取数据 */
	static void TestGetDataAndSetData();
};


void SinglyLinkListTest::TestCopyConstructor() {
	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|             Test SinglyLinkList CopyConstructor           |" << endl;
	cout << "|                      测试单链表复制构造                      |" << endl << endl << endl;

	SinglyLinkedList<string> singly_linked_list;

	singly_linked_list.Insert(0, "Beijing");
	singly_linked_list.Insert(1, "Shanghai");
	singly_linked_list.Insert(2, "Guangzhou");

    singly_linked_list.Print();

	SinglyLinkedList<string> singly_linked_list_2 = singly_linked_list;

    singly_linked_list_2.Print();

	cout << "-------------------------------------------------------------" << endl << endl;
}


void SinglyLinkListTest::TestInsert() {
	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                 Test SinglyLinkList Insert                |" << endl;
	cout << "|                         试单链表插入                        |" << endl << endl << endl;

	SinglyLinkedList<int>* singly_linked_list = new SinglyLinkedList<int>();

	singly_linked_list->Insert(0, 1);
	singly_linked_list->Insert(1, 2);
	singly_linked_list->Insert(2, 3);

    singly_linked_list->Print();

	cout << "-------------------------------------------------------------" << endl << endl;
}


void SinglyLinkListTest::TestLength() {
	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                 Test SinglyLinkList Length                |" << endl;
	cout << "|                        测试单链表长度                       |" << endl << endl << endl;

	SinglyLinkedList<int>* singly_linked_list = new SinglyLinkedList<int>();

	singly_linked_list->Insert(0, 1);
	singly_linked_list->Insert(1, 2);
	singly_linked_list->Insert(2, 3);

	cout << "链表长度: " << singly_linked_list->Length() << endl;

	cout << "-------------------------------------------------------------" << endl << endl;
}


void SinglyLinkListTest::TestRemove() {
	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                 Test SinglyLinkList Remove                |" << endl;
	cout << "|                      测试单链表删除结点                      |" << endl << endl << endl;

	SinglyLinkedList<string>* singly_linked_list = new SinglyLinkedList<string>();

	singly_linked_list->Insert(0, "Beijing");
	singly_linked_list->Insert(1, "Shanghai");
	singly_linked_list->Insert(2, "Guangzhou");
	singly_linked_list->Insert(3, "Shenzhen");
	singly_linked_list->Insert(4, "Caoxian");

	cout << "删除前的链表:" << endl;
    singly_linked_list->Print();

	cout << "测试删除功能:" << endl;

	string remove_str;
	singly_linked_list->Remove(1, remove_str);
    singly_linked_list->Print();
	singly_linked_list->Remove(4, remove_str);
    singly_linked_list->Print();
	singly_linked_list->Remove(2, remove_str);
    singly_linked_list->Print();

	cout << "-------------------------------------------------------------" << endl << endl;
}


void SinglyLinkListTest::TestClear() {
	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                 Test SinglyLinkList Clear                 |" << endl;
	cout << "|                        测试单链表清空                       |" << endl << endl << endl;

	SinglyLinkedList<double>* singly_linked_list = new SinglyLinkedList<double>();

	singly_linked_list->Insert(0, 135.34);
	singly_linked_list->Insert(1, 305.43);
	singly_linked_list->Insert(2, 304.83);
	singly_linked_list->Insert(3, 405.31);
	singly_linked_list->Insert(4, 804.54);

    singly_linked_list->Print();

    singly_linked_list->Clear();

    singly_linked_list->Print();

	cout << "-------------------------------------------------------------" << endl << endl;
}


void SinglyLinkListTest::TestSearch() {

	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                 Test SinglyLinkList Search                |" << endl;
	cout << "|                        测试单链表搜索                       |" << endl << endl << endl;

	SinglyLinkedList<string>* singly_linked_list = new SinglyLinkedList<string>();

	singly_linked_list->Insert(0, "Beijing");
	singly_linked_list->Insert(1, "Shanghai");
	singly_linked_list->Insert(2, "Guangzhou");
	singly_linked_list->Insert(3, "Shenzhen");
	singly_linked_list->Insert(4, "Caoxian");

	LinkedNode<string>* bj_node_ptr = singly_linked_list->Search("Beijing");
	LinkedNode<string>* cx_node_ptr = singly_linked_list->Search("Caoxian");

	cout << "bj_node_ptr->data: " << bj_node_ptr->data << endl;
	cout << "cx_node_ptr->data: " << cx_node_ptr->data << endl;

	cout << "-------------------------------------------------------------" << endl << endl;
}


void SinglyLinkListTest::TestLocate() {
	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|               Test SinglyLinkedList GetNode               |" << endl;
	cout << "|                      测试单链表获取结点                      |" << endl << endl << endl;

	SinglyLinkedList<string>* city_linked_list = new SinglyLinkedList<string>();    // 城市链表city_linked_list

	city_linked_list->Insert(0, "Beijing");     // 位置1插入北京
	city_linked_list->Insert(1, "Shanghai");    // 位置2插入上海
	city_linked_list->Insert(2, "Guangzhou");   // 位置3插入广州
	city_linked_list->Insert(3, "Shenzhen");    // 位置4插入深圳
	city_linked_list->Insert(4, "Caoxian");     // 位置5插入曹县

	LinkedNode<string>* pos_1_node = city_linked_list->GetNode(1);
	LinkedNode<string>* pos_2_node = city_linked_list->GetNode(2);

	cout << "pos_1_node->data: " << pos_1_node->data << endl;
	cout << "pos_2_node->data: " << pos_2_node->data << endl;

	cout << "-------------------------------------------------------------" << endl << endl;
}


void SinglyLinkListTest::TestGetDataAndSetData() {
	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|            Test SinglyLinkList GetDataAndSetData          |" << endl;
	cout << "|                     测试单链表设置和获取数据                  |" << endl << endl << endl;

	SinglyLinkedList<string>* singly_linked_list = new SinglyLinkedList<string>();

	singly_linked_list->Insert(0, "Beijing");
	singly_linked_list->Insert(1, "Shanghai");
	singly_linked_list->Insert(2, "Guangzhou");

	string city;
	singly_linked_list->GetData(2, city);
	cout << city << endl;

	singly_linked_list->SetData(2, "Shenzhen");

    singly_linked_list->Print();


	cout << "-------------------------------------------------------------" << endl << endl;
}

#endif // CYBER_DASH_LINK_LIST_TEST_H
