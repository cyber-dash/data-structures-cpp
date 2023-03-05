/*!
 * @file test.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 子女兄弟树测试.cpp文件
 * @version 0.2.1
 * @date 2020-11-01
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#include "test.h"
#include "child_sibling_tree.h"


 /*!
  * @brief 节点遍历函数
  * @param node 节点(指针)
  */
void visit(ChildSiblingNode<char>* node) {
	cout << node->data << " ";
}


/*!
 * @brief 测试使用创建子女孩子树(使用字符串)
 * @note
 * ```
 *            c                                            c
 *           /                                            /|\
 *          /                                            / | \
 *         y --- d --- h                                y  d  h
 *        /     /                                      /  / \
 *       /     /                                      /  /   \
 *      b     a --- s                                b  a     s
 *     /                                            / \
 *    /                                            /   \
 *   e --- r                                      e     r
 * ```
 */
void TestChildSiblingTreeCreateTreeByStr() {
	cout<<endl;
	cout<<"|------------------------ CyberDash ------------------------|"<<endl;
	cout<<"|          Test ChildSiblingTree CreateByPreorderStr        |"<<endl;
	cout<<"|            测试使用先根(前序)遍历字符串创建子女孩子树           |"<<endl<<endl;
    cout<<"            c                                       c        "<<endl;
    cout<<"           /                                       /|\\      "<<endl;
    cout<<"          /                                       / | \\     "<<endl;
    cout<<"         y --- d --- h                           y  d  h     "<<endl;
    cout<<"        /     /                                 /  / \\      "<<endl;
    cout<<"       /     /                                 /  /   \\     "<<endl;
    cout<<"      b     a --- s                           b  a     s     "<<endl;
    cout<<"     /                                       / \\            "<<endl;
    cout<<"    /                                       /   \\           "<<endl;
    cout<<"   e --- r                                 e     r           "<<endl;

	char* pre_order_str = (char*)"(c(y(b(e)(r)))(d(a)(s))(h))";

	ChildSiblingTree<char> child_sibling_tree;
    child_sibling_tree.CreateByPreorderStr(pre_order_str);

	int node_count = child_sibling_tree.NodeCountRecursive();
	cout << "树的节点数量: " << node_count << endl;

	cout << "调用PrintRecursive显示: ";
    child_sibling_tree.PrintRecursive();

	cout << endl;

	cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief 测试深度
 */
void TestChildSiblingTreeHeight() {
	cout<<endl;
	cout<<"|------------------------ CyberDash ------------------------|"<<endl;
	cout<<"|                Test ChildSiblingTree Height               |"<<endl;
	cout<<"|                          测试高度                          |"<<endl<<endl;
    cout<<"            c                                       c        "<<endl;
    cout<<"           /                                       /|\\      "<<endl;
    cout<<"          /                                       / | \\     "<<endl;
    cout<<"         y --- d --- h                           y  d  h     "<<endl;
    cout<<"        /     /                                 /  / \\      "<<endl;
    cout<<"       /     /                                 /  /   \\     "<<endl;
    cout<<"      b     a --- s                           b  a     s     "<<endl;
    cout<<"     /                                       / \\            "<<endl;
    cout<<"    /                                       /   \\           "<<endl;
    cout<<"   e --- r                                 e     r           "<<endl;

    char* preorder_str = (char*)"(c(y(b(e)(r)))(d(a)(s))(h))";

	ChildSiblingTree<char> child_sibling_tree;
    child_sibling_tree.CreateByPreorderStr(preorder_str);

	int height = child_sibling_tree.Height();
	cout << "深度: " << height << endl;

	cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief 测试节点数量
 */
void TestChildSiblingTreeNodeCount() {
	cout<<endl;
	cout<<"|------------------------ CyberDash ------------------------|"<<endl;
	cout<<"|          Test ChildSiblingTree NodeCountRecursive         |"<<endl;
	cout<<"|                         测试节点数量                        |"<<endl<<endl;
    cout<<"            c                                       c        "<<endl;
    cout<<"           /                                       /|\\      "<<endl;
    cout<<"          /                                       / | \\     "<<endl;
    cout<<"         y --- d --- h                           y  d  h     "<<endl;
    cout<<"        /     /                                 /  / \\      "<<endl;
    cout<<"       /     /                                 /  /   \\     "<<endl;
    cout<<"      b     a --- s                           b  a     s     "<<endl;
    cout<<"     /                                       / \\            "<<endl;
    cout<<"    /                                       /   \\           "<<endl;
    cout<<"   e --- r                                 e     r           "<<endl;

    char* preorder_str = (char*)"(c(y(b(e)(r)))(d(a)(s))(h))";

	ChildSiblingTree<char> child_sibling_tree;
    child_sibling_tree.CreateByPreorderStr(preorder_str);

	int node_count = child_sibling_tree.NodeCountRecursive();
	cout << "节点数量: " << node_count << endl;

	cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief 测试先根遍历
 */
void TestChildSiblingTreePreorder() {
	cout<<endl;
	cout<<"|------------------------ CyberDash ------------------------|"<<endl;
	cout<<"|           Test ChildSiblingTree PreOrderRecursive         |"<<endl;
	cout<<"|                         测试先根遍历                        |"<<endl<<endl;
    cout<<"            0                                       0        "<<endl;
    cout<<"           /                                       /|\\      "<<endl;
    cout<<"          /                                       / | \\     "<<endl;
    cout<<"         1 --- 3 --- 6                           1  3  6     "<<endl;
    cout<<"        /     /                                 /  / \\      "<<endl;
    cout<<"       /     /                                 /  /   \\     "<<endl;
    cout<<"      2     7 --- 8                           2  7     8     "<<endl;
    cout<<"     /                                       / \\            "<<endl;
    cout<<"    /                                       /   \\           "<<endl;
    cout<<"   4 --- 5                                 4     5           "<<endl;

    char* preorder_str = (char*)"(0(1(2(4)(5)))(3(7)(8))(6))";

	ChildSiblingTree<char> child_sibling_tree;
    child_sibling_tree.CreateByPreorderStr(preorder_str);

	cout << "先根遍历: " << endl;
    child_sibling_tree.PreOrderRecursive(visit);

	cout << endl;

	cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief 测试后根遍历
 */
void TestChildSiblingTreePostOrder() {
	cout<<endl;
	cout<<"|------------------------ CyberDash ------------------------|"<<endl;
	cout<<"|           Test ChildSiblingTree PostOrderRecursive        |"<<endl;
	cout<<"|                         测试后根遍历                        |"<<endl<<endl;
    cout<<"            0                                       0        "<<endl;
    cout<<"           /                                       /|\\      "<<endl;
    cout<<"          /                                       / | \\     "<<endl;
    cout<<"         1 --- 3 --- 6                           1  3  6     "<<endl;
    cout<<"        /     /                                 /  / \\      "<<endl;
    cout<<"       /     /                                 /  /   \\     "<<endl;
    cout<<"      2     7 --- 8                           2  7     8     "<<endl;
    cout<<"     /                                       / \\            "<<endl;
    cout<<"    /                                       /   \\           "<<endl;
    cout<<"   4 --- 5                                 4     5           "<<endl;

    char* pre_order_str = (char*)"(0(1(2(4)(5)))(3(7)(8))(6))";

	ChildSiblingTree<char> child_sibling_tree;
    child_sibling_tree.CreateByPreorderStr(pre_order_str);

	cout << "后根遍历: " << endl;
	child_sibling_tree.PostOrder(visit);

	cout << endl;

	cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief 测试层序遍历
 */
void TestChildSiblingTreeLevelOrder() {
	cout << endl;
	cout << "|------------------------ CyberDash ------------------------|" << endl;
	cout << "|              Test ChildSiblingTree LevelOrder             |" << endl;
	cout << "|                         测试层序遍历                        |" << endl << endl;
    cout<<"            0                                       0        "<<endl;
    cout<<"           /                                       /|\\      "<<endl;
    cout<<"          /                                       / | \\     "<<endl;
    cout<<"         1 --- 3 --- 6                           1  3  6     "<<endl;
    cout<<"        /     /                                 /  / \\      "<<endl;
    cout<<"       /     /                                 /  /   \\     "<<endl;
    cout<<"      2     7 --- 8                           2  7     8     "<<endl;
    cout<<"     /                                       / \\            "<<endl;
    cout<<"    /                                       /   \\           "<<endl;
    cout<<"   4 --- 5                                 4     5           "<<endl;

    char* pre_order_str = (char*)"(0(1(2(4)(5)))(3(7)(8))(6))";

	ChildSiblingTree<char> child_sibling_tree;
    child_sibling_tree.CreateByPreorderStr(pre_order_str);

	cout << "层序遍历: " << endl;
	child_sibling_tree.LevelOrder(visit);

	cout << endl;

	cout << "-------------------------------------------------------------" << endl;
}
