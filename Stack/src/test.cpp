
#include "test.h"
#include "linked_stack.h"


void Test_LinkedStack_Push() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                   Test LinkedStack Push                   |" << endl;
    cout << "|                      测试-链式队列-入栈                      |" << endl << endl << endl;

    LinkedStack<int> test_stack;

    test_stack.Push(1);
    test_stack.Push(2);
    test_stack.Push(3);
    test_stack.Push(4);

    cout << test_stack << endl;

    cout << "-------------------------------------------------------------" << endl << endl;
}

void Test_LinkedStack_Pop() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                    Test LinkedStack Pop                   |" << endl;
    cout << "|                      测试-链式队列-出栈                      |" << endl << endl << endl;

    cout << "-------------------------------------------------------------" << endl << endl;
}


void Test_LinkedStack_Top() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                    Test LinkedStack Top                   |" << endl;
    cout << "|                     测试-链式队列-取栈顶                     |" << endl << endl << endl;

    cout << "-------------------------------------------------------------" << endl << endl;
}
