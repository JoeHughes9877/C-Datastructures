#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
};

void insertAtFront(struct Node **head, struct Node **tail, int data) {
  struct Node *newNode = malloc(sizeof(struct Node));
  if (newNode == NULL) {
    perror("Failed to allocate memory for new node");
    exit(EXIT_FAILURE);
  }
  newNode->data = data;
  newNode->prev = NULL;

  if ((*head) == NULL) {
    (*head) = (*tail) = newNode;
    newNode->next = NULL;
  } else {
    (*head)->prev = newNode;
    newNode->next = (*head);
    (*head) = newNode;
  }
}

void insertAtBack(struct Node **head, struct Node **tail, int data) {
  struct Node *newNode = malloc(sizeof(struct Node));
  if (newNode == NULL) {
    perror("Failed to allocate memory for new node");
    exit(EXIT_FAILURE);
  }
  newNode->data = data;
  newNode->next = NULL;

  if ((*head) == NULL) {
    (*head) = (*tail) = newNode;
    newNode->prev = NULL;
  } else {
    newNode->prev = (*tail);
    (*tail)->next = newNode;
    (*tail) = newNode;
  }
}

void printBack(struct Node **tail) {
  struct Node *current = (*tail);
  while (current != NULL) {
    printf("%d", current->data);
    current = current->prev;
  }
  printf("\n"); // pretty printing
}

void printFront(struct Node **head) {
  struct Node *current = (*head);

  while (current != NULL) {
    printf("%d", current->data);
    current = current->next;
  }
  printf("\n"); // pretty printing
}

void deleteByValue(struct Node **head, struct Node **tail, int data) {
  struct Node *current = (*head);

  while (current != NULL) {
    if (current->data == data) {
      if (current->prev != NULL) {
        current->prev->next = current->next;
      } else {
        (*head) = current->next;
      }

      if (current->next != NULL) {
        current->next->prev = current->prev;
      } else {
        (*tail) = current->prev;
      }

      free(current);
      return;
    }
    current = current->next;
  }
}

void deleteByIndex(struct Node **head, struct Node **tail, int index) {
  struct Node *current = (*head);
  int i = 0;

  while (current != NULL) {
    if (i == index) {
      if (current->prev != NULL) {
        current->prev->next = current->next;
      } else {
        (*head) = current->next;
      }

      if (current->next != NULL) {
        current->next->prev = current->prev;
      } else {
        (*tail) = current->prev;
      }

      free(current);
      return;
    }
    current = current->next;
    i++;
  }
}