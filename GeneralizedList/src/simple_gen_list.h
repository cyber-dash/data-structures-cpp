/*!
 * @file simple_gen_list.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief (简单)广义表类
 * @version 0.2.1
 * @date 2022-11-24
 */

#ifndef CYBER_DASH_SIMPLE_GEN_LIST_H
#define CYBER_DASH_SIMPLE_GEN_LIST_H


#include <iostream>
#include <cstdlib>
#include <queue>
#include <string>


using namespace std;


class GenListNode {
public:

    /*! @brief 构造函数 */
    GenListNode(): type(ATOM), data('\0'), next(nullptr), head(nullptr) {}
    explicit GenListNode(int type, char data = '\0'):
        type(type), next(nullptr), head(nullptr), data(data) {}
        /*
    GenListNode(int type, GenListNode* head, GenListNode* next, char data = '\0'):
        type(type), next(next), head(head), data(data) {}
         */

    /*!
     * @brief 复制构造函数
     * @param node 广义表节点
     */
    GenListNode(const GenListNode& node) {
        type = node.type;
        data = node.data;
        head = node.head;
        next = node.next;
    }

    int type; //!< 类型
    char data; //!< 数据
    GenListNode* head; //!< 下一个表的地址
    GenListNode* next; //!< 下一节点指针

    static const int ATOM = 1; //!< 数据节点类型
    static const int LIST_HEAD = 2; //!< 表头类型
};



class GenList {

public:

    // 构造函数
    GenList();

    // 使用char队列创建广义表(递归)
    // void CreateGenListByQueueRecursive(queue<char>& char_queue, GenListNode* node, bool& in_referred_list);
    void CreateByQueueRecursive(queue<char>& char_queue, GenListNode*& node);

    // 使用字符串创建广义表
    void CreateListByString(const string& gen_list_string);
private:
    GenListNode* head_;
};


void GenList::CreateByQueueRecursive(queue<char> &char_queue, GenListNode*& node) {

    if (char_queue.empty()) {
        return;
    }

    char chr = char_queue.front();
    char_queue.pop();

    if (chr == '(') {   // chr为'('
        node = new GenListNode(GenListNode::LIST_HEAD);
        CreateByQueueRecursive(char_queue, node->head); // 对&(*node)->data.head执行递归
        CreateByQueueRecursive(char_queue, node);    // 对node执行递归
    } else if (isalpha(chr)) {  // chr为字母(原子结点)
        node = new GenListNode(GenListNode::ATOM, chr);
        CreateByQueueRecursive(char_queue, node);    // 对node执行递归
    } else if (chr == ',') {    // chr为','
        CreateByQueueRecursive(char_queue, node->next);  // 对&(*node)->next执行递归
    } else if (chr == ')') {    // chr为')'
        if (node) {    // if *node不为NULL
            node->next = nullptr;   // (*node)->next设置为NULL, (如果*node为NULL, 则表示当前子表为空表, 字符串为"()")
        }
    }

}


void GenList::CreateListByString(const string& gen_list_string) {

    queue<char> char_queue;
    for (int i = 0; i < gen_list_string.length(); i++) {
        char chr = gen_list_string[i];
        char_queue.push(chr);
    }

    CreateByQueueRecursive(char_queue, head_);
}

#endif // CYBER_DASH_SIMPLE_GEN_LIST_H
