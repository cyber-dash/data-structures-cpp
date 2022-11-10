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


#include "linked_list.h"


 /*!
  * @brief 单链表测试类
  */
class LinkListTest {
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
	static void TestMakeEmpty();

	/*! @brief 测试查找 */
	static void TestSearch();

	/*! @brief 测试定位 */
	static void TestLocate();

	/*! @brief 测试设置和获取数据 */
	static void TestGetDataAndSetData();
};


void LinkListTest::TestCopyConstructor() {
	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                Test LinkList CopyConstructor              |" << endl;
	cout << "|                       测试链表复制构造                       |" << endl << endl << endl;

	LinkedList<string> link_list;

	link_list.Insert(0, "Beijing");
	link_list.Insert(1, "Shanghai");
	link_list.Insert(2, "Guangzhou");

    link_list.Print();

	// LinkList<string>* link_list_2 = new LinkList<string>(link_list);
	LinkedList<string> link_list_2(link_list);

    link_list_2.Print();

	cout << "-------------------------------------------------------------" << endl << endl;
}


void LinkListTest::TestInsert() {
	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                    Test LinkList Insert                   |" << endl;
	cout << "|                         测试链表插入                        |" << endl << endl << endl;

	LinkedList<int>* link_list = new LinkedList<int>();

	link_list->Insert(0, 1);
	link_list->Insert(1, 2);
	link_list->Insert(2, 3);

    link_list->Print();

	cout << "-------------------------------------------------------------" << endl << endl;
}


void LinkListTest::TestLength() {
	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                    Test LinkList Length                   |" << endl;
	cout << "|                         测试链表长度                        |" << endl << endl << endl;

	LinkedList<int>* link_list = new LinkedList<int>();

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

	LinkedList<string>* link_list = new LinkedList<string>();

	link_list->Insert(0, "Beijing");
	link_list->Insert(1, "Shanghai");
	link_list->Insert(2, "Guangzhou");
	link_list->Insert(3, "Shenzhen");
	link_list->Insert(4, "Caoxian");

	cout << "删除前的链表:" << endl;
    link_list->Print();

	cout << "测试删除功能:" << endl;

	string delete_str;
	link_list->Remove(1, delete_str);
    link_list->Print();
	link_list->Remove(4, delete_str);
    link_list->Print();
	link_list->Remove(2, delete_str);
    link_list->Print();

	cout << "-------------------------------------------------------------" << endl << endl;
}


void LinkListTest::TestMakeEmpty() {
	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                  Test LinkList Clear                  |" << endl;
	cout << "|                         测试清除链表                        |" << endl << endl << endl;

	LinkedList<double>* link_list = new LinkedList<double>();

	link_list->Insert(0, 135.34);
	link_list->Insert(1, 305.43);
	link_list->Insert(2, 304.83);
	link_list->Insert(3, 405.31);
	link_list->Insert(4, 804.54);

    link_list->Print();

    link_list->Clear();

    link_list->Print();

	cout << "-------------------------------------------------------------" << endl << endl;
}


void LinkListTest::TestSearch() {

	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                   Test LinkList Search                    |" << endl;
	cout << "|                         测试链表搜索                        |" << endl << endl << endl;

	LinkedList<string>* link_list = new LinkedList<string>();

	link_list->Insert(0, "Beijing");
	link_list->Insert(1, "Shanghai");
	link_list->Insert(2, "Guangzhou");
	link_list->Insert(3, "Shenzhen");
	link_list->Insert(4, "Caoxian");

	LinkedNode<string>* bj_node_ptr = link_list->Search("Beijing");
	LinkedNode<string>* cx_node_ptr = link_list->Search("Caoxian");

	cout << "bj_node_ptr->data: " << bj_node_ptr->data << endl;
	cout << "cx_node_ptr->data: " << cx_node_ptr->data << endl;

	cout << "-------------------------------------------------------------" << endl << endl;
}


void LinkListTest::TestLocate() {
	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                   Test LinkedList GetNode                 |" << endl;
	cout << "|                       测试链表获取结点                      |" << endl << endl << endl;

	LinkedList<string>* city_linked_list = new LinkedList<string>();    // 城市链表city_linked_list

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


void LinkListTest::TestGetDataAndSetData() {
	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|              Test LinkList GetDataAndSetData              |" << endl;
	cout << "|                     测试链表设置和获取数据                   |" << endl << endl << endl;

	LinkedList<string>* link_list = new LinkedList<string>();

	link_list->Insert(0, "Beijing");
	link_list->Insert(1, "Shanghai");
	link_list->Insert(2, "Guangzhou");

	string city;
	link_list->GetData(2, city);
	cout << city << endl;

	link_list->SetData(2, "Shenzhen");

    link_list->Print();


	cout << "-------------------------------------------------------------" << endl << endl;
}

#endif // CYBER_DASH_LINK_LIST_TEST_H
