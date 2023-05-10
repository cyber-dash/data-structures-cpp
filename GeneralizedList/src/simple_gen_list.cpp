/*!
 * @file simple_gen_list.cpp
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief (简单)广义表类源文件
 * @version 0.2.1
 * @date 2021-05-19
 */

#include "simple_gen_list.h"


/*!
 * @brief **使用队列创建广义表(递归)**
 * @param char_queue 字符队列
 * @param node 结点
 * @note
 * 使用队列创建广义表(递归)
 * --------------------
 * --------------------
 *
 * --------------------
 * + **1 空表处理**\n
 * **if** 空队列 :\n
 * &emsp; 退出函数\n\n
 * + **2 递归建表**\n
 * 取队头字符, 赋给chr\n
 * 队头出队\n\n
 * **if** chr为'(':\n
 * &emsp; 分配内存并初始化LIST类型的结点, 使node指向该结点 <span style="color:#FF9900">(生成新的子表)</span>\n
 * &emsp; 对node->head调用CreateByQueueRecursive_执行递归 <span style="color:#FF9900">(构造子表的表头)</span>\n
 * &emsp; 对node进行递归 <span style="color:#FF9900">(此时应已经处理完子表)</span>\n\n
 * **else if** chr是字符 :\n
 * &emsp; 分配内存并初始化ATOM类型的结点, 使node指向该结点 <span style="color:#E76600">(生成新的原子结点)</span>\n
 * &emsp; 对node进行递归 <span style="color:#E76600">(此时应已经处理完原子结点)</span>\n\n
 * **else if** chr是',' :\n
 * &emsp; 对node->next进行递归 <span style="color:#FB1927">(处理下一个)</span>\n\n
 * **else if** chr是')' :\n
 * &emsp; **if** node不为NULL <span style="color:#FD5E0F">(如果node为NULL, 则表示当前子表为空表, 字符串为"()", 不做处理)</span>:\n
 * &emsp;&emsp; node->next置为nullptr\n\n
 */
void SimpleGenList::CreateByQueueRecursive_(queue<char>& char_queue, SimpleGenListNode*& node) {

    // ---------- 1 空表处理 ----------

    if (char_queue.empty()) {                                               // if 空队列
        return;                                                             // 退出函数
    }

    // ---------- 2 递归建表 ----------

    char chr = char_queue.front();                                          // 取队头字符, 赋给chr
    char_queue.pop();                                                       // 队头出队

    if (chr == '(') {                                                       // if chr为'('
        node = new SimpleGenListNode(SimpleGenListNode::LIST);              // 分配内存并初始化LIST类型的结点, 使node指向该结点(生成新的子表)
        this->CreateByQueueRecursive_(char_queue, node->head);              // 对node->head调用CreateByQueueRecursive_执行递归(构造子表的表头)
        CreateByQueueRecursive_(char_queue, node);                          // 对node进行递归(此时应已经处理完子表)
    } else if (isalpha(chr)) {                                              // else if chr是字符
        node = new SimpleGenListNode(SimpleGenListNode::ATOM, chr);         // 分配内存并初始化ATOM类型的结点, 使node指向该结点(生成新的原子结点)
        CreateByQueueRecursive_(char_queue, node);                          // 对node进行递归(此时应已经处理完原子结点)
    } else if (chr == ',') {                                                // else if chr是','
        CreateByQueueRecursive_(char_queue, node->next);                    // 对node->next进行递归(处理下一个)
    } else if (chr == ')') {                                                // else if chr是')'
        if (node) {                                                         // if node不为NULL(如果node为NULL, 则表示当前子表为空表, 字符串为"()", 不做处理)
            node->next = nullptr;                                           // node->next置为nullptr
        }
    }
}


/*!
 * @brief **使用字符串创建广义表**
 * @param gen_list_string 广义表字符串
 * @note
 * 使用字符串创建广义表
 * -----------------
 * -----------------
 *
 * -----------------
 * + **1 构造字符队列**\n
 * 声明char_queue(字符队列)\n\n
 * **for loop** 遍历gen_list_string(广义表字符串) :\n
 * &emsp; 当前字符入队\n\n
 * + **2 建表**\n
 * 对list_node_调用CreateByQueueRecursive_\n
 */
void SimpleGenList::CreateByString(const string& gen_list_string) {

    // ---------- 1 构造字符队列 ----------

    queue<char> char_queue;                                                         // 声明char_queue(字符队列)

    for (int i = 0; i < gen_list_string.length(); i++) {                            // for loop 遍历gen_list_string(广义表字符串)
        char chr = gen_list_string[i];
        char_queue.push(chr);                                                       // 当前字符入队
    }

    // ---------- 2 建表 ----------

    CreateByQueueRecursive_(char_queue, list_node_);                                // 对list_node_调用CreateByQueueRecursive_
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

    if (node->type != SimpleGenListNode::LIST) {                            // if node不是LIST(表)类型
        return false;                                                       // 返回false
    }

    // ---------- 2 '('入队 ----------
    char_queue.push('(');

    // ---------- 3 递归处理表内结点 ----------
    SimpleGenListNode* cur = node->head;                                    // 指向当前(子)广义表表头结点

    while (cur) {                                                           // while cur != null
        if (cur->type == SimpleGenListNode::LIST) {                         // if cur结点为LIST类型
            bool res = ToCharQueueRecursive_(char_queue, cur);              // 对cur进行递归(使用当前char_queue)
            if (!res) {
                return false;
            }
        } else if (cur->type == SimpleGenListNode::ATOM) {                  // if type为ATOM类型
            char_queue.push(cur->data);                                     // cur->data入队
        }

        if (cur->next != NULL) {                                            // if cur->next存在
            char_queue.push(',');                                           // ','入队
        }

        cur = cur->next;                                                    // cur指向cur->next
    }

    // ---------- 4 ')'入队 ----------

    char_queue.push(')');                                                   // ')'入队

    // ---------- 5 退出函数 ----------

    return true;                                                            // 返回true
}


/*!
 * @brief **生成字符串**
 * @return 字符串
 * @note
 * 生成字符串
 * --------
 * --------
 *
 * --------
 *
 */
string SimpleGenList::ToString() {
    string str;

    queue<char> char_queue;

    bool res = ToCharQueueRecursive_(char_queue, list_node_);
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
 * -------------
 * -------------
 *
 * -------------
 * + **1 空表处理**\n
 * 初始化cur(遍历结点)指向表头\n\n
 * **if** cur为NULL(空表) :\n
 * &emsp; 返回1\n\n
 * + **2 递归求最深子表深度**\n
 * 初始化max_sub_list_depth(最深子表深度)为1\n\n
 * **while** cur不为NULL :\n
 * &emsp; **if** cur指向LIST类型结点 :\n
 * &emsp;&emsp; 递归求cur_sub_list_depth(当前子表的深度)\n
 * &emsp;&emsp; **if** max_sub_list_depth < cur_sub_list_depth :\n
 * &emsp;&emsp;&emsp; 更新max_sub_list_depth\n\n
 * &emsp; cur指向cur->next\n\n
 * + **3 返回深度**\n
 * 返回更新max_sub_list_depth + 1\n
 */
int SimpleGenList::SubGenListDepthRecursive_(SimpleGenListNode* node) {

    // ---------- 1 空表处理 ----------

    SimpleGenListNode* cur = node->head;                                            // 初始化cur(遍历结点)指向表头
    if (cur == NULL) {                                                              // if cur为NULL(空表)
        return 1;                                                                   // 返回1
    }

    // ---------- 2 递归求最深子表深度 ----------

    int max_sub_list_depth = 1;                                                     // 初始化max_sub_list_depth(最深子表深度)为1

    while (cur != NULL) {                                                           // while cur不为NULL

        if (cur->type == SimpleGenListNode::LIST) {                                 // if cur指向LIST类型结点

            int cur_sub_list_depth = SubGenListDepthRecursive_(cur);                // 递归求cur_sub_list_depth(当前子表的深度)
            if (max_sub_list_depth < cur_sub_list_depth) {                          // if max_sub_list_depth < cur_sub_list_depth
                max_sub_list_depth = cur_sub_list_depth;                            // 更新max_sub_list_depth
            }
        }

        cur = cur->next;                                                            // cur指向cur->next
    }

    // ---------- 3 返回深度 ----------

    return max_sub_list_depth + 1;                                                  // 返回更新max_sub_list_depth + 1
}


/*!
 * @brief **求深度**
 * @return 深度
 * @note
 * 求深度
 * -----
 * -----
 *
 * -----
 * 对list_node_调用SubGenListDepthRecursive_
 */
int SimpleGenList::Depth() {
    int depth = SubGenListDepthRecursive_(this->list_node_);

    return depth;
}


/*!
 * @brief **求子表长度(递归)**
 * @param node 结点
 * @return 长度
 * @note
 * 求子表长度(递归)
 * -------------
 * -------------
 *
 * -------------
 * + **1 空结点处理**\n
 * **if** node为NULL\n
 * &emsp; 返回0\n\n
 * + **2 递归求长度**\n
 * 递归调用SubGenListLengthRecursive_求长度\n\n
 * + **3 返回结果**\n
 * 返回长度\n
 */
int SimpleGenList::SubGenListLengthRecursive_(SimpleGenListNode* node) {

    // ---------- 1 空结点处理 ----------

    if (node == NULL) {                                                             // if node为NULL
        return 0;                                                                   // 返回0
    }

    // ---------- 2 递归求长度 ----------

    int sub_list_length = SubGenListLengthRecursive_(node->next) + 1;               // 递归调用SubGenListLengthRecursive_求长度

    // ---------- 3 返回结果 ----------

    return sub_list_length;                                                         // 返回长度
}


/*!
 * @brief **求长度**
 * @return 长度
 * @note
 * 求长度
 * -----
 * -----
 *
 * -----
 * 对list_head_->head调用SubGenListLengthRecursive_
 */
int SimpleGenList::Length() {
    int list_length = SubGenListLengthRecursive_(this->list_node_->head);

    return list_length;
}

