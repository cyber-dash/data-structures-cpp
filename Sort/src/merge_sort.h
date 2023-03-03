/*!
 * @file merge_sort.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 归并排序
 * @version 0.2.1
 * @date 2021-09-19
 */


/*!
 * @brief 合并
 * @param elements 数组
 * @param caches 缓存数组
 * @param left 左子数组左侧
 * @param mid 左子数组右侧
 * @param right 右子数组右侧
 * @note
 * 合并
 * ---
 * ---
 *
 * elements内的两个有序数组(左子数组和右子数组,以left/mid/right划分), 合并成为一个有序数组
 *
 * ---
 * + **1 缓存数组构造数据**\n
 * **for** 遍历索引left至right :\n
 * &emsp; caches[i] <-- elements[i]\n
 * + **2 3个遍历索引初始化**\n
 * cur_left_cache_index(左缓存子数组遍历索引)初始化为left\n
 * cur_right_cache_index(右缓存子数组遍历索引)初始化为mid + 1\n
 * cur_elements_index(数组遍历索引)初始化为mid + 1\n
 * + **3 合并**\n
 * **while loop** 左缓存子数组未遍历完 && 左缓存子数组未遍历完 :\n
 * &emsp; **if** 当前左缓存子数组遍历元素 <= 当前右缓存子数组遍历元素 :\n
 * &emsp;&emsp; 当前数组遍历元素 <-- 当前左缓存子数组遍历元素\n
 * &emsp;&emsp; cur_left_cache_index加1\n
 * &emsp; **else** (当前左缓存子数组遍历元素 > 当前右缓存子数组遍历元素) :\n
 * &emsp;&emsp; 当前数组遍历元素 <-- 当前右缓存子数组遍历元素\n
 * &emsp;&emsp; cur_right_cache_index加1\n
 * &emsp; 数组遍历索引+1\n
 * + **4 合并后剩余数据补充**\n
 * **while loop** 左缓存子数组未遍历完 :\n
 * &emsp; 当前数组遍历元素 <-- 当前左缓存子数组遍历元素\n
 * &emsp; cur_left_cache_index加1\n
 * &emsp; 数组遍历索引+1\n
 * **while loop** 右缓存子数组未遍历完 :\n
 * &emsp; 当前数组遍历元素 <-- 当前右缓存子数组遍历元素\n
 * &emsp; cur_right_cache_index加1\n
 * &emsp; 数组遍历索引+1\n
 */
template<typename TElement>
void Merge(TElement* elements, TElement* caches, int left, int mid, int right) {

    // ---------- 1 缓存数组构造数据 ---------

    for (int i = left; i <= right; i++) {                                       // for 遍历索引left至right
        caches[i] = elements[i];                                                // caches[i] <-- elements[i]
    }

    // ---------- 2 3个遍历索引初始化 ----------

    int cur_left_cache_index = left;                                            // cur_left_cache_index(左缓存子数组遍历索引)初始化为left
    int cur_right_cache_index = mid + 1;                                        // cur_right_cache_index(右缓存子数组遍历索引)初始化为mid + 1

    int cur_elements_index = left;                                              // cur_elements_index(数组遍历索引)初始化为mid + 1

    // ---------- 3 合并 ----------

    while (cur_left_cache_index <= mid && cur_right_cache_index <= right) {     // while loop 左缓存子数组未遍历完 && 左缓存子数组未遍历完

        if (caches[cur_left_cache_index] <= caches[cur_right_cache_index]) {    // if 当前左缓存子数组遍历元素 <= 当前右缓存子数组遍历元素
            elements[cur_elements_index] = caches[cur_left_cache_index];        // 当前数组遍历元素 <-- 当前左缓存子数组遍历元素
            cur_left_cache_index++;                                             // cur_left_cache_index加1
        } else {                                                                // else (当前左缓存子数组遍历元素 > 当前右缓存子数组遍历元素)
            elements[cur_elements_index] = caches[cur_right_cache_index];       // 当前数组遍历元素 <-- 当前右缓存子数组遍历元素
            cur_right_cache_index++;                                            // cur_right_cache_index加1
        }

        cur_elements_index++;                                                   // 数组遍历索引+1
    }

    // ---------- 4 合并后剩余数据补充 ----------

    while (cur_left_cache_index <= mid) {                                       // while loop 左缓存子数组未遍历完
        elements[cur_elements_index] = caches[cur_left_cache_index];            // 当前数组遍历元素 <-- 当前左缓存子数组遍历元素
        cur_left_cache_index++;                                                 // cur_left_cache_index加1
        cur_elements_index++;                                                   // 数组遍历索引+1
    }

    while (cur_right_cache_index <= right) {                                    // while loop 右缓存子数组未遍历完
        elements[cur_elements_index] = caches[cur_right_cache_index];           // 当前数组遍历元素 <-- 当前右缓存子数组遍历元素
        cur_right_cache_index++;                                                // cur_right_cache_index加1
        cur_elements_index++;                                                   // 数组遍历索引+1
    }
}


/**
 * @brief **子数组归并排序(递归)**
 * @param elements 数组
 * @param caches 缓存数组
 * @param left 左边界
 * @param right 右边界
 * @note
 * 子数组归并排序(递归)
 * -----------------
 * -----------------
 *
 * 使用待排序数组的左右边界, 和缓存数组.
 * 使用二分分治法, 分别对左右两个子数组(sub elements)执行递归, 将递归后的两个已排序数组执行merge
 *
 * -----------------
 * + **1 退出递归处理**\n
 * **if** 左边界 >= 右边界 :\n
 * &emsp; 退出函数\n
 * + **2 分治递归**\n
 * 使用mid划分左右子数组\n
 * 对左侧子数组执行归并排序递归\n
 * 对右侧子数组执行归并排序递归\n
 * + **3 合并**\n
 * 调用Merge进行合并\n
 */
template<typename TElement>
void MergeSortInSubArrayRecursive(TElement* elements, TElement* caches, int left, int right) {

    // ---------- 1 退出递归处理 ----------

    if (left >= right) {                                            // if 左边界 >= 右边界
        return;                                                     // 退出函数
    }

    // ---------- 2 分治递归 ----------

    int mid = (left + right) / 2;                                   // 使用mid划分左右子数组

    MergeSortInSubArrayRecursive(elements, caches, left, mid);      // 对左侧子数组执行归并排序递归
    MergeSortInSubArrayRecursive(elements, caches, mid + 1, right); // 对右侧子数组执行归并排序递归

    // ---------- 3 合并 ----------

    Merge(elements, caches, left, mid, right);                      // 调用Merge进行合并
}


/**
 * @brief **归并排序(递归)**
 * @param elements 数组
 * @param size 数组长度
 * @note
 * 归并排序(递归)
 * ------------
 * ------------
 *
 * 调用sub_array_merge_sort_recursive实现归并排序
 *
 * ------------
 * + **1 构造缓存数组**\n
 * caches分配内存并初始化\n
 * **if** caches内存分配失败 :\n
 * &emsp; 抛出bad_alloc()\n
 * + **2 初始化左右边界**\n
 * left(左边界)初始化为0\n
 * right(右边界)初始化为size - 1\n
 * + **3 调用递归函数执行归并**\n
 */
template<typename TElement>
void MergeSortRecursive(TElement* elements, int size) {

    // ---------- 1 构造缓存数组 ----------

    TElement* caches = new TElement[size];  // caches分配内存并初始化
    if (!caches) {                          // if caches内存分配失败
        throw bad_alloc();                  // 抛出bad_alloc()
    }

    // ---------- 2 初始化左右边界 ----------

    int left = 0;                           // left(左边界)初始化为0
    int right = size - 1;                   // right(右边界)初始化为size - 1

    // ---------- 3 调用递归函数执行归并 ----------

    MergeSortInSubArrayRecursive(elements, caches, left, right);
}


int GetNextTurnSubArrayCount(int sub_array_count) {

    int rem = sub_array_count % 2;
    int next_turn_sub_array_count;

    if (rem == 0) {
        next_turn_sub_array_count = sub_array_count / 2;
    } else {
        next_turn_sub_array_count = sub_array_count / 2 + 1;
    }

    return next_turn_sub_array_count;
}


/*!
 * @brief **归并排序**
 * @param elements 数组
 * @param size 数组长度
 * @note
 * 归并排序
 * -------
 * -------
 *
 * -------
 * + **1 声明缓存数组**\n
 * caches初始化并分配内存\n
 * **if** 内存分配失败 :\n
 * &emsp; 抛出bad_alloc()\n
 * + **2 初始化当前子数组长度和数量**\n
 * 初始化当前子数组长度为1(每个元素自身为1个长度为1的子数组)\n
 * 初始化当前子数组数量为数组长度\n
 * + **3 迭代归并**\n
 * **while loop** 当前子数组数量 > 1(还能继续合并) :\n
 * &emsp; 计算cur_merge_times(本轮合并次数)\n
 * &emsp; **for loop** 循环cur_merge_times次执行合并 :\n
 * &emsp;&emsp; 计算cur_left(本次合并的左边界)\n
 * &emsp;&emsp; 计算cur_mid(本次合并的中间分界)\n
 * &emsp;&emsp; (计算right_mid)(本次合并的中间分界)\n
 * &emsp;&emsp; **if** (2 * i + 2) * cur_sub_array_length - 1 > size - 1 :\n
 * &emsp;&emsp;&emsp; cur_right(本次合并的中间分界) <-- size - 1\n
 * &emsp;&emsp; **else** :\n
 * &emsp;&emsp;&emsp; cur_right(本次合并的右边界) <-- (2 * i + 2) * cur_sub_array_length - 1\n
 * &emsp;&emsp; 执行本次合并\n
 * &emsp; 计算更新cur_sub_array_count(下一轮子数组数量)\n
 * &emsp; 计算更新cur_sub_array_length(下一轮子数组长度)\n
 */
template<typename TElement>
void MergeSort(TElement* elements, int size) {

    // ---------- 1 声明缓存数组 ----------

    TElement* caches = new int[size];                                           // caches初始化并分配内存
    if (caches == NULL) {                                                       // if 内存分配失败
        throw bad_alloc();                                                      // 抛出bad_alloc()
    }

    // ---------- 2 初始化当前子数组长度和数量 ----------

    int cur_sub_array_length = 1;                                               // 初始化当前子数组长度为1(每个元素自身为1个长度为1的子数组)
    int cur_sub_array_count = size;                                             // 初始化当前子数组数量为数组长度

    // ---------- 3 迭代归并 ----------

    while (cur_sub_array_count > 1) {                                           // while loop 当前子数组数量 > 1(还能继续合并)
        int cur_merge_times = cur_sub_array_count / 2;                          // 计算cur_merge_times(本轮合并次数)

        for (int i = 0; i < cur_merge_times; i++) {                             // for loop 循环cur_merge_times次执行合并
            int cur_left = 2 * i * cur_sub_array_length;                        // 计算cur_left(本次合并的左边界)
            int cur_mid = (2 * i + 1) * cur_sub_array_length - 1;               // 计算cur_mid(本次合并的中间分界)

            // (计算right_mid)
            int cur_right;
            if ((2 * i + 2) * cur_sub_array_length - 1 > size - 1) {            // if (2 * i + 2) * cur_sub_array_length - 1 > size - 1
                cur_right = size - 1;                                           // cur_right(本次合并的中间分界) <-- size - 1
            } else {                                                            // else
                cur_right = (2 * i + 2) * cur_sub_array_length - 1;             // cur_right(本次合并的右边界) <-- (2 * i + 2) * cur_sub_array_length - 1
            }

            Merge(elements, caches, cur_left, cur_mid, cur_right);              // 执行本次合并
        }

        cur_sub_array_count = GetNextTurnSubArrayCount(cur_sub_array_count);    // 计算更新cur_sub_array_count(下一轮子数组数量)

        cur_sub_array_length = cur_sub_array_length * 2;                        // 计算更新cur_sub_array_length(下一轮子数组长度)
    }
}
