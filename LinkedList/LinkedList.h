#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

// Node structure for doubly linked list
struct Node {
  char *data;
  struct Node *next;
  struct Node *prev;
};

// Global pointers (declare extern to avoid multiple definitions)
extern struct Node *header;
extern struct Node *tail;

// Function declarations
void insertAtFront(char *data);
void insertAtBack(char *data);
void printBack(void);
void printFront(void);
void deleteByValue(char *data);

#endif
