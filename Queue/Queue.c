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
  if (q->queue_size == MAX_SIZE) {
    printf("Queue is full:");
    return;
  }

  insertAtBack(&q->head, &q->tail, item);
  q->queue_size++;
}

// Removes and returns the front element of the queue
int dequeue(struct Queue *q) {
  if (q->queue_size == 0) {
    printf("Queue is empty\n");
    return 0;
  } else {
    int value = q->head->data;
    deleteByIndex(&q->head, &q->tail, 0);
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
    return q->head->data;
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
  q.head = NULL;
  q.tail = NULL;
  q.queue_size = 0;

  // Enqueue elements
  printf("Enqueueing elements:\n");
  for (int i = 1; i <= 12; i++) {
    printf("Enqueue %d: ", i);
    enqueue(&q, i);
    printf("Queue size: %d\n", size(&q));
  }

  // Peek at the front element
  printf("\nPeeking at front: %d\n", peek(&q));

  // Dequeue a few elements
  printf("\nDequeuing elements:\n");
  for (int i = 0; i < 5; i++) {
    int val = dequeue(&q);
    printf("Dequeued: %d | New front: %d | Queue size: %d\n", val, peek(&q),
           size(&q));
  }

  // Dequeue all remaining elements
  printf("\nDequeuing remaining elements:\n");
  while (!is_empty(&q)) {
    printf("Dequeued: %d | Queue size: %d\n", dequeue(&q), size(&q));
  }

  // Try dequeueing from empty queue
  printf("\nTrying to dequeue from an empty queue:\n");
  dequeue(&q);

  // Try peeking from empty queue
  printf("\nTrying to peek at an empty queue:\n");
  peek(&q);

  return 0;
}
