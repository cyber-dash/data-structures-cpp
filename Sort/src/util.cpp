/*!
 * @file util.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 工具.cpp文件
 * @version 0.2.1
 * @date 2021-09-19
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#include <iostream>


using namespace std;


void Swap(int* a, int* b) {

    if (*a == *b) {
        return;
    }

    int tmp = *a;
    *a = *b;
    *b = tmp;
}


int* min_by_ptr(int* ptr1, int* ptr2) {

    if (*ptr1 <= *ptr2) {
        return ptr1;
    }
    else {
        return ptr2;
    }
}


void PrintArray(int* arr, int array_size) {

    for (int i = 0; i < array_size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}


void CyberDashShow() {
    cout << endl
        << "*************************************** CyberDash ***************************************" << endl << endl
        << "抖音号\"CyberDash计算机考研\", id: cyberdash_yuan" << endl << endl
        << "CyberDash成员:" << endl
        << "元哥(cyberdash@163.com), " << "北京邮电大学(通信工程本科)/北京邮电大学(信息与通信系统研究生)" << endl
        << "磊哥(alei_go@163.com), " << "山东理工大学(数学本科)/北京邮电大学(计算机研究生)" << endl << endl
        << "L_Dash(lyu2586@163.com), " << "北京邮电大学(计算机在读研究生)" << endl << endl
        << "数据结构开源代码(C++清华大学殷人昆)魔改升级版本: https://gitee.com/cyberdash/data-structure-cpp" << endl
        << endl << "*************************************** CyberDash ***************************************" << endl << endl;
}
