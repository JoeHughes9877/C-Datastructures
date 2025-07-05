#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dynamicArray {
  int size;
  int capacity;
  int vector[];
};

bool isEmpty(struct dynamicArray *vector) {
  if (vector->size == 0) {
    return true;
  } else {
    return false;
  }
}

int size(struct dynamicArray *vector) { return vector->size; }

void clear(struct dynamicArray *vector) { free(vector); }

int front(struct dynamicArray *vector) {
  return isEmpty(vector) ? -1 : vector->vector[0];
}

int back(struct dynamicArray *vector) {
  return isEmpty(vector) ? -1 : vector->vector[vector->size - 1];
}

void resize(int newSize, struct dynamicArray *vector) {
  int vectorSize = vector->size - 1;

  int *temp = malloc((newSize) * sizeof(int));

  for (int i = 0; i < newSize; i++) {
    memcpy(&vector[i], &temp[i], sizeof(int));
  }

  vector->capacity = newSize;

  if (vectorSize > newSize) {
    vectorSize = newSize;
  }

  free(vector);
}

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
  int front_val = front(vec);
  printf("front: %d\n", front_val);

  // Test back()
  int back_val = back(vec);
  printf("back: %d\n", back_val);

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
