#include <stdbool.h>
#include <stdio.h>
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
  free(vector);

  vector->capacity = newSize;

  if (vector->size > newSize) {
    vector->size = newSize;
  }
}
int main() {}