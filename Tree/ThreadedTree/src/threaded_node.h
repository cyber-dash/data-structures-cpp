/*!
 * @file threaded_node.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 线索树结点模板结构体
 * @version 0.2.1
 * @date 2021-05-13
 */

#ifndef MAIN_THREADED_NODE_H
#define MAIN_THREADED_NODE_H


#include <cstddef>


const int CHILD_POINTER = 0;                    //!< 子结点指针类型
const int THREADED_NODE_POINTER = 1;            //!< 线索结点指针类型


/*!
 * @brief 线索树结点模板结构体
 * @tparam TData 类型模板参数
 */
template <typename TData>
struct ThreadedNode {

    int left_tag;                                //!< right_child的结点类型
    int right_tag;                               //!< left_child的结点类型

    ThreadedNode<TData>* left_child;             //!< 左孩子
    ThreadedNode<TData>* right_child;            //!< 右孩子
    TData data;                                  //!< 数据项

    explicit ThreadedNode(const TData& data):
        data(data),
        left_child(NULL), right_child(NULL),
        left_tag(CHILD_POINTER), right_tag(CHILD_POINTER) {}
};


#endif //MAIN_THREADED_NODE_H
