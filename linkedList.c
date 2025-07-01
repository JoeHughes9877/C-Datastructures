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

void print_back() {
  struct Node *current = tail;
  while (current != NULL) {
    printf("%s", current->data);
    current = current->prev;
  }
  printf("\n"); // pretty printing
}

void print_front() {
  struct Node *current = header;

  while (current != NULL) {
    printf("%s", current->data);
    current = current->next;
  }
  printf("\n"); // pretty printing
}

int main() {
  insertAtFront("a");
  insertAtFront("p");
  insertAtFront("p");
  insertAtFront("l");
  insertAtFront("e");
  insertAtFront("s");

  print_front();
  print_back();
}