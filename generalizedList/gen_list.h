//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/7/14.
//

#ifndef CYBER_DASH_GENERALIZED_LIST_H
#define CYBER_DASH_GENERALIZED_LIST_H


#include <iostream>
#include <vector>
#include <queue>
#include "gen_list_node.h"


using namespace std;


template<class T>
class GenList {

public:
  GenList();
  // ~GenList();

  bool Head(Item<T>& item);
  bool Tail(GenList<T>& tail_list);

  void CopyFrom(GenList<T>& src_gen_list);
  int Length();
  int Depth();

  void CreateListByQueue(queue<T>& char_queue, GenListNode<T>*& node_ptr, bool& in_referred_list);

  void Remove(GenListNode<T>* node_ptr);

  GenListNode<T>* ref_node_ptr_;

  template<class U>
  friend istream& operator>>(istream& in, GenList<T>& gen_list);

  void CyberDashShow();

private:
  int SubListLength_(GenListNode<T>* node_ptr);
  int SubListDepth_(GenListNode<T>* node_ptr);

  bool IsGenListNameChar_(T chr);
  bool IsGenListBeginChar_(T chr);

  void LeftBracketRegulatorQueue_(queue<T>& charQueue);
  GenListNode<T>* GenerateElemNode_(T chr);
  GenListNode<T>* GenerateChildListNode_();

  GenListNode<T>* FindReferredNodePtr_(T chr);

  GenListNode<T>* Copy_(GenListNode<T>*& node_ptr);

  vector<T> gen_list_name_vec_;
  vector<GenListNode<T>*> gen_list_node_ptr_vec_;
};


#endif // CYBER_DASH_GENERALIZED_LIST_H
