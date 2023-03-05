/*!
 * @file main.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 子女兄弟树main.cpp文件
 * @version 0.2.1
 * @date 2020-11-01
 */

#include "test.h"


using namespace std;


int main() {

    // 测试CreateByPreorderStr
	TestChildSiblingTreeCreateTreeByStr();

    // 测试高度
    TestChildSiblingTreeHeight();

    // 测试结点数量
	TestChildSiblingTreeNodeCount();

    // 测试后根遍历
	TestChildSiblingTreePostOrder();

    // 测试先根遍历
    TestChildSiblingTreePreorder();

    // 测试层序遍历
	TestChildSiblingTreeLevelOrder();

	return 0;
}
