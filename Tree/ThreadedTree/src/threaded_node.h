//
// Created by svenlee on 2023/3/14.
//

#ifndef MAIN_THREADED_NODE_H
#define MAIN_THREADED_NODE_H


#include <cstddef>


const int CHILD_POINTER = 0;
const int THREADED_NODE_POINTER = 1;


/*!
 * @brief 线索树结点模板结构体
 * @tparam TData 类型模板参数
 */
template <typename TData>
struct ThreadedNode {

    int left_tag;
    int right_tag;

    ThreadedNode<TData>* left_child; //!< 左孩子
    ThreadedNode<TData>* right_child; //!< 右孩子
    TData data; //!< 数据项

    explicit ThreadedNode(const TData& data):
        data(data),
        left_child(NULL), right_child(NULL),
        left_tag(CHILD_POINTER), right_tag(CHILD_POINTER) {}
};


#endif //MAIN_THREADED_NODE_H
