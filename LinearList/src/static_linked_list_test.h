/*!
 * @file static_linked_list_test.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 静态链表测试类
 * @version 0.2.1
 * @date 2022-11-18
 */

#ifndef CYBER_DASH_STATIC_LINKED_LIST_TEST_H
#define CYBER_DASH_STATIC_LINKED_LIST_TEST_H


#include <iostream>
#include <string>
#include "static_linked_list.h"


using namespace std;


/*!
 * @brief **静态链表测试类**
 */
class StaticLinkedListTest {
public:
    // 测试-静态链表-插入
    static void TestInsert();

    // 测试-静态链表-搜索
    static void TestSearch();

    // 测试-静态链表-删除
    static void TestRemove();
};


/*!
 * @brief **测试-静态链表-插入**
 * @note
 * 测试-静态链表-插入
 * ----------------
 * ----------------
 *
 * ----------------
 * 声明static_link_list\n
 * 插入7个结点\n
 * 打印static_link_list\n
 *
 *
 * ----------------
 */
void StaticLinkedListTest::TestInsert() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                Test StaticLinkedList Insert               |" << endl;
    cout << "|                     测试-静态链表-插入                    |" << endl << endl << endl;

    // 声明static_link_list
    StaticLinkedList<int>* static_link_list = new StaticLinkedList<int>(1);

    // 插入7个结点
    static_link_list->Insert(0, 2);
    static_link_list->Insert(1, 8);
    static_link_list->Insert(2, 5);
    static_link_list->Insert(3, 7);
    static_link_list->Insert(0, 4);
    static_link_list->Insert(0, 1);

    // 打印static_link_list
    static_link_list->Print();

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-静态链表-搜索**
 * @note
 * 测试-静态链表-搜索
 * ----------------
 * ----------------
 *
 * ----------------
 * 声明static_link_list\n
 * 插入6个结点\n
 * 打印static_link_list\n
 * 搜索3个字符串在链表中的位置, 并打印\n
 *
 *
 * ----------------
 */
void StaticLinkedListTest::TestSearch() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                Test StaticLinkedList Search               |" << endl;
    cout << "|                     测试-静态链表-搜索                    |" << endl << endl << endl;

    // 声明static_link_list
    StaticLinkedList<string>* static_link_list = new StaticLinkedList<string>(1);

    // 插入6个结点
    string str1("Cyber");
    string str2("Dash");
    string str3("Yuan");
    string str4("Lei");
    string str5("Yu");
    string str6("Cao");

    static_link_list->Insert(0, str1);
    static_link_list->Insert(1, str2);
    static_link_list->Insert(2, str3);
    static_link_list->Insert(3, str4);
    static_link_list->Insert(4, str5);
    static_link_list->Insert(5, str6);

    // 打印static_link_list
    static_link_list->Print();

    cout << endl;

    // 搜索3个字符串在链表中的位置, 并打印
    int pos = 0;
    string search_str_1("Yuan");
    string search_str_2("Hello");
    string mr_cao("Cao");

    cout << "搜索\"Yuan\":" << endl;

    bool res = static_link_list->Search(search_str_1, pos);
    if (!res) {
        cout << "Not found" << endl << endl;
    } else {
        cout << "位置: " << pos << endl << endl;
    }

    cout << "搜索\"Hello\":" << endl;

    res = static_link_list->Search(search_str_2, pos);
    if (!res) {
        cout << "Not found" << endl << endl;
    } else {
        cout << "位置: " << pos << endl << endl;
    }

    cout << "搜索\"Cao\":" << endl;

    res = static_link_list->Search(mr_cao, pos);
    if (!res) {
        cout << "Not found" << endl << endl;
    } else {
        cout << "位置: " << pos << endl;
    }

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-静态链表-删除**
 * @note
 * 测试-静态链表-删除
 * ----------------
 * ----------------
 *
 * ----------------
 * 声明static_link_list\n\n
 * 插入6个结点\n
 * 打印static_link_list\n\n
 * 删除2个结点\n
 * 打印static_link_list\n
 *
 *
 * ----------------
 */
void StaticLinkedListTest::TestRemove() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                Test StaticLinkedList Remove               |" << endl;
    cout << "|                     测试-静态链表-删除                    |" << endl << endl << endl;

    // 声明static_link_list
    StaticLinkedList<string>* static_link_list = new StaticLinkedList<string>(1);

    // 插入6个结点
    string str1("Cyber");
    string str2("Dash");
    string str3("Yuan");
    string str4("Lei");
    string str5("Yu");
    string str6("Cao");

    static_link_list->Insert(0, str1);
    static_link_list->Insert(1, str2);
    static_link_list->Insert(2, str3);
    static_link_list->Insert(3, str4);
    static_link_list->Insert(4, str5);
    static_link_list->Insert(5, str6);

    static_link_list->Print();

    // 删除2个结点
    string target_str;

    static_link_list->Remove(2, target_str);
    static_link_list->Remove(1, target_str);

    // 打印static_link_list
    cout << "删除前两个节点后:" << endl;

    static_link_list->Print();

    cout << "-------------------------------------------------------------" << endl << endl;
}


#endif // CYBER_DASH_STATIC_LINKED_LIST_TEST_H
