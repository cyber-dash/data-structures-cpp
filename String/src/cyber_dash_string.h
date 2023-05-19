/*!
 * @file cyber_dash_string.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 字符串匹配模板类
 * @version 0.2.1
 * @date 2021-07-29
 */

#ifndef CYBER_DASH_STRING_H
#define CYBER_DASH_STRING_H


#include <iostream>
#include <cstdlib>


using namespace std;


const size_t DEFAULT_SIZE = 128;


/*!
 * @brief **字符串类**
 * @note
 * 字符串类
 * -------
 * -------
 *
 * -------
 */
class String {
public:
    explicit String(size_t size = DEFAULT_SIZE);                            // 构造函数(字符串长度)
    explicit String(const char* mem_data);                                  // 构造函数(字符串数组)
    String(const String& str);                                              // 复制构造函数
    ~String() { delete[] mem_data_; }                                       // 析构函数

    /*!
     * @brief **长度**
     * @return 长度
     */
    int Length() const { return this->length_; }

    /*!
     * @brief **最大长度**
     * @return 最大长度
     */
    size_t Size() const { return this->size_; }

    const char& operator[](size_t index) const;                             // 重载[]
    char& operator[](size_t index);                                         // 重载[]
    String& operator=(const String& src_str);                               // 重载=
    String& operator+=(String& str);                                        // 重载+=
    friend ostream& operator<<(ostream& os, const String& str);             // 重载<<
    friend bool operator==(const String& str1, const String& str2);         // 重载==
    friend bool operator!=(const String& str1, const String& str2);         // 重载!=
    friend bool operator<(const String& str1, const String& str2);          // 重载<
    friend bool operator<=(const String& str1, const String& str2);         // 重载<=
    friend bool operator>(const String& str1, const String& str2);          // 重载>
    friend bool operator>=(const String& str1, const String& str2);         // 重载>=

    int BruteForceMatch(const String& pattern, int offset) const;           // BF字符串匹配
    int KmpMatchByCyberdash(const String& pattern, int offset) const;       // KMP字符串匹配查找
    int KmpMatch(const String& pattern, int offset) const;                  // KMP字符串匹配查找(使用KMPNextByCyberDash生成的next数组)

    int* KmpNext() const;                                                   // 求next数组
    int* KmpNextByCyberDash() const;                                        // 求next数组(CyberDash版)

private:
    char* mem_data_;                                                        //!< **字符串数组**
    int length_;                                                            //!< **当前字符串长度**
    size_t size_;                                                           //!< **最大长度**
};


/*!
 * @brief **构造函数(最大长度)**
 * @param size 字符串最大长度
 * @note
 * 构造函数(最大长度)
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 设置属性**\n
 * 设置size_\n
 * 设置length_\n\n
 * + **2 设置mem_data_**\n
 * mem_data_分配内存并初始化\n
 * **if** 内存分配失败 :\n
 * &emsp; 抛出bad_alloc()\n\n
 * mem_data_数据置0\n
 */
String::String(size_t size) {

    // ---------- 1 设置属性 ----------

    this->size_ = size;                                                         // 设置size_
    this->length_ = 0;                                                          // 设置length_

    // ---------- 2 设置mem_data_ ----------

    this->mem_data_ = new char[size + 1];                                       // mem_data_分配内存并初始化
    if (!this->mem_data_) {                                                     // if 内存分配失败
        throw bad_alloc();                                                      // 抛出bad_alloc()
    }

    memset(this->mem_data_, 0, sizeof(char) * (this->size_ + 1));               // mem_data_数据置0
}


/*!
 * @brief **构造函数(字符串)**
 * @param mem_data 字符串
 * @note
 * 构造函数(字符串)
 * --------------
 * --------------
 *
 * --------------
 */
String::String(const char* mem_data) {
    size_t str_len = strlen(mem_data);

    if (str_len > DEFAULT_SIZE) {
        this->size_ = str_len;
    } else {
        this->size_ = DEFAULT_SIZE;
    }

    this->mem_data_ = new char[this->size_ + 1];
    if (!this->mem_data_) {
        throw bad_alloc();
    }

    this->length_ = (int)str_len;

    memset(this->mem_data_, 0, sizeof(char) * (this->size_ + 1));       // 先全部置0
    memcpy(this->mem_data_, mem_data, sizeof(char) * str_len);          // 再复制字符串内容
}


/*!
 * @brief **复制构造函数**
 * @param str 源字符串
 * @note
 * 复制构造函数
 * ----------
 * ----------
 *
 * ----------
 * + **1 自身函数处理**\n
 * **if** 复制自身 :\n
 * &emsp; 退出函数\n\n
 * + **2 复制**\n
 * 设置length_\n
 * 设置size_\n\n
 * mem_data_分配内存并初始化\n
 * **if** 内存分配失败 :\n
 * &emsp; 抛出bad_alloc()\n\n
 * **for loop** 遍历源字符串 :\n
 * &emsp; 设置mem_data_[i]\n
 * mem_data_[this->Length()]置'\0'\n
 */
String::String(const String& str) {

    // ---------- 1 自身函数处理 ----------

    if (&str == this) {                                                                 // if 复制自身
        return;                                                                         // 退出函数
    }

    // ---------- 2 复制 ----------

    this->length_ = str.Length();                                                       // 设置length_
    this->size_ = str.Size();                                                           // 设置size_

    this->mem_data_ = new char[str.Length() + 1];                                       // mem_data_分配内存并初始化
    if (!this->mem_data_) {                                                             // if 内存分配失败
        throw bad_alloc();                                                              // 抛出bad_alloc()
    }

    for (int i = 0; i < str.Length(); i++) {                                            // for loop 遍历源字符串
        this->mem_data_[i] = str[i];                                                    // 设置mem_data_[i]
    }
    this->mem_data_[this->Length()] = '\0';                                             // mem_data_[this->Length()]置'\0'
}


/*!
 * @brief **重载=**
 * @param src_str 源字符串
 * @return 自身字符串
 * @note
 * **重载=**
 * --------
 * --------
 *
 * 与复制构造函数基本相同
 *
 * --------
 */
String& String::operator=(const String& src_str) {

    if (&src_str == this) {
        return *this;
    }

    if (!this->mem_data_) {
        delete[] this->mem_data_;
    }

    this->length_ = src_str.Length();

    this->mem_data_ = new char[src_str.Length() + 1];
    if (!mem_data_) {
        throw bad_alloc();
    }

    for (int i = 0; i < src_str.Length(); i++) {
        this->mem_data_[i] = src_str[i];
    }
    this->mem_data_[this->Length()] = '\0';

    return *this;
}


/*!
 * @brief **重载+=**
 * @param str 字符串
 * @return 新字符串
 * @note
 * 重载+=
 * -----
 * -----
 *
 * -----
 * + **1 拼接空字符串处理**\n
 * **if** 拼接空字符串 :\n
 * &emsp; 返回自身\n\n
 * + **2 执行**\n
 * 初始化new_length为字符串拼接后的长度\n
 * **if** 当前字符串Size() >= 拼接后的字符串长度 :\n
 * &emsp; **for loop** 遍历str :\n
 * &emsp;&emsp; mem_data_[i + this->Length()] = str[i]\n
 * &emsp; mem_data_[new_length]置'\0'\n
 * **else**\n
 * &emsp; 分配内存并初始化new_mem_data(新的字符数组)\n\n
 * &emsp; **for loop** 遍历当前字符串 :\n
 * &emsp;&emsp; 设置new_mem_data[i]\n\n
 * &emsp; **for loop** 遍历str :\n
 * &emsp;&emsp; 设置new_mem_data[Length() + i]\n
 * &emsp; new_mem_data[new_length]置'\0'\n\n
 * &emsp; 释放this->mem_data_\n
 * &emsp; this->mem_data_指向new_mem_data\n\n
 * 更新length_\n
 * 更新size_\n
 * + **3 返回自身**\n
 * 返回*this\n
 */
String& String::operator+=(String& str) {

    // ---------- 1 拼接空字符串处理 ----------

    if (str.Length() == 0) {                                                    // if 拼接空字符串
        return *this;                                                           // 返回自身
    }

    // ---------- 2 执行 ----------

    int new_length = this->Length() + str.Length();                             // 初始化new_length为字符串拼接后的长度
    if ((int)this->Size() >= new_length) {                                      // if 当前字符串Size() >= 拼接后的字符串长度
        for (int i = 0; i < str.Length(); i++) {                                // for loop 遍历str
            this->mem_data_[i + this->Length()] = str[i];                       // mem_data_[i + this->Length()] = str[i]
        }
        this->mem_data_[new_length] = '\0';                                     // mem_data_[new_length]置'\0'
    } else {                                                                    // else
        char* new_mem_data = new char[new_length + 1];                          // 分配内存并初始化new_mem_data(新的字符数组)

        for (int i = 0; i < this->Length(); i++) {                              // for loop 遍历当前字符串
            new_mem_data[i] = this->operator[](i);                              // 设置new_mem_data[i]
        }

        for (int i = 0; i < str.Length(); i++) {                                // for loop 遍历str
            new_mem_data[this->Length() + i] = str[i];                          // 设置new_mem_data[Length() + i]
        }
        new_mem_data[new_length] = '\0';                                        // new_mem_data[new_length]置'\0'

        delete[] this->mem_data_;                                               // 释放this->mem_data_
        this->mem_data_ = new_mem_data;                                         // this->mem_data_指向new_mem_data
    }

    this->length_ = new_length;                                                 // 更新length_
    this->size_ = new_length;                                                   // 更新size_

    // ---------- 3 返回自身 ----------

    return *this;                                                               // 返回*this
}


/*!
 * @brief **重载[]**
 * @param index 索引
 * @return 字符
 * @note
 * 重载[]
 * -----
 * -----
 *
 * -----
 * **if** 索引值 >= 字符串长度 :\n
 * &emsp; 抛出异常\n\n
 * 返回mem_data_[index]\n
 */
char& String::operator[] (size_t index) {
    if ((int)index >= Length()) {                                               // if 索引值 >= 字符串长度
        throw exception("Out of Range");                                        // 抛出异常
    }

    return this->mem_data_[index];                                              // 返回mem_data_[index]
}


/*!
 * @brief **重载[]**
 * @param str1 字符串1
 * @param str2 字符串2
 * @return 结果
 * @note
 * 重载[]
 * -----
 * -----
 *
 * -----
 */
const char& String::operator[] (size_t index) const {
    if ((int)index >= Length()) {
        throw exception("Out of Range");
    }

    return this->mem_data_[index];
}


/*!
 * @brief **重载<&lt;**
 * @param str1 字符串1
 * @param str2 字符串2
 * @return 结果
 * @note
 * 重载<<
 * -----
 * -----
 *
 * -----
 */
ostream& operator<<(ostream& os, const String& str) {
    os << str.mem_data_;
    return os;
}


/*!
 * @brief **重载==**
 * @param str1 字符串1
 * @param str2 字符串2
 * @return 结果
 * @note
 * 重载==
 * -----
 * -----
 *
 * -----
 */
bool operator==(const String& str1, const String& str2) {
    if (str1.Length() != str2.Length()) {
        return false;
    }

    for (int i = 0; i < str1.Length(); i++) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }

    return true;
}


/*!
 * @brief **重载!=**
 * @param str1 字符串1
 * @param str2 字符串2
 * @return 结果
 * @note
 * 重载!=
 * -----
 * -----
 *
 * -----
 */
bool operator!=(const String& str1, const String& str2) {
    return !(str1 == str2);
}


/*!
 * @brief **重载>**
 * @param str1 字符串1
 * @param str2 字符串2
 * @return 结果
 * @note
 * 重载>
 * -----
 * -----
 *
 * -----
 */
bool operator>(const String& str1, const String& str2) {
    size_t size = str1.Size() >= str2.Size() ? str1.Size() : str2.Size();
    if(strncmp(str1.mem_data_, str2.mem_data_, size) > 0) {
        return true;
    }

    return false;
}


/*!
 * @brief **重载>=**
 * @param str1 字符串1
 * @param str2 字符串2
 * @return 结果
 * @note
 * 重载>=
 * -----
 * -----
 *
 * -----
 */
bool operator>=(const String& str1, const String& str2) {
    size_t size = str1.Size() >= str2.Size() ? str1.Size() : str2.Size();
    if(strncmp(str1.mem_data_, str2.mem_data_, size) >= 0) {
        return true;
    }

    return false;
}


/*!
 * @brief **重载&lt;**
 * @param str1 字符串1
 * @param str2 字符串2
 * @return 结果
 * @note
 * 重载<
 * -----
 * -----
 *
 * -----
 */
bool operator<(const String& str1, const String& str2) {
    if (str1 >= str2) {
        return false;
    }

    return true;
}


/*!
 * @brief **重载<=**
 * @param str1 字符串1
 * @param str2 字符串2
 * @return 结果
 * @note
 * 重载<=
 * -----
 * -----
 *
 * -----
 */
bool operator<=(const String& str1, const String& str2) {
    if (str1 > str2) {
        return false;
    }

    return true;
}


/*!
 * @brief **BF字符串匹配**
 * @param pattern 模式串
 * @param offset 目标串的起始偏移量
 * @return 匹配位置索引
 * @note
 * BF字符串匹配
 * ----------
 * ----------
 *
 * ----------
 * 初始化match_idx为-1\n\n
 * **for loop** 遍历目标串 :\n
 * &emsp; 初始化match_idx为-1\n
 * &emsp; **for loop** 遍历模式串 :\n
 * &emsp;&emsp; **if** 当前模式串字符 != 当前目标串字符 :\n
 * &emsp;&emsp;&emsp; 跳出模式串遍历循环\n\n
 * &emsp; **if** 模式串遍历完毕 :\n
 * &emsp;&emsp; match_idx设为i\n
 * &emsp;&emsp; 跳出目标串遍历循环\n\n
 * 返回match_idx\n
 */
int String::BruteForceMatch(const String& pattern, int offset) const {

    int match_idx = -1;                                                                 // 初始化match_idx为-1

    for (int i = offset; i <= length_ - pattern.length_; i++) {                         // for loop 遍历目标串
        int pattern_idx;                                                                // 初始化match_idx为-1
        for (pattern_idx = 0; pattern_idx < pattern.length_; pattern_idx++) {           // for loop 遍历模式串
            if (mem_data_[i + pattern_idx] != pattern[pattern_idx]) {                   // if 当前模式串字符 != 当前目标串字符
                break;                                                                  // 跳出模式串遍历循环
            }
        }

        if (pattern_idx == pattern.length_) {                                           // if 模式串遍历完毕
            match_idx = i;                                                              // match_idx设为i
            break;                                                                      // 跳出目标串遍历循环
        }
    }

    return match_idx;                                                                   // 返回match_idx
}


/*!
 * @brief **求next数组**
 * @return next数组
 * @note
 * 求next数组
 * ---------
 * ---------
 *
 * 1. <span style="color:#003153">为什么next[0] = -1, next[1] = 0 ?</span>\n
 *
 * A. 当pattern[1]失配时, 必然从pattern[0]开始重新进行匹配, 因此next[1] = 0\n
 * B. 如果: next[i] == x && pattern[i] == pattern[x], 即pattern[i] == pattern[next[i]], 则: next[i + 1] = x + 1\n
 *
 * 因此:\n
 * &emsp;&emsp; 令next[1] = next[0] + 1 = 0\n
 * 得:\n
 * &emsp;&emsp; next[0] = -1\n\n
 * 2. <span style="color:#003153">demo</span>\n
 * 遍历至i = 8, 此时starting_index = 2, 即<span style="color:#FF8100">next[8] = 2</span>\n
 * ```
 * a b c d 5 6 a b c d 7
 * a b
 *             a b
 *                 ^
 *                 |
 *                 |
 *
 * ```
 * 由于: \n
 * &emsp; pattern[i] == pattern[starting_index] = 'c'\n
 * 因此: \n
 * &emsp; i加1, i = 9;\n
 * &emsp; starting_index加1, starting_index = 3\n
 * &emsp; next[i] = starting_index, 即<span style="color:#D40000">next[9] = 3</span>\n
 * ```
 * a b c d 5 6 a b c d 7
 * a b c
 *             a b c
 *                   ^
 *                   |
 *                   |
 *
 * ```
 *
 * ---------
 * + **1 初始化**\n
 * 初始化i(模式化遍历索引)为0\n
 * starting_index为-1\n
 * next分配内存并初始化\n
 * next[0] 设为 -1\n\n
 * + **2 完成next数组设置**\n
 * **while loop** 遍历模式串 :\n
 * &emsp; **if** starting_index == -1 || 索引i和索引starting_index两个位置的字符相同 :\n
 * &emsp;&emsp; i向后移动1位\n
 * &emsp;&emsp; starting_index向后移动1位\n
 * &emsp;&emsp; next[i] <-- starting_index\n
 * &emsp; **else**\n
 * &emsp;&emsp; starting_index <-- next[starting_index]\n\n
 * + **3 退出函数**\n
 * 返回next数组\n
 */
int* String::KmpNext() const {

    // ---------- 1 初始化 ----------

    int i = 0;                                                                                  // 初始化i(模式化遍历索引)为0
    int starting_index = -1;                                                                    // starting_index为-1

    int* next = new int[this->length_];                                                         // next分配内存并初始化
    next[i] = starting_index;                                                                   // next[0] 设为 -1

    // ---------- 2 完成next数组设置 ----------

    while (i < this->length_) {                                                                 // while loop 遍历模式串
        if (starting_index == -1 || this->mem_data_[i] == this->mem_data_[starting_index]) {    // if starting_index == -1 || 索引i和索引starting_index两个位置的字符相同
            i++;                                                                                // i向后移动1位
            starting_index++;                                                                   // starting_index向后移动1位
            next[i] = starting_index;                                                           // next[i] <-- starting_index
        } else {                                                                                // else
            starting_index = next[starting_index];                                              // starting_index <-- next[starting_index]
        }
    }

    // ---------- 3 退出函数 ----------

    return next;                                                                                // 返回next数组
}


/*!
 * @brief **求next数组(CyberDash版本)**
 * @return next数组
 * @note
 * 求next数组(CyberDash版本)
 * -----------------------
 * -----------------------
 *
 * 1. <span style="color:#003153">为什么next[0] = -1, next[1] = 0 ?</span>\n
 *
 * A. 当pattern[1]失配时, 必然从pattern[0]开始重新进行匹配, 因此next[1] = 0\n
 * B. 如果: next[i] == x && pattern[i] == pattern[x], 即pattern[i] == pattern[next[i]], 则: next[i + 1] = x + 1\n
 *
 * 因此:\n
 * &emsp;&emsp; 令next[1] = next[0] + 1 = 0\n
 * 得:\n
 * &emsp;&emsp; next[0] = -1\n\n
 * 2. <span style="color:#003153">demo</span>\n
 * 遍历至i = 8, 此时starting_index = 2, 即<span style="color:#FF8100">next[8] = 2</span>\n
 * ```
 * a b c d 5 6 a b c d 7
 * a b
 *             a b
 *                 ^
 *                 |
 *                 |
 *
 * ```
 * 由于: \n
 * &emsp; pattern[i] == pattern[starting_index] = 'c'\n
 * 因此: \n
 * &emsp; i加1, i = 9;\n
 * &emsp; starting_index加1, starting_index = 3\n
 * &emsp; next[i] = starting_index, 即<span style="color:#D40000">next[9] = 3</span>\n
 * ```
 * a b c d 5 6 a b c d 7
 * a b c
 *             a b c
 *                   ^
 *                   |
 *                   |
 *
 * ```
 *
 * -----------------------
 * + **1 初始化next数组**\n
 * next分配内存并初始化\n
 * next[0] 设为 -1\n\n
 * + **2 模式串长度为1的情况处理**\n
 * **if** 模式串长度为1 :\n
 * &emsp; 直接返回next <span style="color:#FF8100">(next[0]已经设置完毕)</span>\n\n
 * + **3 设置next[1]**\n
 * next[1] 设为 0\n\n
 * + **4 完成next数组设置**\n
 * 初始化i <span style="color:#FF8100">(模式串遍历索引)</span>为1\n
 * 初始化starting_index为0\n\n
 * **while loop** 遍历模式串 :\n
 * &emsp; **if** 索引i和索引starting_index两个位置的字符相同 :\n
 * &emsp;&emsp; i向后移动1位\n
 * &emsp;&emsp; starting_index向后移动1位\n
 * &emsp;&emsp; next[i] <-- starting_index\n
 * &emsp; **else**\n
 * &emsp;&emsp; **if** starting_index == 0 <span style="color:#FF8100">(如果索引i字符发生失配,只能从头重新进行匹配)</span>:\n
 * &emsp;&emsp;&emsp; i向后移动1位\n
 * &emsp;&emsp;&emsp; next[i] <-- 0\n
 * &emsp;&emsp; **else**\n
 * &emsp;&emsp;&emsp; starting_index <-- next[starting_index]\n\n
 * + **5 退出函数**\n
 * 返回next数组\n
 */
int* String::KmpNextByCyberDash() const {

    // ---------- 1 初始化next数组 ----------

    int* next = new int[this->length_];                                     // next分配内存并初始化
    next[0] = -1;                                                           // next[0] 设为 -1

    // ---------- 2 模式串长度为1的情况处理 ----------

    if (length_ == 1) {                                                     // if 模式串长度为1
        return next;                                                        // 直接返回next(next[0]已经设置完毕)
    }

    // ---------- 3 设置next[1] ----------

    next[1] = 0;                                                            // next[1] 设为 0

    // ---------- 4 完成next数组设置 ----------

    int i = 1;                                                              // 初始化i(模式串遍历索引)为1
    int starting_index = 0;                                                 // 初始化starting_index为0

    while (i < length_) {                                                   // while loop 遍历模式串
        if (this->mem_data_[i] == this->mem_data_[starting_index]) {        // if 索引i和索引starting_index两个位置的字符相同
            i++;                                                            // i向后移动1位
            starting_index++;                                               // starting_index向后移动1位
            next[i] = starting_index;                                       // next[i] <-- starting_index
        } else {                                                            // else
            if (starting_index == 0) {                                      // if starting_index == 0 (如果索引i字符发生失配,只能从头重新进行匹配)
                i++;                                                        // i向后移动1位
                next[i] = 0;                                                // next[i] <-- 0
            } else {                                                        // else
                starting_index = next[starting_index];                      // starting_index <-- next[starting_index]
            }
        }
    }

    // ---------- 5 退出函数 ----------

    return next;                                                            // 返回next数组
}


/*!
 * @brief **KMP字符串匹配(Cyberdash版)**
 * @param pattern 模式串
 * @param offset 目标串偏移量
 * @return 匹配位置索引
 * @note
 * KMP字符串匹配(Cyberdash版)
 * ------------------------
 * ------------------------
 *
 * 返回值为-1, 则为不匹配
 *
 * ------------------------
 * + **1 生成模式串的next数组**\n
 * pattern调用KmpNextByCyberDash, 获取next数组\n
 * **if** next为NULL :\n
 * &emsp; 抛出bad_alloc()\n\n
 * + **2 使用next数组执行匹配**\n
 * 初始化pattern_idx<span style="color:#FF8100">(模式串遍历索引)</span>为0\n
 * 初始化target_idx<span style="color:#FF8100">(目标串遍历索引)</span>为offset\n\n
 * **while loop** 模式串未遍历完 <b>&&</b> 目标串未遍历完 :\n
 * &emsp; **if** 当前模式串字符 == 当前目标串字符 :\n
 * &emsp;&emsp; pattern_idx向后移动1位\n
 * &emsp;&emsp; target_idx向后移动1位\n
 * &emsp; **else** (当前模式串字符 != 当前目标串字符) :\n
 * &emsp;&emsp; **if** 模式串首个字符不匹配 :\n
 * &emsp;&emsp;&emsp; target_idx向后移动1位\n
 * &emsp;&emsp; **else** (模式串非首个字符不匹配) :\n
 * &emsp;&emsp;&emsp; pattern_idx <--- next[pattern_idx]\n\n
 * + **3 计算首字符匹配的索引**\n
 * 初始化match_idx为-1\n
 * **if** pattern_idx等于模式串长度(成功匹配) :\n
 * &emsp; match_idx <--- target_idx - pattern.Length()\n\n
 * + **4 返回结果**\n
 * 返回match_idx\n
 */
int String::KmpMatchByCyberdash(const String& pattern, int offset) const {

    // ---------- 1 生成模式串的next数组 ----------

    int* next = pattern.KmpNextByCyberDash();                                       // pattern调用KmpNext, 获取next数组
    if (!next) {                                                                    // if next为NULL
        throw bad_alloc();                                                          // 抛出bad_alloc()
    }

    // ---------- 2 使用next数组执行匹配 ----------

    int pattern_idx = 0;                                                            // 初始化pattern_idx(模式串遍历索引)为0
    int target_idx = offset;                                                        // 初始化target_idx(目标串遍历索引)为offset

    while (pattern_idx < pattern.Length() && target_idx < this->length_) {          // while loop 模式串未遍历完 && 目标串未遍历完
        if (pattern[pattern_idx] == this->mem_data_[target_idx]) {                  // if 当前模式串字符 == 当前目标串字符
            pattern_idx++;                                                          // pattern_idx向后移动1位
            target_idx++;                                                           // target_idx向后移动1位
        } else {                                                                    // else (当前模式串字符 != 当前目标串字符)
            if (pattern_idx == 0) {                                                 // if 模式串首个字符不匹配
                target_idx++;                                                       // target_idx向后移动1位
            } else {                                                                // else (模式串非首个字符不匹配)
                pattern_idx = next[pattern_idx];                                    // pattern_idx <--- next[pattern_idx]
            }
        }
    }

    // ---------- 3 计算首字符匹配的索引 ----------

    int match_idx = -1;                                                             // 初始化match_idx为-1

    if (pattern_idx == pattern.Length()) {                                          // if pattern_idx等于模式串长度(成功匹配)
        match_idx = target_idx - pattern.Length();                                  // match_idx <--- target_idx - pattern.Length()
    }

    // ---------- 4 返回结果 ----------

    return match_idx;                                                               // 返回match_idx
}


/*!
 * @brief **KMP字符串匹配查找**
 * @param pattern 模式串
 * @param offset 目标串的起始偏移量
 * @return 匹配位置索引
 * @note
 * KMP字符串匹配查找
 * --------------
 * --------------
 *
 * --------------
 * + **1 生成模式串的next数组**\n
 * pattern调用KmpNext, 获取next数组\n
 * **if** next为NULL :\n
 * &emsp; 抛出bad_alloc()\n\n
 * + **2 使用next数组执行匹配**\n
 * 初始化pattern_idx<span style="color:#FF8100">(模式串遍历索引)</span>为0\n
 * 初始化target_idx<span style="color:#FF8100">(目标串遍历索引)</span>为offset\n\n
 * **while loop** 模式串未遍历完 <b>&&</b> 目标串未遍历完 :\n
 * &emsp; **if** 当前模式串字符 == 当前目标串字符 <b>||</b> 当前模式串字符 == 当前目标串字符 :\n
 * &emsp;&emsp; pattern_idx向后移动1位\n
 * &emsp;&emsp; target_idx向后移动1位\n
 * &emsp; **else**\n
 * &emsp;&emsp; pattern_idx <--- next[pattern_idx]\n\n
 * + **3 计算首字符匹配的索引**\n
 * 初始化match_idx为-1\n
 * **if** pattern_idx等于模式串长度(成功匹配) :\n
 * &emsp; match_idx <--- target_idx - pattern.Length()\n\n
 * + **4 返回结果**\n
 * 返回match_idx\n
 */
int String::KmpMatch(const String& pattern, int offset) const {

    // ---------- 1 生成模式串的next数组 ----------

    int* next = pattern.KmpNext();                                                  // pattern调用KmpNext, 获取next数组
    if (!next) {                                                                    // if next为NULL
        throw bad_alloc();                                                          // 抛出bad_alloc()
    }

    // ---------- 2 使用next数组执行匹配 ----------

    int pattern_idx = 0;                                                            // 初始化pattern_idx(模式串遍历索引)为0
    int target_idx = offset;                                                        // 初始化target_idx(目标串遍历索引)为offset

    while (pattern_idx < pattern.Length() && target_idx < length_) {                // while loop 模式串未遍历完 && 目标串未遍历完
        if (pattern_idx == -1 || pattern[pattern_idx] == mem_data_[target_idx]) {   // if 当前模式串字符 == 当前目标串字符 || 当前模式串字符 == 当前目标串字符
            pattern_idx++;                                                          // pattern_idx向后移动1位
            target_idx++;                                                           // target_idx向后移动1位
        } else {                                                                    // else
            pattern_idx = next[pattern_idx];                                        // pattern_idx <--- next[pattern_idx]
        }
    }

    // ---------- 3 计算首字符匹配的索引 ----------

    int match_idx = -1;                                                             // 初始化match_idx为-1

    if (pattern_idx == pattern.Length()) {                                          // if pattern_idx等于模式串长度(成功匹配)
        match_idx = target_idx - pattern.Length();                                  // match_idx <--- target_idx - pattern.Length()
    }

    // ---------- 4 返回结果 ----------

    return match_idx;                                                               // 返回match_idx
}


#endif // CYBER_DASH_STRING_H