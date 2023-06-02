#include "test.h"
#include "search.h"
#include <iostream>


using namespace std;


void TestSearch() {

    int arr[6] = { 1, 4, 2, 8, 5, 7 };

    int res = LinearSearch<int>(arr, 6, 5);
    cout << "res: " << res << endl;
    res = LinearSearch<int>(arr, 6, 3);
    cout << "res: " << res << endl;

    int arr2[6] = { 1, 2, 4, 5, 7, 8 };
    res = BinarySearch<int>(arr2, 6, 8);
    cout << "res: " << res << endl;
    res = BinarySearch<int>(arr2, 6, 1);
    cout << "res: " << res << endl;
    res = BinarySearch<int>(arr2, 6, 3);
    cout << "res: " << res << endl;
}
