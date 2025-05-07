#include <iostream>
#include <string>
using namespace std;
// find the mode of a number using hash_maps
int TABLE_SIZE = 100;

typedef struct {
  int key;
  int value;
  int used;
} HashRecords;

typedef struct {
  HashRecords *entries;
} HashTables;

int __hash(int key) { return abs(key) % TABLE_SIZE; }

HashTables *create_table() {
  HashTables *table = (HashTables *)malloc(sizeof(HashTables));
  table->entries = (HashRecords *)calloc(TABLE_SIZE, sizeof(HashRecords));
  return table;
}

void insert_data(HashTables *table, int key) {
  int idx = __hash(key);
  if (table->entries[idx].used) {
    if (table->entries[idx].key == key) {
      table->entries[idx].value += 1;
      return;
    }
  }
  table->entries[idx].key = key;
  table->entries[idx].value = 1;
  table->entries[idx].used = 1;
}
int get_count(HashTables *table, int key) { return table->entries[key].value; }
void destroy_table(HashTables *T) {
  free(T->entries);
  free(T);
  T->entries = NULL;
}

int mode(int *arr, int size) {
  int max_count = 0;
  int i = 0; int key = 0;
  HashTables *table = create_table();
  while (i < size) {
    insert_data(table, arr[i]);
    int count = get_count(table, arr[i]);
    if (count > max_count) {
      max_count = count;
      key = arr[i];
    }
    i++;
  }
  destroy_table(table);
  return key;
}

int main() {
  int arr[13] = {4, 3, 6, 7, 8, 1, 3, 2, 0, 4, 4, 69, 2};
  std::cout << mode(arr, 13) << '\n';
}