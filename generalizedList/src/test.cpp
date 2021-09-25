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
  string gen_list_string1_1 = "A(a);";

  string gen_list_string2 = "A(a, b);";
  string gen_list_string2_1 = "A(a,B(a));";
  string gen_list_string2_2 = "A(a, B(#));";
  string gen_list_string2_3 = "E(B(#), D(B(#)));";
  string gen_list_string2_4 = "E(B(#), D(B(a)));";
  string gen_list_string2_5 = "E(B(a), D(B(#)));";
  string gen_list_string2_6 = "E(B(C(a)), D(a));";
  
  string gen_list_string3 = "A(B(C(#)),a,b);";
  string gen_list_string3_1 = "A(B(C(#)),#,b);";
  string gen_list_string3_2 = "A(B(C(#),D(#)),#,#);";
  string gen_list_string3_3 = "A(B(C(a)),a,b);";

  string gen_list_string4 = "E(#,A(a), A(B(a),a),a);";
  string gen_list_string4_1 = "E(A(#), A(B(#)),A(#),A(#));";
  string gen_list_string4_2 = "E(A(#), A(B(a)),A(a),A(a));";
  string gen_list_string4_3 = "E(a,b,c,d);";
  string gen_list_string4_4 = "E(#,#,#,#);";

  GenList<char> gen_list1;
  GenList<char> gen_list1_1;

  GenList<char> gen_list2;
  GenList<char> gen_list2_1;
  GenList<char> gen_list2_2;
  GenList<char> gen_list2_3;
  GenList<char> gen_list2_4;
  GenList<char> gen_list2_5;
  GenList<char> gen_list2_6;
  
  GenList<char> gen_list3;
  GenList<char> gen_list3_1;
  GenList<char> gen_list3_2;
  GenList<char> gen_list3_3;
  
  GenList<char> gen_list4;
  GenList<char> gen_list4_1;
  GenList<char> gen_list4_2;
  GenList<char> gen_list4_3;
  GenList<char> gen_list4_4;

  gen_list1.CreateListByString(gen_list_string1);
  gen_list1_1.CreateListByString(gen_list_string1_1);

  gen_list2.CreateListByString(gen_list_string2);
  gen_list2_1.CreateListByString(gen_list_string2_1);
  gen_list2_2.CreateListByString(gen_list_string2_2);
  gen_list2_3.CreateListByString(gen_list_string2_3);
  gen_list2_4.CreateListByString(gen_list_string2_4);
  gen_list2_5.CreateListByString(gen_list_string2_5);
  gen_list2_6.CreateListByString(gen_list_string2_6);

  gen_list3.CreateListByString(gen_list_string3);
  gen_list3_1.CreateListByString(gen_list_string3_1);
  gen_list3_2.CreateListByString(gen_list_string3_2);
  gen_list3_3.CreateListByString(gen_list_string3_3);

  gen_list4.CreateListByString(gen_list_string4);
  gen_list4_1.CreateListByString(gen_list_string4_1);
  gen_list4_2.CreateListByString(gen_list_string4_2);
  gen_list4_3.CreateListByString(gen_list_string4_3);
  gen_list4_4.CreateListByString(gen_list_string4_4);

  cout<<"\""<<gen_list_string1<<"\""<<" length: "<<gen_list1.Length()<<endl;//1
  cout<<"\""<<gen_list_string1_1<<"\""<<" length: "<<gen_list1_1.Length()<<endl;//1

  cout<<"\""<<gen_list_string2<<"\""<<" length: "<<gen_list2.Length()<<endl;//2
  cout<<"\""<<gen_list_string2_1<<"\""<<" length: "<<gen_list2_1.Length()<<endl;//2
  cout<<"\""<<gen_list_string2_2<<"\""<<" length: "<<gen_list2_2.Length()<<endl;//2
  cout<<"\""<<gen_list_string2_3<<"\""<<" length: "<<gen_list2_3.Length()<<endl;//2
  cout<<"\""<<gen_list_string2_4<<"\""<<" length: "<<gen_list2_4.Length()<<endl;//2
  cout<<"\""<<gen_list_string2_5<<"\""<<" length: "<<gen_list2_5.Length()<<endl;//2
  cout<<"\""<<gen_list_string2_6<<"\""<<" length: "<<gen_list2_6.Length()<<endl;//2

  cout<<"\""<<gen_list_string3<<"\""<<" length: "<<gen_list3.Length()<<endl;//3
  cout<<"\""<<gen_list_string3_1<<"\""<<" length: "<<gen_list3_1.Length()<<endl;//3
  cout<<"\""<<gen_list_string3_2<<"\""<<" length: "<<gen_list3_2.Length()<<endl;//3
  cout<<"\""<<gen_list_string3_3<<"\""<<" length: "<<gen_list3_3.Length()<<endl;//3

  cout<<"\""<<gen_list_string4<<"\""<<" length: "<<gen_list4.Length()<<endl;//2
  cout<<"\""<<gen_list_string4_1<<"\""<<" length: "<<gen_list4_1.Length()<<endl;//2
  cout<<"\""<<gen_list_string4_2<<"\""<<" length: "<<gen_list4_2.Length()<<endl;//2
  cout<<"\""<<gen_list_string4_3<<"\""<<" length: "<<gen_list4_3.Length()<<endl;//2
  cout<<"\""<<gen_list_string4_4<<"\""<<" length: "<<gen_list4_4.Length()<<endl;//2
}
