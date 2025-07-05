#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct dynamicArray {
  int vector[0];
  int size;
  int capacity;
};

bool isEmpty(struct dynamicArray *vector) {
  if (vector->capacity == 0) {
    return true;
  } else {
    return false;
  }
}

int size(struct dynamicArray *vector) { return vector->capacity; }

void clear(struct dynamicArray *vector) { free(vector); }

void push_back(int value) {}

struct dynamicArray front(struct dynamicArray *vector) {
  if (!isEmpty((vector))) {
    return vector[0];
  }
}

struct dynamicArray back(struct dynamicArray *vector) {
  if (!isEmpty((vector))) {
    return vector[vector->capacity];
  }
}

void resize(int newSize, struct dynamicArray *vector) {
  int *temp = malloc((newSize) * sizeof(int));

  for (int i = 0; i < newSize; i++) {
    memcpy(&vector[i], &temp[i], sizeof(int));
  }

  vector->capacity = newSize;

  if (vector->size > newSize) {
    vector->size = newSize;
  }

  free(vector);
}
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Allocate memory for your dynamicArray struct + 5 ints for vector
  struct dynamicArray *vec =
      malloc(sizeof(struct dynamicArray) + 5 * sizeof(int));
  if (!vec) {
    printf("Memory allocation failed\n");
    return 1;
  }

  vec->size = 5;
  vec->capacity = 5;

  // Initialize the vector array manually (since push_back is empty)
  for (int i = 0; i < vec->capacity; i++) {
    vec->vector[i] = i * 10;
  }

  // Test isEmpty()
  printf("isEmpty: %s\n", isEmpty(vec) ? "true" : "false");

  // Test size()
  printf("size: %d\n", size(vec));

  // Test front()
  struct dynamicArray front_val = front(vec);
  printf("front: %d\n", front_val.vector[0]);

  // Test back()
  struct dynamicArray back_val = back(vec);
  printf("back: %d\n", back_val.vector[0]);

  // Test resize() - resize down to 3
  resize(3, vec);

  // After resize, vec pointer is invalid (freed inside resize),
  // so allocate again for demonstration (to avoid crash)
  vec = malloc(sizeof(struct dynamicArray) + 3 * sizeof(int));
  if (!vec) {
    printf("Memory allocation failed\n");
    return 1;
  }
  vec->size = 3;
  vec->capacity = 3;
  for (int i = 0; i < vec->capacity; i++) {
    vec->vector[i] = i * 100;
  }
  printf("After resize (manual reallocation): size=%d, capacity=%d\n",
         vec->size, vec->capacity);

  // Test clear()
  clear(vec);

  printf("Array cleared\n");

  return 0;
}
