//
// Created by alei_go@163.com(抖音: cyberdash_yuan) on 2020/11/1.
//

#include "test.h"


using namespace std;


int main() {

  // 测试二叉树深度
  TestBinaryTreeHeight();

  // 测试LeftChild和RightChild
  TestBinaryTreeChildFunction();

  // 测试父节点函数Parent
  TestParent();

  // 测试前序遍历
  TestPreOrder();

  // 测试中序遍历
  TestInOrder();

  // 测试后序遍历
  TestPostOrder();

  // 测试层序遍历
  TestLevelOrder();

  // 测试查找是否在二叉树
  TestFind();

  // 测试使用前序遍历和后序遍历结果创建二叉树
  TestCreateBinTreeByPreAndInOrderString();

  return 0;
}
