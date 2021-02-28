//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2021/2/28.
//

#include "test.h"
#include "link_queue.h"


void TestGetSize() {

  cout<<endl;
  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<"                     Test Queue GetSize                      "<<endl;
  cout<<"                         测试队列Size                         "<<endl<<endl<<endl;

  LinkQueue<string> old_memory_queue;

  old_memory_queue.EnQueue("反反复复月光太迷惑");
  old_memory_queue.EnQueue("却还挂在天一边嘲笑我");
  old_memory_queue.EnQueue("过分在意别人给的冷漠");
  old_memory_queue.EnQueue("我该开始为自己而活");

  old_memory_queue.EnQueue("轻轻把沉重的过去上锁");
  old_memory_queue.EnQueue("离开曾经被你溺爱的我");
  old_memory_queue.EnQueue("离开那离不开你的懦弱");
  old_memory_queue.EnQueue("继续往前找另一个自我");

  old_memory_queue.EnQueue("终于把心痛的过去挣脱");
  old_memory_queue.EnQueue("离开自己看清真假对错");
  old_memory_queue.EnQueue("不是飞蛾没资格扑火");
  old_memory_queue.EnQueue("伤到了底总有清醒时候");

  cout<<"Old memory queue size: "<<old_memory_queue.GetSize()<<endl;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void TestEnQueue() {
  cout<<endl;
  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<"                     Test Queue Enqueue                      "<<endl;
  cout<<"                         测试队列入队                          "<<endl<<endl<<endl;

  LinkQueue<int> int_queue;

  cout<<"Enqueue 4 integers."<<endl<<endl;

  int_queue.EnQueue(1);
  int_queue.EnQueue(2);
  int_queue.EnQueue(3);
  int_queue.EnQueue(4);

  cout << int_queue;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void TestDeQueue() {
  cout<<endl;
  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<"                     Test Queue Dequeue                      "<<endl;
  cout<<"                         测试队列出队                          "<<endl<<endl<<endl;

  LinkQueue<double> double_queue;

  cout<<"double_queue enqueue 4 numbers."<<endl;

  double_queue.EnQueue(1.1);
  double_queue.EnQueue(2.2);
  double_queue.EnQueue(3.3);
  double_queue.EnQueue(4.4);

  cout << double_queue << endl;

  cout<<"double_queue dequeue."<<endl<<endl;

  double frontData;
  double_queue.DeQueue(frontData);

  cout << double_queue;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void TestGetFront() {
  cout<<endl;
  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<"                     Test Queue Dequeue                      "<<endl;
  cout<<"                         测试队列队头                          "<<endl<<endl<<endl;

  LinkQueue<string> string_queue;

  string_queue.EnQueue("听我的");
  string_queue.EnQueue("买买买");
  string_queue.EnQueue("买冰箱");
  string_queue.EnQueue("什么都要听我的");
  string_queue.EnQueue("闹够了没有");
  string_queue.EnQueue("我不要你觉得");
  string_queue.EnQueue("我要我觉得");

  string front_data;

  string_queue.GetFront(front_data);
  cout<<"The front of the queue: "<<front_data<<endl;

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}


void TestIsEmpty() {
  cout<<endl;
  cout<<"------------------------- CyberDash -------------------------"<<endl;
  cout<<"                    Test Queue MakeEmpty                     "<<endl;
  cout<<"                         测试清空队列                          "<<endl<<endl<<endl;
  LinkQueue<string> LinkinPark_song_queue;

  LinkinPark_song_queue.EnQueue("<In the end>");
  LinkinPark_song_queue.EnQueue("<Crawling>");
  LinkinPark_song_queue.EnQueue("<One more light>");

  bool is_empty = LinkinPark_song_queue.IsEmpty();
  if (is_empty) {
    cout<<"LinkinPark_song_queue is empty."<<endl;
  } else {
    cout<<"LinkinPark_song_queue isn't empty."<<endl;
  }

  cout<<endl<<"call function MakeEmpty."<<endl<<endl;

  LinkinPark_song_queue.MakeEmpty();

  is_empty = LinkinPark_song_queue.IsEmpty();
  if (is_empty) {
    cout<<"LinkinPark_song_queue is empty."<<endl;
  } else {
    cout<<"LinkinPark_song_queue isn't empty."<<endl;
  }

  cout<<"-------------------------------------------------------------"<<endl<<endl;
}
