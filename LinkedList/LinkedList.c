#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  char *data;
  struct Node *next;
  struct Node *prev;
};

struct Node *header = NULL;
struct Node *tail = NULL;

void insertAtFront(char *data) {
  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->prev = NULL;

  if (header == NULL) {
    header = tail = newNode;
    newNode->prev = newNode->next = NULL;
  } else {
    header->prev = newNode;
    newNode->next = header;
    newNode->prev = NULL;
    header = newNode;
  }
}

void insertAtBack(char *data) {
  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->prev = NULL;

  if (header == NULL) {
    header = tail = newNode;
    newNode->prev = newNode->next = NULL;
  } else {
    newNode->prev = tail;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
  }
}

void printBack() {
  struct Node *current = tail;
  while (current != NULL) {
    printf("%s", current->data);
    current = current->prev;
  }
  printf("\n"); // pretty printing
}

void printFront() {
  struct Node *current = header;

  while (current != NULL) {
    printf("%s", current->data);
    current = current->next;
  }
  printf("\n"); // pretty printing
}

void deleteByValue(char *data) {
  struct Node *current = header;

  while (current != NULL) {
    if (strcmp(current->data, data) == 0) {
      current->next->prev = current->prev;
      current->prev->next = current->next;

      if (current == header) {
        header = current->next;
      }
      if (current == tail) {
        tail = current->prev;
      }
      free(current);
      return;
    }
    current = current->next;
  }
}

int main() {
  insertAtFront("m"); // removed value

  insertAtFront("p");
  insertAtFront("p");
  insertAtFront("l");
  insertAtFront("e");
  insertAtFront("s");

  insertAtBack("a");

  deleteByValue("m");
  printBack();
  printFront();
}