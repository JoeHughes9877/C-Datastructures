#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
};

struct Node *header = NULL;
struct Node *tail = NULL;

void insertAtFront(struct Node node) {
  struct Node *newNode = malloc(sizeof(struct Node));
  if (newNode == NULL) {
    perror("Failed to allocate memory for new node");
    exit(EXIT_FAILURE);
  }

  // Copy data from passed struct node (only data, not pointers)
  newNode->data = node.data;
  newNode->prev = NULL;

  if (header == NULL) {
    header = tail = newNode;
    newNode->next = NULL;
  } else {
    newNode->next = header;
    header->prev = newNode;
    header = newNode;
  }
}

void insertAtBack(struct Node node) {
  struct Node *newNode = malloc(sizeof(struct Node));
  if (newNode == NULL) {
    perror("Failed to allocate memory for new node");
    exit(EXIT_FAILURE);
  }

  newNode->data = node.data;
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

void deleteByValue(int data) {
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

void deleteByIndex(int index) {
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

int main() {
  struct Node tempNode;

  tempNode.data = 13;
  insertAtFront(tempNode);

  tempNode.data = 16;
  insertAtFront(tempNode);

  tempNode.data = 16;
  insertAtFront(tempNode);

  tempNode.data = 12;
  insertAtFront(tempNode);

  tempNode.data = 15;
  insertAtFront(tempNode);

  tempNode.data = 19;
  insertAtFront(tempNode);

  tempNode.data = 10;
  insertAtBack(tempNode);

  deleteByValue(13);

  printFront();

  return 0;
}
