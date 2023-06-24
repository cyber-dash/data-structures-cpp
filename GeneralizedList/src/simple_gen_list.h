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


/*!
 * @brief **简单广义表结点类**
 */
class SimpleGenListNode {
public:

    /*!
     * @brief **默认构造函数**
     * @note
     * 默认构造函数
     * ----------
     * ----------
     *
     * ----------
     * type为ATOM(原子类型)\n
     * data为'\0'\n
     * next和head均设置为nullptr\n
     */
    SimpleGenListNode(): type(ATOM), data('\0'), next(nullptr), head(nullptr) {}


    /*!
     * @brief **构造函数(类型,data)**
     * @note
     * 构造函数(类型,data)
     * -----------------
     * -----------------
     *
     * -----------------
     * type和data使用参数赋值\n
     * next和head均设置为nullptr\n
     */
    explicit SimpleGenListNode(int type, char data = '\0'): type(type), next(nullptr), head(nullptr), data(data) {}


    /*!
     * @brief **复制构造函数**
     * @param node 源广义表结点
     * @note
     * 复制构造函数
     * ----------
     * ----------
     *
     * ----------
     */
    SimpleGenListNode(const SimpleGenListNode& node) {
        type = node.type;
        data = node.data;
        head = node.head;
        next = node.next;
    }

    int type;                                             //!< **类型**
    char data;                                            //!< **数据项**
    SimpleGenListNode* head;                              //!< **表头结点(如果type是LIST_HEAD类型)**
    SimpleGenListNode* next;                              //!< **下一结点**

    static const int ATOM = 1;                            //!< **原子结点类型**
    static const int LIST = 2;                            //!< **表结点类型**
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

    /*!
     * @brief **默认构造函数**
     * @note
     * 默认构造函数
     * ----------
     * ----------
     *
     * ----------
     * 表头结点置为nullptr
     */
    SimpleGenList(): list_node_(nullptr) {};

    // 使用字符串创建广义表
    void CreateByString(const string& gen_list_string);

    // 生成字符串
    string ToString();

    // 获取深度
    int Depth();
    // 获取长度
    int Length();


private:
    // 使用队列创建广义表(递归)
    void CreateByQueueRecursive_(queue<char>& char_queue, SimpleGenListNode*& node);
    // 子表构造字符队列(递归)
    bool ToCharQueueRecursive_(queue<char>& char_queue, SimpleGenListNode* node);

    // 求子表深度(递归)
    int SubGenListDepthRecursive_(SimpleGenListNode* node);
    // 求子表长度(递归)
    int SubGenListLengthRecursive_(SimpleGenListNode* node);

    SimpleGenListNode* list_node_;       //!< **表结点**
};


#endif // CYBER_DASH_SIMPLE_GEN_LIST_H
