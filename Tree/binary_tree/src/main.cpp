//
// Created by alei_go@163.com(抖音: cyberdash_yuan) on 2020/11/1.
//

#include "test.h"


using namespace std;


int main() {

  BinaryTreeTest::TestCopyConstructor();

  // 测试二叉树深度
  BinaryTreeTest::TestHeight();

  // 测试LeftChild和RightChild
  BinaryTreeTest::TestChildFunction();

  // 测试父节点函数Parent
  BinaryTreeTest::TestParent();

  // 测试前序遍历
  BinaryTreeTest::TestPreOrder();

  // 测试中序遍历
  BinaryTreeTest::TestInOrder();

  // 测试后序遍历
  BinaryTreeTest::TestPostOrder();

  // 测试层序遍历
  BinaryTreeTest::TestLevelOrder();

  // 测试查找是否在二叉树
  BinaryTreeTest::TestFind();

  // 测试使用前序遍历和后序遍历结果创建二叉树
  BinaryTreeTest::TestCreateBinTreeByPreAndInOrderString();

  return 0;
}
