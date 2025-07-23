#include <stdio.h>

struct Stack {
  int arr[10];
  int array_size;
};

const int MAX_SIZE = 10;

void push(struct Stack *s, int value);
int pop(struct Stack *s);
void print_stack();

void push(struct Stack *s, int value) {
  if (s->array_size + 1 == 11) {
    printf("Stack full.");
    return;
  }

  s->array_size++;
  s->arr[s->array_size] = value;
  printf("%i added to stack", value);
  return;
}

void print_stack() {}

int pop(struct Stack *s) {
  int last_diget;

  return last_diget;
}

int main() {
  struct Stack s;
  s.array_size = 0;

  push(&s, 1);

  return 0;
}
