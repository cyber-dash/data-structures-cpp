/*!
 * @file main.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 子女兄弟树main.cpp文件
 * @version 0.2.1
 * @date 2020-11-01
 */

#include "test.h"


using namespace std;


/*!
 * @brief **main函数**
 * @return 0
 * @note
 * main函数
 * -------
 * -------
 *
 * -------
 * 测试-子女兄弟树-建树\n\n
 * 测试-子女兄弟树-高度\n\n
 * 测试-子女兄弟树-结点数量\n\n
 * 测试-子女兄弟树-后根遍历\n\n
 * 测试-子女兄弟树-先根遍历\n\n
 * 测试-子女兄弟树-层序遍历\n
 *
 *
 * -------
 */
int main() {

    // 测试-子女兄弟树-建树
	TestChildSiblingTreeCreateTreeByStr();

    // 测试-子女兄弟树-高度
    TestChildSiblingTreeHeightRecursive();

    // 测试-子女兄弟树-结点数量
	TestChildSiblingTreeNodeCount();

    // 测试-子女兄弟树-后根遍历
	TestChildSiblingTreePostOrder();

    // 测试-子女兄弟树-先根遍历
    TestChildSiblingTreePreorder();

    // 测试-子女兄弟树-层序遍历
	TestChildSiblingTreeLevelOrder();

	return 0;
}
