//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/7/29.
//

#include <iostream>
#include <cstdlib>
// #include <string.h>
#include "cyber_dash_string.h"


using namespace std;


CyberDashString::CyberDashString(int size) {

  max_size_ = size;

  char_ptr_ = new char[max_size_ + 1];
  if (char_ptr_ == NULL) {
    cerr<<"Allocation Error"<<endl;
    exit(1);
  }

  length_ = 0;
  char_ptr_[0] = '\0';
}


CyberDashString::CyberDashString(const char* char_ptr) {
  int char_len = strlen(char_ptr);

  if (char_len > DEFAULT_SIZE) {
    max_size_ = char_len;
  } else {
    max_size_ = DEFAULT_SIZE;
  }

  char_ptr_ = new char[max_size_ + 1];
  if (char_ptr_ == NULL) {
    cerr<<"Allocation Error"<<endl;
    exit(1);
  }

  length_ = char_len;

  memcpy(char_ptr_, char_ptr, char_len);
}


CyberDashString::~CyberDashString() {
  delete[] char_ptr_;
}


int CyberDashString::Length() const {
  return length_;
}


CyberDashString CyberDashString::operator () (int index, int offset) const {

  CyberDashString ret_str(offset + 1);

  if (index < 0 || index + offset > max_size_ || offset <= 0 || index + 1 > length_) {

    ret_str.length_ = 0;
    ret_str.char_ptr_[0] = '\0';
  } else {

    if (index + offset > length_) {
      offset = length_ - index;
    }

    ret_str.length_ = offset;

    memcpy(ret_str.char_ptr_, char_ptr_ + index, offset);

    ret_str.char_ptr_[offset] = '\0';
  }

  return ret_str;
}


bool CyberDashString::operator == (const CyberDashString& cyber_dash_str) const {
  int cmp_res = strcmp(char_ptr_, cyber_dash_str.char_ptr_);
  if (cmp_res == 0) {
    return true;
  } else {
    return false;
  }
}


bool CyberDashString::operator != (CyberDashString& cyber_dash_str) const {
  int cmp_res = strcmp(char_ptr_, cyber_dash_str.char_ptr_);
  if (cmp_res != 0) {
    return true;
  } else {
    return false;
  }
}


bool CyberDashString::operator ! () const {
  return true;
}


CyberDashString& CyberDashString::operator = (const CyberDashString& src_str) {

  if (&src_str != this) {

    delete[] char_ptr_;

    char_ptr_ = new char[src_str.max_size_ + 1];
    if (char_ptr_ == NULL) {
      cerr<<"存储分配失败!"<<endl;
      exit(1);
    }

    memcpy(char_ptr_, src_str.char_ptr_, src_str.length_);

    length_ = src_str.length_;

  } else {
    cout<<"字符串自身赋值出错"<<endl;
  }

  return *this;
}


CyberDashString& CyberDashString::operator += (CyberDashString& cyber_dash_str) {
  return *this;
}


char& CyberDashString::operator[] (int index) {
  if (index < 0 || index >= Length()) {
    cerr<<"Out of Range."<<endl;
    exit(1);
  }

  return char_ptr_[index];
}


int CyberDashString::BruteForceFind(CyberDashString& pattern, int offset) const {

  int match_offset = -1;
  int pat_idx;

  for (int i = offset; i <= length_ - pattern.length_; i++) {
    for (pat_idx = 0; pat_idx < pattern.length_; pat_idx++) {
      if (char_ptr_[i + pat_idx] != pattern[pat_idx]) {
        break;
      }
    }

    if (pat_idx == pattern.length_) {
      match_offset = i;
      break;
    }
  }

  return match_offset;
}


int* CyberDashString::KMPNext(char* pattern, int pattern_len) {

  int index = 0;
  int starting_index = -1;

  int* next = new int[pattern_len];
  if (!next) {
    cerr<<"next array allocate error"<<endl;
    return NULL;
  }

  next[0] = starting_index;

  while (index < pattern_len) {
    if (starting_index == -1) {
      index++;
      starting_index = 0;
      next[index] = starting_index;
    } else {
      if (pattern[index] == pattern[starting_index]) {
        index++;
        starting_index++;
        next[index] = starting_index;
      } else {
        starting_index = next[starting_index];
        index++;
      }
    }
  }

  return next;
}


int* CyberDashString::KMPNext_v2(char* pattern, int pattern_len) {

  int* next = new int[pattern_len];
  if (!next) {
    cerr<<"next array allocate error"<<endl;
    return NULL;
  }
  next[0] = -1;
  next[1] = 0;

  int index = 1;
  int starting_index = 0;

  while (index < pattern_len) {
    if (pattern[index] == pattern[starting_index]) {
      index++;
      starting_index++;
      next[index] = starting_index;
    } else {
      if (starting_index == 0) {
        next[index] = starting_index;
      } else {
        starting_index = next[starting_index];
      }

      index++;
    }
  }

  return next;
}


int CyberDashString::KMPFind(CyberDashString& pattern, int offset) const {

  int match_pos;

  int pattern_len = pattern.Length();
  //int* next = KMPNext_v2(pattern.char_ptr_, pattern_len);
  int* next = KMPNext(pattern.char_ptr_, pattern_len);
  if (!next) {
    cerr<<"next array allocation error"<<endl;
    return -2;
  }

  int pattern_index = 0;
  int target_str_index = offset;

  while (pattern_index < pattern_len && target_str_index < length_) {
    if (pattern[pattern_index] == char_ptr_[target_str_index]) {
      pattern_index++;
      target_str_index++;
    } else {
      if (pattern_index == 0) {
        target_str_index++;
      } else {
        pattern_index = next[pattern_index];
      }
    }
  }

  delete[] next;

  if (pattern_index < pattern_len) {
    match_pos = -1;
  } else {
    match_pos = target_str_index - pattern_len;
  }

  return match_pos;
}


int CyberDashString::KMPFind_minified(CyberDashString& pattern, int offset) const {

  int match_pos;

  int pattern_len = pattern.Length();
  int* next = KMPNext(pattern.char_ptr_, pattern_len);
  if (!next) {
    cerr<<"next array allocation error"<<endl;
    return -2;
  }

  int pattern_index = 0;
  int target_str_index = offset;

  while (pattern_index < pattern_len && target_str_index < length_) {
    if (pattern_index == -1 || pattern[pattern_index] == char_ptr_[target_str_index]) {
      pattern_index++;
      target_str_index++;
    } else {
      pattern_index = next[pattern_index];
    }
  }

  delete[] next;

  if (pattern_index < pattern_len) {
    match_pos = -1;
  } else {
    match_pos = target_str_index - pattern_len;
  }

  return match_pos;
}


void CyberDashString::CyberDashShow() {
  cout<<endl
      <<"*************************************** CyberDash ***************************************"<<endl<<endl
      <<"抖音号\"CyberDash计算机考研\", id: cyberdash_yuan"<<endl<<endl
      <<"CyberDash成员:"<<endl
      <<"元哥(cyberdash@163.com), "<<"北京邮电大学(通信工程本科)/北京邮电大学(信息与通信系统研究生)"<<endl
      <<"磊哥(alei_go@163.com), "<<"山东理工大学(数学本科)/北京邮电大学(计算机研究生)"<<endl<<endl
      <<"数据结构开源代码(C++清华大学殷人昆)魔改升级版本: https://gitee.com/cyberdash/data-structure-cpp"<<endl
      <<endl<<"*************************************** CyberDash ***************************************"<<endl<<endl;
}
