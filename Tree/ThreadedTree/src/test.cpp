/*!
 * @file test.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 线索树测试cpp文件
 * @version 0.2.1
 * @date 2021-05-13
 */

#include "inorder_threaded_binary_tree.h"


void visit(ThreadedNode<int>* node_ptr) {
    cout << node_ptr->data << " ";
};


void TestInorderThreadedTreeFirst() {

    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|             Test InorderThreadedBinaryTree First          |"<<endl;
    cout<<"|                  测试中序线索树第一个线索节点                 |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                             0                             |"<<endl;
    cout<<"|                            / \\                            |"<<endl;
    cout<<"|                           /   \\                           |"<<endl;
    cout<<"|                          1     2                          |"<<endl;
    cout<<"|                         / \\   /                           |"<<endl;
    cout<<"|                        3   5 4                            |"<<endl;
    cout<<"|                       /                                   |"<<endl;
    cout<<"|                      6                                    |"<<endl<<endl;

    int node_count = 7;

    InorderThreadedBinaryTree<int> inorder_threaded_tree;

    for (int i = 0 ; i < node_count; i++) {
        inorder_threaded_tree.InsertRecursive(i);
    }

    inorder_threaded_tree.CreateThreadRecursive();

    ThreadedNode<int>* root = inorder_threaded_tree.Root();

    ThreadedNode<int>* first = inorder_threaded_tree.First(root);

    cout << "中序线索第一个线索节点 :" << first->data << endl;

    cout<<endl<<"------------------------- CyberDash -------------------------"<<endl;
    cout<<endl;
}


void TestInorderThreadedTreeLast() {

    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|              Test InorderThreadedBinaryTree Last          |"<<endl;
    cout<<"|                 测试中序线索树最后一个线索节点                 |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                             0                             |"<<endl;
    cout<<"|                            / \\                            |"<<endl;
    cout<<"|                           /   \\                           |"<<endl;
    cout<<"|                          1     2                          |"<<endl;
    cout<<"|                         / \\   /                           |"<<endl;
    cout<<"|                        3   5 4                            |"<<endl;
    cout<<"|                       /                                   |"<<endl;
    cout<<"|                      6                                    |"<<endl<<endl;

    int node_count = 7;

    InorderThreadedBinaryTree<int> inorder_threaded_tree;

    for (int i = 0 ; i < node_count; i++) {
        inorder_threaded_tree.InsertRecursive(i);
    }

    inorder_threaded_tree.CreateThreadRecursive();

    ThreadedNode<int>* root = inorder_threaded_tree.Root();

    ThreadedNode<int>* last_node = inorder_threaded_tree.Last(root);

    cout << "中序线索最后一个线索节点: " << last_node->data << endl;

    cout<<endl<<"------------------------- CyberDash -------------------------"<<endl;
    cout<<endl;
}


void TestInorderThreadedTreeNext() {

    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|              Test InorderThreadedBinaryTree Next          |"<<endl;
    cout<<"|                   测试中序线索树下一个线索节点                 |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                             0                             |"<<endl;
    cout<<"|                            / \\                            |"<<endl;
    cout<<"|                           /   \\                           |"<<endl;
    cout<<"|                          1     2                          |"<<endl;
    cout<<"|                         / \\   /                           |"<<endl;
    cout<<"|                        3   5 4                            |"<<endl;
    cout<<"|                       /                                   |"<<endl;
    cout<<"|                      6                                    |"<<endl<<endl;

    int node_count = 7;

    InorderThreadedBinaryTree<int> inorder_threaded_tree;

    for (int i = 0 ; i < node_count; i++) {
        inorder_threaded_tree.InsertRecursive(i);
    }

    inorder_threaded_tree.CreateThreadRecursive();

    ThreadedNode<int>* first = inorder_threaded_tree.First(inorder_threaded_tree.Root());
    ThreadedNode<int>* second = inorder_threaded_tree.Next(first);
    ThreadedNode<int>* third = inorder_threaded_tree.Next(second);
    ThreadedNode<int>* forth = inorder_threaded_tree.Next(third);

    cout << "中序线索树第1个线索节点: " << first->data << endl;
    cout << "中序线索树第2个线索节点: " << second->data << endl;
    cout << "中序线索树第3个线索节点: " << third->data << endl;
    cout << "中序线索树第4个线索节点: " << forth->data << endl;

    cout<<endl<<"------------------------- CyberDash -------------------------"<<endl;
    cout<<endl;
}


void TestInorderThreadedTreePre() {

    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|             Test InorderThreadedBinaryTree Pre            |"<<endl;
    cout<<"|                  测试中序线索树前一个线索节点                 |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                             0                             |"<<endl;
    cout<<"|                            / \\                            |"<<endl;
    cout<<"|                           /   \\                           |"<<endl;
    cout<<"|                          1     2                          |"<<endl;
    cout<<"|                         / \\   /                           |"<<endl;
    cout<<"|                        3   5 4                            |"<<endl;
    cout<<"|                       /                                   |"<<endl;
    cout<<"|                      6                                    |"<<endl<<endl;

    int node_count = 7;

    ThreadedNode<int>* nodes[4];
    InorderThreadedBinaryTree<int> inorder_threaded_tree;

    for (int i = 0 ; i < node_count; i++) {
        inorder_threaded_tree.InsertRecursive(i);
    }

    inorder_threaded_tree.CreateThreadRecursive();

    nodes[0] = inorder_threaded_tree.First(inorder_threaded_tree.Root());

    for (int i = 1; i < 4; i++) {
        nodes[i] = inorder_threaded_tree.Next(nodes[i - 1]);
    }

    for (int i = 3; i >=1; i--) {
        ThreadedNode<int>* pre_node = inorder_threaded_tree.Pre(nodes[i]);
        cout << "中序线索树第" << i << "个线索节点: " << pre_node->data << endl; // (i - 1) + 1 = i
    }

    cout<<endl<<"------------------------- CyberDash -------------------------"<<endl;
    cout<<endl;
}


/*
 * 中序线索二叉树Parent
 */
void TestInorderThreadedTreeParent() {

    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|            Test InorderThreadedBinaryTree Parent          |"<<endl;
    cout<<"|                     测试中序线索树父节点                     |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                             0                             |"<<endl;
    cout<<"|                            / \\                            |"<<endl;
    cout<<"|                           /   \\                           |"<<endl;
    cout<<"|                          1     2                          |"<<endl;
    cout<<"|                         / \\   /                           |"<<endl;
    cout<<"|                        3   5 4                            |"<<endl;
    cout<<"|                       /                                   |"<<endl;
    cout<<"|                      6                                    |"<<endl<<endl;

    int node_count = 7;

    InorderThreadedBinaryTree<int> inorder_threaded_tree;

    for (int i = 0 ; i < node_count; i++) {
        inorder_threaded_tree.InsertRecursive(i);
    }

    inorder_threaded_tree.CreateThreadRecursive();

    ThreadedNode<int>* root = inorder_threaded_tree.Root();
    ThreadedNode<int>* root_parent = inorder_threaded_tree.Parent(root);

    ThreadedNode<int>* first_node = inorder_threaded_tree.First(root);
    ThreadedNode<int>* first_parent = inorder_threaded_tree.Parent(first_node);
    ThreadedNode<int>* first_grand_parent = inorder_threaded_tree.Parent(first_parent);

    if (root_parent != nullptr) {
        cout << "根节点的父节点: " << root_parent->data << endl;
    } else {
        cout<<"根节点的父节点为NULL"<<endl;
    }

    cout << "第一个线索节点: " << first_node->data << endl;
    cout << "第一个线索节点的父节点: " << first_parent->data << endl;
    cout << "第一个线索节点的父节点的父节点: " << first_grand_parent->data << endl;

    cout<<endl<<"------------------------- CyberDash -------------------------"<<endl;
    cout<<endl;
}


void TestInorderThreadedTreeInorderTraverse() {

    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|          Test InorderThreadedTree InorderTraverse         |"<<endl;
    cout<<"|                    测试中序线索树中序遍历                     |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                             0                             |"<<endl;
    cout<<"|                            / \\                            |"<<endl;
    cout<<"|                           /   \\                           |"<<endl;
    cout<<"|                          1     2                          |"<<endl;
    cout<<"|                         / \\   /                           |"<<endl;
    cout<<"|                        3   5 4                            |"<<endl;
    cout<<"|                       /                                   |"<<endl;
    cout<<"|                      6                                    |"<<endl<<endl;

    int node_count = 7;
    InorderThreadedBinaryTree<int> inorder_threaded_tree;

    for (int i = 0 ; i < node_count; i++) {
        inorder_threaded_tree.InsertRecursive(i);
    }

    inorder_threaded_tree.CreateThreadRecursive();

    cout<<"中序线索树, 中序遍历: "<<endl;
    inorder_threaded_tree.InorderTraverse(visit);

    cout<<endl<<endl<<"------------------------- CyberDash -------------------------"<<endl;
    cout<<endl;
}


void TestInorderThreadedTreePreorderTraverse() {

    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|          Test InorderThreadedTree PreorderTraverse        |"<<endl;
    cout<<"|                    测试中序线索树前序遍历                     |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                             0                             |"<<endl;
    cout<<"|                            / \\                            |"<<endl;
    cout<<"|                           /   \\                           |"<<endl;
    cout<<"|                          1     2                          |"<<endl;
    cout<<"|                         / \\   /                           |"<<endl;
    cout<<"|                        3   5 4                            |"<<endl;
    cout<<"|                       /                                   |"<<endl;
    cout<<"|                      6                                    |"<<endl<<endl;

    int node_count = 7;
    InorderThreadedBinaryTree<int> inorder_threaded_tree;

    for (int i = 0 ; i < node_count; i++) {
        inorder_threaded_tree.InsertRecursive(i);
    }

    inorder_threaded_tree.CreateThreadRecursive();

    cout<<"中序线索树, 前序遍历: "<<endl;
    inorder_threaded_tree.PreorderTraverse(visit);

    cout<<endl<<endl<<"------------------------- CyberDash -------------------------"<<endl;
    cout<<endl;
}


void TestInorderThreadedTreePostorderTraverse() {

    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|          Test InorderThreadedTree PostorderTraverse       |"<<endl;
    cout<<"|                    测试中序线索树后序遍历                     |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                             0                             |"<<endl;
    cout<<"|                            / \\                            |"<<endl;
    cout<<"|                           /   \\                           |"<<endl;
    cout<<"|                          1     2                          |"<<endl;
    cout<<"|                         / \\   /                           |"<<endl;
    cout<<"|                        3   5 4                            |"<<endl;
    cout<<"|                       /                                   |"<<endl;
    cout<<"|                      6                                    |"<<endl<<endl;

    int node_count = 7;
    InorderThreadedBinaryTree<int> inorder_threaded_tree;

    for (int i = 0 ; i < node_count; i++) {
        inorder_threaded_tree.InsertRecursive(i);
    }

    inorder_threaded_tree.CreateThreadRecursive();

    cout<<"中序线索树, 后序遍历: "<<endl;
    inorder_threaded_tree.PostOrderTraverse(visit);

    cout<<endl<<endl<<"------------------------- CyberDash -------------------------"<<endl;
    cout<<endl;
}
