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
    explicit String(size_t size = DEFAULT_SIZE);   // 构造函数(字符串长度)
    explicit String(const char* mem_data);      // 构造函数
    String(const String& str);                  // 复制构造函数
    ~String() { delete[] mem_data_; }           // 析构函数

    int Length() const { return this->length_; }
    size_t Size() const { return this->size_; }

    const char& operator[](size_t index) const;                     // 重载[]
    char& operator[](size_t index);                                 // 重载[]
    String& operator=(const String& src_str);                       // 重载=
    String& operator+=(String& str);                                // 重载+=
    friend ostream& operator<<(ostream& os, const String& str);     // 重载<<
    friend bool operator==(const String& str1, const String& str2); // 重载==
    friend bool operator!=(const String& str1, const String& str2); // 重载!=
    friend bool operator<(const String& str1, const String& str2);  // 重载<
    friend bool operator<=(const String& str1, const String& str2); // 重载<=
    friend bool operator>(const String& str1, const String& str2);  // 重载>
    friend bool operator>=(const String& str1, const String& str2); // 重载>=

    int BruteForceMatch(const String& pattern, int offset) const;     // BF字符串匹配
    int KmpMatch(const String& pattern, int offset) const;            // KMP字符串匹配查找
    int KmpMatchByCyberDash(const String& pattern, int offset) const; // KMP字符串匹配查找(使用KMPNextByCyberDash生成next数组)

    int* KmpNext() const;              // 求next数组
    int* KmpNextByCyberDash() const;   // 求next数组()

private:
    char* mem_data_; //!< 字符串数组
    int length_;     //!< 当前字符串长度
    size_t size_;    //!< 最大长度
};


/*!
 * @brief **构造函数**
 * @param size 字符串最大长度
 */
String::String(size_t size) {

    this->mem_data_ = new char[size + 1];
    if (!this->mem_data_) {
        throw bad_alloc();
    }

    this->size_ = size;
    this->length_ = 0;

    // 先全部置0
    memset(this->mem_data_, 0, sizeof(char) * (this->size_ + 1));
}


/*!
 * @brief **构造函数(字符串) **
 * @param mem_data 字符串
 * @note
 * 构造函数(字符串)
 * --------------
 * --------------
 *
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

    // 先全部置0
    memset(this->mem_data_, 0, sizeof(char) * (this->size_ + 1));
    // 再复制字符串内容
    memcpy(this->mem_data_, mem_data, sizeof(char) * str_len);
}


String::String(const String& str) {

    if (&str == this) {
        return;
    }

    this->length_ = str.Length();
    this->size_ = str.Size();

    this->mem_data_ = new char[str.Length() + 1];
    if (!this->mem_data_) {
        throw bad_alloc();
    }

    for (int i = 0; i < str.Length(); i++) {
        this->mem_data_[i] = str[i];
    }
    this->mem_data_[this->Length()] = '\0';
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


String& String::operator+=(String& str) {
    if (str.Length() == 0) {
        return *this;
    }

    int new_length = this->Length() + str.Length();
    if ((int)this->Size() >= new_length) {
        for (int i = 0; i < str.Length(); i++) {
            this->mem_data_[i + this->Length()] = str[i];
        }
        this->mem_data_[new_length] = '\0';
    } else {
        char* new_mem_data = new char[new_length + 1];
        for (int i = 0; i < this->Length(); i++) {
            new_mem_data[i] = this->operator[](i);
        }
        for (int i = 0; i < str.Length(); i++) {
            new_mem_data[this->Length() + i] = str[i];
        }
        new_mem_data[new_length] = '\0';

        delete[] this->mem_data_;
        this->mem_data_ = new_mem_data;
    }

    this->length_ = new_length;
    this->size_ = new_length;

    return *this;
}


/*!
 * @brief 重载[]
 * @param index
 * @return
 */
char& String::operator[] (size_t index) {
    if ((int)index >= Length()) {
        throw exception("Out of Range");
    }

    return this->mem_data_[index];
}

const char& String::operator[] (size_t index) const {
    if ((int)index >= Length()) {
        throw exception("Out of Range");
    }

    return this->mem_data_[index];
}


ostream& operator<<(ostream& os, const String& str) {
    os << str.mem_data_;
    return os;
}


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


bool operator!=(const String& str1, const String& str2) {
    return !(str1 == str2);
}


bool operator>(const String& str1, const String& str2) {
    size_t size = str1.Size() >= str2.Size() ? str1.Size() : str2.Size();
    if(strncmp(str1.mem_data_, str2.mem_data_, size) > 0) {
        return true;
    }

    return false;
}


bool operator>=(const String& str1, const String& str2) {
    size_t size = str1.Size() >= str2.Size() ? str1.Size() : str2.Size();
    if(strncmp(str1.mem_data_, str2.mem_data_, size) >= 0) {
        return true;
    }

    return false;
}


bool operator<(const String& str1, const String& str2) {
    if (str1 >= str2) {
        return false;
    }

    return true;
}


bool operator<=(const String& str1, const String& str2) {
    if (str1 > str2) {
        return false;
    }

    return true;
}


/*!
 * @brief BF字符串匹配
 * @param pattern 模式串
 * @param offset 目标串的起始偏移量
 * @return 目标串中的匹配位置, -1为不匹配 / 其他为第一个匹配字符的数组索引值
 */
int String::BruteForceMatch(const String& pattern, int offset) const {

    int match_offset = -1;
    int pattern_idx;

    for (int i = offset; i <= length_ - pattern.length_; i++) {
        for (pattern_idx = 0; pattern_idx < pattern.length_; pattern_idx++) {
            if (mem_data_[i + pattern_idx] != pattern[pattern_idx]) {
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
 * @brief **求模式串next数组**
 * @param pattern 模式串
 * @param pattern_len 模式串长度
 * @return next数组首地址
 */
int* String::KmpNext() const {

    /// 设置next[0] = -1
    int i = 0;
    int starting_index = -1;

    // 分配next数组内存
    int* next = new int[this->length_];
    next[i] = starting_index;

    while (i < this->length_) {

        /// 使用next[0]处理next[1]
        /// 当模式串字符pattern[1]失配时, 必然从pattern[0]开始重新进行匹配, 因此next[1] = 0
        /// 此处逻辑可以和下面的pattern[i] == pattern[starting_index]分支逻辑合并
        /// 因此next[0] = -1
        /// 其余部分则相同(代码可以合并)
        if (starting_index == -1) {
            i++;
            starting_index++;
            if (i < this->length_) {
                next[i] = starting_index;
            }
        } else {    /// 使用next[i]求next[i + 1]
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
            if (this->mem_data_[i] == this->mem_data_[starting_index]) {
                i++;
                starting_index++;
                next[i] = starting_index;
            } else {    /// 如果pattern[i]和pattern[starting_index]不同, 则使用next数组进行递归, 逐步验证
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
int* String::KmpNextByCyberDash() const {

    int* next = new int[this->length_];

    next[0] = -1;
    next[1] = 0;

    int i = 1;
    int starting_index = 0;

    while (i < length_) {
        if (this->mem_data_[i] == this->mem_data_[starting_index]) {
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
 /*
void String::PrintNextArray(const int* next_arr, int next_arr_len) {
    /// 示例
    /// 模式字符串:  a b c d 5 6 a b c d 7
    /// next数组:  -1 0 0 0 0 0 0 1 2 3 4
    for (int i = 0; i < next_arr_len; i++) {
        cout << *(next_arr + i) << " ";
    }
    cout << endl;
}
  */


/*!
 * @brief **KMP字符串匹配**
 * @param pattern 模式串
 * @param offset 目标串偏移量
 * @return 匹配位置索引
 * @note
 * KMP字符串匹配
 * ------------
 * ------------
 *
 * 返回值为-1, 则为不匹配
 *
 * ------------
 * + **1 生成模式串的next数组**\n
 * pattern调用KmpNext, 获取next数组\n
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
int String::KmpMatch(const String& pattern, int offset) const {

    int* next = pattern.KmpNext();
    if (!next) {
        throw bad_alloc();
    }

    int pattern_idx = 0;
    int target_idx = offset;

    while (pattern_idx < pattern.Length() && target_idx < this->length_) {
        if (pattern[pattern_idx] == this->mem_data_[target_idx]) {
            pattern_idx++;
            target_idx++;
        } else {
            if (pattern_idx == 0) {
                target_idx++;
            } else {
                pattern_idx = next[pattern_idx];
            }
        }
    }

    int match_idx = -1;

    if (pattern_idx == pattern.Length()) {
        match_idx = target_idx - pattern.Length();
    }

    return match_idx;
}


/*!
 * @brief KMP字符串匹配查找(使用KMPNextByCyberDash生成next数组)
 * @param pattern 模式串
 * @param offset 目标串的起始偏移量
 * @return 目标串中的匹配位置, -1为不匹配 / 其他为第一个匹配字符的数组索引值
 * @note
 */
int String::KmpMatchByCyberDash(const String& pattern, int offset) const {

    int match_idx;

    int* next = pattern.KmpNextByCyberDash();
    if (!next) {
        throw bad_alloc();
    }

    int pattern_idx = 0;
    int target_idx = offset;

    while (pattern_idx < pattern.Length() && target_idx < length_) {
        if (pattern_idx == -1 || pattern[pattern_idx] == mem_data_[target_idx]) {
            pattern_idx++;
            target_idx++;
        } else {
            pattern_idx = next[pattern_idx];
        }
    }

    if (pattern_idx < pattern.Length()) {
        match_idx = -1;
    } else {
        match_idx = target_idx - pattern.Length();
    }

    return match_idx;
}


#endif // CYBER_DASH_STRING_H