//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 8/23/2021.
//

#include "test.h"
#include "cyber_dash_string.h"


void TestBFFind() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                        Test BF BruteForceFind                       |"<<endl;
  cout<<"|                          测试BF算法                        |"<<endl<<endl<<endl;

  CyberDashString string1("");
  CyberDashString string2("wo");
  CyberDashString string3("xx");

  cout << string1.BruteForceFind(string2, 0) << endl;
  cout << string1.BruteForceFind(string3, 0) << endl;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void TestKMPFind() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                        Test KMPFind                       |"<<endl;
  cout<<"|                          测试KMP算法                        |"<<endl<<endl<<endl;

  CyberDashString string1("xyzzz_12345_xyzzz");
  CyberDashString string2("xyz");
  CyberDashString string3("xx");
  CyberDashString string4("12345");

  cout << string1.KMPFind(string2, 0) << endl;
  cout << string1.KMPFind_minified(string3, 0) << endl;
  cout << string1.KMPFind_minified(string4, 2) << endl;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}
