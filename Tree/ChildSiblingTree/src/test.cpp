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
void visit(ChildSiblingNode<int>* node) {
  cout << node->data << " ";
}


/*!
 * @brief 测试使用字符串创建子女孩子树
 */
void TestChildSiblingTreeCreateTreeByStr() {
  cout << endl;
  cout << "|------------------------ CyberDash ------------------------|" << endl;
  cout << "|              Test ChildSiblingTree CreateByStr            |" << endl;
  cout << "|                   测试使用字符串创建子女孩子树                |" << endl << endl << endl;

  char* str = (char*)"(0(1(2))(2))";
  cout << "字符串: " << str << endl << endl;

  ChildSiblingTree<int> child_sibling_tree;
  child_sibling_tree.CreateTreeByStr(str);

  int node_count = child_sibling_tree.NodeCount();
  cout << "树的节点数量: " << node_count << endl;

  cout << "调用ShowTree()显示: ";
  child_sibling_tree.ShowTree();

  cout << endl;

  cout << "-------------------------------------------------------------" << endl;
}


/*!
 * @brief 测试深度
 */
void TestChildSiblingTreeDepth() {
  cout << endl;
  cout << "|------------------------ CyberDash ------------------------|" << endl;
  cout << "|                 Test ChildSiblingTree Depth               |" << endl;
  cout << "|                          测试深度                          |" << endl << endl << endl;

  char* str = (char*)"(0(1(2))(2))";
  cout << "字符串: " << str << endl << endl;

  ChildSiblingTree<int> child_sibling_tree;
  child_sibling_tree.CreateTreeByStr(str);

  int depth = child_sibling_tree.Depth();
  cout << "深度: " << depth << endl;

  cout << "-------------------------------------------------------------" << endl;
}


/*!
 * @brief 测试节点数量
 */
void TestChildSiblingTreeNodeCount() {
  cout << endl;
  cout << "|------------------------ CyberDash ------------------------|" << endl;
  cout << "|               Test ChildSiblingTree NodeCount             |" << endl;
  cout << "|                         测试节点数量                        |" << endl << endl << endl;

  char* str = (char*)"(0(1(2))(2))";
  cout << "字符串: " << str << endl << endl;

  ChildSiblingTree<int> child_sibling_tree;
  child_sibling_tree.CreateTreeByStr(str);

  int node_count = child_sibling_tree.NodeCount();
  cout << "节点数量: " << node_count << endl;

  cout << "-------------------------------------------------------------" << endl;
}


/*!
 * @brief 测试先根遍历
 */
void TestChildSiblingTreePreOrder() {
  cout << endl;
  cout << "|------------------------ CyberDash ------------------------|" << endl;
  cout << "|                Test ChildSiblingTree PreOrder             |" << endl;
  cout << "|                         测试先根遍历                        |" << endl << endl << endl;

  char* str = (char*)"(0(1(2))(2))";
  cout << "字符串: " << str << endl << endl;

  ChildSiblingTree<int> child_sibling_tree;
  child_sibling_tree.CreateTreeByStr(str);

  cout << "先根遍历: " << endl;
  child_sibling_tree.PreOrder(visit);

  cout << endl;

  cout << "-------------------------------------------------------------" << endl;
}


/*!
 * @brief 测试后根遍历
 */
void TestChildSiblingTreePostOrder() {
  cout << endl;
  cout << "|------------------------ CyberDash ------------------------|" << endl;
  cout << "|               Test ChildSiblingTree PostOrder             |" << endl;
  cout << "|                         测试后根遍历                        |" << endl << endl << endl;

  char* str = (char*)"(0(1(2))(2))";
  cout << "字符串: " << str << endl << endl;

  ChildSiblingTree<int> child_sibling_tree;
  child_sibling_tree.CreateTreeByStr(str);

  cout << "后根遍历: " << endl;
  child_sibling_tree.PostOrder(visit);

  cout << endl;

  cout << "-------------------------------------------------------------" << endl;
}


/*!
 * @brief 测试层序遍历
 */
void TestChildSiblingTreeLevelOrder() {
  cout << endl;
  cout << "|------------------------ CyberDash ------------------------|" << endl;
  cout << "|              Test ChildSiblingTree LevelOrder             |" << endl;
  cout << "|                         测试层序遍历                        |" << endl << endl << endl;

  char* str = (char*)"(0(1(2))(2))";
  cout << "字符串: " << str << endl << endl;

  ChildSiblingTree<int> child_sibling_tree;
  child_sibling_tree.CreateTreeByStr(str);

  cout << "层序遍历: " << endl;
  child_sibling_tree.LevelOrder(cout);

  cout << endl;


  cout<<"-------------------------------------------------------------"<<endl;
}
