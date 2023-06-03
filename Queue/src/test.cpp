/*!
 * @file test.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 队列测试.cpp文件
 * @version 0.2.1
 * @date 2021-10-9
 */

#include "test.h"
#include "linked_queue.h"
#include "circular_queue.h"
#include "double_ended_queue.h"


/*!
 * @brief **测试-链式队列-长度**
 * @note
 * 测试-链式队列-长度
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 声明队列**\n
 * + **2 数据入队队列**\n
 * + **3 打印队列长度**\n
 */
void TestLength() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                     Test Queue Length                     |" << endl;
    cout << "|                        测试队列Size                        |" << endl << endl << endl;

    // ---------- 1 声明队列 ----------

    LinkedQueue<string> old_memory_queue;

    // ---------- 2 数据入队队列 ----------

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

    // ---------- 3 打印队列长度 ----------

    cout << endl << "Old memory queue length: " << old_memory_queue.Length() << endl;

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-链式队列-入队**
 * @note
 * 测试-链式队列-入队
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 声明队列**\n
 * + **2 数据入队队列**\n
 * + **3 打印队列**\n
 */
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


/*!
 * @brief **测试-链式队列-出队**
 * @note
 * 测试-链式队列-出队
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 声明队列**\n
 * + **2 数据入队队列**\n
 * + **3 队头出队**\n
 * + **4 打印队列**\n
 */
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


/*!
 * @brief **测试-链式队列-获取队头/队尾数据**
 * @note
 * 测试-链式队列-获取队头/队尾数据
 * --------------------------
 * --------------------------
 *
 * --------------------------
 * + **1 声明队列**\n
 * + **2 数据入队队列**\n
 * + **3 打印队头/队尾数据**\n
 */
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


/*!
 * @brief **测试-链式队列-清空**
 * @note
 * 测试-链式队列-清空
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 声明队列**\n
 * + **2 数据入队队列**\n
 * + **3 清空**\n
 */
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


/*!
 * @brief **测试-链式队列-打印**
 * @note
 * 测试-链式队列-打印
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 声明队列**\n
 * + **2 数据入队队列**\n
 * + **3 打印队列**\n
 */
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


/*!
 * @brief **测试-循环队列-长度**
 * @note
 * 测试-循环队列-长度
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 声明队列**\n
 * + **2 数据入队队列**\n
 * + **3 打印队列长度**\n
 */
void Test_CircularQueue_Length() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                  Test CircularQueue Length                     |" << endl;
    cout << "|                        测试队列Size                        |" << endl << endl << endl;

    // ---------- 1 声明队列 ----------

    CircularQueue<string> old_memory_queue;

    // ---------- 2 数据入队队列 ----------

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

    // ---------- 3 打印队列长度 ----------

    cout << endl << "Old memory queue length: " << old_memory_queue.Length() << endl;

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-循环队列-入队**
 * @note
 * 测试-循环队列-入队
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 声明队列**\n
 * + **2 数据入队队列**\n
 * + **3 打印队列**\n
 */
void Test_CircularQueue_EnQueue() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                 Test CircularQueue Enqueue                |" << endl;
    cout << "|                        测试队列入队                        |" << endl << endl << endl;

    CircularQueue<int> int_queue;

    cout << "Enqueue 4 integers." << endl << endl;

    int_queue.EnQueue(1);
    int_queue.EnQueue(2);
    int_queue.EnQueue(3);
    int_queue.EnQueue(4);

    cout << int_queue;

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-循环队列-出队**
 * @note
 * 测试-循环队列-出队
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 声明队列**\n
 * + **2 数据入队队列**\n
 * + **3 队头出队**\n
 * + **4 打印队列**\n
 */
void Test_CircularQueue_DeQueue() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                 Test CircularQueue Dequeue                |" << endl;
    cout << "|                        测试队列出队                        |" << endl << endl << endl;

    CircularQueue<double> double_queue;

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


/*!
 * @brief **测试-循环队列-获取队头/队尾数据**
 * @note
 * 测试-循环队列-获取队头/队尾数据
 * --------------------------
 * --------------------------
 *
 * --------------------------
 * + **1 声明队列**\n
 * + **2 数据入队队列**\n
 * + **3 打印队头/队尾数据**\n
 */
void Test_CircularQueue_GetFrontAndGetRear() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|               Test CircularQueue Front & Rear                  |" << endl;
    cout << "|                   测试队列获取队头/获取队尾                  |" << endl << endl << endl;

    CircularQueue<string> string_queue;

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


/*!
 * @brief **测试-循环队列-清空**
 * @note
 * 测试-循环队列-清空
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 声明队列**\n
 * + **2 数据入队队列**\n
 * + **3 清空**\n
 */
void Test_CircularQueue_IsEmpty() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                  Test CircularQueue Clear                      |" << endl;
    cout << "|                        测试清空队列                        |" << endl << endl << endl;

    CircularQueue<string> LinkinPark_song_queue;

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


/*!
 * @brief **测试-循环队列-打印**
 * @note
 * 测试-循环队列-打印
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 声明队列**\n
 * + **2 数据入队队列**\n
 * + **3 打印队列**\n
 */
void Test_CircularQueue_Print() {
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


/*!
 * @brief **测试-循环队列-长度**
 * @note
 * 测试-循环队列-长度
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 声明队列**\n
 * + **2 数据入队队列**\n
 * + **3 打印队列长度**\n
 */
void Test_DoubleEndedQueue_Length() {

    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                  Test DoubleEndedQueue Length                     |" << endl;
    cout << "|                        测试队列Size                        |" << endl << endl << endl;

    // ---------- 1 声明队列 ----------

    DoubleEndedQueue<string> old_memory_queue;

    // ---------- 2 数据入队队列 ----------

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
        old_memory_queue.PushBack(old_memory[i]);
    }

    // ---------- 3 打印队列长度 ----------

    cout << endl << "Old memory queue length: " << old_memory_queue.Length() << endl;

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-循环队列-入队**
 * @note
 * 测试-循环队列-入队
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 声明队列**\n
 * + **2 数据入队队列**\n
 * + **3 打印队列**\n
 */
void Test_DoubleEndedQueue_EnQueue() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                 Test DoubleEndedQueue Enqueue                |" << endl;
    cout << "|                        测试队列入队                        |" << endl << endl << endl;

    DoubleEndedQueue<int> int_queue;

    cout << "Enqueue 4 integers." << endl << endl;

    int_queue.PushBack(1);
    int_queue.PushBack(2);
    int_queue.PushBack(3);
    int_queue.PushBack(4);

    cout << int_queue;

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-循环队列-出队**
 * @note
 * 测试-循环队列-出队
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 声明队列**\n
 * + **2 数据入队队列**\n
 * + **3 队头出队**\n
 * + **4 打印队列**\n
 */
void Test_DoubleEndedQueue_DeQueue() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                 Test DoubleEndedQueue Dequeue                |" << endl;
    cout << "|                        测试队列出队                        |" << endl << endl << endl;

    DoubleEndedQueue<double> double_queue;

    cout << "double_queue enqueue 4 numbers." << endl;

    double_queue.PushBack(1.1);
    double_queue.PushBack(2.2);
    double_queue.PushBack(3.3);
    double_queue.PushBack(4.4);

    cout << double_queue << endl;

    cout << "double_queue dequeue." << endl << endl;

    double frontData;
    double_queue.PopFront(frontData);

    cout << double_queue;

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-循环队列-获取队头/队尾数据**
 * @note
 * 测试-循环队列-获取队头/队尾数据
 * --------------------------
 * --------------------------
 *
 * --------------------------
 * + **1 声明队列**\n
 * + **2 数据入队队列**\n
 * + **3 打印队头/队尾数据**\n
 */
void Test_DoubleEndedQueue_GetFrontAndGetRear() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|               Test DoubleEndedQueue Front & Rear                  |" << endl;
    cout << "|                   测试队列获取队头/获取队尾                  |" << endl << endl << endl;

    DoubleEndedQueue<string> string_queue;

    string_queue.PushBack("听我的");
    string_queue.PushBack("买买买");
    string_queue.PushBack("买冰箱");
    string_queue.PushBack("什么都要听我的");
    string_queue.PushBack("闹够了没有");
    string_queue.PushBack("我不要你觉得");
    string_queue.PushBack("我要我觉得");

    string front_data;
    string rear_data;

    string_queue.Front(front_data);
    string_queue.Rear(rear_data);

    cout << "The front of the queue: " << front_data << endl;
    cout << "The rear of the queue: " << rear_data << endl;

    cout << "-------------------------------------------------------------" << endl << endl;
}


/*!
 * @brief **测试-循环队列-清空**
 * @note
 * 测试-循环队列-清空
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 声明队列**\n
 * + **2 数据入队队列**\n
 * + **3 清空**\n
 */
void Test_DoubleEndedQueue_IsEmpty() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                 Test DoubleEndedQueue Clear                      |" << endl;
    cout << "|                        测试清空队列                        |" << endl << endl << endl;

    DoubleEndedQueue<string> LinkinPark_song_queue;

    LinkinPark_song_queue.PushBack("<In the end>");
    LinkinPark_song_queue.PushBack("<Crawling>");
    LinkinPark_song_queue.PushBack("<One more light>");

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


/*!
 * @brief **测试-循环队列-打印**
 * @note
 * 测试-循环队列-打印
 * ---------------
 * ---------------
 *
 * ---------------
 * + **1 声明队列**\n
 * + **2 数据入队队列**\n
 * + **3 打印队列**\n
 */
void Test_DoubleEndedQueue_Print() {
    cout << endl;
    cout << "|------------------------ CyberDash ------------------------|" << endl;
    cout << "|                      Test Operator <<                     |" << endl;
    cout << "|                      测试队列operator<<                    |" << endl << endl << endl;

    DoubleEndedQueue<string> string_queue;

    string_queue.PushBack("听我的");
    string_queue.PushBack("买买买");
    string_queue.PushBack("买冰箱");
    string_queue.PushBack("什么都要听我的");
    string_queue.PushBack("闹够了没有");
    string_queue.PushBack("我不要你觉得");
    string_queue.PushBack("我要我觉得");

    cout << string_queue;

    cout << "-------------------------------------------------------------" << endl << endl;
}