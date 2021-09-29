//
// Created by Zhongyuan.Li on 9/29/2021.
//

#ifndef CYBER_DASH_DOUBLE_LINK_LIST_TEST_H
#define CYBER_DASH_DOUBLE_LINK_LIST_TEST_H


/*!
 * @brief 双向链表测试类
 */
class DoubleLinkListTest {
public:
  /*! @brief 测试插入 */
  static void TestInsert();

  static void TestRemove();
  /*! @brief 测试长度 */
  static void TestLength();

  static void TestEmpty();

  static void TestSearch();

  static void TestLocate();
};


void DoubleLinkListTest::TestInsert() {

  cout<<endl;
  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<"                    Test DoubleList Insert                   "<<endl;
  cout<<"                         测试双向链表插入                        "<<endl<<endl<<endl;

  DoubleLinkList<int>* double_list;
  double_list = new DoubleLinkList<int>();


  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void DoubleLinkListTest::TestRemove() {

  cout<<endl;
  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<"               Test DoubleList Remove              "<<endl;
  cout<<"                         测试双向链表删除                        "<<endl<<endl<<endl;



  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void DoubleLinkListTest::TestLength(){

  cout<<endl;
  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<"               Test DoubleList Length              "<<endl;
  cout<<"                         测试双向链表长度                       "<<endl<<endl<<endl;



  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void DoubleLinkListTest::TestEmpty(){

  cout<<endl;
  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<"               Test DoubleList Empty              "<<endl;
  cout<<"                         测试双向链表是否为空                        "<<endl<<endl<<endl;



  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void DoubleLinkListTest::TestSearch(){

  cout<<endl;
  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<"               Test DoubleList Search              "<<endl;
  cout<<"                         测试双向链表查找                        "<<endl<<endl<<endl;



  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void DoubleLinkListTest::TestLocate(){

  cout<<endl;
  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<"               Test DoubleList Locate              "<<endl;
  cout<<"                         测试双向链表Locate                        "<<endl<<endl<<endl;



  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


#endif // CYBER_DASH_DOUBLE_LINK_LIST_TEST_H
