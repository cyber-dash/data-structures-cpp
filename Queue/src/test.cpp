/*!
 * @file test.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 队列测试.cpp文件
 * @version 0.2.1
 * @date 2021-10-9
 */

#include "test.h"
#include "linked_queue.h"


void TestLength() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                     Test Queue Length                     |" << endl;
    cout << "|                        测试队列Size                        |" << endl << endl << endl;

    LinkedQueue<string> old_memory_queue;

    string old_memory[12] = {
        "反反复复月光太迷惑", "却还挂在天一边嘲笑我",
        "过分在意别人给的冷漠", "我该开始为自己而活",

        "轻轻把沉重的过去上锁", "离开曾经被你溺爱的我",
        "离开那离不开你的懦弱", "继续往前找另一个自我",

        "终于把心痛的过去挣脱", "离开自己看清真假对错",
        "不是飞蛾没资格扑火", "伤到了底总有清醒时候"
    };

    for (int i = 0; i < 12; i++) {
        cout << "Old memory enqueue: " << old_memory[i] << endl;
        old_memory_queue.EnQueue(old_memory[i]);
    }

    cout << endl << "Old memory queue size: " << old_memory_queue.Length() << endl;

    cout << "-------------------------------------------------------------" << endl << endl;
}


void TestEnQueue() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                    Test Queue Enqueue                     |" << endl;
    cout << "|                        测试队列入队                        |" << endl << endl << endl;

    LinkedQueue<int> int_queue;

    cout << "Enqueue 4 integers." << endl << endl;

    int_queue.EnQueue(1);
    int_queue.EnQueue(2);
    int_queue.EnQueue(3);
    int_queue.EnQueue(4);

    cout << int_queue;

    cout << "-------------------------------------------------------------" << endl << endl;
}


void TestDeQueue() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                    Test Queue Dequeue                     |" << endl;
    cout << "|                        测试队列出队                        |" << endl << endl << endl;

    LinkedQueue<double> double_queue;

    cout << "double_queue enqueue 4 numbers." << endl;

    double_queue.EnQueue(1.1);
    double_queue.EnQueue(2.2);
    double_queue.EnQueue(3.3);
    double_queue.EnQueue(4.4);

    cout << double_queue << endl;

    cout << "double_queue dequeue." << endl << endl;

    double frontData;
    double_queue.DeQueue(frontData);

    cout << double_queue;

    cout << "-------------------------------------------------------------" << endl << endl;
}


void TestGetFrontAndGetRear() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                  Test Queue Front & Rear                  |" << endl;
    cout << "|                   测试队列获取队头/获取队尾                  |" << endl << endl << endl;

    LinkedQueue<string> string_queue;

    string_queue.EnQueue("听我的");
    string_queue.EnQueue("买买买");
    string_queue.EnQueue("买冰箱");
    string_queue.EnQueue("什么都要听我的");
    string_queue.EnQueue("闹够了没有");
    string_queue.EnQueue("我不要你觉得");
    string_queue.EnQueue("我要我觉得");

    string front_data;
    string rear_data;

    string_queue.Front(front_data);
    string_queue.Rear(rear_data);

    cout << "The front of the queue: " << front_data << endl;
    cout << "The rear of the queue: " << rear_data << endl;

    cout << "-------------------------------------------------------------" << endl << endl;
}


void TestIsEmpty() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                     Test Queue Clear                      |" << endl;
    cout << "|                        测试清空队列                        |" << endl << endl << endl;
    LinkedQueue<string> LinkinPark_song_queue;

    LinkinPark_song_queue.EnQueue("<In the end>");
    LinkinPark_song_queue.EnQueue("<Crawling>");
    LinkinPark_song_queue.EnQueue("<One more light>");

    bool is_empty = LinkinPark_song_queue.IsEmpty();
    if (is_empty) {
        cout << "LinkinPark_song_queue is empty." << endl;
    } else {
        cout << "LinkinPark_song_queue isn't empty." << endl;
    }

    cout << endl << "call function Clear." << endl << endl;

    LinkinPark_song_queue.Clear();

    is_empty = LinkinPark_song_queue.IsEmpty();
    if (is_empty) {
        cout << "LinkinPark_song_queue is empty." << endl;
    } else {
        cout << "LinkinPark_song_queue isn't empty." << endl;
    }

    cout << "-------------------------------------------------------------" << endl << endl;
}


void TestPrint() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                      Test Operator <<                     |" << endl;
    cout << "|                      测试队列operator<<                    |" << endl << endl << endl;

    LinkedQueue<string> string_queue;

    string_queue.EnQueue("听我的");
    string_queue.EnQueue("买买买");
    string_queue.EnQueue("买冰箱");
    string_queue.EnQueue("什么都要听我的");
    string_queue.EnQueue("闹够了没有");
    string_queue.EnQueue("我不要你觉得");
    string_queue.EnQueue("我要我觉得");

    cout << string_queue;

    cout << "-------------------------------------------------------------" << endl << endl;
}
