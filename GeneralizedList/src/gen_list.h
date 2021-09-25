/*!
 * @file gen_list.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 广义表模板类
 * @version 0.2.1
 * @date 2021-07-14
 *
 * @copyright Copyright (c) 2021
 *  CyberDash计算机考研
 */

#ifndef CYBER_DASH_GENERALIZED_LIST_H
#define CYBER_DASH_GENERALIZED_LIST_H


#include <iostream>
#include <vector>
#include <queue>
#include "gen_list_node.h"


using namespace std;


//!
template<class T>
class GenList {

public:
  GenList();

  bool Head(Item<T>& item);
  bool Tail(GenList<T>& tail_list);

  void CopyFrom(GenList<T>& src_gen_list);
  int Length();
  int Depth();

  // void CreateList(istream& in, GenListNode<T>*& list_node_ptr, bool& inExistedList);
  void CreateListByQueue(queue<T>& char_queue, GenListNode<T>*& node_ptr, bool& in_referred_list);
  void CreateListByString(string gen_string);

  void Remove(GenListNode<T>* node_ptr);

  GenListNode<T>* ref_node_ptr;

  template<class U>
  friend istream& operator>>(istream& in, GenList<T>& gen_list);

private:
  int SubListLength_(GenListNode<T>* node_ptr);
  int SubListDepth_(GenListNode<T>* node_ptr);

  bool IsGenListNameChar_(T chr);
  bool IsGenListBeginChar_(T chr);

  void LeftBracketRegulatorQueue_(queue<T>& charQueue);
  void PassRightParenthesisAfterSharpChar(queue<T>& charQueue);
  GenListNode<T>* GenerateElemNode_(T chr);
  GenListNode<T>* GenerateChildListNode_();

  GenListNode<T>* FindReferredNodePtr_(T chr);

  GenListNode<T>* Copy_(GenListNode<T>*& node_ptr);

  vector<T> gen_list_name_vec_;
  vector<GenListNode<T>*> gen_list_node_ptr_vec_;
};


template<class T>
GenList<T>::GenList() {
  ref_node_ptr = new GenListNode<T>();
  if (ref_node_ptr == NULL) {
    cerr<<"GenList constructor wrong."<<endl;
  }
}


/**
 * @brief 线性表头结点
 * @tparam T
 * @param item
 * @return
 */
template<class T>
bool GenList<T>::Head(Item<T>& item) {

  if (this->ref_node_ptr->next == NULL) {
    return false;
  } else {
    item.type = this->ref_node_ptr->type;
    item.union_info = this->ref_node_ptr->union_info;
  }
}


template<class T>
bool GenList<T>::Tail(GenList<T>& tail_list) {

  if (ref_node_ptr->next == NULL) {
    return false;
  } else {
    tail_list.ref_node_ptr->type = GenListNode<T>::REF_TYPE;
    tail_list.ref_node_ptr->union_info.ref_count = 0;
    tail_list.ref_node_ptr->next = CopyFrom(ref_node_ptr->next->next);
  }
}


template<class T>
void GenList<T>::CopyFrom(GenList<T>& src_gen_list) {
  ref_node_ptr = Copy_(src_gen_list.ref_node_ptr);
}


template<class T>
GenListNode<T>* GenList<T>::Copy_(GenListNode<T>*& node_ptr) {

  GenListNode<T> cur_node_ptr = NULL;

  if (node_ptr != NULL) {
    cur_node_ptr = new GenListNode<T>();
    cur_node_ptr.type = node_ptr->type;

    switch (node_ptr->type) {
      case GenListNode<T>::REF_TYPE:
        cur_node_ptr->union_info.ref_count = node_ptr->union_info.ref_count;
        break;
      case GenListNode<T>::ELEM_TYPE:
        cur_node_ptr->union_info.value = node_ptr->union_info.value;
        break;
      case GenListNode<T>::CHILD_LIST_TYPE:
        cur_node_ptr.union_info.ref_node_ptr = Copy_(node_ptr->union_info.ref_node_ptr);
        break;
      default:
        break;
    }

    cur_node_ptr.next = Copy_(node_ptr->next);
  }

  return cur_node_ptr;
}


template<class T>
int GenList<T>::SubListLength_(GenListNode<T>* node_ptr) {
  if (node_ptr == NULL) {
    return 0;
  }

  int sub_list_length = SubListLength_(node_ptr->next) + 1;

  return sub_list_length;
}


template<class T>
int GenList<T>::Length() {
  int list_length = SubListLength_(this->ref_node_ptr->next);

  return list_length;
}


template<class T>
int GenList<T>::SubListDepth_(GenListNode<T> *node_ptr) {

  GenListNode<T>* cur_node_ptr = node_ptr->next;

  if (cur_node_ptr == NULL) {
    return 1;
  }

  int maxSubListDepth = 0;

  while (cur_node_ptr != NULL) {

    if (cur_node_ptr->type == GenListNode<T>::CHILD_LIST_TYPE) {

      int curSubListDepth = SubListDepth_(cur_node_ptr->union_info.ref_node_ptr);
      if (maxSubListDepth < curSubListDepth) {
        maxSubListDepth = curSubListDepth;
      }
    }

    cur_node_ptr = cur_node_ptr->next;
  }

  return maxSubListDepth + 1;
}


template<class T>
int GenList<T>::Depth() {
  return SubListDepth_(ref_node_ptr);
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
void GenList<T>::PassRightParenthesisAfterSharpChar(queue<T>& char_queue) {
  T chr = char_queue.front();
  char_queue.pop();
  if (chr != ')') {
    exit(1);
  }
}


template<class T>
bool GenList<T>::IsGenListNameChar_(T chr) {
  return isalpha(chr) && isupper(chr);
}


/**
 * @brief 判断是否是线性表的起始字符, 大写字母或者'('
 * @tparam T 线性表节点数据类型
 * @param chr 线性表字符串中的某个字符
 * @return 是or否
 */
template<class T>
bool GenList<T>::IsGenListBeginChar_(T chr) {
  return (isalpha(chr) && isupper(chr)) || chr == '(';
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
        node_ptr->union_info.ref_node_ptr = referred_node_ptr; // 指到一个已经存在的表
        referred_node_ptr->union_info.ref_count++; // 引用数+1

        in_referred_list = true;
      } else { // 不在node vector内
        node_ptr = GenerateChildListNode_(); // 创建一个子表类型(2)的节点

        GenListNode<T>* ref_node_ptr = new GenListNode<T>();
        ref_node_ptr->union_info.ref_count = 1;

        node_ptr->union_info.ref_node_ptr = ref_node_ptr; // 创建一个子表的0节点

        gen_list_name_vec_.push_back(chr);
        gen_list_node_ptr_vec_.push_back(ref_node_ptr);

        in_referred_list = false;
      }

      LeftBracketRegulatorQueue_(char_queue);

      CreateListByQueue(char_queue, node_ptr->union_info.ref_node_ptr->next, in_referred_list);
      CreateListByQueue(char_queue, node_ptr, in_referred_list);
    }
  } else if (isalpha(chr) && islower(chr)) {
    if (!in_referred_list) {
      node_ptr = GenerateElemNode_(chr);
      CreateListByQueue(char_queue, node_ptr, in_referred_list);
    }
  } else if (chr == ',') {
    CreateListByQueue(char_queue, node_ptr->next, in_referred_list);
  } else if (chr == ')') {
    if (!in_referred_list) {
      node_ptr->next = NULL;
    }
    in_referred_list = false;
  }
  else if (chr == '#') {
    if (!in_referred_list) {
      node_ptr = NULL;
      PassRightParenthesisAfterSharpChar(char_queue);
    }
    in_referred_list = false;
  }
}


template<class T>
void GenList<T>::CreateListByString(string gen_string) {
  queue<T> char_queue;
  for (int i = 0; i < gen_string.length(); i++) {
    char cur_chr = gen_string[i];
    char_queue.push(cur_chr);
  }

  bool in_referred_list = false;

  this->CreateListByQueue(char_queue, this->ref_node_ptr->next, in_referred_list);

  this->ref_node_ptr = this->ref_node_ptr->next->union_info.ref_node_ptr;
}

/*
template<class T>
void GenList<T>::CreateList(istream& in, GenListNode<T>*& list_node_ptr, bool& inExistedList) {

  T chr;
  in>>chr;

  bool isGenListBegin = IsGenListBeginChar_(chr);

  GenListNode<T>* in_vector_ptr = NULL;

  if (isGenListBegin) {
    bool isGenListName = this->IsGenListNameChar_(chr);

    if (isGenListName) { // 大写字母

      in_vector_ptr = this->FindReferredNodePtr_(chr); // 检查是否在vector内

      if (in_vector_ptr != NULL) {
        list_node_ptr = this->GenerateChildListNode_(); // 创建一个子表类型(2)的节点
        list_node_ptr->union_info.ref_node_ptr = in_vector_ptr; // 指到一个已经存在的表
        in_vector_ptr->union_info.ref_count++; // 引用数+1

        this->LeftBracketRegulator_(in, chr);

        inExistedList = true;
        CreateList(in, in_vector_ptr->next, inExistedList);

        CreateList(in, list_node_ptr, inExistedList);
      } else { // 不在node vector内
        list_node_ptr = this->GenerateChildListNode_(); // 创建一个子表类型(2)的节点
        gen_list_name_vec_.push_back(chr);
        gen_list_node_ptr_vec_.push_back(list_node_ptr);

        inExistedList = false;

        this->LeftBracketRegulator_(in, chr);

        list_node_ptr->union_info.ref_node_ptr = new GenListNode<T>(); // 创建一个子表的0节点
        list_node_ptr->union_info.ref_node_ptr->union_info.ref_count = 1; // 引用数+1

        CreateList(in, list_node_ptr->union_info.ref_node_ptr->next, inExistedList);
        CreateList(in, list_node_ptr, inExistedList);
      }
    }


  } else if (isalpha(chr) && islower(chr)) {
    if (!inExistedList) {
      list_node_ptr =  this->GenerateElemNode_(chr);
    }
    CreateList(in, list_node_ptr, inExistedList);
  } else if (chr == ',') {
    CreateList(in, list_node_ptr->next, inExistedList);
  } else if (chr == ')') {
    if (!inExistedList) {
      list_node_ptr->next = NULL;
    }
    inExistedList = false;
  } else if (chr == '#') {
    if (!inExistedList) {
      list_node_ptr == NULL;
    }
  }
}
 */



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

  gen_list.CreateListByQueue(char_queue, gen_list.ref_node_ptr->next, in_referred_list);

  gen_list.ref_node_ptr = gen_list.ref_node_ptr->next->union_info.ref_node_ptr;
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
  node_ptr->type = GenListNode<T>::ELEM_TYPE;
  node_ptr->union_info.value = chr;

  return node_ptr;
}


/**
 * @brief 创建子表节点
 * @tparam T
 * @return
 */
template<class T>
GenListNode<T>* GenList<T>::GenerateChildListNode_() {

  GenListNode<T>* node_ptr = new GenListNode<T>();
  node_ptr->type = GenListNode<T>::CHILD_LIST_TYPE;

  return node_ptr;
}


#endif // CYBER_DASH_GENERALIZED_LIST_H
