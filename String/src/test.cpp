/*!
 * @file test.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 字符串匹配测试.cpp文件
 * @version 0.2.1
 * @date 2021-08-23
 */

#include "test.h"
#include "cyber_dash_string.h"


/*!
 * @brief **测试-字符串-基本函数**
 * @note
 * 测试-字符串-基本函数
 * -----------------
 * -----------------
 *
 * -----------------
 * 测试重载==\n
 * 测试重载!=\n
 * 测试复制构造函数\n
 * 测试重载+=\n
 * 测试重载[]\n
 * 测试重载>,>=,<,<=\n
 * 测试重载<<\n
 *
 *
 * -----------------
 */
void TestStringBaseFunctions() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                  Test String base functions               |" << endl;
    cout << "|                    测试-字符串-基本函数                   |" << endl << endl << endl;

    String str1("cyber");
    String str2("dash");

    // - 测试重载==
    cout << "测试重载==" << endl;
    bool is_same = str1 == str2;
    cout << is_same << endl << endl;

    // - 测试重载!=
    cout << "测试重载!=" << endl;
    bool is_not_same = str1 != str2;
    cout << is_not_same << endl << endl;

    // - 测试复制构造函数
    cout << "测试复制构造" << endl;
    String str3 = str1;
    cout << str3 << endl << endl;

    // - 测试重载+=
    cout << "测试重载+=" << endl;
    str1 += str2;
    cout << str1 <<endl << endl;

    // - 测试重载[]
    cout << "测试重载[]" << endl;
    cout << str1[0] << endl;
    str1[0] = 'C';
    cout << str1 << endl << endl;

    // - 测试重载>,>=,<,<=
    cout << "测试重载>,>=,<,<=" << endl;
    String str4("elements");
    String str5("element");
    cout << (str4 > str5) << endl;
    cout << (str4 >= str5) << endl;
    cout << (str4 < str5) << endl;
    cout << (str4 <= str5) << endl;

    String str6("table");
    String str7("tables");
    cout << (str6 > str7) << endl;
    cout << (str6 >= str7) << endl;
    cout << (str6 < str7) << endl;
    cout << (str6 <= str7) << endl << endl;

    // - 测试重载<<
    cout << "测试重载<<" << endl;
    String str8;
    cout << str8 << endl;

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-字符串-BF算法**
 * @note
 * 测试-字符串-BF算法
 * -----------------
 * -----------------
 *
 * 暴力算法
 *
 * -----------------
 * + **1 声明字符串**\n\n
 * 目标串“hand in hand we can, start to understand”\n
 * 模式串1"hand"\n
 * 模式串2"understand"\n\n
 * + **2 执行匹配**\n\n
 * 获取模式串1的匹配结果\n
 * 获取模式串2的匹配结果\n
 *
 *
 * -----------------
 */
void TestBruteForceMatch() {

	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                    Test BruteForceMatch                   |" << endl;
	cout << "|                         测试BF算法                        |" << endl << endl << endl;

	String target_str("hand in hand we can, start to understand");
	String pattern_str_1("hand");
	String pattern_str_2("understand");

	cout << "目标串: " << target_str << endl << endl;
	cout << "模式串" << pattern_str_1 << "的匹配位置: " << target_str.BruteForceMatch(pattern_str_1, 0) << endl;
	cout << "模式串" << pattern_str_2 << "的匹配位置: " << target_str.BruteForceMatch(pattern_str_2, 0) << endl;

	cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-字符串-KMP算法**
 * @note
 * 测试-字符串-KMP算法
 * -----------------
 * -----------------
 *
 * -----------------
 * + **1 声明字符串**\n\n
 * 目标串"aaaabcd56****abcd56abcd7777"\n
 * 模式串1"abcd56abcd7"\n
 * 模式串2"ababc"\n
 * 模式串3"bcd56abc"\n
 * 模式串4"7"\n\n
 * + **2 执行匹配**\n\n
 * 获取模式串1的匹配结果\n
 * 获取模式串2的匹配结果\n
 * 获取模式串3的匹配结果\n
 * 获取模式串4的匹配结果\n
 *
 *
 * -----------------
 */
void TestKmpMatch() {

	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                  Test KmpMatchByCyberdash                 |" << endl;
	cout << "|                        测试KMP算法                        |" << endl << endl << endl;

	String target_str("aaaabcd56****abcd56abcd7777");
	String pattern_str_1("abcd56abcd7");
	String pattern_str_2("ababc");
	String pattern_str_3("bcd56abc");
    String pattern_str_4("7");

	cout << "目标串: " << target_str << endl << endl;
	cout << "模式串\"" << pattern_str_1 << "\"的匹配位置: " << target_str.KmpMatchByCyberdash(pattern_str_1, 0) << endl;
	cout << "模式串\"" << pattern_str_2 << "\"的匹配位置: " << target_str.KmpMatchByCyberdash(pattern_str_2, 0) << endl;
	cout << "模式串\"" << pattern_str_3 << "\"的匹配位置: " << target_str.KmpMatchByCyberdash(pattern_str_3, 0) << endl;
    cout << "模式串\"" << pattern_str_4 << "\"的匹配位置: " << target_str.KmpMatchByCyberdash(pattern_str_4, 0) << endl;

	cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-字符串-KMP算法(CyberDash版)**
 * @note
 * 测试-字符串-KMP算法(CyberDash版)
 * -----------------------------
 * -----------------------------
 *
 * -----------------------------
 * + **1 声明字符串**\n\n
 * 目标串"aaaabcd56****abcd56abcd7777"\n
 * 模式串1"abcd56abcd7"\n
 * 模式串2"ababc"\n
 * 模式串3"bcd56abc"\n
 * 模式串4"7"\n\n
 * + **2 执行匹配**\n\n
 * 获取模式串1的匹配结果\n
 * 获取模式串2的匹配结果\n
 * 获取模式串3的匹配结果\n
 * 获取模式串4的匹配结果\n
 *
 *
 * -----------------
 */
void TestKmpMatchCyberDash() {

	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|                       Test KmpMatch                       |" << endl;
	cout << "|                         测试KMP算法                       |" << endl << endl << endl;

	String target_str("aaaabcd56****abcd56abcd7777");
	String pattern_str_1("abcd56abcd7");
	String pattern_str_2("ababc");
	String pattern_str_3("bcd56abc");
    String pattern_str_4("7");

	cout << "目标串: " << target_str << endl << endl;
	cout << "模式串" << pattern_str_1 << "的匹配位置: " << target_str.KmpMatch(pattern_str_1, 0) << endl;
	cout << "模式串" << pattern_str_2 << "的匹配位置: " << target_str.KmpMatch(pattern_str_2, 0) << endl;
	cout << "模式串" << pattern_str_3 << "的匹配位置: " << target_str.KmpMatch(pattern_str_3, 0) << endl;
    cout << "模式串" << pattern_str_4 << "的匹配位置: " << target_str.KmpMatch(pattern_str_4, 0) << endl;

	cout << "-------------------------------------------------------------" << endl << endl;
}