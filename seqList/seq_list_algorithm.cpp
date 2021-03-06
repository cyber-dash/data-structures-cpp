//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2021/2/24.
//

#include "seq_list_algorithm.h"


template<class T>
void UnionSeqList(SeqList<T>& seq_list_a, SeqList<T>& seq_list_b) {
  int a_length = seq_list_a.Length();
  int b_length = seq_list_b.Length();

  for (int i = 0; i <= b_length; i++) {

    int list_b_item;
    seq_list_b.GetData(i, list_b_item);

    int pos = seq_list_a.Search(list_b_item);
    if (pos == 0) {
      seq_list_a.Insert(a_length, list_b_item);
    }
  }
}


template<class T>
void Intersection(SeqList<T>& seq_list_a, SeqList<T>& seq_list_b) {

  int a_length = seq_list_a.Length();
  int b_length = seq_list_b.Length();

  int pos = 1;
  while (pos <= a_length) {
    int list_b_item;
    seq_list_a.GetData(pos, list_b_item);


  }
}
