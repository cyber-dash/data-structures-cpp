//
// Created by cyberdash@163.com on 2021/6/26.
//

#include "test.h"


void TestBSTInsert() {
  BST<string, string>* binary_search_tree = new BST<string, string>();

  string question1 = "my_favorite_band";
  string answer1 = "Linkin Park";

  string question2 = "my_favorite_game";
  string answer2 = "Dota2";

  string question3 = "my_favorite_film";
  string answer3 = "Matrix";

  binary_search_tree->Insert(question1, answer1);
  binary_search_tree->Insert(question2, answer2);
  binary_search_tree->Insert(question3, answer3);

  cout<<endl;
}
