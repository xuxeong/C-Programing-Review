#include <stdio.h>

#define MAX 5

int stack[MAX] = { 0 };
int top = -1;

int stack_full(){
    if ((top+1)==MAX)
        return 1;
    else
        return 0;
}

int stack_empty(){
    if(top == -1)
        return 1;
    else
        return 0;
}

void push(int value){
    stack[++top] = value;
}

int pop(){
    return stack[top--];
}

void print_stack(){
    printf("Print a stack: ");
    for (int i = 0; i <= top; i++){
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main(){
    int val;
    int input_values[] = {10, 40, 15, 35, 50, 20, 25, 50};

    int length = sizeof(input_values)/sizeof(int);

    //push test
    for (int i = 0; i < length; i++){
        val = input_values[i];
        if(stack_full() != 1){
            push(val);
            printf("Push: %d\n", val);
        }
        else
            printf("Failed to push %d. This stack is full.\n", val);
    }

    print_stack();

    //pop test
    while(stack_empty()!=1){
        val = pop();
        printf("Pop: %d\n", val);
    }
    printf("This stack is empty.\n");
    return 0;
}