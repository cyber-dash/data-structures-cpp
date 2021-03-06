//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2021/2/24.
//

#ifndef CYBER_DASH_SEQ_LIST_ALGORITHM_H
#define CYBER_DASH_SEQ_LIST_ALGORITHM_H


#include "seq_list.h"


/*
template<class T>
void SeqListUnion(SeqList<T>& seq_list_a, SeqList<T>& seq_list_b);


template<class T>
void SeqListIntersection(SeqList<T>& seq_list_a, SeqList<T>& seq_list_b);
 */


template<class T>
void SeqListUnion(SeqList<T>& seq_list_a, SeqList<T>& seq_list_b) {
  int a_length = seq_list_a.Length();
  int b_length = seq_list_b.Length();

  for (int i = 0; i <= b_length; i++) {

    int list_b_item;
    seq_list_b.GetData(i, list_b_item);

    int pos = seq_list_a.Search(list_b_item);
    if (pos == 0) {
      seq_list_a.Insert(a_length, list_b_item);
      a_length++;
    }
  }
}


template<class T>
void SeqListIntersection(SeqList<T>& seq_list_a, SeqList<T>& seq_list_b) {

  int a_length = seq_list_a.Length();
  int b_length = seq_list_b.Length();

  int iter_pos = 1;
  while (iter_pos <= a_length) {
    int list_a_item;
    seq_list_a.GetData(iter_pos, list_a_item);

    int pos = seq_list_b.Search(list_a_item);
    if (pos == 0) {
      seq_list_a.Remove(iter_pos, list_a_item);
      a_length--;
    } else {
      iter_pos++;
    }
  }
}


#endif // CYBER_DASH_SEQ_LIST_ALGORITHM_H
