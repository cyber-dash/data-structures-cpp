//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2021/2/24.
//

#include "test.h"
#include <iostream>


using namespace std;


void TestInsert() {
  cout<<endl;
  cout<<"************************* CyberDash *************************"<<endl;
  cout<<"*                     Test SeqList Insert                   *"<<endl;
  cout<<"*                        测试顺序表插入                       *"<<endl;
  cout<<"************************* CyberDash *************************"<<endl<<endl;

  SeqList<int> seq_list(3);

  int num1 = 1;
  int num2 = 2;
  int num3 = 3;

  seq_list.Insert(0, num1);
  seq_list.Insert(1, num2);
  seq_list.Insert(2, num3);

  seq_list.Output();
}


void TestRemove() {
  cout<<endl;
  cout<<"************************* CyberDash *************************"<<endl;
  cout<<"*                     Test SeqList Remove                   *"<<endl;
  cout<<"*                        测试顺序表删除                       *"<<endl;
  cout<<"************************* CyberDash *************************"<<endl<<endl;

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
}


void TestSize() {
  cout<<endl;
  cout<<"************************* CyberDash *************************"<<endl;
  cout<<"*                     Test SeqList Size                     *"<<endl;
  cout<<"*                       测试顺序表Size                        *"<<endl;
  cout<<"************************* CyberDash *************************"<<endl<<endl;

  SeqList<double> seq_list(3);

  cout<<"seq_list size: "<<seq_list.Size()<<endl;
}


void TestLength() {
  cout<<endl;
  cout<<"************************* CyberDash *************************"<<endl;
  cout<<"*                    Test SeqList Length                    *"<<endl;
  cout<<"*                      测试顺序表Length                       *"<<endl;
  cout<<"************************* CyberDash *************************"<<endl<<endl;

  SeqList<string> seq_list(3);

  cout<<"seq_list length: "<<seq_list.Length()<<endl;

  string BJ = "Beijing";
  string SH = "ShangHai";

  seq_list.Insert(0, BJ);
  seq_list.Insert(1, SH);

  cout<<"seq_list length: "<<seq_list.Length()<<endl;
}


void TestEmpty() {
  cout<<endl;
  cout<<"************************* CyberDash *************************"<<endl;
  cout<<"*                    Test SeqList Empty                     *"<<endl;
  cout<<"*                      测试顺序表Empty                       *"<<endl;
  cout<<"************************* CyberDash *************************"<<endl<<endl;

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
}


void TestSearch() {
  cout<<endl;
  cout<<"************************* CyberDash *************************"<<endl;
  cout<<"*                    Test SeqList Search                    *"<<endl;
  cout<<"*                        测试顺序表查找                       *"<<endl;
  cout<<"************************* CyberDash *************************"<<endl<<endl;

  SeqList<int> seq_list(3);

  int num1 = 1;
  int num2 = 2;
  int num3 = 3;

  seq_list.Insert(0, num1);
  seq_list.Insert(1, num2);
  seq_list.Insert(2, num3);

  int pos = seq_list.Search(num3);

  cout<<"The pos of "<<num3<<" is "<<pos<<endl;
}


void TestLocate() {
  cout<<endl;
  cout<<"************************* CyberDash *************************"<<endl;
  cout<<"*                    Test SeqList Locate                    *"<<endl;
  cout<<"*                       测试顺序表Locate                     *"<<endl;
  cout<<"************************* CyberDash *************************"<<endl<<endl;

  SeqList<double> seq_list(3);

  double num1 = 1.1;
  double num2 = 2.2;
  double num3 = 3.3;

  seq_list.Insert(0, num1);
  seq_list.Insert(1, num2);
  seq_list.Insert(2, num3);

  int pos = seq_list.Locate(2);

  cout<<"The pos is: "<<pos<<endl;
}


void TestGetData() {
  cout<<endl;
  cout<<"************************* CyberDash *************************"<<endl;
  cout<<"*                    Test SeqList GetData                   *"<<endl;
  cout<<"*                      测试顺序表GetData                     *"<<endl;
  cout<<"************************* CyberDash *************************"<<endl<<endl;

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
}


void TestSetData() {
  cout<<endl;
  cout<<"************************* CyberDash *************************"<<endl;
  cout<<"*                   Test SeqList SetData                    *"<<endl;
  cout<<"*                      测试顺序表SetData                     *"<<endl;
  cout<<"************************* CyberDash *************************"<<endl<<endl;

  SeqList<double> seq_list(3);

  seq_list.Insert(0, 1.1);
  seq_list.Insert(1, 2.2);
  seq_list.Insert(2, 3.3);

  seq_list.Output();

  seq_list.SetData(2, 4.4);

  seq_list.Output();
}


void TestCyberDashShow() {
  SeqList<int> seq_list(1);

  seq_list.CyberDashShow();
}


void TestSeqListUnion() {

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


void TestSeqListIntersection() {

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
