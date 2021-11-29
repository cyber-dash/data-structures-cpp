//
// Created by alei_go@163.com(抖音: cyberdash_yuan) on 2020/11/1.
//

#include <iostream>
#include "huffman_tree.h"
#include "min_heap.h"


using namespace std;


template <class T>
HuffmanTree<T>::HuffmanTree(float w[], int n) {
	MinHeap<HuffmanNode<T> > hp;
	HuffmanNode<T> *parent, *first, *second, *work, temp;

	for (int i = 0; i < n; i++) {
		work = new HuffmanNode<T>;
		work->data = w[i];
		work->left_child = NULL;
		work->rightChild = NULL;
		work->parent = work;
		hp.Insert(*work);
	}

	for (int i = 0; i < n - 1; i++) {
		hp.RemoveMin(temp);
		first = temp.parent;
		hp.RemoveMin(temp);
		second = temp.parent;
		mergeTree(first, second, parent);
		hp.Insert(*parent);
	}

	root = parent;
}


template <class T>
void HuffmanTree<T>::deleteTree(HuffmanNode<T> *t) {
	if (t == NULL) {
		return;
	}

	deleteTree(t->left_child);
	deleteTree(t->rightChild);

	delete t;
}

template <class T>
void HuffmanTree<T>::
mergeTree(HuffmanNode<T> *ht1, HuffmanNode<T> *ht2, HuffmanNode<T> *&parent) {
	parent = new HuffmanNode<T>;

	parent->left_child = ht1;
	parent->rightChild = ht2;
	parent->parent = parent; 

	parent->data = ht1->data + ht2->data;
	ht1->parent = ht2->parent = parent;
}


template <class T>
void HuffmanTree<T>::showTree(HuffmanNode<T> * t) {
	if (t == NULL){
		return;
	}

	cout << t->data;
	cout << '(';
	showTree(t->left_child);
	cout << ',';
	showTree(t->rightChild);
	cout << ')';
}


template<class T>
void HuffmanTree<T>::CyberDashShow() {
  cout<<endl
      <<"*************************************** CyberDash ***************************************"<<endl<<endl
      <<"抖音号\"CyberDash计算机考研\", id: cyberdash_yuan"<<endl<<endl
      <<"CyberDash成员:"<<endl
      <<"元哥(cyberdash@163.com), "<<"北京邮电大学(通信工程本科)/北京邮电大学(信息与通信系统研究生)"<<endl
      <<"磊哥(alei_go@163.com), "<<"山东理工大学(数学本科)/北京邮电大学(计算机研究生)"<<endl<<endl
      <<"L_Dash(lyu2586@163.com), "<<"北京邮电大学(计算机在读研究生)"<<endl<<endl
      <<"数据结构开源代码(C++清华大学殷人昆)魔改升级版本: https://gitee.com/cyberdash/data-structure-cpp"<<endl
      <<endl<<"*************************************** CyberDash ***************************************"<<endl<<endl;
}
