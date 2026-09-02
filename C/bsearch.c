#include <stdio.h>
int main() {
  printf("Hello ");

  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 100};

  int arr_size = sizeof(arr) / sizeof(arr[0]);
  int ref = arr[9];

  for (int i = 0; i < arr_size; i++) {
    printf("%i", arr[i]);
  }
  // return 0;

  // now i want to search if 100 is present in the array
  int *start, *end, *mid;
  //   printf("\n%i, %i, %i", *start, *end, *mid);
  start = arr;

  while (1) {
    end = start + arr_size - 1;
    mid = start + ((end - start)) / 2;
    for (int a = 0; a < *mid; a++) {
      printf("\n TRYING");
      if (ref == arr[a]) {
        printf("\nFOUND");
        return 0;
      }
    }
    start = mid;
    arr_size = end - mid;
    printf("\nNOT FOUND YET");
  }
}