/*!
 * @file test.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 字符串匹配测试.cpp文件
 * @version 0.2.1
 * @date 2021-08-23
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#include "test.h"
#include "cyber_dash_string.h"


/*! 测试BF算法 */
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


/*! 测试KMP算法 */
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


/*! 测试KMP(CyberDash版本)算法 */
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
