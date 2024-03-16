/*!
 * @file seq_list_test.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 顺序表测试类
 * @version 0.2.1
 * @date 2021-09-28
 * @copyright Copyright (c) 2021
 * **CyberDash计算机考研**
 */

#ifndef CYBER_DASH_SEQ_LIST_TEST_H
#define CYBER_DASH_SEQ_LIST_TEST_H

#include "seq_list.h"
#include "seq_list_algorithm.h"


using namespace std;


/*!
 * @brief **顺序表测试类**
 */
class SeqListTest {
public:
    // 测试-顺序表-插入
    static void TestInsert();

    // 测试-顺序表-复制构造
    static void TestCopyConstructor();

    // 测试-顺序表-删除
    static void TestRemove();

    // 测试-顺序表-容量
    static void TestCapacity();

    // 测试-顺序表-长度
    static void TestLength();

    // 测试-顺序表-Empty
    static void TestEmpty();

    // 测试-顺序表-查找
    static void TestSearch();

    // 测试-顺序表-获取结点数据
    static void TestGetData();

    // 测试-顺序表-设置结点数据
    static void TestSetData();

    // 测试-顺序表-排序
    static void TestSort();

    // 测试-顺序表-合并
    static void TestUnion();

    // 测试-顺序表-交集
    static void TestIntersection();

    // 测试-顺序表-operator=
    static void TestOperatorAssignment();
};


/*!
 * @brief **测试-顺序表-插入**
 * @note
 * 测试-顺序表-插入
 * -------------
 * -------------
 *
 * -------------
 * 声明seq_list(顺序表)\n\n
 * 位置0后边插入1(插入首位置)\n
 * 位置1后边插入2\n
 * 位置2后边插入3\n\n
 * 打印seq_list\n
 *
 *
 * -------------
 */
void SeqListTest::TestInsert() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                    Test SeqList Insert                    |" << endl;
    cout << "|                       测试-顺序表-插入                       |" << endl << endl << endl;

    SeqList<int> seq_list(3);                                   // 声明seq_list(顺序表)

    seq_list.Insert(0, 1);                                      // 位置0后边插入1(插入首位置)
    seq_list.Insert(1, 2);                                      // 位置1后边插入2
    seq_list.Insert(2, 3);                                      // 位置2后边插入3

    seq_list.Print();                                           // 打印seq_list

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-顺序表-复制构造**
 * @note
 * 测试-顺序表-复制构造
 * -----------------
 * -----------------
 *
 * -----------------
 * 声明seq_list(顺序表)\n\n
 * 位置0后边插入1(插入首位置)\n
 * 位置1后边插入2\n
 * 位置2后边插入3\n\n
 * 使用seq_list初始化seq_list_2\n\n
 * 打印seq_list_2\n
 *
 *
 * -----------------
 */
void SeqListTest::TestCopyConstructor() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                Test SeqList CopyConstructor               |" << endl;
    cout << "|                     测试-顺序表-复制构造                     |" << endl << endl << endl;

    SeqList<int> seq_list(3);                                   // 声明seq_list(顺序表)

    seq_list.Insert(0, 1);                                      // 位置0后边插入1(插入首位置)
    seq_list.Insert(1, 2);                                      // 位置1后边插入2
    seq_list.Insert(2, 3);                                      // 位置2后边插入3

    SeqList<int> seq_list_2 = seq_list;                         // 使用seq_list初始化seq_list_2

    seq_list_2.Print();                                         // 打印seq_list_2

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-顺序表-删除**
 * @note
 * 测试-顺序表-删除
 * --------------
 * --------------
 *
 * --------------
 * 声明seq_list(顺序表)\n\n
 * 位置0后边插入1(插入首位置)\n
 * 位置1后边插入2\n
 * 位置2后边插入3\n\n
 * 删除位置3的元素\n\n
 * 打印seq_list\n
 *
 *
 * --------------
 */
void SeqListTest::TestRemove() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                    Test SeqList Remove                    |" << endl;
    cout << "|                       测试-顺序表-删除                       |" << endl << endl << endl;

    SeqList<int> seq_list(3);                                       // 声明seq_list(顺序表)

    seq_list.Insert(0, 1);                                          // 位置0后边插入1(插入首位置)
    seq_list.Insert(1, 2);                                          // 位置1后边插入2
    seq_list.Insert(2, 3);                                          // 位置2后边插入3

    int target_num;
    seq_list.Remove(3, target_num);                                 // 删除位置3的元素

    seq_list.Print();                                               // 打印seq_list

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-顺序表-容量**
 * @note
 * 测试-顺序表-容量
 * --------------
 * --------------
 *
 * --------------
 * 声明seq_list(顺序表), 容量设置为3\n\n
 * 打印容量\n
 *
 *
 * --------------
 */
void SeqListTest::TestCapacity() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                   Test SeqList Capacity                   |" << endl;
    cout << "|                       测试-顺序表-容量                       |" << endl << endl << endl;

    SeqList<double> seq_list(3);                                                    // 声明seq_list(顺序表), 容量设置为3

    cout << "seq_list capacity: " << seq_list.Capacity() << endl << endl;           // 打印容量

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-顺序表-长度**
 * @note
 * 测试-顺序表-长度
 * --------------
 * --------------
 *
 * --------------
 * 声明seq_list(顺序表), 容量设置为3\n
 * 打印长度\n\n
 * 插入两个结点\n
 * 打印长度\n\n
 *
 *
 * --------------
 */
void SeqListTest::TestLength() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                    Test SeqList Length                    |" << endl;
    cout << "|                       测试-顺序表-长度                       |" << endl << endl << endl;

    // 声明seq_list(顺序表), 容量设置为3
    SeqList<string> seq_list(3);

    // 打印长度
    cout << "seq_list length: " << seq_list.Length() << endl;

    // 插入两个结点

    string BJ = "Beijing";
    string SH = "ShangHai";

    seq_list.Insert(0, BJ);
    seq_list.Insert(1, SH);

    // 打印长度
    cout << "seq_list length: " << seq_list.Length() << endl;

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-顺序表-Empty**
 * @note
 * 测试-顺序表-Empty
 * ---------------
 * ---------------
 *
 * ---------------
 * 声明seq_list(顺序表)\n
 * 打印seq_list是否为空表\n\n
 * 插入1个元素\n
 * 打印seq_list是否为空表\n\n
 *
 *
 * ---------------
 */
void SeqListTest::TestEmpty() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                     Test SeqList Empty                    |" << endl;
    cout << "|                      测试-顺序表-Empty                      |" << endl << endl << endl;

    // 声明seq_list(顺序表)
    SeqList<string> seq_list(3);

    // 打印seq_list是否为空表
    cout << "Before inserting any string:" << endl;

    bool isEmpty = seq_list.IsEmpty();
    if (isEmpty) {
        cout << "The seq_list is empty." << endl;
    } else {
        cout << "The seq_list isn't empty." << endl;
    }

    // 插入1个元素
    string BJ = "Beijing";
    seq_list.Insert(0, BJ);

    cout << endl << "After inserting the string \"Beijing\":" << endl;

    // 打印seq_list是否为空表
    isEmpty = seq_list.IsEmpty();
    if (isEmpty) {
        cout << "The seq_list is empty." << endl;
    } else {
        cout << "The seq_list isn't empty." << endl;
    }

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-顺序表-查找**
 * @note
 * 测试-顺序表-查找
 * --------------
 * --------------
 *
 * --------------
 * 声明seq_list(顺序表)\n\n
 * 位置0后边插入1(插入首位置)\n
 * 位置1后边插入2\n
 * 位置2后边插入3\n\n
 * 搜索3的位置\n
 * 打印结果\n\n
 * 搜索4的位置\n
 * 打印结果\n\n
 *
 *
 * --------------
 */
void SeqListTest::TestSearch() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                    Test SeqList Search                    |" << endl;
    cout << "|                       测试-顺序表-查找                       |" << endl << endl << endl;

    SeqList<int> seq_list(3);                                               // 声明seq_list(顺序表)

    seq_list.Insert(0, 1);                                                  // 位置0后边插入1(插入首位置)
    seq_list.Insert(1, 2);                                                  // 位置1后边插入2
    seq_list.Insert(2, 3);                                                  // 位置2后边插入3

    int pos = seq_list.Search(3);                                           // 搜索3的位置
    cout << "The pos of " << 3 << " is " << pos << endl;                    // 打印结果

    pos = seq_list.Search(4);                                               // 搜索1的位置
    cout << "The pos of " << 1 << " is " << pos << endl;                    // 打印结果

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-顺序表-获取结点数据**
 * @note
 * 测试-顺序表-获取结点数据
 * ---------------------
 * ---------------------
 *
 * ---------------------
 * 声明seq_list(顺序表)\n\n
 * 位置0后边插入1.1(插入首位置)\n
 * 位置1后边插入2.2\n
 * 位置2后边插入3.3\n\n
 * 获取first_node_data(位置1结点的data)\n
 * 打印first_node_data\n
 *
 *
 * --------------
 */
void SeqListTest::TestGetData() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                    Test SeqList Search                    |" << endl;
    cout << "|                    测试-顺序表-获取结点数据                   |" << endl << endl << endl;

    SeqList<double> seq_list(3);                                                // 声明seq_list(顺序表)

    seq_list.Insert(0, 1.1);                                                    // 位置0后边插入1.1(插入首位置)
    seq_list.Insert(1, 2.2);                                                    // 位置1后边插入2.2
    seq_list.Insert(2, 3.3);                                                    // 位置2后边插入3.3

    double first_node_data;
    seq_list.GetData(1, first_node_data);                                       // 获取first_node_data(位置1结点的data)

    cout << "The num of pos 1 is: " << first_node_data << endl;                 // 打印first_node_data

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-顺序表-设置结点数据**
 * @note
 * 测试-顺序表-设置结点数据
 * ---------------------
 * ---------------------
 *
 * ---------------------
 * 声明seq_list(顺序表)\n\n
 * 位置0后边插入1.1(插入首位置)\n
 * 位置1后边插入2.2\n
 * 位置2后边插入3.3\n\n
 * 打印first_node_data\n\n
 * 位置2结点数据设置为4.4\n
 * 打印first_node_data\n
 *
 *
 * --------------
 */
void SeqListTest::TestSetData() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                    Test SeqList SetData                   |" << endl;
    cout << "|                    测试-顺序表-设置结点数据                   |" << endl << endl << endl;

    SeqList<double> seq_list(3);                                                // 声明seq_list(顺序表)

    cout << "初始化顺序表:" << endl;

    seq_list.Insert(0, 1.1);                                                    // 位置0后边插入1.1(插入首位置)
    seq_list.Insert(1, 2.2);                                                    // 位置1后边插入2.2
    seq_list.Insert(2, 3.3);                                                    // 位置2后边插入3.3

    seq_list.Print();                                                           // 打印first_node_data

    cout << endl;

    cout << "位置2的结点数据设置为4.4:" << endl;
    seq_list.SetData(2, 4.4);                                                   // 位置2结点数据设置为4.4
    seq_list.Print();                                                           // 打印first_node_data

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-顺序表-排序**
 * @note
 * 测试-顺序表-排序
 * --------------
 * --------------
 *
 * --------------
 * 声明seq_list(顺序表)\n
 * 依次插入4.4, 2.2, 3.3, 6.6, 5.5\n\n
 * 执行排序\n
 * 打印seq_list\n
 */
void SeqListTest::TestSort() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                     Test SeqList Sort                     |" << endl;
    cout << "|                       测试-顺序表-排序                       |" << endl << endl << endl;

    // 声明seq_list(顺序表)
    SeqList<double> seq_list(5);

    // 依次插入4.4, 2.2, 3.3, 6.6, 5.5
    seq_list.Insert(0, 4.4);
    seq_list.Insert(1, 2.2);
    seq_list.Insert(2, 3.3);
    seq_list.Insert(3, 6.6);
    seq_list.Insert(4, 5.5);

    // 执行排序
    seq_list.Sort();

    // 打印seq_list
    seq_list.Print();

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-顺序表-合并**
 * @note
 * 测试-顺序表-合并
 * --------------
 * --------------
 *
 * --------------
 * 声明seq_list_a(顺序表a)\n
 * 声明seq_list_b(顺序表b)\n\n
 * seq_list_a依次插入1, 3, 5\n
 * seq_list_b依次插入2, 4, 6\n\n
 * 合并seq_list_a和seq_list_b, 结果保存在seq_list_a\n\n
 * 打印seq_list_a\n
 */
void SeqListTest::TestUnion() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                     Test SeqList Union                    |" << endl;
    cout << "|                       测试-顺序表-合并                       |" << endl << endl << endl;

    // 声明seq_list_a(顺序表a) ,seq_list_b(顺序表b)
    SeqList<int> seq_list_a(10);
    SeqList<int> seq_list_b(10);

    // seq_list_a依次插入1, 3, 5
    seq_list_a.Insert(0, 1);
    seq_list_a.Insert(1, 3);
    seq_list_a.Insert(2, 5);

    // seq_list_b依次插入2, 4, 6
    seq_list_b.Insert(0, 2);
    seq_list_b.Insert(1, 4);
    seq_list_b.Insert(2, 6);

    // 合并seq_list_a和seq_list_b, 结果保存在seq_list_a
    SeqListUnion(seq_list_a, seq_list_b);

    // 打印seq_list_a
    seq_list_a.Print();

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-顺序表-交集**
 * @note
 * 测试-顺序表-交集
 * --------------
 * --------------
 *
 * --------------
 * 声明seq_list_a(顺序表a)\n
 * 声明seq_list_b(顺序表b)\n\n
 * seq_list_a依次插入1, 2, 3\n
 * seq_list_b依次插入2, 4, 6\n\n
 * 求seq_list_a和seq_list_b的交集, 结果保存在seq_list_a\n\n
 * 打印seq_list_a\n
 */
void SeqListTest::TestIntersection() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                 Test SeqList Intersection                 |" << endl;
    cout << "|                       测试-顺序表-交集                       |" << endl << endl << endl;

    // 声明seq_list_a(顺序表a)
    SeqList<int> seq_list_a(10);
    // 声明seq_list_b(顺序表b)
    SeqList<int> seq_list_b(10);

    // seq_list_a依次插入1, 2, 3
    seq_list_a.Insert(0, 1);
    seq_list_a.Insert(1, 2);
    seq_list_a.Insert(2, 3);

    // seq_list_b依次插入2, 4, 6
    seq_list_b.Insert(0, 2);
    seq_list_b.Insert(1, 4);
    seq_list_b.Insert(2, 6);

    // 求seq_list_a和seq_list_b的交集, 结果保存在seq_list_a
    SeqListIntersection(seq_list_a, seq_list_b);

    // 打印seq_list_a
    seq_list_a.Print();

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-顺序表-operator=**
 * @note
 * 测试-顺序表-交集
 * --------------
 * --------------
 *
 * --------------
 *
 */
void SeqListTest::TestOperatorAssignment() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                  Test SeqList operator=                   |" << endl;
    cout << "|                     测试-顺序表-oprator=                    |" << endl << endl << endl;

    // 声明seq_list(顺序表)
    SeqList<double> seq_list(5);

    // 依次插入4.4, 2.2, 3.3, 6.6, 5.5
    seq_list.Insert(0, 4.4);
    seq_list.Insert(1, 2.2);
    seq_list.Insert(2, 3.3);
    seq_list.Insert(3, 6.6);
    seq_list.Insert(4, 5.5);

    SeqList<double> new_seq_list(1);

    // 使用operator=进行变量赋值
    new_seq_list = seq_list;

    // 打印new_seq_list
    new_seq_list.Print();

    cout << "-------------------------------------------------------------" << endl << endl;
}


#endif // CYBER_DASH_SEq_LIST_TEST_H
