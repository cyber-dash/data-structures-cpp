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
 * @brief 顺序表测试类
 */
class SeqListTest {
public:
  /*! @brief 测试插入 */
  static void TestInsert();
  /*! @brief 测试删除 */
  static void TestRemove();
  /*! @brief 测试总长度 */
  static void TestSize();
  /*! @brief 测试当前长度 */
  static void TestLength();
  /*! @brief 测试是否为空 */
  static void TestEmpty();
  /*! @brief 测试搜索 */
  static void TestSearch();
  /*! @brief 测试定位 */
  static void TestLocate();
  /*! @brief 测试获取数据 */
  static void TestGetData();
  /*! @brief 测试设置数据 */
  static void TestSetData();
  /*! @brief 测试排序 */
  static void TestSort();
  /*! @brief 测试两个顺序表并集 */
  static void TestUnion();
  /*! @brief 测试两个顺序表交集 */
  static void TestIntersection();
};


void SeqListTest::TestInsert() {
  cout<<endl;
  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<"                     Test SeqList Insert                     "<<endl;
  cout<<"                         测试顺序表插入                        "<<endl<<endl<<endl;

  SeqList<int> seq_list(3);

  int num1 = 1;
  int num2 = 2;
  int num3 = 3;

  seq_list.Insert(0, num1);
  seq_list.Insert(1, num2);
  seq_list.Insert(2, num3);

  seq_list.Output();

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void SeqListTest::TestRemove() {
  cout<<endl;
  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<"                     Test SeqList Remove                     "<<endl;
  cout<<"                         测试顺序表删除                         "<<endl<<endl<<endl;

  SeqList<int> seq_list(3);

  int num1 = 1;
  int num2 = 2;
  int num3 = 3;

  seq_list.Insert(0, num1);
  seq_list.Insert(1, num2);
  seq_list.Insert(2, num3);

  // 删除位置3(注意本实现是从1开始计数)的数据
  int delete_num;
  seq_list.Remove(3, delete_num);

  seq_list.Output();

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void SeqListTest::TestSize() {
  cout<<endl;
  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<"                      Test SeqList Size                      "<<endl;
  cout<<"                        测试顺序表Size                         "<<endl<<endl<<endl;

  SeqList<double> seq_list(3);

  cout<<"seq_list size: "<<seq_list.Size()<<endl;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void SeqListTest::TestLength() {
  cout<<endl;
  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<"                     Test SeqList Length                     "<<endl;
  cout<<"                       测试顺序表Length                        "<<endl<<endl<<endl;

  SeqList<string> seq_list(3);

  cout<<"seq_list length: "<<seq_list.Length()<<endl;

  string BJ = "Beijing";
  string SH = "ShangHai";

  seq_list.Insert(0, BJ);
  seq_list.Insert(1, SH);

  cout<<"seq_list length: "<<seq_list.Length()<<endl;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void SeqListTest::TestEmpty() {
  cout<<endl;
  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<"                     Test SeqList Empty                      "<<endl;
  cout<<"                        测试顺序表Empty                        "<<endl<<endl<<endl;

  SeqList<string> seq_list(3);

  cout<<"Before insert any string:"<<endl;

  bool isEmpty = seq_list.IsEmpty();
  if (isEmpty) {
    cout<<"The seq_list is empty."<<endl;
  } else {
    cout<<"The seq_list isn't empty."<<endl;
  }

  string BJ = "Beijing";
  seq_list.Insert(0, BJ);

  cout<<"After insert the string \"Beijing\":"<<endl;

  isEmpty = seq_list.IsEmpty();
  if (isEmpty) {
    cout<<"The seq_list is empty."<<endl;
  } else {
    cout<<"The seq_list isn't empty."<<endl;
  }

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void SeqListTest::TestSearch() {
  cout<<endl;
  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<"                     Test SeqList Search                     "<<endl;
  cout<<"                         测试顺序表查找                        "<<endl<<endl<<endl;

  SeqList<int> seq_list(3);

  int num1 = 1;
  int num2 = 2;
  int num3 = 3;

  seq_list.Insert(0, num1);
  seq_list.Insert(1, num2);
  seq_list.Insert(2, num3);

  int pos = seq_list.Search(num3);

  cout<<"The pos of "<<num3<<" is "<<pos<<endl;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void SeqListTest::TestLocate() {
  cout<<endl;
  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<"                     Test SeqList Locate                     "<<endl;
  cout<<"                        测试顺序表Locate                       "<<endl<<endl<<endl;

  SeqList<double> seq_list(3);

  double num1 = 1.1;
  double num2 = 2.2;
  double num3 = 3.3;

  seq_list.Insert(0, num1);
  seq_list.Insert(1, num2);
  seq_list.Insert(2, num3);

  int pos = seq_list.Locate(2);

  cout<<"The pos is: "<<pos<<endl;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void SeqListTest::TestGetData() {
  cout<<endl;
  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<"                     Test SeqList GetData                    "<<endl;
  cout<<"                       测试顺序表GetData                       "<<endl<<endl<<endl;

  SeqList<double> seq_list(3);

  double num1 = 1.1;
  double num2 = 2.2;
  double num3 = 3.3;

  seq_list.Insert(0, num1);
  seq_list.Insert(1, num2);
  seq_list.Insert(2, num3);

  double num_of_pos_1;
  seq_list.GetData(1, num_of_pos_1);

  cout<<"The num of pos 1 is: "<<num_of_pos_1<<endl;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void SeqListTest::TestSetData() {
  cout<<endl;
  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<"                     Test SeqList SetData                    "<<endl;
  cout<<"                       测试顺序表SetData                       "<<endl<<endl<<endl;

  SeqList<double> seq_list(3);

  cout<<"Init the seq list:"<<endl;

  seq_list.Insert(0, 1.1);
  seq_list.Insert(1, 2.2);
  seq_list.Insert(2, 3.3);

  seq_list.Output();

  cout<<endl;

  cout<<"Set the item of pos 2 to 4.4:"<<endl;

  seq_list.SetData(2, 4.4);

  seq_list.Output();

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void SeqListTest::TestSort() {

    cout<<endl;
    cout<<"------------------------- CyberDash -------------------------"<<endl;
    cout<<"                      Test SeqList Sort                      "<<endl;
    cout<<"                         测试顺序表Sort                        "<<endl<<endl<<endl;

    SeqList<double> seq_list(5);

    seq_list.Insert(0, 4.4);
    seq_list.Insert(1, 2.2);
    seq_list.Insert(2, 3.3);
    seq_list.Insert(3, 6.6);
    seq_list.Insert(4, 5.5);

    seq_list.Sort();

    seq_list.Output();

    cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void SeqListTest::TestUnion() {

  cout<<endl;
  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<"                      Test SeqList Union                     "<<endl;
  cout<<"                        测试顺序表Union                        "<<endl<<endl<<endl;

  SeqList<int> seq_list_a(10);
  SeqList<int> seq_list_b(10);

  seq_list_a.Insert(0, 1);
  seq_list_a.Insert(1, 3);
  seq_list_a.Insert(2, 5);

  seq_list_b.Insert(0, 2);
  seq_list_b.Insert(1, 4);
  seq_list_b.Insert(2, 6);

  SeqListUnion(seq_list_a, seq_list_b);

  seq_list_a.Output();

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void SeqListTest::TestIntersection() {

  cout<<endl;
  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<"               Test SeqList SeqListIntersection              "<<endl;
  cout<<"                         测试顺序表交集                        "<<endl<<endl<<endl;

  SeqList<int> seq_list_a(10);
  SeqList<int> seq_list_b(10);

  seq_list_a.Insert(0, 1);
  seq_list_a.Insert(1, 2);
  seq_list_a.Insert(2, 3);

  seq_list_b.Insert(0, 2);
  seq_list_b.Insert(1, 4);
  seq_list_b.Insert(2, 6);

  SeqListIntersection(seq_list_a, seq_list_b);

  seq_list_a.Output();

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


#endif // CYBER_DASH_SEq_LIST_TEST_H
