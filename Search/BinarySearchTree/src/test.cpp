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


void TestOperatorEqual() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                       Test Operator=                      |" << endl;
    cout << "|                     测试搜索二叉树=操作                     |" << endl;

    BST<string, string> origin_search_tree;

    string question1 = "我最爱的乐队";
    string answer1 = "林肯公园";

    string question2 = "我最爱的游戏";
    string answer2 = "Dota2";

    string question3 = "我最爱的电影";
    string answer3 = "《黑客帝国》";

    origin_search_tree.Insert(answer1, question1);
    origin_search_tree.Insert(answer2, question2);
    origin_search_tree.Insert(answer3, question3);

    BST<string, string> new_BST = origin_search_tree;

    new_BST.PrintTree(BSTNodeVisit);

    cout << endl << "-------------------------------------------------------------" << endl;
}


void TestBSTInsert() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                      Test BST Insert                      |" << endl;
    cout << "|                     测试搜索二叉树的插入                     |" << endl;

    BST<string, string>* binary_search_tree = new BST<string, string>();

    string question1 = "我最爱的乐队";
    string answer1 = "林肯公园";

    string question2 = "我最爱的游戏";
    string answer2 = "Dota2";

    string question3 = "我最爱的电影";
    string answer3 = "《黑客帝国》";

    binary_search_tree->Insert(answer1, question1);
    binary_search_tree->Insert(answer2, question2);
    binary_search_tree->Insert(answer3, question3);

    binary_search_tree->PrintTree(BSTNodeVisit);

    cout << endl;

    cout << "-------------------------------------------------------------" << endl;
}


void TestBSTRemove() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                      Test BST Remove                      |" << endl;
    cout << "|                     测试搜索二叉树的删除                     |" << endl;

    BST<string, string>* binary_search_tree = new BST<string, string>();

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

    binary_search_tree->Insert(answer1, question1);
    binary_search_tree->Insert(answer2, question2);
    binary_search_tree->Insert(answer3, question3);
    binary_search_tree->Insert(answer4, question4);
    binary_search_tree->Insert(answer5, question5);
    binary_search_tree->Insert(answer6, question6);
    binary_search_tree->Insert(answer7, question7);
    binary_search_tree->Insert(answer8, question8);

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
    cout << "|                      Test BST Search                      |" << endl;
    cout << "|                     测试搜索二叉树的搜索                     |" << endl;

    BST<string, string>* binary_search_tree = new BST<string, string>();

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

    binary_search_tree->Insert(answer1, question1);
    binary_search_tree->Insert(answer2, question2);
    binary_search_tree->Insert(answer3, question3);
    binary_search_tree->Insert(answer4, question4);
    binary_search_tree->Insert(answer5, question5);
    binary_search_tree->Insert(answer6, question6);
    binary_search_tree->Insert(answer7, question7);
    binary_search_tree->Insert(answer8, question8);
    binary_search_tree->Insert(answer9, question9);

    binary_search_tree->Remove(question9);

    BSTNode<string, string>* the_9th_node = binary_search_tree->Search(question9);
    if (the_9th_node == NULL) { // 没有搜索到
      // cout<<"question9: "<<question9<<endl<<"answer9: "<<"Duck不必"<<endl;
        cout << "此问题已删除" << endl;
    }
    else { // 搜索到
        cout << "question9: " << the_9th_node->GetKey() << endl << "answer9: " << the_9th_node->GetValue() << endl;
    }

    cout << endl;

    BSTNode<string, string>* the_8th_node = binary_search_tree->Search(question8);
    if (the_8th_node == NULL) { // 没有搜索到
        cout << "Duck不必" << endl;
    }
    else { // 搜索到
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

    AVL_tree->Insert(answer1, question1);
    AVL_tree->Insert(answer2, question2);
    AVL_tree->Insert(answer3, question3);
    AVL_tree->Insert(answer4, question4);
    AVL_tree->Insert(answer5, question5);
    AVL_tree->Insert(answer6, question6);
    AVL_tree->Insert(answer7, question7);
    AVL_tree->Insert(answer8, question8);
    AVL_tree->Insert(answer9, question9);

    // AVL_tree->Remove(question9);

    AVLNode<string, string>* the_9th_node = AVL_tree->Search(question9);
    if (the_9th_node == NULL) { // 没有搜索到
      // cout<<"question9: "<<question9<<endl<<"answer9: "<<"Duck不必"<<endl;
        cout << "此问题已删除" << endl;
    }
    else { // 搜索到
        cout << "question9: " << the_9th_node->GetKey() << endl << "answer9: " << the_9th_node->GetValue() << endl;
    }

    cout << endl;

    AVLNode<string, string>* the_8th_node = AVL_tree->Search(question8);
    if (the_8th_node == NULL) { // 没有搜索到
        cout << "Duck不必" << endl;
    }
    else { // 搜索到
        cout << "question8: " << the_8th_node->GetKey() << endl << "answer8: " << the_8th_node->GetValue() << endl;
    }

    cout << endl;

    cout << "-------------------------------------------------------------" << endl;
}


void TestBSTMaxAndMin() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                    Test BST Max and Min                   |" << endl;
    cout << "|                  测试搜索二叉树的最大值/最小值                 |" << endl;

    BST<string, string>* binary_search_tree = new BST<string, string>();

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

    binary_search_tree->Insert(answer1, question1);
    binary_search_tree->Insert(answer2, question2);
    binary_search_tree->Insert(answer3, question3);
    binary_search_tree->Insert(answer4, question4);
    binary_search_tree->Insert(answer5, question5);
    binary_search_tree->Insert(answer6, question6);
    binary_search_tree->Insert(answer7, question7);
    binary_search_tree->Insert(answer8, question8);
    binary_search_tree->Insert(answer9, question9);

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

    AVL_tree->Insert(answer1, question1);
    AVL_tree->Insert(answer2, question2);
    AVL_tree->Insert(answer3, question3);
    AVL_tree->Insert(answer4, question4);
    AVL_tree->Insert(answer5, question5);
    AVL_tree->Insert(answer6, question6);
    AVL_tree->Insert(answer7, question7);
    AVL_tree->Insert(answer8, question8);
    AVL_tree->Insert(answer9, question9);

    string max_data = AVL_tree->Max();
    cout << "max_data: " << max_data << endl;

    string min_data = AVL_tree->Min();
    cout << "min_data: " << min_data << endl;

    cout << "-------------------------------------------------------------" << endl;
}


void TestBSTMin() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                        Test BST Min                       |" << endl;
    cout << "|                     测试搜索二叉树的最小值                    |" << endl;

    BST<string, string>* binary_search_tree = new BST<string, string>();

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

    binary_search_tree->Insert(answer1, question1);
    binary_search_tree->Insert(answer2, question2);
    binary_search_tree->Insert(answer3, question3);
    binary_search_tree->Insert(answer4, question4);
    binary_search_tree->Insert(answer5, question5);
    binary_search_tree->Insert(answer6, question6);
    binary_search_tree->Insert(answer7, question7);
    binary_search_tree->Insert(answer8, question8);
    binary_search_tree->Insert(answer9, question9);

    string minData = binary_search_tree->Min();

    cout << "minData: " << minData << endl;

    cout << "-------------------------------------------------------------" << endl;
}


void TestBSTMakeEmpty() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                     Test BST MakeEmpty                    |" << endl;
    cout << "|                      测试搜索二叉树的清除                    |" << endl;

    BST<string, string>* binary_search_tree = new BST<string, string>();

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

    binary_search_tree->Insert(answer1, question1);
    binary_search_tree->Insert(answer2, question2);
    binary_search_tree->Insert(answer3, question3);
    binary_search_tree->Insert(answer4, question4);
    binary_search_tree->Insert(answer5, question5);
    binary_search_tree->Insert(answer6, question6);
    binary_search_tree->Insert(answer7, question7);
    binary_search_tree->Insert(answer8, question8);
    binary_search_tree->Insert(answer9, question9);

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

    AVL_tree->Insert(answer1, question1);
    AVL_tree->Insert(answer2, question2);
    AVL_tree->Insert(answer3, question3);
    AVL_tree->Insert(answer4, question4);

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

    AVL_tree->InsertByCyberDash(answer1, question1);
    AVL_tree->InsertByCyberDash(answer2, question2);
    AVL_tree->InsertByCyberDash(answer3, question3);
    AVL_tree->InsertByCyberDash(answer4, question4);

    AVL_tree->Print(AVLNodeVisit);

    cout << endl;

    cout << "-------------------------------------------------------------" << endl;
}


void TestAVLInsertByCyberDash() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                 Test AVL InsertByCyberDash                |" << endl;
    cout << "|               测试平衡二叉树的插入(CyberDash版本)            |" << endl;

    AVLTree<string, string>* AVL_tree = new AVLTree<string, string>();

    string question1 = "我最爱的乐队";
    string answer1 = "林肯公园";

    string question2 = "我最爱的游戏";
    string answer2 = "Dota2";

    string question3 = "我最爱的电影";
    string answer3 = "《黑客帝国》";

    string question4 = "最爱的运动";
    string answer4 = "足球";

    AVL_tree->InsertByCyberDash(answer1, question1);
    AVL_tree->InsertByCyberDash(answer2, question2);
    AVL_tree->InsertByCyberDash(answer3, question3);
    AVL_tree->InsertByCyberDash(answer4, question4);

    AVL_tree->Print(AVLNodeVisit);

    cout << endl;

    cout << "-------------------------------------------------------------" << endl;
}


void TestAVLRemoveByCyberDash() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                 Test AVL Remove                |" << endl;
    cout << "|               测试平衡二叉树的删除(CyberDash版本)             |" << endl;

    AVLTree<int, int>* AVL_tree = new AVLTree<int, int>();

    int keyArr[26] =
        { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};
         //  "l", "j", "z", "n", "o", "p", "q", "r", "s",
          // "t", "u", "v", "w", "x", "y", "m"};
    int elemArr[26] =
        { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};
        // { "a", "d", "b", "c", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q" };
          // "l", "j", "z", "n", "o", "p", "q", "r", "s",
          // "t", "u", "v", "w", "x", "y", "m"};
    int count = 26;

    for (int i = 0; i < count; i++) {
        AVL_tree->InsertByCyberDash(keyArr[i], elemArr[i]);
        // AVL_tree->Print(AVLNodeVisit);
    }

    for (int i = 0; i < count; i++) {
        if (i == 10) {
            cout << endl;
        }
        cout<<i<<endl;
        int key = keyArr[i];
        AVL_tree->Remove(key);
        AVL_tree->Print(VisitKey);
    }

    cout << endl;

    cout << "-------------------------------------------------------------" << endl;
}


void TestBSTAndAVLHeight() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                   Test BST & AVL Height                   |" << endl;
    cout << "|                  测试搜索二叉树/AVL树的高度                  |" << endl;

    string keyArr[26] =
    { "a", "d", "b", "c", "e", "f", "g", "h", "i", "k", "l", "j", "z", "n", "o", "p", "q", "r", "s",
      "t", "u", "v", "w", "x", "y", "m"};
    string elemArr[26] =
    { "a", "d", "b", "c", "e", "f", "g", "h", "i", "k", "l", "j", "z", "n", "o", "p", "q", "r", "s",
      "t", "u", "v", "w", "x", "y", "m"};
    int count = 26;

    cout << "分别向BST和AVL树插入:" << endl;
    for (int i = 0; i < count; i++) {
        cout << "\"key:" << keyArr[i] << "/elem:" << elemArr[i] << "\"  ";
        // 四个一行
        if (i % 4 == 3 && i != 0) {
            cout << endl;
        }
    }

    BST<string, string>* bst_tree = new BST<string, string>();
    AVLTree<string, string>* AVL_tree = new AVLTree<string, string>();

    for (int i = 0; i < count; i++) {
        bst_tree->Insert(keyArr[i], elemArr[i]);
    }

    for (int i = 0; i < count; i++) {
        AVL_tree->InsertByCyberDash(keyArr[i], elemArr[i]);
    }

    cout << endl << endl;

    cout << "BST树高度: " << bst_tree->Height() << endl;
    cout << "AVL树高度: " << AVL_tree->Height() << endl;

    cout << "-------------------------------------------------------------" << endl;
}