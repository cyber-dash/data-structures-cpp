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
    // 测试插入结点
    static void TestInsert();

    // 测试清空链表
    static void TestClear();

    // 测试删除结点
    static void TestRemove();

    // 测试链表长度
    static void TestLength();

    // 测试搜索
    static void TestSearch();
};


void CircularSinglyLinkedListTest::TestInsert() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|             Test CircularSinglyLinkedList Insert          |" << endl;
    cout << "|                      测试循环单链表插入                     |" << endl << endl << endl;

    CircularSinglyLinkedList<string>* singer_list = new CircularSinglyLinkedList<string>();

    string singer1("The Script");
    string singer2("Linkin Park");
    string singer3("Starship");
    string singer4("Coldplay");
    string singer5("黑豹");

    singer_list->Insert(0, singer1);
    singer_list->Insert(1, singer2);
    singer_list->Insert(2, singer3);
    singer_list->Insert(3, singer4);
    singer_list->Insert(4, singer5);

    singer_list->Print();

    cout << "-------------------------------------------------------------" << endl << endl;
}


void CircularSinglyLinkedListTest::TestClear() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|             Test CircularSinglyLinkedList Clear           |" << endl;
    cout << "|                     测试循环单链表清空链表                   |" << endl << endl << endl;

    CircularSinglyLinkedList<string>* singer_list = new CircularSinglyLinkedList<string>();

    string singer1("The Script");
    string singer2("Linkin Park");
    string singer3("Queen");
    string singer4("Coldplay");
    string singer5("黑豹");

    singer_list->Insert(0, singer1);    // 插入"The Script"作为首结点
    singer_list->Insert(0, singer2);    // 插入"Linkin Park"作为首结点
    singer_list->Insert(0, singer3);    // 插入"Queen"作为首结点
    singer_list->Insert(0, singer4);    // 插入"Coldplay"作为首结点
    singer_list->Insert(0, singer5);    // 插入"黑豹"作为首结点

    cout << "歌手链表:" << endl;
    singer_list->Print();

    singer_list->Clear();

    cout << "清空后的歌手链表:" << endl;
    singer_list->Print();

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试循环单链表删除结点**
 */
void CircularSinglyLinkedListTest::TestRemove() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|            Test CircularSinglyLinkedList Remove           |" << endl;
    cout << "|                     测试循环单链表删除结点                   |" << endl << endl << endl;

    CircularSinglyLinkedList<string>* singer_list = new CircularSinglyLinkedList<string>();

    string singer1("Madonna");
    string singer2("张雨生");
    string singer3("杨坤");
    string singer4("戴佩妮");
    string singer5("莫文蔚");

    singer_list->Insert(0, singer1);
    singer_list->Insert(1, singer2);
    singer_list->Insert(2, singer3);
    singer_list->Insert(3, singer4);
    singer_list->Insert(4, singer5);
    cout<<"歌手链表:"<<endl;
    singer_list->Print();

    cout<<endl;

    string data;
    cout << "删除当前第2个结点: " << singer_list->GetNode(2)->data << endl;
    singer_list->Remove(2, data);
    singer_list->Print();

    cout << "删除当前第4个结点: " << singer_list->GetNode(4)->data << endl;
    singer_list->Remove(4, data);
    singer_list->Print();

    cout << "删除当前第2个结点: " << singer_list->GetNode(1)->data << endl;
    singer_list->Remove(1, data);
    singer_list->Print();

    cout << "删除当前第1个结点: " << singer_list->GetNode(2)->data << endl;
    singer_list->Remove(1, data);
    singer_list->Print();

    cout << "删除当前第1个(唯一1个)结点: " << singer_list->GetNode(1)->data << endl;
    singer_list->Remove(1, data);
    singer_list->Print();

    cout << "-------------------------------------------------------------" << endl << endl;
}


void CircularSinglyLinkedListTest::TestLength() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|            Test CircularSinglyLinkedList Length           |" << endl;
    cout << "|                      测试循环单链表长度                      |" << endl << endl << endl;

    CircularSinglyLinkedList<string>* singer_list = new CircularSinglyLinkedList<string>();

    string singer1("Madonna");
    string singer2("张雨生");
    string singer3("杨坤");
    string singer4("戴佩妮");
    string singer5("莫文蔚");

    singer_list->Insert(0, singer1);
    singer_list->Insert(1, singer2);
    singer_list->Insert(2, singer3);
    singer_list->Insert(3, singer4);
    singer_list->Insert(4, singer5);
    cout<<"歌手链表:"<<endl;
    singer_list->Print();

    cout<<endl;

    string data;
    cout << "链表长度: " << singer_list->Length()<< endl;

    cout << "-------------------------------------------------------------" << endl << endl;
}


void CircularSinglyLinkedListTest::TestSearch() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|            Test CircularSinglyLinkedList Search           |" << endl;
    cout << "|                      测试循环单链表搜索                      |" << endl << endl << endl;

    CircularSinglyLinkedList<string>* singer_list = new CircularSinglyLinkedList<string>();

    string singer1("Madonna");
    string singer2("张雨生");
    string singer3("杨坤");
    string singer4("戴佩妮");
    string singer5("莫文蔚");

    singer_list->Insert(0, singer1);
    singer_list->Insert(1, singer2);
    singer_list->Insert(2, singer3);
    singer_list->Insert(3, singer4);
    singer_list->Insert(4, singer5);
    cout<<"歌手链表:"<<endl;
    singer_list->Print();

    cout<<endl;

    string data;
    cout << "张雨生结点的地址: " << singer_list->Search(singer2)<< endl;
    cout << "莫文蔚结点的地址: " << singer_list->Search(singer5)<< endl;

    cout << "-------------------------------------------------------------" << endl << endl;
}

#endif // CYBER_DASH_CIRCULAR_SINGLY_LINKED_LIST_TEST_H
