/*!
 * @file test.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 广义表测试.cpp文件
 * @version 0.2.1
 * @date 2021-05-19
 *
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#include "test.h"

void TestCreateListByString() {

}

void TestHeadAndTail() {

}


void TestDepth() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                 Test GeneralizedList Depth                |"<<endl;
  cout<<"|                        测试广义表深度                       |"<<endl<<endl<<endl;

  string gen_list_string1 = "A(#);";
  string gen_list_string2 = "A(a,b);";
  string gen_list_string3 = "A(B(C(#)));";
  string gen_list_string4 = "E(B(a),D(B(a)));";

  GenList<char> gen_list1;
  GenList<char> gen_list2;
  GenList<char> gen_list3;
  GenList<char> gen_list4;

  gen_list1.CreateListByString(gen_list_string1);
  gen_list2.CreateListByString(gen_list_string2);
  gen_list3.CreateListByString(gen_list_string3);
  gen_list4.CreateListByString(gen_list_string4);

  cout<<"\""<<gen_list_string1<<"\""<<" depth: "<<gen_list1.Depth()<<endl;
  cout<<"\""<<gen_list_string2<<"\""<<" depth: "<<gen_list2.Depth()<<endl;
  cout<<"\""<<gen_list_string3<<"\""<<" depth: "<<gen_list3.Depth()<<endl;
  cout<<"\""<<gen_list_string4<<"\""<<" depth: "<<gen_list4.Depth()<<endl;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void TestLength() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                Test GeneralizedList Length                |"<<endl;
  cout<<"|                        测试广义表长度                       |"<<endl<<endl<<endl;

  string gen_list_string1 = "A(#);";
  // string gen_list_string1_1 = "A(a);";

  // string gen_list_string2 = "A(a,b);";
  // string gen_list_string2_1 = "A(a,B(a));";
  // string gen_list_string2_2 = "A(a,B(#));";
  // string gen_list_string2_3 = "E(B(#),D(F(#)));";
  string gen_list_string2_3 = "E(B(#), D(#));";
  // string gen_list_string2_3 = "E(B(#));";
  // string gen_list_string2_6 = "E(B(C(a)),D(a));";
  

  // GenList<char> gen_list1;
  // GenList<char> gen_list1_1;

  // GenList<char> gen_list2;
  // GenList<char> gen_list2_1;
  // GenList<char> gen_list2_2;
  GenList<char> gen_list2_3;
  // GenList<char> gen_list2_6;

  /*
  gen_list1.CreateListByString(gen_list_string1);
  gen_list1_1.CreateListByString(gen_list_string1_1);

  gen_list2.CreateListByString(gen_list_string2);
  gen_list2_1.CreateListByString(gen_list_string2_1);
   */
  // gen_list2_2.CreateListByString(gen_list_string2_2);
  gen_list2_3.CreateListByString(gen_list_string2_3);
  // gen_list2_6.CreateListByString(gen_list_string2_6);

  // cout<<"\""<<gen_list_string1<<"\""<<" length: "<<gen_list1.Length()<<endl;//1
  // cout<<"\""<<gen_list_string1_1<<"\""<<" length: "<<gen_list1_1.Length()<<endl;//1

  // cout<<"\""<<gen_list_string2<<"\""<<" length: "<<gen_list2.Length()<<endl;//2
  // cout<<"\""<<gen_list_string2_1<<"\""<<" length: "<<gen_list2_1.Length()<<endl;//2
  // cout<<"\""<<gen_list_string2_2<<"\""<<" length: "<<gen_list2_2.Length()<<endl;//2
  cout<<"\""<<gen_list_string2_3<<"\""<<" length: "<<gen_list2_3.Length()<<endl;//2
  // cout<<"\""<<gen_list_string2_6<<"\""<<" length: "<<gen_list2_6.Length()<<endl;//2

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}
