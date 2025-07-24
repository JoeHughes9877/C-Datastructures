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
void insertAtFront(struct Node node, int data);
void insertAtBack(struct Node node, int data);
void printBack(void);
void printFront(void);
void deleteByValue(struct Node node, int data);
void deleteByIndex(struct Node node, int data);

#endif