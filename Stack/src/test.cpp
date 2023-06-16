/*!
 * @file test.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 栈测试源文件
 * @version 0.2.1
 * @date 2020-07-15
 */

#include "test.h"
#include "linked_stack.h"
#include "seq_stack.h"


/*!
 * @brief **测试-链式栈-入栈**
 * @note
 * 测试-链式栈-入栈
 * ---------------
 * ---------------
 *
 * ---------------
 * 声明test_stack(整型链式栈)\n
 * 依次将1, 2, 3, 4入栈\n
 * 打印test_stack\n
 *
 *
 * ---------------
 */
void TestLinkedStackPush() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                   Test LinkedStack Push                   |" << endl;
    cout << "|                      测试-链式栈-入栈                     |" << endl << endl << endl;

    // 声明test_stack(整型链式栈)
    LinkedStack<int> test_stack;

    // 依次将1, 2, 3, 4入栈
    test_stack.Push(1);
    test_stack.Push(2);
    test_stack.Push(3);
    test_stack.Push(4);

    // 打印test_stack
    cout << test_stack << endl;

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-链式栈-出栈**
 * @note
 * 测试-链式栈-出栈
 * ---------------
 * ---------------
 *
 * ---------------
 * 声明test_stack(整型链式栈)\n
 * 依次将1, 2, 3, 4入栈\n
 * 栈顶出栈3次\n
 * 打印test_stack\n
 *
 *
 * ---------------
 */
void TestLinkedStackPop() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                    Test LinkedStack Pop                   |" << endl;
    cout << "|                      测试-链式栈-出栈                     |" << endl << endl << endl;

    // 声明test_stack(整型链式栈)
    LinkedStack<int> test_stack;

    // 依次将1, 2, 3, 4入栈
    test_stack.Push(1);
    test_stack.Push(2);
    test_stack.Push(3);
    test_stack.Push(4);

    // 栈顶出栈3次
    int pop_data;

    test_stack.Pop(pop_data);
    test_stack.Pop(pop_data);
    test_stack.Pop(pop_data);

    // 打印test_stack
    cout << test_stack << endl;

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-链式栈-取栈顶**
 * @note
 * 测试-链式栈-取栈顶
 * ---------------
 * ---------------
 *
 * ---------------
 *
 *
 * ---------------
 */
void TestLinkedStackTop() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                    Test LinkedStack Top                   |" << endl;
    cout << "|                     测试-链式栈-取栈顶                    |" << endl << endl << endl;

    // 声明test_stack(整型链式栈)
    LinkedStack<int> test_stack;

    // 依次将1, 2, 3, 4入栈
    test_stack.Push(1);
    test_stack.Push(2);
    test_stack.Push(3);
    test_stack.Push(4);

    // 取top_data(栈顶数据项)
    int top_data;
    test_stack.Top(top_data);

    // 打印top_data
    cout << "top_data: " << top_data << endl;

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-顺序栈-入栈**
 * @note
 * 测试-顺序栈-入栈
 * ---------------
 * ---------------
 *
 * ---------------
 *
 *
 * ---------------
 */
void TestSeqStackPush() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                     Test SeqStack Push                    |" << endl;
    cout << "|                      测试-顺序栈-入栈                     |" << endl << endl << endl;

    // 声明test_stack(整型顺序栈)
    SeqStack<int> test_stack;

    // 依次将1, 2, 3, 4入栈
    test_stack.Push(1);
    test_stack.Push(2);
    test_stack.Push(3);
    test_stack.Push(4);

    // 打印test_stack
    cout << test_stack << endl;

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-顺序栈-出栈**
 * @note
 * 测试-顺序栈-出栈
 * ---------------
 * ---------------
 *
 * ---------------
 *
 *
 * ---------------
 */
void TestSeqStackPop() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                     Test SeqStack Pop                     |" << endl;
    cout << "|                      测试-顺序栈-出栈                     |" << endl << endl << endl;

    // 声明test_stack(整型顺序栈)
    SeqStack<int> test_stack;

    // 依次将1, 2, 3, 4入栈
    test_stack.Push(1);
    test_stack.Push(2);
    test_stack.Push(3);
    test_stack.Push(4);

    // 栈顶出栈3次
    int pop_data;

    test_stack.Pop(pop_data);
    test_stack.Pop(pop_data);
    test_stack.Pop(pop_data);

    // 打印test_stack
    cout << test_stack << endl;

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-链式栈-取栈顶**
 * @note
 * 测试-链式栈-取栈顶
 * ---------------
 * ---------------
 *
 * ---------------
 * 声明test_stack(整型链式栈)\n
 * 依次将1, 2, 3, 4入栈\n
 * 取top_data(栈顶数据项)\n
 * 打印top_data\n
 *
 *
 * ---------------
 */
void TestSeqStackTop() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                     Test SeqStack Top                     |" << endl;
    cout << "|                    测试-顺序栈-取栈顶                     |" << endl << endl << endl;

    // 声明test_stack(整型链式栈)
    LinkedStack<int> test_stack;

    // 依次将1, 2, 3, 4入栈
    test_stack.Push(1);
    test_stack.Push(2);
    test_stack.Push(3);
    test_stack.Push(4);

    // 取top_data(栈顶数据项)
    int top_data;
    test_stack.Top(top_data);

    // 打印top_data
    cout << "top_data: " << top_data << endl;

    cout << "-------------------------------------------------------------" << endl << endl;
}
