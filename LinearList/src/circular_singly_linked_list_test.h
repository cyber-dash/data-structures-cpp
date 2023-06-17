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
    // 测试-循环单链表-插入
    static void TestInsert();

    // 测试-循环单链表-清空
    static void TestClear();

    // 测试-循环单链表-删除结点
    static void TestRemove();

    // 测试-循环单链表-长度
    static void TestLength();

    // 测试-循环单链表-搜索
    static void TestSearch();
};


/*!
 * @brief **测试-循环单链表-插入**
 * @note
 * 测试-循环单链表-插入
 * -----------------
 * -----------------
 *
 * -----------------
 * 初始化band_list(乐队链表)\n
 * 依次插入5个乐队\n
 * 打印band_list\n
 *
 *
 * -----------------
 */
void CircularSinglyLinkedListTest::TestInsert() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|            Test CircularSinglyLinkedList Insert           |" << endl;
    cout << "|                    测试-循环单链表-插入                   |" << endl << endl << endl;

    // 初始化band_list(乐队链表)
    CircularSinglyLinkedList<string>* band_list = new CircularSinglyLinkedList<string>();

    // 依次插入5个乐队
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

    // 打印band_list
    band_list->Print();

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-循环单链表-清空**
 * @note
 * 测试-循环单链表-清空
 * -----------------
 * -----------------
 *
 * -----------------
 * 初始化band_list(乐队链表)\n\n
 * 依次插入5个乐队\n
 * 打印band_list\n\n
 * 清空乐队\n
 * 打印band_list\n
 *
 *
 * -----------------
 */
void CircularSinglyLinkedListTest::TestClear() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|             Test CircularSinglyLinkedList Clear           |" << endl;
    cout << "|                    测试-循环单链表-清空                   |" << endl << endl << endl;

    CircularSinglyLinkedList<string>* band_list = new CircularSinglyLinkedList<string>();

    string band1("The Script");
    string band2("Linkin Park");
    string band3("Queen");
    string band4("Coldplay");
    string band5("黑豹");

    band_list->Insert(0, band1);    // 插入"The Script"作为首结点
    band_list->Insert(0, band2);    // 插入"Linkin Park"作为首结点
    band_list->Insert(0, band3);    // 插入"Queen"作为首结点
    band_list->Insert(0, band4);    // 插入"Coldplay"作为首结点
    band_list->Insert(0, band5);    // 插入"黑豹"作为首结点

    cout << "乐队链表:" << endl;
    band_list->Print();

    band_list->Clear();

    cout << "清空后的乐队链表:" << endl;
    band_list->Print();

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-循环单链表-删除结点**
 * @note
 * 测试-循环单链表-删除结点
 * ---------------------
 * ---------------------
 *
 * ---------------------
 * 声明singer_list(歌手链表)\n\n
 * 依次插入5个歌手\n
 * 打印singer_list\n\n
 * 依次删除某个歌手并打印singer_list, 执行5次\n
 *
 *
 * ---------------------
 */
void CircularSinglyLinkedListTest::TestRemove() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|            Test CircularSinglyLinkedList Remove           |" << endl;
    cout << "|                  测试-循环单链表-删除结点                 |" << endl << endl << endl;

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


/*!
 * @brief **测试-循环单链表-长度**
 * @note
 * 测试-循环单链表-长度
 * -----------------
 * -----------------
 *
 * -----------------
 * 初始化singer_list(歌手链表)\n\n
 * 依次插入5个歌手\n
 * 打印singer_list\n
 * 打印singer_list长度\n
 *
 *
 * -----------------
 */
void CircularSinglyLinkedListTest::TestLength() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|            Test CircularSinglyLinkedList Length           |" << endl;
    cout << "|                    测试-循环单链表-长度                   |" << endl << endl << endl;

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


/*!
 * @brief **测试-循环单链表-搜索**
 * @note
 * 测试-循环单链表-搜索
 * -----------------
 * -----------------
 *
 * -----------------
 * 初始化singer_list(歌手链表)\n\n
 * 依次插入5个歌手\n
 * 打印"张雨生"结点和"莫文蔚"结点的地址\n
 *
 *
 * -----------------
 */
void CircularSinglyLinkedListTest::TestSearch() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|            Test CircularSinglyLinkedList Search           |" << endl;
    cout << "|                    测试-循环单链表-搜索                   |" << endl << endl << endl;

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
