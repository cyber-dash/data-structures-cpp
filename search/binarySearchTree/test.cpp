//
// Created by cyberdash@163.com on 2021/6/26.
//


#include "test.h"


void BSTNodeVisit(BSTNode<string, string>* node_ptr) {
  cout<<"["<<node_ptr->GetKey()<<":"<<node_ptr->GetData()<<"]";
}


void AVLNodeVisit(AVLNode<string, string>* node_ptr) {
  cout<<"["<<node_ptr->GetKey()<<":"<<node_ptr->GetData()<<"]";
}


void TestBSTInsert() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                      Test BST Insert                      |"<<endl;
  cout<<"|                     测试搜索二叉树的插入                     |"<<endl;

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

  cout<<endl;

  cout<<"-------------------------------------------------------------"<<endl;
}


void TestBSTRemove() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                      Test BST Remove                      |"<<endl;
  cout<<"|                     测试搜索二叉树的删除                     |"<<endl;

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

  cout<<endl;

  binary_search_tree->Remove(question1);

  binary_search_tree->PrintTree(BSTNodeVisit);

  cout<<endl;

  cout<<"-------------------------------------------------------------"<<endl;
}


void TestBSTSearch() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                      Test BST Search                      |"<<endl;
  cout<<"|                     测试搜索二叉树的删除                     |"<<endl;

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
    cout<<"此问题已删除"<<endl;
  } else { // 搜索到
    cout<<"question9: "<<the_9th_node->GetKey()<<endl<<"answer9: "<<the_9th_node->GetData()<<endl;
  }

  cout<<endl;

  BSTNode<string, string>* the_8th_node = binary_search_tree->Search(question8);
  if (the_8th_node == NULL) { // 没有搜索到
    cout<<"Duck不必"<<endl;
  } else { // 搜索到
    cout<<"question8: "<<the_8th_node->GetKey()<<endl<<"answer8: "<<the_8th_node->GetData()<<endl;
  }

  cout<<endl;

  cout<<"-------------------------------------------------------------"<<endl;
}


void TestAVLInsert() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                      Test AVL Insert                      |"<<endl;
  cout<<"|                     测试平衡二叉树的插入                     |"<<endl;

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

  AVL_tree->PrintTree(AVLNodeVisit);

  cout<<endl;

  cout<<"-------------------------------------------------------------"<<endl;
}


void TestAVLInsertByCyberDash() {
  cout<<endl;
  cout<<"|------------------------ CyberDash ------------------------|"<<endl;
  cout<<"|                 Test AVL InsertByCyberDash                |"<<endl;
  cout<<"|               测试平衡二叉树的插入(CyberDash版本)            |"<<endl;

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

  AVL_tree->PrintTree(AVLNodeVisit);

  cout<<endl;

  cout<<"-------------------------------------------------------------"<<endl;
}
