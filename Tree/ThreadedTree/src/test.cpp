/*!
 * @file test.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 线索树测试cpp文件
 * @version 0.2.1
 * @date 2021-05-13
 */

#include "inorder_threaded_binary_tree.h"


/*!
 * @brief **结点访问函数**
 * @param node 结点
 * @note
 * 结点访问函数
 * ----------
 * ----------
 */
void visit(ThreadedNode<int>* node) {
    cout << node->data << " ";
};


/*!
 * @brief **测试-中序线索树-获取子树首个线索节点**
 * @note
 * 测试-中序线索树-获取子树首个线索节点
 * -------------------------------
 * -------------------------------
 *
 * -------------------------------
 * + **1 构造线索树**\n
 * 声明inorder_threaded_tree\n
 * 插入整数0至6\n
 * 调用CreateThreadRecursive构造线索\n\n
 * + **2 打印线索树的首结点数据项**\n
 * 获取根结点\n
 * 对根结点调用First()\n
 * 打印首结点数据项\n
 *
 *
 * -------------------------------
 */
void TestInorderThreadedTreeFirst() {

    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|            Test InorderThreadedBinaryTree First           |"<<endl;
    cout<<"|            测试-中序线索树-获取子树首个线索节点           |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                             0                             |"<<endl;
    cout<<"|                            / \\                            |"<<endl;
    cout<<"|                           /   \\                           |"<<endl;
    cout<<"|                          1     2                          |"<<endl;
    cout<<"|                         / \\   /                           |"<<endl;
    cout<<"|                        3   5 4                            |"<<endl;
    cout<<"|                       /                                   |"<<endl;
    cout<<"|                      6                                    |"<<endl<<endl;

    // ---------- 1 构造线索树 ----------

    InorderThreadedBinaryTree<int> inorder_threaded_tree;                               // 声明inorder_threaded_tree

    int node_count = 7;
    for (int i = 0 ; i < node_count; i++) {                                             // 插入整数0至6
        inorder_threaded_tree.InsertRecursive(i);
    }

    inorder_threaded_tree.CreateThreadRecursive();                                      // 调用CreateThreadRecursive构造线索

    // ---------- 2 打印线索树的首结点数据项 ----------

    ThreadedNode<int>* root = inorder_threaded_tree.Root();                             // 获取根结点
    ThreadedNode<int>* first = inorder_threaded_tree.First(root);                       // 对根结点调用First()

    cout << "中序线索第一个线索节点 :" << first->data << endl;                              // 打印首结点数据项

    cout<<endl<<"------------------------- CyberDash -------------------------"<<endl;
    cout<<endl;
}


/*!
 * @brief **测试-中序线索树-获取子树最后一个线索节点**
 * @note
 * 测试-中序线索树-获取子树最后一个线索节点
 * -----------------------------------
 * -----------------------------------
 *
 * -----------------------------------
 * + **1 构造线索树**\n\n
 * 声明inorder_threaded_tree\n
 * 插入整数0至6\n
 * 调用CreateThreadRecursive构造线索\n\n
 * + **2 打印线索树的最后的结点数据项**\n\n
 * 获取根结点\n
 * 对根结点调用Last()\n
 * 打印最后的线索结点数据项\n
 *
 *
 * -----------------------------------
 */
void TestInorderThreadedTreeLast() {

    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|             Test InorderThreadedBinaryTree Last           |"<<endl;
    cout<<"|           测试-中序线索树-获取子树最后一个线索节点        |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                             0                             |"<<endl;
    cout<<"|                            / \\                            |"<<endl;
    cout<<"|                           /   \\                           |"<<endl;
    cout<<"|                          1     2                          |"<<endl;
    cout<<"|                         / \\   /                           |"<<endl;
    cout<<"|                        3   5 4                            |"<<endl;
    cout<<"|                       /                                   |"<<endl;
    cout<<"|                      6                                    |"<<endl<<endl;

    // ---------- 1 构造线索树 ----------

    InorderThreadedBinaryTree<int> inorder_threaded_tree;                               // 声明inorder_threaded_tree

    int node_count = 7;
    for (int i = 0 ; i < node_count; i++) {
        inorder_threaded_tree.InsertRecursive(i);                                       // 插入整数0至6
    }

    inorder_threaded_tree.CreateThreadRecursive();                                      //调用CreateThreadRecursive构造线索

    // ---------- 2 打印线索树的最后的结点数据项 ----------

    ThreadedNode<int>* root = inorder_threaded_tree.Root();                             // 获取根结点
    ThreadedNode<int>* last_node = inorder_threaded_tree.Last(root);                    // 对根结点调用Last()

    cout << "中序线索最后一个线索节点: " << last_node->data << endl;                        // 打印最后的线索结点数据项

    cout<<endl<<"------------------------- CyberDash -------------------------"<<endl;
    cout<<endl;
}


/*!
 * @brief **测试-中序线索树-下一个线索结点**
 * @note
 * 测试-中序线索树-下一个线索结点
 * -------------------------
 * -------------------------
 *
 * -------------------------
 * + **1 构造线索树**\n\n
 * 声明inorder_threaded_tree\n
 * 插入整数0至6\n
 * 调用CreateThreadRecursive构造线索\n\n
 * + **2 打印线索树的前4个结点的数据项**\n\n
 * 按线索顺序获取7个结点\n
 * 打印7个线索结点的数据项\n
 *
 *
 * -------------------------
 */
void TestInorderThreadedTreeNext() {

    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|              Test InorderThreadedBinaryTree Next          |"<<endl;
    cout<<"|                测试-中序线索树-下一个线索节点             |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                             0                             |"<<endl;
    cout<<"|                            / \\                            |"<<endl;
    cout<<"|                           /   \\                           |"<<endl;
    cout<<"|                          1     2                          |"<<endl;
    cout<<"|                         / \\   /                           |"<<endl;
    cout<<"|                        3   5 4                            |"<<endl;
    cout<<"|                       /                                   |"<<endl;
    cout<<"|                      6                                    |"<<endl<<endl;

    // ---------- 1 构造线索树 ----------

    // 声明inorder_threaded_tree
    InorderThreadedBinaryTree<int> inorder_threaded_tree;

    // 插入整数0至6
    int node_count = 7;
    for (int i = 0 ; i < node_count; i++) {
        inorder_threaded_tree.InsertRecursive(i);
    }

    // 调用CreateThreadRecursive构造线索
    inorder_threaded_tree.CreateThreadRecursive();

    // ---------- 2 打印线索树的前4个结点的数据项 ----------

    // 按线索顺序获取7个结点
    ThreadedNode<int>* first = inorder_threaded_tree.First(inorder_threaded_tree.Root());
    ThreadedNode<int>* second = inorder_threaded_tree.Next(first);
    ThreadedNode<int>* third = inorder_threaded_tree.Next(second);
    ThreadedNode<int>* forth = inorder_threaded_tree.Next(third);
    ThreadedNode<int>* fifth = inorder_threaded_tree.Next(forth);
    ThreadedNode<int>* sixth = inorder_threaded_tree.Next(fifth);
    ThreadedNode<int>* seventh = inorder_threaded_tree.Next(sixth);

    // 打印7个线索结点的数据项
    cout << "中序线索树第1个线索节点: " << first->data << endl;
    cout << "中序线索树第2个线索节点: " << second->data << endl;
    cout << "中序线索树第3个线索节点: " << third->data << endl;
    cout << "中序线索树第4个线索节点: " << forth->data << endl;
    cout << "中序线索树第5个线索节点: " << fifth->data << endl;
    cout << "中序线索树第6个线索节点: " << sixth->data << endl;
    cout << "中序线索树第7个线索节点: " << seventh->data << endl;

    cout<<endl<<"------------------------- CyberDash -------------------------"<<endl;
    cout<<endl;
}


/*!
 * @brief **测试-中序线索树-前一个线索节点**
 * @note
 * 测试-中序线索树-前一个线索节点
 * -------------------------
 * -------------------------
 *
 * -------------------------
 * + **1 构造线索树**\n\n
 * 声明inorder_threaded_tree\n
 * 插入整数0至6\n
 * 调用CreateThreadRecursive构造线索\n\n
 * + **2 测试Pre函数**\n\n
 * 声明nodes(结点数组, 长度4)\n
 * nodes[0]取线索树首个线索结点\n
 * nodes[1]至nodes[3]依次取后序结点\n
 * 检测Pre函数\n
 */
void TestInorderThreadedTreePre() {
    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|             Test InorderThreadedBinaryTree Pre            |"<<endl;
    cout<<"|               测试-中序线索树-前一个线索节点              |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                             0                             |"<<endl;
    cout<<"|                            / \\                            |"<<endl;
    cout<<"|                           /   \\                           |"<<endl;
    cout<<"|                          1     2                          |"<<endl;
    cout<<"|                         / \\   /                           |"<<endl;
    cout<<"|                        3   5 4                            |"<<endl;
    cout<<"|                       /                                   |"<<endl;
    cout<<"|                      6                                    |"<<endl<<endl;

    // ---------- 1 构造线索树 ----------

    // 声明inorder_threaded_tree
    InorderThreadedBinaryTree<int> inorder_threaded_tree;

    int node_count = 7;
    // 插入整数0至6
    for (int i = 0 ; i < node_count; i++) {
        inorder_threaded_tree.InsertRecursive(i);
    }

    // 调用CreateThreadRecursive构造线索
    inorder_threaded_tree.CreateThreadRecursive();

    // ---------- 2 测试Pre函数 ----------

    // 声明nodes(结点数组, 长度4)
    ThreadedNode<int>* nodes[4];

    // nodes[0]取线索树首个线索结点
    nodes[0] = inorder_threaded_tree.First(inorder_threaded_tree.Root());

    // nodes[1]至nodes[3]依次取后序结点
    for (int i = 1; i < 4; i++) {
        nodes[i] = inorder_threaded_tree.Next(nodes[i - 1]);
    }

    // 检测Pre函数
    for (int i = 3; i >=1; i--) {
        ThreadedNode<int>* pre_node = inorder_threaded_tree.Pre(nodes[i]);
        cout << "中序线索树第" << i << "个线索节点: " << pre_node->data << endl;
    }

    cout<<endl<<"------------------------- CyberDash -------------------------"<<endl;
    cout<<endl;
}


/*!
 * @brief **测试-中序线索树-父节点**
 * @note
 * 测试-中序线索树-父节点
 * ------------------
 * ------------------
 *
 * ------------------
 * + **1 构造线索树**\n\n
 * 声明inorder_threaded_tree\n
 * 插入整数0至6\n
 * 调用CreateThreadRecursive构造线索\n\n
 * + **2 检测Parent函数**\n\n
 * 取根结点, 结点2, 结点4, 根结点的父节点\n
 * 取结点6, 结点3, 结点1, 结点5, 结点5的父节点, 结点4的父节点, 结点2的父节点\n
 * 打印相关结点信息\n
 */
void TestInorderThreadedTreeParent() {

    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|            Test InorderThreadedBinaryTree Parent          |"<<endl;
    cout<<"|                   测试-中序线索树-父节点                  |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                             0                             |"<<endl;
    cout<<"|                            / \\                            |"<<endl;
    cout<<"|                           /   \\                           |"<<endl;
    cout<<"|                          1     2                          |"<<endl;
    cout<<"|                         / \\   /                           |"<<endl;
    cout<<"|                        3   5 4                            |"<<endl;
    cout<<"|                       /                                   |"<<endl;
    cout<<"|                      6                                    |"<<endl<<endl;

    // ---------- 1 构造线索树 ----------

    // 声明inorder_threaded_tree
    InorderThreadedBinaryTree<int> inorder_threaded_tree;

    int node_count = 7;
    // 插入整数0至6
    for (int i = 0 ; i < node_count; i++) {
        inorder_threaded_tree.InsertRecursive(i);
    }

    // 调用CreateThreadRecursive构造线索
    inorder_threaded_tree.CreateThreadRecursive();

    // ---------- 2 检测Parent函数 ----------

    // 取根结点, 结点2, 结点4, 根结点的父节点
    ThreadedNode<int>* root = inorder_threaded_tree.Root();
    ThreadedNode<int>* node_2 = root->right_child;
    ThreadedNode<int>* node_4 = node_2->left_child;
    ThreadedNode<int>* root_parent = inorder_threaded_tree.Parent(root);

    // 取结点6, 结点3, 结点1, 结点5, 结点5的父节点, 结点4的父节点, 结点2的父节点
    ThreadedNode<int>* node_6 = inorder_threaded_tree.First(root);
    ThreadedNode<int>* node_3 = inorder_threaded_tree.Parent(node_6);
    ThreadedNode<int>* node_1 = inorder_threaded_tree.Parent(node_3);
    ThreadedNode<int>* node_5 = node_1->right_child;
    ThreadedNode<int>* node_5_parent = inorder_threaded_tree.Parent(node_5);
    ThreadedNode<int>* node_4_parent = inorder_threaded_tree.Parent(node_4);
    ThreadedNode<int>* node_2_parent = inorder_threaded_tree.Parent(node_2);

    // 打印相关结点信息
    if (root_parent != nullptr) {
        cout << "根节点的父节点: " << root_parent->data << endl;
    } else {
        cout<<"根节点的父节点为NULL"<<endl;
    }
    cout << "结点6的父结点: " << node_3->data << endl;
    cout << "结点3的父结点: " << node_1->data << endl;
    cout << "结点5的父结点: " << node_5_parent->data << endl;
    cout << "结点4的父结点: " << node_4_parent->data << endl;
    cout << "结点2的父结点: " << node_2_parent->data << endl;

    cout << endl << "------------------------- CyberDash -------------------------" << endl << endl;
}


/*!
 * @brief **测试-中序线索树-中序遍历**
 * @note
 * 测试-中序线索树-中序遍历
 * --------------------
 * --------------------
 *
 * --------------------
 * + **1 构造线索树**\n\n
 * 声明inorder_threaded_tree\n
 * 插入整数0至6\n
 * 调用CreateThreadRecursive构造线索\n\n
 * + **2 中序遍历**\n\n
 * 调用InorderTraverse\n
 *
 *
 * --------------------
 */
void TestInorderThreadedTreeInorderTraverse() {

    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|          Test InorderThreadedTree InorderTraverse         |"<<endl;
    cout<<"|                  测试-中序线索树-中序遍历                 |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                             0                             |"<<endl;
    cout<<"|                            / \\                            |"<<endl;
    cout<<"|                           /   \\                           |"<<endl;
    cout<<"|                          1     2                          |"<<endl;
    cout<<"|                         / \\   /                           |"<<endl;
    cout<<"|                        3   5 4                            |"<<endl;
    cout<<"|                       /                                   |"<<endl;
    cout<<"|                      6                                    |"<<endl<<endl;

    // ---------- 1 构造线索树 ----------

    // 声明inorder_threaded_tree
    InorderThreadedBinaryTree<int> inorder_threaded_tree;

    int node_count = 7;
    // 插入整数0至6
    for (int i = 0 ; i < node_count; i++) {
        inorder_threaded_tree.InsertRecursive(i);
    }

    // 调用CreateThreadRecursive构造线索
    inorder_threaded_tree.CreateThreadRecursive();

    // ---------- 2 中序遍历 ----------

    cout<<"中序线索树, 中序遍历: "<<endl;
    inorder_threaded_tree.InorderTraverse(visit);                       // 调用InorderTraverse

    cout<<endl<<endl<<"------------------------- CyberDash -------------------------"<<endl;
    cout<<endl;
}


/*!
 * @brief **测试-中序线索树-前序遍历**
 * @note
 * 测试-中序线索树-前序遍历
 * --------------------
 * --------------------
 *
 * --------------------
 * + **1 构造线索树**\n\n
 * 声明inorder_threaded_tree\n
 * 插入整数0至6\n
 * 调用CreateThreadRecursive构造线索\n\n
 * + **2 前序遍历**\n\n
 * 调用PreorderTraverse\n
 *
 *
 * --------------------
 */
void TestInorderThreadedTreePreorderTraverse() {
    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|          Test InorderThreadedTree PreorderTraverse        |"<<endl;
    cout<<"|                  测试-中序线索树-前序遍历                 |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                             0                             |"<<endl;
    cout<<"|                            / \\                            |"<<endl;
    cout<<"|                           /   \\                           |"<<endl;
    cout<<"|                          1     2                          |"<<endl;
    cout<<"|                         / \\   /                           |"<<endl;
    cout<<"|                        3   5 4                            |"<<endl;
    cout<<"|                       /                                   |"<<endl;
    cout<<"|                      6                                    |"<<endl<<endl;

    // ---------- 1 构造线索树 ----------

    // 声明inorder_threaded_tree
    InorderThreadedBinaryTree<int> inorder_threaded_tree;

    int node_count = 7;
    // 插入整数0至6
    for (int i = 0 ; i < node_count; i++) {
        inorder_threaded_tree.InsertRecursive(i);
    }

    // 调用CreateThreadRecursive构造线索
    inorder_threaded_tree.CreateThreadRecursive();

    // ---------- 2 前序遍历 ----------

    cout<<"中序线索树, 前序遍历: "<<endl;
    inorder_threaded_tree.PreorderTraverse(visit);                       // 调用PreorderTraverse

    cout<<endl<<endl<<"------------------------- CyberDash -------------------------"<<endl;
    cout<<endl;
}


/*!
 * @brief **测试-中序线索树-后序遍历**
 * @note
 * 测试-中序线索树-后序遍历
 * --------------------
 * --------------------
 *
 * --------------------
 * + **1 构造线索树**\n\n
 * 声明inorder_threaded_tree\n
 * 插入整数0至6\n
 * 调用CreateThreadRecursive构造线索\n\n
 * + **2 后序遍历**\n\n
 * 调用PostorderTraverse\n
 *
 *
 * --------------------
 */
void TestInorderThreadedTreePostorderTraverse() {

    cout<<endl;
    cout<<"|------------------------ CyberDash ------------------------|"<<endl;
    cout<<"|          Test InorderThreadedTree PostorderTraverse       |"<<endl;
    cout<<"|                  测试-中序线索树-后序遍历                 |"<<endl;
    cout<<"|                                                           |"<<endl;
    cout<<"|                             0                             |"<<endl;
    cout<<"|                            / \\                            |"<<endl;
    cout<<"|                           /   \\                           |"<<endl;
    cout<<"|                          1     2                          |"<<endl;
    cout<<"|                         / \\   /                           |"<<endl;
    cout<<"|                        3   5 4                            |"<<endl;
    cout<<"|                       /                                   |"<<endl;
    cout<<"|                      6                                    |"<<endl<<endl;

    // ---------- 1 构造线索树 ----------

    // 声明inorder_threaded_tree
    InorderThreadedBinaryTree<int> inorder_threaded_tree;

    int node_count = 7;
    // 插入整数0至6
    for (int i = 0 ; i < node_count; i++) {
        inorder_threaded_tree.InsertRecursive(i);
    }

    // 调用CreateThreadRecursive构造线索
    inorder_threaded_tree.CreateThreadRecursive();

    // ---------- 2 后序遍历 ----------

    cout<<"中序线索树, 后序遍历: "<<endl;
    inorder_threaded_tree.PostorderTraverse(visit);                       // 调用PostorderTraverse

    cout<<endl<<endl<<"------------------------- CyberDash -------------------------"<<endl;
    cout<<endl;
}
