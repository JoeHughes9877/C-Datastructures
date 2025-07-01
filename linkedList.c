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
    header = newNode;
    tail = newNode;
  } else {
    header->prev = newNode;
    newNode->next = header; // this makes newNode point to the last thing
                            // header was pointing to
    header = newNode;       // updates the header to include the new node
  }
}

void printList() {
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

  printList();
}