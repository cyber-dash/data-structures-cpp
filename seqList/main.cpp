//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/7/15.
//

#include "SeqList.h"
#include "SeqList.cpp"


using namespace std;


int main() {

  SeqList<int>* seq_list_ptr = new SeqList<int>(3);

  int num1 = 1;
  int num2 = 2;
  int num3 = 3;

  // test Insert
  seq_list_ptr->Insert(0, num1);
  seq_list_ptr->Insert(1, num2);
  seq_list_ptr->Insert(2, num3);

  // test operator=
  SeqList<int> new_seq_list_ptr = *seq_list_ptr;
  new_seq_list_ptr.Output();

  // test Remove
  int delete_num;
  seq_list_ptr->Remove(2, delete_num);
  cout<<"delete_num:"<<delete_num<<endl<<endl;

  // test Search
  int search_pos;
  search_pos = seq_list_ptr->Search(num2);
  cout<<"num2 search_pos:"<<search_pos<<endl;
  search_pos = seq_list_ptr->Search(num3);
  cout<<"num3 search_pos:"<<search_pos<<endl<<endl;

  // test Locate
  int pos = seq_list_ptr->Locate(1);
  cout<<"pos 1:"<<pos<<endl<<endl;

  // test GetData
  bool is_in_seq_list;
  int get_data;
  is_in_seq_list = seq_list_ptr->GetData(2, get_data);
  cout<<"in_seq_list_ptr:"<<is_in_seq_list<<endl;
  is_in_seq_list = seq_list_ptr->GetData(3, get_data);
  cout<<"in_seq_list_ptr:"<<is_in_seq_list<<endl<<endl;

  //test SetData
  int num4 = 4;
  bool set_done = seq_list_ptr->SetData(2, num4);

  // test IsEmpty
  bool is_empty = seq_list_ptr->IsEmpty();
  cout<<"is_empty:"<<is_empty<<endl<<endl;

  // test IsFull
  bool is_full;
  is_full = seq_list_ptr->IsFull();
  cout<<"is_full:"<<is_full<<endl;
  seq_list_ptr->Insert(2, num4);
  is_full = seq_list_ptr->IsFull();
  cout<<"is_full:"<<is_full<<endl<<endl;

  // test Resize
  seq_list_ptr->Resize(10);
  is_full = seq_list_ptr->IsFull();
  cout<<"is_full:"<<is_full<<endl;
  cout<<"Now, the data_array_ length is: "<<seq_list_ptr->Length()<<endl;
  cout<<"Now, the size is: "<<seq_list_ptr->Size()<<endl<<endl;

  // test Output
  seq_list_ptr->Output();

  delete seq_list_ptr;

  seq_list_ptr->CyberDashShow();

  return 0;
}
