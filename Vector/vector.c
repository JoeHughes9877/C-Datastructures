#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int vector[0];
  int size;
  int capacity;
};

bool isEmpty(struct Node *vector) {
  if (vector->capacity == 0) {
    return true;
  } else {
    return false;
  }
}

int size(struct Node *vector) { return vector->capacity; }

void clear(struct Node *vector) { free(vector); }

int main() {}