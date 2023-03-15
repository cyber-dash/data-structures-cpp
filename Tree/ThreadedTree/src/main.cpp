//
// Created by alei_go@163.com(抖音: cyberdash_yuan) on 2020/11/1.
//

#include "test.h"


using namespace std;


int main() {

    // 测试First
    TestFirst();

    // 测试Last
    TestLast();

    // 测试Next(中序)
    TestNext();

    // 测试Prior(中序)
    TestPrior();

    // 测试Parent(中序)
    TestParent();

    // 测试中序线索树中序遍历
    TestInOrderTraverseOfInOrderThread();

    // 测试中序线索树前序遍历
    TestPreOrderTraverseOfInOrderThread();

    // 测试中序线索树后序遍历
    TestPostOrderTraverseOfInOrderThread();

    return 0;
}