#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node* createNode(int data) {
  struct Node *newNode = malloc(sizeof(struct Node));
  
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void insert(int data, struct Node** header){
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;

    newNode->next = *header; //this makes newNode point to the last thing header was pointing to
    *header = newNode; //updates the header to include the new node 
}

void printList(struct Node* header) {
    struct Node *current = header;

    while (current != NULL) {
        printf("%i", current->data);
        current = current->next;
    }
    return;
}

void delete() {}

int main() {
    struct Node* header = createNode(0);

    insert(1, &header);

    printList(header);
    printf("Done");
}
