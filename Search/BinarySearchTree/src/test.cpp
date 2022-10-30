//
// Created by cyberdash@163.com on 2021/6/26.
//


#include "test.h"
#include "vector"


template<class Value, class Key>
void BSTNodeVisit(BSTNode<Value, Key>* node) {
    cout << "[" << node->GetKey() << ":" << node->GetValue() << "]";
}


template<class Value, class Key>
void AVLNodeVisit(AVLNode<Value, Key>* node) {
    cout << "[" << node->GetKey() << ":" << node->GetValue() << "|" << node->GetBalanceFactor() << "]";
}


template<class Value, class Key>
void VisitKey(AVLNode<Value, Key>* node) {
    cout << node->GetKey() ;
}


void TestBSTInsert() {
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

    binary_search_tree->Insert(question1, answer1);
    binary_search_tree->Insert(question2, answer2);
    binary_search_tree->Insert(question3, answer3);

    binary_search_tree->PrintTree(BSTNodeVisit);

    cout << endl;

    cout << "-------------------------------------------------------------" << endl;
}


void TestBSTRemove() {
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

    binary_search_tree->Insert(question1, answer1);
    binary_search_tree->Insert(question2, answer2);
    binary_search_tree->Insert(question3, answer3);
    binary_search_tree->Insert(question4, answer4);
    binary_search_tree->Insert(question5, answer5);
    binary_search_tree->Insert(question6, answer6);
    binary_search_tree->Insert(question7, answer7);
    binary_search_tree->Insert(question8, answer8);

    binary_search_tree->PrintTree(BSTNodeVisit);

    cout << endl;

    binary_search_tree->Remove(question1);

    binary_search_tree->PrintTree(BSTNodeVisit);

    cout << endl;

    cout << "-------------------------------------------------------------" << endl;
}


void TestBSTSearch() {
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

    binary_search_tree->Insert(question1, answer1);
    binary_search_tree->Insert(question2, answer2);
    binary_search_tree->Insert(question3, answer3);
    binary_search_tree->Insert(question4, answer4);
    binary_search_tree->Insert(question5, answer5);
    binary_search_tree->Insert(question6, answer6);
    binary_search_tree->Insert(question7, answer7);
    binary_search_tree->Insert(question8, answer8);
    binary_search_tree->Insert(question9, answer9);

    binary_search_tree->Remove(question9);

    BSTNode<string, string>* the_9th_node = binary_search_tree->Search(question9);
    if (the_9th_node == NULL) { // 没有搜索到
        cout << "此问题已删除" << endl;
    } else { // 搜索到
        cout << "question9: " << the_9th_node->GetKey() << endl << "answer9: " << the_9th_node->GetValue() << endl;
    }

    cout << endl;

    BSTNode<string, string>* the_8th_node = binary_search_tree->Search(question8);
    if (the_8th_node == NULL) { // 没有搜索到
        cout << "Duck不必" << endl;
    } else { // 搜索到
        cout << "question8: " << the_8th_node->GetKey() << endl << "answer8: " << the_8th_node->GetValue() << endl;
    }

    cout << endl;

    cout << "-------------------------------------------------------------" << endl;
}


void TestAVLSearch() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                      Test AVL Search                      |" << endl;
    cout << "|                       测试AVL树的搜索                       |" << endl;

    AVLTree<string, string>* AVL_tree = new AVLTree<string, string>();

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

    AVLNode<string, string>* the_9th_node = AVL_tree->Search(question9);
    if (!the_9th_node) { // 没有搜索到
        cout << "此问题已删除" << endl;
    } else { // 搜索到
        cout << "question9: " << the_9th_node->GetKey() << endl << "answer9: " << the_9th_node->GetValue() << endl;
    }

    cout << endl;

    AVLNode<string, string>* the_8th_node = AVL_tree->Search(question8);
    if (!the_8th_node) { // 没有搜索到
        cout << "Duck不必" << endl;
    } else { // 搜索到
        cout << "question8: " << the_8th_node->GetKey() << endl << "answer8: " << the_8th_node->GetValue() << endl;
    }

    cout << endl;

    cout << "-------------------------------------------------------------" << endl;
}


void TestBSTMaxAndMin() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|              Test BinarySearchTree Max and Min            |" << endl;
    cout << "|                  测试搜索二叉树的最大值/最小值                 |" << endl;

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

    binary_search_tree->Insert(question1, answer1);
    binary_search_tree->Insert(question2, answer2);
    binary_search_tree->Insert(question3, answer3);
    binary_search_tree->Insert(question4, answer4);
    binary_search_tree->Insert(question5, answer5);
    binary_search_tree->Insert(question6, answer6);
    binary_search_tree->Insert(question7, answer7);
    binary_search_tree->Insert(question8, answer8);
    binary_search_tree->Insert(question9, answer9);

    string max_data = binary_search_tree->Max();
    cout << "max_data: " << max_data << endl;

    string min_data = binary_search_tree->Min();
    cout << "min_data: " << min_data << endl;

    cout << "-------------------------------------------------------------" << endl;
}


void TestAVLMaxAndMin() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                     Test AVL Max & Min                    |" << endl;
    cout << "|                    测试AVL树的最大值/最小值                  |" << endl;

    AVLTree<string, string>* AVL_tree = new AVLTree<string, string>();

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

    string max_data = AVL_tree->Max();
    cout << "max_data: " << max_data << endl;

    string min_data = AVL_tree->Min();
    cout << "min_data: " << min_data << endl;

    cout << "-------------------------------------------------------------" << endl;
}


void TestBSTMin() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                 Test BinarySearchTree Min                 |" << endl;
    cout << "|                     测试搜索二叉树的最小值                    |" << endl;

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

    binary_search_tree->Insert(question1, answer1);
    binary_search_tree->Insert(question2, answer2);
    binary_search_tree->Insert(question3, answer3);
    binary_search_tree->Insert(question4, answer4);
    binary_search_tree->Insert(question5, answer5);
    binary_search_tree->Insert(question6, answer6);
    binary_search_tree->Insert(question7, answer7);
    binary_search_tree->Insert(question8, answer8);
    binary_search_tree->Insert(question9, answer9);

    string minData = binary_search_tree->Min();

    cout << "minData: " << minData << endl;

    cout << "-------------------------------------------------------------" << endl;
}


void TestBSTMakeEmpty() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                Test BinarySearchTree MakeEmpty            |" << endl;
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

    binary_search_tree->Insert(question1, answer1);
    binary_search_tree->Insert(question2, answer2);
    binary_search_tree->Insert(question3, answer3);
    binary_search_tree->Insert(question4, answer4);
    binary_search_tree->Insert(question5, answer5);
    binary_search_tree->Insert(question6, answer6);
    binary_search_tree->Insert(question7, answer7);
    binary_search_tree->Insert(question8, answer8);
    binary_search_tree->Insert(question9, answer9);

    binary_search_tree->MakeEmpty();

    binary_search_tree->PrintTree(BSTNodeVisit);

    cout << "-------------------------------------------------------------" << endl;
}


void TestAVLInsert() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                      Test AVL Insert                      |" << endl;
    cout << "|                     测试平衡二叉树的插入                     |" << endl;

    AVLTree<string, string>* AVL_tree = new AVLTree<string, string>();

    string question1 = "我最爱的乐队";
    string answer1 = "林肯公园";

    string question2 = "我最爱的游戏";
    string answer2 = "Dota2";

    string question3 = "我最爱的电影";
    string answer3 = "《黑客帝国》";

    string question4 = "最爱的运动";
    string answer4 = "足球";

    AVL_tree->Insert(question1, answer1);
    AVL_tree->Insert(question2, answer2);
    AVL_tree->Insert(question3, answer3);
    AVL_tree->Insert(question4, answer4);

    AVL_tree->Print(AVLNodeVisit);

    cout << endl;

    cout << "-------------------------------------------------------------" << endl;
}


void TestAVLInsert2() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                     Test AVL Insert2                      |" << endl;
    cout << "|                    测试平衡二叉树的插入2                     |" << endl;

    AVLTree<string, string>* AVL_tree = new AVLTree<string, string>();

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


void TestAVLInsertByCyberDash() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                      Test AVL Insert                      |" << endl;
    cout << "|                     测试平衡二叉树的插入                     |" << endl;

    AVLTree<string, string>* AVL_tree = new AVLTree<string, string>();

    string question1 = "我最爱的乐队";
    string answer1 = "林肯公园";

    string question2 = "我最爱的游戏";
    string answer2 = "Dota2";

    string question3 = "我最爱的电影";
    string answer3 = "《黑客帝国》";

    string question4 = "最爱的运动";
    string answer4 = "足球";

    AVL_tree->Insert(question1, answer1);
    AVL_tree->Insert(question2, answer2);
    AVL_tree->Insert(question3, answer3);
    AVL_tree->Insert(question4, answer4);

    AVL_tree->Print(AVLNodeVisit);

    cout << endl;

    cout << "-------------------------------------------------------------" << endl;
}


void TestAvlInsertAndRemove() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                   Test AVL Insert/Remove                  |" << endl;
    cout << "|                    测试平衡二叉树的插入/删除                  |" << endl;

    AVLTree<int, int>* AVL_tree = new AVLTree<int, int>();

    int keyArr[31] =
        { 9, 15, 5, 23, 27, 22, 7, 17, 8, 28,
          25, 12, 13, 14, 2, 26, 30, 18, 16, 20,
          21, 6, 4, 24, 11, 19, 3, 1, 29, 10, 10 };
    int elemArr[31] =
        { 9, 15, 5, 23, 27, 22, 7, 17, 8, 28,
          25, 12, 13, 14, 2, 26, 30, 18, 16, 20,
          21, 6, 4, 24, 11, 19, 3, 1, 29, 10, 10 };
    int count = 30;

    for (int i = 0; i < count; i++) {
        AVL_tree->Insert(keyArr[i], elemArr[i]);
        AVL_tree->Print(VisitKey);
    }

    for (int i = 0; i < count; i++) {
        int key = keyArr[i];
        AVL_tree->Remove(key);
        AVL_tree->Print(VisitKey);
    }

    cout << endl;

    cout << "-------------------------------------------------------------" << endl;
}


void TestAvlInsertAndRemoveRecursive() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|              Test AVL Insert/Remove recursive             |" << endl;
    cout << "|                 测试平衡二叉树的插入/删除(递归)                |" << endl;

    AVLTree<int, int>* AVL_tree = new AVLTree<int, int>();

    int keyArr[31] =
        { 9, 15, 5, 23, 27, 22, 7, 17, 8, 28,
          25, 12, 13, 14, 2, 26, 30, 18, 16, 20,
          21, 6, 4, 24, 11, 19, 3, 1, 29, 10, 10 };
    int elemArr[31] =
        { 9, 15, 5, 23, 27, 22, 7, 17, 8, 28,
          25, 12, 13, 14, 2, 26, 30, 18, 16, 20,
          21, 6, 4, 24, 11, 19, 3, 1, 29, 10, 10 };
    int count = 30;

    for (int i = 0; i < count; i++) {
        AVL_tree->InsertRecursive(keyArr[i], elemArr[i]);
        AVL_tree->Print(VisitKey);
    }

    for (int i = 0; i < count; i++) {
        int key = keyArr[i];
        AVL_tree->RemoveRecursive(key);
        AVL_tree->Print(VisitKey);
    }

    cout << endl;

    cout << "-------------------------------------------------------------" << endl;
}


void TestBSTAndAVLHeight() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|              Test BinarySearchTree & AVL Height           |" << endl;
    cout << "|                    测试搜索二叉树/AVL树的高度                 |" << endl;

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
    AVLTree<string, string>* AVL_tree = new AVLTree<string, string>();

    for (int i = 0; i < count; i++) {
        bst_tree->Insert(keys[i], elements[i]);
    }

    for (int i = 0; i < count; i++) {
        AVL_tree->Insert(keys[i], elements[i]);
    }

    cout << endl << endl;

    cout << "BST树高度: " << bst_tree->Height() << endl;
    cout << "AVL树高度: " << AVL_tree->Height() << endl;

    cout << "-------------------------------------------------------------" << endl;
}