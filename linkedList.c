#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node* createNode(int data) {
  struct Node *newNode = malloc(sizeof(struct Node));
  
  newNode->data = data;
  newNode->next = NULL;f
  return newNode;
}

void insert(int data, struct Node** header){

}

void delete() {}

int main() {
    struct Node* header = createNode(0);
}
