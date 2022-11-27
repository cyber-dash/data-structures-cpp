/*!
 * @file simple_gen_list.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief (简单)广义表类源文件
 * @version 0.2.1
 * @date 2021-05-19
 */

#include "simple_gen_list.h"

void SimpleGenList::CreateByQueueRecursive(queue<char>& char_queue, SimpleGenListNode*& node) {

    if (char_queue.empty()) {
        return;
    }

    char chr = char_queue.front();
    char_queue.pop();

    if (chr == '(') {   // chr为'('
        node = new SimpleGenListNode(SimpleGenListNode::LIST_HEAD);
        this->CreateByQueueRecursive(char_queue, node->head); // 对&(*node)->data.head执行递归
        CreateByQueueRecursive(char_queue, node);    // 对node执行递归
    } else if (isalpha(chr)) {  // chr为字母(原子结点)
        node = new SimpleGenListNode(SimpleGenListNode::ATOM, chr);
        CreateByQueueRecursive(char_queue, node);    // 对node执行递归
    } else if (chr == ',') {    // chr为','
        CreateByQueueRecursive(char_queue, node->next);  // 对&(*node)->next执行递归
    } else if (chr == ')') {    // chr为')'
        if (node) {    // if *node不为NULL
            node->next = nullptr;   // (*node)->next设置为NULL, (如果*node为NULL, 则表示当前子表为空表, 字符串为"()")
        }
    }
}


void SimpleGenList::CreateByString(const string& gen_list_string) {

    queue<char> char_queue;
    for (int i = 0; i < gen_list_string.length(); i++) {
        char chr = gen_list_string[i];
        char_queue.push(chr);
    }

    CreateByQueueRecursive(char_queue, head_);
}


void SimpleGenList::ToCharQueueRecursive(queue<char>& char_queue, SimpleGenListNode* node) {

    // ----- 1 初始化cur结点指针 -----
    // GenListNode* cur = this.head; // 指向当前(子)广义表表头
    SimpleGenListNode* cur = node; // 指向当前(子)广义表表头

    // ----- 2 字符‘(’入队 -----
    // CircularQueueEnQueue(char_queue, '(');
    char_queue.push('(');

    // ----- 3 构造表内元素 -----
    while (cur) {   // while cur指向结点不为NULL
        if (cur->type == SimpleGenListNode::LIST_HEAD) {    // if tag为LIST_HEAD类型
            ToCharQueueRecursive(char_queue, cur->head);   // 对cur进行递归
        } else if (cur->type == SimpleGenListNode::ATOM) {  // if tag为ATOM类型
            char_queue.push(cur->data);   // cur->item.atom入队
        }

        if (cur->next != NULL) {    // if cur->next不为NULL
            char_queue.push(',');  // ','入队
        }

        cur = cur->next;    // cur指向cur->next
    }

    // ----- 4 子表遍历结束处理 -----
    char_queue.push(')');  // ')'入队
}


string SimpleGenList::ToString() {
    string str("");

    queue<char> char_queue;

    ToCharQueueRecursive(char_queue, head_);

    while (!char_queue.empty()) {
        char chr = char_queue.front();
        str.push_back(chr);

        char_queue.pop();
    }

    return str;
}