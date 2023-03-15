//
// Created by svenlee on 2023/3/14.
//

#ifndef MAIN_THREADED_NODE_H
#define MAIN_THREADED_NODE_H


#include <cstddef>


const int IS_CHILD = 0;
const int IS_THREAD_NODE = 1;


/*!
 * @brief 线索树结点模板结构体
 * @tparam T 类型模板参数
 */
template <class T>
struct ThreadedNode {

    int left_tag;
    int right_tag;

    ThreadedNode<T>* left_child; //!< 左孩子
    ThreadedNode<T>* right_child; //!< 右孩子
    T data; //!< 数据项

    explicit ThreadedNode(const T& data):
        data(data),
        left_child(NULL), right_child(NULL),
        left_tag(IS_CHILD), right_tag(IS_CHILD) {}
};


#endif //MAIN_THREADED_NODE_H
