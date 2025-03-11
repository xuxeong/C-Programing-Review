#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

int stack[MAX] = {0};
int top = -1;

int stack_full();
int stack_empty();
void push(int);
int pop();
void print_stack();
int is_digit(char);
void calculate(char*);

int main(){
    char eq[8] = "234*2*+";
    printf("Expression: %s\n", eq);
    calculate(eq);
    while(stack_empty()!=1)
        printf("Pop: %d\n", pop());
    printf("This stack is empty.\n");
}

int stack_full(){
    if((top + 1)== MAX)
        return 1;
    else
        return 0;
}

int stack_empty(){
    if(top == 0)
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
    for(int i = 0; i <= top; i++){
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int is_digit(char d){
    if (d >= '0' && d <= '9')
        return 1;
    else  
        return 0;
}

void calculate(char* eq){
    int temp, first, second, op_result;
    print_stack();

    for(int i = 0; i < strlen(eq); i++){
        printf("Read: %c\n", eq[i]);
        if(is_digit(eq[i])){
            temp = eq[i];
            temp = temp - '0';
            printf("Push: %d\n", temp);
            push(temp);
            print_stack();
        }
        else if(eq[i] == '*' || eq[i] == '+' || eq[i] == '/' || eq[i] == '-'){
            second = pop();
            printf("Pop %d\n", second);
            first = pop();
            printf("Pop %d\n", first);
            print_stack();
            op_result = -1;
            if(eq[i] == '*')
                op_result = first * second;
            if(eq[i]=='+')
                op_result = first + second;
            if(eq[i] == '-')
                op_result = first - second;
            if(eq[i] == '/')
                op_result = first / second;

            printf("Push: %d\n", op_result);
            push(op_result);
            print_stack();
        }
        else{
            printf("Unknown error.\n");
            exit(1);
        }
    }
}