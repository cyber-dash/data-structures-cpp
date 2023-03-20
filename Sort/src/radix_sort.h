//
// Created by fenix on 2023/3/18.
//

#ifndef CYBER_DASH_RADIX_SORT_H
#define CYBER_DASH_RADIX_SORT_H


#include <iostream>
using namespace std;


/*!
 * @brief 获取数组中最大的元素
 * @param elements
 * @param length
 * @return
 */
int Max(const int* elements, int length) {
    int max_element = elements[0];

    for (int i = 1; i < length; i++) {
        if (elements[i] > max_element) {
            max_element = elements[i];
        }
    }

    return max_element;
}


void BucketSort(int* elements, int length, int exponent) {
    int* cache = new int[length]; // cache array
    int buckets[10] = { 0 };

    for (int i = 0; i < length; i++) {
        int digit = (elements[i] / exponent) % 10;
        buckets[digit]++;
    }

    for (int i = 1; i < 10; i++) {
        buckets[i] += buckets[i - 1];
    }

    for (int i = length - 1; i >= 0; i--) {
        int digit = (elements[i] / exponent) % 10;
        cache[ buckets[digit] - 1 ] = elements[i];
        buckets[ digit ]--;
    }

    for (int i = 0; i < length; i++) {
        elements[i] = cache[i];
    }

    delete[] cache;
}


void RadixSortForArray(int* elements, int length) {
    int max_element = Max(elements, length);

    for (int exponent = 1; max_element / exponent > 0; exponent *= 10) {
        BucketSort(elements, length, exponent);
    }
}


#endif // CYBER_DASH_RADIX_SORT_H
