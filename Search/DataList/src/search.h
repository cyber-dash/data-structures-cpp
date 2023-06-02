#ifndef CYBER_DASH_SEARCH_IN_DATA_LIST_H
#define CYBER_DASH_SEARCH_IN_DATA_LIST_H


template<typename Elem>
int LinearSearch(Elem* elements, int size, Elem element) {
    if (size == 0) {
        return -1;
    }

    int i = 0;
    while (i < size && elements[i] != element) {
        i++;
    }

    if (i == size) {
        return -1;
    }

    return i;
}


template<typename Elem>
int BinarySearch(Elem* elements, int size, Elem element) {

    int right = size - 1;
    int left = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (element > elements[mid]) {
            left = mid + 1;
        } else if (element < elements[mid]) {
            right = mid - 1;
        } else {
            return mid;
        }
    }

    return -1;
}


#endif //CYBER_DASH_SEARCH_IN_DATA_LIST_H