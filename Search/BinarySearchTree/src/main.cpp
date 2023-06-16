/*!
 * @file main.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief main函数文件
 * @version 0.2.1
 * @date 2023-02-25
 */

#include "test.h"


using namespace std;


/*!
 * @brief **main函数**
 * @return 0
 * @note
 * main函数
 * --------
 * --------
 *
 * --------
 * 测试-二分搜索树-插入\n
 * 测试-AVL树-插入\n\n
 * 测试-二分搜索树-删除\n
 * 测试-AVL树-删除\n
 * 测试-AVL树-删除(递归)\n\n
 * 测试-二分搜索树-搜索\n
 * 测试-AVL树-搜索\n
 * 测试-二分搜索树和AVL树-高度\n\n
 * 测试-二分搜索树-最大最小值\n
 * 测试-AVL树-最大最小值\n\n
 * 测试-二分搜索树-清空
 *
 *
 * --------
 */
int main() {
    TestBstInsert();                                    // 测试二分搜索树插入
    TestAvlInsert();                                    // 测试AVL树插入

    TestBstRemove();                                    // 测试二分搜索树删除
    TestAvlRemove();                                    // 测试AVL树删除
    TestAvlRemoveRecursive();                           // 测试AVL树删除(递归)

    TestBstSearch();                                    // 测试二分搜索树搜索
    TestAvlSearch();                                    // 测试AVL树搜索

    TestBstAndAvlHeight();                              // 测试二分搜索树和AVL树的高度

	TestBSTMaxAndMin();                                 // 测试二分搜索树最大最小值
	TestAVLMaxAndMin();                                 // 测试AVL树最大最小值

    TestBstClear();                                     // 测试二分搜索树清空

	return 0;
}