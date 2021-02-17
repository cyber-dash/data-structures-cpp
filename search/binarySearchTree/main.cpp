
#include <iostream>

#include "BSTNode.h"
#include "BSTNode.cpp"
#include "person.h"

using namespace std;

void visit(BSTNode<person, long> *p) {
  cout << p->data << " ";
};

int main(void)
{
  int num;
  long id;
  string name;
  BST<person, long> bst;

  cout << "Input the nodes num in the binary tree: ";
  cin >> num;

  int i = 0;
  BSTNode<person,long> *node;

  for (i = 0 ; i < num; i++) {
    cout << "input id and name" << endl;
    cin >> id >> name;
    person tmp(id, name);
    bst.Insert(tmp, id);
  }

  bst.PrintTree(visit);

  cout << endl;

  person p_node = bst.Max();
  cout << "Max node is: " << p_node << endl;
  p_node = bst.Min();
  cout << "Min node is: " << p_node << endl;

  cout << "input id to search" << endl;
  cin >> id;
  node = bst.Search(id);
  if (node == NULL) {
    cout << "Do not found node for key: " + id;
  } else {
    cout << "Found node: " << node->data << endl;
  }
  cout << "input id to delete" << endl;
  cin >> id;
  bst.Remove(id);
  bst.PrintTree(visit);

  cout << endl;

  bst.makeEmpty();
  bst.PrintTree(visit);

  return 0;
}
