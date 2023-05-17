/*!
 * @file test.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 二叉搜索树测试cpp文件
 * @version 0.2.1
 * @date 2023-02-25
 */


#include "test.h"
#include "vector"


/*!
 * @brief **搜索二叉树结点打印**
 * @tparam Key 关键字类型模板参数
 * @tparam Value 值类型模板参数
 * @param node 结点
 * @note
 * 搜索二叉树结点打印
 * ---------------
 * ---------------
 *
 * ---------------
 */
template<typename Key, typename Value>
void BstNodePrint(BstNode<Key, Value>* node) {
    cout << "[" << node->Key() << ":" << node->Value() << "]";
}


/*!
 * @brief **AVL树结点打印**
 * @tparam Key 关键字类型模板参数
 * @tparam Value 值类型模板参数
 * @param node 结点
 * @note
 * AVL树结点打印
 * -----------
 * -----------
 *
 * -----------
 */
template<typename Key, typename Value>
void AvlNodeVisit(AvlNode<Key, Value>* node) {
    cout << "[" << node->Key() << ":" << node->Value() << "|" << node->BalanceFactor() << "]";
}


/*!
 * @brief **AVL树结点Key打印**
 * @tparam Key 关键字类型模板参数
 * @tparam Value 值类型模板参数
 * @param node 结点
 * @note
 * AVL树结点Key打印
 * --------------
 * --------------
 *
 * --------------
 */
template<typename Key, typename Value>
void AvlNodeKeyVisit(AvlNode<Key, Value>* node) {
    cout << node->Key() ;
}


/*!
 * @brief **二叉搜索树_插入结点_测试**
 * @note
 * 二叉搜索树_插入结点_测试
 * ---------------------
 * ---------------------
 *
 * ---------------------
 * 声明binary_search_tree(搜索二叉树)\n\n
 * 插入3个结点\n\n
 * 复制binary_search_tree给new_bst\n\n
 * 打印new_bst\n\n
 */
void TestBstInsert() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|            Test BinarySearchTree CopyConstructor          |" << endl;
    cout << "|                  测试搜索二叉树的复制构造函数                 |" << endl;

    // 声明binary_search_tree(搜索二叉树)
    BinarySearchTree<string, string>* binary_search_tree = new BinarySearchTree<string, string>();

    // 插入3个结点

    string question1 = "我最爱的乐队";
    string answer1 = "林肯公园";

    string question2 = "我最爱的游戏";
    string answer2 = "Dota2";

    string question3 = "我最爱的电影";
    string answer3 = "《黑客帝国》";

    binary_search_tree->InsertRecursive(question1, answer1);
    binary_search_tree->InsertRecursive(question2, answer2);
    binary_search_tree->InsertRecursive(question3, answer3);

    // 复制binary_search_tree给new_bst
    BinarySearchTree<string, string> new_bst = *binary_search_tree;

    // 打印new_bst
    new_bst.Print(BstNodePrint);

    cout << endl;

    cout << "-------------------------------------------------------------" << endl;
}


/*!
 * @brief **二叉搜索树_删除结点_测试**
 * @note
 * 二叉搜索树_删除结点_测试
 * ---------------------
 * ---------------------
 *
 * ---------------------
 * + **1 构造二叉搜索树**\n
 * 声明binary_search_tree(二叉搜索树)\n
 * 8个问答, 插入binary_search_tree\n
 * 打印binary_search_tree\n\n
 * + **2 测试删除结点**\n
 * 删除第1个问答\n
 * 打印binary_search_tree\n\n
 */
void TestBstRemove() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                Test BinarySearchTree Remove               |" << endl;
    cout << "|                     测试搜索二叉树的删除                     |" << endl;

    // ---------- 1 构造二叉搜索树 ----------

    // 声明binary_search_tree(二叉搜索树)

    BinarySearchTree<string, string>* binary_search_tree = new BinarySearchTree<string, string>();

    // 8个问答, 插入binary_search_tree

    string question1 = "最爱的乐队";
    string answer1 = "林肯公园";

    string question2 = "最爱的游戏";
    string answer2 = "Dota2";

    string question3 = "最爱的电影";
    string answer3 = "《黑客帝国》";

    string question4 = "最爱的运动";
    string answer4 = "足球";

    string question5 = "最讨厌的编程语言";
    string answer5 = "Java";

    string question6 = "如果暴富了想干嘛";
    string answer6 = "包养数学家";

    string question7 = "推荐几首歌听";
    string answer7 = "Learning To Survive|Final Masquerade|Nothing";

    string question8 = "最后随便说句话";
    string answer8 = "搞编程一定要爱这个世界, 否则只有折磨";

    binary_search_tree->InsertRecursive(question1, answer1);
    binary_search_tree->InsertRecursive(question2, answer2);
    binary_search_tree->InsertRecursive(question3, answer3);
    binary_search_tree->InsertRecursive(question4, answer4);
    binary_search_tree->InsertRecursive(question5, answer5);
    binary_search_tree->InsertRecursive(question6, answer6);
    binary_search_tree->InsertRecursive(question7, answer7);
    binary_search_tree->InsertRecursive(question8, answer8);

    // 打印binary_search_tree
    binary_search_tree->Print(BstNodePrint);

    cout << endl;

    // ---------- 2 测试删除结点 ----------

    // 删除第1个问答
    binary_search_tree->RemoveRecursive(question1);

    // 打印binary_search_tree
    binary_search_tree->Print(BstNodePrint);

    cout << endl;

    cout << "-------------------------------------------------------------" << endl;
}


/*!
 * @brief **二叉搜索树_搜索_测试**
 * @note
 * 二叉搜索树_搜索_测试
 * -----------------
 * -----------------
 *
 * -----------------
 * + **1 构造二叉搜索树**\n
 * 声明binary_search_tree(二叉搜索树)\n
 * 9个问答, 插入binary_search_tree\n\n
 * + **1 测试搜索**\n
 * 删除问答9\n\n
 * 搜索问答9, 并打印搜索结果\n
 * 搜索问答8, 并打印搜索结果\n
 */
void TestBstSearch() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                Test BinarySearchTree Search               |" << endl;
    cout << "|                     测试搜索二叉树的搜索                     |" << endl;

    // ---------- 1 构造二叉搜索树 ----------

    // 声明binary_search_tree(二叉搜索树)

    BinarySearchTree<string, string>* binary_search_tree = new BinarySearchTree<string, string>();

    // 9个问答, 插入binary_search_tree

    string question1 = "最爱的乐队";
    string answer1 = "林肯公园";

    string question2 = "最爱的游戏";
    string answer2 = "Dota2";

    string question3 = "最爱的电影";
    string answer3 = "《黑客帝国》";

    string question4 = "最爱的运动";
    string answer4 = "足球";

    string question5 = "最讨厌的编程语言";
    string answer5 = "Java";

    string question6 = "如果暴富了想干嘛";
    string answer6 = "包养数学家";

    string question7 = "推荐几首歌听";
    string answer7 = "Learning To Survive|Final Masquerade|Nothing";

    string question8 = "最后随便说句话";
    string answer8 = "搞编程一定要爱这个世界, 否则只有折磨";

    string question9 = "讲一件后悔的事儿";
    string answer9 = "烂到肚子里也不会说的";

    binary_search_tree->InsertRecursive(question1, answer1);
    binary_search_tree->InsertRecursive(question2, answer2);
    binary_search_tree->InsertRecursive(question3, answer3);
    binary_search_tree->InsertRecursive(question4, answer4);
    binary_search_tree->InsertRecursive(question5, answer5);
    binary_search_tree->InsertRecursive(question6, answer6);
    binary_search_tree->InsertRecursive(question7, answer7);
    binary_search_tree->InsertRecursive(question8, answer8);
    binary_search_tree->InsertRecursive(question9, answer9);

    // ---------- 2 测试搜索 ----------

    // 删除问答9
    binary_search_tree->RemoveRecursive(question9);

    // 搜索问答9, 并打印搜索结果
    BstNode<string, string>* node9 = binary_search_tree->Search(question9);
    if (node9 == NULL) {
        cout << "此问题已删除" << endl;
    } else {
        cout << "question9: " << node9->Key() << endl << "answer9: " << node9->Value() << endl;
    }

    cout << endl;

    // 搜索问答8, 并打印搜索结果
    BstNode<string, string>* node8 = binary_search_tree->Search(question8);
    if (node8 == NULL) {
        cout << "Duck不必" << endl;
    } else {
        cout << "question8: " << node8->Key() << endl << "answer8: " << node8->Value() << endl;
    }

    cout << endl;

    cout << "-------------------------------------------------------------" << endl;
}


/*!
 * @brief **AVL树_搜索_测试**
 * @note
 * AVL树_搜索_测试
 * -------------
 * -------------
 *
 * -------------
 * + **1 构造二叉搜索树**\n
 * 声明binary_search_tree(二叉搜索树)\n
 * 9个问答, 插入binary_search_tree\n\n
 * + **2 测试搜索**\n
 * 删除问答9\n\n
 * 搜索问答9, 并打印搜索结果\n
 * 搜索问答8, 并打印搜索结果\n
 */
void TestAvlSearch() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                      Test AVL Search                      |" << endl;
    cout << "|                       测试AVL树的搜索                       |" << endl;

    // ---------- 1 构造二叉搜索树 ----------

    // 声明binary_search_tree(二叉搜索树)

    AvlTree<string, string>* avl_tree = new AvlTree<string, string>();

    // 9个问答, 插入binary_search_tree

    string question1 = "最爱的乐队";
    string answer1 = "林肯公园";

    string question2 = "最爱的游戏";
    string answer2 = "Dota2";

    string question3 = "最爱的电影";
    string answer3 = "《黑客帝国》";

    string question4 = "最爱的运动";
    string answer4 = "足球";

    string question5 = "最讨厌的编程语言";
    string answer5 = "Java";

    string question6 = "如果暴富了想干嘛";
    string answer6 = "包养数学家";

    string question7 = "推荐几首歌听";
    string answer7 = "Learning To Survive|Final Masquerade|Nothing";

    string question8 = "最后随便说句话";
    string answer8 = "搞编程一定要爱这个世界, 否则只有折磨";

    string question9 = "讲一件后悔的事儿";
    string answer9 = "烂到肚子里也不会说的";

    avl_tree->Insert(question1, answer1);
    avl_tree->Insert(question2, answer2);
    avl_tree->Insert(question3, answer3);
    avl_tree->Insert(question4, answer4);
    avl_tree->Insert(question5, answer5);
    avl_tree->Insert(question6, answer6);
    avl_tree->Insert(question7, answer7);
    avl_tree->Insert(question8, answer8);
    avl_tree->Insert(question9, answer9);

    // ---------- 2 测试搜索 ----------

    // 删除问答9
    avl_tree->Remove(question9);

    // 搜索问答9, 并打印搜索结果
    AvlNode<string, string>* node9 = avl_tree->Search(question9);
    if (!node9) {
        cout << "此问题已删除" << endl;
    } else {
        cout << "question9: " << node9->Key() << endl << "answer9: " << node9->Value() << endl;
    }

    cout << endl;

    // 搜索问答8, 并打印搜索结果
    AvlNode<string, string>* node8 = avl_tree->Search(question8);
    if (!node8) {
        cout << "Duck不必" << endl;
    } else {
        cout << "question8: " << node8->Key() << endl << "answer8: " << node8->Value() << endl;
    }

    cout << endl;

    cout << "-------------------------------------------------------------" << endl;
}


/*!
 * @brief **二叉搜索树_最大值最小值_测试**
 * @note
 * 二叉搜索树_最大值最小值_测试
 * ------------------------
 * ------------------------
 *
 * ------------------------
 * + **1 构造二叉搜索树**\n
 * 声明binary_search_tree(二叉搜索树)\n
 * 9个问答, 插入binary_search_tree\n
 * 打印binary_search_tree\n\n
 * + **2 测试最大Key结点/最小Key结点**\n
 * 打印最大Key结点的值\n
 * 打印最小Key结点的值\n
 */
void TestBSTMaxAndMin() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|              Test BinarySearchTree Max and Min            |" << endl;
    cout << "|                  测试搜索二叉树的最大Key值/最小Key值                |" << endl;

    // ---------- 1 构造二叉搜索树 ----------

    // 声明binary_search_tree(二叉搜索树)

    BinarySearchTree<string, string>* binary_search_tree = new BinarySearchTree<string, string>();

    // 9个问答, 插入binary_search_tree

    string question1 = "最爱的乐队";
    string answer1 = "林肯公园";

    string question2 = "最爱的游戏";
    string answer2 = "Dota2";

    string question3 = "最爱的电影";
    string answer3 = "《黑客帝国》";

    string question4 = "最爱的运动";
    string answer4 = "足球";

    string question5 = "最讨厌的编程语言";
    string answer5 = "Java";

    string question6 = "如果暴富了想干嘛";
    string answer6 = "包养数学家";

    string question7 = "推荐几首歌听";
    string answer7 = "Learning To Survive|Final Masquerade|Nothing";

    string question8 = "最后随便说句话";
    string answer8 = "搞编程一定要爱这个世界, 否则只有折磨";

    string question9 = "讲一件后悔的事儿";
    string answer9 = "那些无法形容的痛, 见不得光";

    binary_search_tree->InsertRecursive(question1, answer1);
    binary_search_tree->InsertRecursive(question2, answer2);
    binary_search_tree->InsertRecursive(question3, answer3);
    binary_search_tree->InsertRecursive(question4, answer4);
    binary_search_tree->InsertRecursive(question5, answer5);
    binary_search_tree->InsertRecursive(question6, answer6);
    binary_search_tree->InsertRecursive(question7, answer7);
    binary_search_tree->InsertRecursive(question8, answer8);
    binary_search_tree->InsertRecursive(question9, answer9);

    // ---------- 2 测试最大Key结点/最小Key结点 ----------

    // 打印最大Key结点的值
    string max_data;
    bool res = binary_search_tree->Max(max_data);
    cout << "max_data: " << max_data << endl;

    // 打印最小Key结点的值
    string min_data;
    res = binary_search_tree->Min(min_data);
    cout << "min_data: " << min_data << endl;

    cout << "-------------------------------------------------------------" << endl;
}


/*!
 * @brief **AVL树_最大值最小值_测试**
 * @note
 * AVL树_最大值最小值_测试
 * --------------------
 * --------------------
 *
 * --------------------
 * + **1 构造avl树**\n
 * 声明avl_tree(平衡二叉树)\n
 * 9个问答, 插入avl_tree\n\n
 * + **2 测试最大Key结点/最小Key结点**\n
 * 打印最大Key结点的值\n
 * 打印最小Key结点的值\n
 */
void TestAVLMaxAndMin() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                     Test AVL Max & Min                    |" << endl;
    cout << "|                    测试AVL树的最大值/最小值                  |" << endl;

    // ---------- 1 构造avl树 ----------

    // 声明avl_tree(平衡二叉树)

    AvlTree<string, string>* avl_tree = new AvlTree<string, string>();

    // 9个问答, 插入avl_tree

    string question1 = "最爱的乐队";
    string answer1 = "林肯公园";

    string question2 = "最爱的游戏";
    string answer2 = "Dota2";

    string question3 = "最爱的电影";
    string answer3 = "《黑客帝国》";

    string question4 = "最爱的运动";
    string answer4 = "足球";

    string question5 = "最讨厌的编程语言";
    string answer5 = "Java";

    string question6 = "如果暴富了想干嘛";
    string answer6 = "包养数学家";

    string question7 = "推荐几首歌听";
    string answer7 = "Learning To Survive|Final Masquerade|Nothing";

    string question8 = "最后随便说句话";
    string answer8 = "搞编程一定要爱这个世界, 否则只有折磨";

    string question9 = "讲一件后悔的事儿";
    string answer9 = "那些无法形容的痛, 见不得光";

    avl_tree->Insert(question1, answer1);
    avl_tree->Insert(question2, answer2);
    avl_tree->Insert(question3, answer3);
    avl_tree->Insert(question4, answer4);
    avl_tree->Insert(question5, answer5);
    avl_tree->Insert(question6, answer6);
    avl_tree->Insert(question7, answer7);
    avl_tree->Insert(question8, answer8);
    avl_tree->Insert(question9, answer9);

    // ---------- 2 测试最大Key结点/最小Key结点 ----------

    // 打印最大Key结点的值
    string max_data;
    bool res = avl_tree->Max(max_data);
    if (res) {
        cout << "max_data: " << max_data << endl;
    }

    // 打印最小Key结点的值
    string min_data;
    res = avl_tree->Min(min_data);
    if (res) {
        cout << "min_data: " << min_data << endl;
    }

    cout << "-------------------------------------------------------------" << endl;
}


/*!
 * @brief **二叉搜索树_清空_测试**
 * @note
 * 二叉搜索树_清空_测试
 * -----------------
 * -----------------
 *
 * -----------------
 * 声明binary_search_tree(搜索二叉树)\n\n
 * 9个问答, 插入binary_search_tree\n\n
 * 清除binary_search_tree\n\n
 * 打印binary_search_tree\n
 */
void TestBstClear() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                Test BinarySearchTree Clear            |" << endl;
    cout << "|                      测试搜索二叉树的清除                    |" << endl;

    // ----- 声明binary_search_tree(搜索二叉树) -----

    BinarySearchTree<string, string>* binary_search_tree = new BinarySearchTree<string, string>();

    // ----- 9个问答, 插入binary_search_tree -----

    string question1 = "最爱的乐队";
    string answer1 = "林肯公园";

    string question2 = "最爱的游戏";
    string answer2 = "Dota2";

    string question3 = "最爱的电影";
    string answer3 = "《黑客帝国》";

    string question4 = "最爱的运动";
    string answer4 = "足球";

    string question5 = "最讨厌的编程语言";
    string answer5 = "Java";

    string question6 = "如果暴富了想干嘛";
    string answer6 = "包养数学家";

    string question7 = "推荐几首歌听";
    string answer7 = "Learning To Survive|Final Masquerade|Nothing";

    string question8 = "最后随便说句话";
    string answer8 = "搞编程一定要爱这个世界, 否则只有折磨";

    string question9 = "讲一件后悔的事儿";
    string answer9 = "烂到肚子里也不会说的";

    binary_search_tree->InsertRecursive(question1, answer1);
    binary_search_tree->InsertRecursive(question2, answer2);
    binary_search_tree->InsertRecursive(question3, answer3);
    binary_search_tree->InsertRecursive(question4, answer4);
    binary_search_tree->InsertRecursive(question5, answer5);
    binary_search_tree->InsertRecursive(question6, answer6);
    binary_search_tree->InsertRecursive(question7, answer7);
    binary_search_tree->InsertRecursive(question8, answer8);
    binary_search_tree->InsertRecursive(question9, answer9);

    // ----- 清除binary_search_tree -----

    binary_search_tree->Clear();

    // ----- 打印binary_search_tree -----

    binary_search_tree->Print(BstNodePrint);

    cout << "-------------------------------------------------------------" << endl;
}


/*!
 * @brief **AVL树_插入结点_测试**
 * @note
 * AVL树_插入节点_测试
 * -----------------
 * -----------------
 *
 * -----------------
 * 声明avl_tree(平衡二叉树)\n\n
 * 4个问答, 插入avl_tree\n\n
 * 打印avl_tree\n\n
 */
void TestAvlInsert() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                      Test AVL Insert                      |" << endl;
    cout << "|                     测试平衡二叉树的插入                     |" << endl;

    // 声明avl_tree(平衡二叉树)

    AvlTree<string, string>* AVL_tree = new AvlTree<string, string>();

    string question1 = "a";
    string answer1 = "a";

    string question2 = "d";
    string answer2 = "d";

    string question3 = "c";
    string answer3 = "c";

    string question4 = "b";
    string answer4 = "b";

    // 4个问答, 插入avl_tree

    AVL_tree->Insert(question1, answer1);
    AVL_tree->Insert(question2, answer2);
    AVL_tree->Insert(question3, answer3);
    AVL_tree->Insert(question4, answer4);

    // 打印avl_tree

    AVL_tree->Print(AvlNodeVisit);

    cout << endl;

    cout << "-------------------------------------------------------------" << endl;
}


/*!
 * @brief **AVL树_插入结点和删除结点_测试**
 * @note
 * AVL树_插入结点和删除结点_测试
 * --------------------------
 * --------------------------
 *
 * --------------------------
 * 声明avl_tree(平衡二叉树)\n\n
 * 初始化30对key/value\n\n
 * 每次插入1对key/value, 打印当前avl_tree\n\n
 * 每次删除1对key/value, 打印当前avl_tree\n
 */
void TestAvlInsertAndRemove() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                   Test AVL Insert/Remove                  |" << endl;
    cout << "|                    测试平衡二叉树的插入/删除                  |" << endl;

    // ----- 声明avl_tree(平衡二叉树) -----

    AvlTree<int, int>* avl_tree = new AvlTree<int, int>();

    // ----- 初始化30对key/value -----

    int keys[31] =
        { 9, 15, 5, 23, 27, 22, 7, 17, 8, 28,
          25, 12, 13, 14, 2, 26, 30, 18, 16, 20,
          21, 6, 4, 24, 11, 19, 3, 1, 29, 10, 10 };
    int values[31] =
        { 9, 15, 5, 23, 27, 22, 7, 17, 8, 28,
          25, 12, 13, 14, 2, 26, 30, 18, 16, 20,
          21, 6, 4, 24, 11, 19, 3, 1, 29, 10, 10 };
    int count = 30;

    // ----- 每次插入1对key/value, 打印当前avl_tree -----

    for (int i = 0; i < count; i++) {
        avl_tree->Insert(keys[i], values[i]);
        avl_tree->Print(AvlNodeKeyVisit);
    }

    // ----- 每次删除1对key/value, 打印当前avl_tree -----

    for (int i = 0; i < count; i++) {
        avl_tree->Remove(keys[i]);
        avl_tree->Print(AvlNodeKeyVisit);
    }

    cout << endl;

    cout << "-------------------------------------------------------------" << endl;
}


/*!
 * @brief **AVL树_插入结点(递归)和删除结点(递归)_测试**
 * @note
 * AVL树_插入结点(递归)和删除结点(递归)_测试
 * -------------------------------------
 * -------------------------------------
 *
 * -------------------------------------
 * 声明avl_tree(平衡二叉树)\n\n
 * 初始化30对key/value\n\n
 * 每次插入(使用递归方法)1对key/value, 打印当前avl_tree\n\n
 * 每次删除(使用递归方法)1对key/value, 打印当前avl_tree\n
 */
void TestAvlInsertAndRemoveRecursive() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|              Test AVL Insert/Remove recursive             |" << endl;
    cout << "|                 测试平衡二叉树的插入/删除(递归)               |" << endl;

    // ----- 声明avl_tree(平衡二叉树) -----

    AvlTree<int, int>* AVL_tree = new AvlTree<int, int>();

    // ----- 初始化30对key/value -----

    int keys[30] =
        { 9, 15, 5, 23, 27, 22, 7, 17, 8, 28,
          25, 12, 13, 14, 2, 26, 30, 18, 16, 20,
          21, 6, 4, 24, 11, 19, 3, 1, 29, 10 };
    int values[30] =
        { 9, 15, 5, 23, 27, 22, 7, 17, 8, 28,
          25, 12, 13, 14, 2, 26, 30, 18, 16, 20,
          21, 6, 4, 24, 11, 19, 3, 1, 29, 10 };
    int count = 30;

    // ----- 每次插入(使用递归方法)1对key/value, 打印当前avl_tree -----

    for (int i = 0; i < count; i++) {
        AVL_tree->InsertRecursive(keys[i], values[i]);
        AVL_tree->Print(AvlNodeKeyVisit);
    }

    // ----- 每次删除(使用递归方法)1对key/value, 打印当前avl_tree -----

    for (int i = 0; i < count; i++) {
        AVL_tree->RemoveRecursive(keys[i]);
        AVL_tree->Print(AvlNodeKeyVisit);
    }

    cout << endl;

    cout << "-------------------------------------------------------------" << endl;
}


/*!
 * @brief **二叉搜索树和AVL树_树高度_测试**
 * @note
 * 二叉搜索树和AVL树_树高度_测试
 * -------------------------
 * -------------------------
 *
 * -------------------------
 * 初始化26对key/value\n\n
 * 初始化bst_tree(二叉搜索树)和avl_tree(平衡二叉树)\n\n
 * 对两棵树插入26对key/value\n\n
 * 打印两棵树的高度\n
 */
void TestBstAndAvlHeight() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|              Test BinarySearchTree & AVL Height           |" << endl;
    cout << "|                   测试搜索二叉树/AVL树的高度                 |" << endl;

    // ----- 初始化26对key/value -----

    string keys[26] =
    { "a", "d", "b", "c", "e", "f", "g", "h", "i", "k", "l", "j", "z", "n", "o", "p", "q", "r", "s",
      "t", "u", "v", "w", "x", "y", "m"};
    string elements[26] =
    { "a", "d", "b", "c", "e", "f", "g", "h", "i", "k", "l", "j", "z", "n", "o", "p", "q", "r", "s",
      "t", "u", "v", "w", "x", "y", "m"};
    int count = 26;

    cout << "分别向BST和AVL树插入:" << endl;
    for (int i = 0; i < count; i++) {
        cout << "\"key:" << keys[i] << "/elem:" << elements[i] << "\"  ";
        if (i % 4 == 3 && i != 0) {
            cout << endl;
        }
    }

    // ----- 初始化bst_tree(二叉搜索树)和avl_tree(平衡二叉树) -----

    BinarySearchTree<string, string>* bst_tree = new BinarySearchTree<string, string>();
    AvlTree<string, string>* avl_tree = new AvlTree<string, string>();

    // ----- 对两棵树插入26对key/value -----

    for (int i = 0; i < count; i++) {
        bst_tree->InsertRecursive(keys[i], elements[i]);
    }

    for (int i = 0; i < count; i++) {
        avl_tree->Insert(keys[i], elements[i]);
    }

    cout << endl << endl;

    // ----- 打印两棵树的高度 -----

    cout << "BST树高度: " << bst_tree->Height() << endl;
    cout << "AVL树高度: " << avl_tree->Height() << endl;

    cout << "-------------------------------------------------------------" << endl;
}