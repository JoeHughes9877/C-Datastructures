#include "../LinkedList/LinkedList.h"
#include <stdio.h>

struct Queue {
  struct Node *head;
  struct Node *tail;
  int queue_size;
};

const int MAX_SIZE = 10;

void enqueue(struct Queue *q, int item);
int dequeue(struct Queue *q);
int peek(struct Queue *q);
int is_empty(struct Queue *q);
int size(struct Queue *q);

// Adds an element to the back of the queue
void enqueue(struct Queue *q, int item) {
  insertAtBack(*q->tail, item);
  q->queue_size++;
}

// Removes and returns the front element of the queue
int dequeue(struct Queue *q) {
  if (q->queue_size == 0) {
    printf("Queue is empty\n");
    return 0;
  } else {
    int value = header->data;
    deleteByIndex(*q->head, 0);
    q->queue_size--;
    return value;
  }
}

// Returns the front element without removing it
int peek(struct Queue *q) {
  if (q->queue_size == 0) {
    printf("Queue is empty\n");
    return 0;
  } else {
    return header->data;
  }
}

// Checks if the queue is empty
int is_empty(struct Queue *q) {
  if (q->queue_size == 0) {
    return 1;
  }

  return 0;
}

// Returns the number of elements in the queue
int size(struct Queue *q) { return q->queue_size; }

int main() {
  struct Queue q;
  q.queue_size = 0;

  if (is_empty(&q) == 1) {
    printf("Stack is empty\n");
  } else {
    printf("stacks size is currently");
    size(&q);
    printf("\n");
  }
}