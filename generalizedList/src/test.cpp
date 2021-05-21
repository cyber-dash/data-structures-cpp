//
// Created by svenlee on 2021/5/19.
//

#include "test.h"

void TestCreateListByString() {

}

void TestHeadAndTail() {

}

void TestDepth() {

  string gen_list_string1 = "A(#);";
  string gen_list_string2 = "A(a, b);";
  string gen_list_string3 = "A(B(C(#)));";
  string gen_list_string4 = "E(B(a), D(B(a)));";

  GenList<char> gen_list1;
  GenList<char> gen_list2;
  GenList<char> gen_list3;
  GenList<char> gen_list4;

  gen_list1.CreateListByString(gen_list_string1);
  gen_list2.CreateListByString(gen_list_string2);
  gen_list3.CreateListByString(gen_list_string3);
  gen_list4.CreateListByString(gen_list_string4);

  cout<<"\""<<gen_list_string1<<"\""<<" depth: "<<gen_list1.Depth()<<endl;
  cout<<"\""<<gen_list_string2<<"\""<<" depth: "<<gen_list2.Depth()<<endl;
  cout<<"\""<<gen_list_string3<<"\""<<" depth: "<<gen_list3.Depth()<<endl;
  cout<<"\""<<gen_list_string4<<"\""<<" depth: "<<gen_list4.Depth()<<endl;
}


void TestLength() {

  string gen_list_string1 = "A(#);";
  string gen_list_string2 = "A(a, b);";
  string gen_list_string3 = "A(B(C(#)));";
  string gen_list_string4 = "E(B(a), D(B(a)));";

  GenList<char> gen_list1;
  GenList<char> gen_list2;
  GenList<char> gen_list3;
  GenList<char> gen_list4;

  gen_list1.CreateListByString(gen_list_string1);
  gen_list2.CreateListByString(gen_list_string2);
  gen_list3.CreateListByString(gen_list_string3);
  gen_list4.CreateListByString(gen_list_string4);

  cout<<"\""<<gen_list_string1<<"\""<<" length: "<<gen_list1.Length()<<endl;
  cout<<"\""<<gen_list_string2<<"\""<<" length: "<<gen_list2.Length()<<endl;
  cout<<"\""<<gen_list_string3<<"\""<<" length: "<<gen_list3.Length()<<endl;
  cout<<"\""<<gen_list_string4<<"\""<<" length: "<<gen_list4.Length()<<endl;
}
