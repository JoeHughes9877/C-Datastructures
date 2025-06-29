#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  char *data;
  struct Node *next;
  struct Node *prev;
};

struct Node *createNode(char *data) {
  struct Node *newNode = malloc(sizeof(struct Node));

  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

void insert(char *data, struct Node **header) {
  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->prev = NULL;

  (*header)->prev = newNode;
  newNode->next = *header; // this makes newNode point to the last thing header
                           // was pointing to
  *header = newNode;       // updates the header to include the new node
}

void printList(struct Node *header) {
  struct Node *current = header;

  while (current != NULL) {
    printf("%s", current->data);
    current = current->prev;
  }
  printf("\n"); // pretty printing
}

void delete(char *data, struct Node *header) {}

int main() {
  struct Node *header = createNode("");

  insert("a", &header);
  insert("p", &header);
  insert("p", &header);
  insert("l", &header);
  insert("e", &header);
  insert("s", &header);

  printList(header);
}