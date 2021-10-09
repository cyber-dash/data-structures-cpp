//
// Created by cyberdash@163.com(抖音: cyberdash_yuan) on 2020/6/2.
//


/**
 * @brief 合并函数
 * array内的两个有序数组(左子数组和右子数组,以left/mid/right划分), 合并成为一个有序数组
 * @param array 待合并数组(包含两个子数组)
 * @param cache_array 缓存数组
 * @param left 左子数组左侧
 * @param mid 左子数组右侧
 * @param right 右子数组右侧
 */
void merge(int* array, int* cache_array, int left, int mid, int right) {

  for (int i = left; i <= right; i++) {
    cache_array[i] = array[i];
  }

  int left_cache_index = left;
  int right_cache_index = mid + 1;

  int array_index = left;

  while (left_cache_index <= mid && right_cache_index <= right) {

    if (cache_array[left_cache_index] <= cache_array[right_cache_index]) {
      array[array_index] = cache_array[left_cache_index];
      left_cache_index++;
    } else {
      array[array_index] = cache_array[right_cache_index];
      right_cache_index++;
    }

    array_index++;
  }

  while (left_cache_index <= mid) {
    array[array_index] = cache_array[left_cache_index];
    left_cache_index++;
    array_index++;
  }

  while (right_cache_index <= right) {
    array[array_index] = cache_array[right_cache_index];
    right_cache_index++;
    array_index++;
  }
}


/**
 * @brief 子数组归并排序(递归/二分)
 * 使用待排序数组的左右边界, 和缓存数组.
 * 使用二分分治法, 分别对左右两个子数组(sub array)执行递归, 将递归后的两个已排序数组执行merge
 * @param array 待排序数组
 * @param cache_array 缓存数组(用于辅助归并操作)
 * @param left 待排序数组左边界
 * @param right 待排序数组右边界
 */
void sub_array_merge_sort_recursive(int* array, int* cache_array, int left, int right) {

  if (left >= right) {
    return;
  }

  int mid = (left + right) / 2; // 使用mid划分左右子数组

  sub_array_merge_sort_recursive(array, cache_array, left, mid); // 左侧子数组递归
  sub_array_merge_sort_recursive(array, cache_array, mid + 1, right); // 右侧子数组递归

  merge(array, cache_array, left, mid, right);
}


/**
 * @brief 归并排序(使用递归/二分)
 * 调用sub_array_merge_sort_recursive实现归并排序
 * @param array 待排序数组
 * @param arr_size 待排序数组长度
 */
void MergeSort(int *array, int array_size) {

  int* cache_array = new int[arr_size];

  int left = 0;
  int right = arr_size - 1;

  sub_array_merge_sort_recursive(array, cache_array, left, right);
}


int get_next_turn_array_count(int array_count) {

  int rem = array_count % 2;
  int next_turn_array_count;

  if (rem == 0) {
    next_turn_array_count = array_count / 2;
  } else {
    next_turn_array_count = array_count / 2 + 1;
  }

  return next_turn_array_count;
}


/**
 * @brief 归并排序(非递归/二分)
 * @param array 待排序数组
 * @param array_size 待排序数组长度
 */
void MergeSortNonrecursive(int* array, int array_size) {

  int* cache_array = new int[array_size];

  int merge_array_length = 1;
  int sub_array_count = array_size;

  do {
    int merge_count = sub_array_count / 2;

    for (int i = 0; i < merge_count; i++) {
      int left = 2 * i * merge_array_length;
      int mid = (2 * i + 1) * merge_array_length - 1;
      int right;

      if ((2 * i + 2) * merge_array_length - 1 > array_size - 1) {
        right = array_size - 1;
      } else {
        right = (2 * i + 2) * merge_array_length - 1;
      }

      merge(array, cache_array, left, mid, right);
    }

    sub_array_count = get_next_turn_array_count(sub_array_count);

    merge_array_length = merge_array_length * 2;

  } while (sub_array_count != 1);
}