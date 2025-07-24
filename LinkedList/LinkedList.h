#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
};

// Global pointers (declare extern to avoid multiple definitions)
extern struct Node *header;
extern struct Node *tail;

// Function declarations
void insertAtFront(struct Node **head, struct Node **tail, int data);
void insertAtBack(struct Node **head, struct Node **tail, int data);
void printBack(struct Node **tail);
void printFront(struct Node **head);
void deleteByValue(struct Node **head, struct Node **tail, int data);
void deleteByIndex(struct Node **head, struct Node **tail, int index);

#endif