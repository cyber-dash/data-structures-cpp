//
// Created by svenlee on 2020/7/29.
//

#include <iostream>
#include "cyber_dash_string.h"


using namespace std;



int main() {

  // test Find
  CyberDashString pattern1("aab12aab12aab");
  CyberDashString pattern2("aab12aab12aab");
  CyberDashString pattern3("a");
  CyberDashString pattern4("xyz");
  CyberDashString pattern5("xyzzz");

  CyberDashString test_str6("12aab12aab12aabxyz");
  CyberDashString test_str7("12aab12aab12aabxyz");

  // test KMPFind
  int find_pos;
  find_pos = test_str6.KMPFind(pattern1, 0);
  cout<<"KMP find_pos1:"<<find_pos<<endl;
  find_pos = test_str6.KMPFind(pattern2, 0);
  cout<<"KMP find_pos2:"<<find_pos<<endl;
  find_pos = test_str6.KMPFind(pattern3, 0);
  cout<<"KMP find_pos3:"<<find_pos<<endl;
  find_pos = test_str6.KMPFind(pattern4, 0);
  cout<<"KMP find_pos4:"<<find_pos<<endl;
  find_pos = test_str6.KMPFind(pattern5, 0);
  cout<<"KMP find_pos5:"<<find_pos<<endl<<endl;

  // test KMPFind_minified
  find_pos = test_str7.KMPFind_minified(pattern1, 0);
  cout<<"KMP_minified find_pos1:"<<find_pos<<endl;
  find_pos = test_str7.KMPFind_minified(pattern2, 0);
  cout<<"KMP_minified find_pos2:"<<find_pos<<endl;
  find_pos = test_str7.KMPFind_minified(pattern3, 0);
  cout<<"KMP_minified find_pos3:"<<find_pos<<endl;
  find_pos = test_str7.KMPFind_minified(pattern4, 0);
  cout<<"KMP_minified find_pos4:"<<find_pos<<endl;
  find_pos = test_str6.KMPFind_minified(pattern5, 0);
  cout<<"KMP find_pos5:"<<find_pos<<endl<<endl;

  // CyberDashSHow
  test_str6.CyberDashShow();

  return 0;
}