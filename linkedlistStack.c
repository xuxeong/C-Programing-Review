#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct NODE {
   int key;
   struct NODE* next;
}node;

typedef struct {
   node* top;
}stack;

void init(stack*);
int is_empty(stack*);
int is_full(stack*);
void push(stack*, int);
int pop(stack*);
void printStack(stack*);
int count = 0;

void init(stack* s) {
   s->top = NULL;
}

int is_full(stack* s) {
   if (count == MAX)
      return 1;
   else
      return 0;
}

int is_empty(stack* s) {
   if (s->top == NULL)
      return 1;
   else
      return 0;
}

void push(stack* s, int val) {
   node* new_node = (node*)malloc(sizeof(node));
   new_node->key = val;

   new_node->next = s->top;
   s->top = new_node;
   count++;
}

int pop(stack* s) {
   node* tmp = s->top;
   int val = tmp->key;
   s->top = s->top->next;

   count--;
   free(tmp);
   return val;
}

void printStack(stack* s) {
   for (node* p = s->top; p != NULL; p = p->next) {
      printf("%d ", p->key);
   }
}

void main() {
   stack s;
   init(&s);

   int input_values[] = { 1, 3, 2,4 ,5, 6,4,10 };
   int length = sizeof(input_values) / sizeof(int);

   for (int i = 0; i < length; i++) {
      if (is_full(&s) != 1) {
         push(&s, input_values[i]);
         printf("push: %d\n", input_values[i]);
      }
      else
         printf("stack is full");
   }

   printStack(&s);

   while (is_empty(&s) != 1) {
      printf("pop: %d\n", pop(&s));
   }

   printStack(&s);
}
