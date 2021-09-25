//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/6/2.
//

#include <iostream>


using namespace std;


void swap(int *a, int *b) {

    if (a == b) {
        return;
    }

    int tmp = *a;
    *a = *b;
    *b = tmp;
}


int* min_by_ptr(int *ptr1, int *ptr2) {

    if (*ptr1 <= *ptr2) {
        return ptr1;
    } else {
        return ptr2;
    }
}


void array_show(int *arr, int array_size) {

  for (int i = 0; i < array_size; i++) {
    cout<<arr[i]<<" ";
  }

  cout<<endl;
}


void CyberDashShow() {
  cout<<endl
      <<"*************************************** CyberDash ***************************************"<<endl<<endl
      <<"抖音号\"CyberDash计算机考研\", id: cyberdash_yuan"<<endl<<endl
      <<"CyberDash成员:"<<endl
      <<"元哥(cyberdash@163.com), "<<"北京邮电大学(通信工程本科)/北京邮电大学(信息与通信系统研究生)"<<endl
      <<"磊哥(alei_go@163.com), "<<"山东理工大学(数学本科)/北京邮电大学(计算机研究生)"<<endl<<endl
      <<"数据结构开源代码(C++清华大学殷人昆)魔改升级版本: https://gitee.com/cyberdash/data-structure-cpp"<<endl
      <<endl<<"*************************************** CyberDash ***************************************"<<endl<<endl;
}
