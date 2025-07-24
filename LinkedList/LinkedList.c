#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
};

struct Node *header = NULL;
struct Node *tail = NULL;

void insertAtFront(struct Node node, int data) {
  struct Node *newNode = malloc(sizeof(struct Node));
  if (newNode == NULL) {
    perror("Failed to allocate memory for new node");
    exit(EXIT_FAILURE);
  }
  newNode->data = data;
  newNode->prev = NULL;

  if (header == NULL) {
    header = tail = newNode;
    newNode->next = NULL;
  } else {
    header->prev = newNode;
    newNode->next = header;
    header = newNode;
  }
}

void insertAtBack(struct Node node, int data) {
  struct Node *newNode = malloc(sizeof(struct Node));
  if (newNode == NULL) {
    perror("Failed to allocate memory for new node");
    exit(EXIT_FAILURE);
  }
  newNode->data = data;
  newNode->next = NULL;

  if (header == NULL) {
    header = tail = newNode;
    newNode->prev = NULL;
  } else {
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
  }
}

void printBack() {
  struct Node *current = tail;
  while (current != NULL) {
    printf("%d", current->data);
    current = current->prev;
  }
  printf("\n"); // pretty printing
}

void printFront() {
  struct Node *current = header;

  while (current != NULL) {
    printf("%d", current->data);
    current = current->next;
  }
  printf("\n"); // pretty printing
}

void deleteByValue(struct Node node, int data) {
  struct Node *current = header;

  while (current != NULL) {
    if (current->data == data) {
      if (current->prev != NULL) {
        current->prev->next = current->next;
      } else {
        header = current->next;
      }

      if (current->next != NULL) {
        current->next->prev = current->prev;
      } else {
        tail = current->prev;
      }

      free(current);
      return;
    }
    current = current->next;
  }
}

void deleteByIndex(struct Node node, int index) {
  struct Node *current = header;
  int i = 0;

  while (current != NULL) {
    if (i == index) {
      if (current->prev != NULL) {
        current->prev->next = current->next;
      } else {
        header = current->next;
      }

      if (current->next != NULL) {
        current->next->prev = current->prev;
      } else {
        tail = current->prev;
      }

      free(current);
      return;
    }
    current = current->next;
    i++;
  }
}