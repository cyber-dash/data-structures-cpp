//
// Created by alei_go@163.com(抖音: cyberdash_yuan) on 2020/11/1.
//

#include "binary_tree.h"
#include "test.h"


using namespace std;


void visit(BinTreeNode<int>* node_ptr) {
  cout<<node_ptr->data_ <<" ";
};


int main() {

  TestBinaryTreeHeight();

  TestBinaryTreeChildFunction();

  TestParent();

  /*
  int num = 7;
  BinaryTree<int> binTree;

  cout << "The nodes num in the binary tree is "<<num<<endl;

  int i = 0;
  for (i = 0 ; i < num; i++) {
    binTree.Insert(i);
  }

  cout << "tree height: " << binTree.Height() << endl;
  cout << "tree size: " << binTree.Size() << endl;
  binTree.Print();
  cout << endl;

  cout << "pre order: " << endl;
  binTree.PreOrder(visit);
  cout << endl;

  cout << "pre order 2: " << endl;
  binTree.PreOrderNonRecursive(visit);
  cout << endl;
  cout << "in order: " << endl;
  binTree.InOrder(visit);
  cout << endl;
  cout << "in order1: " << endl;
  binTree.InOrderNonRecursive(visit);
  cout << endl;
  cout << "post order: " << endl;
  binTree.PostOrder(visit);
  cout << endl;
  cout << "post order non-recursive: " << endl;
  binTree.PostOrderNonRecursive(visit);
  cout << endl;
  cout << "level order: " << endl;
  binTree.LevelOrder(visit);
  cout << endl;

  if (binTree.Find(10)) {
    cout << "find 10 in tree!" << endl;
  } else {
    cout << "can't find 10 in tree!" << endl;
  }

  BinaryTree<int> binTree_1(binTree);

  cout << "is empty: " << binTree_1.IsEmpty() << endl;
  cout << binTree_1 << endl;
  cout << "is equal: " << (binTree_1 == binTree) << endl;

  BinTreeNode<int> *root = binTree_1.GetRoot();
  BinTreeNode<int> *node = binTree_1.LeftChild(root);
  if (node != NULL) {
    cout << "left child for node: " << root->data_ << " is " << node->data_ << endl;
  }
  node = binTree_1.RightChild(root);
  if (node != NULL) {
    cout << "right child for node: " << root->data_ << " is " << node->data_ << endl;
  }

  cout << "parent of node: " << node->data_ << " is " << binTree_1.Parent_(node)->data_ << endl;

  ifstream fin("data_.txt");
  BinaryTree<int> binTree_2(0);
  fin >> binTree_2;
  fin.close();
  cout << "The binary tree is: \n" << binTree_2 << endl;

  binTree_2.Print();
  cout << endl;
   */

  /* CreateBinTree   CreateSubBinTreeByPreAndInOrderString_ */

  /*
  BinaryTree<int> binTree_3(0);

  binTree_3.Print();
  cout << endl;
  filebuf fbuf;
  fbuf.open("data_.txt", ios::in);
  istream iss(&fbuf);
  binTree_3.CreateBinTree(iss);
  cout << "size: " << binTree_3.Size() << endl;
  binTree_3.Print();
  fbuf.close();

  cout << endl;

  BinaryTree<int> binTree_4(0);
  int vlr[] = {0, 1, 3, 6, 5, 9, 2, 4, 8, 7};
  int lvr[] = {6, 3, 1, 9, 5, 0, 8, 4, 2, 7};
  binTree_4.createBinTreeByPreAndInOrderString(vlr, lvr, 10);
  binTree_4.Print();

  cout << endl;

  binTree_4.CyberDashShow();
   */

  return 0;
}
