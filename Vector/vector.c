#define _POSIX_C_SOURCE 200809L

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct vector {
  int size;
  int capacity;
  char **elements;
};

bool isEmpty(struct vector *vec) { return vec->size == 0; }

int size(struct vector *vec) { return vec->size; }

void clear(struct vector *vec) {
  for (int i = 0; i < vec->size; i++) {
    free(vec->elements[i]);
  }
  free(vec->elements);
  free(vec);
}

char *front(struct vector *vec) {
  return isEmpty(vec) ? NULL : vec->elements[0];
}

// Returns the last element (NULL if empty)
char *back(struct vector *vec) {
  return isEmpty(vec) ? NULL : vec->elements[vec->size - 1];
}

void delete_by_value(struct vector *vec, char *target_value) {
  for (int i = 0; i < vec->size; i++) {
    if (strstr(vec->elements[i], target_value) != NULL) {
      free(vec->elements[i]); // free the string
      for (int j = i; j < vec->size - 1; j++) {
        vec->elements[j] = vec->elements[j + 1];
      }
      vec->size--;
      break;
    }
  }
}

void resize_vector(int newSize, struct vector *vec) {
  char **temp = malloc(newSize * sizeof(char *));
  if (!temp) {
    printf("malloc failed.\n");
    return;
  }

  int minSize = (vec->size < newSize) ? vec->size : newSize;
  for (int i = 0; i < minSize; i++) {
    temp[i] = vec->elements[i];
  }

  for (int i = minSize; i < vec->size; i++) {
    free(vec->elements[i]);
  }

  free(vec->elements);
  vec->elements = temp;
  vec->capacity = newSize;
  vec->size = minSize;
}

int main() {
  // Initialize vector
  struct vector *vec = malloc(sizeof(struct vector));
  vec->size = 0;
  vec->capacity = 5;
  vec->elements = malloc(vec->capacity * sizeof(char *));

  // Add elements
  vec->elements[vec->size++] = strdup("apple");
  vec->elements[vec->size++] = strdup("banana");
  vec->elements[vec->size++] = strdup("carrot");
  vec->elements[vec->size++] = strdup("date");
  vec->elements[vec->size++] = strdup("elderberry");

  // Print all elements
  printf("Original vector:\n");
  for (int i = 0; i < vec->size; i++) {
    printf("  [%d] %s\n", i, vec->elements[i]);
  }

  // Test front() and back()
  printf("\nFront: %s\n", front(vec));
  printf("Back: %s\n", back(vec));

  // Test isEmpty and size
  printf("Is empty: %s\n", isEmpty(vec) ? "Yes" : "No");
  printf("Size: %d\n", size(vec));

  // Delete by value
  printf("\nDeleting 'banana'...\n");
  delete_by_value(vec, "banana");

  // Print after deletion
  printf("After deletion:\n");
  for (int i = 0; i < vec->size; i++) {
    printf("  [%d] %s\n", i, vec->elements[i]);
  }

  // Resize to a larger capacity
  printf("\nResizing to capacity 10...\n");
  resize_vector(10, vec);
  printf("New capacity: %d\n", vec->capacity);

  // Resize to a smaller capacity (trimming)
  printf("Resizing to capacity 2...\n");
  resize_vector(2, vec);
  printf("New size: %d, New capacity: %d\n", vec->size, vec->capacity);

  // Final contents
  printf("\nFinal vector contents:\n");
  for (int i = 0; i < vec->size; i++) {
    printf("  [%d] %s\n", i, vec->elements[i]);
  }

  // Clear memory
  clear(vec);
  printf("\nVector memory cleared.\n");

  return 0;
}
