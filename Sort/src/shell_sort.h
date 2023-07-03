/*!
 * @file shell_sort.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 希尔排序
 * @version 0.2.1
 * @date 2021-09-19
 */


/*!
 * @brief **间隔区间插入排序**
 * @tparam TElement 数组元素类型模板参数
 * @param elements 数组
 * @param gap 间隔
 * @param length 数组长度
 * @note
 * 间隔区间插入排序
 * -------------
 * -------------
 *
 * -------------
 */
template <typename TElement>
void GapedInsertionSort(TElement* elements, int gap, int length) {
    for (int i = gap; i < length; i++) {

        if (elements[i] >= elements[i - gap]) {
            continue;
        }

        TElement cur = elements[i];
        int j;
        for (j = i - gap; j >= 0 && cur < elements[j]; j -= gap) {
            elements[j + gap] = elements[j];
        }

        elements[j + gap] = cur;
    }
}


/*!
 * @brief **希尔排序**
 * @tparam TElement
 * @param elements 数组
 * @param gaps 间隔数组
 * @param length 数组长度
 * @param gaps_count 间隔数组长度
 * @note
 * 希尔排序
 * -------
 * -------
 *
 * -------
 */
template <typename TElement>
void ShellSort(TElement* elements, int* gaps, int length, int gaps_count) {
    for (int i = 0; i < gaps_count; i++) {
        GapedInsertionSort(elements, gaps[i], length);
    }
}
