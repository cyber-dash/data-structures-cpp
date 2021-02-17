#include <iostream>


using namespace std;


void showArray(int* ptr, int arr_size) {

  for (int i = 0; i < arr_size; i++) {
    cout<<ptr[i]<<" ";
  }

  cout<<endl;
}


int main() {

  int array_size = 5;
  // int* arr_ptr = new int[array_size];
  int int_array[array_size];

  for (int i = 0; i < array_size; i++) {
    int_array[i] = i;
  }

  showArray(int_array, array_size);

  return 0;
}