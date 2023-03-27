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


void TestFirst() {

    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|              Test InOrder InorderThreadedBinaryTree First Node           |"<<endl;
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

    int count = 7;

    InorderThreadedBinaryTree<int> inorder_threaded_tree;

    for (int i = 0 ; i < count; i++) {
        inorder_threaded_tree.Insert(i);
    }

    inorder_threaded_tree.CreateThreadRecursive();

    ThreadedNode<int>* root_ptr = inorder_threaded_tree.Root();

    ThreadedNode<int>* first_node_ptr = inorder_threaded_tree.First(root_ptr);

    cout << "中序线索第一个线索节点 :" << first_node_ptr->data << endl;

    cout<<endl<<"------------------------- CyberDash -------------------------"<<endl;
    cout<<endl;
}


void TestLast() {

    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|              Test InOrder InorderThreadedBinaryTree Last Node            |"<<endl;
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

    int count = 7;

    InorderThreadedBinaryTree<int> inorder_threaded_tree;

    for (int i = 0 ; i < count; i++) {
        inorder_threaded_tree.Insert(i);
    }

    inorder_threaded_tree.CreateThreadRecursive();

    ThreadedNode<int>* root_ptr = inorder_threaded_tree.Root();

    ThreadedNode<int>* last_node_ptr = inorder_threaded_tree.Last(root_ptr);

    cout << "中序线索最后一个线索节点: " << last_node_ptr->data << endl;

    cout<<endl<<"------------------------- CyberDash -------------------------"<<endl;
    cout<<endl;
}


void TestNext() {

    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|              Test InOrder InorderThreadedBinaryTree Next Node            |"<<endl;
    cout<<"|                  测试中序线索树下一个线索节点                 |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                             0                             |"<<endl;
    cout<<"|                            / \\                            |"<<endl;
    cout<<"|                           /   \\                           |"<<endl;
    cout<<"|                          1     2                          |"<<endl;
    cout<<"|                         / \\   /                           |"<<endl;
    cout<<"|                        3   5 4                            |"<<endl;
    cout<<"|                       /                                   |"<<endl;
    cout<<"|                      6                                    |"<<endl<<endl;

    int count = 7;

    InorderThreadedBinaryTree<int> inorder_threaded_tree;

    for (int i = 0 ; i < count; i++) {
        inorder_threaded_tree.Insert(i);
    }

    inorder_threaded_tree.CreateThreadRecursive();

    ThreadedNode<int>* first_node_ptr = inorder_threaded_tree.First(inorder_threaded_tree.Root());

    ThreadedNode<int>* second_node_ptr = inorder_threaded_tree.Next(first_node_ptr);
    ThreadedNode<int>* third_node_ptr = inorder_threaded_tree.Next(second_node_ptr);
    ThreadedNode<int>* forth_node_ptr = inorder_threaded_tree.Next(third_node_ptr);

    cout << "中序线索树第1个线索节点: " << first_node_ptr->data << endl;
    cout << "中序线索树第2个线索节点: " << second_node_ptr->data << endl;
    cout << "中序线索树第3个线索节点: " << third_node_ptr->data << endl;
    cout << "中序线索树第4个线索节点: " << forth_node_ptr->data << endl;

    cout<<endl<<"------------------------- CyberDash -------------------------"<<endl;
    cout<<endl;
}


void TestPrior() {

    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|             Test InOrder InorderThreadedBinaryTree Pre Node            |"<<endl;
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

    int count = 7;

    ThreadedNode<int>* node_ptr_array[4];
    InorderThreadedBinaryTree<int> inorder_threaded_tree;

    for (int i = 0 ; i < count; i++) {
        inorder_threaded_tree.Insert(i);
    }

    inorder_threaded_tree.CreateThreadRecursive();

    node_ptr_array[0] = inorder_threaded_tree.First(inorder_threaded_tree.Root());

    for (int i = 1; i < 4; i++) {
        node_ptr_array[i] = inorder_threaded_tree.Next(node_ptr_array[i - 1]);
    }

    for (int i = 3; i >=1; i--) {
        ThreadedNode<int>* prior_node_ptr = inorder_threaded_tree.Pre(node_ptr_array[i]);
        cout << "中序线索树第" << i << "个线索节点: " << prior_node_ptr->data << endl; // (i - 1) + 1 = i
    }

    cout<<endl<<"------------------------- CyberDash -------------------------"<<endl;
    cout<<endl;
}


/*
 * 中序线索二叉树Parent
 */
void TestParent() {

    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|             Test InOrder InorderThreadedBinaryTree Parent Node           |"<<endl;
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

    int count = 7;

    InorderThreadedBinaryTree<int> inorder_threaded_tree;

    for (int i = 0 ; i < count; i++) {
        inorder_threaded_tree.Insert(i);
    }

    inorder_threaded_tree.CreateThreadRecursive();

    ThreadedNode<int>* root_ptr = inorder_threaded_tree.Root();
    ThreadedNode<int>* root_parent_ptr = inorder_threaded_tree.Parent(root_ptr);

    ThreadedNode<int>* first_node_ptr = inorder_threaded_tree.First(root_ptr);
    ThreadedNode<int>* first_parent_ptr = inorder_threaded_tree.Parent(first_node_ptr);
    ThreadedNode<int>* first_parent_parent_ptr = inorder_threaded_tree.Parent(first_parent_ptr);

    if (root_parent_ptr != NULL) {
        cout << "根节点的父节点: " << root_parent_ptr->data << endl;
    } else {
        cout<<"根节点的父节点为NULL"<<endl;
    }

    cout << "第一个线索节点: " << first_node_ptr->data << endl;
    cout << "第一个线索节点的父节点: " << first_parent_ptr->data << endl;
    cout << "第一个线索节点的父节点的父节点: " << first_parent_parent_ptr->data << endl;

    cout<<endl<<"------------------------- CyberDash -------------------------"<<endl;
    cout<<endl;
}


void TestInOrderTraverseOfInOrderThread() {

    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|          Test InOrder InorderThreadedBinaryTree InorderTraverse          |"<<endl;
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

    int count = 7;
    InorderThreadedBinaryTree<int> inorder_threaded_tree;

    for (int i = 0 ; i < count; i++) {
        inorder_threaded_tree.Insert(i);
    }

    inorder_threaded_tree.CreateThreadRecursive();

    cout<<"中序线索树, 中序遍历: "<<endl;
    inorder_threaded_tree.InorderTraverse(visit);

    cout<<endl<<endl<<"------------------------- CyberDash -------------------------"<<endl;
    cout<<endl;
}


void TestPreOrderTraverseOfInOrderThread() {

    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|          Test InOrder InorderThreadedBinaryTree PreorderTraverse         |"<<endl;
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

    int count = 7;
    InorderThreadedBinaryTree<int> inorder_threaded_tree;

    for (int i = 0 ; i < count; i++) {
        inorder_threaded_tree.Insert(i);
    }

    inorder_threaded_tree.CreateThreadRecursive();

    cout<<"中序线索树, 前序遍历: "<<endl;
    inorder_threaded_tree.PreorderTraverse(visit);

    cout<<endl<<endl<<"------------------------- CyberDash -------------------------"<<endl;
    cout<<endl;
}


void TestPostOrderTraverseOfInOrderThread() {

    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|          Test InOrder InorderThreadedBinaryTree PostOrderTraverse        |"<<endl;
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

    int count = 7;
    InorderThreadedBinaryTree<int> inorder_threaded_tree;

    for (int i = 0 ; i < count; i++) {
        inorder_threaded_tree.Insert(i);
    }

    inorder_threaded_tree.CreateThreadRecursive();

    cout<<"中序线索树, 后序遍历: "<<endl;
    inorder_threaded_tree.PostOrderTraverse(visit);

    cout<<endl<<endl<<"------------------------- CyberDash -------------------------"<<endl;
    cout<<endl;
}
