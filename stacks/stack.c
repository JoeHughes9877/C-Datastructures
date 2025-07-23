#include <stdio.h>

struct Stack {
  int arr[10];
  int array_size;
};

const int MAX_SIZE = 10;

void push(struct Stack *s, int value);
int pop(struct Stack *s);
void print_stack(struct Stack *s);
void peek(struct Stack *s);

void push(struct Stack *s, int value) {
  if (s->array_size == 10) {
    printf("Stack full.");
    return;
  }

  s->arr[s->array_size] = value;
  s->array_size++;
  printf("%i added to stack\n", value);
  return;
}

void print_stack(struct Stack *s) {
  for (int i = 0; i < s->array_size; i++) {
    printf("at index %i is %i\n", i, s->arr[i]);
  }
}

int pop(struct Stack *s) {
  if (s->array_size == 0) {
    printf("Stack underflow\n");
    return -1; // or some error code
  }

  int last_diget = s->arr[s->array_size - 1];
  s->array_size = s->array_size - 1;

  return last_diget;
}

void peek(struct Stack *s) {
  printf("Top value is: %i\n", s->arr[s->array_size - 1]);
}

int main() {
  struct Stack s;
  s.array_size = 0;

  push(&s, 10);
  peek(&s);

  push(&s, 20);
  peek(&s);

  push(&s, 30);
  peek(&s);

  push(&s, 50);
  peek(&s);

  pop(&s);

  push(&s, 40);

  print_stack(&s);

  return 0;
}
