
template <typename TElement>
void GappedInsertionSort(TElement* elements, int gap, int length) {
    for (int i = gap; i < length; i++) {

        if (elements[i] >= elements[i - gap]) {
            continue;
        }

        // elements[0] = elements[i];
        TElement cur = elements[i];
        int j;
        for (j = i - gap; j >= 0 && cur < elements[j]; j -= gap) {
            elements[j + gap] = elements[j];
        }

        // elements[j + gap] = elements[0];
        elements[j + gap] = cur;
    }
}


template <typename TElement>
void ShellSort(TElement* elements, int* gaps, int length, int gaps_count) {
    for (int i = 0; i < gaps_count; i++) {
        GappedInsertionSort(elements, gaps[i], length);
    }
}