#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct NODE {
   int key;
   struct NODE* next;
}node;

typedef struct {
   node* front;
   node* back;
}cQueue;

int count = 0;
int is_full();
int is_empty();
void enqueue(cQueue*, int);
int dequeue(cQueue*);
void printQueue(cQueue*);
void init(cQueue*);

void init(cQueue* c) {
   c->front = c->back = NULL;
}

int is_full() {
   if (count == MAX)
      return 1;
   else
      return 0;
}

int is_empty() {
   if (count == 0)
      return 1;
   else
      return 0;
}

void enqueue(cQueue* c, int val) {
   node* new_node = (node*)malloc(sizeof(node));
   new_node->key = val;

   if (count == 0) {
      c->front = c->back = new_node;
      new_node->next = new_node;
   }
   else {
      new_node->next = c->front;
      c->back->next = new_node;
      c->back = new_node;
   }
   count++;
   printf("Debug in enqueue: c->front = %p, c->back = %p\n", c->front, c->back);
}

int dequeue(cQueue* c) {
   node* tmp = c->front;
   int val = tmp->key;
   count--;

   if (count == 0)
      c->front = c->back = NULL;
   else {
      c->front = c->front->next;
      c->back->next = c->front;
   }
   free(tmp);
   return val;
}

void printQueue(cQueue* c) {
   if (is_empty()) {
      printf("Queue is empty\n");
      return;
   }
   node* ptr = c->front;
    do {
        printf("%d ", ptr->key);
        ptr = ptr->next;
    } while (ptr != c->front);
   printf("\n\n");
}

void main() {
   cQueue c;
   init(&c);

   int input_values[] = { 1, 3, 24, 35, 40, 2 };
   int length = sizeof(input_values) / sizeof(int);

   for (int i = 0; i < length; i++) {
      if (is_full() != 1) {
         enqueue(&c, input_values[i]);
         printf("enqueue: %d\n", input_values[i]);
      }
      else
         printf("queue is full\n");
   }

   printQueue(&c);

   while (is_empty() != 1) {
      printf("dequeue: %d\n", dequeue(&c));
   }

   printQueue(&c);
}
