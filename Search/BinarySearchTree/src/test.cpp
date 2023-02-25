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
void AVLNodeVisit(AvlNode<Key, Value>* node) {
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
void VisitKey(AvlNode<Key, Value>* node) {
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
 */
void TestBstInsert() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                Test BinarySearchTree Insert               |" << endl;
    cout << "|                     测试搜索二叉树的插入                     |" << endl;

    BinarySearchTree<string, string>* binary_search_tree = new BinarySearchTree<string, string>();

    string question1 = "我最爱的乐队";
    string answer1 = "林肯公园";

    string question2 = "我最爱的游戏";
    string answer2 = "Dota2";

    string question3 = "我最爱的电影";
    string answer3 = "《黑客帝国》";

    binary_search_tree->InsertRecursive(question1, answer1);
    binary_search_tree->InsertRecursive(question2, answer2);
    binary_search_tree->InsertRecursive(question3, answer3);

    BinarySearchTree<string, string> new_bst = *binary_search_tree;

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
 */
void TestBstRemove() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                Test BinarySearchTree Remove               |" << endl;
    cout << "|                     测试搜索二叉树的删除                     |" << endl;

    BinarySearchTree<string, string>* binary_search_tree = new BinarySearchTree<string, string>();

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

    binary_search_tree->Print(BstNodePrint);

    cout << endl;

    binary_search_tree->RemoveRecursive(question1);

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
 */
void TestBstSearch() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                Test BinarySearchTree Search               |" << endl;
    cout << "|                     测试搜索二叉树的搜索                     |" << endl;

    BinarySearchTree<string, string>* binary_search_tree = new BinarySearchTree<string, string>();

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

    binary_search_tree->RemoveRecursive(question9);

    BstNode<string, string>* the_9th_node = binary_search_tree->Search(question9);
    if (the_9th_node == NULL) { // 没有搜索到
        cout << "此问题已删除" << endl;
    } else { // 搜索到
        cout << "question9: " << the_9th_node->Key() << endl << "answer9: " << the_9th_node->Value() << endl;
    }

    cout << endl;

    BstNode<string, string>* the_8th_node = binary_search_tree->Search(question8);
    if (the_8th_node == NULL) { // 没有搜索到
        cout << "Duck不必" << endl;
    } else { // 搜索到
        cout << "question8: " << the_8th_node->Key() << endl << "answer8: " << the_8th_node->Value() << endl;
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
 */
void TestAvlSearch() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                      Test AVL Search                      |" << endl;
    cout << "|                       测试AVL树的搜索                       |" << endl;

    AvlTree<string, string>* AVL_tree = new AvlTree<string, string>();

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

    AVL_tree->Insert(question1, answer1);
    AVL_tree->Insert(question2, answer2);
    AVL_tree->Insert(question3, answer3);
    AVL_tree->Insert(question4, answer4);
    AVL_tree->Insert(question5, answer5);
    AVL_tree->Insert(question6, answer6);
    AVL_tree->Insert(question7, answer7);
    AVL_tree->Insert(question8, answer8);
    AVL_tree->Insert(question9, answer9);

    AVL_tree->Remove(question9);

    AvlNode<string, string>* the_9th_node = AVL_tree->Search(question9);
    if (!the_9th_node) { // 没有搜索到
        cout << "此问题已删除" << endl;
    } else { // 搜索到
        cout << "question9: " << the_9th_node->Key() << endl << "answer9: " << the_9th_node->Value() << endl;
    }

    cout << endl;

    AvlNode<string, string>* the_8th_node = AVL_tree->Search(question8);
    if (!the_8th_node) { // 没有搜索到
        cout << "Duck不必" << endl;
    } else { // 搜索到
        cout << "question8: " << the_8th_node->Key() << endl << "answer8: " << the_8th_node->Value() << endl;
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
 */
void TestBSTMaxAndMin() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|              Test BinarySearchTree Max and Min            |" << endl;
    cout << "|                  测试搜索二叉树的最大值/最小值                |" << endl;

    BinarySearchTree<string, string>* binary_search_tree = new BinarySearchTree<string, string>();

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

    string max_data;
    bool res = binary_search_tree->Max(max_data);
    cout << "max_data: " << max_data << endl;

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
 */
void TestAVLMaxAndMin() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                     Test AVL Max & Min                    |" << endl;
    cout << "|                    测试AVL树的最大值/最小值                  |" << endl;

    AvlTree<string, string>* AVL_tree = new AvlTree<string, string>();

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

    AVL_tree->Insert(question1, answer1);
    AVL_tree->Insert(question2, answer2);
    AVL_tree->Insert(question3, answer3);
    AVL_tree->Insert(question4, answer4);
    AVL_tree->Insert(question5, answer5);
    AVL_tree->Insert(question6, answer6);
    AVL_tree->Insert(question7, answer7);
    AVL_tree->Insert(question8, answer8);
    AVL_tree->Insert(question9, answer9);

    string max_data;
    bool res = AVL_tree->Max(max_data);
    if (res) {
        cout << "max_data: " << max_data << endl;
    }

    string min_data;
    res = AVL_tree->Min(min_data);
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
 */
void TestBstClear() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                Test BinarySearchTree Clear            |" << endl;
    cout << "|                      测试搜索二叉树的清除                    |" << endl;

    BinarySearchTree<string, string>* binary_search_tree = new BinarySearchTree<string, string>();

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

    binary_search_tree->Clear();

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
 */
void TestAVLInsert() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                      Test AVL Insert                      |" << endl;
    cout << "|                     测试平衡二叉树的插入                     |" << endl;

    AvlTree<string, string>* AVL_tree = new AvlTree<string, string>();

    string question1 = "a";
    string answer1 = "a";

    string question2 = "d";
    string answer2 = "d";

    string question3 = "c";
    string answer3 = "c";

    string question4 = "b";
    string answer4 = "b";

    AVL_tree->Insert(question1, answer1);
    AVL_tree->Insert(question2, answer2);
    AVL_tree->Insert(question3, answer3);
    AVL_tree->Insert(question4, answer4);

    AVL_tree->Print(AVLNodeVisit);

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
 */
void TestAvlInsertAndRemove() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                   Test AVL Insert/Remove                  |" << endl;
    cout << "|                    测试平衡二叉树的插入/删除                  |" << endl;

    AvlTree<int, int>* AVL_tree = new AvlTree<int, int>();

    int keys[31] =
        { 9, 15, 5, 23, 27, 22, 7, 17, 8, 28,
          25, 12, 13, 14, 2, 26, 30, 18, 16, 20,
          21, 6, 4, 24, 11, 19, 3, 1, 29, 10, 10 };
    int values[31] =
        { 9, 15, 5, 23, 27, 22, 7, 17, 8, 28,
          25, 12, 13, 14, 2, 26, 30, 18, 16, 20,
          21, 6, 4, 24, 11, 19, 3, 1, 29, 10, 10 };
    int count = 30;

    for (int i = 0; i < count; i++) {
        AVL_tree->Insert(keys[i], values[i]);
        AVL_tree->Print(VisitKey);
    }

    for (int i = 0; i < count; i++) {
        int key = keys[i];
        AVL_tree->Remove(key);
        AVL_tree->Print(VisitKey);
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
 */
void TestAvlInsertAndRemoveRecursive() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|              Test AVL Insert/Remove recursive             |" << endl;
    cout << "|                 测试平衡二叉树的插入/删除(递归)               |" << endl;

    AvlTree<int, int>* AVL_tree = new AvlTree<int, int>();

    int keys[30] =
        { 9, 15, 5, 23, 27, 22, 7, 17, 8, 28,
          25, 12, 13, 14, 2, 26, 30, 18, 16, 20,
          21, 6, 4, 24, 11, 19, 3, 1, 29, 10 };
    int values[30] =
        { 9, 15, 5, 23, 27, 22, 7, 17, 8, 28,
          25, 12, 13, 14, 2, 26, 30, 18, 16, 20,
          21, 6, 4, 24, 11, 19, 3, 1, 29, 10 };
    int count = 30;

    for (int i = 0; i < count; i++) {
        AVL_tree->InsertRecursive(keys[i], values[i]);
        AVL_tree->Print(VisitKey);
    }

    for (int i = 0; i < count; i++) {
        int key = keys[i];
        AVL_tree->RemoveRecursive(key);
        AVL_tree->Print(VisitKey);
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
 */
void TestBstAndAvlHeight() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|              Test BinarySearchTree & AVL Height           |" << endl;
    cout << "|                   测试搜索二叉树/AVL树的高度                 |" << endl;

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
        // 四个一行
        if (i % 4 == 3 && i != 0) {
            cout << endl;
        }
    }

    BinarySearchTree<string, string>* bst_tree = new BinarySearchTree<string, string>();
    AvlTree<string, string>* AVL_tree = new AvlTree<string, string>();

    for (int i = 0; i < count; i++) {
        bst_tree->InsertRecursive(keys[i], elements[i]);
    }

    for (int i = 0; i < count; i++) {
        AVL_tree->Insert(keys[i], elements[i]);
    }

    cout << endl << endl;

    cout << "BST树高度: " << bst_tree->Height() << endl;
    cout << "AVL树高度: " << AVL_tree->Height() << endl;

    cout << "-------------------------------------------------------------" << endl;
}