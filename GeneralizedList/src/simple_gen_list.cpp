/*!
 * @file simple_gen_list.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief (简单)广义表类源文件
 * @version 0.2.1
 * @date 2021-05-19
 */

#include "simple_gen_list.h"

void SimpleGenList::CreateByQueueRecursive_(queue<char>& char_queue, SimpleGenListNode*& node) {

    if (char_queue.empty()) {
        return;
    }

    char chr = char_queue.front();
    char_queue.pop();

    if (chr == '(') {                                                       // chr为'('
        node = new SimpleGenListNode(SimpleGenListNode::LIST);
        this->CreateByQueueRecursive_(char_queue, node->head);              // 对node->head执行递归
        CreateByQueueRecursive_(char_queue, node);                          // 对node执行递归
    } else if (isalpha(chr)) {                                              // chr为字母(原子结点)
        node = new SimpleGenListNode(SimpleGenListNode::ATOM, chr);
        CreateByQueueRecursive_(char_queue, node);                          // 对node执行递归
    } else if (chr == ',') {                                                // chr为','
        CreateByQueueRecursive_(char_queue, node->next);                    // 对node->next执行递归
    } else if (chr == ')') {                                                // chr为')'
        if (node) {                                                         // if node不为NULL
            node->next = nullptr;                                           // node->next设置为NULL, (如果node为NULL, 则表示当前子表为空表, 字符串为"()")
        }
    }
}


void SimpleGenList::CreateByString(const string& gen_list_string) {

    queue<char> char_queue;
    for (int i = 0; i < gen_list_string.length(); i++) {
        char chr = gen_list_string[i];
        char_queue.push(chr);
    }

    CreateByQueueRecursive_(char_queue, head_);
}


/*!
 * @brief **子表构造字符队列(递归)**
 * @param char_queue 字符队列
 * @param node 表头结点
 * @return 执行结果
 * @note
 * 子表构造字符队列(递归)
 * ------------------
 * ------------------
 *
 * ------------------
 * + **1 非法表头结点处理**\n
 * **if** node不是LIST(表)类型 :\n
 * &emsp; 返回false\n\n
 * + **2 '('入队**\n
 * '('入队char_queue\n\n
 * + **3 递归处理表内结点**\n
 * cur(遍历结点)指向list_head_node->head(当前子表的表头结点)\n\n
 * **while loop** cur != null :\n
 * &emsp; **if** cur结点为LIST(表)类型 : \n
 * &emsp;&emsp; 对cur结点进行递归(使用当前的char_queue)\n
 * &emsp;&emsp; **if** 递归失败 :\n
 * &emsp;&emsp;&emsp; 返回false\n
 * &emsp; **else if** cur结点为ATOM(原子)类型 :\n
 * &emsp;&emsp; cur->data入队char_queue\n\n
 * &emsp; **if** cur结点存在下一结点 :\n
 * &emsp;&emsp; ','入队char_queue\n\n
 * &emsp; cur指向cur->next\n\n
 * + **4 ')'入队**\n
 * ')'入队char_queue\n\n
 * + **5 退出函数**\n
 * 返回true\n
 */
bool SimpleGenList::ToCharQueueRecursive_(queue<char>& char_queue, SimpleGenListNode* node) {

    // ---------- 1 非法表头结点处理 ----------

    if (node->type != SimpleGenListNode::LIST) {                    // if node不是LIST(表)类型
        return false;                                               // 返回false
    }

    // ---------- 2 '('入队 ----------
    char_queue.push('(');

    // ---------- 3 递归处理表内结点 ----------
    SimpleGenListNode* cur = node->head;                            // 指向当前(子)广义表表头结点

    while (cur) {                                                   // while cur != null
        if (cur->type == SimpleGenListNode::LIST) {                 // if cur结点为LIST类型
            bool res = ToCharQueueRecursive_(char_queue, cur);      // 对cur进行递归(使用当前char_queue)
            if (!res) {
                return false;
            }
        } else if (cur->type == SimpleGenListNode::ATOM) {          // if type为ATOM类型
            char_queue.push(cur->data);                             // cur->data入队
        }

        if (cur->next != NULL) {                                    // if cur->next存在
            char_queue.push(',');                                   // ','入队
        }

        cur = cur->next;                                            // cur指向cur->next
    }

    // ---------- 4 ')'入队 ----------

    char_queue.push(')');                                           // ')'入队

    // ---------- 5 退出函数 ----------

    return true;                                                    // 返回true
}


string SimpleGenList::ToString() {
    string str("");

    queue<char> char_queue;

    bool res = ToCharQueueRecursive_(char_queue, head_);
    if (!res) {
        throw exception("error in ToCharQueueRecursive_");
    }

    while (!char_queue.empty()) {
        char chr = char_queue.front();
        str.push_back(chr);

        char_queue.pop();
    }

    return str;
}


/*!
 * @brief **求子表深度(递归)**
 * @param node 子表结点
 * @return 深度
 * @note
 * 求子表深度(递归)
 * --------------
 * --------------
 *
 * --------------
 */
int SimpleGenList::SubGenListDepthRecursive_(SimpleGenListNode* node) {

    SimpleGenListNode* cur_node = node->head;

    if (cur_node == NULL) {
        return 1;
    }

    int max_sub_list_depth = 1; // 1为深度的最小可能值

    while (cur_node != NULL) {

        if (cur_node->type == SimpleGenListNode::LIST) {

            int sub_list_depth = SubGenListDepthRecursive_(cur_node);
            if (max_sub_list_depth < sub_list_depth) {
                max_sub_list_depth = sub_list_depth;
            }
        }

        cur_node = cur_node->next;
    }

    return max_sub_list_depth + 1;
}


int SimpleGenList::Depth() {
    int depth = SubGenListDepthRecursive_(this->head_);

    return depth;
}


int SimpleGenList::SubGenListLengthRecursive_(SimpleGenListNode* node) {

    if (node == NULL) {
        return 0;
    }

    int sub_list_length = SubGenListLengthRecursive_(node->next) + 1;

    return sub_list_length;
}


int SimpleGenList::Length() {
    int list_length = SubGenListLengthRecursive_(this->head_->head);

    return list_length;
}

