/*!
 * @file test.cpp
 * @author CyberDash计算机考研(抖音id:cyberdash_yuan), cyberdash@163.com
 * @brief 测试cpp文件
 * @version 0.2.1
 * @date 2021-05-29
 */

#include <iostream>
#include "test.h"
#include "search.h"


using namespace std;


/*!
 * @brief **测试-线性表搜索-顺序搜索和二分搜索**
 * @note
 * 测试-线性表搜索-顺序搜索和二分搜索
 * ----------------------------
 * ----------------------------
 *
 * ----------------------------
 * + **1 测试顺序搜索**\n\n
 * <span style="color:#E76600;font-weight:bold">数组 { 1, 4, 2, 8, 5, 7 }</span>\n\n
 * 搜索5的数组索引, 结果为4\n
 * 搜索3的数组索引, 结果为-1(不存在)\n\n
 * + **2 测试二分搜索**\n\n
 * <span style="color:#FB1927;font-weight:bold">数组 { 1, 2, 4, 5, 7, 8 }</span>\n\n
 * 搜索8的数组索引, 结果为5\n
 * 搜索1的数组索引, 结果为0\n
 * 搜索3的数组索引, 结果为-1(不存在)\n\n
 *
 *
 * ----------------------------
 */
void TestSearch() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                    Test DataList Search                   |" << endl;
    cout << "|              测试-线性表搜索-顺序搜索和二分搜索           |" << endl << endl << endl;

    // ---------- 1 测试顺序搜索 ----------

    int arr[6] = { 1, 4, 2, 8, 5, 7 };

    cout << "数组{ 1, 4, 2, 8, 5, 7 }, 测试顺序搜索: " <<endl;

    int res = SequentialSearch<int>(arr, 6, 5);                                                     // 搜索5的数组索引
    cout << "搜索 5, 数组索引: " << res << endl;                                                      // 结果为4

    res = SequentialSearch<int>(arr, 6, 3);                                                         // 搜索3的数组索引
    cout << "搜索 3, 数组索引: " << res << endl << endl;                                                                 // 结果为-1(不存在)

    // ---------- 2 测试二分搜索 ----------

    int arr2[6] = { 1, 2, 4, 5, 7, 8 };

    cout << "有序数组{ 1, 2, 4, 5, 7, 8 }, 测试二分搜索: " <<endl;

    res = BinarySearch<int>(arr2, 6, 8);                                                            // 搜索8的数组索引
    cout << "搜索 8, 数组索引: " << res << endl;                                                      // 结果为5

    res = BinarySearch<int>(arr2, 6, 1);                                                            // 搜索1的数组索引
    cout << "搜索 1, 数组索引: " << res << endl;                                                      // 结果为0

    res = BinarySearch<int>(arr2, 6, 3);                                                            // 搜索3的数组索引
    cout << "搜索 3, 数组索引: " << res << endl;                                                      // 结果为-1(不存在)

    cout << endl << "-------------------------------------------------------------" << endl;
}
