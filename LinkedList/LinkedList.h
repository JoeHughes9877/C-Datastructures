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
void insertAtFront(int data);
void insertAtBack(int data);
void printBack(void);
void printFront(void);
void deleteByValue(int data);

#endif