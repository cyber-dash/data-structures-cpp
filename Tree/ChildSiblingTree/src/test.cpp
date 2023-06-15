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
  * @brief **结点访问函数**
  * @tparam TData 数据项类型模板参数
  * @param node 结点(指针)
  * @note
  * 结点访问函数
  * ----------
  * ----------
  *
  * ----------
  * 打印node->data
  */
template<typename TData>
void NodeVisit(ChildSiblingNode<TData>* node) {
	cout << node->data << " ";
}


/*!
 * @brief **测试-子女兄弟树-建树**
 * @note
 * 测试-子女兄弟树-建树
 * -----------------
 * -----------------
 *
 * 使用字符串"(c(y(b(e)(r)))(d(a)(s))(h))", 建树\n
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
 *
 * -----------------
 * + **1 使用先根遍历字符串(使用括号)建树**\n
 * + **2 打印结点数量**\n
 * + **3 打印树**\n
 *
 *
 * -----------------
 */
void TestChildSiblingTreeCreateTreeByStr() {
	cout<<endl;
	cout<<"|------------------------ CyberDash ------------------------|"<<endl;
	cout<<"|          Test ChildSiblingTree CreateByPreorderStr        |"<<endl;
	cout<<"|            测试使用先根(前序)遍历字符串创建子女兄弟树           |"<<endl<<endl;
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

    // ---------- 1 使用先根遍历字符串(使用括号)建树 ----------

	char* preorder_str = (char*)"(c(y(b(e)(r)))(d(a)(s))(h))";

	ChildSiblingTree<char> child_sibling_tree;
    child_sibling_tree.CreateByPreorderStr(preorder_str);

    // ---------- 2 打印结点数量 ----------

	int node_count = child_sibling_tree.NodeCountRecursive();
	cout << "树的节点数量: " << node_count << endl;

    // ---------- 3 打印树 ----------

	cout << "调用PrintRecursive显示: ";
    child_sibling_tree.PrintRecursive();

	cout << endl;

	cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-子女兄弟树-高度**
 * @note
 * 测试-子女兄弟树-高度
 * -----------------
 * -----------------
 *
 * 使用字符串"(c(y(b(e)(r)))(d(a)(s))(h))", 建树\n
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
 *
 * -----------------
 * + **1 使用先根遍历字符串(使用括号)建树**\n
 * + **2 打印树的高度**\n
 *
 *
 * -----------------
 */
void TestChildSiblingTreeHeightRecursive() {
	cout<<endl;
	cout<<"|------------------------ CyberDash ------------------------|"<<endl;
	cout<<"|            Test ChildSiblingTree HeightRecursive          |"<<endl;
	cout<<"|                          测试高度                        |"<<endl<<endl;
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

    // ---------- 1 使用先根遍历字符串(使用括号)建树 ----------

    char* preorder_str = (char*)"(c(y(b(e)(r)))(d(a)(s))(h))";

	ChildSiblingTree<char> child_sibling_tree;
    child_sibling_tree.CreateByPreorderStr(preorder_str);

    // ---------- 2 打印树的高度 ----------

	int height = child_sibling_tree.HeightRecursive();
	cout << "高度: " << height << endl;

	cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-子女兄弟树-结点数量**
 * @note
 * 测试-子女兄弟树-结点数量
 * --------------------
 * --------------------
 *
 * 使用字符串"(c(y(b(e)(r)))(d(a)(s))(h))", 建树\n
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
 * 调用NodeCountRecursive求结点数量\n
 *
 * --------------------
 * + **1 使用先根遍历字符串(使用括号)建树**\n
 * + **2 打印结点数量**\n
 *
 *
 * --------------------
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

    // ---------- 1 使用先根遍历字符串(使用括号)建树 ----------

    char* preorder_str = (char*)"(c(y(b(e)(r)))(d(a)(s))(h))";

	ChildSiblingTree<char> child_sibling_tree;
    child_sibling_tree.CreateByPreorderStr(preorder_str);

    // ---------- 2 打印树的高度 ----------

    int node_count = child_sibling_tree.NodeCountRecursive();
	cout << "结点数量: " << node_count << endl;

	cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-子女兄弟树-先根遍历**
 * @note
 * 测试-子女兄弟树-先根遍历
 * --------------------
 * --------------------
 *
 * 使用字符串"(0(1(2(4)(5)))(3(7)(8))(6))", 建树\n
 * ```
 *            0                                            0
 *           /                                            /|\
 *          /                                            / | \
 *         1 --- 3 --- 6                                1  3  6
 *        /     /                                      /  / \
 *       /     /                                      /  /   \
 *      2     7 --- 8                                2  7     8
 *     /                                            / \
 *    /                                            /   \
 *   4 --- 5                                      4     5
 * ```
 * 调用PreOrderRecursive进行先根遍历\n
 *
 * --------------------
 * + **1 使用先根遍历字符串(使用括号)建树**\n
 * + **2 进行先根遍历**\n
 *
 *
 * --------------------
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

    // ---------- 1 使用先根遍历字符串(使用括号)建树 ----------

    char* preorder_str = (char*)"(0(1(2(4)(5)))(3(7)(8))(6))";

	ChildSiblingTree<char> child_sibling_tree;
    child_sibling_tree.CreateByPreorderStr(preorder_str);

    // ---------- 2 进行先根遍历 ----------

    cout << "先根遍历: " << endl;
    child_sibling_tree.PreOrderRecursive(NodeVisit);

	cout << endl;

	cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-子女兄弟树-后根遍历**
 * @note
 * 测试-子女兄弟树-后根遍历
 * --------------------
 * --------------------
 *
 * 使用字符串"(0(1(2(4)(5)))(3(7)(8))(6))", 建树\n
 * ```
 *            0                                            0
 *           /                                            /|\
 *          /                                            / | \
 *         1 --- 3 --- 6                                1  3  6
 *        /     /                                      /  / \
 *       /     /                                      /  /   \
 *      2     7 --- 8                                2  7     8
 *     /                                            / \
 *    /                                            /   \
 *   4 --- 5                                      4     5
 * ```
 * 调用PostOrderRecursive进行后根遍历\n
 *
 * --------------------
 * + **1 使用先根遍历字符串(使用括号)建树**\n
 * + **2 进行后根遍历**\n
 *
 *
 * --------------------
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

    // ---------- 1 使用先根遍历字符串(使用括号)建树 ----------

    char* pre_order_str = (char*)"(0(1(2(4)(5)))(3(7)(8))(6))";

	ChildSiblingTree<char> child_sibling_tree;
    child_sibling_tree.CreateByPreorderStr(pre_order_str);

    // ---------- 2 进行后根遍历 ----------

    cout << "后根遍历: " << endl;
    child_sibling_tree.PostOrder(NodeVisit);

	cout << endl;

	cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-子女兄弟树-层序遍历**
 * @note
 * 测试-子女兄弟树-层序遍历
 * --------------------
 * --------------------
 *
 * 使用字符串"(0(1(2(4)(5)))(3(7)(8))(6))", 建树\n
 * ```
 *            0                                            0
 *           /                                            /|\
 *          /                                            / | \
 *         1 --- 3 --- 6                                1  3  6
 *        /     /                                      /  / \
 *       /     /                                      /  /   \
 *      2     7 --- 8                                2  7     8
 *     /                                            / \
 *    /                                            /   \
 *   4 --- 5                                      4     5
 * ```
 * 调用LevelOrder进行层序遍历\n
 *
 * --------------------
 * + **1 使用先根遍历字符串(使用括号)建树**\n
 * + **2 进行层序遍历**\n
 *
 *
 * --------------------
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

    // ---------- 1 使用先根遍历字符串(使用括号)建树 ----------

    char* pre_order_str = (char*)"(0(1(2(4)(5)))(3(7)(8))(6))";

	ChildSiblingTree<char> child_sibling_tree;
    child_sibling_tree.CreateByPreorderStr(pre_order_str);

    // ---------- 2 进行层序遍历 ----------

    cout << "层序遍历: " << endl;
    child_sibling_tree.LevelOrder(NodeVisit);

	cout << endl;

	cout << "-------------------------------------------------------------" << endl;
}
