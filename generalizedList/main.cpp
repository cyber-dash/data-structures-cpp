//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/7/29.
//

#include <iostream>
#include "gen_list.h"


using namespace std;


int main() {

  GenList<char> gen_list;

  // gen_list.CyberDashShow();

  // cin>>gen_list;

  string string1 = "A(B(C(#)))";

  gen_list.CreateListByString(string1);

  cout<<"gen_list length: "<<gen_list.Length()<<endl;
  cout<<"gen_list depth: "<<gen_list.Depth()<<endl;

  return 0;
}