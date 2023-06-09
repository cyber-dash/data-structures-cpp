/*!
 * @file test.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 测试cpp文件
 * @version 0.2.1
 * @date 2021-05-29
 */

#include "test.h"
#include "search.h"
#include <iostream>


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
 * 数组 { 1, 4, 2, 8, 5, 7 }\n\n
 * 搜索5的数组索引, 结果为4\n
 * 搜索3的数组索引, 结果为-1(不存在)\n\n
 * + **2 测试二分搜索**\n\n
 * 数组 { 1, 2, 4, 5, 7, 8 }\n\n
 * 搜索8的数组索引, 结果为5\n
 * 搜索1的数组索引, 结果为0\n
 * 搜索3的数组索引, 结果为-1(不存在)\n\n
 */
void TestSearch() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                    Test DataList Search                   |" << endl;
    cout << "|                 测试-线性表搜索-顺序搜索和二分搜索        |" << endl;

    // ---------- 1 测试顺序搜索 ----------

    // { 1, 4, 2, 8, 5, 7 }
    int arr[6] = { 1, 4, 2, 8, 5, 7 };

    // 搜索5的数组索引, 结果为4
    int res = SequentialSearch<int>(arr, 6, 5);
    cout << "res: " << res << endl;

    // 搜索3的数组索引, 结果为-1(不存在)
    res = SequentialSearch<int>(arr, 6, 3);
    cout << "res: " << res << endl;

    // ---------- 2 测试二分搜索 ----------

    // 数组 { 1, 2, 4, 5, 7, 8 }
    int arr2[6] = { 1, 2, 4, 5, 7, 8 };

    // 搜索8的数组索引, 结果为5
    res = BinarySearch<int>(arr2, 6, 8);
    cout << "res: " << res << endl;

    // 搜索1的数组索引, 结果为0
    res = BinarySearch<int>(arr2, 6, 1);
    cout << "res: " << res << endl;

    // 搜索3的数组索引, 结果为-1(不存在)
    res = BinarySearch<int>(arr2, 6, 3);
    cout << "res: " << res << endl;

    cout << "-------------------------------------------------------------" << endl;
}
