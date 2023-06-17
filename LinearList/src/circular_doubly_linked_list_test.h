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
    // 测试-循环双向链表-按方向插入
    static void TestInsert();

    // 测试-循环双向链表-按方向删除
    static void TestRemove();

    // 测试-循环双向链表-长度
    static void TestLength();

    // 测试-循环双向链表-是否为空
    static void TestEmpty();

    // 测试-循环双向链表-搜索
    static void TestSearch();

    // 测试-双向循环链表-获取结点
    static void TestGetNode();
};


/*!
 * @brief **测试-循环双向链表-按方向插入**
 * @note
 * 测试-循环双向链表-按方向插入
 * ------------------------
 * ------------------------
 *
 * ------------------------
 * 声明band_list(乐队链表)\n
 * 依次插入5个乐队\n
 * 打印band_list\n
 *
 *
 * ------------------------
 */
void CircularDoublyLinkedListTest::TestInsert() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|       Test CircularDoublyLinkedList InsertByDirection     |" << endl;
    cout << "|                测试-循环双向链表-按方向插入               |" << endl << endl << endl;

    CircularDoublyLinkedList<string>* band_list = new CircularDoublyLinkedList<string>();

    string band1("The Script");
    string band2("Linkin Park");
    string band3("Starship");
    string band4("Coldplay");
    string band5("黑豹");

    band_list->Insert(0, band1);
    band_list->Insert(0, band2);
    band_list->Insert(0, band3);
    band_list->Insert(0, band4);
    band_list->Insert(0, band5);

    band_list->Print();

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-循环双向链表-按方向删除**
 * @note
 * 测试-循环双向链表-按方向删除
 * ------------------------
 * ------------------------
 *
 * ------------------------
 * 声明city_list(城市链表)\n
 * 依次插入6个城市\n
 * 打印city_list\n
 * 测试2次删除结点\n
 *
 *
 * ------------------------
 */
void CircularDoublyLinkedListTest::TestRemove() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|       Test CircularDoublyLinkedList RemoveByDirection     |" << endl;
    cout << "|                测试-循环双向链表-按方向删除               |" << endl << endl << endl;

    CircularDoublyLinkedList<string>* city_list = new CircularDoublyLinkedList<string>();

    city_list->Insert(0, "北京");
    city_list->Insert(1, "上海");
    city_list->Insert(2, "广州");
    city_list->Insert(3, "深圳");
    city_list->Insert(4, "成都");
    city_list->Insert(5, "珠海");

    city_list->Print();

    string delete_item;

    int step = 2;
    city_list->RemoveByDirection(step, delete_item, CircularDoublyLinkedList<int>::FORWARD_DIRECTION);

    cout << endl << "向后删除, 首结点城市" << step << "个结点之后的城市: " << endl;
    city_list->Print();

    step = 0;
    city_list->RemoveByDirection(step, delete_item, CircularDoublyLinkedList<int>::FORWARD_DIRECTION);

    cout << "向后删除, 首结点城市" << step << "个结点之后的城市: " << endl;
    city_list->Print();

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-循环双向链表-长度**
 * @note
 * 测试-循环双向链表-长度
 * -------------------
 * -------------------
 *
 * -------------------
 * 声明double_list\n
 * 依次插入3个结点\n
 * 打印double_list长度\n
 *
 *
 * -------------------
 */
void CircularDoublyLinkedListTest::TestLength() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|             Test CircularDoublyLinkedList Length          |" << endl;
    cout << "|                   测试-循环双向链表-长度                  |" << endl << endl << endl;

    CircularDoublyLinkedList<int>* double_list;
    double_list = new CircularDoublyLinkedList<int>();

    double_list->Insert(0, 1);
    double_list->Insert(1, 2);
    double_list->Insert(2, 3);

    cout << "双向链表长度: " << double_list->Length() << endl;

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-双向链表-IsEmpty(是否为空)**
 * @note
 * 测试-双向链表-IsEmpty(是否为空)
 * ----------------------------
 * ----------------------------
 *
 * <span style="color:#d40000">
 * |------------------------ CyberDash ------------------------|\n
 * Test CircularDoublyLinkedList IsEmpty\n
 * 测试双向链表是否为空\n\n
 * Before inserting any string: \n
 * The city_list is empty. \n\n
 * After inserting "Beijing": \n
 * The city_list isn't empty. \n
 * -------------------------------------------------------------\n
 * </span>
 *
 * ----------------------------
 * + **1 初始化city_list(城市列表)**\n\n
 * + **2 测试空链表IsEmpty()结果**\n
 * 调用IsEmpty(), 结果为is_empty\n
 * **if** is_empty == true :\n
 * &emsp; 打印"is empty"的文本\n
 * **else** \n
 * &emsp; 打印"isn't empty"的文本\n\n
 * + **3 测试非空链表IsEmpty()结果**\n
 * 向city_list中插入北京"Beijing"\n\n
 * 调用IsEmpty(), 结果为is_empty\n
 * **if** is_empty == true :\n
 * &emsp; 打印"is empty"的文本\n
 * **else** \n
 * &emsp; 打印"isn't empty"的文本\n
 */
void CircularDoublyLinkedListTest::TestEmpty() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|             Test CircularDoublyLinkedList Empty           |" << endl;
    cout << "|                 测试-循环双向链表-是否为空                |" << endl << endl << endl;

    // ---------- 1 初始化city_list(城市列表) ----------

    CircularDoublyLinkedList<string>* city_list = new CircularDoublyLinkedList<string>();

    // ---------- 2 测试空链表IsEmpty()结果 ----------

    cout << "Before inserting any string:" << endl;

    bool is_empty = city_list->IsEmpty();                                                   // 调用IsEmpty(), 结果为is_empty
    if (is_empty) {                                                                         // if is_empty == true
        cout << "The city_list is empty." << endl;                                          // 打印"is empty"的文本
    } else {                                                                                // else
        cout << "The city_list isn't empty." << endl;                                       // 打印"isn't empty"的文本
    }
    cout << endl;

    // ---------- 3 测试非空链表IsEmpty()结果 ----------

    string BJ = "Beijing";
    city_list->Insert(0, BJ);                                                               // 向city_list中插入北京"Beijing"

    cout << "After inserting \"Beijing\":" << endl;

    is_empty = city_list->IsEmpty();                                                        // 调用IsEmpty(), 结果为is_empty
    if (is_empty) {                                                                         // if is_empty == true
        cout << "The city_list is empty." << endl;                                          // 打印"is empty"的文本
    } else {                                                                                // else
        cout << "The city_list isn't empty." << endl;                                       // 打印"isn't empty"的文本
    }

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-循环双向链表-搜索**
 * @note
 * 测试-循环双向链表-搜索
 * -------------------
 * -------------------
 *
 * -------------------
 * 声明double_list\n
 * 依次插入1,2,3\n
 * 取1和3对应的结点地址\n
 * 打印结点地址\n
 *
 *
 * -------------------
 */
void CircularDoublyLinkedListTest::TestSearch() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|            Test CircularDoublyLinkedList Search           |" << endl;
    cout << "|                   测试-循环双向链表-搜索                  |" << endl << endl << endl;

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


/*!
 * @brief **测试-双向循环链表-获取结点**
 * @note
 * 测试-双向循环链表-获取结点
 * ----------------------
 * ----------------------
 *
 * ----------------------
 * 声明circular_doubly_linked_list\n
 * 依次插入6个结点\n
 * 取位置1, 4, 7, 0的结点\n
 * 打印结点的信息\n
 *
 *
 * ----------------------
 */
void CircularDoublyLinkedListTest::TestGetNode() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|            Test CircularDoublyLinkedList GetNode          |" << endl;
    cout << "|                 测试-双向循环链表-获取结点                |" << endl << endl << endl;

    CircularDoublyLinkedList<int>* circular_doubly_linked_list = new CircularDoublyLinkedList<int>();

    circular_doubly_linked_list->Insert(0, 1);
    circular_doubly_linked_list->Insert(1, 2);
    circular_doubly_linked_list->Insert(2, 3);
    circular_doubly_linked_list->Insert(3, 4);
    circular_doubly_linked_list->Insert(4, 5);
    circular_doubly_linked_list->Insert(5, 5);
    circular_doubly_linked_list->Insert(6, 7);

    CircularDoublyLinkedNode<int>* pos1_node = circular_doubly_linked_list->GetNode(1);
    CircularDoublyLinkedNode<int>* pos4_node = circular_doubly_linked_list->GetNode(4);
    CircularDoublyLinkedNode<int>* pos7_node = circular_doubly_linked_list->GetNode(7);
    CircularDoublyLinkedNode<int>* pos0_node = circular_doubly_linked_list->GetNode(0);

    cout << "Get position 1 node, node->data: " << pos1_node->data << endl;
    cout << "Get position 4 node, node->data: " << pos4_node->data << endl;
    cout << "Get position 7 node, node->data: " << pos7_node->data << endl;
    cout << "Get position 0 node, node->data: " << pos0_node->data << endl;

    cout<<"-------------------------------------------------------------"<<endl<<endl;
}


#endif // CYBER_DASH_DOUBLE_LINK_LIST_TEST_H
