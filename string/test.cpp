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

  CyberDashString string1("xwxwowxwoxxo");
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

  CyberDashString string1("aaaabcd56****abcd56abcd7777");
  CyberDashString string2("abcd56abcd7");
  CyberDashString string3("ababc");
  CyberDashString string4("bcd56abc");

  cout << string1.KMPFind(string2, 0) << endl;
  cout << string1.KMPFind(string3, 0) << endl;
  cout << string1.KMPFind(string4, 2) << endl;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void TestKMPFindCyberDash() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                    Test KMPFindCyberDash                  |"<<endl;
  cout<<"|                        测试KMP算法                         |"<<endl<<endl<<endl;

  CyberDashString string1("aaaabcd56****abcd56abcd7777");
  CyberDashString string2("abcd56abcd7");
  CyberDashString string3("ababc");
  CyberDashString string4("bcd56abc");

  cout << string1.KMPFindCyberDash(string2, 0) << endl;
  cout << string1.KMPFindCyberDash(string3, 0) << endl;
  cout << string1.KMPFindCyberDash(string4, 2) << endl;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}
