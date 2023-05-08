/*!
 * @file simple_gen_list.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief (简单)广义表类头文件
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


class SimpleGenListNode {
public:

    /*! @brief 构造函数 */
    SimpleGenListNode(): type(ATOM), data('\0'), next(nullptr), head(nullptr) {}
    explicit SimpleGenListNode(int type, char data = '\0'):
        type(type), next(nullptr), head(nullptr), data(data) {}

    /*!
     * @brief 复制构造函数
     * @param node 广义表节点
     */
    SimpleGenListNode(const SimpleGenListNode& node) {
        type = node.type;
        data = node.data;
        head = node.head;
        next = node.next;
    }

    int type;                                       //!< 类型
    char data;                                      //!< 数据
    SimpleGenListNode* head;                              //!< 表头结点(如果type是LIST_HEAD类型)
    SimpleGenListNode* next;                               //!< 下一结点

    static const int ATOM = 1;                             //!< 原子结点类型
    static const int LIST = 2;                        //!< 表结点类型
};


/*!
 * @brief **简单广义表**
 * @note
 * 简单广义表
 * --------
 * --------
 *
 * 示例:\n
 * (a,b,(c,d,(e)),())\n
 *
 * 只有表和原子结点, 无表名和引用
 *
 * --------
 */
class SimpleGenList {
public:

    // 构造函数
    SimpleGenList(): head_(nullptr) {};

    // 使用字符串创建广义表
    void CreateByString(const string& gen_list_string);

    // 字符串格式化
    string ToString();

    int Depth();
    int Length();


private:
    // 使用char队列创建广义表(递归)
    void CreateByQueueRecursive_(queue<char>& char_queue, SimpleGenListNode*& node);

    bool ToCharQueueRecursive_(queue<char>& char_queue, SimpleGenListNode* node);

    int SubGenListDepthRecursive_(SimpleGenListNode* node);
    int SubGenListLengthRecursive_(SimpleGenListNode* node);

    SimpleGenListNode* head_;
};


#endif // CYBER_DASH_SIMPLE_GEN_LIST_H
