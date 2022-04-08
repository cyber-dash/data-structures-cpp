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
#include <algorithm>
#include "gen_list_node.h"


using namespace std;


//! 广义表模板类
template<class T>
class GenList {

public:

  // 构造函数
  GenList();

  // 线性表头结点
  bool Head(Item<T>& item);
  // 线性表尾
  bool Tail(GenList<T>& tail_list);

  // CyberDash批注:
  // 殷人昆版本中, 使用了一段线性结构保存线性表的名称(大写字母),
  // 原书中使用数组, 本代码使用vector, 因此在复制时, 需要将这部分vector也复制, 并做相应的数据指向
  // 这种方式本身, 对复制操作就比较不友好，如果优化, 则结点元素与书中的结构不太相同
  // 因此, 目前不再对此进行进一步实现。
  //
  // 未来如果实现它, 也只可能会在其他版本(或其他代码)中实现此功能
  void CopyFrom(GenList<T>& src_gen_list);

  // 长度
  int Length();
  // 深度
  int Depth();

  // 使用char队列创建广义表(递归)
  void CreateGenListByQueueRecursive(queue<T>& char_queue, GenListNode<T>*& node, bool& in_referred_list);
  // 使用字符串创建广义表
  void CreateListByString(string gen_list_string);

  // 删除结点, todo: 未实现
  void Remove(GenListNode<T>* node_ptr);

  string ToString();

  GenListNode<T>* ref_node_; //!< 广义表的引用结点

  // 输入广义表
  template<class U>
  friend istream& operator>>(istream& in, GenList<T>& gen_list);

private:
  // 子表打印
  void SubGenToStringRecursive_(GenListNode<T>* node, vector<T>& char_vec);
  // 子表长度(递归)
  int SubGenListLengthRecursive_(GenListNode<T>* un_ref_type_node);
  // 子表深度(递归)
  int SubGenListDepthRecursive_(GenListNode<T>* ref_type_node);

  // 是否是表名(大写字母)
  bool IsGenListNameChar_(T chr);
  // 是否是表起始字符(大写字母或者'(')
  bool IsGenListBeginChar_(T chr);

  // 左括号处理
  void LeftBracketHandler_(queue<T>& char_queue);
  // '#'对应的右括号处理
  void PassRightBracketAfterSharpChar(queue<T>& char_queue);

  // 新建元素结点
  GenListNode<T>* NewElemTypeNode_(T chr);
  // 新建子表节点
  GenListNode<T>* NewChildGenListNode_();

  // 查找已经被引用的结点
  GenListNode<T>* FindReferredNodePtr_(T chr);
  // 复制子树,
  GenListNode<T>* Copy_(GenListNode<T>*& ref_type_node);

  vector<T> gen_list_name_vec_; //!< 各表节点的vector
  vector<GenListNode<T>*> gen_list_node_vec_; //!< 各表节点指针的vector
};


/*!
 * @brief 构造函数(无参数)
 * @tparam T 类型模板参数
 */
template<class T>
GenList<T>::GenList() {
  this->ref_node_ = new GenListNode<T>();
  if (this->ref_node_ == NULL) {
    cerr<<"GenList constructor wrong."<<endl;
  }
}


/*!
 * @brief 线性表头结点
 * @tparam T 类型模板参数
 * @param item 数据变量(存储表头数据)
 * @return 是否获取成功
 */
template<class T>
bool GenList<T>::Head(Item<T>& item) {

  if (this->ref_node_->next == NULL) {
    return false;
  } else {
    item.type = this->ref_node_->type;
    item.union_info = this->ref_node_->union_info;
  }
}


/*!
 * @brief 线性表尾
 * @tparam T 类型模板参数
 * @param tail_list 广义表变量(存储表尾)
 * @return 是否获取成功
 */
template<class T>
bool GenList<T>::Tail(GenList<T>& tail_list) {

  if (ref_node_->next == NULL) {
    return false;
  } else {
    tail_list.ref_node_->type = GenListNode<T>::REF_TYPE;
    tail_list.ref_node_->union_info.ref_count = 0;
    tail_list.ref_node_->next = CopyFrom(this->ref_node_->next->next);
  }
}


/*!
 *
 * @tparam T
 * @param src_gen_list
 * @note
 * CyberDash批注:
 * 殷人昆版本中, 使用了一段线性结构保存线性表的名称(大写字母),
 * 原书中使用数组, 本代码使用vector, 因此在复制时, 需要将这部分vector也复制, 并做相应的数据指向
 * 这种方式本身, 对复制操作就比较不友好，如果优化, 则结点元素与书中的结构不太相同
 * 因此, 目前不再对此进行进一步实现。
 *
 * 未来如果实现它, 也只可能会在其他版本(或其他代码)中实现此功能
 */
template<class T>
void GenList<T>::CopyFrom(GenList<T>& src_gen_list) {
  ref_node_ = Copy_(src_gen_list.ref_node_);
}


template<class T>
GenListNode<T>* GenList<T>::Copy_(GenListNode<T>*& ref_type_node) {

  GenListNode<T>* cur_node = NULL;

  if (ref_type_node != NULL) {
    cur_node = new GenListNode<T>();
    cur_node->type = ref_type_node->type;

    switch (ref_type_node->type) {
      case GenListNode<T>::REF_TYPE:
          cur_node->union_info.ref_count = ref_type_node->union_info.ref_count;
        break;
      case GenListNode<T>::ELEM_TYPE:
          cur_node->union_info.value = ref_type_node->union_info.value;
        break;
      case GenListNode<T>::CHILD_LIST_TYPE:
          cur_node->union_info.ref_node = Copy_(ref_type_node->union_info.ref_node);
        break;
      default:
        break;
    }

    cur_node->next = Copy_(ref_type_node->next);
  }

  return cur_node;
}


/*!
 * @brief 获取子表长度(递归)
 * @tparam T 参数模板类型
 * @param un_ref_type_node 非引用类型(type为1或2)结点指针
 * @return 长度
 */
template<class T>
int GenList<T>::SubGenListLengthRecursive_(GenListNode<T>* un_ref_type_node) {
  if (un_ref_type_node == NULL) {
    return 0;
  }

  int sub_list_length = SubGenListLengthRecursive_(un_ref_type_node->next) + 1;

  return sub_list_length;
}


/*!
 * @brief 获取长度
 * @tparam T 参数模板类型
 * @return 长度
 */
template<class T>
int GenList<T>::Length() {
  int list_length = SubGenListLengthRecursive_(this->ref_node_->next);

  return list_length;
}


/*!
 * @brief 获取深度
 * @tparam T 参数模板类型
 * @return 深度
 */
template<class T>
int GenList<T>::Depth() {
  return SubGenListDepthRecursive_(this->ref_node_);
}


/*!
 * @brief 获取子表深度(递归)
 * @tparam T 类型模板参数
 * @param ref_type_node 子表的引用类型(type为0)结点指针
 * @return 深度
 */
template<class T>
int GenList<T>::SubGenListDepthRecursive_(GenListNode<T>* ref_type_node) {

  GenListNode<T>* cur_node = ref_type_node->next;

  if (cur_node == NULL) {
    return 1;
  }

  int max_sub_list_depth = 1; // 1为深度的最小可能值

  while (cur_node != NULL) {

    if (cur_node->type == GenListNode<T>::CHILD_LIST_TYPE) {

      int sub_list_depth = SubGenListDepthRecursive_(cur_node->union_info.ref_node);
      if (max_sub_list_depth < sub_list_depth) {
          max_sub_list_depth = sub_list_depth;
      }
    }

    cur_node = cur_node->next;
  }

  return max_sub_list_depth + 1;
}


/*!
 * @brief 左括号处理函数
 * @tparam T 类型模板参数
 * @param char_queue 字符队列
 */
template<class T>
void GenList<T>::LeftBracketHandler_(queue<T>& char_queue) {
  T chr = char_queue.front();
  char_queue.pop();
  if (chr != '(') {
    exit(1);
  }
}


/*!
 * @brief '#'对应的右括号处理
 * @tparam T 类型模板参数
 * @param char_queue
 */
template<class T>
void GenList<T>::PassRightBracketAfterSharpChar(queue<T>& char_queue) {
  T chr = char_queue.front();
  char_queue.pop();
  if (chr != ')') {
    exit(1);
  }
}


/*!
 * @brief 判断是否是表名(大写字母)
 * @tparam T 类型模板参数
 * @param chr 线性表字符串中的某个字符
 * @return 是or否
 */
template<class T>
bool GenList<T>::IsGenListNameChar_(T chr) {
  return isalpha(chr) && isupper(chr);
}


/*!
 * @brief 判断是否是线性表的起始字符, 大写字母或者'('
 * @tparam T 线性表节点数据类型
 * @param chr 线性表字符串中的某个字符
 * @return 是or否
 */
template<class T>
bool GenList<T>::IsGenListBeginChar_(T chr) {
  return (isalpha(chr) && isupper(chr)) || chr == '(';
}


/*!
 * @brief 使用char队列创建广义表(递归)
 * @tparam T 类型模板参数
 * @param char_queue char队列
 * @param node 节点指针
 * @param in_referred_list 该节点是否已经被引用
 * @note
 *  注意: 本实现中, 子表名必须使用大写字母表示, 如E(B(C(a)),D(a),G(#));
 *  如果想要实现兼容无需子表名的广义表, 如(((a)), (a))等, 则本项目的很多实现需要较大调整
 *  特别是gen_list_name_vec_这个变量, 尽量取消使用这个结构
 */
template<class T>
void GenList<T>::CreateGenListByQueueRecursive(queue<T>& char_queue, GenListNode<T>*& node, bool& in_referred_list) {

  // 字符队列出队
  T chr = char_queue.front();
  char_queue.pop();

  GenListNode<T>* referred_node = NULL;

  bool is_gen_list_begin_char = this->IsGenListBeginChar_(chr); // 是否是大写字母或者'('
  if (is_gen_list_begin_char) {

    bool is_gen_list_name_char = this->IsGenListNameChar_(chr); // 是否是大写字母
    if (is_gen_list_name_char) {

      referred_node = this->FindReferredNodePtr_(chr); // 检查该字符所对应的结点, 是否已经在vector内

      if (referred_node != NULL) {
        node = this->NewChildGenListNode_(); // 创建一个子表结点, 即类型(2)的节点
        node->union_info.ref_node = referred_node; // 指到这个已经存在的子表
        referred_node->union_info.ref_count++; // 该字表对应的引用数+1

        in_referred_list = true;
      } else { // 不在node vector内
        node = this->NewChildGenListNode_();              // 创建一个类型(2)的子表节点, node指到该结点
        GenListNode<T>* ref_type_node = new GenListNode<T>();  // 创建一个类型(0)的引用节点
        ref_type_node->union_info.ref_count = 1;               // 引用结点的引用数ref_count初始化为1
        node->union_info.ref_node = ref_type_node;             // 子表结点的ref_node --> 引用结点

        this->gen_list_name_vec_.push_back(chr);
        this->gen_list_node_vec_.push_back(ref_type_node);

        in_referred_list = false;
      }

      LeftBracketHandler_(char_queue); // 将队列中的'('出队

      CreateGenListByQueueRecursive(char_queue, node->union_info.ref_node->next, in_referred_list);
      CreateGenListByQueueRecursive(char_queue, node, in_referred_list);
    }
  } else if (isalpha(chr) && islower(chr)) {
    if (!in_referred_list) {  // 没有在进行遍历子表
      node = NewElemTypeNode_(chr);
      CreateGenListByQueueRecursive(char_queue, node, in_referred_list);
    }
  } else if (chr == ',') {
    CreateGenListByQueueRecursive(char_queue, node->next, in_referred_list);
  } else if (chr == ')') {
    if (!in_referred_list) {
      node->next = NULL;
    }
    in_referred_list = false;
  }
  else if (chr == '#') {
    if (!in_referred_list) {
      node = NULL;
      PassRightBracketAfterSharpChar(char_queue);
    }
    in_referred_list = false;
  }
}


/*!
 * @brief 使用字符串创建广义表
 * @tparam T 模板节点类型
 * @param gen_list_string 广义表字符串
 * @note
 * 先将字符串放入队列中
 * 调用CreateGenListByQueueRecursive
 * 调整ref_node_指向的结点
 */
template<class T>
void GenList<T>::CreateListByString(string gen_list_string) {

  // 先将字符串放入队列中
  queue<T> char_queue;
  for (int i = 0; i < gen_list_string.length(); i++) {
    char_queue.push(gen_list_string[i]);
  }

  bool in_referred_list = false;

  // 调用CreateGenListByQueueRecursive
  this->CreateGenListByQueueRecursive(char_queue, this->ref_node_->next, in_referred_list);

  // 调整ref_node_
  this->ref_node_ = this->ref_node_->next->union_info.ref_node;
}


/*!
 * @brief 输入广义表(重载标准输入)
 * @tparam T 类型模板参数
 * @param in 输入流
 * @param gen_list 广义表(的引用)
 * @return 输入流(的引用)
 */
template<class T>
istream& operator>>(istream& in, GenList<T>& gen_list) {

  string input_str;
  cout<<"Input the string:"<<endl;

  in >> input_str;

  gen_list.CreateListByString(input_str);

  return in;
}


/*!
 * @brief 查找已经被引用的结点
 * @tparam T 类型模板参数
 * @param chr 字符
 * @return 已经被引用的节点的地址
 */
template<class T>
GenListNode<T>* GenList<T>::FindReferredNodePtr_(T chr) {

  GenListNode<T>* node = NULL;

  typename vector<T>::iterator name_iter = gen_list_name_vec_.begin();
  typename vector<GenListNode<T>*>::iterator node_iter = gen_list_node_vec_.begin();

  // 遍历this->gen_list_name, 找到存在于字符串中的字符
  for (; name_iter != this->gen_list_name_vec_.end(); name_iter++, node_iter++) {
    if (chr == *name_iter) {
      node = *node_iter;
      break;
    }
  }

  return node;
}


/*!
 * @brief 新建元素结点
 * @tparam T 类型模板参数
 * @param chr 字符
 * @return 结点地址
 */
template<class T>
GenListNode<T>* GenList<T>::NewElemTypeNode_(T chr) {

  GenListNode<T>* node = new GenListNode<T>();
  node->type = GenListNode<T>::ELEM_TYPE;
  node->union_info.value = chr;

  return node;
}


/*!
 * @brief 新建子表节点
 * @tparam T 类型模板参数
 * @return 结点地址
 */
template<class T>
GenListNode<T>* GenList<T>::NewChildGenListNode_() {

  GenListNode<T>* node = new GenListNode<T>();
  node->type = GenListNode<T>::CHILD_LIST_TYPE;

  return node;
}


template<class T>
string GenList<T>::ToString() {
  vector<T> char_vec;
  this->SubGenToStringRecursive_(this->ref_node_, char_vec);

  string gen_list_string(char_vec.begin(), char_vec.end());
  return gen_list_string;
}


/*!
 * @brief 子表的字符化(递归)
 * @tparam T
 * @param ref_type_node
 * @param char_vec
 */
template<class T>
void GenList<T>::SubGenToStringRecursive_(GenListNode<T>* ref_type_node, vector<T>& char_vec) {

  for (int i = 0; i < this->gen_list_node_vec_.size(); i++) {
    if (this->gen_list_node_vec_[i] == ref_type_node) {
      char_vec.push_back(this->gen_list_name_vec_[i]);
      char_vec.push_back('(');
    }
  }

  GenListNode<T>* cur_node = ref_type_node->next;
  if (cur_node == NULL) {
    char_vec.push_back('#');
    char_vec.push_back(')');
  }

  while (cur_node != NULL) {
    if (cur_node->type == GenListNode<T>::CHILD_LIST_TYPE) {
      SubGenToStringRecursive_(cur_node->union_info.ref_node, char_vec);
    } else if (cur_node->type == GenListNode<T>::ELEM_TYPE) {
      char_vec.push_back(cur_node->union_info.value);
    }
    if (cur_node->next != NULL) {
      char_vec.push_back(',');
    }
    cur_node = cur_node->next;
  }

  char_vec.push_back(')');
}


#endif // CYBER_DASH_GENERALIZED_LIST_H
