/*!
 * @file seq_list_algorithm.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 顺序表算法测试类
 * @version 0.2.1
 * @date 2021-09-28
 * @copyright Copyright (c) 2021
 * **CyberDash计算机考研**
 */

#ifndef CYBER_DASH_SEQ_LIST_ALGORITHM_H
#define CYBER_DASH_SEQ_LIST_ALGORITHM_H


#include "seq_list.h"


 /*!
  * @brief 顺序表求并集
  * @tparam TData 类型模板参数
  * @param seq_list_a 顺序表a(并运算后的表)
  * @param seq_list_b 顺序表b
  * @note
  * 遍历顺序表b, 对每个元素, 如果在表a中不存在, 则插入到表a中
  */
template<class TData>
void SeqListUnion(SeqList<TData>& seq_list_a, SeqList<TData>& seq_list_b) {
    int a_length = seq_list_a.Length();
    int b_length = seq_list_b.Length();

    for (int i = 1; i <= b_length; i++) {

        int list_b_item;
        seq_list_b.GetData(i, list_b_item);

        int pos = seq_list_a.Search(list_b_item);
        if (pos == 0) {
            seq_list_a.Insert(a_length, list_b_item);
            a_length++;
        }
    }
}


/*!
 * @brief 顺序表求交集
 * @tparam TData 类型模板参数
 * @param seq_list_a 顺序表a(交运算后的表)
 * @param seq_list_b 顺序表b
 */
template<class TData>
void SeqListIntersection(SeqList<TData>& seq_list_a, SeqList<TData>& seq_list_b) {

    int a_length = seq_list_a.Length();

    int iter_pos = 1;
    while (iter_pos <= a_length) {
        int list_a_item;
        seq_list_a.GetData(iter_pos, list_a_item);

        int pos = seq_list_b.Search(list_a_item);
        if (pos == 0) {
            seq_list_a.Remove(iter_pos, list_a_item);
            a_length--;
        }
        else {
            iter_pos++;
        }
    }
}


#endif // CYBER_DASH_SEQ_LIST_ALGORITHM_H
