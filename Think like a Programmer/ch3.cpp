#include <iostream>
#include <string>
using namespace std;

int isSorted(int *arr, int size);

int main(int args, char **argvs) {

  int arr[12] = {4, 3, 6, 7, 8, 1, 2, 3, 4, 5, 69, 2};
  if (isSorted(arr, sizeof(arr))) {
    cout << "True" << '\n';
  } else {
    cout << "False" << '\n';
  }

  return 0;
}

int isSorted(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    if (arr[i] > arr[i + 1]) {
      return 0;
    }
  }
  return 1;
}
