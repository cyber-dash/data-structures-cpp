//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/7/14.
//

#include <iostream>
#include "gen_list.h"


using namespace std;


template<class T>
GenList<T>::GenList() {
  ref_node_ptr_ = new GenListNode<T>();
  if (ref_node_ptr_ == NULL) {
    cerr<<"GenList constructor wrong."<<endl;
  }
}


template<class T>
bool GenList<T>::Head(Item<T>& item) {

  if (ref_node_ptr_->next_ == NULL) {
    return false;
  } else {
    item.type_ = ref_node_ptr_->type_;
    item.union_info_ = ref_node_ptr_->union_info_;
  }
}


template<class T>
bool GenList<T>::Tail(GenList<T>& tail_list) {

  if (ref_node_ptr_->next_ == NULL) {
    return false;
  } else {
    tail_list.ref_node_ptr_->type_ = 0;
    tail_list.ref_node_ptr_->union_info_.ref_count_ = 0;
    tail_list.ref_node_ptr_->next_ = CopyFrom(ref_node_ptr_->next_->next_);
  }
}


template<class T>
void GenList<T>::CopyFrom(GenList<T>& src_gen_list) {
  ref_node_ptr_ = Copy_(src_gen_list.ref_node_ptr_);
}


template<class T>
GenListNode<T>* GenList<T>::Copy_(GenListNode<T>*& node_ptr) {

  GenListNode<T> cur_node_ptr = NULL;

  if (node_ptr != NULL) {
    cur_node_ptr = new GenListNode<T>();
    cur_node_ptr.type_ = node_ptr->type_;

    switch (node_ptr->type_) {
      case GenListNode<T>::REF_TYPE:
        cur_node_ptr->union_info_.ref_count_ = node_ptr->union_info_.ref_count_;
        break;
      case GenListNode<T>::ELEM_TYPE:
        cur_node_ptr->union_info_.value_ = node_ptr->union_info_.value_;
        break;
      case GenListNode<T>::CHILD_LIST_TYPE:
        cur_node_ptr.union_info_.ref_node_ptr_ = Copy_(node_ptr->union_info_.ref_node_ptr_);
        break;
      default:
        break;
    }

    cur_node_ptr.next_ = Copy_(node_ptr->next_);
  }

  return cur_node_ptr;
}


template<class T>
int GenList<T>::SubListLength_(GenListNode<T>* node_ptr) {
  if (node_ptr == NULL) {
    return 0;
  }

  int sub_list_length = SubListLength_(node_ptr->next_) + 1;

  return sub_list_length;
}


template<class T>
int GenList<T>::Length() {
  int list_length = SubListLength_(ref_node_ptr_);

  return list_length;
}


template<class T>
int GenList<T>::SubListDepth_(GenListNode<T> *node_ptr) {

  GenListNode<T>* cur_node_ptr = node_ptr->next_;

  if (cur_node_ptr == NULL) {
    return 1;
  }

  int maxSubListDepth = 0;

  while (cur_node_ptr != NULL) {

    if (cur_node_ptr->type_ == 2) {

      int curSubListDepth = SubListDepth_(cur_node_ptr->union_info_.ref_node_ptr_);
      if (maxSubListDepth < curSubListDepth) {
        maxSubListDepth = curSubListDepth;
      }
    }

    cur_node_ptr = cur_node_ptr->next_;
  }

  return maxSubListDepth + 1;
}


template<class T>
int GenList<T>::Depth() {
  return SubListDepth_(ref_node_ptr_);
}


template<class T>
void GenList<T>::LeftBracketRegulatorQueue_(queue<T>& char_queue) {
  T chr = char_queue.front();
  char_queue.pop();
  if (chr != '(') {
    exit(1);
  }
}


template<class T>
bool GenList<T>::IsGenListNameChar_(T chr) {
  return isalpha(chr) && isupper(chr);
}


template<class T>
bool GenList<T>::IsGenListBeginChar_(T chr) {
  return isalpha(chr) && isupper(chr) || chr == '(';
}


template<class T>
void GenList<T>::CreateListByQueue(queue<T>& char_queue, GenListNode<T>*& node_ptr, bool& in_referred_list) {

  T chr = char_queue.front();
  char_queue.pop();

  GenListNode<T>* referred_node_ptr = NULL;

  bool is_gen_list_begin_char = IsGenListBeginChar_(chr);
  if (is_gen_list_begin_char) {

    bool is_gen_list_name_char = IsGenListNameChar_(chr);
    if (is_gen_list_name_char) { // 大写字母

      referred_node_ptr = FindReferredNodePtr_(chr); // 检查是否在vector内

      if (referred_node_ptr != NULL) {
        node_ptr = GenerateChildListNode_(); // 创建一个子表类型(2)的节点
        node_ptr->union_info_.ref_node_ptr_ = referred_node_ptr; // 指到一个已经存在的表
        referred_node_ptr->union_info_.ref_count_++; // 引用数+1

        in_referred_list = true;
      } else { // 不在node vector内
        node_ptr = GenerateChildListNode_(); // 创建一个子表类型(2)的节点

        GenListNode<T>* ref_node_ptr = new GenListNode<T>();
        ref_node_ptr->union_info_.ref_count_ = 1;

        node_ptr->union_info_.ref_node_ptr_ = ref_node_ptr; // 创建一个子表的0节点

        gen_list_name_vec_.push_back(chr);
        gen_list_node_ptr_vec_.push_back(ref_node_ptr);

        in_referred_list = false;
      }

      LeftBracketRegulatorQueue_(char_queue);

      CreateListByQueue(char_queue, node_ptr->union_info_.ref_node_ptr_->next_, in_referred_list);
      CreateListByQueue(char_queue, node_ptr, in_referred_list);
    }
  } else if (isalpha(chr) && islower(chr)) {
    if (!in_referred_list) {
      node_ptr = GenerateElemNode_(chr);
    }
    CreateListByQueue(char_queue, node_ptr, in_referred_list);
  } else if (chr == ',') {
    CreateListByQueue(char_queue, node_ptr->next_, in_referred_list);
  } else if (chr == ')') {
    if (!in_referred_list) {
      node_ptr->next_ = NULL;
    }
    in_referred_list = false;
  } else if (chr == '#') {
    if (!in_referred_list) {
      node_ptr == NULL;
    }
  }
}


template<class T>
istream& operator>>(istream& in, GenList<T>& gen_list) {

  string input_str;
  cout<<"Input the string:"<<endl;

  in >> input_str;

  queue<T> char_queue;

  for (int i = 0; i < input_str.length(); i++) {
    T cur_char = input_str[i];

    if (cur_char == ';') {
      break;
    }

    char_queue.push(cur_char);
  }

  bool in_referred_list = false;

  gen_list.CreateListByQueue(char_queue, gen_list.ref_node_ptr_->next_, in_referred_list);

  gen_list.ref_node_ptr_ = gen_list.ref_node_ptr_->next_->union_info_.ref_node_ptr_;
}


template<class T>
GenListNode<T>* GenList<T>::FindReferredNodePtr_(T chr) {

  GenListNode<T>* node_ptr = NULL;

  typename vector<T>::iterator name_iter = gen_list_name_vec_.begin();
  typename vector<GenListNode<T>*>::iterator node_iter = gen_list_node_ptr_vec_.begin();

  for (; name_iter != gen_list_name_vec_.end(); name_iter++, node_iter++) {
    if (chr == *name_iter) {
      node_ptr = *node_iter;
      break;
    }
  }

  return node_ptr;
}


template<class T>
GenListNode<T>* GenList<T>::GenerateElemNode_(T chr) {

  GenListNode<T>* node_ptr = new GenListNode<T>();
  node_ptr->type_ = GenListNode<T>::ELEM_TYPE;
  node_ptr->union_info_.value_ = chr;

  return node_ptr;
}


template<class T>
GenListNode<T>* GenList<T>::GenerateChildListNode_() {

  GenListNode<T>* node_ptr = new GenListNode<T>();
  node_ptr->type_ = GenListNode<T>::CHILD_LIST_TYPE;

  return node_ptr;
}


template<class T>
void GenList<T>::CyberDashShow() {
  cout<<endl
      <<"*************************************** CyberDash ***************************************"<<endl<<endl
      <<"抖音号\"CyberDash计算机考研\", id: cyberdash_yuan"<<endl<<endl
      <<"CyberDash成员:"<<endl
      <<"元哥(cyberdash@163.com), "<<"北京邮电大学(通信工程本科)/北京邮电大学(信息与通信系统研究生)"<<endl
      <<"磊哥(alei_go@163.com), "<<"山东理工大学(数学本科)/北京邮电大学(计算机研究生)"<<endl<<endl
      <<"数据结构开源代码(C++清华大学殷人昆)魔改升级版本: https://gitee.com/cyberdash/data-structure-cpp"<<endl
      <<endl<<"*************************************** CyberDash ***************************************"<<endl<<endl;
}