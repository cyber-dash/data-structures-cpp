//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/7/29.
//

#ifndef CYBER_DASH_YUAN_STRING_H
#define CYBER_DASH_YUAN_STRING_H


#include <iostream>


using namespace std;


const int DEFAULT_SIZE = 128;


class CyberDashString {

public:
  explicit CyberDashString(int size = DEFAULT_SIZE);
  explicit CyberDashString(const char* char_ptr);
  ~CyberDashString();

  int Length() const;
  CyberDashString operator() (int index, int len) const;
  bool operator == (const CyberDashString& cyber_dash_str) const;
  bool operator != (CyberDashString& cyber_dash_str) const;
  bool operator ! () const;
  CyberDashString& operator = (const CyberDashString& cyber_dash_str);
  CyberDashString& operator += (CyberDashString& cyber_dash_str);
  char& operator[] (int index);
  int BruteForceFind(CyberDashString& pattern, int offset) const;
  int KMPFind(CyberDashString& pattern, int offset) const;
  // int KMPFind_v2(CyberDashString& pattern, int offset) const;
  int KMPFindCyberDash(CyberDashString& pattern, int offset) const;

  friend ostream& operator<<(ostream& os, CyberDashString& cyber_dash_str) {
    os << cyber_dash_str.char_array_ << endl;
  }

  static void CyberDashShow();

private:
  char* char_array_;
  int length_;
  int max_size_;
  static int* KMPNext(const char* pattern, int pattern_len);
  static int* KMPNextByCyberDash(const char* pattern, int pattern_len);
  static void PrintNextArray(const int* next_arr_ptr, int next_arr_len);
};


#endif //CYBER_DASH_YUAN_STRING_H
