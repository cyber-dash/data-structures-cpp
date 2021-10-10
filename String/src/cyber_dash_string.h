/*!
 * @file cyber_dash_string.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 字符串匹配模板类
 * @version 0.2.1
 * @date 2021-07-29
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#ifndef CYBER_DASH_YUAN_STRING_H
#define CYBER_DASH_YUAN_STRING_H


#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;


const int DEFAULT_SIZE = 128;


/*!
 * @brief CyberDash字符串类
 */
class CyberDashString {

public:
  // 构造函数(字符串长度)
  CyberDashString(int size = DEFAULT_SIZE);
  /*! 构造函数 */
  CyberDashString(const char* char_ptr);
  /*! 析构函数 */
  ~CyberDashString() { delete[] char_array_; };

  int Length() const { return this->length_; };
  CyberDashString operator() (int index, int len) const;
  bool operator == (const CyberDashString& cyber_dash_str) const;
  bool operator != (CyberDashString& cyber_dash_str) const;
  bool operator ! () const;
  CyberDashString& operator = (const CyberDashString& cyber_dash_str);
  CyberDashString& operator += (CyberDashString& cyber_dash_str);
  char& operator[] (int index);

  // BF字符串匹配
  int BruteForceFind(CyberDashString& pattern, int offset) const;

  // KMP字符串匹配查找
  int KMPFind(CyberDashString& pattern, int offset) const;

  // KMP字符串匹配查找(使用KMPNextByCyberDash生成next数组)
  int KMPFindCyberDash(CyberDashString& pattern, int offset) const;

  // 重载<<
  friend ostream& operator<<(ostream& os, CyberDashString& cyber_dash_str) {
    os << cyber_dash_str.char_array_;
    return os;
  }

  static void CyberDashShow();

  static int* KMPNext(const char* pattern, int pattern_len);
  static int* KMPNextByCyberDash(const char* pattern, int pattern_len);
  static void PrintNextArray(const int* next_arr, int next_arr_len);

private:
  char* char_array_; //!< 字符串数组
  int length_; //!< 当前字符串长度
  int max_size_; //!< 最大长度
};


/*!
 * @brief 构造函数(字符串长度)
 * @param size 字符串最大长度
 */
CyberDashString::CyberDashString(int size) {

  max_size_ = size;

  char_array_ = new char[max_size_ + 1];
  if (char_array_ == NULL) {
    cerr<<"Allocation Error"<<endl;
    exit(1);
  }

  length_ = 0;
  // 先全部置0
  memset(char_array_, 0, sizeof(char) * (max_size_ + 1));
}


/*!
 * @brief 构造函数(字符串)
 * @param char_ptr 字符串
 */
CyberDashString::CyberDashString(const char* char_ptr) {
  int char_len = strlen(char_ptr);

  if (char_len > DEFAULT_SIZE) {
    max_size_ = char_len;
  } else {
    max_size_ = DEFAULT_SIZE;
  }

  char_array_ = new char[max_size_ + 1];
  if (char_array_ == NULL) {
    cerr<<"Allocation Error"<<endl;
    exit(1);
  }

  length_ = char_len;

  // 先全部置0
  memset(char_array_, 0, sizeof(char) * (max_size_ + 1));
  // 再复制字符串内容
  memcpy(char_array_, char_ptr, sizeof(char) * char_len);
}


/*!
 * @brief 重载()
 * @param index 起始index
 * @param offset 偏移量
 * @return 字符串
 */
CyberDashString CyberDashString::operator () (int index, int offset) const {

  CyberDashString ret_str(offset + 1);

  if (index < 0 || index + offset > max_size_ || offset <= 0 || index + 1 > length_) {

    ret_str.length_ = 0;
    ret_str.char_array_[0] = '\0';
  } else {

    if (index + offset > length_) {
      offset = length_ - index;
    }

    ret_str.length_ = offset;

    memcpy(ret_str.char_array_, char_array_ + index, sizeof(char) * offset);

    ret_str.char_array_[offset] = '\0';
  }

  return ret_str;
}


/*!
 * @brief 重载==
 * @param cyber_dash_str 字符串
 * @return 是否相同
 */
bool CyberDashString::operator == (const CyberDashString& cyber_dash_str) const {
  int cmp_res = strcmp(char_array_, cyber_dash_str.char_array_);
  if (cmp_res == 0) {
    return true;
  } else {
    return false;
  }
}


/*!
 * @brief 重载!=
 * @param cyber_dash_str 字符串
 * @return 是否不同
 */
bool CyberDashString::operator != (CyberDashString& cyber_dash_str) const {
  int cmp_res = strcmp(char_array_, cyber_dash_str.char_array_);
  if (cmp_res != 0) {
    return true;
  } else {
    return false;
  }
}


// todo
bool CyberDashString::operator ! () const {
  return true;
}


/*!
 * @brief 重载=
 * @param src_str 源字符串
 * @return 自身字符串
 */
CyberDashString& CyberDashString::operator = (const CyberDashString& src_str) {

  if (&src_str != this) {

    delete[] char_array_;

    char_array_ = new char[src_str.max_size_ + 1];
    if (char_array_ == NULL) {
      cerr<<"存储分配失败!"<<endl;
      exit(1);
    }

    memcpy(char_array_, src_str.char_array_, sizeof(char) * src_str.length_);

    length_ = src_str.length_;

  } else {
    cout<<"字符串自身赋值出错"<<endl;
  }

  return *this;
}


// todo
CyberDashString& CyberDashString::operator += (CyberDashString& cyber_dash_str) {
  return *this;
}


/*!
 * @brief 重载[]
 * @param index
 * @return
 */
char& CyberDashString::operator[] (int index) {
  if (index < 0 || index >= Length()) {
    cerr<<"Out of Range."<<endl;
    exit(1);
  }

  return char_array_[index];
}


/*!
 * @brief BF字符串匹配
 * @param pattern 模式串
 * @param offset 目标串的起始偏移量
 * @return 目标串中的匹配位置, -1为不匹配 / 其他为第一个匹配字符的数组索引值
 */
int CyberDashString::BruteForceFind(CyberDashString& pattern, int offset) const {

  int match_offset = -1;
  int pattern_idx;

  for (int i = offset; i <= length_ - pattern.length_; i++) {
    for (pattern_idx = 0; pattern_idx < pattern.length_; pattern_idx++) {
      if (char_array_[i + pattern_idx] != pattern[pattern_idx]) {
        break;
      }
    }

    if (pattern_idx == pattern.length_) {
      match_offset = i;
      break;
    }
  }

  return match_offset;
}


/*!
 * @brief 求模式串的next数组
 * @param pattern 模式串第一个字符串的指针
 * @param pattern_len 模式串长度
 * @return next数组起始地址
 */
int* CyberDashString::KMPNext(const char* pattern, int pattern_len) {

  // 分配next数组内存
  int* next = new int[pattern_len];
  if (next == NULL) {
    cerr<<"next array allocate error"<<endl;
    return NULL;
  }

  /// 设置next[0] = -1
  int i = 0;
  int starting_index = -1;

  next[0] = starting_index;

  while (i < pattern_len) {

    /// 使用next[0]处理next[1]
    /// 当模式串字符pattern[1]失配时, 必然从pattern[0]开始重新进行匹配, 因此next[1] = 0
    /// 此处逻辑可以和下面的pattern[i] == pattern[starting_index]分支逻辑合并
    /// 因此next[0] = -1
    /// 其余部分则相同(代码可以合并)
    if (starting_index == -1) {
      i++;
      starting_index++;
      next[i] = starting_index;
    }
      /// 使用next[i]求next[i + 1]
    else
    {
      /// 如果pattern[i]和pattern[starting_index]相同, 则左右两侧的相同字符串区域扩展
      /// 示例
      ///  a b c d 5 6 a b c d 7
      ///  a b
      ///              a b
      ///                  ^
      ///                  |
      ///
      ///
      /// i == 8, starting_index == 2
      /// pattern[8] == pattern[2] == 'c', 走if( == )分支:
      ///     8++ -> 9,
      ///     starting_index++ -> 3
      ///     next[9] == pattern[3]
      ///
      ///
      ///  a b c d 5 6 a b c d 7
      ///  a b c
      ///              a b c
      ///                    ^
      ///                    |
      ///
      if (pattern[i] == pattern[starting_index]) {
        i++;
        starting_index++;
        next[i] = starting_index;
      }
        /// 如果pattern[i]和pattern[starting_index]不同, 则使用next数组进行递归, 逐步验证
      else
      {
        starting_index = next[starting_index];
      }
    }
  }

  return next;
}


/*!
 * @brief 求模式串的next数组(CyberDash版本)
 * @param pattern 模式串第一个字符串的指针
 * @param pattern_len 模式串长度
 * @return next数组起始地址
 */
int* CyberDashString::KMPNextByCyberDash(const char* pattern, int pattern_len) {

  int* next = new int[pattern_len];
  if (next == NULL) {
    cerr<<"next array allocate error"<<endl;
    return NULL;
  }

  next[0] = -1;
  next[1] = 0;

  int i = 1;
  int starting_index = 0;

  while (i < pattern_len) {
    if (pattern[i] == pattern[starting_index]) {
      i++;
      starting_index++;
      next[i] = starting_index;
    } else {
      if (starting_index == 0) {
        i++;
        next[i] = starting_index;
      } else {
        starting_index = next[starting_index];
      }
    }
  }

  return next;
}


/*!
 * @brief 打印next数组
 * @param next_arr next数组
 * @param next_arr_len
 */
void CyberDashString::PrintNextArray(const int* next_arr, int next_arr_len) {
  /// 示例
  /// 模式字符串:  a b c d 5 6 a b c d 7
  /// next数组:  -1 0 0 0 0 0 0 1 2 3 4
  for (int i = 0; i < next_arr_len; i++) {
    cout << *(next_arr + i) << " ";
  }
  cout<<endl;
}


/*!
 * @brief KMP字符串匹配查找
 * @param pattern 模式串
 * @param offset 目标串的起始偏移量
 * @return 目标串中的匹配位置, -1为不匹配 / 其他为第一个匹配字符的数组索引值
 * @note
 */
int CyberDashString::KMPFind(CyberDashString& pattern, int offset) const {

  int pattern_len = pattern.Length();
  int* next = KMPNext(pattern.char_array_, pattern_len);
  if (next == NULL) {
    cerr<<"next array allocation error"<<endl;
    return -2; //
  }

  // cout<<"模式串: "<<pattern<<endl<<"对应的next数组: ";
  // PrintNextArray(next, pattern_len); // show the next array

  int pattern_str_i = 0;
  int target_str_i = offset;

  while (pattern_str_i < pattern_len && target_str_i < this->length_) {
    /// 如果模式串字符(位置pattern_str_i)和目标串字符(位置target_str_i)相同, 则向后移位
    if (pattern[pattern_str_i] == this->char_array_[target_str_i]) {
      pattern_str_i++;
      target_str_i++;
    }
      /// 如果模式串字符(位置pattern_str_i)和目标串字符(位置target_str_i)不同
    else
    {
      // 如果是模式串第1个字符不匹配, 则目标串向后移位
      if (pattern_str_i == 0) {
        target_str_i++;
      }
        // 如果不是模式串第1个字符不匹配, 则从模式串的next[pattern_str_i]开始执行下一趟匹配
      else
      {
        pattern_str_i = next[pattern_str_i];
      }
    }
  }

  delete[] next; // 删除next数组

  int match_pos;

  if (pattern_str_i < pattern_len) {
    match_pos = -1; // 不匹配
  } else {
    match_pos = target_str_i - pattern_len; // 算出目标串中匹配的第一个字符的(在目标串中的)位置
  }

  return match_pos;
}


/*!
 * @brief KMP字符串匹配查找(使用KMPNextByCyberDash生成next数组)
 * @param pattern 模式串
 * @param offset 目标串的起始偏移量
 * @return 目标串中的匹配位置, -1为不匹配 / 其他为第一个匹配字符的数组索引值
 * @note
 */
int CyberDashString::KMPFindCyberDash(CyberDashString& pattern, int offset) const {

  int match_pos;

  int pattern_len = pattern.Length();
  int* next = KMPNextByCyberDash(pattern.char_array_, pattern_len);
  // PrintNextArray(next, pattern_len);
  if (!next) {
    cerr<<"next array allocation error"<<endl;
    return -2;
  }

  int pattern_index = 0;
  int target_str_index = offset;

  while (pattern_index < pattern_len && target_str_index < length_) {
    if (pattern_index == -1 || pattern[pattern_index] == char_array_[target_str_index]) {
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


/*!
 * @brief 我们是CyberDash:-)
 */
void CyberDashString::CyberDashShow() {
  cout<<endl
      <<"*************************************** CyberDash ***************************************"<<endl<<endl
      <<"抖音号\"CyberDash计算机考研\", id: cyberdash_yuan"<<endl<<endl
      <<"CyberDash成员:"<<endl
      <<"元哥(cyberdash@163.com), "<<"北京邮电大学(通信工程本科)/北京邮电大学(信息与通信系统研究生)"<<endl
      <<"磊哥(alei_go@163.com), "<<"山东理工大学(数学本科)/北京邮电大学(计算机研究生)"<<endl<<endl
      <<"L_Dash(lyu2586@163.com), "<<"北京邮电大学(计算机在读研究生)"<<endl<<endl
      <<"数据结构开源代码(C++清华大学殷人昆)魔改升级版本: https://gitee.com/cyberdash/data-structure-cpp"<<endl
      <<endl<<"*************************************** CyberDash ***************************************"<<endl<<endl;
}


#endif //CYBER_DASH_YUAN_STRING_H
