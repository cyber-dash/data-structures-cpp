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
    // 测试-双向链表-插入
    static void TestInsert();

    // 测试-双向链表-删除结点
    static void TestRemove();

    // 测试-双向链表-搜索
    static void TestSearch();

    // 测试-双向链表-长度
    static void TestLength();

    // 测试-双向链表-清空
    static void TestClear();
};


/*!
 * @brief **测试-双向链表-插入**
 * @note
 * 测试-双向链表-插入
 * ---------------
 * ---------------
 *
 * ---------------
 * 声明band_list(乐队链表)\n
 * 插入5个乐队名字\n
 * 打印band_list\n
 *
 *
 * ---------------
 */
void DoublyLinkedListTest::TestInsert() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                Test DoublyLinkedList Insert               |" << endl;
    cout << "|                      测试-双向链表-插入                     |" << endl << endl << endl;

    // 声明band_list(乐队链表)
    DoublyLinkedList<string>* band_list = new DoublyLinkedList<string>();

    // 插入5个乐队名字
    string band1("The Script");
    string band2("Linkin Park");
    string band3("Starship");
    string band4("Coldplay");
    string band5("黑豹");

    string bands[5] = { band1, band2, band3, band4, band5 };

    for (int i = 0; i < 5; i++) {
        band_list->Insert(i, bands[i]);
    }

    // 打印band_list
    band_list->Print();

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-双向链表-删除结点**
 * @note
 * 测试-双向链表-删除结点
 * -------------------
 * -------------------
 *
 * -------------------
 * 声明band_list(乐队链表)\n
 * 插入5个乐队名字\n
 * 打印band_list\n
 * 删除当前某个乐队, 并打印, 测试3次\n
 *
 *
 * -------------------
 */
void DoublyLinkedListTest::TestRemove() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                Test DoublyLinkedList Remove               |" << endl;
    cout << "|                    测试-双向链表-删除结点                    |" << endl << endl << endl;

    // 声明band_list(乐队链表)
    DoublyLinkedList<string>* band_list = new DoublyLinkedList<string>();

    // 插入5个乐队名字
    string band1("The Script");
    string band2("Linkin Park");
    string band3("Starship");
    string band4("Coldplay");
    string band5("黑豹");

    string bands[5] = { band1, band2, band3, band4, band5 };

    for (int i = 0; i < 5; i++) {
        band_list->Insert(i, bands[i]);
    }

    // 打印band_list
    band_list->Print();

    cout << endl;

    // 删除当前某个乐队, 并打印, 测试3次
    string target_band;
    band_list->Remove(1, target_band);
    cout << "删除当前第1个乐队后:" << endl;
    band_list->Print();
    band_list->Remove(4, target_band);
    cout << "删除当前第4个乐队后:" << endl;
    band_list->Print();
    band_list->Remove(2, target_band);
    cout << "删除当前第2个乐队后:" << endl;
    band_list->Print();

    cout << "-------------------------------------------------------------" << endl << endl;
}


// 测试双向链表搜索
/*!
 * @brief **测试-双向链表-搜索**
 * @note
 * 测试-双向链表-搜索
 * ----------------
 * ----------------
 *
 * ----------------
 * 初始化number_list(整形链表)\n
 * 依次插入1至5\n
 * 依次搜索1至5, 打印对应的结点的地址\n
 *
 * ----------------
 */
void DoublyLinkedListTest::TestSearch() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                Test DoublyLinkedList Search               |" << endl;
    cout << "|                      测试-双向链表-搜索                     |" << endl << endl << endl;

    // 初始化number_list(整形链表)
    DoublyLinkedList<int>* number_list = new DoublyLinkedList<int>();

    // 依次插入1至5
    for (int i = 1; i <= 5; i++) {
        int pos = i - 1;
        int data = i;
        number_list->Insert(pos, data);
    }

    // 依次搜索1至5, 打印对应的结点的地址
    for (int i = 1; i <= 5; i++) {
        DoublyLinkedNode<int>* addr_by_search = number_list->Search(i);
        DoublyLinkedNode<int>* addr_by_search_recursive = number_list->SearchRecursive(i);

        cout << "Search返回的" << i << "对应的结点地址: " << addr_by_search << endl;
        cout << "SearchRecursive返回的" << i << "对应的结点地址: " << addr_by_search_recursive << endl;
    }

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-双向链表-长度**
 * @note
 * 测试-双向链表-长度
 * ----------------
 * ----------------
 *
 * ----------------
 * 初始化number_list(整形链表)\n
 * 依次插入1至5\n
 * 打印链表长度\n
 *
 *
 * ----------------
 */
void DoublyLinkedListTest::TestLength() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                Test DoublyLinkedList Length               |" << endl;
    cout << "|                      测试-双向链表-长度                     |" << endl << endl << endl;

    // 初始化number_list(整形链表)
    DoublyLinkedList<int>* number_list = new DoublyLinkedList<int>();

    // 依次插入1至5
    for (int i = 1; i <= 5; i++) {
        int pos = i - 1;
        int data = i;
        number_list->Insert(pos, data);
    }

    // 打印链表长度
    cout << "链表长度: " << number_list->Length() << endl;

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-双向链表-清空**
 * @note
 * 测试-双向链表-清空
 * ----------------
 * ----------------
 *
 * ----------------
 * 初始化number_list\n\n
 * 依次插入1至5\n
 * 打印链表长度\n\n
 * 清空链表\n
 * 打印链表长度\n
 *
 *
 * ----------------
 */
void DoublyLinkedListTest::TestClear() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                 Test DoublyLinkedList Clear               |" << endl;
    cout << "|                      测试-双向链表-清空                     |" << endl << endl << endl;

    // 初始化number_list
    DoublyLinkedList<int>* number_list = new DoublyLinkedList<int>();

    // 依次插入1至5
    for (int i = 1; i <= 5; i++) {
        int pos = i - 1;
        int data = i;
        number_list->Insert(pos, data);
    }

    // 打印链表长度
    cout << "清空前链表长度: " << number_list->Length() << endl;

    // 清空链表
    number_list->Clear();

    // 打印链表长度
    cout << "清空后链表长度: " << number_list->Length() << endl;

    cout << "-------------------------------------------------------------" << endl << endl;
}


#endif // CYBER_DASH_DOUBLY_LINKED_LIST_TEST_H
