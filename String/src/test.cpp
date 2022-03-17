/*!
 * @file test.cpp
 * @author CyberDash���������, cyberdash@163.com(����id:cyberdash_yuan)
 * @brief �ַ���ƥ�����.cpp�ļ�
 * @version 0.2.1
 * @date 2021-08-23
 * @copyright Copyright (c) 2021
 *  CyberDash���������
 */

#include "test.h"
#include "cyber_dash_string.h"


/*! ����BF�㷨 */
void TestBFFind() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                    Test BruteForceFind                    |"<<endl;
  cout<<"|                          ����BF�㷨                        |"<<endl<<endl<<endl;

  CyberDashString target_str("hand in hand we can, start to understand");
  CyberDashString pattern_str_1("hand");
  CyberDashString pattern_str_2("understand");

  cout << "Ŀ�괮: " << target_str << endl << endl;
  cout << "ģʽ��\"" << pattern_str_1 << "\"��ƥ��λ��: " << target_str.BruteForceFind(pattern_str_1, 0) << endl;
  cout << "ģʽ��\"" << pattern_str_2 << "\"��ƥ��λ��: " << target_str.BruteForceFind(pattern_str_2, 0) << endl;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


/*! ����KMP�㷨 */
void TestKMPFind() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                        Test KMPFind                       |"<<endl;
  cout<<"|                         ����KMP�㷨                        |"<<endl<<endl<<endl;

  CyberDashString target_str("aaaabcd56****abcd56abcd7777");
  CyberDashString pattern_str_1("abcd56abcd7");
  CyberDashString pattern_str_2("ababc");
  CyberDashString pattern_str_3("bcd56abc");

  cout << "Ŀ�괮: " << target_str << endl << endl;
  cout << "ģʽ��\"" << pattern_str_1 << "\"��ƥ��λ��: " << target_str.KMPFind(pattern_str_1, 0) << endl;
  cout << "ģʽ��\"" << pattern_str_2 << "\"��ƥ��λ��: " << target_str.KMPFind(pattern_str_2, 0) << endl;
  cout << "ģʽ��\"" << pattern_str_3 << "\"��ƥ��λ��: " << target_str.KMPFind(pattern_str_3, 0) << endl;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


/*! ����KMP(CyberDash�汾)�㷨 */
void TestKMPFindCyberDash() {

  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                    Test KMPFindCyberDash                  |"<<endl;
  cout<<"|                         ����KMP�㷨                        |"<<endl<<endl<<endl;

  CyberDashString target_str("aaaabcd56****abcd56abcd7777");
  CyberDashString pattern_str_1("abcd56abcd7");
  CyberDashString pattern_str_2("ababc");
  CyberDashString pattern_str_3("bcd56abc");

  cout << "Ŀ�괮: " << target_str << endl << endl;
  cout << "ģʽ��\"" << pattern_str_1 << "\"��ƥ��λ��: " << target_str.KMPFindCyberDash(pattern_str_1, 0) << endl;
  cout << "ģʽ��\"" << pattern_str_2 << "\"��ƥ��λ��: " << target_str.KMPFindCyberDash(pattern_str_2, 0) << endl;
  cout << "ģʽ��\"" << pattern_str_3 << "\"��ƥ��λ��: " << target_str.KMPFindCyberDash(pattern_str_3, 0) << endl;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}
