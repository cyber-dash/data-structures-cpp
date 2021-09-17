//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 8/23/2021.
//

#include "test.h"
#include "cyber_dash_string.h"


void TestBFFind() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                    Test BruteForceFind                    |"<<endl;
  cout<<"|                          测试BF算法                        |"<<endl<<endl<<endl;

  CyberDashString target_str("hand in hand we can, start to understand");
  CyberDashString pattern_str_1("hand");
  CyberDashString pattern_str_2("understand");

  cout << "目标串: " << target_str << endl << endl;
  cout << "模式串\"" << pattern_str_1 << "\"的匹配位置: " << target_str.BruteForceFind(pattern_str_1, 0) << endl;
  cout << "模式串\"" << pattern_str_2 << "\"的匹配位置: " << target_str.BruteForceFind(pattern_str_2, 0) << endl;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void TestKMPFind() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                        Test KMPFind                       |"<<endl;
  cout<<"|                         测试KMP算法                        |"<<endl<<endl<<endl;

  CyberDashString target_str("aaaabcd56****abcd56abcd7777");
  CyberDashString pattern_str_1("abcd56abcd7");
  CyberDashString pattern_str_2("ababc");
  CyberDashString pattern_str_3("bcd56abc");

  cout << "目标串: " << target_str << endl << endl;
  cout << "模式串\"" << pattern_str_1 << "\"的匹配位置: " << target_str.KMPFind(pattern_str_1, 0) << endl;
  cout << "模式串\"" << pattern_str_2 << "\"的匹配位置: " << target_str.KMPFind(pattern_str_2, 0) << endl;
  cout << "模式串\"" << pattern_str_3 << "\"的匹配位置: " << target_str.KMPFind(pattern_str_3, 0) << endl;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void TestKMPFindCyberDash() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                    Test KMPFindCyberDash                  |"<<endl;
  cout<<"|                         测试KMP算法                        |"<<endl<<endl<<endl;

  CyberDashString target_str("aaaabcd56****abcd56abcd7777");
  CyberDashString pattern_str_1("abcd56abcd7");
  CyberDashString pattern_str_2("ababc");
  CyberDashString pattern_str_3("bcd56abc");

  cout << "目标串: " << target_str << endl << endl;
  cout << "模式串\"" << pattern_str_1 << "\"的匹配位置: " << target_str.KMPFindCyberDash(pattern_str_1, 0) << endl;
  cout << "模式串\"" << pattern_str_2 << "\"的匹配位置: " << target_str.KMPFindCyberDash(pattern_str_2, 0) << endl;
  cout << "模式串\"" << pattern_str_3 << "\"的匹配位置: " << target_str.KMPFindCyberDash(pattern_str_3, 0) << endl;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}
